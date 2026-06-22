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
	case 5ULL: goto x86_l_5;
	case 7ULL: goto x86_l_7;
	case 9ULL: goto x86_l_9;
	case 10ULL: goto x86_l_a;
	case 17ULL: goto x86_l_11;
	case 20ULL: goto x86_l_14;
	case 31ULL: goto x86_l_1f;
	case 38ULL: goto x86_l_26;
	case 46ULL: goto x86_l_2e;
	case 51ULL: goto x86_l_33;
	case 53ULL: goto x86_l_35;
	case 56ULL: goto x86_l_38;
	case 62ULL: goto x86_l_3e;
	case 65ULL: goto x86_l_41;
	case 72ULL: goto x86_l_48;
	case 77ULL: goto x86_l_4d;
	case 84ULL: goto x86_l_54;
	case 89ULL: goto x86_l_59;
	case 93ULL: goto x86_l_5d;
	case 101ULL: goto x86_l_65;
	case 105ULL: goto x86_l_69;
	case 110ULL: goto x86_l_6e;
	case 114ULL: goto x86_l_72;
	case 122ULL: goto x86_l_7a;
	case 126ULL: goto x86_l_7e;
	case 131ULL: goto x86_l_83;
	case 135ULL: goto x86_l_87;
	case 143ULL: goto x86_l_8f;
	case 147ULL: goto x86_l_93;
	case 152ULL: goto x86_l_98;
	case 156ULL: goto x86_l_9c;
	case 164ULL: goto x86_l_a4;
	case 168ULL: goto x86_l_a8;
	case 173ULL: goto x86_l_ad;
	case 177ULL: goto x86_l_b1;
	case 182ULL: goto x86_l_b6;
	case 186ULL: goto x86_l_ba;
	case 191ULL: goto x86_l_bf;
	case 195ULL: goto x86_l_c3;
	case 200ULL: goto x86_l_c8;
	case 204ULL: goto x86_l_cc;
	case 209ULL: goto x86_l_d1;
	case 213ULL: goto x86_l_d5;
	case 218ULL: goto x86_l_da;
	case 222ULL: goto x86_l_de;
	case 227ULL: goto x86_l_e3;
	case 230ULL: goto x86_l_e6;
	case 235ULL: goto x86_l_eb;
	case 237ULL: goto x86_l_ed;
	case 240ULL: goto x86_l_f0;
	case 245ULL: goto x86_l_f5;
	case 251ULL: goto x86_l_fb;
	case 254ULL: goto x86_l_fe;
	case 259ULL: goto x86_l_103;
	case 265ULL: goto x86_l_109;
	case 268ULL: goto x86_l_10c;
	case 273ULL: goto x86_l_111;
	case 279ULL: goto x86_l_117;
	case 282ULL: goto x86_l_11a;
	case 287ULL: goto x86_l_11f;
	case 293ULL: goto x86_l_125;
	case 295ULL: goto x86_l_127;
	case 302ULL: goto x86_l_12e;
	case 303ULL: goto x86_l_12f;
	case 305ULL: goto x86_l_131;
	case 307ULL: goto x86_l_133;
	case 309ULL: goto x86_l_135;
	case 311ULL: goto x86_l_137;
	case 312ULL: goto x86_l_138;
	case 317ULL: goto x86_l_13d;
	case 319ULL: goto x86_l_13f;
	case 325ULL: goto x86_l_145;
	case 332ULL: goto x86_l_14c;
	case 334ULL: goto x86_l_14e;
	case 337ULL: goto x86_l_151;
	case 343ULL: goto x86_l_157;
	case 346ULL: goto x86_l_15a;
	case 352ULL: goto x86_l_160;
	case 355ULL: goto x86_l_163;
	case 361ULL: goto x86_l_169;
	case 367ULL: goto x86_l_16f;
	case 373ULL: goto x86_l_175;
	case 376ULL: goto x86_l_178;
	case 381ULL: goto x86_l_17d;
	case 386ULL: goto x86_l_182;
	case 391ULL: goto x86_l_187;
	case 396ULL: goto x86_l_18c;
	case 398ULL: goto x86_l_18e;
	case 400ULL: goto x86_l_190;
	case 406ULL: goto x86_l_196;
	case 408ULL: goto x86_l_198;
	case 413ULL: goto x86_l_19d;
	case 415ULL: goto x86_l_19f;
	case 421ULL: goto x86_l_1a5;
	case 428ULL: goto x86_l_1ac;
	case 430ULL: goto x86_l_1ae;
	case 433ULL: goto x86_l_1b1;
	case 439ULL: goto x86_l_1b7;
	case 442ULL: goto x86_l_1ba;
	case 448ULL: goto x86_l_1c0;
	case 451ULL: goto x86_l_1c3;
	case 457ULL: goto x86_l_1c9;
	case 463ULL: goto x86_l_1cf;
	case 469ULL: goto x86_l_1d5;
	case 472ULL: goto x86_l_1d8;
	case 477ULL: goto x86_l_1dd;
	case 482ULL: goto x86_l_1e2;
	case 487ULL: goto x86_l_1e7;
	case 492ULL: goto x86_l_1ec;
	case 494ULL: goto x86_l_1ee;
	case 496ULL: goto x86_l_1f0;
	case 502ULL: goto x86_l_1f6;
	case 504ULL: goto x86_l_1f8;
	case 509ULL: goto x86_l_1fd;
	case 511ULL: goto x86_l_1ff;
	case 517ULL: goto x86_l_205;
	case 524ULL: goto x86_l_20c;
	case 526ULL: goto x86_l_20e;
	case 529ULL: goto x86_l_211;
	case 535ULL: goto x86_l_217;
	case 538ULL: goto x86_l_21a;
	case 544ULL: goto x86_l_220;
	case 547ULL: goto x86_l_223;
	case 553ULL: goto x86_l_229;
	case 559ULL: goto x86_l_22f;
	case 565ULL: goto x86_l_235;
	case 568ULL: goto x86_l_238;
	case 573ULL: goto x86_l_23d;
	case 578ULL: goto x86_l_242;
	case 583ULL: goto x86_l_247;
	case 588ULL: goto x86_l_24c;
	case 590ULL: goto x86_l_24e;
	case 592ULL: goto x86_l_250;
	case 598ULL: goto x86_l_256;
	case 600ULL: goto x86_l_258;
	case 605ULL: goto x86_l_25d;
	case 607ULL: goto x86_l_25f;
	case 613ULL: goto x86_l_265;
	case 620ULL: goto x86_l_26c;
	case 622ULL: goto x86_l_26e;
	case 625ULL: goto x86_l_271;
	case 631ULL: goto x86_l_277;
	case 634ULL: goto x86_l_27a;
	case 640ULL: goto x86_l_280;
	case 643ULL: goto x86_l_283;
	case 649ULL: goto x86_l_289;
	case 655ULL: goto x86_l_28f;
	case 661ULL: goto x86_l_295;
	case 664ULL: goto x86_l_298;
	case 669ULL: goto x86_l_29d;
	case 674ULL: goto x86_l_2a2;
	case 679ULL: goto x86_l_2a7;
	case 684ULL: goto x86_l_2ac;
	case 686ULL: goto x86_l_2ae;
	case 688ULL: goto x86_l_2b0;
	case 694ULL: goto x86_l_2b6;
	case 696ULL: goto x86_l_2b8;
	case 701ULL: goto x86_l_2bd;
	case 703ULL: goto x86_l_2bf;
	case 709ULL: goto x86_l_2c5;
	case 716ULL: goto x86_l_2cc;
	case 718ULL: goto x86_l_2ce;
	case 721ULL: goto x86_l_2d1;
	case 727ULL: goto x86_l_2d7;
	case 730ULL: goto x86_l_2da;
	case 736ULL: goto x86_l_2e0;
	case 739ULL: goto x86_l_2e3;
	case 745ULL: goto x86_l_2e9;
	case 751ULL: goto x86_l_2ef;
	case 756ULL: goto x86_l_2f4;
	case 759ULL: goto x86_l_2f7;
	case 764ULL: goto x86_l_2fc;
	case 769ULL: goto x86_l_301;
	case 774ULL: goto x86_l_306;
	case 779ULL: goto x86_l_30b;
	case 782ULL: goto x86_l_30e;
	case 784ULL: goto x86_l_310;
	case 786ULL: goto x86_l_312;
	case 792ULL: goto x86_l_318;
	case 794ULL: goto x86_l_31a;
	case 799ULL: goto x86_l_31f;
	case 806ULL: goto x86_l_326;
	case 813ULL: goto x86_l_32d;
	case 819ULL: goto x86_l_333;
	case 821ULL: goto x86_l_335;
	case 824ULL: goto x86_l_338;
	case 830ULL: goto x86_l_33e;
	case 833ULL: goto x86_l_341;
	case 839ULL: goto x86_l_347;
	case 842ULL: goto x86_l_34a;
	case 848ULL: goto x86_l_350;
	case 856ULL: goto x86_l_358;
	case 859ULL: goto x86_l_35b;
	case 865ULL: goto x86_l_361;
	case 870ULL: goto x86_l_366;
	case 873ULL: goto x86_l_369;
	case 879ULL: goto x86_l_36f;
	case 882ULL: goto x86_l_372;
	case 888ULL: goto x86_l_378;
	case 893ULL: goto x86_l_37d;
	case 898ULL: goto x86_l_382;
	case 905ULL: goto x86_l_389;
	case 912ULL: goto x86_l_390;
	case 918ULL: goto x86_l_396;
	case 920ULL: goto x86_l_398;
	case 923ULL: goto x86_l_39b;
	case 929ULL: goto x86_l_3a1;
	case 932ULL: goto x86_l_3a4;
	case 938ULL: goto x86_l_3aa;
	case 941ULL: goto x86_l_3ad;
	case 947ULL: goto x86_l_3b3;
	case 955ULL: goto x86_l_3bb;
	case 958ULL: goto x86_l_3be;
	case 964ULL: goto x86_l_3c4;
	case 969ULL: goto x86_l_3c9;
	case 972ULL: goto x86_l_3cc;
	case 978ULL: goto x86_l_3d2;
	case 983ULL: goto x86_l_3d7;
	case 986ULL: goto x86_l_3da;
	case 992ULL: goto x86_l_3e0;
	case 997ULL: goto x86_l_3e5;
	case 1004ULL: goto x86_l_3ec;
	case 1011ULL: goto x86_l_3f3;
	case 1017ULL: goto x86_l_3f9;
	case 1019ULL: goto x86_l_3fb;
	case 1022ULL: goto x86_l_3fe;
	case 1028ULL: goto x86_l_404;
	case 1031ULL: goto x86_l_407;
	case 1037ULL: goto x86_l_40d;
	case 1040ULL: goto x86_l_410;
	case 1046ULL: goto x86_l_416;
	case 1054ULL: goto x86_l_41e;
	case 1057ULL: goto x86_l_421;
	case 1063ULL: goto x86_l_427;
	case 1068ULL: goto x86_l_42c;
	case 1071ULL: goto x86_l_42f;
	case 1077ULL: goto x86_l_435;
	case 1082ULL: goto x86_l_43a;
	case 1085ULL: goto x86_l_43d;
	case 1091ULL: goto x86_l_443;
	case 1096ULL: goto x86_l_448;
	case 1103ULL: goto x86_l_44f;
	case 1110ULL: goto x86_l_456;
	case 1116ULL: goto x86_l_45c;
	case 1118ULL: goto x86_l_45e;
	case 1121ULL: goto x86_l_461;
	case 1127ULL: goto x86_l_467;
	case 1130ULL: goto x86_l_46a;
	case 1136ULL: goto x86_l_470;
	case 1139ULL: goto x86_l_473;
	case 1145ULL: goto x86_l_479;
	case 1153ULL: goto x86_l_481;
	case 1156ULL: goto x86_l_484;
	case 1162ULL: goto x86_l_48a;
	case 1167ULL: goto x86_l_48f;
	case 1170ULL: goto x86_l_492;
	case 1176ULL: goto x86_l_498;
	case 1181ULL: goto x86_l_49d;
	case 1184ULL: goto x86_l_4a0;
	case 1190ULL: goto x86_l_4a6;
	case 1195ULL: goto x86_l_4ab;
	case 1202ULL: goto x86_l_4b2;
	case 1209ULL: goto x86_l_4b9;
	case 1215ULL: goto x86_l_4bf;
	case 1217ULL: goto x86_l_4c1;
	case 1220ULL: goto x86_l_4c4;
	case 1226ULL: goto x86_l_4ca;
	case 1229ULL: goto x86_l_4cd;
	case 1235ULL: goto x86_l_4d3;
	case 1238ULL: goto x86_l_4d6;
	case 1244ULL: goto x86_l_4dc;
	case 1252ULL: goto x86_l_4e4;
	case 1255ULL: goto x86_l_4e7;
	case 1261ULL: goto x86_l_4ed;
	case 1266ULL: goto x86_l_4f2;
	case 1269ULL: goto x86_l_4f5;
	case 1275ULL: goto x86_l_4fb;
	case 1280ULL: goto x86_l_500;
	case 1283ULL: goto x86_l_503;
	case 1289ULL: goto x86_l_509;
	case 1294ULL: goto x86_l_50e;
	case 1297ULL: goto x86_l_511;
	case 1303ULL: goto x86_l_517;
	case 1306ULL: goto x86_l_51a;
	case 1312ULL: goto x86_l_520;
	case 1318ULL: goto x86_l_526;
	case 1324ULL: goto x86_l_52c;
	case 1327ULL: goto x86_l_52f;
	case 1332ULL: goto x86_l_534;
	case 1337ULL: goto x86_l_539;
	case 1342ULL: goto x86_l_53e;
	case 1347ULL: goto x86_l_543;
	case 1349ULL: goto x86_l_545;
	case 1351ULL: goto x86_l_547;
	case 1357ULL: goto x86_l_54d;
	case 1363ULL: goto x86_l_553;
	case 1369ULL: goto x86_l_559;
	case 1372ULL: goto x86_l_55c;
	case 1375ULL: goto x86_l_55f;
	case 1380ULL: goto x86_l_564;
	case 1385ULL: goto x86_l_569;
	case 1390ULL: goto x86_l_56e;
	case 1392ULL: goto x86_l_570;
	case 1394ULL: goto x86_l_572;
	case 1400ULL: goto x86_l_578;
	case 1407ULL: goto x86_l_57f;
	case 1413ULL: goto x86_l_585;
	case 1420ULL: goto x86_l_58c;
	case 1425ULL: goto x86_l_591;
	case 1428ULL: goto x86_l_594;
	case 1433ULL: goto x86_l_599;
	case 1438ULL: goto x86_l_59e;
	case 1443ULL: goto x86_l_5a3;
	case 1450ULL: goto x86_l_5aa;
	case 1456ULL: goto x86_l_5b0;
	case 1463ULL: goto x86_l_5b7;
	case 1468ULL: goto x86_l_5bc;
	case 1471ULL: goto x86_l_5bf;
	case 1476ULL: goto x86_l_5c4;
	case 1478ULL: goto x86_l_5c6;
	case 1480ULL: goto x86_l_5c8;
	case 1486ULL: goto x86_l_5ce;
	case 1491ULL: goto x86_l_5d3;
	case 1494ULL: goto x86_l_5d6;
	case 1500ULL: goto x86_l_5dc;
	case 1503ULL: goto x86_l_5df;
	case 1509ULL: goto x86_l_5e5;
	case 1515ULL: goto x86_l_5eb;
	case 1521ULL: goto x86_l_5f1;
	case 1524ULL: goto x86_l_5f4;
	case 1529ULL: goto x86_l_5f9;
	case 1534ULL: goto x86_l_5fe;
	case 1539ULL: goto x86_l_603;
	case 1544ULL: goto x86_l_608;
	case 1546ULL: goto x86_l_60a;
	case 1548ULL: goto x86_l_60c;
	case 1554ULL: goto x86_l_612;
	case 1559ULL: goto x86_l_617;
	case 1566ULL: goto x86_l_61e;
	case 1571ULL: goto x86_l_623;
	case 1576ULL: goto x86_l_628;
	case 1581ULL: goto x86_l_62d;
	case 1586ULL: goto x86_l_632;
	case 1593ULL: goto x86_l_639;
	case 1598ULL: goto x86_l_63e;
	case 1600ULL: goto x86_l_640;
	case 1602ULL: goto x86_l_642;
	case 1608ULL: goto x86_l_648;
	case 1613ULL: goto x86_l_64d;
	case 1616ULL: goto x86_l_650;
	case 1622ULL: goto x86_l_656;
	case 1625ULL: goto x86_l_659;
	case 1631ULL: goto x86_l_65f;
	case 1637ULL: goto x86_l_665;
	case 1643ULL: goto x86_l_66b;
	case 1646ULL: goto x86_l_66e;
	case 1651ULL: goto x86_l_673;
	case 1656ULL: goto x86_l_678;
	case 1661ULL: goto x86_l_67d;
	case 1666ULL: goto x86_l_682;
	case 1668ULL: goto x86_l_684;
	case 1670ULL: goto x86_l_686;
	case 1676ULL: goto x86_l_68c;
	case 1681ULL: goto x86_l_691;
	case 1688ULL: goto x86_l_698;
	case 1693ULL: goto x86_l_69d;
	case 1698ULL: goto x86_l_6a2;
	case 1703ULL: goto x86_l_6a7;
	case 1708ULL: goto x86_l_6ac;
	case 1715ULL: goto x86_l_6b3;
	case 1720ULL: goto x86_l_6b8;
	case 1722ULL: goto x86_l_6ba;
	case 1724ULL: goto x86_l_6bc;
	case 1730ULL: goto x86_l_6c2;
	case 1735ULL: goto x86_l_6c7;
	case 1738ULL: goto x86_l_6ca;
	case 1744ULL: goto x86_l_6d0;
	case 1747ULL: goto x86_l_6d3;
	case 1753ULL: goto x86_l_6d9;
	case 1759ULL: goto x86_l_6df;
	case 1765ULL: goto x86_l_6e5;
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
	/* 0xa: sub    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 168ULL);
x86_l_11:
	/* 0x11: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    DWORD PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1f:
	/* 0x1f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_26:
	/* 0x26: lea    rsi,[rsp+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_2e:
	/* 0x2e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33:
	/* 0x33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35:
	/* 0x35: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38:
	/* 0x38: je     125 <generic_sleepable_preload+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_125;
	}
x86_l_3e:
	/* 0x3e: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_41:
	/* 0x41: lea    rax,[r14+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_48:
	/* 0x48: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4d:
	/* 0x4d: lea    rax,[r14+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_54:
	/* 0x54: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_59:
	/* 0x59: lea    rax,[r14+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5d:
	/* 0x5d: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_65:
	/* 0x65: lea    rax,[r14+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_69:
	/* 0x69: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6e:
	/* 0x6e: lea    rax,[r14+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_72:
	/* 0x72: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_7a:
	/* 0x7a: lea    rax,[r14+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_7e:
	/* 0x7e: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_83:
	/* 0x83: lea    rax,[r14+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_87:
	/* 0x87: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_8f:
	/* 0x8f: lea    rax,[r14+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_93:
	/* 0x93: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_98:
	/* 0x98: lea    rax,[r14+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9c:
	/* 0x9c: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a4:
	/* 0xa4: lea    rax,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a8:
	/* 0xa8: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ad:
	/* 0xad: lea    rax,[r14+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b1:
	/* 0xb1: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_b6:
	/* 0xb6: lea    rax,[r14+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ba:
	/* 0xba: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_bf:
	/* 0xbf: lea    rax,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c3:
	/* 0xc3: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c8:
	/* 0xc8: lea    rax,[r14+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cc:
	/* 0xcc: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d1:
	/* 0xd1: lea    rax,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d5:
	/* 0xd5: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_da:
	/* 0xda: lea    rax,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_de:
	/* 0xde: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e3:
	/* 0xe3: mov    eax,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e6:
	/* 0xe6: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_eb:
	/* 0xeb: jne    13d <generic_sleepable_preload+0x13d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13d;
	}
x86_l_ed:
	/* 0xed: mov    eax,DWORD PTR [rbx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_f0:
	/* 0xf0: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_f5:
	/* 0xf5: jne    19d <generic_sleepable_preload+0x19d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19d;
	}
x86_l_fb:
	/* 0xfb: mov    eax,DWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fe:
	/* 0xfe: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_103:
	/* 0x103: jne    1fd <generic_sleepable_preload+0x1fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fd;
	}
x86_l_109:
	/* 0x109: mov    eax,DWORD PTR [rbx+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_10c:
	/* 0x10c: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_111:
	/* 0x111: jne    25d <generic_sleepable_preload+0x25d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25d;
	}
x86_l_117:
	/* 0x117: mov    eax,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11a:
	/* 0x11a: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_11f:
	/* 0x11f: jne    2bd <generic_sleepable_preload+0x2bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2bd;
	}
x86_l_125:
	/* 0x125: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_127:
	/* 0x127: add    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_12e:
	/* 0x12e: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_12f:
	/* 0x12f: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_131:
	/* 0x131: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_133:
	/* 0x133: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_135:
	/* 0x135: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_137:
	/* 0x137: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_138:
	/* 0x138: jmp    38c9 <generic_sleepable_preload+0x38c9> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_13d:
	/* 0x13d: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_13f:
	/* 0x13f: js     31f <generic_sleepable_preload+0x31f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_31f;
	}
x86_l_145:
	/* 0x145: movzx  eax,BYTE PTR [rbx+0x211] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 529ULL);
x86_l_14c:
	/* 0x14c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14e:
	/* 0x14e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_151:
	/* 0x151: jg     50e <generic_sleepable_preload+0x50e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_50e;
	}
x86_l_157:
	/* 0x157: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15a:
	/* 0x15a: je     a54 <generic_sleepable_preload+0xa54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2644ULL;
	}
x86_l_160:
	/* 0x160: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_163:
	/* 0x163: jne    bbf <generic_sleepable_preload+0xbbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3007ULL;
	}
x86_l_169:
	/* 0x169: mov    edx,DWORD PTR [rbx+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_16f:
	/* 0x16f: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_175:
	/* 0x175: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_178:
	/* 0x178: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17d:
	/* 0x17d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_182:
	/* 0x182: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_187:
	/* 0x187: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18c:
	/* 0x18c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e:
	/* 0x18e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_190:
	/* 0x190: je     a60 <generic_sleepable_preload+0xa60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2656ULL;
	}
x86_l_196:
	/* 0x196: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_198:
	/* 0x198: jmp    bbf <generic_sleepable_preload+0xbbf> */
	return 3007ULL;
x86_l_19d:
	/* 0x19d: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_19f:
	/* 0x19f: js     382 <generic_sleepable_preload+0x382> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_382;
	}
x86_l_1a5:
	/* 0x1a5: movzx  eax,BYTE PTR [rbx+0x229] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 553ULL);
x86_l_1ac:
	/* 0x1ac: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ae:
	/* 0x1ae: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b1:
	/* 0x1b1: jg     5d3 <generic_sleepable_preload+0x5d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_5d3;
	}
x86_l_1b7:
	/* 0x1b7: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ba:
	/* 0x1ba: je     a88 <generic_sleepable_preload+0xa88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2696ULL;
	}
x86_l_1c0:
	/* 0x1c0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c3:
	/* 0x1c3: jne    f60 <generic_sleepable_preload+0xf60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3936ULL;
	}
x86_l_1c9:
	/* 0x1c9: mov    edx,DWORD PTR [rbx+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_1cf:
	/* 0x1cf: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1d5:
	/* 0x1d5: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1d8:
	/* 0x1d8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dd:
	/* 0x1dd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e2:
	/* 0x1e2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e7:
	/* 0x1e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ec:
	/* 0x1ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ee:
	/* 0x1ee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f0:
	/* 0x1f0: je     a94 <generic_sleepable_preload+0xa94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2708ULL;
	}
x86_l_1f6:
	/* 0x1f6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f8:
	/* 0x1f8: jmp    f60 <generic_sleepable_preload+0xf60> */
	return 3936ULL;
x86_l_1fd:
	/* 0x1fd: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1ff:
	/* 0x1ff: js     3e5 <generic_sleepable_preload+0x3e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3e5;
	}
x86_l_205:
	/* 0x205: movzx  eax,BYTE PTR [rbx+0x241] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 577ULL);
x86_l_20c:
	/* 0x20c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20e:
	/* 0x20e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_211:
	/* 0x211: jg     64d <generic_sleepable_preload+0x64d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_64d;
	}
x86_l_217:
	/* 0x217: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21a:
	/* 0x21a: je     ac1 <generic_sleepable_preload+0xac1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2753ULL;
	}
x86_l_220:
	/* 0x220: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_223:
	/* 0x223: jne    1313 <generic_sleepable_preload+0x1313> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4883ULL;
	}
x86_l_229:
	/* 0x229: mov    edx,DWORD PTR [rbx+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_22f:
	/* 0x22f: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_235:
	/* 0x235: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_238:
	/* 0x238: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23d:
	/* 0x23d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_242:
	/* 0x242: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_247:
	/* 0x247: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24c:
	/* 0x24c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24e:
	/* 0x24e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_250:
	/* 0x250: je     acd <generic_sleepable_preload+0xacd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2765ULL;
	}
x86_l_256:
	/* 0x256: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_258:
	/* 0x258: jmp    1313 <generic_sleepable_preload+0x1313> */
	return 4883ULL;
x86_l_25d:
	/* 0x25d: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_25f:
	/* 0x25f: js     448 <generic_sleepable_preload+0x448> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_448;
	}
x86_l_265:
	/* 0x265: movzx  eax,BYTE PTR [rbx+0x259] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 601ULL);
x86_l_26c:
	/* 0x26c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26e:
	/* 0x26e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_271:
	/* 0x271: jg     6c7 <generic_sleepable_preload+0x6c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_6c7;
	}
x86_l_277:
	/* 0x277: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27a:
	/* 0x27a: je     af5 <generic_sleepable_preload+0xaf5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2805ULL;
	}
x86_l_280:
	/* 0x280: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_283:
	/* 0x283: jne    16c6 <generic_sleepable_preload+0x16c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5830ULL;
	}
x86_l_289:
	/* 0x289: mov    edx,DWORD PTR [rbx+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_28f:
	/* 0x28f: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_295:
	/* 0x295: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_298:
	/* 0x298: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29d:
	/* 0x29d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a2:
	/* 0x2a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a7:
	/* 0x2a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ac:
	/* 0x2ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae:
	/* 0x2ae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b0:
	/* 0x2b0: je     b01 <generic_sleepable_preload+0xb01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2817ULL;
	}
x86_l_2b6:
	/* 0x2b6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b8:
	/* 0x2b8: jmp    16c6 <generic_sleepable_preload+0x16c6> */
	return 5830ULL;
x86_l_2bd:
	/* 0x2bd: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2bf:
	/* 0x2bf: js     4ab <generic_sleepable_preload+0x4ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4ab;
	}
x86_l_2c5:
	/* 0x2c5: movzx  eax,BYTE PTR [rbx+0x271] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 625ULL);
x86_l_2cc:
	/* 0x2cc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ce:
	/* 0x2ce: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d1:
	/* 0x2d1: jg     741 <generic_sleepable_preload+0x741> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1857ULL;
	}
x86_l_2d7:
	/* 0x2d7: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2da:
	/* 0x2da: je     b29 <generic_sleepable_preload+0xb29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2857ULL;
	}
x86_l_2e0:
	/* 0x2e0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e3:
	/* 0x2e3: jne    1a7b <generic_sleepable_preload+0x1a7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6779ULL;
	}
x86_l_2e9:
	/* 0x2e9: mov    eax,DWORD PTR [rbx+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_2ef:
	/* 0x2ef: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2f4:
	/* 0x2f4: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f7:
	/* 0x2f7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fc:
	/* 0x2fc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_301:
	/* 0x301: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_306:
	/* 0x306: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30b:
	/* 0x30b: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_30e:
	/* 0x30e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_310:
	/* 0x310: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_312:
	/* 0x312: je     b35 <generic_sleepable_preload+0xb35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2869ULL;
	}
x86_l_318:
	/* 0x318: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31a:
	/* 0x31a: jmp    1a7b <generic_sleepable_preload+0x1a7b> */
	return 6779ULL;
x86_l_31f:
	/* 0x31f: movzx  eax,BYTE PTR [rbx+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_326:
	/* 0x326: movzx  ecx,WORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_32d:
	/* 0x32d: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_333:
	/* 0x333: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_335:
	/* 0x335: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_338:
	/* 0x338: jle    7bd <generic_sleepable_preload+0x7bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 1981ULL;
	}
x86_l_33e:
	/* 0x33e: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_341:
	/* 0x341: jle    8a1 <generic_sleepable_preload+0x8a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2209ULL;
	}
x86_l_347:
	/* 0x347: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_34a:
	/* 0x34a: jle    1fb3 <generic_sleepable_preload+0x1fb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8115ULL;
	}
x86_l_350:
	/* 0x350: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_358:
	/* 0x358: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_35b:
	/* 0x35b: je     1fca <generic_sleepable_preload+0x1fca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8138ULL;
	}
x86_l_361:
	/* 0x361: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_366:
	/* 0x366: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_369:
	/* 0x369: je     1fca <generic_sleepable_preload+0x1fca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8138ULL;
	}
x86_l_36f:
	/* 0x36f: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_372:
	/* 0x372: jne    1fdd <generic_sleepable_preload+0x1fdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8157ULL;
	}
x86_l_378:
	/* 0x378: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_37d:
	/* 0x37d: jmp    1fca <generic_sleepable_preload+0x1fca> */
	return 8138ULL;
x86_l_382:
	/* 0x382: movzx  eax,BYTE PTR [rbx+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_389:
	/* 0x389: movzx  ecx,WORD PTR [rbx+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_390:
	/* 0x390: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_396:
	/* 0x396: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_398:
	/* 0x398: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_39b:
	/* 0x39b: jle    7ed <generic_sleepable_preload+0x7ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2029ULL;
	}
x86_l_3a1:
	/* 0x3a1: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_3a4:
	/* 0x3a4: jle    8ce <generic_sleepable_preload+0x8ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2254ULL;
	}
x86_l_3aa:
	/* 0x3aa: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_3ad:
	/* 0x3ad: jle    22ae <generic_sleepable_preload+0x22ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8878ULL;
	}
x86_l_3b3:
	/* 0x3b3: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3bb:
	/* 0x3bb: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_3be:
	/* 0x3be: je     2672 <generic_sleepable_preload+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9842ULL;
	}
x86_l_3c4:
	/* 0x3c4: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3c9:
	/* 0x3c9: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_3cc:
	/* 0x3cc: je     2672 <generic_sleepable_preload+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9842ULL;
	}
x86_l_3d2:
	/* 0x3d2: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3d7:
	/* 0x3d7: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_3da:
	/* 0x3da: je     2672 <generic_sleepable_preload+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9842ULL;
	}
x86_l_3e0:
	/* 0x3e0: jmp    2685 <generic_sleepable_preload+0x2685> */
	return 9861ULL;
x86_l_3e5:
	/* 0x3e5: movzx  eax,BYTE PTR [rbx+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_3ec:
	/* 0x3ec: movzx  ecx,WORD PTR [rbx+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
x86_l_3f3:
	/* 0x3f3: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_3f9:
	/* 0x3f9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3fb:
	/* 0x3fb: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_3fe:
	/* 0x3fe: jle    81a <generic_sleepable_preload+0x81a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2074ULL;
	}
x86_l_404:
	/* 0x404: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_407:
	/* 0x407: jle    8fb <generic_sleepable_preload+0x8fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2299ULL;
	}
x86_l_40d:
	/* 0x40d: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_410:
	/* 0x410: jle    22d2 <generic_sleepable_preload+0x22d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8914ULL;
	}
x86_l_416:
	/* 0x416: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_41e:
	/* 0x41e: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_421:
	/* 0x421: je     2976 <generic_sleepable_preload+0x2976> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10614ULL;
	}
x86_l_427:
	/* 0x427: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_42c:
	/* 0x42c: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_42f:
	/* 0x42f: je     2976 <generic_sleepable_preload+0x2976> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10614ULL;
	}
x86_l_435:
	/* 0x435: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_43a:
	/* 0x43a: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_43d:
	/* 0x43d: je     2976 <generic_sleepable_preload+0x2976> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10614ULL;
	}
x86_l_443:
	/* 0x443: jmp    2989 <generic_sleepable_preload+0x2989> */
	return 10633ULL;
x86_l_448:
	/* 0x448: movzx  eax,BYTE PTR [rbx+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_44f:
	/* 0x44f: movzx  ecx,WORD PTR [rbx+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_456:
	/* 0x456: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_45c:
	/* 0x45c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_45e:
	/* 0x45e: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_461:
	/* 0x461: jle    847 <generic_sleepable_preload+0x847> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2119ULL;
	}
x86_l_467:
	/* 0x467: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_46a:
	/* 0x46a: jle    928 <generic_sleepable_preload+0x928> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2344ULL;
	}
x86_l_470:
	/* 0x470: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_473:
	/* 0x473: jle    22f6 <generic_sleepable_preload+0x22f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8950ULL;
	}
x86_l_479:
	/* 0x479: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_481:
	/* 0x481: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_484:
	/* 0x484: je     2c7a <generic_sleepable_preload+0x2c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11386ULL;
	}
x86_l_48a:
	/* 0x48a: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_48f:
	/* 0x48f: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_492:
	/* 0x492: je     2c7a <generic_sleepable_preload+0x2c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11386ULL;
	}
x86_l_498:
	/* 0x498: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_49d:
	/* 0x49d: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_4a0:
	/* 0x4a0: je     2c7a <generic_sleepable_preload+0x2c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11386ULL;
	}
x86_l_4a6:
	/* 0x4a6: jmp    2c8d <generic_sleepable_preload+0x2c8d> */
	return 11405ULL;
x86_l_4ab:
	/* 0x4ab: movzx  eax,BYTE PTR [rbx+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_4b2:
	/* 0x4b2: movzx  ecx,WORD PTR [rbx+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_4b9:
	/* 0x4b9: rorx   edx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_4bf:
	/* 0x4bf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c1:
	/* 0x4c1: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_4c4:
	/* 0x4c4: jle    874 <generic_sleepable_preload+0x874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2164ULL;
	}
x86_l_4ca:
	/* 0x4ca: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_4cd:
	/* 0x4cd: jle    955 <generic_sleepable_preload+0x955> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2389ULL;
	}
x86_l_4d3:
	/* 0x4d3: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_4d6:
	/* 0x4d6: jle    231a <generic_sleepable_preload+0x231a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8986ULL;
	}
x86_l_4dc:
	/* 0x4dc: mov    r14,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4e4:
	/* 0x4e4: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_4e7:
	/* 0x4e7: je     2331 <generic_sleepable_preload+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9009ULL;
	}
x86_l_4ed:
	/* 0x4ed: mov    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4f2:
	/* 0x4f2: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_4f5:
	/* 0x4f5: je     2331 <generic_sleepable_preload+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9009ULL;
	}
x86_l_4fb:
	/* 0x4fb: mov    r14,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_500:
	/* 0x500: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_503:
	/* 0x503: je     2331 <generic_sleepable_preload+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9009ULL;
	}
x86_l_509:
	/* 0x509: jmp    2344 <generic_sleepable_preload+0x2344> */
	return 9028ULL;
x86_l_50e:
	/* 0x50e: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_511:
	/* 0x511: je     b5d <generic_sleepable_preload+0xb5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2909ULL;
	}
x86_l_517:
	/* 0x517: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_51a:
	/* 0x51a: jne    bbf <generic_sleepable_preload+0xbbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3007ULL;
	}
x86_l_520:
	/* 0x520: mov    edx,DWORD PTR [rbx+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_526:
	/* 0x526: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_52c:
	/* 0x52c: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_52f:
	/* 0x52f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_534:
	/* 0x534: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_539:
	/* 0x539: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_53e:
	/* 0x53e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_543:
	/* 0x543: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_545:
	/* 0x545: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_547:
	/* 0x547: jne    bbc <generic_sleepable_preload+0xbbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3004ULL;
	}
x86_l_54d:
	/* 0x54d: mov    edx,DWORD PTR [rbx+0x20c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_553:
	/* 0x553: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_559:
	/* 0x559: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_55c:
	/* 0x55c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_55f:
	/* 0x55f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_564:
	/* 0x564: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_569:
	/* 0x569: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56e:
	/* 0x56e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_570:
	/* 0x570: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_572:
	/* 0x572: jne    bbc <generic_sleepable_preload+0xbbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3004ULL;
	}
x86_l_578:
	/* 0x578: movzx  eax,BYTE PTR [rbx+0x213] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 531ULL);
x86_l_57f:
	/* 0x57f: shlx   rax,QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_585:
	/* 0x585: mov    rcx,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_58c:
	/* 0x58c: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_591:
	/* 0x591: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_594:
	/* 0x594: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_599:
	/* 0x599: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_59e:
	/* 0x59e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5a3:
	/* 0x5a3: movzx  ecx,BYTE PTR [rbx+0x213] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 531ULL);
x86_l_5aa:
	/* 0x5aa: shlx   rcx,QWORD PTR [rsp],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_5b0:
	/* 0x5b0: mov    rdx,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_5b7:
	/* 0x5b7: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_5bc:
	/* 0x5bc: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
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
	/* 0x5c8: jne    bbc <generic_sleepable_preload+0xbbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3004ULL;
	}
x86_l_5ce:
	/* 0x5ce: jmp    a60 <generic_sleepable_preload+0xa60> */
	return 2656ULL;
x86_l_5d3:
	/* 0x5d3: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5d6:
	/* 0x5d6: je     eb3 <generic_sleepable_preload+0xeb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3763ULL;
	}
x86_l_5dc:
	/* 0x5dc: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_5df:
	/* 0x5df: jne    f60 <generic_sleepable_preload+0xf60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3936ULL;
	}
x86_l_5e5:
	/* 0x5e5: mov    edx,DWORD PTR [rbx+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_5eb:
	/* 0x5eb: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5f1:
	/* 0x5f1: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5f4:
	/* 0x5f4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5f9:
	/* 0x5f9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5fe:
	/* 0x5fe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_603:
	/* 0x603: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_608:
	/* 0x608: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60a:
	/* 0x60a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_60c:
	/* 0x60c: jne    f5d <generic_sleepable_preload+0xf5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3933ULL;
	}
x86_l_612:
	/* 0x612: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_617:
	/* 0x617: add    rcx,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 536ULL);
x86_l_61e:
	/* 0x61e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_623:
	/* 0x623: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_628:
	/* 0x628: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_62d:
	/* 0x62d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_632:
	/* 0x632: add    rdx,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 536ULL);
x86_l_639:
	/* 0x639: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_63e:
	/* 0x63e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_640:
	/* 0x640: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_642:
	/* 0x642: jne    f5d <generic_sleepable_preload+0xf5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3933ULL;
	}
x86_l_648:
	/* 0x648: jmp    a94 <generic_sleepable_preload+0xa94> */
	return 2708ULL;
x86_l_64d:
	/* 0x64d: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_650:
	/* 0x650: je     1266 <generic_sleepable_preload+0x1266> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4710ULL;
	}
x86_l_656:
	/* 0x656: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_659:
	/* 0x659: jne    1313 <generic_sleepable_preload+0x1313> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4883ULL;
	}
x86_l_65f:
	/* 0x65f: mov    edx,DWORD PTR [rbx+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_665:
	/* 0x665: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_66b:
	/* 0x66b: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_66e:
	/* 0x66e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_673:
	/* 0x673: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_678:
	/* 0x678: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_67d:
	/* 0x67d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_682:
	/* 0x682: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_684:
	/* 0x684: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_686:
	/* 0x686: jne    1310 <generic_sleepable_preload+0x1310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4880ULL;
	}
x86_l_68c:
	/* 0x68c: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_691:
	/* 0x691: add    rcx,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 560ULL);
x86_l_698:
	/* 0x698: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_69d:
	/* 0x69d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6a2:
	/* 0x6a2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_6a7:
	/* 0x6a7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6ac:
	/* 0x6ac: add    rdx,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 560ULL);
x86_l_6b3:
	/* 0x6b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6b8:
	/* 0x6b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ba:
	/* 0x6ba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6bc:
	/* 0x6bc: jne    1310 <generic_sleepable_preload+0x1310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4880ULL;
	}
x86_l_6c2:
	/* 0x6c2: jmp    acd <generic_sleepable_preload+0xacd> */
	return 2765ULL;
x86_l_6c7:
	/* 0x6c7: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6ca:
	/* 0x6ca: je     1619 <generic_sleepable_preload+0x1619> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5657ULL;
	}
x86_l_6d0:
	/* 0x6d0: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_6d3:
	/* 0x6d3: jne    16c6 <generic_sleepable_preload+0x16c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5830ULL;
	}
x86_l_6d9:
	/* 0x6d9: mov    edx,DWORD PTR [rbx+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_6df:
	/* 0x6df: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6e5:
	/* 0x6e5: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
	return 1768ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1768ULL: goto x86_l_6e8;
	case 1773ULL: goto x86_l_6ed;
	case 1778ULL: goto x86_l_6f2;
	case 1783ULL: goto x86_l_6f7;
	case 1788ULL: goto x86_l_6fc;
	case 1790ULL: goto x86_l_6fe;
	case 1792ULL: goto x86_l_700;
	case 1798ULL: goto x86_l_706;
	case 1803ULL: goto x86_l_70b;
	case 1810ULL: goto x86_l_712;
	case 1815ULL: goto x86_l_717;
	case 1820ULL: goto x86_l_71c;
	case 1825ULL: goto x86_l_721;
	case 1830ULL: goto x86_l_726;
	case 1837ULL: goto x86_l_72d;
	case 1842ULL: goto x86_l_732;
	case 1844ULL: goto x86_l_734;
	case 1846ULL: goto x86_l_736;
	case 1852ULL: goto x86_l_73c;
	case 1857ULL: goto x86_l_741;
	case 1860ULL: goto x86_l_744;
	case 1866ULL: goto x86_l_74a;
	case 1869ULL: goto x86_l_74d;
	case 1875ULL: goto x86_l_753;
	case 1881ULL: goto x86_l_759;
	case 1886ULL: goto x86_l_75e;
	case 1889ULL: goto x86_l_761;
	case 1894ULL: goto x86_l_766;
	case 1899ULL: goto x86_l_76b;
	case 1904ULL: goto x86_l_770;
	case 1909ULL: goto x86_l_775;
	case 1912ULL: goto x86_l_778;
	case 1914ULL: goto x86_l_77a;
	case 1916ULL: goto x86_l_77c;
	case 1922ULL: goto x86_l_782;
	case 1927ULL: goto x86_l_787;
	case 1934ULL: goto x86_l_78e;
	case 1939ULL: goto x86_l_793;
	case 1944ULL: goto x86_l_798;
	case 1949ULL: goto x86_l_79d;
	case 1954ULL: goto x86_l_7a2;
	case 1961ULL: goto x86_l_7a9;
	case 1966ULL: goto x86_l_7ae;
	case 1968ULL: goto x86_l_7b0;
	case 1970ULL: goto x86_l_7b2;
	case 1976ULL: goto x86_l_7b8;
	case 1981ULL: goto x86_l_7bd;
	case 1984ULL: goto x86_l_7c0;
	case 1990ULL: goto x86_l_7c6;
	case 1993ULL: goto x86_l_7c9;
	case 1999ULL: goto x86_l_7cf;
	case 2002ULL: goto x86_l_7d2;
	case 2004ULL: goto x86_l_7d4;
	case 2010ULL: goto x86_l_7da;
	case 2015ULL: goto x86_l_7df;
	case 2018ULL: goto x86_l_7e2;
	case 2024ULL: goto x86_l_7e8;
	case 2029ULL: goto x86_l_7ed;
	case 2032ULL: goto x86_l_7f0;
	case 2038ULL: goto x86_l_7f6;
	case 2041ULL: goto x86_l_7f9;
	case 2047ULL: goto x86_l_7ff;
	case 2049ULL: goto x86_l_801;
	case 2055ULL: goto x86_l_807;
	case 2060ULL: goto x86_l_80c;
	case 2063ULL: goto x86_l_80f;
	case 2069ULL: goto x86_l_815;
	case 2074ULL: goto x86_l_81a;
	case 2077ULL: goto x86_l_81d;
	case 2083ULL: goto x86_l_823;
	case 2086ULL: goto x86_l_826;
	case 2092ULL: goto x86_l_82c;
	case 2094ULL: goto x86_l_82e;
	case 2100ULL: goto x86_l_834;
	case 2105ULL: goto x86_l_839;
	case 2108ULL: goto x86_l_83c;
	case 2114ULL: goto x86_l_842;
	case 2119ULL: goto x86_l_847;
	case 2122ULL: goto x86_l_84a;
	case 2128ULL: goto x86_l_850;
	case 2131ULL: goto x86_l_853;
	case 2137ULL: goto x86_l_859;
	case 2139ULL: goto x86_l_85b;
	case 2145ULL: goto x86_l_861;
	case 2150ULL: goto x86_l_866;
	case 2153ULL: goto x86_l_869;
	case 2159ULL: goto x86_l_86f;
	case 2164ULL: goto x86_l_874;
	case 2167ULL: goto x86_l_877;
	case 2173ULL: goto x86_l_87d;
	case 2176ULL: goto x86_l_880;
	case 2182ULL: goto x86_l_886;
	case 2184ULL: goto x86_l_888;
	case 2190ULL: goto x86_l_88e;
	case 2193ULL: goto x86_l_891;
	case 2198ULL: goto x86_l_896;
	case 2204ULL: goto x86_l_89c;
	case 2209ULL: goto x86_l_8a1;
	case 2212ULL: goto x86_l_8a4;
	case 2218ULL: goto x86_l_8aa;
	case 2226ULL: goto x86_l_8b2;
	case 2229ULL: goto x86_l_8b5;
	case 2235ULL: goto x86_l_8bb;
	case 2240ULL: goto x86_l_8c0;
	case 2243ULL: goto x86_l_8c3;
	case 2249ULL: goto x86_l_8c9;
	case 2254ULL: goto x86_l_8ce;
	case 2257ULL: goto x86_l_8d1;
	case 2263ULL: goto x86_l_8d7;
	case 2271ULL: goto x86_l_8df;
	case 2274ULL: goto x86_l_8e2;
	case 2280ULL: goto x86_l_8e8;
	case 2285ULL: goto x86_l_8ed;
	case 2288ULL: goto x86_l_8f0;
	case 2294ULL: goto x86_l_8f6;
	case 2299ULL: goto x86_l_8fb;
	case 2302ULL: goto x86_l_8fe;
	case 2308ULL: goto x86_l_904;
	case 2316ULL: goto x86_l_90c;
	case 2319ULL: goto x86_l_90f;
	case 2325ULL: goto x86_l_915;
	case 2330ULL: goto x86_l_91a;
	case 2333ULL: goto x86_l_91d;
	case 2339ULL: goto x86_l_923;
	case 2344ULL: goto x86_l_928;
	case 2347ULL: goto x86_l_92b;
	case 2353ULL: goto x86_l_931;
	case 2361ULL: goto x86_l_939;
	case 2364ULL: goto x86_l_93c;
	case 2370ULL: goto x86_l_942;
	case 2375ULL: goto x86_l_947;
	case 2378ULL: goto x86_l_94a;
	case 2384ULL: goto x86_l_950;
	case 2389ULL: goto x86_l_955;
	case 2392ULL: goto x86_l_958;
	case 2398ULL: goto x86_l_95e;
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
	case 2633ULL: goto x86_l_a49;
	case 2639ULL: goto x86_l_a4f;
	case 2644ULL: goto x86_l_a54;
	case 2651ULL: goto x86_l_a5b;
	case 2656ULL: goto x86_l_a60;
	case 2663ULL: goto x86_l_a67;
	case 2670ULL: goto x86_l_a6e;
	case 2677ULL: goto x86_l_a75;
	case 2682ULL: goto x86_l_a7a;
	case 2687ULL: goto x86_l_a7f;
	case 2691ULL: goto x86_l_a83;
	case 2696ULL: goto x86_l_a88;
	case 2703ULL: goto x86_l_a8f;
	case 2708ULL: goto x86_l_a94;
	case 2715ULL: goto x86_l_a9b;
	case 2722ULL: goto x86_l_aa2;
	case 2727ULL: goto x86_l_aa7;
	case 2734ULL: goto x86_l_aae;
	case 2739ULL: goto x86_l_ab3;
	case 2744ULL: goto x86_l_ab8;
	case 2748ULL: goto x86_l_abc;
	case 2753ULL: goto x86_l_ac1;
	case 2760ULL: goto x86_l_ac8;
	case 2765ULL: goto x86_l_acd;
	case 2772ULL: goto x86_l_ad4;
	case 2779ULL: goto x86_l_adb;
	case 2786ULL: goto x86_l_ae2;
	case 2791ULL: goto x86_l_ae7;
	case 2796ULL: goto x86_l_aec;
	case 2800ULL: goto x86_l_af0;
	case 2805ULL: goto x86_l_af5;
	case 2812ULL: goto x86_l_afc;
	case 2817ULL: goto x86_l_b01;
	case 2824ULL: goto x86_l_b08;
	case 2831ULL: goto x86_l_b0f;
	case 2838ULL: goto x86_l_b16;
	case 2843ULL: goto x86_l_b1b;
	case 2848ULL: goto x86_l_b20;
	case 2852ULL: goto x86_l_b24;
	case 2857ULL: goto x86_l_b29;
	case 2864ULL: goto x86_l_b30;
	case 2869ULL: goto x86_l_b35;
	case 2876ULL: goto x86_l_b3c;
	case 2883ULL: goto x86_l_b43;
	case 2890ULL: goto x86_l_b4a;
	case 2895ULL: goto x86_l_b4f;
	case 2900ULL: goto x86_l_b54;
	case 2904ULL: goto x86_l_b58;
	case 2909ULL: goto x86_l_b5d;
	case 2915ULL: goto x86_l_b63;
	case 2921ULL: goto x86_l_b69;
	case 2924ULL: goto x86_l_b6c;
	case 2929ULL: goto x86_l_b71;
	case 2934ULL: goto x86_l_b76;
	case 2939ULL: goto x86_l_b7b;
	case 2944ULL: goto x86_l_b80;
	case 2946ULL: goto x86_l_b82;
	case 2948ULL: goto x86_l_b84;
	case 2950ULL: goto x86_l_b86;
	case 2955ULL: goto x86_l_b8b;
	case 2962ULL: goto x86_l_b92;
	case 2967ULL: goto x86_l_b97;
	case 2972ULL: goto x86_l_b9c;
	case 2977ULL: goto x86_l_ba1;
	case 2982ULL: goto x86_l_ba6;
	case 2989ULL: goto x86_l_bad;
	case 2994ULL: goto x86_l_bb2;
	case 2996ULL: goto x86_l_bb4;
	case 2998ULL: goto x86_l_bb6;
	case 3004ULL: goto x86_l_bbc;
	case 3007ULL: goto x86_l_bbf;
	case 3012ULL: goto x86_l_bc4;
	case 3015ULL: goto x86_l_bc7;
	case 3018ULL: goto x86_l_bca;
	case 3023ULL: goto x86_l_bcf;
	case 3029ULL: goto x86_l_bd5;
	case 3032ULL: goto x86_l_bd8;
	case 3035ULL: goto x86_l_bdb;
	case 3040ULL: goto x86_l_be0;
	case 3045ULL: goto x86_l_be5;
	case 3047ULL: goto x86_l_be7;
	case 3052ULL: goto x86_l_bec;
	case 3057ULL: goto x86_l_bf1;
	case 3062ULL: goto x86_l_bf6;
	case 3067ULL: goto x86_l_bfb;
	case 3072ULL: goto x86_l_c00;
	case 3074ULL: goto x86_l_c02;
	case 3076ULL: goto x86_l_c04;
	case 3082ULL: goto x86_l_c0a;
	case 3087ULL: goto x86_l_c0f;
	case 3093ULL: goto x86_l_c15;
	case 3096ULL: goto x86_l_c18;
	case 3101ULL: goto x86_l_c1d;
	case 3106ULL: goto x86_l_c22;
	case 3111ULL: goto x86_l_c27;
	case 3113ULL: goto x86_l_c29;
	case 3118ULL: goto x86_l_c2e;
	case 3123ULL: goto x86_l_c33;
	case 3128ULL: goto x86_l_c38;
	case 3133ULL: goto x86_l_c3d;
	case 3138ULL: goto x86_l_c42;
	case 3140ULL: goto x86_l_c44;
	case 3142ULL: goto x86_l_c46;
	case 3148ULL: goto x86_l_c4c;
	case 3156ULL: goto x86_l_c54;
	case 3162ULL: goto x86_l_c5a;
	case 3168ULL: goto x86_l_c60;
	case 3173ULL: goto x86_l_c65;
	case 3178ULL: goto x86_l_c6a;
	case 3186ULL: goto x86_l_c72;
	case 3188ULL: goto x86_l_c74;
	case 3193ULL: goto x86_l_c79;
	case 3198ULL: goto x86_l_c7e;
	case 3203ULL: goto x86_l_c83;
	case 3208ULL: goto x86_l_c88;
	case 3213ULL: goto x86_l_c8d;
	case 3215ULL: goto x86_l_c8f;
	case 3217ULL: goto x86_l_c91;
	case 3223ULL: goto x86_l_c97;
	case 3231ULL: goto x86_l_c9f;
	case 3237ULL: goto x86_l_ca5;
	case 3243ULL: goto x86_l_cab;
	case 3248ULL: goto x86_l_cb0;
	case 3253ULL: goto x86_l_cb5;
	case 3261ULL: goto x86_l_cbd;
	case 3263ULL: goto x86_l_cbf;
	case 3268ULL: goto x86_l_cc4;
	case 3273ULL: goto x86_l_cc9;
	case 3278ULL: goto x86_l_cce;
	case 3283ULL: goto x86_l_cd3;
	case 3288ULL: goto x86_l_cd8;
	case 3290ULL: goto x86_l_cda;
	case 3292ULL: goto x86_l_cdc;
	case 3298ULL: goto x86_l_ce2;
	case 3306ULL: goto x86_l_cea;
	case 3312ULL: goto x86_l_cf0;
	case 3318ULL: goto x86_l_cf6;
	case 3323ULL: goto x86_l_cfb;
	case 3328ULL: goto x86_l_d00;
	case 3336ULL: goto x86_l_d08;
	case 3338ULL: goto x86_l_d0a;
	case 3343ULL: goto x86_l_d0f;
	case 3348ULL: goto x86_l_d14;
	case 3353ULL: goto x86_l_d19;
	case 3358ULL: goto x86_l_d1e;
	case 3363ULL: goto x86_l_d23;
	case 3365ULL: goto x86_l_d25;
	case 3367ULL: goto x86_l_d27;
	case 3373ULL: goto x86_l_d2d;
	case 3381ULL: goto x86_l_d35;
	case 3387ULL: goto x86_l_d3b;
	case 3393ULL: goto x86_l_d41;
	case 3398ULL: goto x86_l_d46;
	case 3403ULL: goto x86_l_d4b;
	case 3411ULL: goto x86_l_d53;
	case 3413ULL: goto x86_l_d55;
	case 3418ULL: goto x86_l_d5a;
	case 3423ULL: goto x86_l_d5f;
	case 3428ULL: goto x86_l_d64;
	case 3433ULL: goto x86_l_d69;
	case 3438ULL: goto x86_l_d6e;
	case 3440ULL: goto x86_l_d70;
	case 3442ULL: goto x86_l_d72;
	case 3448ULL: goto x86_l_d78;
	case 3456ULL: goto x86_l_d80;
	case 3462ULL: goto x86_l_d86;
	case 3468ULL: goto x86_l_d8c;
	case 3473ULL: goto x86_l_d91;
	case 3478ULL: goto x86_l_d96;
	case 3486ULL: goto x86_l_d9e;
	case 3488ULL: goto x86_l_da0;
	case 3493ULL: goto x86_l_da5;
	case 3498ULL: goto x86_l_daa;
	case 3503ULL: goto x86_l_daf;
	case 3508ULL: goto x86_l_db4;
	case 3513ULL: goto x86_l_db9;
	case 3515ULL: goto x86_l_dbb;
	case 3517ULL: goto x86_l_dbd;
	case 3523ULL: goto x86_l_dc3;
	case 3531ULL: goto x86_l_dcb;
	case 3537ULL: goto x86_l_dd1;
	case 3543ULL: goto x86_l_dd7;
	case 3548ULL: goto x86_l_ddc;
	case 3553ULL: goto x86_l_de1;
	case 3561ULL: goto x86_l_de9;
	case 3563ULL: goto x86_l_deb;
	case 3568ULL: goto x86_l_df0;
	case 3573ULL: goto x86_l_df5;
	case 3578ULL: goto x86_l_dfa;
	case 3583ULL: goto x86_l_dff;
	case 3588ULL: goto x86_l_e04;
	case 3590ULL: goto x86_l_e06;
	case 3592ULL: goto x86_l_e08;
	case 3598ULL: goto x86_l_e0e;
	case 3606ULL: goto x86_l_e16;
	case 3612ULL: goto x86_l_e1c;
	case 3618ULL: goto x86_l_e22;
	case 3623ULL: goto x86_l_e27;
	case 3628ULL: goto x86_l_e2c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6e8:
	/* 0x6e8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6ed:
	/* 0x6ed: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6f2:
	/* 0x6f2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6f7:
	/* 0x6f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6fc:
	/* 0x6fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6fe:
	/* 0x6fe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_700:
	/* 0x700: jne    16c3 <generic_sleepable_preload+0x16c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5827ULL;
	}
x86_l_706:
	/* 0x706: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_70b:
	/* 0x70b: add    rcx,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 584ULL);
x86_l_712:
	/* 0x712: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_717:
	/* 0x717: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_71c:
	/* 0x71c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_721:
	/* 0x721: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_726:
	/* 0x726: add    rdx,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 584ULL);
x86_l_72d:
	/* 0x72d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_732:
	/* 0x732: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_734:
	/* 0x734: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_736:
	/* 0x736: jne    16c3 <generic_sleepable_preload+0x16c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5827ULL;
	}
x86_l_73c:
	/* 0x73c: jmp    b01 <generic_sleepable_preload+0xb01> */
	goto x86_l_b01;
x86_l_741:
	/* 0x741: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_744:
	/* 0x744: je     19cc <generic_sleepable_preload+0x19cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6604ULL;
	}
x86_l_74a:
	/* 0x74a: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_74d:
	/* 0x74d: jne    1a7b <generic_sleepable_preload+0x1a7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6779ULL;
	}
x86_l_753:
	/* 0x753: mov    eax,DWORD PTR [rbx+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_759:
	/* 0x759: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_75e:
	/* 0x75e: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_761:
	/* 0x761: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_766:
	/* 0x766: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_76b:
	/* 0x76b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_770:
	/* 0x770: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_775:
	/* 0x775: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_778:
	/* 0x778: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_77a:
	/* 0x77a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_77c:
	/* 0x77c: jne    1a78 <generic_sleepable_preload+0x1a78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6776ULL;
	}
x86_l_782:
	/* 0x782: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_787:
	/* 0x787: add    rcx,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 608ULL);
x86_l_78e:
	/* 0x78e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_793:
	/* 0x793: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_798:
	/* 0x798: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_79d:
	/* 0x79d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7a2:
	/* 0x7a2: add    rdx,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 608ULL);
x86_l_7a9:
	/* 0x7a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7ae:
	/* 0x7ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b0:
	/* 0x7b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7b2:
	/* 0x7b2: jne    1a78 <generic_sleepable_preload+0x1a78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6776ULL;
	}
x86_l_7b8:
	/* 0x7b8: jmp    b35 <generic_sleepable_preload+0xb35> */
	goto x86_l_b35;
x86_l_7bd:
	/* 0x7bd: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_7c0:
	/* 0x7c0: jg     982 <generic_sleepable_preload+0x982> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_982;
	}
x86_l_7c6:
	/* 0x7c6: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_7c9:
	/* 0x7c9: jg     1e69 <generic_sleepable_preload+0x1e69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7785ULL;
	}
x86_l_7cf:
	/* 0x7cf: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_7d2:
	/* 0x7d2: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_7d4:
	/* 0x7d4: je     1fca <generic_sleepable_preload+0x1fca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8138ULL;
	}
x86_l_7da:
	/* 0x7da: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7df:
	/* 0x7df: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_7e2:
	/* 0x7e2: je     1fca <generic_sleepable_preload+0x1fca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8138ULL;
	}
x86_l_7e8:
	/* 0x7e8: jmp    1fdd <generic_sleepable_preload+0x1fdd> */
	return 8157ULL;
x86_l_7ed:
	/* 0x7ed: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_7f0:
	/* 0x7f0: jg     9ac <generic_sleepable_preload+0x9ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_9ac;
	}
x86_l_7f6:
	/* 0x7f6: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_7f9:
	/* 0x7f9: jg     1e8a <generic_sleepable_preload+0x1e8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7818ULL;
	}
x86_l_7ff:
	/* 0x7ff: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_801:
	/* 0x801: je     266f <generic_sleepable_preload+0x266f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9839ULL;
	}
x86_l_807:
	/* 0x807: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_80c:
	/* 0x80c: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_80f:
	/* 0x80f: je     2672 <generic_sleepable_preload+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9842ULL;
	}
x86_l_815:
	/* 0x815: jmp    2685 <generic_sleepable_preload+0x2685> */
	return 9861ULL;
x86_l_81a:
	/* 0x81a: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_81d:
	/* 0x81d: jg     9d6 <generic_sleepable_preload+0x9d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_9d6;
	}
x86_l_823:
	/* 0x823: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_826:
	/* 0x826: jg     1eab <generic_sleepable_preload+0x1eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7851ULL;
	}
x86_l_82c:
	/* 0x82c: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_82e:
	/* 0x82e: je     2973 <generic_sleepable_preload+0x2973> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10611ULL;
	}
x86_l_834:
	/* 0x834: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_839:
	/* 0x839: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_83c:
	/* 0x83c: je     2976 <generic_sleepable_preload+0x2976> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10614ULL;
	}
x86_l_842:
	/* 0x842: jmp    2989 <generic_sleepable_preload+0x2989> */
	return 10633ULL;
x86_l_847:
	/* 0x847: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_84a:
	/* 0x84a: jg     a00 <generic_sleepable_preload+0xa00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_a00;
	}
x86_l_850:
	/* 0x850: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_853:
	/* 0x853: jg     1ecc <generic_sleepable_preload+0x1ecc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7884ULL;
	}
x86_l_859:
	/* 0x859: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_85b:
	/* 0x85b: je     2c77 <generic_sleepable_preload+0x2c77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11383ULL;
	}
x86_l_861:
	/* 0x861: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_866:
	/* 0x866: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_869:
	/* 0x869: je     2c7a <generic_sleepable_preload+0x2c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11386ULL;
	}
x86_l_86f:
	/* 0x86f: jmp    2c8d <generic_sleepable_preload+0x2c8d> */
	return 11405ULL;
x86_l_874:
	/* 0x874: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_877:
	/* 0x877: jg     a2a <generic_sleepable_preload+0xa2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_a2a;
	}
x86_l_87d:
	/* 0x87d: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_880:
	/* 0x880: jg     1eed <generic_sleepable_preload+0x1eed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7917ULL;
	}
x86_l_886:
	/* 0x886: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_888:
	/* 0x888: je     2331 <generic_sleepable_preload+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9009ULL;
	}
x86_l_88e:
	/* 0x88e: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_891:
	/* 0x891: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_896:
	/* 0x896: je     2331 <generic_sleepable_preload+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9009ULL;
	}
x86_l_89c:
	/* 0x89c: jmp    2344 <generic_sleepable_preload+0x2344> */
	return 9028ULL;
x86_l_8a1:
	/* 0x8a1: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_8a4:
	/* 0x8a4: jg     1db5 <generic_sleepable_preload+0x1db5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7605ULL;
	}
x86_l_8aa:
	/* 0x8aa: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8b2:
	/* 0x8b2: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_8b5:
	/* 0x8b5: je     1fca <generic_sleepable_preload+0x1fca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8138ULL;
	}
x86_l_8bb:
	/* 0x8bb: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_8c0:
	/* 0x8c0: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_8c3:
	/* 0x8c3: je     1fca <generic_sleepable_preload+0x1fca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8138ULL;
	}
x86_l_8c9:
	/* 0x8c9: jmp    1fdd <generic_sleepable_preload+0x1fdd> */
	return 8157ULL;
x86_l_8ce:
	/* 0x8ce: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_8d1:
	/* 0x8d1: jg     1dd9 <generic_sleepable_preload+0x1dd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7641ULL;
	}
x86_l_8d7:
	/* 0x8d7: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8df:
	/* 0x8df: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_8e2:
	/* 0x8e2: je     2672 <generic_sleepable_preload+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9842ULL;
	}
x86_l_8e8:
	/* 0x8e8: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_8ed:
	/* 0x8ed: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_8f0:
	/* 0x8f0: je     2672 <generic_sleepable_preload+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9842ULL;
	}
x86_l_8f6:
	/* 0x8f6: jmp    2685 <generic_sleepable_preload+0x2685> */
	return 9861ULL;
x86_l_8fb:
	/* 0x8fb: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_8fe:
	/* 0x8fe: jg     1dfd <generic_sleepable_preload+0x1dfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7677ULL;
	}
x86_l_904:
	/* 0x904: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_90c:
	/* 0x90c: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_90f:
	/* 0x90f: je     2976 <generic_sleepable_preload+0x2976> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10614ULL;
	}
x86_l_915:
	/* 0x915: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_91a:
	/* 0x91a: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_91d:
	/* 0x91d: je     2976 <generic_sleepable_preload+0x2976> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10614ULL;
	}
x86_l_923:
	/* 0x923: jmp    2989 <generic_sleepable_preload+0x2989> */
	return 10633ULL;
x86_l_928:
	/* 0x928: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_92b:
	/* 0x92b: jg     1e21 <generic_sleepable_preload+0x1e21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7713ULL;
	}
x86_l_931:
	/* 0x931: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_939:
	/* 0x939: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_93c:
	/* 0x93c: je     2c7a <generic_sleepable_preload+0x2c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11386ULL;
	}
x86_l_942:
	/* 0x942: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_947:
	/* 0x947: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_94a:
	/* 0x94a: je     2c7a <generic_sleepable_preload+0x2c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11386ULL;
	}
x86_l_950:
	/* 0x950: jmp    2c8d <generic_sleepable_preload+0x2c8d> */
	return 11405ULL;
x86_l_955:
	/* 0x955: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_958:
	/* 0x958: jg     1e45 <generic_sleepable_preload+0x1e45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7749ULL;
	}
x86_l_95e:
	/* 0x95e: mov    r14,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_966:
	/* 0x966: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_969:
	/* 0x969: je     2331 <generic_sleepable_preload+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9009ULL;
	}
x86_l_96f:
	/* 0x96f: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_974:
	/* 0x974: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_977:
	/* 0x977: je     2331 <generic_sleepable_preload+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9009ULL;
	}
x86_l_97d:
	/* 0x97d: jmp    2344 <generic_sleepable_preload+0x2344> */
	return 9028ULL;
x86_l_982:
	/* 0x982: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_985:
	/* 0x985: jg     1f0e <generic_sleepable_preload+0x1f0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7950ULL;
	}
x86_l_98b:
	/* 0x98b: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_990:
	/* 0x990: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_993:
	/* 0x993: je     1fca <generic_sleepable_preload+0x1fca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8138ULL;
	}
x86_l_999:
	/* 0x999: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_99e:
	/* 0x99e: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_9a1:
	/* 0x9a1: je     1fca <generic_sleepable_preload+0x1fca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8138ULL;
	}
x86_l_9a7:
	/* 0x9a7: jmp    1fdd <generic_sleepable_preload+0x1fdd> */
	return 8157ULL;
x86_l_9ac:
	/* 0x9ac: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_9af:
	/* 0x9af: jg     1f2f <generic_sleepable_preload+0x1f2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 7983ULL;
	}
x86_l_9b5:
	/* 0x9b5: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9ba:
	/* 0x9ba: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_9bd:
	/* 0x9bd: je     2672 <generic_sleepable_preload+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9842ULL;
	}
x86_l_9c3:
	/* 0x9c3: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9c8:
	/* 0x9c8: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_9cb:
	/* 0x9cb: je     2672 <generic_sleepable_preload+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9842ULL;
	}
x86_l_9d1:
	/* 0x9d1: jmp    2685 <generic_sleepable_preload+0x2685> */
	return 9861ULL;
x86_l_9d6:
	/* 0x9d6: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_9d9:
	/* 0x9d9: jg     1f50 <generic_sleepable_preload+0x1f50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8016ULL;
	}
x86_l_9df:
	/* 0x9df: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9e4:
	/* 0x9e4: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_9e7:
	/* 0x9e7: je     2976 <generic_sleepable_preload+0x2976> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10614ULL;
	}
x86_l_9ed:
	/* 0x9ed: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9f2:
	/* 0x9f2: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_9f5:
	/* 0x9f5: je     2976 <generic_sleepable_preload+0x2976> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10614ULL;
	}
x86_l_9fb:
	/* 0x9fb: jmp    2989 <generic_sleepable_preload+0x2989> */
	return 10633ULL;
x86_l_a00:
	/* 0xa00: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_a03:
	/* 0xa03: jg     1f71 <generic_sleepable_preload+0x1f71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8049ULL;
	}
x86_l_a09:
	/* 0xa09: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a0e:
	/* 0xa0e: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_a11:
	/* 0xa11: je     2c7a <generic_sleepable_preload+0x2c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11386ULL;
	}
x86_l_a17:
	/* 0xa17: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a1c:
	/* 0xa1c: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_a1f:
	/* 0xa1f: je     2c7a <generic_sleepable_preload+0x2c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11386ULL;
	}
x86_l_a25:
	/* 0xa25: jmp    2c8d <generic_sleepable_preload+0x2c8d> */
	return 11405ULL;
x86_l_a2a:
	/* 0xa2a: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_a2d:
	/* 0xa2d: jg     1f92 <generic_sleepable_preload+0x1f92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8082ULL;
	}
x86_l_a33:
	/* 0xa33: mov    r14,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a38:
	/* 0xa38: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_a3b:
	/* 0xa3b: je     2331 <generic_sleepable_preload+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9009ULL;
	}
x86_l_a41:
	/* 0xa41: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a46:
	/* 0xa46: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_a49:
	/* 0xa49: je     2331 <generic_sleepable_preload+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9009ULL;
	}
x86_l_a4f:
	/* 0xa4f: jmp    2344 <generic_sleepable_preload+0x2344> */
	return 9028ULL;
x86_l_a54:
	/* 0xa54: mov    rax,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_a5b:
	/* 0xa5b: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a60:
	/* 0xa60: movzx  eax,BYTE PTR [rbx+0x210] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 528ULL);
x86_l_a67:
	/* 0xa67: shlx   rcx,QWORD PTR [rsp+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((16ULL << 32) | X86_ALU_SHL));
x86_l_a6e:
	/* 0xa6e: cmp    BYTE PTR [rbx+0x212],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2276332666880ULL);
x86_l_a75:
	/* 0xa75: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_a7a:
	/* 0xa7a: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_a7f:
	/* 0xa7f: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_a83:
	/* 0xa83: jmp    bbf <generic_sleepable_preload+0xbbf> */
	goto x86_l_bbf;
x86_l_a88:
	/* 0xa88: mov    rax,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_a8f:
	/* 0xa8f: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a94:
	/* 0xa94: movzx  eax,BYTE PTR [rbx+0x228] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 552ULL);
x86_l_a9b:
	/* 0xa9b: shlx   rcx,QWORD PTR [rsp+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((16ULL << 32) | X86_ALU_SHL));
x86_l_aa2:
	/* 0xaa2: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_aa7:
	/* 0xaa7: cmp    BYTE PTR [rbx+0x22a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2379411881984ULL);
x86_l_aae:
	/* 0xaae: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_ab3:
	/* 0xab3: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_ab8:
	/* 0xab8: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_abc:
	/* 0xabc: jmp    f60 <generic_sleepable_preload+0xf60> */
	return 3936ULL;
x86_l_ac1:
	/* 0xac1: mov    rax,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_ac8:
	/* 0xac8: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_acd:
	/* 0xacd: movzx  eax,BYTE PTR [rbx+0x240] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 576ULL);
x86_l_ad4:
	/* 0xad4: shlx   rcx,QWORD PTR [rsp+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((16ULL << 32) | X86_ALU_SHL));
x86_l_adb:
	/* 0xadb: cmp    BYTE PTR [rbx+0x242],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2482491097088ULL);
x86_l_ae2:
	/* 0xae2: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_ae7:
	/* 0xae7: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_aec:
	/* 0xaec: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_af0:
	/* 0xaf0: jmp    1313 <generic_sleepable_preload+0x1313> */
	return 4883ULL;
x86_l_af5:
	/* 0xaf5: mov    rax,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_afc:
	/* 0xafc: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b01:
	/* 0xb01: movzx  eax,BYTE PTR [rbx+0x258] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 600ULL);
x86_l_b08:
	/* 0xb08: shlx   rcx,QWORD PTR [rsp+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((16ULL << 32) | X86_ALU_SHL));
x86_l_b0f:
	/* 0xb0f: cmp    BYTE PTR [rbx+0x25a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2585570312192ULL);
x86_l_b16:
	/* 0xb16: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_b1b:
	/* 0xb1b: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_b20:
	/* 0xb20: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_b24:
	/* 0xb24: jmp    16c6 <generic_sleepable_preload+0x16c6> */
	return 5830ULL;
x86_l_b29:
	/* 0xb29: mov    rax,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_b30:
	/* 0xb30: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b35:
	/* 0xb35: movzx  eax,BYTE PTR [rbx+0x270] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 624ULL);
x86_l_b3c:
	/* 0xb3c: shlx   rcx,QWORD PTR [rsp+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((16ULL << 32) | X86_ALU_SHL));
x86_l_b43:
	/* 0xb43: cmp    BYTE PTR [rbx+0x272],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2688649527296ULL);
x86_l_b4a:
	/* 0xb4a: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_b4f:
	/* 0xb4f: sarx   rcx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_b54:
	/* 0xb54: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_b58:
	/* 0xb58: jmp    1a7b <generic_sleepable_preload+0x1a7b> */
	return 6779ULL;
x86_l_b5d:
	/* 0xb5d: mov    edx,DWORD PTR [rbx+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_b63:
	/* 0xb63: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b69:
	/* 0xb69: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b6c:
	/* 0xb6c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b71:
	/* 0xb71: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b76:
	/* 0xb76: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b7b:
	/* 0xb7b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b80:
	/* 0xb80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b82:
	/* 0xb82: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b84:
	/* 0xb84: jne    bbc <generic_sleepable_preload+0xbbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_bbc;
	}
x86_l_b86:
	/* 0xb86: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b8b:
	/* 0xb8b: add    rcx,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 512ULL);
x86_l_b92:
	/* 0xb92: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b97:
	/* 0xb97: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b9c:
	/* 0xb9c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_ba1:
	/* 0xba1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ba6:
	/* 0xba6: add    rdx,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 512ULL);
x86_l_bad:
	/* 0xbad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bb2:
	/* 0xbb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb4:
	/* 0xbb4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bb6:
	/* 0xbb6: je     a60 <generic_sleepable_preload+0xa60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a60;
	}
x86_l_bbc:
	/* 0xbbc: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_bbf:
	/* 0xbbf: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bc4:
	/* 0xbc4: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bc7:
	/* 0xbc7: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_bca:
	/* 0xbca: cmp    WORD PTR [rbx+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_bcf:
	/* 0xbcf: je     3130 <generic_sleepable_preload+0x3130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12592ULL;
	}
x86_l_bd5:
	/* 0xbd5: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_bd8:
	/* 0xbd8: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_bdb:
	/* 0xbdb: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_be0:
	/* 0xbe0: cmp    WORD PTR [rbx+0x74],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_be5:
	/* 0xbe5: je     c0a <generic_sleepable_preload+0xc0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c0a;
	}
x86_l_be7:
	/* 0xbe7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bec:
	/* 0xbec: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_bf1:
	/* 0xbf1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_bf6:
	/* 0xbf6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bfb:
	/* 0xbfb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c00:
	/* 0xc00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c02:
	/* 0xc02: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c04:
	/* 0xc04: js     1d7f <generic_sleepable_preload+0x1d7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7551ULL;
	}
x86_l_c0a:
	/* 0xc0a: cmp    WORD PTR [rbx+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_c0f:
	/* 0xc0f: je     3130 <generic_sleepable_preload+0x3130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12592ULL;
	}
x86_l_c15:
	/* 0xc15: mov    ecx,DWORD PTR [rbx+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c18:
	/* 0xc18: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c1d:
	/* 0xc1d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c22:
	/* 0xc22: cmp    WORD PTR [rbx+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_c27:
	/* 0xc27: je     c4c <generic_sleepable_preload+0xc4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c4c;
	}
x86_l_c29:
	/* 0xc29: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c2e:
	/* 0xc2e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c33:
	/* 0xc33: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c38:
	/* 0xc38: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c3d:
	/* 0xc3d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c42:
	/* 0xc42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c44:
	/* 0xc44: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c46:
	/* 0xc46: js     2624 <generic_sleepable_preload+0x2624> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9764ULL;
	}
x86_l_c4c:
	/* 0xc4c: cmp    WORD PTR [rbx+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_c54:
	/* 0xc54: je     3130 <generic_sleepable_preload+0x3130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12592ULL;
	}
x86_l_c5a:
	/* 0xc5a: mov    ecx,DWORD PTR [rbx+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c60:
	/* 0xc60: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c65:
	/* 0xc65: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c6a:
	/* 0xc6a: cmp    WORD PTR [rbx+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_c72:
	/* 0xc72: je     c97 <generic_sleepable_preload+0xc97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c97;
	}
x86_l_c74:
	/* 0xc74: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c79:
	/* 0xc79: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c7e:
	/* 0xc7e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c83:
	/* 0xc83: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c88:
	/* 0xc88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c8d:
	/* 0xc8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c8f:
	/* 0xc8f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c91:
	/* 0xc91: js     2f7b <generic_sleepable_preload+0x2f7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12155ULL;
	}
x86_l_c97:
	/* 0xc97: cmp    WORD PTR [rbx+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_c9f:
	/* 0xc9f: je     3130 <generic_sleepable_preload+0x3130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12592ULL;
	}
x86_l_ca5:
	/* 0xca5: mov    ecx,DWORD PTR [rbx+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_cab:
	/* 0xcab: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_cb0:
	/* 0xcb0: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cb5:
	/* 0xcb5: cmp    WORD PTR [rbx+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_cbd:
	/* 0xcbd: je     ce2 <generic_sleepable_preload+0xce2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ce2;
	}
x86_l_cbf:
	/* 0xcbf: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cc4:
	/* 0xcc4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_cc9:
	/* 0xcc9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_cce:
	/* 0xcce: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cd3:
	/* 0xcd3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cd8:
	/* 0xcd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cda:
	/* 0xcda: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cdc:
	/* 0xcdc: js     2fe7 <generic_sleepable_preload+0x2fe7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12263ULL;
	}
x86_l_ce2:
	/* 0xce2: cmp    WORD PTR [rbx+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_cea:
	/* 0xcea: je     3130 <generic_sleepable_preload+0x3130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12592ULL;
	}
x86_l_cf0:
	/* 0xcf0: mov    ecx,DWORD PTR [rbx+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_cf6:
	/* 0xcf6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_cfb:
	/* 0xcfb: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d00:
	/* 0xd00: cmp    WORD PTR [rbx+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_d08:
	/* 0xd08: je     d2d <generic_sleepable_preload+0xd2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d2d;
	}
x86_l_d0a:
	/* 0xd0a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d0f:
	/* 0xd0f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d14:
	/* 0xd14: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d19:
	/* 0xd19: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d1e:
	/* 0xd1e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d23:
	/* 0xd23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d25:
	/* 0xd25: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d27:
	/* 0xd27: js     3053 <generic_sleepable_preload+0x3053> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12371ULL;
	}
x86_l_d2d:
	/* 0xd2d: cmp    WORD PTR [rbx+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_d35:
	/* 0xd35: je     3130 <generic_sleepable_preload+0x3130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12592ULL;
	}
x86_l_d3b:
	/* 0xd3b: mov    ecx,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_d41:
	/* 0xd41: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d46:
	/* 0xd46: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d4b:
	/* 0xd4b: cmp    WORD PTR [rbx+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_d53:
	/* 0xd53: je     d78 <generic_sleepable_preload+0xd78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d78;
	}
x86_l_d55:
	/* 0xd55: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d5a:
	/* 0xd5a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d5f:
	/* 0xd5f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d64:
	/* 0xd64: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d69:
	/* 0xd69: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d6e:
	/* 0xd6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d70:
	/* 0xd70: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d72:
	/* 0xd72: js     30bf <generic_sleepable_preload+0x30bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12479ULL;
	}
x86_l_d78:
	/* 0xd78: cmp    WORD PTR [rbx+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_d80:
	/* 0xd80: je     3130 <generic_sleepable_preload+0x3130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12592ULL;
	}
x86_l_d86:
	/* 0xd86: mov    ecx,DWORD PTR [rbx+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_d8c:
	/* 0xd8c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d91:
	/* 0xd91: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d96:
	/* 0xd96: cmp    WORD PTR [rbx+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_d9e:
	/* 0xd9e: je     dc3 <generic_sleepable_preload+0xdc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dc3;
	}
x86_l_da0:
	/* 0xda0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_da5:
	/* 0xda5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_daa:
	/* 0xdaa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_daf:
	/* 0xdaf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_db4:
	/* 0xdb4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_db9:
	/* 0xdb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dbb:
	/* 0xdbb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dbd:
	/* 0xdbd: js     3128 <generic_sleepable_preload+0x3128> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12584ULL;
	}
x86_l_dc3:
	/* 0xdc3: cmp    WORD PTR [rbx+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_dcb:
	/* 0xdcb: je     3130 <generic_sleepable_preload+0x3130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12592ULL;
	}
x86_l_dd1:
	/* 0xdd1: mov    ecx,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_dd7:
	/* 0xdd7: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ddc:
	/* 0xddc: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_de1:
	/* 0xde1: cmp    WORD PTR [rbx+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_de9:
	/* 0xde9: je     e0e <generic_sleepable_preload+0xe0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e0e;
	}
x86_l_deb:
	/* 0xdeb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_df0:
	/* 0xdf0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_df5:
	/* 0xdf5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_dfa:
	/* 0xdfa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dff:
	/* 0xdff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e04:
	/* 0xe04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e06:
	/* 0xe06: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e08:
	/* 0xe08: js     37a9 <generic_sleepable_preload+0x37a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14249ULL;
	}
x86_l_e0e:
	/* 0xe0e: cmp    WORD PTR [rbx+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_e16:
	/* 0xe16: je     3130 <generic_sleepable_preload+0x3130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12592ULL;
	}
x86_l_e1c:
	/* 0xe1c: mov    ecx,DWORD PTR [rbx+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_e22:
	/* 0xe22: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e27:
	/* 0xe27: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e2c:
	/* 0xe2c: cmp    WORD PTR [rbx+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
	return 3636ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3636ULL: goto x86_l_e34;
	case 3638ULL: goto x86_l_e36;
	case 3643ULL: goto x86_l_e3b;
	case 3648ULL: goto x86_l_e40;
	case 3653ULL: goto x86_l_e45;
	case 3658ULL: goto x86_l_e4a;
	case 3663ULL: goto x86_l_e4f;
	case 3665ULL: goto x86_l_e51;
	case 3667ULL: goto x86_l_e53;
	case 3673ULL: goto x86_l_e59;
	case 3681ULL: goto x86_l_e61;
	case 3687ULL: goto x86_l_e67;
	case 3693ULL: goto x86_l_e6d;
	case 3698ULL: goto x86_l_e72;
	case 3703ULL: goto x86_l_e77;
	case 3711ULL: goto x86_l_e7f;
	case 3717ULL: goto x86_l_e85;
	case 3722ULL: goto x86_l_e8a;
	case 3727ULL: goto x86_l_e8f;
	case 3732ULL: goto x86_l_e94;
	case 3737ULL: goto x86_l_e99;
	case 3742ULL: goto x86_l_e9e;
	case 3744ULL: goto x86_l_ea0;
	case 3746ULL: goto x86_l_ea2;
	case 3752ULL: goto x86_l_ea8;
	case 3758ULL: goto x86_l_eae;
	case 3763ULL: goto x86_l_eb3;
	case 3769ULL: goto x86_l_eb9;
	case 3775ULL: goto x86_l_ebf;
	case 3778ULL: goto x86_l_ec2;
	case 3783ULL: goto x86_l_ec7;
	case 3788ULL: goto x86_l_ecc;
	case 3793ULL: goto x86_l_ed1;
	case 3798ULL: goto x86_l_ed6;
	case 3800ULL: goto x86_l_ed8;
	case 3802ULL: goto x86_l_eda;
	case 3808ULL: goto x86_l_ee0;
	case 3814ULL: goto x86_l_ee6;
	case 3820ULL: goto x86_l_eec;
	case 3823ULL: goto x86_l_eef;
	case 3826ULL: goto x86_l_ef2;
	case 3831ULL: goto x86_l_ef7;
	case 3836ULL: goto x86_l_efc;
	case 3841ULL: goto x86_l_f01;
	case 3843ULL: goto x86_l_f03;
	case 3845ULL: goto x86_l_f05;
	case 3847ULL: goto x86_l_f07;
	case 3854ULL: goto x86_l_f0e;
	case 3860ULL: goto x86_l_f14;
	case 3867ULL: goto x86_l_f1b;
	case 3872ULL: goto x86_l_f20;
	case 3875ULL: goto x86_l_f23;
	case 3880ULL: goto x86_l_f28;
	case 3885ULL: goto x86_l_f2d;
	case 3890ULL: goto x86_l_f32;
	case 3897ULL: goto x86_l_f39;
	case 3903ULL: goto x86_l_f3f;
	case 3910ULL: goto x86_l_f46;
	case 3915ULL: goto x86_l_f4b;
	case 3918ULL: goto x86_l_f4e;
	case 3923ULL: goto x86_l_f53;
	case 3925ULL: goto x86_l_f55;
	case 3927ULL: goto x86_l_f57;
	case 3933ULL: goto x86_l_f5d;
	case 3936ULL: goto x86_l_f60;
	case 3941ULL: goto x86_l_f65;
	case 3944ULL: goto x86_l_f68;
	case 3947ULL: goto x86_l_f6b;
	case 3955ULL: goto x86_l_f73;
	case 3961ULL: goto x86_l_f79;
	case 3967ULL: goto x86_l_f7f;
	case 3970ULL: goto x86_l_f82;
	case 3975ULL: goto x86_l_f87;
	case 3983ULL: goto x86_l_f8f;
	case 3985ULL: goto x86_l_f91;
	case 3990ULL: goto x86_l_f96;
	case 3995ULL: goto x86_l_f9b;
	case 4000ULL: goto x86_l_fa0;
	case 4005ULL: goto x86_l_fa5;
	case 4010ULL: goto x86_l_faa;
	case 4012ULL: goto x86_l_fac;
	case 4014ULL: goto x86_l_fae;
	case 4020ULL: goto x86_l_fb4;
	case 4028ULL: goto x86_l_fbc;
	case 4034ULL: goto x86_l_fc2;
	case 4040ULL: goto x86_l_fc8;
	case 4045ULL: goto x86_l_fcd;
	case 4050ULL: goto x86_l_fd2;
	case 4058ULL: goto x86_l_fda;
	case 4060ULL: goto x86_l_fdc;
	case 4065ULL: goto x86_l_fe1;
	case 4070ULL: goto x86_l_fe6;
	case 4075ULL: goto x86_l_feb;
	case 4080ULL: goto x86_l_ff0;
	case 4085ULL: goto x86_l_ff5;
	case 4087ULL: goto x86_l_ff7;
	case 4089ULL: goto x86_l_ff9;
	case 4095ULL: goto x86_l_fff;
	case 4103ULL: goto x86_l_1007;
	case 4109ULL: goto x86_l_100d;
	case 4115ULL: goto x86_l_1013;
	case 4120ULL: goto x86_l_1018;
	case 4125ULL: goto x86_l_101d;
	case 4133ULL: goto x86_l_1025;
	case 4135ULL: goto x86_l_1027;
	case 4140ULL: goto x86_l_102c;
	case 4145ULL: goto x86_l_1031;
	case 4150ULL: goto x86_l_1036;
	case 4155ULL: goto x86_l_103b;
	case 4160ULL: goto x86_l_1040;
	case 4162ULL: goto x86_l_1042;
	case 4164ULL: goto x86_l_1044;
	case 4170ULL: goto x86_l_104a;
	case 4178ULL: goto x86_l_1052;
	case 4184ULL: goto x86_l_1058;
	case 4190ULL: goto x86_l_105e;
	case 4195ULL: goto x86_l_1063;
	case 4200ULL: goto x86_l_1068;
	case 4208ULL: goto x86_l_1070;
	case 4210ULL: goto x86_l_1072;
	case 4215ULL: goto x86_l_1077;
	case 4220ULL: goto x86_l_107c;
	case 4225ULL: goto x86_l_1081;
	case 4230ULL: goto x86_l_1086;
	case 4235ULL: goto x86_l_108b;
	case 4237ULL: goto x86_l_108d;
	case 4239ULL: goto x86_l_108f;
	case 4245ULL: goto x86_l_1095;
	case 4253ULL: goto x86_l_109d;
	case 4259ULL: goto x86_l_10a3;
	case 4265ULL: goto x86_l_10a9;
	case 4270ULL: goto x86_l_10ae;
	case 4275ULL: goto x86_l_10b3;
	case 4283ULL: goto x86_l_10bb;
	case 4285ULL: goto x86_l_10bd;
	case 4290ULL: goto x86_l_10c2;
	case 4295ULL: goto x86_l_10c7;
	case 4300ULL: goto x86_l_10cc;
	case 4305ULL: goto x86_l_10d1;
	case 4310ULL: goto x86_l_10d6;
	case 4312ULL: goto x86_l_10d8;
	case 4314ULL: goto x86_l_10da;
	case 4320ULL: goto x86_l_10e0;
	case 4328ULL: goto x86_l_10e8;
	case 4334ULL: goto x86_l_10ee;
	case 4340ULL: goto x86_l_10f4;
	case 4345ULL: goto x86_l_10f9;
	case 4350ULL: goto x86_l_10fe;
	case 4358ULL: goto x86_l_1106;
	case 4360ULL: goto x86_l_1108;
	case 4365ULL: goto x86_l_110d;
	case 4370ULL: goto x86_l_1112;
	case 4375ULL: goto x86_l_1117;
	case 4380ULL: goto x86_l_111c;
	case 4385ULL: goto x86_l_1121;
	case 4387ULL: goto x86_l_1123;
	case 4389ULL: goto x86_l_1125;
	case 4395ULL: goto x86_l_112b;
	case 4403ULL: goto x86_l_1133;
	case 4409ULL: goto x86_l_1139;
	case 4415ULL: goto x86_l_113f;
	case 4420ULL: goto x86_l_1144;
	case 4425ULL: goto x86_l_1149;
	case 4433ULL: goto x86_l_1151;
	case 4435ULL: goto x86_l_1153;
	case 4440ULL: goto x86_l_1158;
	case 4445ULL: goto x86_l_115d;
	case 4450ULL: goto x86_l_1162;
	case 4455ULL: goto x86_l_1167;
	case 4460ULL: goto x86_l_116c;
	case 4462ULL: goto x86_l_116e;
	case 4464ULL: goto x86_l_1170;
	case 4470ULL: goto x86_l_1176;
	case 4478ULL: goto x86_l_117e;
	case 4484ULL: goto x86_l_1184;
	case 4490ULL: goto x86_l_118a;
	case 4495ULL: goto x86_l_118f;
	case 4500ULL: goto x86_l_1194;
	case 4508ULL: goto x86_l_119c;
	case 4510ULL: goto x86_l_119e;
	case 4515ULL: goto x86_l_11a3;
	case 4520ULL: goto x86_l_11a8;
	case 4525ULL: goto x86_l_11ad;
	case 4530ULL: goto x86_l_11b2;
	case 4535ULL: goto x86_l_11b7;
	case 4537ULL: goto x86_l_11b9;
	case 4539ULL: goto x86_l_11bb;
	case 4545ULL: goto x86_l_11c1;
	case 4553ULL: goto x86_l_11c9;
	case 4559ULL: goto x86_l_11cf;
	case 4565ULL: goto x86_l_11d5;
	case 4570ULL: goto x86_l_11da;
	case 4575ULL: goto x86_l_11df;
	case 4583ULL: goto x86_l_11e7;
	case 4585ULL: goto x86_l_11e9;
	case 4590ULL: goto x86_l_11ee;
	case 4595ULL: goto x86_l_11f3;
	case 4600ULL: goto x86_l_11f8;
	case 4605ULL: goto x86_l_11fd;
	case 4610ULL: goto x86_l_1202;
	case 4612ULL: goto x86_l_1204;
	case 4614ULL: goto x86_l_1206;
	case 4620ULL: goto x86_l_120c;
	case 4628ULL: goto x86_l_1214;
	case 4634ULL: goto x86_l_121a;
	case 4640ULL: goto x86_l_1220;
	case 4645ULL: goto x86_l_1225;
	case 4650ULL: goto x86_l_122a;
	case 4658ULL: goto x86_l_1232;
	case 4664ULL: goto x86_l_1238;
	case 4669ULL: goto x86_l_123d;
	case 4674ULL: goto x86_l_1242;
	case 4679ULL: goto x86_l_1247;
	case 4684ULL: goto x86_l_124c;
	case 4689ULL: goto x86_l_1251;
	case 4691ULL: goto x86_l_1253;
	case 4693ULL: goto x86_l_1255;
	case 4699ULL: goto x86_l_125b;
	case 4705ULL: goto x86_l_1261;
	case 4710ULL: goto x86_l_1266;
	case 4716ULL: goto x86_l_126c;
	case 4722ULL: goto x86_l_1272;
	case 4725ULL: goto x86_l_1275;
	case 4730ULL: goto x86_l_127a;
	case 4735ULL: goto x86_l_127f;
	case 4740ULL: goto x86_l_1284;
	case 4745ULL: goto x86_l_1289;
	case 4747ULL: goto x86_l_128b;
	case 4749ULL: goto x86_l_128d;
	case 4755ULL: goto x86_l_1293;
	case 4761ULL: goto x86_l_1299;
	case 4767ULL: goto x86_l_129f;
	case 4770ULL: goto x86_l_12a2;
	case 4773ULL: goto x86_l_12a5;
	case 4778ULL: goto x86_l_12aa;
	case 4783ULL: goto x86_l_12af;
	case 4788ULL: goto x86_l_12b4;
	case 4790ULL: goto x86_l_12b6;
	case 4792ULL: goto x86_l_12b8;
	case 4794ULL: goto x86_l_12ba;
	case 4801ULL: goto x86_l_12c1;
	case 4807ULL: goto x86_l_12c7;
	case 4814ULL: goto x86_l_12ce;
	case 4819ULL: goto x86_l_12d3;
	case 4822ULL: goto x86_l_12d6;
	case 4827ULL: goto x86_l_12db;
	case 4832ULL: goto x86_l_12e0;
	case 4837ULL: goto x86_l_12e5;
	case 4844ULL: goto x86_l_12ec;
	case 4850ULL: goto x86_l_12f2;
	case 4857ULL: goto x86_l_12f9;
	case 4862ULL: goto x86_l_12fe;
	case 4865ULL: goto x86_l_1301;
	case 4870ULL: goto x86_l_1306;
	case 4872ULL: goto x86_l_1308;
	case 4874ULL: goto x86_l_130a;
	case 4880ULL: goto x86_l_1310;
	case 4883ULL: goto x86_l_1313;
	case 4888ULL: goto x86_l_1318;
	case 4891ULL: goto x86_l_131b;
	case 4894ULL: goto x86_l_131e;
	case 4902ULL: goto x86_l_1326;
	case 4908ULL: goto x86_l_132c;
	case 4914ULL: goto x86_l_1332;
	case 4917ULL: goto x86_l_1335;
	case 4922ULL: goto x86_l_133a;
	case 4930ULL: goto x86_l_1342;
	case 4932ULL: goto x86_l_1344;
	case 4937ULL: goto x86_l_1349;
	case 4942ULL: goto x86_l_134e;
	case 4947ULL: goto x86_l_1353;
	case 4952ULL: goto x86_l_1358;
	case 4957ULL: goto x86_l_135d;
	case 4959ULL: goto x86_l_135f;
	case 4961ULL: goto x86_l_1361;
	case 4967ULL: goto x86_l_1367;
	case 4975ULL: goto x86_l_136f;
	case 4981ULL: goto x86_l_1375;
	case 4987ULL: goto x86_l_137b;
	case 4992ULL: goto x86_l_1380;
	case 4997ULL: goto x86_l_1385;
	case 5005ULL: goto x86_l_138d;
	case 5007ULL: goto x86_l_138f;
	case 5012ULL: goto x86_l_1394;
	case 5017ULL: goto x86_l_1399;
	case 5022ULL: goto x86_l_139e;
	case 5027ULL: goto x86_l_13a3;
	case 5032ULL: goto x86_l_13a8;
	case 5034ULL: goto x86_l_13aa;
	case 5036ULL: goto x86_l_13ac;
	case 5042ULL: goto x86_l_13b2;
	case 5050ULL: goto x86_l_13ba;
	case 5056ULL: goto x86_l_13c0;
	case 5062ULL: goto x86_l_13c6;
	case 5067ULL: goto x86_l_13cb;
	case 5072ULL: goto x86_l_13d0;
	case 5080ULL: goto x86_l_13d8;
	case 5082ULL: goto x86_l_13da;
	case 5087ULL: goto x86_l_13df;
	case 5092ULL: goto x86_l_13e4;
	case 5097ULL: goto x86_l_13e9;
	case 5102ULL: goto x86_l_13ee;
	case 5107ULL: goto x86_l_13f3;
	case 5109ULL: goto x86_l_13f5;
	case 5111ULL: goto x86_l_13f7;
	case 5117ULL: goto x86_l_13fd;
	case 5125ULL: goto x86_l_1405;
	case 5131ULL: goto x86_l_140b;
	case 5137ULL: goto x86_l_1411;
	case 5142ULL: goto x86_l_1416;
	case 5147ULL: goto x86_l_141b;
	case 5155ULL: goto x86_l_1423;
	case 5157ULL: goto x86_l_1425;
	case 5162ULL: goto x86_l_142a;
	case 5167ULL: goto x86_l_142f;
	case 5172ULL: goto x86_l_1434;
	case 5177ULL: goto x86_l_1439;
	case 5182ULL: goto x86_l_143e;
	case 5184ULL: goto x86_l_1440;
	case 5186ULL: goto x86_l_1442;
	case 5192ULL: goto x86_l_1448;
	case 5200ULL: goto x86_l_1450;
	case 5206ULL: goto x86_l_1456;
	case 5212ULL: goto x86_l_145c;
	case 5217ULL: goto x86_l_1461;
	case 5222ULL: goto x86_l_1466;
	case 5230ULL: goto x86_l_146e;
	case 5232ULL: goto x86_l_1470;
	case 5237ULL: goto x86_l_1475;
	case 5242ULL: goto x86_l_147a;
	case 5247ULL: goto x86_l_147f;
	case 5252ULL: goto x86_l_1484;
	case 5257ULL: goto x86_l_1489;
	case 5259ULL: goto x86_l_148b;
	case 5261ULL: goto x86_l_148d;
	case 5267ULL: goto x86_l_1493;
	case 5275ULL: goto x86_l_149b;
	case 5281ULL: goto x86_l_14a1;
	case 5287ULL: goto x86_l_14a7;
	case 5292ULL: goto x86_l_14ac;
	case 5297ULL: goto x86_l_14b1;
	case 5305ULL: goto x86_l_14b9;
	case 5307ULL: goto x86_l_14bb;
	case 5312ULL: goto x86_l_14c0;
	case 5317ULL: goto x86_l_14c5;
	case 5322ULL: goto x86_l_14ca;
	case 5327ULL: goto x86_l_14cf;
	case 5332ULL: goto x86_l_14d4;
	case 5334ULL: goto x86_l_14d6;
	case 5336ULL: goto x86_l_14d8;
	case 5342ULL: goto x86_l_14de;
	case 5350ULL: goto x86_l_14e6;
	case 5356ULL: goto x86_l_14ec;
	case 5362ULL: goto x86_l_14f2;
	case 5367ULL: goto x86_l_14f7;
	case 5372ULL: goto x86_l_14fc;
	case 5380ULL: goto x86_l_1504;
	case 5382ULL: goto x86_l_1506;
	case 5387ULL: goto x86_l_150b;
	case 5392ULL: goto x86_l_1510;
	case 5397ULL: goto x86_l_1515;
	case 5402ULL: goto x86_l_151a;
	case 5407ULL: goto x86_l_151f;
	case 5409ULL: goto x86_l_1521;
	case 5411ULL: goto x86_l_1523;
	case 5417ULL: goto x86_l_1529;
	case 5425ULL: goto x86_l_1531;
	case 5431ULL: goto x86_l_1537;
	case 5437ULL: goto x86_l_153d;
	case 5442ULL: goto x86_l_1542;
	case 5447ULL: goto x86_l_1547;
	case 5455ULL: goto x86_l_154f;
	case 5457ULL: goto x86_l_1551;
	case 5462ULL: goto x86_l_1556;
	case 5467ULL: goto x86_l_155b;
	case 5472ULL: goto x86_l_1560;
	case 5477ULL: goto x86_l_1565;
	case 5482ULL: goto x86_l_156a;
	case 5484ULL: goto x86_l_156c;
	case 5486ULL: goto x86_l_156e;
	case 5492ULL: goto x86_l_1574;
	case 5500ULL: goto x86_l_157c;
	case 5506ULL: goto x86_l_1582;
	case 5512ULL: goto x86_l_1588;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e34:
	/* 0xe34: je     e59 <generic_sleepable_preload+0xe59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e59;
	}
x86_l_e36:
	/* 0xe36: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e3b:
	/* 0xe3b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e40:
	/* 0xe40: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e45:
	/* 0xe45: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e4a:
	/* 0xe4a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e4f:
	/* 0xe4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e51:
	/* 0xe51: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e53:
	/* 0xe53: js     385d <generic_sleepable_preload+0x385d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14429ULL;
	}
x86_l_e59:
	/* 0xe59: cmp    WORD PTR [rbx+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_e61:
	/* 0xe61: je     3130 <generic_sleepable_preload+0x3130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12592ULL;
	}
x86_l_e67:
	/* 0xe67: mov    ecx,DWORD PTR [rbx+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_e6d:
	/* 0xe6d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e72:
	/* 0xe72: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e77:
	/* 0xe77: cmp    WORD PTR [rbx+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_e7f:
	/* 0xe7f: je     3130 <generic_sleepable_preload+0x3130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12592ULL;
	}
x86_l_e85:
	/* 0xe85: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e8a:
	/* 0xe8a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_e8f:
	/* 0xe8f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e94:
	/* 0xe94: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e99:
	/* 0xe99: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e9e:
	/* 0xe9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea0:
	/* 0xea0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ea2:
	/* 0xea2: jns    3130 <generic_sleepable_preload+0x3130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 12592ULL;
	}
x86_l_ea8:
	/* 0xea8: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_eae:
	/* 0xeae: jmp    312e <generic_sleepable_preload+0x312e> */
	return 12590ULL;
x86_l_eb3:
	/* 0xeb3: mov    edx,DWORD PTR [rbx+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_eb9:
	/* 0xeb9: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ebf:
	/* 0xebf: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ec2:
	/* 0xec2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ec7:
	/* 0xec7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ecc:
	/* 0xecc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ed1:
	/* 0xed1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ed6:
	/* 0xed6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed8:
	/* 0xed8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_eda:
	/* 0xeda: jne    f5d <generic_sleepable_preload+0xf5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f5d;
	}
x86_l_ee0:
	/* 0xee0: mov    edx,DWORD PTR [rbx+0x224] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 548ULL);
x86_l_ee6:
	/* 0xee6: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_eec:
	/* 0xeec: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_eef:
	/* 0xeef: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ef2:
	/* 0xef2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ef7:
	/* 0xef7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_efc:
	/* 0xefc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f01:
	/* 0xf01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f03:
	/* 0xf03: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f05:
	/* 0xf05: jne    f5d <generic_sleepable_preload+0xf5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f5d;
	}
x86_l_f07:
	/* 0xf07: movzx  eax,BYTE PTR [rbx+0x22b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 555ULL);
x86_l_f0e:
	/* 0xf0e: shlx   rax,QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_f14:
	/* 0xf14: mov    rcx,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_f1b:
	/* 0xf1b: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_f20:
	/* 0xf20: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_f23:
	/* 0xf23: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f28:
	/* 0xf28: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_f2d:
	/* 0xf2d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_f32:
	/* 0xf32: movzx  ecx,BYTE PTR [rbx+0x22b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 555ULL);
x86_l_f39:
	/* 0xf39: shlx   rcx,QWORD PTR [rsp],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_f3f:
	/* 0xf3f: mov    rdx,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_f46:
	/* 0xf46: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_f4b:
	/* 0xf4b: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_f4e:
	/* 0xf4e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f53:
	/* 0xf53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f55:
	/* 0xf55: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f57:
	/* 0xf57: je     a94 <generic_sleepable_preload+0xa94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2708ULL;
	}
x86_l_f5d:
	/* 0xf5d: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_f60:
	/* 0xf60: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f65:
	/* 0xf65: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f68:
	/* 0xf68: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_f6b:
	/* 0xf6b: cmp    WORD PTR [rbx+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_f73:
	/* 0xf73: je     31c6 <generic_sleepable_preload+0x31c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12742ULL;
	}
x86_l_f79:
	/* 0xf79: mov    eax,DWORD PTR [rbx+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_f7f:
	/* 0xf7f: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_f82:
	/* 0xf82: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f87:
	/* 0xf87: cmp    WORD PTR [rbx+0xc4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_f8f:
	/* 0xf8f: je     fb4 <generic_sleepable_preload+0xfb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fb4;
	}
x86_l_f91:
	/* 0xf91: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f96:
	/* 0xf96: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_f9b:
	/* 0xf9b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_fa0:
	/* 0xfa0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fa5:
	/* 0xfa5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_faa:
	/* 0xfaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fac:
	/* 0xfac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fae:
	/* 0xfae: js     1d8a <generic_sleepable_preload+0x1d8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7562ULL;
	}
x86_l_fb4:
	/* 0xfb4: cmp    WORD PTR [rbx+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_fbc:
	/* 0xfbc: je     31c6 <generic_sleepable_preload+0x31c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12742ULL;
	}
x86_l_fc2:
	/* 0xfc2: mov    ecx,DWORD PTR [rbx+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_fc8:
	/* 0xfc8: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_fcd:
	/* 0xfcd: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fd2:
	/* 0xfd2: cmp    WORD PTR [rbx+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_fda:
	/* 0xfda: je     fff <generic_sleepable_preload+0xfff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fff;
	}
x86_l_fdc:
	/* 0xfdc: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fe1:
	/* 0xfe1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_fe6:
	/* 0xfe6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_feb:
	/* 0xfeb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ff0:
	/* 0xff0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ff5:
	/* 0xff5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff7:
	/* 0xff7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ff9:
	/* 0xff9: js     262f <generic_sleepable_preload+0x262f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9775ULL;
	}
x86_l_fff:
	/* 0xfff: cmp    WORD PTR [rbx+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_1007:
	/* 0x1007: je     31c6 <generic_sleepable_preload+0x31c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12742ULL;
	}
x86_l_100d:
	/* 0x100d: mov    ecx,DWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1013:
	/* 0x1013: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1018:
	/* 0x1018: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_101d:
	/* 0x101d: cmp    WORD PTR [rbx+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_1025:
	/* 0x1025: je     104a <generic_sleepable_preload+0x104a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_104a;
	}
x86_l_1027:
	/* 0x1027: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_102c:
	/* 0x102c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1031:
	/* 0x1031: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1036:
	/* 0x1036: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_103b:
	/* 0x103b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1040:
	/* 0x1040: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1042:
	/* 0x1042: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1044:
	/* 0x1044: js     2f86 <generic_sleepable_preload+0x2f86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12166ULL;
	}
x86_l_104a:
	/* 0x104a: cmp    WORD PTR [rbx+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_1052:
	/* 0x1052: je     31c6 <generic_sleepable_preload+0x31c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12742ULL;
	}
x86_l_1058:
	/* 0x1058: mov    ecx,DWORD PTR [rbx+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_105e:
	/* 0x105e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1063:
	/* 0x1063: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1068:
	/* 0x1068: cmp    WORD PTR [rbx+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_1070:
	/* 0x1070: je     1095 <generic_sleepable_preload+0x1095> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1095;
	}
x86_l_1072:
	/* 0x1072: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1077:
	/* 0x1077: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_107c:
	/* 0x107c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1081:
	/* 0x1081: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1086:
	/* 0x1086: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_108b:
	/* 0x108b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_108d:
	/* 0x108d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_108f:
	/* 0x108f: js     2ff2 <generic_sleepable_preload+0x2ff2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12274ULL;
	}
x86_l_1095:
	/* 0x1095: cmp    WORD PTR [rbx+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_109d:
	/* 0x109d: je     31c6 <generic_sleepable_preload+0x31c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12742ULL;
	}
x86_l_10a3:
	/* 0x10a3: mov    ecx,DWORD PTR [rbx+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_10a9:
	/* 0x10a9: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_10ae:
	/* 0x10ae: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10b3:
	/* 0x10b3: cmp    WORD PTR [rbx+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_10bb:
	/* 0x10bb: je     10e0 <generic_sleepable_preload+0x10e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10e0;
	}
x86_l_10bd:
	/* 0x10bd: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10c2:
	/* 0x10c2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_10c7:
	/* 0x10c7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_10cc:
	/* 0x10cc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10d1:
	/* 0x10d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10d6:
	/* 0x10d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d8:
	/* 0x10d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10da:
	/* 0x10da: js     305e <generic_sleepable_preload+0x305e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12382ULL;
	}
x86_l_10e0:
	/* 0x10e0: cmp    WORD PTR [rbx+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_10e8:
	/* 0x10e8: je     31c6 <generic_sleepable_preload+0x31c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12742ULL;
	}
x86_l_10ee:
	/* 0x10ee: mov    ecx,DWORD PTR [rbx+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_10f4:
	/* 0x10f4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_10f9:
	/* 0x10f9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10fe:
	/* 0x10fe: cmp    WORD PTR [rbx+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_1106:
	/* 0x1106: je     112b <generic_sleepable_preload+0x112b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_112b;
	}
x86_l_1108:
	/* 0x1108: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_110d:
	/* 0x110d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1112:
	/* 0x1112: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1117:
	/* 0x1117: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_111c:
	/* 0x111c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1121:
	/* 0x1121: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1123:
	/* 0x1123: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1125:
	/* 0x1125: js     30c7 <generic_sleepable_preload+0x30c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12487ULL;
	}
x86_l_112b:
	/* 0x112b: cmp    WORD PTR [rbx+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_1133:
	/* 0x1133: je     31c6 <generic_sleepable_preload+0x31c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12742ULL;
	}
x86_l_1139:
	/* 0x1139: mov    ecx,DWORD PTR [rbx+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_113f:
	/* 0x113f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1144:
	/* 0x1144: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1149:
	/* 0x1149: cmp    WORD PTR [rbx+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_1151:
	/* 0x1151: je     1176 <generic_sleepable_preload+0x1176> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1176;
	}
x86_l_1153:
	/* 0x1153: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1158:
	/* 0x1158: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_115d:
	/* 0x115d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1162:
	/* 0x1162: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1167:
	/* 0x1167: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_116c:
	/* 0x116c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_116e:
	/* 0x116e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1170:
	/* 0x1170: js     31be <generic_sleepable_preload+0x31be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12734ULL;
	}
x86_l_1176:
	/* 0x1176: cmp    WORD PTR [rbx+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_117e:
	/* 0x117e: je     31c6 <generic_sleepable_preload+0x31c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12742ULL;
	}
x86_l_1184:
	/* 0x1184: mov    ecx,DWORD PTR [rbx+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_118a:
	/* 0x118a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_118f:
	/* 0x118f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1194:
	/* 0x1194: cmp    WORD PTR [rbx+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_119c:
	/* 0x119c: je     11c1 <generic_sleepable_preload+0x11c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11c1;
	}
x86_l_119e:
	/* 0x119e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11a3:
	/* 0x11a3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_11a8:
	/* 0x11a8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_11ad:
	/* 0x11ad: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11b2:
	/* 0x11b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11b7:
	/* 0x11b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11b9:
	/* 0x11b9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11bb:
	/* 0x11bb: js     37b6 <generic_sleepable_preload+0x37b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14262ULL;
	}
x86_l_11c1:
	/* 0x11c1: cmp    WORD PTR [rbx+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_11c9:
	/* 0x11c9: je     31c6 <generic_sleepable_preload+0x31c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12742ULL;
	}
x86_l_11cf:
	/* 0x11cf: mov    ecx,DWORD PTR [rbx+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_11d5:
	/* 0x11d5: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_11da:
	/* 0x11da: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11df:
	/* 0x11df: cmp    WORD PTR [rbx+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_11e7:
	/* 0x11e7: je     120c <generic_sleepable_preload+0x120c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_120c;
	}
x86_l_11e9:
	/* 0x11e9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11ee:
	/* 0x11ee: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_11f3:
	/* 0x11f3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_11f8:
	/* 0x11f8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11fd:
	/* 0x11fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1202:
	/* 0x1202: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1204:
	/* 0x1204: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1206:
	/* 0x1206: js     3868 <generic_sleepable_preload+0x3868> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14440ULL;
	}
x86_l_120c:
	/* 0x120c: cmp    WORD PTR [rbx+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_1214:
	/* 0x1214: je     31c6 <generic_sleepable_preload+0x31c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12742ULL;
	}
x86_l_121a:
	/* 0x121a: mov    ecx,DWORD PTR [rbx+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_1220:
	/* 0x1220: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1225:
	/* 0x1225: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_122a:
	/* 0x122a: cmp    WORD PTR [rbx+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_1232:
	/* 0x1232: je     31c6 <generic_sleepable_preload+0x31c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12742ULL;
	}
x86_l_1238:
	/* 0x1238: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_123d:
	/* 0x123d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1242:
	/* 0x1242: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1247:
	/* 0x1247: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_124c:
	/* 0x124c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1251:
	/* 0x1251: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1253:
	/* 0x1253: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1255:
	/* 0x1255: jns    31c6 <generic_sleepable_preload+0x31c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 12742ULL;
	}
x86_l_125b:
	/* 0x125b: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_1261:
	/* 0x1261: jmp    31c4 <generic_sleepable_preload+0x31c4> */
	return 12740ULL;
x86_l_1266:
	/* 0x1266: mov    edx,DWORD PTR [rbx+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_126c:
	/* 0x126c: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1272:
	/* 0x1272: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1275:
	/* 0x1275: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_127a:
	/* 0x127a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_127f:
	/* 0x127f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1284:
	/* 0x1284: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1289:
	/* 0x1289: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_128b:
	/* 0x128b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_128d:
	/* 0x128d: jne    1310 <generic_sleepable_preload+0x1310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1310;
	}
x86_l_1293:
	/* 0x1293: mov    edx,DWORD PTR [rbx+0x23c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_1299:
	/* 0x1299: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_129f:
	/* 0x129f: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_12a2:
	/* 0x12a2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_12a5:
	/* 0x12a5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12aa:
	/* 0x12aa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_12af:
	/* 0x12af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12b4:
	/* 0x12b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12b6:
	/* 0x12b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12b8:
	/* 0x12b8: jne    1310 <generic_sleepable_preload+0x1310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1310;
	}
x86_l_12ba:
	/* 0x12ba: movzx  eax,BYTE PTR [rbx+0x243] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 579ULL);
x86_l_12c1:
	/* 0x12c1: shlx   rax,QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_12c7:
	/* 0x12c7: mov    rcx,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_12ce:
	/* 0x12ce: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_12d3:
	/* 0x12d3: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_12d6:
	/* 0x12d6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12db:
	/* 0x12db: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_12e0:
	/* 0x12e0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_12e5:
	/* 0x12e5: movzx  ecx,BYTE PTR [rbx+0x243] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 579ULL);
x86_l_12ec:
	/* 0x12ec: shlx   rcx,QWORD PTR [rsp],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_12f2:
	/* 0x12f2: mov    rdx,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_12f9:
	/* 0x12f9: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_12fe:
	/* 0x12fe: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1301:
	/* 0x1301: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1306:
	/* 0x1306: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1308:
	/* 0x1308: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_130a:
	/* 0x130a: je     acd <generic_sleepable_preload+0xacd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2765ULL;
	}
x86_l_1310:
	/* 0x1310: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_1313:
	/* 0x1313: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1318:
	/* 0x1318: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_131b:
	/* 0x131b: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_131e:
	/* 0x131e: cmp    WORD PTR [rbx+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_1326:
	/* 0x1326: je     3259 <generic_sleepable_preload+0x3259> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12889ULL;
	}
x86_l_132c:
	/* 0x132c: mov    eax,DWORD PTR [rbx+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_1332:
	/* 0x1332: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1335:
	/* 0x1335: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_133a:
	/* 0x133a: cmp    WORD PTR [rbx+0x114],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1185410973696ULL);
x86_l_1342:
	/* 0x1342: je     1367 <generic_sleepable_preload+0x1367> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1367;
	}
x86_l_1344:
	/* 0x1344: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1349:
	/* 0x1349: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_134e:
	/* 0x134e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1353:
	/* 0x1353: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1358:
	/* 0x1358: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_135d:
	/* 0x135d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_135f:
	/* 0x135f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1361:
	/* 0x1361: js     1d95 <generic_sleepable_preload+0x1d95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7573ULL;
	}
x86_l_1367:
	/* 0x1367: cmp    WORD PTR [rbx+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_136f:
	/* 0x136f: je     3259 <generic_sleepable_preload+0x3259> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12889ULL;
	}
x86_l_1375:
	/* 0x1375: mov    ecx,DWORD PTR [rbx+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_137b:
	/* 0x137b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1380:
	/* 0x1380: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1385:
	/* 0x1385: cmp    WORD PTR [rbx+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_138d:
	/* 0x138d: je     13b2 <generic_sleepable_preload+0x13b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13b2;
	}
x86_l_138f:
	/* 0x138f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1394:
	/* 0x1394: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1399:
	/* 0x1399: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_139e:
	/* 0x139e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13a3:
	/* 0x13a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13a8:
	/* 0x13a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13aa:
	/* 0x13aa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13ac:
	/* 0x13ac: js     263a <generic_sleepable_preload+0x263a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9786ULL;
	}
x86_l_13b2:
	/* 0x13b2: cmp    WORD PTR [rbx+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_13ba:
	/* 0x13ba: je     3259 <generic_sleepable_preload+0x3259> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12889ULL;
	}
x86_l_13c0:
	/* 0x13c0: mov    ecx,DWORD PTR [rbx+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_13c6:
	/* 0x13c6: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_13cb:
	/* 0x13cb: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13d0:
	/* 0x13d0: cmp    WORD PTR [rbx+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_13d8:
	/* 0x13d8: je     13fd <generic_sleepable_preload+0x13fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13fd;
	}
x86_l_13da:
	/* 0x13da: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13df:
	/* 0x13df: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_13e4:
	/* 0x13e4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_13e9:
	/* 0x13e9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13ee:
	/* 0x13ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13f3:
	/* 0x13f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f5:
	/* 0x13f5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13f7:
	/* 0x13f7: js     2f91 <generic_sleepable_preload+0x2f91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12177ULL;
	}
x86_l_13fd:
	/* 0x13fd: cmp    WORD PTR [rbx+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_1405:
	/* 0x1405: je     3259 <generic_sleepable_preload+0x3259> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12889ULL;
	}
x86_l_140b:
	/* 0x140b: mov    ecx,DWORD PTR [rbx+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_1411:
	/* 0x1411: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1416:
	/* 0x1416: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_141b:
	/* 0x141b: cmp    WORD PTR [rbx+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_1423:
	/* 0x1423: je     1448 <generic_sleepable_preload+0x1448> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1448;
	}
x86_l_1425:
	/* 0x1425: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_142a:
	/* 0x142a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_142f:
	/* 0x142f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1434:
	/* 0x1434: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1439:
	/* 0x1439: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_143e:
	/* 0x143e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1440:
	/* 0x1440: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1442:
	/* 0x1442: js     2ffd <generic_sleepable_preload+0x2ffd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12285ULL;
	}
x86_l_1448:
	/* 0x1448: cmp    WORD PTR [rbx+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_1450:
	/* 0x1450: je     3259 <generic_sleepable_preload+0x3259> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12889ULL;
	}
x86_l_1456:
	/* 0x1456: mov    ecx,DWORD PTR [rbx+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_145c:
	/* 0x145c: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1461:
	/* 0x1461: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1466:
	/* 0x1466: cmp    WORD PTR [rbx+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_146e:
	/* 0x146e: je     1493 <generic_sleepable_preload+0x1493> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1493;
	}
x86_l_1470:
	/* 0x1470: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1475:
	/* 0x1475: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_147a:
	/* 0x147a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_147f:
	/* 0x147f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1484:
	/* 0x1484: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1489:
	/* 0x1489: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_148b:
	/* 0x148b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_148d:
	/* 0x148d: js     3069 <generic_sleepable_preload+0x3069> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12393ULL;
	}
x86_l_1493:
	/* 0x1493: cmp    WORD PTR [rbx+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_149b:
	/* 0x149b: je     3259 <generic_sleepable_preload+0x3259> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12889ULL;
	}
x86_l_14a1:
	/* 0x14a1: mov    ecx,DWORD PTR [rbx+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_14a7:
	/* 0x14a7: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_14ac:
	/* 0x14ac: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14b1:
	/* 0x14b1: cmp    WORD PTR [rbx+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_14b9:
	/* 0x14b9: je     14de <generic_sleepable_preload+0x14de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14de;
	}
x86_l_14bb:
	/* 0x14bb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14c0:
	/* 0x14c0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_14c5:
	/* 0x14c5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_14ca:
	/* 0x14ca: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14cf:
	/* 0x14cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14d4:
	/* 0x14d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d6:
	/* 0x14d6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14d8:
	/* 0x14d8: js     30d2 <generic_sleepable_preload+0x30d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12498ULL;
	}
x86_l_14de:
	/* 0x14de: cmp    WORD PTR [rbx+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_14e6:
	/* 0x14e6: je     3259 <generic_sleepable_preload+0x3259> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12889ULL;
	}
x86_l_14ec:
	/* 0x14ec: mov    ecx,DWORD PTR [rbx+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_14f2:
	/* 0x14f2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_14f7:
	/* 0x14f7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14fc:
	/* 0x14fc: cmp    WORD PTR [rbx+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_1504:
	/* 0x1504: je     1529 <generic_sleepable_preload+0x1529> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1529;
	}
x86_l_1506:
	/* 0x1506: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_150b:
	/* 0x150b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1510:
	/* 0x1510: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1515:
	/* 0x1515: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_151a:
	/* 0x151a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_151f:
	/* 0x151f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1521:
	/* 0x1521: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1523:
	/* 0x1523: js     3251 <generic_sleepable_preload+0x3251> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12881ULL;
	}
x86_l_1529:
	/* 0x1529: cmp    WORD PTR [rbx+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_1531:
	/* 0x1531: je     3259 <generic_sleepable_preload+0x3259> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12889ULL;
	}
x86_l_1537:
	/* 0x1537: mov    ecx,DWORD PTR [rbx+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_153d:
	/* 0x153d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1542:
	/* 0x1542: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1547:
	/* 0x1547: cmp    WORD PTR [rbx+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_154f:
	/* 0x154f: je     1574 <generic_sleepable_preload+0x1574> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1574;
	}
x86_l_1551:
	/* 0x1551: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1556:
	/* 0x1556: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_155b:
	/* 0x155b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1560:
	/* 0x1560: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1565:
	/* 0x1565: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_156a:
	/* 0x156a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_156c:
	/* 0x156c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_156e:
	/* 0x156e: js     37c3 <generic_sleepable_preload+0x37c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14275ULL;
	}
x86_l_1574:
	/* 0x1574: cmp    WORD PTR [rbx+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_157c:
	/* 0x157c: je     3259 <generic_sleepable_preload+0x3259> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12889ULL;
	}
x86_l_1582:
	/* 0x1582: mov    ecx,DWORD PTR [rbx+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_1588:
	/* 0x1588: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
	return 5517ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5517ULL: goto x86_l_158d;
	case 5522ULL: goto x86_l_1592;
	case 5530ULL: goto x86_l_159a;
	case 5532ULL: goto x86_l_159c;
	case 5537ULL: goto x86_l_15a1;
	case 5542ULL: goto x86_l_15a6;
	case 5547ULL: goto x86_l_15ab;
	case 5552ULL: goto x86_l_15b0;
	case 5557ULL: goto x86_l_15b5;
	case 5559ULL: goto x86_l_15b7;
	case 5561ULL: goto x86_l_15b9;
	case 5567ULL: goto x86_l_15bf;
	case 5575ULL: goto x86_l_15c7;
	case 5581ULL: goto x86_l_15cd;
	case 5587ULL: goto x86_l_15d3;
	case 5592ULL: goto x86_l_15d8;
	case 5597ULL: goto x86_l_15dd;
	case 5605ULL: goto x86_l_15e5;
	case 5611ULL: goto x86_l_15eb;
	case 5616ULL: goto x86_l_15f0;
	case 5621ULL: goto x86_l_15f5;
	case 5626ULL: goto x86_l_15fa;
	case 5631ULL: goto x86_l_15ff;
	case 5636ULL: goto x86_l_1604;
	case 5638ULL: goto x86_l_1606;
	case 5640ULL: goto x86_l_1608;
	case 5646ULL: goto x86_l_160e;
	case 5652ULL: goto x86_l_1614;
	case 5657ULL: goto x86_l_1619;
	case 5663ULL: goto x86_l_161f;
	case 5669ULL: goto x86_l_1625;
	case 5672ULL: goto x86_l_1628;
	case 5677ULL: goto x86_l_162d;
	case 5682ULL: goto x86_l_1632;
	case 5687ULL: goto x86_l_1637;
	case 5692ULL: goto x86_l_163c;
	case 5694ULL: goto x86_l_163e;
	case 5696ULL: goto x86_l_1640;
	case 5702ULL: goto x86_l_1646;
	case 5708ULL: goto x86_l_164c;
	case 5714ULL: goto x86_l_1652;
	case 5717ULL: goto x86_l_1655;
	case 5720ULL: goto x86_l_1658;
	case 5725ULL: goto x86_l_165d;
	case 5730ULL: goto x86_l_1662;
	case 5735ULL: goto x86_l_1667;
	case 5737ULL: goto x86_l_1669;
	case 5739ULL: goto x86_l_166b;
	case 5741ULL: goto x86_l_166d;
	case 5748ULL: goto x86_l_1674;
	case 5754ULL: goto x86_l_167a;
	case 5761ULL: goto x86_l_1681;
	case 5766ULL: goto x86_l_1686;
	case 5769ULL: goto x86_l_1689;
	case 5774ULL: goto x86_l_168e;
	case 5779ULL: goto x86_l_1693;
	case 5784ULL: goto x86_l_1698;
	case 5791ULL: goto x86_l_169f;
	case 5797ULL: goto x86_l_16a5;
	case 5804ULL: goto x86_l_16ac;
	case 5809ULL: goto x86_l_16b1;
	case 5812ULL: goto x86_l_16b4;
	case 5817ULL: goto x86_l_16b9;
	case 5819ULL: goto x86_l_16bb;
	case 5821ULL: goto x86_l_16bd;
	case 5827ULL: goto x86_l_16c3;
	case 5830ULL: goto x86_l_16c6;
	case 5835ULL: goto x86_l_16cb;
	case 5838ULL: goto x86_l_16ce;
	case 5841ULL: goto x86_l_16d1;
	case 5849ULL: goto x86_l_16d9;
	case 5855ULL: goto x86_l_16df;
	case 5861ULL: goto x86_l_16e5;
	case 5864ULL: goto x86_l_16e8;
	case 5869ULL: goto x86_l_16ed;
	case 5877ULL: goto x86_l_16f5;
	case 5879ULL: goto x86_l_16f7;
	case 5884ULL: goto x86_l_16fc;
	case 5889ULL: goto x86_l_1701;
	case 5894ULL: goto x86_l_1706;
	case 5899ULL: goto x86_l_170b;
	case 5904ULL: goto x86_l_1710;
	case 5906ULL: goto x86_l_1712;
	case 5908ULL: goto x86_l_1714;
	case 5914ULL: goto x86_l_171a;
	case 5922ULL: goto x86_l_1722;
	case 5928ULL: goto x86_l_1728;
	case 5934ULL: goto x86_l_172e;
	case 5939ULL: goto x86_l_1733;
	case 5944ULL: goto x86_l_1738;
	case 5952ULL: goto x86_l_1740;
	case 5954ULL: goto x86_l_1742;
	case 5959ULL: goto x86_l_1747;
	case 5964ULL: goto x86_l_174c;
	case 5969ULL: goto x86_l_1751;
	case 5974ULL: goto x86_l_1756;
	case 5979ULL: goto x86_l_175b;
	case 5981ULL: goto x86_l_175d;
	case 5983ULL: goto x86_l_175f;
	case 5989ULL: goto x86_l_1765;
	case 5997ULL: goto x86_l_176d;
	case 6003ULL: goto x86_l_1773;
	case 6009ULL: goto x86_l_1779;
	case 6014ULL: goto x86_l_177e;
	case 6019ULL: goto x86_l_1783;
	case 6027ULL: goto x86_l_178b;
	case 6029ULL: goto x86_l_178d;
	case 6034ULL: goto x86_l_1792;
	case 6039ULL: goto x86_l_1797;
	case 6044ULL: goto x86_l_179c;
	case 6049ULL: goto x86_l_17a1;
	case 6054ULL: goto x86_l_17a6;
	case 6056ULL: goto x86_l_17a8;
	case 6058ULL: goto x86_l_17aa;
	case 6064ULL: goto x86_l_17b0;
	case 6072ULL: goto x86_l_17b8;
	case 6078ULL: goto x86_l_17be;
	case 6084ULL: goto x86_l_17c4;
	case 6089ULL: goto x86_l_17c9;
	case 6094ULL: goto x86_l_17ce;
	case 6102ULL: goto x86_l_17d6;
	case 6104ULL: goto x86_l_17d8;
	case 6109ULL: goto x86_l_17dd;
	case 6114ULL: goto x86_l_17e2;
	case 6119ULL: goto x86_l_17e7;
	case 6124ULL: goto x86_l_17ec;
	case 6129ULL: goto x86_l_17f1;
	case 6131ULL: goto x86_l_17f3;
	case 6133ULL: goto x86_l_17f5;
	case 6139ULL: goto x86_l_17fb;
	case 6147ULL: goto x86_l_1803;
	case 6153ULL: goto x86_l_1809;
	case 6159ULL: goto x86_l_180f;
	case 6164ULL: goto x86_l_1814;
	case 6169ULL: goto x86_l_1819;
	case 6177ULL: goto x86_l_1821;
	case 6179ULL: goto x86_l_1823;
	case 6184ULL: goto x86_l_1828;
	case 6189ULL: goto x86_l_182d;
	case 6194ULL: goto x86_l_1832;
	case 6199ULL: goto x86_l_1837;
	case 6204ULL: goto x86_l_183c;
	case 6206ULL: goto x86_l_183e;
	case 6208ULL: goto x86_l_1840;
	case 6214ULL: goto x86_l_1846;
	case 6222ULL: goto x86_l_184e;
	case 6228ULL: goto x86_l_1854;
	case 6234ULL: goto x86_l_185a;
	case 6239ULL: goto x86_l_185f;
	case 6244ULL: goto x86_l_1864;
	case 6252ULL: goto x86_l_186c;
	case 6254ULL: goto x86_l_186e;
	case 6259ULL: goto x86_l_1873;
	case 6264ULL: goto x86_l_1878;
	case 6269ULL: goto x86_l_187d;
	case 6274ULL: goto x86_l_1882;
	case 6279ULL: goto x86_l_1887;
	case 6281ULL: goto x86_l_1889;
	case 6283ULL: goto x86_l_188b;
	case 6289ULL: goto x86_l_1891;
	case 6297ULL: goto x86_l_1899;
	case 6303ULL: goto x86_l_189f;
	case 6309ULL: goto x86_l_18a5;
	case 6314ULL: goto x86_l_18aa;
	case 6319ULL: goto x86_l_18af;
	case 6327ULL: goto x86_l_18b7;
	case 6329ULL: goto x86_l_18b9;
	case 6334ULL: goto x86_l_18be;
	case 6339ULL: goto x86_l_18c3;
	case 6344ULL: goto x86_l_18c8;
	case 6349ULL: goto x86_l_18cd;
	case 6354ULL: goto x86_l_18d2;
	case 6356ULL: goto x86_l_18d4;
	case 6358ULL: goto x86_l_18d6;
	case 6364ULL: goto x86_l_18dc;
	case 6372ULL: goto x86_l_18e4;
	case 6378ULL: goto x86_l_18ea;
	case 6384ULL: goto x86_l_18f0;
	case 6389ULL: goto x86_l_18f5;
	case 6394ULL: goto x86_l_18fa;
	case 6402ULL: goto x86_l_1902;
	case 6404ULL: goto x86_l_1904;
	case 6409ULL: goto x86_l_1909;
	case 6414ULL: goto x86_l_190e;
	case 6419ULL: goto x86_l_1913;
	case 6424ULL: goto x86_l_1918;
	case 6429ULL: goto x86_l_191d;
	case 6431ULL: goto x86_l_191f;
	case 6433ULL: goto x86_l_1921;
	case 6439ULL: goto x86_l_1927;
	case 6447ULL: goto x86_l_192f;
	case 6453ULL: goto x86_l_1935;
	case 6459ULL: goto x86_l_193b;
	case 6464ULL: goto x86_l_1940;
	case 6469ULL: goto x86_l_1945;
	case 6477ULL: goto x86_l_194d;
	case 6479ULL: goto x86_l_194f;
	case 6484ULL: goto x86_l_1954;
	case 6489ULL: goto x86_l_1959;
	case 6494ULL: goto x86_l_195e;
	case 6499ULL: goto x86_l_1963;
	case 6504ULL: goto x86_l_1968;
	case 6506ULL: goto x86_l_196a;
	case 6508ULL: goto x86_l_196c;
	case 6514ULL: goto x86_l_1972;
	case 6522ULL: goto x86_l_197a;
	case 6528ULL: goto x86_l_1980;
	case 6534ULL: goto x86_l_1986;
	case 6539ULL: goto x86_l_198b;
	case 6544ULL: goto x86_l_1990;
	case 6552ULL: goto x86_l_1998;
	case 6558ULL: goto x86_l_199e;
	case 6563ULL: goto x86_l_19a3;
	case 6568ULL: goto x86_l_19a8;
	case 6573ULL: goto x86_l_19ad;
	case 6578ULL: goto x86_l_19b2;
	case 6583ULL: goto x86_l_19b7;
	case 6585ULL: goto x86_l_19b9;
	case 6587ULL: goto x86_l_19bb;
	case 6593ULL: goto x86_l_19c1;
	case 6599ULL: goto x86_l_19c7;
	case 6604ULL: goto x86_l_19cc;
	case 6610ULL: goto x86_l_19d2;
	case 6616ULL: goto x86_l_19d8;
	case 6619ULL: goto x86_l_19db;
	case 6624ULL: goto x86_l_19e0;
	case 6629ULL: goto x86_l_19e5;
	case 6634ULL: goto x86_l_19ea;
	case 6639ULL: goto x86_l_19ef;
	case 6641ULL: goto x86_l_19f1;
	case 6643ULL: goto x86_l_19f3;
	case 6649ULL: goto x86_l_19f9;
	case 6655ULL: goto x86_l_19ff;
	case 6660ULL: goto x86_l_1a04;
	case 6663ULL: goto x86_l_1a07;
	case 6666ULL: goto x86_l_1a0a;
	case 6671ULL: goto x86_l_1a0f;
	case 6676ULL: goto x86_l_1a14;
	case 6681ULL: goto x86_l_1a19;
	case 6684ULL: goto x86_l_1a1c;
	case 6686ULL: goto x86_l_1a1e;
	case 6688ULL: goto x86_l_1a20;
	case 6690ULL: goto x86_l_1a22;
	case 6697ULL: goto x86_l_1a29;
	case 6703ULL: goto x86_l_1a2f;
	case 6710ULL: goto x86_l_1a36;
	case 6715ULL: goto x86_l_1a3b;
	case 6718ULL: goto x86_l_1a3e;
	case 6723ULL: goto x86_l_1a43;
	case 6728ULL: goto x86_l_1a48;
	case 6733ULL: goto x86_l_1a4d;
	case 6740ULL: goto x86_l_1a54;
	case 6746ULL: goto x86_l_1a5a;
	case 6753ULL: goto x86_l_1a61;
	case 6758ULL: goto x86_l_1a66;
	case 6761ULL: goto x86_l_1a69;
	case 6766ULL: goto x86_l_1a6e;
	case 6768ULL: goto x86_l_1a70;
	case 6770ULL: goto x86_l_1a72;
	case 6776ULL: goto x86_l_1a78;
	case 6779ULL: goto x86_l_1a7b;
	case 6784ULL: goto x86_l_1a80;
	case 6786ULL: goto x86_l_1a82;
	case 6789ULL: goto x86_l_1a85;
	case 6797ULL: goto x86_l_1a8d;
	case 6803ULL: goto x86_l_1a93;
	case 6809ULL: goto x86_l_1a99;
	case 6812ULL: goto x86_l_1a9c;
	case 6817ULL: goto x86_l_1aa1;
	case 6825ULL: goto x86_l_1aa9;
	case 6827ULL: goto x86_l_1aab;
	case 6832ULL: goto x86_l_1ab0;
	case 6837ULL: goto x86_l_1ab5;
	case 6842ULL: goto x86_l_1aba;
	case 6847ULL: goto x86_l_1abf;
	case 6852ULL: goto x86_l_1ac4;
	case 6854ULL: goto x86_l_1ac6;
	case 6856ULL: goto x86_l_1ac8;
	case 6862ULL: goto x86_l_1ace;
	case 6870ULL: goto x86_l_1ad6;
	case 6876ULL: goto x86_l_1adc;
	case 6882ULL: goto x86_l_1ae2;
	case 6887ULL: goto x86_l_1ae7;
	case 6892ULL: goto x86_l_1aec;
	case 6900ULL: goto x86_l_1af4;
	case 6902ULL: goto x86_l_1af6;
	case 6907ULL: goto x86_l_1afb;
	case 6912ULL: goto x86_l_1b00;
	case 6917ULL: goto x86_l_1b05;
	case 6922ULL: goto x86_l_1b0a;
	case 6927ULL: goto x86_l_1b0f;
	case 6929ULL: goto x86_l_1b11;
	case 6931ULL: goto x86_l_1b13;
	case 6937ULL: goto x86_l_1b19;
	case 6945ULL: goto x86_l_1b21;
	case 6951ULL: goto x86_l_1b27;
	case 6957ULL: goto x86_l_1b2d;
	case 6962ULL: goto x86_l_1b32;
	case 6967ULL: goto x86_l_1b37;
	case 6975ULL: goto x86_l_1b3f;
	case 6977ULL: goto x86_l_1b41;
	case 6982ULL: goto x86_l_1b46;
	case 6987ULL: goto x86_l_1b4b;
	case 6992ULL: goto x86_l_1b50;
	case 6997ULL: goto x86_l_1b55;
	case 7002ULL: goto x86_l_1b5a;
	case 7004ULL: goto x86_l_1b5c;
	case 7006ULL: goto x86_l_1b5e;
	case 7012ULL: goto x86_l_1b64;
	case 7020ULL: goto x86_l_1b6c;
	case 7026ULL: goto x86_l_1b72;
	case 7032ULL: goto x86_l_1b78;
	case 7037ULL: goto x86_l_1b7d;
	case 7042ULL: goto x86_l_1b82;
	case 7050ULL: goto x86_l_1b8a;
	case 7052ULL: goto x86_l_1b8c;
	case 7057ULL: goto x86_l_1b91;
	case 7062ULL: goto x86_l_1b96;
	case 7067ULL: goto x86_l_1b9b;
	case 7072ULL: goto x86_l_1ba0;
	case 7077ULL: goto x86_l_1ba5;
	case 7079ULL: goto x86_l_1ba7;
	case 7081ULL: goto x86_l_1ba9;
	case 7087ULL: goto x86_l_1baf;
	case 7095ULL: goto x86_l_1bb7;
	case 7101ULL: goto x86_l_1bbd;
	case 7107ULL: goto x86_l_1bc3;
	case 7112ULL: goto x86_l_1bc8;
	case 7117ULL: goto x86_l_1bcd;
	case 7125ULL: goto x86_l_1bd5;
	case 7127ULL: goto x86_l_1bd7;
	case 7132ULL: goto x86_l_1bdc;
	case 7137ULL: goto x86_l_1be1;
	case 7142ULL: goto x86_l_1be6;
	case 7147ULL: goto x86_l_1beb;
	case 7152ULL: goto x86_l_1bf0;
	case 7154ULL: goto x86_l_1bf2;
	case 7156ULL: goto x86_l_1bf4;
	case 7162ULL: goto x86_l_1bfa;
	case 7170ULL: goto x86_l_1c02;
	case 7176ULL: goto x86_l_1c08;
	case 7182ULL: goto x86_l_1c0e;
	case 7187ULL: goto x86_l_1c13;
	case 7192ULL: goto x86_l_1c18;
	case 7200ULL: goto x86_l_1c20;
	case 7202ULL: goto x86_l_1c22;
	case 7207ULL: goto x86_l_1c27;
	case 7212ULL: goto x86_l_1c2c;
	case 7217ULL: goto x86_l_1c31;
	case 7222ULL: goto x86_l_1c36;
	case 7227ULL: goto x86_l_1c3b;
	case 7229ULL: goto x86_l_1c3d;
	case 7231ULL: goto x86_l_1c3f;
	case 7237ULL: goto x86_l_1c45;
	case 7245ULL: goto x86_l_1c4d;
	case 7251ULL: goto x86_l_1c53;
	case 7257ULL: goto x86_l_1c59;
	case 7262ULL: goto x86_l_1c5e;
	case 7267ULL: goto x86_l_1c63;
	case 7275ULL: goto x86_l_1c6b;
	case 7277ULL: goto x86_l_1c6d;
	case 7282ULL: goto x86_l_1c72;
	case 7287ULL: goto x86_l_1c77;
	case 7292ULL: goto x86_l_1c7c;
	case 7297ULL: goto x86_l_1c81;
	case 7302ULL: goto x86_l_1c86;
	case 7304ULL: goto x86_l_1c88;
	case 7306ULL: goto x86_l_1c8a;
	case 7312ULL: goto x86_l_1c90;
	case 7320ULL: goto x86_l_1c98;
	case 7326ULL: goto x86_l_1c9e;
	case 7332ULL: goto x86_l_1ca4;
	case 7337ULL: goto x86_l_1ca9;
	case 7342ULL: goto x86_l_1cae;
	case 7350ULL: goto x86_l_1cb6;
	case 7352ULL: goto x86_l_1cb8;
	case 7357ULL: goto x86_l_1cbd;
	case 7362ULL: goto x86_l_1cc2;
	case 7367ULL: goto x86_l_1cc7;
	case 7372ULL: goto x86_l_1ccc;
	case 7377ULL: goto x86_l_1cd1;
	case 7379ULL: goto x86_l_1cd3;
	case 7381ULL: goto x86_l_1cd5;
	case 7387ULL: goto x86_l_1cdb;
	default: return 0xffffffffffffffffULL;
	}
x86_l_158d:
	/* 0x158d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1592:
	/* 0x1592: cmp    WORD PTR [rbx+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_159a:
	/* 0x159a: je     15bf <generic_sleepable_preload+0x15bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15bf;
	}
x86_l_159c:
	/* 0x159c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15a1:
	/* 0x15a1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_15a6:
	/* 0x15a6: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_15ab:
	/* 0x15ab: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15b0:
	/* 0x15b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15b5:
	/* 0x15b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15b7:
	/* 0x15b7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15b9:
	/* 0x15b9: js     3873 <generic_sleepable_preload+0x3873> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14451ULL;
	}
x86_l_15bf:
	/* 0x15bf: cmp    WORD PTR [rbx+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_15c7:
	/* 0x15c7: je     3259 <generic_sleepable_preload+0x3259> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12889ULL;
	}
x86_l_15cd:
	/* 0x15cd: mov    ecx,DWORD PTR [rbx+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_15d3:
	/* 0x15d3: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_15d8:
	/* 0x15d8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15dd:
	/* 0x15dd: cmp    WORD PTR [rbx+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_15e5:
	/* 0x15e5: je     3259 <generic_sleepable_preload+0x3259> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12889ULL;
	}
x86_l_15eb:
	/* 0x15eb: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15f0:
	/* 0x15f0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_15f5:
	/* 0x15f5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_15fa:
	/* 0x15fa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15ff:
	/* 0x15ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1604:
	/* 0x1604: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1606:
	/* 0x1606: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1608:
	/* 0x1608: jns    3259 <generic_sleepable_preload+0x3259> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 12889ULL;
	}
x86_l_160e:
	/* 0x160e: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_1614:
	/* 0x1614: jmp    3257 <generic_sleepable_preload+0x3257> */
	return 12887ULL;
x86_l_1619:
	/* 0x1619: mov    edx,DWORD PTR [rbx+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_161f:
	/* 0x161f: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1625:
	/* 0x1625: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1628:
	/* 0x1628: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_162d:
	/* 0x162d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1632:
	/* 0x1632: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1637:
	/* 0x1637: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_163c:
	/* 0x163c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_163e:
	/* 0x163e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1640:
	/* 0x1640: jne    16c3 <generic_sleepable_preload+0x16c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16c3;
	}
x86_l_1646:
	/* 0x1646: mov    edx,DWORD PTR [rbx+0x254] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 596ULL);
x86_l_164c:
	/* 0x164c: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1652:
	/* 0x1652: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1655:
	/* 0x1655: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1658:
	/* 0x1658: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_165d:
	/* 0x165d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1662:
	/* 0x1662: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1667:
	/* 0x1667: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1669:
	/* 0x1669: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_166b:
	/* 0x166b: jne    16c3 <generic_sleepable_preload+0x16c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16c3;
	}
x86_l_166d:
	/* 0x166d: movzx  eax,BYTE PTR [rbx+0x25b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 603ULL);
x86_l_1674:
	/* 0x1674: shlx   rax,QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_167a:
	/* 0x167a: mov    rcx,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_1681:
	/* 0x1681: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1686:
	/* 0x1686: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1689:
	/* 0x1689: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_168e:
	/* 0x168e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1693:
	/* 0x1693: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1698:
	/* 0x1698: movzx  ecx,BYTE PTR [rbx+0x25b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 603ULL);
x86_l_169f:
	/* 0x169f: shlx   rcx,QWORD PTR [rsp],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_16a5:
	/* 0x16a5: mov    rdx,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_16ac:
	/* 0x16ac: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_16b1:
	/* 0x16b1: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16b4:
	/* 0x16b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16b9:
	/* 0x16b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16bb:
	/* 0x16bb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16bd:
	/* 0x16bd: je     b01 <generic_sleepable_preload+0xb01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2817ULL;
	}
x86_l_16c3:
	/* 0x16c3: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_16c6:
	/* 0x16c6: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16cb:
	/* 0x16cb: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16ce:
	/* 0x16ce: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_16d1:
	/* 0x16d1: cmp    WORD PTR [rbx+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_16d9:
	/* 0x16d9: je     32ec <generic_sleepable_preload+0x32ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13036ULL;
	}
x86_l_16df:
	/* 0x16df: mov    eax,DWORD PTR [rbx+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_16e5:
	/* 0x16e5: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16e8:
	/* 0x16e8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16ed:
	/* 0x16ed: cmp    WORD PTR [rbx+0x164],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1529008357376ULL);
x86_l_16f5:
	/* 0x16f5: je     171a <generic_sleepable_preload+0x171a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_171a;
	}
x86_l_16f7:
	/* 0x16f7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16fc:
	/* 0x16fc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1701:
	/* 0x1701: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1706:
	/* 0x1706: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_170b:
	/* 0x170b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1710:
	/* 0x1710: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1712:
	/* 0x1712: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1714:
	/* 0x1714: js     1da0 <generic_sleepable_preload+0x1da0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7584ULL;
	}
x86_l_171a:
	/* 0x171a: cmp    WORD PTR [rbx+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_1722:
	/* 0x1722: je     32ec <generic_sleepable_preload+0x32ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13036ULL;
	}
x86_l_1728:
	/* 0x1728: mov    ecx,DWORD PTR [rbx+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_172e:
	/* 0x172e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1733:
	/* 0x1733: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1738:
	/* 0x1738: cmp    WORD PTR [rbx+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_1740:
	/* 0x1740: je     1765 <generic_sleepable_preload+0x1765> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1765;
	}
x86_l_1742:
	/* 0x1742: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1747:
	/* 0x1747: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_174c:
	/* 0x174c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1751:
	/* 0x1751: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1756:
	/* 0x1756: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_175b:
	/* 0x175b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_175d:
	/* 0x175d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_175f:
	/* 0x175f: js     2645 <generic_sleepable_preload+0x2645> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9797ULL;
	}
x86_l_1765:
	/* 0x1765: cmp    WORD PTR [rbx+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_176d:
	/* 0x176d: je     32ec <generic_sleepable_preload+0x32ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13036ULL;
	}
x86_l_1773:
	/* 0x1773: mov    ecx,DWORD PTR [rbx+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_1779:
	/* 0x1779: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_177e:
	/* 0x177e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1783:
	/* 0x1783: cmp    WORD PTR [rbx+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_178b:
	/* 0x178b: je     17b0 <generic_sleepable_preload+0x17b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17b0;
	}
x86_l_178d:
	/* 0x178d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1792:
	/* 0x1792: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1797:
	/* 0x1797: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_179c:
	/* 0x179c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17a1:
	/* 0x17a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17a6:
	/* 0x17a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17a8:
	/* 0x17a8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17aa:
	/* 0x17aa: js     2f9c <generic_sleepable_preload+0x2f9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12188ULL;
	}
x86_l_17b0:
	/* 0x17b0: cmp    WORD PTR [rbx+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_17b8:
	/* 0x17b8: je     32ec <generic_sleepable_preload+0x32ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13036ULL;
	}
x86_l_17be:
	/* 0x17be: mov    ecx,DWORD PTR [rbx+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_17c4:
	/* 0x17c4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_17c9:
	/* 0x17c9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17ce:
	/* 0x17ce: cmp    WORD PTR [rbx+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_17d6:
	/* 0x17d6: je     17fb <generic_sleepable_preload+0x17fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17fb;
	}
x86_l_17d8:
	/* 0x17d8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17dd:
	/* 0x17dd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_17e2:
	/* 0x17e2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_17e7:
	/* 0x17e7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17ec:
	/* 0x17ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17f1:
	/* 0x17f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f3:
	/* 0x17f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17f5:
	/* 0x17f5: js     3008 <generic_sleepable_preload+0x3008> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12296ULL;
	}
x86_l_17fb:
	/* 0x17fb: cmp    WORD PTR [rbx+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_1803:
	/* 0x1803: je     32ec <generic_sleepable_preload+0x32ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13036ULL;
	}
x86_l_1809:
	/* 0x1809: mov    ecx,DWORD PTR [rbx+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_180f:
	/* 0x180f: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1814:
	/* 0x1814: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1819:
	/* 0x1819: cmp    WORD PTR [rbx+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_1821:
	/* 0x1821: je     1846 <generic_sleepable_preload+0x1846> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1846;
	}
x86_l_1823:
	/* 0x1823: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1828:
	/* 0x1828: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_182d:
	/* 0x182d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1832:
	/* 0x1832: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1837:
	/* 0x1837: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_183c:
	/* 0x183c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_183e:
	/* 0x183e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1840:
	/* 0x1840: js     3074 <generic_sleepable_preload+0x3074> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12404ULL;
	}
x86_l_1846:
	/* 0x1846: cmp    WORD PTR [rbx+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_184e:
	/* 0x184e: je     32ec <generic_sleepable_preload+0x32ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13036ULL;
	}
x86_l_1854:
	/* 0x1854: mov    ecx,DWORD PTR [rbx+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_185a:
	/* 0x185a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_185f:
	/* 0x185f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1864:
	/* 0x1864: cmp    WORD PTR [rbx+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_186c:
	/* 0x186c: je     1891 <generic_sleepable_preload+0x1891> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1891;
	}
x86_l_186e:
	/* 0x186e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1873:
	/* 0x1873: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1878:
	/* 0x1878: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_187d:
	/* 0x187d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1882:
	/* 0x1882: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1887:
	/* 0x1887: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1889:
	/* 0x1889: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_188b:
	/* 0x188b: js     30dd <generic_sleepable_preload+0x30dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12509ULL;
	}
x86_l_1891:
	/* 0x1891: cmp    WORD PTR [rbx+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_1899:
	/* 0x1899: je     32ec <generic_sleepable_preload+0x32ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13036ULL;
	}
x86_l_189f:
	/* 0x189f: mov    ecx,DWORD PTR [rbx+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_18a5:
	/* 0x18a5: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_18aa:
	/* 0x18aa: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18af:
	/* 0x18af: cmp    WORD PTR [rbx+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_18b7:
	/* 0x18b7: je     18dc <generic_sleepable_preload+0x18dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18dc;
	}
x86_l_18b9:
	/* 0x18b9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18be:
	/* 0x18be: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_18c3:
	/* 0x18c3: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_18c8:
	/* 0x18c8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18cd:
	/* 0x18cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18d2:
	/* 0x18d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18d4:
	/* 0x18d4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18d6:
	/* 0x18d6: js     32e4 <generic_sleepable_preload+0x32e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13028ULL;
	}
x86_l_18dc:
	/* 0x18dc: cmp    WORD PTR [rbx+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_18e4:
	/* 0x18e4: je     32ec <generic_sleepable_preload+0x32ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13036ULL;
	}
x86_l_18ea:
	/* 0x18ea: mov    ecx,DWORD PTR [rbx+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_18f0:
	/* 0x18f0: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_18f5:
	/* 0x18f5: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18fa:
	/* 0x18fa: cmp    WORD PTR [rbx+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_1902:
	/* 0x1902: je     1927 <generic_sleepable_preload+0x1927> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1927;
	}
x86_l_1904:
	/* 0x1904: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1909:
	/* 0x1909: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_190e:
	/* 0x190e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1913:
	/* 0x1913: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1918:
	/* 0x1918: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_191d:
	/* 0x191d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_191f:
	/* 0x191f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1921:
	/* 0x1921: js     37d0 <generic_sleepable_preload+0x37d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14288ULL;
	}
x86_l_1927:
	/* 0x1927: cmp    WORD PTR [rbx+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_192f:
	/* 0x192f: je     32ec <generic_sleepable_preload+0x32ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13036ULL;
	}
x86_l_1935:
	/* 0x1935: mov    ecx,DWORD PTR [rbx+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_193b:
	/* 0x193b: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1940:
	/* 0x1940: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1945:
	/* 0x1945: cmp    WORD PTR [rbx+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_194d:
	/* 0x194d: je     1972 <generic_sleepable_preload+0x1972> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1972;
	}
x86_l_194f:
	/* 0x194f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1954:
	/* 0x1954: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1959:
	/* 0x1959: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_195e:
	/* 0x195e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1963:
	/* 0x1963: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1968:
	/* 0x1968: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_196a:
	/* 0x196a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_196c:
	/* 0x196c: js     387e <generic_sleepable_preload+0x387e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14462ULL;
	}
x86_l_1972:
	/* 0x1972: cmp    WORD PTR [rbx+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_197a:
	/* 0x197a: je     32ec <generic_sleepable_preload+0x32ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13036ULL;
	}
x86_l_1980:
	/* 0x1980: mov    ecx,DWORD PTR [rbx+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_1986:
	/* 0x1986: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_198b:
	/* 0x198b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1990:
	/* 0x1990: cmp    WORD PTR [rbx+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_1998:
	/* 0x1998: je     32ec <generic_sleepable_preload+0x32ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13036ULL;
	}
x86_l_199e:
	/* 0x199e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19a3:
	/* 0x19a3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_19a8:
	/* 0x19a8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_19ad:
	/* 0x19ad: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19b2:
	/* 0x19b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19b7:
	/* 0x19b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b9:
	/* 0x19b9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19bb:
	/* 0x19bb: jns    32ec <generic_sleepable_preload+0x32ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 13036ULL;
	}
x86_l_19c1:
	/* 0x19c1: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_19c7:
	/* 0x19c7: jmp    32ea <generic_sleepable_preload+0x32ea> */
	return 13034ULL;
x86_l_19cc:
	/* 0x19cc: mov    edx,DWORD PTR [rbx+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_19d2:
	/* 0x19d2: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_19d8:
	/* 0x19d8: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_19db:
	/* 0x19db: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19e0:
	/* 0x19e0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19e5:
	/* 0x19e5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19ea:
	/* 0x19ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19ef:
	/* 0x19ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19f1:
	/* 0x19f1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19f3:
	/* 0x19f3: jne    1a78 <generic_sleepable_preload+0x1a78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a78;
	}
x86_l_19f9:
	/* 0x19f9: mov    eax,DWORD PTR [rbx+0x26c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 620ULL);
x86_l_19ff:
	/* 0x19ff: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1a04:
	/* 0x1a04: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a07:
	/* 0x1a07: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a0a:
	/* 0x1a0a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a0f:
	/* 0x1a0f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a14:
	/* 0x1a14: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a19:
	/* 0x1a19: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1a1c:
	/* 0x1a1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a1e:
	/* 0x1a1e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a20:
	/* 0x1a20: jne    1a78 <generic_sleepable_preload+0x1a78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a78;
	}
x86_l_1a22:
	/* 0x1a22: movzx  eax,BYTE PTR [rbx+0x273] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 627ULL);
x86_l_1a29:
	/* 0x1a29: shlx   rax,QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_1a2f:
	/* 0x1a2f: mov    rcx,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_1a36:
	/* 0x1a36: add    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1a3b:
	/* 0x1a3b: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a3e:
	/* 0x1a3e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a43:
	/* 0x1a43: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1a48:
	/* 0x1a48: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1a4d:
	/* 0x1a4d: movzx  ecx,BYTE PTR [rbx+0x273] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 627ULL);
x86_l_1a54:
	/* 0x1a54: shlx   rcx,QWORD PTR [rsp],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_1a5a:
	/* 0x1a5a: mov    rdx,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_1a61:
	/* 0x1a61: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1a66:
	/* 0x1a66: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a69:
	/* 0x1a69: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a6e:
	/* 0x1a6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a70:
	/* 0x1a70: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a72:
	/* 0x1a72: je     b35 <generic_sleepable_preload+0xb35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2869ULL;
	}
x86_l_1a78:
	/* 0x1a78: movsxd rcx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_1a7b:
	/* 0x1a7b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a80:
	/* 0x1a80: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a82:
	/* 0x1a82: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_1a85:
	/* 0x1a85: cmp    WORD PTR [rbx+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_1a8d:
	/* 0x1a8d: je     337f <generic_sleepable_preload+0x337f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13183ULL;
	}
x86_l_1a93:
	/* 0x1a93: mov    eax,DWORD PTR [rbx+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_1a99:
	/* 0x1a99: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a9c:
	/* 0x1a9c: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aa1:
	/* 0x1aa1: cmp    WORD PTR [rbx+0x1b4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1872605741056ULL);
x86_l_1aa9:
	/* 0x1aa9: je     1ace <generic_sleepable_preload+0x1ace> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ace;
	}
x86_l_1aab:
	/* 0x1aab: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ab0:
	/* 0x1ab0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1ab5:
	/* 0x1ab5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1aba:
	/* 0x1aba: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1abf:
	/* 0x1abf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ac4:
	/* 0x1ac4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ac6:
	/* 0x1ac6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ac8:
	/* 0x1ac8: js     1dab <generic_sleepable_preload+0x1dab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7595ULL;
	}
x86_l_1ace:
	/* 0x1ace: cmp    WORD PTR [rbx+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_1ad6:
	/* 0x1ad6: je     337f <generic_sleepable_preload+0x337f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13183ULL;
	}
x86_l_1adc:
	/* 0x1adc: mov    ecx,DWORD PTR [rbx+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_1ae2:
	/* 0x1ae2: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ae7:
	/* 0x1ae7: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aec:
	/* 0x1aec: cmp    WORD PTR [rbx+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_1af4:
	/* 0x1af4: je     1b19 <generic_sleepable_preload+0x1b19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b19;
	}
x86_l_1af6:
	/* 0x1af6: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1afb:
	/* 0x1afb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b00:
	/* 0x1b00: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b05:
	/* 0x1b05: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b0a:
	/* 0x1b0a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b0f:
	/* 0x1b0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b11:
	/* 0x1b11: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b13:
	/* 0x1b13: js     2650 <generic_sleepable_preload+0x2650> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9808ULL;
	}
x86_l_1b19:
	/* 0x1b19: cmp    WORD PTR [rbx+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
x86_l_1b21:
	/* 0x1b21: je     337f <generic_sleepable_preload+0x337f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13183ULL;
	}
x86_l_1b27:
	/* 0x1b27: mov    ecx,DWORD PTR [rbx+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_1b2d:
	/* 0x1b2d: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1b32:
	/* 0x1b32: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b37:
	/* 0x1b37: cmp    WORD PTR [rbx+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_1b3f:
	/* 0x1b3f: je     1b64 <generic_sleepable_preload+0x1b64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b64;
	}
x86_l_1b41:
	/* 0x1b41: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b46:
	/* 0x1b46: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b4b:
	/* 0x1b4b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b50:
	/* 0x1b50: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b55:
	/* 0x1b55: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b5a:
	/* 0x1b5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b5c:
	/* 0x1b5c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b5e:
	/* 0x1b5e: js     2fa7 <generic_sleepable_preload+0x2fa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12199ULL;
	}
x86_l_1b64:
	/* 0x1b64: cmp    WORD PTR [rbx+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_1b6c:
	/* 0x1b6c: je     337f <generic_sleepable_preload+0x337f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13183ULL;
	}
x86_l_1b72:
	/* 0x1b72: mov    ecx,DWORD PTR [rbx+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_1b78:
	/* 0x1b78: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1b7d:
	/* 0x1b7d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b82:
	/* 0x1b82: cmp    WORD PTR [rbx+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_1b8a:
	/* 0x1b8a: je     1baf <generic_sleepable_preload+0x1baf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1baf;
	}
x86_l_1b8c:
	/* 0x1b8c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b91:
	/* 0x1b91: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1b96:
	/* 0x1b96: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1b9b:
	/* 0x1b9b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ba0:
	/* 0x1ba0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ba5:
	/* 0x1ba5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ba7:
	/* 0x1ba7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ba9:
	/* 0x1ba9: js     3013 <generic_sleepable_preload+0x3013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12307ULL;
	}
x86_l_1baf:
	/* 0x1baf: cmp    WORD PTR [rbx+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_1bb7:
	/* 0x1bb7: je     337f <generic_sleepable_preload+0x337f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13183ULL;
	}
x86_l_1bbd:
	/* 0x1bbd: mov    ecx,DWORD PTR [rbx+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_1bc3:
	/* 0x1bc3: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1bc8:
	/* 0x1bc8: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bcd:
	/* 0x1bcd: cmp    WORD PTR [rbx+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_1bd5:
	/* 0x1bd5: je     1bfa <generic_sleepable_preload+0x1bfa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bfa;
	}
x86_l_1bd7:
	/* 0x1bd7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bdc:
	/* 0x1bdc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1be1:
	/* 0x1be1: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1be6:
	/* 0x1be6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1beb:
	/* 0x1beb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bf0:
	/* 0x1bf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bf2:
	/* 0x1bf2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bf4:
	/* 0x1bf4: js     307f <generic_sleepable_preload+0x307f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12415ULL;
	}
x86_l_1bfa:
	/* 0x1bfa: cmp    WORD PTR [rbx+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_1c02:
	/* 0x1c02: je     337f <generic_sleepable_preload+0x337f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13183ULL;
	}
x86_l_1c08:
	/* 0x1c08: mov    ecx,DWORD PTR [rbx+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_1c0e:
	/* 0x1c0e: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1c13:
	/* 0x1c13: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c18:
	/* 0x1c18: cmp    WORD PTR [rbx+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_1c20:
	/* 0x1c20: je     1c45 <generic_sleepable_preload+0x1c45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c45;
	}
x86_l_1c22:
	/* 0x1c22: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c27:
	/* 0x1c27: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1c2c:
	/* 0x1c2c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1c31:
	/* 0x1c31: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c36:
	/* 0x1c36: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c3b:
	/* 0x1c3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c3d:
	/* 0x1c3d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c3f:
	/* 0x1c3f: js     30e8 <generic_sleepable_preload+0x30e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12520ULL;
	}
x86_l_1c45:
	/* 0x1c45: cmp    WORD PTR [rbx+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_1c4d:
	/* 0x1c4d: je     337f <generic_sleepable_preload+0x337f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13183ULL;
	}
x86_l_1c53:
	/* 0x1c53: mov    ecx,DWORD PTR [rbx+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_1c59:
	/* 0x1c59: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1c5e:
	/* 0x1c5e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c63:
	/* 0x1c63: cmp    WORD PTR [rbx+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_1c6b:
	/* 0x1c6b: je     1c90 <generic_sleepable_preload+0x1c90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c90;
	}
x86_l_1c6d:
	/* 0x1c6d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c72:
	/* 0x1c72: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1c77:
	/* 0x1c77: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1c7c:
	/* 0x1c7c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c81:
	/* 0x1c81: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c86:
	/* 0x1c86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c88:
	/* 0x1c88: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c8a:
	/* 0x1c8a: js     3377 <generic_sleepable_preload+0x3377> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13175ULL;
	}
x86_l_1c90:
	/* 0x1c90: cmp    WORD PTR [rbx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_1c98:
	/* 0x1c98: je     337f <generic_sleepable_preload+0x337f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13183ULL;
	}
x86_l_1c9e:
	/* 0x1c9e: mov    ecx,DWORD PTR [rbx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_1ca4:
	/* 0x1ca4: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ca9:
	/* 0x1ca9: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cae:
	/* 0x1cae: cmp    WORD PTR [rbx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_1cb6:
	/* 0x1cb6: je     1cdb <generic_sleepable_preload+0x1cdb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cdb;
	}
x86_l_1cb8:
	/* 0x1cb8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cbd:
	/* 0x1cbd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1cc2:
	/* 0x1cc2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1cc7:
	/* 0x1cc7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ccc:
	/* 0x1ccc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cd1:
	/* 0x1cd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd3:
	/* 0x1cd3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cd5:
	/* 0x1cd5: js     37dd <generic_sleepable_preload+0x37dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14301ULL;
	}
x86_l_1cdb:
	/* 0x1cdb: cmp    WORD PTR [rbx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
	return 7395ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7395ULL: goto x86_l_1ce3;
	case 7401ULL: goto x86_l_1ce9;
	case 7407ULL: goto x86_l_1cef;
	case 7412ULL: goto x86_l_1cf4;
	case 7417ULL: goto x86_l_1cf9;
	case 7425ULL: goto x86_l_1d01;
	case 7427ULL: goto x86_l_1d03;
	case 7432ULL: goto x86_l_1d08;
	case 7437ULL: goto x86_l_1d0d;
	case 7442ULL: goto x86_l_1d12;
	case 7447ULL: goto x86_l_1d17;
	case 7452ULL: goto x86_l_1d1c;
	case 7454ULL: goto x86_l_1d1e;
	case 7456ULL: goto x86_l_1d20;
	case 7462ULL: goto x86_l_1d26;
	case 7470ULL: goto x86_l_1d2e;
	case 7476ULL: goto x86_l_1d34;
	case 7482ULL: goto x86_l_1d3a;
	case 7487ULL: goto x86_l_1d3f;
	case 7492ULL: goto x86_l_1d44;
	case 7500ULL: goto x86_l_1d4c;
	case 7506ULL: goto x86_l_1d52;
	case 7511ULL: goto x86_l_1d57;
	case 7516ULL: goto x86_l_1d5c;
	case 7521ULL: goto x86_l_1d61;
	case 7526ULL: goto x86_l_1d66;
	case 7531ULL: goto x86_l_1d6b;
	case 7533ULL: goto x86_l_1d6d;
	case 7535ULL: goto x86_l_1d6f;
	case 7541ULL: goto x86_l_1d75;
	case 7546ULL: goto x86_l_1d7a;
	case 7551ULL: goto x86_l_1d7f;
	case 7557ULL: goto x86_l_1d85;
	case 7562ULL: goto x86_l_1d8a;
	case 7568ULL: goto x86_l_1d90;
	case 7573ULL: goto x86_l_1d95;
	case 7579ULL: goto x86_l_1d9b;
	case 7584ULL: goto x86_l_1da0;
	case 7590ULL: goto x86_l_1da6;
	case 7595ULL: goto x86_l_1dab;
	case 7600ULL: goto x86_l_1db0;
	case 7605ULL: goto x86_l_1db5;
	case 7613ULL: goto x86_l_1dbd;
	case 7616ULL: goto x86_l_1dc0;
	case 7622ULL: goto x86_l_1dc6;
	case 7627ULL: goto x86_l_1dcb;
	case 7630ULL: goto x86_l_1dce;
	case 7636ULL: goto x86_l_1dd4;
	case 7641ULL: goto x86_l_1dd9;
	case 7649ULL: goto x86_l_1de1;
	case 7652ULL: goto x86_l_1de4;
	case 7658ULL: goto x86_l_1dea;
	case 7663ULL: goto x86_l_1def;
	case 7666ULL: goto x86_l_1df2;
	case 7672ULL: goto x86_l_1df8;
	case 7677ULL: goto x86_l_1dfd;
	case 7685ULL: goto x86_l_1e05;
	case 7688ULL: goto x86_l_1e08;
	case 7694ULL: goto x86_l_1e0e;
	case 7699ULL: goto x86_l_1e13;
	case 7702ULL: goto x86_l_1e16;
	case 7708ULL: goto x86_l_1e1c;
	case 7713ULL: goto x86_l_1e21;
	case 7721ULL: goto x86_l_1e29;
	case 7724ULL: goto x86_l_1e2c;
	case 7730ULL: goto x86_l_1e32;
	case 7735ULL: goto x86_l_1e37;
	case 7738ULL: goto x86_l_1e3a;
	case 7744ULL: goto x86_l_1e40;
	case 7749ULL: goto x86_l_1e45;
	case 7757ULL: goto x86_l_1e4d;
	case 7760ULL: goto x86_l_1e50;
	case 7766ULL: goto x86_l_1e56;
	case 7771ULL: goto x86_l_1e5b;
	case 7774ULL: goto x86_l_1e5e;
	case 7780ULL: goto x86_l_1e64;
	case 7785ULL: goto x86_l_1e69;
	case 7790ULL: goto x86_l_1e6e;
	case 7793ULL: goto x86_l_1e71;
	case 7799ULL: goto x86_l_1e77;
	case 7804ULL: goto x86_l_1e7c;
	case 7807ULL: goto x86_l_1e7f;
	case 7813ULL: goto x86_l_1e85;
	case 7818ULL: goto x86_l_1e8a;
	case 7823ULL: goto x86_l_1e8f;
	case 7826ULL: goto x86_l_1e92;
	case 7832ULL: goto x86_l_1e98;
	case 7837ULL: goto x86_l_1e9d;
	case 7840ULL: goto x86_l_1ea0;
	case 7846ULL: goto x86_l_1ea6;
	case 7851ULL: goto x86_l_1eab;
	case 7856ULL: goto x86_l_1eb0;
	case 7859ULL: goto x86_l_1eb3;
	case 7865ULL: goto x86_l_1eb9;
	case 7870ULL: goto x86_l_1ebe;
	case 7873ULL: goto x86_l_1ec1;
	case 7879ULL: goto x86_l_1ec7;
	case 7884ULL: goto x86_l_1ecc;
	case 7889ULL: goto x86_l_1ed1;
	case 7892ULL: goto x86_l_1ed4;
	case 7898ULL: goto x86_l_1eda;
	case 7903ULL: goto x86_l_1edf;
	case 7906ULL: goto x86_l_1ee2;
	case 7912ULL: goto x86_l_1ee8;
	case 7917ULL: goto x86_l_1eed;
	case 7922ULL: goto x86_l_1ef2;
	case 7925ULL: goto x86_l_1ef5;
	case 7931ULL: goto x86_l_1efb;
	case 7936ULL: goto x86_l_1f00;
	case 7939ULL: goto x86_l_1f03;
	case 7945ULL: goto x86_l_1f09;
	case 7950ULL: goto x86_l_1f0e;
	case 7955ULL: goto x86_l_1f13;
	case 7958ULL: goto x86_l_1f16;
	case 7964ULL: goto x86_l_1f1c;
	case 7969ULL: goto x86_l_1f21;
	case 7972ULL: goto x86_l_1f24;
	case 7978ULL: goto x86_l_1f2a;
	case 7983ULL: goto x86_l_1f2f;
	case 7988ULL: goto x86_l_1f34;
	case 7991ULL: goto x86_l_1f37;
	case 7997ULL: goto x86_l_1f3d;
	case 8002ULL: goto x86_l_1f42;
	case 8005ULL: goto x86_l_1f45;
	case 8011ULL: goto x86_l_1f4b;
	case 8016ULL: goto x86_l_1f50;
	case 8021ULL: goto x86_l_1f55;
	case 8024ULL: goto x86_l_1f58;
	case 8030ULL: goto x86_l_1f5e;
	case 8035ULL: goto x86_l_1f63;
	case 8038ULL: goto x86_l_1f66;
	case 8044ULL: goto x86_l_1f6c;
	case 8049ULL: goto x86_l_1f71;
	case 8054ULL: goto x86_l_1f76;
	case 8057ULL: goto x86_l_1f79;
	case 8063ULL: goto x86_l_1f7f;
	case 8068ULL: goto x86_l_1f84;
	case 8071ULL: goto x86_l_1f87;
	case 8077ULL: goto x86_l_1f8d;
	case 8082ULL: goto x86_l_1f92;
	case 8087ULL: goto x86_l_1f97;
	case 8090ULL: goto x86_l_1f9a;
	case 8096ULL: goto x86_l_1fa0;
	case 8101ULL: goto x86_l_1fa5;
	case 8104ULL: goto x86_l_1fa8;
	case 8110ULL: goto x86_l_1fae;
	case 8115ULL: goto x86_l_1fb3;
	case 8123ULL: goto x86_l_1fbb;
	case 8126ULL: goto x86_l_1fbe;
	case 8128ULL: goto x86_l_1fc0;
	case 8133ULL: goto x86_l_1fc5;
	case 8136ULL: goto x86_l_1fc8;
	case 8138ULL: goto x86_l_1fca;
	case 8141ULL: goto x86_l_1fcd;
	case 8143ULL: goto x86_l_1fcf;
	case 8145ULL: goto x86_l_1fd1;
	case 8150ULL: goto x86_l_1fd6;
	case 8152ULL: goto x86_l_1fd8;
	case 8157ULL: goto x86_l_1fdd;
	case 8161ULL: goto x86_l_1fe1;
	case 8165ULL: goto x86_l_1fe5;
	case 8168ULL: goto x86_l_1fe8;
	case 8171ULL: goto x86_l_1feb;
	case 8176ULL: goto x86_l_1ff0;
	case 8182ULL: goto x86_l_1ff6;
	case 8185ULL: goto x86_l_1ff9;
	case 8188ULL: goto x86_l_1ffc;
	case 8192ULL: goto x86_l_2000;
	case 8197ULL: goto x86_l_2005;
	case 8199ULL: goto x86_l_2007;
	case 8202ULL: goto x86_l_200a;
	case 8207ULL: goto x86_l_200f;
	case 8212ULL: goto x86_l_2014;
	case 8216ULL: goto x86_l_2018;
	case 8221ULL: goto x86_l_201d;
	case 8223ULL: goto x86_l_201f;
	case 8225ULL: goto x86_l_2021;
	case 8231ULL: goto x86_l_2027;
	case 8236ULL: goto x86_l_202c;
	case 8242ULL: goto x86_l_2032;
	case 8245ULL: goto x86_l_2035;
	case 8249ULL: goto x86_l_2039;
	case 8253ULL: goto x86_l_203d;
	case 8258ULL: goto x86_l_2042;
	case 8260ULL: goto x86_l_2044;
	case 8263ULL: goto x86_l_2047;
	case 8268ULL: goto x86_l_204c;
	case 8273ULL: goto x86_l_2051;
	case 8277ULL: goto x86_l_2055;
	case 8282ULL: goto x86_l_205a;
	case 8284ULL: goto x86_l_205c;
	case 8286ULL: goto x86_l_205e;
	case 8292ULL: goto x86_l_2064;
	case 8300ULL: goto x86_l_206c;
	case 8306ULL: goto x86_l_2072;
	case 8312ULL: goto x86_l_2078;
	case 8316ULL: goto x86_l_207c;
	case 8320ULL: goto x86_l_2080;
	case 8328ULL: goto x86_l_2088;
	case 8330ULL: goto x86_l_208a;
	case 8333ULL: goto x86_l_208d;
	case 8338ULL: goto x86_l_2092;
	case 8343ULL: goto x86_l_2097;
	case 8347ULL: goto x86_l_209b;
	case 8352ULL: goto x86_l_20a0;
	case 8354ULL: goto x86_l_20a2;
	case 8356ULL: goto x86_l_20a4;
	case 8362ULL: goto x86_l_20aa;
	case 8370ULL: goto x86_l_20b2;
	case 8376ULL: goto x86_l_20b8;
	case 8382ULL: goto x86_l_20be;
	case 8386ULL: goto x86_l_20c2;
	case 8390ULL: goto x86_l_20c6;
	case 8398ULL: goto x86_l_20ce;
	case 8400ULL: goto x86_l_20d0;
	case 8403ULL: goto x86_l_20d3;
	case 8408ULL: goto x86_l_20d8;
	case 8413ULL: goto x86_l_20dd;
	case 8417ULL: goto x86_l_20e1;
	case 8422ULL: goto x86_l_20e6;
	case 8424ULL: goto x86_l_20e8;
	case 8426ULL: goto x86_l_20ea;
	case 8432ULL: goto x86_l_20f0;
	case 8440ULL: goto x86_l_20f8;
	case 8446ULL: goto x86_l_20fe;
	case 8452ULL: goto x86_l_2104;
	case 8456ULL: goto x86_l_2108;
	case 8460ULL: goto x86_l_210c;
	case 8468ULL: goto x86_l_2114;
	case 8470ULL: goto x86_l_2116;
	case 8473ULL: goto x86_l_2119;
	case 8478ULL: goto x86_l_211e;
	case 8483ULL: goto x86_l_2123;
	case 8487ULL: goto x86_l_2127;
	case 8492ULL: goto x86_l_212c;
	case 8494ULL: goto x86_l_212e;
	case 8496ULL: goto x86_l_2130;
	case 8502ULL: goto x86_l_2136;
	case 8510ULL: goto x86_l_213e;
	case 8516ULL: goto x86_l_2144;
	case 8522ULL: goto x86_l_214a;
	case 8526ULL: goto x86_l_214e;
	case 8530ULL: goto x86_l_2152;
	case 8538ULL: goto x86_l_215a;
	case 8540ULL: goto x86_l_215c;
	case 8543ULL: goto x86_l_215f;
	case 8548ULL: goto x86_l_2164;
	case 8553ULL: goto x86_l_2169;
	case 8557ULL: goto x86_l_216d;
	case 8562ULL: goto x86_l_2172;
	case 8564ULL: goto x86_l_2174;
	case 8566ULL: goto x86_l_2176;
	case 8572ULL: goto x86_l_217c;
	case 8580ULL: goto x86_l_2184;
	case 8586ULL: goto x86_l_218a;
	case 8592ULL: goto x86_l_2190;
	case 8596ULL: goto x86_l_2194;
	case 8600ULL: goto x86_l_2198;
	case 8608ULL: goto x86_l_21a0;
	case 8610ULL: goto x86_l_21a2;
	case 8613ULL: goto x86_l_21a5;
	case 8618ULL: goto x86_l_21aa;
	case 8623ULL: goto x86_l_21af;
	case 8627ULL: goto x86_l_21b3;
	case 8632ULL: goto x86_l_21b8;
	case 8634ULL: goto x86_l_21ba;
	case 8636ULL: goto x86_l_21bc;
	case 8642ULL: goto x86_l_21c2;
	case 8650ULL: goto x86_l_21ca;
	case 8656ULL: goto x86_l_21d0;
	case 8662ULL: goto x86_l_21d6;
	case 8666ULL: goto x86_l_21da;
	case 8670ULL: goto x86_l_21de;
	case 8678ULL: goto x86_l_21e6;
	case 8680ULL: goto x86_l_21e8;
	case 8683ULL: goto x86_l_21eb;
	case 8688ULL: goto x86_l_21f0;
	case 8693ULL: goto x86_l_21f5;
	case 8697ULL: goto x86_l_21f9;
	case 8702ULL: goto x86_l_21fe;
	case 8704ULL: goto x86_l_2200;
	case 8706ULL: goto x86_l_2202;
	case 8712ULL: goto x86_l_2208;
	case 8720ULL: goto x86_l_2210;
	case 8726ULL: goto x86_l_2216;
	case 8732ULL: goto x86_l_221c;
	case 8736ULL: goto x86_l_2220;
	case 8740ULL: goto x86_l_2224;
	case 8748ULL: goto x86_l_222c;
	case 8750ULL: goto x86_l_222e;
	case 8753ULL: goto x86_l_2231;
	case 8758ULL: goto x86_l_2236;
	case 8763ULL: goto x86_l_223b;
	case 8767ULL: goto x86_l_223f;
	case 8772ULL: goto x86_l_2244;
	case 8774ULL: goto x86_l_2246;
	case 8776ULL: goto x86_l_2248;
	case 8782ULL: goto x86_l_224e;
	case 8790ULL: goto x86_l_2256;
	case 8796ULL: goto x86_l_225c;
	case 8802ULL: goto x86_l_2262;
	case 8806ULL: goto x86_l_2266;
	case 8810ULL: goto x86_l_226a;
	case 8818ULL: goto x86_l_2272;
	case 8824ULL: goto x86_l_2278;
	case 8827ULL: goto x86_l_227b;
	case 8832ULL: goto x86_l_2280;
	case 8837ULL: goto x86_l_2285;
	case 8841ULL: goto x86_l_2289;
	case 8846ULL: goto x86_l_228e;
	case 8848ULL: goto x86_l_2290;
	case 8850ULL: goto x86_l_2292;
	case 8856ULL: goto x86_l_2298;
	case 8862ULL: goto x86_l_229e;
	case 8867ULL: goto x86_l_22a3;
	case 8873ULL: goto x86_l_22a9;
	case 8878ULL: goto x86_l_22ae;
	case 8886ULL: goto x86_l_22b6;
	case 8889ULL: goto x86_l_22b9;
	case 8895ULL: goto x86_l_22bf;
	case 8900ULL: goto x86_l_22c4;
	case 8903ULL: goto x86_l_22c7;
	case 8909ULL: goto x86_l_22cd;
	case 8914ULL: goto x86_l_22d2;
	case 8922ULL: goto x86_l_22da;
	case 8925ULL: goto x86_l_22dd;
	case 8931ULL: goto x86_l_22e3;
	case 8936ULL: goto x86_l_22e8;
	case 8939ULL: goto x86_l_22eb;
	case 8945ULL: goto x86_l_22f1;
	case 8950ULL: goto x86_l_22f6;
	case 8958ULL: goto x86_l_22fe;
	case 8961ULL: goto x86_l_2301;
	case 8967ULL: goto x86_l_2307;
	case 8972ULL: goto x86_l_230c;
	case 8975ULL: goto x86_l_230f;
	case 8981ULL: goto x86_l_2315;
	case 8986ULL: goto x86_l_231a;
	case 8994ULL: goto x86_l_2322;
	case 8997ULL: goto x86_l_2325;
	case 8999ULL: goto x86_l_2327;
	case 9004ULL: goto x86_l_232c;
	case 9007ULL: goto x86_l_232f;
	case 9009ULL: goto x86_l_2331;
	case 9012ULL: goto x86_l_2334;
	case 9014ULL: goto x86_l_2336;
	case 9016ULL: goto x86_l_2338;
	case 9021ULL: goto x86_l_233d;
	case 9023ULL: goto x86_l_233f;
	case 9028ULL: goto x86_l_2344;
	case 9032ULL: goto x86_l_2348;
	case 9036ULL: goto x86_l_234c;
	case 9038ULL: goto x86_l_234e;
	case 9041ULL: goto x86_l_2351;
	case 9049ULL: goto x86_l_2359;
	case 9055ULL: goto x86_l_235f;
	case 9061ULL: goto x86_l_2365;
	case 9064ULL: goto x86_l_2368;
	case 9068ULL: goto x86_l_236c;
	case 9076ULL: goto x86_l_2374;
	case 9078ULL: goto x86_l_2376;
	case 9081ULL: goto x86_l_2379;
	case 9086ULL: goto x86_l_237e;
	case 9091ULL: goto x86_l_2383;
	case 9095ULL: goto x86_l_2387;
	case 9100ULL: goto x86_l_238c;
	case 9102ULL: goto x86_l_238e;
	case 9104ULL: goto x86_l_2390;
	case 9110ULL: goto x86_l_2396;
	case 9118ULL: goto x86_l_239e;
	case 9124ULL: goto x86_l_23a4;
	case 9130ULL: goto x86_l_23aa;
	case 9134ULL: goto x86_l_23ae;
	case 9138ULL: goto x86_l_23b2;
	case 9146ULL: goto x86_l_23ba;
	case 9148ULL: goto x86_l_23bc;
	case 9151ULL: goto x86_l_23bf;
	case 9156ULL: goto x86_l_23c4;
	case 9161ULL: goto x86_l_23c9;
	case 9165ULL: goto x86_l_23cd;
	case 9170ULL: goto x86_l_23d2;
	case 9172ULL: goto x86_l_23d4;
	case 9174ULL: goto x86_l_23d6;
	case 9180ULL: goto x86_l_23dc;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1ce3:
	/* 0x1ce3: je     337f <generic_sleepable_preload+0x337f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13183ULL;
	}
x86_l_1ce9:
	/* 0x1ce9: mov    ecx,DWORD PTR [rbx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_1cef:
	/* 0x1cef: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1cf4:
	/* 0x1cf4: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cf9:
	/* 0x1cf9: cmp    WORD PTR [rbx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_1d01:
	/* 0x1d01: je     1d26 <generic_sleepable_preload+0x1d26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d26;
	}
x86_l_1d03:
	/* 0x1d03: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d08:
	/* 0x1d08: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d0d:
	/* 0x1d0d: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d12:
	/* 0x1d12: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d17:
	/* 0x1d17: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d1c:
	/* 0x1d1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d1e:
	/* 0x1d1e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d20:
	/* 0x1d20: js     3889 <generic_sleepable_preload+0x3889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14473ULL;
	}
x86_l_1d26:
	/* 0x1d26: cmp    WORD PTR [rbx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_1d2e:
	/* 0x1d2e: je     337f <generic_sleepable_preload+0x337f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13183ULL;
	}
x86_l_1d34:
	/* 0x1d34: mov    ecx,DWORD PTR [rbx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_1d3a:
	/* 0x1d3a: add    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1d3f:
	/* 0x1d3f: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d44:
	/* 0x1d44: cmp    WORD PTR [rbx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_1d4c:
	/* 0x1d4c: je     337f <generic_sleepable_preload+0x337f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13183ULL;
	}
x86_l_1d52:
	/* 0x1d52: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d57:
	/* 0x1d57: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1d5c:
	/* 0x1d5c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1d61:
	/* 0x1d61: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d66:
	/* 0x1d66: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d6b:
	/* 0x1d6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d6d:
	/* 0x1d6d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d6f:
	/* 0x1d6f: jns    337f <generic_sleepable_preload+0x337f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 13183ULL;
	}
x86_l_1d75:
	/* 0x1d75: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_1d7a:
	/* 0x1d7a: jmp    337c <generic_sleepable_preload+0x337c> */
	return 13180ULL;
x86_l_1d7f:
	/* 0x1d7f: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_1d85:
	/* 0x1d85: jmp    312e <generic_sleepable_preload+0x312e> */
	return 12590ULL;
x86_l_1d8a:
	/* 0x1d8a: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_1d90:
	/* 0x1d90: jmp    31c4 <generic_sleepable_preload+0x31c4> */
	return 12740ULL;
x86_l_1d95:
	/* 0x1d95: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_1d9b:
	/* 0x1d9b: jmp    3257 <generic_sleepable_preload+0x3257> */
	return 12887ULL;
x86_l_1da0:
	/* 0x1da0: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_1da6:
	/* 0x1da6: jmp    32ea <generic_sleepable_preload+0x32ea> */
	return 13034ULL;
x86_l_1dab:
	/* 0x1dab: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_1db0:
	/* 0x1db0: jmp    337c <generic_sleepable_preload+0x337c> */
	return 13180ULL;
x86_l_1db5:
	/* 0x1db5: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1dbd:
	/* 0x1dbd: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1dc0:
	/* 0x1dc0: je     1fca <generic_sleepable_preload+0x1fca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fca;
	}
x86_l_1dc6:
	/* 0x1dc6: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1dcb:
	/* 0x1dcb: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1dce:
	/* 0x1dce: je     1fca <generic_sleepable_preload+0x1fca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fca;
	}
x86_l_1dd4:
	/* 0x1dd4: jmp    1fdd <generic_sleepable_preload+0x1fdd> */
	goto x86_l_1fdd;
x86_l_1dd9:
	/* 0x1dd9: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1de1:
	/* 0x1de1: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1de4:
	/* 0x1de4: je     2672 <generic_sleepable_preload+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9842ULL;
	}
x86_l_1dea:
	/* 0x1dea: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1def:
	/* 0x1def: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1df2:
	/* 0x1df2: je     2672 <generic_sleepable_preload+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9842ULL;
	}
x86_l_1df8:
	/* 0x1df8: jmp    2685 <generic_sleepable_preload+0x2685> */
	return 9861ULL;
x86_l_1dfd:
	/* 0x1dfd: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1e05:
	/* 0x1e05: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1e08:
	/* 0x1e08: je     2976 <generic_sleepable_preload+0x2976> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10614ULL;
	}
x86_l_1e0e:
	/* 0x1e0e: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e13:
	/* 0x1e13: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1e16:
	/* 0x1e16: je     2976 <generic_sleepable_preload+0x2976> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10614ULL;
	}
x86_l_1e1c:
	/* 0x1e1c: jmp    2989 <generic_sleepable_preload+0x2989> */
	return 10633ULL;
x86_l_1e21:
	/* 0x1e21: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1e29:
	/* 0x1e29: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1e2c:
	/* 0x1e2c: je     2c7a <generic_sleepable_preload+0x2c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11386ULL;
	}
x86_l_1e32:
	/* 0x1e32: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e37:
	/* 0x1e37: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1e3a:
	/* 0x1e3a: je     2c7a <generic_sleepable_preload+0x2c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11386ULL;
	}
x86_l_1e40:
	/* 0x1e40: jmp    2c8d <generic_sleepable_preload+0x2c8d> */
	return 11405ULL;
x86_l_1e45:
	/* 0x1e45: mov    r14,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1e4d:
	/* 0x1e4d: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1e50:
	/* 0x1e50: je     2331 <generic_sleepable_preload+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2331;
	}
x86_l_1e56:
	/* 0x1e56: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e5b:
	/* 0x1e5b: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1e5e:
	/* 0x1e5e: je     2331 <generic_sleepable_preload+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2331;
	}
x86_l_1e64:
	/* 0x1e64: jmp    2344 <generic_sleepable_preload+0x2344> */
	goto x86_l_2344;
x86_l_1e69:
	/* 0x1e69: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1e6e:
	/* 0x1e6e: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1e71:
	/* 0x1e71: je     1fca <generic_sleepable_preload+0x1fca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fca;
	}
x86_l_1e77:
	/* 0x1e77: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e7c:
	/* 0x1e7c: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1e7f:
	/* 0x1e7f: je     1fca <generic_sleepable_preload+0x1fca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fca;
	}
x86_l_1e85:
	/* 0x1e85: jmp    1fdd <generic_sleepable_preload+0x1fdd> */
	goto x86_l_1fdd;
x86_l_1e8a:
	/* 0x1e8a: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1e8f:
	/* 0x1e8f: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1e92:
	/* 0x1e92: je     2672 <generic_sleepable_preload+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9842ULL;
	}
x86_l_1e98:
	/* 0x1e98: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e9d:
	/* 0x1e9d: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1ea0:
	/* 0x1ea0: je     2672 <generic_sleepable_preload+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9842ULL;
	}
x86_l_1ea6:
	/* 0x1ea6: jmp    2685 <generic_sleepable_preload+0x2685> */
	return 9861ULL;
x86_l_1eab:
	/* 0x1eab: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1eb0:
	/* 0x1eb0: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1eb3:
	/* 0x1eb3: je     2976 <generic_sleepable_preload+0x2976> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10614ULL;
	}
x86_l_1eb9:
	/* 0x1eb9: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ebe:
	/* 0x1ebe: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1ec1:
	/* 0x1ec1: je     2976 <generic_sleepable_preload+0x2976> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10614ULL;
	}
x86_l_1ec7:
	/* 0x1ec7: jmp    2989 <generic_sleepable_preload+0x2989> */
	return 10633ULL;
x86_l_1ecc:
	/* 0x1ecc: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1ed1:
	/* 0x1ed1: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1ed4:
	/* 0x1ed4: je     2c7a <generic_sleepable_preload+0x2c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11386ULL;
	}
x86_l_1eda:
	/* 0x1eda: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1edf:
	/* 0x1edf: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1ee2:
	/* 0x1ee2: je     2c7a <generic_sleepable_preload+0x2c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11386ULL;
	}
x86_l_1ee8:
	/* 0x1ee8: jmp    2c8d <generic_sleepable_preload+0x2c8d> */
	return 11405ULL;
x86_l_1eed:
	/* 0x1eed: mov    r14,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1ef2:
	/* 0x1ef2: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1ef5:
	/* 0x1ef5: je     2331 <generic_sleepable_preload+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2331;
	}
x86_l_1efb:
	/* 0x1efb: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f00:
	/* 0x1f00: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1f03:
	/* 0x1f03: je     2331 <generic_sleepable_preload+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2331;
	}
x86_l_1f09:
	/* 0x1f09: jmp    2344 <generic_sleepable_preload+0x2344> */
	goto x86_l_2344;
x86_l_1f0e:
	/* 0x1f0e: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1f13:
	/* 0x1f13: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_1f16:
	/* 0x1f16: je     1fca <generic_sleepable_preload+0x1fca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fca;
	}
x86_l_1f1c:
	/* 0x1f1c: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f21:
	/* 0x1f21: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1f24:
	/* 0x1f24: je     1fca <generic_sleepable_preload+0x1fca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fca;
	}
x86_l_1f2a:
	/* 0x1f2a: jmp    1fdd <generic_sleepable_preload+0x1fdd> */
	goto x86_l_1fdd;
x86_l_1f2f:
	/* 0x1f2f: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1f34:
	/* 0x1f34: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_1f37:
	/* 0x1f37: je     2672 <generic_sleepable_preload+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9842ULL;
	}
x86_l_1f3d:
	/* 0x1f3d: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f42:
	/* 0x1f42: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1f45:
	/* 0x1f45: je     2672 <generic_sleepable_preload+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9842ULL;
	}
x86_l_1f4b:
	/* 0x1f4b: jmp    2685 <generic_sleepable_preload+0x2685> */
	return 9861ULL;
x86_l_1f50:
	/* 0x1f50: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1f55:
	/* 0x1f55: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_1f58:
	/* 0x1f58: je     2976 <generic_sleepable_preload+0x2976> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10614ULL;
	}
x86_l_1f5e:
	/* 0x1f5e: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f63:
	/* 0x1f63: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1f66:
	/* 0x1f66: je     2976 <generic_sleepable_preload+0x2976> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10614ULL;
	}
x86_l_1f6c:
	/* 0x1f6c: jmp    2989 <generic_sleepable_preload+0x2989> */
	return 10633ULL;
x86_l_1f71:
	/* 0x1f71: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1f76:
	/* 0x1f76: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_1f79:
	/* 0x1f79: je     2c7a <generic_sleepable_preload+0x2c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11386ULL;
	}
x86_l_1f7f:
	/* 0x1f7f: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f84:
	/* 0x1f84: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1f87:
	/* 0x1f87: je     2c7a <generic_sleepable_preload+0x2c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11386ULL;
	}
x86_l_1f8d:
	/* 0x1f8d: jmp    2c8d <generic_sleepable_preload+0x2c8d> */
	return 11405ULL;
x86_l_1f92:
	/* 0x1f92: mov    r14,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1f97:
	/* 0x1f97: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_1f9a:
	/* 0x1f9a: je     2331 <generic_sleepable_preload+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2331;
	}
x86_l_1fa0:
	/* 0x1fa0: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fa5:
	/* 0x1fa5: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1fa8:
	/* 0x1fa8: je     2331 <generic_sleepable_preload+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2331;
	}
x86_l_1fae:
	/* 0x1fae: jmp    2344 <generic_sleepable_preload+0x2344> */
	goto x86_l_2344;
x86_l_1fb3:
	/* 0x1fb3: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1fbb:
	/* 0x1fbb: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_1fbe:
	/* 0x1fbe: je     1fca <generic_sleepable_preload+0x1fca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fca;
	}
x86_l_1fc0:
	/* 0x1fc0: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1fc5:
	/* 0x1fc5: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1fc8:
	/* 0x1fc8: jne    1fdd <generic_sleepable_preload+0x1fdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fdd;
	}
x86_l_1fca:
	/* 0x1fca: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_1fcd:
	/* 0x1fcd: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_1fcf:
	/* 0x1fcf: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1fd1:
	/* 0x1fd1: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_1fd6:
	/* 0x1fd6: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1fd8:
	/* 0x1fd8: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_1fdd:
	/* 0x1fdd: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fe1:
	/* 0x1fe1: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1fe5:
	/* 0x1fe5: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fe8:
	/* 0x1fe8: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_1feb:
	/* 0x1feb: cmp    WORD PTR [rbx+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_1ff0:
	/* 0x1ff0: je     3408 <generic_sleepable_preload+0x3408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13320ULL;
	}
x86_l_1ff6:
	/* 0x1ff6: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1ff9:
	/* 0x1ff9: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ffc:
	/* 0x1ffc: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2000:
	/* 0x2000: cmp    WORD PTR [rbx+0x74],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_2005:
	/* 0x2005: je     2027 <generic_sleepable_preload+0x2027> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2027;
	}
x86_l_2007:
	/* 0x2007: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_200a:
	/* 0x200a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_200f:
	/* 0x200f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2014:
	/* 0x2014: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2018:
	/* 0x2018: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_201d:
	/* 0x201d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_201f:
	/* 0x201f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2021:
	/* 0x2021: js     22a3 <generic_sleepable_preload+0x22a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_22a3;
	}
x86_l_2027:
	/* 0x2027: cmp    WORD PTR [rbx+0x7e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_202c:
	/* 0x202c: je     3408 <generic_sleepable_preload+0x3408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13320ULL;
	}
x86_l_2032:
	/* 0x2032: mov    ecx,DWORD PTR [rbx+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2035:
	/* 0x2035: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2039:
	/* 0x2039: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_203d:
	/* 0x203d: cmp    WORD PTR [rbx+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_2042:
	/* 0x2042: je     2064 <generic_sleepable_preload+0x2064> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2064;
	}
x86_l_2044:
	/* 0x2044: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2047:
	/* 0x2047: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_204c:
	/* 0x204c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2051:
	/* 0x2051: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2055:
	/* 0x2055: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_205a:
	/* 0x205a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_205c:
	/* 0x205c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_205e:
	/* 0x205e: js     265a <generic_sleepable_preload+0x265a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9818ULL;
	}
x86_l_2064:
	/* 0x2064: cmp    WORD PTR [rbx+0x86],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_206c:
	/* 0x206c: je     3408 <generic_sleepable_preload+0x3408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13320ULL;
	}
x86_l_2072:
	/* 0x2072: mov    ecx,DWORD PTR [rbx+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2078:
	/* 0x2078: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_207c:
	/* 0x207c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2080:
	/* 0x2080: cmp    WORD PTR [rbx+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_2088:
	/* 0x2088: je     20aa <generic_sleepable_preload+0x20aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20aa;
	}
x86_l_208a:
	/* 0x208a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_208d:
	/* 0x208d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2092:
	/* 0x2092: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2097:
	/* 0x2097: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_209b:
	/* 0x209b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20a0:
	/* 0x20a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20a2:
	/* 0x20a2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20a4:
	/* 0x20a4: js     2fb1 <generic_sleepable_preload+0x2fb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12209ULL;
	}
x86_l_20aa:
	/* 0x20aa: cmp    WORD PTR [rbx+0x8e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_20b2:
	/* 0x20b2: je     3408 <generic_sleepable_preload+0x3408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13320ULL;
	}
x86_l_20b8:
	/* 0x20b8: mov    ecx,DWORD PTR [rbx+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_20be:
	/* 0x20be: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_20c2:
	/* 0x20c2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20c6:
	/* 0x20c6: cmp    WORD PTR [rbx+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_20ce:
	/* 0x20ce: je     20f0 <generic_sleepable_preload+0x20f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20f0;
	}
x86_l_20d0:
	/* 0x20d0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_20d3:
	/* 0x20d3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_20d8:
	/* 0x20d8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_20dd:
	/* 0x20dd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20e1:
	/* 0x20e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20e6:
	/* 0x20e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20e8:
	/* 0x20e8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20ea:
	/* 0x20ea: js     301d <generic_sleepable_preload+0x301d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12317ULL;
	}
x86_l_20f0:
	/* 0x20f0: cmp    WORD PTR [rbx+0x96],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_20f8:
	/* 0x20f8: je     3408 <generic_sleepable_preload+0x3408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13320ULL;
	}
x86_l_20fe:
	/* 0x20fe: mov    ecx,DWORD PTR [rbx+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2104:
	/* 0x2104: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2108:
	/* 0x2108: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_210c:
	/* 0x210c: cmp    WORD PTR [rbx+0x94],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_2114:
	/* 0x2114: je     2136 <generic_sleepable_preload+0x2136> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2136;
	}
x86_l_2116:
	/* 0x2116: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2119:
	/* 0x2119: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_211e:
	/* 0x211e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2123:
	/* 0x2123: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2127:
	/* 0x2127: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_212c:
	/* 0x212c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_212e:
	/* 0x212e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2130:
	/* 0x2130: js     3089 <generic_sleepable_preload+0x3089> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12425ULL;
	}
x86_l_2136:
	/* 0x2136: cmp    WORD PTR [rbx+0x9e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_213e:
	/* 0x213e: je     3408 <generic_sleepable_preload+0x3408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13320ULL;
	}
x86_l_2144:
	/* 0x2144: mov    ecx,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_214a:
	/* 0x214a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_214e:
	/* 0x214e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2152:
	/* 0x2152: cmp    WORD PTR [rbx+0x9c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_215a:
	/* 0x215a: je     217c <generic_sleepable_preload+0x217c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_217c;
	}
x86_l_215c:
	/* 0x215c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_215f:
	/* 0x215f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2164:
	/* 0x2164: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2169:
	/* 0x2169: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_216d:
	/* 0x216d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2172:
	/* 0x2172: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2174:
	/* 0x2174: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2176:
	/* 0x2176: js     30f2 <generic_sleepable_preload+0x30f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12530ULL;
	}
x86_l_217c:
	/* 0x217c: cmp    WORD PTR [rbx+0xa6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_2184:
	/* 0x2184: je     3408 <generic_sleepable_preload+0x3408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13320ULL;
	}
x86_l_218a:
	/* 0x218a: mov    ecx,DWORD PTR [rbx+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2190:
	/* 0x2190: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2194:
	/* 0x2194: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2198:
	/* 0x2198: cmp    WORD PTR [rbx+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_21a0:
	/* 0x21a0: je     21c2 <generic_sleepable_preload+0x21c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c2;
	}
x86_l_21a2:
	/* 0x21a2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_21a5:
	/* 0x21a5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_21aa:
	/* 0x21aa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_21af:
	/* 0x21af: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21b3:
	/* 0x21b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21b8:
	/* 0x21b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21ba:
	/* 0x21ba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21bc:
	/* 0x21bc: js     3400 <generic_sleepable_preload+0x3400> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13312ULL;
	}
x86_l_21c2:
	/* 0x21c2: cmp    WORD PTR [rbx+0xae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 747324309504ULL);
x86_l_21ca:
	/* 0x21ca: je     3408 <generic_sleepable_preload+0x3408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13320ULL;
	}
x86_l_21d0:
	/* 0x21d0: mov    ecx,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_21d6:
	/* 0x21d6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_21da:
	/* 0x21da: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21de:
	/* 0x21de: cmp    WORD PTR [rbx+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_21e6:
	/* 0x21e6: je     2208 <generic_sleepable_preload+0x2208> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2208;
	}
x86_l_21e8:
	/* 0x21e8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_21eb:
	/* 0x21eb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_21f0:
	/* 0x21f0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_21f5:
	/* 0x21f5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21f9:
	/* 0x21f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21fe:
	/* 0x21fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2200:
	/* 0x2200: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2202:
	/* 0x2202: js     37ea <generic_sleepable_preload+0x37ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14314ULL;
	}
x86_l_2208:
	/* 0x2208: cmp    WORD PTR [rbx+0xb6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047872ULL);
x86_l_2210:
	/* 0x2210: je     3408 <generic_sleepable_preload+0x3408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13320ULL;
	}
x86_l_2216:
	/* 0x2216: mov    ecx,DWORD PTR [rbx+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_221c:
	/* 0x221c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2220:
	/* 0x2220: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2224:
	/* 0x2224: cmp    WORD PTR [rbx+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_222c:
	/* 0x222c: je     224e <generic_sleepable_preload+0x224e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_224e;
	}
x86_l_222e:
	/* 0x222e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2231:
	/* 0x2231: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2236:
	/* 0x2236: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_223b:
	/* 0x223b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_223f:
	/* 0x223f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2244:
	/* 0x2244: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2246:
	/* 0x2246: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2248:
	/* 0x2248: js     3893 <generic_sleepable_preload+0x3893> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14483ULL;
	}
x86_l_224e:
	/* 0x224e: cmp    WORD PTR [rbx+0xbe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_2256:
	/* 0x2256: je     3408 <generic_sleepable_preload+0x3408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13320ULL;
	}
x86_l_225c:
	/* 0x225c: mov    ecx,DWORD PTR [rbx+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2262:
	/* 0x2262: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2266:
	/* 0x2266: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_226a:
	/* 0x226a: cmp    WORD PTR [rbx+0xbc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_2272:
	/* 0x2272: je     3408 <generic_sleepable_preload+0x3408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13320ULL;
	}
x86_l_2278:
	/* 0x2278: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_227b:
	/* 0x227b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2280:
	/* 0x2280: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2285:
	/* 0x2285: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2289:
	/* 0x2289: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_228e:
	/* 0x228e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2290:
	/* 0x2290: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2292:
	/* 0x2292: jns    3408 <generic_sleepable_preload+0x3408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 13320ULL;
	}
x86_l_2298:
	/* 0x2298: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_229e:
	/* 0x229e: jmp    3406 <generic_sleepable_preload+0x3406> */
	return 13318ULL;
x86_l_22a3:
	/* 0x22a3: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_22a9:
	/* 0x22a9: jmp    3406 <generic_sleepable_preload+0x3406> */
	return 13318ULL;
x86_l_22ae:
	/* 0x22ae: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_22b6:
	/* 0x22b6: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_22b9:
	/* 0x22b9: je     2672 <generic_sleepable_preload+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9842ULL;
	}
x86_l_22bf:
	/* 0x22bf: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_22c4:
	/* 0x22c4: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_22c7:
	/* 0x22c7: je     2672 <generic_sleepable_preload+0x2672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9842ULL;
	}
x86_l_22cd:
	/* 0x22cd: jmp    2685 <generic_sleepable_preload+0x2685> */
	return 9861ULL;
x86_l_22d2:
	/* 0x22d2: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_22da:
	/* 0x22da: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_22dd:
	/* 0x22dd: je     2976 <generic_sleepable_preload+0x2976> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10614ULL;
	}
x86_l_22e3:
	/* 0x22e3: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_22e8:
	/* 0x22e8: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_22eb:
	/* 0x22eb: je     2976 <generic_sleepable_preload+0x2976> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10614ULL;
	}
x86_l_22f1:
	/* 0x22f1: jmp    2989 <generic_sleepable_preload+0x2989> */
	return 10633ULL;
x86_l_22f6:
	/* 0x22f6: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_22fe:
	/* 0x22fe: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_2301:
	/* 0x2301: je     2c7a <generic_sleepable_preload+0x2c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11386ULL;
	}
x86_l_2307:
	/* 0x2307: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_230c:
	/* 0x230c: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_230f:
	/* 0x230f: je     2c7a <generic_sleepable_preload+0x2c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11386ULL;
	}
x86_l_2315:
	/* 0x2315: jmp    2c8d <generic_sleepable_preload+0x2c8d> */
	return 11405ULL;
x86_l_231a:
	/* 0x231a: mov    r14,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2322:
	/* 0x2322: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_2325:
	/* 0x2325: je     2331 <generic_sleepable_preload+0x2331> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2331;
	}
x86_l_2327:
	/* 0x2327: mov    r14,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_232c:
	/* 0x232c: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_232f:
	/* 0x232f: jne    2344 <generic_sleepable_preload+0x2344> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2344;
	}
x86_l_2331:
	/* 0x2331: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_2334:
	/* 0x2334: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_2336:
	/* 0x2336: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2338:
	/* 0x2338: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_233d:
	/* 0x233d: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_233f:
	/* 0x233f: bzhi   rcx,QWORD PTR [r14],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_2344:
	/* 0x2344: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2348:
	/* 0x2348: mov    r14d,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_234c:
	/* 0x234c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_234e:
	/* 0x234e: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_2351:
	/* 0x2351: cmp    WORD PTR [rbx+0x1b6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1881195675648ULL);
x86_l_2359:
	/* 0x2359: je     34c4 <generic_sleepable_preload+0x34c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13508ULL;
	}
x86_l_235f:
	/* 0x235f: mov    eax,DWORD PTR [rbx+0x1b0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 432ULL);
x86_l_2365:
	/* 0x2365: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2368:
	/* 0x2368: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_236c:
	/* 0x236c: cmp    WORD PTR [rbx+0x1b4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1872605741056ULL);
x86_l_2374:
	/* 0x2374: je     2396 <generic_sleepable_preload+0x2396> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2396;
	}
x86_l_2376:
	/* 0x2376: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2379:
	/* 0x2379: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_237e:
	/* 0x237e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2383:
	/* 0x2383: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2387:
	/* 0x2387: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_238c:
	/* 0x238c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_238e:
	/* 0x238e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2390:
	/* 0x2390: js     261a <generic_sleepable_preload+0x261a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9754ULL;
	}
x86_l_2396:
	/* 0x2396: cmp    WORD PTR [rbx+0x1be],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1915555414016ULL);
x86_l_239e:
	/* 0x239e: je     34c4 <generic_sleepable_preload+0x34c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13508ULL;
	}
x86_l_23a4:
	/* 0x23a4: mov    ecx,DWORD PTR [rbx+0x1b8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 440ULL);
x86_l_23aa:
	/* 0x23aa: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_23ae:
	/* 0x23ae: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23b2:
	/* 0x23b2: cmp    WORD PTR [rbx+0x1bc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1906965479424ULL);
x86_l_23ba:
	/* 0x23ba: je     23dc <generic_sleepable_preload+0x23dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23dc;
	}
x86_l_23bc:
	/* 0x23bc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_23bf:
	/* 0x23bf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_23c4:
	/* 0x23c4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_23c9:
	/* 0x23c9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23cd:
	/* 0x23cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23d2:
	/* 0x23d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23d4:
	/* 0x23d4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23d6:
	/* 0x23d6: js     2665 <generic_sleepable_preload+0x2665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9829ULL;
	}
x86_l_23dc:
	/* 0x23dc: cmp    WORD PTR [rbx+0x1c6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1949915152384ULL);
	return 9188ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9188ULL: goto x86_l_23e4;
	case 9194ULL: goto x86_l_23ea;
	case 9200ULL: goto x86_l_23f0;
	case 9204ULL: goto x86_l_23f4;
	case 9208ULL: goto x86_l_23f8;
	case 9216ULL: goto x86_l_2400;
	case 9218ULL: goto x86_l_2402;
	case 9221ULL: goto x86_l_2405;
	case 9226ULL: goto x86_l_240a;
	case 9231ULL: goto x86_l_240f;
	case 9235ULL: goto x86_l_2413;
	case 9240ULL: goto x86_l_2418;
	case 9242ULL: goto x86_l_241a;
	case 9244ULL: goto x86_l_241c;
	case 9250ULL: goto x86_l_2422;
	case 9258ULL: goto x86_l_242a;
	case 9264ULL: goto x86_l_2430;
	case 9270ULL: goto x86_l_2436;
	case 9274ULL: goto x86_l_243a;
	case 9278ULL: goto x86_l_243e;
	case 9286ULL: goto x86_l_2446;
	case 9288ULL: goto x86_l_2448;
	case 9291ULL: goto x86_l_244b;
	case 9296ULL: goto x86_l_2450;
	case 9301ULL: goto x86_l_2455;
	case 9305ULL: goto x86_l_2459;
	case 9310ULL: goto x86_l_245e;
	case 9312ULL: goto x86_l_2460;
	case 9314ULL: goto x86_l_2462;
	case 9320ULL: goto x86_l_2468;
	case 9328ULL: goto x86_l_2470;
	case 9334ULL: goto x86_l_2476;
	case 9340ULL: goto x86_l_247c;
	case 9344ULL: goto x86_l_2480;
	case 9348ULL: goto x86_l_2484;
	case 9356ULL: goto x86_l_248c;
	case 9358ULL: goto x86_l_248e;
	case 9361ULL: goto x86_l_2491;
	case 9366ULL: goto x86_l_2496;
	case 9371ULL: goto x86_l_249b;
	case 9375ULL: goto x86_l_249f;
	case 9380ULL: goto x86_l_24a4;
	case 9382ULL: goto x86_l_24a6;
	case 9384ULL: goto x86_l_24a8;
	case 9390ULL: goto x86_l_24ae;
	case 9398ULL: goto x86_l_24b6;
	case 9404ULL: goto x86_l_24bc;
	case 9410ULL: goto x86_l_24c2;
	case 9414ULL: goto x86_l_24c6;
	case 9418ULL: goto x86_l_24ca;
	case 9426ULL: goto x86_l_24d2;
	case 9428ULL: goto x86_l_24d4;
	case 9431ULL: goto x86_l_24d7;
	case 9436ULL: goto x86_l_24dc;
	case 9441ULL: goto x86_l_24e1;
	case 9445ULL: goto x86_l_24e5;
	case 9450ULL: goto x86_l_24ea;
	case 9452ULL: goto x86_l_24ec;
	case 9454ULL: goto x86_l_24ee;
	case 9460ULL: goto x86_l_24f4;
	case 9468ULL: goto x86_l_24fc;
	case 9474ULL: goto x86_l_2502;
	case 9480ULL: goto x86_l_2508;
	case 9484ULL: goto x86_l_250c;
	case 9488ULL: goto x86_l_2510;
	case 9496ULL: goto x86_l_2518;
	case 9498ULL: goto x86_l_251a;
	case 9501ULL: goto x86_l_251d;
	case 9506ULL: goto x86_l_2522;
	case 9511ULL: goto x86_l_2527;
	case 9515ULL: goto x86_l_252b;
	case 9520ULL: goto x86_l_2530;
	case 9522ULL: goto x86_l_2532;
	case 9524ULL: goto x86_l_2534;
	case 9530ULL: goto x86_l_253a;
	case 9538ULL: goto x86_l_2542;
	case 9544ULL: goto x86_l_2548;
	case 9550ULL: goto x86_l_254e;
	case 9554ULL: goto x86_l_2552;
	case 9558ULL: goto x86_l_2556;
	case 9566ULL: goto x86_l_255e;
	case 9568ULL: goto x86_l_2560;
	case 9571ULL: goto x86_l_2563;
	case 9576ULL: goto x86_l_2568;
	case 9581ULL: goto x86_l_256d;
	case 9585ULL: goto x86_l_2571;
	case 9590ULL: goto x86_l_2576;
	case 9592ULL: goto x86_l_2578;
	case 9594ULL: goto x86_l_257a;
	case 9600ULL: goto x86_l_2580;
	case 9608ULL: goto x86_l_2588;
	case 9614ULL: goto x86_l_258e;
	case 9620ULL: goto x86_l_2594;
	case 9624ULL: goto x86_l_2598;
	case 9628ULL: goto x86_l_259c;
	case 9636ULL: goto x86_l_25a4;
	case 9638ULL: goto x86_l_25a6;
	case 9641ULL: goto x86_l_25a9;
	case 9646ULL: goto x86_l_25ae;
	case 9651ULL: goto x86_l_25b3;
	case 9655ULL: goto x86_l_25b7;
	case 9660ULL: goto x86_l_25bc;
	case 9662ULL: goto x86_l_25be;
	case 9664ULL: goto x86_l_25c0;
	case 9670ULL: goto x86_l_25c6;
	case 9678ULL: goto x86_l_25ce;
	case 9684ULL: goto x86_l_25d4;
	case 9690ULL: goto x86_l_25da;
	case 9694ULL: goto x86_l_25de;
	case 9698ULL: goto x86_l_25e2;
	case 9706ULL: goto x86_l_25ea;
	case 9712ULL: goto x86_l_25f0;
	case 9715ULL: goto x86_l_25f3;
	case 9720ULL: goto x86_l_25f8;
	case 9725ULL: goto x86_l_25fd;
	case 9729ULL: goto x86_l_2601;
	case 9734ULL: goto x86_l_2606;
	case 9736ULL: goto x86_l_2608;
	case 9738ULL: goto x86_l_260a;
	case 9744ULL: goto x86_l_2610;
	case 9749ULL: goto x86_l_2615;
	case 9754ULL: goto x86_l_261a;
	case 9759ULL: goto x86_l_261f;
	case 9764ULL: goto x86_l_2624;
	case 9770ULL: goto x86_l_262a;
	case 9775ULL: goto x86_l_262f;
	case 9781ULL: goto x86_l_2635;
	case 9786ULL: goto x86_l_263a;
	case 9792ULL: goto x86_l_2640;
	case 9797ULL: goto x86_l_2645;
	case 9803ULL: goto x86_l_264b;
	case 9808ULL: goto x86_l_2650;
	case 9813ULL: goto x86_l_2655;
	case 9818ULL: goto x86_l_265a;
	case 9824ULL: goto x86_l_2660;
	case 9829ULL: goto x86_l_2665;
	case 9834ULL: goto x86_l_266a;
	case 9839ULL: goto x86_l_266f;
	case 9842ULL: goto x86_l_2672;
	case 9845ULL: goto x86_l_2675;
	case 9847ULL: goto x86_l_2677;
	case 9849ULL: goto x86_l_2679;
	case 9854ULL: goto x86_l_267e;
	case 9856ULL: goto x86_l_2680;
	case 9861ULL: goto x86_l_2685;
	case 9865ULL: goto x86_l_2689;
	case 9869ULL: goto x86_l_268d;
	case 9872ULL: goto x86_l_2690;
	case 9875ULL: goto x86_l_2693;
	case 9883ULL: goto x86_l_269b;
	case 9889ULL: goto x86_l_26a1;
	case 9895ULL: goto x86_l_26a7;
	case 9898ULL: goto x86_l_26aa;
	case 9902ULL: goto x86_l_26ae;
	case 9910ULL: goto x86_l_26b6;
	case 9912ULL: goto x86_l_26b8;
	case 9915ULL: goto x86_l_26bb;
	case 9920ULL: goto x86_l_26c0;
	case 9925ULL: goto x86_l_26c5;
	case 9929ULL: goto x86_l_26c9;
	case 9934ULL: goto x86_l_26ce;
	case 9936ULL: goto x86_l_26d0;
	case 9938ULL: goto x86_l_26d2;
	case 9944ULL: goto x86_l_26d8;
	case 9952ULL: goto x86_l_26e0;
	case 9958ULL: goto x86_l_26e6;
	case 9964ULL: goto x86_l_26ec;
	case 9968ULL: goto x86_l_26f0;
	case 9972ULL: goto x86_l_26f4;
	case 9980ULL: goto x86_l_26fc;
	case 9982ULL: goto x86_l_26fe;
	case 9985ULL: goto x86_l_2701;
	case 9990ULL: goto x86_l_2706;
	case 9995ULL: goto x86_l_270b;
	case 9999ULL: goto x86_l_270f;
	case 10004ULL: goto x86_l_2714;
	case 10006ULL: goto x86_l_2716;
	case 10008ULL: goto x86_l_2718;
	case 10014ULL: goto x86_l_271e;
	case 10022ULL: goto x86_l_2726;
	case 10028ULL: goto x86_l_272c;
	case 10034ULL: goto x86_l_2732;
	case 10038ULL: goto x86_l_2736;
	case 10042ULL: goto x86_l_273a;
	case 10050ULL: goto x86_l_2742;
	case 10052ULL: goto x86_l_2744;
	case 10055ULL: goto x86_l_2747;
	case 10060ULL: goto x86_l_274c;
	case 10065ULL: goto x86_l_2751;
	case 10069ULL: goto x86_l_2755;
	case 10074ULL: goto x86_l_275a;
	case 10076ULL: goto x86_l_275c;
	case 10078ULL: goto x86_l_275e;
	case 10084ULL: goto x86_l_2764;
	case 10092ULL: goto x86_l_276c;
	case 10098ULL: goto x86_l_2772;
	case 10104ULL: goto x86_l_2778;
	case 10108ULL: goto x86_l_277c;
	case 10112ULL: goto x86_l_2780;
	case 10120ULL: goto x86_l_2788;
	case 10122ULL: goto x86_l_278a;
	case 10125ULL: goto x86_l_278d;
	case 10130ULL: goto x86_l_2792;
	case 10135ULL: goto x86_l_2797;
	case 10139ULL: goto x86_l_279b;
	case 10144ULL: goto x86_l_27a0;
	case 10146ULL: goto x86_l_27a2;
	case 10148ULL: goto x86_l_27a4;
	case 10154ULL: goto x86_l_27aa;
	case 10162ULL: goto x86_l_27b2;
	case 10168ULL: goto x86_l_27b8;
	case 10174ULL: goto x86_l_27be;
	case 10178ULL: goto x86_l_27c2;
	case 10182ULL: goto x86_l_27c6;
	case 10190ULL: goto x86_l_27ce;
	case 10192ULL: goto x86_l_27d0;
	case 10195ULL: goto x86_l_27d3;
	case 10200ULL: goto x86_l_27d8;
	case 10205ULL: goto x86_l_27dd;
	case 10209ULL: goto x86_l_27e1;
	case 10214ULL: goto x86_l_27e6;
	case 10216ULL: goto x86_l_27e8;
	case 10218ULL: goto x86_l_27ea;
	case 10224ULL: goto x86_l_27f0;
	case 10232ULL: goto x86_l_27f8;
	case 10238ULL: goto x86_l_27fe;
	case 10244ULL: goto x86_l_2804;
	case 10248ULL: goto x86_l_2808;
	case 10252ULL: goto x86_l_280c;
	case 10260ULL: goto x86_l_2814;
	case 10262ULL: goto x86_l_2816;
	case 10265ULL: goto x86_l_2819;
	case 10270ULL: goto x86_l_281e;
	case 10275ULL: goto x86_l_2823;
	case 10279ULL: goto x86_l_2827;
	case 10284ULL: goto x86_l_282c;
	case 10286ULL: goto x86_l_282e;
	case 10288ULL: goto x86_l_2830;
	case 10294ULL: goto x86_l_2836;
	case 10302ULL: goto x86_l_283e;
	case 10308ULL: goto x86_l_2844;
	case 10314ULL: goto x86_l_284a;
	case 10318ULL: goto x86_l_284e;
	case 10322ULL: goto x86_l_2852;
	case 10330ULL: goto x86_l_285a;
	case 10332ULL: goto x86_l_285c;
	case 10335ULL: goto x86_l_285f;
	case 10340ULL: goto x86_l_2864;
	case 10345ULL: goto x86_l_2869;
	case 10349ULL: goto x86_l_286d;
	case 10354ULL: goto x86_l_2872;
	case 10356ULL: goto x86_l_2874;
	case 10358ULL: goto x86_l_2876;
	case 10364ULL: goto x86_l_287c;
	case 10372ULL: goto x86_l_2884;
	case 10378ULL: goto x86_l_288a;
	case 10384ULL: goto x86_l_2890;
	case 10388ULL: goto x86_l_2894;
	case 10392ULL: goto x86_l_2898;
	case 10400ULL: goto x86_l_28a0;
	case 10402ULL: goto x86_l_28a2;
	case 10405ULL: goto x86_l_28a5;
	case 10410ULL: goto x86_l_28aa;
	case 10415ULL: goto x86_l_28af;
	case 10419ULL: goto x86_l_28b3;
	case 10424ULL: goto x86_l_28b8;
	case 10426ULL: goto x86_l_28ba;
	case 10428ULL: goto x86_l_28bc;
	case 10434ULL: goto x86_l_28c2;
	case 10442ULL: goto x86_l_28ca;
	case 10448ULL: goto x86_l_28d0;
	case 10454ULL: goto x86_l_28d6;
	case 10458ULL: goto x86_l_28da;
	case 10462ULL: goto x86_l_28de;
	case 10470ULL: goto x86_l_28e6;
	case 10472ULL: goto x86_l_28e8;
	case 10475ULL: goto x86_l_28eb;
	case 10480ULL: goto x86_l_28f0;
	case 10485ULL: goto x86_l_28f5;
	case 10489ULL: goto x86_l_28f9;
	case 10494ULL: goto x86_l_28fe;
	case 10496ULL: goto x86_l_2900;
	case 10498ULL: goto x86_l_2902;
	case 10504ULL: goto x86_l_2908;
	case 10512ULL: goto x86_l_2910;
	case 10518ULL: goto x86_l_2916;
	case 10524ULL: goto x86_l_291c;
	case 10528ULL: goto x86_l_2920;
	case 10532ULL: goto x86_l_2924;
	case 10540ULL: goto x86_l_292c;
	case 10546ULL: goto x86_l_2932;
	case 10549ULL: goto x86_l_2935;
	case 10554ULL: goto x86_l_293a;
	case 10559ULL: goto x86_l_293f;
	case 10563ULL: goto x86_l_2943;
	case 10568ULL: goto x86_l_2948;
	case 10570ULL: goto x86_l_294a;
	case 10572ULL: goto x86_l_294c;
	case 10578ULL: goto x86_l_2952;
	case 10584ULL: goto x86_l_2958;
	case 10589ULL: goto x86_l_295d;
	case 10595ULL: goto x86_l_2963;
	case 10600ULL: goto x86_l_2968;
	case 10606ULL: goto x86_l_296e;
	case 10611ULL: goto x86_l_2973;
	case 10614ULL: goto x86_l_2976;
	case 10617ULL: goto x86_l_2979;
	case 10619ULL: goto x86_l_297b;
	case 10621ULL: goto x86_l_297d;
	case 10626ULL: goto x86_l_2982;
	case 10628ULL: goto x86_l_2984;
	case 10633ULL: goto x86_l_2989;
	case 10637ULL: goto x86_l_298d;
	case 10641ULL: goto x86_l_2991;
	case 10644ULL: goto x86_l_2994;
	case 10647ULL: goto x86_l_2997;
	case 10655ULL: goto x86_l_299f;
	case 10661ULL: goto x86_l_29a5;
	case 10667ULL: goto x86_l_29ab;
	case 10670ULL: goto x86_l_29ae;
	case 10674ULL: goto x86_l_29b2;
	case 10682ULL: goto x86_l_29ba;
	case 10684ULL: goto x86_l_29bc;
	case 10687ULL: goto x86_l_29bf;
	case 10692ULL: goto x86_l_29c4;
	case 10697ULL: goto x86_l_29c9;
	case 10701ULL: goto x86_l_29cd;
	case 10706ULL: goto x86_l_29d2;
	case 10708ULL: goto x86_l_29d4;
	case 10710ULL: goto x86_l_29d6;
	case 10716ULL: goto x86_l_29dc;
	case 10724ULL: goto x86_l_29e4;
	case 10730ULL: goto x86_l_29ea;
	case 10736ULL: goto x86_l_29f0;
	case 10740ULL: goto x86_l_29f4;
	case 10744ULL: goto x86_l_29f8;
	case 10752ULL: goto x86_l_2a00;
	case 10754ULL: goto x86_l_2a02;
	case 10757ULL: goto x86_l_2a05;
	case 10762ULL: goto x86_l_2a0a;
	case 10767ULL: goto x86_l_2a0f;
	case 10771ULL: goto x86_l_2a13;
	case 10776ULL: goto x86_l_2a18;
	case 10778ULL: goto x86_l_2a1a;
	case 10780ULL: goto x86_l_2a1c;
	case 10786ULL: goto x86_l_2a22;
	case 10794ULL: goto x86_l_2a2a;
	case 10800ULL: goto x86_l_2a30;
	case 10806ULL: goto x86_l_2a36;
	case 10810ULL: goto x86_l_2a3a;
	case 10814ULL: goto x86_l_2a3e;
	case 10822ULL: goto x86_l_2a46;
	case 10824ULL: goto x86_l_2a48;
	case 10827ULL: goto x86_l_2a4b;
	case 10832ULL: goto x86_l_2a50;
	case 10837ULL: goto x86_l_2a55;
	case 10841ULL: goto x86_l_2a59;
	case 10846ULL: goto x86_l_2a5e;
	case 10848ULL: goto x86_l_2a60;
	case 10850ULL: goto x86_l_2a62;
	case 10856ULL: goto x86_l_2a68;
	case 10864ULL: goto x86_l_2a70;
	case 10870ULL: goto x86_l_2a76;
	case 10876ULL: goto x86_l_2a7c;
	case 10880ULL: goto x86_l_2a80;
	case 10884ULL: goto x86_l_2a84;
	case 10892ULL: goto x86_l_2a8c;
	case 10894ULL: goto x86_l_2a8e;
	case 10897ULL: goto x86_l_2a91;
	case 10902ULL: goto x86_l_2a96;
	case 10907ULL: goto x86_l_2a9b;
	case 10911ULL: goto x86_l_2a9f;
	case 10916ULL: goto x86_l_2aa4;
	case 10918ULL: goto x86_l_2aa6;
	case 10920ULL: goto x86_l_2aa8;
	case 10926ULL: goto x86_l_2aae;
	case 10934ULL: goto x86_l_2ab6;
	case 10940ULL: goto x86_l_2abc;
	case 10946ULL: goto x86_l_2ac2;
	case 10950ULL: goto x86_l_2ac6;
	case 10954ULL: goto x86_l_2aca;
	case 10962ULL: goto x86_l_2ad2;
	case 10964ULL: goto x86_l_2ad4;
	case 10967ULL: goto x86_l_2ad7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_23e4:
	/* 0x23e4: je     34c4 <generic_sleepable_preload+0x34c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13508ULL;
	}
x86_l_23ea:
	/* 0x23ea: mov    ecx,DWORD PTR [rbx+0x1c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 448ULL);
x86_l_23f0:
	/* 0x23f0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_23f4:
	/* 0x23f4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23f8:
	/* 0x23f8: cmp    WORD PTR [rbx+0x1c4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1941325217792ULL);
x86_l_2400:
	/* 0x2400: je     2422 <generic_sleepable_preload+0x2422> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2422;
	}
x86_l_2402:
	/* 0x2402: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2405:
	/* 0x2405: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_240a:
	/* 0x240a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_240f:
	/* 0x240f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2413:
	/* 0x2413: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2418:
	/* 0x2418: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_241a:
	/* 0x241a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_241c:
	/* 0x241c: js     2fbc <generic_sleepable_preload+0x2fbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12220ULL;
	}
x86_l_2422:
	/* 0x2422: cmp    WORD PTR [rbx+0x1ce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1984274890752ULL);
x86_l_242a:
	/* 0x242a: je     34c4 <generic_sleepable_preload+0x34c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13508ULL;
	}
x86_l_2430:
	/* 0x2430: mov    ecx,DWORD PTR [rbx+0x1c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 456ULL);
x86_l_2436:
	/* 0x2436: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_243a:
	/* 0x243a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_243e:
	/* 0x243e: cmp    WORD PTR [rbx+0x1cc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1975684956160ULL);
x86_l_2446:
	/* 0x2446: je     2468 <generic_sleepable_preload+0x2468> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2468;
	}
x86_l_2448:
	/* 0x2448: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_244b:
	/* 0x244b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2450:
	/* 0x2450: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2455:
	/* 0x2455: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2459:
	/* 0x2459: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_245e:
	/* 0x245e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2460:
	/* 0x2460: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2462:
	/* 0x2462: js     3028 <generic_sleepable_preload+0x3028> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12328ULL;
	}
x86_l_2468:
	/* 0x2468: cmp    WORD PTR [rbx+0x1d6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2018634629120ULL);
x86_l_2470:
	/* 0x2470: je     34c4 <generic_sleepable_preload+0x34c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13508ULL;
	}
x86_l_2476:
	/* 0x2476: mov    ecx,DWORD PTR [rbx+0x1d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 464ULL);
x86_l_247c:
	/* 0x247c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2480:
	/* 0x2480: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2484:
	/* 0x2484: cmp    WORD PTR [rbx+0x1d4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2010044694528ULL);
x86_l_248c:
	/* 0x248c: je     24ae <generic_sleepable_preload+0x24ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24ae;
	}
x86_l_248e:
	/* 0x248e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2491:
	/* 0x2491: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2496:
	/* 0x2496: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_249b:
	/* 0x249b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_249f:
	/* 0x249f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24a4:
	/* 0x24a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24a6:
	/* 0x24a6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24a8:
	/* 0x24a8: js     3094 <generic_sleepable_preload+0x3094> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12436ULL;
	}
x86_l_24ae:
	/* 0x24ae: cmp    WORD PTR [rbx+0x1de],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2052994367488ULL);
x86_l_24b6:
	/* 0x24b6: je     34c4 <generic_sleepable_preload+0x34c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13508ULL;
	}
x86_l_24bc:
	/* 0x24bc: mov    ecx,DWORD PTR [rbx+0x1d8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 472ULL);
x86_l_24c2:
	/* 0x24c2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_24c6:
	/* 0x24c6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24ca:
	/* 0x24ca: cmp    WORD PTR [rbx+0x1dc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2044404432896ULL);
x86_l_24d2:
	/* 0x24d2: je     24f4 <generic_sleepable_preload+0x24f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24f4;
	}
x86_l_24d4:
	/* 0x24d4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_24d7:
	/* 0x24d7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_24dc:
	/* 0x24dc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_24e1:
	/* 0x24e1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24e5:
	/* 0x24e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24ea:
	/* 0x24ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24ec:
	/* 0x24ec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24ee:
	/* 0x24ee: js     30fd <generic_sleepable_preload+0x30fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12541ULL;
	}
x86_l_24f4:
	/* 0x24f4: cmp    WORD PTR [rbx+0x1e6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2087354105856ULL);
x86_l_24fc:
	/* 0x24fc: je     34c4 <generic_sleepable_preload+0x34c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13508ULL;
	}
x86_l_2502:
	/* 0x2502: mov    ecx,DWORD PTR [rbx+0x1e0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 480ULL);
x86_l_2508:
	/* 0x2508: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_250c:
	/* 0x250c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2510:
	/* 0x2510: cmp    WORD PTR [rbx+0x1e4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2078764171264ULL);
x86_l_2518:
	/* 0x2518: je     253a <generic_sleepable_preload+0x253a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_253a;
	}
x86_l_251a:
	/* 0x251a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_251d:
	/* 0x251d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2522:
	/* 0x2522: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2527:
	/* 0x2527: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_252b:
	/* 0x252b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2530:
	/* 0x2530: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2532:
	/* 0x2532: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2534:
	/* 0x2534: js     34bc <generic_sleepable_preload+0x34bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13500ULL;
	}
x86_l_253a:
	/* 0x253a: cmp    WORD PTR [rbx+0x1ee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2121713844224ULL);
x86_l_2542:
	/* 0x2542: je     34c4 <generic_sleepable_preload+0x34c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13508ULL;
	}
x86_l_2548:
	/* 0x2548: mov    ecx,DWORD PTR [rbx+0x1e8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 488ULL);
x86_l_254e:
	/* 0x254e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2552:
	/* 0x2552: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2556:
	/* 0x2556: cmp    WORD PTR [rbx+0x1ec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2113123909632ULL);
x86_l_255e:
	/* 0x255e: je     2580 <generic_sleepable_preload+0x2580> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2580;
	}
x86_l_2560:
	/* 0x2560: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2563:
	/* 0x2563: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2568:
	/* 0x2568: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_256d:
	/* 0x256d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2571:
	/* 0x2571: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2576:
	/* 0x2576: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2578:
	/* 0x2578: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_257a:
	/* 0x257a: js     3801 <generic_sleepable_preload+0x3801> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14337ULL;
	}
x86_l_2580:
	/* 0x2580: cmp    WORD PTR [rbx+0x1f6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2156073582592ULL);
x86_l_2588:
	/* 0x2588: je     34c4 <generic_sleepable_preload+0x34c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13508ULL;
	}
x86_l_258e:
	/* 0x258e: mov    ecx,DWORD PTR [rbx+0x1f0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 496ULL);
x86_l_2594:
	/* 0x2594: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2598:
	/* 0x2598: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_259c:
	/* 0x259c: cmp    WORD PTR [rbx+0x1f4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2147483648000ULL);
x86_l_25a4:
	/* 0x25a4: je     25c6 <generic_sleepable_preload+0x25c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25c6;
	}
x86_l_25a6:
	/* 0x25a6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_25a9:
	/* 0x25a9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_25ae:
	/* 0x25ae: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_25b3:
	/* 0x25b3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25b7:
	/* 0x25b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25bc:
	/* 0x25bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25be:
	/* 0x25be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25c0:
	/* 0x25c0: js     389e <generic_sleepable_preload+0x389e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14494ULL;
	}
x86_l_25c6:
	/* 0x25c6: cmp    WORD PTR [rbx+0x1fe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2190433320960ULL);
x86_l_25ce:
	/* 0x25ce: je     34c4 <generic_sleepable_preload+0x34c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13508ULL;
	}
x86_l_25d4:
	/* 0x25d4: mov    ecx,DWORD PTR [rbx+0x1f8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 504ULL);
x86_l_25da:
	/* 0x25da: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_25de:
	/* 0x25de: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25e2:
	/* 0x25e2: cmp    WORD PTR [rbx+0x1fc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2181843386368ULL);
x86_l_25ea:
	/* 0x25ea: je     34c4 <generic_sleepable_preload+0x34c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13508ULL;
	}
x86_l_25f0:
	/* 0x25f0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_25f3:
	/* 0x25f3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_25f8:
	/* 0x25f8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_25fd:
	/* 0x25fd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2601:
	/* 0x2601: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2606:
	/* 0x2606: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2608:
	/* 0x2608: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_260a:
	/* 0x260a: jns    34c4 <generic_sleepable_preload+0x34c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 13508ULL;
	}
x86_l_2610:
	/* 0x2610: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_2615:
	/* 0x2615: jmp    34c1 <generic_sleepable_preload+0x34c1> */
	return 13505ULL;
x86_l_261a:
	/* 0x261a: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_261f:
	/* 0x261f: jmp    34c1 <generic_sleepable_preload+0x34c1> */
	return 13505ULL;
x86_l_2624:
	/* 0x2624: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_262a:
	/* 0x262a: jmp    312e <generic_sleepable_preload+0x312e> */
	return 12590ULL;
x86_l_262f:
	/* 0x262f: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_2635:
	/* 0x2635: jmp    31c4 <generic_sleepable_preload+0x31c4> */
	return 12740ULL;
x86_l_263a:
	/* 0x263a: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_2640:
	/* 0x2640: jmp    3257 <generic_sleepable_preload+0x3257> */
	return 12887ULL;
x86_l_2645:
	/* 0x2645: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_264b:
	/* 0x264b: jmp    32ea <generic_sleepable_preload+0x32ea> */
	return 13034ULL;
x86_l_2650:
	/* 0x2650: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_2655:
	/* 0x2655: jmp    337c <generic_sleepable_preload+0x337c> */
	return 13180ULL;
x86_l_265a:
	/* 0x265a: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_2660:
	/* 0x2660: jmp    3406 <generic_sleepable_preload+0x3406> */
	return 13318ULL;
x86_l_2665:
	/* 0x2665: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_266a:
	/* 0x266a: jmp    34c1 <generic_sleepable_preload+0x34c1> */
	return 13505ULL;
x86_l_266f:
	/* 0x266f: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2672:
	/* 0x2672: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_2675:
	/* 0x2675: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_2677:
	/* 0x2677: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2679:
	/* 0x2679: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_267e:
	/* 0x267e: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2680:
	/* 0x2680: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_2685:
	/* 0x2685: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2689:
	/* 0x2689: mov    r15d,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_268d:
	/* 0x268d: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2690:
	/* 0x2690: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_2693:
	/* 0x2693: cmp    WORD PTR [rbx+0xc6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_269b:
	/* 0x269b: je     3574 <generic_sleepable_preload+0x3574> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13684ULL;
	}
x86_l_26a1:
	/* 0x26a1: mov    eax,DWORD PTR [rbx+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_26a7:
	/* 0x26a7: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26aa:
	/* 0x26aa: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26ae:
	/* 0x26ae: cmp    WORD PTR [rbx+0xc4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_26b6:
	/* 0x26b6: je     26d8 <generic_sleepable_preload+0x26d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d8;
	}
x86_l_26b8:
	/* 0x26b8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_26bb:
	/* 0x26bb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_26c0:
	/* 0x26c0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_26c5:
	/* 0x26c5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26c9:
	/* 0x26c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26ce:
	/* 0x26ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26d0:
	/* 0x26d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26d2:
	/* 0x26d2: js     295d <generic_sleepable_preload+0x295d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_295d;
	}
x86_l_26d8:
	/* 0x26d8: cmp    WORD PTR [rbx+0xce],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 884763262976ULL);
x86_l_26e0:
	/* 0x26e0: je     3574 <generic_sleepable_preload+0x3574> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13684ULL;
	}
x86_l_26e6:
	/* 0x26e6: mov    ecx,DWORD PTR [rbx+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_26ec:
	/* 0x26ec: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_26f0:
	/* 0x26f0: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26f4:
	/* 0x26f4: cmp    WORD PTR [rbx+0xcc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_26fc:
	/* 0x26fc: je     271e <generic_sleepable_preload+0x271e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_271e;
	}
x86_l_26fe:
	/* 0x26fe: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2701:
	/* 0x2701: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2706:
	/* 0x2706: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_270b:
	/* 0x270b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_270f:
	/* 0x270f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2714:
	/* 0x2714: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2716:
	/* 0x2716: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2718:
	/* 0x2718: js     2968 <generic_sleepable_preload+0x2968> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2968;
	}
x86_l_271e:
	/* 0x271e: cmp    WORD PTR [rbx+0xd6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 919123001344ULL);
x86_l_2726:
	/* 0x2726: je     3574 <generic_sleepable_preload+0x3574> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13684ULL;
	}
x86_l_272c:
	/* 0x272c: mov    ecx,DWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2732:
	/* 0x2732: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2736:
	/* 0x2736: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_273a:
	/* 0x273a: cmp    WORD PTR [rbx+0xd4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_2742:
	/* 0x2742: je     2764 <generic_sleepable_preload+0x2764> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2764;
	}
x86_l_2744:
	/* 0x2744: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2747:
	/* 0x2747: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_274c:
	/* 0x274c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2751:
	/* 0x2751: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2755:
	/* 0x2755: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_275a:
	/* 0x275a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_275c:
	/* 0x275c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_275e:
	/* 0x275e: js     2fc6 <generic_sleepable_preload+0x2fc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12230ULL;
	}
x86_l_2764:
	/* 0x2764: cmp    WORD PTR [rbx+0xde],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 953482739712ULL);
x86_l_276c:
	/* 0x276c: je     3574 <generic_sleepable_preload+0x3574> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13684ULL;
	}
x86_l_2772:
	/* 0x2772: mov    ecx,DWORD PTR [rbx+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2778:
	/* 0x2778: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_277c:
	/* 0x277c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2780:
	/* 0x2780: cmp    WORD PTR [rbx+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_2788:
	/* 0x2788: je     27aa <generic_sleepable_preload+0x27aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27aa;
	}
x86_l_278a:
	/* 0x278a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_278d:
	/* 0x278d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2792:
	/* 0x2792: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2797:
	/* 0x2797: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_279b:
	/* 0x279b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27a0:
	/* 0x27a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27a2:
	/* 0x27a2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27a4:
	/* 0x27a4: js     3032 <generic_sleepable_preload+0x3032> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12338ULL;
	}
x86_l_27aa:
	/* 0x27aa: cmp    WORD PTR [rbx+0xe6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 987842478080ULL);
x86_l_27b2:
	/* 0x27b2: je     3574 <generic_sleepable_preload+0x3574> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13684ULL;
	}
x86_l_27b8:
	/* 0x27b8: mov    ecx,DWORD PTR [rbx+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_27be:
	/* 0x27be: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_27c2:
	/* 0x27c2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27c6:
	/* 0x27c6: cmp    WORD PTR [rbx+0xe4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_27ce:
	/* 0x27ce: je     27f0 <generic_sleepable_preload+0x27f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27f0;
	}
x86_l_27d0:
	/* 0x27d0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_27d3:
	/* 0x27d3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_27d8:
	/* 0x27d8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_27dd:
	/* 0x27dd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27e1:
	/* 0x27e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27e6:
	/* 0x27e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27e8:
	/* 0x27e8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27ea:
	/* 0x27ea: js     309e <generic_sleepable_preload+0x309e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12446ULL;
	}
x86_l_27f0:
	/* 0x27f0: cmp    WORD PTR [rbx+0xee],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_27f8:
	/* 0x27f8: je     3574 <generic_sleepable_preload+0x3574> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13684ULL;
	}
x86_l_27fe:
	/* 0x27fe: mov    ecx,DWORD PTR [rbx+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2804:
	/* 0x2804: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2808:
	/* 0x2808: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_280c:
	/* 0x280c: cmp    WORD PTR [rbx+0xec],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_2814:
	/* 0x2814: je     2836 <generic_sleepable_preload+0x2836> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2836;
	}
x86_l_2816:
	/* 0x2816: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2819:
	/* 0x2819: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_281e:
	/* 0x281e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2823:
	/* 0x2823: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2827:
	/* 0x2827: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_282c:
	/* 0x282c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_282e:
	/* 0x282e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2830:
	/* 0x2830: js     3107 <generic_sleepable_preload+0x3107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12551ULL;
	}
x86_l_2836:
	/* 0x2836: cmp    WORD PTR [rbx+0xf6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1056561954816ULL);
x86_l_283e:
	/* 0x283e: je     3574 <generic_sleepable_preload+0x3574> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13684ULL;
	}
x86_l_2844:
	/* 0x2844: mov    ecx,DWORD PTR [rbx+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_284a:
	/* 0x284a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_284e:
	/* 0x284e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2852:
	/* 0x2852: cmp    WORD PTR [rbx+0xf4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_285a:
	/* 0x285a: je     287c <generic_sleepable_preload+0x287c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_287c;
	}
x86_l_285c:
	/* 0x285c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_285f:
	/* 0x285f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2864:
	/* 0x2864: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2869:
	/* 0x2869: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_286d:
	/* 0x286d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2872:
	/* 0x2872: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2874:
	/* 0x2874: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2876:
	/* 0x2876: js     356c <generic_sleepable_preload+0x356c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13676ULL;
	}
x86_l_287c:
	/* 0x287c: cmp    WORD PTR [rbx+0xfe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1090921693184ULL);
x86_l_2884:
	/* 0x2884: je     3574 <generic_sleepable_preload+0x3574> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13684ULL;
	}
x86_l_288a:
	/* 0x288a: mov    ecx,DWORD PTR [rbx+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2890:
	/* 0x2890: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2894:
	/* 0x2894: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2898:
	/* 0x2898: cmp    WORD PTR [rbx+0xfc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_28a0:
	/* 0x28a0: je     28c2 <generic_sleepable_preload+0x28c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28c2;
	}
x86_l_28a2:
	/* 0x28a2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_28a5:
	/* 0x28a5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_28aa:
	/* 0x28aa: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_28af:
	/* 0x28af: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28b3:
	/* 0x28b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28b8:
	/* 0x28b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28ba:
	/* 0x28ba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28bc:
	/* 0x28bc: js     3818 <generic_sleepable_preload+0x3818> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14360ULL;
	}
x86_l_28c2:
	/* 0x28c2: cmp    WORD PTR [rbx+0x106],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1125281431552ULL);
x86_l_28ca:
	/* 0x28ca: je     3574 <generic_sleepable_preload+0x3574> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13684ULL;
	}
x86_l_28d0:
	/* 0x28d0: mov    ecx,DWORD PTR [rbx+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_28d6:
	/* 0x28d6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_28da:
	/* 0x28da: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28de:
	/* 0x28de: cmp    WORD PTR [rbx+0x104],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1116691496960ULL);
x86_l_28e6:
	/* 0x28e6: je     2908 <generic_sleepable_preload+0x2908> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2908;
	}
x86_l_28e8:
	/* 0x28e8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_28eb:
	/* 0x28eb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_28f0:
	/* 0x28f0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_28f5:
	/* 0x28f5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28f9:
	/* 0x28f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28fe:
	/* 0x28fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2900:
	/* 0x2900: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2902:
	/* 0x2902: js     38a8 <generic_sleepable_preload+0x38a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14504ULL;
	}
x86_l_2908:
	/* 0x2908: cmp    WORD PTR [rbx+0x10e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1159641169920ULL);
x86_l_2910:
	/* 0x2910: je     3574 <generic_sleepable_preload+0x3574> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13684ULL;
	}
x86_l_2916:
	/* 0x2916: mov    ecx,DWORD PTR [rbx+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_291c:
	/* 0x291c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2920:
	/* 0x2920: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2924:
	/* 0x2924: cmp    WORD PTR [rbx+0x10c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_292c:
	/* 0x292c: je     3574 <generic_sleepable_preload+0x3574> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13684ULL;
	}
x86_l_2932:
	/* 0x2932: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2935:
	/* 0x2935: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_293a:
	/* 0x293a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_293f:
	/* 0x293f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2943:
	/* 0x2943: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2948:
	/* 0x2948: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_294a:
	/* 0x294a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_294c:
	/* 0x294c: jns    3574 <generic_sleepable_preload+0x3574> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 13684ULL;
	}
x86_l_2952:
	/* 0x2952: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_2958:
	/* 0x2958: jmp    3572 <generic_sleepable_preload+0x3572> */
	return 13682ULL;
x86_l_295d:
	/* 0x295d: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_2963:
	/* 0x2963: jmp    3572 <generic_sleepable_preload+0x3572> */
	return 13682ULL;
x86_l_2968:
	/* 0x2968: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_296e:
	/* 0x296e: jmp    3572 <generic_sleepable_preload+0x3572> */
	return 13682ULL;
x86_l_2973:
	/* 0x2973: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2976:
	/* 0x2976: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_2979:
	/* 0x2979: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_297b:
	/* 0x297b: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_297d:
	/* 0x297d: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_2982:
	/* 0x2982: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2984:
	/* 0x2984: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_2989:
	/* 0x2989: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_298d:
	/* 0x298d: mov    r15d,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2991:
	/* 0x2991: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2994:
	/* 0x2994: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_2997:
	/* 0x2997: cmp    WORD PTR [rbx+0x116],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1194000908288ULL);
x86_l_299f:
	/* 0x299f: je     3633 <generic_sleepable_preload+0x3633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13875ULL;
	}
x86_l_29a5:
	/* 0x29a5: mov    eax,DWORD PTR [rbx+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_29ab:
	/* 0x29ab: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29ae:
	/* 0x29ae: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29b2:
	/* 0x29b2: cmp    WORD PTR [rbx+0x114],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1185410973696ULL);
x86_l_29ba:
	/* 0x29ba: je     29dc <generic_sleepable_preload+0x29dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29dc;
	}
x86_l_29bc:
	/* 0x29bc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29bf:
	/* 0x29bf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_29c4:
	/* 0x29c4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_29c9:
	/* 0x29c9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29cd:
	/* 0x29cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29d2:
	/* 0x29d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29d4:
	/* 0x29d4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29d6:
	/* 0x29d6: js     2c61 <generic_sleepable_preload+0x2c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11361ULL;
	}
x86_l_29dc:
	/* 0x29dc: cmp    WORD PTR [rbx+0x11e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1228360646656ULL);
x86_l_29e4:
	/* 0x29e4: je     3633 <generic_sleepable_preload+0x3633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13875ULL;
	}
x86_l_29ea:
	/* 0x29ea: mov    ecx,DWORD PTR [rbx+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_29f0:
	/* 0x29f0: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_29f4:
	/* 0x29f4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29f8:
	/* 0x29f8: cmp    WORD PTR [rbx+0x11c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_2a00:
	/* 0x2a00: je     2a22 <generic_sleepable_preload+0x2a22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a22;
	}
x86_l_2a02:
	/* 0x2a02: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a05:
	/* 0x2a05: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a0a:
	/* 0x2a0a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a0f:
	/* 0x2a0f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a13:
	/* 0x2a13: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a18:
	/* 0x2a18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a1a:
	/* 0x2a1a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a1c:
	/* 0x2a1c: js     2c6c <generic_sleepable_preload+0x2c6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11372ULL;
	}
x86_l_2a22:
	/* 0x2a22: cmp    WORD PTR [rbx+0x126],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1262720385024ULL);
x86_l_2a2a:
	/* 0x2a2a: je     3633 <generic_sleepable_preload+0x3633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13875ULL;
	}
x86_l_2a30:
	/* 0x2a30: mov    ecx,DWORD PTR [rbx+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2a36:
	/* 0x2a36: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a3a:
	/* 0x2a3a: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a3e:
	/* 0x2a3e: cmp    WORD PTR [rbx+0x124],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1254130450432ULL);
x86_l_2a46:
	/* 0x2a46: je     2a68 <generic_sleepable_preload+0x2a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a68;
	}
x86_l_2a48:
	/* 0x2a48: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a4b:
	/* 0x2a4b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a50:
	/* 0x2a50: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a55:
	/* 0x2a55: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a59:
	/* 0x2a59: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a5e:
	/* 0x2a5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a60:
	/* 0x2a60: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a62:
	/* 0x2a62: js     2fd1 <generic_sleepable_preload+0x2fd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12241ULL;
	}
x86_l_2a68:
	/* 0x2a68: cmp    WORD PTR [rbx+0x12e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1297080123392ULL);
x86_l_2a70:
	/* 0x2a70: je     3633 <generic_sleepable_preload+0x3633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13875ULL;
	}
x86_l_2a76:
	/* 0x2a76: mov    ecx,DWORD PTR [rbx+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_2a7c:
	/* 0x2a7c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2a80:
	/* 0x2a80: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a84:
	/* 0x2a84: cmp    WORD PTR [rbx+0x12c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1288490188800ULL);
x86_l_2a8c:
	/* 0x2a8c: je     2aae <generic_sleepable_preload+0x2aae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aae;
	}
x86_l_2a8e:
	/* 0x2a8e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a91:
	/* 0x2a91: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a96:
	/* 0x2a96: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2a9b:
	/* 0x2a9b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a9f:
	/* 0x2a9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2aa4:
	/* 0x2aa4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aa6:
	/* 0x2aa6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2aa8:
	/* 0x2aa8: js     303d <generic_sleepable_preload+0x303d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12349ULL;
	}
x86_l_2aae:
	/* 0x2aae: cmp    WORD PTR [rbx+0x136],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1331439861760ULL);
x86_l_2ab6:
	/* 0x2ab6: je     3633 <generic_sleepable_preload+0x3633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13875ULL;
	}
x86_l_2abc:
	/* 0x2abc: mov    ecx,DWORD PTR [rbx+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_2ac2:
	/* 0x2ac2: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2ac6:
	/* 0x2ac6: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2aca:
	/* 0x2aca: cmp    WORD PTR [rbx+0x134],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1322849927168ULL);
x86_l_2ad2:
	/* 0x2ad2: je     2af4 <generic_sleepable_preload+0x2af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10996ULL;
	}
x86_l_2ad4:
	/* 0x2ad4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ad7:
	/* 0x2ad7: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
	return 10972ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10972ULL: goto x86_l_2adc;
	case 10977ULL: goto x86_l_2ae1;
	case 10981ULL: goto x86_l_2ae5;
	case 10986ULL: goto x86_l_2aea;
	case 10988ULL: goto x86_l_2aec;
	case 10990ULL: goto x86_l_2aee;
	case 10996ULL: goto x86_l_2af4;
	case 11004ULL: goto x86_l_2afc;
	case 11010ULL: goto x86_l_2b02;
	case 11016ULL: goto x86_l_2b08;
	case 11020ULL: goto x86_l_2b0c;
	case 11024ULL: goto x86_l_2b10;
	case 11032ULL: goto x86_l_2b18;
	case 11034ULL: goto x86_l_2b1a;
	case 11037ULL: goto x86_l_2b1d;
	case 11042ULL: goto x86_l_2b22;
	case 11047ULL: goto x86_l_2b27;
	case 11051ULL: goto x86_l_2b2b;
	case 11056ULL: goto x86_l_2b30;
	case 11058ULL: goto x86_l_2b32;
	case 11060ULL: goto x86_l_2b34;
	case 11066ULL: goto x86_l_2b3a;
	case 11074ULL: goto x86_l_2b42;
	case 11080ULL: goto x86_l_2b48;
	case 11086ULL: goto x86_l_2b4e;
	case 11090ULL: goto x86_l_2b52;
	case 11094ULL: goto x86_l_2b56;
	case 11102ULL: goto x86_l_2b5e;
	case 11104ULL: goto x86_l_2b60;
	case 11107ULL: goto x86_l_2b63;
	case 11112ULL: goto x86_l_2b68;
	case 11117ULL: goto x86_l_2b6d;
	case 11121ULL: goto x86_l_2b71;
	case 11126ULL: goto x86_l_2b76;
	case 11128ULL: goto x86_l_2b78;
	case 11130ULL: goto x86_l_2b7a;
	case 11136ULL: goto x86_l_2b80;
	case 11144ULL: goto x86_l_2b88;
	case 11150ULL: goto x86_l_2b8e;
	case 11156ULL: goto x86_l_2b94;
	case 11160ULL: goto x86_l_2b98;
	case 11164ULL: goto x86_l_2b9c;
	case 11172ULL: goto x86_l_2ba4;
	case 11174ULL: goto x86_l_2ba6;
	case 11177ULL: goto x86_l_2ba9;
	case 11182ULL: goto x86_l_2bae;
	case 11187ULL: goto x86_l_2bb3;
	case 11191ULL: goto x86_l_2bb7;
	case 11196ULL: goto x86_l_2bbc;
	case 11198ULL: goto x86_l_2bbe;
	case 11200ULL: goto x86_l_2bc0;
	case 11206ULL: goto x86_l_2bc6;
	case 11214ULL: goto x86_l_2bce;
	case 11220ULL: goto x86_l_2bd4;
	case 11226ULL: goto x86_l_2bda;
	case 11230ULL: goto x86_l_2bde;
	case 11234ULL: goto x86_l_2be2;
	case 11242ULL: goto x86_l_2bea;
	case 11244ULL: goto x86_l_2bec;
	case 11247ULL: goto x86_l_2bef;
	case 11252ULL: goto x86_l_2bf4;
	case 11257ULL: goto x86_l_2bf9;
	case 11261ULL: goto x86_l_2bfd;
	case 11266ULL: goto x86_l_2c02;
	case 11268ULL: goto x86_l_2c04;
	case 11270ULL: goto x86_l_2c06;
	case 11276ULL: goto x86_l_2c0c;
	case 11284ULL: goto x86_l_2c14;
	case 11290ULL: goto x86_l_2c1a;
	case 11296ULL: goto x86_l_2c20;
	case 11300ULL: goto x86_l_2c24;
	case 11304ULL: goto x86_l_2c28;
	case 11312ULL: goto x86_l_2c30;
	case 11318ULL: goto x86_l_2c36;
	case 11321ULL: goto x86_l_2c39;
	case 11326ULL: goto x86_l_2c3e;
	case 11331ULL: goto x86_l_2c43;
	case 11335ULL: goto x86_l_2c47;
	case 11340ULL: goto x86_l_2c4c;
	case 11342ULL: goto x86_l_2c4e;
	case 11344ULL: goto x86_l_2c50;
	case 11350ULL: goto x86_l_2c56;
	case 11356ULL: goto x86_l_2c5c;
	case 11361ULL: goto x86_l_2c61;
	case 11367ULL: goto x86_l_2c67;
	case 11372ULL: goto x86_l_2c6c;
	case 11378ULL: goto x86_l_2c72;
	case 11383ULL: goto x86_l_2c77;
	case 11386ULL: goto x86_l_2c7a;
	case 11389ULL: goto x86_l_2c7d;
	case 11391ULL: goto x86_l_2c7f;
	case 11393ULL: goto x86_l_2c81;
	case 11398ULL: goto x86_l_2c86;
	case 11400ULL: goto x86_l_2c88;
	case 11405ULL: goto x86_l_2c8d;
	case 11409ULL: goto x86_l_2c91;
	case 11413ULL: goto x86_l_2c95;
	case 11416ULL: goto x86_l_2c98;
	case 11419ULL: goto x86_l_2c9b;
	case 11427ULL: goto x86_l_2ca3;
	case 11433ULL: goto x86_l_2ca9;
	case 11439ULL: goto x86_l_2caf;
	case 11442ULL: goto x86_l_2cb2;
	case 11446ULL: goto x86_l_2cb6;
	case 11454ULL: goto x86_l_2cbe;
	case 11456ULL: goto x86_l_2cc0;
	case 11459ULL: goto x86_l_2cc3;
	case 11464ULL: goto x86_l_2cc8;
	case 11469ULL: goto x86_l_2ccd;
	case 11473ULL: goto x86_l_2cd1;
	case 11478ULL: goto x86_l_2cd6;
	case 11480ULL: goto x86_l_2cd8;
	case 11482ULL: goto x86_l_2cda;
	case 11488ULL: goto x86_l_2ce0;
	case 11496ULL: goto x86_l_2ce8;
	case 11502ULL: goto x86_l_2cee;
	case 11508ULL: goto x86_l_2cf4;
	case 11512ULL: goto x86_l_2cf8;
	case 11516ULL: goto x86_l_2cfc;
	case 11524ULL: goto x86_l_2d04;
	case 11526ULL: goto x86_l_2d06;
	case 11529ULL: goto x86_l_2d09;
	case 11534ULL: goto x86_l_2d0e;
	case 11539ULL: goto x86_l_2d13;
	case 11543ULL: goto x86_l_2d17;
	case 11548ULL: goto x86_l_2d1c;
	case 11550ULL: goto x86_l_2d1e;
	case 11552ULL: goto x86_l_2d20;
	case 11558ULL: goto x86_l_2d26;
	case 11566ULL: goto x86_l_2d2e;
	case 11572ULL: goto x86_l_2d34;
	case 11578ULL: goto x86_l_2d3a;
	case 11582ULL: goto x86_l_2d3e;
	case 11586ULL: goto x86_l_2d42;
	case 11594ULL: goto x86_l_2d4a;
	case 11596ULL: goto x86_l_2d4c;
	case 11599ULL: goto x86_l_2d4f;
	case 11604ULL: goto x86_l_2d54;
	case 11609ULL: goto x86_l_2d59;
	case 11613ULL: goto x86_l_2d5d;
	case 11618ULL: goto x86_l_2d62;
	case 11620ULL: goto x86_l_2d64;
	case 11622ULL: goto x86_l_2d66;
	case 11628ULL: goto x86_l_2d6c;
	case 11636ULL: goto x86_l_2d74;
	case 11642ULL: goto x86_l_2d7a;
	case 11648ULL: goto x86_l_2d80;
	case 11652ULL: goto x86_l_2d84;
	case 11656ULL: goto x86_l_2d88;
	case 11664ULL: goto x86_l_2d90;
	case 11666ULL: goto x86_l_2d92;
	case 11669ULL: goto x86_l_2d95;
	case 11674ULL: goto x86_l_2d9a;
	case 11679ULL: goto x86_l_2d9f;
	case 11683ULL: goto x86_l_2da3;
	case 11688ULL: goto x86_l_2da8;
	case 11690ULL: goto x86_l_2daa;
	case 11692ULL: goto x86_l_2dac;
	case 11698ULL: goto x86_l_2db2;
	case 11706ULL: goto x86_l_2dba;
	case 11712ULL: goto x86_l_2dc0;
	case 11718ULL: goto x86_l_2dc6;
	case 11722ULL: goto x86_l_2dca;
	case 11726ULL: goto x86_l_2dce;
	case 11734ULL: goto x86_l_2dd6;
	case 11736ULL: goto x86_l_2dd8;
	case 11739ULL: goto x86_l_2ddb;
	case 11744ULL: goto x86_l_2de0;
	case 11749ULL: goto x86_l_2de5;
	case 11753ULL: goto x86_l_2de9;
	case 11758ULL: goto x86_l_2dee;
	case 11760ULL: goto x86_l_2df0;
	case 11762ULL: goto x86_l_2df2;
	case 11768ULL: goto x86_l_2df8;
	case 11776ULL: goto x86_l_2e00;
	case 11782ULL: goto x86_l_2e06;
	case 11788ULL: goto x86_l_2e0c;
	case 11792ULL: goto x86_l_2e10;
	case 11796ULL: goto x86_l_2e14;
	case 11804ULL: goto x86_l_2e1c;
	case 11806ULL: goto x86_l_2e1e;
	case 11809ULL: goto x86_l_2e21;
	case 11814ULL: goto x86_l_2e26;
	case 11819ULL: goto x86_l_2e2b;
	case 11823ULL: goto x86_l_2e2f;
	case 11828ULL: goto x86_l_2e34;
	case 11830ULL: goto x86_l_2e36;
	case 11832ULL: goto x86_l_2e38;
	case 11838ULL: goto x86_l_2e3e;
	case 11846ULL: goto x86_l_2e46;
	case 11852ULL: goto x86_l_2e4c;
	case 11858ULL: goto x86_l_2e52;
	case 11862ULL: goto x86_l_2e56;
	case 11866ULL: goto x86_l_2e5a;
	case 11874ULL: goto x86_l_2e62;
	case 11876ULL: goto x86_l_2e64;
	case 11879ULL: goto x86_l_2e67;
	case 11884ULL: goto x86_l_2e6c;
	case 11889ULL: goto x86_l_2e71;
	case 11893ULL: goto x86_l_2e75;
	case 11898ULL: goto x86_l_2e7a;
	case 11900ULL: goto x86_l_2e7c;
	case 11902ULL: goto x86_l_2e7e;
	case 11908ULL: goto x86_l_2e84;
	case 11916ULL: goto x86_l_2e8c;
	case 11922ULL: goto x86_l_2e92;
	case 11928ULL: goto x86_l_2e98;
	case 11932ULL: goto x86_l_2e9c;
	case 11936ULL: goto x86_l_2ea0;
	case 11944ULL: goto x86_l_2ea8;
	case 11946ULL: goto x86_l_2eaa;
	case 11949ULL: goto x86_l_2ead;
	case 11954ULL: goto x86_l_2eb2;
	case 11959ULL: goto x86_l_2eb7;
	case 11963ULL: goto x86_l_2ebb;
	case 11968ULL: goto x86_l_2ec0;
	case 11970ULL: goto x86_l_2ec2;
	case 11972ULL: goto x86_l_2ec4;
	case 11978ULL: goto x86_l_2eca;
	case 11986ULL: goto x86_l_2ed2;
	case 11992ULL: goto x86_l_2ed8;
	case 11998ULL: goto x86_l_2ede;
	case 12002ULL: goto x86_l_2ee2;
	case 12006ULL: goto x86_l_2ee6;
	case 12014ULL: goto x86_l_2eee;
	case 12016ULL: goto x86_l_2ef0;
	case 12019ULL: goto x86_l_2ef3;
	case 12024ULL: goto x86_l_2ef8;
	case 12029ULL: goto x86_l_2efd;
	case 12033ULL: goto x86_l_2f01;
	case 12038ULL: goto x86_l_2f06;
	case 12040ULL: goto x86_l_2f08;
	case 12042ULL: goto x86_l_2f0a;
	case 12048ULL: goto x86_l_2f10;
	case 12056ULL: goto x86_l_2f18;
	case 12062ULL: goto x86_l_2f1e;
	case 12068ULL: goto x86_l_2f24;
	case 12072ULL: goto x86_l_2f28;
	case 12076ULL: goto x86_l_2f2c;
	case 12084ULL: goto x86_l_2f34;
	case 12090ULL: goto x86_l_2f3a;
	case 12093ULL: goto x86_l_2f3d;
	case 12098ULL: goto x86_l_2f42;
	case 12103ULL: goto x86_l_2f47;
	case 12107ULL: goto x86_l_2f4b;
	case 12112ULL: goto x86_l_2f50;
	case 12114ULL: goto x86_l_2f52;
	case 12116ULL: goto x86_l_2f54;
	case 12122ULL: goto x86_l_2f5a;
	case 12128ULL: goto x86_l_2f60;
	case 12133ULL: goto x86_l_2f65;
	case 12139ULL: goto x86_l_2f6b;
	case 12144ULL: goto x86_l_2f70;
	case 12150ULL: goto x86_l_2f76;
	case 12155ULL: goto x86_l_2f7b;
	case 12161ULL: goto x86_l_2f81;
	case 12166ULL: goto x86_l_2f86;
	case 12172ULL: goto x86_l_2f8c;
	case 12177ULL: goto x86_l_2f91;
	case 12183ULL: goto x86_l_2f97;
	case 12188ULL: goto x86_l_2f9c;
	case 12194ULL: goto x86_l_2fa2;
	case 12199ULL: goto x86_l_2fa7;
	case 12204ULL: goto x86_l_2fac;
	case 12209ULL: goto x86_l_2fb1;
	case 12215ULL: goto x86_l_2fb7;
	case 12220ULL: goto x86_l_2fbc;
	case 12225ULL: goto x86_l_2fc1;
	case 12230ULL: goto x86_l_2fc6;
	case 12236ULL: goto x86_l_2fcc;
	case 12241ULL: goto x86_l_2fd1;
	case 12247ULL: goto x86_l_2fd7;
	case 12252ULL: goto x86_l_2fdc;
	case 12258ULL: goto x86_l_2fe2;
	case 12263ULL: goto x86_l_2fe7;
	case 12269ULL: goto x86_l_2fed;
	case 12274ULL: goto x86_l_2ff2;
	case 12280ULL: goto x86_l_2ff8;
	case 12285ULL: goto x86_l_2ffd;
	case 12291ULL: goto x86_l_3003;
	case 12296ULL: goto x86_l_3008;
	case 12302ULL: goto x86_l_300e;
	case 12307ULL: goto x86_l_3013;
	case 12312ULL: goto x86_l_3018;
	case 12317ULL: goto x86_l_301d;
	case 12323ULL: goto x86_l_3023;
	case 12328ULL: goto x86_l_3028;
	case 12333ULL: goto x86_l_302d;
	case 12338ULL: goto x86_l_3032;
	case 12344ULL: goto x86_l_3038;
	case 12349ULL: goto x86_l_303d;
	case 12355ULL: goto x86_l_3043;
	case 12360ULL: goto x86_l_3048;
	case 12366ULL: goto x86_l_304e;
	case 12371ULL: goto x86_l_3053;
	case 12377ULL: goto x86_l_3059;
	case 12382ULL: goto x86_l_305e;
	case 12388ULL: goto x86_l_3064;
	case 12393ULL: goto x86_l_3069;
	case 12399ULL: goto x86_l_306f;
	case 12404ULL: goto x86_l_3074;
	case 12410ULL: goto x86_l_307a;
	case 12415ULL: goto x86_l_307f;
	case 12420ULL: goto x86_l_3084;
	case 12425ULL: goto x86_l_3089;
	case 12431ULL: goto x86_l_308f;
	case 12436ULL: goto x86_l_3094;
	case 12441ULL: goto x86_l_3099;
	case 12446ULL: goto x86_l_309e;
	case 12452ULL: goto x86_l_30a4;
	case 12457ULL: goto x86_l_30a9;
	case 12463ULL: goto x86_l_30af;
	case 12468ULL: goto x86_l_30b4;
	case 12474ULL: goto x86_l_30ba;
	case 12479ULL: goto x86_l_30bf;
	case 12485ULL: goto x86_l_30c5;
	case 12487ULL: goto x86_l_30c7;
	case 12493ULL: goto x86_l_30cd;
	case 12498ULL: goto x86_l_30d2;
	case 12504ULL: goto x86_l_30d8;
	case 12509ULL: goto x86_l_30dd;
	case 12515ULL: goto x86_l_30e3;
	case 12520ULL: goto x86_l_30e8;
	case 12525ULL: goto x86_l_30ed;
	case 12530ULL: goto x86_l_30f2;
	case 12536ULL: goto x86_l_30f8;
	case 12541ULL: goto x86_l_30fd;
	case 12546ULL: goto x86_l_3102;
	case 12551ULL: goto x86_l_3107;
	case 12557ULL: goto x86_l_310d;
	case 12562ULL: goto x86_l_3112;
	case 12568ULL: goto x86_l_3118;
	case 12573ULL: goto x86_l_311d;
	case 12579ULL: goto x86_l_3123;
	case 12584ULL: goto x86_l_3128;
	case 12590ULL: goto x86_l_312e;
	case 12592ULL: goto x86_l_3130;
	case 12596ULL: goto x86_l_3134;
	case 12601ULL: goto x86_l_3139;
	case 12606ULL: goto x86_l_313e;
	case 12611ULL: goto x86_l_3143;
	case 12616ULL: goto x86_l_3148;
	case 12619ULL: goto x86_l_314b;
	case 12621ULL: goto x86_l_314d;
	case 12625ULL: goto x86_l_3151;
	case 12631ULL: goto x86_l_3157;
	case 12636ULL: goto x86_l_315c;
	case 12641ULL: goto x86_l_3161;
	case 12646ULL: goto x86_l_3166;
	case 12648ULL: goto x86_l_3168;
	case 12653ULL: goto x86_l_316d;
	case 12660ULL: goto x86_l_3174;
	case 12667ULL: goto x86_l_317b;
	case 12670ULL: goto x86_l_317e;
	case 12675ULL: goto x86_l_3183;
	case 12677ULL: goto x86_l_3185;
	case 12680ULL: goto x86_l_3188;
	case 12686ULL: goto x86_l_318e;
	case 12689ULL: goto x86_l_3191;
	case 12692ULL: goto x86_l_3194;
	case 12695ULL: goto x86_l_3197;
	case 12702ULL: goto x86_l_319e;
	case 12704ULL: goto x86_l_31a0;
	case 12709ULL: goto x86_l_31a5;
	case 12714ULL: goto x86_l_31aa;
	case 12717ULL: goto x86_l_31ad;
	case 12720ULL: goto x86_l_31b0;
	case 12722ULL: goto x86_l_31b2;
	case 12724ULL: goto x86_l_31b4;
	case 12729ULL: goto x86_l_31b9;
	case 12734ULL: goto x86_l_31be;
	case 12740ULL: goto x86_l_31c4;
	case 12742ULL: goto x86_l_31c6;
	case 12746ULL: goto x86_l_31ca;
	case 12751ULL: goto x86_l_31cf;
	case 12756ULL: goto x86_l_31d4;
	case 12761ULL: goto x86_l_31d9;
	case 12766ULL: goto x86_l_31de;
	case 12769ULL: goto x86_l_31e1;
	case 12771ULL: goto x86_l_31e3;
	case 12775ULL: goto x86_l_31e7;
	case 12781ULL: goto x86_l_31ed;
	case 12786ULL: goto x86_l_31f2;
	case 12791ULL: goto x86_l_31f7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2adc:
	/* 0x2adc: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ae1:
	/* 0x2ae1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ae5:
	/* 0x2ae5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2aea:
	/* 0x2aea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aec:
	/* 0x2aec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2aee:
	/* 0x2aee: js     30a9 <generic_sleepable_preload+0x30a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_30a9;
	}
x86_l_2af4:
	/* 0x2af4: cmp    WORD PTR [rbx+0x13e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1365799600128ULL);
x86_l_2afc:
	/* 0x2afc: je     3633 <generic_sleepable_preload+0x3633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13875ULL;
	}
x86_l_2b02:
	/* 0x2b02: mov    ecx,DWORD PTR [rbx+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_2b08:
	/* 0x2b08: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2b0c:
	/* 0x2b0c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b10:
	/* 0x2b10: cmp    WORD PTR [rbx+0x13c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1357209665536ULL);
x86_l_2b18:
	/* 0x2b18: je     2b3a <generic_sleepable_preload+0x2b3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b3a;
	}
x86_l_2b1a:
	/* 0x2b1a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b1d:
	/* 0x2b1d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b22:
	/* 0x2b22: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b27:
	/* 0x2b27: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b2b:
	/* 0x2b2b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b30:
	/* 0x2b30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b32:
	/* 0x2b32: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b34:
	/* 0x2b34: js     3112 <generic_sleepable_preload+0x3112> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3112;
	}
x86_l_2b3a:
	/* 0x2b3a: cmp    WORD PTR [rbx+0x146],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1400159338496ULL);
x86_l_2b42:
	/* 0x2b42: je     3633 <generic_sleepable_preload+0x3633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13875ULL;
	}
x86_l_2b48:
	/* 0x2b48: mov    ecx,DWORD PTR [rbx+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_2b4e:
	/* 0x2b4e: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2b52:
	/* 0x2b52: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b56:
	/* 0x2b56: cmp    WORD PTR [rbx+0x144],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1391569403904ULL);
x86_l_2b5e:
	/* 0x2b5e: je     2b80 <generic_sleepable_preload+0x2b80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b80;
	}
x86_l_2b60:
	/* 0x2b60: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b63:
	/* 0x2b63: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2b68:
	/* 0x2b68: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2b6d:
	/* 0x2b6d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b71:
	/* 0x2b71: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b76:
	/* 0x2b76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b78:
	/* 0x2b78: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b7a:
	/* 0x2b7a: js     362b <generic_sleepable_preload+0x362b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13867ULL;
	}
x86_l_2b80:
	/* 0x2b80: cmp    WORD PTR [rbx+0x14e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1434519076864ULL);
x86_l_2b88:
	/* 0x2b88: je     3633 <generic_sleepable_preload+0x3633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13875ULL;
	}
x86_l_2b8e:
	/* 0x2b8e: mov    ecx,DWORD PTR [rbx+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_2b94:
	/* 0x2b94: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2b98:
	/* 0x2b98: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b9c:
	/* 0x2b9c: cmp    WORD PTR [rbx+0x14c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1425929142272ULL);
x86_l_2ba4:
	/* 0x2ba4: je     2bc6 <generic_sleepable_preload+0x2bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bc6;
	}
x86_l_2ba6:
	/* 0x2ba6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ba9:
	/* 0x2ba9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2bae:
	/* 0x2bae: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2bb3:
	/* 0x2bb3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bb7:
	/* 0x2bb7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bbc:
	/* 0x2bbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bbe:
	/* 0x2bbe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bc0:
	/* 0x2bc0: js     382f <generic_sleepable_preload+0x382f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14383ULL;
	}
x86_l_2bc6:
	/* 0x2bc6: cmp    WORD PTR [rbx+0x156],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1468878815232ULL);
x86_l_2bce:
	/* 0x2bce: je     3633 <generic_sleepable_preload+0x3633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13875ULL;
	}
x86_l_2bd4:
	/* 0x2bd4: mov    ecx,DWORD PTR [rbx+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_2bda:
	/* 0x2bda: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2bde:
	/* 0x2bde: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2be2:
	/* 0x2be2: cmp    WORD PTR [rbx+0x154],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1460288880640ULL);
x86_l_2bea:
	/* 0x2bea: je     2c0c <generic_sleepable_preload+0x2c0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c0c;
	}
x86_l_2bec:
	/* 0x2bec: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2bef:
	/* 0x2bef: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2bf4:
	/* 0x2bf4: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2bf9:
	/* 0x2bf9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bfd:
	/* 0x2bfd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c02:
	/* 0x2c02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c04:
	/* 0x2c04: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c06:
	/* 0x2c06: js     38b3 <generic_sleepable_preload+0x38b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14515ULL;
	}
x86_l_2c0c:
	/* 0x2c0c: cmp    WORD PTR [rbx+0x15e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1503238553600ULL);
x86_l_2c14:
	/* 0x2c14: je     3633 <generic_sleepable_preload+0x3633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13875ULL;
	}
x86_l_2c1a:
	/* 0x2c1a: mov    ecx,DWORD PTR [rbx+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_2c20:
	/* 0x2c20: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2c24:
	/* 0x2c24: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c28:
	/* 0x2c28: cmp    WORD PTR [rbx+0x15c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1494648619008ULL);
x86_l_2c30:
	/* 0x2c30: je     3633 <generic_sleepable_preload+0x3633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13875ULL;
	}
x86_l_2c36:
	/* 0x2c36: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2c39:
	/* 0x2c39: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2c3e:
	/* 0x2c3e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2c43:
	/* 0x2c43: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c47:
	/* 0x2c47: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c4c:
	/* 0x2c4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c4e:
	/* 0x2c4e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c50:
	/* 0x2c50: jns    3633 <generic_sleepable_preload+0x3633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 13875ULL;
	}
x86_l_2c56:
	/* 0x2c56: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_2c5c:
	/* 0x2c5c: jmp    3631 <generic_sleepable_preload+0x3631> */
	return 13873ULL;
x86_l_2c61:
	/* 0x2c61: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_2c67:
	/* 0x2c67: jmp    3631 <generic_sleepable_preload+0x3631> */
	return 13873ULL;
x86_l_2c6c:
	/* 0x2c6c: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_2c72:
	/* 0x2c72: jmp    3631 <generic_sleepable_preload+0x3631> */
	return 13873ULL;
x86_l_2c77:
	/* 0x2c77: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2c7a:
	/* 0x2c7a: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_2c7d:
	/* 0x2c7d: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_2c7f:
	/* 0x2c7f: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2c81:
	/* 0x2c81: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_2c86:
	/* 0x2c86: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c88:
	/* 0x2c88: bzhi   rcx,QWORD PTR [rsi],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RCX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_2c8d:
	/* 0x2c8d: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c91:
	/* 0x2c91: mov    r15d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c95:
	/* 0x2c95: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c98:
	/* 0x2c98: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_2c9b:
	/* 0x2c9b: cmp    WORD PTR [rbx+0x166],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1537598291968ULL);
x86_l_2ca3:
	/* 0x2ca3: je     36f2 <generic_sleepable_preload+0x36f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14066ULL;
	}
x86_l_2ca9:
	/* 0x2ca9: mov    eax,DWORD PTR [rbx+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_2caf:
	/* 0x2caf: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2cb2:
	/* 0x2cb2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cb6:
	/* 0x2cb6: cmp    WORD PTR [rbx+0x164],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1529008357376ULL);
x86_l_2cbe:
	/* 0x2cbe: je     2ce0 <generic_sleepable_preload+0x2ce0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ce0;
	}
x86_l_2cc0:
	/* 0x2cc0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2cc3:
	/* 0x2cc3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2cc8:
	/* 0x2cc8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2ccd:
	/* 0x2ccd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cd1:
	/* 0x2cd1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cd6:
	/* 0x2cd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cd8:
	/* 0x2cd8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2cda:
	/* 0x2cda: js     2f65 <generic_sleepable_preload+0x2f65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2f65;
	}
x86_l_2ce0:
	/* 0x2ce0: cmp    WORD PTR [rbx+0x16e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1571958030336ULL);
x86_l_2ce8:
	/* 0x2ce8: je     36f2 <generic_sleepable_preload+0x36f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14066ULL;
	}
x86_l_2cee:
	/* 0x2cee: mov    ecx,DWORD PTR [rbx+0x168] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360ULL);
x86_l_2cf4:
	/* 0x2cf4: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2cf8:
	/* 0x2cf8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cfc:
	/* 0x2cfc: cmp    WORD PTR [rbx+0x16c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1563368095744ULL);
x86_l_2d04:
	/* 0x2d04: je     2d26 <generic_sleepable_preload+0x2d26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d26;
	}
x86_l_2d06:
	/* 0x2d06: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2d09:
	/* 0x2d09: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d0e:
	/* 0x2d0e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d13:
	/* 0x2d13: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d17:
	/* 0x2d17: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d1c:
	/* 0x2d1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d1e:
	/* 0x2d1e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d20:
	/* 0x2d20: js     2f70 <generic_sleepable_preload+0x2f70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2f70;
	}
x86_l_2d26:
	/* 0x2d26: cmp    WORD PTR [rbx+0x176],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1606317768704ULL);
x86_l_2d2e:
	/* 0x2d2e: je     36f2 <generic_sleepable_preload+0x36f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14066ULL;
	}
x86_l_2d34:
	/* 0x2d34: mov    ecx,DWORD PTR [rbx+0x170] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 368ULL);
x86_l_2d3a:
	/* 0x2d3a: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2d3e:
	/* 0x2d3e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d42:
	/* 0x2d42: cmp    WORD PTR [rbx+0x174],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1597727834112ULL);
x86_l_2d4a:
	/* 0x2d4a: je     2d6c <generic_sleepable_preload+0x2d6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d6c;
	}
x86_l_2d4c:
	/* 0x2d4c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2d4f:
	/* 0x2d4f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d54:
	/* 0x2d54: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d59:
	/* 0x2d59: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d5d:
	/* 0x2d5d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d62:
	/* 0x2d62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d64:
	/* 0x2d64: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d66:
	/* 0x2d66: js     2fdc <generic_sleepable_preload+0x2fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2fdc;
	}
x86_l_2d6c:
	/* 0x2d6c: cmp    WORD PTR [rbx+0x17e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1640677507072ULL);
x86_l_2d74:
	/* 0x2d74: je     36f2 <generic_sleepable_preload+0x36f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14066ULL;
	}
x86_l_2d7a:
	/* 0x2d7a: mov    ecx,DWORD PTR [rbx+0x178] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 376ULL);
x86_l_2d80:
	/* 0x2d80: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2d84:
	/* 0x2d84: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d88:
	/* 0x2d88: cmp    WORD PTR [rbx+0x17c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1632087572480ULL);
x86_l_2d90:
	/* 0x2d90: je     2db2 <generic_sleepable_preload+0x2db2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2db2;
	}
x86_l_2d92:
	/* 0x2d92: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2d95:
	/* 0x2d95: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d9a:
	/* 0x2d9a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2d9f:
	/* 0x2d9f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
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
	/* 0x2dac: js     3048 <generic_sleepable_preload+0x3048> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3048;
	}
x86_l_2db2:
	/* 0x2db2: cmp    WORD PTR [rbx+0x186],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1675037245440ULL);
x86_l_2dba:
	/* 0x2dba: je     36f2 <generic_sleepable_preload+0x36f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14066ULL;
	}
x86_l_2dc0:
	/* 0x2dc0: mov    ecx,DWORD PTR [rbx+0x180] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 384ULL);
x86_l_2dc6:
	/* 0x2dc6: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2dca:
	/* 0x2dca: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dce:
	/* 0x2dce: cmp    WORD PTR [rbx+0x184],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1666447310848ULL);
x86_l_2dd6:
	/* 0x2dd6: je     2df8 <generic_sleepable_preload+0x2df8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2df8;
	}
x86_l_2dd8:
	/* 0x2dd8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ddb:
	/* 0x2ddb: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2de0:
	/* 0x2de0: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2de5:
	/* 0x2de5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2de9:
	/* 0x2de9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dee:
	/* 0x2dee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2df0:
	/* 0x2df0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2df2:
	/* 0x2df2: js     30b4 <generic_sleepable_preload+0x30b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_30b4;
	}
x86_l_2df8:
	/* 0x2df8: cmp    WORD PTR [rbx+0x18e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1709396983808ULL);
x86_l_2e00:
	/* 0x2e00: je     36f2 <generic_sleepable_preload+0x36f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14066ULL;
	}
x86_l_2e06:
	/* 0x2e06: mov    ecx,DWORD PTR [rbx+0x188] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 392ULL);
x86_l_2e0c:
	/* 0x2e0c: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2e10:
	/* 0x2e10: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e14:
	/* 0x2e14: cmp    WORD PTR [rbx+0x18c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1700807049216ULL);
x86_l_2e1c:
	/* 0x2e1c: je     2e3e <generic_sleepable_preload+0x2e3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e3e;
	}
x86_l_2e1e:
	/* 0x2e1e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2e21:
	/* 0x2e21: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e26:
	/* 0x2e26: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2e2b:
	/* 0x2e2b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e2f:
	/* 0x2e2f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e34:
	/* 0x2e34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e36:
	/* 0x2e36: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e38:
	/* 0x2e38: js     311d <generic_sleepable_preload+0x311d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_311d;
	}
x86_l_2e3e:
	/* 0x2e3e: cmp    WORD PTR [rbx+0x196],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1743756722176ULL);
x86_l_2e46:
	/* 0x2e46: je     36f2 <generic_sleepable_preload+0x36f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14066ULL;
	}
x86_l_2e4c:
	/* 0x2e4c: mov    ecx,DWORD PTR [rbx+0x190] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 400ULL);
x86_l_2e52:
	/* 0x2e52: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2e56:
	/* 0x2e56: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e5a:
	/* 0x2e5a: cmp    WORD PTR [rbx+0x194],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1735166787584ULL);
x86_l_2e62:
	/* 0x2e62: je     2e84 <generic_sleepable_preload+0x2e84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e84;
	}
x86_l_2e64:
	/* 0x2e64: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2e67:
	/* 0x2e67: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e6c:
	/* 0x2e6c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2e71:
	/* 0x2e71: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e75:
	/* 0x2e75: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e7a:
	/* 0x2e7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e7c:
	/* 0x2e7c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e7e:
	/* 0x2e7e: js     36ea <generic_sleepable_preload+0x36ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14058ULL;
	}
x86_l_2e84:
	/* 0x2e84: cmp    WORD PTR [rbx+0x19e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1778116460544ULL);
x86_l_2e8c:
	/* 0x2e8c: je     36f2 <generic_sleepable_preload+0x36f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14066ULL;
	}
x86_l_2e92:
	/* 0x2e92: mov    ecx,DWORD PTR [rbx+0x198] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 408ULL);
x86_l_2e98:
	/* 0x2e98: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2e9c:
	/* 0x2e9c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ea0:
	/* 0x2ea0: cmp    WORD PTR [rbx+0x19c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1769526525952ULL);
x86_l_2ea8:
	/* 0x2ea8: je     2eca <generic_sleepable_preload+0x2eca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2eca;
	}
x86_l_2eaa:
	/* 0x2eaa: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ead:
	/* 0x2ead: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2eb2:
	/* 0x2eb2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2eb7:
	/* 0x2eb7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ebb:
	/* 0x2ebb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ec0:
	/* 0x2ec0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ec2:
	/* 0x2ec2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ec4:
	/* 0x2ec4: js     3846 <generic_sleepable_preload+0x3846> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14406ULL;
	}
x86_l_2eca:
	/* 0x2eca: cmp    WORD PTR [rbx+0x1a6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1812476198912ULL);
x86_l_2ed2:
	/* 0x2ed2: je     36f2 <generic_sleepable_preload+0x36f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14066ULL;
	}
x86_l_2ed8:
	/* 0x2ed8: mov    ecx,DWORD PTR [rbx+0x1a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 416ULL);
x86_l_2ede:
	/* 0x2ede: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2ee2:
	/* 0x2ee2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ee6:
	/* 0x2ee6: cmp    WORD PTR [rbx+0x1a4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1803886264320ULL);
x86_l_2eee:
	/* 0x2eee: je     2f10 <generic_sleepable_preload+0x2f10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f10;
	}
x86_l_2ef0:
	/* 0x2ef0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ef3:
	/* 0x2ef3: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ef8:
	/* 0x2ef8: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2efd:
	/* 0x2efd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f01:
	/* 0x2f01: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f06:
	/* 0x2f06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f08:
	/* 0x2f08: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f0a:
	/* 0x2f0a: js     38be <generic_sleepable_preload+0x38be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14526ULL;
	}
x86_l_2f10:
	/* 0x2f10: cmp    WORD PTR [rbx+0x1ae],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1846835937280ULL);
x86_l_2f18:
	/* 0x2f18: je     36f2 <generic_sleepable_preload+0x36f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14066ULL;
	}
x86_l_2f1e:
	/* 0x2f1e: mov    ecx,DWORD PTR [rbx+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_2f24:
	/* 0x2f24: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2f28:
	/* 0x2f28: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f2c:
	/* 0x2f2c: cmp    WORD PTR [rbx+0x1ac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1838246002688ULL);
x86_l_2f34:
	/* 0x2f34: je     36f2 <generic_sleepable_preload+0x36f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14066ULL;
	}
x86_l_2f3a:
	/* 0x2f3a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2f3d:
	/* 0x2f3d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f42:
	/* 0x2f42: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_2f47:
	/* 0x2f47: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f4b:
	/* 0x2f4b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f50:
	/* 0x2f50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f52:
	/* 0x2f52: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f54:
	/* 0x2f54: jns    36f2 <generic_sleepable_preload+0x36f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 14066ULL;
	}
x86_l_2f5a:
	/* 0x2f5a: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_2f60:
	/* 0x2f60: jmp    36f0 <generic_sleepable_preload+0x36f0> */
	return 14064ULL;
x86_l_2f65:
	/* 0x2f65: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_2f6b:
	/* 0x2f6b: jmp    36f0 <generic_sleepable_preload+0x36f0> */
	return 14064ULL;
x86_l_2f70:
	/* 0x2f70: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_2f76:
	/* 0x2f76: jmp    36f0 <generic_sleepable_preload+0x36f0> */
	return 14064ULL;
x86_l_2f7b:
	/* 0x2f7b: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_2f81:
	/* 0x2f81: jmp    312e <generic_sleepable_preload+0x312e> */
	goto x86_l_312e;
x86_l_2f86:
	/* 0x2f86: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_2f8c:
	/* 0x2f8c: jmp    31c4 <generic_sleepable_preload+0x31c4> */
	goto x86_l_31c4;
x86_l_2f91:
	/* 0x2f91: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_2f97:
	/* 0x2f97: jmp    3257 <generic_sleepable_preload+0x3257> */
	return 12887ULL;
x86_l_2f9c:
	/* 0x2f9c: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_2fa2:
	/* 0x2fa2: jmp    32ea <generic_sleepable_preload+0x32ea> */
	return 13034ULL;
x86_l_2fa7:
	/* 0x2fa7: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2fac:
	/* 0x2fac: jmp    337c <generic_sleepable_preload+0x337c> */
	return 13180ULL;
x86_l_2fb1:
	/* 0x2fb1: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_2fb7:
	/* 0x2fb7: jmp    3406 <generic_sleepable_preload+0x3406> */
	return 13318ULL;
x86_l_2fbc:
	/* 0x2fbc: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2fc1:
	/* 0x2fc1: jmp    34c1 <generic_sleepable_preload+0x34c1> */
	return 13505ULL;
x86_l_2fc6:
	/* 0x2fc6: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_2fcc:
	/* 0x2fcc: jmp    3572 <generic_sleepable_preload+0x3572> */
	return 13682ULL;
x86_l_2fd1:
	/* 0x2fd1: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_2fd7:
	/* 0x2fd7: jmp    3631 <generic_sleepable_preload+0x3631> */
	return 13873ULL;
x86_l_2fdc:
	/* 0x2fdc: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_2fe2:
	/* 0x2fe2: jmp    36f0 <generic_sleepable_preload+0x36f0> */
	return 14064ULL;
x86_l_2fe7:
	/* 0x2fe7: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_2fed:
	/* 0x2fed: jmp    312e <generic_sleepable_preload+0x312e> */
	goto x86_l_312e;
x86_l_2ff2:
	/* 0x2ff2: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2ff8:
	/* 0x2ff8: jmp    31c4 <generic_sleepable_preload+0x31c4> */
	goto x86_l_31c4;
x86_l_2ffd:
	/* 0x2ffd: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_3003:
	/* 0x3003: jmp    3257 <generic_sleepable_preload+0x3257> */
	return 12887ULL;
x86_l_3008:
	/* 0x3008: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_300e:
	/* 0x300e: jmp    32ea <generic_sleepable_preload+0x32ea> */
	return 13034ULL;
x86_l_3013:
	/* 0x3013: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_3018:
	/* 0x3018: jmp    337c <generic_sleepable_preload+0x337c> */
	return 13180ULL;
x86_l_301d:
	/* 0x301d: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_3023:
	/* 0x3023: jmp    3406 <generic_sleepable_preload+0x3406> */
	return 13318ULL;
x86_l_3028:
	/* 0x3028: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_302d:
	/* 0x302d: jmp    34c1 <generic_sleepable_preload+0x34c1> */
	return 13505ULL;
x86_l_3032:
	/* 0x3032: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_3038:
	/* 0x3038: jmp    3572 <generic_sleepable_preload+0x3572> */
	return 13682ULL;
x86_l_303d:
	/* 0x303d: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_3043:
	/* 0x3043: jmp    3631 <generic_sleepable_preload+0x3631> */
	return 13873ULL;
x86_l_3048:
	/* 0x3048: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_304e:
	/* 0x304e: jmp    36f0 <generic_sleepable_preload+0x36f0> */
	return 14064ULL;
x86_l_3053:
	/* 0x3053: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_3059:
	/* 0x3059: jmp    312e <generic_sleepable_preload+0x312e> */
	goto x86_l_312e;
x86_l_305e:
	/* 0x305e: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_3064:
	/* 0x3064: jmp    31c4 <generic_sleepable_preload+0x31c4> */
	goto x86_l_31c4;
x86_l_3069:
	/* 0x3069: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_306f:
	/* 0x306f: jmp    3257 <generic_sleepable_preload+0x3257> */
	return 12887ULL;
x86_l_3074:
	/* 0x3074: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_307a:
	/* 0x307a: jmp    32ea <generic_sleepable_preload+0x32ea> */
	return 13034ULL;
x86_l_307f:
	/* 0x307f: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_3084:
	/* 0x3084: jmp    337c <generic_sleepable_preload+0x337c> */
	return 13180ULL;
x86_l_3089:
	/* 0x3089: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_308f:
	/* 0x308f: jmp    3406 <generic_sleepable_preload+0x3406> */
	return 13318ULL;
x86_l_3094:
	/* 0x3094: mov    ebp,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_3099:
	/* 0x3099: jmp    34c1 <generic_sleepable_preload+0x34c1> */
	return 13505ULL;
x86_l_309e:
	/* 0x309e: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_30a4:
	/* 0x30a4: jmp    3572 <generic_sleepable_preload+0x3572> */
	return 13682ULL;
x86_l_30a9:
	/* 0x30a9: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_30af:
	/* 0x30af: jmp    3631 <generic_sleepable_preload+0x3631> */
	return 13873ULL;
x86_l_30b4:
	/* 0x30b4: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_30ba:
	/* 0x30ba: jmp    36f0 <generic_sleepable_preload+0x36f0> */
	return 14064ULL;
x86_l_30bf:
	/* 0x30bf: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_30c5:
	/* 0x30c5: jmp    312e <generic_sleepable_preload+0x312e> */
	goto x86_l_312e;
x86_l_30c7:
	/* 0x30c7: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_30cd:
	/* 0x30cd: jmp    31c4 <generic_sleepable_preload+0x31c4> */
	goto x86_l_31c4;
x86_l_30d2:
	/* 0x30d2: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_30d8:
	/* 0x30d8: jmp    3257 <generic_sleepable_preload+0x3257> */
	return 12887ULL;
x86_l_30dd:
	/* 0x30dd: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_30e3:
	/* 0x30e3: jmp    32ea <generic_sleepable_preload+0x32ea> */
	return 13034ULL;
x86_l_30e8:
	/* 0x30e8: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_30ed:
	/* 0x30ed: jmp    337c <generic_sleepable_preload+0x337c> */
	return 13180ULL;
x86_l_30f2:
	/* 0x30f2: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_30f8:
	/* 0x30f8: jmp    3406 <generic_sleepable_preload+0x3406> */
	return 13318ULL;
x86_l_30fd:
	/* 0x30fd: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_3102:
	/* 0x3102: jmp    34c1 <generic_sleepable_preload+0x34c1> */
	return 13505ULL;
x86_l_3107:
	/* 0x3107: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_310d:
	/* 0x310d: jmp    3572 <generic_sleepable_preload+0x3572> */
	return 13682ULL;
x86_l_3112:
	/* 0x3112: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_3118:
	/* 0x3118: jmp    3631 <generic_sleepable_preload+0x3631> */
	return 13873ULL;
x86_l_311d:
	/* 0x311d: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_3123:
	/* 0x3123: jmp    36f0 <generic_sleepable_preload+0x36f0> */
	return 14064ULL;
x86_l_3128:
	/* 0x3128: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_312e:
	/* 0x312e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3130:
	/* 0x3130: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3134:
	/* 0x3134: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3139:
	/* 0x3139: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_313e:
	/* 0x313e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3143:
	/* 0x3143: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3148:
	/* 0x3148: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_314b:
	/* 0x314b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_314d:
	/* 0x314d: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_3151:
	/* 0x3151: jne    ed <generic_sleepable_preload+0xed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 237ULL;
	}
x86_l_3157:
	/* 0x3157: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_315c:
	/* 0x315c: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3161:
	/* 0x3161: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3166:
	/* 0x3166: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3168:
	/* 0x3168: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_316d:
	/* 0x316d: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3174:
	/* 0x3174: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_317b:
	/* 0x317b: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_317e:
	/* 0x317e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3183:
	/* 0x3183: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3185:
	/* 0x3185: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3188:
	/* 0x3188: je     ed <generic_sleepable_preload+0xed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 237ULL;
	}
x86_l_318e:
	/* 0x318e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3191:
	/* 0x3191: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_3194:
	/* 0x3194: mov    ebp,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_32);
x86_l_3197:
	/* 0x3197: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_319e:
	/* 0x319e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31a0:
	/* 0x31a0: lea    r13,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31a5:
	/* 0x31a5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_31aa:
	/* 0x31aa: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_31ad:
	/* 0x31ad: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_31b0:
	/* 0x31b0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31b2:
	/* 0x31b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31b4:
	/* 0x31b4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31b9:
	/* 0x31b9: jmp    3476 <generic_sleepable_preload+0x3476> */
	return 13430ULL;
x86_l_31be:
	/* 0x31be: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_31c4:
	/* 0x31c4: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31c6:
	/* 0x31c6: mov    r15d,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31ca:
	/* 0x31ca: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31cf:
	/* 0x31cf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31d4:
	/* 0x31d4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31d9:
	/* 0x31d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31de:
	/* 0x31de: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_31e1:
	/* 0x31e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31e3:
	/* 0x31e3: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_31e7:
	/* 0x31e7: jne    fb <generic_sleepable_preload+0xfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 251ULL;
	}
x86_l_31ed:
	/* 0x31ed: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31f2:
	/* 0x31f2: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31f7:
	/* 0x31f7: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
	return 12796ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12796ULL: goto x86_l_31fc;
	case 12798ULL: goto x86_l_31fe;
	case 12803ULL: goto x86_l_3203;
	case 12810ULL: goto x86_l_320a;
	case 12817ULL: goto x86_l_3211;
	case 12820ULL: goto x86_l_3214;
	case 12825ULL: goto x86_l_3219;
	case 12827ULL: goto x86_l_321b;
	case 12830ULL: goto x86_l_321e;
	case 12836ULL: goto x86_l_3224;
	case 12839ULL: goto x86_l_3227;
	case 12846ULL: goto x86_l_322e;
	case 12848ULL: goto x86_l_3230;
	case 12851ULL: goto x86_l_3233;
	case 12856ULL: goto x86_l_3238;
	case 12861ULL: goto x86_l_323d;
	case 12864ULL: goto x86_l_3240;
	case 12867ULL: goto x86_l_3243;
	case 12869ULL: goto x86_l_3245;
	case 12871ULL: goto x86_l_3247;
	case 12876ULL: goto x86_l_324c;
	case 12881ULL: goto x86_l_3251;
	case 12887ULL: goto x86_l_3257;
	case 12889ULL: goto x86_l_3259;
	case 12893ULL: goto x86_l_325d;
	case 12898ULL: goto x86_l_3262;
	case 12903ULL: goto x86_l_3267;
	case 12908ULL: goto x86_l_326c;
	case 12913ULL: goto x86_l_3271;
	case 12916ULL: goto x86_l_3274;
	case 12918ULL: goto x86_l_3276;
	case 12922ULL: goto x86_l_327a;
	case 12928ULL: goto x86_l_3280;
	case 12933ULL: goto x86_l_3285;
	case 12938ULL: goto x86_l_328a;
	case 12943ULL: goto x86_l_328f;
	case 12945ULL: goto x86_l_3291;
	case 12950ULL: goto x86_l_3296;
	case 12957ULL: goto x86_l_329d;
	case 12964ULL: goto x86_l_32a4;
	case 12967ULL: goto x86_l_32a7;
	case 12972ULL: goto x86_l_32ac;
	case 12974ULL: goto x86_l_32ae;
	case 12977ULL: goto x86_l_32b1;
	case 12983ULL: goto x86_l_32b7;
	case 12986ULL: goto x86_l_32ba;
	case 12993ULL: goto x86_l_32c1;
	case 12995ULL: goto x86_l_32c3;
	case 12998ULL: goto x86_l_32c6;
	case 13003ULL: goto x86_l_32cb;
	case 13008ULL: goto x86_l_32d0;
	case 13011ULL: goto x86_l_32d3;
	case 13014ULL: goto x86_l_32d6;
	case 13016ULL: goto x86_l_32d8;
	case 13018ULL: goto x86_l_32da;
	case 13023ULL: goto x86_l_32df;
	case 13028ULL: goto x86_l_32e4;
	case 13034ULL: goto x86_l_32ea;
	case 13036ULL: goto x86_l_32ec;
	case 13040ULL: goto x86_l_32f0;
	case 13045ULL: goto x86_l_32f5;
	case 13050ULL: goto x86_l_32fa;
	case 13055ULL: goto x86_l_32ff;
	case 13060ULL: goto x86_l_3304;
	case 13063ULL: goto x86_l_3307;
	case 13065ULL: goto x86_l_3309;
	case 13069ULL: goto x86_l_330d;
	case 13075ULL: goto x86_l_3313;
	case 13080ULL: goto x86_l_3318;
	case 13085ULL: goto x86_l_331d;
	case 13090ULL: goto x86_l_3322;
	case 13092ULL: goto x86_l_3324;
	case 13097ULL: goto x86_l_3329;
	case 13104ULL: goto x86_l_3330;
	case 13111ULL: goto x86_l_3337;
	case 13114ULL: goto x86_l_333a;
	case 13119ULL: goto x86_l_333f;
	case 13121ULL: goto x86_l_3341;
	case 13124ULL: goto x86_l_3344;
	case 13130ULL: goto x86_l_334a;
	case 13133ULL: goto x86_l_334d;
	case 13140ULL: goto x86_l_3354;
	case 13142ULL: goto x86_l_3356;
	case 13145ULL: goto x86_l_3359;
	case 13150ULL: goto x86_l_335e;
	case 13155ULL: goto x86_l_3363;
	case 13158ULL: goto x86_l_3366;
	case 13161ULL: goto x86_l_3369;
	case 13163ULL: goto x86_l_336b;
	case 13165ULL: goto x86_l_336d;
	case 13170ULL: goto x86_l_3372;
	case 13175ULL: goto x86_l_3377;
	case 13180ULL: goto x86_l_337c;
	case 13183ULL: goto x86_l_337f;
	case 13186ULL: goto x86_l_3382;
	case 13191ULL: goto x86_l_3387;
	case 13196ULL: goto x86_l_338c;
	case 13201ULL: goto x86_l_3391;
	case 13206ULL: goto x86_l_3396;
	case 13209ULL: goto x86_l_3399;
	case 13211ULL: goto x86_l_339b;
	case 13214ULL: goto x86_l_339e;
	case 13220ULL: goto x86_l_33a4;
	case 13225ULL: goto x86_l_33a9;
	case 13230ULL: goto x86_l_33ae;
	case 13232ULL: goto x86_l_33b0;
	case 13237ULL: goto x86_l_33b5;
	case 13244ULL: goto x86_l_33bc;
	case 13251ULL: goto x86_l_33c3;
	case 13254ULL: goto x86_l_33c6;
	case 13259ULL: goto x86_l_33cb;
	case 13261ULL: goto x86_l_33cd;
	case 13264ULL: goto x86_l_33d0;
	case 13270ULL: goto x86_l_33d6;
	case 13273ULL: goto x86_l_33d9;
	case 13280ULL: goto x86_l_33e0;
	case 13282ULL: goto x86_l_33e2;
	case 13287ULL: goto x86_l_33e7;
	case 13292ULL: goto x86_l_33ec;
	case 13295ULL: goto x86_l_33ef;
	case 13298ULL: goto x86_l_33f2;
	case 13300ULL: goto x86_l_33f4;
	case 13302ULL: goto x86_l_33f6;
	case 13307ULL: goto x86_l_33fb;
	case 13312ULL: goto x86_l_3400;
	case 13318ULL: goto x86_l_3406;
	case 13320ULL: goto x86_l_3408;
	case 13324ULL: goto x86_l_340c;
	case 13330ULL: goto x86_l_3412;
	case 13334ULL: goto x86_l_3416;
	case 13339ULL: goto x86_l_341b;
	case 13344ULL: goto x86_l_3420;
	case 13346ULL: goto x86_l_3422;
	case 13351ULL: goto x86_l_3427;
	case 13359ULL: goto x86_l_342f;
	case 13366ULL: goto x86_l_3436;
	case 13371ULL: goto x86_l_343b;
	case 13376ULL: goto x86_l_3440;
	case 13378ULL: goto x86_l_3442;
	case 13381ULL: goto x86_l_3445;
	case 13387ULL: goto x86_l_344b;
	case 13390ULL: goto x86_l_344e;
	case 13393ULL: goto x86_l_3451;
	case 13396ULL: goto x86_l_3454;
	case 13403ULL: goto x86_l_345b;
	case 13405ULL: goto x86_l_345d;
	case 13410ULL: goto x86_l_3462;
	case 13415ULL: goto x86_l_3467;
	case 13418ULL: goto x86_l_346a;
	case 13421ULL: goto x86_l_346d;
	case 13423ULL: goto x86_l_346f;
	case 13425ULL: goto x86_l_3471;
	case 13430ULL: goto x86_l_3476;
	case 13433ULL: goto x86_l_3479;
	case 13436ULL: goto x86_l_347c;
	case 13438ULL: goto x86_l_347e;
	case 13441ULL: goto x86_l_3481;
	case 13447ULL: goto x86_l_3487;
	case 13450ULL: goto x86_l_348a;
	case 13452ULL: goto x86_l_348c;
	case 13455ULL: goto x86_l_348f;
	case 13459ULL: goto x86_l_3493;
	case 13464ULL: goto x86_l_3498;
	case 13469ULL: goto x86_l_349d;
	case 13471ULL: goto x86_l_349f;
	case 13474ULL: goto x86_l_34a2;
	case 13479ULL: goto x86_l_34a7;
	case 13481ULL: goto x86_l_34a9;
	case 13484ULL: goto x86_l_34ac;
	case 13486ULL: goto x86_l_34ae;
	case 13488ULL: goto x86_l_34b0;
	case 13493ULL: goto x86_l_34b5;
	case 13495ULL: goto x86_l_34b7;
	case 13500ULL: goto x86_l_34bc;
	case 13505ULL: goto x86_l_34c1;
	case 13508ULL: goto x86_l_34c4;
	case 13512ULL: goto x86_l_34c8;
	case 13518ULL: goto x86_l_34ce;
	case 13522ULL: goto x86_l_34d2;
	case 13527ULL: goto x86_l_34d7;
	case 13529ULL: goto x86_l_34d9;
	case 13534ULL: goto x86_l_34de;
	case 13542ULL: goto x86_l_34e6;
	case 13549ULL: goto x86_l_34ed;
	case 13554ULL: goto x86_l_34f2;
	case 13559ULL: goto x86_l_34f7;
	case 13561ULL: goto x86_l_34f9;
	case 13564ULL: goto x86_l_34fc;
	case 13570ULL: goto x86_l_3502;
	case 13573ULL: goto x86_l_3505;
	case 13580ULL: goto x86_l_350c;
	case 13582ULL: goto x86_l_350e;
	case 13587ULL: goto x86_l_3513;
	case 13592ULL: goto x86_l_3518;
	case 13595ULL: goto x86_l_351b;
	case 13598ULL: goto x86_l_351e;
	case 13600ULL: goto x86_l_3520;
	case 13602ULL: goto x86_l_3522;
	case 13607ULL: goto x86_l_3527;
	case 13610ULL: goto x86_l_352a;
	case 13613ULL: goto x86_l_352d;
	case 13615ULL: goto x86_l_352f;
	case 13618ULL: goto x86_l_3532;
	case 13624ULL: goto x86_l_3538;
	case 13627ULL: goto x86_l_353b;
	case 13629ULL: goto x86_l_353d;
	case 13632ULL: goto x86_l_3540;
	case 13636ULL: goto x86_l_3544;
	case 13641ULL: goto x86_l_3549;
	case 13644ULL: goto x86_l_354c;
	case 13646ULL: goto x86_l_354e;
	case 13649ULL: goto x86_l_3551;
	case 13654ULL: goto x86_l_3556;
	case 13656ULL: goto x86_l_3558;
	case 13659ULL: goto x86_l_355b;
	case 13661ULL: goto x86_l_355d;
	case 13666ULL: goto x86_l_3562;
	case 13669ULL: goto x86_l_3565;
	case 13671ULL: goto x86_l_3567;
	case 13676ULL: goto x86_l_356c;
	case 13682ULL: goto x86_l_3572;
	case 13684ULL: goto x86_l_3574;
	case 13688ULL: goto x86_l_3578;
	case 13694ULL: goto x86_l_357e;
	case 13698ULL: goto x86_l_3582;
	case 13703ULL: goto x86_l_3587;
	case 13708ULL: goto x86_l_358c;
	case 13710ULL: goto x86_l_358e;
	case 13715ULL: goto x86_l_3593;
	case 13723ULL: goto x86_l_359b;
	case 13730ULL: goto x86_l_35a2;
	case 13735ULL: goto x86_l_35a7;
	case 13740ULL: goto x86_l_35ac;
	case 13742ULL: goto x86_l_35ae;
	case 13745ULL: goto x86_l_35b1;
	case 13751ULL: goto x86_l_35b7;
	case 13754ULL: goto x86_l_35ba;
	case 13761ULL: goto x86_l_35c1;
	case 13763ULL: goto x86_l_35c3;
	case 13766ULL: goto x86_l_35c6;
	case 13771ULL: goto x86_l_35cb;
	case 13776ULL: goto x86_l_35d0;
	case 13779ULL: goto x86_l_35d3;
	case 13782ULL: goto x86_l_35d6;
	case 13784ULL: goto x86_l_35d8;
	case 13786ULL: goto x86_l_35da;
	case 13791ULL: goto x86_l_35df;
	case 13794ULL: goto x86_l_35e2;
	case 13797ULL: goto x86_l_35e5;
	case 13800ULL: goto x86_l_35e8;
	case 13802ULL: goto x86_l_35ea;
	case 13805ULL: goto x86_l_35ed;
	case 13811ULL: goto x86_l_35f3;
	case 13814ULL: goto x86_l_35f6;
	case 13816ULL: goto x86_l_35f8;
	case 13819ULL: goto x86_l_35fb;
	case 13823ULL: goto x86_l_35ff;
	case 13828ULL: goto x86_l_3604;
	case 13833ULL: goto x86_l_3609;
	case 13835ULL: goto x86_l_360b;
	case 13838ULL: goto x86_l_360e;
	case 13843ULL: goto x86_l_3613;
	case 13845ULL: goto x86_l_3615;
	case 13848ULL: goto x86_l_3618;
	case 13850ULL: goto x86_l_361a;
	case 13855ULL: goto x86_l_361f;
	case 13859ULL: goto x86_l_3623;
	case 13862ULL: goto x86_l_3626;
	case 13867ULL: goto x86_l_362b;
	case 13873ULL: goto x86_l_3631;
	case 13875ULL: goto x86_l_3633;
	case 13879ULL: goto x86_l_3637;
	case 13885ULL: goto x86_l_363d;
	case 13889ULL: goto x86_l_3641;
	case 13894ULL: goto x86_l_3646;
	case 13899ULL: goto x86_l_364b;
	case 13901ULL: goto x86_l_364d;
	case 13906ULL: goto x86_l_3652;
	case 13914ULL: goto x86_l_365a;
	case 13921ULL: goto x86_l_3661;
	case 13926ULL: goto x86_l_3666;
	case 13931ULL: goto x86_l_366b;
	case 13933ULL: goto x86_l_366d;
	case 13936ULL: goto x86_l_3670;
	case 13942ULL: goto x86_l_3676;
	case 13945ULL: goto x86_l_3679;
	case 13952ULL: goto x86_l_3680;
	case 13954ULL: goto x86_l_3682;
	case 13957ULL: goto x86_l_3685;
	case 13962ULL: goto x86_l_368a;
	case 13967ULL: goto x86_l_368f;
	case 13970ULL: goto x86_l_3692;
	case 13973ULL: goto x86_l_3695;
	case 13975ULL: goto x86_l_3697;
	case 13977ULL: goto x86_l_3699;
	case 13982ULL: goto x86_l_369e;
	case 13985ULL: goto x86_l_36a1;
	case 13988ULL: goto x86_l_36a4;
	case 13991ULL: goto x86_l_36a7;
	case 13993ULL: goto x86_l_36a9;
	case 13996ULL: goto x86_l_36ac;
	case 14002ULL: goto x86_l_36b2;
	case 14005ULL: goto x86_l_36b5;
	case 14007ULL: goto x86_l_36b7;
	case 14010ULL: goto x86_l_36ba;
	case 14014ULL: goto x86_l_36be;
	case 14019ULL: goto x86_l_36c3;
	case 14024ULL: goto x86_l_36c8;
	case 14026ULL: goto x86_l_36ca;
	case 14029ULL: goto x86_l_36cd;
	case 14034ULL: goto x86_l_36d2;
	case 14036ULL: goto x86_l_36d4;
	case 14039ULL: goto x86_l_36d7;
	case 14041ULL: goto x86_l_36d9;
	case 14046ULL: goto x86_l_36de;
	case 14050ULL: goto x86_l_36e2;
	case 14053ULL: goto x86_l_36e5;
	case 14058ULL: goto x86_l_36ea;
	case 14064ULL: goto x86_l_36f0;
	case 14066ULL: goto x86_l_36f2;
	case 14070ULL: goto x86_l_36f6;
	case 14076ULL: goto x86_l_36fc;
	case 14080ULL: goto x86_l_3700;
	case 14085ULL: goto x86_l_3705;
	case 14090ULL: goto x86_l_370a;
	case 14092ULL: goto x86_l_370c;
	case 14097ULL: goto x86_l_3711;
	case 14105ULL: goto x86_l_3719;
	case 14112ULL: goto x86_l_3720;
	case 14117ULL: goto x86_l_3725;
	case 14122ULL: goto x86_l_372a;
	case 14124ULL: goto x86_l_372c;
	case 14127ULL: goto x86_l_372f;
	case 14133ULL: goto x86_l_3735;
	case 14136ULL: goto x86_l_3738;
	case 14143ULL: goto x86_l_373f;
	case 14145ULL: goto x86_l_3741;
	case 14148ULL: goto x86_l_3744;
	case 14153ULL: goto x86_l_3749;
	case 14158ULL: goto x86_l_374e;
	case 14161ULL: goto x86_l_3751;
	case 14164ULL: goto x86_l_3754;
	case 14166ULL: goto x86_l_3756;
	case 14168ULL: goto x86_l_3758;
	case 14173ULL: goto x86_l_375d;
	case 14176ULL: goto x86_l_3760;
	case 14179ULL: goto x86_l_3763;
	case 14182ULL: goto x86_l_3766;
	case 14184ULL: goto x86_l_3768;
	case 14187ULL: goto x86_l_376b;
	case 14193ULL: goto x86_l_3771;
	case 14196ULL: goto x86_l_3774;
	case 14198ULL: goto x86_l_3776;
	case 14201ULL: goto x86_l_3779;
	case 14205ULL: goto x86_l_377d;
	case 14210ULL: goto x86_l_3782;
	case 14215ULL: goto x86_l_3787;
	case 14217ULL: goto x86_l_3789;
	case 14220ULL: goto x86_l_378c;
	case 14225ULL: goto x86_l_3791;
	case 14227ULL: goto x86_l_3793;
	case 14230ULL: goto x86_l_3796;
	case 14232ULL: goto x86_l_3798;
	case 14237ULL: goto x86_l_379d;
	case 14241ULL: goto x86_l_37a1;
	case 14244ULL: goto x86_l_37a4;
	case 14249ULL: goto x86_l_37a9;
	case 14251ULL: goto x86_l_37ab;
	case 14257ULL: goto x86_l_37b1;
	case 14262ULL: goto x86_l_37b6;
	case 14264ULL: goto x86_l_37b8;
	case 14270ULL: goto x86_l_37be;
	case 14275ULL: goto x86_l_37c3;
	case 14277ULL: goto x86_l_37c5;
	case 14283ULL: goto x86_l_37cb;
	case 14288ULL: goto x86_l_37d0;
	case 14290ULL: goto x86_l_37d2;
	case 14296ULL: goto x86_l_37d8;
	case 14301ULL: goto x86_l_37dd;
	case 14304ULL: goto x86_l_37e0;
	case 14309ULL: goto x86_l_37e5;
	case 14314ULL: goto x86_l_37ea;
	case 14316ULL: goto x86_l_37ec;
	case 14322ULL: goto x86_l_37f2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_31fc:
	/* 0x31fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31fe:
	/* 0x31fe: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3203:
	/* 0x3203: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_320a:
	/* 0x320a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3211:
	/* 0x3211: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_3214:
	/* 0x3214: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3219:
	/* 0x3219: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_321b:
	/* 0x321b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_321e:
	/* 0x321e: je     fb <generic_sleepable_preload+0xfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 251ULL;
	}
x86_l_3224:
	/* 0x3224: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3227:
	/* 0x3227: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_322e:
	/* 0x322e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3230:
	/* 0x3230: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_3233:
	/* 0x3233: lea    r13,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3238:
	/* 0x3238: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_323d:
	/* 0x323d: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3240:
	/* 0x3240: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3243:
	/* 0x3243: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3245:
	/* 0x3245: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3247:
	/* 0x3247: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_324c:
	/* 0x324c: jmp    35df <generic_sleepable_preload+0x35df> */
	goto x86_l_35df;
x86_l_3251:
	/* 0x3251: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_3257:
	/* 0x3257: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3259:
	/* 0x3259: mov    r15d,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_325d:
	/* 0x325d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3262:
	/* 0x3262: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3267:
	/* 0x3267: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_326c:
	/* 0x326c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3271:
	/* 0x3271: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_3274:
	/* 0x3274: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3276:
	/* 0x3276: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_327a:
	/* 0x327a: jne    109 <generic_sleepable_preload+0x109> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 265ULL;
	}
x86_l_3280:
	/* 0x3280: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3285:
	/* 0x3285: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_328a:
	/* 0x328a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_328f:
	/* 0x328f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3291:
	/* 0x3291: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3296:
	/* 0x3296: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_329d:
	/* 0x329d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_32a4:
	/* 0x32a4: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_32a7:
	/* 0x32a7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32ac:
	/* 0x32ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32ae:
	/* 0x32ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32b1:
	/* 0x32b1: je     109 <generic_sleepable_preload+0x109> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 265ULL;
	}
x86_l_32b7:
	/* 0x32b7: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_32ba:
	/* 0x32ba: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_32c1:
	/* 0x32c1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32c3:
	/* 0x32c3: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_32c6:
	/* 0x32c6: lea    r13,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32cb:
	/* 0x32cb: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_32d0:
	/* 0x32d0: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_32d3:
	/* 0x32d3: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_32d6:
	/* 0x32d6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32d8:
	/* 0x32d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32da:
	/* 0x32da: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32df:
	/* 0x32df: jmp    369e <generic_sleepable_preload+0x369e> */
	goto x86_l_369e;
x86_l_32e4:
	/* 0x32e4: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_32ea:
	/* 0x32ea: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32ec:
	/* 0x32ec: mov    r15d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32f0:
	/* 0x32f0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32f5:
	/* 0x32f5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_32fa:
	/* 0x32fa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32ff:
	/* 0x32ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3304:
	/* 0x3304: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_3307:
	/* 0x3307: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3309:
	/* 0x3309: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_330d:
	/* 0x330d: jne    117 <generic_sleepable_preload+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 279ULL;
	}
x86_l_3313:
	/* 0x3313: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3318:
	/* 0x3318: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_331d:
	/* 0x331d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3322:
	/* 0x3322: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3324:
	/* 0x3324: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3329:
	/* 0x3329: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3330:
	/* 0x3330: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3337:
	/* 0x3337: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_333a:
	/* 0x333a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_333f:
	/* 0x333f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3341:
	/* 0x3341: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3344:
	/* 0x3344: je     117 <generic_sleepable_preload+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 279ULL;
	}
x86_l_334a:
	/* 0x334a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_334d:
	/* 0x334d: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3354:
	/* 0x3354: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3356:
	/* 0x3356: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_3359:
	/* 0x3359: lea    r13,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_335e:
	/* 0x335e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3363:
	/* 0x3363: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3366:
	/* 0x3366: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3369:
	/* 0x3369: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_336b:
	/* 0x336b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_336d:
	/* 0x336d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3372:
	/* 0x3372: jmp    375d <generic_sleepable_preload+0x375d> */
	goto x86_l_375d;
x86_l_3377:
	/* 0x3377: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_337c:
	/* 0x337c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_337f:
	/* 0x337f: mov    ebx,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3382:
	/* 0x3382: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3387:
	/* 0x3387: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_338c:
	/* 0x338c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3391:
	/* 0x3391: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3396:
	/* 0x3396: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_3399:
	/* 0x3399: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_339b:
	/* 0x339b: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_339e:
	/* 0x339e: jne    125 <generic_sleepable_preload+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 293ULL;
	}
x86_l_33a4:
	/* 0x33a4: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33a9:
	/* 0x33a9: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_33ae:
	/* 0x33ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33b0:
	/* 0x33b0: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33b5:
	/* 0x33b5: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33bc:
	/* 0x33bc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_33c3:
	/* 0x33c3: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_33c6:
	/* 0x33c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33cb:
	/* 0x33cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33cd:
	/* 0x33cd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33d0:
	/* 0x33d0: je     125 <generic_sleepable_preload+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 293ULL;
	}
x86_l_33d6:
	/* 0x33d6: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_33d9:
	/* 0x33d9: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_33e0:
	/* 0x33e0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33e2:
	/* 0x33e2: lea    r15,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33e7:
	/* 0x33e7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_33ec:
	/* 0x33ec: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_33ef:
	/* 0x33ef: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_33f2:
	/* 0x33f2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33f4:
	/* 0x33f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33f6:
	/* 0x33f6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33fb:
	/* 0x33fb: jmp    3527 <generic_sleepable_preload+0x3527> */
	goto x86_l_3527;
x86_l_3400:
	/* 0x3400: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_3406:
	/* 0x3406: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3408:
	/* 0x3408: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_340c:
	/* 0x340c: jne    ed <generic_sleepable_preload+0xed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 237ULL;
	}
x86_l_3412:
	/* 0x3412: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3416:
	/* 0x3416: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_341b:
	/* 0x341b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3420:
	/* 0x3420: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3422:
	/* 0x3422: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3427:
	/* 0x3427: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_342f:
	/* 0x342f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3436:
	/* 0x3436: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_343b:
	/* 0x343b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3440:
	/* 0x3440: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3442:
	/* 0x3442: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3445:
	/* 0x3445: je     ed <generic_sleepable_preload+0xed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 237ULL;
	}
x86_l_344b:
	/* 0x344b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_344e:
	/* 0x344e: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_3451:
	/* 0x3451: mov    ebp,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_32);
x86_l_3454:
	/* 0x3454: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_345b:
	/* 0x345b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_345d:
	/* 0x345d: lea    r13,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3462:
	/* 0x3462: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3467:
	/* 0x3467: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_346a:
	/* 0x346a: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_346d:
	/* 0x346d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_346f:
	/* 0x346f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3471:
	/* 0x3471: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3476:
	/* 0x3476: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3479:
	/* 0x3479: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_347c:
	/* 0x347c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_347e:
	/* 0x347e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3481:
	/* 0x3481: je     ed <generic_sleepable_preload+0xed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 237ULL;
	}
x86_l_3487:
	/* 0x3487: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_348a:
	/* 0x348a: je     34b5 <generic_sleepable_preload+0x34b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34b5;
	}
x86_l_348c:
	/* 0x348c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_348f:
	/* 0x348f: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3493:
	/* 0x3493: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3498:
	/* 0x3498: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_349d:
	/* 0x349d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_349f:
	/* 0x349f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_34a2:
	/* 0x34a2: call   34a7 <generic_sleepable_preload+0x34a7> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_34a7:
	/* 0x34a7: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_34a9:
	/* 0x34a9: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_34ac:
	/* 0x34ac: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_34ae:
	/* 0x34ae: jns    34b5 <generic_sleepable_preload+0x34b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_34b5;
	}
x86_l_34b0:
	/* 0x34b0: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_34b5:
	/* 0x34b5: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34b7:
	/* 0x34b7: jmp    ed <generic_sleepable_preload+0xed> */
	return 237ULL;
x86_l_34bc:
	/* 0x34bc: mov    ebp,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_34c1:
	/* 0x34c1: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34c4:
	/* 0x34c4: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_34c8:
	/* 0x34c8: jne    125 <generic_sleepable_preload+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 293ULL;
	}
x86_l_34ce:
	/* 0x34ce: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34d2:
	/* 0x34d2: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_34d7:
	/* 0x34d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34d9:
	/* 0x34d9: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34de:
	/* 0x34de: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_34e6:
	/* 0x34e6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_34ed:
	/* 0x34ed: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34f2:
	/* 0x34f2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34f7:
	/* 0x34f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34f9:
	/* 0x34f9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_34fc:
	/* 0x34fc: je     125 <generic_sleepable_preload+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 293ULL;
	}
x86_l_3502:
	/* 0x3502: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3505:
	/* 0x3505: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_350c:
	/* 0x350c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_350e:
	/* 0x350e: lea    r15,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3513:
	/* 0x3513: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3518:
	/* 0x3518: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_351b:
	/* 0x351b: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_351e:
	/* 0x351e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3520:
	/* 0x3520: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3522:
	/* 0x3522: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3527:
	/* 0x3527: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_352a:
	/* 0x352a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_352d:
	/* 0x352d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_352f:
	/* 0x352f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3532:
	/* 0x3532: je     125 <generic_sleepable_preload+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 293ULL;
	}
x86_l_3538:
	/* 0x3538: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_353b:
	/* 0x353b: je     3565 <generic_sleepable_preload+0x3565> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3565;
	}
x86_l_353d:
	/* 0x353d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3540:
	/* 0x3540: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3544:
	/* 0x3544: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3549:
	/* 0x3549: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_354c:
	/* 0x354c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_354e:
	/* 0x354e: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3551:
	/* 0x3551: call   3556 <generic_sleepable_preload+0x3556> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_3556:
	/* 0x3556: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_3558:
	/* 0x3558: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_355b:
	/* 0x355b: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_355d:
	/* 0x355d: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_3562:
	/* 0x3562: cmovs  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_3565:
	/* 0x3565: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3567:
	/* 0x3567: jmp    125 <generic_sleepable_preload+0x125> */
	return 293ULL;
x86_l_356c:
	/* 0x356c: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_3572:
	/* 0x3572: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3574:
	/* 0x3574: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_3578:
	/* 0x3578: jne    fb <generic_sleepable_preload+0xfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 251ULL;
	}
x86_l_357e:
	/* 0x357e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3582:
	/* 0x3582: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3587:
	/* 0x3587: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_358c:
	/* 0x358c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_358e:
	/* 0x358e: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3593:
	/* 0x3593: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_359b:
	/* 0x359b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_35a2:
	/* 0x35a2: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35a7:
	/* 0x35a7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35ac:
	/* 0x35ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35ae:
	/* 0x35ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35b1:
	/* 0x35b1: je     fb <generic_sleepable_preload+0xfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 251ULL;
	}
x86_l_35b7:
	/* 0x35b7: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_35ba:
	/* 0x35ba: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_35c1:
	/* 0x35c1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35c3:
	/* 0x35c3: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_35c6:
	/* 0x35c6: lea    r13,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35cb:
	/* 0x35cb: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_35d0:
	/* 0x35d0: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_35d3:
	/* 0x35d3: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_35d6:
	/* 0x35d6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35d8:
	/* 0x35d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35da:
	/* 0x35da: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35df:
	/* 0x35df: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_35e2:
	/* 0x35e2: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_35e5:
	/* 0x35e5: mov    r12d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_32);
x86_l_35e8:
	/* 0x35e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35ea:
	/* 0x35ea: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35ed:
	/* 0x35ed: je     fb <generic_sleepable_preload+0xfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 251ULL;
	}
x86_l_35f3:
	/* 0x35f3: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_35f6:
	/* 0x35f6: je     3623 <generic_sleepable_preload+0x3623> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3623;
	}
x86_l_35f8:
	/* 0x35f8: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_35fb:
	/* 0x35fb: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_35ff:
	/* 0x35ff: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3604:
	/* 0x3604: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3609:
	/* 0x3609: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_360b:
	/* 0x360b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_360e:
	/* 0x360e: call   3613 <generic_sleepable_preload+0x3613> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_3613:
	/* 0x3613: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_3615:
	/* 0x3615: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_3618:
	/* 0x3618: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_361a:
	/* 0x361a: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_361f:
	/* 0x361f: cmovs  r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_3623:
	/* 0x3623: mov    DWORD PTR [rax],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3626:
	/* 0x3626: jmp    fb <generic_sleepable_preload+0xfb> */
	return 251ULL;
x86_l_362b:
	/* 0x362b: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_3631:
	/* 0x3631: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3633:
	/* 0x3633: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_3637:
	/* 0x3637: jne    109 <generic_sleepable_preload+0x109> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 265ULL;
	}
x86_l_363d:
	/* 0x363d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3641:
	/* 0x3641: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3646:
	/* 0x3646: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_364b:
	/* 0x364b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_364d:
	/* 0x364d: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3652:
	/* 0x3652: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_365a:
	/* 0x365a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3661:
	/* 0x3661: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3666:
	/* 0x3666: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_366b:
	/* 0x366b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_366d:
	/* 0x366d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3670:
	/* 0x3670: je     109 <generic_sleepable_preload+0x109> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 265ULL;
	}
x86_l_3676:
	/* 0x3676: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3679:
	/* 0x3679: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_3680:
	/* 0x3680: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3682:
	/* 0x3682: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_3685:
	/* 0x3685: lea    r13,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_368a:
	/* 0x368a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_368f:
	/* 0x368f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3692:
	/* 0x3692: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3695:
	/* 0x3695: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3697:
	/* 0x3697: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3699:
	/* 0x3699: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_369e:
	/* 0x369e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_36a1:
	/* 0x36a1: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_36a4:
	/* 0x36a4: mov    r12d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_32);
x86_l_36a7:
	/* 0x36a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36a9:
	/* 0x36a9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36ac:
	/* 0x36ac: je     109 <generic_sleepable_preload+0x109> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 265ULL;
	}
x86_l_36b2:
	/* 0x36b2: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_36b5:
	/* 0x36b5: je     36e2 <generic_sleepable_preload+0x36e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36e2;
	}
x86_l_36b7:
	/* 0x36b7: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_36ba:
	/* 0x36ba: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_36be:
	/* 0x36be: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_36c3:
	/* 0x36c3: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_36c8:
	/* 0x36c8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36ca:
	/* 0x36ca: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_36cd:
	/* 0x36cd: call   36d2 <generic_sleepable_preload+0x36d2> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_36d2:
	/* 0x36d2: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_36d4:
	/* 0x36d4: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_36d7:
	/* 0x36d7: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_36d9:
	/* 0x36d9: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_36de:
	/* 0x36de: cmovs  r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_36e2:
	/* 0x36e2: mov    DWORD PTR [rax],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36e5:
	/* 0x36e5: jmp    109 <generic_sleepable_preload+0x109> */
	return 265ULL;
x86_l_36ea:
	/* 0x36ea: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_36f0:
	/* 0x36f0: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36f2:
	/* 0x36f2: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_36f6:
	/* 0x36f6: jne    117 <generic_sleepable_preload+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 279ULL;
	}
x86_l_36fc:
	/* 0x36fc: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3700:
	/* 0x3700: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3705:
	/* 0x3705: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_370a:
	/* 0x370a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_370c:
	/* 0x370c: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3711:
	/* 0x3711: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3719:
	/* 0x3719: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_3720:
	/* 0x3720: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3725:
	/* 0x3725: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_372a:
	/* 0x372a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_372c:
	/* 0x372c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_372f:
	/* 0x372f: je     117 <generic_sleepable_preload+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 279ULL;
	}
x86_l_3735:
	/* 0x3735: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3738:
	/* 0x3738: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_373f:
	/* 0x373f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3741:
	/* 0x3741: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_3744:
	/* 0x3744: lea    r13,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3749:
	/* 0x3749: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_374e:
	/* 0x374e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3751:
	/* 0x3751: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3754:
	/* 0x3754: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3756:
	/* 0x3756: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3758:
	/* 0x3758: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_375d:
	/* 0x375d: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3760:
	/* 0x3760: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3763:
	/* 0x3763: mov    r12d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_32);
x86_l_3766:
	/* 0x3766: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3768:
	/* 0x3768: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_376b:
	/* 0x376b: je     117 <generic_sleepable_preload+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 279ULL;
	}
x86_l_3771:
	/* 0x3771: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_3774:
	/* 0x3774: je     37a1 <generic_sleepable_preload+0x37a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37a1;
	}
x86_l_3776:
	/* 0x3776: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3779:
	/* 0x3779: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_377d:
	/* 0x377d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3782:
	/* 0x3782: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3787:
	/* 0x3787: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3789:
	/* 0x3789: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_378c:
	/* 0x378c: call   3791 <generic_sleepable_preload+0x3791> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_3791:
	/* 0x3791: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_3793:
	/* 0x3793: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_3796:
	/* 0x3796: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_3798:
	/* 0x3798: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_379d:
	/* 0x379d: cmovs  r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_37a1:
	/* 0x37a1: mov    DWORD PTR [rax],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37a4:
	/* 0x37a4: jmp    117 <generic_sleepable_preload+0x117> */
	return 279ULL;
x86_l_37a9:
	/* 0x37a9: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37ab:
	/* 0x37ab: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_37b1:
	/* 0x37b1: jmp    3130 <generic_sleepable_preload+0x3130> */
	return 12592ULL;
x86_l_37b6:
	/* 0x37b6: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37b8:
	/* 0x37b8: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_37be:
	/* 0x37be: jmp    31c6 <generic_sleepable_preload+0x31c6> */
	return 12742ULL;
x86_l_37c3:
	/* 0x37c3: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37c5:
	/* 0x37c5: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_37cb:
	/* 0x37cb: jmp    3259 <generic_sleepable_preload+0x3259> */
	goto x86_l_3259;
x86_l_37d0:
	/* 0x37d0: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37d2:
	/* 0x37d2: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_37d8:
	/* 0x37d8: jmp    32ec <generic_sleepable_preload+0x32ec> */
	goto x86_l_32ec;
x86_l_37dd:
	/* 0x37dd: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37e0:
	/* 0x37e0: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_37e5:
	/* 0x37e5: jmp    337f <generic_sleepable_preload+0x337f> */
	goto x86_l_337f;
x86_l_37ea:
	/* 0x37ea: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37ec:
	/* 0x37ec: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_37f2:
	/* 0x37f2: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
	return 14326ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14326ULL: goto x86_l_37f6;
	case 14332ULL: goto x86_l_37fc;
	case 14337ULL: goto x86_l_3801;
	case 14340ULL: goto x86_l_3804;
	case 14345ULL: goto x86_l_3809;
	case 14349ULL: goto x86_l_380d;
	case 14355ULL: goto x86_l_3813;
	case 14360ULL: goto x86_l_3818;
	case 14362ULL: goto x86_l_381a;
	case 14368ULL: goto x86_l_3820;
	case 14372ULL: goto x86_l_3824;
	case 14378ULL: goto x86_l_382a;
	case 14383ULL: goto x86_l_382f;
	case 14385ULL: goto x86_l_3831;
	case 14391ULL: goto x86_l_3837;
	case 14395ULL: goto x86_l_383b;
	case 14401ULL: goto x86_l_3841;
	case 14406ULL: goto x86_l_3846;
	case 14408ULL: goto x86_l_3848;
	case 14414ULL: goto x86_l_384e;
	case 14418ULL: goto x86_l_3852;
	case 14424ULL: goto x86_l_3858;
	case 14429ULL: goto x86_l_385d;
	case 14435ULL: goto x86_l_3863;
	case 14440ULL: goto x86_l_3868;
	case 14446ULL: goto x86_l_386e;
	case 14451ULL: goto x86_l_3873;
	case 14457ULL: goto x86_l_3879;
	case 14462ULL: goto x86_l_387e;
	case 14468ULL: goto x86_l_3884;
	case 14473ULL: goto x86_l_3889;
	case 14478ULL: goto x86_l_388e;
	case 14483ULL: goto x86_l_3893;
	case 14489ULL: goto x86_l_3899;
	case 14494ULL: goto x86_l_389e;
	case 14499ULL: goto x86_l_38a3;
	case 14504ULL: goto x86_l_38a8;
	case 14510ULL: goto x86_l_38ae;
	case 14515ULL: goto x86_l_38b3;
	case 14521ULL: goto x86_l_38b9;
	case 14526ULL: goto x86_l_38be;
	case 14532ULL: goto x86_l_38c4;
	default: return 0xffffffffffffffffULL;
	}
x86_l_37f6:
	/* 0x37f6: jne    ed <generic_sleepable_preload+0xed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 237ULL;
	}
x86_l_37fc:
	/* 0x37fc: jmp    3412 <generic_sleepable_preload+0x3412> */
	return 13330ULL;
x86_l_3801:
	/* 0x3801: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3804:
	/* 0x3804: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_3809:
	/* 0x3809: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_380d:
	/* 0x380d: jne    125 <generic_sleepable_preload+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 293ULL;
	}
x86_l_3813:
	/* 0x3813: jmp    34ce <generic_sleepable_preload+0x34ce> */
	return 13518ULL;
x86_l_3818:
	/* 0x3818: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_381a:
	/* 0x381a: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_3820:
	/* 0x3820: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_3824:
	/* 0x3824: jne    fb <generic_sleepable_preload+0xfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 251ULL;
	}
x86_l_382a:
	/* 0x382a: jmp    357e <generic_sleepable_preload+0x357e> */
	return 13694ULL;
x86_l_382f:
	/* 0x382f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3831:
	/* 0x3831: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_3837:
	/* 0x3837: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_383b:
	/* 0x383b: jne    109 <generic_sleepable_preload+0x109> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 265ULL;
	}
x86_l_3841:
	/* 0x3841: jmp    363d <generic_sleepable_preload+0x363d> */
	return 13885ULL;
x86_l_3846:
	/* 0x3846: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3848:
	/* 0x3848: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_384e:
	/* 0x384e: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_3852:
	/* 0x3852: jne    117 <generic_sleepable_preload+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 279ULL;
	}
x86_l_3858:
	/* 0x3858: jmp    36fc <generic_sleepable_preload+0x36fc> */
	return 14076ULL;
x86_l_385d:
	/* 0x385d: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_3863:
	/* 0x3863: jmp    312e <generic_sleepable_preload+0x312e> */
	return 12590ULL;
x86_l_3868:
	/* 0x3868: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_386e:
	/* 0x386e: jmp    31c4 <generic_sleepable_preload+0x31c4> */
	return 12740ULL;
x86_l_3873:
	/* 0x3873: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_3879:
	/* 0x3879: jmp    3257 <generic_sleepable_preload+0x3257> */
	return 12887ULL;
x86_l_387e:
	/* 0x387e: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_3884:
	/* 0x3884: jmp    32ea <generic_sleepable_preload+0x32ea> */
	return 13034ULL;
x86_l_3889:
	/* 0x3889: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_388e:
	/* 0x388e: jmp    337c <generic_sleepable_preload+0x337c> */
	return 13180ULL;
x86_l_3893:
	/* 0x3893: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_3899:
	/* 0x3899: jmp    3406 <generic_sleepable_preload+0x3406> */
	return 13318ULL;
x86_l_389e:
	/* 0x389e: mov    ebp,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_38a3:
	/* 0x38a3: jmp    34c1 <generic_sleepable_preload+0x34c1> */
	return 13505ULL;
x86_l_38a8:
	/* 0x38a8: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_38ae:
	/* 0x38ae: jmp    3572 <generic_sleepable_preload+0x3572> */
	return 13682ULL;
x86_l_38b3:
	/* 0x38b3: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_38b9:
	/* 0x38b9: jmp    3631 <generic_sleepable_preload+0x3631> */
	return 13873ULL;
x86_l_38be:
	/* 0x38be: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_38c4:
	/* 0x38c4: jmp    36f0 <generic_sleepable_preload+0x36f0> */
	return 14064ULL;
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
	for (__u32 __x86_iter = 0; __x86_iter < 12456U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1765ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1768ULL && __x86_pc <= 3628ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3636ULL && __x86_pc <= 5512ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5517ULL && __x86_pc <= 7387ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7395ULL && __x86_pc <= 9180ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9188ULL && __x86_pc <= 10967ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10972ULL && __x86_pc <= 12791ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12796ULL && __x86_pc <= 14322ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14326ULL && __x86_pc <= 14532ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v53_generic_sleepable_preload_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

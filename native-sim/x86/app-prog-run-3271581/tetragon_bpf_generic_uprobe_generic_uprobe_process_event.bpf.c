extern char buffer_heap_map;
extern char config_map;
extern char fdinstall_map;
extern char process_call_heap;
extern char sleepable_preload;
extern char tg_ipv6_ext_heap;
extern char uprobe_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_0(
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
	case 76ULL: goto x86_l_4c;
	case 83ULL: goto x86_l_53;
	case 89ULL: goto x86_l_59;
	case 100ULL: goto x86_l_64;
	case 107ULL: goto x86_l_6b;
	case 115ULL: goto x86_l_73;
	case 120ULL: goto x86_l_78;
	case 122ULL: goto x86_l_7a;
	case 125ULL: goto x86_l_7d;
	case 131ULL: goto x86_l_83;
	case 134ULL: goto x86_l_86;
	case 141ULL: goto x86_l_8d;
	case 148ULL: goto x86_l_94;
	case 153ULL: goto x86_l_99;
	case 155ULL: goto x86_l_9b;
	case 159ULL: goto x86_l_9f;
	case 165ULL: goto x86_l_a5;
	case 168ULL: goto x86_l_a8;
	case 174ULL: goto x86_l_ae;
	case 182ULL: goto x86_l_b6;
	case 186ULL: goto x86_l_ba;
	case 189ULL: goto x86_l_bd;
	case 194ULL: goto x86_l_c2;
	case 197ULL: goto x86_l_c5;
	case 201ULL: goto x86_l_c9;
	case 206ULL: goto x86_l_ce;
	case 218ULL: goto x86_l_da;
	case 222ULL: goto x86_l_de;
	case 230ULL: goto x86_l_e6;
	case 236ULL: goto x86_l_ec;
	case 246ULL: goto x86_l_f6;
	case 250ULL: goto x86_l_fa;
	case 256ULL: goto x86_l_100;
	case 263ULL: goto x86_l_107;
	case 269ULL: goto x86_l_10d;
	case 272ULL: goto x86_l_110;
	case 274ULL: goto x86_l_112;
	case 278ULL: goto x86_l_116;
	case 280ULL: goto x86_l_118;
	case 285ULL: goto x86_l_11d;
	case 289ULL: goto x86_l_121;
	case 292ULL: goto x86_l_124;
	case 300ULL: goto x86_l_12c;
	case 305ULL: goto x86_l_131;
	case 310ULL: goto x86_l_136;
	case 318ULL: goto x86_l_13e;
	case 321ULL: goto x86_l_141;
	case 324ULL: goto x86_l_144;
	case 327ULL: goto x86_l_147;
	case 331ULL: goto x86_l_14b;
	case 339ULL: goto x86_l_153;
	case 341ULL: goto x86_l_155;
	case 344ULL: goto x86_l_158;
	case 350ULL: goto x86_l_15e;
	case 353ULL: goto x86_l_161;
	case 358ULL: goto x86_l_166;
	case 363ULL: goto x86_l_16b;
	case 368ULL: goto x86_l_170;
	case 373ULL: goto x86_l_175;
	case 375ULL: goto x86_l_177;
	case 382ULL: goto x86_l_17e;
	case 387ULL: goto x86_l_183;
	case 392ULL: goto x86_l_188;
	case 397ULL: goto x86_l_18d;
	case 399ULL: goto x86_l_18f;
	case 402ULL: goto x86_l_192;
	case 407ULL: goto x86_l_197;
	case 413ULL: goto x86_l_19d;
	case 416ULL: goto x86_l_1a0;
	case 419ULL: goto x86_l_1a3;
	case 425ULL: goto x86_l_1a9;
	case 428ULL: goto x86_l_1ac;
	case 434ULL: goto x86_l_1b2;
	case 437ULL: goto x86_l_1b5;
	case 443ULL: goto x86_l_1bb;
	case 446ULL: goto x86_l_1be;
	case 452ULL: goto x86_l_1c4;
	case 455ULL: goto x86_l_1c7;
	case 461ULL: goto x86_l_1cd;
	case 464ULL: goto x86_l_1d0;
	case 470ULL: goto x86_l_1d6;
	case 475ULL: goto x86_l_1db;
	case 478ULL: goto x86_l_1de;
	case 487ULL: goto x86_l_1e7;
	case 492ULL: goto x86_l_1ec;
	case 495ULL: goto x86_l_1ef;
	case 500ULL: goto x86_l_1f4;
	case 507ULL: goto x86_l_1fb;
	case 512ULL: goto x86_l_200;
	case 515ULL: goto x86_l_203;
	case 520ULL: goto x86_l_208;
	case 523ULL: goto x86_l_20b;
	case 528ULL: goto x86_l_210;
	case 530ULL: goto x86_l_212;
	case 533ULL: goto x86_l_215;
	case 540ULL: goto x86_l_21c;
	case 546ULL: goto x86_l_222;
	case 555ULL: goto x86_l_22b;
	case 560ULL: goto x86_l_230;
	case 562ULL: goto x86_l_232;
	case 567ULL: goto x86_l_237;
	case 574ULL: goto x86_l_23e;
	case 579ULL: goto x86_l_243;
	case 584ULL: goto x86_l_248;
	case 586ULL: goto x86_l_24a;
	case 589ULL: goto x86_l_24d;
	case 591ULL: goto x86_l_24f;
	case 593ULL: goto x86_l_251;
	case 598ULL: goto x86_l_256;
	case 606ULL: goto x86_l_25e;
	case 609ULL: goto x86_l_261;
	case 611ULL: goto x86_l_263;
	case 615ULL: goto x86_l_267;
	case 620ULL: goto x86_l_26c;
	case 625ULL: goto x86_l_271;
	case 630ULL: goto x86_l_276;
	case 635ULL: goto x86_l_27b;
	case 640ULL: goto x86_l_280;
	case 643ULL: goto x86_l_283;
	case 645ULL: goto x86_l_285;
	case 650ULL: goto x86_l_28a;
	case 653ULL: goto x86_l_28d;
	case 659ULL: goto x86_l_293;
	case 661ULL: goto x86_l_295;
	case 671ULL: goto x86_l_29f;
	case 675ULL: goto x86_l_2a3;
	case 681ULL: goto x86_l_2a9;
	case 688ULL: goto x86_l_2b0;
	case 695ULL: goto x86_l_2b7;
	case 698ULL: goto x86_l_2ba;
	case 703ULL: goto x86_l_2bf;
	case 705ULL: goto x86_l_2c1;
	case 708ULL: goto x86_l_2c4;
	case 714ULL: goto x86_l_2ca;
	case 717ULL: goto x86_l_2cd;
	case 724ULL: goto x86_l_2d4;
	case 730ULL: goto x86_l_2da;
	case 742ULL: goto x86_l_2e6;
	case 749ULL: goto x86_l_2ed;
	case 752ULL: goto x86_l_2f0;
	case 757ULL: goto x86_l_2f5;
	case 759ULL: goto x86_l_2f7;
	case 762ULL: goto x86_l_2fa;
	case 768ULL: goto x86_l_300;
	case 771ULL: goto x86_l_303;
	case 776ULL: goto x86_l_308;
	case 784ULL: goto x86_l_310;
	case 792ULL: goto x86_l_318;
	case 800ULL: goto x86_l_320;
	case 803ULL: goto x86_l_323;
	case 807ULL: goto x86_l_327;
	case 815ULL: goto x86_l_32f;
	case 820ULL: goto x86_l_334;
	case 822ULL: goto x86_l_336;
	case 828ULL: goto x86_l_33c;
	case 831ULL: goto x86_l_33f;
	case 838ULL: goto x86_l_346;
	case 846ULL: goto x86_l_34e;
	case 851ULL: goto x86_l_353;
	case 856ULL: goto x86_l_358;
	case 858ULL: goto x86_l_35a;
	case 863ULL: goto x86_l_35f;
	case 866ULL: goto x86_l_362;
	case 874ULL: goto x86_l_36a;
	case 878ULL: goto x86_l_36e;
	case 882ULL: goto x86_l_372;
	case 888ULL: goto x86_l_378;
	case 893ULL: goto x86_l_37d;
	case 896ULL: goto x86_l_380;
	case 898ULL: goto x86_l_382;
	case 900ULL: goto x86_l_384;
	case 908ULL: goto x86_l_38c;
	case 912ULL: goto x86_l_390;
	case 917ULL: goto x86_l_395;
	case 922ULL: goto x86_l_39a;
	case 927ULL: goto x86_l_39f;
	case 932ULL: goto x86_l_3a4;
	case 935ULL: goto x86_l_3a7;
	case 943ULL: goto x86_l_3af;
	case 945ULL: goto x86_l_3b1;
	case 950ULL: goto x86_l_3b6;
	case 954ULL: goto x86_l_3ba;
	case 959ULL: goto x86_l_3bf;
	case 964ULL: goto x86_l_3c4;
	case 969ULL: goto x86_l_3c9;
	case 974ULL: goto x86_l_3ce;
	case 978ULL: goto x86_l_3d2;
	case 983ULL: goto x86_l_3d7;
	case 985ULL: goto x86_l_3d9;
	case 990ULL: goto x86_l_3de;
	case 998ULL: goto x86_l_3e6;
	case 1003ULL: goto x86_l_3eb;
	case 1008ULL: goto x86_l_3f0;
	case 1013ULL: goto x86_l_3f5;
	case 1018ULL: goto x86_l_3fa;
	case 1020ULL: goto x86_l_3fc;
	case 1023ULL: goto x86_l_3ff;
	case 1028ULL: goto x86_l_404;
	case 1037ULL: goto x86_l_40d;
	case 1045ULL: goto x86_l_415;
	case 1051ULL: goto x86_l_41b;
	case 1054ULL: goto x86_l_41e;
	case 1059ULL: goto x86_l_423;
	case 1064ULL: goto x86_l_428;
	case 1073ULL: goto x86_l_431;
	case 1076ULL: goto x86_l_434;
	case 1078ULL: goto x86_l_436;
	case 1081ULL: goto x86_l_439;
	case 1087ULL: goto x86_l_43f;
	case 1090ULL: goto x86_l_442;
	case 1096ULL: goto x86_l_448;
	case 1104ULL: goto x86_l_450;
	case 1109ULL: goto x86_l_455;
	case 1115ULL: goto x86_l_45b;
	case 1118ULL: goto x86_l_45e;
	case 1124ULL: goto x86_l_464;
	case 1127ULL: goto x86_l_467;
	case 1133ULL: goto x86_l_46d;
	case 1136ULL: goto x86_l_470;
	case 1142ULL: goto x86_l_476;
	case 1145ULL: goto x86_l_479;
	case 1148ULL: goto x86_l_47c;
	case 1153ULL: goto x86_l_481;
	case 1159ULL: goto x86_l_487;
	case 1162ULL: goto x86_l_48a;
	case 1165ULL: goto x86_l_48d;
	case 1171ULL: goto x86_l_493;
	case 1174ULL: goto x86_l_496;
	case 1180ULL: goto x86_l_49c;
	case 1185ULL: goto x86_l_4a1;
	case 1188ULL: goto x86_l_4a4;
	case 1194ULL: goto x86_l_4aa;
	case 1197ULL: goto x86_l_4ad;
	case 1199ULL: goto x86_l_4af;
	case 1202ULL: goto x86_l_4b2;
	case 1208ULL: goto x86_l_4b8;
	case 1220ULL: goto x86_l_4c4;
	case 1228ULL: goto x86_l_4cc;
	case 1233ULL: goto x86_l_4d1;
	case 1235ULL: goto x86_l_4d3;
	case 1243ULL: goto x86_l_4db;
	case 1246ULL: goto x86_l_4de;
	case 1249ULL: goto x86_l_4e1;
	case 1257ULL: goto x86_l_4e9;
	case 1261ULL: goto x86_l_4ed;
	case 1265ULL: goto x86_l_4f1;
	case 1267ULL: goto x86_l_4f3;
	case 1275ULL: goto x86_l_4fb;
	case 1282ULL: goto x86_l_502;
	case 1287ULL: goto x86_l_507;
	case 1292ULL: goto x86_l_50c;
	case 1294ULL: goto x86_l_50e;
	case 1297ULL: goto x86_l_511;
	case 1299ULL: goto x86_l_513;
	case 1302ULL: goto x86_l_516;
	case 1309ULL: goto x86_l_51d;
	case 1316ULL: goto x86_l_524;
	case 1321ULL: goto x86_l_529;
	case 1323ULL: goto x86_l_52b;
	case 1326ULL: goto x86_l_52e;
	case 1328ULL: goto x86_l_530;
	case 1331ULL: goto x86_l_533;
	case 1334ULL: goto x86_l_536;
	case 1337ULL: goto x86_l_539;
	case 1342ULL: goto x86_l_53e;
	case 1344ULL: goto x86_l_540;
	case 1351ULL: goto x86_l_547;
	case 1358ULL: goto x86_l_54e;
	case 1363ULL: goto x86_l_553;
	case 1368ULL: goto x86_l_558;
	case 1371ULL: goto x86_l_55b;
	case 1376ULL: goto x86_l_560;
	case 1378ULL: goto x86_l_562;
	case 1389ULL: goto x86_l_56d;
	case 1396ULL: goto x86_l_574;
	case 1401ULL: goto x86_l_579;
	case 1406ULL: goto x86_l_57e;
	case 1409ULL: goto x86_l_581;
	case 1414ULL: goto x86_l_586;
	case 1416ULL: goto x86_l_588;
	case 1418ULL: goto x86_l_58a;
	case 1425ULL: goto x86_l_591;
	case 1426ULL: goto x86_l_592;
	case 1428ULL: goto x86_l_594;
	case 1430ULL: goto x86_l_596;
	case 1432ULL: goto x86_l_598;
	case 1434ULL: goto x86_l_59a;
	case 1435ULL: goto x86_l_59b;
	case 1440ULL: goto x86_l_5a0;
	case 1443ULL: goto x86_l_5a3;
	case 1449ULL: goto x86_l_5a9;
	case 1452ULL: goto x86_l_5ac;
	case 1457ULL: goto x86_l_5b1;
	case 1463ULL: goto x86_l_5b7;
	case 1466ULL: goto x86_l_5ba;
	case 1469ULL: goto x86_l_5bd;
	case 1475ULL: goto x86_l_5c3;
	case 1478ULL: goto x86_l_5c6;
	case 1484ULL: goto x86_l_5cc;
	case 1489ULL: goto x86_l_5d1;
	case 1492ULL: goto x86_l_5d4;
	case 1498ULL: goto x86_l_5da;
	case 1501ULL: goto x86_l_5dd;
	case 1507ULL: goto x86_l_5e3;
	case 1509ULL: goto x86_l_5e5;
	case 1515ULL: goto x86_l_5eb;
	case 1518ULL: goto x86_l_5ee;
	case 1524ULL: goto x86_l_5f4;
	case 1529ULL: goto x86_l_5f9;
	case 1532ULL: goto x86_l_5fc;
	case 1538ULL: goto x86_l_602;
	case 1543ULL: goto x86_l_607;
	case 1548ULL: goto x86_l_60c;
	case 1553ULL: goto x86_l_611;
	case 1558ULL: goto x86_l_616;
	case 1563ULL: goto x86_l_61b;
	case 1568ULL: goto x86_l_620;
	case 1570ULL: goto x86_l_622;
	case 1575ULL: goto x86_l_627;
	case 1578ULL: goto x86_l_62a;
	case 1586ULL: goto x86_l_632;
	case 1588ULL: goto x86_l_634;
	case 1590ULL: goto x86_l_636;
	case 1595ULL: goto x86_l_63b;
	case 1603ULL: goto x86_l_643;
	case 1608ULL: goto x86_l_648;
	case 1613ULL: goto x86_l_64d;
	case 1618ULL: goto x86_l_652;
	case 1621ULL: goto x86_l_655;
	case 1626ULL: goto x86_l_65a;
	case 1628ULL: goto x86_l_65c;
	case 1636ULL: goto x86_l_664;
	case 1641ULL: goto x86_l_669;
	case 1646ULL: goto x86_l_66e;
	case 1651ULL: goto x86_l_673;
	case 1656ULL: goto x86_l_678;
	case 1664ULL: goto x86_l_680;
	case 1669ULL: goto x86_l_685;
	case 1671ULL: goto x86_l_687;
	case 1679ULL: goto x86_l_68f;
	case 1683ULL: goto x86_l_693;
	case 1691ULL: goto x86_l_69b;
	case 1699ULL: goto x86_l_6a3;
	case 1706ULL: goto x86_l_6aa;
	case 1711ULL: goto x86_l_6af;
	case 1716ULL: goto x86_l_6b4;
	case 1719ULL: goto x86_l_6b7;
	case 1724ULL: goto x86_l_6bc;
	case 1726ULL: goto x86_l_6be;
	case 1728ULL: goto x86_l_6c0;
	case 1733ULL: goto x86_l_6c5;
	case 1736ULL: goto x86_l_6c8;
	case 1742ULL: goto x86_l_6ce;
	case 1745ULL: goto x86_l_6d1;
	case 1748ULL: goto x86_l_6d4;
	case 1753ULL: goto x86_l_6d9;
	case 1755ULL: goto x86_l_6db;
	case 1758ULL: goto x86_l_6de;
	case 1760ULL: goto x86_l_6e0;
	case 1763ULL: goto x86_l_6e3;
	case 1769ULL: goto x86_l_6e9;
	case 1774ULL: goto x86_l_6ee;
	case 1777ULL: goto x86_l_6f1;
	case 1782ULL: goto x86_l_6f6;
	case 1788ULL: goto x86_l_6fc;
	case 1794ULL: goto x86_l_702;
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
	/* 0xa: sub    rsp,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 232ULL);
x86_l_11:
	/* 0x11: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    DWORD PTR [rsp+0xc4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_1f:
	/* 0x1f: mov    rdi,QWORD PTR [rip+0x210] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_26:
	/* 0x26: lea    rsi,[rsp+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
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
	/* 0x38: je     588 <generic_uprobe_process_event+0x588> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_588;
	}
x86_l_3e:
	/* 0x3e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_41:
	/* 0x41: mov    r12d,DWORD PTR [rax+0x5eec] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24300ULL);
x86_l_48:
	/* 0x48: mov    r13d,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4c:
	/* 0x4c: cmp    r13,0x2327 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 8999ULL);
x86_l_53:
	/* 0x53: ja     4e9 <generic_uprobe_process_event+0x4e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4e9;
	}
x86_l_59:
	/* 0x59: mov    DWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_64:
	/* 0x64: mov    rdi,QWORD PTR [rip+0x210] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_6b:
	/* 0x6b: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_73:
	/* 0x73: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_78:
	/* 0x78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a:
	/* 0x7a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7d:
	/* 0x7d: je     4e9 <generic_uprobe_process_event+0x4e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e9;
	}
x86_l_83:
	/* 0x83: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_86:
	/* 0x86: lea    rsi,[rax+0x5ee8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24296ULL);
x86_l_8d:
	/* 0x8d: mov    rdi,QWORD PTR [rip+0x210] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_94:
	/* 0x94: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_99:
	/* 0x99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b:
	/* 0x9b: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_9f:
	/* 0x9f: jg     4e9 <generic_uprobe_process_event+0x4e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4e9;
	}
x86_l_a5:
	/* 0xa5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a8:
	/* 0xa8: je     4e9 <generic_uprobe_process_event+0x4e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e9;
	}
x86_l_ae:
	/* 0xae: mov    QWORD PTR [rsp+0xe0],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_b6:
	/* 0xb6: and    r12d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_ba:
	/* 0xba: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_bd:
	/* 0xbd: mov    QWORD PTR [rsp+0x68],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c2:
	/* 0xc2: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_c5:
	/* 0xc5: mov    ebp,DWORD PTR [rax+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_c9:
	/* 0xc9: movsxd r12,DWORD PTR [rax+rcx*4+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RCX, 2, X86_WIDTH_32), 24ULL);
x86_l_ce:
	/* 0xce: mov    DWORD PTR [r15+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_da:
	/* 0xda: cmp    rbp,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 40ULL);
x86_l_de:
	/* 0xde: mov    QWORD PTR [rsp+0x90],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_e6:
	/* 0xe6: ja     1f4 <generic_uprobe_process_event+0x1f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f4;
	}
x86_l_ec:
	/* 0xec: movabs rcx,0x1c1f2027cf2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1932500565234ULL);
x86_l_f6:
	/* 0xf6: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_fa:
	/* 0xfa: jae    1f4 <generic_uprobe_process_event+0x1f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f4;
	}
x86_l_100:
	/* 0x100: test   r12d,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_32, 256ULL);
x86_l_107:
	/* 0x107: jne    222 <generic_uprobe_process_event+0x222> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_222;
	}
x86_l_10d:
	/* 0x10d: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_110:
	/* 0x110: js     131 <generic_uprobe_process_event+0x131> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_131;
	}
x86_l_112:
	/* 0x112: test   r12b,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_8, 64ULL);
x86_l_116:
	/* 0x116: jne    188 <generic_uprobe_process_event+0x188> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_188;
	}
x86_l_118:
	/* 0x118: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_11d:
	/* 0x11d: mov    eax,DWORD PTR [rax+rcx*4+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 64ULL);
x86_l_121:
	/* 0x121: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_124:
	/* 0x124: mov    r13,QWORD PTR [r15+rax*8+0x5e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24144ULL);
x86_l_12c:
	/* 0x12c: jmp    28a <generic_uprobe_process_event+0x28a> */
	goto x86_l_28a;
x86_l_131:
	/* 0x131: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_136:
	/* 0x136: movzx  ecx,BYTE PTR [rax+rdx*4+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 2, X86_WIDTH_8), 706ULL);
x86_l_13e:
	/* 0x13e: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_141:
	/* 0x141: mov    r15b,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 64ULL);
x86_l_144:
	/* 0x144: sub    r15b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_147:
	/* 0x147: cmp    DWORD PTR [rax+0x54],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_14b:
	/* 0x14b: movzx  edx,WORD PTR [rax+rdx*4+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 2, X86_WIDTH_16), 704ULL);
x86_l_153:
	/* 0x153: je     197 <generic_uprobe_process_event+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_197;
	}
x86_l_155:
	/* 0x155: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_158:
	/* 0x158: je     1ec <generic_uprobe_process_event+0x1ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ec;
	}
x86_l_15e:
	/* 0x15e: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_161:
	/* 0x161: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_166:
	/* 0x166: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16b:
	/* 0x16b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_170:
	/* 0x170: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_175:
	/* 0x175: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_177:
	/* 0x177: shlx   rax,QWORD PTR [rsp+0x28],r15 */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_R15)), ((40ULL << 32) | X86_ALU_SHL));
x86_l_17e:
	/* 0x17e: sarx   r13,rax,r15 */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R13, X86_RAX, X86_WIDTH_64, X86_R15, X86_ALU_SAR);
x86_l_183:
	/* 0x183: jmp    28a <generic_uprobe_process_event+0x28a> */
	goto x86_l_28a;
x86_l_188:
	/* 0x188: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_18d:
	/* 0x18d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18f:
	/* 0x18f: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_192:
	/* 0x192: jmp    28a <generic_uprobe_process_event+0x28a> */
	goto x86_l_28a;
x86_l_197:
	/* 0x197: rorx   eax,edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RDX, X86_WIDTH_32, 0, 3ULL);
x86_l_19d:
	/* 0x19d: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a0:
	/* 0x1a0: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1a3:
	/* 0x1a3: jle    5d1 <generic_uprobe_process_event+0x5d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_5d1;
	}
x86_l_1a9:
	/* 0x1a9: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1ac:
	/* 0x1ac: jle    75e <generic_uprobe_process_event+0x75e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 1886ULL;
	}
x86_l_1b2:
	/* 0x1b2: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1b5:
	/* 0x1b5: jle    875 <generic_uprobe_process_event+0x875> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2165ULL;
	}
x86_l_1bb:
	/* 0x1bb: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1be:
	/* 0x1be: je     97f <generic_uprobe_process_event+0x97f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2431ULL;
	}
x86_l_1c4:
	/* 0x1c4: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1c7:
	/* 0x1c7: je     91e <generic_uprobe_process_event+0x91e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2334ULL;
	}
x86_l_1cd:
	/* 0x1cd: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_1d0:
	/* 0x1d0: jne    28a <generic_uprobe_process_event+0x28a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28a;
	}
x86_l_1d6:
	/* 0x1d6: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_1db:
	/* 0x1db: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1de:
	/* 0x1de: bzhi   r13,QWORD PTR [rbx+0x98],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 152ULL);
x86_l_1e7:
	/* 0x1e7: jmp    28a <generic_uprobe_process_event+0x28a> */
	goto x86_l_28a;
x86_l_1ec:
	/* 0x1ec: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ef:
	/* 0x1ef: jmp    28a <generic_uprobe_process_event+0x28a> */
	goto x86_l_28a;
x86_l_1f4:
	/* 0x1f4: mov    rsi,QWORD PTR [rip+0x210] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&uprobe_calls)));
x86_l_1fb:
	/* 0x1fb: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_200:
	/* 0x200: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_203:
	/* 0x203: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_208:
	/* 0x208: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_20b:
	/* 0x20b: mov    edx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_210:
	/* 0x210: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_212:
	/* 0x212: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_215:
	/* 0x215: test   r12d,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_32, 256ULL);
x86_l_21c:
	/* 0x21c: je     10d <generic_uprobe_process_event+0x10d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10d;
	}
x86_l_222:
	/* 0x222: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_22b:
	/* 0x22b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_230:
	/* 0x230: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_232:
	/* 0x232: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_237:
	/* 0x237: mov    rdi,QWORD PTR [rip+0x210] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_23e:
	/* 0x23e: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_243:
	/* 0x243: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_248:
	/* 0x248: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24a:
	/* 0x24a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24d:
	/* 0x24d: je     285 <generic_uprobe_process_event+0x285> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_285;
	}
x86_l_24f:
	/* 0x24f: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_251:
	/* 0x251: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_256:
	/* 0x256: mov    DWORD PTR [r15+rdx*4+0x5ea0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 24224ULL);
x86_l_25e:
	/* 0x25e: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_261:
	/* 0x261: jne    285 <generic_uprobe_process_event+0x285> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_285;
	}
x86_l_263:
	/* 0x263: add    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_267:
	/* 0x267: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_26c:
	/* 0x26c: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_271:
	/* 0x271: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_276:
	/* 0x276: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27b:
	/* 0x27b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_280:
	/* 0x280: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_283:
	/* 0x283: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_285:
	/* 0x285: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_28a:
	/* 0x28a: cmp    ebp,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 42ULL);
x86_l_28d:
	/* 0x28d: ja     455 <generic_uprobe_process_event+0x455> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_455;
	}
x86_l_293:
	/* 0x293: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_295:
	/* 0x295: movabs rcx,0x42001018000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 4535502340096ULL);
x86_l_29f:
	/* 0x29f: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2a3:
	/* 0x2a3: jae    455 <generic_uprobe_process_event+0x455> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_455;
	}
x86_l_2a9:
	/* 0x2a9: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b0:
	/* 0x2b0: mov    rdi,QWORD PTR [rip+0x210] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_2b7:
	/* 0x2b7: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2ba:
	/* 0x2ba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bf:
	/* 0x2bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c1:
	/* 0x2c1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c4:
	/* 0x2c4: je     4d1 <generic_uprobe_process_event+0x4d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d1;
	}
x86_l_2ca:
	/* 0x2ca: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2cd:
	/* 0x2cd: cmp    DWORD PTR [rax+0x6410],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 110019882254336ULL);
x86_l_2d4:
	/* 0x2d4: je     423 <generic_uprobe_process_event+0x423> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_423;
	}
x86_l_2da:
	/* 0x2da: mov    DWORD PTR [r12+0x6410],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 110019882254336ULL);
x86_l_2e6:
	/* 0x2e6: mov    rdi,QWORD PTR [rip+0x210] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_2ed:
	/* 0x2ed: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2f0:
	/* 0x2f0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f5:
	/* 0x2f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f7:
	/* 0x2f7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2fa:
	/* 0x2fa: je     4d1 <generic_uprobe_process_event+0x4d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d1;
	}
x86_l_300:
	/* 0x300: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_303:
	/* 0x303: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_308:
	/* 0x308: mov    eax,DWORD PTR [r12+rcx*4+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 24224ULL);
x86_l_310:
	/* 0x310: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_318:
	/* 0x318: mov    DWORD PTR [r12+r13*1+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 144ULL);
x86_l_320:
	/* 0x320: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_323:
	/* 0x323: add    rbp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_327:
	/* 0x327: mov    QWORD PTR [r12+rcx*8+0x5e78],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24184ULL);
x86_l_32f:
	/* 0x32f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_334:
	/* 0x334: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_336:
	/* 0x336: jne    4db <generic_uprobe_process_event+0x4db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4db;
	}
x86_l_33c:
	/* 0x33c: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_33f:
	/* 0x33f: add    r15,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_346:
	/* 0x346: mov    eax,DWORD PTR [r12+0x6414] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 25620ULL);
x86_l_34e:
	/* 0x34e: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_353:
	/* 0x353: mov    ebx,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4095ULL);
x86_l_358:
	/* 0x358: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_35a:
	/* 0x35a: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_35f:
	/* 0x35f: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_362:
	/* 0x362: mov    r13,QWORD PTR [r12+0x6430] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 25648ULL);
x86_l_36a:
	/* 0x36a: lea    rdi,[r15+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_36e:
	/* 0x36e: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_372:
	/* 0x372: and    ebx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_378:
	/* 0x378: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37d:
	/* 0x37d: add    r15,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_380:
	/* 0x380: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_382:
	/* 0x382: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_384:
	/* 0x384: mov    DWORD PTR [r12+rbp*1+0x90],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_38c:
	/* 0x38c: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_390:
	/* 0x390: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_395:
	/* 0x395: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_39a:
	/* 0x39a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_39f:
	/* 0x39f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a4:
	/* 0x3a4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3a7:
	/* 0x3a7: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3af:
	/* 0x3af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b1:
	/* 0x3b1: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3b6:
	/* 0x3b6: add    rcx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_3ba:
	/* 0x3ba: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3bf:
	/* 0x3bf: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3c4:
	/* 0x3c4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c9:
	/* 0x3c9: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3ce:
	/* 0x3ce: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_3d2:
	/* 0x3d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d7:
	/* 0x3d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d9:
	/* 0x3d9: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3de:
	/* 0x3de: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3e6:
	/* 0x3e6: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3eb:
	/* 0x3eb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3f0:
	/* 0x3f0: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3f5:
	/* 0x3f5: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3fa:
	/* 0x3fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fc:
	/* 0x3fc: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_3ff:
	/* 0x3ff: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_404:
	/* 0x404: mov    DWORD PTR [rsi+r15*1+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 17179869184ULL);
x86_l_40d:
	/* 0x40d: movzx  eax,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_415:
	/* 0x415: mov    WORD PTR [rsi+r15*1+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 8ULL);
x86_l_41b:
	/* 0x41b: add    esi,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 14ULL);
x86_l_41e:
	/* 0x41e: jmp    4db <generic_uprobe_process_event+0x4db> */
	goto x86_l_4db;
x86_l_423:
	/* 0x423: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_428:
	/* 0x428: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_431:
	/* 0x431: cmp    ebp,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 23ULL);
x86_l_434:
	/* 0x434: jg     4a1 <generic_uprobe_process_event+0x4a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4a1;
	}
x86_l_436:
	/* 0x436: cmp    ebp,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 15ULL);
x86_l_439:
	/* 0x439: je     607 <generic_uprobe_process_event+0x607> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_607;
	}
x86_l_43f:
	/* 0x43f: cmp    ebp,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_442:
	/* 0x442: jne    4d1 <generic_uprobe_process_event+0x4d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4d1;
	}
x86_l_448:
	/* 0x448: lea    r15,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_450:
	/* 0x450: jmp    669 <generic_uprobe_process_event+0x669> */
	goto x86_l_669;
x86_l_455:
	/* 0x455: mov    r15d,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 144ULL);
x86_l_45b:
	/* 0x45b: cmp    ebp,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 22ULL);
x86_l_45e:
	/* 0x45e: jg     5a0 <generic_uprobe_process_event+0x5a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_5a0;
	}
x86_l_464:
	/* 0x464: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_467:
	/* 0x467: jle    6c5 <generic_uprobe_process_event+0x6c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_6c5;
	}
x86_l_46d:
	/* 0x46d: cmp    ebp,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 17ULL);
x86_l_470:
	/* 0x470: jg     707 <generic_uprobe_process_event+0x707> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1799ULL;
	}
x86_l_476:
	/* 0x476: lea    eax,[rbp-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_479:
	/* 0x479: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_47c:
	/* 0x47c: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_481:
	/* 0x481: jb     7fb <generic_uprobe_process_event+0x7fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2043ULL;
	}
x86_l_487:
	/* 0x487: lea    eax,[rbp-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_48a:
	/* 0x48a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_48d:
	/* 0x48d: jb     6fc <generic_uprobe_process_event+0x6fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_6fc;
	}
x86_l_493:
	/* 0x493: cmp    ebp,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 17ULL);
x86_l_496:
	/* 0x496: je     9b8 <generic_uprobe_process_event+0x9b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2488ULL;
	}
x86_l_49c:
	/* 0x49c: jmp    8e5 <generic_uprobe_process_event+0x8e5> */
	return 2277ULL;
x86_l_4a1:
	/* 0x4a1: cmp    ebp,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_4a4:
	/* 0x4a4: je     63b <generic_uprobe_process_event+0x63b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_63b;
	}
x86_l_4aa:
	/* 0x4aa: cmp    ebp,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 42ULL);
x86_l_4ad:
	/* 0x4ad: jne    4d1 <generic_uprobe_process_event+0x4d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4d1;
	}
x86_l_4af:
	/* 0x4af: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_4b2:
	/* 0x4b2: add    rax,0x6420 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 25632ULL);
x86_l_4b8:
	/* 0x4b8: mov    QWORD PTR [r12+0x6420],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 110088601731072ULL);
x86_l_4c4:
	/* 0x4c4: mov    QWORD PTR [r12+0x6428],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 25640ULL);
x86_l_4cc:
	/* 0x4cc: jmp    693 <generic_uprobe_process_event+0x693> */
	goto x86_l_693;
x86_l_4d1:
	/* 0x4d1: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4d3:
	/* 0x4d3: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4db:
	/* 0x4db: add    esi,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4de:
	/* 0x4de: mov    r13d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_32);
x86_l_4e1:
	/* 0x4e1: mov    r12,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_4e9:
	/* 0x4e9: mov    DWORD PTR [r14+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4ed:
	/* 0x4ed: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_4f1:
	/* 0x4f1: jg     562 <generic_uprobe_process_event+0x562> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_562;
	}
x86_l_4f3:
	/* 0x4f3: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_4fb:
	/* 0x4fb: mov    rdi,QWORD PTR [rip+0x210] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_502:
	/* 0x502: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_507:
	/* 0x507: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_50c:
	/* 0x50c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50e:
	/* 0x50e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_511:
	/* 0x511: je     562 <generic_uprobe_process_event+0x562> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_562;
	}
x86_l_513:
	/* 0x513: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_516:
	/* 0x516: add    rsi,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_51d:
	/* 0x51d: mov    rdi,QWORD PTR [rip+0x214] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_524:
	/* 0x524: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_529:
	/* 0x529: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52b:
	/* 0x52b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_52e:
	/* 0x52e: je     562 <generic_uprobe_process_event+0x562> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_562;
	}
x86_l_530:
	/* 0x530: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_533:
	/* 0x533: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_536:
	/* 0x536: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_539:
	/* 0x539: cmp    DWORD PTR [rax+rcx*4+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 279172874239ULL);
x86_l_53e:
	/* 0x53e: je     562 <generic_uprobe_process_event+0x562> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_562;
	}
x86_l_540:
	/* 0x540: mov    DWORD PTR [r14+0x5eec],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24300ULL);
x86_l_547:
	/* 0x547: mov    rsi,QWORD PTR [rip+0x210] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&uprobe_calls)));
x86_l_54e:
	/* 0x54e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_553:
	/* 0x553: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_558:
	/* 0x558: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_55b:
	/* 0x55b: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_560:
	/* 0x560: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_562:
	/* 0x562: mov    DWORD PTR [r14+0x5eec],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104367705292800ULL);
x86_l_56d:
	/* 0x56d: mov    rsi,QWORD PTR [rip+0x210] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&uprobe_calls)));
x86_l_574:
	/* 0x574: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_579:
	/* 0x579: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_57e:
	/* 0x57e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_581:
	/* 0x581: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_586:
	/* 0x586: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_588:
	/* 0x588: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_58a:
	/* 0x58a: add    rsp,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_591:
	/* 0x591: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_592:
	/* 0x592: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_594:
	/* 0x594: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_596:
	/* 0x596: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_598:
	/* 0x598: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_59a:
	/* 0x59a: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_59b:
	/* 0x59b: jmp    2ff9 <generic_uprobe_process_event+0x2ff9> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_5a0:
	/* 0x5a0: cmp    ebp,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 32ULL);
x86_l_5a3:
	/* 0x5a3: jle    6ee <generic_uprobe_process_event+0x6ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_6ee;
	}
x86_l_5a9:
	/* 0x5a9: cmp    ebp,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 38ULL);
x86_l_5ac:
	/* 0x5ac: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5b1:
	/* 0x5b1: jg     735 <generic_uprobe_process_event+0x735> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1845ULL;
	}
x86_l_5b7:
	/* 0x5b7: lea    eax,[rbp-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_5ba:
	/* 0x5ba: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5bd:
	/* 0x5bd: jb     7fb <generic_uprobe_process_event+0x7fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2043ULL;
	}
x86_l_5c3:
	/* 0x5c3: cmp    ebp,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 37ULL);
x86_l_5c6:
	/* 0x5c6: je     9b8 <generic_uprobe_process_event+0x9b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2488ULL;
	}
x86_l_5cc:
	/* 0x5cc: jmp    8e5 <generic_uprobe_process_event+0x8e5> */
	return 2277ULL;
x86_l_5d1:
	/* 0x5d1: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_5d4:
	/* 0x5d4: jg     78c <generic_uprobe_process_event+0x78c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1932ULL;
	}
x86_l_5da:
	/* 0x5da: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5dd:
	/* 0x5dd: jg     82b <generic_uprobe_process_event+0x82b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2091ULL;
	}
x86_l_5e3:
	/* 0x5e3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5e5:
	/* 0x5e5: je     934 <generic_uprobe_process_event+0x934> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2356ULL;
	}
x86_l_5eb:
	/* 0x5eb: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5ee:
	/* 0x5ee: jne    28a <generic_uprobe_process_event+0x28a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28a;
	}
x86_l_5f4:
	/* 0x5f4: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_5f9:
	/* 0x5f9: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5fc:
	/* 0x5fc: bzhi   r13,QWORD PTR [rbx+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 8ULL);
x86_l_602:
	/* 0x602: jmp    28a <generic_uprobe_process_event+0x28a> */
	goto x86_l_28a;
x86_l_607:
	/* 0x607: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_60c:
	/* 0x60c: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_611:
	/* 0x611: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_616:
	/* 0x616: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_61b:
	/* 0x61b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_620:
	/* 0x620: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_622:
	/* 0x622: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_627:
	/* 0x627: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_62a:
	/* 0x62a: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_632:
	/* 0x632: jne    69b <generic_uprobe_process_event+0x69b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_69b;
	}
x86_l_634:
	/* 0x634: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_636:
	/* 0x636: jmp    4db <generic_uprobe_process_event+0x4db> */
	goto x86_l_4db;
x86_l_63b:
	/* 0x63b: lea    r15,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_643:
	/* 0x643: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_648:
	/* 0x648: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_64d:
	/* 0x64d: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_652:
	/* 0x652: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_655:
	/* 0x655: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_65a:
	/* 0x65a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65c:
	/* 0x65c: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_664:
	/* 0x664: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_669:
	/* 0x669: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_66e:
	/* 0x66e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_673:
	/* 0x673: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_678:
	/* 0x678: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_680:
	/* 0x680: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_685:
	/* 0x685: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_687:
	/* 0x687: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_68f:
	/* 0x68f: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_693:
	/* 0x693: mov    r13,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_69b:
	/* 0x69b: mov    QWORD PTR [r12+0x6430],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 25648ULL);
x86_l_6a3:
	/* 0x6a3: mov    rsi,QWORD PTR [rip+0x210] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&uprobe_calls)));
x86_l_6aa:
	/* 0x6aa: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6af:
	/* 0x6af: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_6b4:
	/* 0x6b4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6b7:
	/* 0x6b7: mov    edx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_6bc:
	/* 0x6bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6be:
	/* 0x6be: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6c0:
	/* 0x6c0: jmp    4db <generic_uprobe_process_event+0x4db> */
	goto x86_l_4db;
x86_l_6c5:
	/* 0x6c5: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_6c8:
	/* 0x6c8: jg     7ba <generic_uprobe_process_event+0x7ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1978ULL;
	}
x86_l_6ce:
	/* 0x6ce: lea    eax,[rbp-0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_6d1:
	/* 0x6d1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6d4:
	/* 0x6d4: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6d9:
	/* 0x6d9: jb     6fc <generic_uprobe_process_event+0x6fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_6fc;
	}
x86_l_6db:
	/* 0x6db: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_6de:
	/* 0x6de: je     6fc <generic_uprobe_process_event+0x6fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6fc;
	}
x86_l_6e0:
	/* 0x6e0: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_6e3:
	/* 0x6e3: je     7fb <generic_uprobe_process_event+0x7fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2043ULL;
	}
x86_l_6e9:
	/* 0x6e9: jmp    8e5 <generic_uprobe_process_event+0x8e5> */
	return 2277ULL;
x86_l_6ee:
	/* 0x6ee: cmp    ebp,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 28ULL);
x86_l_6f1:
	/* 0x6f1: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6f6:
	/* 0x6f6: jle    7df <generic_uprobe_process_event+0x7df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2015ULL;
	}
x86_l_6fc:
	/* 0x6fc: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_702:
	/* 0x702: jmp    9b8 <generic_uprobe_process_event+0x9b8> */
	return 2488ULL;
	return 1799ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1799ULL: goto x86_l_707;
	case 1802ULL: goto x86_l_70a;
	case 1808ULL: goto x86_l_710;
	case 1811ULL: goto x86_l_713;
	case 1817ULL: goto x86_l_719;
	case 1820ULL: goto x86_l_71c;
	case 1825ULL: goto x86_l_721;
	case 1831ULL: goto x86_l_727;
	case 1834ULL: goto x86_l_72a;
	case 1840ULL: goto x86_l_730;
	case 1845ULL: goto x86_l_735;
	case 1848ULL: goto x86_l_738;
	case 1854ULL: goto x86_l_73e;
	case 1857ULL: goto x86_l_741;
	case 1863ULL: goto x86_l_747;
	case 1866ULL: goto x86_l_74a;
	case 1872ULL: goto x86_l_750;
	case 1875ULL: goto x86_l_753;
	case 1881ULL: goto x86_l_759;
	case 1886ULL: goto x86_l_75e;
	case 1889ULL: goto x86_l_761;
	case 1895ULL: goto x86_l_767;
	case 1898ULL: goto x86_l_76a;
	case 1904ULL: goto x86_l_770;
	case 1907ULL: goto x86_l_773;
	case 1913ULL: goto x86_l_779;
	case 1918ULL: goto x86_l_77e;
	case 1921ULL: goto x86_l_781;
	case 1927ULL: goto x86_l_787;
	case 1932ULL: goto x86_l_78c;
	case 1935ULL: goto x86_l_78f;
	case 1941ULL: goto x86_l_795;
	case 1944ULL: goto x86_l_798;
	case 1950ULL: goto x86_l_79e;
	case 1953ULL: goto x86_l_7a1;
	case 1959ULL: goto x86_l_7a7;
	case 1964ULL: goto x86_l_7ac;
	case 1967ULL: goto x86_l_7af;
	case 1973ULL: goto x86_l_7b5;
	case 1978ULL: goto x86_l_7ba;
	case 1981ULL: goto x86_l_7bd;
	case 1986ULL: goto x86_l_7c2;
	case 1992ULL: goto x86_l_7c8;
	case 1995ULL: goto x86_l_7cb;
	case 2001ULL: goto x86_l_7d1;
	case 2004ULL: goto x86_l_7d4;
	case 2010ULL: goto x86_l_7da;
	case 2015ULL: goto x86_l_7df;
	case 2018ULL: goto x86_l_7e2;
	case 2020ULL: goto x86_l_7e4;
	case 2023ULL: goto x86_l_7e7;
	case 2029ULL: goto x86_l_7ed;
	case 2032ULL: goto x86_l_7f0;
	case 2038ULL: goto x86_l_7f6;
	case 2043ULL: goto x86_l_7fb;
	case 2049ULL: goto x86_l_801;
	case 2054ULL: goto x86_l_806;
	case 2057ULL: goto x86_l_809;
	case 2063ULL: goto x86_l_80f;
	case 2066ULL: goto x86_l_812;
	case 2072ULL: goto x86_l_818;
	case 2077ULL: goto x86_l_81d;
	case 2080ULL: goto x86_l_820;
	case 2086ULL: goto x86_l_826;
	case 2091ULL: goto x86_l_82b;
	case 2094ULL: goto x86_l_82e;
	case 2100ULL: goto x86_l_834;
	case 2103ULL: goto x86_l_837;
	case 2109ULL: goto x86_l_83d;
	case 2114ULL: goto x86_l_842;
	case 2117ULL: goto x86_l_845;
	case 2123ULL: goto x86_l_84b;
	case 2128ULL: goto x86_l_850;
	case 2131ULL: goto x86_l_853;
	case 2137ULL: goto x86_l_859;
	case 2140ULL: goto x86_l_85c;
	case 2146ULL: goto x86_l_862;
	case 2151ULL: goto x86_l_867;
	case 2154ULL: goto x86_l_86a;
	case 2160ULL: goto x86_l_870;
	case 2165ULL: goto x86_l_875;
	case 2168ULL: goto x86_l_878;
	case 2174ULL: goto x86_l_87e;
	case 2177ULL: goto x86_l_881;
	case 2183ULL: goto x86_l_887;
	case 2188ULL: goto x86_l_88c;
	case 2191ULL: goto x86_l_88f;
	case 2197ULL: goto x86_l_895;
	case 2202ULL: goto x86_l_89a;
	case 2205ULL: goto x86_l_89d;
	case 2207ULL: goto x86_l_89f;
	case 2210ULL: goto x86_l_8a2;
	case 2212ULL: goto x86_l_8a4;
	case 2218ULL: goto x86_l_8aa;
	case 2223ULL: goto x86_l_8af;
	case 2229ULL: goto x86_l_8b5;
	case 2234ULL: goto x86_l_8ba;
	case 2237ULL: goto x86_l_8bd;
	case 2240ULL: goto x86_l_8c0;
	case 2245ULL: goto x86_l_8c5;
	case 2251ULL: goto x86_l_8cb;
	case 2254ULL: goto x86_l_8ce;
	case 2256ULL: goto x86_l_8d0;
	case 2262ULL: goto x86_l_8d6;
	case 2267ULL: goto x86_l_8db;
	case 2270ULL: goto x86_l_8de;
	case 2272ULL: goto x86_l_8e0;
	case 2275ULL: goto x86_l_8e3;
	case 2277ULL: goto x86_l_8e5;
	case 2280ULL: goto x86_l_8e8;
	case 2285ULL: goto x86_l_8ed;
	case 2291ULL: goto x86_l_8f3;
	case 2296ULL: goto x86_l_8f8;
	case 2301ULL: goto x86_l_8fd;
	case 2304ULL: goto x86_l_900;
	case 2310ULL: goto x86_l_906;
	case 2315ULL: goto x86_l_90b;
	case 2320ULL: goto x86_l_910;
	case 2323ULL: goto x86_l_913;
	case 2329ULL: goto x86_l_919;
	case 2334ULL: goto x86_l_91e;
	case 2339ULL: goto x86_l_923;
	case 2342ULL: goto x86_l_926;
	case 2351ULL: goto x86_l_92f;
	case 2356ULL: goto x86_l_934;
	case 2361ULL: goto x86_l_939;
	case 2364ULL: goto x86_l_93c;
	case 2369ULL: goto x86_l_941;
	case 2374ULL: goto x86_l_946;
	case 2379ULL: goto x86_l_94b;
	case 2382ULL: goto x86_l_94e;
	case 2388ULL: goto x86_l_954;
	case 2393ULL: goto x86_l_959;
	case 2398ULL: goto x86_l_95e;
	case 2401ULL: goto x86_l_961;
	case 2407ULL: goto x86_l_967;
	case 2412ULL: goto x86_l_96c;
	case 2417ULL: goto x86_l_971;
	case 2420ULL: goto x86_l_974;
	case 2426ULL: goto x86_l_97a;
	case 2431ULL: goto x86_l_97f;
	case 2436ULL: goto x86_l_984;
	case 2439ULL: goto x86_l_987;
	case 2445ULL: goto x86_l_98d;
	case 2450ULL: goto x86_l_992;
	case 2455ULL: goto x86_l_997;
	case 2458ULL: goto x86_l_99a;
	case 2464ULL: goto x86_l_9a0;
	case 2469ULL: goto x86_l_9a5;
	case 2475ULL: goto x86_l_9ab;
	case 2477ULL: goto x86_l_9ad;
	case 2483ULL: goto x86_l_9b3;
	case 2488ULL: goto x86_l_9b8;
	case 2499ULL: goto x86_l_9c3;
	case 2506ULL: goto x86_l_9ca;
	case 2514ULL: goto x86_l_9d2;
	case 2519ULL: goto x86_l_9d7;
	case 2521ULL: goto x86_l_9d9;
	case 2523ULL: goto x86_l_9db;
	case 2526ULL: goto x86_l_9de;
	case 2532ULL: goto x86_l_9e4;
	case 2537ULL: goto x86_l_9e9;
	case 2540ULL: goto x86_l_9ec;
	case 2548ULL: goto x86_l_9f4;
	case 2554ULL: goto x86_l_9fa;
	case 2562ULL: goto x86_l_a02;
	case 2570ULL: goto x86_l_a0a;
	case 2577ULL: goto x86_l_a11;
	case 2581ULL: goto x86_l_a15;
	case 2589ULL: goto x86_l_a1d;
	case 2594ULL: goto x86_l_a22;
	case 2596ULL: goto x86_l_a24;
	case 2602ULL: goto x86_l_a2a;
	case 2605ULL: goto x86_l_a2d;
	case 2612ULL: goto x86_l_a34;
	case 2615ULL: goto x86_l_a37;
	case 2620ULL: goto x86_l_a3c;
	case 2629ULL: goto x86_l_a45;
	case 2632ULL: goto x86_l_a48;
	case 2640ULL: goto x86_l_a50;
	case 2642ULL: goto x86_l_a52;
	case 2645ULL: goto x86_l_a55;
	case 2647ULL: goto x86_l_a57;
	case 2650ULL: goto x86_l_a5a;
	case 2652ULL: goto x86_l_a5c;
	case 2655ULL: goto x86_l_a5f;
	case 2660ULL: goto x86_l_a64;
	case 2663ULL: goto x86_l_a67;
	case 2669ULL: goto x86_l_a6d;
	case 2672ULL: goto x86_l_a70;
	case 2674ULL: goto x86_l_a72;
	case 2686ULL: goto x86_l_a7e;
	case 2694ULL: goto x86_l_a86;
	case 2702ULL: goto x86_l_a8e;
	case 2707ULL: goto x86_l_a93;
	case 2712ULL: goto x86_l_a98;
	case 2717ULL: goto x86_l_a9d;
	case 2722ULL: goto x86_l_aa2;
	case 2727ULL: goto x86_l_aa7;
	case 2732ULL: goto x86_l_aac;
	case 2734ULL: goto x86_l_aae;
	case 2739ULL: goto x86_l_ab3;
	case 2744ULL: goto x86_l_ab8;
	case 2747ULL: goto x86_l_abb;
	case 2753ULL: goto x86_l_ac1;
	case 2757ULL: goto x86_l_ac5;
	case 2765ULL: goto x86_l_acd;
	case 2772ULL: goto x86_l_ad4;
	case 2777ULL: goto x86_l_ad9;
	case 2782ULL: goto x86_l_ade;
	case 2784ULL: goto x86_l_ae0;
	case 2787ULL: goto x86_l_ae3;
	case 2790ULL: goto x86_l_ae6;
	case 2796ULL: goto x86_l_aec;
	case 2799ULL: goto x86_l_aef;
	case 2807ULL: goto x86_l_af7;
	case 2813ULL: goto x86_l_afd;
	case 2816ULL: goto x86_l_b00;
	case 2822ULL: goto x86_l_b06;
	case 2825ULL: goto x86_l_b09;
	case 2831ULL: goto x86_l_b0f;
	case 2836ULL: goto x86_l_b14;
	case 2839ULL: goto x86_l_b17;
	case 2845ULL: goto x86_l_b1d;
	case 2848ULL: goto x86_l_b20;
	case 2854ULL: goto x86_l_b26;
	case 2857ULL: goto x86_l_b29;
	case 2865ULL: goto x86_l_b31;
	case 2870ULL: goto x86_l_b36;
	case 2875ULL: goto x86_l_b3b;
	case 2878ULL: goto x86_l_b3e;
	case 2883ULL: goto x86_l_b43;
	case 2888ULL: goto x86_l_b48;
	case 2893ULL: goto x86_l_b4d;
	case 2896ULL: goto x86_l_b50;
	case 2901ULL: goto x86_l_b55;
	case 2903ULL: goto x86_l_b57;
	case 2907ULL: goto x86_l_b5b;
	case 2912ULL: goto x86_l_b60;
	case 2917ULL: goto x86_l_b65;
	case 2922ULL: goto x86_l_b6a;
	case 2927ULL: goto x86_l_b6f;
	case 2930ULL: goto x86_l_b72;
	case 2935ULL: goto x86_l_b77;
	case 2937ULL: goto x86_l_b79;
	case 2941ULL: goto x86_l_b7d;
	case 2945ULL: goto x86_l_b81;
	case 2950ULL: goto x86_l_b86;
	case 2961ULL: goto x86_l_b91;
	case 2968ULL: goto x86_l_b98;
	case 2976ULL: goto x86_l_ba0;
	case 2981ULL: goto x86_l_ba5;
	case 2983ULL: goto x86_l_ba7;
	case 2986ULL: goto x86_l_baa;
	case 2992ULL: goto x86_l_bb0;
	case 2995ULL: goto x86_l_bb3;
	case 3000ULL: goto x86_l_bb8;
	case 3006ULL: goto x86_l_bbe;
	case 3014ULL: goto x86_l_bc6;
	case 3019ULL: goto x86_l_bcb;
	case 3021ULL: goto x86_l_bcd;
	case 3028ULL: goto x86_l_bd4;
	case 3036ULL: goto x86_l_bdc;
	case 3041ULL: goto x86_l_be1;
	case 3046ULL: goto x86_l_be6;
	case 3051ULL: goto x86_l_beb;
	case 3053ULL: goto x86_l_bed;
	case 3061ULL: goto x86_l_bf5;
	case 3066ULL: goto x86_l_bfa;
	case 3070ULL: goto x86_l_bfe;
	case 3078ULL: goto x86_l_c06;
	case 3083ULL: goto x86_l_c0b;
	case 3088ULL: goto x86_l_c10;
	case 3093ULL: goto x86_l_c15;
	case 3101ULL: goto x86_l_c1d;
	case 3106ULL: goto x86_l_c22;
	case 3114ULL: goto x86_l_c2a;
	case 3116ULL: goto x86_l_c2c;
	case 3124ULL: goto x86_l_c34;
	case 3128ULL: goto x86_l_c38;
	case 3133ULL: goto x86_l_c3d;
	case 3138ULL: goto x86_l_c42;
	case 3143ULL: goto x86_l_c47;
	case 3148ULL: goto x86_l_c4c;
	case 3150ULL: goto x86_l_c4e;
	case 3156ULL: goto x86_l_c54;
	case 3161ULL: goto x86_l_c59;
	case 3163ULL: goto x86_l_c5b;
	case 3171ULL: goto x86_l_c63;
	case 3173ULL: goto x86_l_c65;
	case 3177ULL: goto x86_l_c69;
	case 3182ULL: goto x86_l_c6e;
	case 3187ULL: goto x86_l_c73;
	case 3192ULL: goto x86_l_c78;
	case 3197ULL: goto x86_l_c7d;
	case 3199ULL: goto x86_l_c7f;
	case 3204ULL: goto x86_l_c84;
	case 3212ULL: goto x86_l_c8c;
	case 3214ULL: goto x86_l_c8e;
	case 3217ULL: goto x86_l_c91;
	case 3224ULL: goto x86_l_c98;
	case 3234ULL: goto x86_l_ca2;
	case 3241ULL: goto x86_l_ca9;
	case 3251ULL: goto x86_l_cb3;
	case 3256ULL: goto x86_l_cb8;
	case 3265ULL: goto x86_l_cc1;
	case 3274ULL: goto x86_l_cca;
	case 3279ULL: goto x86_l_ccf;
	case 3288ULL: goto x86_l_cd8;
	case 3297ULL: goto x86_l_ce1;
	case 3306ULL: goto x86_l_cea;
	case 3314ULL: goto x86_l_cf2;
	case 3319ULL: goto x86_l_cf7;
	case 3323ULL: goto x86_l_cfb;
	case 3328ULL: goto x86_l_d00;
	case 3332ULL: goto x86_l_d04;
	case 3337ULL: goto x86_l_d09;
	case 3342ULL: goto x86_l_d0e;
	case 3347ULL: goto x86_l_d13;
	case 3352ULL: goto x86_l_d18;
	case 3357ULL: goto x86_l_d1d;
	case 3362ULL: goto x86_l_d22;
	case 3367ULL: goto x86_l_d27;
	case 3370ULL: goto x86_l_d2a;
	case 3372ULL: goto x86_l_d2c;
	case 3377ULL: goto x86_l_d31;
	case 3382ULL: goto x86_l_d36;
	case 3390ULL: goto x86_l_d3e;
	case 3393ULL: goto x86_l_d41;
	case 3398ULL: goto x86_l_d46;
	case 3400ULL: goto x86_l_d48;
	case 3405ULL: goto x86_l_d4d;
	case 3410ULL: goto x86_l_d52;
	case 3418ULL: goto x86_l_d5a;
	case 3421ULL: goto x86_l_d5d;
	case 3426ULL: goto x86_l_d62;
	case 3428ULL: goto x86_l_d64;
	case 3433ULL: goto x86_l_d69;
	case 3438ULL: goto x86_l_d6e;
	case 3443ULL: goto x86_l_d73;
	case 3446ULL: goto x86_l_d76;
	case 3451ULL: goto x86_l_d7b;
	case 3453ULL: goto x86_l_d7d;
	case 3458ULL: goto x86_l_d82;
	case 3463ULL: goto x86_l_d87;
	case 3468ULL: goto x86_l_d8c;
	case 3473ULL: goto x86_l_d91;
	case 3478ULL: goto x86_l_d96;
	case 3480ULL: goto x86_l_d98;
	case 3485ULL: goto x86_l_d9d;
	case 3487ULL: goto x86_l_d9f;
	case 3492ULL: goto x86_l_da4;
	case 3497ULL: goto x86_l_da9;
	case 3505ULL: goto x86_l_db1;
	case 3508ULL: goto x86_l_db4;
	case 3513ULL: goto x86_l_db9;
	case 3518ULL: goto x86_l_dbe;
	case 3524ULL: goto x86_l_dc4;
	case 3526ULL: goto x86_l_dc6;
	case 3531ULL: goto x86_l_dcb;
	case 3534ULL: goto x86_l_dce;
	case 3538ULL: goto x86_l_dd2;
	case 3544ULL: goto x86_l_dd8;
	case 3547ULL: goto x86_l_ddb;
	case 3549ULL: goto x86_l_ddd;
	case 3553ULL: goto x86_l_de1;
	case 3556ULL: goto x86_l_de4;
	case 3558ULL: goto x86_l_de6;
	case 3561ULL: goto x86_l_de9;
	case 3563ULL: goto x86_l_deb;
	case 3566ULL: goto x86_l_dee;
	case 3571ULL: goto x86_l_df3;
	case 3574ULL: goto x86_l_df6;
	case 3579ULL: goto x86_l_dfb;
	case 3584ULL: goto x86_l_e00;
	case 3589ULL: goto x86_l_e05;
	case 3594ULL: goto x86_l_e0a;
	case 3599ULL: goto x86_l_e0f;
	case 3602ULL: goto x86_l_e12;
	case 3604ULL: goto x86_l_e14;
	case 3609ULL: goto x86_l_e19;
	case 3615ULL: goto x86_l_e1f;
	case 3619ULL: goto x86_l_e23;
	case 3622ULL: goto x86_l_e26;
	default: return 0xffffffffffffffffULL;
	}
x86_l_707:
	/* 0x707: cmp    ebp,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 19ULL);
x86_l_70a:
	/* 0x70a: jle    8ba <generic_uprobe_process_event+0x8ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_8ba;
	}
x86_l_710:
	/* 0x710: cmp    ebp,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 20ULL);
x86_l_713:
	/* 0x713: je     9ad <generic_uprobe_process_event+0x9ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9ad;
	}
x86_l_719:
	/* 0x719: cmp    ebp,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 21ULL);
x86_l_71c:
	/* 0x71c: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_721:
	/* 0x721: je     9a5 <generic_uprobe_process_event+0x9a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9a5;
	}
x86_l_727:
	/* 0x727: cmp    ebp,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 22ULL);
x86_l_72a:
	/* 0x72a: je     8ed <generic_uprobe_process_event+0x8ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8ed;
	}
x86_l_730:
	/* 0x730: jmp    8e5 <generic_uprobe_process_event+0x8e5> */
	goto x86_l_8e5;
x86_l_735:
	/* 0x735: cmp    ebp,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 40ULL);
x86_l_738:
	/* 0x738: jle    8db <generic_uprobe_process_event+0x8db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_8db;
	}
x86_l_73e:
	/* 0x73e: cmp    ebp,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 41ULL);
x86_l_741:
	/* 0x741: je     8af <generic_uprobe_process_event+0x8af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8af;
	}
x86_l_747:
	/* 0x747: cmp    ebp,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 42ULL);
x86_l_74a:
	/* 0x74a: je     9b8 <generic_uprobe_process_event+0x9b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9b8;
	}
x86_l_750:
	/* 0x750: cmp    ebp,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 43ULL);
x86_l_753:
	/* 0x753: je     8d0 <generic_uprobe_process_event+0x8d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8d0;
	}
x86_l_759:
	/* 0x759: jmp    8e5 <generic_uprobe_process_event+0x8e5> */
	goto x86_l_8e5;
x86_l_75e:
	/* 0x75e: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_761:
	/* 0x761: jg     806 <generic_uprobe_process_event+0x806> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_806;
	}
x86_l_767:
	/* 0x767: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_76a:
	/* 0x76a: je     8f8 <generic_uprobe_process_event+0x8f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8f8;
	}
x86_l_770:
	/* 0x770: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_773:
	/* 0x773: jne    28a <generic_uprobe_process_event+0x28a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 650ULL;
	}
x86_l_779:
	/* 0x779: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_77e:
	/* 0x77e: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_781:
	/* 0x781: bzhi   r13,QWORD PTR [rbx+0x48],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 72ULL);
x86_l_787:
	/* 0x787: jmp    28a <generic_uprobe_process_event+0x28a> */
	return 650ULL;
x86_l_78c:
	/* 0x78c: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_78f:
	/* 0x78f: jg     850 <generic_uprobe_process_event+0x850> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_850;
	}
x86_l_795:
	/* 0x795: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_798:
	/* 0x798: je     946 <generic_uprobe_process_event+0x946> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_946;
	}
x86_l_79e:
	/* 0x79e: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_7a1:
	/* 0x7a1: jne    28a <generic_uprobe_process_event+0x28a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 650ULL;
	}
x86_l_7a7:
	/* 0x7a7: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_7ac:
	/* 0x7ac: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_7af:
	/* 0x7af: bzhi   r13,QWORD PTR [rbx+0x28],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 40ULL);
x86_l_7b5:
	/* 0x7b5: jmp    28a <generic_uprobe_process_event+0x28a> */
	return 650ULL;
x86_l_7ba:
	/* 0x7ba: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_7bd:
	/* 0x7bd: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_7c2:
	/* 0x7c2: jg     89a <generic_uprobe_process_event+0x89a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_89a;
	}
x86_l_7c8:
	/* 0x7c8: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_7cb:
	/* 0x7cb: je     8af <generic_uprobe_process_event+0x8af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8af;
	}
x86_l_7d1:
	/* 0x7d1: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_7d4:
	/* 0x7d4: je     9b8 <generic_uprobe_process_event+0x9b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9b8;
	}
x86_l_7da:
	/* 0x7da: jmp    8e5 <generic_uprobe_process_event+0x8e5> */
	goto x86_l_8e5;
x86_l_7df:
	/* 0x7df: cmp    ebp,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 23ULL);
x86_l_7e2:
	/* 0x7e2: je     7fb <generic_uprobe_process_event+0x7fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7fb;
	}
x86_l_7e4:
	/* 0x7e4: cmp    ebp,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 26ULL);
x86_l_7e7:
	/* 0x7e7: je     8a4 <generic_uprobe_process_event+0x8a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8a4;
	}
x86_l_7ed:
	/* 0x7ed: cmp    ebp,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 27ULL);
x86_l_7f0:
	/* 0x7f0: je     8a4 <generic_uprobe_process_event+0x8a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8a4;
	}
x86_l_7f6:
	/* 0x7f6: jmp    8e5 <generic_uprobe_process_event+0x8e5> */
	goto x86_l_8e5;
x86_l_7fb:
	/* 0x7fb: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_801:
	/* 0x801: jmp    9b8 <generic_uprobe_process_event+0x9b8> */
	goto x86_l_9b8;
x86_l_806:
	/* 0x806: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_809:
	/* 0x809: je     90b <generic_uprobe_process_event+0x90b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_90b;
	}
x86_l_80f:
	/* 0x80f: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_812:
	/* 0x812: jne    28a <generic_uprobe_process_event+0x28a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 650ULL;
	}
x86_l_818:
	/* 0x818: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_81d:
	/* 0x81d: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_820:
	/* 0x820: bzhi   r13,QWORD PTR [rbx+0x58],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 88ULL);
x86_l_826:
	/* 0x826: jmp    28a <generic_uprobe_process_event+0x28a> */
	return 650ULL;
x86_l_82b:
	/* 0x82b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_82e:
	/* 0x82e: je     959 <generic_uprobe_process_event+0x959> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_959;
	}
x86_l_834:
	/* 0x834: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_837:
	/* 0x837: jne    28a <generic_uprobe_process_event+0x28a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 650ULL;
	}
x86_l_83d:
	/* 0x83d: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_842:
	/* 0x842: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_845:
	/* 0x845: bzhi   r13,QWORD PTR [rbx+0x18],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 24ULL);
x86_l_84b:
	/* 0x84b: jmp    28a <generic_uprobe_process_event+0x28a> */
	return 650ULL;
x86_l_850:
	/* 0x850: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_853:
	/* 0x853: je     96c <generic_uprobe_process_event+0x96c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_96c;
	}
x86_l_859:
	/* 0x859: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_85c:
	/* 0x85c: jne    28a <generic_uprobe_process_event+0x28a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 650ULL;
	}
x86_l_862:
	/* 0x862: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_867:
	/* 0x867: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_86a:
	/* 0x86a: bzhi   r13,QWORD PTR [rbx+0x38],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 56ULL);
x86_l_870:
	/* 0x870: jmp    28a <generic_uprobe_process_event+0x28a> */
	return 650ULL;
x86_l_875:
	/* 0x875: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_878:
	/* 0x878: je     992 <generic_uprobe_process_event+0x992> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_992;
	}
x86_l_87e:
	/* 0x87e: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_881:
	/* 0x881: jne    28a <generic_uprobe_process_event+0x28a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 650ULL;
	}
x86_l_887:
	/* 0x887: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_88c:
	/* 0x88c: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_88f:
	/* 0x88f: bzhi   r13,QWORD PTR [rbx+0x68],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 104ULL);
x86_l_895:
	/* 0x895: jmp    28a <generic_uprobe_process_event+0x28a> */
	return 650ULL;
x86_l_89a:
	/* 0x89a: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_89d:
	/* 0x89d: je     8af <generic_uprobe_process_event+0x8af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8af;
	}
x86_l_89f:
	/* 0x89f: cmp    ebp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_8a2:
	/* 0x8a2: jne    8e5 <generic_uprobe_process_event+0x8e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8e5;
	}
x86_l_8a4:
	/* 0x8a4: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_8aa:
	/* 0x8aa: jmp    9b8 <generic_uprobe_process_event+0x9b8> */
	goto x86_l_9b8;
x86_l_8af:
	/* 0x8af: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_8b5:
	/* 0x8b5: jmp    9b8 <generic_uprobe_process_event+0x9b8> */
	goto x86_l_9b8;
x86_l_8ba:
	/* 0x8ba: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_8bd:
	/* 0x8bd: cmp    ebp,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 18ULL);
x86_l_8c0:
	/* 0x8c0: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_8c5:
	/* 0x8c5: je     9b8 <generic_uprobe_process_event+0x9b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9b8;
	}
x86_l_8cb:
	/* 0x8cb: cmp    ebp,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 19ULL);
x86_l_8ce:
	/* 0x8ce: jne    8e5 <generic_uprobe_process_event+0x8e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8e5;
	}
x86_l_8d0:
	/* 0x8d0: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_8d6:
	/* 0x8d6: jmp    9b8 <generic_uprobe_process_event+0x9b8> */
	goto x86_l_9b8;
x86_l_8db:
	/* 0x8db: cmp    ebp,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 39ULL);
x86_l_8de:
	/* 0x8de: je     8ed <generic_uprobe_process_event+0x8ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8ed;
	}
x86_l_8e0:
	/* 0x8e0: cmp    ebp,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 40ULL);
x86_l_8e3:
	/* 0x8e3: je     8d0 <generic_uprobe_process_event+0x8d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8d0;
	}
x86_l_8e5:
	/* 0x8e5: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8e8:
	/* 0x8e8: jmp    9b8 <generic_uprobe_process_event+0x9b8> */
	goto x86_l_9b8;
x86_l_8ed:
	/* 0x8ed: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_8f3:
	/* 0x8f3: jmp    9b8 <generic_uprobe_process_event+0x9b8> */
	goto x86_l_9b8;
x86_l_8f8:
	/* 0x8f8: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_8fd:
	/* 0x8fd: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_900:
	/* 0x900: bzhi   r13,QWORD PTR [rbx+0x40],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 64ULL);
x86_l_906:
	/* 0x906: jmp    28a <generic_uprobe_process_event+0x28a> */
	return 650ULL;
x86_l_90b:
	/* 0x90b: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_910:
	/* 0x910: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_913:
	/* 0x913: bzhi   r13,QWORD PTR [rbx+0x50],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 80ULL);
x86_l_919:
	/* 0x919: jmp    28a <generic_uprobe_process_event+0x28a> */
	return 650ULL;
x86_l_91e:
	/* 0x91e: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_923:
	/* 0x923: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_926:
	/* 0x926: bzhi   r13,QWORD PTR [rbx+0x80],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 128ULL);
x86_l_92f:
	/* 0x92f: jmp    28a <generic_uprobe_process_event+0x28a> */
	return 650ULL;
x86_l_934:
	/* 0x934: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_939:
	/* 0x939: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_93c:
	/* 0x93c: bzhi   r13,QWORD PTR [rbx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_941:
	/* 0x941: jmp    28a <generic_uprobe_process_event+0x28a> */
	return 650ULL;
x86_l_946:
	/* 0x946: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_94b:
	/* 0x94b: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_94e:
	/* 0x94e: bzhi   r13,QWORD PTR [rbx+0x20],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 32ULL);
x86_l_954:
	/* 0x954: jmp    28a <generic_uprobe_process_event+0x28a> */
	return 650ULL;
x86_l_959:
	/* 0x959: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_95e:
	/* 0x95e: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_961:
	/* 0x961: bzhi   r13,QWORD PTR [rbx+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 16ULL);
x86_l_967:
	/* 0x967: jmp    28a <generic_uprobe_process_event+0x28a> */
	return 650ULL;
x86_l_96c:
	/* 0x96c: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_971:
	/* 0x971: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_974:
	/* 0x974: bzhi   r13,QWORD PTR [rbx+0x30],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 48ULL);
x86_l_97a:
	/* 0x97a: jmp    28a <generic_uprobe_process_event+0x28a> */
	return 650ULL;
x86_l_97f:
	/* 0x97f: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_984:
	/* 0x984: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_987:
	/* 0x987: bzhi   r13,QWORD PTR [rbx+0x70],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 112ULL);
x86_l_98d:
	/* 0x98d: jmp    28a <generic_uprobe_process_event+0x28a> */
	return 650ULL;
x86_l_992:
	/* 0x992: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_997:
	/* 0x997: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_99a:
	/* 0x99a: bzhi   r13,QWORD PTR [rbx+0x60],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R13, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 96ULL);
x86_l_9a0:
	/* 0x9a0: jmp    28a <generic_uprobe_process_event+0x28a> */
	return 650ULL;
x86_l_9a5:
	/* 0x9a5: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_9ab:
	/* 0x9ab: jmp    9b8 <generic_uprobe_process_event+0x9b8> */
	goto x86_l_9b8;
x86_l_9ad:
	/* 0x9ad: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_9b3:
	/* 0x9b3: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9b8:
	/* 0x9b8: mov    DWORD PTR [rsp+0xcc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 876173328384ULL);
x86_l_9c3:
	/* 0x9c3: mov    rdi,QWORD PTR [rip+0x20c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_9ca:
	/* 0x9ca: lea    rsi,[rsp+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_9d2:
	/* 0x9d2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9d7:
	/* 0x9d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d9:
	/* 0x9d9: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9db:
	/* 0x9db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9de:
	/* 0x9de: je     4d3 <generic_uprobe_process_event+0x4d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1235ULL;
	}
x86_l_9e4:
	/* 0x9e4: mov    ecx,0x3ffb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16379ULL);
x86_l_9e9:
	/* 0x9e9: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_9ec:
	/* 0x9ec: cmp    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 144ULL);
x86_l_9f4:
	/* 0x9f4: jbe    4d3 <generic_uprobe_process_event+0x4d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1235ULL;
	}
x86_l_9fa:
	/* 0x9fa: mov    edx,DWORD PTR [rax+r12*4+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 24224ULL);
x86_l_a02:
	/* 0xa02: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a0a:
	/* 0xa0a: mov    DWORD PTR [rax+rcx*1+0x90],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 144ULL);
x86_l_a11:
	/* 0xa11: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a15:
	/* 0xa15: mov    QWORD PTR [rax+r12*8+0x5e78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 24184ULL);
x86_l_a1d:
	/* 0xa1d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a22:
	/* 0xa22: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_a24:
	/* 0xa24: jne    4d3 <generic_uprobe_process_event+0x4d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1235ULL;
	}
x86_l_a2a:
	/* 0xa2a: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_a2d:
	/* 0xa2d: add    r15,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_a34:
	/* 0xa34: add    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a37:
	/* 0xa37: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a3c:
	/* 0xa3c: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_a45:
	/* 0xa45: cmp    ebp,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 23ULL);
x86_l_a48:
	/* 0xa48: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a50:
	/* 0xa50: jg     a64 <generic_uprobe_process_event+0xa64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_a64;
	}
x86_l_a52:
	/* 0xa52: cmp    ebp,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 15ULL);
x86_l_a55:
	/* 0xa55: je     a93 <generic_uprobe_process_event+0xa93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a93;
	}
x86_l_a57:
	/* 0xa57: cmp    ebp,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_a5a:
	/* 0xa5a: jne    ac1 <generic_uprobe_process_event+0xac1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ac1;
	}
x86_l_a5c:
	/* 0xa5c: mov    r12,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSP, X86_WIDTH_64);
x86_l_a5f:
	/* 0xa5f: jmp    b60 <generic_uprobe_process_event+0xb60> */
	goto x86_l_b60;
x86_l_a64:
	/* 0xa64: cmp    ebp,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_a67:
	/* 0xa67: je     b3b <generic_uprobe_process_event+0xb3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b3b;
	}
x86_l_a6d:
	/* 0xa6d: cmp    ebp,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 42ULL);
x86_l_a70:
	/* 0xa70: jne    ac1 <generic_uprobe_process_event+0xac1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ac1;
	}
x86_l_a72:
	/* 0xa72: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_a7e:
	/* 0xa7e: mov    QWORD PTR [rsp+0xa8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_a86:
	/* 0xa86: lea    rax,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_a8e:
	/* 0xa8e: jmp    b81 <generic_uprobe_process_event+0xb81> */
	goto x86_l_b81;
x86_l_a93:
	/* 0xa93: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a98:
	/* 0xa98: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a9d:
	/* 0xa9d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_aa2:
	/* 0xaa2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_aa7:
	/* 0xaa7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_aac:
	/* 0xaac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aae:
	/* 0xaae: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ab3:
	/* 0xab3: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ab8:
	/* 0xab8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_abb:
	/* 0xabb: jne    b86 <generic_uprobe_process_event+0xb86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b86;
	}
x86_l_ac1:
	/* 0xac1: mov    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ac5:
	/* 0xac5: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_acd:
	/* 0xacd: mov    rdi,QWORD PTR [rip+0x20c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_ad4:
	/* 0xad4: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ad9:
	/* 0xad9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ade:
	/* 0xade: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ae0:
	/* 0xae0: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ae3:
	/* 0xae3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ae6:
	/* 0xae6: je     fb1 <generic_uprobe_process_event+0xfb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4017ULL;
	}
x86_l_aec:
	/* 0xaec: cmp    ebp,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 13ULL);
x86_l_aef:
	/* 0xaef: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_af7:
	/* 0xaf7: jle    1181 <generic_uprobe_process_event+0x1181> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4481ULL;
	}
x86_l_afd:
	/* 0xafd: cmp    ebp,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 30ULL);
x86_l_b00:
	/* 0xb00: jg     12da <generic_uprobe_process_event+0x12da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4826ULL;
	}
x86_l_b06:
	/* 0xb06: cmp    ebp,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 28ULL);
x86_l_b09:
	/* 0xb09: jg     1558 <generic_uprobe_process_event+0x1558> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5464ULL;
	}
x86_l_b0f:
	/* 0xb0f: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b14:
	/* 0xb14: cmp    ebp,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 14ULL);
x86_l_b17:
	/* 0xb17: je     1911 <generic_uprobe_process_event+0x1911> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6417ULL;
	}
x86_l_b1d:
	/* 0xb1d: cmp    ebp,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 17ULL);
x86_l_b20:
	/* 0xb20: je     1855 <generic_uprobe_process_event+0x1855> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6229ULL;
	}
x86_l_b26:
	/* 0xb26: cmp    ebp,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 28ULL);
x86_l_b29:
	/* 0xb29: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b31:
	/* 0xb31: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b36:
	/* 0xb36: jmp    133b <generic_uprobe_process_event+0x133b> */
	return 4923ULL;
x86_l_b3b:
	/* 0xb3b: mov    r12,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSP, X86_WIDTH_64);
x86_l_b3e:
	/* 0xb3e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b43:
	/* 0xb43: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b48:
	/* 0xb48: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b4d:
	/* 0xb4d: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_b50:
	/* 0xb50: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b55:
	/* 0xb55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b57:
	/* 0xb57: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b5b:
	/* 0xb5b: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b60:
	/* 0xb60: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b65:
	/* 0xb65: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b6a:
	/* 0xb6a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b6f:
	/* 0xb6f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b72:
	/* 0xb72: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b77:
	/* 0xb77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b79:
	/* 0xb79: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b7d:
	/* 0xb7d: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_b81:
	/* 0xb81: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b86:
	/* 0xb86: mov    DWORD PTR [rsp+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_b91:
	/* 0xb91: mov    rdi,QWORD PTR [rip+0x20c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_b98:
	/* 0xb98: lea    rsi,[rsp+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_ba0:
	/* 0xba0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ba5:
	/* 0xba5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ba7:
	/* 0xba7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_baa:
	/* 0xbaa: je     df3 <generic_uprobe_process_event+0xdf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_df3;
	}
x86_l_bb0:
	/* 0xbb0: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_bb3:
	/* 0xbb3: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bb8:
	/* 0xbb8: add    rax,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4096ULL);
x86_l_bbe:
	/* 0xbbe: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_bc6:
	/* 0xbc6: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_bcb:
	/* 0xbcb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bcd:
	/* 0xbcd: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_bd4:
	/* 0xbd4: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_bdc:
	/* 0xbdc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_be1:
	/* 0xbe1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_be6:
	/* 0xbe6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_beb:
	/* 0xbeb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bed:
	/* 0xbed: mov    r12,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_bf5:
	/* 0xbf5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bfa:
	/* 0xbfa: lea    rdx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bfe:
	/* 0xbfe: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_c06:
	/* 0xc06: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c0b:
	/* 0xc0b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c10:
	/* 0xc10: lea    rcx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c15:
	/* 0xc15: mov    QWORD PTR [rsp+0xd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_c1d:
	/* 0xc1d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c22:
	/* 0xc22: mov    QWORD PTR [rsp+0xd0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_c2a:
	/* 0xc2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2c:
	/* 0xc2c: mov    r15,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_c34:
	/* 0xc34: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c38:
	/* 0xc38: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c3d:
	/* 0xc3d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c42:
	/* 0xc42: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c47:
	/* 0xc47: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c4c:
	/* 0xc4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c4e:
	/* 0xc4e: cmp    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_c54:
	/* 0xc54: mov    ebp,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_c59:
	/* 0xc59: je     c65 <generic_uprobe_process_event+0xc65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c65;
	}
x86_l_c5b:
	/* 0xc5b: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c63:
	/* 0xc63: jmp    cb8 <generic_uprobe_process_event+0xcb8> */
	goto x86_l_cb8;
x86_l_c65:
	/* 0xc65: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c69:
	/* 0xc69: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c6e:
	/* 0xc6e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c73:
	/* 0xc73: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c78:
	/* 0xc78: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c7d:
	/* 0xc7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c7f:
	/* 0xc7f: cmp    QWORD PTR [rsp+0x28],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c84:
	/* 0xc84: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c8c:
	/* 0xc8c: je     cb8 <generic_uprobe_process_event+0xcb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cb8;
	}
x86_l_c8e:
	/* 0xc8e: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_c91:
	/* 0xc91: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_c98:
	/* 0xc98: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_ca2:
	/* 0xca2: mov    QWORD PTR [r13+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_ca9:
	/* 0xca9: mov    WORD PTR [r13+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_cb3:
	/* 0xcb3: mov    ebp,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4086ULL);
x86_l_cb8:
	/* 0xcb8: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_cc1:
	/* 0xcc1: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_cca:
	/* 0xcca: mov    QWORD PTR [rsp+0x38],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ccf:
	/* 0xccf: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_cd8:
	/* 0xcd8: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_ce1:
	/* 0xce1: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_cea:
	/* 0xcea: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_cf2:
	/* 0xcf2: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_cf7:
	/* 0xcf7: mov    DWORD PTR [rsp+0x60],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_cfb:
	/* 0xcfb: mov    BYTE PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_d00:
	/* 0xd00: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_d04:
	/* 0xd04: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d09:
	/* 0xd09: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d0e:
	/* 0xd0e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d13:
	/* 0xd13: lea    r13,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d18:
	/* 0xd18: lea    r15,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d1d:
	/* 0xd1d: lea    rbp,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d22:
	/* 0xd22: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d27:
	/* 0xd27: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d2a:
	/* 0xd2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d2c:
	/* 0xd2c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d31:
	/* 0xd31: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d36:
	/* 0xd36: mov    rdx,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_d3e:
	/* 0xd3e: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_d41:
	/* 0xd41: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d46:
	/* 0xd46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d48:
	/* 0xd48: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d4d:
	/* 0xd4d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d52:
	/* 0xd52: mov    rdx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_d5a:
	/* 0xd5a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_d5d:
	/* 0xd5d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d62:
	/* 0xd62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d64:
	/* 0xd64: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d69:
	/* 0xd69: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d6e:
	/* 0xd6e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d73:
	/* 0xd73: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_d76:
	/* 0xd76: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d7b:
	/* 0xd7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d7d:
	/* 0xd7d: mov    r12,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d82:
	/* 0xd82: lea    rax,[r12-0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551584ULL);
x86_l_d87:
	/* 0xd87: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d8c:
	/* 0xd8c: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d91:
	/* 0xd91: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_d96:
	/* 0xd96: jne    dfb <generic_uprobe_process_event+0xdfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_dfb;
	}
x86_l_d98:
	/* 0xd98: cmp    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_d9d:
	/* 0xd9d: jne    dfb <generic_uprobe_process_event+0xdfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_dfb;
	}
x86_l_d9f:
	/* 0xd9f: mov    BYTE PTR [rsp+0x64],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 429496729601ULL);
x86_l_da4:
	/* 0xda4: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_da9:
	/* 0xda9: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_db1:
	/* 0xdb1: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_db4:
	/* 0xdb4: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_db9:
	/* 0xdb9: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dbe:
	/* 0xdbe: je     f1d <generic_uprobe_process_event+0xf1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3869ULL;
	}
x86_l_dc4:
	/* 0xdc4: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dc6:
	/* 0xdc6: cmp    BYTE PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_dcb:
	/* 0xdcb: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_dce:
	/* 0xdce: mov    edx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_dd2:
	/* 0xdd2: mov    r13d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4096ULL);
x86_l_dd8:
	/* 0xdd8: sub    r13d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_ddb:
	/* 0xddb: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_ddd:
	/* 0xddd: cmovle r13d,edx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_de1:
	/* 0xde1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_de4:
	/* 0xde4: je     df3 <generic_uprobe_process_event+0xdf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_df3;
	}
x86_l_de6:
	/* 0xde6: mov    bpl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_8);
x86_l_de9:
	/* 0xde9: add    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_deb:
	/* 0xdeb: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_dee:
	/* 0xdee: jmp    f22 <generic_uprobe_process_event+0xf22> */
	return 3874ULL;
x86_l_df3:
	/* 0xdf3: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_df6:
	/* 0xdf6: jmp    fc3 <generic_uprobe_process_event+0xfc3> */
	return 4035ULL;
x86_l_dfb:
	/* 0xdfb: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e00:
	/* 0xe00: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e05:
	/* 0xe05: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e0a:
	/* 0xe0a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e0f:
	/* 0xe0f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_e12:
	/* 0xe12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e14:
	/* 0xe14: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_e19:
	/* 0xe19: je     ffa <generic_uprobe_process_event+0xffa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4090ULL;
	}
x86_l_e1f:
	/* 0xe1f: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e23:
	/* 0xe23: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_e26:
	/* 0xe26: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
	return 3627ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3627ULL: goto x86_l_e2b;
	case 3632ULL: goto x86_l_e30;
	case 3637ULL: goto x86_l_e35;
	case 3640ULL: goto x86_l_e38;
	case 3642ULL: goto x86_l_e3a;
	case 3646ULL: goto x86_l_e3e;
	case 3652ULL: goto x86_l_e44;
	case 3657ULL: goto x86_l_e49;
	case 3662ULL: goto x86_l_e4e;
	case 3667ULL: goto x86_l_e53;
	case 3672ULL: goto x86_l_e58;
	case 3675ULL: goto x86_l_e5b;
	case 3677ULL: goto x86_l_e5d;
	case 3681ULL: goto x86_l_e61;
	case 3686ULL: goto x86_l_e66;
	case 3691ULL: goto x86_l_e6b;
	case 3696ULL: goto x86_l_e70;
	case 3701ULL: goto x86_l_e75;
	case 3704ULL: goto x86_l_e78;
	case 3706ULL: goto x86_l_e7a;
	case 3711ULL: goto x86_l_e7f;
	case 3716ULL: goto x86_l_e84;
	case 3720ULL: goto x86_l_e88;
	case 3723ULL: goto x86_l_e8b;
	case 3728ULL: goto x86_l_e90;
	case 3730ULL: goto x86_l_e92;
	case 3732ULL: goto x86_l_e94;
	case 3735ULL: goto x86_l_e97;
	case 3738ULL: goto x86_l_e9a;
	case 3743ULL: goto x86_l_e9f;
	case 3745ULL: goto x86_l_ea1;
	case 3748ULL: goto x86_l_ea4;
	case 3752ULL: goto x86_l_ea8;
	case 3754ULL: goto x86_l_eaa;
	case 3758ULL: goto x86_l_eae;
	case 3760ULL: goto x86_l_eb0;
	case 3763ULL: goto x86_l_eb3;
	case 3765ULL: goto x86_l_eb5;
	case 3769ULL: goto x86_l_eb9;
	case 3772ULL: goto x86_l_ebc;
	case 3778ULL: goto x86_l_ec2;
	case 3784ULL: goto x86_l_ec8;
	case 3790ULL: goto x86_l_ece;
	case 3793ULL: goto x86_l_ed1;
	case 3795ULL: goto x86_l_ed3;
	case 3800ULL: goto x86_l_ed8;
	case 3802ULL: goto x86_l_eda;
	case 3805ULL: goto x86_l_edd;
	case 3809ULL: goto x86_l_ee1;
	case 3812ULL: goto x86_l_ee4;
	case 3815ULL: goto x86_l_ee7;
	case 3818ULL: goto x86_l_eea;
	case 3823ULL: goto x86_l_eef;
	case 3825ULL: goto x86_l_ef1;
	case 3830ULL: goto x86_l_ef6;
	case 3833ULL: goto x86_l_ef9;
	case 3839ULL: goto x86_l_eff;
	case 3844ULL: goto x86_l_f04;
	case 3849ULL: goto x86_l_f09;
	case 3854ULL: goto x86_l_f0e;
	case 3859ULL: goto x86_l_f13;
	case 3864ULL: goto x86_l_f18;
	case 3869ULL: goto x86_l_f1d;
	case 3871ULL: goto x86_l_f1f;
	case 3874ULL: goto x86_l_f22;
	case 3878ULL: goto x86_l_f26;
	case 3885ULL: goto x86_l_f2d;
	case 3890ULL: goto x86_l_f32;
	case 3893ULL: goto x86_l_f35;
	case 3895ULL: goto x86_l_f37;
	case 3898ULL: goto x86_l_f3a;
	case 3903ULL: goto x86_l_f3f;
	case 3908ULL: goto x86_l_f44;
	case 3913ULL: goto x86_l_f49;
	case 3921ULL: goto x86_l_f51;
	case 3926ULL: goto x86_l_f56;
	case 3928ULL: goto x86_l_f58;
	case 3933ULL: goto x86_l_f5d;
	case 3937ULL: goto x86_l_f61;
	case 3942ULL: goto x86_l_f66;
	case 3947ULL: goto x86_l_f6b;
	case 3952ULL: goto x86_l_f70;
	case 3957ULL: goto x86_l_f75;
	case 3961ULL: goto x86_l_f79;
	case 3966ULL: goto x86_l_f7e;
	case 3968ULL: goto x86_l_f80;
	case 3973ULL: goto x86_l_f85;
	case 3976ULL: goto x86_l_f88;
	case 3981ULL: goto x86_l_f8d;
	case 3986ULL: goto x86_l_f92;
	case 3991ULL: goto x86_l_f97;
	case 3996ULL: goto x86_l_f9c;
	case 3998ULL: goto x86_l_f9e;
	case 4003ULL: goto x86_l_fa3;
	case 4007ULL: goto x86_l_fa7;
	case 4013ULL: goto x86_l_fad;
	case 4017ULL: goto x86_l_fb1;
	case 4025ULL: goto x86_l_fb9;
	case 4030ULL: goto x86_l_fbe;
	case 4033ULL: goto x86_l_fc1;
	case 4035ULL: goto x86_l_fc3;
	case 4042ULL: goto x86_l_fca;
	case 4046ULL: goto x86_l_fce;
	case 4049ULL: goto x86_l_fd1;
	case 4054ULL: goto x86_l_fd6;
	case 4066ULL: goto x86_l_fe2;
	case 4074ULL: goto x86_l_fea;
	case 4085ULL: goto x86_l_ff5;
	case 4090ULL: goto x86_l_ffa;
	case 4095ULL: goto x86_l_fff;
	case 4098ULL: goto x86_l_1002;
	case 4103ULL: goto x86_l_1007;
	case 4108ULL: goto x86_l_100c;
	case 4113ULL: goto x86_l_1011;
	case 4115ULL: goto x86_l_1013;
	case 4120ULL: goto x86_l_1018;
	case 4124ULL: goto x86_l_101c;
	case 4130ULL: goto x86_l_1022;
	case 4134ULL: goto x86_l_1026;
	case 4139ULL: goto x86_l_102b;
	case 4144ULL: goto x86_l_1030;
	case 4147ULL: goto x86_l_1033;
	case 4152ULL: goto x86_l_1038;
	case 4155ULL: goto x86_l_103b;
	case 4157ULL: goto x86_l_103d;
	case 4161ULL: goto x86_l_1041;
	case 4166ULL: goto x86_l_1046;
	case 4171ULL: goto x86_l_104b;
	case 4176ULL: goto x86_l_1050;
	case 4181ULL: goto x86_l_1055;
	case 4186ULL: goto x86_l_105a;
	case 4188ULL: goto x86_l_105c;
	case 4193ULL: goto x86_l_1061;
	case 4199ULL: goto x86_l_1067;
	case 4204ULL: goto x86_l_106c;
	case 4209ULL: goto x86_l_1071;
	case 4214ULL: goto x86_l_1076;
	case 4219ULL: goto x86_l_107b;
	case 4221ULL: goto x86_l_107d;
	case 4226ULL: goto x86_l_1082;
	case 4232ULL: goto x86_l_1088;
	case 4236ULL: goto x86_l_108c;
	case 4239ULL: goto x86_l_108f;
	case 4244ULL: goto x86_l_1094;
	case 4249ULL: goto x86_l_1099;
	case 4254ULL: goto x86_l_109e;
	case 4257ULL: goto x86_l_10a1;
	case 4259ULL: goto x86_l_10a3;
	case 4263ULL: goto x86_l_10a7;
	case 4269ULL: goto x86_l_10ad;
	case 4274ULL: goto x86_l_10b2;
	case 4279ULL: goto x86_l_10b7;
	case 4284ULL: goto x86_l_10bc;
	case 4289ULL: goto x86_l_10c1;
	case 4292ULL: goto x86_l_10c4;
	case 4294ULL: goto x86_l_10c6;
	case 4298ULL: goto x86_l_10ca;
	case 4303ULL: goto x86_l_10cf;
	case 4308ULL: goto x86_l_10d4;
	case 4313ULL: goto x86_l_10d9;
	case 4318ULL: goto x86_l_10de;
	case 4321ULL: goto x86_l_10e1;
	case 4323ULL: goto x86_l_10e3;
	case 4328ULL: goto x86_l_10e8;
	case 4333ULL: goto x86_l_10ed;
	case 4337ULL: goto x86_l_10f1;
	case 4340ULL: goto x86_l_10f4;
	case 4345ULL: goto x86_l_10f9;
	case 4347ULL: goto x86_l_10fb;
	case 4349ULL: goto x86_l_10fd;
	case 4352ULL: goto x86_l_1100;
	case 4355ULL: goto x86_l_1103;
	case 4360ULL: goto x86_l_1108;
	case 4362ULL: goto x86_l_110a;
	case 4365ULL: goto x86_l_110d;
	case 4369ULL: goto x86_l_1111;
	case 4371ULL: goto x86_l_1113;
	case 4375ULL: goto x86_l_1117;
	case 4377ULL: goto x86_l_1119;
	case 4380ULL: goto x86_l_111c;
	case 4382ULL: goto x86_l_111e;
	case 4386ULL: goto x86_l_1122;
	case 4389ULL: goto x86_l_1125;
	case 4395ULL: goto x86_l_112b;
	case 4401ULL: goto x86_l_1131;
	case 4407ULL: goto x86_l_1137;
	case 4410ULL: goto x86_l_113a;
	case 4412ULL: goto x86_l_113c;
	case 4417ULL: goto x86_l_1141;
	case 4419ULL: goto x86_l_1143;
	case 4422ULL: goto x86_l_1146;
	case 4426ULL: goto x86_l_114a;
	case 4429ULL: goto x86_l_114d;
	case 4432ULL: goto x86_l_1150;
	case 4435ULL: goto x86_l_1153;
	case 4440ULL: goto x86_l_1158;
	case 4442ULL: goto x86_l_115a;
	case 4447ULL: goto x86_l_115f;
	case 4450ULL: goto x86_l_1162;
	case 4456ULL: goto x86_l_1168;
	case 4461ULL: goto x86_l_116d;
	case 4466ULL: goto x86_l_1172;
	case 4471ULL: goto x86_l_1177;
	case 4476ULL: goto x86_l_117c;
	case 4481ULL: goto x86_l_1181;
	case 4486ULL: goto x86_l_1186;
	case 4489ULL: goto x86_l_1189;
	case 4495ULL: goto x86_l_118f;
	case 4498ULL: goto x86_l_1192;
	case 4501ULL: goto x86_l_1195;
	case 4507ULL: goto x86_l_119b;
	case 4510ULL: goto x86_l_119e;
	case 4513ULL: goto x86_l_11a1;
	case 4519ULL: goto x86_l_11a7;
	case 4522ULL: goto x86_l_11aa;
	case 4530ULL: goto x86_l_11b2;
	case 4535ULL: goto x86_l_11b7;
	case 4541ULL: goto x86_l_11bd;
	case 4545ULL: goto x86_l_11c1;
	case 4550ULL: goto x86_l_11c6;
	case 4554ULL: goto x86_l_11ca;
	case 4558ULL: goto x86_l_11ce;
	case 4562ULL: goto x86_l_11d2;
	case 4567ULL: goto x86_l_11d7;
	case 4572ULL: goto x86_l_11dc;
	case 4577ULL: goto x86_l_11e1;
	case 4579ULL: goto x86_l_11e3;
	case 4583ULL: goto x86_l_11e7;
	case 4587ULL: goto x86_l_11eb;
	case 4592ULL: goto x86_l_11f0;
	case 4597ULL: goto x86_l_11f5;
	case 4602ULL: goto x86_l_11fa;
	case 4604ULL: goto x86_l_11fc;
	case 4608ULL: goto x86_l_1200;
	case 4615ULL: goto x86_l_1207;
	case 4620ULL: goto x86_l_120c;
	case 4625ULL: goto x86_l_1211;
	case 4630ULL: goto x86_l_1216;
	case 4632ULL: goto x86_l_1218;
	case 4636ULL: goto x86_l_121c;
	case 4643ULL: goto x86_l_1223;
	case 4648ULL: goto x86_l_1228;
	case 4653ULL: goto x86_l_122d;
	case 4658ULL: goto x86_l_1232;
	case 4660ULL: goto x86_l_1234;
	case 4664ULL: goto x86_l_1238;
	case 4671ULL: goto x86_l_123f;
	case 4676ULL: goto x86_l_1244;
	case 4681ULL: goto x86_l_1249;
	case 4686ULL: goto x86_l_124e;
	case 4688ULL: goto x86_l_1250;
	case 4692ULL: goto x86_l_1254;
	case 4699ULL: goto x86_l_125b;
	case 4704ULL: goto x86_l_1260;
	case 4709ULL: goto x86_l_1265;
	case 4714ULL: goto x86_l_126a;
	case 4716ULL: goto x86_l_126c;
	case 4720ULL: goto x86_l_1270;
	case 4727ULL: goto x86_l_1277;
	case 4735ULL: goto x86_l_127f;
	case 4743ULL: goto x86_l_1287;
	case 4751ULL: goto x86_l_128f;
	case 4756ULL: goto x86_l_1294;
	case 4759ULL: goto x86_l_1297;
	case 4765ULL: goto x86_l_129d;
	case 4768ULL: goto x86_l_12a0;
	case 4774ULL: goto x86_l_12a6;
	case 4778ULL: goto x86_l_12aa;
	case 4783ULL: goto x86_l_12af;
	case 4788ULL: goto x86_l_12b4;
	case 4793ULL: goto x86_l_12b9;
	case 4798ULL: goto x86_l_12be;
	case 4800ULL: goto x86_l_12c0;
	case 4805ULL: goto x86_l_12c5;
	case 4810ULL: goto x86_l_12ca;
	case 4813ULL: goto x86_l_12cd;
	case 4818ULL: goto x86_l_12d2;
	case 4821ULL: goto x86_l_12d5;
	case 4826ULL: goto x86_l_12da;
	case 4831ULL: goto x86_l_12df;
	case 4834ULL: goto x86_l_12e2;
	case 4840ULL: goto x86_l_12e8;
	case 4843ULL: goto x86_l_12eb;
	case 4846ULL: goto x86_l_12ee;
	case 4849ULL: goto x86_l_12f1;
	case 4855ULL: goto x86_l_12f7;
	case 4858ULL: goto x86_l_12fa;
	case 4864ULL: goto x86_l_1300;
	case 4869ULL: goto x86_l_1305;
	case 4874ULL: goto x86_l_130a;
	case 4879ULL: goto x86_l_130f;
	case 4884ULL: goto x86_l_1314;
	case 4886ULL: goto x86_l_1316;
	case 4889ULL: goto x86_l_1319;
	case 4894ULL: goto x86_l_131e;
	case 4897ULL: goto x86_l_1321;
	case 4903ULL: goto x86_l_1327;
	case 4906ULL: goto x86_l_132a;
	case 4912ULL: goto x86_l_1330;
	case 4915ULL: goto x86_l_1333;
	case 4923ULL: goto x86_l_133b;
	case 4928ULL: goto x86_l_1340;
	case 4934ULL: goto x86_l_1346;
	case 4940ULL: goto x86_l_134c;
	case 4943ULL: goto x86_l_134f;
	case 4948ULL: goto x86_l_1354;
	case 4951ULL: goto x86_l_1357;
	case 4956ULL: goto x86_l_135c;
	case 4961ULL: goto x86_l_1361;
	case 4966ULL: goto x86_l_1366;
	case 4968ULL: goto x86_l_1368;
	case 4973ULL: goto x86_l_136d;
	case 4976ULL: goto x86_l_1370;
	case 4981ULL: goto x86_l_1375;
	case 4986ULL: goto x86_l_137a;
	case 4989ULL: goto x86_l_137d;
	case 4994ULL: goto x86_l_1382;
	case 4999ULL: goto x86_l_1387;
	case 5004ULL: goto x86_l_138c;
	case 5006ULL: goto x86_l_138e;
	case 5011ULL: goto x86_l_1393;
	case 5015ULL: goto x86_l_1397;
	case 5021ULL: goto x86_l_139d;
	case 5025ULL: goto x86_l_13a1;
	case 5030ULL: goto x86_l_13a6;
	case 5035ULL: goto x86_l_13ab;
	case 5038ULL: goto x86_l_13ae;
	case 5043ULL: goto x86_l_13b3;
	case 5046ULL: goto x86_l_13b6;
	case 5048ULL: goto x86_l_13b8;
	case 5052ULL: goto x86_l_13bc;
	case 5057ULL: goto x86_l_13c1;
	case 5062ULL: goto x86_l_13c6;
	case 5067ULL: goto x86_l_13cb;
	case 5072ULL: goto x86_l_13d0;
	case 5077ULL: goto x86_l_13d5;
	case 5079ULL: goto x86_l_13d7;
	case 5084ULL: goto x86_l_13dc;
	case 5090ULL: goto x86_l_13e2;
	case 5095ULL: goto x86_l_13e7;
	case 5100ULL: goto x86_l_13ec;
	case 5105ULL: goto x86_l_13f1;
	case 5110ULL: goto x86_l_13f6;
	case 5115ULL: goto x86_l_13fb;
	case 5117ULL: goto x86_l_13fd;
	case 5122ULL: goto x86_l_1402;
	case 5128ULL: goto x86_l_1408;
	case 5132ULL: goto x86_l_140c;
	case 5135ULL: goto x86_l_140f;
	case 5140ULL: goto x86_l_1414;
	case 5145ULL: goto x86_l_1419;
	case 5150ULL: goto x86_l_141e;
	case 5153ULL: goto x86_l_1421;
	case 5155ULL: goto x86_l_1423;
	case 5159ULL: goto x86_l_1427;
	case 5165ULL: goto x86_l_142d;
	case 5170ULL: goto x86_l_1432;
	case 5175ULL: goto x86_l_1437;
	case 5180ULL: goto x86_l_143c;
	case 5185ULL: goto x86_l_1441;
	case 5188ULL: goto x86_l_1444;
	case 5190ULL: goto x86_l_1446;
	case 5194ULL: goto x86_l_144a;
	case 5199ULL: goto x86_l_144f;
	case 5204ULL: goto x86_l_1454;
	case 5209ULL: goto x86_l_1459;
	case 5214ULL: goto x86_l_145e;
	case 5217ULL: goto x86_l_1461;
	case 5219ULL: goto x86_l_1463;
	case 5224ULL: goto x86_l_1468;
	case 5229ULL: goto x86_l_146d;
	case 5233ULL: goto x86_l_1471;
	case 5236ULL: goto x86_l_1474;
	case 5241ULL: goto x86_l_1479;
	case 5243ULL: goto x86_l_147b;
	case 5245ULL: goto x86_l_147d;
	case 5248ULL: goto x86_l_1480;
	case 5251ULL: goto x86_l_1483;
	case 5256ULL: goto x86_l_1488;
	case 5258ULL: goto x86_l_148a;
	case 5261ULL: goto x86_l_148d;
	case 5265ULL: goto x86_l_1491;
	case 5267ULL: goto x86_l_1493;
	case 5271ULL: goto x86_l_1497;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e2b:
	/* 0xe2b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e30:
	/* 0xe30: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e35:
	/* 0xe35: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_e38:
	/* 0xe38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e3a:
	/* 0xe3a: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e3e:
	/* 0xe3e: je     ffa <generic_uprobe_process_event+0xffa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ffa;
	}
x86_l_e44:
	/* 0xe44: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e49:
	/* 0xe49: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e4e:
	/* 0xe4e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e53:
	/* 0xe53: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e58:
	/* 0xe58: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_e5b:
	/* 0xe5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e5d:
	/* 0xe5d: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_e61:
	/* 0xe61: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e66:
	/* 0xe66: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_e6b:
	/* 0xe6b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e70:
	/* 0xe70: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_e75:
	/* 0xe75: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_e78:
	/* 0xe78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e7a:
	/* 0xe7a: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e7f:
	/* 0xe7f: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e84:
	/* 0xe84: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_e88:
	/* 0xe88: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_e8b:
	/* 0xe8b: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e90:
	/* 0xe90: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e92:
	/* 0xe92: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_e94:
	/* 0xe94: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_e97:
	/* 0xe97: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_e9a:
	/* 0xe9a: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_e9f:
	/* 0xe9f: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ea1:
	/* 0xea1: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_ea4:
	/* 0xea4: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_ea8:
	/* 0xea8: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_eaa:
	/* 0xeaa: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_eae:
	/* 0xeae: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_eb0:
	/* 0xeb0: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_eb3:
	/* 0xeb3: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_eb5:
	/* 0xeb5: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_eb9:
	/* 0xeb9: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_ebc:
	/* 0xebc: jb     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3492ULL;
	}
x86_l_ec2:
	/* 0xec2: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_ec8:
	/* 0xec8: ja     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3492ULL;
	}
x86_l_ece:
	/* 0xece: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_ed1:
	/* 0xed1: jbe    ed8 <generic_uprobe_process_event+0xed8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_ed8;
	}
x86_l_ed3:
	/* 0xed3: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_ed8:
	/* 0xed8: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_eda:
	/* 0xeda: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_edd:
	/* 0xedd: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_ee1:
	/* 0xee1: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ee4:
	/* 0xee4: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ee7:
	/* 0xee7: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_eea:
	/* 0xeea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_eef:
	/* 0xeef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef1:
	/* 0xef1: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_ef6:
	/* 0xef6: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_ef9:
	/* 0xef9: jbe    da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3492ULL;
	}
x86_l_eff:
	/* 0xeff: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_f04:
	/* 0xf04: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f09:
	/* 0xf09: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f0e:
	/* 0xf0e: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f13:
	/* 0xf13: lea    r15,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f18:
	/* 0xf18: jmp    1055 <generic_uprobe_process_event+0x1055> */
	goto x86_l_1055;
x86_l_f1d:
	/* 0xf1d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f1f:
	/* 0xf1f: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f22:
	/* 0xf22: lea    rdi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f26:
	/* 0xf26: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f2d:
	/* 0xf2d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f32:
	/* 0xf32: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_f35:
	/* 0xf35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f37:
	/* 0xf37: mov    DWORD PTR [r15],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f3a:
	/* 0xf3a: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f3f:
	/* 0xf3f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f44:
	/* 0xf44: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f49:
	/* 0xf49: mov    rdx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_f51:
	/* 0xf51: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f56:
	/* 0xf56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f58:
	/* 0xf58: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f5d:
	/* 0xf5d: add    rcx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_f61:
	/* 0xf61: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f66:
	/* 0xf66: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_f6b:
	/* 0xf6b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f70:
	/* 0xf70: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f75:
	/* 0xf75: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_f79:
	/* 0xf79: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f7e:
	/* 0xf7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f80:
	/* 0xf80: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f85:
	/* 0xf85: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_f88:
	/* 0xf88: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_f8d:
	/* 0xf8d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f92:
	/* 0xf92: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f97:
	/* 0xf97: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_f9c:
	/* 0xf9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f9e:
	/* 0xf9e: mov    DWORD PTR [r15+r13*1+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 4ULL);
x86_l_fa3:
	/* 0xfa3: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_fa7:
	/* 0xfa7: mov    WORD PTR [r15+r13*1+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_fad:
	/* 0xfad: add    r13d,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_fb1:
	/* 0xfb1: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_fb9:
	/* 0xfb9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fbe:
	/* 0xfbe: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_fc1:
	/* 0xfc1: js     fd6 <generic_uprobe_process_event+0xfd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_fd6;
	}
x86_l_fc3:
	/* 0xfc3: and    r13d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_fca:
	/* 0xfca: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_fce:
	/* 0xfce: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_fd1:
	/* 0xfd1: jmp    4d3 <generic_uprobe_process_event+0x4d3> */
	return 1235ULL;
x86_l_fd6:
	/* 0xfd6: mov    DWORD PTR [rax+r12*4+0x5ea0],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 104045582745599ULL);
x86_l_fe2:
	/* 0xfe2: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_fea:
	/* 0xfea: mov    DWORD PTR [rax+rcx*1+0x90],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 622770257919ULL);
x86_l_ff5:
	/* 0xff5: jmp    4d3 <generic_uprobe_process_event+0x4d3> */
	return 1235ULL;
x86_l_ffa:
	/* 0xffa: lea    rdx,[r12-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_fff:
	/* 0xfff: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1002:
	/* 0x1002: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1007:
	/* 0x1007: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_100c:
	/* 0x100c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1011:
	/* 0x1011: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1013:
	/* 0x1013: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1018:
	/* 0x1018: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_101c:
	/* 0x101c: je     d9f <generic_uprobe_process_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3487ULL;
	}
x86_l_1022:
	/* 0x1022: add    r12,0xfffffffffffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551608ULL);
x86_l_1026:
	/* 0x1026: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_102b:
	/* 0x102b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1030:
	/* 0x1030: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1033:
	/* 0x1033: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1038:
	/* 0x1038: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_103b:
	/* 0x103b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_103d:
	/* 0x103d: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1041:
	/* 0x1041: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1046:
	/* 0x1046: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_104b:
	/* 0x104b: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1050:
	/* 0x1050: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1055:
	/* 0x1055: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_105a:
	/* 0x105a: jne    1067 <generic_uprobe_process_event+0x1067> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1067;
	}
x86_l_105c:
	/* 0x105c: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_1061:
	/* 0x1061: je     d9f <generic_uprobe_process_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3487ULL;
	}
x86_l_1067:
	/* 0x1067: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_106c:
	/* 0x106c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1071:
	/* 0x1071: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1076:
	/* 0x1076: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_107b:
	/* 0x107b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_107d:
	/* 0x107d: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_1082:
	/* 0x1082: je     1375 <generic_uprobe_process_event+0x1375> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1375;
	}
x86_l_1088:
	/* 0x1088: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_108c:
	/* 0x108c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_108f:
	/* 0x108f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1094:
	/* 0x1094: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1099:
	/* 0x1099: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_109e:
	/* 0x109e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_10a1:
	/* 0x10a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10a3:
	/* 0x10a3: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10a7:
	/* 0x10a7: je     1375 <generic_uprobe_process_event+0x1375> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1375;
	}
x86_l_10ad:
	/* 0x10ad: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_10b2:
	/* 0x10b2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10b7:
	/* 0x10b7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10bc:
	/* 0x10bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10c1:
	/* 0x10c1: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_10c4:
	/* 0x10c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10c6:
	/* 0x10c6: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_10ca:
	/* 0x10ca: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10cf:
	/* 0x10cf: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_10d4:
	/* 0x10d4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10d9:
	/* 0x10d9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_10de:
	/* 0x10de: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_10e1:
	/* 0x10e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10e3:
	/* 0x10e3: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_10e8:
	/* 0x10e8: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_10ed:
	/* 0x10ed: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_10f1:
	/* 0x10f1: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_10f4:
	/* 0x10f4: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_10f9:
	/* 0x10f9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10fb:
	/* 0x10fb: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_10fd:
	/* 0x10fd: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1100:
	/* 0x1100: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1103:
	/* 0x1103: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1108:
	/* 0x1108: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_110a:
	/* 0x110a: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_110d:
	/* 0x110d: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_1111:
	/* 0x1111: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1113:
	/* 0x1113: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_1117:
	/* 0x1117: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1119:
	/* 0x1119: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_111c:
	/* 0x111c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_111e:
	/* 0x111e: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1122:
	/* 0x1122: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1125:
	/* 0x1125: jb     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3492ULL;
	}
x86_l_112b:
	/* 0x112b: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_1131:
	/* 0x1131: ja     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3492ULL;
	}
x86_l_1137:
	/* 0x1137: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_113a:
	/* 0x113a: jbe    1141 <generic_uprobe_process_event+0x1141> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1141;
	}
x86_l_113c:
	/* 0x113c: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_1141:
	/* 0x1141: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1143:
	/* 0x1143: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1146:
	/* 0x1146: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_114a:
	/* 0x114a: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_114d:
	/* 0x114d: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1150:
	/* 0x1150: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1153:
	/* 0x1153: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1158:
	/* 0x1158: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_115a:
	/* 0x115a: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_115f:
	/* 0x115f: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1162:
	/* 0x1162: jbe    da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3492ULL;
	}
x86_l_1168:
	/* 0x1168: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_116d:
	/* 0x116d: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1172:
	/* 0x1172: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1177:
	/* 0x1177: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_117c:
	/* 0x117c: jmp    13d0 <generic_uprobe_process_event+0x13d0> */
	goto x86_l_13d0;
x86_l_1181:
	/* 0x1181: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1186:
	/* 0x1186: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1189:
	/* 0x1189: jle    131e <generic_uprobe_process_event+0x131e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_131e;
	}
x86_l_118f:
	/* 0x118f: lea    ecx,[rbp-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_1192:
	/* 0x1192: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1195:
	/* 0x1195: jb     1346 <generic_uprobe_process_event+0x1346> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1346;
	}
x86_l_119b:
	/* 0x119b: lea    eax,[rbp-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_119e:
	/* 0x119e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_11a1:
	/* 0x11a1: jb     150b <generic_uprobe_process_event+0x150b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5387ULL;
	}
x86_l_11a7:
	/* 0x11a7: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_11aa:
	/* 0x11aa: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_11b2:
	/* 0x11b2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_11b7:
	/* 0x11b7: jne    fbe <generic_uprobe_process_event+0xfbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fbe;
	}
x86_l_11bd:
	/* 0x11bd: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11c1:
	/* 0x11c1: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11c6:
	/* 0x11c6: mov    QWORD PTR [r15+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11ca:
	/* 0x11ca: lea    rdi,[r15+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_11ce:
	/* 0x11ce: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11d2:
	/* 0x11d2: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_11d7:
	/* 0x11d7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11dc:
	/* 0x11dc: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_11e1:
	/* 0x11e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11e3:
	/* 0x11e3: lea    rdi,[r15+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_11e7:
	/* 0x11e7: lea    rdx,[r13+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_11eb:
	/* 0x11eb: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11f0:
	/* 0x11f0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11f5:
	/* 0x11f5: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_11fa:
	/* 0x11fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11fc:
	/* 0x11fc: lea    rdi,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1200:
	/* 0x1200: lea    rdx,[r13+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_1207:
	/* 0x1207: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_120c:
	/* 0x120c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1211:
	/* 0x1211: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1216:
	/* 0x1216: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1218:
	/* 0x1218: lea    rdi,[r15+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_121c:
	/* 0x121c: lea    rdx,[r13+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_1223:
	/* 0x1223: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1228:
	/* 0x1228: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_122d:
	/* 0x122d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1232:
	/* 0x1232: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1234:
	/* 0x1234: lea    rdi,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1238:
	/* 0x1238: lea    rdx,[r13+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_123f:
	/* 0x123f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1244:
	/* 0x1244: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1249:
	/* 0x1249: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_124e:
	/* 0x124e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1250:
	/* 0x1250: lea    rdi,[r15+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1254:
	/* 0x1254: lea    rdx,[r13+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_125b:
	/* 0x125b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1260:
	/* 0x1260: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1265:
	/* 0x1265: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_126a:
	/* 0x126a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_126c:
	/* 0x126c: lea    r12,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1270:
	/* 0x1270: mov    QWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1277:
	/* 0x1277: mov    QWORD PTR [r15+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_127f:
	/* 0x127f: mov    QWORD PTR [r15+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1287:
	/* 0x1287: mov    QWORD PTR [r15+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_128f:
	/* 0x128f: movzx  eax,WORD PTR [r15+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1294:
	/* 0x1294: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1297:
	/* 0x1297: je     1c30 <generic_uprobe_process_event+0x1c30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7216ULL;
	}
x86_l_129d:
	/* 0x129d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12a0:
	/* 0x12a0: jne    1c62 <generic_uprobe_process_event+0x1c62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7266ULL;
	}
x86_l_12a6:
	/* 0x12a6: lea    rdx,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_12aa:
	/* 0x12aa: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12af:
	/* 0x12af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12b4:
	/* 0x12b4: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12b9:
	/* 0x12b9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12be:
	/* 0x12be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12c0:
	/* 0x12c0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12c5:
	/* 0x12c5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12ca:
	/* 0x12ca: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_12cd:
	/* 0x12cd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12d2:
	/* 0x12d2: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_12d5:
	/* 0x12d5: jmp    1c60 <generic_uprobe_process_event+0x1c60> */
	return 7264ULL;
x86_l_12da:
	/* 0x12da: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12df:
	/* 0x12df: cmp    ebp,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 38ULL);
x86_l_12e2:
	/* 0x12e2: jg     157a <generic_uprobe_process_event+0x157a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5498ULL;
	}
x86_l_12e8:
	/* 0x12e8: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_12eb:
	/* 0x12eb: lea    eax,[rbp-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_12ee:
	/* 0x12ee: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12f1:
	/* 0x12f1: jae    163c <generic_uprobe_process_event+0x163c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5692ULL;
	}
x86_l_12f7:
	/* 0x12f7: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_12fa:
	/* 0x12fa: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1300:
	/* 0x1300: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1305:
	/* 0x1305: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_130a:
	/* 0x130a: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_130f:
	/* 0x130f: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1314:
	/* 0x1314: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1316:
	/* 0x1316: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_1319:
	/* 0x1319: jmp    fb9 <generic_uprobe_process_event+0xfb9> */
	goto x86_l_fb9;
x86_l_131e:
	/* 0x131e: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1321:
	/* 0x1321: jg     152f <generic_uprobe_process_event+0x152f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5423ULL;
	}
x86_l_1327:
	/* 0x1327: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_132a:
	/* 0x132a: je     150b <generic_uprobe_process_event+0x150b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5387ULL;
	}
x86_l_1330:
	/* 0x1330: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1333:
	/* 0x1333: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_133b:
	/* 0x133b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1340:
	/* 0x1340: jne    fbe <generic_uprobe_process_event+0xfbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fbe;
	}
x86_l_1346:
	/* 0x1346: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_134c:
	/* 0x134c: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_134f:
	/* 0x134f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1354:
	/* 0x1354: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1357:
	/* 0x1357: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_135c:
	/* 0x135c: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1361:
	/* 0x1361: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1366:
	/* 0x1366: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1368:
	/* 0x1368: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_136d:
	/* 0x136d: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_1370:
	/* 0x1370: jmp    fbe <generic_uprobe_process_event+0xfbe> */
	goto x86_l_fbe;
x86_l_1375:
	/* 0x1375: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_137a:
	/* 0x137a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_137d:
	/* 0x137d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1382:
	/* 0x1382: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1387:
	/* 0x1387: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_138c:
	/* 0x138c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_138e:
	/* 0x138e: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1393:
	/* 0x1393: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1397:
	/* 0x1397: je     d9f <generic_uprobe_process_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3487ULL;
	}
x86_l_139d:
	/* 0x139d: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_13a1:
	/* 0x13a1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13a6:
	/* 0x13a6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13ab:
	/* 0x13ab: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_13ae:
	/* 0x13ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13b3:
	/* 0x13b3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_13b6:
	/* 0x13b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b8:
	/* 0x13b8: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13bc:
	/* 0x13bc: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_13c1:
	/* 0x13c1: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13c6:
	/* 0x13c6: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_13cb:
	/* 0x13cb: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13d0:
	/* 0x13d0: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_13d5:
	/* 0x13d5: jne    13e2 <generic_uprobe_process_event+0x13e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13e2;
	}
x86_l_13d7:
	/* 0x13d7: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_13dc:
	/* 0x13dc: je     d9f <generic_uprobe_process_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3487ULL;
	}
x86_l_13e2:
	/* 0x13e2: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13e7:
	/* 0x13e7: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_13ec:
	/* 0x13ec: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13f1:
	/* 0x13f1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13f6:
	/* 0x13f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13fb:
	/* 0x13fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13fd:
	/* 0x13fd: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_1402:
	/* 0x1402: je     19d6 <generic_uprobe_process_event+0x19d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6614ULL;
	}
x86_l_1408:
	/* 0x1408: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_140c:
	/* 0x140c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_140f:
	/* 0x140f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1414:
	/* 0x1414: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1419:
	/* 0x1419: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_141e:
	/* 0x141e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1421:
	/* 0x1421: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1423:
	/* 0x1423: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1427:
	/* 0x1427: je     19d6 <generic_uprobe_process_event+0x19d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6614ULL;
	}
x86_l_142d:
	/* 0x142d: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1432:
	/* 0x1432: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1437:
	/* 0x1437: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_143c:
	/* 0x143c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1441:
	/* 0x1441: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1444:
	/* 0x1444: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1446:
	/* 0x1446: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_144a:
	/* 0x144a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_144f:
	/* 0x144f: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1454:
	/* 0x1454: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1459:
	/* 0x1459: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_145e:
	/* 0x145e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1461:
	/* 0x1461: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1463:
	/* 0x1463: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1468:
	/* 0x1468: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_146d:
	/* 0x146d: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1471:
	/* 0x1471: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1474:
	/* 0x1474: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1479:
	/* 0x1479: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_147b:
	/* 0x147b: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_147d:
	/* 0x147d: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1480:
	/* 0x1480: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1483:
	/* 0x1483: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1488:
	/* 0x1488: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_148a:
	/* 0x148a: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_148d:
	/* 0x148d: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_1491:
	/* 0x1491: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1493:
	/* 0x1493: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_1497:
	/* 0x1497: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
	return 5273ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5273ULL: goto x86_l_1499;
	case 5276ULL: goto x86_l_149c;
	case 5278ULL: goto x86_l_149e;
	case 5282ULL: goto x86_l_14a2;
	case 5285ULL: goto x86_l_14a5;
	case 5290ULL: goto x86_l_14aa;
	case 5296ULL: goto x86_l_14b0;
	case 5302ULL: goto x86_l_14b6;
	case 5308ULL: goto x86_l_14bc;
	case 5311ULL: goto x86_l_14bf;
	case 5313ULL: goto x86_l_14c1;
	case 5318ULL: goto x86_l_14c6;
	case 5320ULL: goto x86_l_14c8;
	case 5323ULL: goto x86_l_14cb;
	case 5327ULL: goto x86_l_14cf;
	case 5330ULL: goto x86_l_14d2;
	case 5333ULL: goto x86_l_14d5;
	case 5336ULL: goto x86_l_14d8;
	case 5341ULL: goto x86_l_14dd;
	case 5343ULL: goto x86_l_14df;
	case 5348ULL: goto x86_l_14e4;
	case 5351ULL: goto x86_l_14e7;
	case 5356ULL: goto x86_l_14ec;
	case 5362ULL: goto x86_l_14f2;
	case 5367ULL: goto x86_l_14f7;
	case 5372ULL: goto x86_l_14fc;
	case 5377ULL: goto x86_l_1501;
	case 5382ULL: goto x86_l_1506;
	case 5387ULL: goto x86_l_150b;
	case 5390ULL: goto x86_l_150e;
	case 5396ULL: goto x86_l_1514;
	case 5401ULL: goto x86_l_1519;
	case 5406ULL: goto x86_l_151e;
	case 5411ULL: goto x86_l_1523;
	case 5416ULL: goto x86_l_1528;
	case 5418ULL: goto x86_l_152a;
	case 5423ULL: goto x86_l_152f;
	case 5426ULL: goto x86_l_1532;
	case 5432ULL: goto x86_l_1538;
	case 5435ULL: goto x86_l_153b;
	case 5443ULL: goto x86_l_1543;
	case 5448ULL: goto x86_l_1548;
	case 5453ULL: goto x86_l_154d;
	case 5459ULL: goto x86_l_1553;
	case 5464ULL: goto x86_l_1558;
	case 5467ULL: goto x86_l_155b;
	case 5473ULL: goto x86_l_1561;
	case 5478ULL: goto x86_l_1566;
	case 5483ULL: goto x86_l_156b;
	case 5486ULL: goto x86_l_156e;
	case 5491ULL: goto x86_l_1573;
	case 5493ULL: goto x86_l_1575;
	case 5498ULL: goto x86_l_157a;
	case 5503ULL: goto x86_l_157f;
	case 5506ULL: goto x86_l_1582;
	case 5509ULL: goto x86_l_1585;
	case 5515ULL: goto x86_l_158b;
	case 5518ULL: goto x86_l_158e;
	case 5521ULL: goto x86_l_1591;
	case 5526ULL: goto x86_l_1596;
	case 5531ULL: goto x86_l_159b;
	case 5536ULL: goto x86_l_15a0;
	case 5542ULL: goto x86_l_15a6;
	case 5546ULL: goto x86_l_15aa;
	case 5551ULL: goto x86_l_15af;
	case 5559ULL: goto x86_l_15b7;
	case 5567ULL: goto x86_l_15bf;
	case 5574ULL: goto x86_l_15c6;
	case 5579ULL: goto x86_l_15cb;
	case 5584ULL: goto x86_l_15d0;
	case 5589ULL: goto x86_l_15d5;
	case 5592ULL: goto x86_l_15d8;
	case 5594ULL: goto x86_l_15da;
	case 5597ULL: goto x86_l_15dd;
	case 5603ULL: goto x86_l_15e3;
	case 5608ULL: goto x86_l_15e8;
	case 5611ULL: goto x86_l_15eb;
	case 5614ULL: goto x86_l_15ee;
	case 5620ULL: goto x86_l_15f4;
	case 5623ULL: goto x86_l_15f7;
	case 5629ULL: goto x86_l_15fd;
	case 5634ULL: goto x86_l_1602;
	case 5639ULL: goto x86_l_1607;
	case 5644ULL: goto x86_l_160c;
	case 5649ULL: goto x86_l_1611;
	case 5654ULL: goto x86_l_1616;
	case 5656ULL: goto x86_l_1618;
	case 5660ULL: goto x86_l_161c;
	case 5665ULL: goto x86_l_1621;
	case 5669ULL: goto x86_l_1625;
	case 5673ULL: goto x86_l_1629;
	case 5677ULL: goto x86_l_162d;
	case 5682ULL: goto x86_l_1632;
	case 5687ULL: goto x86_l_1637;
	case 5692ULL: goto x86_l_163c;
	case 5695ULL: goto x86_l_163f;
	case 5698ULL: goto x86_l_1642;
	case 5703ULL: goto x86_l_1647;
	case 5709ULL: goto x86_l_164d;
	case 5713ULL: goto x86_l_1651;
	case 5716ULL: goto x86_l_1654;
	case 5719ULL: goto x86_l_1657;
	case 5722ULL: goto x86_l_165a;
	case 5725ULL: goto x86_l_165d;
	case 5731ULL: goto x86_l_1663;
	case 5736ULL: goto x86_l_1668;
	case 5740ULL: goto x86_l_166c;
	case 5742ULL: goto x86_l_166e;
	case 5747ULL: goto x86_l_1673;
	case 5749ULL: goto x86_l_1675;
	case 5752ULL: goto x86_l_1678;
	case 5755ULL: goto x86_l_167b;
	case 5757ULL: goto x86_l_167d;
	case 5761ULL: goto x86_l_1681;
	case 5766ULL: goto x86_l_1686;
	case 5768ULL: goto x86_l_1688;
	case 5772ULL: goto x86_l_168c;
	case 5775ULL: goto x86_l_168f;
	case 5780ULL: goto x86_l_1694;
	case 5785ULL: goto x86_l_1699;
	case 5788ULL: goto x86_l_169c;
	case 5793ULL: goto x86_l_16a1;
	case 5797ULL: goto x86_l_16a5;
	case 5802ULL: goto x86_l_16aa;
	case 5806ULL: goto x86_l_16ae;
	case 5813ULL: goto x86_l_16b5;
	case 5818ULL: goto x86_l_16ba;
	case 5823ULL: goto x86_l_16bf;
	case 5828ULL: goto x86_l_16c4;
	case 5830ULL: goto x86_l_16c6;
	case 5834ULL: goto x86_l_16ca;
	case 5838ULL: goto x86_l_16ce;
	case 5843ULL: goto x86_l_16d3;
	case 5848ULL: goto x86_l_16d8;
	case 5853ULL: goto x86_l_16dd;
	case 5855ULL: goto x86_l_16df;
	case 5859ULL: goto x86_l_16e3;
	case 5866ULL: goto x86_l_16ea;
	case 5871ULL: goto x86_l_16ef;
	case 5876ULL: goto x86_l_16f4;
	case 5881ULL: goto x86_l_16f9;
	case 5883ULL: goto x86_l_16fb;
	case 5887ULL: goto x86_l_16ff;
	case 5894ULL: goto x86_l_1706;
	case 5899ULL: goto x86_l_170b;
	case 5904ULL: goto x86_l_1710;
	case 5909ULL: goto x86_l_1715;
	case 5911ULL: goto x86_l_1717;
	case 5920ULL: goto x86_l_1720;
	case 5927ULL: goto x86_l_1727;
	case 5932ULL: goto x86_l_172c;
	case 5937ULL: goto x86_l_1731;
	case 5942ULL: goto x86_l_1736;
	case 5947ULL: goto x86_l_173b;
	case 5949ULL: goto x86_l_173d;
	case 5956ULL: goto x86_l_1744;
	case 5961ULL: goto x86_l_1749;
	case 5966ULL: goto x86_l_174e;
	case 5971ULL: goto x86_l_1753;
	case 5976ULL: goto x86_l_1758;
	case 5978ULL: goto x86_l_175a;
	case 5984ULL: goto x86_l_1760;
	case 5989ULL: goto x86_l_1765;
	case 5997ULL: goto x86_l_176d;
	case 6002ULL: goto x86_l_1772;
	case 6007ULL: goto x86_l_1777;
	case 6012ULL: goto x86_l_177c;
	case 6015ULL: goto x86_l_177f;
	case 6017ULL: goto x86_l_1781;
	case 6025ULL: goto x86_l_1789;
	case 6028ULL: goto x86_l_178c;
	case 6031ULL: goto x86_l_178f;
	case 6037ULL: goto x86_l_1795;
	case 6040ULL: goto x86_l_1798;
	case 6046ULL: goto x86_l_179e;
	case 6051ULL: goto x86_l_17a3;
	case 6059ULL: goto x86_l_17ab;
	case 6064ULL: goto x86_l_17b0;
	case 6069ULL: goto x86_l_17b5;
	case 6074ULL: goto x86_l_17ba;
	case 6076ULL: goto x86_l_17bc;
	case 6084ULL: goto x86_l_17c4;
	case 6089ULL: goto x86_l_17c9;
	case 6093ULL: goto x86_l_17cd;
	case 6099ULL: goto x86_l_17d3;
	case 6104ULL: goto x86_l_17d8;
	case 6111ULL: goto x86_l_17df;
	case 6119ULL: goto x86_l_17e7;
	case 6127ULL: goto x86_l_17ef;
	case 6135ULL: goto x86_l_17f7;
	case 6140ULL: goto x86_l_17fc;
	case 6145ULL: goto x86_l_1801;
	case 6149ULL: goto x86_l_1805;
	case 6154ULL: goto x86_l_180a;
	case 6156ULL: goto x86_l_180c;
	case 6160ULL: goto x86_l_1810;
	case 6165ULL: goto x86_l_1815;
	case 6170ULL: goto x86_l_181a;
	case 6173ULL: goto x86_l_181d;
	case 6178ULL: goto x86_l_1822;
	case 6181ULL: goto x86_l_1825;
	case 6183ULL: goto x86_l_1827;
	case 6190ULL: goto x86_l_182e;
	case 6198ULL: goto x86_l_1836;
	case 6203ULL: goto x86_l_183b;
	case 6208ULL: goto x86_l_1840;
	case 6213ULL: goto x86_l_1845;
	case 6215ULL: goto x86_l_1847;
	case 6224ULL: goto x86_l_1850;
	case 6229ULL: goto x86_l_1855;
	case 6238ULL: goto x86_l_185e;
	case 6243ULL: goto x86_l_1863;
	case 6245ULL: goto x86_l_1865;
	case 6249ULL: goto x86_l_1869;
	case 6254ULL: goto x86_l_186e;
	case 6259ULL: goto x86_l_1873;
	case 6262ULL: goto x86_l_1876;
	case 6267ULL: goto x86_l_187b;
	case 6272ULL: goto x86_l_1880;
	case 6278ULL: goto x86_l_1886;
	case 6283ULL: goto x86_l_188b;
	case 6285ULL: goto x86_l_188d;
	case 6289ULL: goto x86_l_1891;
	case 6293ULL: goto x86_l_1895;
	case 6300ULL: goto x86_l_189c;
	case 6305ULL: goto x86_l_18a1;
	case 6310ULL: goto x86_l_18a6;
	case 6312ULL: goto x86_l_18a8;
	case 6315ULL: goto x86_l_18ab;
	case 6321ULL: goto x86_l_18b1;
	case 6324ULL: goto x86_l_18b4;
	case 6327ULL: goto x86_l_18b7;
	case 6332ULL: goto x86_l_18bc;
	case 6337ULL: goto x86_l_18c1;
	case 6342ULL: goto x86_l_18c6;
	case 6345ULL: goto x86_l_18c9;
	case 6350ULL: goto x86_l_18ce;
	case 6352ULL: goto x86_l_18d0;
	case 6359ULL: goto x86_l_18d7;
	case 6363ULL: goto x86_l_18db;
	case 6367ULL: goto x86_l_18df;
	case 6372ULL: goto x86_l_18e4;
	case 6375ULL: goto x86_l_18e7;
	case 6377ULL: goto x86_l_18e9;
	case 6385ULL: goto x86_l_18f1;
	case 6388ULL: goto x86_l_18f4;
	case 6392ULL: goto x86_l_18f8;
	case 6396ULL: goto x86_l_18fc;
	case 6401ULL: goto x86_l_1901;
	case 6406ULL: goto x86_l_1906;
	case 6408ULL: goto x86_l_1908;
	case 6412ULL: goto x86_l_190c;
	case 6417ULL: goto x86_l_1911;
	case 6422ULL: goto x86_l_1916;
	case 6425ULL: goto x86_l_1919;
	case 6430ULL: goto x86_l_191e;
	case 6435ULL: goto x86_l_1923;
	case 6440ULL: goto x86_l_1928;
	case 6443ULL: goto x86_l_192b;
	case 6445ULL: goto x86_l_192d;
	case 6450ULL: goto x86_l_1932;
	case 6455ULL: goto x86_l_1937;
	case 6460ULL: goto x86_l_193c;
	case 6465ULL: goto x86_l_1941;
	case 6468ULL: goto x86_l_1944;
	case 6473ULL: goto x86_l_1949;
	case 6475ULL: goto x86_l_194b;
	case 6483ULL: goto x86_l_1953;
	case 6486ULL: goto x86_l_1956;
	case 6490ULL: goto x86_l_195a;
	case 6495ULL: goto x86_l_195f;
	case 6499ULL: goto x86_l_1963;
	case 6504ULL: goto x86_l_1968;
	case 6509ULL: goto x86_l_196d;
	case 6514ULL: goto x86_l_1972;
	case 6516ULL: goto x86_l_1974;
	case 6519ULL: goto x86_l_1977;
	case 6522ULL: goto x86_l_197a;
	case 6524ULL: goto x86_l_197c;
	case 6528ULL: goto x86_l_1980;
	case 6533ULL: goto x86_l_1985;
	case 6535ULL: goto x86_l_1987;
	case 6539ULL: goto x86_l_198b;
	case 6542ULL: goto x86_l_198e;
	case 6547ULL: goto x86_l_1993;
	case 6552ULL: goto x86_l_1998;
	case 6556ULL: goto x86_l_199c;
	case 6561ULL: goto x86_l_19a1;
	case 6565ULL: goto x86_l_19a5;
	case 6570ULL: goto x86_l_19aa;
	case 6575ULL: goto x86_l_19af;
	case 6580ULL: goto x86_l_19b4;
	case 6582ULL: goto x86_l_19b6;
	case 6585ULL: goto x86_l_19b9;
	case 6588ULL: goto x86_l_19bc;
	case 6594ULL: goto x86_l_19c2;
	case 6598ULL: goto x86_l_19c6;
	case 6603ULL: goto x86_l_19cb;
	case 6605ULL: goto x86_l_19cd;
	case 6609ULL: goto x86_l_19d1;
	case 6614ULL: goto x86_l_19d6;
	case 6619ULL: goto x86_l_19db;
	case 6622ULL: goto x86_l_19de;
	case 6627ULL: goto x86_l_19e3;
	case 6632ULL: goto x86_l_19e8;
	case 6637ULL: goto x86_l_19ed;
	case 6639ULL: goto x86_l_19ef;
	case 6644ULL: goto x86_l_19f4;
	case 6648ULL: goto x86_l_19f8;
	case 6653ULL: goto x86_l_19fd;
	case 6658ULL: goto x86_l_1a02;
	case 6664ULL: goto x86_l_1a08;
	case 6668ULL: goto x86_l_1a0c;
	case 6673ULL: goto x86_l_1a11;
	case 6678ULL: goto x86_l_1a16;
	case 6683ULL: goto x86_l_1a1b;
	case 6686ULL: goto x86_l_1a1e;
	case 6688ULL: goto x86_l_1a20;
	case 6692ULL: goto x86_l_1a24;
	case 6697ULL: goto x86_l_1a29;
	case 6702ULL: goto x86_l_1a2e;
	case 6707ULL: goto x86_l_1a33;
	case 6712ULL: goto x86_l_1a38;
	case 6717ULL: goto x86_l_1a3d;
	case 6722ULL: goto x86_l_1a42;
	case 6724ULL: goto x86_l_1a44;
	case 6729ULL: goto x86_l_1a49;
	case 6735ULL: goto x86_l_1a4f;
	case 6740ULL: goto x86_l_1a54;
	case 6745ULL: goto x86_l_1a59;
	case 6750ULL: goto x86_l_1a5e;
	case 6755ULL: goto x86_l_1a63;
	case 6757ULL: goto x86_l_1a65;
	case 6762ULL: goto x86_l_1a6a;
	case 6768ULL: goto x86_l_1a70;
	case 6772ULL: goto x86_l_1a74;
	case 6775ULL: goto x86_l_1a77;
	case 6780ULL: goto x86_l_1a7c;
	case 6785ULL: goto x86_l_1a81;
	case 6790ULL: goto x86_l_1a86;
	case 6793ULL: goto x86_l_1a89;
	case 6795ULL: goto x86_l_1a8b;
	case 6799ULL: goto x86_l_1a8f;
	case 6805ULL: goto x86_l_1a95;
	case 6810ULL: goto x86_l_1a9a;
	case 6815ULL: goto x86_l_1a9f;
	case 6820ULL: goto x86_l_1aa4;
	case 6825ULL: goto x86_l_1aa9;
	case 6828ULL: goto x86_l_1aac;
	case 6830ULL: goto x86_l_1aae;
	case 6834ULL: goto x86_l_1ab2;
	case 6839ULL: goto x86_l_1ab7;
	case 6844ULL: goto x86_l_1abc;
	case 6849ULL: goto x86_l_1ac1;
	case 6854ULL: goto x86_l_1ac6;
	case 6857ULL: goto x86_l_1ac9;
	case 6859ULL: goto x86_l_1acb;
	case 6864ULL: goto x86_l_1ad0;
	case 6869ULL: goto x86_l_1ad5;
	case 6873ULL: goto x86_l_1ad9;
	case 6876ULL: goto x86_l_1adc;
	case 6881ULL: goto x86_l_1ae1;
	case 6883ULL: goto x86_l_1ae3;
	case 6885ULL: goto x86_l_1ae5;
	case 6888ULL: goto x86_l_1ae8;
	case 6891ULL: goto x86_l_1aeb;
	case 6896ULL: goto x86_l_1af0;
	case 6898ULL: goto x86_l_1af2;
	case 6901ULL: goto x86_l_1af5;
	case 6905ULL: goto x86_l_1af9;
	case 6907ULL: goto x86_l_1afb;
	case 6911ULL: goto x86_l_1aff;
	case 6913ULL: goto x86_l_1b01;
	case 6916ULL: goto x86_l_1b04;
	case 6918ULL: goto x86_l_1b06;
	case 6922ULL: goto x86_l_1b0a;
	case 6925ULL: goto x86_l_1b0d;
	case 6930ULL: goto x86_l_1b12;
	case 6936ULL: goto x86_l_1b18;
	case 6942ULL: goto x86_l_1b1e;
	case 6948ULL: goto x86_l_1b24;
	case 6951ULL: goto x86_l_1b27;
	case 6953ULL: goto x86_l_1b29;
	case 6958ULL: goto x86_l_1b2e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1499:
	/* 0x1499: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_149c:
	/* 0x149c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_149e:
	/* 0x149e: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_14a2:
	/* 0x14a2: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_14a5:
	/* 0x14a5: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14aa:
	/* 0x14aa: jb     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3492ULL;
	}
x86_l_14b0:
	/* 0x14b0: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_14b6:
	/* 0x14b6: ja     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3492ULL;
	}
x86_l_14bc:
	/* 0x14bc: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_14bf:
	/* 0x14bf: jbe    14c6 <generic_uprobe_process_event+0x14c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_14c6;
	}
x86_l_14c1:
	/* 0x14c1: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_14c6:
	/* 0x14c6: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14c8:
	/* 0x14c8: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_14cb:
	/* 0x14cb: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_14cf:
	/* 0x14cf: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_14d2:
	/* 0x14d2: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_14d5:
	/* 0x14d5: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_14d8:
	/* 0x14d8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14dd:
	/* 0x14dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14df:
	/* 0x14df: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_14e4:
	/* 0x14e4: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_14e7:
	/* 0x14e7: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14ec:
	/* 0x14ec: jbe    da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3492ULL;
	}
x86_l_14f2:
	/* 0x14f2: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_14f7:
	/* 0x14f7: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_14fc:
	/* 0x14fc: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1501:
	/* 0x1501: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1506:
	/* 0x1506: jmp    1a38 <generic_uprobe_process_event+0x1a38> */
	goto x86_l_1a38;
x86_l_150b:
	/* 0x150b: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_150e:
	/* 0x150e: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1514:
	/* 0x1514: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1519:
	/* 0x1519: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_151e:
	/* 0x151e: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1523:
	/* 0x1523: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1528:
	/* 0x1528: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_152a:
	/* 0x152a: jmp    fb1 <generic_uprobe_process_event+0xfb1> */
	return 4017ULL;
x86_l_152f:
	/* 0x152f: cmp    ebp,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 5ULL);
x86_l_1532:
	/* 0x1532: je     16a1 <generic_uprobe_process_event+0x16a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16a1;
	}
x86_l_1538:
	/* 0x1538: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_153b:
	/* 0x153b: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1543:
	/* 0x1543: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1548:
	/* 0x1548: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_154d:
	/* 0x154d: je     1953 <generic_uprobe_process_event+0x1953> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1953;
	}
x86_l_1553:
	/* 0x1553: jmp    fbe <generic_uprobe_process_event+0xfbe> */
	return 4030ULL;
x86_l_1558:
	/* 0x1558: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_155b:
	/* 0x155b: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1561:
	/* 0x1561: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1566:
	/* 0x1566: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_156b:
	/* 0x156b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_156e:
	/* 0x156e: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1573:
	/* 0x1573: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1575:
	/* 0x1575: jmp    fb1 <generic_uprobe_process_event+0xfb1> */
	return 4017ULL;
x86_l_157a:
	/* 0x157a: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_157f:
	/* 0x157f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1582:
	/* 0x1582: cmp    ebp,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 39ULL);
x86_l_1585:
	/* 0x1585: je     1993 <generic_uprobe_process_event+0x1993> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1993;
	}
x86_l_158b:
	/* 0x158b: cmp    ebp,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 40ULL);
x86_l_158e:
	/* 0x158e: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_1591:
	/* 0x1591: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1596:
	/* 0x1596: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_159b:
	/* 0x159b: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15a0:
	/* 0x15a0: jne    fbe <generic_uprobe_process_event+0xfbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4030ULL;
	}
x86_l_15a6:
	/* 0x15a6: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15aa:
	/* 0x15aa: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15af:
	/* 0x15af: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_15b7:
	/* 0x15b7: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_15bf:
	/* 0x15bf: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15c6:
	/* 0x15c6: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_15cb:
	/* 0x15cb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15d0:
	/* 0x15d0: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_15d5:
	/* 0x15d5: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_15d8:
	/* 0x15d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15da:
	/* 0x15da: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15dd:
	/* 0x15dd: js     1cfa <generic_uprobe_process_event+0x1cfa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7418ULL;
	}
x86_l_15e3:
	/* 0x15e3: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15e8:
	/* 0x15e8: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15eb:
	/* 0x15eb: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_15ee:
	/* 0x15ee: je     1cb0 <generic_uprobe_process_event+0x1cb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7344ULL;
	}
x86_l_15f4:
	/* 0x15f4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15f7:
	/* 0x15f7: jne    1ceb <generic_uprobe_process_event+0x1ceb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7403ULL;
	}
x86_l_15fd:
	/* 0x15fd: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1602:
	/* 0x1602: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1607:
	/* 0x1607: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_160c:
	/* 0x160c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1611:
	/* 0x1611: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1616:
	/* 0x1616: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1618:
	/* 0x1618: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_161c:
	/* 0x161c: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1621:
	/* 0x1621: mov    QWORD PTR [rcx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1625:
	/* 0x1625: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1629:
	/* 0x1629: add    r12,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_162d:
	/* 0x162d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1632:
	/* 0x1632: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1637:
	/* 0x1637: jmp    1ce1 <generic_uprobe_process_event+0x1ce1> */
	return 7393ULL;
x86_l_163c:
	/* 0x163c: cmp    ebp,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 38ULL);
x86_l_163f:
	/* 0x163f: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_1642:
	/* 0x1642: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1647:
	/* 0x1647: jne    fbe <generic_uprobe_process_event+0xfbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4030ULL;
	}
x86_l_164d:
	/* 0x164d: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1651:
	/* 0x1651: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1654:
	/* 0x1654: mov    rbp,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RBX, X86_WIDTH_64);
x86_l_1657:
	/* 0x1657: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_165a:
	/* 0x165a: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_165d:
	/* 0x165d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1663:
	/* 0x1663: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1668:
	/* 0x1668: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_166c:
	/* 0x166c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_166e:
	/* 0x166e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1673:
	/* 0x1673: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1675:
	/* 0x1675: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1678:
	/* 0x1678: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_167b:
	/* 0x167b: js     168c <generic_uprobe_process_event+0x168c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_168c;
	}
x86_l_167d:
	/* 0x167d: lea    eax,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1681:
	/* 0x1681: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1686:
	/* 0x1686: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1688:
	/* 0x1688: add    r13,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_168c:
	/* 0x168c: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_168f:
	/* 0x168f: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1694:
	/* 0x1694: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1699:
	/* 0x1699: mov    rbx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RBP, X86_WIDTH_64);
x86_l_169c:
	/* 0x169c: jmp    fbe <generic_uprobe_process_event+0xfbe> */
	return 4030ULL;
x86_l_16a1:
	/* 0x16a1: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16a5:
	/* 0x16a5: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16aa:
	/* 0x16aa: lea    rdi,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16ae:
	/* 0x16ae: lea    rdx,[r13+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_16b5:
	/* 0x16b5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_16ba:
	/* 0x16ba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16bf:
	/* 0x16bf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16c4:
	/* 0x16c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c6:
	/* 0x16c6: lea    rdi,[r15+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_16ca:
	/* 0x16ca: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_16ce:
	/* 0x16ce: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_16d3:
	/* 0x16d3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16d8:
	/* 0x16d8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16dd:
	/* 0x16dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16df:
	/* 0x16df: lea    rdi,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16e3:
	/* 0x16e3: lea    rdx,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_16ea:
	/* 0x16ea: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_16ef:
	/* 0x16ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16f4:
	/* 0x16f4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16f9:
	/* 0x16f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16fb:
	/* 0x16fb: lea    rdi,[r15+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_16ff:
	/* 0x16ff: lea    rdx,[r13+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1706:
	/* 0x1706: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
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
	/* 0x1717: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1720:
	/* 0x1720: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1727:
	/* 0x1727: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_172c:
	/* 0x172c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1731:
	/* 0x1731: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1736:
	/* 0x1736: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_173b:
	/* 0x173b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_173d:
	/* 0x173d: lea    rdx,[r13+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1744:
	/* 0x1744: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1749:
	/* 0x1749: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_174e:
	/* 0x174e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1753:
	/* 0x1753: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1758:
	/* 0x1758: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_175a:
	/* 0x175a: movzx  r12d,WORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 112ULL);
x86_l_1760:
	/* 0x1760: add    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_1765:
	/* 0x1765: lea    rdi,[rsp+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_176d:
	/* 0x176d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1772:
	/* 0x1772: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1777:
	/* 0x1777: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_177c:
	/* 0x177c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_177f:
	/* 0x177f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1781:
	/* 0x1781: movzx  eax,BYTE PTR [rsp+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 156ULL);
x86_l_1789:
	/* 0x1789: shr    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_178c:
	/* 0x178c: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_178f:
	/* 0x178f: je     1b7f <generic_uprobe_process_event+0x1b7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7039ULL;
	}
x86_l_1795:
	/* 0x1795: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1798:
	/* 0x1798: jne    2abe <generic_uprobe_process_event+0x2abe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10942ULL;
	}
x86_l_179e:
	/* 0x179e: lea    rdx,[r12+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_17a3:
	/* 0x17a3: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_17ab:
	/* 0x17ab: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_17b0:
	/* 0x17b0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17b5:
	/* 0x17b5: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_17ba:
	/* 0x17ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17bc:
	/* 0x17bc: movzx  eax,BYTE PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 176ULL);
x86_l_17c4:
	/* 0x17c4: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17c9:
	/* 0x17c9: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_17cd:
	/* 0x17cd: mov    WORD PTR [rdi+0x26],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757250ULL);
x86_l_17d3:
	/* 0x17d3: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_17d8:
	/* 0x17d8: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17df:
	/* 0x17df: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_17e7:
	/* 0x17e7: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_17ef:
	/* 0x17ef: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_17f7:
	/* 0x17f7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_17fc:
	/* 0x17fc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1801:
	/* 0x1801: lea    rbp,[rdi+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1805:
	/* 0x1805: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_180a:
	/* 0x180a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_180c:
	/* 0x180c: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1810:
	/* 0x1810: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1815:
	/* 0x1815: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_181a:
	/* 0x181a: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_181d:
	/* 0x181d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1822:
	/* 0x1822: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1825:
	/* 0x1825: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1827:
	/* 0x1827: lea    rdx,[r13+0xb6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_182e:
	/* 0x182e: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1836:
	/* 0x1836: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_183b:
	/* 0x183b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1840:
	/* 0x1840: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1845:
	/* 0x1845: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1847:
	/* 0x1847: movzx  r12d,BYTE PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 176ULL);
x86_l_1850:
	/* 0x1850: jmp    2960 <generic_uprobe_process_event+0x2960> */
	return 10592ULL;
x86_l_1855:
	/* 0x1855: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_185e:
	/* 0x185e: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1863:
	/* 0x1863: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1865:
	/* 0x1865: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1869:
	/* 0x1869: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_186e:
	/* 0x186e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1873:
	/* 0x1873: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_1876:
	/* 0x1876: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_187b:
	/* 0x187b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1880:
	/* 0x1880: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_1886:
	/* 0x1886: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_188b:
	/* 0x188b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_188d:
	/* 0x188d: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1891:
	/* 0x1891: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1895:
	/* 0x1895: mov    rdi,QWORD PTR [rip+0x210] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_189c:
	/* 0x189c: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18a1:
	/* 0x18a1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18a6:
	/* 0x18a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18a8:
	/* 0x18a8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18ab:
	/* 0x18ab: je     1b73 <generic_uprobe_process_event+0x1b73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7027ULL;
	}
x86_l_18b1:
	/* 0x18b1: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_18b4:
	/* 0x18b4: mov    r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18b7:
	/* 0x18b7: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18bc:
	/* 0x18bc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18c1:
	/* 0x18c1: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18c6:
	/* 0x18c6: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_18c9:
	/* 0x18c9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18ce:
	/* 0x18ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18d0:
	/* 0x18d0: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_18d7:
	/* 0x18d7: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_18db:
	/* 0x18db: lea    rsi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_18df:
	/* 0x18df: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18e4:
	/* 0x18e4: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_18e7:
	/* 0x18e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e9:
	/* 0x18e9: lea    rdi,[r13*1+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_18f1:
	/* 0x18f1: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_18f4:
	/* 0x18f4: lea    rdx,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_18f8:
	/* 0x18f8: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_18fc:
	/* 0x18fc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1901:
	/* 0x1901: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1906:
	/* 0x1906: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1908:
	/* 0x1908: add    r13,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_190c:
	/* 0x190c: jmp    2ac4 <generic_uprobe_process_event+0x2ac4> */
	return 10948ULL;
x86_l_1911:
	/* 0x1911: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1916:
	/* 0x1916: mov    r12,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSP, X86_WIDTH_64);
x86_l_1919:
	/* 0x1919: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_191e:
	/* 0x191e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1923:
	/* 0x1923: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1928:
	/* 0x1928: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_192b:
	/* 0x192b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_192d:
	/* 0x192d: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1932:
	/* 0x1932: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1937:
	/* 0x1937: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_193c:
	/* 0x193c: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1941:
	/* 0x1941: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1944:
	/* 0x1944: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1949:
	/* 0x1949: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_194b:
	/* 0x194b: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1953:
	/* 0x1953: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1956:
	/* 0x1956: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_195a:
	/* 0x195a: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_195f:
	/* 0x195f: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1963:
	/* 0x1963: mov    ecx,0x91 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 145ULL);
x86_l_1968:
	/* 0x1968: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_196d:
	/* 0x196d: mov    esi,0x91 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 145ULL);
x86_l_1972:
	/* 0x1972: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1974:
	/* 0x1974: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1977:
	/* 0x1977: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_197a:
	/* 0x197a: js     198b <generic_uprobe_process_event+0x198b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_198b;
	}
x86_l_197c:
	/* 0x197c: lea    eax,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1980:
	/* 0x1980: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1985:
	/* 0x1985: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1987:
	/* 0x1987: add    r13,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_198b:
	/* 0x198b: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_198e:
	/* 0x198e: jmp    2acc <generic_uprobe_process_event+0x2acc> */
	return 10956ULL;
x86_l_1993:
	/* 0x1993: mov    edx,0x120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 288ULL);
x86_l_1998:
	/* 0x1998: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_199c:
	/* 0x199c: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19a1:
	/* 0x19a1: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19a5:
	/* 0x19a5: mov    ecx,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_19aa:
	/* 0x19aa: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_19af:
	/* 0x19af: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_19b4:
	/* 0x19b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b6:
	/* 0x19b6: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_19b9:
	/* 0x19b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19bc:
	/* 0x19bc: js     1d00 <generic_uprobe_process_event+0x1d00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7424ULL;
	}
x86_l_19c2:
	/* 0x19c2: lea    eax,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_19c6:
	/* 0x19c6: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19cb:
	/* 0x19cb: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19cd:
	/* 0x19cd: add    r13,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_19d1:
	/* 0x19d1: jmp    1d00 <generic_uprobe_process_event+0x1d00> */
	return 7424ULL;
x86_l_19d6:
	/* 0x19d6: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19db:
	/* 0x19db: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_19de:
	/* 0x19de: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19e3:
	/* 0x19e3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19e8:
	/* 0x19e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19ed:
	/* 0x19ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19ef:
	/* 0x19ef: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_19f4:
	/* 0x19f4: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_19f8:
	/* 0x19f8: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19fd:
	/* 0x19fd: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a02:
	/* 0x1a02: je     d9f <generic_uprobe_process_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3487ULL;
	}
x86_l_1a08:
	/* 0x1a08: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1a0c:
	/* 0x1a0c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a11:
	/* 0x1a11: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a16:
	/* 0x1a16: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a1b:
	/* 0x1a1b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1a1e:
	/* 0x1a1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a20:
	/* 0x1a20: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a24:
	/* 0x1a24: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a29:
	/* 0x1a29: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a2e:
	/* 0x1a2e: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1a33:
	/* 0x1a33: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a38:
	/* 0x1a38: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1a3d:
	/* 0x1a3d: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a42:
	/* 0x1a42: jne    1a4f <generic_uprobe_process_event+0x1a4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a4f;
	}
x86_l_1a44:
	/* 0x1a44: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_1a49:
	/* 0x1a49: je     d9f <generic_uprobe_process_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3487ULL;
	}
x86_l_1a4f:
	/* 0x1a4f: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1a54:
	/* 0x1a54: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a59:
	/* 0x1a59: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a5e:
	/* 0x1a5e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a63:
	/* 0x1a63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a65:
	/* 0x1a65: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_1a6a:
	/* 0x1a6a: je     1d17 <generic_uprobe_process_event+0x1d17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7447ULL;
	}
x86_l_1a70:
	/* 0x1a70: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a74:
	/* 0x1a74: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1a77:
	/* 0x1a77: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a7c:
	/* 0x1a7c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a81:
	/* 0x1a81: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a86:
	/* 0x1a86: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1a89:
	/* 0x1a89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a8b:
	/* 0x1a8b: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a8f:
	/* 0x1a8f: je     1d17 <generic_uprobe_process_event+0x1d17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7447ULL;
	}
x86_l_1a95:
	/* 0x1a95: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1a9a:
	/* 0x1a9a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a9f:
	/* 0x1a9f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1aa4:
	/* 0x1aa4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1aa9:
	/* 0x1aa9: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1aac:
	/* 0x1aac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aae:
	/* 0x1aae: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1ab2:
	/* 0x1ab2: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ab7:
	/* 0x1ab7: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1abc:
	/* 0x1abc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ac1:
	/* 0x1ac1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1ac6:
	/* 0x1ac6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1ac9:
	/* 0x1ac9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1acb:
	/* 0x1acb: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ad0:
	/* 0x1ad0: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1ad5:
	/* 0x1ad5: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1ad9:
	/* 0x1ad9: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1adc:
	/* 0x1adc: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1ae1:
	/* 0x1ae1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ae3:
	/* 0x1ae3: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1ae5:
	/* 0x1ae5: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1ae8:
	/* 0x1ae8: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1aeb:
	/* 0x1aeb: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1af0:
	/* 0x1af0: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1af2:
	/* 0x1af2: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1af5:
	/* 0x1af5: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_1af9:
	/* 0x1af9: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1afb:
	/* 0x1afb: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_1aff:
	/* 0x1aff: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1b01:
	/* 0x1b01: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_1b04:
	/* 0x1b04: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1b06:
	/* 0x1b06: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1b0a:
	/* 0x1b0a: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1b0d:
	/* 0x1b0d: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b12:
	/* 0x1b12: jb     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3492ULL;
	}
x86_l_1b18:
	/* 0x1b18: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_1b1e:
	/* 0x1b1e: ja     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3492ULL;
	}
x86_l_1b24:
	/* 0x1b24: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1b27:
	/* 0x1b27: jbe    1b2e <generic_uprobe_process_event+0x1b2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1b2e;
	}
x86_l_1b29:
	/* 0x1b29: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_1b2e:
	/* 0x1b2e: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
	return 6960ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6960ULL: goto x86_l_1b30;
	case 6963ULL: goto x86_l_1b33;
	case 6967ULL: goto x86_l_1b37;
	case 6970ULL: goto x86_l_1b3a;
	case 6973ULL: goto x86_l_1b3d;
	case 6976ULL: goto x86_l_1b40;
	case 6981ULL: goto x86_l_1b45;
	case 6983ULL: goto x86_l_1b47;
	case 6988ULL: goto x86_l_1b4c;
	case 6991ULL: goto x86_l_1b4f;
	case 6996ULL: goto x86_l_1b54;
	case 7002ULL: goto x86_l_1b5a;
	case 7007ULL: goto x86_l_1b5f;
	case 7012ULL: goto x86_l_1b64;
	case 7017ULL: goto x86_l_1b69;
	case 7022ULL: goto x86_l_1b6e;
	case 7027ULL: goto x86_l_1b73;
	case 7034ULL: goto x86_l_1b7a;
	case 7039ULL: goto x86_l_1b7f;
	case 7044ULL: goto x86_l_1b84;
	case 7052ULL: goto x86_l_1b8c;
	case 7058ULL: goto x86_l_1b92;
	case 7065ULL: goto x86_l_1b99;
	case 7070ULL: goto x86_l_1b9e;
	case 7075ULL: goto x86_l_1ba3;
	case 7083ULL: goto x86_l_1bab;
	case 7086ULL: goto x86_l_1bae;
	case 7091ULL: goto x86_l_1bb3;
	case 7093ULL: goto x86_l_1bb5;
	case 7096ULL: goto x86_l_1bb8;
	case 7102ULL: goto x86_l_1bbe;
	case 7105ULL: goto x86_l_1bc1;
	case 7109ULL: goto x86_l_1bc5;
	case 7113ULL: goto x86_l_1bc9;
	case 7117ULL: goto x86_l_1bcd;
	case 7120ULL: goto x86_l_1bd0;
	case 7124ULL: goto x86_l_1bd4;
	case 7129ULL: goto x86_l_1bd9;
	case 7133ULL: goto x86_l_1bdd;
	case 7138ULL: goto x86_l_1be2;
	case 7143ULL: goto x86_l_1be7;
	case 7146ULL: goto x86_l_1bea;
	case 7151ULL: goto x86_l_1bef;
	case 7153ULL: goto x86_l_1bf1;
	case 7156ULL: goto x86_l_1bf4;
	case 7162ULL: goto x86_l_1bfa;
	case 7166ULL: goto x86_l_1bfe;
	case 7169ULL: goto x86_l_1c01;
	case 7175ULL: goto x86_l_1c07;
	case 7177ULL: goto x86_l_1c09;
	case 7183ULL: goto x86_l_1c0f;
	case 7186ULL: goto x86_l_1c12;
	case 7192ULL: goto x86_l_1c18;
	case 7195ULL: goto x86_l_1c1b;
	case 7201ULL: goto x86_l_1c21;
	case 7207ULL: goto x86_l_1c27;
	case 7211ULL: goto x86_l_1c2b;
	case 7216ULL: goto x86_l_1c30;
	case 7220ULL: goto x86_l_1c34;
	case 7225ULL: goto x86_l_1c39;
	case 7230ULL: goto x86_l_1c3e;
	case 7235ULL: goto x86_l_1c43;
	case 7240ULL: goto x86_l_1c48;
	case 7242ULL: goto x86_l_1c4a;
	case 7246ULL: goto x86_l_1c4e;
	case 7251ULL: goto x86_l_1c53;
	case 7256ULL: goto x86_l_1c58;
	case 7259ULL: goto x86_l_1c5b;
	case 7264ULL: goto x86_l_1c60;
	case 7266ULL: goto x86_l_1c62;
	case 7271ULL: goto x86_l_1c67;
	case 7275ULL: goto x86_l_1c6b;
	case 7279ULL: goto x86_l_1c6f;
	case 7283ULL: goto x86_l_1c73;
	case 7288ULL: goto x86_l_1c78;
	case 7293ULL: goto x86_l_1c7d;
	case 7298ULL: goto x86_l_1c82;
	case 7301ULL: goto x86_l_1c85;
	case 7303ULL: goto x86_l_1c87;
	case 7307ULL: goto x86_l_1c8b;
	case 7312ULL: goto x86_l_1c90;
	case 7317ULL: goto x86_l_1c95;
	case 7322ULL: goto x86_l_1c9a;
	case 7325ULL: goto x86_l_1c9d;
	case 7327ULL: goto x86_l_1c9f;
	case 7332ULL: goto x86_l_1ca4;
	case 7339ULL: goto x86_l_1cab;
	case 7344ULL: goto x86_l_1cb0;
	case 7349ULL: goto x86_l_1cb5;
	case 7353ULL: goto x86_l_1cb9;
	case 7358ULL: goto x86_l_1cbe;
	case 7363ULL: goto x86_l_1cc3;
	case 7368ULL: goto x86_l_1cc8;
	case 7373ULL: goto x86_l_1ccd;
	case 7375ULL: goto x86_l_1ccf;
	case 7379ULL: goto x86_l_1cd3;
	case 7383ULL: goto x86_l_1cd7;
	case 7388ULL: goto x86_l_1cdc;
	case 7393ULL: goto x86_l_1ce1;
	case 7398ULL: goto x86_l_1ce6;
	case 7401ULL: goto x86_l_1ce9;
	case 7403ULL: goto x86_l_1ceb;
	case 7408ULL: goto x86_l_1cf0;
	case 7412ULL: goto x86_l_1cf4;
	case 7418ULL: goto x86_l_1cfa;
	case 7424ULL: goto x86_l_1d00;
	case 7427ULL: goto x86_l_1d03;
	case 7432ULL: goto x86_l_1d08;
	case 7437ULL: goto x86_l_1d0d;
	case 7442ULL: goto x86_l_1d12;
	case 7447ULL: goto x86_l_1d17;
	case 7452ULL: goto x86_l_1d1c;
	case 7455ULL: goto x86_l_1d1f;
	case 7460ULL: goto x86_l_1d24;
	case 7465ULL: goto x86_l_1d29;
	case 7470ULL: goto x86_l_1d2e;
	case 7472ULL: goto x86_l_1d30;
	case 7477ULL: goto x86_l_1d35;
	case 7481ULL: goto x86_l_1d39;
	case 7486ULL: goto x86_l_1d3e;
	case 7491ULL: goto x86_l_1d43;
	case 7497ULL: goto x86_l_1d49;
	case 7501ULL: goto x86_l_1d4d;
	case 7506ULL: goto x86_l_1d52;
	case 7511ULL: goto x86_l_1d57;
	case 7516ULL: goto x86_l_1d5c;
	case 7519ULL: goto x86_l_1d5f;
	case 7521ULL: goto x86_l_1d61;
	case 7525ULL: goto x86_l_1d65;
	case 7530ULL: goto x86_l_1d6a;
	case 7535ULL: goto x86_l_1d6f;
	case 7540ULL: goto x86_l_1d74;
	case 7545ULL: goto x86_l_1d79;
	case 7550ULL: goto x86_l_1d7e;
	case 7555ULL: goto x86_l_1d83;
	case 7557ULL: goto x86_l_1d85;
	case 7562ULL: goto x86_l_1d8a;
	case 7568ULL: goto x86_l_1d90;
	case 7573ULL: goto x86_l_1d95;
	case 7578ULL: goto x86_l_1d9a;
	case 7583ULL: goto x86_l_1d9f;
	case 7588ULL: goto x86_l_1da4;
	case 7590ULL: goto x86_l_1da6;
	case 7595ULL: goto x86_l_1dab;
	case 7601ULL: goto x86_l_1db1;
	case 7605ULL: goto x86_l_1db5;
	case 7608ULL: goto x86_l_1db8;
	case 7613ULL: goto x86_l_1dbd;
	case 7618ULL: goto x86_l_1dc2;
	case 7623ULL: goto x86_l_1dc7;
	case 7626ULL: goto x86_l_1dca;
	case 7628ULL: goto x86_l_1dcc;
	case 7632ULL: goto x86_l_1dd0;
	case 7638ULL: goto x86_l_1dd6;
	case 7643ULL: goto x86_l_1ddb;
	case 7648ULL: goto x86_l_1de0;
	case 7653ULL: goto x86_l_1de5;
	case 7658ULL: goto x86_l_1dea;
	case 7661ULL: goto x86_l_1ded;
	case 7663ULL: goto x86_l_1def;
	case 7667ULL: goto x86_l_1df3;
	case 7672ULL: goto x86_l_1df8;
	case 7677ULL: goto x86_l_1dfd;
	case 7682ULL: goto x86_l_1e02;
	case 7687ULL: goto x86_l_1e07;
	case 7690ULL: goto x86_l_1e0a;
	case 7692ULL: goto x86_l_1e0c;
	case 7697ULL: goto x86_l_1e11;
	case 7702ULL: goto x86_l_1e16;
	case 7706ULL: goto x86_l_1e1a;
	case 7709ULL: goto x86_l_1e1d;
	case 7714ULL: goto x86_l_1e22;
	case 7716ULL: goto x86_l_1e24;
	case 7718ULL: goto x86_l_1e26;
	case 7721ULL: goto x86_l_1e29;
	case 7724ULL: goto x86_l_1e2c;
	case 7729ULL: goto x86_l_1e31;
	case 7731ULL: goto x86_l_1e33;
	case 7734ULL: goto x86_l_1e36;
	case 7738ULL: goto x86_l_1e3a;
	case 7740ULL: goto x86_l_1e3c;
	case 7744ULL: goto x86_l_1e40;
	case 7746ULL: goto x86_l_1e42;
	case 7749ULL: goto x86_l_1e45;
	case 7751ULL: goto x86_l_1e47;
	case 7755ULL: goto x86_l_1e4b;
	case 7758ULL: goto x86_l_1e4e;
	case 7763ULL: goto x86_l_1e53;
	case 7769ULL: goto x86_l_1e59;
	case 7775ULL: goto x86_l_1e5f;
	case 7781ULL: goto x86_l_1e65;
	case 7784ULL: goto x86_l_1e68;
	case 7786ULL: goto x86_l_1e6a;
	case 7791ULL: goto x86_l_1e6f;
	case 7793ULL: goto x86_l_1e71;
	case 7796ULL: goto x86_l_1e74;
	case 7800ULL: goto x86_l_1e78;
	case 7803ULL: goto x86_l_1e7b;
	case 7806ULL: goto x86_l_1e7e;
	case 7809ULL: goto x86_l_1e81;
	case 7814ULL: goto x86_l_1e86;
	case 7816ULL: goto x86_l_1e88;
	case 7821ULL: goto x86_l_1e8d;
	case 7824ULL: goto x86_l_1e90;
	case 7829ULL: goto x86_l_1e95;
	case 7835ULL: goto x86_l_1e9b;
	case 7840ULL: goto x86_l_1ea0;
	case 7845ULL: goto x86_l_1ea5;
	case 7850ULL: goto x86_l_1eaa;
	case 7855ULL: goto x86_l_1eaf;
	case 7860ULL: goto x86_l_1eb4;
	case 7863ULL: goto x86_l_1eb7;
	case 7869ULL: goto x86_l_1ebd;
	case 7872ULL: goto x86_l_1ec0;
	case 7874ULL: goto x86_l_1ec2;
	case 7879ULL: goto x86_l_1ec7;
	case 7885ULL: goto x86_l_1ecd;
	case 7891ULL: goto x86_l_1ed3;
	case 7895ULL: goto x86_l_1ed7;
	case 7900ULL: goto x86_l_1edc;
	case 7904ULL: goto x86_l_1ee0;
	case 7911ULL: goto x86_l_1ee7;
	case 7916ULL: goto x86_l_1eec;
	case 7921ULL: goto x86_l_1ef1;
	case 7924ULL: goto x86_l_1ef4;
	case 7929ULL: goto x86_l_1ef9;
	case 7934ULL: goto x86_l_1efe;
	case 7939ULL: goto x86_l_1f03;
	case 7941ULL: goto x86_l_1f05;
	case 7946ULL: goto x86_l_1f0a;
	case 7950ULL: goto x86_l_1f0e;
	case 7955ULL: goto x86_l_1f13;
	case 7960ULL: goto x86_l_1f18;
	case 7966ULL: goto x86_l_1f1e;
	case 7970ULL: goto x86_l_1f22;
	case 7975ULL: goto x86_l_1f27;
	case 7980ULL: goto x86_l_1f2c;
	case 7985ULL: goto x86_l_1f31;
	case 7988ULL: goto x86_l_1f34;
	case 7990ULL: goto x86_l_1f36;
	case 7994ULL: goto x86_l_1f3a;
	case 7999ULL: goto x86_l_1f3f;
	case 8004ULL: goto x86_l_1f44;
	case 8009ULL: goto x86_l_1f49;
	case 8014ULL: goto x86_l_1f4e;
	case 8019ULL: goto x86_l_1f53;
	case 8024ULL: goto x86_l_1f58;
	case 8026ULL: goto x86_l_1f5a;
	case 8031ULL: goto x86_l_1f5f;
	case 8037ULL: goto x86_l_1f65;
	case 8042ULL: goto x86_l_1f6a;
	case 8047ULL: goto x86_l_1f6f;
	case 8052ULL: goto x86_l_1f74;
	case 8057ULL: goto x86_l_1f79;
	case 8059ULL: goto x86_l_1f7b;
	case 8064ULL: goto x86_l_1f80;
	case 8070ULL: goto x86_l_1f86;
	case 8074ULL: goto x86_l_1f8a;
	case 8077ULL: goto x86_l_1f8d;
	case 8082ULL: goto x86_l_1f92;
	case 8087ULL: goto x86_l_1f97;
	case 8092ULL: goto x86_l_1f9c;
	case 8095ULL: goto x86_l_1f9f;
	case 8097ULL: goto x86_l_1fa1;
	case 8101ULL: goto x86_l_1fa5;
	case 8107ULL: goto x86_l_1fab;
	case 8112ULL: goto x86_l_1fb0;
	case 8117ULL: goto x86_l_1fb5;
	case 8122ULL: goto x86_l_1fba;
	case 8127ULL: goto x86_l_1fbf;
	case 8130ULL: goto x86_l_1fc2;
	case 8132ULL: goto x86_l_1fc4;
	case 8136ULL: goto x86_l_1fc8;
	case 8141ULL: goto x86_l_1fcd;
	case 8146ULL: goto x86_l_1fd2;
	case 8151ULL: goto x86_l_1fd7;
	case 8156ULL: goto x86_l_1fdc;
	case 8159ULL: goto x86_l_1fdf;
	case 8161ULL: goto x86_l_1fe1;
	case 8166ULL: goto x86_l_1fe6;
	case 8171ULL: goto x86_l_1feb;
	case 8175ULL: goto x86_l_1fef;
	case 8178ULL: goto x86_l_1ff2;
	case 8183ULL: goto x86_l_1ff7;
	case 8185ULL: goto x86_l_1ff9;
	case 8187ULL: goto x86_l_1ffb;
	case 8190ULL: goto x86_l_1ffe;
	case 8193ULL: goto x86_l_2001;
	case 8198ULL: goto x86_l_2006;
	case 8200ULL: goto x86_l_2008;
	case 8203ULL: goto x86_l_200b;
	case 8207ULL: goto x86_l_200f;
	case 8209ULL: goto x86_l_2011;
	case 8213ULL: goto x86_l_2015;
	case 8215ULL: goto x86_l_2017;
	case 8218ULL: goto x86_l_201a;
	case 8220ULL: goto x86_l_201c;
	case 8224ULL: goto x86_l_2020;
	case 8227ULL: goto x86_l_2023;
	case 8232ULL: goto x86_l_2028;
	case 8238ULL: goto x86_l_202e;
	case 8244ULL: goto x86_l_2034;
	case 8250ULL: goto x86_l_203a;
	case 8253ULL: goto x86_l_203d;
	case 8255ULL: goto x86_l_203f;
	case 8260ULL: goto x86_l_2044;
	case 8262ULL: goto x86_l_2046;
	case 8265ULL: goto x86_l_2049;
	case 8269ULL: goto x86_l_204d;
	case 8272ULL: goto x86_l_2050;
	case 8275ULL: goto x86_l_2053;
	case 8278ULL: goto x86_l_2056;
	case 8283ULL: goto x86_l_205b;
	case 8285ULL: goto x86_l_205d;
	case 8290ULL: goto x86_l_2062;
	case 8293ULL: goto x86_l_2065;
	case 8298ULL: goto x86_l_206a;
	case 8304ULL: goto x86_l_2070;
	case 8309ULL: goto x86_l_2075;
	case 8314ULL: goto x86_l_207a;
	case 8319ULL: goto x86_l_207f;
	case 8324ULL: goto x86_l_2084;
	case 8329ULL: goto x86_l_2089;
	case 8333ULL: goto x86_l_208d;
	case 8340ULL: goto x86_l_2094;
	case 8344ULL: goto x86_l_2098;
	case 8348ULL: goto x86_l_209c;
	case 8352ULL: goto x86_l_20a0;
	case 8357ULL: goto x86_l_20a5;
	case 8361ULL: goto x86_l_20a9;
	case 8367ULL: goto x86_l_20af;
	case 8377ULL: goto x86_l_20b9;
	case 8381ULL: goto x86_l_20bd;
	case 8387ULL: goto x86_l_20c3;
	case 8391ULL: goto x86_l_20c7;
	case 8394ULL: goto x86_l_20ca;
	case 8402ULL: goto x86_l_20d2;
	case 8405ULL: goto x86_l_20d5;
	case 8410ULL: goto x86_l_20da;
	case 8415ULL: goto x86_l_20df;
	case 8419ULL: goto x86_l_20e3;
	case 8422ULL: goto x86_l_20e6;
	case 8425ULL: goto x86_l_20e9;
	case 8430ULL: goto x86_l_20ee;
	case 8432ULL: goto x86_l_20f0;
	case 8435ULL: goto x86_l_20f3;
	case 8441ULL: goto x86_l_20f9;
	case 8445ULL: goto x86_l_20fd;
	case 8448ULL: goto x86_l_2100;
	case 8450ULL: goto x86_l_2102;
	case 8452ULL: goto x86_l_2104;
	case 8454ULL: goto x86_l_2106;
	case 8457ULL: goto x86_l_2109;
	case 8459ULL: goto x86_l_210b;
	case 8462ULL: goto x86_l_210e;
	case 8464ULL: goto x86_l_2110;
	case 8470ULL: goto x86_l_2116;
	case 8474ULL: goto x86_l_211a;
	case 8476ULL: goto x86_l_211c;
	case 8479ULL: goto x86_l_211f;
	case 8481ULL: goto x86_l_2121;
	case 8484ULL: goto x86_l_2124;
	case 8486ULL: goto x86_l_2126;
	case 8491ULL: goto x86_l_212b;
	case 8493ULL: goto x86_l_212d;
	case 8499ULL: goto x86_l_2133;
	case 8503ULL: goto x86_l_2137;
	case 8505ULL: goto x86_l_2139;
	case 8509ULL: goto x86_l_213d;
	case 8516ULL: goto x86_l_2144;
	case 8520ULL: goto x86_l_2148;
	case 8522ULL: goto x86_l_214a;
	case 8526ULL: goto x86_l_214e;
	case 8531ULL: goto x86_l_2153;
	case 8535ULL: goto x86_l_2157;
	case 8542ULL: goto x86_l_215e;
	case 8546ULL: goto x86_l_2162;
	case 8548ULL: goto x86_l_2164;
	case 8552ULL: goto x86_l_2168;
	case 8556ULL: goto x86_l_216c;
	case 8560ULL: goto x86_l_2170;
	case 8565ULL: goto x86_l_2175;
	case 8569ULL: goto x86_l_2179;
	case 8575ULL: goto x86_l_217f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b30:
	/* 0x1b30: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1b33:
	/* 0x1b33: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_1b37:
	/* 0x1b37: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b3a:
	/* 0x1b3a: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b3d:
	/* 0x1b3d: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b40:
	/* 0x1b40: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b45:
	/* 0x1b45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b47:
	/* 0x1b47: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1b4c:
	/* 0x1b4c: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1b4f:
	/* 0x1b4f: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b54:
	/* 0x1b54: jbe    da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3492ULL;
	}
x86_l_1b5a:
	/* 0x1b5a: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1b5f:
	/* 0x1b5f: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b64:
	/* 0x1b64: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b69:
	/* 0x1b69: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b6e:
	/* 0x1b6e: jmp    1d79 <generic_uprobe_process_event+0x1d79> */
	goto x86_l_1d79;
x86_l_1b73:
	/* 0x1b73: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1b7a:
	/* 0x1b7a: jmp    2ac4 <generic_uprobe_process_event+0x2ac4> */
	return 10948ULL;
x86_l_1b7f:
	/* 0x1b7f: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b84:
	/* 0x1b84: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1b8c:
	/* 0x1b8c: movzx  r15d,WORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 112ULL);
x86_l_1b92:
	/* 0x1b92: mov    rdi,QWORD PTR [rip+0x20c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_1b99:
	/* 0x1b99: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b9e:
	/* 0x1b9e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ba3:
	/* 0x1ba3: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1bab:
	/* 0x1bab: add    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1bae:
	/* 0x1bae: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bb3:
	/* 0x1bb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bb5:
	/* 0x1bb5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bb8:
	/* 0x1bb8: je     2907 <generic_uprobe_process_event+0x2907> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10503ULL;
	}
x86_l_1bbe:
	/* 0x1bbe: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1bc1:
	/* 0x1bc1: mov    WORD PTR [rax],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bc5:
	/* 0x1bc5: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_1bc9:
	/* 0x1bc9: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_1bcd:
	/* 0x1bcd: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1bd0:
	/* 0x1bd0: add    r15,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_1bd4:
	/* 0x1bd4: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bd9:
	/* 0x1bd9: lea    rdx,[rax+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1bdd:
	/* 0x1bdd: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1be2:
	/* 0x1be2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1be7:
	/* 0x1be7: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1bea:
	/* 0x1bea: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1bef:
	/* 0x1bef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bf1:
	/* 0x1bf1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bf4:
	/* 0x1bf4: js     2907 <generic_uprobe_process_event+0x2907> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10503ULL;
	}
x86_l_1bfa:
	/* 0x1bfa: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_1bfe:
	/* 0x1bfe: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_1c01:
	/* 0x1c01: jg     1eb4 <generic_uprobe_process_event+0x1eb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1eb4;
	}
x86_l_1c07:
	/* 0x1c07: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c09:
	/* 0x1c09: je     1edc <generic_uprobe_process_event+0x1edc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1edc;
	}
x86_l_1c0f:
	/* 0x1c0f: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1c12:
	/* 0x1c12: je     1edc <generic_uprobe_process_event+0x1edc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1edc;
	}
x86_l_1c18:
	/* 0x1c18: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_1c1b:
	/* 0x1c1b: jne    214a <generic_uprobe_process_event+0x214a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_214a;
	}
x86_l_1c21:
	/* 0x1c21: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_1c27:
	/* 0x1c27: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_1c2b:
	/* 0x1c2b: jmp    2098 <generic_uprobe_process_event+0x2098> */
	goto x86_l_2098;
x86_l_1c30:
	/* 0x1c30: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1c34:
	/* 0x1c34: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1c39:
	/* 0x1c39: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c3e:
	/* 0x1c3e: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c43:
	/* 0x1c43: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1c48:
	/* 0x1c48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c4a:
	/* 0x1c4a: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c4e:
	/* 0x1c4e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1c53:
	/* 0x1c53: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c58:
	/* 0x1c58: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1c5b:
	/* 0x1c5b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1c60:
	/* 0x1c60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c62:
	/* 0x1c62: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c67:
	/* 0x1c67: lea    rdi,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c6b:
	/* 0x1c6b: lea    r12,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1c6f:
	/* 0x1c6f: add    r13,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_1c73:
	/* 0x1c73: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1c78:
	/* 0x1c78: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c7d:
	/* 0x1c7d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1c82:
	/* 0x1c82: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1c85:
	/* 0x1c85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c87:
	/* 0x1c87: lea    rdi,[r15+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_1c8b:
	/* 0x1c8b: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1c90:
	/* 0x1c90: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c95:
	/* 0x1c95: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1c9a:
	/* 0x1c9a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1c9d:
	/* 0x1c9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c9f:
	/* 0x1c9f: movzx  eax,WORD PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_1ca4:
	/* 0x1ca4: movbe  WORD PTR [r15+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_1cab:
	/* 0x1cab: jmp    2abe <generic_uprobe_process_event+0x2abe> */
	return 10942ULL;
x86_l_1cb0:
	/* 0x1cb0: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cb5:
	/* 0x1cb5: lea    rdi,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cb9:
	/* 0x1cb9: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cbe:
	/* 0x1cbe: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1cc3:
	/* 0x1cc3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cc8:
	/* 0x1cc8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1ccd:
	/* 0x1ccd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ccf:
	/* 0x1ccf: lea    rdi,[rbx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1cd3:
	/* 0x1cd3: add    r12,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1cd7:
	/* 0x1cd7: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1cdc:
	/* 0x1cdc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ce1:
	/* 0x1ce1: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1ce6:
	/* 0x1ce6: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1ce9:
	/* 0x1ce9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ceb:
	/* 0x1ceb: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cf0:
	/* 0x1cf0: movzx  eax,WORD PTR [rcx+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1cf4:
	/* 0x1cf4: movbe  WORD PTR [rcx+0x2],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1cfa:
	/* 0x1cfa: mov    r13d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 24ULL);
x86_l_1d00:
	/* 0x1d00: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_1d03:
	/* 0x1d03: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1d08:
	/* 0x1d08: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d0d:
	/* 0x1d0d: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d12:
	/* 0x1d12: jmp    fbe <generic_uprobe_process_event+0xfbe> */
	return 4030ULL;
x86_l_1d17:
	/* 0x1d17: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d1c:
	/* 0x1d1c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1d1f:
	/* 0x1d1f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d24:
	/* 0x1d24: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d29:
	/* 0x1d29: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d2e:
	/* 0x1d2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d30:
	/* 0x1d30: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1d35:
	/* 0x1d35: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1d39:
	/* 0x1d39: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d3e:
	/* 0x1d3e: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d43:
	/* 0x1d43: je     d9f <generic_uprobe_process_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3487ULL;
	}
x86_l_1d49:
	/* 0x1d49: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1d4d:
	/* 0x1d4d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d52:
	/* 0x1d52: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d57:
	/* 0x1d57: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d5c:
	/* 0x1d5c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1d5f:
	/* 0x1d5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d61:
	/* 0x1d61: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d65:
	/* 0x1d65: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1d6a:
	/* 0x1d6a: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d6f:
	/* 0x1d6f: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1d74:
	/* 0x1d74: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d79:
	/* 0x1d79: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1d7e:
	/* 0x1d7e: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d83:
	/* 0x1d83: jne    1d90 <generic_uprobe_process_event+0x1d90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d90;
	}
x86_l_1d85:
	/* 0x1d85: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_1d8a:
	/* 0x1d8a: je     d9f <generic_uprobe_process_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3487ULL;
	}
x86_l_1d90:
	/* 0x1d90: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1d95:
	/* 0x1d95: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d9a:
	/* 0x1d9a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d9f:
	/* 0x1d9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1da4:
	/* 0x1da4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1da6:
	/* 0x1da6: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_1dab:
	/* 0x1dab: je     1eec <generic_uprobe_process_event+0x1eec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1eec;
	}
x86_l_1db1:
	/* 0x1db1: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1db5:
	/* 0x1db5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1db8:
	/* 0x1db8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1dbd:
	/* 0x1dbd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dc2:
	/* 0x1dc2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dc7:
	/* 0x1dc7: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1dca:
	/* 0x1dca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dcc:
	/* 0x1dcc: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dd0:
	/* 0x1dd0: je     1eec <generic_uprobe_process_event+0x1eec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1eec;
	}
x86_l_1dd6:
	/* 0x1dd6: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1ddb:
	/* 0x1ddb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1de0:
	/* 0x1de0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1de5:
	/* 0x1de5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dea:
	/* 0x1dea: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1ded:
	/* 0x1ded: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1def:
	/* 0x1def: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1df3:
	/* 0x1df3: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1df8:
	/* 0x1df8: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1dfd:
	/* 0x1dfd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e02:
	/* 0x1e02: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e07:
	/* 0x1e07: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1e0a:
	/* 0x1e0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e0c:
	/* 0x1e0c: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1e11:
	/* 0x1e11: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1e16:
	/* 0x1e16: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1e1a:
	/* 0x1e1a: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1e1d:
	/* 0x1e1d: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1e22:
	/* 0x1e22: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e24:
	/* 0x1e24: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1e26:
	/* 0x1e26: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1e29:
	/* 0x1e29: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1e2c:
	/* 0x1e2c: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_1e31:
	/* 0x1e31: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e33:
	/* 0x1e33: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1e36:
	/* 0x1e36: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_1e3a:
	/* 0x1e3a: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1e3c:
	/* 0x1e3c: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_1e40:
	/* 0x1e40: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1e42:
	/* 0x1e42: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_1e45:
	/* 0x1e45: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1e47:
	/* 0x1e47: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1e4b:
	/* 0x1e4b: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1e4e:
	/* 0x1e4e: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e53:
	/* 0x1e53: jb     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3492ULL;
	}
x86_l_1e59:
	/* 0x1e59: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_1e5f:
	/* 0x1e5f: ja     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3492ULL;
	}
x86_l_1e65:
	/* 0x1e65: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1e68:
	/* 0x1e68: jbe    1e6f <generic_uprobe_process_event+0x1e6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e6f;
	}
x86_l_1e6a:
	/* 0x1e6a: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_1e6f:
	/* 0x1e6f: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e71:
	/* 0x1e71: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1e74:
	/* 0x1e74: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_1e78:
	/* 0x1e78: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1e7b:
	/* 0x1e7b: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1e7e:
	/* 0x1e7e: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1e81:
	/* 0x1e81: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e86:
	/* 0x1e86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e88:
	/* 0x1e88: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1e8d:
	/* 0x1e8d: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_1e90:
	/* 0x1e90: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e95:
	/* 0x1e95: jbe    da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3492ULL;
	}
x86_l_1e9b:
	/* 0x1e9b: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1ea0:
	/* 0x1ea0: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ea5:
	/* 0x1ea5: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1eaa:
	/* 0x1eaa: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1eaf:
	/* 0x1eaf: jmp    1f4e <generic_uprobe_process_event+0x1f4e> */
	goto x86_l_1f4e;
x86_l_1eb4:
	/* 0x1eb4: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_1eb7:
	/* 0x1eb7: je     2089 <generic_uprobe_process_event+0x2089> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2089;
	}
x86_l_1ebd:
	/* 0x1ebd: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1ec0:
	/* 0x1ec0: je     1edc <generic_uprobe_process_event+0x1edc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1edc;
	}
x86_l_1ec2:
	/* 0x1ec2: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_1ec7:
	/* 0x1ec7: jne    214a <generic_uprobe_process_event+0x214a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_214a;
	}
x86_l_1ecd:
	/* 0x1ecd: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_1ed3:
	/* 0x1ed3: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_1ed7:
	/* 0x1ed7: jmp    2098 <generic_uprobe_process_event+0x2098> */
	goto x86_l_2098;
x86_l_1edc:
	/* 0x1edc: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_1ee0:
	/* 0x1ee0: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_1ee7:
	/* 0x1ee7: jmp    2094 <generic_uprobe_process_event+0x2094> */
	goto x86_l_2094;
x86_l_1eec:
	/* 0x1eec: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ef1:
	/* 0x1ef1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1ef4:
	/* 0x1ef4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ef9:
	/* 0x1ef9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1efe:
	/* 0x1efe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f03:
	/* 0x1f03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f05:
	/* 0x1f05: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1f0a:
	/* 0x1f0a: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1f0e:
	/* 0x1f0e: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f13:
	/* 0x1f13: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f18:
	/* 0x1f18: je     d9f <generic_uprobe_process_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3487ULL;
	}
x86_l_1f1e:
	/* 0x1f1e: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1f22:
	/* 0x1f22: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f27:
	/* 0x1f27: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f2c:
	/* 0x1f2c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f31:
	/* 0x1f31: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f34:
	/* 0x1f34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f36:
	/* 0x1f36: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f3a:
	/* 0x1f3a: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1f3f:
	/* 0x1f3f: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f44:
	/* 0x1f44: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1f49:
	/* 0x1f49: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f4e:
	/* 0x1f4e: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_1f53:
	/* 0x1f53: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f58:
	/* 0x1f58: jne    1f65 <generic_uprobe_process_event+0x1f65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f65;
	}
x86_l_1f5a:
	/* 0x1f5a: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_1f5f:
	/* 0x1f5f: je     d9f <generic_uprobe_process_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3487ULL;
	}
x86_l_1f65:
	/* 0x1f65: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1f6a:
	/* 0x1f6a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f6f:
	/* 0x1f6f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f74:
	/* 0x1f74: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f79:
	/* 0x1f79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f7b:
	/* 0x1f7b: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_1f80:
	/* 0x1f80: je     222f <generic_uprobe_process_event+0x222f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8751ULL;
	}
x86_l_1f86:
	/* 0x1f86: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f8a:
	/* 0x1f8a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1f8d:
	/* 0x1f8d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f92:
	/* 0x1f92: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f97:
	/* 0x1f97: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f9c:
	/* 0x1f9c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1f9f:
	/* 0x1f9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fa1:
	/* 0x1fa1: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fa5:
	/* 0x1fa5: je     222f <generic_uprobe_process_event+0x222f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8751ULL;
	}
x86_l_1fab:
	/* 0x1fab: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1fb0:
	/* 0x1fb0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1fb5:
	/* 0x1fb5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fba:
	/* 0x1fba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fbf:
	/* 0x1fbf: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1fc2:
	/* 0x1fc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fc4:
	/* 0x1fc4: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1fc8:
	/* 0x1fc8: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fcd:
	/* 0x1fcd: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1fd2:
	/* 0x1fd2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fd7:
	/* 0x1fd7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1fdc:
	/* 0x1fdc: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1fdf:
	/* 0x1fdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fe1:
	/* 0x1fe1: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1fe6:
	/* 0x1fe6: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1feb:
	/* 0x1feb: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1fef:
	/* 0x1fef: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1ff2:
	/* 0x1ff2: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1ff7:
	/* 0x1ff7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ff9:
	/* 0x1ff9: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1ffb:
	/* 0x1ffb: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1ffe:
	/* 0x1ffe: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2001:
	/* 0x2001: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2006:
	/* 0x2006: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2008:
	/* 0x2008: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_200b:
	/* 0x200b: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_200f:
	/* 0x200f: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_2011:
	/* 0x2011: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_2015:
	/* 0x2015: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2017:
	/* 0x2017: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_201a:
	/* 0x201a: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_201c:
	/* 0x201c: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2020:
	/* 0x2020: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2023:
	/* 0x2023: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2028:
	/* 0x2028: jb     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3492ULL;
	}
x86_l_202e:
	/* 0x202e: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_2034:
	/* 0x2034: ja     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3492ULL;
	}
x86_l_203a:
	/* 0x203a: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_203d:
	/* 0x203d: jbe    2044 <generic_uprobe_process_event+0x2044> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2044;
	}
x86_l_203f:
	/* 0x203f: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2044:
	/* 0x2044: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2046:
	/* 0x2046: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2049:
	/* 0x2049: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_204d:
	/* 0x204d: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2050:
	/* 0x2050: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2053:
	/* 0x2053: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2056:
	/* 0x2056: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_205b:
	/* 0x205b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_205d:
	/* 0x205d: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2062:
	/* 0x2062: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2065:
	/* 0x2065: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_206a:
	/* 0x206a: jbe    da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3492ULL;
	}
x86_l_2070:
	/* 0x2070: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2075:
	/* 0x2075: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_207a:
	/* 0x207a: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_207f:
	/* 0x207f: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2084:
	/* 0x2084: jmp    2291 <generic_uprobe_process_event+0x2291> */
	return 8849ULL;
x86_l_2089:
	/* 0x2089: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_208d:
	/* 0x208d: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2094:
	/* 0x2094: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2098:
	/* 0x2098: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_209c:
	/* 0x209c: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20a0:
	/* 0x20a0: movzx  r12d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_20a5:
	/* 0x20a5: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_20a9:
	/* 0x20a9: ja     2ad6 <generic_uprobe_process_event+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10966ULL;
	}
x86_l_20af:
	/* 0x20af: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_20b9:
	/* 0x20b9: bt     rcx,r12 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_20bd:
	/* 0x20bd: jae    2ad6 <generic_uprobe_process_event+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10966ULL;
	}
x86_l_20c3:
	/* 0x20c3: mov    BYTE PTR [rbp+0x5],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_20c7:
	/* 0x20c7: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_20ca:
	/* 0x20ca: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_20d2:
	/* 0x20d2: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_20d5:
	/* 0x20d5: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_20da:
	/* 0x20da: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20df:
	/* 0x20df: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_20e3:
	/* 0x20e3: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_20e6:
	/* 0x20e6: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_20e9:
	/* 0x20e9: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_20ee:
	/* 0x20ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20f0:
	/* 0x20f0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20f3:
	/* 0x20f3: js     2907 <generic_uprobe_process_event+0x2907> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10503ULL;
	}
x86_l_20f9:
	/* 0x20f9: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_20fd:
	/* 0x20fd: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2100:
	/* 0x2100: jg     211c <generic_uprobe_process_event+0x211c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_211c;
	}
x86_l_2102:
	/* 0x2102: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2104:
	/* 0x2104: je     2139 <generic_uprobe_process_event+0x2139> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2139;
	}
x86_l_2106:
	/* 0x2106: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2109:
	/* 0x2109: je     2139 <generic_uprobe_process_event+0x2139> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2139;
	}
x86_l_210b:
	/* 0x210b: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_210e:
	/* 0x210e: jne    2164 <generic_uprobe_process_event+0x2164> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2164;
	}
x86_l_2110:
	/* 0x2110: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2116:
	/* 0x2116: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_211a:
	/* 0x211a: jmp    2168 <generic_uprobe_process_event+0x2168> */
	goto x86_l_2168;
x86_l_211c:
	/* 0x211c: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_211f:
	/* 0x211f: je     2153 <generic_uprobe_process_event+0x2153> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2153;
	}
x86_l_2121:
	/* 0x2121: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2124:
	/* 0x2124: je     2139 <generic_uprobe_process_event+0x2139> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2139;
	}
x86_l_2126:
	/* 0x2126: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_212b:
	/* 0x212b: jne    2164 <generic_uprobe_process_event+0x2164> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2164;
	}
x86_l_212d:
	/* 0x212d: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2133:
	/* 0x2133: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2137:
	/* 0x2137: jmp    2168 <generic_uprobe_process_event+0x2168> */
	goto x86_l_2168;
x86_l_2139:
	/* 0x2139: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_213d:
	/* 0x213d: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2144:
	/* 0x2144: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2148:
	/* 0x2148: jmp    2168 <generic_uprobe_process_event+0x2168> */
	goto x86_l_2168;
x86_l_214a:
	/* 0x214a: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_214e:
	/* 0x214e: jmp    2098 <generic_uprobe_process_event+0x2098> */
	goto x86_l_2098;
x86_l_2153:
	/* 0x2153: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2157:
	/* 0x2157: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_215e:
	/* 0x215e: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2162:
	/* 0x2162: jmp    2168 <generic_uprobe_process_event+0x2168> */
	goto x86_l_2168;
x86_l_2164:
	/* 0x2164: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2168:
	/* 0x2168: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_216c:
	/* 0x216c: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2170:
	/* 0x2170: movzx  r12d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2175:
	/* 0x2175: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_2179:
	/* 0x2179: ja     2ad6 <generic_uprobe_process_event+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10966ULL;
	}
x86_l_217f:
	/* 0x217f: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
	return 8585ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8585ULL: goto x86_l_2189;
	case 8589ULL: goto x86_l_218d;
	case 8595ULL: goto x86_l_2193;
	case 8599ULL: goto x86_l_2197;
	case 8602ULL: goto x86_l_219a;
	case 8610ULL: goto x86_l_21a2;
	case 8613ULL: goto x86_l_21a5;
	case 8618ULL: goto x86_l_21aa;
	case 8623ULL: goto x86_l_21af;
	case 8627ULL: goto x86_l_21b3;
	case 8630ULL: goto x86_l_21b6;
	case 8633ULL: goto x86_l_21b9;
	case 8638ULL: goto x86_l_21be;
	case 8640ULL: goto x86_l_21c0;
	case 8643ULL: goto x86_l_21c3;
	case 8649ULL: goto x86_l_21c9;
	case 8653ULL: goto x86_l_21cd;
	case 8656ULL: goto x86_l_21d0;
	case 8658ULL: goto x86_l_21d2;
	case 8660ULL: goto x86_l_21d4;
	case 8662ULL: goto x86_l_21d6;
	case 8665ULL: goto x86_l_21d9;
	case 8667ULL: goto x86_l_21db;
	case 8670ULL: goto x86_l_21de;
	case 8676ULL: goto x86_l_21e4;
	case 8682ULL: goto x86_l_21ea;
	case 8686ULL: goto x86_l_21ee;
	case 8691ULL: goto x86_l_21f3;
	case 8694ULL: goto x86_l_21f6;
	case 8700ULL: goto x86_l_21fc;
	case 8703ULL: goto x86_l_21ff;
	case 8705ULL: goto x86_l_2201;
	case 8710ULL: goto x86_l_2206;
	case 8716ULL: goto x86_l_220c;
	case 8722ULL: goto x86_l_2212;
	case 8726ULL: goto x86_l_2216;
	case 8731ULL: goto x86_l_221b;
	case 8735ULL: goto x86_l_221f;
	case 8742ULL: goto x86_l_2226;
	case 8746ULL: goto x86_l_222a;
	case 8751ULL: goto x86_l_222f;
	case 8756ULL: goto x86_l_2234;
	case 8759ULL: goto x86_l_2237;
	case 8764ULL: goto x86_l_223c;
	case 8769ULL: goto x86_l_2241;
	case 8774ULL: goto x86_l_2246;
	case 8776ULL: goto x86_l_2248;
	case 8781ULL: goto x86_l_224d;
	case 8785ULL: goto x86_l_2251;
	case 8790ULL: goto x86_l_2256;
	case 8795ULL: goto x86_l_225b;
	case 8801ULL: goto x86_l_2261;
	case 8805ULL: goto x86_l_2265;
	case 8810ULL: goto x86_l_226a;
	case 8815ULL: goto x86_l_226f;
	case 8820ULL: goto x86_l_2274;
	case 8823ULL: goto x86_l_2277;
	case 8825ULL: goto x86_l_2279;
	case 8829ULL: goto x86_l_227d;
	case 8834ULL: goto x86_l_2282;
	case 8839ULL: goto x86_l_2287;
	case 8844ULL: goto x86_l_228c;
	case 8849ULL: goto x86_l_2291;
	case 8854ULL: goto x86_l_2296;
	case 8859ULL: goto x86_l_229b;
	case 8861ULL: goto x86_l_229d;
	case 8866ULL: goto x86_l_22a2;
	case 8872ULL: goto x86_l_22a8;
	case 8877ULL: goto x86_l_22ad;
	case 8882ULL: goto x86_l_22b2;
	case 8887ULL: goto x86_l_22b7;
	case 8892ULL: goto x86_l_22bc;
	case 8894ULL: goto x86_l_22be;
	case 8899ULL: goto x86_l_22c3;
	case 8905ULL: goto x86_l_22c9;
	case 8909ULL: goto x86_l_22cd;
	case 8912ULL: goto x86_l_22d0;
	case 8917ULL: goto x86_l_22d5;
	case 8922ULL: goto x86_l_22da;
	case 8927ULL: goto x86_l_22df;
	case 8930ULL: goto x86_l_22e2;
	case 8932ULL: goto x86_l_22e4;
	case 8936ULL: goto x86_l_22e8;
	case 8942ULL: goto x86_l_22ee;
	case 8947ULL: goto x86_l_22f3;
	case 8952ULL: goto x86_l_22f8;
	case 8957ULL: goto x86_l_22fd;
	case 8962ULL: goto x86_l_2302;
	case 8965ULL: goto x86_l_2305;
	case 8967ULL: goto x86_l_2307;
	case 8971ULL: goto x86_l_230b;
	case 8976ULL: goto x86_l_2310;
	case 8981ULL: goto x86_l_2315;
	case 8986ULL: goto x86_l_231a;
	case 8991ULL: goto x86_l_231f;
	case 8994ULL: goto x86_l_2322;
	case 8996ULL: goto x86_l_2324;
	case 9001ULL: goto x86_l_2329;
	case 9006ULL: goto x86_l_232e;
	case 9010ULL: goto x86_l_2332;
	case 9013ULL: goto x86_l_2335;
	case 9018ULL: goto x86_l_233a;
	case 9020ULL: goto x86_l_233c;
	case 9022ULL: goto x86_l_233e;
	case 9025ULL: goto x86_l_2341;
	case 9028ULL: goto x86_l_2344;
	case 9033ULL: goto x86_l_2349;
	case 9035ULL: goto x86_l_234b;
	case 9038ULL: goto x86_l_234e;
	case 9042ULL: goto x86_l_2352;
	case 9044ULL: goto x86_l_2354;
	case 9048ULL: goto x86_l_2358;
	case 9050ULL: goto x86_l_235a;
	case 9053ULL: goto x86_l_235d;
	case 9055ULL: goto x86_l_235f;
	case 9059ULL: goto x86_l_2363;
	case 9062ULL: goto x86_l_2366;
	case 9067ULL: goto x86_l_236b;
	case 9073ULL: goto x86_l_2371;
	case 9079ULL: goto x86_l_2377;
	case 9085ULL: goto x86_l_237d;
	case 9088ULL: goto x86_l_2380;
	case 9090ULL: goto x86_l_2382;
	case 9095ULL: goto x86_l_2387;
	case 9097ULL: goto x86_l_2389;
	case 9100ULL: goto x86_l_238c;
	case 9104ULL: goto x86_l_2390;
	case 9107ULL: goto x86_l_2393;
	case 9110ULL: goto x86_l_2396;
	case 9113ULL: goto x86_l_2399;
	case 9118ULL: goto x86_l_239e;
	case 9120ULL: goto x86_l_23a0;
	case 9125ULL: goto x86_l_23a5;
	case 9128ULL: goto x86_l_23a8;
	case 9133ULL: goto x86_l_23ad;
	case 9139ULL: goto x86_l_23b3;
	case 9144ULL: goto x86_l_23b8;
	case 9149ULL: goto x86_l_23bd;
	case 9154ULL: goto x86_l_23c2;
	case 9159ULL: goto x86_l_23c7;
	case 9164ULL: goto x86_l_23cc;
	case 9168ULL: goto x86_l_23d0;
	case 9175ULL: goto x86_l_23d7;
	case 9179ULL: goto x86_l_23db;
	case 9181ULL: goto x86_l_23dd;
	case 9185ULL: goto x86_l_23e1;
	case 9189ULL: goto x86_l_23e5;
	case 9193ULL: goto x86_l_23e9;
	case 9198ULL: goto x86_l_23ee;
	case 9202ULL: goto x86_l_23f2;
	case 9208ULL: goto x86_l_23f8;
	case 9218ULL: goto x86_l_2402;
	case 9222ULL: goto x86_l_2406;
	case 9228ULL: goto x86_l_240c;
	case 9232ULL: goto x86_l_2410;
	case 9235ULL: goto x86_l_2413;
	case 9243ULL: goto x86_l_241b;
	case 9246ULL: goto x86_l_241e;
	case 9251ULL: goto x86_l_2423;
	case 9256ULL: goto x86_l_2428;
	case 9260ULL: goto x86_l_242c;
	case 9263ULL: goto x86_l_242f;
	case 9266ULL: goto x86_l_2432;
	case 9271ULL: goto x86_l_2437;
	case 9273ULL: goto x86_l_2439;
	case 9276ULL: goto x86_l_243c;
	case 9282ULL: goto x86_l_2442;
	case 9286ULL: goto x86_l_2446;
	case 9289ULL: goto x86_l_2449;
	case 9291ULL: goto x86_l_244b;
	case 9293ULL: goto x86_l_244d;
	case 9295ULL: goto x86_l_244f;
	case 9298ULL: goto x86_l_2452;
	case 9300ULL: goto x86_l_2454;
	case 9303ULL: goto x86_l_2457;
	case 9305ULL: goto x86_l_2459;
	case 9311ULL: goto x86_l_245f;
	case 9315ULL: goto x86_l_2463;
	case 9317ULL: goto x86_l_2465;
	case 9320ULL: goto x86_l_2468;
	case 9322ULL: goto x86_l_246a;
	case 9325ULL: goto x86_l_246d;
	case 9327ULL: goto x86_l_246f;
	case 9332ULL: goto x86_l_2474;
	case 9334ULL: goto x86_l_2476;
	case 9340ULL: goto x86_l_247c;
	case 9344ULL: goto x86_l_2480;
	case 9346ULL: goto x86_l_2482;
	case 9350ULL: goto x86_l_2486;
	case 9357ULL: goto x86_l_248d;
	case 9361ULL: goto x86_l_2491;
	case 9363ULL: goto x86_l_2493;
	case 9367ULL: goto x86_l_2497;
	case 9374ULL: goto x86_l_249e;
	case 9378ULL: goto x86_l_24a2;
	case 9380ULL: goto x86_l_24a4;
	case 9384ULL: goto x86_l_24a8;
	case 9388ULL: goto x86_l_24ac;
	case 9392ULL: goto x86_l_24b0;
	case 9397ULL: goto x86_l_24b5;
	case 9401ULL: goto x86_l_24b9;
	case 9407ULL: goto x86_l_24bf;
	case 9417ULL: goto x86_l_24c9;
	case 9421ULL: goto x86_l_24cd;
	case 9427ULL: goto x86_l_24d3;
	case 9431ULL: goto x86_l_24d7;
	case 9434ULL: goto x86_l_24da;
	case 9442ULL: goto x86_l_24e2;
	case 9445ULL: goto x86_l_24e5;
	case 9450ULL: goto x86_l_24ea;
	case 9455ULL: goto x86_l_24ef;
	case 9459ULL: goto x86_l_24f3;
	case 9462ULL: goto x86_l_24f6;
	case 9465ULL: goto x86_l_24f9;
	case 9470ULL: goto x86_l_24fe;
	case 9472ULL: goto x86_l_2500;
	case 9475ULL: goto x86_l_2503;
	case 9481ULL: goto x86_l_2509;
	case 9485ULL: goto x86_l_250d;
	case 9488ULL: goto x86_l_2510;
	case 9490ULL: goto x86_l_2512;
	case 9492ULL: goto x86_l_2514;
	case 9494ULL: goto x86_l_2516;
	case 9497ULL: goto x86_l_2519;
	case 9499ULL: goto x86_l_251b;
	case 9502ULL: goto x86_l_251e;
	case 9508ULL: goto x86_l_2524;
	case 9514ULL: goto x86_l_252a;
	case 9518ULL: goto x86_l_252e;
	case 9523ULL: goto x86_l_2533;
	case 9526ULL: goto x86_l_2536;
	case 9532ULL: goto x86_l_253c;
	case 9535ULL: goto x86_l_253f;
	case 9537ULL: goto x86_l_2541;
	case 9542ULL: goto x86_l_2546;
	case 9548ULL: goto x86_l_254c;
	case 9554ULL: goto x86_l_2552;
	case 9558ULL: goto x86_l_2556;
	case 9563ULL: goto x86_l_255b;
	case 9567ULL: goto x86_l_255f;
	case 9574ULL: goto x86_l_2566;
	case 9578ULL: goto x86_l_256a;
	case 9583ULL: goto x86_l_256f;
	case 9588ULL: goto x86_l_2574;
	case 9591ULL: goto x86_l_2577;
	case 9596ULL: goto x86_l_257c;
	case 9601ULL: goto x86_l_2581;
	case 9606ULL: goto x86_l_2586;
	case 9608ULL: goto x86_l_2588;
	case 9613ULL: goto x86_l_258d;
	case 9617ULL: goto x86_l_2591;
	case 9622ULL: goto x86_l_2596;
	case 9627ULL: goto x86_l_259b;
	case 9633ULL: goto x86_l_25a1;
	case 9637ULL: goto x86_l_25a5;
	case 9642ULL: goto x86_l_25aa;
	case 9647ULL: goto x86_l_25af;
	case 9652ULL: goto x86_l_25b4;
	case 9655ULL: goto x86_l_25b7;
	case 9657ULL: goto x86_l_25b9;
	case 9661ULL: goto x86_l_25bd;
	case 9666ULL: goto x86_l_25c2;
	case 9671ULL: goto x86_l_25c7;
	case 9676ULL: goto x86_l_25cc;
	case 9681ULL: goto x86_l_25d1;
	case 9686ULL: goto x86_l_25d6;
	case 9691ULL: goto x86_l_25db;
	case 9693ULL: goto x86_l_25dd;
	case 9698ULL: goto x86_l_25e2;
	case 9704ULL: goto x86_l_25e8;
	case 9709ULL: goto x86_l_25ed;
	case 9714ULL: goto x86_l_25f2;
	case 9719ULL: goto x86_l_25f7;
	case 9724ULL: goto x86_l_25fc;
	case 9726ULL: goto x86_l_25fe;
	case 9731ULL: goto x86_l_2603;
	case 9737ULL: goto x86_l_2609;
	case 9741ULL: goto x86_l_260d;
	case 9744ULL: goto x86_l_2610;
	case 9749ULL: goto x86_l_2615;
	case 9754ULL: goto x86_l_261a;
	case 9759ULL: goto x86_l_261f;
	case 9762ULL: goto x86_l_2622;
	case 9764ULL: goto x86_l_2624;
	case 9768ULL: goto x86_l_2628;
	case 9774ULL: goto x86_l_262e;
	case 9779ULL: goto x86_l_2633;
	case 9784ULL: goto x86_l_2638;
	case 9789ULL: goto x86_l_263d;
	case 9794ULL: goto x86_l_2642;
	case 9797ULL: goto x86_l_2645;
	case 9799ULL: goto x86_l_2647;
	case 9803ULL: goto x86_l_264b;
	case 9808ULL: goto x86_l_2650;
	case 9813ULL: goto x86_l_2655;
	case 9818ULL: goto x86_l_265a;
	case 9823ULL: goto x86_l_265f;
	case 9826ULL: goto x86_l_2662;
	case 9828ULL: goto x86_l_2664;
	case 9833ULL: goto x86_l_2669;
	case 9838ULL: goto x86_l_266e;
	case 9842ULL: goto x86_l_2672;
	case 9845ULL: goto x86_l_2675;
	case 9850ULL: goto x86_l_267a;
	case 9852ULL: goto x86_l_267c;
	case 9854ULL: goto x86_l_267e;
	case 9857ULL: goto x86_l_2681;
	case 9860ULL: goto x86_l_2684;
	case 9865ULL: goto x86_l_2689;
	case 9867ULL: goto x86_l_268b;
	case 9870ULL: goto x86_l_268e;
	case 9874ULL: goto x86_l_2692;
	case 9876ULL: goto x86_l_2694;
	case 9880ULL: goto x86_l_2698;
	case 9882ULL: goto x86_l_269a;
	case 9885ULL: goto x86_l_269d;
	case 9887ULL: goto x86_l_269f;
	case 9891ULL: goto x86_l_26a3;
	case 9894ULL: goto x86_l_26a6;
	case 9899ULL: goto x86_l_26ab;
	case 9905ULL: goto x86_l_26b1;
	case 9911ULL: goto x86_l_26b7;
	case 9917ULL: goto x86_l_26bd;
	case 9920ULL: goto x86_l_26c0;
	case 9922ULL: goto x86_l_26c2;
	case 9927ULL: goto x86_l_26c7;
	case 9929ULL: goto x86_l_26c9;
	case 9932ULL: goto x86_l_26cc;
	case 9936ULL: goto x86_l_26d0;
	case 9939ULL: goto x86_l_26d3;
	case 9942ULL: goto x86_l_26d6;
	case 9945ULL: goto x86_l_26d9;
	case 9950ULL: goto x86_l_26de;
	case 9952ULL: goto x86_l_26e0;
	case 9957ULL: goto x86_l_26e5;
	case 9960ULL: goto x86_l_26e8;
	case 9965ULL: goto x86_l_26ed;
	case 9971ULL: goto x86_l_26f3;
	case 9976ULL: goto x86_l_26f8;
	case 9981ULL: goto x86_l_26fd;
	case 9986ULL: goto x86_l_2702;
	case 9991ULL: goto x86_l_2707;
	case 9996ULL: goto x86_l_270c;
	case 10000ULL: goto x86_l_2710;
	case 10007ULL: goto x86_l_2717;
	case 10011ULL: goto x86_l_271b;
	case 10013ULL: goto x86_l_271d;
	case 10017ULL: goto x86_l_2721;
	case 10021ULL: goto x86_l_2725;
	case 10025ULL: goto x86_l_2729;
	case 10030ULL: goto x86_l_272e;
	case 10034ULL: goto x86_l_2732;
	case 10040ULL: goto x86_l_2738;
	case 10050ULL: goto x86_l_2742;
	case 10054ULL: goto x86_l_2746;
	case 10060ULL: goto x86_l_274c;
	case 10064ULL: goto x86_l_2750;
	case 10067ULL: goto x86_l_2753;
	case 10075ULL: goto x86_l_275b;
	case 10078ULL: goto x86_l_275e;
	case 10083ULL: goto x86_l_2763;
	case 10088ULL: goto x86_l_2768;
	case 10092ULL: goto x86_l_276c;
	case 10095ULL: goto x86_l_276f;
	case 10098ULL: goto x86_l_2772;
	case 10103ULL: goto x86_l_2777;
	case 10105ULL: goto x86_l_2779;
	case 10108ULL: goto x86_l_277c;
	case 10114ULL: goto x86_l_2782;
	case 10118ULL: goto x86_l_2786;
	case 10121ULL: goto x86_l_2789;
	case 10123ULL: goto x86_l_278b;
	case 10125ULL: goto x86_l_278d;
	case 10127ULL: goto x86_l_278f;
	case 10130ULL: goto x86_l_2792;
	case 10132ULL: goto x86_l_2794;
	case 10135ULL: goto x86_l_2797;
	case 10137ULL: goto x86_l_2799;
	case 10143ULL: goto x86_l_279f;
	case 10147ULL: goto x86_l_27a3;
	case 10149ULL: goto x86_l_27a5;
	case 10152ULL: goto x86_l_27a8;
	case 10154ULL: goto x86_l_27aa;
	case 10157ULL: goto x86_l_27ad;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2189:
	/* 0x2189: bt     rcx,r12 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_218d:
	/* 0x218d: jae    2ad6 <generic_uprobe_process_event+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10966ULL;
	}
x86_l_2193:
	/* 0x2193: mov    BYTE PTR [rbp+0x5],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2197:
	/* 0x2197: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_219a:
	/* 0x219a: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_21a2:
	/* 0x21a2: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_21a5:
	/* 0x21a5: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_21aa:
	/* 0x21aa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21af:
	/* 0x21af: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_21b3:
	/* 0x21b3: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_21b6:
	/* 0x21b6: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_21b9:
	/* 0x21b9: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_21be:
	/* 0x21be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21c0:
	/* 0x21c0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21c3:
	/* 0x21c3: js     2907 <generic_uprobe_process_event+0x2907> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10503ULL;
	}
x86_l_21c9:
	/* 0x21c9: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_21cd:
	/* 0x21cd: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_21d0:
	/* 0x21d0: jg     21f3 <generic_uprobe_process_event+0x21f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_21f3;
	}
x86_l_21d2:
	/* 0x21d2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21d4:
	/* 0x21d4: je     221b <generic_uprobe_process_event+0x221b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_221b;
	}
x86_l_21d6:
	/* 0x21d6: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_21d9:
	/* 0x21d9: je     221b <generic_uprobe_process_event+0x221b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_221b;
	}
x86_l_21db:
	/* 0x21db: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_21de:
	/* 0x21de: jne    23dd <generic_uprobe_process_event+0x23dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23dd;
	}
x86_l_21e4:
	/* 0x21e4: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_21ea:
	/* 0x21ea: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_21ee:
	/* 0x21ee: jmp    23e1 <generic_uprobe_process_event+0x23e1> */
	goto x86_l_23e1;
x86_l_21f3:
	/* 0x21f3: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_21f6:
	/* 0x21f6: je     23cc <generic_uprobe_process_event+0x23cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23cc;
	}
x86_l_21fc:
	/* 0x21fc: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_21ff:
	/* 0x21ff: je     221b <generic_uprobe_process_event+0x221b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_221b;
	}
x86_l_2201:
	/* 0x2201: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2206:
	/* 0x2206: jne    23dd <generic_uprobe_process_event+0x23dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23dd;
	}
x86_l_220c:
	/* 0x220c: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2212:
	/* 0x2212: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2216:
	/* 0x2216: jmp    23e1 <generic_uprobe_process_event+0x23e1> */
	goto x86_l_23e1;
x86_l_221b:
	/* 0x221b: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_221f:
	/* 0x221f: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2226:
	/* 0x2226: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_222a:
	/* 0x222a: jmp    23e1 <generic_uprobe_process_event+0x23e1> */
	goto x86_l_23e1;
x86_l_222f:
	/* 0x222f: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2234:
	/* 0x2234: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2237:
	/* 0x2237: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_223c:
	/* 0x223c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2241:
	/* 0x2241: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2246:
	/* 0x2246: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2248:
	/* 0x2248: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_224d:
	/* 0x224d: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2251:
	/* 0x2251: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2256:
	/* 0x2256: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_225b:
	/* 0x225b: je     d9f <generic_uprobe_process_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3487ULL;
	}
x86_l_2261:
	/* 0x2261: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2265:
	/* 0x2265: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_226a:
	/* 0x226a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_226f:
	/* 0x226f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2274:
	/* 0x2274: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2277:
	/* 0x2277: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2279:
	/* 0x2279: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_227d:
	/* 0x227d: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2282:
	/* 0x2282: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2287:
	/* 0x2287: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_228c:
	/* 0x228c: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2291:
	/* 0x2291: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2296:
	/* 0x2296: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_229b:
	/* 0x229b: jne    22a8 <generic_uprobe_process_event+0x22a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22a8;
	}
x86_l_229d:
	/* 0x229d: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_22a2:
	/* 0x22a2: je     d9f <generic_uprobe_process_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3487ULL;
	}
x86_l_22a8:
	/* 0x22a8: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_22ad:
	/* 0x22ad: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22b2:
	/* 0x22b2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22b7:
	/* 0x22b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22bc:
	/* 0x22bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22be:
	/* 0x22be: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_22c3:
	/* 0x22c3: je     256f <generic_uprobe_process_event+0x256f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_256f;
	}
x86_l_22c9:
	/* 0x22c9: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22cd:
	/* 0x22cd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_22d0:
	/* 0x22d0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22d5:
	/* 0x22d5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22da:
	/* 0x22da: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22df:
	/* 0x22df: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_22e2:
	/* 0x22e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22e4:
	/* 0x22e4: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22e8:
	/* 0x22e8: je     256f <generic_uprobe_process_event+0x256f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_256f;
	}
x86_l_22ee:
	/* 0x22ee: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_22f3:
	/* 0x22f3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22f8:
	/* 0x22f8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22fd:
	/* 0x22fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2302:
	/* 0x2302: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2305:
	/* 0x2305: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2307:
	/* 0x2307: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_230b:
	/* 0x230b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2310:
	/* 0x2310: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2315:
	/* 0x2315: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_231a:
	/* 0x231a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_231f:
	/* 0x231f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2322:
	/* 0x2322: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2324:
	/* 0x2324: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2329:
	/* 0x2329: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_232e:
	/* 0x232e: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2332:
	/* 0x2332: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2335:
	/* 0x2335: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_233a:
	/* 0x233a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_233c:
	/* 0x233c: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_233e:
	/* 0x233e: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2341:
	/* 0x2341: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2344:
	/* 0x2344: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2349:
	/* 0x2349: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_234b:
	/* 0x234b: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_234e:
	/* 0x234e: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_2352:
	/* 0x2352: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_2354:
	/* 0x2354: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_2358:
	/* 0x2358: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_235a:
	/* 0x235a: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_235d:
	/* 0x235d: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_235f:
	/* 0x235f: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2363:
	/* 0x2363: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2366:
	/* 0x2366: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_236b:
	/* 0x236b: jb     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3492ULL;
	}
x86_l_2371:
	/* 0x2371: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_2377:
	/* 0x2377: ja     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3492ULL;
	}
x86_l_237d:
	/* 0x237d: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2380:
	/* 0x2380: jbe    2387 <generic_uprobe_process_event+0x2387> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2387;
	}
x86_l_2382:
	/* 0x2382: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2387:
	/* 0x2387: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2389:
	/* 0x2389: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_238c:
	/* 0x238c: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_2390:
	/* 0x2390: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2393:
	/* 0x2393: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2396:
	/* 0x2396: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2399:
	/* 0x2399: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_239e:
	/* 0x239e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23a0:
	/* 0x23a0: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_23a5:
	/* 0x23a5: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_23a8:
	/* 0x23a8: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23ad:
	/* 0x23ad: jbe    da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3492ULL;
	}
x86_l_23b3:
	/* 0x23b3: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_23b8:
	/* 0x23b8: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_23bd:
	/* 0x23bd: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_23c2:
	/* 0x23c2: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_23c7:
	/* 0x23c7: jmp    25d1 <generic_uprobe_process_event+0x25d1> */
	goto x86_l_25d1;
x86_l_23cc:
	/* 0x23cc: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_23d0:
	/* 0x23d0: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_23d7:
	/* 0x23d7: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_23db:
	/* 0x23db: jmp    23e1 <generic_uprobe_process_event+0x23e1> */
	goto x86_l_23e1;
x86_l_23dd:
	/* 0x23dd: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_23e1:
	/* 0x23e1: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_23e5:
	/* 0x23e5: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23e9:
	/* 0x23e9: movzx  r12d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_23ee:
	/* 0x23ee: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_23f2:
	/* 0x23f2: ja     2ad6 <generic_uprobe_process_event+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10966ULL;
	}
x86_l_23f8:
	/* 0x23f8: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2402:
	/* 0x2402: bt     rcx,r12 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2406:
	/* 0x2406: jae    2ad6 <generic_uprobe_process_event+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10966ULL;
	}
x86_l_240c:
	/* 0x240c: mov    BYTE PTR [rbp+0x5],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2410:
	/* 0x2410: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2413:
	/* 0x2413: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_241b:
	/* 0x241b: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_241e:
	/* 0x241e: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2423:
	/* 0x2423: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2428:
	/* 0x2428: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_242c:
	/* 0x242c: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_242f:
	/* 0x242f: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2432:
	/* 0x2432: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2437:
	/* 0x2437: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2439:
	/* 0x2439: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_243c:
	/* 0x243c: js     2907 <generic_uprobe_process_event+0x2907> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10503ULL;
	}
x86_l_2442:
	/* 0x2442: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2446:
	/* 0x2446: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2449:
	/* 0x2449: jg     2465 <generic_uprobe_process_event+0x2465> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2465;
	}
x86_l_244b:
	/* 0x244b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_244d:
	/* 0x244d: je     2482 <generic_uprobe_process_event+0x2482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2482;
	}
x86_l_244f:
	/* 0x244f: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2452:
	/* 0x2452: je     2482 <generic_uprobe_process_event+0x2482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2482;
	}
x86_l_2454:
	/* 0x2454: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2457:
	/* 0x2457: jne    24a4 <generic_uprobe_process_event+0x24a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24a4;
	}
x86_l_2459:
	/* 0x2459: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_245f:
	/* 0x245f: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2463:
	/* 0x2463: jmp    24a8 <generic_uprobe_process_event+0x24a8> */
	goto x86_l_24a8;
x86_l_2465:
	/* 0x2465: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2468:
	/* 0x2468: je     2493 <generic_uprobe_process_event+0x2493> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2493;
	}
x86_l_246a:
	/* 0x246a: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_246d:
	/* 0x246d: je     2482 <generic_uprobe_process_event+0x2482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2482;
	}
x86_l_246f:
	/* 0x246f: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2474:
	/* 0x2474: jne    24a4 <generic_uprobe_process_event+0x24a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24a4;
	}
x86_l_2476:
	/* 0x2476: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_247c:
	/* 0x247c: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2480:
	/* 0x2480: jmp    24a8 <generic_uprobe_process_event+0x24a8> */
	goto x86_l_24a8;
x86_l_2482:
	/* 0x2482: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2486:
	/* 0x2486: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_248d:
	/* 0x248d: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2491:
	/* 0x2491: jmp    24a8 <generic_uprobe_process_event+0x24a8> */
	goto x86_l_24a8;
x86_l_2493:
	/* 0x2493: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2497:
	/* 0x2497: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_249e:
	/* 0x249e: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_24a2:
	/* 0x24a2: jmp    24a8 <generic_uprobe_process_event+0x24a8> */
	goto x86_l_24a8;
x86_l_24a4:
	/* 0x24a4: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_24a8:
	/* 0x24a8: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_24ac:
	/* 0x24ac: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24b0:
	/* 0x24b0: movzx  r12d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_24b5:
	/* 0x24b5: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_24b9:
	/* 0x24b9: ja     2ad6 <generic_uprobe_process_event+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10966ULL;
	}
x86_l_24bf:
	/* 0x24bf: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_24c9:
	/* 0x24c9: bt     rcx,r12 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_24cd:
	/* 0x24cd: jae    2ad6 <generic_uprobe_process_event+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10966ULL;
	}
x86_l_24d3:
	/* 0x24d3: mov    BYTE PTR [rbp+0x5],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_24d7:
	/* 0x24d7: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_24da:
	/* 0x24da: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_24e2:
	/* 0x24e2: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_24e5:
	/* 0x24e5: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_24ea:
	/* 0x24ea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24ef:
	/* 0x24ef: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_24f3:
	/* 0x24f3: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_24f6:
	/* 0x24f6: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_24f9:
	/* 0x24f9: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_24fe:
	/* 0x24fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2500:
	/* 0x2500: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2503:
	/* 0x2503: js     2907 <generic_uprobe_process_event+0x2907> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10503ULL;
	}
x86_l_2509:
	/* 0x2509: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_250d:
	/* 0x250d: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2510:
	/* 0x2510: jg     2533 <generic_uprobe_process_event+0x2533> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2533;
	}
x86_l_2512:
	/* 0x2512: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2514:
	/* 0x2514: je     255b <generic_uprobe_process_event+0x255b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_255b;
	}
x86_l_2516:
	/* 0x2516: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2519:
	/* 0x2519: je     255b <generic_uprobe_process_event+0x255b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_255b;
	}
x86_l_251b:
	/* 0x251b: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_251e:
	/* 0x251e: jne    271d <generic_uprobe_process_event+0x271d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_271d;
	}
x86_l_2524:
	/* 0x2524: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_252a:
	/* 0x252a: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_252e:
	/* 0x252e: jmp    2721 <generic_uprobe_process_event+0x2721> */
	goto x86_l_2721;
x86_l_2533:
	/* 0x2533: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2536:
	/* 0x2536: je     270c <generic_uprobe_process_event+0x270c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_270c;
	}
x86_l_253c:
	/* 0x253c: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_253f:
	/* 0x253f: je     255b <generic_uprobe_process_event+0x255b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_255b;
	}
x86_l_2541:
	/* 0x2541: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2546:
	/* 0x2546: jne    271d <generic_uprobe_process_event+0x271d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_271d;
	}
x86_l_254c:
	/* 0x254c: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2552:
	/* 0x2552: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2556:
	/* 0x2556: jmp    2721 <generic_uprobe_process_event+0x2721> */
	goto x86_l_2721;
x86_l_255b:
	/* 0x255b: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_255f:
	/* 0x255f: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2566:
	/* 0x2566: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_256a:
	/* 0x256a: jmp    2721 <generic_uprobe_process_event+0x2721> */
	goto x86_l_2721;
x86_l_256f:
	/* 0x256f: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2574:
	/* 0x2574: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2577:
	/* 0x2577: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_257c:
	/* 0x257c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2581:
	/* 0x2581: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2586:
	/* 0x2586: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2588:
	/* 0x2588: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_258d:
	/* 0x258d: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2591:
	/* 0x2591: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2596:
	/* 0x2596: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_259b:
	/* 0x259b: je     d9f <generic_uprobe_process_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3487ULL;
	}
x86_l_25a1:
	/* 0x25a1: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_25a5:
	/* 0x25a5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_25aa:
	/* 0x25aa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25af:
	/* 0x25af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25b4:
	/* 0x25b4: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_25b7:
	/* 0x25b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25b9:
	/* 0x25b9: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25bd:
	/* 0x25bd: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_25c2:
	/* 0x25c2: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25c7:
	/* 0x25c7: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_25cc:
	/* 0x25cc: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25d1:
	/* 0x25d1: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_25d6:
	/* 0x25d6: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25db:
	/* 0x25db: jne    25e8 <generic_uprobe_process_event+0x25e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25e8;
	}
x86_l_25dd:
	/* 0x25dd: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_25e2:
	/* 0x25e2: je     d9f <generic_uprobe_process_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3487ULL;
	}
x86_l_25e8:
	/* 0x25e8: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_25ed:
	/* 0x25ed: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_25f2:
	/* 0x25f2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25f7:
	/* 0x25f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25fc:
	/* 0x25fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25fe:
	/* 0x25fe: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_2603:
	/* 0x2603: je     2ae3 <generic_uprobe_process_event+0x2ae3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10979ULL;
	}
x86_l_2609:
	/* 0x2609: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_260d:
	/* 0x260d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2610:
	/* 0x2610: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2615:
	/* 0x2615: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_261a:
	/* 0x261a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_261f:
	/* 0x261f: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2622:
	/* 0x2622: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2624:
	/* 0x2624: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2628:
	/* 0x2628: je     2ae3 <generic_uprobe_process_event+0x2ae3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10979ULL;
	}
x86_l_262e:
	/* 0x262e: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2633:
	/* 0x2633: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2638:
	/* 0x2638: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_263d:
	/* 0x263d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2642:
	/* 0x2642: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2645:
	/* 0x2645: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2647:
	/* 0x2647: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_264b:
	/* 0x264b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2650:
	/* 0x2650: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2655:
	/* 0x2655: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_265a:
	/* 0x265a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_265f:
	/* 0x265f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2662:
	/* 0x2662: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2664:
	/* 0x2664: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2669:
	/* 0x2669: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_266e:
	/* 0x266e: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2672:
	/* 0x2672: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2675:
	/* 0x2675: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_267a:
	/* 0x267a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_267c:
	/* 0x267c: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_267e:
	/* 0x267e: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2681:
	/* 0x2681: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2684:
	/* 0x2684: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2689:
	/* 0x2689: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_268b:
	/* 0x268b: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_268e:
	/* 0x268e: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_2692:
	/* 0x2692: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_2694:
	/* 0x2694: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_2698:
	/* 0x2698: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_269a:
	/* 0x269a: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_269d:
	/* 0x269d: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_269f:
	/* 0x269f: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_26a3:
	/* 0x26a3: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_26a6:
	/* 0x26a6: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26ab:
	/* 0x26ab: jb     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3492ULL;
	}
x86_l_26b1:
	/* 0x26b1: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_26b7:
	/* 0x26b7: ja     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3492ULL;
	}
x86_l_26bd:
	/* 0x26bd: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_26c0:
	/* 0x26c0: jbe    26c7 <generic_uprobe_process_event+0x26c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_26c7;
	}
x86_l_26c2:
	/* 0x26c2: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_26c7:
	/* 0x26c7: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26c9:
	/* 0x26c9: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_26cc:
	/* 0x26cc: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_26d0:
	/* 0x26d0: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_26d3:
	/* 0x26d3: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26d6:
	/* 0x26d6: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26d9:
	/* 0x26d9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26de:
	/* 0x26de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26e0:
	/* 0x26e0: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_26e5:
	/* 0x26e5: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_26e8:
	/* 0x26e8: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26ed:
	/* 0x26ed: jbe    da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3492ULL;
	}
x86_l_26f3:
	/* 0x26f3: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_26f8:
	/* 0x26f8: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_26fd:
	/* 0x26fd: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2702:
	/* 0x2702: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2707:
	/* 0x2707: jmp    2b45 <generic_uprobe_process_event+0x2b45> */
	return 11077ULL;
x86_l_270c:
	/* 0x270c: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2710:
	/* 0x2710: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2717:
	/* 0x2717: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_271b:
	/* 0x271b: jmp    2721 <generic_uprobe_process_event+0x2721> */
	goto x86_l_2721;
x86_l_271d:
	/* 0x271d: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2721:
	/* 0x2721: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2725:
	/* 0x2725: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2729:
	/* 0x2729: movzx  r12d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_272e:
	/* 0x272e: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_2732:
	/* 0x2732: ja     2ad6 <generic_uprobe_process_event+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10966ULL;
	}
x86_l_2738:
	/* 0x2738: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2742:
	/* 0x2742: bt     rcx,r12 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2746:
	/* 0x2746: jae    2ad6 <generic_uprobe_process_event+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10966ULL;
	}
x86_l_274c:
	/* 0x274c: mov    BYTE PTR [rbp+0x5],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2750:
	/* 0x2750: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2753:
	/* 0x2753: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_275b:
	/* 0x275b: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_275e:
	/* 0x275e: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2763:
	/* 0x2763: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2768:
	/* 0x2768: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_276c:
	/* 0x276c: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_276f:
	/* 0x276f: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2772:
	/* 0x2772: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2777:
	/* 0x2777: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2779:
	/* 0x2779: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_277c:
	/* 0x277c: js     2907 <generic_uprobe_process_event+0x2907> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10503ULL;
	}
x86_l_2782:
	/* 0x2782: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2786:
	/* 0x2786: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2789:
	/* 0x2789: jg     27a5 <generic_uprobe_process_event+0x27a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_27a5;
	}
x86_l_278b:
	/* 0x278b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_278d:
	/* 0x278d: je     27c2 <generic_uprobe_process_event+0x27c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10178ULL;
	}
x86_l_278f:
	/* 0x278f: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2792:
	/* 0x2792: je     27c2 <generic_uprobe_process_event+0x27c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10178ULL;
	}
x86_l_2794:
	/* 0x2794: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2797:
	/* 0x2797: jne    27e4 <generic_uprobe_process_event+0x27e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10212ULL;
	}
x86_l_2799:
	/* 0x2799: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_279f:
	/* 0x279f: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_27a3:
	/* 0x27a3: jmp    27e8 <generic_uprobe_process_event+0x27e8> */
	return 10216ULL;
x86_l_27a5:
	/* 0x27a5: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_27a8:
	/* 0x27a8: je     27d3 <generic_uprobe_process_event+0x27d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10195ULL;
	}
x86_l_27aa:
	/* 0x27aa: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_27ad:
	/* 0x27ad: je     27c2 <generic_uprobe_process_event+0x27c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10178ULL;
	}
	return 10159ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10159ULL: goto x86_l_27af;
	case 10164ULL: goto x86_l_27b4;
	case 10166ULL: goto x86_l_27b6;
	case 10172ULL: goto x86_l_27bc;
	case 10176ULL: goto x86_l_27c0;
	case 10178ULL: goto x86_l_27c2;
	case 10182ULL: goto x86_l_27c6;
	case 10189ULL: goto x86_l_27cd;
	case 10193ULL: goto x86_l_27d1;
	case 10195ULL: goto x86_l_27d3;
	case 10199ULL: goto x86_l_27d7;
	case 10206ULL: goto x86_l_27de;
	case 10210ULL: goto x86_l_27e2;
	case 10212ULL: goto x86_l_27e4;
	case 10216ULL: goto x86_l_27e8;
	case 10220ULL: goto x86_l_27ec;
	case 10224ULL: goto x86_l_27f0;
	case 10229ULL: goto x86_l_27f5;
	case 10233ULL: goto x86_l_27f9;
	case 10239ULL: goto x86_l_27ff;
	case 10249ULL: goto x86_l_2809;
	case 10253ULL: goto x86_l_280d;
	case 10259ULL: goto x86_l_2813;
	case 10263ULL: goto x86_l_2817;
	case 10266ULL: goto x86_l_281a;
	case 10274ULL: goto x86_l_2822;
	case 10277ULL: goto x86_l_2825;
	case 10282ULL: goto x86_l_282a;
	case 10287ULL: goto x86_l_282f;
	case 10291ULL: goto x86_l_2833;
	case 10294ULL: goto x86_l_2836;
	case 10297ULL: goto x86_l_2839;
	case 10302ULL: goto x86_l_283e;
	case 10304ULL: goto x86_l_2840;
	case 10307ULL: goto x86_l_2843;
	case 10313ULL: goto x86_l_2849;
	case 10317ULL: goto x86_l_284d;
	case 10320ULL: goto x86_l_2850;
	case 10322ULL: goto x86_l_2852;
	case 10324ULL: goto x86_l_2854;
	case 10326ULL: goto x86_l_2856;
	case 10329ULL: goto x86_l_2859;
	case 10331ULL: goto x86_l_285b;
	case 10334ULL: goto x86_l_285e;
	case 10336ULL: goto x86_l_2860;
	case 10342ULL: goto x86_l_2866;
	case 10346ULL: goto x86_l_286a;
	case 10348ULL: goto x86_l_286c;
	case 10351ULL: goto x86_l_286f;
	case 10353ULL: goto x86_l_2871;
	case 10356ULL: goto x86_l_2874;
	case 10358ULL: goto x86_l_2876;
	case 10363ULL: goto x86_l_287b;
	case 10365ULL: goto x86_l_287d;
	case 10371ULL: goto x86_l_2883;
	case 10375ULL: goto x86_l_2887;
	case 10377ULL: goto x86_l_2889;
	case 10381ULL: goto x86_l_288d;
	case 10388ULL: goto x86_l_2894;
	case 10392ULL: goto x86_l_2898;
	case 10394ULL: goto x86_l_289a;
	case 10398ULL: goto x86_l_289e;
	case 10405ULL: goto x86_l_28a5;
	case 10409ULL: goto x86_l_28a9;
	case 10411ULL: goto x86_l_28ab;
	case 10415ULL: goto x86_l_28af;
	case 10419ULL: goto x86_l_28b3;
	case 10423ULL: goto x86_l_28b7;
	case 10428ULL: goto x86_l_28bc;
	case 10432ULL: goto x86_l_28c0;
	case 10438ULL: goto x86_l_28c6;
	case 10448ULL: goto x86_l_28d0;
	case 10452ULL: goto x86_l_28d4;
	case 10458ULL: goto x86_l_28da;
	case 10462ULL: goto x86_l_28de;
	case 10465ULL: goto x86_l_28e1;
	case 10473ULL: goto x86_l_28e9;
	case 10476ULL: goto x86_l_28ec;
	case 10481ULL: goto x86_l_28f1;
	case 10486ULL: goto x86_l_28f6;
	case 10490ULL: goto x86_l_28fa;
	case 10493ULL: goto x86_l_28fd;
	case 10496ULL: goto x86_l_2900;
	case 10501ULL: goto x86_l_2905;
	case 10503ULL: goto x86_l_2907;
	case 10506ULL: goto x86_l_290a;
	case 10514ULL: goto x86_l_2912;
	case 10518ULL: goto x86_l_2916;
	case 10523ULL: goto x86_l_291b;
	case 10528ULL: goto x86_l_2920;
	case 10535ULL: goto x86_l_2927;
	case 10540ULL: goto x86_l_292c;
	case 10544ULL: goto x86_l_2930;
	case 10549ULL: goto x86_l_2935;
	case 10554ULL: goto x86_l_293a;
	case 10557ULL: goto x86_l_293d;
	case 10562ULL: goto x86_l_2942;
	case 10564ULL: goto x86_l_2944;
	case 10568ULL: goto x86_l_2948;
	case 10572ULL: goto x86_l_294c;
	case 10577ULL: goto x86_l_2951;
	case 10582ULL: goto x86_l_2956;
	case 10587ULL: goto x86_l_295b;
	case 10590ULL: goto x86_l_295e;
	case 10592ULL: goto x86_l_2960;
	case 10596ULL: goto x86_l_2964;
	case 10598ULL: goto x86_l_2966;
	case 10602ULL: goto x86_l_296a;
	case 10605ULL: goto x86_l_296d;
	case 10611ULL: goto x86_l_2973;
	case 10616ULL: goto x86_l_2978;
	case 10625ULL: goto x86_l_2981;
	case 10629ULL: goto x86_l_2985;
	case 10634ULL: goto x86_l_298a;
	case 10638ULL: goto x86_l_298e;
	case 10643ULL: goto x86_l_2993;
	case 10648ULL: goto x86_l_2998;
	case 10653ULL: goto x86_l_299d;
	case 10655ULL: goto x86_l_299f;
	case 10659ULL: goto x86_l_29a3;
	case 10663ULL: goto x86_l_29a7;
	case 10667ULL: goto x86_l_29ab;
	case 10672ULL: goto x86_l_29b0;
	case 10677ULL: goto x86_l_29b5;
	case 10679ULL: goto x86_l_29b7;
	case 10684ULL: goto x86_l_29bc;
	case 10693ULL: goto x86_l_29c5;
	case 10697ULL: goto x86_l_29c9;
	case 10702ULL: goto x86_l_29ce;
	case 10706ULL: goto x86_l_29d2;
	case 10711ULL: goto x86_l_29d7;
	case 10716ULL: goto x86_l_29dc;
	case 10721ULL: goto x86_l_29e1;
	case 10723ULL: goto x86_l_29e3;
	case 10727ULL: goto x86_l_29e7;
	case 10731ULL: goto x86_l_29eb;
	case 10735ULL: goto x86_l_29ef;
	case 10740ULL: goto x86_l_29f4;
	case 10745ULL: goto x86_l_29f9;
	case 10750ULL: goto x86_l_29fe;
	case 10752ULL: goto x86_l_2a00;
	case 10754ULL: goto x86_l_2a02;
	case 10759ULL: goto x86_l_2a07;
	case 10766ULL: goto x86_l_2a0e;
	case 10771ULL: goto x86_l_2a13;
	case 10775ULL: goto x86_l_2a17;
	case 10779ULL: goto x86_l_2a1b;
	case 10785ULL: goto x86_l_2a21;
	case 10791ULL: goto x86_l_2a27;
	case 10798ULL: goto x86_l_2a2e;
	case 10803ULL: goto x86_l_2a33;
	case 10808ULL: goto x86_l_2a38;
	case 10813ULL: goto x86_l_2a3d;
	case 10819ULL: goto x86_l_2a43;
	case 10824ULL: goto x86_l_2a48;
	case 10827ULL: goto x86_l_2a4b;
	case 10829ULL: goto x86_l_2a4d;
	case 10834ULL: goto x86_l_2a52;
	case 10837ULL: goto x86_l_2a55;
	case 10839ULL: goto x86_l_2a57;
	case 10843ULL: goto x86_l_2a5b;
	case 10851ULL: goto x86_l_2a63;
	case 10856ULL: goto x86_l_2a68;
	case 10861ULL: goto x86_l_2a6d;
	case 10866ULL: goto x86_l_2a72;
	case 10870ULL: goto x86_l_2a76;
	case 10875ULL: goto x86_l_2a7b;
	case 10877ULL: goto x86_l_2a7d;
	case 10882ULL: goto x86_l_2a82;
	case 10890ULL: goto x86_l_2a8a;
	case 10894ULL: goto x86_l_2a8e;
	case 10899ULL: goto x86_l_2a93;
	case 10903ULL: goto x86_l_2a97;
	case 10908ULL: goto x86_l_2a9c;
	case 10913ULL: goto x86_l_2aa1;
	case 10915ULL: goto x86_l_2aa3;
	case 10919ULL: goto x86_l_2aa7;
	case 10923ULL: goto x86_l_2aab;
	case 10927ULL: goto x86_l_2aaf;
	case 10932ULL: goto x86_l_2ab4;
	case 10935ULL: goto x86_l_2ab7;
	case 10940ULL: goto x86_l_2abc;
	case 10942ULL: goto x86_l_2abe;
	case 10948ULL: goto x86_l_2ac4;
	case 10956ULL: goto x86_l_2acc;
	case 10961ULL: goto x86_l_2ad1;
	case 10966ULL: goto x86_l_2ad6;
	case 10974ULL: goto x86_l_2ade;
	case 10979ULL: goto x86_l_2ae3;
	case 10984ULL: goto x86_l_2ae8;
	case 10987ULL: goto x86_l_2aeb;
	case 10992ULL: goto x86_l_2af0;
	case 10997ULL: goto x86_l_2af5;
	case 11002ULL: goto x86_l_2afa;
	case 11004ULL: goto x86_l_2afc;
	case 11009ULL: goto x86_l_2b01;
	case 11013ULL: goto x86_l_2b05;
	case 11018ULL: goto x86_l_2b0a;
	case 11023ULL: goto x86_l_2b0f;
	case 11029ULL: goto x86_l_2b15;
	case 11033ULL: goto x86_l_2b19;
	case 11038ULL: goto x86_l_2b1e;
	case 11043ULL: goto x86_l_2b23;
	case 11048ULL: goto x86_l_2b28;
	case 11051ULL: goto x86_l_2b2b;
	case 11053ULL: goto x86_l_2b2d;
	case 11057ULL: goto x86_l_2b31;
	case 11062ULL: goto x86_l_2b36;
	case 11067ULL: goto x86_l_2b3b;
	case 11072ULL: goto x86_l_2b40;
	case 11077ULL: goto x86_l_2b45;
	case 11082ULL: goto x86_l_2b4a;
	case 11087ULL: goto x86_l_2b4f;
	case 11089ULL: goto x86_l_2b51;
	case 11094ULL: goto x86_l_2b56;
	case 11100ULL: goto x86_l_2b5c;
	case 11105ULL: goto x86_l_2b61;
	case 11110ULL: goto x86_l_2b66;
	case 11115ULL: goto x86_l_2b6b;
	case 11120ULL: goto x86_l_2b70;
	case 11122ULL: goto x86_l_2b72;
	case 11127ULL: goto x86_l_2b77;
	case 11133ULL: goto x86_l_2b7d;
	case 11137ULL: goto x86_l_2b81;
	case 11140ULL: goto x86_l_2b84;
	case 11145ULL: goto x86_l_2b89;
	case 11150ULL: goto x86_l_2b8e;
	case 11155ULL: goto x86_l_2b93;
	case 11158ULL: goto x86_l_2b96;
	case 11160ULL: goto x86_l_2b98;
	case 11164ULL: goto x86_l_2b9c;
	case 11170ULL: goto x86_l_2ba2;
	case 11175ULL: goto x86_l_2ba7;
	case 11180ULL: goto x86_l_2bac;
	case 11185ULL: goto x86_l_2bb1;
	case 11190ULL: goto x86_l_2bb6;
	case 11193ULL: goto x86_l_2bb9;
	case 11195ULL: goto x86_l_2bbb;
	case 11199ULL: goto x86_l_2bbf;
	case 11204ULL: goto x86_l_2bc4;
	case 11209ULL: goto x86_l_2bc9;
	case 11214ULL: goto x86_l_2bce;
	case 11219ULL: goto x86_l_2bd3;
	case 11222ULL: goto x86_l_2bd6;
	case 11224ULL: goto x86_l_2bd8;
	case 11229ULL: goto x86_l_2bdd;
	case 11234ULL: goto x86_l_2be2;
	case 11238ULL: goto x86_l_2be6;
	case 11241ULL: goto x86_l_2be9;
	case 11246ULL: goto x86_l_2bee;
	case 11248ULL: goto x86_l_2bf0;
	case 11250ULL: goto x86_l_2bf2;
	case 11253ULL: goto x86_l_2bf5;
	case 11256ULL: goto x86_l_2bf8;
	case 11261ULL: goto x86_l_2bfd;
	case 11263ULL: goto x86_l_2bff;
	case 11266ULL: goto x86_l_2c02;
	case 11270ULL: goto x86_l_2c06;
	case 11272ULL: goto x86_l_2c08;
	case 11276ULL: goto x86_l_2c0c;
	case 11278ULL: goto x86_l_2c0e;
	case 11281ULL: goto x86_l_2c11;
	case 11283ULL: goto x86_l_2c13;
	case 11287ULL: goto x86_l_2c17;
	case 11290ULL: goto x86_l_2c1a;
	case 11295ULL: goto x86_l_2c1f;
	case 11301ULL: goto x86_l_2c25;
	case 11307ULL: goto x86_l_2c2b;
	case 11313ULL: goto x86_l_2c31;
	case 11316ULL: goto x86_l_2c34;
	case 11318ULL: goto x86_l_2c36;
	case 11323ULL: goto x86_l_2c3b;
	case 11325ULL: goto x86_l_2c3d;
	case 11328ULL: goto x86_l_2c40;
	case 11332ULL: goto x86_l_2c44;
	case 11335ULL: goto x86_l_2c47;
	case 11338ULL: goto x86_l_2c4a;
	case 11341ULL: goto x86_l_2c4d;
	case 11346ULL: goto x86_l_2c52;
	case 11348ULL: goto x86_l_2c54;
	case 11353ULL: goto x86_l_2c59;
	case 11356ULL: goto x86_l_2c5c;
	case 11361ULL: goto x86_l_2c61;
	case 11367ULL: goto x86_l_2c67;
	case 11372ULL: goto x86_l_2c6c;
	case 11377ULL: goto x86_l_2c71;
	case 11382ULL: goto x86_l_2c76;
	case 11387ULL: goto x86_l_2c7b;
	case 11389ULL: goto x86_l_2c7d;
	case 11394ULL: goto x86_l_2c82;
	case 11397ULL: goto x86_l_2c85;
	case 11402ULL: goto x86_l_2c8a;
	case 11407ULL: goto x86_l_2c8f;
	case 11412ULL: goto x86_l_2c94;
	case 11414ULL: goto x86_l_2c96;
	case 11419ULL: goto x86_l_2c9b;
	case 11423ULL: goto x86_l_2c9f;
	case 11428ULL: goto x86_l_2ca4;
	case 11433ULL: goto x86_l_2ca9;
	case 11439ULL: goto x86_l_2caf;
	case 11443ULL: goto x86_l_2cb3;
	case 11448ULL: goto x86_l_2cb8;
	case 11453ULL: goto x86_l_2cbd;
	case 11458ULL: goto x86_l_2cc2;
	case 11461ULL: goto x86_l_2cc5;
	case 11463ULL: goto x86_l_2cc7;
	case 11467ULL: goto x86_l_2ccb;
	case 11472ULL: goto x86_l_2cd0;
	case 11477ULL: goto x86_l_2cd5;
	case 11482ULL: goto x86_l_2cda;
	case 11487ULL: goto x86_l_2cdf;
	case 11492ULL: goto x86_l_2ce4;
	case 11497ULL: goto x86_l_2ce9;
	case 11499ULL: goto x86_l_2ceb;
	case 11504ULL: goto x86_l_2cf0;
	case 11510ULL: goto x86_l_2cf6;
	case 11515ULL: goto x86_l_2cfb;
	case 11520ULL: goto x86_l_2d00;
	case 11525ULL: goto x86_l_2d05;
	case 11530ULL: goto x86_l_2d0a;
	case 11532ULL: goto x86_l_2d0c;
	case 11537ULL: goto x86_l_2d11;
	case 11543ULL: goto x86_l_2d17;
	case 11547ULL: goto x86_l_2d1b;
	case 11550ULL: goto x86_l_2d1e;
	case 11555ULL: goto x86_l_2d23;
	case 11560ULL: goto x86_l_2d28;
	case 11565ULL: goto x86_l_2d2d;
	case 11568ULL: goto x86_l_2d30;
	case 11570ULL: goto x86_l_2d32;
	case 11574ULL: goto x86_l_2d36;
	case 11580ULL: goto x86_l_2d3c;
	case 11585ULL: goto x86_l_2d41;
	case 11590ULL: goto x86_l_2d46;
	case 11595ULL: goto x86_l_2d4b;
	case 11600ULL: goto x86_l_2d50;
	case 11603ULL: goto x86_l_2d53;
	case 11605ULL: goto x86_l_2d55;
	case 11609ULL: goto x86_l_2d59;
	case 11614ULL: goto x86_l_2d5e;
	case 11619ULL: goto x86_l_2d63;
	case 11624ULL: goto x86_l_2d68;
	case 11629ULL: goto x86_l_2d6d;
	case 11632ULL: goto x86_l_2d70;
	case 11634ULL: goto x86_l_2d72;
	case 11639ULL: goto x86_l_2d77;
	case 11644ULL: goto x86_l_2d7c;
	case 11648ULL: goto x86_l_2d80;
	case 11651ULL: goto x86_l_2d83;
	case 11656ULL: goto x86_l_2d88;
	case 11658ULL: goto x86_l_2d8a;
	case 11660ULL: goto x86_l_2d8c;
	case 11663ULL: goto x86_l_2d8f;
	case 11666ULL: goto x86_l_2d92;
	case 11671ULL: goto x86_l_2d97;
	case 11673ULL: goto x86_l_2d99;
	case 11676ULL: goto x86_l_2d9c;
	case 11680ULL: goto x86_l_2da0;
	case 11682ULL: goto x86_l_2da2;
	case 11686ULL: goto x86_l_2da6;
	case 11688ULL: goto x86_l_2da8;
	case 11691ULL: goto x86_l_2dab;
	case 11693ULL: goto x86_l_2dad;
	case 11697ULL: goto x86_l_2db1;
	case 11700ULL: goto x86_l_2db4;
	case 11705ULL: goto x86_l_2db9;
	case 11711ULL: goto x86_l_2dbf;
	case 11717ULL: goto x86_l_2dc5;
	case 11723ULL: goto x86_l_2dcb;
	case 11726ULL: goto x86_l_2dce;
	case 11728ULL: goto x86_l_2dd0;
	case 11733ULL: goto x86_l_2dd5;
	case 11735ULL: goto x86_l_2dd7;
	case 11738ULL: goto x86_l_2dda;
	case 11742ULL: goto x86_l_2dde;
	case 11745ULL: goto x86_l_2de1;
	case 11748ULL: goto x86_l_2de4;
	case 11751ULL: goto x86_l_2de7;
	case 11756ULL: goto x86_l_2dec;
	case 11758ULL: goto x86_l_2dee;
	case 11763ULL: goto x86_l_2df3;
	case 11766ULL: goto x86_l_2df6;
	case 11771ULL: goto x86_l_2dfb;
	case 11777ULL: goto x86_l_2e01;
	default: return 0xffffffffffffffffULL;
	}
x86_l_27af:
	/* 0x27af: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_27b4:
	/* 0x27b4: jne    27e4 <generic_uprobe_process_event+0x27e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_27e4;
	}
x86_l_27b6:
	/* 0x27b6: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_27bc:
	/* 0x27bc: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_27c0:
	/* 0x27c0: jmp    27e8 <generic_uprobe_process_event+0x27e8> */
	goto x86_l_27e8;
x86_l_27c2:
	/* 0x27c2: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_27c6:
	/* 0x27c6: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_27cd:
	/* 0x27cd: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_27d1:
	/* 0x27d1: jmp    27e8 <generic_uprobe_process_event+0x27e8> */
	goto x86_l_27e8;
x86_l_27d3:
	/* 0x27d3: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_27d7:
	/* 0x27d7: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_27de:
	/* 0x27de: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_27e2:
	/* 0x27e2: jmp    27e8 <generic_uprobe_process_event+0x27e8> */
	goto x86_l_27e8;
x86_l_27e4:
	/* 0x27e4: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_27e8:
	/* 0x27e8: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_27ec:
	/* 0x27ec: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27f0:
	/* 0x27f0: movzx  r12d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_27f5:
	/* 0x27f5: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_27f9:
	/* 0x27f9: ja     2ad6 <generic_uprobe_process_event+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2ad6;
	}
x86_l_27ff:
	/* 0x27ff: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2809:
	/* 0x2809: bt     rcx,r12 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_280d:
	/* 0x280d: jae    2ad6 <generic_uprobe_process_event+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2ad6;
	}
x86_l_2813:
	/* 0x2813: mov    BYTE PTR [rbp+0x5],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2817:
	/* 0x2817: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_281a:
	/* 0x281a: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2822:
	/* 0x2822: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2825:
	/* 0x2825: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_282a:
	/* 0x282a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_282f:
	/* 0x282f: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2833:
	/* 0x2833: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2836:
	/* 0x2836: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2839:
	/* 0x2839: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_283e:
	/* 0x283e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2840:
	/* 0x2840: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2843:
	/* 0x2843: js     2907 <generic_uprobe_process_event+0x2907> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2907;
	}
x86_l_2849:
	/* 0x2849: movzx  eax,BYTE PTR [rbp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_284d:
	/* 0x284d: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2850:
	/* 0x2850: jg     286c <generic_uprobe_process_event+0x286c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_286c;
	}
x86_l_2852:
	/* 0x2852: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2854:
	/* 0x2854: je     2889 <generic_uprobe_process_event+0x2889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2889;
	}
x86_l_2856:
	/* 0x2856: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2859:
	/* 0x2859: je     2889 <generic_uprobe_process_event+0x2889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2889;
	}
x86_l_285b:
	/* 0x285b: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_285e:
	/* 0x285e: jne    28ab <generic_uprobe_process_event+0x28ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28ab;
	}
x86_l_2860:
	/* 0x2860: mov    WORD PTR [rbp+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2866:
	/* 0x2866: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_286a:
	/* 0x286a: jmp    28af <generic_uprobe_process_event+0x28af> */
	goto x86_l_28af;
x86_l_286c:
	/* 0x286c: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_286f:
	/* 0x286f: je     289a <generic_uprobe_process_event+0x289a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_289a;
	}
x86_l_2871:
	/* 0x2871: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2874:
	/* 0x2874: je     2889 <generic_uprobe_process_event+0x2889> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2889;
	}
x86_l_2876:
	/* 0x2876: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_287b:
	/* 0x287b: jne    28ab <generic_uprobe_process_event+0x28ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28ab;
	}
x86_l_287d:
	/* 0x287d: mov    WORD PTR [rbp+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2883:
	/* 0x2883: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2887:
	/* 0x2887: jmp    28af <generic_uprobe_process_event+0x28af> */
	goto x86_l_28af;
x86_l_2889:
	/* 0x2889: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_288d:
	/* 0x288d: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2894:
	/* 0x2894: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2898:
	/* 0x2898: jmp    28af <generic_uprobe_process_event+0x28af> */
	goto x86_l_28af;
x86_l_289a:
	/* 0x289a: movzx  eax,BYTE PTR [rbp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_289e:
	/* 0x289e: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_28a5:
	/* 0x28a5: mov    WORD PTR [rbp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_28a9:
	/* 0x28a9: jmp    28af <generic_uprobe_process_event+0x28af> */
	goto x86_l_28af;
x86_l_28ab:
	/* 0x28ab: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_28af:
	/* 0x28af: add    ax,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_28b3:
	/* 0x28b3: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28b7:
	/* 0x28b7: movzx  r12d,BYTE PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_28bc:
	/* 0x28bc: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_28c0:
	/* 0x28c0: ja     2ad6 <generic_uprobe_process_event+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2ad6;
	}
x86_l_28c6:
	/* 0x28c6: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_28d0:
	/* 0x28d0: bt     rcx,r12 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_28d4:
	/* 0x28d4: jae    2ad6 <generic_uprobe_process_event+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2ad6;
	}
x86_l_28da:
	/* 0x28da: mov    BYTE PTR [rbp+0x5],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_28de:
	/* 0x28de: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_28e1:
	/* 0x28e1: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_28e9:
	/* 0x28e9: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28ec:
	/* 0x28ec: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_28f1:
	/* 0x28f1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28f6:
	/* 0x28f6: movzx  edx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_28fa:
	/* 0x28fa: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28fd:
	/* 0x28fd: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2900:
	/* 0x2900: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2905:
	/* 0x2905: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2907:
	/* 0x2907: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_290a:
	/* 0x290a: mov    BYTE PTR [rsp+0xb0],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2912:
	/* 0x2912: movzx  eax,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2916:
	/* 0x2916: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_291b:
	/* 0x291b: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2920:
	/* 0x2920: mov    WORD PTR [r15+0x26],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757258ULL);
x86_l_2927:
	/* 0x2927: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_292c:
	/* 0x292c: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2930:
	/* 0x2930: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2935:
	/* 0x2935: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_293a:
	/* 0x293a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_293d:
	/* 0x293d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2942:
	/* 0x2942: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2944:
	/* 0x2944: lea    rdi,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2948:
	/* 0x2948: add    rbp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_294c:
	/* 0x294c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2951:
	/* 0x2951: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2956:
	/* 0x2956: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_295b:
	/* 0x295b: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_295e:
	/* 0x295e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2960:
	/* 0x2960: cmp    r12b,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 17ULL);
x86_l_2964:
	/* 0x2964: je     29b7 <generic_uprobe_process_event+0x29b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29b7;
	}
x86_l_2966:
	/* 0x2966: movzx  eax,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_296a:
	/* 0x296a: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_296d:
	/* 0x296d: jne    2a02 <generic_uprobe_process_event+0x2a02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a02;
	}
x86_l_2973:
	/* 0x2973: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2978:
	/* 0x2978: movzx  r12d,WORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 184ULL);
x86_l_2981:
	/* 0x2981: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2985:
	/* 0x2985: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_298a:
	/* 0x298a: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_298e:
	/* 0x298e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2993:
	/* 0x2993: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2998:
	/* 0x2998: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_299d:
	/* 0x299d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_299f:
	/* 0x299f: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_29a3:
	/* 0x29a3: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_29a7:
	/* 0x29a7: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_29ab:
	/* 0x29ab: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_29b0:
	/* 0x29b0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29b5:
	/* 0x29b5: jmp    29f9 <generic_uprobe_process_event+0x29f9> */
	goto x86_l_29f9;
x86_l_29b7:
	/* 0x29b7: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29bc:
	/* 0x29bc: movzx  r12d,WORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 184ULL);
x86_l_29c5:
	/* 0x29c5: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_29c9:
	/* 0x29c9: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29ce:
	/* 0x29ce: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29d2:
	/* 0x29d2: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_29d7:
	/* 0x29d7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29dc:
	/* 0x29dc: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_29e1:
	/* 0x29e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29e3:
	/* 0x29e3: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_29e7:
	/* 0x29e7: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_29eb:
	/* 0x29eb: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_29ef:
	/* 0x29ef: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_29f4:
	/* 0x29f4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29f9:
	/* 0x29f9: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_29fe:
	/* 0x29fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a00:
	/* 0x2a00: jmp    2a0e <generic_uprobe_process_event+0x2a0e> */
	goto x86_l_2a0e;
x86_l_2a02:
	/* 0x2a02: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a07:
	/* 0x2a07: mov    DWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2a0e:
	/* 0x2a0e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a13:
	/* 0x2a13: movzx  eax,WORD PTR [rdx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_2a17:
	/* 0x2a17: movzx  ecx,WORD PTR [rdx+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2a1b:
	/* 0x2a1b: movbe  WORD PTR [rdx+0x20],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_2a21:
	/* 0x2a21: movbe  WORD PTR [rdx+0x22],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2a27:
	/* 0x2a27: add    r13,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_2a2e:
	/* 0x2a2e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a33:
	/* 0x2a33: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a38:
	/* 0x2a38: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a3d:
	/* 0x2a3d: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2a43:
	/* 0x2a43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a48:
	/* 0x2a48: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2a4b:
	/* 0x2a4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a4d:
	/* 0x2a4d: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a52:
	/* 0x2a52: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2a55:
	/* 0x2a55: je     2abe <generic_uprobe_process_event+0x2abe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2abe;
	}
x86_l_2a57:
	/* 0x2a57: add    rcx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_2a5b:
	/* 0x2a5b: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2a63:
	/* 0x2a63: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2a68:
	/* 0x2a68: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a6d:
	/* 0x2a6d: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a72:
	/* 0x2a72: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_2a76:
	/* 0x2a76: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a7b:
	/* 0x2a7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a7d:
	/* 0x2a7d: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a82:
	/* 0x2a82: mov    r13,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2a8a:
	/* 0x2a8a: lea    rdx,[r12+r13*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 0ULL);
x86_l_2a8e:
	/* 0x2a8e: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a93:
	/* 0x2a93: lea    rdi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2a97:
	/* 0x2a97: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a9c:
	/* 0x2a9c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2aa1:
	/* 0x2aa1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aa3:
	/* 0x2aa3: add    rbp,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 60ULL);
x86_l_2aa7:
	/* 0x2aa7: lea    rdx,[r12+r13*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 0ULL);
x86_l_2aab:
	/* 0x2aab: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2aaf:
	/* 0x2aaf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ab4:
	/* 0x2ab4: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_2ab7:
	/* 0x2ab7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2abc:
	/* 0x2abc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2abe:
	/* 0x2abe: mov    r13d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 64ULL);
x86_l_2ac4:
	/* 0x2ac4: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2acc:
	/* 0x2acc: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2ad1:
	/* 0x2ad1: jmp    fb9 <generic_uprobe_process_event+0xfb9> */
	return 4025ULL;
x86_l_2ad6:
	/* 0x2ad6: mov    WORD PTR [rsp+0xb8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2ade:
	/* 0x2ade: jmp    290a <generic_uprobe_process_event+0x290a> */
	goto x86_l_290a;
x86_l_2ae3:
	/* 0x2ae3: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ae8:
	/* 0x2ae8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2aeb:
	/* 0x2aeb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2af0:
	/* 0x2af0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2af5:
	/* 0x2af5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2afa:
	/* 0x2afa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2afc:
	/* 0x2afc: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b01:
	/* 0x2b01: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2b05:
	/* 0x2b05: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b0a:
	/* 0x2b0a: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b0f:
	/* 0x2b0f: je     d9f <generic_uprobe_process_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3487ULL;
	}
x86_l_2b15:
	/* 0x2b15: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2b19:
	/* 0x2b19: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b1e:
	/* 0x2b1e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b23:
	/* 0x2b23: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b28:
	/* 0x2b28: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2b2b:
	/* 0x2b2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b2d:
	/* 0x2b2d: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b31:
	/* 0x2b31: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b36:
	/* 0x2b36: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b3b:
	/* 0x2b3b: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2b40:
	/* 0x2b40: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b45:
	/* 0x2b45: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2b4a:
	/* 0x2b4a: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b4f:
	/* 0x2b4f: jne    2b5c <generic_uprobe_process_event+0x2b5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b5c;
	}
x86_l_2b51:
	/* 0x2b51: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2b56:
	/* 0x2b56: je     d9f <generic_uprobe_process_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3487ULL;
	}
x86_l_2b5c:
	/* 0x2b5c: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2b61:
	/* 0x2b61: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b66:
	/* 0x2b66: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b6b:
	/* 0x2b6b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b70:
	/* 0x2b70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b72:
	/* 0x2b72: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_2b77:
	/* 0x2b77: je     2c7d <generic_uprobe_process_event+0x2c7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c7d;
	}
x86_l_2b7d:
	/* 0x2b7d: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b81:
	/* 0x2b81: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b84:
	/* 0x2b84: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b89:
	/* 0x2b89: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b8e:
	/* 0x2b8e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b93:
	/* 0x2b93: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2b96:
	/* 0x2b96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b98:
	/* 0x2b98: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b9c:
	/* 0x2b9c: je     2c7d <generic_uprobe_process_event+0x2c7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c7d;
	}
x86_l_2ba2:
	/* 0x2ba2: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2ba7:
	/* 0x2ba7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2bac:
	/* 0x2bac: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bb1:
	/* 0x2bb1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bb6:
	/* 0x2bb6: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2bb9:
	/* 0x2bb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bbb:
	/* 0x2bbb: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2bbf:
	/* 0x2bbf: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2bc4:
	/* 0x2bc4: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2bc9:
	/* 0x2bc9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bce:
	/* 0x2bce: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2bd3:
	/* 0x2bd3: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2bd6:
	/* 0x2bd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bd8:
	/* 0x2bd8: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2bdd:
	/* 0x2bdd: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2be2:
	/* 0x2be2: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2be6:
	/* 0x2be6: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2be9:
	/* 0x2be9: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2bee:
	/* 0x2bee: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bf0:
	/* 0x2bf0: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_2bf2:
	/* 0x2bf2: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2bf5:
	/* 0x2bf5: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2bf8:
	/* 0x2bf8: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2bfd:
	/* 0x2bfd: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bff:
	/* 0x2bff: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2c02:
	/* 0x2c02: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_2c06:
	/* 0x2c06: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_2c08:
	/* 0x2c08: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_2c0c:
	/* 0x2c0c: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2c0e:
	/* 0x2c0e: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_2c11:
	/* 0x2c11: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c13:
	/* 0x2c13: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2c17:
	/* 0x2c17: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2c1a:
	/* 0x2c1a: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c1f:
	/* 0x2c1f: jb     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3492ULL;
	}
x86_l_2c25:
	/* 0x2c25: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_2c2b:
	/* 0x2c2b: ja     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3492ULL;
	}
x86_l_2c31:
	/* 0x2c31: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2c34:
	/* 0x2c34: jbe    2c3b <generic_uprobe_process_event+0x2c3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2c3b;
	}
x86_l_2c36:
	/* 0x2c36: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2c3b:
	/* 0x2c3b: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c3d:
	/* 0x2c3d: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2c40:
	/* 0x2c40: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_2c44:
	/* 0x2c44: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2c47:
	/* 0x2c47: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c4a:
	/* 0x2c4a: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c4d:
	/* 0x2c4d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c52:
	/* 0x2c52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c54:
	/* 0x2c54: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2c59:
	/* 0x2c59: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2c5c:
	/* 0x2c5c: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c61:
	/* 0x2c61: jbe    da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3492ULL;
	}
x86_l_2c67:
	/* 0x2c67: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2c6c:
	/* 0x2c6c: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c71:
	/* 0x2c71: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2c76:
	/* 0x2c76: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c7b:
	/* 0x2c7b: jmp    2cdf <generic_uprobe_process_event+0x2cdf> */
	goto x86_l_2cdf;
x86_l_2c7d:
	/* 0x2c7d: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c82:
	/* 0x2c82: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2c85:
	/* 0x2c85: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c8a:
	/* 0x2c8a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c8f:
	/* 0x2c8f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c94:
	/* 0x2c94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c96:
	/* 0x2c96: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c9b:
	/* 0x2c9b: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2c9f:
	/* 0x2c9f: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ca4:
	/* 0x2ca4: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ca9:
	/* 0x2ca9: je     d9f <generic_uprobe_process_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3487ULL;
	}
x86_l_2caf:
	/* 0x2caf: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2cb3:
	/* 0x2cb3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2cb8:
	/* 0x2cb8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cbd:
	/* 0x2cbd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cc2:
	/* 0x2cc2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2cc5:
	/* 0x2cc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cc7:
	/* 0x2cc7: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ccb:
	/* 0x2ccb: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2cd0:
	/* 0x2cd0: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2cd5:
	/* 0x2cd5: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2cda:
	/* 0x2cda: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2cdf:
	/* 0x2cdf: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2ce4:
	/* 0x2ce4: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ce9:
	/* 0x2ce9: jne    2cf6 <generic_uprobe_process_event+0x2cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cf6;
	}
x86_l_2ceb:
	/* 0x2ceb: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2cf0:
	/* 0x2cf0: je     d9f <generic_uprobe_process_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3487ULL;
	}
x86_l_2cf6:
	/* 0x2cf6: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2cfb:
	/* 0x2cfb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d00:
	/* 0x2d00: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d05:
	/* 0x2d05: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d0a:
	/* 0x2d0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d0c:
	/* 0x2d0c: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_2d11:
	/* 0x2d11: je     2e17 <generic_uprobe_process_event+0x2e17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11799ULL;
	}
x86_l_2d17:
	/* 0x2d17: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d1b:
	/* 0x2d1b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2d1e:
	/* 0x2d1e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d23:
	/* 0x2d23: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d28:
	/* 0x2d28: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d2d:
	/* 0x2d2d: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2d30:
	/* 0x2d30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d32:
	/* 0x2d32: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d36:
	/* 0x2d36: je     2e17 <generic_uprobe_process_event+0x2e17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11799ULL;
	}
x86_l_2d3c:
	/* 0x2d3c: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2d41:
	/* 0x2d41: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d46:
	/* 0x2d46: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d4b:
	/* 0x2d4b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d50:
	/* 0x2d50: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2d53:
	/* 0x2d53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d55:
	/* 0x2d55: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2d59:
	/* 0x2d59: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d5e:
	/* 0x2d5e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2d63:
	/* 0x2d63: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d68:
	/* 0x2d68: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2d6d:
	/* 0x2d6d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2d70:
	/* 0x2d70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d72:
	/* 0x2d72: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d77:
	/* 0x2d77: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2d7c:
	/* 0x2d7c: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2d80:
	/* 0x2d80: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2d83:
	/* 0x2d83: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2d88:
	/* 0x2d88: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d8a:
	/* 0x2d8a: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_2d8c:
	/* 0x2d8c: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d8f:
	/* 0x2d8f: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2d92:
	/* 0x2d92: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2d97:
	/* 0x2d97: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d99:
	/* 0x2d99: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2d9c:
	/* 0x2d9c: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_2da0:
	/* 0x2da0: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_2da2:
	/* 0x2da2: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_2da6:
	/* 0x2da6: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2da8:
	/* 0x2da8: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_2dab:
	/* 0x2dab: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2dad:
	/* 0x2dad: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2db1:
	/* 0x2db1: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2db4:
	/* 0x2db4: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2db9:
	/* 0x2db9: jb     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3492ULL;
	}
x86_l_2dbf:
	/* 0x2dbf: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_2dc5:
	/* 0x2dc5: ja     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3492ULL;
	}
x86_l_2dcb:
	/* 0x2dcb: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2dce:
	/* 0x2dce: jbe    2dd5 <generic_uprobe_process_event+0x2dd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2dd5;
	}
x86_l_2dd0:
	/* 0x2dd0: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2dd5:
	/* 0x2dd5: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2dd7:
	/* 0x2dd7: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2dda:
	/* 0x2dda: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_2dde:
	/* 0x2dde: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2de1:
	/* 0x2de1: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2de4:
	/* 0x2de4: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2de7:
	/* 0x2de7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2dec:
	/* 0x2dec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dee:
	/* 0x2dee: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2df3:
	/* 0x2df3: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2df6:
	/* 0x2df6: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dfb:
	/* 0x2dfb: jbe    da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3492ULL;
	}
x86_l_2e01:
	/* 0x2e01: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
	return 11782ULL;
}

static __noinline __u64 tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11782ULL: goto x86_l_2e06;
	case 11787ULL: goto x86_l_2e0b;
	case 11792ULL: goto x86_l_2e10;
	case 11797ULL: goto x86_l_2e15;
	case 11799ULL: goto x86_l_2e17;
	case 11804ULL: goto x86_l_2e1c;
	case 11807ULL: goto x86_l_2e1f;
	case 11812ULL: goto x86_l_2e24;
	case 11817ULL: goto x86_l_2e29;
	case 11822ULL: goto x86_l_2e2e;
	case 11824ULL: goto x86_l_2e30;
	case 11829ULL: goto x86_l_2e35;
	case 11833ULL: goto x86_l_2e39;
	case 11838ULL: goto x86_l_2e3e;
	case 11843ULL: goto x86_l_2e43;
	case 11849ULL: goto x86_l_2e49;
	case 11853ULL: goto x86_l_2e4d;
	case 11858ULL: goto x86_l_2e52;
	case 11863ULL: goto x86_l_2e57;
	case 11868ULL: goto x86_l_2e5c;
	case 11871ULL: goto x86_l_2e5f;
	case 11873ULL: goto x86_l_2e61;
	case 11877ULL: goto x86_l_2e65;
	case 11882ULL: goto x86_l_2e6a;
	case 11887ULL: goto x86_l_2e6f;
	case 11892ULL: goto x86_l_2e74;
	case 11897ULL: goto x86_l_2e79;
	case 11902ULL: goto x86_l_2e7e;
	case 11907ULL: goto x86_l_2e83;
	case 11909ULL: goto x86_l_2e85;
	case 11914ULL: goto x86_l_2e8a;
	case 11920ULL: goto x86_l_2e90;
	case 11925ULL: goto x86_l_2e95;
	case 11930ULL: goto x86_l_2e9a;
	case 11935ULL: goto x86_l_2e9f;
	case 11940ULL: goto x86_l_2ea4;
	case 11942ULL: goto x86_l_2ea6;
	case 11947ULL: goto x86_l_2eab;
	case 11953ULL: goto x86_l_2eb1;
	case 11957ULL: goto x86_l_2eb5;
	case 11960ULL: goto x86_l_2eb8;
	case 11965ULL: goto x86_l_2ebd;
	case 11970ULL: goto x86_l_2ec2;
	case 11975ULL: goto x86_l_2ec7;
	case 11978ULL: goto x86_l_2eca;
	case 11980ULL: goto x86_l_2ecc;
	case 11984ULL: goto x86_l_2ed0;
	case 11990ULL: goto x86_l_2ed6;
	case 11995ULL: goto x86_l_2edb;
	case 12000ULL: goto x86_l_2ee0;
	case 12005ULL: goto x86_l_2ee5;
	case 12010ULL: goto x86_l_2eea;
	case 12013ULL: goto x86_l_2eed;
	case 12015ULL: goto x86_l_2eef;
	case 12019ULL: goto x86_l_2ef3;
	case 12024ULL: goto x86_l_2ef8;
	case 12029ULL: goto x86_l_2efd;
	case 12034ULL: goto x86_l_2f02;
	case 12039ULL: goto x86_l_2f07;
	case 12042ULL: goto x86_l_2f0a;
	case 12044ULL: goto x86_l_2f0c;
	case 12049ULL: goto x86_l_2f11;
	case 12054ULL: goto x86_l_2f16;
	case 12058ULL: goto x86_l_2f1a;
	case 12061ULL: goto x86_l_2f1d;
	case 12066ULL: goto x86_l_2f22;
	case 12068ULL: goto x86_l_2f24;
	case 12070ULL: goto x86_l_2f26;
	case 12073ULL: goto x86_l_2f29;
	case 12076ULL: goto x86_l_2f2c;
	case 12081ULL: goto x86_l_2f31;
	case 12083ULL: goto x86_l_2f33;
	case 12086ULL: goto x86_l_2f36;
	case 12090ULL: goto x86_l_2f3a;
	case 12092ULL: goto x86_l_2f3c;
	case 12096ULL: goto x86_l_2f40;
	case 12098ULL: goto x86_l_2f42;
	case 12101ULL: goto x86_l_2f45;
	case 12103ULL: goto x86_l_2f47;
	case 12107ULL: goto x86_l_2f4b;
	case 12110ULL: goto x86_l_2f4e;
	case 12115ULL: goto x86_l_2f53;
	case 12121ULL: goto x86_l_2f59;
	case 12127ULL: goto x86_l_2f5f;
	case 12133ULL: goto x86_l_2f65;
	case 12136ULL: goto x86_l_2f68;
	case 12138ULL: goto x86_l_2f6a;
	case 12143ULL: goto x86_l_2f6f;
	case 12145ULL: goto x86_l_2f71;
	case 12148ULL: goto x86_l_2f74;
	case 12152ULL: goto x86_l_2f78;
	case 12155ULL: goto x86_l_2f7b;
	case 12158ULL: goto x86_l_2f7e;
	case 12161ULL: goto x86_l_2f81;
	case 12166ULL: goto x86_l_2f86;
	case 12168ULL: goto x86_l_2f88;
	case 12173ULL: goto x86_l_2f8d;
	case 12176ULL: goto x86_l_2f90;
	case 12181ULL: goto x86_l_2f95;
	case 12187ULL: goto x86_l_2f9b;
	case 12192ULL: goto x86_l_2fa0;
	case 12197ULL: goto x86_l_2fa5;
	case 12202ULL: goto x86_l_2faa;
	case 12207ULL: goto x86_l_2faf;
	case 12210ULL: goto x86_l_2fb2;
	case 12215ULL: goto x86_l_2fb7;
	case 12220ULL: goto x86_l_2fbc;
	case 12225ULL: goto x86_l_2fc1;
	case 12227ULL: goto x86_l_2fc3;
	case 12232ULL: goto x86_l_2fc8;
	case 12236ULL: goto x86_l_2fcc;
	case 12241ULL: goto x86_l_2fd1;
	case 12246ULL: goto x86_l_2fd6;
	case 12252ULL: goto x86_l_2fdc;
	case 12256ULL: goto x86_l_2fe0;
	case 12261ULL: goto x86_l_2fe5;
	case 12266ULL: goto x86_l_2fea;
	case 12271ULL: goto x86_l_2fef;
	case 12274ULL: goto x86_l_2ff2;
	case 12276ULL: goto x86_l_2ff4;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2e06:
	/* 0x2e06: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e0b:
	/* 0x2e0b: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2e10:
	/* 0x2e10: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2e15:
	/* 0x2e15: jmp    2e79 <generic_uprobe_process_event+0x2e79> */
	goto x86_l_2e79;
x86_l_2e17:
	/* 0x2e17: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e1c:
	/* 0x2e1c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2e1f:
	/* 0x2e1f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e24:
	/* 0x2e24: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e29:
	/* 0x2e29: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e2e:
	/* 0x2e2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e30:
	/* 0x2e30: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2e35:
	/* 0x2e35: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2e39:
	/* 0x2e39: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e3e:
	/* 0x2e3e: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e43:
	/* 0x2e43: je     d9f <generic_uprobe_process_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3487ULL;
	}
x86_l_2e49:
	/* 0x2e49: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2e4d:
	/* 0x2e4d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e52:
	/* 0x2e52: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e57:
	/* 0x2e57: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e5c:
	/* 0x2e5c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2e5f:
	/* 0x2e5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e61:
	/* 0x2e61: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e65:
	/* 0x2e65: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2e6a:
	/* 0x2e6a: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e6f:
	/* 0x2e6f: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2e74:
	/* 0x2e74: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e79:
	/* 0x2e79: cmp    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_2e7e:
	/* 0x2e7e: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e83:
	/* 0x2e83: jne    2e90 <generic_uprobe_process_event+0x2e90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e90;
	}
x86_l_2e85:
	/* 0x2e85: cmp    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 48ULL);
x86_l_2e8a:
	/* 0x2e8a: je     d9f <generic_uprobe_process_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3487ULL;
	}
x86_l_2e90:
	/* 0x2e90: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2e95:
	/* 0x2e95: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e9a:
	/* 0x2e9a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e9f:
	/* 0x2e9f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ea4:
	/* 0x2ea4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ea6:
	/* 0x2ea6: cmp    r13,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_2eab:
	/* 0x2eab: je     2faa <generic_uprobe_process_event+0x2faa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2faa;
	}
x86_l_2eb1:
	/* 0x2eb1: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2eb5:
	/* 0x2eb5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2eb8:
	/* 0x2eb8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ebd:
	/* 0x2ebd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ec2:
	/* 0x2ec2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ec7:
	/* 0x2ec7: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2eca:
	/* 0x2eca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ecc:
	/* 0x2ecc: cmp    QWORD PTR [rsp],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ed0:
	/* 0x2ed0: je     2faa <generic_uprobe_process_event+0x2faa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2faa;
	}
x86_l_2ed6:
	/* 0x2ed6: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2edb:
	/* 0x2edb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ee0:
	/* 0x2ee0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ee5:
	/* 0x2ee5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2eea:
	/* 0x2eea: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2eed:
	/* 0x2eed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eef:
	/* 0x2eef: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2ef3:
	/* 0x2ef3: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ef8:
	/* 0x2ef8: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2efd:
	/* 0x2efd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f02:
	/* 0x2f02: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2f07:
	/* 0x2f07: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2f0a:
	/* 0x2f0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f0c:
	/* 0x2f0c: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f11:
	/* 0x2f11: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2f16:
	/* 0x2f16: mov    ebp,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2f1a:
	/* 0x2f1a: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2f1d:
	/* 0x2f1d: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2f22:
	/* 0x2f22: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f24:
	/* 0x2f24: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_2f26:
	/* 0x2f26: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f29:
	/* 0x2f29: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2f2c:
	/* 0x2f2c: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2f31:
	/* 0x2f31: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f33:
	/* 0x2f33: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2f36:
	/* 0x2f36: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_2f3a:
	/* 0x2f3a: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_2f3c:
	/* 0x2f3c: cmovb  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_2f40:
	/* 0x2f40: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2f42:
	/* 0x2f42: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_2f45:
	/* 0x2f45: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f47:
	/* 0x2f47: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2f4b:
	/* 0x2f4b: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2f4e:
	/* 0x2f4e: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f53:
	/* 0x2f53: jb     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3492ULL;
	}
x86_l_2f59:
	/* 0x2f59: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_2f5f:
	/* 0x2f5f: ja     da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3492ULL;
	}
x86_l_2f65:
	/* 0x2f65: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2f68:
	/* 0x2f68: jbe    2f6f <generic_uprobe_process_event+0x2f6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2f6f;
	}
x86_l_2f6a:
	/* 0x2f6a: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2f6f:
	/* 0x2f6f: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f71:
	/* 0x2f71: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2f74:
	/* 0x2f74: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_2f78:
	/* 0x2f78: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2f7b:
	/* 0x2f7b: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f7e:
	/* 0x2f7e: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f81:
	/* 0x2f81: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f86:
	/* 0x2f86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f88:
	/* 0x2f88: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2f8d:
	/* 0x2f8d: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_2f90:
	/* 0x2f90: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f95:
	/* 0x2f95: jbe    da4 <generic_uprobe_process_event+0xda4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3492ULL;
	}
x86_l_2f9b:
	/* 0x2f9b: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2fa0:
	/* 0x2fa0: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2fa5:
	/* 0x2fa5: jmp    da4 <generic_uprobe_process_event+0xda4> */
	return 3492ULL;
x86_l_2faa:
	/* 0x2faa: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2faf:
	/* 0x2faf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2fb2:
	/* 0x2fb2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2fb7:
	/* 0x2fb7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2fbc:
	/* 0x2fbc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fc1:
	/* 0x2fc1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fc3:
	/* 0x2fc3: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2fc8:
	/* 0x2fc8: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2fcc:
	/* 0x2fcc: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fd1:
	/* 0x2fd1: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2fd6:
	/* 0x2fd6: je     d9f <generic_uprobe_process_event+0xd9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3487ULL;
	}
x86_l_2fdc:
	/* 0x2fdc: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2fe0:
	/* 0x2fe0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2fe5:
	/* 0x2fe5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2fea:
	/* 0x2fea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fef:
	/* 0x2fef: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2ff2:
	/* 0x2ff2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ff4:
	/* 0x2ff4: jmp    da4 <generic_uprobe_process_event+0xda4> */
	return 3492ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 11232U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1794ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1799ULL && __x86_pc <= 3622ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3627ULL && __x86_pc <= 5271ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5273ULL && __x86_pc <= 6958ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6960ULL && __x86_pc <= 8575ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8585ULL && __x86_pc <= 10157ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10159ULL && __x86_pc <= 11777ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 11782ULL && __x86_pc <= 12276ULL)
			__x86_pc = tetragon_bpf_generic_uprobe_generic_uprobe_process_event_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

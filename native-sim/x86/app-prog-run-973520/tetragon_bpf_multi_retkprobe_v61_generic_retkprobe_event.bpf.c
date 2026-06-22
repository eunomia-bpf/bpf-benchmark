extern char CONFIG_ITER_NUM;
extern char buffer_heap_map;
extern char config_map;
extern char execve_map;
extern char fdinstall_map;
extern char process_call_heap;
extern char retkprobe_calls;
extern char retprobe_map;
extern char socktrack_map;
extern char tg_ipv6_ext_heap;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 17ULL: goto x86_l_11;
	case 25ULL: goto x86_l_19;
	case 36ULL: goto x86_l_24;
	case 41ULL: goto x86_l_29;
	case 48ULL: goto x86_l_30;
	case 56ULL: goto x86_l_38;
	case 58ULL: goto x86_l_3a;
	case 60ULL: goto x86_l_3c;
	case 63ULL: goto x86_l_3f;
	case 69ULL: goto x86_l_45;
	case 72ULL: goto x86_l_48;
	case 75ULL: goto x86_l_4b;
	case 80ULL: goto x86_l_50;
	case 83ULL: goto x86_l_53;
	case 85ULL: goto x86_l_55;
	case 92ULL: goto x86_l_5c;
	case 98ULL: goto x86_l_62;
	case 103ULL: goto x86_l_67;
	case 110ULL: goto x86_l_6e;
	case 112ULL: goto x86_l_70;
	case 115ULL: goto x86_l_73;
	case 121ULL: goto x86_l_79;
	case 124ULL: goto x86_l_7c;
	case 126ULL: goto x86_l_7e;
	case 130ULL: goto x86_l_82;
	case 135ULL: goto x86_l_87;
	case 137ULL: goto x86_l_89;
	case 141ULL: goto x86_l_8d;
	case 143ULL: goto x86_l_8f;
	case 147ULL: goto x86_l_93;
	case 151ULL: goto x86_l_97;
	case 156ULL: goto x86_l_9c;
	case 158ULL: goto x86_l_9e;
	case 162ULL: goto x86_l_a2;
	case 166ULL: goto x86_l_a6;
	case 170ULL: goto x86_l_aa;
	case 175ULL: goto x86_l_af;
	case 180ULL: goto x86_l_b4;
	case 185ULL: goto x86_l_b9;
	case 192ULL: goto x86_l_c0;
	case 197ULL: goto x86_l_c5;
	case 199ULL: goto x86_l_c7;
	case 202ULL: goto x86_l_ca;
	case 208ULL: goto x86_l_d0;
	case 213ULL: goto x86_l_d5;
	case 216ULL: goto x86_l_d8;
	case 220ULL: goto x86_l_dc;
	case 228ULL: goto x86_l_e4;
	case 232ULL: goto x86_l_e8;
	case 240ULL: goto x86_l_f0;
	case 245ULL: goto x86_l_f5;
	case 252ULL: goto x86_l_fc;
	case 257ULL: goto x86_l_101;
	case 259ULL: goto x86_l_103;
	case 266ULL: goto x86_l_10a;
	case 270ULL: goto x86_l_10e;
	case 274ULL: goto x86_l_112;
	case 277ULL: goto x86_l_115;
	case 283ULL: goto x86_l_11b;
	case 287ULL: goto x86_l_11f;
	case 298ULL: goto x86_l_12a;
	case 306ULL: goto x86_l_132;
	case 317ULL: goto x86_l_13d;
	case 322ULL: goto x86_l_142;
	case 329ULL: goto x86_l_149;
	case 337ULL: goto x86_l_151;
	case 339ULL: goto x86_l_153;
	case 342ULL: goto x86_l_156;
	case 348ULL: goto x86_l_15c;
	case 354ULL: goto x86_l_162;
	case 360ULL: goto x86_l_168;
	case 371ULL: goto x86_l_173;
	case 376ULL: goto x86_l_178;
	case 378ULL: goto x86_l_17a;
	case 384ULL: goto x86_l_180;
	case 391ULL: goto x86_l_187;
	case 396ULL: goto x86_l_18c;
	case 405ULL: goto x86_l_195;
	case 409ULL: goto x86_l_199;
	case 413ULL: goto x86_l_19d;
	case 421ULL: goto x86_l_1a5;
	case 427ULL: goto x86_l_1ab;
	case 431ULL: goto x86_l_1af;
	case 437ULL: goto x86_l_1b5;
	case 441ULL: goto x86_l_1b9;
	case 447ULL: goto x86_l_1bf;
	case 451ULL: goto x86_l_1c3;
	case 457ULL: goto x86_l_1c9;
	case 462ULL: goto x86_l_1ce;
	case 467ULL: goto x86_l_1d3;
	case 472ULL: goto x86_l_1d8;
	case 477ULL: goto x86_l_1dd;
	case 479ULL: goto x86_l_1df;
	case 484ULL: goto x86_l_1e4;
	case 489ULL: goto x86_l_1e9;
	case 494ULL: goto x86_l_1ee;
	case 499ULL: goto x86_l_1f3;
	case 504ULL: goto x86_l_1f8;
	case 511ULL: goto x86_l_1ff;
	case 514ULL: goto x86_l_202;
	case 522ULL: goto x86_l_20a;
	case 528ULL: goto x86_l_210;
	case 536ULL: goto x86_l_218;
	case 540ULL: goto x86_l_21c;
	case 549ULL: goto x86_l_225;
	case 557ULL: goto x86_l_22d;
	case 562ULL: goto x86_l_232;
	case 568ULL: goto x86_l_238;
	case 573ULL: goto x86_l_23d;
	case 581ULL: goto x86_l_245;
	case 587ULL: goto x86_l_24b;
	case 592ULL: goto x86_l_250;
	case 597ULL: goto x86_l_255;
	case 602ULL: goto x86_l_25a;
	case 610ULL: goto x86_l_262;
	case 612ULL: goto x86_l_264;
	case 617ULL: goto x86_l_269;
	case 619ULL: goto x86_l_26b;
	case 625ULL: goto x86_l_271;
	case 630ULL: goto x86_l_276;
	case 633ULL: goto x86_l_279;
	case 636ULL: goto x86_l_27c;
	case 640ULL: goto x86_l_280;
	case 643ULL: goto x86_l_283;
	case 647ULL: goto x86_l_287;
	case 652ULL: goto x86_l_28c;
	case 659ULL: goto x86_l_293;
	case 665ULL: goto x86_l_299;
	case 668ULL: goto x86_l_29c;
	case 672ULL: goto x86_l_2a0;
	case 676ULL: goto x86_l_2a4;
	case 681ULL: goto x86_l_2a9;
	case 685ULL: goto x86_l_2ad;
	case 690ULL: goto x86_l_2b2;
	case 695ULL: goto x86_l_2b7;
	case 698ULL: goto x86_l_2ba;
	case 700ULL: goto x86_l_2bc;
	case 705ULL: goto x86_l_2c1;
	case 707ULL: goto x86_l_2c3;
	case 713ULL: goto x86_l_2c9;
	case 716ULL: goto x86_l_2cc;
	case 719ULL: goto x86_l_2cf;
	case 725ULL: goto x86_l_2d5;
	case 728ULL: goto x86_l_2d8;
	case 733ULL: goto x86_l_2dd;
	case 738ULL: goto x86_l_2e2;
	case 744ULL: goto x86_l_2e8;
	case 746ULL: goto x86_l_2ea;
	case 748ULL: goto x86_l_2ec;
	case 753ULL: goto x86_l_2f1;
	case 757ULL: goto x86_l_2f5;
	case 761ULL: goto x86_l_2f9;
	case 764ULL: goto x86_l_2fc;
	case 770ULL: goto x86_l_302;
	case 773ULL: goto x86_l_305;
	case 779ULL: goto x86_l_30b;
	case 783ULL: goto x86_l_30f;
	case 787ULL: goto x86_l_313;
	case 791ULL: goto x86_l_317;
	case 795ULL: goto x86_l_31b;
	case 799ULL: goto x86_l_31f;
	case 804ULL: goto x86_l_324;
	case 809ULL: goto x86_l_329;
	case 816ULL: goto x86_l_330;
	case 824ULL: goto x86_l_338;
	case 829ULL: goto x86_l_33d;
	case 831ULL: goto x86_l_33f;
	case 833ULL: goto x86_l_341;
	case 838ULL: goto x86_l_346;
	case 841ULL: goto x86_l_349;
	case 846ULL: goto x86_l_34e;
	case 850ULL: goto x86_l_352;
	case 855ULL: goto x86_l_357;
	case 859ULL: goto x86_l_35b;
	case 862ULL: goto x86_l_35e;
	case 867ULL: goto x86_l_363;
	case 871ULL: goto x86_l_367;
	case 877ULL: goto x86_l_36d;
	case 881ULL: goto x86_l_371;
	case 887ULL: goto x86_l_377;
	case 892ULL: goto x86_l_37c;
	case 897ULL: goto x86_l_381;
	case 902ULL: goto x86_l_386;
	case 904ULL: goto x86_l_388;
	case 916ULL: goto x86_l_394;
	case 924ULL: goto x86_l_39c;
	case 932ULL: goto x86_l_3a4;
	case 934ULL: goto x86_l_3a6;
	case 938ULL: goto x86_l_3aa;
	case 943ULL: goto x86_l_3af;
	case 948ULL: goto x86_l_3b4;
	case 953ULL: goto x86_l_3b9;
	case 958ULL: goto x86_l_3be;
	case 963ULL: goto x86_l_3c3;
	case 965ULL: goto x86_l_3c5;
	case 970ULL: goto x86_l_3ca;
	case 974ULL: goto x86_l_3ce;
	case 979ULL: goto x86_l_3d3;
	case 990ULL: goto x86_l_3de;
	case 995ULL: goto x86_l_3e3;
	case 1002ULL: goto x86_l_3ea;
	case 1010ULL: goto x86_l_3f2;
	case 1012ULL: goto x86_l_3f4;
	case 1015ULL: goto x86_l_3f7;
	case 1021ULL: goto x86_l_3fd;
	case 1024ULL: goto x86_l_400;
	case 1030ULL: goto x86_l_406;
	case 1035ULL: goto x86_l_40b;
	case 1040ULL: goto x86_l_410;
	case 1042ULL: goto x86_l_412;
	case 1049ULL: goto x86_l_419;
	case 1054ULL: goto x86_l_41e;
	case 1062ULL: goto x86_l_426;
	case 1067ULL: goto x86_l_42b;
	case 1069ULL: goto x86_l_42d;
	case 1077ULL: goto x86_l_435;
	case 1081ULL: goto x86_l_439;
	case 1089ULL: goto x86_l_441;
	case 1094ULL: goto x86_l_446;
	case 1098ULL: goto x86_l_44a;
	case 1103ULL: goto x86_l_44f;
	case 1111ULL: goto x86_l_457;
	case 1116ULL: goto x86_l_45c;
	case 1124ULL: goto x86_l_464;
	case 1126ULL: goto x86_l_466;
	case 1134ULL: goto x86_l_46e;
	case 1138ULL: goto x86_l_472;
	case 1143ULL: goto x86_l_477;
	case 1148ULL: goto x86_l_47c;
	case 1153ULL: goto x86_l_481;
	case 1155ULL: goto x86_l_483;
	case 1161ULL: goto x86_l_489;
	case 1166ULL: goto x86_l_48e;
	case 1168ULL: goto x86_l_490;
	case 1173ULL: goto x86_l_495;
	case 1175ULL: goto x86_l_497;
	case 1178ULL: goto x86_l_49a;
	case 1183ULL: goto x86_l_49f;
	case 1188ULL: goto x86_l_4a4;
	case 1192ULL: goto x86_l_4a8;
	case 1197ULL: goto x86_l_4ad;
	case 1202ULL: goto x86_l_4b2;
	case 1207ULL: goto x86_l_4b7;
	case 1209ULL: goto x86_l_4b9;
	case 1214ULL: goto x86_l_4be;
	case 1219ULL: goto x86_l_4c3;
	case 1221ULL: goto x86_l_4c5;
	case 1224ULL: goto x86_l_4c8;
	case 1231ULL: goto x86_l_4cf;
	case 1241ULL: goto x86_l_4d9;
	case 1249ULL: goto x86_l_4e1;
	case 1260ULL: goto x86_l_4ec;
	case 1265ULL: goto x86_l_4f1;
	case 1274ULL: goto x86_l_4fa;
	case 1283ULL: goto x86_l_503;
	case 1288ULL: goto x86_l_508;
	case 1293ULL: goto x86_l_50d;
	case 1298ULL: goto x86_l_512;
	case 1307ULL: goto x86_l_51b;
	case 1316ULL: goto x86_l_524;
	case 1325ULL: goto x86_l_52d;
	case 1330ULL: goto x86_l_532;
	case 1335ULL: goto x86_l_537;
	case 1339ULL: goto x86_l_53b;
	case 1344ULL: goto x86_l_540;
	case 1349ULL: goto x86_l_545;
	case 1353ULL: goto x86_l_549;
	case 1358ULL: goto x86_l_54e;
	case 1363ULL: goto x86_l_553;
	case 1368ULL: goto x86_l_558;
	case 1371ULL: goto x86_l_55b;
	case 1373ULL: goto x86_l_55d;
	case 1378ULL: goto x86_l_562;
	case 1381ULL: goto x86_l_565;
	case 1386ULL: goto x86_l_56a;
	case 1394ULL: goto x86_l_572;
	case 1396ULL: goto x86_l_574;
	case 1401ULL: goto x86_l_579;
	case 1404ULL: goto x86_l_57c;
	case 1409ULL: goto x86_l_581;
	case 1417ULL: goto x86_l_589;
	case 1419ULL: goto x86_l_58b;
	case 1424ULL: goto x86_l_590;
	case 1427ULL: goto x86_l_593;
	case 1432ULL: goto x86_l_598;
	case 1437ULL: goto x86_l_59d;
	case 1439ULL: goto x86_l_59f;
	case 1444ULL: goto x86_l_5a4;
	case 1448ULL: goto x86_l_5a8;
	case 1453ULL: goto x86_l_5ad;
	case 1460ULL: goto x86_l_5b4;
	case 1463ULL: goto x86_l_5b7;
	case 1469ULL: goto x86_l_5bd;
	case 1474ULL: goto x86_l_5c2;
	case 1479ULL: goto x86_l_5c7;
	case 1484ULL: goto x86_l_5cc;
	case 1489ULL: goto x86_l_5d1;
	case 1494ULL: goto x86_l_5d6;
	case 1496ULL: goto x86_l_5d8;
	case 1501ULL: goto x86_l_5dd;
	case 1507ULL: goto x86_l_5e3;
	case 1512ULL: goto x86_l_5e8;
	case 1520ULL: goto x86_l_5f0;
	case 1525ULL: goto x86_l_5f5;
	case 1527ULL: goto x86_l_5f7;
	case 1535ULL: goto x86_l_5ff;
	case 1541ULL: goto x86_l_605;
	case 1545ULL: goto x86_l_609;
	case 1550ULL: goto x86_l_60e;
	case 1555ULL: goto x86_l_613;
	case 1560ULL: goto x86_l_618;
	case 1563ULL: goto x86_l_61b;
	case 1565ULL: goto x86_l_61d;
	case 1570ULL: goto x86_l_622;
	case 1576ULL: goto x86_l_628;
	case 1581ULL: goto x86_l_62d;
	case 1589ULL: goto x86_l_635;
	case 1594ULL: goto x86_l_63a;
	case 1597ULL: goto x86_l_63d;
	case 1599ULL: goto x86_l_63f;
	case 1603ULL: goto x86_l_643;
	case 1608ULL: goto x86_l_648;
	case 1613ULL: goto x86_l_64d;
	case 1618ULL: goto x86_l_652;
	case 1621ULL: goto x86_l_655;
	case 1623ULL: goto x86_l_657;
	case 1628ULL: goto x86_l_65c;
	case 1633ULL: goto x86_l_661;
	case 1637ULL: goto x86_l_665;
	case 1640ULL: goto x86_l_668;
	case 1644ULL: goto x86_l_66c;
	case 1646ULL: goto x86_l_66e;
	case 1648ULL: goto x86_l_670;
	case 1653ULL: goto x86_l_675;
	case 1656ULL: goto x86_l_678;
	case 1661ULL: goto x86_l_67d;
	case 1664ULL: goto x86_l_680;
	case 1666ULL: goto x86_l_682;
	case 1670ULL: goto x86_l_686;
	case 1672ULL: goto x86_l_688;
	case 1675ULL: goto x86_l_68b;
	case 1678ULL: goto x86_l_68e;
	case 1681ULL: goto x86_l_691;
	case 1684ULL: goto x86_l_694;
	case 1689ULL: goto x86_l_699;
	case 1692ULL: goto x86_l_69c;
	case 1698ULL: goto x86_l_6a2;
	case 1704ULL: goto x86_l_6a8;
	case 1710ULL: goto x86_l_6ae;
	case 1712ULL: goto x86_l_6b0;
	case 1718ULL: goto x86_l_6b6;
	case 1722ULL: goto x86_l_6ba;
	case 1727ULL: goto x86_l_6bf;
	case 1731ULL: goto x86_l_6c3;
	case 1735ULL: goto x86_l_6c7;
	case 1738ULL: goto x86_l_6ca;
	case 1743ULL: goto x86_l_6cf;
	case 1745ULL: goto x86_l_6d1;
	case 1750ULL: goto x86_l_6d6;
	case 1758ULL: goto x86_l_6de;
	case 1763ULL: goto x86_l_6e3;
	case 1765ULL: goto x86_l_6e5;
	case 1771ULL: goto x86_l_6eb;
	case 1776ULL: goto x86_l_6f0;
	case 1781ULL: goto x86_l_6f5;
	case 1786ULL: goto x86_l_6fa;
	case 1791ULL: goto x86_l_6ff;
	case 1796ULL: goto x86_l_704;
	case 1798ULL: goto x86_l_706;
	case 1803ULL: goto x86_l_70b;
	case 1808ULL: goto x86_l_710;
	case 1814ULL: goto x86_l_716;
	case 1818ULL: goto x86_l_71a;
	case 1823ULL: goto x86_l_71f;
	case 1828ULL: goto x86_l_724;
	case 1833ULL: goto x86_l_729;
	case 1836ULL: goto x86_l_72c;
	case 1838ULL: goto x86_l_72e;
	case 1843ULL: goto x86_l_733;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 248ULL);
x86_l_a:
	/* 0xa: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    rax,QWORD PTR [rdi+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_11:
	/* 0x11: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_19:
	/* 0x19: mov    DWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_24:
	/* 0x24: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29:
	/* 0x29: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_30:
	/* 0x30: lea    rsi,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_38:
	/* 0x38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a:
	/* 0x3a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c:
	/* 0x3c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f:
	/* 0x3f: je     2d29 <generic_retkprobe_event+0x2d29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11561ULL;
	}
x86_l_45:
	/* 0x45: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_48:
	/* 0x48: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_4b:
	/* 0x4b: mov    eax,0xae */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 174ULL);
x86_l_50:
	/* 0x50: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_53:
	/* 0x53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55:
	/* 0x55: lea    rsi,[rbx+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_5c:
	/* 0x5c: mov    DWORD PTR [rbx+0x5ef8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_62:
	/* 0x62: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_67:
	/* 0x67: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_6e:
	/* 0x6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_70:
	/* 0x70: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_73:
	/* 0x73: je     2d29 <generic_retkprobe_event+0x2d29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11561ULL;
	}
x86_l_79:
	/* 0x79: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_7c:
	/* 0x7c: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7e:
	/* 0x7e: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_82:
	/* 0x82: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_87:
	/* 0x87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_89:
	/* 0x89: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_8d:
	/* 0x8d: jne    93 <generic_retkprobe_event+0x93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_93;
	}
x86_l_8f:
	/* 0x8f: mov    rax,QWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_93:
	/* 0x93: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_97:
	/* 0x97: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_9c:
	/* 0x9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e:
	/* 0x9e: mov    DWORD PTR [r14+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_a2:
	/* 0xa2: mov    rax,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a6:
	/* 0xa6: mov    rcx,QWORD PTR [r14+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_aa:
	/* 0xaa: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_af:
	/* 0xaf: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b4:
	/* 0xb4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b9:
	/* 0xb9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_c0:
	/* 0xc0: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c5:
	/* 0xc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c7:
	/* 0xc7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ca:
	/* 0xca: je     2d29 <generic_retkprobe_event+0x2d29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11561ULL;
	}
x86_l_d0:
	/* 0xd0: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d5:
	/* 0xd5: mov    rbx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d8:
	/* 0xd8: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dc:
	/* 0xdc: mov    QWORD PTR [rsp+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_e4:
	/* 0xe4: mov    rax,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e8:
	/* 0xe8: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_f0:
	/* 0xf0: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_f5:
	/* 0xf5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_fc:
	/* 0xfc: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_101:
	/* 0x101: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_103:
	/* 0x103: mov    QWORD PTR [r14+0x90],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_10a:
	/* 0x10a: mov    eax,DWORD PTR [r15+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_10e:
	/* 0x10e: mov    r12d,DWORD PTR [r15+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_112:
	/* 0x112: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_115:
	/* 0x115: je     1ee <generic_retkprobe_event+0x1ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ee;
	}
x86_l_11b:
	/* 0x11b: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11f:
	/* 0x11f: mov    DWORD PTR [r14+0x5ea0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104041287778304ULL);
x86_l_12a:
	/* 0x12a: mov    rbp,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_132:
	/* 0x132: mov    DWORD PTR [rsp+0xdc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_13d:
	/* 0x13d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_142:
	/* 0x142: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_149:
	/* 0x149: lea    rsi,[rsp+0xdc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_151:
	/* 0x151: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_153:
	/* 0x153: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_156:
	/* 0x156: je     2ea <generic_retkprobe_event+0x2ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ea;
	}
x86_l_15c:
	/* 0x15c: mov    ecx,DWORD PTR [rax+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24224ULL);
x86_l_162:
	/* 0x162: mov    DWORD PTR [rax+0x98],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_168:
	/* 0x168: mov    QWORD PTR [rax+0x5e78],0xc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103869489086476ULL);
x86_l_173:
	/* 0x173: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_178:
	/* 0x178: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_17a:
	/* 0x17a: jne    2ec <generic_retkprobe_event+0x2ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ec;
	}
x86_l_180:
	/* 0x180: lea    rcx,[rax+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_187:
	/* 0x187: mov    QWORD PTR [rsp+0x40],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18c:
	/* 0x18c: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_195:
	/* 0x195: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_199:
	/* 0x199: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19d:
	/* 0x19d: mov    QWORD PTR [rsp+0xb0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1a5:
	/* 0x1a5: jle    363 <generic_retkprobe_event+0x363> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_363;
	}
x86_l_1ab:
	/* 0x1ab: cmp    r12d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 42ULL);
x86_l_1af:
	/* 0x1af: je     388 <generic_retkprobe_event+0x388> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_388;
	}
x86_l_1b5:
	/* 0x1b5: cmp    r12d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 37ULL);
x86_l_1b9:
	/* 0x1b9: je     3a6 <generic_retkprobe_event+0x3a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a6;
	}
x86_l_1bf:
	/* 0x1bf: cmp    r12d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 24ULL);
x86_l_1c3:
	/* 0x1c3: jne    831 <generic_retkprobe_event+0x831> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2097ULL;
	}
x86_l_1c9:
	/* 0x1c9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ce:
	/* 0x1ce: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d3:
	/* 0x1d3: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d8:
	/* 0x1d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dd:
	/* 0x1dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1df:
	/* 0x1df: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e4:
	/* 0x1e4: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e9:
	/* 0x1e9: jmp    377 <generic_retkprobe_event+0x377> */
	goto x86_l_377;
x86_l_1ee:
	/* 0x1ee: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_1f3:
	/* 0x1f3: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f8:
	/* 0x1f8: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1ff:
	/* 0x1ff: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_202:
	/* 0x202: mov    QWORD PTR [rsp+0xf0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_20a:
	/* 0x20a: jne    28e1 <generic_retkprobe_event+0x28e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10465ULL;
	}
x86_l_210:
	/* 0x210: mov    DWORD PTR [r12+rbx*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_218:
	/* 0x218: lea    rbp,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_21c:
	/* 0x21c: cmp    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_225:
	/* 0x225: mov    QWORD PTR [rsp+0xb0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_22d:
	/* 0x22d: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_232:
	/* 0x232: je     346 <generic_retkprobe_event+0x346> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_346;
	}
x86_l_238:
	/* 0x238: mov    QWORD PTR [rsp+0x28],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_23d:
	/* 0x23d: mov    r12,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_245:
	/* 0x245: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_24b:
	/* 0x24b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_250:
	/* 0x250: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_255:
	/* 0x255: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_25a:
	/* 0x25a: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_262:
	/* 0x262: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_264:
	/* 0x264: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_269:
	/* 0x269: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26b:
	/* 0x26b: js     2adb <generic_retkprobe_event+0x2adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10971ULL;
	}
x86_l_271:
	/* 0x271: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_276:
	/* 0x276: cmp    rsi,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_279:
	/* 0x279: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_27c:
	/* 0x27c: cmovb  r12,rsi */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RSI, X86_WIDTH_64, X86_CC_B);
x86_l_280:
	/* 0x280: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_283:
	/* 0x283: cmovne rsi,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_287:
	/* 0x287: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_28c:
	/* 0x28c: cmp    rsi,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 4094ULL);
x86_l_293:
	/* 0x293: ja     2adb <generic_retkprobe_event+0x2adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10971ULL;
	}
x86_l_299:
	/* 0x299: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_29c:
	/* 0x29c: add    rbx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_2a0:
	/* 0x2a0: mov    QWORD PTR [rsp],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a4:
	/* 0x2a4: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a9:
	/* 0x2a9: lea    rdi,[rax+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_2ad:
	/* 0x2ad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b2:
	/* 0x2b2: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b7:
	/* 0x2b7: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_2ba:
	/* 0x2ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bc:
	/* 0x2bc: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2c1:
	/* 0x2c1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c3:
	/* 0x2c3: js     2adb <generic_retkprobe_event+0x2adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10971ULL;
	}
x86_l_2c9:
	/* 0x2c9: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2cc:
	/* 0x2cc: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_2cf:
	/* 0x2cf: je     9d3 <generic_retkprobe_event+0x9d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2515ULL;
	}
x86_l_2d5:
	/* 0x2d5: sub    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2d8:
	/* 0x2d8: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dd:
	/* 0x2dd: mov    rbp,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e2:
	/* 0x2e2: jne    9df <generic_retkprobe_event+0x9df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2527ULL;
	}
x86_l_2e8:
	/* 0x2e8: jmp    349 <generic_retkprobe_event+0x349> */
	goto x86_l_349;
x86_l_2ea:
	/* 0x2ea: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ec:
	/* 0x2ec: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f1:
	/* 0x2f1: add    rbx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f5:
	/* 0x2f5: mov    eax,DWORD PTR [r15+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2f9:
	/* 0x2f9: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_2fc:
	/* 0x2fc: je     28a9 <generic_retkprobe_event+0x28a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10409ULL;
	}
x86_l_302:
	/* 0x302: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_305:
	/* 0x305: jne    28bf <generic_retkprobe_event+0x28bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10431ULL;
	}
x86_l_30b:
	/* 0x30b: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30f:
	/* 0x30f: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_313:
	/* 0x313: mov    eax,DWORD PTR [r14+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_317:
	/* 0x317: mov    DWORD PTR [rsp+0x44],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_31b:
	/* 0x31b: mov    rax,QWORD PTR [r14+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31f:
	/* 0x31f: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_324:
	/* 0x324: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_329:
	/* 0x329: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_330:
	/* 0x330: lea    rsi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_338:
	/* 0x338: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_33d:
	/* 0x33d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33f:
	/* 0x33f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_341:
	/* 0x341: jmp    28bf <generic_retkprobe_event+0x28bf> */
	return 10431ULL;
x86_l_346:
	/* 0x346: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_349:
	/* 0x349: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34e:
	/* 0x34e: mov    DWORD PTR [rbx+rbp*1],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_352:
	/* 0x352: mov    DWORD PTR [rbx+rbp*1+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 4ULL);
x86_l_357:
	/* 0x357: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_35b:
	/* 0x35b: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_35e:
	/* 0x35e: jmp    2ae8 <generic_retkprobe_event+0x2ae8> */
	return 10984ULL;
x86_l_363:
	/* 0x363: cmp    r12d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 15ULL);
x86_l_367:
	/* 0x367: je     76d <generic_retkprobe_event+0x76d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1901ULL;
	}
x86_l_36d:
	/* 0x36d: cmp    r12d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 16ULL);
x86_l_371:
	/* 0x371: jne    831 <generic_retkprobe_event+0x831> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2097ULL;
	}
x86_l_377:
	/* 0x377: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37c:
	/* 0x37c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_381:
	/* 0x381: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_386:
	/* 0x386: jmp    3be <generic_retkprobe_event+0x3be> */
	goto x86_l_3be;
x86_l_388:
	/* 0x388: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_394:
	/* 0x394: mov    QWORD PTR [rsp+0x90],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_39c:
	/* 0x39c: lea    rax,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3a4:
	/* 0x3a4: jmp    3ce <generic_retkprobe_event+0x3ce> */
	goto x86_l_3ce;
x86_l_3a6:
	/* 0x3a6: add    rbp,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_3aa:
	/* 0x3aa: mov    QWORD PTR [rsp+0x40],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3af:
	/* 0x3af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b4:
	/* 0x3b4: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3b9:
	/* 0x3b9: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3be:
	/* 0x3be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c3:
	/* 0x3c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c5:
	/* 0x3c5: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ca:
	/* 0x3ca: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_3ce:
	/* 0x3ce: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3d3:
	/* 0x3d3: mov    DWORD PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_3de:
	/* 0x3de: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e3:
	/* 0x3e3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_3ea:
	/* 0x3ea: lea    rsi,[rsp+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_3f2:
	/* 0x3f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f4:
	/* 0x3f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f7:
	/* 0x3f7: je     497 <generic_retkprobe_event+0x497> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_497;
	}
x86_l_3fd:
	/* 0x3fd: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_400:
	/* 0x400: add    rax,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4096ULL);
x86_l_406:
	/* 0x406: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40b:
	/* 0x40b: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_410:
	/* 0x410: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_412:
	/* 0x412: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_419:
	/* 0x419: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_41e:
	/* 0x41e: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_426:
	/* 0x426: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42b:
	/* 0x42b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42d:
	/* 0x42d: mov    rbp,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_435:
	/* 0x435: lea    rax,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_439:
	/* 0x439: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_441:
	/* 0x441: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_446:
	/* 0x446: lea    rdx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44a:
	/* 0x44a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_44f:
	/* 0x44f: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_457:
	/* 0x457: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45c:
	/* 0x45c: mov    QWORD PTR [rsp+0xe0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_464:
	/* 0x464: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_466:
	/* 0x466: mov    r13,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_46e:
	/* 0x46e: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_472:
	/* 0x472: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_477:
	/* 0x477: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_47c:
	/* 0x47c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_481:
	/* 0x481: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_483:
	/* 0x483: cmp    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_489:
	/* 0x489: mov    ebx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4096ULL);
x86_l_48e:
	/* 0x48e: je     4a4 <generic_retkprobe_event+0x4a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a4;
	}
x86_l_490:
	/* 0x490: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_495:
	/* 0x495: jmp    4f1 <generic_retkprobe_event+0x4f1> */
	goto x86_l_4f1;
x86_l_497:
	/* 0x497: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_49a:
	/* 0x49a: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_49f:
	/* 0x49f: jmp    2882 <generic_retkprobe_event+0x2882> */
	return 10370ULL;
x86_l_4a4:
	/* 0x4a4: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a8:
	/* 0x4a8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4ad:
	/* 0x4ad: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4b2:
	/* 0x4b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b7:
	/* 0x4b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b9:
	/* 0x4b9: cmp    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4be:
	/* 0x4be: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c3:
	/* 0x4c3: je     4f1 <generic_retkprobe_event+0x4f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f1;
	}
x86_l_4c5:
	/* 0x4c5: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_4c8:
	/* 0x4c8: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_4cf:
	/* 0x4cf: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_4d9:
	/* 0x4d9: mov    QWORD PTR [r12+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_4e1:
	/* 0x4e1: mov    WORD PTR [r12+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_4ec:
	/* 0x4ec: mov    ebx,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4086ULL);
x86_l_4f1:
	/* 0x4f1: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_4fa:
	/* 0x4fa: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_503:
	/* 0x503: mov    QWORD PTR [rsp+0x50],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_508:
	/* 0x508: lea    r12,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_50d:
	/* 0x50d: lea    r13,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_512:
	/* 0x512: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_51b:
	/* 0x51b: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_524:
	/* 0x524: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_52d:
	/* 0x52d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_532:
	/* 0x532: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_537:
	/* 0x537: mov    DWORD PTR [rsp+0x78],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_53b:
	/* 0x53b: lea    rbx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_540:
	/* 0x540: mov    BYTE PTR [rsp+0x7c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_545:
	/* 0x545: add    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_549:
	/* 0x549: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_54e:
	/* 0x54e: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_553:
	/* 0x553: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_558:
	/* 0x558: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_55b:
	/* 0x55b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55d:
	/* 0x55d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_562:
	/* 0x562: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_565:
	/* 0x565: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56a:
	/* 0x56a: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_572:
	/* 0x572: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_574:
	/* 0x574: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_579:
	/* 0x579: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_57c:
	/* 0x57c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_581:
	/* 0x581: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_589:
	/* 0x589: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58b:
	/* 0x58b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_590:
	/* 0x590: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_593:
	/* 0x593: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_598:
	/* 0x598: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_59d:
	/* 0x59d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59f:
	/* 0x59f: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5a4:
	/* 0x5a4: add    rax,0xffffffffffffffe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_5a8:
	/* 0x5a8: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5ad:
	/* 0x5ad: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_5b4:
	/* 0x5b4: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b7:
	/* 0x5b7: je     74e <generic_retkprobe_event+0x74e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1870ULL;
	}
x86_l_5bd:
	/* 0x5bd: mov    ebx,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2048ULL);
x86_l_5c2:
	/* 0x5c2: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5c7:
	/* 0x5c7: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5cc:
	/* 0x5cc: mov    r12,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5d1:
	/* 0x5d1: cmp    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_5d6:
	/* 0x5d6: jne    5e3 <generic_retkprobe_event+0x5e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5e3;
	}
x86_l_5d8:
	/* 0x5d8: cmp    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_5dd:
	/* 0x5dd: je     8d6 <generic_retkprobe_event+0x8d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2262ULL;
	}
x86_l_5e3:
	/* 0x5e3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5e8:
	/* 0x5e8: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_5f0:
	/* 0x5f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f5:
	/* 0x5f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f7:
	/* 0x5f7: cmp    r13,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 168ULL);
x86_l_5ff:
	/* 0x5ff: je     6f0 <generic_retkprobe_event+0x6f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6f0;
	}
x86_l_605:
	/* 0x605: lea    rbp,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_609:
	/* 0x609: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_60e:
	/* 0x60e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_613:
	/* 0x613: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_618:
	/* 0x618: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_61b:
	/* 0x61b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61d:
	/* 0x61d: cmp    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_622:
	/* 0x622: je     6f0 <generic_retkprobe_event+0x6f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6f0;
	}
x86_l_628:
	/* 0x628: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_62d:
	/* 0x62d: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_635:
	/* 0x635: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_63a:
	/* 0x63a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_63d:
	/* 0x63d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63f:
	/* 0x63f: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_643:
	/* 0x643: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_648:
	/* 0x648: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_64d:
	/* 0x64d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_652:
	/* 0x652: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_655:
	/* 0x655: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_657:
	/* 0x657: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_65c:
	/* 0x65c: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_661:
	/* 0x661: mov    ecx,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_665:
	/* 0x665: sub    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_668:
	/* 0x668: mov    esi,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_66c:
	/* 0x66c: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_66e:
	/* 0x66e: sub    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_670:
	/* 0x670: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_675:
	/* 0x675: cmovb  edx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_678:
	/* 0x678: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_67d:
	/* 0x67d: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_680:
	/* 0x680: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_682:
	/* 0x682: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_686:
	/* 0x686: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_688:
	/* 0x688: cmovb  edi,esi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_32, X86_CC_B);
x86_l_68b:
	/* 0x68b: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_68e:
	/* 0x68e: mov    r9d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RSI, X86_WIDTH_32);
x86_l_691:
	/* 0x691: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_694:
	/* 0x694: mov    DWORD PTR [rsp+0x78],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_699:
	/* 0x699: sub    rax,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_69c:
	/* 0x69c: jb     8db <generic_retkprobe_event+0x8db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2267ULL;
	}
x86_l_6a2:
	/* 0x6a2: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_6a8:
	/* 0x6a8: ja     8db <generic_retkprobe_event+0x8db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2267ULL;
	}
x86_l_6ae:
	/* 0x6ae: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_6b0:
	/* 0x6b0: jbe    bed <generic_retkprobe_event+0xbed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 3053ULL;
	}
x86_l_6b6:
	/* 0x6b6: lea    r13,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_6ba:
	/* 0x6ba: mov    BYTE PTR [r12+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_6bf:
	/* 0x6bf: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_6c3:
	/* 0x6c3: lea    rdi,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_6c7:
	/* 0x6c7: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_6ca:
	/* 0x6ca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6cf:
	/* 0x6cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d1:
	/* 0x6d1: mov    QWORD PTR [rsp+0x70],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6d6:
	/* 0x6d6: mov    rax,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_6de:
	/* 0x6de: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_6e3:
	/* 0x6e3: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_6e5:
	/* 0x6e5: jne    5c2 <generic_retkprobe_event+0x5c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5c2;
	}
x86_l_6eb:
	/* 0x6eb: jmp    8db <generic_retkprobe_event+0x8db> */
	return 2267ULL;
x86_l_6f0:
	/* 0x6f0: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6f5:
	/* 0x6f5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6fa:
	/* 0x6fa: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6ff:
	/* 0x6ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_704:
	/* 0x704: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_706:
	/* 0x706: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_70b:
	/* 0x70b: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_710:
	/* 0x710: je     8d6 <generic_retkprobe_event+0x8d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2262ULL;
	}
x86_l_716:
	/* 0x716: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_71a:
	/* 0x71a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_71f:
	/* 0x71f: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_724:
	/* 0x724: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_729:
	/* 0x729: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_72c:
	/* 0x72c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72e:
	/* 0x72e: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_733:
	/* 0x733: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
	return 1848ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1848ULL: goto x86_l_738;
	case 1852ULL: goto x86_l_73c;
	case 1857ULL: goto x86_l_741;
	case 1859ULL: goto x86_l_743;
	case 1865ULL: goto x86_l_749;
	case 1870ULL: goto x86_l_74e;
	case 1875ULL: goto x86_l_753;
	case 1882ULL: goto x86_l_75a;
	case 1887ULL: goto x86_l_75f;
	case 1892ULL: goto x86_l_764;
	case 1894ULL: goto x86_l_766;
	case 1896ULL: goto x86_l_768;
	case 1901ULL: goto x86_l_76d;
	case 1906ULL: goto x86_l_772;
	case 1911ULL: goto x86_l_777;
	case 1916ULL: goto x86_l_77c;
	case 1921ULL: goto x86_l_781;
	case 1926ULL: goto x86_l_786;
	case 1928ULL: goto x86_l_788;
	case 1933ULL: goto x86_l_78d;
	case 1938ULL: goto x86_l_792;
	case 1941ULL: goto x86_l_795;
	case 1947ULL: goto x86_l_79b;
	case 1958ULL: goto x86_l_7a6;
	case 1963ULL: goto x86_l_7ab;
	case 1970ULL: goto x86_l_7b2;
	case 1978ULL: goto x86_l_7ba;
	case 1980ULL: goto x86_l_7bc;
	case 1983ULL: goto x86_l_7bf;
	case 1986ULL: goto x86_l_7c2;
	case 1992ULL: goto x86_l_7c8;
	case 1996ULL: goto x86_l_7cc;
	case 2000ULL: goto x86_l_7d0;
	case 2006ULL: goto x86_l_7d6;
	case 2010ULL: goto x86_l_7da;
	case 2016ULL: goto x86_l_7e0;
	case 2020ULL: goto x86_l_7e4;
	case 2026ULL: goto x86_l_7ea;
	case 2030ULL: goto x86_l_7ee;
	case 2036ULL: goto x86_l_7f4;
	case 2040ULL: goto x86_l_7f8;
	case 2046ULL: goto x86_l_7fe;
	case 2050ULL: goto x86_l_802;
	case 2055ULL: goto x86_l_807;
	case 2061ULL: goto x86_l_80d;
	case 2071ULL: goto x86_l_817;
	case 2077ULL: goto x86_l_81d;
	case 2083ULL: goto x86_l_823;
	case 2086ULL: goto x86_l_826;
	case 2092ULL: goto x86_l_82c;
	case 2097ULL: goto x86_l_831;
	case 2102ULL: goto x86_l_836;
	case 2106ULL: goto x86_l_83a;
	case 2112ULL: goto x86_l_840;
	case 2115ULL: goto x86_l_843;
	case 2125ULL: goto x86_l_84d;
	case 2129ULL: goto x86_l_851;
	case 2135ULL: goto x86_l_857;
	case 2140ULL: goto x86_l_85c;
	case 2151ULL: goto x86_l_867;
	case 2156ULL: goto x86_l_86c;
	case 2163ULL: goto x86_l_873;
	case 2171ULL: goto x86_l_87b;
	case 2173ULL: goto x86_l_87d;
	case 2176ULL: goto x86_l_880;
	case 2179ULL: goto x86_l_883;
	case 2185ULL: goto x86_l_889;
	case 2189ULL: goto x86_l_88d;
	case 2195ULL: goto x86_l_893;
	case 2199ULL: goto x86_l_897;
	case 2204ULL: goto x86_l_89c;
	case 2210ULL: goto x86_l_8a2;
	case 2214ULL: goto x86_l_8a6;
	case 2220ULL: goto x86_l_8ac;
	case 2225ULL: goto x86_l_8b1;
	case 2228ULL: goto x86_l_8b4;
	case 2234ULL: goto x86_l_8ba;
	case 2240ULL: goto x86_l_8c0;
	case 2245ULL: goto x86_l_8c5;
	case 2250ULL: goto x86_l_8ca;
	case 2255ULL: goto x86_l_8cf;
	case 2257ULL: goto x86_l_8d1;
	case 2262ULL: goto x86_l_8d6;
	case 2267ULL: goto x86_l_8db;
	case 2272ULL: goto x86_l_8e0;
	case 2277ULL: goto x86_l_8e5;
	case 2279ULL: goto x86_l_8e7;
	case 2282ULL: goto x86_l_8ea;
	case 2284ULL: goto x86_l_8ec;
	case 2289ULL: goto x86_l_8f1;
	case 2292ULL: goto x86_l_8f4;
	case 2296ULL: goto x86_l_8f8;
	case 2302ULL: goto x86_l_8fe;
	case 2305ULL: goto x86_l_901;
	case 2307ULL: goto x86_l_903;
	case 2311ULL: goto x86_l_907;
	case 2314ULL: goto x86_l_90a;
	case 2318ULL: goto x86_l_90e;
	case 2323ULL: goto x86_l_913;
	case 2329ULL: goto x86_l_919;
	case 2331ULL: goto x86_l_91b;
	case 2333ULL: goto x86_l_91d;
	case 2336ULL: goto x86_l_920;
	case 2338ULL: goto x86_l_922;
	case 2341ULL: goto x86_l_925;
	case 2345ULL: goto x86_l_929;
	case 2350ULL: goto x86_l_92e;
	case 2357ULL: goto x86_l_935;
	case 2364ULL: goto x86_l_93c;
	case 2369ULL: goto x86_l_941;
	case 2372ULL: goto x86_l_944;
	case 2374ULL: goto x86_l_946;
	case 2378ULL: goto x86_l_94a;
	case 2385ULL: goto x86_l_951;
	case 2390ULL: goto x86_l_956;
	case 2395ULL: goto x86_l_95b;
	case 2400ULL: goto x86_l_960;
	case 2408ULL: goto x86_l_968;
	case 2410ULL: goto x86_l_96a;
	case 2415ULL: goto x86_l_96f;
	case 2420ULL: goto x86_l_974;
	case 2424ULL: goto x86_l_978;
	case 2429ULL: goto x86_l_97d;
	case 2434ULL: goto x86_l_982;
	case 2436ULL: goto x86_l_984;
	case 2441ULL: goto x86_l_989;
	case 2446ULL: goto x86_l_98e;
	case 2451ULL: goto x86_l_993;
	case 2456ULL: goto x86_l_998;
	case 2458ULL: goto x86_l_99a;
	case 2462ULL: goto x86_l_99e;
	case 2470ULL: goto x86_l_9a6;
	case 2475ULL: goto x86_l_9ab;
	case 2484ULL: goto x86_l_9b4;
	case 2488ULL: goto x86_l_9b8;
	case 2493ULL: goto x86_l_9bd;
	case 2496ULL: goto x86_l_9c0;
	case 2502ULL: goto x86_l_9c6;
	case 2507ULL: goto x86_l_9cb;
	case 2510ULL: goto x86_l_9ce;
	case 2515ULL: goto x86_l_9d3;
	case 2517ULL: goto x86_l_9d5;
	case 2522ULL: goto x86_l_9da;
	case 2527ULL: goto x86_l_9df;
	case 2536ULL: goto x86_l_9e8;
	case 2538ULL: goto x86_l_9ea;
	case 2541ULL: goto x86_l_9ed;
	case 2546ULL: goto x86_l_9f2;
	case 2554ULL: goto x86_l_9fa;
	case 2558ULL: goto x86_l_9fe;
	case 2564ULL: goto x86_l_a04;
	case 2569ULL: goto x86_l_a09;
	case 2574ULL: goto x86_l_a0e;
	case 2579ULL: goto x86_l_a13;
	case 2581ULL: goto x86_l_a15;
	case 2586ULL: goto x86_l_a1a;
	case 2588ULL: goto x86_l_a1c;
	case 2590ULL: goto x86_l_a1e;
	case 2595ULL: goto x86_l_a23;
	case 2600ULL: goto x86_l_a28;
	case 2603ULL: goto x86_l_a2b;
	case 2606ULL: goto x86_l_a2e;
	case 2610ULL: goto x86_l_a32;
	case 2613ULL: goto x86_l_a35;
	case 2617ULL: goto x86_l_a39;
	case 2622ULL: goto x86_l_a3e;
	case 2629ULL: goto x86_l_a45;
	case 2631ULL: goto x86_l_a47;
	case 2635ULL: goto x86_l_a4b;
	case 2638ULL: goto x86_l_a4e;
	case 2642ULL: goto x86_l_a52;
	case 2647ULL: goto x86_l_a57;
	case 2651ULL: goto x86_l_a5b;
	case 2656ULL: goto x86_l_a60;
	case 2661ULL: goto x86_l_a65;
	case 2664ULL: goto x86_l_a68;
	case 2666ULL: goto x86_l_a6a;
	case 2671ULL: goto x86_l_a6f;
	case 2673ULL: goto x86_l_a71;
	case 2675ULL: goto x86_l_a73;
	case 2678ULL: goto x86_l_a76;
	case 2683ULL: goto x86_l_a7b;
	case 2686ULL: goto x86_l_a7e;
	case 2692ULL: goto x86_l_a84;
	case 2695ULL: goto x86_l_a87;
	case 2698ULL: goto x86_l_a8a;
	case 2704ULL: goto x86_l_a90;
	case 2709ULL: goto x86_l_a95;
	case 2714ULL: goto x86_l_a9a;
	case 2719ULL: goto x86_l_a9f;
	case 2723ULL: goto x86_l_aa3;
	case 2729ULL: goto x86_l_aa9;
	case 2733ULL: goto x86_l_aad;
	case 2737ULL: goto x86_l_ab1;
	case 2743ULL: goto x86_l_ab7;
	case 2747ULL: goto x86_l_abb;
	case 2753ULL: goto x86_l_ac1;
	case 2757ULL: goto x86_l_ac5;
	case 2763ULL: goto x86_l_acb;
	case 2767ULL: goto x86_l_acf;
	case 2773ULL: goto x86_l_ad5;
	case 2776ULL: goto x86_l_ad8;
	case 2781ULL: goto x86_l_add;
	case 2788ULL: goto x86_l_ae4;
	case 2795ULL: goto x86_l_aeb;
	case 2800ULL: goto x86_l_af0;
	case 2805ULL: goto x86_l_af5;
	case 2810ULL: goto x86_l_afa;
	case 2813ULL: goto x86_l_afd;
	case 2815ULL: goto x86_l_aff;
	case 2822ULL: goto x86_l_b06;
	case 2827ULL: goto x86_l_b0b;
	case 2832ULL: goto x86_l_b10;
	case 2837ULL: goto x86_l_b15;
	case 2839ULL: goto x86_l_b17;
	case 2846ULL: goto x86_l_b1e;
	case 2854ULL: goto x86_l_b26;
	case 2859ULL: goto x86_l_b2b;
	case 2864ULL: goto x86_l_b30;
	case 2866ULL: goto x86_l_b32;
	case 2873ULL: goto x86_l_b39;
	case 2881ULL: goto x86_l_b41;
	case 2886ULL: goto x86_l_b46;
	case 2891ULL: goto x86_l_b4b;
	case 2893ULL: goto x86_l_b4d;
	case 2900ULL: goto x86_l_b54;
	case 2908ULL: goto x86_l_b5c;
	case 2913ULL: goto x86_l_b61;
	case 2918ULL: goto x86_l_b66;
	case 2920ULL: goto x86_l_b68;
	case 2927ULL: goto x86_l_b6f;
	case 2935ULL: goto x86_l_b77;
	case 2940ULL: goto x86_l_b7c;
	case 2945ULL: goto x86_l_b81;
	case 2947ULL: goto x86_l_b83;
	case 2954ULL: goto x86_l_b8a;
	case 2959ULL: goto x86_l_b8f;
	case 2966ULL: goto x86_l_b96;
	case 2974ULL: goto x86_l_b9e;
	case 2982ULL: goto x86_l_ba6;
	case 2990ULL: goto x86_l_bae;
	case 2997ULL: goto x86_l_bb5;
	case 3000ULL: goto x86_l_bb8;
	case 3006ULL: goto x86_l_bbe;
	case 3009ULL: goto x86_l_bc1;
	case 3015ULL: goto x86_l_bc7;
	case 3020ULL: goto x86_l_bcc;
	case 3025ULL: goto x86_l_bd1;
	case 3030ULL: goto x86_l_bd6;
	case 3032ULL: goto x86_l_bd8;
	case 3037ULL: goto x86_l_bdd;
	case 3040ULL: goto x86_l_be0;
	case 3045ULL: goto x86_l_be5;
	case 3048ULL: goto x86_l_be8;
	case 3053ULL: goto x86_l_bed;
	case 3057ULL: goto x86_l_bf1;
	case 3060ULL: goto x86_l_bf4;
	case 3065ULL: goto x86_l_bf9;
	case 3068ULL: goto x86_l_bfc;
	case 3070ULL: goto x86_l_bfe;
	case 3075ULL: goto x86_l_c03;
	case 3080ULL: goto x86_l_c08;
	case 3084ULL: goto x86_l_c0c;
	case 3090ULL: goto x86_l_c12;
	case 3094ULL: goto x86_l_c16;
	case 3100ULL: goto x86_l_c1c;
	case 3104ULL: goto x86_l_c20;
	case 3110ULL: goto x86_l_c26;
	case 3114ULL: goto x86_l_c2a;
	case 3118ULL: goto x86_l_c2e;
	case 3124ULL: goto x86_l_c34;
	case 3129ULL: goto x86_l_c39;
	case 3134ULL: goto x86_l_c3e;
	case 3137ULL: goto x86_l_c41;
	case 3141ULL: goto x86_l_c45;
	case 3147ULL: goto x86_l_c4b;
	case 3152ULL: goto x86_l_c50;
	case 3155ULL: goto x86_l_c53;
	case 3161ULL: goto x86_l_c59;
	case 3165ULL: goto x86_l_c5d;
	case 3171ULL: goto x86_l_c63;
	case 3176ULL: goto x86_l_c68;
	case 3181ULL: goto x86_l_c6d;
	case 3186ULL: goto x86_l_c72;
	case 3191ULL: goto x86_l_c77;
	case 3194ULL: goto x86_l_c7a;
	case 3196ULL: goto x86_l_c7c;
	case 3201ULL: goto x86_l_c81;
	case 3206ULL: goto x86_l_c86;
	case 3209ULL: goto x86_l_c89;
	case 3214ULL: goto x86_l_c8e;
	case 3216ULL: goto x86_l_c90;
	case 3220ULL: goto x86_l_c94;
	case 3225ULL: goto x86_l_c99;
	case 3228ULL: goto x86_l_c9c;
	case 3235ULL: goto x86_l_ca3;
	case 3240ULL: goto x86_l_ca8;
	case 3245ULL: goto x86_l_cad;
	case 3250ULL: goto x86_l_cb2;
	case 3254ULL: goto x86_l_cb6;
	case 3260ULL: goto x86_l_cbc;
	case 3265ULL: goto x86_l_cc1;
	case 3268ULL: goto x86_l_cc4;
	case 3274ULL: goto x86_l_cca;
	case 3279ULL: goto x86_l_ccf;
	case 3284ULL: goto x86_l_cd4;
	case 3289ULL: goto x86_l_cd9;
	case 3292ULL: goto x86_l_cdc;
	case 3297ULL: goto x86_l_ce1;
	case 3301ULL: goto x86_l_ce5;
	case 3307ULL: goto x86_l_ceb;
	case 3311ULL: goto x86_l_cef;
	case 3317ULL: goto x86_l_cf5;
	case 3321ULL: goto x86_l_cf9;
	case 3325ULL: goto x86_l_cfd;
	case 3331ULL: goto x86_l_d03;
	case 3336ULL: goto x86_l_d08;
	case 3341ULL: goto x86_l_d0d;
	case 3346ULL: goto x86_l_d12;
	case 3354ULL: goto x86_l_d1a;
	case 3362ULL: goto x86_l_d22;
	case 3370ULL: goto x86_l_d2a;
	case 3378ULL: goto x86_l_d32;
	case 3386ULL: goto x86_l_d3a;
	case 3394ULL: goto x86_l_d42;
	case 3402ULL: goto x86_l_d4a;
	case 3410ULL: goto x86_l_d52;
	case 3418ULL: goto x86_l_d5a;
	case 3426ULL: goto x86_l_d62;
	case 3434ULL: goto x86_l_d6a;
	case 3442ULL: goto x86_l_d72;
	case 3450ULL: goto x86_l_d7a;
	case 3457ULL: goto x86_l_d81;
	case 3462ULL: goto x86_l_d86;
	case 3467ULL: goto x86_l_d8b;
	case 3470ULL: goto x86_l_d8e;
	case 3472ULL: goto x86_l_d90;
	case 3475ULL: goto x86_l_d93;
	case 3481ULL: goto x86_l_d99;
	case 3486ULL: goto x86_l_d9e;
	case 3491ULL: goto x86_l_da3;
	case 3496ULL: goto x86_l_da8;
	case 3501ULL: goto x86_l_dad;
	case 3504ULL: goto x86_l_db0;
	case 3506ULL: goto x86_l_db2;
	case 3509ULL: goto x86_l_db5;
	case 3515ULL: goto x86_l_dbb;
	case 3519ULL: goto x86_l_dbf;
	case 3522ULL: goto x86_l_dc2;
	case 3529ULL: goto x86_l_dc9;
	case 3534ULL: goto x86_l_dce;
	case 3541ULL: goto x86_l_dd5;
	case 3547ULL: goto x86_l_ddb;
	case 3552ULL: goto x86_l_de0;
	case 3557ULL: goto x86_l_de5;
	case 3560ULL: goto x86_l_de8;
	case 3562ULL: goto x86_l_dea;
	case 3564ULL: goto x86_l_dec;
	case 3570ULL: goto x86_l_df2;
	case 3572ULL: goto x86_l_df4;
	case 3577ULL: goto x86_l_df9;
	case 3581ULL: goto x86_l_dfd;
	case 3587ULL: goto x86_l_e03;
	case 3591ULL: goto x86_l_e07;
	case 3597ULL: goto x86_l_e0d;
	case 3601ULL: goto x86_l_e11;
	case 3606ULL: goto x86_l_e16;
	case 3612ULL: goto x86_l_e1c;
	case 3623ULL: goto x86_l_e27;
	case 3629ULL: goto x86_l_e2d;
	case 3632ULL: goto x86_l_e30;
	case 3638ULL: goto x86_l_e36;
	case 3643ULL: goto x86_l_e3b;
	case 3649ULL: goto x86_l_e41;
	case 3654ULL: goto x86_l_e46;
	case 3659ULL: goto x86_l_e4b;
	case 3664ULL: goto x86_l_e50;
	case 3666ULL: goto x86_l_e52;
	case 3671ULL: goto x86_l_e57;
	case 3675ULL: goto x86_l_e5b;
	case 3677ULL: goto x86_l_e5d;
	case 3681ULL: goto x86_l_e61;
	case 3687ULL: goto x86_l_e67;
	case 3692ULL: goto x86_l_e6c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_738:
	/* 0x738: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_73c:
	/* 0x73c: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_741:
	/* 0x741: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_743:
	/* 0x743: jne    5c2 <generic_retkprobe_event+0x5c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1474ULL;
	}
x86_l_749:
	/* 0x749: jmp    8db <generic_retkprobe_event+0x8db> */
	goto x86_l_8db;
x86_l_74e:
	/* 0x74e: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_753:
	/* 0x753: lea    rsi,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_75a:
	/* 0x75a: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_75f:
	/* 0x75f: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_764:
	/* 0x764: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_766:
	/* 0x766: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_768:
	/* 0x768: jmp    8db <generic_retkprobe_event+0x8db> */
	goto x86_l_8db;
x86_l_76d:
	/* 0x76d: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_772:
	/* 0x772: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_777:
	/* 0x777: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_77c:
	/* 0x77c: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_781:
	/* 0x781: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_786:
	/* 0x786: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_788:
	/* 0x788: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_78d:
	/* 0x78d: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_792:
	/* 0x792: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_795:
	/* 0x795: jne    3d3 <generic_retkprobe_event+0x3d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 979ULL;
	}
x86_l_79b:
	/* 0x79b: mov    DWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_7a6:
	/* 0x7a6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7ab:
	/* 0x7ab: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_7b2:
	/* 0x7b2: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_7ba:
	/* 0x7ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7bc:
	/* 0x7bc: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7bf:
	/* 0x7bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7c2:
	/* 0x7c2: je     2870 <generic_retkprobe_event+0x2870> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10352ULL;
	}
x86_l_7c8:
	/* 0x7c8: cmp    r12d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 25ULL);
x86_l_7cc:
	/* 0x7cc: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7d0:
	/* 0x7d0: jg     cb2 <generic_retkprobe_event+0xcb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_cb2;
	}
x86_l_7d6:
	/* 0x7d6: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_7da:
	/* 0x7da: jle    df9 <generic_retkprobe_event+0xdf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_df9;
	}
x86_l_7e0:
	/* 0x7e0: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_7e4:
	/* 0x7e4: jle    1111 <generic_retkprobe_event+0x1111> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4369ULL;
	}
x86_l_7ea:
	/* 0x7ea: cmp    r12d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 21ULL);
x86_l_7ee:
	/* 0x7ee: je     19d7 <generic_retkprobe_event+0x19d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6615ULL;
	}
x86_l_7f4:
	/* 0x7f4: cmp    r12d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 22ULL);
x86_l_7f8:
	/* 0x7f8: je     1953 <generic_retkprobe_event+0x1953> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6483ULL;
	}
x86_l_7fe:
	/* 0x7fe: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_802:
	/* 0x802: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_807:
	/* 0x807: jne    2879 <generic_retkprobe_event+0x2879> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10361ULL;
	}
x86_l_80d:
	/* 0x80d: mov    DWORD PTR [rcx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_817:
	/* 0x817: mov    DWORD PTR [rcx+0x9c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_81d:
	/* 0x81d: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_823:
	/* 0x823: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_826:
	/* 0x826: jns    2882 <generic_retkprobe_event+0x2882> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 10370ULL;
	}
x86_l_82c:
	/* 0x82c: jmp    1fde <generic_retkprobe_event+0x1fde> */
	return 8158ULL;
x86_l_831:
	/* 0x831: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_836:
	/* 0x836: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_83a:
	/* 0x83a: ja     79b <generic_retkprobe_event+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_79b;
	}
x86_l_840:
	/* 0x840: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_843:
	/* 0x843: movabs rcx,0x11c1f2027cf2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19524686609650ULL);
x86_l_84d:
	/* 0x84d: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_851:
	/* 0x851: jae    79b <generic_retkprobe_event+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_79b;
	}
x86_l_857:
	/* 0x857: mov    QWORD PTR [rsp+0x18],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_85c:
	/* 0x85c: mov    DWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_867:
	/* 0x867: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_86c:
	/* 0x86c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_873:
	/* 0x873: lea    rsi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_87b:
	/* 0x87b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_87d:
	/* 0x87d: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_880:
	/* 0x880: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_883:
	/* 0x883: je     2870 <generic_retkprobe_event+0x2870> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10352ULL;
	}
x86_l_889:
	/* 0x889: cmp    r12d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 16ULL);
x86_l_88d:
	/* 0x88d: jle    a9f <generic_retkprobe_event+0xa9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_a9f;
	}
x86_l_893:
	/* 0x893: cmp    r12d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 30ULL);
x86_l_897:
	/* 0x897: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_89c:
	/* 0x89c: jle    c08 <generic_retkprobe_event+0xc08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_c08;
	}
x86_l_8a2:
	/* 0x8a2: cmp    r12d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 38ULL);
x86_l_8a6:
	/* 0x8a6: jg     ce1 <generic_retkprobe_event+0xce1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_ce1;
	}
x86_l_8ac:
	/* 0x8ac: lea    eax,[r12-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_8b1:
	/* 0x8b1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8b4:
	/* 0x8b4: jae    11de <generic_retkprobe_event+0x11de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4574ULL;
	}
x86_l_8ba:
	/* 0x8ba: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_8c0:
	/* 0x8c0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8c5:
	/* 0x8c5: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8ca:
	/* 0x8ca: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_8cf:
	/* 0x8cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d1:
	/* 0x8d1: jmp    2870 <generic_retkprobe_event+0x2870> */
	return 10352ULL;
x86_l_8d6:
	/* 0x8d6: mov    BYTE PTR [rsp+0x7c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 532575944705ULL);
x86_l_8db:
	/* 0x8db: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8e0:
	/* 0x8e0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8e5:
	/* 0x8e5: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8e7:
	/* 0x8e7: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_8ea:
	/* 0x8ea: je     922 <generic_retkprobe_event+0x922> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_922;
	}
x86_l_8ec:
	/* 0x8ec: cmp    BYTE PTR [rsp+0x7c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_8f1:
	/* 0x8f1: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_8f4:
	/* 0x8f4: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_8f8:
	/* 0x8f8: mov    r13d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4096ULL);
x86_l_8fe:
	/* 0x8fe: sub    r13d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_901:
	/* 0x901: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_903:
	/* 0x903: cmovle r13d,edx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_907:
	/* 0x907: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_90a:
	/* 0x90a: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_90e:
	/* 0x90e: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_913:
	/* 0x913: je     9cb <generic_retkprobe_event+0x9cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9cb;
	}
x86_l_919:
	/* 0x919: mov    bl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_8);
x86_l_91b:
	/* 0x91b: add    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_91d:
	/* 0x91d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_920:
	/* 0x920: jmp    92e <generic_retkprobe_event+0x92e> */
	goto x86_l_92e;
x86_l_922:
	/* 0x922: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_925:
	/* 0x925: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_929:
	/* 0x929: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_92e:
	/* 0x92e: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_935:
	/* 0x935: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_93c:
	/* 0x93c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_941:
	/* 0x941: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_944:
	/* 0x944: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_946:
	/* 0x946: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_94a:
	/* 0x94a: mov    DWORD PTR [rax+0x9c],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_951:
	/* 0x951: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_956:
	/* 0x956: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_95b:
	/* 0x95b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_960:
	/* 0x960: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_968:
	/* 0x968: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_96a:
	/* 0x96a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_96f:
	/* 0x96f: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_974:
	/* 0x974: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_978:
	/* 0x978: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_97d:
	/* 0x97d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_982:
	/* 0x982: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_984:
	/* 0x984: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_989:
	/* 0x989: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_98e:
	/* 0x98e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_993:
	/* 0x993: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_998:
	/* 0x998: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_99a:
	/* 0x99a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_99e:
	/* 0x99e: mov    DWORD PTR [rcx+r13*1+0xa0],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 160ULL);
x86_l_9a6:
	/* 0x9a6: movzx  eax,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_9ab:
	/* 0x9ab: mov    WORD PTR [rcx+r13*1+0xa4],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R13, 0), 164ULL);
x86_l_9b4:
	/* 0x9b4: add    r13d,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_9b8:
	/* 0x9b8: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_9bd:
	/* 0x9bd: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_9c0:
	/* 0x9c0: jns    2882 <generic_retkprobe_event+0x2882> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 10370ULL;
	}
x86_l_9c6:
	/* 0x9c6: jmp    1fde <generic_retkprobe_event+0x1fde> */
	return 8158ULL;
x86_l_9cb:
	/* 0x9cb: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9ce:
	/* 0x9ce: jmp    2882 <generic_retkprobe_event+0x2882> */
	return 10370ULL;
x86_l_9d3:
	/* 0x9d3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9d5:
	/* 0x9d5: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9da:
	/* 0x9da: mov    rbp,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9df:
	/* 0x9df: cmp    QWORD PTR [rsp+0x80],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813889ULL);
x86_l_9e8:
	/* 0x9e8: jne    9f2 <generic_retkprobe_event+0x9f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9f2;
	}
x86_l_9ea:
	/* 0x9ea: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_9ed:
	/* 0x9ed: jmp    349 <generic_retkprobe_event+0x349> */
	return 841ULL;
x86_l_9f2:
	/* 0x9f2: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_9fa:
	/* 0x9fa: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9fe:
	/* 0x9fe: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_a04:
	/* 0xa04: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a09:
	/* 0xa09: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a0e:
	/* 0xa0e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_a13:
	/* 0xa13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a15:
	/* 0xa15: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_a1a:
	/* 0xa1a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a1c:
	/* 0xa1c: js     a95 <generic_retkprobe_event+0xa95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_a95;
	}
x86_l_a1e:
	/* 0xa1e: mov    r12,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a23:
	/* 0xa23: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a28:
	/* 0xa28: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_a2b:
	/* 0xa2b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_a2e:
	/* 0xa2e: cmovb  r15,r12 */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_R12, X86_WIDTH_64, X86_CC_B);
x86_l_a32:
	/* 0xa32: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a35:
	/* 0xa35: cmovne r12,r15 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R15, X86_WIDTH_64, X86_CC_NE);
x86_l_a39:
	/* 0xa39: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_a3e:
	/* 0xa3e: cmp    r12,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 4094ULL);
x86_l_a45:
	/* 0xa45: ja     a95 <generic_retkprobe_event+0xa95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_a95;
	}
x86_l_a47:
	/* 0xa47: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a4b:
	/* 0xa4b: add    rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a4e:
	/* 0xa4e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a52:
	/* 0xa52: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a57:
	/* 0xa57: lea    rdi,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_a5b:
	/* 0xa5b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a60:
	/* 0xa60: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a65:
	/* 0xa65: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_a68:
	/* 0xa68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a6a:
	/* 0xa6a: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_a6f:
	/* 0xa6f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a71:
	/* 0xa71: js     a95 <generic_retkprobe_event+0xa95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_a95;
	}
x86_l_a73:
	/* 0xa73: add    rbx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a76:
	/* 0xa76: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a7b:
	/* 0xa7b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a7e:
	/* 0xa7e: je     15fb <generic_retkprobe_event+0x15fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5627ULL;
	}
x86_l_a84:
	/* 0xa84: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_a87:
	/* 0xa87: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_a8a:
	/* 0xa8a: jne    15fe <generic_retkprobe_event+0x15fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5630ULL;
	}
x86_l_a90:
	/* 0xa90: jmp    16bd <generic_retkprobe_event+0x16bd> */
	return 5821ULL;
x86_l_a95:
	/* 0xa95: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a9a:
	/* 0xa9a: jmp    2ae5 <generic_retkprobe_event+0x2ae5> */
	return 10981ULL;
x86_l_a9f:
	/* 0xa9f: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_aa3:
	/* 0xaa3: jg     c39 <generic_retkprobe_event+0xc39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_c39;
	}
x86_l_aa9:
	/* 0xaa9: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_aad:
	/* 0xaad: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ab1:
	/* 0xab1: jle    e57 <generic_retkprobe_event+0xe57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e57;
	}
x86_l_ab7:
	/* 0xab7: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_abb:
	/* 0xabb: je     1399 <generic_retkprobe_event+0x1399> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5017ULL;
	}
x86_l_ac1:
	/* 0xac1: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_ac5:
	/* 0xac5: je     c94 <generic_retkprobe_event+0xc94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c94;
	}
x86_l_acb:
	/* 0xacb: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_acf:
	/* 0xacf: jne    2874 <generic_retkprobe_event+0x2874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10356ULL;
	}
x86_l_ad5:
	/* 0xad5: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_ad8:
	/* 0xad8: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_add:
	/* 0xadd: mov    QWORD PTR [rcx+0xc4],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_ae4:
	/* 0xae4: lea    rdi,[rcx+0xc2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_aeb:
	/* 0xaeb: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_af0:
	/* 0xaf0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_af5:
	/* 0xaf5: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_afa:
	/* 0xafa: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_afd:
	/* 0xafd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aff:
	/* 0xaff: lea    rdi,[rbx+0xd6] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 214ULL);
x86_l_b06:
	/* 0xb06: lea    rdx,[r12+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_b0b:
	/* 0xb0b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b10:
	/* 0xb10: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_b15:
	/* 0xb15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b17:
	/* 0xb17: lea    rdi,[rbx+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_b1e:
	/* 0xb1e: lea    rdx,[r12+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_b26:
	/* 0xb26: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b2b:
	/* 0xb2b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_b30:
	/* 0xb30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b32:
	/* 0xb32: lea    rdi,[rbx+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_b39:
	/* 0xb39: lea    rdx,[r12+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_b41:
	/* 0xb41: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b46:
	/* 0xb46: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_b4b:
	/* 0xb4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b4d:
	/* 0xb4d: lea    rdi,[rbx+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_b54:
	/* 0xb54: lea    rdx,[r12+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_b5c:
	/* 0xb5c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b61:
	/* 0xb61: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_b66:
	/* 0xb66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b68:
	/* 0xb68: lea    rdi,[rbx+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_b6f:
	/* 0xb6f: lea    rdx,[r12+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_b77:
	/* 0xb77: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b7c:
	/* 0xb7c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_b81:
	/* 0xb81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b83:
	/* 0xb83: lea    r13,[rbx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_b8a:
	/* 0xb8a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b8f:
	/* 0xb8f: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b96:
	/* 0xb96: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_b9e:
	/* 0xb9e: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_ba6:
	/* 0xba6: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_bae:
	/* 0xbae: movzx  eax,WORD PTR [rbx+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_bb5:
	/* 0xbb5: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_bb8:
	/* 0xbb8: je     1d09 <generic_retkprobe_event+0x1d09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7433ULL;
	}
x86_l_bbe:
	/* 0xbbe: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_bc1:
	/* 0xbc1: jne    1d2e <generic_retkprobe_event+0x1d2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7470ULL;
	}
x86_l_bc7:
	/* 0xbc7: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bcc:
	/* 0xbcc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bd1:
	/* 0xbd1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_bd6:
	/* 0xbd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd8:
	/* 0xbd8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bdd:
	/* 0xbdd: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_be0:
	/* 0xbe0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_be5:
	/* 0xbe5: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_be8:
	/* 0xbe8: jmp    1d2c <generic_retkprobe_event+0x1d2c> */
	return 7468ULL;
x86_l_bed:
	/* 0xbed: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_bf1:
	/* 0xbf1: add    r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_bf4:
	/* 0xbf4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bf9:
	/* 0xbf9: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_bfc:
	/* 0xbfc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bfe:
	/* 0xbfe: mov    QWORD PTR [rsp+0x70],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c03:
	/* 0xc03: jmp    8db <generic_retkprobe_event+0x8db> */
	goto x86_l_8db;
x86_l_c08:
	/* 0xc08: cmp    r12d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 28ULL);
x86_l_c0c:
	/* 0xc0c: jg     e3b <generic_retkprobe_event+0xe3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_e3b;
	}
x86_l_c12:
	/* 0xc12: cmp    r12d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 17ULL);
x86_l_c16:
	/* 0xc16: je     121b <generic_retkprobe_event+0x121b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4635ULL;
	}
x86_l_c1c:
	/* 0xc1c: cmp    r12d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 25ULL);
x86_l_c20:
	/* 0xc20: je     12de <generic_retkprobe_event+0x12de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4830ULL;
	}
x86_l_c26:
	/* 0xc26: cmp    r12d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 28ULL);
x86_l_c2a:
	/* 0xc2a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c2e:
	/* 0xc2e: je     e67 <generic_retkprobe_event+0xe67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e67;
	}
x86_l_c34:
	/* 0xc34: jmp    2874 <generic_retkprobe_event+0x2874> */
	return 10356ULL;
x86_l_c39:
	/* 0xc39: lea    eax,[r12-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_c3e:
	/* 0xc3e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c41:
	/* 0xc41: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c45:
	/* 0xc45: jb     e67 <generic_retkprobe_event+0xe67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_e67;
	}
x86_l_c4b:
	/* 0xc4b: lea    eax,[r12-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_c50:
	/* 0xc50: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c53:
	/* 0xc53: jb     e8c <generic_retkprobe_event+0xe8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 3724ULL;
	}
x86_l_c59:
	/* 0xc59: cmp    r12d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 14ULL);
x86_l_c5d:
	/* 0xc5d: jne    2874 <generic_retkprobe_event+0x2874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10356ULL;
	}
x86_l_c63:
	/* 0xc63: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c68:
	/* 0xc68: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c6d:
	/* 0xc6d: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c72:
	/* 0xc72: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c77:
	/* 0xc77: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_c7a:
	/* 0xc7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c7c:
	/* 0xc7c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c81:
	/* 0xc81: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c86:
	/* 0xc86: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_c89:
	/* 0xc89: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c8e:
	/* 0xc8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c90:
	/* 0xc90: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c94:
	/* 0xc94: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c99:
	/* 0xc99: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_c9c:
	/* 0xc9c: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_ca3:
	/* 0xca3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_ca8:
	/* 0xca8: mov    esi,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4097ULL);
x86_l_cad:
	/* 0xcad: jmp    154d <generic_retkprobe_event+0x154d> */
	return 5453ULL;
x86_l_cb2:
	/* 0xcb2: cmp    r12d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 32ULL);
x86_l_cb6:
	/* 0xcb6: jle    1005 <generic_retkprobe_event+0x1005> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4101ULL;
	}
x86_l_cbc:
	/* 0xcbc: lea    edx,[r12-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_cc1:
	/* 0xcc1: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_cc4:
	/* 0xcc4: jae    ead <generic_retkprobe_event+0xead> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3757ULL;
	}
x86_l_cca:
	/* 0xcca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ccf:
	/* 0xccf: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cd4:
	/* 0xcd4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cd9:
	/* 0xcd9: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_cdc:
	/* 0xcdc: jmp    e7b <generic_retkprobe_event+0xe7b> */
	return 3707ULL;
x86_l_ce1:
	/* 0xce1: cmp    r12d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 39ULL);
x86_l_ce5:
	/* 0xce5: je     152e <generic_retkprobe_event+0x152e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5422ULL;
	}
x86_l_ceb:
	/* 0xceb: cmp    r12d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 40ULL);
x86_l_cef:
	/* 0xcef: je     156f <generic_retkprobe_event+0x156f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5487ULL;
	}
x86_l_cf5:
	/* 0xcf5: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_cf9:
	/* 0xcf9: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cfd:
	/* 0xcfd: jne    2874 <generic_retkprobe_event+0x2874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10356ULL;
	}
x86_l_d03:
	/* 0xd03: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d08:
	/* 0xd08: mov    BYTE PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_d0d:
	/* 0xd0d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d12:
	/* 0xd12: mov    QWORD PTR [rdi+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_d1a:
	/* 0xd1a: mov    QWORD PTR [rdi+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_d22:
	/* 0xd22: mov    QWORD PTR [rdi+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_d2a:
	/* 0xd2a: mov    QWORD PTR [rdi+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_d32:
	/* 0xd32: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_d3a:
	/* 0xd3a: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_d42:
	/* 0xd42: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_d4a:
	/* 0xd4a: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_d52:
	/* 0xd52: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_d5a:
	/* 0xd5a: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_d62:
	/* 0xd62: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_d6a:
	/* 0xd6a: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_d72:
	/* 0xd72: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_d7a:
	/* 0xd7a: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d81:
	/* 0xd81: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d86:
	/* 0xd86: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_d8b:
	/* 0xd8b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d8e:
	/* 0xd8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d90:
	/* 0xd90: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d93:
	/* 0xd93: js     1f05 <generic_retkprobe_event+0x1f05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7941ULL;
	}
x86_l_d99:
	/* 0xd99: lea    r13,[r12+0x2] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_d9e:
	/* 0xd9e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_da3:
	/* 0xda3: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_da8:
	/* 0xda8: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_dad:
	/* 0xdad: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_db0:
	/* 0xdb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_db2:
	/* 0xdb2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_db5:
	/* 0xdb5: js     1f05 <generic_retkprobe_event+0x1f05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7941ULL;
	}
x86_l_dbb:
	/* 0xdbb: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dbf:
	/* 0xdbf: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_dc2:
	/* 0xdc2: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_dc9:
	/* 0xdc9: cmp    BYTE PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_dce:
	/* 0xdce: sete   BYTE PTR [rax+0x9e] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_RAX, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 158ULL);
x86_l_dd5:
	/* 0xdd5: je     1edf <generic_retkprobe_event+0x1edf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7903ULL;
	}
x86_l_ddb:
	/* 0xddb: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_de0:
	/* 0xde0: mov    esi,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 108ULL);
x86_l_de5:
	/* 0xde5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_de8:
	/* 0xde8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dea:
	/* 0xdea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dec:
	/* 0xdec: js     1f05 <generic_retkprobe_event+0x1f05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7941ULL;
	}
x86_l_df2:
	/* 0xdf2: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_df4:
	/* 0xdf4: jmp    1efb <generic_retkprobe_event+0x1efb> */
	return 7931ULL;
x86_l_df9:
	/* 0xdf9: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_dfd:
	/* 0xdfd: jg     10d2 <generic_retkprobe_event+0x10d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4306ULL;
	}
x86_l_e03:
	/* 0xe03: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_e07:
	/* 0xe07: je     16c5 <generic_retkprobe_event+0x16c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5829ULL;
	}
x86_l_e0d:
	/* 0xe0d: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_e11:
	/* 0xe11: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e16:
	/* 0xe16: jne    2879 <generic_retkprobe_event+0x2879> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10361ULL;
	}
x86_l_e1c:
	/* 0xe1c: mov    QWORD PTR [rax+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_e27:
	/* 0xe27: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_e2d:
	/* 0xe2d: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_e30:
	/* 0xe30: jns    2882 <generic_retkprobe_event+0x2882> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 10370ULL;
	}
x86_l_e36:
	/* 0xe36: jmp    1fde <generic_retkprobe_event+0x1fde> */
	return 8158ULL;
x86_l_e3b:
	/* 0xe3b: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_e41:
	/* 0xe41: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e46:
	/* 0xe46: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e4b:
	/* 0xe4b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e50:
	/* 0xe50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e52:
	/* 0xe52: jmp    2870 <generic_retkprobe_event+0x2870> */
	return 10352ULL;
x86_l_e57:
	/* 0xe57: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_e5b:
	/* 0xe5b: je     e8c <generic_retkprobe_event+0xe8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3724ULL;
	}
x86_l_e5d:
	/* 0xe5d: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_e61:
	/* 0xe61: jne    2874 <generic_retkprobe_event+0x2874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10356ULL;
	}
x86_l_e67:
	/* 0xe67: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e6c:
	/* 0xe6c: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
	return 3697ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3697ULL: goto x86_l_e71;
	case 3702ULL: goto x86_l_e76;
	case 3707ULL: goto x86_l_e7b;
	case 3709ULL: goto x86_l_e7d;
	case 3713ULL: goto x86_l_e81;
	case 3719ULL: goto x86_l_e87;
	case 3724ULL: goto x86_l_e8c;
	case 3730ULL: goto x86_l_e92;
	case 3735ULL: goto x86_l_e97;
	case 3740ULL: goto x86_l_e9c;
	case 3745ULL: goto x86_l_ea1;
	case 3750ULL: goto x86_l_ea6;
	case 3752ULL: goto x86_l_ea8;
	case 3757ULL: goto x86_l_ead;
	case 3761ULL: goto x86_l_eb1;
	case 3767ULL: goto x86_l_eb7;
	case 3771ULL: goto x86_l_ebb;
	case 3776ULL: goto x86_l_ec0;
	case 3782ULL: goto x86_l_ec6;
	case 3787ULL: goto x86_l_ecb;
	case 3791ULL: goto x86_l_ecf;
	case 3796ULL: goto x86_l_ed4;
	case 3801ULL: goto x86_l_ed9;
	case 3806ULL: goto x86_l_ede;
	case 3809ULL: goto x86_l_ee1;
	case 3811ULL: goto x86_l_ee3;
	case 3816ULL: goto x86_l_ee8;
	case 3819ULL: goto x86_l_eeb;
	case 3825ULL: goto x86_l_ef1;
	case 3829ULL: goto x86_l_ef5;
	case 3836ULL: goto x86_l_efc;
	case 3843ULL: goto x86_l_f03;
	case 3848ULL: goto x86_l_f08;
	case 3853ULL: goto x86_l_f0d;
	case 3858ULL: goto x86_l_f12;
	case 3860ULL: goto x86_l_f14;
	case 3867ULL: goto x86_l_f1b;
	case 3872ULL: goto x86_l_f20;
	case 3877ULL: goto x86_l_f25;
	case 3882ULL: goto x86_l_f2a;
	case 3884ULL: goto x86_l_f2c;
	case 3891ULL: goto x86_l_f33;
	case 3899ULL: goto x86_l_f3b;
	case 3904ULL: goto x86_l_f40;
	case 3909ULL: goto x86_l_f45;
	case 3911ULL: goto x86_l_f47;
	case 3918ULL: goto x86_l_f4e;
	case 3926ULL: goto x86_l_f56;
	case 3931ULL: goto x86_l_f5b;
	case 3936ULL: goto x86_l_f60;
	case 3938ULL: goto x86_l_f62;
	case 3945ULL: goto x86_l_f69;
	case 3953ULL: goto x86_l_f71;
	case 3958ULL: goto x86_l_f76;
	case 3963ULL: goto x86_l_f7b;
	case 3965ULL: goto x86_l_f7d;
	case 3972ULL: goto x86_l_f84;
	case 3980ULL: goto x86_l_f8c;
	case 3985ULL: goto x86_l_f91;
	case 3990ULL: goto x86_l_f96;
	case 3992ULL: goto x86_l_f98;
	case 3999ULL: goto x86_l_f9f;
	case 4004ULL: goto x86_l_fa4;
	case 4011ULL: goto x86_l_fab;
	case 4019ULL: goto x86_l_fb3;
	case 4027ULL: goto x86_l_fbb;
	case 4030ULL: goto x86_l_fbe;
	case 4038ULL: goto x86_l_fc6;
	case 4045ULL: goto x86_l_fcd;
	case 4048ULL: goto x86_l_fd0;
	case 4054ULL: goto x86_l_fd6;
	case 4057ULL: goto x86_l_fd9;
	case 4063ULL: goto x86_l_fdf;
	case 4068ULL: goto x86_l_fe4;
	case 4073ULL: goto x86_l_fe9;
	case 4078ULL: goto x86_l_fee;
	case 4080ULL: goto x86_l_ff0;
	case 4085ULL: goto x86_l_ff5;
	case 4088ULL: goto x86_l_ff8;
	case 4093ULL: goto x86_l_ffd;
	case 4096ULL: goto x86_l_1000;
	case 4101ULL: goto x86_l_1005;
	case 4105ULL: goto x86_l_1009;
	case 4111ULL: goto x86_l_100f;
	case 4115ULL: goto x86_l_1013;
	case 4120ULL: goto x86_l_1018;
	case 4126ULL: goto x86_l_101e;
	case 4131ULL: goto x86_l_1023;
	case 4139ULL: goto x86_l_102b;
	case 4147ULL: goto x86_l_1033;
	case 4155ULL: goto x86_l_103b;
	case 4163ULL: goto x86_l_1043;
	case 4171ULL: goto x86_l_104b;
	case 4179ULL: goto x86_l_1053;
	case 4187ULL: goto x86_l_105b;
	case 4195ULL: goto x86_l_1063;
	case 4203ULL: goto x86_l_106b;
	case 4210ULL: goto x86_l_1072;
	case 4217ULL: goto x86_l_1079;
	case 4221ULL: goto x86_l_107d;
	case 4226ULL: goto x86_l_1082;
	case 4231ULL: goto x86_l_1087;
	case 4233ULL: goto x86_l_1089;
	case 4236ULL: goto x86_l_108c;
	case 4242ULL: goto x86_l_1092;
	case 4246ULL: goto x86_l_1096;
	case 4249ULL: goto x86_l_1099;
	case 4256ULL: goto x86_l_10a0;
	case 4263ULL: goto x86_l_10a7;
	case 4268ULL: goto x86_l_10ac;
	case 4273ULL: goto x86_l_10b1;
	case 4276ULL: goto x86_l_10b4;
	case 4278ULL: goto x86_l_10b6;
	case 4281ULL: goto x86_l_10b9;
	case 4287ULL: goto x86_l_10bf;
	case 4292ULL: goto x86_l_10c4;
	case 4295ULL: goto x86_l_10c7;
	case 4301ULL: goto x86_l_10cd;
	case 4306ULL: goto x86_l_10d2;
	case 4310ULL: goto x86_l_10d6;
	case 4316ULL: goto x86_l_10dc;
	case 4320ULL: goto x86_l_10e0;
	case 4325ULL: goto x86_l_10e5;
	case 4331ULL: goto x86_l_10eb;
	case 4336ULL: goto x86_l_10f0;
	case 4339ULL: goto x86_l_10f3;
	case 4344ULL: goto x86_l_10f8;
	case 4346ULL: goto x86_l_10fa;
	case 4349ULL: goto x86_l_10fd;
	case 4351ULL: goto x86_l_10ff;
	case 4355ULL: goto x86_l_1103;
	case 4358ULL: goto x86_l_1106;
	case 4364ULL: goto x86_l_110c;
	case 4369ULL: goto x86_l_1111;
	case 4373ULL: goto x86_l_1115;
	case 4379ULL: goto x86_l_111b;
	case 4383ULL: goto x86_l_111f;
	case 4388ULL: goto x86_l_1124;
	case 4394ULL: goto x86_l_112a;
	case 4403ULL: goto x86_l_1133;
	case 4410ULL: goto x86_l_113a;
	case 4417ULL: goto x86_l_1141;
	case 4422ULL: goto x86_l_1146;
	case 4427ULL: goto x86_l_114b;
	case 4432ULL: goto x86_l_1150;
	case 4434ULL: goto x86_l_1152;
	case 4439ULL: goto x86_l_1157;
	case 4444ULL: goto x86_l_115c;
	case 4449ULL: goto x86_l_1161;
	case 4454ULL: goto x86_l_1166;
	case 4456ULL: goto x86_l_1168;
	case 4460ULL: goto x86_l_116c;
	case 4467ULL: goto x86_l_1173;
	case 4472ULL: goto x86_l_1178;
	case 4477ULL: goto x86_l_117d;
	case 4480ULL: goto x86_l_1180;
	case 4485ULL: goto x86_l_1185;
	case 4487ULL: goto x86_l_1187;
	case 4491ULL: goto x86_l_118b;
	case 4498ULL: goto x86_l_1192;
	case 4505ULL: goto x86_l_1199;
	case 4510ULL: goto x86_l_119e;
	case 4515ULL: goto x86_l_11a3;
	case 4517ULL: goto x86_l_11a5;
	case 4521ULL: goto x86_l_11a9;
	case 4528ULL: goto x86_l_11b0;
	case 4535ULL: goto x86_l_11b7;
	case 4540ULL: goto x86_l_11bc;
	case 4545ULL: goto x86_l_11c1;
	case 4548ULL: goto x86_l_11c4;
	case 4550ULL: goto x86_l_11c6;
	case 4554ULL: goto x86_l_11ca;
	case 4560ULL: goto x86_l_11d0;
	case 4563ULL: goto x86_l_11d3;
	case 4569ULL: goto x86_l_11d9;
	case 4574ULL: goto x86_l_11de;
	case 4578ULL: goto x86_l_11e2;
	case 4582ULL: goto x86_l_11e6;
	case 4588ULL: goto x86_l_11ec;
	case 4593ULL: goto x86_l_11f1;
	case 4596ULL: goto x86_l_11f4;
	case 4604ULL: goto x86_l_11fc;
	case 4607ULL: goto x86_l_11ff;
	case 4613ULL: goto x86_l_1205;
	case 4616ULL: goto x86_l_1208;
	case 4623ULL: goto x86_l_120f;
	case 4625ULL: goto x86_l_1211;
	case 4630ULL: goto x86_l_1216;
	case 4635ULL: goto x86_l_121b;
	case 4644ULL: goto x86_l_1224;
	case 4653ULL: goto x86_l_122d;
	case 4658ULL: goto x86_l_1232;
	case 4660ULL: goto x86_l_1234;
	case 4664ULL: goto x86_l_1238;
	case 4669ULL: goto x86_l_123d;
	case 4674ULL: goto x86_l_1242;
	case 4679ULL: goto x86_l_1247;
	case 4684ULL: goto x86_l_124c;
	case 4689ULL: goto x86_l_1251;
	case 4691ULL: goto x86_l_1253;
	case 4695ULL: goto x86_l_1257;
	case 4699ULL: goto x86_l_125b;
	case 4704ULL: goto x86_l_1260;
	case 4711ULL: goto x86_l_1267;
	case 4716ULL: goto x86_l_126c;
	case 4718ULL: goto x86_l_126e;
	case 4721ULL: goto x86_l_1271;
	case 4727ULL: goto x86_l_1277;
	case 4730ULL: goto x86_l_127a;
	case 4735ULL: goto x86_l_127f;
	case 4740ULL: goto x86_l_1284;
	case 4745ULL: goto x86_l_1289;
	case 4748ULL: goto x86_l_128c;
	case 4753ULL: goto x86_l_1291;
	case 4756ULL: goto x86_l_1294;
	case 4758ULL: goto x86_l_1296;
	case 4765ULL: goto x86_l_129d;
	case 4769ULL: goto x86_l_12a1;
	case 4776ULL: goto x86_l_12a8;
	case 4780ULL: goto x86_l_12ac;
	case 4785ULL: goto x86_l_12b1;
	case 4788ULL: goto x86_l_12b4;
	case 4790ULL: goto x86_l_12b6;
	case 4798ULL: goto x86_l_12be;
	case 4801ULL: goto x86_l_12c1;
	case 4805ULL: goto x86_l_12c5;
	case 4809ULL: goto x86_l_12c9;
	case 4814ULL: goto x86_l_12ce;
	case 4819ULL: goto x86_l_12d3;
	case 4821ULL: goto x86_l_12d5;
	case 4825ULL: goto x86_l_12d9;
	case 4830ULL: goto x86_l_12de;
	case 4833ULL: goto x86_l_12e1;
	case 4838ULL: goto x86_l_12e6;
	case 4843ULL: goto x86_l_12eb;
	case 4851ULL: goto x86_l_12f3;
	case 4856ULL: goto x86_l_12f8;
	case 4859ULL: goto x86_l_12fb;
	case 4861ULL: goto x86_l_12fd;
	case 4869ULL: goto x86_l_1305;
	case 4871ULL: goto x86_l_1307;
	case 4877ULL: goto x86_l_130d;
	case 4880ULL: goto x86_l_1310;
	case 4886ULL: goto x86_l_1316;
	case 4890ULL: goto x86_l_131a;
	case 4896ULL: goto x86_l_1320;
	case 4901ULL: goto x86_l_1325;
	case 4906ULL: goto x86_l_132a;
	case 4911ULL: goto x86_l_132f;
	case 4914ULL: goto x86_l_1332;
	case 4916ULL: goto x86_l_1334;
	case 4921ULL: goto x86_l_1339;
	case 4926ULL: goto x86_l_133e;
	case 4931ULL: goto x86_l_1343;
	case 4936ULL: goto x86_l_1348;
	case 4938ULL: goto x86_l_134a;
	case 4943ULL: goto x86_l_134f;
	case 4947ULL: goto x86_l_1353;
	case 4952ULL: goto x86_l_1358;
	case 4960ULL: goto x86_l_1360;
	case 4965ULL: goto x86_l_1365;
	case 4967ULL: goto x86_l_1367;
	case 4972ULL: goto x86_l_136c;
	case 4980ULL: goto x86_l_1374;
	case 4987ULL: goto x86_l_137b;
	case 4993ULL: goto x86_l_1381;
	case 4997ULL: goto x86_l_1385;
	case 5000ULL: goto x86_l_1388;
	case 5007ULL: goto x86_l_138f;
	case 5012ULL: goto x86_l_1394;
	case 5017ULL: goto x86_l_1399;
	case 5022ULL: goto x86_l_139e;
	case 5029ULL: goto x86_l_13a5;
	case 5036ULL: goto x86_l_13ac;
	case 5041ULL: goto x86_l_13b1;
	case 5046ULL: goto x86_l_13b6;
	case 5049ULL: goto x86_l_13b9;
	case 5051ULL: goto x86_l_13bb;
	case 5058ULL: goto x86_l_13c2;
	case 5062ULL: goto x86_l_13c6;
	case 5067ULL: goto x86_l_13cb;
	case 5072ULL: goto x86_l_13d0;
	case 5074ULL: goto x86_l_13d2;
	case 5081ULL: goto x86_l_13d9;
	case 5088ULL: goto x86_l_13e0;
	case 5093ULL: goto x86_l_13e5;
	case 5098ULL: goto x86_l_13ea;
	case 5100ULL: goto x86_l_13ec;
	case 5107ULL: goto x86_l_13f3;
	case 5114ULL: goto x86_l_13fa;
	case 5119ULL: goto x86_l_13ff;
	case 5124ULL: goto x86_l_1404;
	case 5126ULL: goto x86_l_1406;
	case 5135ULL: goto x86_l_140f;
	case 5142ULL: goto x86_l_1416;
	case 5147ULL: goto x86_l_141b;
	case 5152ULL: goto x86_l_1420;
	case 5157ULL: goto x86_l_1425;
	case 5159ULL: goto x86_l_1427;
	case 5166ULL: goto x86_l_142e;
	case 5171ULL: goto x86_l_1433;
	case 5179ULL: goto x86_l_143b;
	case 5184ULL: goto x86_l_1440;
	case 5186ULL: goto x86_l_1442;
	case 5195ULL: goto x86_l_144b;
	case 5200ULL: goto x86_l_1450;
	case 5205ULL: goto x86_l_1455;
	case 5213ULL: goto x86_l_145d;
	case 5218ULL: goto x86_l_1462;
	case 5221ULL: goto x86_l_1465;
	case 5223ULL: goto x86_l_1467;
	case 5231ULL: goto x86_l_146f;
	case 5234ULL: goto x86_l_1472;
	case 5237ULL: goto x86_l_1475;
	case 5243ULL: goto x86_l_147b;
	case 5246ULL: goto x86_l_147e;
	case 5251ULL: goto x86_l_1483;
	case 5257ULL: goto x86_l_1489;
	case 5262ULL: goto x86_l_148e;
	case 5267ULL: goto x86_l_1493;
	case 5275ULL: goto x86_l_149b;
	case 5280ULL: goto x86_l_14a0;
	case 5282ULL: goto x86_l_14a2;
	case 5290ULL: goto x86_l_14aa;
	case 5294ULL: goto x86_l_14ae;
	case 5301ULL: goto x86_l_14b5;
	case 5310ULL: goto x86_l_14be;
	case 5317ULL: goto x86_l_14c5;
	case 5322ULL: goto x86_l_14ca;
	case 5327ULL: goto x86_l_14cf;
	case 5334ULL: goto x86_l_14d6;
	case 5342ULL: goto x86_l_14de;
	case 5350ULL: goto x86_l_14e6;
	case 5358ULL: goto x86_l_14ee;
	case 5363ULL: goto x86_l_14f3;
	case 5368ULL: goto x86_l_14f8;
	case 5370ULL: goto x86_l_14fa;
	case 5374ULL: goto x86_l_14fe;
	case 5379ULL: goto x86_l_1503;
	case 5382ULL: goto x86_l_1506;
	case 5387ULL: goto x86_l_150b;
	case 5390ULL: goto x86_l_150e;
	case 5392ULL: goto x86_l_1510;
	case 5399ULL: goto x86_l_1517;
	case 5404ULL: goto x86_l_151c;
	case 5412ULL: goto x86_l_1524;
	case 5417ULL: goto x86_l_1529;
	case 5422ULL: goto x86_l_152e;
	case 5427ULL: goto x86_l_1533;
	case 5432ULL: goto x86_l_1538;
	case 5436ULL: goto x86_l_153c;
	case 5443ULL: goto x86_l_1543;
	case 5448ULL: goto x86_l_1548;
	case 5453ULL: goto x86_l_154d;
	case 5455ULL: goto x86_l_154f;
	case 5458ULL: goto x86_l_1552;
	case 5461ULL: goto x86_l_1555;
	case 5467ULL: goto x86_l_155b;
	case 5471ULL: goto x86_l_155f;
	case 5476ULL: goto x86_l_1564;
	case 5478ULL: goto x86_l_1566;
	case 5482ULL: goto x86_l_156a;
	case 5487ULL: goto x86_l_156f;
	case 5492ULL: goto x86_l_1574;
	case 5500ULL: goto x86_l_157c;
	case 5508ULL: goto x86_l_1584;
	case 5515ULL: goto x86_l_158b;
	case 5520ULL: goto x86_l_1590;
	case 5525ULL: goto x86_l_1595;
	case 5528ULL: goto x86_l_1598;
	case 5531ULL: goto x86_l_159b;
	case 5533ULL: goto x86_l_159d;
	case 5536ULL: goto x86_l_15a0;
	case 5540ULL: goto x86_l_15a4;
	case 5546ULL: goto x86_l_15aa;
	case 5551ULL: goto x86_l_15af;
	case 5554ULL: goto x86_l_15b2;
	case 5560ULL: goto x86_l_15b8;
	case 5563ULL: goto x86_l_15bb;
	case 5569ULL: goto x86_l_15c1;
	case 5574ULL: goto x86_l_15c6;
	case 5579ULL: goto x86_l_15cb;
	case 5584ULL: goto x86_l_15d0;
	case 5589ULL: goto x86_l_15d5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e71:
	/* 0xe71: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e76:
	/* 0xe76: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e7b:
	/* 0xe7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e7d:
	/* 0xe7d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e81:
	/* 0xe81: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_e87:
	/* 0xe87: jmp    2874 <generic_retkprobe_event+0x2874> */
	return 10356ULL;
x86_l_e8c:
	/* 0xe8c: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_e92:
	/* 0xe92: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e97:
	/* 0xe97: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e9c:
	/* 0xe9c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ea1:
	/* 0xea1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ea6:
	/* 0xea6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea8:
	/* 0xea8: jmp    2870 <generic_retkprobe_event+0x2870> */
	return 10352ULL;
x86_l_ead:
	/* 0xead: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_eb1:
	/* 0xeb1: je     1aba <generic_retkprobe_event+0x1aba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6842ULL;
	}
x86_l_eb7:
	/* 0xeb7: cmp    r12d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 41ULL);
x86_l_ebb:
	/* 0xebb: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ec0:
	/* 0xec0: jne    2879 <generic_retkprobe_event+0x2879> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10361ULL;
	}
x86_l_ec6:
	/* 0xec6: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ecb:
	/* 0xecb: add    rbp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_ecf:
	/* 0xecf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ed4:
	/* 0xed4: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ed9:
	/* 0xed9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ede:
	/* 0xede: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_ee1:
	/* 0xee1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee3:
	/* 0xee3: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ee8:
	/* 0xee8: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_eeb:
	/* 0xeeb: je     1f81 <generic_retkprobe_event+0x1f81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8065ULL;
	}
x86_l_ef1:
	/* 0xef1: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ef5:
	/* 0xef5: mov    QWORD PTR [rbx+0xc4],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_efc:
	/* 0xefc: lea    rdi,[rbx+0xc2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_f03:
	/* 0xf03: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f08:
	/* 0xf08: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f0d:
	/* 0xf0d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_f12:
	/* 0xf12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f14:
	/* 0xf14: lea    rdi,[rbx+0xd6] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 214ULL);
x86_l_f1b:
	/* 0xf1b: lea    rdx,[r12+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_f20:
	/* 0xf20: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f25:
	/* 0xf25: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_f2a:
	/* 0xf2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f2c:
	/* 0xf2c: lea    rdi,[rbx+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_f33:
	/* 0xf33: lea    rdx,[r12+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_f3b:
	/* 0xf3b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f40:
	/* 0xf40: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_f45:
	/* 0xf45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f47:
	/* 0xf47: lea    rdi,[rbx+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_f4e:
	/* 0xf4e: lea    rdx,[r12+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_f56:
	/* 0xf56: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f5b:
	/* 0xf5b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_f60:
	/* 0xf60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f62:
	/* 0xf62: lea    rdi,[rbx+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_f69:
	/* 0xf69: lea    rdx,[r12+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_f71:
	/* 0xf71: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f76:
	/* 0xf76: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f7b:
	/* 0xf7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f7d:
	/* 0xf7d: lea    rdi,[rbx+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_f84:
	/* 0xf84: lea    rdx,[r12+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_f8c:
	/* 0xf8c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f91:
	/* 0xf91: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f96:
	/* 0xf96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f98:
	/* 0xf98: lea    r13,[rbx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_f9f:
	/* 0xf9f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fa4:
	/* 0xfa4: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fab:
	/* 0xfab: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_fb3:
	/* 0xfb3: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_fbb:
	/* 0xfbb: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_fbe:
	/* 0xfbe: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_fc6:
	/* 0xfc6: movzx  eax,WORD PTR [rbx+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_fcd:
	/* 0xfcd: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_fd0:
	/* 0xfd0: je     1f10 <generic_retkprobe_event+0x1f10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7952ULL;
	}
x86_l_fd6:
	/* 0xfd6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_fd9:
	/* 0xfd9: jne    1f35 <generic_retkprobe_event+0x1f35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7989ULL;
	}
x86_l_fdf:
	/* 0xfdf: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_fe4:
	/* 0xfe4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fe9:
	/* 0xfe9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fee:
	/* 0xfee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff0:
	/* 0xff0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ff5:
	/* 0xff5: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_ff8:
	/* 0xff8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ffd:
	/* 0xffd: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1000:
	/* 0x1000: jmp    1f33 <generic_retkprobe_event+0x1f33> */
	return 7987ULL;
x86_l_1005:
	/* 0x1005: cmp    r12d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 26ULL);
x86_l_1009:
	/* 0x1009: je     1b48 <generic_retkprobe_event+0x1b48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6984ULL;
	}
x86_l_100f:
	/* 0x100f: cmp    r12d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 27ULL);
x86_l_1013:
	/* 0x1013: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1018:
	/* 0x1018: jne    2879 <generic_retkprobe_event+0x2879> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10361ULL;
	}
x86_l_101e:
	/* 0x101e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1023:
	/* 0x1023: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_102b:
	/* 0x102b: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1033:
	/* 0x1033: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_103b:
	/* 0x103b: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1043:
	/* 0x1043: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_104b:
	/* 0x104b: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1053:
	/* 0x1053: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_105b:
	/* 0x105b: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1063:
	/* 0x1063: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_106b:
	/* 0x106b: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1072:
	/* 0x1072: lea    rdi,[rcx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1079:
	/* 0x1079: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_107d:
	/* 0x107d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1082:
	/* 0x1082: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_1087:
	/* 0x1087: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1089:
	/* 0x1089: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_108c:
	/* 0x108c: js     1ec5 <generic_retkprobe_event+0x1ec5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7877ULL;
	}
x86_l_1092:
	/* 0x1092: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1096:
	/* 0x1096: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1099:
	/* 0x1099: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_10a0:
	/* 0x10a0: add    rbp,0x348 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 840ULL);
x86_l_10a7:
	/* 0x10a7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10ac:
	/* 0x10ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10b1:
	/* 0x10b1: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_10b4:
	/* 0x10b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b6:
	/* 0x10b6: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_10b9:
	/* 0x10b9: mov    r13d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 80ULL);
x86_l_10bf:
	/* 0x10bf: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_10c4:
	/* 0x10c4: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_10c7:
	/* 0x10c7: jns    2882 <generic_retkprobe_event+0x2882> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 10370ULL;
	}
x86_l_10cd:
	/* 0x10cd: jmp    1fde <generic_retkprobe_event+0x1fde> */
	return 8158ULL;
x86_l_10d2:
	/* 0x10d2: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_10d6:
	/* 0x10d6: je     175f <generic_retkprobe_event+0x175f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5983ULL;
	}
x86_l_10dc:
	/* 0x10dc: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_10e0:
	/* 0x10e0: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10e5:
	/* 0x10e5: jne    2879 <generic_retkprobe_event+0x2879> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10361ULL;
	}
x86_l_10eb:
	/* 0x10eb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10f0:
	/* 0x10f0: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10f3:
	/* 0x10f3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10f8:
	/* 0x10f8: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10fa:
	/* 0x10fa: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_10fd:
	/* 0x10fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ff:
	/* 0x10ff: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_1106:
	/* 0x1106: jns    2882 <generic_retkprobe_event+0x2882> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 10370ULL;
	}
x86_l_110c:
	/* 0x110c: jmp    1fde <generic_retkprobe_event+0x1fde> */
	return 8158ULL;
x86_l_1111:
	/* 0x1111: cmp    r12d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 19ULL);
x86_l_1115:
	/* 0x1115: je     1a6a <generic_retkprobe_event+0x1a6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6762ULL;
	}
x86_l_111b:
	/* 0x111b: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_111f:
	/* 0x111f: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1124:
	/* 0x1124: jne    2879 <generic_retkprobe_event+0x2879> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10361ULL;
	}
x86_l_112a:
	/* 0x112a: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1133:
	/* 0x1133: lea    r12,[rbp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_113a:
	/* 0x113a: lea    rdx,[rbp+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_1141:
	/* 0x1141: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1146:
	/* 0x1146: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_114b:
	/* 0x114b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1150:
	/* 0x1150: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1152:
	/* 0x1152: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1157:
	/* 0x1157: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_115c:
	/* 0x115c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1161:
	/* 0x1161: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_1166:
	/* 0x1166: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1168:
	/* 0x1168: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_116c:
	/* 0x116c: lea    rdi,[rax+0x12c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 300ULL);
x86_l_1173:
	/* 0x1173: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1178:
	/* 0x1178: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_117d:
	/* 0x117d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1180:
	/* 0x1180: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1185:
	/* 0x1185: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1187:
	/* 0x1187: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_118b:
	/* 0x118b: lea    rdi,[rax+0x11c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 284ULL);
x86_l_1192:
	/* 0x1192: lea    rdx,[rbp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1199:
	/* 0x1199: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_119e:
	/* 0x119e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11a3:
	/* 0x11a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11a5:
	/* 0x11a5: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11a9:
	/* 0x11a9: add    rdi,0x124 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 292ULL);
x86_l_11b0:
	/* 0x11b0: add    rbp,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_11b7:
	/* 0x11b7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11bc:
	/* 0x11bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11c1:
	/* 0x11c1: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_11c4:
	/* 0x11c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11c6:
	/* 0x11c6: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11ca:
	/* 0x11ca: mov    r13d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 152ULL);
x86_l_11d0:
	/* 0x11d0: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_11d3:
	/* 0x11d3: jns    2882 <generic_retkprobe_event+0x2882> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 10370ULL;
	}
x86_l_11d9:
	/* 0x11d9: jmp    1fde <generic_retkprobe_event+0x1fde> */
	return 8158ULL;
x86_l_11de:
	/* 0x11de: cmp    r12d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 38ULL);
x86_l_11e2:
	/* 0x11e2: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11e6:
	/* 0x11e6: jne    2874 <generic_retkprobe_event+0x2874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10356ULL;
	}
x86_l_11ec:
	/* 0x11ec: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11f1:
	/* 0x11f1: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11f4:
	/* 0x11f4: add    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 176ULL);
x86_l_11fc:
	/* 0x11fc: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_11ff:
	/* 0x11ff: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1205:
	/* 0x1205: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_1208:
	/* 0x1208: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_120f:
	/* 0x120f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1211:
	/* 0x1211: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1216:
	/* 0x1216: jmp    154d <generic_retkprobe_event+0x154d> */
	goto x86_l_154d;
x86_l_121b:
	/* 0x121b: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1224:
	/* 0x1224: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_122d:
	/* 0x122d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1232:
	/* 0x1232: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1234:
	/* 0x1234: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1238:
	/* 0x1238: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_123d:
	/* 0x123d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1242:
	/* 0x1242: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1247:
	/* 0x1247: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_124c:
	/* 0x124c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1251:
	/* 0x1251: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1253:
	/* 0x1253: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1257:
	/* 0x1257: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_125b:
	/* 0x125b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1260:
	/* 0x1260: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1267:
	/* 0x1267: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_126c:
	/* 0x126c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_126e:
	/* 0x126e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1271:
	/* 0x1271: je     1bc4 <generic_retkprobe_event+0x1bc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7108ULL;
	}
x86_l_1277:
	/* 0x1277: mov    r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_127a:
	/* 0x127a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_127f:
	/* 0x127f: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1284:
	/* 0x1284: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1289:
	/* 0x1289: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_128c:
	/* 0x128c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1291:
	/* 0x1291: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1294:
	/* 0x1294: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1296:
	/* 0x1296: and    r13d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_129d:
	/* 0x129d: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12a1:
	/* 0x12a1: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_12a8:
	/* 0x12a8: lea    esi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_12ac:
	/* 0x12ac: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12b1:
	/* 0x12b1: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_12b4:
	/* 0x12b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12b6:
	/* 0x12b6: lea    rdi,[r13*1+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 8ULL);
x86_l_12be:
	/* 0x12be: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_12c1:
	/* 0x12c1: lea    rdx,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_12c5:
	/* 0x12c5: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_12c9:
	/* 0x12c9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12ce:
	/* 0x12ce: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12d3:
	/* 0x12d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d5:
	/* 0x12d5: add    r13,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_12d9:
	/* 0x12d9: jmp    2870 <generic_retkprobe_event+0x2870> */
	return 10352ULL;
x86_l_12de:
	/* 0x12de: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_12e1:
	/* 0x12e1: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12e6:
	/* 0x12e6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12eb:
	/* 0x12eb: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_12f3:
	/* 0x12f3: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_12f8:
	/* 0x12f8: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_12fb:
	/* 0x12fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12fd:
	/* 0x12fd: movzx  eax,BYTE PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 168ULL);
x86_l_1305:
	/* 0x1305: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1307:
	/* 0x1307: je     1bd0 <generic_retkprobe_event+0x1bd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7120ULL;
	}
x86_l_130d:
	/* 0x130d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1310:
	/* 0x1310: jne    1db7 <generic_retkprobe_event+0x1db7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7607ULL;
	}
x86_l_1316:
	/* 0x1316: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_131a:
	/* 0x131a: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1320:
	/* 0x1320: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1325:
	/* 0x1325: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_132a:
	/* 0x132a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_132f:
	/* 0x132f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1332:
	/* 0x1332: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1334:
	/* 0x1334: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1339:
	/* 0x1339: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_133e:
	/* 0x133e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1343:
	/* 0x1343: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1348:
	/* 0x1348: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_134a:
	/* 0x134a: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_134f:
	/* 0x134f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1353:
	/* 0x1353: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1358:
	/* 0x1358: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1360:
	/* 0x1360: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1365:
	/* 0x1365: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1367:
	/* 0x1367: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_136c:
	/* 0x136c: mov    rbp,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1374:
	/* 0x1374: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_137b:
	/* 0x137b: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_1381:
	/* 0x1381: cmovb  r12,rbp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_64, X86_CC_B);
x86_l_1385:
	/* 0x1385: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1388:
	/* 0x1388: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_138f:
	/* 0x138f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1394:
	/* 0x1394: jmp    1c34 <generic_retkprobe_event+0x1c34> */
	return 7220ULL;
x86_l_1399:
	/* 0x1399: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_139e:
	/* 0x139e: lea    rdi,[rcx+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_13a5:
	/* 0x13a5: lea    rdx,[rbp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_13ac:
	/* 0x13ac: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13b1:
	/* 0x13b1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13b6:
	/* 0x13b6: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_13b9:
	/* 0x13b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13bb:
	/* 0x13bb: lea    rdi,[rbx+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_13c2:
	/* 0x13c2: lea    rdx,[rbp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_13c6:
	/* 0x13c6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13cb:
	/* 0x13cb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13d0:
	/* 0x13d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13d2:
	/* 0x13d2: lea    rdi,[rbx+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_13d9:
	/* 0x13d9: lea    rdx,[rbp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_13e0:
	/* 0x13e0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13e5:
	/* 0x13e5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13ea:
	/* 0x13ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13ec:
	/* 0x13ec: lea    rdi,[rbx+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_13f3:
	/* 0x13f3: lea    rdx,[rbp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_13fa:
	/* 0x13fa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13ff:
	/* 0x13ff: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1404:
	/* 0x1404: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1406:
	/* 0x1406: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_140f:
	/* 0x140f: lea    rdx,[rbp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1416:
	/* 0x1416: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_141b:
	/* 0x141b: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1420:
	/* 0x1420: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1425:
	/* 0x1425: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1427:
	/* 0x1427: lea    rdx,[rbp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_142e:
	/* 0x142e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1433:
	/* 0x1433: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_143b:
	/* 0x143b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1440:
	/* 0x1440: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1442:
	/* 0x1442: movzx  r12d,WORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_144b:
	/* 0x144b: add    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_1450:
	/* 0x1450: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1455:
	/* 0x1455: lea    rdi,[rsp+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_145d:
	/* 0x145d: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1462:
	/* 0x1462: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1465:
	/* 0x1465: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1467:
	/* 0x1467: movzx  eax,BYTE PTR [rsp+0xa4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 164ULL);
x86_l_146f:
	/* 0x146f: shr    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_1472:
	/* 0x1472: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1475:
	/* 0x1475: je     1c65 <generic_retkprobe_event+0x1c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7269ULL;
	}
x86_l_147b:
	/* 0x147b: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_147e:
	/* 0x147e: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_1483:
	/* 0x1483: jne    286a <generic_retkprobe_event+0x286a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10346ULL;
	}
x86_l_1489:
	/* 0x1489: lea    rdx,[r12+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_148e:
	/* 0x148e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1493:
	/* 0x1493: lea    rdi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_149b:
	/* 0x149b: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_14a0:
	/* 0x14a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14a2:
	/* 0x14a2: movzx  eax,BYTE PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 192ULL);
x86_l_14aa:
	/* 0x14aa: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14ae:
	/* 0x14ae: mov    WORD PTR [rcx+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_14b5:
	/* 0x14b5: mov    WORD PTR [rcx+0xc2],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655426ULL);
x86_l_14be:
	/* 0x14be: lea    r13,[rcx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_14c5:
	/* 0x14c5: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_14ca:
	/* 0x14ca: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14cf:
	/* 0x14cf: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14d6:
	/* 0x14d6: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_14de:
	/* 0x14de: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_14e6:
	/* 0x14e6: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_14ee:
	/* 0x14ee: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14f3:
	/* 0x14f3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14f8:
	/* 0x14f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14fa:
	/* 0x14fa: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_14fe:
	/* 0x14fe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1503:
	/* 0x1503: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1506:
	/* 0x1506: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_150b:
	/* 0x150b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_150e:
	/* 0x150e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1510:
	/* 0x1510: lea    rdx,[rbp+0xb6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_1517:
	/* 0x1517: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_151c:
	/* 0x151c: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1524:
	/* 0x1524: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1529:
	/* 0x1529: jmp    2710 <generic_retkprobe_event+0x2710> */
	return 10000ULL;
x86_l_152e:
	/* 0x152e: mov    edx,0x120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 288ULL);
x86_l_1533:
	/* 0x1533: add    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_1538:
	/* 0x1538: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_153c:
	/* 0x153c: add    rdi,0xa0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 160ULL);
x86_l_1543:
	/* 0x1543: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1548:
	/* 0x1548: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_154d:
	/* 0x154d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_154f:
	/* 0x154f: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1552:
	/* 0x1552: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1555:
	/* 0x1555: js     2870 <generic_retkprobe_event+0x2870> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10352ULL;
	}
x86_l_155b:
	/* 0x155b: lea    eax,[r13-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_155f:
	/* 0x155f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1564:
	/* 0x1564: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1566:
	/* 0x1566: add    r13,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_156a:
	/* 0x156a: jmp    2870 <generic_retkprobe_event+0x2870> */
	return 10352ULL;
x86_l_156f:
	/* 0x156f: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1574:
	/* 0x1574: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_157c:
	/* 0x157c: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1584:
	/* 0x1584: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_158b:
	/* 0x158b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1590:
	/* 0x1590: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1595:
	/* 0x1595: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1598:
	/* 0x1598: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_159b:
	/* 0x159b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_159d:
	/* 0x159d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15a0:
	/* 0x15a0: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15a4:
	/* 0x15a4: js     1e27 <generic_retkprobe_event+0x1e27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7719ULL;
	}
x86_l_15aa:
	/* 0x15aa: movzx  eax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15af:
	/* 0x15af: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_15b2:
	/* 0x15b2: je     1dd6 <generic_retkprobe_event+0x1dd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7638ULL;
	}
x86_l_15b8:
	/* 0x15b8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15bb:
	/* 0x15bb: jne    1e0e <generic_retkprobe_event+0x1e0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7694ULL;
	}
x86_l_15c1:
	/* 0x15c1: lea    rdx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_15c6:
	/* 0x15c6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15cb:
	/* 0x15cb: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15d0:
	/* 0x15d0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15d5:
	/* 0x15d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 5591ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5591ULL: goto x86_l_15d7;
	case 5595ULL: goto x86_l_15db;
	case 5599ULL: goto x86_l_15df;
	case 5606ULL: goto x86_l_15e6;
	case 5613ULL: goto x86_l_15ed;
	case 5617ULL: goto x86_l_15f1;
	case 5622ULL: goto x86_l_15f6;
	case 5627ULL: goto x86_l_15fb;
	case 5630ULL: goto x86_l_15fe;
	case 5639ULL: goto x86_l_1607;
	case 5645ULL: goto x86_l_160d;
	case 5650ULL: goto x86_l_1612;
	case 5658ULL: goto x86_l_161a;
	case 5662ULL: goto x86_l_161e;
	case 5668ULL: goto x86_l_1624;
	case 5673ULL: goto x86_l_1629;
	case 5678ULL: goto x86_l_162e;
	case 5683ULL: goto x86_l_1633;
	case 5685ULL: goto x86_l_1635;
	case 5690ULL: goto x86_l_163a;
	case 5692ULL: goto x86_l_163c;
	case 5698ULL: goto x86_l_1642;
	case 5703ULL: goto x86_l_1647;
	case 5706ULL: goto x86_l_164a;
	case 5709ULL: goto x86_l_164d;
	case 5712ULL: goto x86_l_1650;
	case 5716ULL: goto x86_l_1654;
	case 5719ULL: goto x86_l_1657;
	case 5722ULL: goto x86_l_165a;
	case 5726ULL: goto x86_l_165e;
	case 5731ULL: goto x86_l_1663;
	case 5738ULL: goto x86_l_166a;
	case 5744ULL: goto x86_l_1670;
	case 5748ULL: goto x86_l_1674;
	case 5751ULL: goto x86_l_1677;
	case 5757ULL: goto x86_l_167d;
	case 5762ULL: goto x86_l_1682;
	case 5767ULL: goto x86_l_1687;
	case 5772ULL: goto x86_l_168c;
	case 5774ULL: goto x86_l_168e;
	case 5776ULL: goto x86_l_1690;
	case 5781ULL: goto x86_l_1695;
	case 5783ULL: goto x86_l_1697;
	case 5789ULL: goto x86_l_169d;
	case 5793ULL: goto x86_l_16a1;
	case 5798ULL: goto x86_l_16a6;
	case 5801ULL: goto x86_l_16a9;
	case 5807ULL: goto x86_l_16af;
	case 5810ULL: goto x86_l_16b2;
	case 5816ULL: goto x86_l_16b8;
	case 5821ULL: goto x86_l_16bd;
	case 5824ULL: goto x86_l_16c0;
	case 5829ULL: goto x86_l_16c5;
	case 5838ULL: goto x86_l_16ce;
	case 5847ULL: goto x86_l_16d7;
	case 5853ULL: goto x86_l_16dd;
	case 5858ULL: goto x86_l_16e2;
	case 5863ULL: goto x86_l_16e7;
	case 5868ULL: goto x86_l_16ec;
	case 5873ULL: goto x86_l_16f1;
	case 5876ULL: goto x86_l_16f4;
	case 5878ULL: goto x86_l_16f6;
	case 5883ULL: goto x86_l_16fb;
	case 5889ULL: goto x86_l_1701;
	case 5895ULL: goto x86_l_1707;
	case 5900ULL: goto x86_l_170c;
	case 5904ULL: goto x86_l_1710;
	case 5909ULL: goto x86_l_1715;
	case 5916ULL: goto x86_l_171c;
	case 5921ULL: goto x86_l_1721;
	case 5924ULL: goto x86_l_1724;
	case 5927ULL: goto x86_l_1727;
	case 5930ULL: goto x86_l_172a;
	case 5932ULL: goto x86_l_172c;
	case 5937ULL: goto x86_l_1731;
	case 5939ULL: goto x86_l_1733;
	case 5941ULL: goto x86_l_1735;
	case 5946ULL: goto x86_l_173a;
	case 5953ULL: goto x86_l_1741;
	case 5957ULL: goto x86_l_1745;
	case 5962ULL: goto x86_l_174a;
	case 5964ULL: goto x86_l_174c;
	case 5967ULL: goto x86_l_174f;
	case 5972ULL: goto x86_l_1754;
	case 5978ULL: goto x86_l_175a;
	case 5983ULL: goto x86_l_175f;
	case 5990ULL: goto x86_l_1766;
	case 5997ULL: goto x86_l_176d;
	case 6001ULL: goto x86_l_1771;
	case 6006ULL: goto x86_l_1776;
	case 6011ULL: goto x86_l_177b;
	case 6016ULL: goto x86_l_1780;
	case 6018ULL: goto x86_l_1782;
	case 6022ULL: goto x86_l_1786;
	case 6029ULL: goto x86_l_178d;
	case 6033ULL: goto x86_l_1791;
	case 6038ULL: goto x86_l_1796;
	case 6043ULL: goto x86_l_179b;
	case 6045ULL: goto x86_l_179d;
	case 6049ULL: goto x86_l_17a1;
	case 6056ULL: goto x86_l_17a8;
	case 6060ULL: goto x86_l_17ac;
	case 6065ULL: goto x86_l_17b1;
	case 6070ULL: goto x86_l_17b6;
	case 6072ULL: goto x86_l_17b8;
	case 6076ULL: goto x86_l_17bc;
	case 6083ULL: goto x86_l_17c3;
	case 6087ULL: goto x86_l_17c7;
	case 6092ULL: goto x86_l_17cc;
	case 6097ULL: goto x86_l_17d1;
	case 6099ULL: goto x86_l_17d3;
	case 6103ULL: goto x86_l_17d7;
	case 6110ULL: goto x86_l_17de;
	case 6114ULL: goto x86_l_17e2;
	case 6119ULL: goto x86_l_17e7;
	case 6124ULL: goto x86_l_17ec;
	case 6126ULL: goto x86_l_17ee;
	case 6130ULL: goto x86_l_17f2;
	case 6137ULL: goto x86_l_17f9;
	case 6141ULL: goto x86_l_17fd;
	case 6146ULL: goto x86_l_1802;
	case 6151ULL: goto x86_l_1807;
	case 6153ULL: goto x86_l_1809;
	case 6157ULL: goto x86_l_180d;
	case 6164ULL: goto x86_l_1814;
	case 6168ULL: goto x86_l_1818;
	case 6173ULL: goto x86_l_181d;
	case 6178ULL: goto x86_l_1822;
	case 6180ULL: goto x86_l_1824;
	case 6184ULL: goto x86_l_1828;
	case 6191ULL: goto x86_l_182f;
	case 6195ULL: goto x86_l_1833;
	case 6200ULL: goto x86_l_1838;
	case 6205ULL: goto x86_l_183d;
	case 6207ULL: goto x86_l_183f;
	case 6211ULL: goto x86_l_1843;
	case 6221ULL: goto x86_l_184d;
	case 6225ULL: goto x86_l_1851;
	case 6232ULL: goto x86_l_1858;
	case 6236ULL: goto x86_l_185c;
	case 6241ULL: goto x86_l_1861;
	case 6246ULL: goto x86_l_1866;
	case 6248ULL: goto x86_l_1868;
	case 6252ULL: goto x86_l_186c;
	case 6259ULL: goto x86_l_1873;
	case 6263ULL: goto x86_l_1877;
	case 6268ULL: goto x86_l_187c;
	case 6273ULL: goto x86_l_1881;
	case 6275ULL: goto x86_l_1883;
	case 6279ULL: goto x86_l_1887;
	case 6286ULL: goto x86_l_188e;
	case 6290ULL: goto x86_l_1892;
	case 6295ULL: goto x86_l_1897;
	case 6300ULL: goto x86_l_189c;
	case 6302ULL: goto x86_l_189e;
	case 6306ULL: goto x86_l_18a2;
	case 6311ULL: goto x86_l_18a7;
	case 6314ULL: goto x86_l_18aa;
	case 6319ULL: goto x86_l_18af;
	case 6321ULL: goto x86_l_18b1;
	case 6328ULL: goto x86_l_18b8;
	case 6333ULL: goto x86_l_18bd;
	case 6338ULL: goto x86_l_18c2;
	case 6343ULL: goto x86_l_18c7;
	case 6346ULL: goto x86_l_18ca;
	case 6348ULL: goto x86_l_18cc;
	case 6353ULL: goto x86_l_18d1;
	case 6360ULL: goto x86_l_18d8;
	case 6365ULL: goto x86_l_18dd;
	case 6368ULL: goto x86_l_18e0;
	case 6373ULL: goto x86_l_18e5;
	case 6375ULL: goto x86_l_18e7;
	case 6379ULL: goto x86_l_18eb;
	case 6386ULL: goto x86_l_18f2;
	case 6393ULL: goto x86_l_18f9;
	case 6398ULL: goto x86_l_18fe;
	case 6403ULL: goto x86_l_1903;
	case 6405ULL: goto x86_l_1905;
	case 6409ULL: goto x86_l_1909;
	case 6416ULL: goto x86_l_1910;
	case 6423ULL: goto x86_l_1917;
	case 6428ULL: goto x86_l_191c;
	case 6433ULL: goto x86_l_1921;
	case 6435ULL: goto x86_l_1923;
	case 6439ULL: goto x86_l_1927;
	case 6446ULL: goto x86_l_192e;
	case 6453ULL: goto x86_l_1935;
	case 6458ULL: goto x86_l_193a;
	case 6463ULL: goto x86_l_193f;
	case 6466ULL: goto x86_l_1942;
	case 6468ULL: goto x86_l_1944;
	case 6472ULL: goto x86_l_1948;
	case 6478ULL: goto x86_l_194e;
	case 6483ULL: goto x86_l_1953;
	case 6490ULL: goto x86_l_195a;
	case 6495ULL: goto x86_l_195f;
	case 6500ULL: goto x86_l_1964;
	case 6505ULL: goto x86_l_1969;
	case 6507ULL: goto x86_l_196b;
	case 6511ULL: goto x86_l_196f;
	case 6518ULL: goto x86_l_1976;
	case 6525ULL: goto x86_l_197d;
	case 6530ULL: goto x86_l_1982;
	case 6535ULL: goto x86_l_1987;
	case 6537ULL: goto x86_l_1989;
	case 6541ULL: goto x86_l_198d;
	case 6548ULL: goto x86_l_1994;
	case 6555ULL: goto x86_l_199b;
	case 6560ULL: goto x86_l_19a0;
	case 6565ULL: goto x86_l_19a5;
	case 6567ULL: goto x86_l_19a7;
	case 6571ULL: goto x86_l_19ab;
	case 6578ULL: goto x86_l_19b2;
	case 6585ULL: goto x86_l_19b9;
	case 6590ULL: goto x86_l_19be;
	case 6595ULL: goto x86_l_19c3;
	case 6598ULL: goto x86_l_19c6;
	case 6600ULL: goto x86_l_19c8;
	case 6604ULL: goto x86_l_19cc;
	case 6610ULL: goto x86_l_19d2;
	case 6615ULL: goto x86_l_19d7;
	case 6619ULL: goto x86_l_19db;
	case 6624ULL: goto x86_l_19e0;
	case 6629ULL: goto x86_l_19e5;
	case 6634ULL: goto x86_l_19ea;
	case 6636ULL: goto x86_l_19ec;
	case 6640ULL: goto x86_l_19f0;
	case 6647ULL: goto x86_l_19f7;
	case 6651ULL: goto x86_l_19fb;
	case 6656ULL: goto x86_l_1a00;
	case 6661ULL: goto x86_l_1a05;
	case 6663ULL: goto x86_l_1a07;
	case 6667ULL: goto x86_l_1a0b;
	case 6674ULL: goto x86_l_1a12;
	case 6678ULL: goto x86_l_1a16;
	case 6683ULL: goto x86_l_1a1b;
	case 6688ULL: goto x86_l_1a20;
	case 6690ULL: goto x86_l_1a22;
	case 6694ULL: goto x86_l_1a26;
	case 6701ULL: goto x86_l_1a2d;
	case 6705ULL: goto x86_l_1a31;
	case 6710ULL: goto x86_l_1a36;
	case 6715ULL: goto x86_l_1a3b;
	case 6717ULL: goto x86_l_1a3d;
	case 6721ULL: goto x86_l_1a41;
	case 6728ULL: goto x86_l_1a48;
	case 6732ULL: goto x86_l_1a4c;
	case 6737ULL: goto x86_l_1a51;
	case 6742ULL: goto x86_l_1a56;
	case 6745ULL: goto x86_l_1a59;
	case 6747ULL: goto x86_l_1a5b;
	case 6751ULL: goto x86_l_1a5f;
	case 6757ULL: goto x86_l_1a65;
	case 6762ULL: goto x86_l_1a6a;
	case 6767ULL: goto x86_l_1a6f;
	case 6772ULL: goto x86_l_1a74;
	case 6777ULL: goto x86_l_1a79;
	case 6780ULL: goto x86_l_1a7c;
	case 6782ULL: goto x86_l_1a7e;
	case 6786ULL: goto x86_l_1a82;
	case 6793ULL: goto x86_l_1a89;
	case 6797ULL: goto x86_l_1a8d;
	case 6802ULL: goto x86_l_1a92;
	case 6807ULL: goto x86_l_1a97;
	case 6809ULL: goto x86_l_1a99;
	case 6813ULL: goto x86_l_1a9d;
	case 6820ULL: goto x86_l_1aa4;
	case 6824ULL: goto x86_l_1aa8;
	case 6829ULL: goto x86_l_1aad;
	case 6834ULL: goto x86_l_1ab2;
	case 6837ULL: goto x86_l_1ab5;
	case 6842ULL: goto x86_l_1aba;
	case 6846ULL: goto x86_l_1abe;
	case 6851ULL: goto x86_l_1ac3;
	case 6856ULL: goto x86_l_1ac8;
	case 6861ULL: goto x86_l_1acd;
	case 6863ULL: goto x86_l_1acf;
	case 6867ULL: goto x86_l_1ad3;
	case 6871ULL: goto x86_l_1ad7;
	case 6877ULL: goto x86_l_1add;
	case 6881ULL: goto x86_l_1ae1;
	case 6886ULL: goto x86_l_1ae6;
	case 6891ULL: goto x86_l_1aeb;
	case 6896ULL: goto x86_l_1af0;
	case 6898ULL: goto x86_l_1af2;
	case 6902ULL: goto x86_l_1af6;
	case 6906ULL: goto x86_l_1afa;
	case 6912ULL: goto x86_l_1b00;
	case 6916ULL: goto x86_l_1b04;
	case 6921ULL: goto x86_l_1b09;
	case 6926ULL: goto x86_l_1b0e;
	case 6931ULL: goto x86_l_1b13;
	case 6934ULL: goto x86_l_1b16;
	case 6936ULL: goto x86_l_1b18;
	case 6940ULL: goto x86_l_1b1c;
	case 6947ULL: goto x86_l_1b23;
	case 6952ULL: goto x86_l_1b28;
	case 6957ULL: goto x86_l_1b2d;
	case 6962ULL: goto x86_l_1b32;
	case 6967ULL: goto x86_l_1b37;
	case 6969ULL: goto x86_l_1b39;
	case 6973ULL: goto x86_l_1b3d;
	case 6979ULL: goto x86_l_1b43;
	case 6984ULL: goto x86_l_1b48;
	case 6989ULL: goto x86_l_1b4d;
	case 6997ULL: goto x86_l_1b55;
	case 7005ULL: goto x86_l_1b5d;
	case 7013ULL: goto x86_l_1b65;
	case 7021ULL: goto x86_l_1b6d;
	case 7029ULL: goto x86_l_1b75;
	case 7037ULL: goto x86_l_1b7d;
	case 7045ULL: goto x86_l_1b85;
	case 7053ULL: goto x86_l_1b8d;
	case 7061ULL: goto x86_l_1b95;
	case 7064ULL: goto x86_l_1b98;
	case 7071ULL: goto x86_l_1b9f;
	case 7076ULL: goto x86_l_1ba4;
	case 7081ULL: goto x86_l_1ba9;
	case 7086ULL: goto x86_l_1bae;
	case 7089ULL: goto x86_l_1bb1;
	case 7091ULL: goto x86_l_1bb3;
	case 7094ULL: goto x86_l_1bb6;
	case 7100ULL: goto x86_l_1bbc;
	case 7103ULL: goto x86_l_1bbf;
	case 7108ULL: goto x86_l_1bc4;
	case 7115ULL: goto x86_l_1bcb;
	case 7120ULL: goto x86_l_1bd0;
	case 7125ULL: goto x86_l_1bd5;
	case 7131ULL: goto x86_l_1bdb;
	case 7136ULL: goto x86_l_1be0;
	case 7141ULL: goto x86_l_1be5;
	case 7146ULL: goto x86_l_1bea;
	case 7148ULL: goto x86_l_1bec;
	case 7152ULL: goto x86_l_1bf0;
	case 7157ULL: goto x86_l_1bf5;
	case 7165ULL: goto x86_l_1bfd;
	case 7170ULL: goto x86_l_1c02;
	case 7173ULL: goto x86_l_1c05;
	case 7175ULL: goto x86_l_1c07;
	case 7180ULL: goto x86_l_1c0c;
	case 7188ULL: goto x86_l_1c14;
	case 7195ULL: goto x86_l_1c1b;
	case 7201ULL: goto x86_l_1c21;
	case 7205ULL: goto x86_l_1c25;
	case 7208ULL: goto x86_l_1c28;
	case 7215ULL: goto x86_l_1c2f;
	case 7220ULL: goto x86_l_1c34;
	case 7223ULL: goto x86_l_1c37;
	case 7225ULL: goto x86_l_1c39;
	case 7227ULL: goto x86_l_1c3b;
	case 7229ULL: goto x86_l_1c3d;
	case 7235ULL: goto x86_l_1c43;
	case 7242ULL: goto x86_l_1c4a;
	case 7246ULL: goto x86_l_1c4e;
	case 7249ULL: goto x86_l_1c51;
	case 7254ULL: goto x86_l_1c56;
	case 7264ULL: goto x86_l_1c60;
	case 7269ULL: goto x86_l_1c65;
	case 7274ULL: goto x86_l_1c6a;
	case 7282ULL: goto x86_l_1c72;
	case 7287ULL: goto x86_l_1c77;
	case 7291ULL: goto x86_l_1c7b;
	case 7299ULL: goto x86_l_1c83;
	case 7304ULL: goto x86_l_1c88;
	case 7311ULL: goto x86_l_1c8f;
	case 7316ULL: goto x86_l_1c94;
	case 7318ULL: goto x86_l_1c96;
	case 7321ULL: goto x86_l_1c99;
	case 7327ULL: goto x86_l_1c9f;
	case 7330ULL: goto x86_l_1ca2;
	case 7333ULL: goto x86_l_1ca5;
	case 7337ULL: goto x86_l_1ca9;
	case 7341ULL: goto x86_l_1cad;
	case 7344ULL: goto x86_l_1cb0;
	case 7348ULL: goto x86_l_1cb4;
	case 7353ULL: goto x86_l_1cb9;
	case 7358ULL: goto x86_l_1cbe;
	case 7361ULL: goto x86_l_1cc1;
	case 7366ULL: goto x86_l_1cc6;
	case 7368ULL: goto x86_l_1cc8;
	case 7371ULL: goto x86_l_1ccb;
	case 7377ULL: goto x86_l_1cd1;
	case 7382ULL: goto x86_l_1cd6;
	case 7385ULL: goto x86_l_1cd9;
	default: return 0xffffffffffffffffULL;
	}
x86_l_15d7:
	/* 0x15d7: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15db:
	/* 0x15db: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15df:
	/* 0x15df: mov    QWORD PTR [rdi+0xa4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_15e6:
	/* 0x15e6: add    rdi,0x9e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 158ULL);
x86_l_15ed:
	/* 0x15ed: add    r12,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_15f1:
	/* 0x15f1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15f6:
	/* 0x15f6: jmp    1e04 <generic_retkprobe_event+0x1e04> */
	return 7684ULL;
x86_l_15fb:
	/* 0x15fb: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15fe:
	/* 0x15fe: cmp    QWORD PTR [rsp+0x80],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813891ULL);
x86_l_1607:
	/* 0x1607: jb     16bd <generic_retkprobe_event+0x16bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_16bd;
	}
x86_l_160d:
	/* 0x160d: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1612:
	/* 0x1612: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_161a:
	/* 0x161a: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_161e:
	/* 0x161e: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1624:
	/* 0x1624: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1629:
	/* 0x1629: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_162e:
	/* 0x162e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1633:
	/* 0x1633: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1635:
	/* 0x1635: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_163a:
	/* 0x163a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_163c:
	/* 0x163c: js     2adb <generic_retkprobe_event+0x2adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10971ULL;
	}
x86_l_1642:
	/* 0x1642: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1647:
	/* 0x1647: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_164a:
	/* 0x164a: cmp    rbp,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_164d:
	/* 0x164d: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_1650:
	/* 0x1650: cmovb  rcx,rbp */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBP, X86_WIDTH_64, X86_CC_B);
x86_l_1654:
	/* 0x1654: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1657:
	/* 0x1657: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_165a:
	/* 0x165a: cmovne rbp,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_64, X86_CC_NE);
x86_l_165e:
	/* 0x165e: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_1663:
	/* 0x1663: cmp    rbp,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4094ULL);
x86_l_166a:
	/* 0x166a: ja     2adb <generic_retkprobe_event+0x2adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10971ULL;
	}
x86_l_1670:
	/* 0x1670: add    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1674:
	/* 0x1674: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_1677:
	/* 0x1677: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_167d:
	/* 0x167d: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1682:
	/* 0x1682: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1687:
	/* 0x1687: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_168c:
	/* 0x168c: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_168e:
	/* 0x168e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1690:
	/* 0x1690: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1695:
	/* 0x1695: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1697:
	/* 0x1697: js     2adb <generic_retkprobe_event+0x2adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10971ULL;
	}
x86_l_169d:
	/* 0x169d: mov    QWORD PTR [rsp],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16a1:
	/* 0x16a1: add    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_16a6:
	/* 0x16a6: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_16a9:
	/* 0x16a9: je     2031 <generic_retkprobe_event+0x2031> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8241ULL;
	}
x86_l_16af:
	/* 0x16af: sub    r15,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_16b2:
	/* 0x16b2: jne    2034 <generic_retkprobe_event+0x2034> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8244ULL;
	}
x86_l_16b8:
	/* 0x16b8: jmp    203f <generic_retkprobe_event+0x203f> */
	return 8255ULL;
x86_l_16bd:
	/* 0x16bd: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_16c0:
	/* 0x16c0: jmp    349 <generic_retkprobe_event+0x349> */
	return 841ULL;
x86_l_16c5:
	/* 0x16c5: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_16ce:
	/* 0x16ce: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_16d7:
	/* 0x16d7: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_16dd:
	/* 0x16dd: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_16e2:
	/* 0x16e2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16e7:
	/* 0x16e7: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16ec:
	/* 0x16ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16f1:
	/* 0x16f1: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_16f4:
	/* 0x16f4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_16f6:
	/* 0x16f6: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16fb:
	/* 0x16fb: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_1701:
	/* 0x1701: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_1707:
	/* 0x1707: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_170c:
	/* 0x170c: cmovb  r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_B);
x86_l_1710:
	/* 0x1710: mov    QWORD PTR [rsp+0x20],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1715:
	/* 0x1715: add    rbx,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_171c:
	/* 0x171c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1721:
	/* 0x1721: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1724:
	/* 0x1724: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_1727:
	/* 0x1727: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_172a:
	/* 0x172a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_172c:
	/* 0x172c: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1731:
	/* 0x1731: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1733:
	/* 0x1733: js     174f <generic_retkprobe_event+0x174f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_174f;
	}
x86_l_1735:
	/* 0x1735: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_173a:
	/* 0x173a: mov    DWORD PTR [rax+0xa0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1741:
	/* 0x1741: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1745:
	/* 0x1745: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_174a:
	/* 0x174a: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_174c:
	/* 0x174c: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_174f:
	/* 0x174f: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1754:
	/* 0x1754: mov    DWORD PTR [rax+0x9c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_175a:
	/* 0x175a: jmp    1fc7 <generic_retkprobe_event+0x1fc7> */
	return 8135ULL;
x86_l_175f:
	/* 0x175f: lea    r13,[rcx+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1766:
	/* 0x1766: lea    r12,[rcx+0xdc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_176d:
	/* 0x176d: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1771:
	/* 0x1771: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1776:
	/* 0x1776: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_177b:
	/* 0x177b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1780:
	/* 0x1780: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1782:
	/* 0x1782: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1786:
	/* 0x1786: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_178d:
	/* 0x178d: lea    rdx,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1791:
	/* 0x1791: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1796:
	/* 0x1796: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_179b:
	/* 0x179b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_179d:
	/* 0x179d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17a1:
	/* 0x17a1: lea    rdi,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_17a8:
	/* 0x17a8: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17ac:
	/* 0x17ac: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17b1:
	/* 0x17b1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17b6:
	/* 0x17b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17b8:
	/* 0x17b8: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17bc:
	/* 0x17bc: lea    rdi,[rax+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_17c3:
	/* 0x17c3: lea    rdx,[rbp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_17c7:
	/* 0x17c7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17cc:
	/* 0x17cc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17d1:
	/* 0x17d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17d3:
	/* 0x17d3: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17d7:
	/* 0x17d7: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_17de:
	/* 0x17de: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17e2:
	/* 0x17e2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17e7:
	/* 0x17e7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17ec:
	/* 0x17ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ee:
	/* 0x17ee: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17f2:
	/* 0x17f2: lea    rdi,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_17f9:
	/* 0x17f9: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_17fd:
	/* 0x17fd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1802:
	/* 0x1802: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1807:
	/* 0x1807: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1809:
	/* 0x1809: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_180d:
	/* 0x180d: lea    rdi,[rax+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_1814:
	/* 0x1814: lea    rdx,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1818:
	/* 0x1818: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_181d:
	/* 0x181d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1822:
	/* 0x1822: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1824:
	/* 0x1824: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1828:
	/* 0x1828: lea    rdi,[rax+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_182f:
	/* 0x182f: lea    rdx,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1833:
	/* 0x1833: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1838:
	/* 0x1838: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_183d:
	/* 0x183d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_183f:
	/* 0x183f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1843:
	/* 0x1843: mov    DWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_184d:
	/* 0x184d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1851:
	/* 0x1851: lea    rdi,[rax+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1858:
	/* 0x1858: lea    rdx,[rbp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_185c:
	/* 0x185c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1861:
	/* 0x1861: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1866:
	/* 0x1866: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1868:
	/* 0x1868: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_186c:
	/* 0x186c: lea    rdi,[rax+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1873:
	/* 0x1873: lea    rdx,[rbp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1877:
	/* 0x1877: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_187c:
	/* 0x187c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1881:
	/* 0x1881: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1883:
	/* 0x1883: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1887:
	/* 0x1887: lea    rdi,[rax+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_188e:
	/* 0x188e: lea    rdx,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1892:
	/* 0x1892: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1897:
	/* 0x1897: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_189c:
	/* 0x189c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_189e:
	/* 0x189e: lea    rdx,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18a2:
	/* 0x18a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18a7:
	/* 0x18a7: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_18aa:
	/* 0x18aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18af:
	/* 0x18af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b1:
	/* 0x18b1: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_18b8:
	/* 0x18b8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18bd:
	/* 0x18bd: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18c2:
	/* 0x18c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18c7:
	/* 0x18c7: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_18ca:
	/* 0x18ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18cc:
	/* 0x18cc: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18d1:
	/* 0x18d1: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_18d8:
	/* 0x18d8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18dd:
	/* 0x18dd: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_18e0:
	/* 0x18e0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18e5:
	/* 0x18e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e7:
	/* 0x18e7: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18eb:
	/* 0x18eb: lea    rdi,[rax+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_18f2:
	/* 0x18f2: lea    rdx,[r13+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_18f9:
	/* 0x18f9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18fe:
	/* 0x18fe: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1903:
	/* 0x1903: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1905:
	/* 0x1905: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1909:
	/* 0x1909: lea    rdi,[rax+0xe4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_1910:
	/* 0x1910: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1917:
	/* 0x1917: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_191c:
	/* 0x191c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1921:
	/* 0x1921: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1923:
	/* 0x1923: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1927:
	/* 0x1927: add    rdi,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_192e:
	/* 0x192e: add    r13,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1935:
	/* 0x1935: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_193a:
	/* 0x193a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_193f:
	/* 0x193f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1942:
	/* 0x1942: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1944:
	/* 0x1944: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1948:
	/* 0x1948: mov    r13d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 80ULL);
x86_l_194e:
	/* 0x194e: jmp    2874 <generic_retkprobe_event+0x2874> */
	return 10356ULL;
x86_l_1953:
	/* 0x1953: lea    rdx,[rbp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_195a:
	/* 0x195a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_195f:
	/* 0x195f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1964:
	/* 0x1964: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1969:
	/* 0x1969: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_196b:
	/* 0x196b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_196f:
	/* 0x196f: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1976:
	/* 0x1976: lea    rdx,[rbp+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_197d:
	/* 0x197d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1982:
	/* 0x1982: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1987:
	/* 0x1987: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1989:
	/* 0x1989: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_198d:
	/* 0x198d: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1994:
	/* 0x1994: lea    rdx,[rbp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_199b:
	/* 0x199b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19a0:
	/* 0x19a0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19a5:
	/* 0x19a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19a7:
	/* 0x19a7: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19ab:
	/* 0x19ab: add    rdi,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_19b2:
	/* 0x19b2: add    rbp,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_19b9:
	/* 0x19b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19be:
	/* 0x19be: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19c3:
	/* 0x19c3: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_19c6:
	/* 0x19c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19c8:
	/* 0x19c8: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19cc:
	/* 0x19cc: mov    r13d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 16ULL);
x86_l_19d2:
	/* 0x19d2: jmp    2874 <generic_retkprobe_event+0x2874> */
	return 10356ULL;
x86_l_19d7:
	/* 0x19d7: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19db:
	/* 0x19db: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19e0:
	/* 0x19e0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19e5:
	/* 0x19e5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19ea:
	/* 0x19ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19ec:
	/* 0x19ec: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19f0:
	/* 0x19f0: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_19f7:
	/* 0x19f7: lea    rdx,[rbp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_19fb:
	/* 0x19fb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a00:
	/* 0x1a00: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a05:
	/* 0x1a05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a07:
	/* 0x1a07: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a0b:
	/* 0x1a0b: lea    rdi,[rax+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1a12:
	/* 0x1a12: lea    rdx,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a16:
	/* 0x1a16: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a1b:
	/* 0x1a1b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a20:
	/* 0x1a20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a22:
	/* 0x1a22: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a26:
	/* 0x1a26: lea    rdi,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1a2d:
	/* 0x1a2d: lea    rdx,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
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
	/* 0x1a3d: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a41:
	/* 0x1a41: add    rdi,0xac */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 172ULL);
x86_l_1a48:
	/* 0x1a48: add    rbp,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1a4c:
	/* 0x1a4c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a51:
	/* 0x1a51: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1a56:
	/* 0x1a56: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1a59:
	/* 0x1a59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a5b:
	/* 0x1a5b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a5f:
	/* 0x1a5f: mov    r13d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 32ULL);
x86_l_1a65:
	/* 0x1a65: jmp    2874 <generic_retkprobe_event+0x2874> */
	return 10356ULL;
x86_l_1a6a:
	/* 0x1a6a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a6f:
	/* 0x1a6f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a74:
	/* 0x1a74: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a79:
	/* 0x1a79: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1a7c:
	/* 0x1a7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a7e:
	/* 0x1a7e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a82:
	/* 0x1a82: lea    rdi,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1a89:
	/* 0x1a89: lea    rdx,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a8d:
	/* 0x1a8d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a92:
	/* 0x1a92: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a97:
	/* 0x1a97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a99:
	/* 0x1a99: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a9d:
	/* 0x1a9d: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1aa4:
	/* 0x1aa4: add    rbp,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_1aa8:
	/* 0x1aa8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1aad:
	/* 0x1aad: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1ab2:
	/* 0x1ab2: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1ab5:
	/* 0x1ab5: jmp    1b37 <generic_retkprobe_event+0x1b37> */
	goto x86_l_1b37;
x86_l_1aba:
	/* 0x1aba: lea    rdx,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1abe:
	/* 0x1abe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ac3:
	/* 0x1ac3: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ac8:
	/* 0x1ac8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1acd:
	/* 0x1acd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1acf:
	/* 0x1acf: mov    ecx,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ad3:
	/* 0x1ad3: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ad7:
	/* 0x1ad7: mov    DWORD PTR [rax+0x9c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1add:
	/* 0x1add: lea    rdx,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ae1:
	/* 0x1ae1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ae6:
	/* 0x1ae6: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1aeb:
	/* 0x1aeb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1af0:
	/* 0x1af0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1af2:
	/* 0x1af2: mov    ecx,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1af6:
	/* 0x1af6: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1afa:
	/* 0x1afa: mov    DWORD PTR [rax+0xa0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1b00:
	/* 0x1b00: add    rbp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_1b04:
	/* 0x1b04: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b09:
	/* 0x1b09: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b0e:
	/* 0x1b0e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b13:
	/* 0x1b13: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1b16:
	/* 0x1b16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b18:
	/* 0x1b18: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b1c:
	/* 0x1b1c: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1b23:
	/* 0x1b23: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1b28:
	/* 0x1b28: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_1b2d:
	/* 0x1b2d: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_1b32:
	/* 0x1b32: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b37:
	/* 0x1b37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b39:
	/* 0x1b39: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b3d:
	/* 0x1b3d: mov    r13d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 24ULL);
x86_l_1b43:
	/* 0x1b43: jmp    2874 <generic_retkprobe_event+0x2874> */
	return 10356ULL;
x86_l_1b48:
	/* 0x1b48: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b4d:
	/* 0x1b4d: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1b55:
	/* 0x1b55: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1b5d:
	/* 0x1b5d: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1b65:
	/* 0x1b65: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1b6d:
	/* 0x1b6d: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1b75:
	/* 0x1b75: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1b7d:
	/* 0x1b7d: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1b85:
	/* 0x1b85: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1b8d:
	/* 0x1b8d: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1b95:
	/* 0x1b95: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1b98:
	/* 0x1b98: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b9f:
	/* 0x1b9f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ba4:
	/* 0x1ba4: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ba9:
	/* 0x1ba9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bae:
	/* 0x1bae: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1bb1:
	/* 0x1bb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bb3:
	/* 0x1bb3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bb6:
	/* 0x1bb6: je     1e32 <generic_retkprobe_event+0x1e32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7730ULL;
	}
x86_l_1bbc:
	/* 0x1bbc: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bbf:
	/* 0x1bbf: jmp    1fc7 <generic_retkprobe_event+0x1fc7> */
	return 8135ULL;
x86_l_1bc4:
	/* 0x1bc4: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1bcb:
	/* 0x1bcb: jmp    2870 <generic_retkprobe_event+0x2870> */
	return 10352ULL;
x86_l_1bd0:
	/* 0x1bd0: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bd5:
	/* 0x1bd5: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_1bdb:
	/* 0x1bdb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1be0:
	/* 0x1be0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1be5:
	/* 0x1be5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bea:
	/* 0x1bea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bec:
	/* 0x1bec: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1bf0:
	/* 0x1bf0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bf5:
	/* 0x1bf5: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1bfd:
	/* 0x1bfd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c02:
	/* 0x1c02: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1c05:
	/* 0x1c05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c07:
	/* 0x1c07: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c0c:
	/* 0x1c0c: mov    rbp,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1c14:
	/* 0x1c14: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_1c1b:
	/* 0x1c1b: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_1c21:
	/* 0x1c21: cmovb  r12,rbp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_64, X86_CC_B);
x86_l_1c25:
	/* 0x1c25: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1c28:
	/* 0x1c28: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1c2f:
	/* 0x1c2f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c34:
	/* 0x1c34: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_1c37:
	/* 0x1c37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c39:
	/* 0x1c39: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c3b:
	/* 0x1c3b: js     1c56 <generic_retkprobe_event+0x1c56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1c56;
	}
x86_l_1c3d:
	/* 0x1c3d: mov    DWORD PTR [rbx+0x9c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1c43:
	/* 0x1c43: mov    DWORD PTR [rbx+0xa0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1c4a:
	/* 0x1c4a: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1c4e:
	/* 0x1c4e: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_1c51:
	/* 0x1c51: jmp    1dc8 <generic_retkprobe_event+0x1dc8> */
	return 7624ULL;
x86_l_1c56:
	/* 0x1c56: mov    DWORD PTR [rbx+0x9c],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 674309865470ULL);
x86_l_1c60:
	/* 0x1c60: jmp    1dc8 <generic_retkprobe_event+0x1dc8> */
	return 7624ULL;
x86_l_1c65:
	/* 0x1c65: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1c6a:
	/* 0x1c6a: movzx  ebx,WORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_1c72:
	/* 0x1c72: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c77:
	/* 0x1c77: lea    r12,[rax+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_1c7b:
	/* 0x1c7b: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1c83:
	/* 0x1c83: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c88:
	/* 0x1c88: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_1c8f:
	/* 0x1c8f: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c94:
	/* 0x1c94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c96:
	/* 0x1c96: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c99:
	/* 0x1c99: je     26c2 <generic_retkprobe_event+0x26c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9922ULL;
	}
x86_l_1c9f:
	/* 0x1c9f: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1ca2:
	/* 0x1ca2: mov    WORD PTR [rax],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ca5:
	/* 0x1ca5: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_1ca9:
	/* 0x1ca9: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_1cad:
	/* 0x1cad: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1cb0:
	/* 0x1cb0: add    rdi,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_1cb4:
	/* 0x1cb4: lea    rdx,[r12+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1cb9:
	/* 0x1cb9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cbe:
	/* 0x1cbe: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_1cc1:
	/* 0x1cc1: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1cc6:
	/* 0x1cc6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cc8:
	/* 0x1cc8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ccb:
	/* 0x1ccb: js     26c2 <generic_retkprobe_event+0x26c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9922ULL;
	}
x86_l_1cd1:
	/* 0x1cd1: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_1cd6:
	/* 0x1cd6: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_1cd9:
	/* 0x1cd9: jg     1ff7 <generic_retkprobe_event+0x1ff7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8183ULL;
	}
	return 7391ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7391ULL: goto x86_l_1cdf;
	case 7393ULL: goto x86_l_1ce1;
	case 7399ULL: goto x86_l_1ce7;
	case 7402ULL: goto x86_l_1cea;
	case 7408ULL: goto x86_l_1cf0;
	case 7411ULL: goto x86_l_1cf3;
	case 7417ULL: goto x86_l_1cf9;
	case 7424ULL: goto x86_l_1d00;
	case 7428ULL: goto x86_l_1d04;
	case 7433ULL: goto x86_l_1d09;
	case 7438ULL: goto x86_l_1d0e;
	case 7443ULL: goto x86_l_1d13;
	case 7448ULL: goto x86_l_1d18;
	case 7450ULL: goto x86_l_1d1a;
	case 7455ULL: goto x86_l_1d1f;
	case 7460ULL: goto x86_l_1d24;
	case 7463ULL: goto x86_l_1d27;
	case 7468ULL: goto x86_l_1d2c;
	case 7470ULL: goto x86_l_1d2e;
	case 7474ULL: goto x86_l_1d32;
	case 7481ULL: goto x86_l_1d39;
	case 7486ULL: goto x86_l_1d3e;
	case 7490ULL: goto x86_l_1d42;
	case 7495ULL: goto x86_l_1d47;
	case 7500ULL: goto x86_l_1d4c;
	case 7503ULL: goto x86_l_1d4f;
	case 7505ULL: goto x86_l_1d51;
	case 7508ULL: goto x86_l_1d54;
	case 7515ULL: goto x86_l_1d5b;
	case 7520ULL: goto x86_l_1d60;
	case 7525ULL: goto x86_l_1d65;
	case 7528ULL: goto x86_l_1d68;
	case 7530ULL: goto x86_l_1d6a;
	case 7537ULL: goto x86_l_1d71;
	case 7546ULL: goto x86_l_1d7a;
	case 7551ULL: goto x86_l_1d7f;
	case 7556ULL: goto x86_l_1d84;
	case 7561ULL: goto x86_l_1d89;
	case 7568ULL: goto x86_l_1d90;
	case 7573ULL: goto x86_l_1d95;
	case 7575ULL: goto x86_l_1d97;
	case 7578ULL: goto x86_l_1d9a;
	case 7580ULL: goto x86_l_1d9c;
	case 7582ULL: goto x86_l_1d9e;
	case 7585ULL: goto x86_l_1da1;
	case 7589ULL: goto x86_l_1da5;
	case 7593ULL: goto x86_l_1da9;
	case 7596ULL: goto x86_l_1dac;
	case 7599ULL: goto x86_l_1daf;
	case 7605ULL: goto x86_l_1db5;
	case 7607ULL: goto x86_l_1db7;
	case 7618ULL: goto x86_l_1dc2;
	case 7624ULL: goto x86_l_1dc8;
	case 7628ULL: goto x86_l_1dcc;
	case 7633ULL: goto x86_l_1dd1;
	case 7638ULL: goto x86_l_1dd6;
	case 7645ULL: goto x86_l_1ddd;
	case 7650ULL: goto x86_l_1de2;
	case 7655ULL: goto x86_l_1de7;
	case 7660ULL: goto x86_l_1dec;
	case 7663ULL: goto x86_l_1def;
	case 7665ULL: goto x86_l_1df1;
	case 7668ULL: goto x86_l_1df4;
	case 7675ULL: goto x86_l_1dfb;
	case 7679ULL: goto x86_l_1dff;
	case 7684ULL: goto x86_l_1e04;
	case 7689ULL: goto x86_l_1e09;
	case 7692ULL: goto x86_l_1e0c;
	case 7694ULL: goto x86_l_1e0e;
	case 7698ULL: goto x86_l_1e12;
	case 7705ULL: goto x86_l_1e19;
	case 7714ULL: goto x86_l_1e22;
	case 7719ULL: goto x86_l_1e27;
	case 7725ULL: goto x86_l_1e2d;
	case 7730ULL: goto x86_l_1e32;
	case 7734ULL: goto x86_l_1e36;
	case 7741ULL: goto x86_l_1e3d;
	case 7746ULL: goto x86_l_1e42;
	case 7751ULL: goto x86_l_1e47;
	case 7756ULL: goto x86_l_1e4c;
	case 7758ULL: goto x86_l_1e4e;
	case 7761ULL: goto x86_l_1e51;
	case 7767ULL: goto x86_l_1e57;
	case 7771ULL: goto x86_l_1e5b;
	case 7776ULL: goto x86_l_1e60;
	case 7781ULL: goto x86_l_1e65;
	case 7786ULL: goto x86_l_1e6a;
	case 7788ULL: goto x86_l_1e6c;
	case 7792ULL: goto x86_l_1e70;
	case 7799ULL: goto x86_l_1e77;
	case 7804ULL: goto x86_l_1e7c;
	case 7809ULL: goto x86_l_1e81;
	case 7814ULL: goto x86_l_1e86;
	case 7819ULL: goto x86_l_1e8b;
	case 7821ULL: goto x86_l_1e8d;
	case 7825ULL: goto x86_l_1e91;
	case 7830ULL: goto x86_l_1e96;
	case 7835ULL: goto x86_l_1e9b;
	case 7840ULL: goto x86_l_1ea0;
	case 7843ULL: goto x86_l_1ea3;
	case 7845ULL: goto x86_l_1ea5;
	case 7851ULL: goto x86_l_1eab;
	case 7854ULL: goto x86_l_1eae;
	case 7860ULL: goto x86_l_1eb4;
	case 7862ULL: goto x86_l_1eb6;
	case 7867ULL: goto x86_l_1ebb;
	case 7870ULL: goto x86_l_1ebe;
	case 7872ULL: goto x86_l_1ec0;
	case 7877ULL: goto x86_l_1ec5;
	case 7880ULL: goto x86_l_1ec8;
	case 7884ULL: goto x86_l_1ecc;
	case 7889ULL: goto x86_l_1ed1;
	case 7892ULL: goto x86_l_1ed4;
	case 7898ULL: goto x86_l_1eda;
	case 7903ULL: goto x86_l_1edf;
	case 7907ULL: goto x86_l_1ee3;
	case 7912ULL: goto x86_l_1ee8;
	case 7917ULL: goto x86_l_1eed;
	case 7920ULL: goto x86_l_1ef0;
	case 7922ULL: goto x86_l_1ef2;
	case 7925ULL: goto x86_l_1ef5;
	case 7927ULL: goto x86_l_1ef7;
	case 7929ULL: goto x86_l_1ef9;
	case 7931ULL: goto x86_l_1efb;
	case 7935ULL: goto x86_l_1eff;
	case 7941ULL: goto x86_l_1f05;
	case 7947ULL: goto x86_l_1f0b;
	case 7952ULL: goto x86_l_1f10;
	case 7957ULL: goto x86_l_1f15;
	case 7962ULL: goto x86_l_1f1a;
	case 7967ULL: goto x86_l_1f1f;
	case 7969ULL: goto x86_l_1f21;
	case 7974ULL: goto x86_l_1f26;
	case 7979ULL: goto x86_l_1f2b;
	case 7982ULL: goto x86_l_1f2e;
	case 7987ULL: goto x86_l_1f33;
	case 7989ULL: goto x86_l_1f35;
	case 7993ULL: goto x86_l_1f39;
	case 8000ULL: goto x86_l_1f40;
	case 8005ULL: goto x86_l_1f45;
	case 8009ULL: goto x86_l_1f49;
	case 8014ULL: goto x86_l_1f4e;
	case 8019ULL: goto x86_l_1f53;
	case 8022ULL: goto x86_l_1f56;
	case 8024ULL: goto x86_l_1f58;
	case 8027ULL: goto x86_l_1f5b;
	case 8034ULL: goto x86_l_1f62;
	case 8039ULL: goto x86_l_1f67;
	case 8044ULL: goto x86_l_1f6c;
	case 8047ULL: goto x86_l_1f6f;
	case 8049ULL: goto x86_l_1f71;
	case 8056ULL: goto x86_l_1f78;
	case 8065ULL: goto x86_l_1f81;
	case 8069ULL: goto x86_l_1f85;
	case 8076ULL: goto x86_l_1f8c;
	case 8081ULL: goto x86_l_1f91;
	case 8086ULL: goto x86_l_1f96;
	case 8093ULL: goto x86_l_1f9d;
	case 8098ULL: goto x86_l_1fa2;
	case 8100ULL: goto x86_l_1fa4;
	case 8103ULL: goto x86_l_1fa7;
	case 8105ULL: goto x86_l_1fa9;
	case 8107ULL: goto x86_l_1fab;
	case 8112ULL: goto x86_l_1fb0;
	case 8115ULL: goto x86_l_1fb3;
	case 8119ULL: goto x86_l_1fb7;
	case 8123ULL: goto x86_l_1fbb;
	case 8126ULL: goto x86_l_1fbe;
	case 8129ULL: goto x86_l_1fc1;
	case 8135ULL: goto x86_l_1fc7;
	case 8139ULL: goto x86_l_1fcb;
	case 8144ULL: goto x86_l_1fd0;
	case 8149ULL: goto x86_l_1fd5;
	case 8152ULL: goto x86_l_1fd8;
	case 8158ULL: goto x86_l_1fde;
	case 8168ULL: goto x86_l_1fe8;
	case 8178ULL: goto x86_l_1ff2;
	case 8183ULL: goto x86_l_1ff7;
	case 8186ULL: goto x86_l_1ffa;
	case 8192ULL: goto x86_l_2000;
	case 8195ULL: goto x86_l_2003;
	case 8197ULL: goto x86_l_2005;
	case 8202ULL: goto x86_l_200a;
	case 8208ULL: goto x86_l_2010;
	case 8215ULL: goto x86_l_2017;
	case 8219ULL: goto x86_l_201b;
	case 8224ULL: goto x86_l_2020;
	case 8229ULL: goto x86_l_2025;
	case 8236ULL: goto x86_l_202c;
	case 8241ULL: goto x86_l_2031;
	case 8244ULL: goto x86_l_2034;
	case 8253ULL: goto x86_l_203d;
	case 8255ULL: goto x86_l_203f;
	case 8260ULL: goto x86_l_2044;
	case 8265ULL: goto x86_l_2049;
	case 8270ULL: goto x86_l_204e;
	case 8278ULL: goto x86_l_2056;
	case 8282ULL: goto x86_l_205a;
	case 8288ULL: goto x86_l_2060;
	case 8293ULL: goto x86_l_2065;
	case 8298ULL: goto x86_l_206a;
	case 8303ULL: goto x86_l_206f;
	case 8305ULL: goto x86_l_2071;
	case 8310ULL: goto x86_l_2076;
	case 8312ULL: goto x86_l_2078;
	case 8318ULL: goto x86_l_207e;
	case 8323ULL: goto x86_l_2083;
	case 8326ULL: goto x86_l_2086;
	case 8329ULL: goto x86_l_2089;
	case 8332ULL: goto x86_l_208c;
	case 8336ULL: goto x86_l_2090;
	case 8339ULL: goto x86_l_2093;
	case 8343ULL: goto x86_l_2097;
	case 8348ULL: goto x86_l_209c;
	case 8355ULL: goto x86_l_20a3;
	case 8361ULL: goto x86_l_20a9;
	case 8364ULL: goto x86_l_20ac;
	case 8368ULL: goto x86_l_20b0;
	case 8371ULL: goto x86_l_20b3;
	case 8374ULL: goto x86_l_20b6;
	case 8380ULL: goto x86_l_20bc;
	case 8385ULL: goto x86_l_20c1;
	case 8390ULL: goto x86_l_20c6;
	case 8395ULL: goto x86_l_20cb;
	case 8397ULL: goto x86_l_20cd;
	case 8399ULL: goto x86_l_20cf;
	case 8404ULL: goto x86_l_20d4;
	case 8406ULL: goto x86_l_20d6;
	case 8412ULL: goto x86_l_20dc;
	case 8417ULL: goto x86_l_20e1;
	case 8420ULL: goto x86_l_20e4;
	case 8426ULL: goto x86_l_20ea;
	case 8429ULL: goto x86_l_20ed;
	case 8435ULL: goto x86_l_20f3;
	case 8440ULL: goto x86_l_20f8;
	case 8445ULL: goto x86_l_20fd;
	case 8452ULL: goto x86_l_2104;
	case 8457ULL: goto x86_l_2109;
	case 8462ULL: goto x86_l_210e;
	case 8467ULL: goto x86_l_2113;
	case 8472ULL: goto x86_l_2118;
	case 8476ULL: goto x86_l_211c;
	case 8482ULL: goto x86_l_2122;
	case 8492ULL: goto x86_l_212c;
	case 8496ULL: goto x86_l_2130;
	case 8502ULL: goto x86_l_2136;
	case 8506ULL: goto x86_l_213a;
	case 8511ULL: goto x86_l_213f;
	case 8516ULL: goto x86_l_2144;
	case 8521ULL: goto x86_l_2149;
	case 8524ULL: goto x86_l_214c;
	case 8529ULL: goto x86_l_2151;
	case 8531ULL: goto x86_l_2153;
	case 8534ULL: goto x86_l_2156;
	case 8540ULL: goto x86_l_215c;
	case 8545ULL: goto x86_l_2161;
	case 8548ULL: goto x86_l_2164;
	case 8550ULL: goto x86_l_2166;
	case 8552ULL: goto x86_l_2168;
	case 8554ULL: goto x86_l_216a;
	case 8557ULL: goto x86_l_216d;
	case 8559ULL: goto x86_l_216f;
	case 8562ULL: goto x86_l_2172;
	case 8564ULL: goto x86_l_2174;
	case 8571ULL: goto x86_l_217b;
	case 8575ULL: goto x86_l_217f;
	case 8577ULL: goto x86_l_2181;
	case 8580ULL: goto x86_l_2184;
	case 8582ULL: goto x86_l_2186;
	case 8585ULL: goto x86_l_2189;
	case 8587ULL: goto x86_l_218b;
	case 8592ULL: goto x86_l_2190;
	case 8594ULL: goto x86_l_2192;
	case 8601ULL: goto x86_l_2199;
	case 8605ULL: goto x86_l_219d;
	case 8607ULL: goto x86_l_219f;
	case 8612ULL: goto x86_l_21a4;
	case 8619ULL: goto x86_l_21ab;
	case 8624ULL: goto x86_l_21b0;
	case 8626ULL: goto x86_l_21b2;
	case 8631ULL: goto x86_l_21b7;
	case 8636ULL: goto x86_l_21bc;
	case 8641ULL: goto x86_l_21c1;
	case 8648ULL: goto x86_l_21c8;
	case 8653ULL: goto x86_l_21cd;
	case 8655ULL: goto x86_l_21cf;
	case 8660ULL: goto x86_l_21d4;
	case 8665ULL: goto x86_l_21d9;
	case 8670ULL: goto x86_l_21de;
	case 8675ULL: goto x86_l_21e3;
	case 8679ULL: goto x86_l_21e7;
	case 8685ULL: goto x86_l_21ed;
	case 8695ULL: goto x86_l_21f7;
	case 8699ULL: goto x86_l_21fb;
	case 8705ULL: goto x86_l_2201;
	case 8709ULL: goto x86_l_2205;
	case 8714ULL: goto x86_l_220a;
	case 8719ULL: goto x86_l_220f;
	case 8724ULL: goto x86_l_2214;
	case 8727ULL: goto x86_l_2217;
	case 8732ULL: goto x86_l_221c;
	case 8734ULL: goto x86_l_221e;
	case 8737ULL: goto x86_l_2221;
	case 8743ULL: goto x86_l_2227;
	case 8748ULL: goto x86_l_222c;
	case 8751ULL: goto x86_l_222f;
	case 8753ULL: goto x86_l_2231;
	case 8755ULL: goto x86_l_2233;
	case 8757ULL: goto x86_l_2235;
	case 8760ULL: goto x86_l_2238;
	case 8762ULL: goto x86_l_223a;
	case 8765ULL: goto x86_l_223d;
	case 8767ULL: goto x86_l_223f;
	case 8774ULL: goto x86_l_2246;
	case 8778ULL: goto x86_l_224a;
	case 8780ULL: goto x86_l_224c;
	case 8783ULL: goto x86_l_224f;
	case 8785ULL: goto x86_l_2251;
	case 8788ULL: goto x86_l_2254;
	case 8790ULL: goto x86_l_2256;
	case 8795ULL: goto x86_l_225b;
	case 8797ULL: goto x86_l_225d;
	case 8804ULL: goto x86_l_2264;
	case 8808ULL: goto x86_l_2268;
	case 8810ULL: goto x86_l_226a;
	case 8815ULL: goto x86_l_226f;
	case 8822ULL: goto x86_l_2276;
	case 8827ULL: goto x86_l_227b;
	case 8829ULL: goto x86_l_227d;
	case 8834ULL: goto x86_l_2282;
	case 8841ULL: goto x86_l_2289;
	case 8846ULL: goto x86_l_228e;
	case 8848ULL: goto x86_l_2290;
	case 8853ULL: goto x86_l_2295;
	case 8858ULL: goto x86_l_229a;
	case 8863ULL: goto x86_l_229f;
	case 8868ULL: goto x86_l_22a4;
	case 8872ULL: goto x86_l_22a8;
	case 8878ULL: goto x86_l_22ae;
	case 8888ULL: goto x86_l_22b8;
	case 8892ULL: goto x86_l_22bc;
	case 8898ULL: goto x86_l_22c2;
	case 8902ULL: goto x86_l_22c6;
	case 8907ULL: goto x86_l_22cb;
	case 8912ULL: goto x86_l_22d0;
	case 8917ULL: goto x86_l_22d5;
	case 8920ULL: goto x86_l_22d8;
	case 8925ULL: goto x86_l_22dd;
	case 8927ULL: goto x86_l_22df;
	case 8930ULL: goto x86_l_22e2;
	case 8936ULL: goto x86_l_22e8;
	case 8941ULL: goto x86_l_22ed;
	case 8944ULL: goto x86_l_22f0;
	case 8946ULL: goto x86_l_22f2;
	case 8948ULL: goto x86_l_22f4;
	case 8950ULL: goto x86_l_22f6;
	case 8953ULL: goto x86_l_22f9;
	case 8955ULL: goto x86_l_22fb;
	case 8958ULL: goto x86_l_22fe;
	case 8960ULL: goto x86_l_2300;
	case 8967ULL: goto x86_l_2307;
	case 8971ULL: goto x86_l_230b;
	case 8973ULL: goto x86_l_230d;
	case 8976ULL: goto x86_l_2310;
	case 8978ULL: goto x86_l_2312;
	case 8981ULL: goto x86_l_2315;
	case 8983ULL: goto x86_l_2317;
	case 8988ULL: goto x86_l_231c;
	case 8990ULL: goto x86_l_231e;
	case 8997ULL: goto x86_l_2325;
	case 9001ULL: goto x86_l_2329;
	case 9003ULL: goto x86_l_232b;
	case 9008ULL: goto x86_l_2330;
	case 9015ULL: goto x86_l_2337;
	case 9020ULL: goto x86_l_233c;
	case 9022ULL: goto x86_l_233e;
	case 9027ULL: goto x86_l_2343;
	case 9034ULL: goto x86_l_234a;
	case 9039ULL: goto x86_l_234f;
	case 9041ULL: goto x86_l_2351;
	case 9046ULL: goto x86_l_2356;
	case 9051ULL: goto x86_l_235b;
	case 9056ULL: goto x86_l_2360;
	case 9061ULL: goto x86_l_2365;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1cdf:
	/* 0x1cdf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ce1:
	/* 0x1ce1: je     2020 <generic_retkprobe_event+0x2020> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2020;
	}
x86_l_1ce7:
	/* 0x1ce7: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1cea:
	/* 0x1cea: je     2020 <generic_retkprobe_event+0x2020> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2020;
	}
x86_l_1cf0:
	/* 0x1cf0: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_1cf3:
	/* 0x1cf3: jne    21b2 <generic_retkprobe_event+0x21b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21b2;
	}
x86_l_1cf9:
	/* 0x1cf9: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_1d00:
	/* 0x1d00: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_1d04:
	/* 0x1d04: jmp    2109 <generic_retkprobe_event+0x2109> */
	goto x86_l_2109;
x86_l_1d09:
	/* 0x1d09: lea    rdx,[r12+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1d0e:
	/* 0x1d0e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d13:
	/* 0x1d13: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d18:
	/* 0x1d18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d1a:
	/* 0x1d1a: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d1f:
	/* 0x1d1f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d24:
	/* 0x1d24: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1d27:
	/* 0x1d27: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d2c:
	/* 0x1d2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d2e:
	/* 0x1d2e: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d32:
	/* 0x1d32: lea    rdi,[rbx+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1d39:
	/* 0x1d39: lea    r13,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d3e:
	/* 0x1d3e: add    r12,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_1d42:
	/* 0x1d42: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d47:
	/* 0x1d47: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1d4c:
	/* 0x1d4c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1d4f:
	/* 0x1d4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d51:
	/* 0x1d51: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d54:
	/* 0x1d54: add    rdi,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_1d5b:
	/* 0x1d5b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d60:
	/* 0x1d60: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1d65:
	/* 0x1d65: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1d68:
	/* 0x1d68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d6a:
	/* 0x1d6a: movzx  eax,WORD PTR [rbx+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1d71:
	/* 0x1d71: movbe  WORD PTR [rbx+0xbe],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1d7a:
	/* 0x1d7a: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d7f:
	/* 0x1d7f: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d84:
	/* 0x1d84: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d89:
	/* 0x1d89: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_1d90:
	/* 0x1d90: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d95:
	/* 0x1d95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d97:
	/* 0x1d97: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d9a:
	/* 0x1d9a: je     1daf <generic_retkprobe_event+0x1daf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1daf;
	}
x86_l_1d9c:
	/* 0x1d9c: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d9e:
	/* 0x1d9e: mov    DWORD PTR [rbp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1da1:
	/* 0x1da1: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1da5:
	/* 0x1da5: mov    QWORD PTR [rbp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1da9:
	/* 0x1da9: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1dac:
	/* 0x1dac: mov    DWORD PTR [rbp+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1daf:
	/* 0x1daf: mov    r13d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 64ULL);
x86_l_1db5:
	/* 0x1db5: jmp    1dc8 <generic_retkprobe_event+0x1dc8> */
	goto x86_l_1dc8;
x86_l_1db7:
	/* 0x1db7: mov    QWORD PTR [rbx+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_1dc2:
	/* 0x1dc2: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_1dc8:
	/* 0x1dc8: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dcc:
	/* 0x1dcc: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_1dd1:
	/* 0x1dd1: jmp    2874 <generic_retkprobe_event+0x2874> */
	return 10356ULL;
x86_l_1dd6:
	/* 0x1dd6: lea    rdi,[rcx+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1ddd:
	/* 0x1ddd: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1de2:
	/* 0x1de2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1de7:
	/* 0x1de7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1dec:
	/* 0x1dec: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_1def:
	/* 0x1def: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1df1:
	/* 0x1df1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1df4:
	/* 0x1df4: add    rdi,0x9e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 158ULL);
x86_l_1dfb:
	/* 0x1dfb: add    r12,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1dff:
	/* 0x1dff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e04:
	/* 0x1e04: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1e09:
	/* 0x1e09: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1e0c:
	/* 0x1e0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e0e:
	/* 0x1e0e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e12:
	/* 0x1e12: movzx  eax,WORD PTR [rcx+0x9e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_1e19:
	/* 0x1e19: movbe  WORD PTR [rcx+0x9e],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_1e22:
	/* 0x1e22: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_1e27:
	/* 0x1e27: mov    r13d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 24ULL);
x86_l_1e2d:
	/* 0x1e2d: jmp    2874 <generic_retkprobe_event+0x2874> */
	return 10356ULL;
x86_l_1e32:
	/* 0x1e32: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e36:
	/* 0x1e36: lea    rdi,[rax+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1e3d:
	/* 0x1e3d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1e42:
	/* 0x1e42: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e47:
	/* 0x1e47: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_1e4c:
	/* 0x1e4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e4e:
	/* 0x1e4e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e51:
	/* 0x1e51: js     1bbc <generic_retkprobe_event+0x1bbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7100ULL;
	}
x86_l_1e57:
	/* 0x1e57: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e5b:
	/* 0x1e5b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e60:
	/* 0x1e60: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e65:
	/* 0x1e65: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e6a:
	/* 0x1e6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e6c:
	/* 0x1e6c: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e70:
	/* 0x1e70: add    rdi,0xa4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 164ULL);
x86_l_1e77:
	/* 0x1e77: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e7c:
	/* 0x1e7c: mov    edx,0x348 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 840ULL);
x86_l_1e81:
	/* 0x1e81: add    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_1e86:
	/* 0x1e86: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e8b:
	/* 0x1e8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e8d:
	/* 0x1e8d: add    rbp,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_1e91:
	/* 0x1e91: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e96:
	/* 0x1e96: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e9b:
	/* 0x1e9b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ea0:
	/* 0x1ea0: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1ea3:
	/* 0x1ea3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ea5:
	/* 0x1ea5: mov    r13d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 80ULL);
x86_l_1eab:
	/* 0x1eab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1eae:
	/* 0x1eae: jne    1fc7 <generic_retkprobe_event+0x1fc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fc7;
	}
x86_l_1eb4:
	/* 0x1eb4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1eb6:
	/* 0x1eb6: cmp    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1ebb:
	/* 0x1ebb: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1ebe:
	/* 0x1ebe: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ec0:
	/* 0x1ec0: jmp    1fc7 <generic_retkprobe_event+0x1fc7> */
	goto x86_l_1fc7;
x86_l_1ec5:
	/* 0x1ec5: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ec8:
	/* 0x1ec8: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ecc:
	/* 0x1ecc: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_1ed1:
	/* 0x1ed1: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_1ed4:
	/* 0x1ed4: jns    2882 <generic_retkprobe_event+0x2882> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 10370ULL;
	}
x86_l_1eda:
	/* 0x1eda: jmp    1fde <generic_retkprobe_event+0x1fde> */
	goto x86_l_1fde;
x86_l_1edf:
	/* 0x1edf: add    r12,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_1ee3:
	/* 0x1ee3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ee8:
	/* 0x1ee8: mov    esi,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 107ULL);
x86_l_1eed:
	/* 0x1eed: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1ef0:
	/* 0x1ef0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ef2:
	/* 0x1ef2: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1ef5:
	/* 0x1ef5: mov    al,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 107ULL);
x86_l_1ef7:
	/* 0x1ef7: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1ef9:
	/* 0x1ef9: js     1f05 <generic_retkprobe_event+0x1f05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1f05;
	}
x86_l_1efb:
	/* 0x1efb: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1eff:
	/* 0x1eff: mov    BYTE PTR [rcx+0x9f],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 159ULL);
x86_l_1f05:
	/* 0x1f05: mov    r13d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 112ULL);
x86_l_1f0b:
	/* 0x1f0b: jmp    2870 <generic_retkprobe_event+0x2870> */
	return 10352ULL;
x86_l_1f10:
	/* 0x1f10: lea    rdx,[r12+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1f15:
	/* 0x1f15: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f1a:
	/* 0x1f1a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1f1f:
	/* 0x1f1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f21:
	/* 0x1f21: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f26:
	/* 0x1f26: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f2b:
	/* 0x1f2b: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1f2e:
	/* 0x1f2e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1f33:
	/* 0x1f33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f35:
	/* 0x1f35: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f39:
	/* 0x1f39: lea    rdi,[rbx+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1f40:
	/* 0x1f40: lea    r13,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f45:
	/* 0x1f45: add    r12,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_1f49:
	/* 0x1f49: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f4e:
	/* 0x1f4e: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1f53:
	/* 0x1f53: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f56:
	/* 0x1f56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f58:
	/* 0x1f58: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1f5b:
	/* 0x1f5b: add    rdi,0xbe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 190ULL);
x86_l_1f62:
	/* 0x1f62: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f67:
	/* 0x1f67: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1f6c:
	/* 0x1f6c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1f6f:
	/* 0x1f6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f71:
	/* 0x1f71: movzx  eax,WORD PTR [rbx+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1f78:
	/* 0x1f78: movbe  WORD PTR [rbx+0xbe],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_1f81:
	/* 0x1f81: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f85:
	/* 0x1f85: mov    rax,QWORD PTR [rax+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1f8c:
	/* 0x1f8c: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f91:
	/* 0x1f91: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f96:
	/* 0x1f96: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_1f9d:
	/* 0x1f9d: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1fa2:
	/* 0x1fa2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fa4:
	/* 0x1fa4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fa7:
	/* 0x1fa7: je     1fc1 <generic_retkprobe_event+0x1fc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fc1;
	}
x86_l_1fa9:
	/* 0x1fa9: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fab:
	/* 0x1fab: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fb0:
	/* 0x1fb0: mov    DWORD PTR [rdx+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fb3:
	/* 0x1fb3: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fb7:
	/* 0x1fb7: mov    QWORD PTR [rdx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fbb:
	/* 0x1fbb: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1fbe:
	/* 0x1fbe: mov    DWORD PTR [rdx+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1fc1:
	/* 0x1fc1: mov    r13d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 64ULL);
x86_l_1fc7:
	/* 0x1fc7: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fcb:
	/* 0x1fcb: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fd0:
	/* 0x1fd0: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_1fd5:
	/* 0x1fd5: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_1fd8:
	/* 0x1fd8: jns    2882 <generic_retkprobe_event+0x2882> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 10370ULL;
	}
x86_l_1fde:
	/* 0x1fde: mov    DWORD PTR [rcx+0x5ea0],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104045582745599ULL);
x86_l_1fe8:
	/* 0x1fe8: mov    DWORD PTR [rcx+0x98],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 657129996287ULL);
x86_l_1ff2:
	/* 0x1ff2: jmp    2890 <generic_retkprobe_event+0x2890> */
	return 10384ULL;
x86_l_1ff7:
	/* 0x1ff7: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_1ffa:
	/* 0x1ffa: je     20f8 <generic_retkprobe_event+0x20f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20f8;
	}
x86_l_2000:
	/* 0x2000: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2003:
	/* 0x2003: je     2020 <generic_retkprobe_event+0x2020> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2020;
	}
x86_l_2005:
	/* 0x2005: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_200a:
	/* 0x200a: jne    21b2 <generic_retkprobe_event+0x21b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21b2;
	}
x86_l_2010:
	/* 0x2010: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2017:
	/* 0x2017: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_201b:
	/* 0x201b: jmp    2109 <generic_retkprobe_event+0x2109> */
	goto x86_l_2109;
x86_l_2020:
	/* 0x2020: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2025:
	/* 0x2025: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_202c:
	/* 0x202c: jmp    2104 <generic_retkprobe_event+0x2104> */
	goto x86_l_2104;
x86_l_2031:
	/* 0x2031: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2034:
	/* 0x2034: cmp    QWORD PTR [rsp+0x80],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813891ULL);
x86_l_203d:
	/* 0x203d: jne    204e <generic_retkprobe_event+0x204e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_204e;
	}
x86_l_203f:
	/* 0x203f: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2044:
	/* 0x2044: mov    rbp,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2049:
	/* 0x2049: jmp    349 <generic_retkprobe_event+0x349> */
	return 841ULL;
x86_l_204e:
	/* 0x204e: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2056:
	/* 0x2056: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_205a:
	/* 0x205a: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2060:
	/* 0x2060: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2065:
	/* 0x2065: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_206a:
	/* 0x206a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_206f:
	/* 0x206f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2071:
	/* 0x2071: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2076:
	/* 0x2076: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2078:
	/* 0x2078: js     2adb <generic_retkprobe_event+0x2adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10971ULL;
	}
x86_l_207e:
	/* 0x207e: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2083:
	/* 0x2083: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_2086:
	/* 0x2086: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2089:
	/* 0x2089: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_208c:
	/* 0x208c: cmovb  rbx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_2090:
	/* 0x2090: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_2093:
	/* 0x2093: cmovne rdx,rbx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RBX, X86_WIDTH_64, X86_CC_NE);
x86_l_2097:
	/* 0x2097: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_209c:
	/* 0x209c: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_20a3:
	/* 0x20a3: ja     2adb <generic_retkprobe_event+0x2adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10971ULL;
	}
x86_l_20a9:
	/* 0x20a9: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_20ac:
	/* 0x20ac: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20b0:
	/* 0x20b0: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_20b3:
	/* 0x20b3: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_20b6:
	/* 0x20b6: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_20bc:
	/* 0x20bc: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_20c1:
	/* 0x20c1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20c6:
	/* 0x20c6: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_20cb:
	/* 0x20cb: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_20cd:
	/* 0x20cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20cf:
	/* 0x20cf: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_20d4:
	/* 0x20d4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20d6:
	/* 0x20d6: js     2adb <generic_retkprobe_event+0x2adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10971ULL;
	}
x86_l_20dc:
	/* 0x20dc: add    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_20e1:
	/* 0x20e1: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_20e4:
	/* 0x20e4: je     2414 <generic_retkprobe_event+0x2414> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9236ULL;
	}
x86_l_20ea:
	/* 0x20ea: sub    r15,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_20ed:
	/* 0x20ed: jne    2417 <generic_retkprobe_event+0x2417> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9239ULL;
	}
x86_l_20f3:
	/* 0x20f3: jmp    203f <generic_retkprobe_event+0x203f> */
	goto x86_l_203f;
x86_l_20f8:
	/* 0x20f8: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_20fd:
	/* 0x20fd: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2104:
	/* 0x2104: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2109:
	/* 0x2109: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_210e:
	/* 0x210e: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2113:
	/* 0x2113: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2118:
	/* 0x2118: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_211c:
	/* 0x211c: ja     2971 <generic_retkprobe_event+0x2971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10609ULL;
	}
x86_l_2122:
	/* 0x2122: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_212c:
	/* 0x212c: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2130:
	/* 0x2130: jae    2971 <generic_retkprobe_event+0x2971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10609ULL;
	}
x86_l_2136:
	/* 0x2136: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_213a:
	/* 0x213a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_213f:
	/* 0x213f: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2144:
	/* 0x2144: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2149:
	/* 0x2149: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_214c:
	/* 0x214c: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2151:
	/* 0x2151: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2153:
	/* 0x2153: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2156:
	/* 0x2156: js     26c2 <generic_retkprobe_event+0x26c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9922ULL;
	}
x86_l_215c:
	/* 0x215c: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2161:
	/* 0x2161: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2164:
	/* 0x2164: jg     2181 <generic_retkprobe_event+0x2181> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2181;
	}
x86_l_2166:
	/* 0x2166: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2168:
	/* 0x2168: je     219f <generic_retkprobe_event+0x219f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_219f;
	}
x86_l_216a:
	/* 0x216a: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_216d:
	/* 0x216d: je     219f <generic_retkprobe_event+0x219f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_219f;
	}
x86_l_216f:
	/* 0x216f: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2172:
	/* 0x2172: jne    21cf <generic_retkprobe_event+0x21cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21cf;
	}
x86_l_2174:
	/* 0x2174: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_217b:
	/* 0x217b: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_217f:
	/* 0x217f: jmp    21d4 <generic_retkprobe_event+0x21d4> */
	goto x86_l_21d4;
x86_l_2181:
	/* 0x2181: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2184:
	/* 0x2184: je     21bc <generic_retkprobe_event+0x21bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21bc;
	}
x86_l_2186:
	/* 0x2186: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2189:
	/* 0x2189: je     219f <generic_retkprobe_event+0x219f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_219f;
	}
x86_l_218b:
	/* 0x218b: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2190:
	/* 0x2190: jne    21cf <generic_retkprobe_event+0x21cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21cf;
	}
x86_l_2192:
	/* 0x2192: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2199:
	/* 0x2199: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_219d:
	/* 0x219d: jmp    21d4 <generic_retkprobe_event+0x21d4> */
	goto x86_l_21d4;
x86_l_219f:
	/* 0x219f: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_21a4:
	/* 0x21a4: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_21ab:
	/* 0x21ab: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_21b0:
	/* 0x21b0: jmp    21d4 <generic_retkprobe_event+0x21d4> */
	goto x86_l_21d4;
x86_l_21b2:
	/* 0x21b2: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_21b7:
	/* 0x21b7: jmp    2109 <generic_retkprobe_event+0x2109> */
	goto x86_l_2109;
x86_l_21bc:
	/* 0x21bc: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_21c1:
	/* 0x21c1: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_21c8:
	/* 0x21c8: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_21cd:
	/* 0x21cd: jmp    21d4 <generic_retkprobe_event+0x21d4> */
	goto x86_l_21d4;
x86_l_21cf:
	/* 0x21cf: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_21d4:
	/* 0x21d4: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_21d9:
	/* 0x21d9: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21de:
	/* 0x21de: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_21e3:
	/* 0x21e3: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_21e7:
	/* 0x21e7: ja     2971 <generic_retkprobe_event+0x2971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10609ULL;
	}
x86_l_21ed:
	/* 0x21ed: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_21f7:
	/* 0x21f7: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_21fb:
	/* 0x21fb: jae    2971 <generic_retkprobe_event+0x2971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10609ULL;
	}
x86_l_2201:
	/* 0x2201: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2205:
	/* 0x2205: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_220a:
	/* 0x220a: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_220f:
	/* 0x220f: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2214:
	/* 0x2214: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2217:
	/* 0x2217: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_221c:
	/* 0x221c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_221e:
	/* 0x221e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2221:
	/* 0x2221: js     26c2 <generic_retkprobe_event+0x26c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9922ULL;
	}
x86_l_2227:
	/* 0x2227: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_222c:
	/* 0x222c: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_222f:
	/* 0x222f: jg     224c <generic_retkprobe_event+0x224c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_224c;
	}
x86_l_2231:
	/* 0x2231: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2233:
	/* 0x2233: je     226a <generic_retkprobe_event+0x226a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_226a;
	}
x86_l_2235:
	/* 0x2235: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2238:
	/* 0x2238: je     226a <generic_retkprobe_event+0x226a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_226a;
	}
x86_l_223a:
	/* 0x223a: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_223d:
	/* 0x223d: jne    2290 <generic_retkprobe_event+0x2290> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2290;
	}
x86_l_223f:
	/* 0x223f: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2246:
	/* 0x2246: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_224a:
	/* 0x224a: jmp    2295 <generic_retkprobe_event+0x2295> */
	goto x86_l_2295;
x86_l_224c:
	/* 0x224c: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_224f:
	/* 0x224f: je     227d <generic_retkprobe_event+0x227d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_227d;
	}
x86_l_2251:
	/* 0x2251: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2254:
	/* 0x2254: je     226a <generic_retkprobe_event+0x226a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_226a;
	}
x86_l_2256:
	/* 0x2256: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_225b:
	/* 0x225b: jne    2290 <generic_retkprobe_event+0x2290> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2290;
	}
x86_l_225d:
	/* 0x225d: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2264:
	/* 0x2264: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2268:
	/* 0x2268: jmp    2295 <generic_retkprobe_event+0x2295> */
	goto x86_l_2295;
x86_l_226a:
	/* 0x226a: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_226f:
	/* 0x226f: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2276:
	/* 0x2276: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_227b:
	/* 0x227b: jmp    2295 <generic_retkprobe_event+0x2295> */
	goto x86_l_2295;
x86_l_227d:
	/* 0x227d: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2282:
	/* 0x2282: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2289:
	/* 0x2289: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_228e:
	/* 0x228e: jmp    2295 <generic_retkprobe_event+0x2295> */
	goto x86_l_2295;
x86_l_2290:
	/* 0x2290: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2295:
	/* 0x2295: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_229a:
	/* 0x229a: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_229f:
	/* 0x229f: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_22a4:
	/* 0x22a4: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_22a8:
	/* 0x22a8: ja     2971 <generic_retkprobe_event+0x2971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10609ULL;
	}
x86_l_22ae:
	/* 0x22ae: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_22b8:
	/* 0x22b8: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_22bc:
	/* 0x22bc: jae    2971 <generic_retkprobe_event+0x2971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 10609ULL;
	}
x86_l_22c2:
	/* 0x22c2: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_22c6:
	/* 0x22c6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22cb:
	/* 0x22cb: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_22d0:
	/* 0x22d0: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_22d5:
	/* 0x22d5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_22d8:
	/* 0x22d8: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_22dd:
	/* 0x22dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22df:
	/* 0x22df: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22e2:
	/* 0x22e2: js     26c2 <generic_retkprobe_event+0x26c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9922ULL;
	}
x86_l_22e8:
	/* 0x22e8: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_22ed:
	/* 0x22ed: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_22f0:
	/* 0x22f0: jg     230d <generic_retkprobe_event+0x230d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_230d;
	}
x86_l_22f2:
	/* 0x22f2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22f4:
	/* 0x22f4: je     232b <generic_retkprobe_event+0x232b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_232b;
	}
x86_l_22f6:
	/* 0x22f6: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_22f9:
	/* 0x22f9: je     232b <generic_retkprobe_event+0x232b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_232b;
	}
x86_l_22fb:
	/* 0x22fb: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_22fe:
	/* 0x22fe: jne    2351 <generic_retkprobe_event+0x2351> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2351;
	}
x86_l_2300:
	/* 0x2300: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2307:
	/* 0x2307: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_230b:
	/* 0x230b: jmp    2356 <generic_retkprobe_event+0x2356> */
	goto x86_l_2356;
x86_l_230d:
	/* 0x230d: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2310:
	/* 0x2310: je     233e <generic_retkprobe_event+0x233e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_233e;
	}
x86_l_2312:
	/* 0x2312: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2315:
	/* 0x2315: je     232b <generic_retkprobe_event+0x232b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_232b;
	}
x86_l_2317:
	/* 0x2317: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_231c:
	/* 0x231c: jne    2351 <generic_retkprobe_event+0x2351> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2351;
	}
x86_l_231e:
	/* 0x231e: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2325:
	/* 0x2325: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2329:
	/* 0x2329: jmp    2356 <generic_retkprobe_event+0x2356> */
	goto x86_l_2356;
x86_l_232b:
	/* 0x232b: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2330:
	/* 0x2330: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2337:
	/* 0x2337: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_233c:
	/* 0x233c: jmp    2356 <generic_retkprobe_event+0x2356> */
	goto x86_l_2356;
x86_l_233e:
	/* 0x233e: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2343:
	/* 0x2343: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_234a:
	/* 0x234a: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_234f:
	/* 0x234f: jmp    2356 <generic_retkprobe_event+0x2356> */
	goto x86_l_2356;
x86_l_2351:
	/* 0x2351: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2356:
	/* 0x2356: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_235b:
	/* 0x235b: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2360:
	/* 0x2360: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2365:
	/* 0x2365: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
	return 9065ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9065ULL: goto x86_l_2369;
	case 9071ULL: goto x86_l_236f;
	case 9081ULL: goto x86_l_2379;
	case 9085ULL: goto x86_l_237d;
	case 9091ULL: goto x86_l_2383;
	case 9095ULL: goto x86_l_2387;
	case 9100ULL: goto x86_l_238c;
	case 9105ULL: goto x86_l_2391;
	case 9110ULL: goto x86_l_2396;
	case 9113ULL: goto x86_l_2399;
	case 9118ULL: goto x86_l_239e;
	case 9120ULL: goto x86_l_23a0;
	case 9123ULL: goto x86_l_23a3;
	case 9129ULL: goto x86_l_23a9;
	case 9134ULL: goto x86_l_23ae;
	case 9137ULL: goto x86_l_23b1;
	case 9139ULL: goto x86_l_23b3;
	case 9141ULL: goto x86_l_23b5;
	case 9143ULL: goto x86_l_23b7;
	case 9146ULL: goto x86_l_23ba;
	case 9148ULL: goto x86_l_23bc;
	case 9151ULL: goto x86_l_23bf;
	case 9157ULL: goto x86_l_23c5;
	case 9164ULL: goto x86_l_23cc;
	case 9168ULL: goto x86_l_23d0;
	case 9173ULL: goto x86_l_23d5;
	case 9176ULL: goto x86_l_23d8;
	case 9182ULL: goto x86_l_23de;
	case 9185ULL: goto x86_l_23e1;
	case 9187ULL: goto x86_l_23e3;
	case 9192ULL: goto x86_l_23e8;
	case 9198ULL: goto x86_l_23ee;
	case 9205ULL: goto x86_l_23f5;
	case 9209ULL: goto x86_l_23f9;
	case 9214ULL: goto x86_l_23fe;
	case 9219ULL: goto x86_l_2403;
	case 9226ULL: goto x86_l_240a;
	case 9231ULL: goto x86_l_240f;
	case 9236ULL: goto x86_l_2414;
	case 9239ULL: goto x86_l_2417;
	case 9248ULL: goto x86_l_2420;
	case 9254ULL: goto x86_l_2426;
	case 9262ULL: goto x86_l_242e;
	case 9266ULL: goto x86_l_2432;
	case 9272ULL: goto x86_l_2438;
	case 9277ULL: goto x86_l_243d;
	case 9282ULL: goto x86_l_2442;
	case 9287ULL: goto x86_l_2447;
	case 9289ULL: goto x86_l_2449;
	case 9294ULL: goto x86_l_244e;
	case 9296ULL: goto x86_l_2450;
	case 9302ULL: goto x86_l_2456;
	case 9307ULL: goto x86_l_245b;
	case 9310ULL: goto x86_l_245e;
	case 9313ULL: goto x86_l_2461;
	case 9316ULL: goto x86_l_2464;
	case 9320ULL: goto x86_l_2468;
	case 9323ULL: goto x86_l_246b;
	case 9327ULL: goto x86_l_246f;
	case 9332ULL: goto x86_l_2474;
	case 9336ULL: goto x86_l_2478;
	case 9343ULL: goto x86_l_247f;
	case 9349ULL: goto x86_l_2485;
	case 9352ULL: goto x86_l_2488;
	case 9355ULL: goto x86_l_248b;
	case 9358ULL: goto x86_l_248e;
	case 9364ULL: goto x86_l_2494;
	case 9369ULL: goto x86_l_2499;
	case 9374ULL: goto x86_l_249e;
	case 9379ULL: goto x86_l_24a3;
	case 9383ULL: goto x86_l_24a7;
	case 9385ULL: goto x86_l_24a9;
	case 9390ULL: goto x86_l_24ae;
	case 9392ULL: goto x86_l_24b0;
	case 9398ULL: goto x86_l_24b6;
	case 9403ULL: goto x86_l_24bb;
	case 9407ULL: goto x86_l_24bf;
	case 9412ULL: goto x86_l_24c4;
	case 9415ULL: goto x86_l_24c7;
	case 9421ULL: goto x86_l_24cd;
	case 9424ULL: goto x86_l_24d0;
	case 9430ULL: goto x86_l_24d6;
	case 9435ULL: goto x86_l_24db;
	case 9440ULL: goto x86_l_24e0;
	case 9447ULL: goto x86_l_24e7;
	case 9452ULL: goto x86_l_24ec;
	case 9454ULL: goto x86_l_24ee;
	case 9459ULL: goto x86_l_24f3;
	case 9464ULL: goto x86_l_24f8;
	case 9469ULL: goto x86_l_24fd;
	case 9474ULL: goto x86_l_2502;
	case 9478ULL: goto x86_l_2506;
	case 9484ULL: goto x86_l_250c;
	case 9494ULL: goto x86_l_2516;
	case 9498ULL: goto x86_l_251a;
	case 9504ULL: goto x86_l_2520;
	case 9508ULL: goto x86_l_2524;
	case 9513ULL: goto x86_l_2529;
	case 9518ULL: goto x86_l_252e;
	case 9523ULL: goto x86_l_2533;
	case 9526ULL: goto x86_l_2536;
	case 9531ULL: goto x86_l_253b;
	case 9533ULL: goto x86_l_253d;
	case 9536ULL: goto x86_l_2540;
	case 9542ULL: goto x86_l_2546;
	case 9547ULL: goto x86_l_254b;
	case 9550ULL: goto x86_l_254e;
	case 9552ULL: goto x86_l_2550;
	case 9554ULL: goto x86_l_2552;
	case 9556ULL: goto x86_l_2554;
	case 9559ULL: goto x86_l_2557;
	case 9561ULL: goto x86_l_2559;
	case 9564ULL: goto x86_l_255c;
	case 9566ULL: goto x86_l_255e;
	case 9573ULL: goto x86_l_2565;
	case 9577ULL: goto x86_l_2569;
	case 9579ULL: goto x86_l_256b;
	case 9582ULL: goto x86_l_256e;
	case 9584ULL: goto x86_l_2570;
	case 9587ULL: goto x86_l_2573;
	case 9589ULL: goto x86_l_2575;
	case 9594ULL: goto x86_l_257a;
	case 9596ULL: goto x86_l_257c;
	case 9603ULL: goto x86_l_2583;
	case 9607ULL: goto x86_l_2587;
	case 9609ULL: goto x86_l_2589;
	case 9614ULL: goto x86_l_258e;
	case 9621ULL: goto x86_l_2595;
	case 9626ULL: goto x86_l_259a;
	case 9628ULL: goto x86_l_259c;
	case 9633ULL: goto x86_l_25a1;
	case 9640ULL: goto x86_l_25a8;
	case 9645ULL: goto x86_l_25ad;
	case 9647ULL: goto x86_l_25af;
	case 9652ULL: goto x86_l_25b4;
	case 9657ULL: goto x86_l_25b9;
	case 9662ULL: goto x86_l_25be;
	case 9667ULL: goto x86_l_25c3;
	case 9671ULL: goto x86_l_25c7;
	case 9677ULL: goto x86_l_25cd;
	case 9687ULL: goto x86_l_25d7;
	case 9691ULL: goto x86_l_25db;
	case 9697ULL: goto x86_l_25e1;
	case 9701ULL: goto x86_l_25e5;
	case 9706ULL: goto x86_l_25ea;
	case 9711ULL: goto x86_l_25ef;
	case 9716ULL: goto x86_l_25f4;
	case 9719ULL: goto x86_l_25f7;
	case 9724ULL: goto x86_l_25fc;
	case 9726ULL: goto x86_l_25fe;
	case 9729ULL: goto x86_l_2601;
	case 9735ULL: goto x86_l_2607;
	case 9740ULL: goto x86_l_260c;
	case 9743ULL: goto x86_l_260f;
	case 9745ULL: goto x86_l_2611;
	case 9747ULL: goto x86_l_2613;
	case 9749ULL: goto x86_l_2615;
	case 9752ULL: goto x86_l_2618;
	case 9754ULL: goto x86_l_261a;
	case 9757ULL: goto x86_l_261d;
	case 9759ULL: goto x86_l_261f;
	case 9766ULL: goto x86_l_2626;
	case 9770ULL: goto x86_l_262a;
	case 9772ULL: goto x86_l_262c;
	case 9775ULL: goto x86_l_262f;
	case 9777ULL: goto x86_l_2631;
	case 9780ULL: goto x86_l_2634;
	case 9782ULL: goto x86_l_2636;
	case 9787ULL: goto x86_l_263b;
	case 9789ULL: goto x86_l_263d;
	case 9796ULL: goto x86_l_2644;
	case 9800ULL: goto x86_l_2648;
	case 9802ULL: goto x86_l_264a;
	case 9807ULL: goto x86_l_264f;
	case 9814ULL: goto x86_l_2656;
	case 9819ULL: goto x86_l_265b;
	case 9821ULL: goto x86_l_265d;
	case 9826ULL: goto x86_l_2662;
	case 9833ULL: goto x86_l_2669;
	case 9838ULL: goto x86_l_266e;
	case 9840ULL: goto x86_l_2670;
	case 9845ULL: goto x86_l_2675;
	case 9850ULL: goto x86_l_267a;
	case 9855ULL: goto x86_l_267f;
	case 9860ULL: goto x86_l_2684;
	case 9864ULL: goto x86_l_2688;
	case 9870ULL: goto x86_l_268e;
	case 9880ULL: goto x86_l_2698;
	case 9884ULL: goto x86_l_269c;
	case 9890ULL: goto x86_l_26a2;
	case 9894ULL: goto x86_l_26a6;
	case 9899ULL: goto x86_l_26ab;
	case 9904ULL: goto x86_l_26b0;
	case 9909ULL: goto x86_l_26b5;
	case 9912ULL: goto x86_l_26b8;
	case 9915ULL: goto x86_l_26bb;
	case 9920ULL: goto x86_l_26c0;
	case 9922ULL: goto x86_l_26c2;
	case 9924ULL: goto x86_l_26c4;
	case 9931ULL: goto x86_l_26cb;
	case 9934ULL: goto x86_l_26ce;
	case 9938ULL: goto x86_l_26d2;
	case 9945ULL: goto x86_l_26d9;
	case 9954ULL: goto x86_l_26e2;
	case 9959ULL: goto x86_l_26e7;
	case 9964ULL: goto x86_l_26ec;
	case 9969ULL: goto x86_l_26f1;
	case 9974ULL: goto x86_l_26f6;
	case 9976ULL: goto x86_l_26f8;
	case 9983ULL: goto x86_l_26ff;
	case 9987ULL: goto x86_l_2703;
	case 9992ULL: goto x86_l_2708;
	case 9997ULL: goto x86_l_270d;
	case 10000ULL: goto x86_l_2710;
	case 10002ULL: goto x86_l_2712;
	case 10010ULL: goto x86_l_271a;
	case 10013ULL: goto x86_l_271d;
	case 10015ULL: goto x86_l_271f;
	case 10018ULL: goto x86_l_2722;
	case 10024ULL: goto x86_l_2728;
	case 10029ULL: goto x86_l_272d;
	case 10038ULL: goto x86_l_2736;
	case 10042ULL: goto x86_l_273a;
	case 10046ULL: goto x86_l_273e;
	case 10053ULL: goto x86_l_2745;
	case 10058ULL: goto x86_l_274a;
	case 10063ULL: goto x86_l_274f;
	case 10065ULL: goto x86_l_2751;
	case 10072ULL: goto x86_l_2758;
	case 10076ULL: goto x86_l_275c;
	case 10080ULL: goto x86_l_2760;
	case 10085ULL: goto x86_l_2765;
	case 10087ULL: goto x86_l_2767;
	case 10092ULL: goto x86_l_276c;
	case 10101ULL: goto x86_l_2775;
	case 10105ULL: goto x86_l_2779;
	case 10109ULL: goto x86_l_277d;
	case 10116ULL: goto x86_l_2784;
	case 10121ULL: goto x86_l_2789;
	case 10126ULL: goto x86_l_278e;
	case 10128ULL: goto x86_l_2790;
	case 10135ULL: goto x86_l_2797;
	case 10139ULL: goto x86_l_279b;
	case 10143ULL: goto x86_l_279f;
	case 10148ULL: goto x86_l_27a4;
	case 10153ULL: goto x86_l_27a9;
	case 10155ULL: goto x86_l_27ab;
	case 10157ULL: goto x86_l_27ad;
	case 10161ULL: goto x86_l_27b1;
	case 10171ULL: goto x86_l_27bb;
	case 10175ULL: goto x86_l_27bf;
	case 10182ULL: goto x86_l_27c6;
	case 10189ULL: goto x86_l_27cd;
	case 10198ULL: goto x86_l_27d6;
	case 10207ULL: goto x86_l_27df;
	case 10214ULL: goto x86_l_27e6;
	case 10219ULL: goto x86_l_27eb;
	case 10224ULL: goto x86_l_27f0;
	case 10229ULL: goto x86_l_27f5;
	case 10232ULL: goto x86_l_27f8;
	case 10234ULL: goto x86_l_27fa;
	case 10240ULL: goto x86_l_2800;
	case 10242ULL: goto x86_l_2802;
	case 10247ULL: goto x86_l_2807;
	case 10252ULL: goto x86_l_280c;
	case 10256ULL: goto x86_l_2810;
	case 10264ULL: goto x86_l_2818;
	case 10269ULL: goto x86_l_281d;
	case 10271ULL: goto x86_l_281f;
	case 10276ULL: goto x86_l_2824;
	case 10284ULL: goto x86_l_282c;
	case 10288ULL: goto x86_l_2830;
	case 10292ULL: goto x86_l_2834;
	case 10299ULL: goto x86_l_283b;
	case 10304ULL: goto x86_l_2840;
	case 10309ULL: goto x86_l_2845;
	case 10311ULL: goto x86_l_2847;
	case 10314ULL: goto x86_l_284a;
	case 10321ULL: goto x86_l_2851;
	case 10325ULL: goto x86_l_2855;
	case 10329ULL: goto x86_l_2859;
	case 10334ULL: goto x86_l_285e;
	case 10339ULL: goto x86_l_2863;
	case 10341ULL: goto x86_l_2865;
	case 10346ULL: goto x86_l_286a;
	case 10352ULL: goto x86_l_2870;
	case 10356ULL: goto x86_l_2874;
	case 10361ULL: goto x86_l_2879;
	case 10364ULL: goto x86_l_287c;
	case 10370ULL: goto x86_l_2882;
	case 10377ULL: goto x86_l_2889;
	case 10381ULL: goto x86_l_288d;
	case 10384ULL: goto x86_l_2890;
	case 10392ULL: goto x86_l_2898;
	case 10396ULL: goto x86_l_289c;
	case 10400ULL: goto x86_l_28a0;
	case 10403ULL: goto x86_l_28a3;
	case 10409ULL: goto x86_l_28a9;
	case 10414ULL: goto x86_l_28ae;
	case 10421ULL: goto x86_l_28b5;
	case 10429ULL: goto x86_l_28bd;
	case 10431ULL: goto x86_l_28bf;
	case 10437ULL: goto x86_l_28c5;
	case 10441ULL: goto x86_l_28c9;
	case 10448ULL: goto x86_l_28d0;
	case 10451ULL: goto x86_l_28d3;
	case 10459ULL: goto x86_l_28db;
	case 10465ULL: goto x86_l_28e1;
	case 10468ULL: goto x86_l_28e4;
	case 10474ULL: goto x86_l_28ea;
	case 10482ULL: goto x86_l_28f2;
	case 10485ULL: goto x86_l_28f5;
	case 10493ULL: goto x86_l_28fd;
	case 10497ULL: goto x86_l_2901;
	case 10505ULL: goto x86_l_2909;
	case 10509ULL: goto x86_l_290d;
	case 10513ULL: goto x86_l_2911;
	case 10520ULL: goto x86_l_2918;
	case 10523ULL: goto x86_l_291b;
	case 10529ULL: goto x86_l_2921;
	case 10533ULL: goto x86_l_2925;
	case 10537ULL: goto x86_l_2929;
	case 10541ULL: goto x86_l_292d;
	case 10546ULL: goto x86_l_2932;
	case 10551ULL: goto x86_l_2937;
	case 10554ULL: goto x86_l_293a;
	case 10562ULL: goto x86_l_2942;
	case 10564ULL: goto x86_l_2944;
	case 10569ULL: goto x86_l_2949;
	case 10571ULL: goto x86_l_294b;
	case 10573ULL: goto x86_l_294d;
	case 10577ULL: goto x86_l_2951;
	case 10581ULL: goto x86_l_2955;
	case 10583ULL: goto x86_l_2957;
	case 10586ULL: goto x86_l_295a;
	case 10589ULL: goto x86_l_295d;
	case 10593ULL: goto x86_l_2961;
	case 10596ULL: goto x86_l_2964;
	case 10604ULL: goto x86_l_296c;
	case 10609ULL: goto x86_l_2971;
	case 10617ULL: goto x86_l_2979;
	case 10622ULL: goto x86_l_297e;
	case 10625ULL: goto x86_l_2981;
	case 10634ULL: goto x86_l_298a;
	case 10640ULL: goto x86_l_2990;
	case 10648ULL: goto x86_l_2998;
	case 10652ULL: goto x86_l_299c;
	case 10658ULL: goto x86_l_29a2;
	case 10663ULL: goto x86_l_29a7;
	case 10668ULL: goto x86_l_29ac;
	case 10673ULL: goto x86_l_29b1;
	case 10675ULL: goto x86_l_29b3;
	case 10680ULL: goto x86_l_29b8;
	case 10682ULL: goto x86_l_29ba;
	case 10688ULL: goto x86_l_29c0;
	case 10693ULL: goto x86_l_29c5;
	case 10696ULL: goto x86_l_29c8;
	case 10699ULL: goto x86_l_29cb;
	case 10702ULL: goto x86_l_29ce;
	case 10706ULL: goto x86_l_29d2;
	case 10709ULL: goto x86_l_29d5;
	case 10713ULL: goto x86_l_29d9;
	case 10718ULL: goto x86_l_29de;
	case 10723ULL: goto x86_l_29e3;
	case 10730ULL: goto x86_l_29ea;
	case 10736ULL: goto x86_l_29f0;
	case 10740ULL: goto x86_l_29f4;
	case 10743ULL: goto x86_l_29f7;
	case 10746ULL: goto x86_l_29fa;
	case 10752ULL: goto x86_l_2a00;
	case 10757ULL: goto x86_l_2a05;
	case 10762ULL: goto x86_l_2a0a;
	case 10767ULL: goto x86_l_2a0f;
	case 10772ULL: goto x86_l_2a14;
	case 10774ULL: goto x86_l_2a16;
	case 10779ULL: goto x86_l_2a1b;
	case 10781ULL: goto x86_l_2a1d;
	case 10787ULL: goto x86_l_2a23;
	case 10792ULL: goto x86_l_2a28;
	case 10797ULL: goto x86_l_2a2d;
	case 10802ULL: goto x86_l_2a32;
	case 10805ULL: goto x86_l_2a35;
	case 10807ULL: goto x86_l_2a37;
	case 10810ULL: goto x86_l_2a3a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2369:
	/* 0x2369: ja     2971 <generic_retkprobe_event+0x2971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2971;
	}
x86_l_236f:
	/* 0x236f: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2379:
	/* 0x2379: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_237d:
	/* 0x237d: jae    2971 <generic_retkprobe_event+0x2971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2971;
	}
x86_l_2383:
	/* 0x2383: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2387:
	/* 0x2387: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_238c:
	/* 0x238c: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2391:
	/* 0x2391: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2396:
	/* 0x2396: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2399:
	/* 0x2399: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_239e:
	/* 0x239e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23a0:
	/* 0x23a0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23a3:
	/* 0x23a3: js     26c2 <generic_retkprobe_event+0x26c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_26c2;
	}
x86_l_23a9:
	/* 0x23a9: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_23ae:
	/* 0x23ae: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_23b1:
	/* 0x23b1: jg     23d5 <generic_retkprobe_event+0x23d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_23d5;
	}
x86_l_23b3:
	/* 0x23b3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23b5:
	/* 0x23b5: je     23fe <generic_retkprobe_event+0x23fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23fe;
	}
x86_l_23b7:
	/* 0x23b7: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_23ba:
	/* 0x23ba: je     23fe <generic_retkprobe_event+0x23fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23fe;
	}
x86_l_23bc:
	/* 0x23bc: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_23bf:
	/* 0x23bf: jne    24ee <generic_retkprobe_event+0x24ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24ee;
	}
x86_l_23c5:
	/* 0x23c5: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_23cc:
	/* 0x23cc: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_23d0:
	/* 0x23d0: jmp    24f3 <generic_retkprobe_event+0x24f3> */
	goto x86_l_24f3;
x86_l_23d5:
	/* 0x23d5: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_23d8:
	/* 0x23d8: je     24db <generic_retkprobe_event+0x24db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24db;
	}
x86_l_23de:
	/* 0x23de: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_23e1:
	/* 0x23e1: je     23fe <generic_retkprobe_event+0x23fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23fe;
	}
x86_l_23e3:
	/* 0x23e3: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_23e8:
	/* 0x23e8: jne    24ee <generic_retkprobe_event+0x24ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24ee;
	}
x86_l_23ee:
	/* 0x23ee: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_23f5:
	/* 0x23f5: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_23f9:
	/* 0x23f9: jmp    24f3 <generic_retkprobe_event+0x24f3> */
	goto x86_l_24f3;
x86_l_23fe:
	/* 0x23fe: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2403:
	/* 0x2403: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_240a:
	/* 0x240a: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_240f:
	/* 0x240f: jmp    24f3 <generic_retkprobe_event+0x24f3> */
	goto x86_l_24f3;
x86_l_2414:
	/* 0x2414: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2417:
	/* 0x2417: cmp    QWORD PTR [rsp+0x80],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813893ULL);
x86_l_2420:
	/* 0x2420: jb     203f <generic_retkprobe_event+0x203f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8255ULL;
	}
x86_l_2426:
	/* 0x2426: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_242e:
	/* 0x242e: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2432:
	/* 0x2432: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2438:
	/* 0x2438: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_243d:
	/* 0x243d: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2442:
	/* 0x2442: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2447:
	/* 0x2447: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2449:
	/* 0x2449: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_244e:
	/* 0x244e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2450:
	/* 0x2450: js     2adb <generic_retkprobe_event+0x2adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10971ULL;
	}
x86_l_2456:
	/* 0x2456: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_245b:
	/* 0x245b: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_245e:
	/* 0x245e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2461:
	/* 0x2461: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_2464:
	/* 0x2464: cmovb  rbx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_2468:
	/* 0x2468: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_246b:
	/* 0x246b: cmovne rdx,rbx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RBX, X86_WIDTH_64, X86_CC_NE);
x86_l_246f:
	/* 0x246f: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2474:
	/* 0x2474: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2478:
	/* 0x2478: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_247f:
	/* 0x247f: ja     2adb <generic_retkprobe_event+0x2adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10971ULL;
	}
x86_l_2485:
	/* 0x2485: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_2488:
	/* 0x2488: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_248b:
	/* 0x248b: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_248e:
	/* 0x248e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2494:
	/* 0x2494: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2499:
	/* 0x2499: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_249e:
	/* 0x249e: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_24a3:
	/* 0x24a3: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24a7:
	/* 0x24a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24a9:
	/* 0x24a9: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_24ae:
	/* 0x24ae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24b0:
	/* 0x24b0: js     2adb <generic_retkprobe_event+0x2adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10971ULL;
	}
x86_l_24b6:
	/* 0x24b6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24bb:
	/* 0x24bb: add    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_24bf:
	/* 0x24bf: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24c4:
	/* 0x24c4: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_24c7:
	/* 0x24c7: je     297e <generic_retkprobe_event+0x297e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_297e;
	}
x86_l_24cd:
	/* 0x24cd: sub    r15,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_24d0:
	/* 0x24d0: jne    2981 <generic_retkprobe_event+0x2981> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2981;
	}
x86_l_24d6:
	/* 0x24d6: jmp    203f <generic_retkprobe_event+0x203f> */
	return 8255ULL;
x86_l_24db:
	/* 0x24db: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_24e0:
	/* 0x24e0: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_24e7:
	/* 0x24e7: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_24ec:
	/* 0x24ec: jmp    24f3 <generic_retkprobe_event+0x24f3> */
	goto x86_l_24f3;
x86_l_24ee:
	/* 0x24ee: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_24f3:
	/* 0x24f3: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_24f8:
	/* 0x24f8: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24fd:
	/* 0x24fd: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2502:
	/* 0x2502: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2506:
	/* 0x2506: ja     2971 <generic_retkprobe_event+0x2971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2971;
	}
x86_l_250c:
	/* 0x250c: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2516:
	/* 0x2516: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_251a:
	/* 0x251a: jae    2971 <generic_retkprobe_event+0x2971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2971;
	}
x86_l_2520:
	/* 0x2520: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2524:
	/* 0x2524: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2529:
	/* 0x2529: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_252e:
	/* 0x252e: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2533:
	/* 0x2533: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2536:
	/* 0x2536: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_253b:
	/* 0x253b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_253d:
	/* 0x253d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2540:
	/* 0x2540: js     26c2 <generic_retkprobe_event+0x26c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_26c2;
	}
x86_l_2546:
	/* 0x2546: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_254b:
	/* 0x254b: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_254e:
	/* 0x254e: jg     256b <generic_retkprobe_event+0x256b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_256b;
	}
x86_l_2550:
	/* 0x2550: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2552:
	/* 0x2552: je     2589 <generic_retkprobe_event+0x2589> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2589;
	}
x86_l_2554:
	/* 0x2554: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2557:
	/* 0x2557: je     2589 <generic_retkprobe_event+0x2589> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2589;
	}
x86_l_2559:
	/* 0x2559: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_255c:
	/* 0x255c: jne    25af <generic_retkprobe_event+0x25af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25af;
	}
x86_l_255e:
	/* 0x255e: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2565:
	/* 0x2565: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2569:
	/* 0x2569: jmp    25b4 <generic_retkprobe_event+0x25b4> */
	goto x86_l_25b4;
x86_l_256b:
	/* 0x256b: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_256e:
	/* 0x256e: je     259c <generic_retkprobe_event+0x259c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_259c;
	}
x86_l_2570:
	/* 0x2570: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2573:
	/* 0x2573: je     2589 <generic_retkprobe_event+0x2589> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2589;
	}
x86_l_2575:
	/* 0x2575: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_257a:
	/* 0x257a: jne    25af <generic_retkprobe_event+0x25af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25af;
	}
x86_l_257c:
	/* 0x257c: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2583:
	/* 0x2583: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2587:
	/* 0x2587: jmp    25b4 <generic_retkprobe_event+0x25b4> */
	goto x86_l_25b4;
x86_l_2589:
	/* 0x2589: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_258e:
	/* 0x258e: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2595:
	/* 0x2595: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_259a:
	/* 0x259a: jmp    25b4 <generic_retkprobe_event+0x25b4> */
	goto x86_l_25b4;
x86_l_259c:
	/* 0x259c: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_25a1:
	/* 0x25a1: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_25a8:
	/* 0x25a8: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_25ad:
	/* 0x25ad: jmp    25b4 <generic_retkprobe_event+0x25b4> */
	goto x86_l_25b4;
x86_l_25af:
	/* 0x25af: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_25b4:
	/* 0x25b4: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_25b9:
	/* 0x25b9: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25be:
	/* 0x25be: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_25c3:
	/* 0x25c3: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_25c7:
	/* 0x25c7: ja     2971 <generic_retkprobe_event+0x2971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2971;
	}
x86_l_25cd:
	/* 0x25cd: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_25d7:
	/* 0x25d7: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_25db:
	/* 0x25db: jae    2971 <generic_retkprobe_event+0x2971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2971;
	}
x86_l_25e1:
	/* 0x25e1: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_25e5:
	/* 0x25e5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25ea:
	/* 0x25ea: movzx  edx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_25ef:
	/* 0x25ef: add    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_25f4:
	/* 0x25f4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_25f7:
	/* 0x25f7: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_25fc:
	/* 0x25fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25fe:
	/* 0x25fe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2601:
	/* 0x2601: js     26c2 <generic_retkprobe_event+0x26c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_26c2;
	}
x86_l_2607:
	/* 0x2607: movzx  eax,BYTE PTR [r13+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_260c:
	/* 0x260c: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_260f:
	/* 0x260f: jg     262c <generic_retkprobe_event+0x262c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_262c;
	}
x86_l_2611:
	/* 0x2611: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2613:
	/* 0x2613: je     264a <generic_retkprobe_event+0x264a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_264a;
	}
x86_l_2615:
	/* 0x2615: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2618:
	/* 0x2618: je     264a <generic_retkprobe_event+0x264a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_264a;
	}
x86_l_261a:
	/* 0x261a: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_261d:
	/* 0x261d: jne    2670 <generic_retkprobe_event+0x2670> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2670;
	}
x86_l_261f:
	/* 0x261f: mov    WORD PTR [r13+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2626:
	/* 0x2626: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_262a:
	/* 0x262a: jmp    2675 <generic_retkprobe_event+0x2675> */
	goto x86_l_2675;
x86_l_262c:
	/* 0x262c: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_262f:
	/* 0x262f: je     265d <generic_retkprobe_event+0x265d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_265d;
	}
x86_l_2631:
	/* 0x2631: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2634:
	/* 0x2634: je     264a <generic_retkprobe_event+0x264a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_264a;
	}
x86_l_2636:
	/* 0x2636: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_263b:
	/* 0x263b: jne    2670 <generic_retkprobe_event+0x2670> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2670;
	}
x86_l_263d:
	/* 0x263d: mov    WORD PTR [r13+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2644:
	/* 0x2644: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2648:
	/* 0x2648: jmp    2675 <generic_retkprobe_event+0x2675> */
	goto x86_l_2675;
x86_l_264a:
	/* 0x264a: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_264f:
	/* 0x264f: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2656:
	/* 0x2656: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_265b:
	/* 0x265b: jmp    2675 <generic_retkprobe_event+0x2675> */
	goto x86_l_2675;
x86_l_265d:
	/* 0x265d: movzx  eax,BYTE PTR [r13+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2662:
	/* 0x2662: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2669:
	/* 0x2669: mov    WORD PTR [r13+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_266e:
	/* 0x266e: jmp    2675 <generic_retkprobe_event+0x2675> */
	goto x86_l_2675;
x86_l_2670:
	/* 0x2670: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2675:
	/* 0x2675: add    ax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_267a:
	/* 0x267a: mov    WORD PTR [r13+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_267f:
	/* 0x267f: movzx  ecx,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2684:
	/* 0x2684: cmp    rcx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 60ULL);
x86_l_2688:
	/* 0x2688: ja     2971 <generic_retkprobe_event+0x2971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2971;
	}
x86_l_268e:
	/* 0x268e: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2698:
	/* 0x2698: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_269c:
	/* 0x269c: jae    2971 <generic_retkprobe_event+0x2971> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2971;
	}
x86_l_26a2:
	/* 0x26a2: mov    BYTE PTR [r13+0x5],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_26a6:
	/* 0x26a6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26ab:
	/* 0x26ab: movzx  ecx,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_26b0:
	/* 0x26b0: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26b5:
	/* 0x26b5: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26b8:
	/* 0x26b8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_26bb:
	/* 0x26bb: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_26c0:
	/* 0x26c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26c2:
	/* 0x26c2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26c4:
	/* 0x26c4: mov    BYTE PTR [rsp+0xc0],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_26cb:
	/* 0x26cb: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_26ce:
	/* 0x26ce: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26d2:
	/* 0x26d2: mov    WORD PTR [rbx+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_26d9:
	/* 0x26d9: mov    WORD PTR [rbx+0xc2],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655434ULL);
x86_l_26e2:
	/* 0x26e2: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26e7:
	/* 0x26e7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26ec:
	/* 0x26ec: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26f1:
	/* 0x26f1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_26f6:
	/* 0x26f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f8:
	/* 0x26f8: lea    rdi,[rbx+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_26ff:
	/* 0x26ff: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2703:
	/* 0x2703: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2708:
	/* 0x2708: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_270d:
	/* 0x270d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2710:
	/* 0x2710: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2712:
	/* 0x2712: movzx  eax,BYTE PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 192ULL);
x86_l_271a:
	/* 0x271a: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_271d:
	/* 0x271d: je     2767 <generic_retkprobe_event+0x2767> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2767;
	}
x86_l_271f:
	/* 0x271f: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2722:
	/* 0x2722: jne    27ad <generic_retkprobe_event+0x27ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_27ad;
	}
x86_l_2728:
	/* 0x2728: mov    rbx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_272d:
	/* 0x272d: movzx  r12d,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_2736:
	/* 0x2736: lea    rdx,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_273a:
	/* 0x273a: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_273e:
	/* 0x273e: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2745:
	/* 0x2745: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_274a:
	/* 0x274a: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_274f:
	/* 0x274f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2751:
	/* 0x2751: lea    rdi,[r13+0xbe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 190ULL);
x86_l_2758:
	/* 0x2758: lea    rdx,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_275c:
	/* 0x275c: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2760:
	/* 0x2760: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2765:
	/* 0x2765: jmp    27a4 <generic_retkprobe_event+0x27a4> */
	goto x86_l_27a4;
x86_l_2767:
	/* 0x2767: mov    rbx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_276c:
	/* 0x276c: movzx  r12d,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_2775:
	/* 0x2775: lea    rdx,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_2779:
	/* 0x2779: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_277d:
	/* 0x277d: lea    rdi,[r13+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2784:
	/* 0x2784: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2789:
	/* 0x2789: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_278e:
	/* 0x278e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2790:
	/* 0x2790: lea    rdi,[r13+0xbe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 190ULL);
x86_l_2797:
	/* 0x2797: lea    rdx,[rbx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_279b:
	/* 0x279b: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_279f:
	/* 0x279f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27a4:
	/* 0x27a4: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_27a9:
	/* 0x27a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27ab:
	/* 0x27ab: jmp    27bb <generic_retkprobe_event+0x27bb> */
	goto x86_l_27bb;
x86_l_27ad:
	/* 0x27ad: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27b1:
	/* 0x27b1: mov    DWORD PTR [rax+0xbc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_27bb:
	/* 0x27bb: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27bf:
	/* 0x27bf: movzx  ecx,WORD PTR [rax+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_27c6:
	/* 0x27c6: movzx  edx,WORD PTR [rax+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_27cd:
	/* 0x27cd: movbe  WORD PTR [rax+0xbc],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_27d6:
	/* 0x27d6: movbe  WORD PTR [rax+0xbe],dx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 190ULL);
x86_l_27df:
	/* 0x27df: add    rbp,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_27e6:
	/* 0x27e6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27eb:
	/* 0x27eb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27f0:
	/* 0x27f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27f5:
	/* 0x27f5: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_27f8:
	/* 0x27f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27fa:
	/* 0x27fa: cmp    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2800:
	/* 0x2800: je     2865 <generic_retkprobe_event+0x2865> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2865;
	}
x86_l_2802:
	/* 0x2802: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2807:
	/* 0x2807: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_280c:
	/* 0x280c: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_2810:
	/* 0x2810: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2818:
	/* 0x2818: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_281d:
	/* 0x281d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_281f:
	/* 0x281f: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2824:
	/* 0x2824: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_282c:
	/* 0x282c: lea    rdx,[rbx+r12*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_2830:
	/* 0x2830: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2834:
	/* 0x2834: lea    rdi,[r13+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_283b:
	/* 0x283b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2840:
	/* 0x2840: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2845:
	/* 0x2845: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2847:
	/* 0x2847: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_284a:
	/* 0x284a: add    rdi,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_2851:
	/* 0x2851: lea    rdx,[rbx+r12*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 3), 0ULL);
x86_l_2855:
	/* 0x2855: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2859:
	/* 0x2859: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_285e:
	/* 0x285e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2863:
	/* 0x2863: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2865:
	/* 0x2865: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_286a:
	/* 0x286a: mov    r13d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 64ULL);
x86_l_2870:
	/* 0x2870: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2874:
	/* 0x2874: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2879:
	/* 0x2879: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_287c:
	/* 0x287c: js     1fde <generic_retkprobe_event+0x1fde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8158ULL;
	}
x86_l_2882:
	/* 0x2882: and    r13d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_2889:
	/* 0x2889: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_288d:
	/* 0x288d: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_2890:
	/* 0x2890: mov    r13,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2898:
	/* 0x2898: add    rbx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_289c:
	/* 0x289c: mov    eax,DWORD PTR [r15+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_28a0:
	/* 0x28a0: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_28a3:
	/* 0x28a3: jne    302 <generic_retkprobe_event+0x302> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 770ULL;
	}
x86_l_28a9:
	/* 0x28a9: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_28ae:
	/* 0x28ae: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_28b5:
	/* 0x28b5: lea    rsi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_28bd:
	/* 0x28bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28bf:
	/* 0x28bf: and    ebx,0x1fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 8191ULL);
x86_l_28c5:
	/* 0x28c5: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_28c9:
	/* 0x28c9: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_28d0:
	/* 0x28d0: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_28d3:
	/* 0x28d3: mov    QWORD PTR [rsp+0xf0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_28db:
	/* 0x28db: je     210 <generic_retkprobe_event+0x210> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 528ULL;
	}
x86_l_28e1:
	/* 0x28e1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_28e4:
	/* 0x28e4: jne    2af6 <generic_retkprobe_event+0x2af6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10998ULL;
	}
x86_l_28ea:
	/* 0x28ea: mov    QWORD PTR [rsp+0x80],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_28f2:
	/* 0x28f2: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_28f5:
	/* 0x28f5: mov    DWORD PTR [r12+rbx*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_28fd:
	/* 0x28fd: lea    r14,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2901:
	/* 0x2901: mov    rbp,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2909:
	/* 0x2909: lea    r13,[r12+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_290d:
	/* 0x290d: add    r13,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2911:
	/* 0x2911: cmp    rbp,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4095ULL);
x86_l_2918:
	/* 0x2918: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_291b:
	/* 0x291b: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_2921:
	/* 0x2921: cmovb  r12,rbp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_64, X86_CC_B);
x86_l_2925:
	/* 0x2925: lea    rdi,[rax+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_2929:
	/* 0x2929: add    rdi,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_292d:
	/* 0x292d: mov    ebx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4ULL);
x86_l_2932:
	/* 0x2932: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2937:
	/* 0x2937: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_293a:
	/* 0x293a: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2942:
	/* 0x2942: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2944:
	/* 0x2944: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2949:
	/* 0x2949: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_294b:
	/* 0x294b: js     295a <generic_retkprobe_event+0x295a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_295a;
	}
x86_l_294d:
	/* 0x294d: mov    DWORD PTR [r13+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2951:
	/* 0x2951: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2955:
	/* 0x2955: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_2957:
	/* 0x2957: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_295a:
	/* 0x295a: add    rbx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_295d:
	/* 0x295d: mov    DWORD PTR [r13+0x0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2961:
	/* 0x2961: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_2964:
	/* 0x2964: mov    r14,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_296c:
	/* 0x296c: jmp    2af6 <generic_retkprobe_event+0x2af6> */
	return 10998ULL;
x86_l_2971:
	/* 0x2971: mov    WORD PTR [rsp+0xc8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2979:
	/* 0x2979: jmp    26c4 <generic_retkprobe_event+0x26c4> */
	goto x86_l_26c4;
x86_l_297e:
	/* 0x297e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2981:
	/* 0x2981: cmp    QWORD PTR [rsp+0x80],0x5 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813893ULL);
x86_l_298a:
	/* 0x298a: je     203f <generic_retkprobe_event+0x203f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8255ULL;
	}
x86_l_2990:
	/* 0x2990: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2998:
	/* 0x2998: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_299c:
	/* 0x299c: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_29a2:
	/* 0x29a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29a7:
	/* 0x29a7: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_29ac:
	/* 0x29ac: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_29b1:
	/* 0x29b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29b3:
	/* 0x29b3: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_29b8:
	/* 0x29b8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29ba:
	/* 0x29ba: js     2adb <generic_retkprobe_event+0x2adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10971ULL;
	}
x86_l_29c0:
	/* 0x29c0: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_29c5:
	/* 0x29c5: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_29c8:
	/* 0x29c8: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_29cb:
	/* 0x29cb: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_29ce:
	/* 0x29ce: cmovb  r12,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RDX, X86_WIDTH_64, X86_CC_B);
x86_l_29d2:
	/* 0x29d2: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_29d5:
	/* 0x29d5: cmovne rdx,r12 */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R12, X86_WIDTH_64, X86_CC_NE);
x86_l_29d9:
	/* 0x29d9: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_29de:
	/* 0x29de: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29e3:
	/* 0x29e3: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_29ea:
	/* 0x29ea: ja     2adb <generic_retkprobe_event+0x2adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10971ULL;
	}
x86_l_29f0:
	/* 0x29f0: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29f4:
	/* 0x29f4: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29f7:
	/* 0x29f7: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_29fa:
	/* 0x29fa: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2a00:
	/* 0x2a00: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2a05:
	/* 0x2a05: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a0a:
	/* 0x2a0a: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2a0f:
	/* 0x2a0f: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a14:
	/* 0x2a14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a16:
	/* 0x2a16: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2a1b:
	/* 0x2a1b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a1d:
	/* 0x2a1d: js     2adb <generic_retkprobe_event+0x2adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10971ULL;
	}
x86_l_2a23:
	/* 0x2a23: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a28:
	/* 0x2a28: add    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_2a2d:
	/* 0x2a2d: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a32:
	/* 0x2a32: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_2a35:
	/* 0x2a35: je     2a41 <generic_retkprobe_event+0x2a41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10817ULL;
	}
x86_l_2a37:
	/* 0x2a37: sub    r15,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2a3a:
	/* 0x2a3a: jne    2a44 <generic_retkprobe_event+0x2a44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10820ULL;
	}
	return 10812ULL;
}

static __noinline __u64 tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10812ULL: goto x86_l_2a3c;
	case 10817ULL: goto x86_l_2a41;
	case 10820ULL: goto x86_l_2a44;
	case 10829ULL: goto x86_l_2a4d;
	case 10835ULL: goto x86_l_2a53;
	case 10843ULL: goto x86_l_2a5b;
	case 10847ULL: goto x86_l_2a5f;
	case 10853ULL: goto x86_l_2a65;
	case 10858ULL: goto x86_l_2a6a;
	case 10863ULL: goto x86_l_2a6f;
	case 10868ULL: goto x86_l_2a74;
	case 10870ULL: goto x86_l_2a76;
	case 10875ULL: goto x86_l_2a7b;
	case 10877ULL: goto x86_l_2a7d;
	case 10879ULL: goto x86_l_2a7f;
	case 10884ULL: goto x86_l_2a84;
	case 10887ULL: goto x86_l_2a87;
	case 10890ULL: goto x86_l_2a8a;
	case 10893ULL: goto x86_l_2a8d;
	case 10897ULL: goto x86_l_2a91;
	case 10900ULL: goto x86_l_2a94;
	case 10904ULL: goto x86_l_2a98;
	case 10909ULL: goto x86_l_2a9d;
	case 10916ULL: goto x86_l_2aa4;
	case 10918ULL: goto x86_l_2aa6;
	case 10923ULL: goto x86_l_2aab;
	case 10926ULL: goto x86_l_2aae;
	case 10932ULL: goto x86_l_2ab4;
	case 10937ULL: goto x86_l_2ab9;
	case 10942ULL: goto x86_l_2abe;
	case 10947ULL: goto x86_l_2ac3;
	case 10950ULL: goto x86_l_2ac6;
	case 10952ULL: goto x86_l_2ac8;
	case 10957ULL: goto x86_l_2acd;
	case 10959ULL: goto x86_l_2acf;
	case 10961ULL: goto x86_l_2ad1;
	case 10966ULL: goto x86_l_2ad6;
	case 10971ULL: goto x86_l_2adb;
	case 10976ULL: goto x86_l_2ae0;
	case 10981ULL: goto x86_l_2ae5;
	case 10984ULL: goto x86_l_2ae8;
	case 10987ULL: goto x86_l_2aeb;
	case 10990ULL: goto x86_l_2aee;
	case 10998ULL: goto x86_l_2af6;
	case 11003ULL: goto x86_l_2afb;
	case 11005ULL: goto x86_l_2afd;
	case 11008ULL: goto x86_l_2b00;
	case 11013ULL: goto x86_l_2b05;
	case 11018ULL: goto x86_l_2b0a;
	case 11026ULL: goto x86_l_2b12;
	case 11034ULL: goto x86_l_2b1a;
	case 11039ULL: goto x86_l_2b1f;
	case 11041ULL: goto x86_l_2b21;
	case 11048ULL: goto x86_l_2b28;
	case 11052ULL: goto x86_l_2b2c;
	case 11057ULL: goto x86_l_2b31;
	case 11064ULL: goto x86_l_2b38;
	case 11069ULL: goto x86_l_2b3d;
	case 11071ULL: goto x86_l_2b3f;
	case 11074ULL: goto x86_l_2b42;
	case 11076ULL: goto x86_l_2b44;
	case 11079ULL: goto x86_l_2b47;
	case 11084ULL: goto x86_l_2b4c;
	case 11090ULL: goto x86_l_2b52;
	case 11095ULL: goto x86_l_2b57;
	case 11102ULL: goto x86_l_2b5e;
	case 11107ULL: goto x86_l_2b63;
	case 11112ULL: goto x86_l_2b68;
	case 11115ULL: goto x86_l_2b6b;
	case 11117ULL: goto x86_l_2b6d;
	case 11123ULL: goto x86_l_2b73;
	case 11129ULL: goto x86_l_2b79;
	case 11134ULL: goto x86_l_2b7e;
	case 11139ULL: goto x86_l_2b83;
	case 11144ULL: goto x86_l_2b88;
	case 11152ULL: goto x86_l_2b90;
	case 11157ULL: goto x86_l_2b95;
	case 11159ULL: goto x86_l_2b97;
	case 11166ULL: goto x86_l_2b9e;
	case 11170ULL: goto x86_l_2ba2;
	case 11175ULL: goto x86_l_2ba7;
	case 11182ULL: goto x86_l_2bae;
	case 11187ULL: goto x86_l_2bb3;
	case 11189ULL: goto x86_l_2bb5;
	case 11192ULL: goto x86_l_2bb8;
	case 11194ULL: goto x86_l_2bba;
	case 11197ULL: goto x86_l_2bbd;
	case 11202ULL: goto x86_l_2bc2;
	case 11208ULL: goto x86_l_2bc8;
	case 11213ULL: goto x86_l_2bcd;
	case 11218ULL: goto x86_l_2bd2;
	case 11223ULL: goto x86_l_2bd7;
	case 11228ULL: goto x86_l_2bdc;
	case 11233ULL: goto x86_l_2be1;
	case 11235ULL: goto x86_l_2be3;
	case 11241ULL: goto x86_l_2be9;
	case 11247ULL: goto x86_l_2bef;
	case 11252ULL: goto x86_l_2bf4;
	case 11257ULL: goto x86_l_2bf9;
	case 11262ULL: goto x86_l_2bfe;
	case 11270ULL: goto x86_l_2c06;
	case 11275ULL: goto x86_l_2c0b;
	case 11277ULL: goto x86_l_2c0d;
	case 11284ULL: goto x86_l_2c14;
	case 11288ULL: goto x86_l_2c18;
	case 11293ULL: goto x86_l_2c1d;
	case 11300ULL: goto x86_l_2c24;
	case 11305ULL: goto x86_l_2c29;
	case 11307ULL: goto x86_l_2c2b;
	case 11310ULL: goto x86_l_2c2e;
	case 11312ULL: goto x86_l_2c30;
	case 11315ULL: goto x86_l_2c33;
	case 11320ULL: goto x86_l_2c38;
	case 11326ULL: goto x86_l_2c3e;
	case 11331ULL: goto x86_l_2c43;
	case 11336ULL: goto x86_l_2c48;
	case 11341ULL: goto x86_l_2c4d;
	case 11346ULL: goto x86_l_2c52;
	case 11351ULL: goto x86_l_2c57;
	case 11353ULL: goto x86_l_2c59;
	case 11359ULL: goto x86_l_2c5f;
	case 11361ULL: goto x86_l_2c61;
	case 11366ULL: goto x86_l_2c66;
	case 11371ULL: goto x86_l_2c6b;
	case 11376ULL: goto x86_l_2c70;
	case 11384ULL: goto x86_l_2c78;
	case 11389ULL: goto x86_l_2c7d;
	case 11391ULL: goto x86_l_2c7f;
	case 11398ULL: goto x86_l_2c86;
	case 11402ULL: goto x86_l_2c8a;
	case 11407ULL: goto x86_l_2c8f;
	case 11414ULL: goto x86_l_2c96;
	case 11419ULL: goto x86_l_2c9b;
	case 11421ULL: goto x86_l_2c9d;
	case 11424ULL: goto x86_l_2ca0;
	case 11426ULL: goto x86_l_2ca2;
	case 11429ULL: goto x86_l_2ca5;
	case 11434ULL: goto x86_l_2caa;
	case 11436ULL: goto x86_l_2cac;
	case 11441ULL: goto x86_l_2cb1;
	case 11446ULL: goto x86_l_2cb6;
	case 11451ULL: goto x86_l_2cbb;
	case 11456ULL: goto x86_l_2cc0;
	case 11461ULL: goto x86_l_2cc5;
	case 11463ULL: goto x86_l_2cc7;
	case 11466ULL: goto x86_l_2cca;
	case 11473ULL: goto x86_l_2cd1;
	case 11477ULL: goto x86_l_2cd5;
	case 11482ULL: goto x86_l_2cda;
	case 11484ULL: goto x86_l_2cdc;
	case 11488ULL: goto x86_l_2ce0;
	case 11491ULL: goto x86_l_2ce3;
	case 11493ULL: goto x86_l_2ce5;
	case 11496ULL: goto x86_l_2ce8;
	case 11500ULL: goto x86_l_2cec;
	case 11504ULL: goto x86_l_2cf0;
	case 11508ULL: goto x86_l_2cf4;
	case 11516ULL: goto x86_l_2cfc;
	case 11524ULL: goto x86_l_2d04;
	case 11526ULL: goto x86_l_2d06;
	case 11530ULL: goto x86_l_2d0a;
	case 11534ULL: goto x86_l_2d0e;
	case 11539ULL: goto x86_l_2d13;
	case 11546ULL: goto x86_l_2d1a;
	case 11549ULL: goto x86_l_2d1d;
	case 11554ULL: goto x86_l_2d22;
	case 11556ULL: goto x86_l_2d24;
	case 11561ULL: goto x86_l_2d29;
	case 11563ULL: goto x86_l_2d2b;
	case 11570ULL: goto x86_l_2d32;
	case 11572ULL: goto x86_l_2d34;
	case 11573ULL: goto x86_l_2d35;
	case 11578ULL: goto x86_l_2d3a;
	case 11580ULL: goto x86_l_2d3c;
	case 11582ULL: goto x86_l_2d3e;
	case 11584ULL: goto x86_l_2d40;
	case 11585ULL: goto x86_l_2d41;
	case 11589ULL: goto x86_l_2d45;
	case 11592ULL: goto x86_l_2d48;
	case 11596ULL: goto x86_l_2d4c;
	case 11600ULL: goto x86_l_2d50;
	case 11604ULL: goto x86_l_2d54;
	case 11607ULL: goto x86_l_2d57;
	case 11609ULL: goto x86_l_2d59;
	case 11613ULL: goto x86_l_2d5d;
	case 11619ULL: goto x86_l_2d63;
	case 11624ULL: goto x86_l_2d68;
	case 11629ULL: goto x86_l_2d6d;
	case 11634ULL: goto x86_l_2d72;
	case 11636ULL: goto x86_l_2d74;
	case 11641ULL: goto x86_l_2d79;
	case 11647ULL: goto x86_l_2d7f;
	case 11651ULL: goto x86_l_2d83;
	case 11656ULL: goto x86_l_2d88;
	case 11661ULL: goto x86_l_2d8d;
	case 11666ULL: goto x86_l_2d92;
	case 11669ULL: goto x86_l_2d95;
	case 11671ULL: goto x86_l_2d97;
	case 11676ULL: goto x86_l_2d9c;
	case 11682ULL: goto x86_l_2da2;
	case 11687ULL: goto x86_l_2da7;
	case 11692ULL: goto x86_l_2dac;
	case 11697ULL: goto x86_l_2db1;
	case 11700ULL: goto x86_l_2db4;
	case 11702ULL: goto x86_l_2db6;
	case 11706ULL: goto x86_l_2dba;
	case 11711ULL: goto x86_l_2dbf;
	case 11716ULL: goto x86_l_2dc4;
	case 11721ULL: goto x86_l_2dc9;
	case 11724ULL: goto x86_l_2dcc;
	case 11726ULL: goto x86_l_2dce;
	case 11730ULL: goto x86_l_2dd2;
	case 11734ULL: goto x86_l_2dd6;
	case 11738ULL: goto x86_l_2dda;
	case 11741ULL: goto x86_l_2ddd;
	case 11744ULL: goto x86_l_2de0;
	case 11746ULL: goto x86_l_2de2;
	case 11748ULL: goto x86_l_2de4;
	case 11750ULL: goto x86_l_2de6;
	case 11753ULL: goto x86_l_2de9;
	case 11758ULL: goto x86_l_2dee;
	case 11761ULL: goto x86_l_2df1;
	case 11763ULL: goto x86_l_2df3;
	case 11767ULL: goto x86_l_2df7;
	case 11770ULL: goto x86_l_2dfa;
	case 11774ULL: goto x86_l_2dfe;
	case 11777ULL: goto x86_l_2e01;
	case 11779ULL: goto x86_l_2e03;
	case 11782ULL: goto x86_l_2e06;
	case 11785ULL: goto x86_l_2e09;
	case 11790ULL: goto x86_l_2e0e;
	case 11793ULL: goto x86_l_2e11;
	case 11799ULL: goto x86_l_2e17;
	case 11806ULL: goto x86_l_2e1e;
	case 11812ULL: goto x86_l_2e24;
	case 11814ULL: goto x86_l_2e26;
	case 11820ULL: goto x86_l_2e2c;
	case 11824ULL: goto x86_l_2e30;
	case 11829ULL: goto x86_l_2e35;
	case 11833ULL: goto x86_l_2e39;
	case 11837ULL: goto x86_l_2e3d;
	case 11840ULL: goto x86_l_2e40;
	case 11845ULL: goto x86_l_2e45;
	case 11847ULL: goto x86_l_2e47;
	case 11851ULL: goto x86_l_2e4b;
	case 11856ULL: goto x86_l_2e50;
	case 11860ULL: goto x86_l_2e54;
	case 11862ULL: goto x86_l_2e56;
	case 11864ULL: goto x86_l_2e58;
	case 11868ULL: goto x86_l_2e5c;
	case 11873ULL: goto x86_l_2e61;
	case 11878ULL: goto x86_l_2e66;
	case 11883ULL: goto x86_l_2e6b;
	case 11885ULL: goto x86_l_2e6d;
	case 11889ULL: goto x86_l_2e71;
	case 11894ULL: goto x86_l_2e76;
	case 11896ULL: goto x86_l_2e78;
	case 11900ULL: goto x86_l_2e7c;
	case 11904ULL: goto x86_l_2e80;
	case 11909ULL: goto x86_l_2e85;
	case 11914ULL: goto x86_l_2e8a;
	case 11917ULL: goto x86_l_2e8d;
	case 11919ULL: goto x86_l_2e8f;
	case 11924ULL: goto x86_l_2e94;
	case 11928ULL: goto x86_l_2e98;
	case 11932ULL: goto x86_l_2e9c;
	case 11936ULL: goto x86_l_2ea0;
	case 11938ULL: goto x86_l_2ea2;
	case 11940ULL: goto x86_l_2ea4;
	case 11944ULL: goto x86_l_2ea8;
	case 11949ULL: goto x86_l_2ead;
	case 11953ULL: goto x86_l_2eb1;
	case 11954ULL: goto x86_l_2eb2;
	case 11956ULL: goto x86_l_2eb4;
	case 11958ULL: goto x86_l_2eb6;
	case 11960ULL: goto x86_l_2eb8;
	case 11961ULL: goto x86_l_2eb9;
	case 11965ULL: goto x86_l_2ebd;
	case 11968ULL: goto x86_l_2ec0;
	case 11973ULL: goto x86_l_2ec5;
	case 11976ULL: goto x86_l_2ec8;
	case 11978ULL: goto x86_l_2eca;
	case 11983ULL: goto x86_l_2ecf;
	case 11987ULL: goto x86_l_2ed3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a3c:
	/* 0x2a3c: jmp    203f <generic_retkprobe_event+0x203f> */
	return 8255ULL;
x86_l_2a41:
	/* 0x2a41: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a44:
	/* 0x2a44: cmp    QWORD PTR [rsp+0x80],0x7 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813895ULL);
x86_l_2a4d:
	/* 0x2a4d: jb     203f <generic_retkprobe_event+0x203f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8255ULL;
	}
x86_l_2a53:
	/* 0x2a53: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2a5b:
	/* 0x2a5b: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_2a5f:
	/* 0x2a5f: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_2a65:
	/* 0x2a65: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a6a:
	/* 0x2a6a: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2a6f:
	/* 0x2a6f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2a74:
	/* 0x2a74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a76:
	/* 0x2a76: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2a7b:
	/* 0x2a7b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a7d:
	/* 0x2a7d: js     2adb <generic_retkprobe_event+0x2adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2adb;
	}
x86_l_2a7f:
	/* 0x2a7f: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2a84:
	/* 0x2a84: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_2a87:
	/* 0x2a87: cmp    rax,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_2a8a:
	/* 0x2a8a: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_2a8d:
	/* 0x2a8d: cmovb  r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_B);
x86_l_2a91:
	/* 0x2a91: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_2a94:
	/* 0x2a94: cmove  r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_E);
x86_l_2a98:
	/* 0x2a98: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2a9d:
	/* 0x2a9d: cmp    r12,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 4094ULL);
x86_l_2aa4:
	/* 0x2aa4: ja     2adb <generic_retkprobe_event+0x2adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2adb;
	}
x86_l_2aa6:
	/* 0x2aa6: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2aab:
	/* 0x2aab: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2aae:
	/* 0x2aae: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2ab4:
	/* 0x2ab4: add    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2ab9:
	/* 0x2ab9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2abe:
	/* 0x2abe: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ac3:
	/* 0x2ac3: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2ac6:
	/* 0x2ac6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ac8:
	/* 0x2ac8: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2acd:
	/* 0x2acd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2acf:
	/* 0x2acf: js     2adb <generic_retkprobe_event+0x2adb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2adb;
	}
x86_l_2ad1:
	/* 0x2ad1: add    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2ad6:
	/* 0x2ad6: jmp    2044 <generic_retkprobe_event+0x2044> */
	return 8260ULL;
x86_l_2adb:
	/* 0x2adb: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ae0:
	/* 0x2ae0: mov    rbp,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ae5:
	/* 0x2ae5: mov    DWORD PTR [rax+rbp*1],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_2ae8:
	/* 0x2ae8: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2aeb:
	/* 0x2aeb: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_2aee:
	/* 0x2aee: mov    r13,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2af6:
	/* 0x2af6: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_2afb:
	/* 0x2afb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2afd:
	/* 0x2afd: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2b00:
	/* 0x2b00: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b05:
	/* 0x2b05: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b0a:
	/* 0x2b0a: lea    rdx,[r12+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_2b12:
	/* 0x2b12: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2b1a:
	/* 0x2b1a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b1f:
	/* 0x2b1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b21:
	/* 0x2b21: mov    eax,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2b28:
	/* 0x2b28: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b2c:
	/* 0x2b2c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b31:
	/* 0x2b31: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2b38:
	/* 0x2b38: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b3d:
	/* 0x2b3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b3f:
	/* 0x2b3f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b42:
	/* 0x2b42: je     2b52 <generic_retkprobe_event+0x2b52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b52;
	}
x86_l_2b44:
	/* 0x2b44: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2b47:
	/* 0x2b47: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2b4c:
	/* 0x2b4c: jne    2cca <generic_retkprobe_event+0x2cca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cca;
	}
x86_l_2b52:
	/* 0x2b52: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b57:
	/* 0x2b57: add    r12,0xae0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 2784ULL);
x86_l_2b5e:
	/* 0x2b5e: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b63:
	/* 0x2b63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b68:
	/* 0x2b68: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2b6b:
	/* 0x2b6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b6d:
	/* 0x2b6d: cmp    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2b73:
	/* 0x2b73: je     2cc7 <generic_retkprobe_event+0x2cc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cc7;
	}
x86_l_2b79:
	/* 0x2b79: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b7e:
	/* 0x2b7e: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2b83:
	/* 0x2b83: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2b88:
	/* 0x2b88: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2b90:
	/* 0x2b90: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b95:
	/* 0x2b95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b97:
	/* 0x2b97: mov    eax,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2b9e:
	/* 0x2b9e: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ba2:
	/* 0x2ba2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ba7:
	/* 0x2ba7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2bae:
	/* 0x2bae: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2bb3:
	/* 0x2bb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bb5:
	/* 0x2bb5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2bb8:
	/* 0x2bb8: je     2bc8 <generic_retkprobe_event+0x2bc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bc8;
	}
x86_l_2bba:
	/* 0x2bba: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2bbd:
	/* 0x2bbd: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2bc2:
	/* 0x2bc2: jne    2cca <generic_retkprobe_event+0x2cca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cca;
	}
x86_l_2bc8:
	/* 0x2bc8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bcd:
	/* 0x2bcd: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2bd2:
	/* 0x2bd2: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2bd7:
	/* 0x2bd7: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2bdc:
	/* 0x2bdc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2be1:
	/* 0x2be1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2be3:
	/* 0x2be3: cmp    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2be9:
	/* 0x2be9: je     2cc7 <generic_retkprobe_event+0x2cc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cc7;
	}
x86_l_2bef:
	/* 0x2bef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bf4:
	/* 0x2bf4: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2bf9:
	/* 0x2bf9: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2bfe:
	/* 0x2bfe: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2c06:
	/* 0x2c06: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c0b:
	/* 0x2c0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c0d:
	/* 0x2c0d: mov    eax,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2c14:
	/* 0x2c14: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c18:
	/* 0x2c18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c1d:
	/* 0x2c1d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2c24:
	/* 0x2c24: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c29:
	/* 0x2c29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c2b:
	/* 0x2c2b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c2e:
	/* 0x2c2e: je     2c3e <generic_retkprobe_event+0x2c3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c3e;
	}
x86_l_2c30:
	/* 0x2c30: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2c33:
	/* 0x2c33: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2c38:
	/* 0x2c38: jne    2cca <generic_retkprobe_event+0x2cca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cca;
	}
x86_l_2c3e:
	/* 0x2c3e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c43:
	/* 0x2c43: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2c48:
	/* 0x2c48: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2c4d:
	/* 0x2c4d: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c52:
	/* 0x2c52: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c57:
	/* 0x2c57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c59:
	/* 0x2c59: cmp    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2c5f:
	/* 0x2c5f: je     2cc7 <generic_retkprobe_event+0x2cc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cc7;
	}
x86_l_2c61:
	/* 0x2c61: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c66:
	/* 0x2c66: mov    edx,0xad4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2772ULL);
x86_l_2c6b:
	/* 0x2c6b: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2c70:
	/* 0x2c70: lea    rdi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2c78:
	/* 0x2c78: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c7d:
	/* 0x2c7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c7f:
	/* 0x2c7f: mov    eax,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2c86:
	/* 0x2c86: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c8a:
	/* 0x2c8a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c8f:
	/* 0x2c8f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_2c96:
	/* 0x2c96: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c9b:
	/* 0x2c9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c9d:
	/* 0x2c9d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ca0:
	/* 0x2ca0: je     2cac <generic_retkprobe_event+0x2cac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cac;
	}
x86_l_2ca2:
	/* 0x2ca2: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2ca5:
	/* 0x2ca5: cmp    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2caa:
	/* 0x2caa: jne    2cca <generic_retkprobe_event+0x2cca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cca;
	}
x86_l_2cac:
	/* 0x2cac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cb1:
	/* 0x2cb1: mov    edx,0xae0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2784ULL);
x86_l_2cb6:
	/* 0x2cb6: add    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_2cbb:
	/* 0x2cbb: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2cc0:
	/* 0x2cc0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cc5:
	/* 0x2cc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cc7:
	/* 0x2cc7: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cca:
	/* 0x2cca: mov    DWORD PTR [r14],0x10d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 269ULL);
x86_l_2cd1:
	/* 0x2cd1: mov    DWORD PTR [r14+0x4],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2cd5:
	/* 0x2cd5: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_2cda:
	/* 0x2cda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cdc:
	/* 0x2cdc: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ce0:
	/* 0x2ce0: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_2ce3:
	/* 0x2ce3: je     2cf4 <generic_retkprobe_event+0x2cf4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf4;
	}
x86_l_2ce5:
	/* 0x2ce5: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ce8:
	/* 0x2ce8: mov    DWORD PTR [r14+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cec:
	/* 0x2cec: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cf0:
	/* 0x2cf0: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cf4:
	/* 0x2cf4: mov    DWORD PTR [r14+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_2cfc:
	/* 0x2cfc: mov    rax,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2d04:
	/* 0x2d04: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d06:
	/* 0x2d06: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2d0a:
	/* 0x2d0a: mov    DWORD PTR [r14+0x4],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2d0e:
	/* 0x2d0e: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2d13:
	/* 0x2d13: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&retkprobe_calls)));
x86_l_2d1a:
	/* 0x2d1a: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2d1d:
	/* 0x2d1d: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2d22:
	/* 0x2d22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d24:
	/* 0x2d24: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2d29:
	/* 0x2d29: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_2d2b:
	/* 0x2d2b: add    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_2d32:
	/* 0x2d32: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2d34:
	/* 0x2d34: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2d35:
	/* 0x2d35: jmp    2ed5 <cwd_read_v61+0x19b> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2d3a:
	/* 0x2d3a: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_2d3c:
	/* 0x2d3c: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_2d3e:
	/* 0x2d3e: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2d40:
	/* 0x2d40: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2d41:
	/* 0x2d41: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_2d45:
	/* 0x2d45: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_2d48:
	/* 0x2d48: mov    r15,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d4c:
	/* 0x2d4c: mov    rdx,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d50:
	/* 0x2d50: mov    r14,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d54:
	/* 0x2d54: cmp    r15,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2d57:
	/* 0x2d57: jne    2d63 <cwd_read_v61+0x29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d63;
	}
x86_l_2d59:
	/* 0x2d59: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2d5d:
	/* 0x2d5d: je     2ea4 <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ea4;
	}
x86_l_2d63:
	/* 0x2d63: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d68:
	/* 0x2d68: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d6d:
	/* 0x2d6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d72:
	/* 0x2d72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d74:
	/* 0x2d74: cmp    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2d79:
	/* 0x2d79: je     2e58 <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e58;
	}
x86_l_2d7f:
	/* 0x2d7f: lea    r12,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d83:
	/* 0x2d83: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d88:
	/* 0x2d88: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d8d:
	/* 0x2d8d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d92:
	/* 0x2d92: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2d95:
	/* 0x2d95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d97:
	/* 0x2d97: cmp    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d9c:
	/* 0x2d9c: je     2e58 <cwd_read_v61+0x11e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e58;
	}
x86_l_2da2:
	/* 0x2da2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2da7:
	/* 0x2da7: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2dac:
	/* 0x2dac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2db1:
	/* 0x2db1: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2db4:
	/* 0x2db4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2db6:
	/* 0x2db6: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2dba:
	/* 0x2dba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2dbf:
	/* 0x2dbf: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dc4:
	/* 0x2dc4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2dc9:
	/* 0x2dc9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2dcc:
	/* 0x2dcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dce:
	/* 0x2dce: mov    r14,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dd2:
	/* 0x2dd2: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2dd6:
	/* 0x2dd6: mov    esi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2dda:
	/* 0x2dda: sub    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2ddd:
	/* 0x2ddd: mov    edi,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2de0:
	/* 0x2de0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2de2:
	/* 0x2de2: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2de4:
	/* 0x2de4: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2de6:
	/* 0x2de6: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2de9:
	/* 0x2de9: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_2dee:
	/* 0x2dee: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2df1:
	/* 0x2df1: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2df3:
	/* 0x2df3: seta   r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_A);
x86_l_2df7:
	/* 0x2df7: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_2dfa:
	/* 0x2dfa: cmovb  r8d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_2dfe:
	/* 0x2dfe: add    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2e01:
	/* 0x2e01: mov    eax,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDI, X86_WIDTH_32);
x86_l_2e03:
	/* 0x2e03: sub    eax,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R9, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e06:
	/* 0x2e06: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e09:
	/* 0x2e09: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e0e:
	/* 0x2e0e: sub    rcx,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R9, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2e11:
	/* 0x2e11: jb     2ead <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2ead;
	}
x86_l_2e17:
	/* 0x2e17: cmp    rcx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4095ULL);
x86_l_2e1e:
	/* 0x2e1e: ja     2ead <cwd_read_v61+0x173> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2ead;
	}
x86_l_2e24:
	/* 0x2e24: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2e26:
	/* 0x2e26: jbe    2eb9 <cwd_read_v61+0x17f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2eb9;
	}
x86_l_2e2c:
	/* 0x2e2c: lea    r15,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2e30:
	/* 0x2e30: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2e35:
	/* 0x2e35: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2e39:
	/* 0x2e39: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2e3d:
	/* 0x2e3d: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_2e40:
	/* 0x2e40: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e45:
	/* 0x2e45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e47:
	/* 0x2e47: mov    QWORD PTR [rbx+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e4b:
	/* 0x2e4b: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e50:
	/* 0x2e50: mov    QWORD PTR [rbx+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e54:
	/* 0x2e54: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e56:
	/* 0x2e56: jmp    2ead <cwd_read_v61+0x173> */
	goto x86_l_2ead;
x86_l_2e58:
	/* 0x2e58: lea    rdx,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e5c:
	/* 0x2e5c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e61:
	/* 0x2e61: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e66:
	/* 0x2e66: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e6b:
	/* 0x2e6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e6d:
	/* 0x2e6d: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e71:
	/* 0x2e71: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2e76:
	/* 0x2e76: je     2ea4 <cwd_read_v61+0x16a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ea4;
	}
x86_l_2e78:
	/* 0x2e78: lea    rdi,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e7c:
	/* 0x2e7c: add    r14,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2e80:
	/* 0x2e80: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e85:
	/* 0x2e85: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e8a:
	/* 0x2e8a: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2e8d:
	/* 0x2e8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e8f:
	/* 0x2e8f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e94:
	/* 0x2e94: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e98:
	/* 0x2e98: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2e9c:
	/* 0x2e9c: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ea0:
	/* 0x2ea0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ea2:
	/* 0x2ea2: jmp    2ead <cwd_read_v61+0x173> */
	goto x86_l_2ead;
x86_l_2ea4:
	/* 0x2ea4: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_2ea8:
	/* 0x2ea8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ead:
	/* 0x2ead: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_2eb1:
	/* 0x2eb1: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2eb2:
	/* 0x2eb2: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2eb4:
	/* 0x2eb4: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2eb6:
	/* 0x2eb6: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2eb8:
	/* 0x2eb8: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2eb9:
	/* 0x2eb9: movzx  esi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2ebd:
	/* 0x2ebd: add    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ec0:
	/* 0x2ec0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ec5:
	/* 0x2ec5: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2ec8:
	/* 0x2ec8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eca:
	/* 0x2eca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ecf:
	/* 0x2ecf: mov    QWORD PTR [rbx+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ed3:
	/* 0x2ed3: jmp    2ead <cwd_read_v61+0x173> */
	goto x86_l_2ead;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 10352U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1843ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1848ULL && __x86_pc <= 3692ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3697ULL && __x86_pc <= 5589ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5591ULL && __x86_pc <= 7385ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7391ULL && __x86_pc <= 9061ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9065ULL && __x86_pc <= 10810ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10812ULL && __x86_pc <= 11987ULL)
			__x86_pc = tetragon_bpf_multi_retkprobe_v61_generic_retkprobe_event_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

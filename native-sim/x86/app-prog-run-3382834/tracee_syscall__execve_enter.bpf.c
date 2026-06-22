extern char binary_filter_version;
extern char cgroup_id_filter_version;
extern char comm_filter_version;
extern char config_map;
extern char event_data_map;
extern char events;
extern char events_map_version;
extern char mnt_ns_filter_version;
extern char pid_filter_version;
extern char pid_ns_filter_version;
extern char proc_info_map;
extern char process_tree_map_version;
extern char stack_addresses;
extern char task_info_map;
extern char uid_filter_version;
extern char uts_ns_filter_version;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_0(
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
	case 28ULL: goto x86_l_1c;
	case 35ULL: goto x86_l_23;
	case 40ULL: goto x86_l_28;
	case 45ULL: goto x86_l_2d;
	case 47ULL: goto x86_l_2f;
	case 50ULL: goto x86_l_32;
	case 56ULL: goto x86_l_38;
	case 59ULL: goto x86_l_3b;
	case 66ULL: goto x86_l_42;
	case 71ULL: goto x86_l_47;
	case 76ULL: goto x86_l_4c;
	case 78ULL: goto x86_l_4e;
	case 81ULL: goto x86_l_51;
	case 87ULL: goto x86_l_57;
	case 90ULL: goto x86_l_5a;
	case 94ULL: goto x86_l_5e;
	case 101ULL: goto x86_l_65;
	case 106ULL: goto x86_l_6a;
	case 109ULL: goto x86_l_6d;
	case 111ULL: goto x86_l_6f;
	case 114ULL: goto x86_l_72;
	case 120ULL: goto x86_l_78;
	case 123ULL: goto x86_l_7b;
	case 127ULL: goto x86_l_7f;
	case 134ULL: goto x86_l_86;
	case 139ULL: goto x86_l_8b;
	case 142ULL: goto x86_l_8e;
	case 144ULL: goto x86_l_90;
	case 147ULL: goto x86_l_93;
	case 153ULL: goto x86_l_99;
	case 161ULL: goto x86_l_a1;
	case 167ULL: goto x86_l_a7;
	case 172ULL: goto x86_l_ac;
	case 179ULL: goto x86_l_b3;
	case 183ULL: goto x86_l_b7;
	case 190ULL: goto x86_l_be;
	case 199ULL: goto x86_l_c7;
	case 206ULL: goto x86_l_ce;
	case 217ULL: goto x86_l_d9;
	case 228ULL: goto x86_l_e4;
	case 239ULL: goto x86_l_ef;
	case 250ULL: goto x86_l_fa;
	case 261ULL: goto x86_l_105;
	case 272ULL: goto x86_l_110;
	case 283ULL: goto x86_l_11b;
	case 294ULL: goto x86_l_126;
	case 305ULL: goto x86_l_131;
	case 309ULL: goto x86_l_135;
	case 317ULL: goto x86_l_13d;
	case 322ULL: goto x86_l_142;
	case 329ULL: goto x86_l_149;
	case 334ULL: goto x86_l_14e;
	case 339ULL: goto x86_l_153;
	case 341ULL: goto x86_l_155;
	case 344ULL: goto x86_l_158;
	case 350ULL: goto x86_l_15e;
	case 353ULL: goto x86_l_161;
	case 358ULL: goto x86_l_166;
	case 363ULL: goto x86_l_16b;
	case 365ULL: goto x86_l_16d;
	case 368ULL: goto x86_l_170;
	case 374ULL: goto x86_l_176;
	case 378ULL: goto x86_l_17a;
	case 385ULL: goto x86_l_181;
	case 388ULL: goto x86_l_184;
	case 395ULL: goto x86_l_18b;
	case 402ULL: goto x86_l_192;
	case 406ULL: goto x86_l_196;
	case 413ULL: goto x86_l_19d;
	case 417ULL: goto x86_l_1a1;
	case 424ULL: goto x86_l_1a8;
	case 428ULL: goto x86_l_1ac;
	case 435ULL: goto x86_l_1b3;
	case 439ULL: goto x86_l_1b7;
	case 446ULL: goto x86_l_1be;
	case 450ULL: goto x86_l_1c2;
	case 454ULL: goto x86_l_1c6;
	case 461ULL: goto x86_l_1cd;
	case 468ULL: goto x86_l_1d4;
	case 472ULL: goto x86_l_1d8;
	case 475ULL: goto x86_l_1db;
	case 480ULL: goto x86_l_1e0;
	case 485ULL: goto x86_l_1e5;
	case 490ULL: goto x86_l_1ea;
	case 498ULL: goto x86_l_1f2;
	case 500ULL: goto x86_l_1f4;
	case 503ULL: goto x86_l_1f7;
	case 505ULL: goto x86_l_1f9;
	case 508ULL: goto x86_l_1fc;
	case 515ULL: goto x86_l_203;
	case 521ULL: goto x86_l_209;
	case 526ULL: goto x86_l_20e;
	case 528ULL: goto x86_l_210;
	case 533ULL: goto x86_l_215;
	case 538ULL: goto x86_l_21a;
	case 543ULL: goto x86_l_21f;
	case 550ULL: goto x86_l_226;
	case 553ULL: goto x86_l_229;
	case 559ULL: goto x86_l_22f;
	case 567ULL: goto x86_l_237;
	case 570ULL: goto x86_l_23a;
	case 573ULL: goto x86_l_23d;
	case 576ULL: goto x86_l_240;
	case 580ULL: goto x86_l_244;
	case 583ULL: goto x86_l_247;
	case 586ULL: goto x86_l_24a;
	case 593ULL: goto x86_l_251;
	case 596ULL: goto x86_l_254;
	case 603ULL: goto x86_l_25b;
	case 606ULL: goto x86_l_25e;
	case 608ULL: goto x86_l_260;
	case 610ULL: goto x86_l_262;
	case 615ULL: goto x86_l_267;
	case 622ULL: goto x86_l_26e;
	case 625ULL: goto x86_l_271;
	case 628ULL: goto x86_l_274;
	case 631ULL: goto x86_l_277;
	case 638ULL: goto x86_l_27e;
	case 641ULL: goto x86_l_281;
	case 644ULL: goto x86_l_284;
	case 651ULL: goto x86_l_28b;
	case 654ULL: goto x86_l_28e;
	case 656ULL: goto x86_l_290;
	case 659ULL: goto x86_l_293;
	case 662ULL: goto x86_l_296;
	case 665ULL: goto x86_l_299;
	case 668ULL: goto x86_l_29c;
	case 675ULL: goto x86_l_2a3;
	case 678ULL: goto x86_l_2a6;
	case 681ULL: goto x86_l_2a9;
	case 688ULL: goto x86_l_2b0;
	case 691ULL: goto x86_l_2b3;
	case 693ULL: goto x86_l_2b5;
	case 696ULL: goto x86_l_2b8;
	case 701ULL: goto x86_l_2bd;
	case 705ULL: goto x86_l_2c1;
	case 708ULL: goto x86_l_2c4;
	case 715ULL: goto x86_l_2cb;
	case 718ULL: goto x86_l_2ce;
	case 721ULL: goto x86_l_2d1;
	case 726ULL: goto x86_l_2d6;
	case 733ULL: goto x86_l_2dd;
	case 736ULL: goto x86_l_2e0;
	case 742ULL: goto x86_l_2e6;
	case 748ULL: goto x86_l_2ec;
	case 756ULL: goto x86_l_2f4;
	case 763ULL: goto x86_l_2fb;
	case 771ULL: goto x86_l_303;
	case 778ULL: goto x86_l_30a;
	case 783ULL: goto x86_l_30f;
	case 790ULL: goto x86_l_316;
	case 795ULL: goto x86_l_31b;
	case 801ULL: goto x86_l_321;
	case 808ULL: goto x86_l_328;
	case 813ULL: goto x86_l_32d;
	case 818ULL: goto x86_l_332;
	case 820ULL: goto x86_l_334;
	case 823ULL: goto x86_l_337;
	case 826ULL: goto x86_l_33a;
	case 831ULL: goto x86_l_33f;
	case 838ULL: goto x86_l_346;
	case 841ULL: goto x86_l_349;
	case 843ULL: goto x86_l_34b;
	case 848ULL: goto x86_l_350;
	case 853ULL: goto x86_l_355;
	case 856ULL: goto x86_l_358;
	case 858ULL: goto x86_l_35a;
	case 861ULL: goto x86_l_35d;
	case 863ULL: goto x86_l_35f;
	case 866ULL: goto x86_l_362;
	case 870ULL: goto x86_l_366;
	case 873ULL: goto x86_l_369;
	case 875ULL: goto x86_l_36b;
	case 877ULL: goto x86_l_36d;
	case 882ULL: goto x86_l_372;
	case 887ULL: goto x86_l_377;
	case 892ULL: goto x86_l_37c;
	case 895ULL: goto x86_l_37f;
	case 898ULL: goto x86_l_382;
	case 900ULL: goto x86_l_384;
	case 904ULL: goto x86_l_388;
	case 906ULL: goto x86_l_38a;
	case 909ULL: goto x86_l_38d;
	case 911ULL: goto x86_l_38f;
	case 919ULL: goto x86_l_397;
	case 922ULL: goto x86_l_39a;
	case 925ULL: goto x86_l_39d;
	case 930ULL: goto x86_l_3a2;
	case 937ULL: goto x86_l_3a9;
	case 940ULL: goto x86_l_3ac;
	case 946ULL: goto x86_l_3b2;
	case 948ULL: goto x86_l_3b4;
	case 953ULL: goto x86_l_3b9;
	case 958ULL: goto x86_l_3be;
	case 963ULL: goto x86_l_3c3;
	case 966ULL: goto x86_l_3c6;
	case 968ULL: goto x86_l_3c8;
	case 971ULL: goto x86_l_3cb;
	case 973ULL: goto x86_l_3cd;
	case 976ULL: goto x86_l_3d0;
	case 980ULL: goto x86_l_3d4;
	case 983ULL: goto x86_l_3d7;
	case 985ULL: goto x86_l_3d9;
	case 992ULL: goto x86_l_3e0;
	case 999ULL: goto x86_l_3e7;
	case 1002ULL: goto x86_l_3ea;
	case 1008ULL: goto x86_l_3f0;
	case 1013ULL: goto x86_l_3f5;
	case 1015ULL: goto x86_l_3f7;
	case 1023ULL: goto x86_l_3ff;
	case 1025ULL: goto x86_l_401;
	case 1027ULL: goto x86_l_403;
	case 1035ULL: goto x86_l_40b;
	case 1040ULL: goto x86_l_410;
	case 1045ULL: goto x86_l_415;
	case 1048ULL: goto x86_l_418;
	case 1053ULL: goto x86_l_41d;
	case 1056ULL: goto x86_l_420;
	case 1058ULL: goto x86_l_422;
	case 1062ULL: goto x86_l_426;
	case 1064ULL: goto x86_l_428;
	case 1067ULL: goto x86_l_42b;
	case 1069ULL: goto x86_l_42d;
	case 1077ULL: goto x86_l_435;
	case 1080ULL: goto x86_l_438;
	case 1083ULL: goto x86_l_43b;
	case 1086ULL: goto x86_l_43e;
	case 1089ULL: goto x86_l_441;
	case 1094ULL: goto x86_l_446;
	case 1102ULL: goto x86_l_44e;
	case 1108ULL: goto x86_l_454;
	case 1113ULL: goto x86_l_459;
	case 1115ULL: goto x86_l_45b;
	case 1118ULL: goto x86_l_45e;
	case 1125ULL: goto x86_l_465;
	case 1132ULL: goto x86_l_46c;
	case 1137ULL: goto x86_l_471;
	case 1144ULL: goto x86_l_478;
	case 1151ULL: goto x86_l_47f;
	case 1156ULL: goto x86_l_484;
	case 1162ULL: goto x86_l_48a;
	case 1169ULL: goto x86_l_491;
	case 1174ULL: goto x86_l_496;
	case 1179ULL: goto x86_l_49b;
	case 1181ULL: goto x86_l_49d;
	case 1184ULL: goto x86_l_4a0;
	case 1187ULL: goto x86_l_4a3;
	case 1192ULL: goto x86_l_4a8;
	case 1199ULL: goto x86_l_4af;
	case 1202ULL: goto x86_l_4b2;
	case 1204ULL: goto x86_l_4b4;
	case 1209ULL: goto x86_l_4b9;
	case 1214ULL: goto x86_l_4be;
	case 1216ULL: goto x86_l_4c0;
	case 1219ULL: goto x86_l_4c3;
	case 1221ULL: goto x86_l_4c5;
	case 1224ULL: goto x86_l_4c8;
	case 1228ULL: goto x86_l_4cc;
	case 1231ULL: goto x86_l_4cf;
	case 1233ULL: goto x86_l_4d1;
	case 1235ULL: goto x86_l_4d3;
	case 1238ULL: goto x86_l_4d6;
	case 1243ULL: goto x86_l_4db;
	case 1246ULL: goto x86_l_4de;
	case 1249ULL: goto x86_l_4e1;
	case 1251ULL: goto x86_l_4e3;
	case 1256ULL: goto x86_l_4e8;
	case 1260ULL: goto x86_l_4ec;
	case 1262ULL: goto x86_l_4ee;
	case 1265ULL: goto x86_l_4f1;
	case 1267ULL: goto x86_l_4f3;
	case 1272ULL: goto x86_l_4f8;
	case 1275ULL: goto x86_l_4fb;
	case 1278ULL: goto x86_l_4fe;
	case 1281ULL: goto x86_l_501;
	case 1286ULL: goto x86_l_506;
	case 1294ULL: goto x86_l_50e;
	case 1300ULL: goto x86_l_514;
	case 1305ULL: goto x86_l_519;
	case 1312ULL: goto x86_l_520;
	case 1317ULL: goto x86_l_525;
	case 1322ULL: goto x86_l_52a;
	case 1327ULL: goto x86_l_52f;
	case 1332ULL: goto x86_l_534;
	case 1334ULL: goto x86_l_536;
	case 1339ULL: goto x86_l_53b;
	case 1343ULL: goto x86_l_53f;
	case 1348ULL: goto x86_l_544;
	case 1353ULL: goto x86_l_549;
	case 1358ULL: goto x86_l_54e;
	case 1363ULL: goto x86_l_553;
	case 1365ULL: goto x86_l_555;
	case 1370ULL: goto x86_l_55a;
	case 1375ULL: goto x86_l_55f;
	case 1380ULL: goto x86_l_564;
	case 1385ULL: goto x86_l_569;
	case 1390ULL: goto x86_l_56e;
	case 1395ULL: goto x86_l_573;
	case 1397ULL: goto x86_l_575;
	case 1401ULL: goto x86_l_579;
	case 1404ULL: goto x86_l_57c;
	case 1411ULL: goto x86_l_583;
	case 1418ULL: goto x86_l_58a;
	case 1424ULL: goto x86_l_590;
	case 1431ULL: goto x86_l_597;
	case 1436ULL: goto x86_l_59c;
	case 1441ULL: goto x86_l_5a1;
	case 1444ULL: goto x86_l_5a4;
	case 1446ULL: goto x86_l_5a6;
	case 1453ULL: goto x86_l_5ad;
	case 1456ULL: goto x86_l_5b0;
	case 1458ULL: goto x86_l_5b2;
	case 1461ULL: goto x86_l_5b5;
	case 1465ULL: goto x86_l_5b9;
	case 1470ULL: goto x86_l_5be;
	case 1472ULL: goto x86_l_5c0;
	case 1475ULL: goto x86_l_5c3;
	case 1477ULL: goto x86_l_5c5;
	case 1480ULL: goto x86_l_5c8;
	case 1484ULL: goto x86_l_5cc;
	case 1487ULL: goto x86_l_5cf;
	case 1489ULL: goto x86_l_5d1;
	case 1491ULL: goto x86_l_5d3;
	case 1494ULL: goto x86_l_5d6;
	case 1497ULL: goto x86_l_5d9;
	case 1500ULL: goto x86_l_5dc;
	case 1503ULL: goto x86_l_5df;
	case 1509ULL: goto x86_l_5e5;
	case 1517ULL: goto x86_l_5ed;
	case 1523ULL: goto x86_l_5f3;
	case 1530ULL: goto x86_l_5fa;
	case 1534ULL: goto x86_l_5fe;
	case 1539ULL: goto x86_l_603;
	case 1544ULL: goto x86_l_608;
	case 1549ULL: goto x86_l_60d;
	case 1554ULL: goto x86_l_612;
	case 1556ULL: goto x86_l_614;
	case 1561ULL: goto x86_l_619;
	case 1566ULL: goto x86_l_61e;
	case 1571ULL: goto x86_l_623;
	case 1576ULL: goto x86_l_628;
	case 1581ULL: goto x86_l_62d;
	case 1584ULL: goto x86_l_630;
	case 1586ULL: goto x86_l_632;
	case 1590ULL: goto x86_l_636;
	case 1594ULL: goto x86_l_63a;
	case 1598ULL: goto x86_l_63e;
	case 1602ULL: goto x86_l_642;
	case 1607ULL: goto x86_l_647;
	case 1612ULL: goto x86_l_64c;
	case 1617ULL: goto x86_l_651;
	case 1622ULL: goto x86_l_656;
	case 1624ULL: goto x86_l_658;
	case 1629ULL: goto x86_l_65d;
	case 1633ULL: goto x86_l_661;
	case 1638ULL: goto x86_l_666;
	case 1643ULL: goto x86_l_66b;
	case 1648ULL: goto x86_l_670;
	case 1653ULL: goto x86_l_675;
	case 1655ULL: goto x86_l_677;
	case 1659ULL: goto x86_l_67b;
	case 1662ULL: goto x86_l_67e;
	case 1669ULL: goto x86_l_685;
	case 1676ULL: goto x86_l_68c;
	case 1682ULL: goto x86_l_692;
	case 1689ULL: goto x86_l_699;
	case 1694ULL: goto x86_l_69e;
	case 1699ULL: goto x86_l_6a3;
	case 1702ULL: goto x86_l_6a6;
	case 1704ULL: goto x86_l_6a8;
	case 1711ULL: goto x86_l_6af;
	case 1714ULL: goto x86_l_6b2;
	case 1716ULL: goto x86_l_6b4;
	case 1719ULL: goto x86_l_6b7;
	case 1723ULL: goto x86_l_6bb;
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
	/* 0x14: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1c:
	/* 0x1c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_23:
	/* 0x23: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28:
	/* 0x28: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d:
	/* 0x2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f:
	/* 0x2f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32:
	/* 0x32: je     20e <syscall__execve_enter+0x20e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20e;
	}
x86_l_38:
	/* 0x38: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_3b:
	/* 0x3b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_42:
	/* 0x42: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47:
	/* 0x47: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4c:
	/* 0x4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e:
	/* 0x4e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_51:
	/* 0x51: je     20e <syscall__execve_enter+0x20e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20e;
	}
x86_l_57:
	/* 0x57: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_5a:
	/* 0x5a: lea    r15,[rbp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5e:
	/* 0x5e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_65:
	/* 0x65: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6a:
	/* 0x6a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_6d:
	/* 0x6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f:
	/* 0x6f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_72:
	/* 0x72: je     20e <syscall__execve_enter+0x20e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20e;
	}
x86_l_78:
	/* 0x78: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_7b:
	/* 0x7b: lea    rbx,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_7f:
	/* 0x7f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_86:
	/* 0x86: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8b:
	/* 0x8b: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_8e:
	/* 0x8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_90:
	/* 0x90: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_93:
	/* 0x93: je     20e <syscall__execve_enter+0x20e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20e;
	}
x86_l_99:
	/* 0x99: cmp    BYTE PTR [r13+0xb0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_a1:
	/* 0xa1: je     215 <syscall__execve_enter+0x215> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_215;
	}
x86_l_a7:
	/* 0xa7: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ac:
	/* 0xac: mov    rax,QWORD PTR [r13+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_b3:
	/* 0xb3: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b7:
	/* 0xb7: mov    DWORD PTR [rbp+0x70],0x3b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337211ULL);
x86_l_be:
	/* 0xbe: mov    WORD PTR [rbp+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_c7:
	/* 0xc7: mov    BYTE PTR [rbp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_ce:
	/* 0xce: mov    QWORD PTR [rbp+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_d9:
	/* 0xd9: mov    QWORD PTR [rbp+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_e4:
	/* 0xe4: mov    QWORD PTR [rbp+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_ef:
	/* 0xef: mov    QWORD PTR [rbp+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_fa:
	/* 0xfa: mov    QWORD PTR [rbp+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_105:
	/* 0x105: mov    QWORD PTR [rbp+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_110:
	/* 0x110: mov    QWORD PTR [rbp+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_11b:
	/* 0x11b: mov    QWORD PTR [rbp+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_126:
	/* 0x126: mov    QWORD PTR [rbp+0x7dd8],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138370961375231ULL);
x86_l_131:
	/* 0x131: movzx  eax,WORD PTR [rbp+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_135:
	/* 0x135: mov    DWORD PTR [rsp+0x10],0x3b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476795ULL);
x86_l_13d:
	/* 0x13d: mov    WORD PTR [rsp+0x4],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_142:
	/* 0x142: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_149:
	/* 0x149: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14e:
	/* 0x14e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_153:
	/* 0x153: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_155:
	/* 0x155: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_158:
	/* 0x158: je     20e <syscall__execve_enter+0x20e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20e;
	}
x86_l_15e:
	/* 0x15e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_161:
	/* 0x161: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_166:
	/* 0x166: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16b:
	/* 0x16b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16d:
	/* 0x16d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_170:
	/* 0x170: je     20e <syscall__execve_enter+0x20e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20e;
	}
x86_l_176:
	/* 0x176: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17a:
	/* 0x17a: mov    QWORD PTR [rbp+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_181:
	/* 0x181: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_184:
	/* 0x184: mov    QWORD PTR [rbp+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_18b:
	/* 0x18b: mov    QWORD PTR [rbp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_192:
	/* 0x192: mov    rdx,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_196:
	/* 0x196: mov    QWORD PTR [rbp+0x7e10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_19d:
	/* 0x19d: mov    rdx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a1:
	/* 0x1a1: mov    QWORD PTR [rbp+0x7e08],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_1a8:
	/* 0x1a8: mov    rdx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ac:
	/* 0x1ac: mov    QWORD PTR [rbp+0x7e00],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_1b3:
	/* 0x1b3: mov    rdx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b7:
	/* 0x1b7: mov    QWORD PTR [rbp+0x7df8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_1be:
	/* 0x1be: mov    rdx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c2:
	/* 0x1c2: mov    rax,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c6:
	/* 0x1c6: mov    QWORD PTR [rbp+0x7df0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_1cd:
	/* 0x1cd: mov    QWORD PTR [rbp+0x7de8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_1d4:
	/* 0x1d4: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d8:
	/* 0x1d8: cmp    eax,DWORD PTR [rbp+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1db:
	/* 0x1db: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e0:
	/* 0x1e0: mov    QWORD PTR [rsp+0x70],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1e5:
	/* 0x1e5: mov    QWORD PTR [rsp+0x60],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1ea:
	/* 0x1ea: mov    QWORD PTR [rsp+0xa0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1f2:
	/* 0x1f2: jne    21f <syscall__execve_enter+0x21f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21f;
	}
x86_l_1f4:
	/* 0x1f4: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f7:
	/* 0x1f7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f9:
	/* 0x1f9: and    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1fc:
	/* 0x1fc: mov    QWORD PTR [rbp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_203:
	/* 0x203: jne    a17 <syscall__execve_enter+0xa17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2583ULL;
	}
x86_l_209:
	/* 0x209: jmp    1192 <syscall__execve_enter+0x1192> */
	return 4498ULL;
x86_l_20e:
	/* 0x20e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_210:
	/* 0x210: jmp    1192 <syscall__execve_enter+0x1192> */
	return 4498ULL;
x86_l_215:
	/* 0x215: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_21a:
	/* 0x21a: jmp    1192 <syscall__execve_enter+0x1192> */
	return 4498ULL;
x86_l_21f:
	/* 0x21f: mov    rax,QWORD PTR [rbp+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_226:
	/* 0x226: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_229:
	/* 0x229: je     3d9 <syscall__execve_enter+0x3d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d9;
	}
x86_l_22f:
	/* 0x22f: movzx  ecx,BYTE PTR [r13+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_237:
	/* 0x237: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_23a:
	/* 0x23a: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23d:
	/* 0x23d: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_240:
	/* 0x240: sete   r13b */
	X86_SIM_L_EXEC_SETCC(X86_R13, X86_CC_E);
x86_l_244:
	/* 0x244: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_247:
	/* 0x247: neg    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_24a:
	/* 0x24a: xor    r13,QWORD PTR [rbp+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_251:
	/* 0x251: or     r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_254:
	/* 0x254: mov    rax,QWORD PTR [rbp+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_25b:
	/* 0x25b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25e:
	/* 0x25e: je     284 <syscall__execve_enter+0x284> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_284;
	}
x86_l_260:
	/* 0x260: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_262:
	/* 0x262: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_267:
	/* 0x267: cmp    BYTE PTR [rdx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_26e:
	/* 0x26e: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_271:
	/* 0x271: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_274:
	/* 0x274: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_277:
	/* 0x277: xor    rcx,QWORD PTR [rbp+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_27e:
	/* 0x27e: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_281:
	/* 0x281: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_284:
	/* 0x284: mov    rax,QWORD PTR [rbp+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_28b:
	/* 0x28b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28e:
	/* 0x28e: je     2a9 <syscall__execve_enter+0x2a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a9;
	}
x86_l_290:
	/* 0x290: mov    ecx,DWORD PTR [rbp+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_293:
	/* 0x293: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_296:
	/* 0x296: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_299:
	/* 0x299: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_29c:
	/* 0x29c: xor    rcx,QWORD PTR [rbp+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_2a3:
	/* 0x2a3: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2a6:
	/* 0x2a6: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_2a9:
	/* 0x2a9: mov    rax,QWORD PTR [rbp+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_2b0:
	/* 0x2b0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b3:
	/* 0x2b3: je     2d1 <syscall__execve_enter+0x2d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d1;
	}
x86_l_2b5:
	/* 0x2b5: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2b8:
	/* 0x2b8: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2bd:
	/* 0x2bd: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2c1:
	/* 0x2c1: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_2c4:
	/* 0x2c4: xor    rcx,QWORD PTR [rbp+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_2cb:
	/* 0x2cb: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2ce:
	/* 0x2ce: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_2d1:
	/* 0x2d1: movzx  r14d,WORD PTR [rbp+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_2d6:
	/* 0x2d6: mov    rax,QWORD PTR [rbp+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_2dd:
	/* 0x2dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e0:
	/* 0x2e0: mov    WORD PTR [rsp+0x56],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_2e6:
	/* 0x2e6: je     446 <syscall__execve_enter+0x446> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_446;
	}
x86_l_2ec:
	/* 0x2ec: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2f4:
	/* 0x2f4: mov    rax,QWORD PTR [rbp+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_2fb:
	/* 0x2fb: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_303:
	/* 0x303: mov    rax,QWORD PTR [rbp+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_30a:
	/* 0x30a: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_30f:
	/* 0x30f: mov    rax,QWORD PTR [rbp+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_316:
	/* 0x316: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_31b:
	/* 0x31b: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_321:
	/* 0x321: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_328:
	/* 0x328: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32d:
	/* 0x32d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_332:
	/* 0x332: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_334:
	/* 0x334: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_337:
	/* 0x337: mov    eax,DWORD PTR [rbp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_33a:
	/* 0x33a: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33f:
	/* 0x33f: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_346:
	/* 0x346: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_349:
	/* 0x349: je     36b <syscall__execve_enter+0x36b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36b;
	}
x86_l_34b:
	/* 0x34b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_350:
	/* 0x350: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_355:
	/* 0x355: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_358:
	/* 0x358: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35a:
	/* 0x35a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35d:
	/* 0x35d: je     36b <syscall__execve_enter+0x36b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36b;
	}
x86_l_35f:
	/* 0x35f: mov    rbp,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_362:
	/* 0x362: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_366:
	/* 0x366: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_369:
	/* 0x369: jmp    36d <syscall__execve_enter+0x36d> */
	goto x86_l_36d;
x86_l_36b:
	/* 0x36b: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36d:
	/* 0x36d: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_372:
	/* 0x372: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_377:
	/* 0x377: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37c:
	/* 0x37c: dec    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_37f:
	/* 0x37f: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_382:
	/* 0x382: jb     39a <syscall__execve_enter+0x39a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_39a;
	}
x86_l_384:
	/* 0x384: cmp    rsi,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_388:
	/* 0x388: je     38f <syscall__execve_enter+0x38f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38f;
	}
x86_l_38a:
	/* 0x38a: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_38d:
	/* 0x38d: jbe    39a <syscall__execve_enter+0x39a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_39a;
	}
x86_l_38f:
	/* 0x38f: and    r14,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 152ULL);
x86_l_397:
	/* 0x397: or     rbp,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_39a:
	/* 0x39a: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39d:
	/* 0x39d: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a2:
	/* 0x3a2: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_3a9:
	/* 0x3a9: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_3ac:
	/* 0x3ac: movzx  r14d,WORD PTR [rsp+0x56] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 86ULL);
x86_l_3b2:
	/* 0x3b2: je     3f5 <syscall__execve_enter+0x3f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f5;
	}
x86_l_3b4:
	/* 0x3b4: mov    QWORD PTR [rsp+0x58],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3b9:
	/* 0x3b9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3be:
	/* 0x3be: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c3:
	/* 0x3c3: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3c6:
	/* 0x3c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c8:
	/* 0x3c8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3cb:
	/* 0x3cb: je     401 <syscall__execve_enter+0x401> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_401;
	}
x86_l_3cd:
	/* 0x3cd: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d0:
	/* 0x3d0: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d4:
	/* 0x3d4: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_3d7:
	/* 0x3d7: jmp    403 <syscall__execve_enter+0x403> */
	goto x86_l_403;
x86_l_3d9:
	/* 0x3d9: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_3e0:
	/* 0x3e0: mov    rax,QWORD PTR [rbp+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_3e7:
	/* 0x3e7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3ea:
	/* 0x3ea: jne    260 <syscall__execve_enter+0x260> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_260;
	}
x86_l_3f0:
	/* 0x3f0: jmp    284 <syscall__execve_enter+0x284> */
	goto x86_l_284;
x86_l_3f5:
	/* 0x3f5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f7:
	/* 0x3f7: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3ff:
	/* 0x3ff: jmp    415 <syscall__execve_enter+0x415> */
	goto x86_l_415;
x86_l_401:
	/* 0x401: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_403:
	/* 0x403: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_40b:
	/* 0x40b: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_410:
	/* 0x410: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_415:
	/* 0x415: not    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_418:
	/* 0x418: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41d:
	/* 0x41d: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_420:
	/* 0x420: jb     438 <syscall__execve_enter+0x438> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_438;
	}
x86_l_422:
	/* 0x422: cmp    rsi,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_426:
	/* 0x426: je     42d <syscall__execve_enter+0x42d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42d;
	}
x86_l_428:
	/* 0x428: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_42b:
	/* 0x42b: jbe    438 <syscall__execve_enter+0x438> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_438;
	}
x86_l_42d:
	/* 0x42d: and    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 152ULL);
x86_l_435:
	/* 0x435: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_438:
	/* 0x438: or     rbp,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_43b:
	/* 0x43b: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_43e:
	/* 0x43e: and    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_441:
	/* 0x441: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_446:
	/* 0x446: cmp    QWORD PTR [rbp+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_44e:
	/* 0x44e: je     506 <syscall__execve_enter+0x506> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_506;
	}
x86_l_454:
	/* 0x454: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_459:
	/* 0x459: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45b:
	/* 0x45b: mov    DWORD PTR [rbp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_45e:
	/* 0x45e: mov    r15,QWORD PTR [rbp+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_465:
	/* 0x465: mov    rax,QWORD PTR [rbp+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_46c:
	/* 0x46c: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_471:
	/* 0x471: mov    r12,QWORD PTR [rbp+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_478:
	/* 0x478: mov    rax,QWORD PTR [rbp+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_47f:
	/* 0x47f: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_484:
	/* 0x484: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48a:
	/* 0x48a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_491:
	/* 0x491: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_496:
	/* 0x496: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_49b:
	/* 0x49b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49d:
	/* 0x49d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4a0:
	/* 0x4a0: mov    eax,DWORD PTR [rbp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4a3:
	/* 0x4a3: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a8:
	/* 0x4a8: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_4af:
	/* 0x4af: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_4b2:
	/* 0x4b2: je     4d1 <syscall__execve_enter+0x4d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d1;
	}
x86_l_4b4:
	/* 0x4b4: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b9:
	/* 0x4b9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4be:
	/* 0x4be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c0:
	/* 0x4c0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4c3:
	/* 0x4c3: je     4d1 <syscall__execve_enter+0x4d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d1;
	}
x86_l_4c5:
	/* 0x4c5: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c8:
	/* 0x4c8: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cc:
	/* 0x4cc: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_4cf:
	/* 0x4cf: jmp    4d3 <syscall__execve_enter+0x4d3> */
	goto x86_l_4d3;
x86_l_4d1:
	/* 0x4d1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4d3:
	/* 0x4d3: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_4d6:
	/* 0x4d6: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4db:
	/* 0x4db: dec    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_4de:
	/* 0x4de: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_4e1:
	/* 0x4e1: jb     4fb <syscall__execve_enter+0x4fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4fb;
	}
x86_l_4e3:
	/* 0x4e3: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4e8:
	/* 0x4e8: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_4ec:
	/* 0x4ec: je     4f3 <syscall__execve_enter+0x4f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f3;
	}
x86_l_4ee:
	/* 0x4ee: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_4f1:
	/* 0x4f1: jbe    4fb <syscall__execve_enter+0x4fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_4fb;
	}
x86_l_4f3:
	/* 0x4f3: and    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 104ULL);
x86_l_4f8:
	/* 0x4f8: or     rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_4fb:
	/* 0x4fb: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_4fe:
	/* 0x4fe: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_501:
	/* 0x501: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_506:
	/* 0x506: cmp    QWORD PTR [rbp+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_50e:
	/* 0x50e: je     5e5 <syscall__execve_enter+0x5e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e5;
	}
x86_l_514:
	/* 0x514: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_519:
	/* 0x519: add    rdx,QWORD PTR [rbp+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_520:
	/* 0x520: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_525:
	/* 0x525: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_52a:
	/* 0x52a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_52f:
	/* 0x52f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_534:
	/* 0x534: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_536:
	/* 0x536: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53b:
	/* 0x53b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_53f:
	/* 0x53f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_544:
	/* 0x544: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_549:
	/* 0x549: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_54e:
	/* 0x54e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_553:
	/* 0x553: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_555:
	/* 0x555: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55a:
	/* 0x55a: lea    rdi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_55f:
	/* 0x55f: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_564:
	/* 0x564: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_569:
	/* 0x569: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_56e:
	/* 0x56e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_573:
	/* 0x573: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_575:
	/* 0x575: mov    eax,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_579:
	/* 0x579: mov    DWORD PTR [rbp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_57c:
	/* 0x57c: mov    r15,QWORD PTR [rbp+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_583:
	/* 0x583: mov    r12,QWORD PTR [rbp+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_58a:
	/* 0x58a: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_590:
	/* 0x590: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_597:
	/* 0x597: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_59c:
	/* 0x59c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5a1:
	/* 0x5a1: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_5a4:
	/* 0x5a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a6:
	/* 0x5a6: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_5ad:
	/* 0x5ad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b0:
	/* 0x5b0: je     5d1 <syscall__execve_enter+0x5d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d1;
	}
x86_l_5b2:
	/* 0x5b2: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_5b5:
	/* 0x5b5: lea    rsi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_5b9:
	/* 0x5b9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5be:
	/* 0x5be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c0:
	/* 0x5c0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5c3:
	/* 0x5c3: je     5d1 <syscall__execve_enter+0x5d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d1;
	}
x86_l_5c5:
	/* 0x5c5: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c8:
	/* 0x5c8: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cc:
	/* 0x5cc: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_5cf:
	/* 0x5cf: jmp    5d3 <syscall__execve_enter+0x5d3> */
	goto x86_l_5d3;
x86_l_5d1:
	/* 0x5d1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d3:
	/* 0x5d3: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_5d6:
	/* 0x5d6: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_5d9:
	/* 0x5d9: or     r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_5dc:
	/* 0x5dc: and    r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_5df:
	/* 0x5df: movzx  r14d,WORD PTR [rsp+0x56] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 86ULL);
x86_l_5e5:
	/* 0x5e5: cmp    QWORD PTR [rbp+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_5ed:
	/* 0x5ed: je     6e7 <syscall__execve_enter+0x6e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1767ULL;
	}
x86_l_5f3:
	/* 0x5f3: mov    rdx,QWORD PTR [rbp+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_5fa:
	/* 0x5fa: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5fe:
	/* 0x5fe: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_603:
	/* 0x603: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_608:
	/* 0x608: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_60d:
	/* 0x60d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_612:
	/* 0x612: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_614:
	/* 0x614: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_619:
	/* 0x619: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_61e:
	/* 0x61e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_623:
	/* 0x623: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_628:
	/* 0x628: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_62d:
	/* 0x62d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_630:
	/* 0x630: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_632:
	/* 0x632: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_636:
	/* 0x636: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_63a:
	/* 0x63a: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_63e:
	/* 0x63e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_642:
	/* 0x642: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_647:
	/* 0x647: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_64c:
	/* 0x64c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_651:
	/* 0x651: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_656:
	/* 0x656: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_658:
	/* 0x658: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_65d:
	/* 0x65d: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_661:
	/* 0x661: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_666:
	/* 0x666: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_66b:
	/* 0x66b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_670:
	/* 0x670: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_675:
	/* 0x675: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_677:
	/* 0x677: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_67b:
	/* 0x67b: mov    DWORD PTR [rbp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_67e:
	/* 0x67e: mov    r15,QWORD PTR [rbp+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_685:
	/* 0x685: mov    r12,QWORD PTR [rbp+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_68c:
	/* 0x68c: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_692:
	/* 0x692: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_699:
	/* 0x699: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_69e:
	/* 0x69e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6a3:
	/* 0x6a3: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_6a6:
	/* 0x6a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a8:
	/* 0x6a8: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_6af:
	/* 0x6af: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6b2:
	/* 0x6b2: je     6d3 <syscall__execve_enter+0x6d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1747ULL;
	}
x86_l_6b4:
	/* 0x6b4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_6b7:
	/* 0x6b7: lea    rsi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6bb:
	/* 0x6bb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
	return 1728ULL;
}

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1728ULL: goto x86_l_6c0;
	case 1730ULL: goto x86_l_6c2;
	case 1733ULL: goto x86_l_6c5;
	case 1735ULL: goto x86_l_6c7;
	case 1738ULL: goto x86_l_6ca;
	case 1742ULL: goto x86_l_6ce;
	case 1745ULL: goto x86_l_6d1;
	case 1747ULL: goto x86_l_6d3;
	case 1749ULL: goto x86_l_6d5;
	case 1752ULL: goto x86_l_6d8;
	case 1755ULL: goto x86_l_6db;
	case 1758ULL: goto x86_l_6de;
	case 1761ULL: goto x86_l_6e1;
	case 1767ULL: goto x86_l_6e7;
	case 1775ULL: goto x86_l_6ef;
	case 1781ULL: goto x86_l_6f5;
	case 1786ULL: goto x86_l_6fa;
	case 1793ULL: goto x86_l_701;
	case 1798ULL: goto x86_l_706;
	case 1803ULL: goto x86_l_70b;
	case 1808ULL: goto x86_l_710;
	case 1813ULL: goto x86_l_715;
	case 1815ULL: goto x86_l_717;
	case 1820ULL: goto x86_l_71c;
	case 1825ULL: goto x86_l_721;
	case 1830ULL: goto x86_l_726;
	case 1835ULL: goto x86_l_72b;
	case 1840ULL: goto x86_l_730;
	case 1842ULL: goto x86_l_732;
	case 1847ULL: goto x86_l_737;
	case 1852ULL: goto x86_l_73c;
	case 1857ULL: goto x86_l_741;
	case 1862ULL: goto x86_l_746;
	case 1865ULL: goto x86_l_749;
	case 1870ULL: goto x86_l_74e;
	case 1872ULL: goto x86_l_750;
	case 1876ULL: goto x86_l_754;
	case 1881ULL: goto x86_l_759;
	case 1886ULL: goto x86_l_75e;
	case 1889ULL: goto x86_l_761;
	case 1894ULL: goto x86_l_766;
	case 1897ULL: goto x86_l_769;
	case 1899ULL: goto x86_l_76b;
	case 1906ULL: goto x86_l_772;
	case 1913ULL: goto x86_l_779;
	case 1919ULL: goto x86_l_77f;
	case 1926ULL: goto x86_l_786;
	case 1931ULL: goto x86_l_78b;
	case 1936ULL: goto x86_l_790;
	case 1939ULL: goto x86_l_793;
	case 1941ULL: goto x86_l_795;
	case 1948ULL: goto x86_l_79c;
	case 1951ULL: goto x86_l_79f;
	case 1953ULL: goto x86_l_7a1;
	case 1956ULL: goto x86_l_7a4;
	case 1961ULL: goto x86_l_7a9;
	case 1964ULL: goto x86_l_7ac;
	case 1966ULL: goto x86_l_7ae;
	case 1969ULL: goto x86_l_7b1;
	case 1971ULL: goto x86_l_7b3;
	case 1974ULL: goto x86_l_7b6;
	case 1978ULL: goto x86_l_7ba;
	case 1981ULL: goto x86_l_7bd;
	case 1983ULL: goto x86_l_7bf;
	case 1985ULL: goto x86_l_7c1;
	case 1988ULL: goto x86_l_7c4;
	case 1991ULL: goto x86_l_7c7;
	case 1994ULL: goto x86_l_7ca;
	case 1997ULL: goto x86_l_7cd;
	case 2002ULL: goto x86_l_7d2;
	case 2008ULL: goto x86_l_7d8;
	case 2016ULL: goto x86_l_7e0;
	case 2022ULL: goto x86_l_7e6;
	case 2026ULL: goto x86_l_7ea;
	case 2031ULL: goto x86_l_7ef;
	case 2036ULL: goto x86_l_7f4;
	case 2039ULL: goto x86_l_7f7;
	case 2044ULL: goto x86_l_7fc;
	case 2046ULL: goto x86_l_7fe;
	case 2053ULL: goto x86_l_805;
	case 2060ULL: goto x86_l_80c;
	case 2066ULL: goto x86_l_812;
	case 2073ULL: goto x86_l_819;
	case 2078ULL: goto x86_l_81e;
	case 2083ULL: goto x86_l_823;
	case 2086ULL: goto x86_l_826;
	case 2088ULL: goto x86_l_828;
	case 2095ULL: goto x86_l_82f;
	case 2098ULL: goto x86_l_832;
	case 2100ULL: goto x86_l_834;
	case 2103ULL: goto x86_l_837;
	case 2108ULL: goto x86_l_83c;
	case 2111ULL: goto x86_l_83f;
	case 2113ULL: goto x86_l_841;
	case 2116ULL: goto x86_l_844;
	case 2118ULL: goto x86_l_846;
	case 2121ULL: goto x86_l_849;
	case 2125ULL: goto x86_l_84d;
	case 2128ULL: goto x86_l_850;
	case 2130ULL: goto x86_l_852;
	case 2132ULL: goto x86_l_854;
	case 2135ULL: goto x86_l_857;
	case 2138ULL: goto x86_l_85a;
	case 2141ULL: goto x86_l_85d;
	case 2144ULL: goto x86_l_860;
	case 2149ULL: goto x86_l_865;
	case 2155ULL: goto x86_l_86b;
	case 2162ULL: goto x86_l_872;
	case 2165ULL: goto x86_l_875;
	case 2167ULL: goto x86_l_877;
	case 2170ULL: goto x86_l_87a;
	case 2174ULL: goto x86_l_87e;
	case 2181ULL: goto x86_l_885;
	case 2187ULL: goto x86_l_88b;
	case 2194ULL: goto x86_l_892;
	case 2199ULL: goto x86_l_897;
	case 2204ULL: goto x86_l_89c;
	case 2207ULL: goto x86_l_89f;
	case 2209ULL: goto x86_l_8a1;
	case 2216ULL: goto x86_l_8a8;
	case 2219ULL: goto x86_l_8ab;
	case 2221ULL: goto x86_l_8ad;
	case 2224ULL: goto x86_l_8b0;
	case 2229ULL: goto x86_l_8b5;
	case 2234ULL: goto x86_l_8ba;
	case 2236ULL: goto x86_l_8bc;
	case 2239ULL: goto x86_l_8bf;
	case 2241ULL: goto x86_l_8c1;
	case 2244ULL: goto x86_l_8c4;
	case 2248ULL: goto x86_l_8c8;
	case 2251ULL: goto x86_l_8cb;
	case 2253ULL: goto x86_l_8cd;
	case 2255ULL: goto x86_l_8cf;
	case 2258ULL: goto x86_l_8d2;
	case 2261ULL: goto x86_l_8d5;
	case 2264ULL: goto x86_l_8d8;
	case 2267ULL: goto x86_l_8db;
	case 2273ULL: goto x86_l_8e1;
	case 2280ULL: goto x86_l_8e8;
	case 2283ULL: goto x86_l_8eb;
	case 2285ULL: goto x86_l_8ed;
	case 2292ULL: goto x86_l_8f4;
	case 2298ULL: goto x86_l_8fa;
	case 2305ULL: goto x86_l_901;
	case 2310ULL: goto x86_l_906;
	case 2315ULL: goto x86_l_90b;
	case 2318ULL: goto x86_l_90e;
	case 2320ULL: goto x86_l_910;
	case 2327ULL: goto x86_l_917;
	case 2330ULL: goto x86_l_91a;
	case 2332ULL: goto x86_l_91c;
	case 2335ULL: goto x86_l_91f;
	case 2340ULL: goto x86_l_924;
	case 2343ULL: goto x86_l_927;
	case 2345ULL: goto x86_l_929;
	case 2348ULL: goto x86_l_92c;
	case 2350ULL: goto x86_l_92e;
	case 2353ULL: goto x86_l_931;
	case 2357ULL: goto x86_l_935;
	case 2360ULL: goto x86_l_938;
	case 2362ULL: goto x86_l_93a;
	case 2364ULL: goto x86_l_93c;
	case 2367ULL: goto x86_l_93f;
	case 2370ULL: goto x86_l_942;
	case 2373ULL: goto x86_l_945;
	case 2376ULL: goto x86_l_948;
	case 2382ULL: goto x86_l_94e;
	case 2389ULL: goto x86_l_955;
	case 2392ULL: goto x86_l_958;
	case 2398ULL: goto x86_l_95e;
	case 2405ULL: goto x86_l_965;
	case 2411ULL: goto x86_l_96b;
	case 2418ULL: goto x86_l_972;
	case 2423ULL: goto x86_l_977;
	case 2428ULL: goto x86_l_97c;
	case 2431ULL: goto x86_l_97f;
	case 2433ULL: goto x86_l_981;
	case 2440ULL: goto x86_l_988;
	case 2443ULL: goto x86_l_98b;
	case 2445ULL: goto x86_l_98d;
	case 2448ULL: goto x86_l_990;
	case 2453ULL: goto x86_l_995;
	case 2457ULL: goto x86_l_999;
	case 2462ULL: goto x86_l_99e;
	case 2465ULL: goto x86_l_9a1;
	case 2467ULL: goto x86_l_9a3;
	case 2470ULL: goto x86_l_9a6;
	case 2472ULL: goto x86_l_9a8;
	case 2477ULL: goto x86_l_9ad;
	case 2481ULL: goto x86_l_9b1;
	case 2486ULL: goto x86_l_9b6;
	case 2489ULL: goto x86_l_9b9;
	case 2491ULL: goto x86_l_9bb;
	case 2494ULL: goto x86_l_9be;
	case 2496ULL: goto x86_l_9c0;
	case 2499ULL: goto x86_l_9c3;
	case 2503ULL: goto x86_l_9c7;
	case 2506ULL: goto x86_l_9ca;
	case 2508ULL: goto x86_l_9cc;
	case 2510ULL: goto x86_l_9ce;
	case 2513ULL: goto x86_l_9d1;
	case 2516ULL: goto x86_l_9d4;
	case 2519ULL: goto x86_l_9d7;
	case 2522ULL: goto x86_l_9da;
	case 2527ULL: goto x86_l_9df;
	case 2534ULL: goto x86_l_9e6;
	case 2537ULL: goto x86_l_9e9;
	case 2539ULL: goto x86_l_9eb;
	case 2544ULL: goto x86_l_9f0;
	case 2548ULL: goto x86_l_9f4;
	case 2551ULL: goto x86_l_9f7;
	case 2553ULL: goto x86_l_9f9;
	case 2560ULL: goto x86_l_a00;
	case 2567ULL: goto x86_l_a07;
	case 2570ULL: goto x86_l_a0a;
	case 2577ULL: goto x86_l_a11;
	case 2583ULL: goto x86_l_a17;
	case 2590ULL: goto x86_l_a1e;
	case 2593ULL: goto x86_l_a21;
	case 2599ULL: goto x86_l_a27;
	case 2601ULL: goto x86_l_a29;
	case 2606ULL: goto x86_l_a2e;
	case 2611ULL: goto x86_l_a33;
	case 2616ULL: goto x86_l_a38;
	case 2621ULL: goto x86_l_a3d;
	case 2625ULL: goto x86_l_a41;
	case 2633ULL: goto x86_l_a49;
	case 2640ULL: goto x86_l_a50;
	case 2647ULL: goto x86_l_a57;
	case 2654ULL: goto x86_l_a5e;
	case 2659ULL: goto x86_l_a63;
	case 2661ULL: goto x86_l_a65;
	case 2664ULL: goto x86_l_a68;
	case 2671ULL: goto x86_l_a6f;
	case 2676ULL: goto x86_l_a74;
	case 2681ULL: goto x86_l_a79;
	case 2688ULL: goto x86_l_a80;
	case 2692ULL: goto x86_l_a84;
	case 2699ULL: goto x86_l_a8b;
	case 2704ULL: goto x86_l_a90;
	case 2706ULL: goto x86_l_a92;
	case 2708ULL: goto x86_l_a94;
	case 2710ULL: goto x86_l_a96;
	case 2713ULL: goto x86_l_a99;
	case 2720ULL: goto x86_l_aa0;
	case 2722ULL: goto x86_l_aa2;
	case 2729ULL: goto x86_l_aa9;
	case 2736ULL: goto x86_l_ab0;
	case 2739ULL: goto x86_l_ab3;
	case 2746ULL: goto x86_l_aba;
	case 2752ULL: goto x86_l_ac0;
	case 2754ULL: goto x86_l_ac2;
	case 2756ULL: goto x86_l_ac4;
	case 2759ULL: goto x86_l_ac7;
	case 2762ULL: goto x86_l_aca;
	case 2767ULL: goto x86_l_acf;
	case 2773ULL: goto x86_l_ad5;
	case 2777ULL: goto x86_l_ad9;
	case 2785ULL: goto x86_l_ae1;
	case 2793ULL: goto x86_l_ae9;
	case 2797ULL: goto x86_l_aed;
	case 2804ULL: goto x86_l_af4;
	case 2813ULL: goto x86_l_afd;
	case 2818ULL: goto x86_l_b02;
	case 2823ULL: goto x86_l_b07;
	case 2828ULL: goto x86_l_b0c;
	case 2833ULL: goto x86_l_b11;
	case 2836ULL: goto x86_l_b14;
	case 2838ULL: goto x86_l_b16;
	case 2843ULL: goto x86_l_b1b;
	case 2846ULL: goto x86_l_b1e;
	case 2848ULL: goto x86_l_b20;
	case 2851ULL: goto x86_l_b23;
	case 2857ULL: goto x86_l_b29;
	case 2859ULL: goto x86_l_b2b;
	case 2863ULL: goto x86_l_b2f;
	case 2870ULL: goto x86_l_b36;
	case 2875ULL: goto x86_l_b3b;
	case 2880ULL: goto x86_l_b40;
	case 2887ULL: goto x86_l_b47;
	case 2891ULL: goto x86_l_b4b;
	case 2898ULL: goto x86_l_b52;
	case 2903ULL: goto x86_l_b57;
	case 2908ULL: goto x86_l_b5c;
	case 2910ULL: goto x86_l_b5e;
	case 2914ULL: goto x86_l_b62;
	case 2916ULL: goto x86_l_b64;
	case 2918ULL: goto x86_l_b66;
	case 2921ULL: goto x86_l_b69;
	case 2927ULL: goto x86_l_b6f;
	case 2933ULL: goto x86_l_b75;
	case 2935ULL: goto x86_l_b77;
	case 2940ULL: goto x86_l_b7c;
	case 2945ULL: goto x86_l_b81;
	case 2952ULL: goto x86_l_b88;
	case 2957ULL: goto x86_l_b8d;
	case 2959ULL: goto x86_l_b8f;
	case 2967ULL: goto x86_l_b97;
	case 2973ULL: goto x86_l_b9d;
	case 2979ULL: goto x86_l_ba3;
	case 2985ULL: goto x86_l_ba9;
	case 2988ULL: goto x86_l_bac;
	case 2994ULL: goto x86_l_bb2;
	case 3000ULL: goto x86_l_bb8;
	case 3007ULL: goto x86_l_bbf;
	case 3015ULL: goto x86_l_bc7;
	case 3023ULL: goto x86_l_bcf;
	case 3027ULL: goto x86_l_bd3;
	case 3034ULL: goto x86_l_bda;
	case 3043ULL: goto x86_l_be3;
	case 3048ULL: goto x86_l_be8;
	case 3053ULL: goto x86_l_bed;
	case 3058ULL: goto x86_l_bf2;
	case 3063ULL: goto x86_l_bf7;
	case 3066ULL: goto x86_l_bfa;
	case 3068ULL: goto x86_l_bfc;
	case 3073ULL: goto x86_l_c01;
	case 3076ULL: goto x86_l_c04;
	case 3078ULL: goto x86_l_c06;
	case 3081ULL: goto x86_l_c09;
	case 3087ULL: goto x86_l_c0f;
	case 3089ULL: goto x86_l_c11;
	case 3093ULL: goto x86_l_c15;
	case 3100ULL: goto x86_l_c1c;
	case 3105ULL: goto x86_l_c21;
	case 3110ULL: goto x86_l_c26;
	case 3117ULL: goto x86_l_c2d;
	case 3121ULL: goto x86_l_c31;
	case 3128ULL: goto x86_l_c38;
	case 3133ULL: goto x86_l_c3d;
	case 3138ULL: goto x86_l_c42;
	case 3140ULL: goto x86_l_c44;
	case 3144ULL: goto x86_l_c48;
	case 3146ULL: goto x86_l_c4a;
	case 3148ULL: goto x86_l_c4c;
	case 3151ULL: goto x86_l_c4f;
	case 3157ULL: goto x86_l_c55;
	case 3163ULL: goto x86_l_c5b;
	case 3165ULL: goto x86_l_c5d;
	case 3172ULL: goto x86_l_c64;
	case 3177ULL: goto x86_l_c69;
	case 3179ULL: goto x86_l_c6b;
	case 3187ULL: goto x86_l_c73;
	case 3193ULL: goto x86_l_c79;
	case 3200ULL: goto x86_l_c80;
	case 3204ULL: goto x86_l_c84;
	case 3209ULL: goto x86_l_c89;
	case 3214ULL: goto x86_l_c8e;
	case 3219ULL: goto x86_l_c93;
	case 3224ULL: goto x86_l_c98;
	case 3227ULL: goto x86_l_c9b;
	case 3229ULL: goto x86_l_c9d;
	case 3234ULL: goto x86_l_ca2;
	case 3239ULL: goto x86_l_ca7;
	case 3243ULL: goto x86_l_cab;
	case 3248ULL: goto x86_l_cb0;
	case 3253ULL: goto x86_l_cb5;
	case 3258ULL: goto x86_l_cba;
	case 3263ULL: goto x86_l_cbf;
	case 3265ULL: goto x86_l_cc1;
	case 3270ULL: goto x86_l_cc6;
	case 3274ULL: goto x86_l_cca;
	case 3279ULL: goto x86_l_ccf;
	case 3284ULL: goto x86_l_cd4;
	case 3289ULL: goto x86_l_cd9;
	case 3294ULL: goto x86_l_cde;
	case 3296ULL: goto x86_l_ce0;
	case 3299ULL: goto x86_l_ce3;
	case 3304ULL: goto x86_l_ce8;
	case 3308ULL: goto x86_l_cec;
	case 3313ULL: goto x86_l_cf1;
	case 3318ULL: goto x86_l_cf6;
	case 3323ULL: goto x86_l_cfb;
	case 3328ULL: goto x86_l_d00;
	case 3330ULL: goto x86_l_d02;
	case 3334ULL: goto x86_l_d06;
	case 3338ULL: goto x86_l_d0a;
	case 3342ULL: goto x86_l_d0e;
	case 3347ULL: goto x86_l_d13;
	case 3352ULL: goto x86_l_d18;
	case 3357ULL: goto x86_l_d1d;
	case 3362ULL: goto x86_l_d22;
	case 3365ULL: goto x86_l_d25;
	case 3367ULL: goto x86_l_d27;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6c0:
	/* 0x6c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c2:
	/* 0x6c2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6c5:
	/* 0x6c5: je     6d3 <syscall__execve_enter+0x6d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6d3;
	}
x86_l_6c7:
	/* 0x6c7: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ca:
	/* 0x6ca: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6ce:
	/* 0x6ce: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_6d1:
	/* 0x6d1: jmp    6d5 <syscall__execve_enter+0x6d5> */
	goto x86_l_6d5;
x86_l_6d3:
	/* 0x6d3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6d5:
	/* 0x6d5: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_6d8:
	/* 0x6d8: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_6db:
	/* 0x6db: or     r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_6de:
	/* 0x6de: and    r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_6e1:
	/* 0x6e1: movzx  r14d,WORD PTR [rsp+0x56] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 86ULL);
x86_l_6e7:
	/* 0x6e7: cmp    QWORD PTR [rbp+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_6ef:
	/* 0x6ef: je     7d8 <syscall__execve_enter+0x7d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7d8;
	}
x86_l_6f5:
	/* 0x6f5: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_6fa:
	/* 0x6fa: add    rdx,QWORD PTR [rbp+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_701:
	/* 0x701: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_706:
	/* 0x706: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_70b:
	/* 0x70b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_710:
	/* 0x710: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_715:
	/* 0x715: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_717:
	/* 0x717: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_71c:
	/* 0x71c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_721:
	/* 0x721: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_726:
	/* 0x726: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_72b:
	/* 0x72b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_730:
	/* 0x730: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_732:
	/* 0x732: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_737:
	/* 0x737: lea    r12,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_73c:
	/* 0x73c: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_741:
	/* 0x741: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_746:
	/* 0x746: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_749:
	/* 0x749: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_74e:
	/* 0x74e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_750:
	/* 0x750: lea    r15,[rbp+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_754:
	/* 0x754: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_759:
	/* 0x759: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_75e:
	/* 0x75e: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_761:
	/* 0x761: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_766:
	/* 0x766: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_769:
	/* 0x769: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76b:
	/* 0x76b: mov    r12,QWORD PTR [rbp+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_772:
	/* 0x772: mov    rbp,QWORD PTR [rbp+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_779:
	/* 0x779: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_77f:
	/* 0x77f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_786:
	/* 0x786: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_78b:
	/* 0x78b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_790:
	/* 0x790: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_793:
	/* 0x793: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_795:
	/* 0x795: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_79c:
	/* 0x79c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_79f:
	/* 0x79f: je     7bf <syscall__execve_enter+0x7bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7bf;
	}
x86_l_7a1:
	/* 0x7a1: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_7a4:
	/* 0x7a4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7a9:
	/* 0x7a9: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_7ac:
	/* 0x7ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ae:
	/* 0x7ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7b1:
	/* 0x7b1: je     7bf <syscall__execve_enter+0x7bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7bf;
	}
x86_l_7b3:
	/* 0x7b3: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7b6:
	/* 0x7b6: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7ba:
	/* 0x7ba: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_7bd:
	/* 0x7bd: jmp    7c1 <syscall__execve_enter+0x7c1> */
	goto x86_l_7c1;
x86_l_7bf:
	/* 0x7bf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7c1:
	/* 0x7c1: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_7c4:
	/* 0x7c4: and    r14,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_7c7:
	/* 0x7c7: or     r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_7ca:
	/* 0x7ca: and    r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_7cd:
	/* 0x7cd: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7d2:
	/* 0x7d2: movzx  r14d,WORD PTR [rsp+0x56] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 86ULL);
x86_l_7d8:
	/* 0x7d8: cmp    QWORD PTR [rbp+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_7e0:
	/* 0x7e0: je     86b <syscall__execve_enter+0x86b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_86b;
	}
x86_l_7e6:
	/* 0x7e6: lea    r15,[rbp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_7ea:
	/* 0x7ea: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_7ef:
	/* 0x7ef: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_7f4:
	/* 0x7f4: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_7f7:
	/* 0x7f7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_7fc:
	/* 0x7fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7fe:
	/* 0x7fe: mov    r12,QWORD PTR [rbp+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_805:
	/* 0x805: mov    rbp,QWORD PTR [rbp+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_80c:
	/* 0x80c: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_812:
	/* 0x812: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_819:
	/* 0x819: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_81e:
	/* 0x81e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_823:
	/* 0x823: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_826:
	/* 0x826: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_828:
	/* 0x828: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_82f:
	/* 0x82f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_832:
	/* 0x832: je     852 <syscall__execve_enter+0x852> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_852;
	}
x86_l_834:
	/* 0x834: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_837:
	/* 0x837: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_83c:
	/* 0x83c: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_83f:
	/* 0x83f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_841:
	/* 0x841: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_844:
	/* 0x844: je     852 <syscall__execve_enter+0x852> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_852;
	}
x86_l_846:
	/* 0x846: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_849:
	/* 0x849: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_84d:
	/* 0x84d: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_850:
	/* 0x850: jmp    854 <syscall__execve_enter+0x854> */
	goto x86_l_854;
x86_l_852:
	/* 0x852: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_854:
	/* 0x854: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_857:
	/* 0x857: and    r14,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_85a:
	/* 0x85a: or     r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_85d:
	/* 0x85d: and    r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_860:
	/* 0x860: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_865:
	/* 0x865: movzx  r14d,WORD PTR [rsp+0x56] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 86ULL);
x86_l_86b:
	/* 0x86b: mov    r15,QWORD PTR [rbp+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_872:
	/* 0x872: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_875:
	/* 0x875: je     8e1 <syscall__execve_enter+0x8e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8e1;
	}
x86_l_877:
	/* 0x877: mov    eax,DWORD PTR [rbp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_87a:
	/* 0x87a: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_87e:
	/* 0x87e: mov    r12,QWORD PTR [rbp+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_885:
	/* 0x885: mov    WORD PTR [rsp+0x4],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_88b:
	/* 0x88b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_892:
	/* 0x892: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_897:
	/* 0x897: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_89c:
	/* 0x89c: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_89f:
	/* 0x89f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a1:
	/* 0x8a1: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_8a8:
	/* 0x8a8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8ab:
	/* 0x8ab: je     8cd <syscall__execve_enter+0x8cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8cd;
	}
x86_l_8ad:
	/* 0x8ad: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_8b0:
	/* 0x8b0: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8b5:
	/* 0x8b5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8ba:
	/* 0x8ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8bc:
	/* 0x8bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8bf:
	/* 0x8bf: je     8cd <syscall__execve_enter+0x8cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8cd;
	}
x86_l_8c1:
	/* 0x8c1: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8c4:
	/* 0x8c4: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8c8:
	/* 0x8c8: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_8cb:
	/* 0x8cb: jmp    8cf <syscall__execve_enter+0x8cf> */
	goto x86_l_8cf;
x86_l_8cd:
	/* 0x8cd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8cf:
	/* 0x8cf: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_8d2:
	/* 0x8d2: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_8d5:
	/* 0x8d5: or     r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_8d8:
	/* 0x8d8: and    r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_8db:
	/* 0x8db: movzx  r14d,WORD PTR [rsp+0x56] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 86ULL);
x86_l_8e1:
	/* 0x8e1: mov    r15,QWORD PTR [rbp+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_8e8:
	/* 0x8e8: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_8eb:
	/* 0x8eb: je     94e <syscall__execve_enter+0x94e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_94e;
	}
x86_l_8ed:
	/* 0x8ed: mov    r12,QWORD PTR [rbp+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_8f4:
	/* 0x8f4: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8fa:
	/* 0x8fa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_901:
	/* 0x901: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_906:
	/* 0x906: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_90b:
	/* 0x90b: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_90e:
	/* 0x90e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_910:
	/* 0x910: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_917:
	/* 0x917: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_91a:
	/* 0x91a: je     93a <syscall__execve_enter+0x93a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_93a;
	}
x86_l_91c:
	/* 0x91c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_91f:
	/* 0x91f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_924:
	/* 0x924: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_927:
	/* 0x927: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_929:
	/* 0x929: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_92c:
	/* 0x92c: je     93a <syscall__execve_enter+0x93a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_93a;
	}
x86_l_92e:
	/* 0x92e: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_931:
	/* 0x931: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_935:
	/* 0x935: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_938:
	/* 0x938: jmp    93c <syscall__execve_enter+0x93c> */
	goto x86_l_93c;
x86_l_93a:
	/* 0x93a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_93c:
	/* 0x93c: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_93f:
	/* 0x93f: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_942:
	/* 0x942: or     r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_945:
	/* 0x945: and    r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_948:
	/* 0x948: movzx  r14d,WORD PTR [rsp+0x56] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 86ULL);
x86_l_94e:
	/* 0x94e: mov    r15,QWORD PTR [rbp+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_955:
	/* 0x955: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_958:
	/* 0x958: je     9df <syscall__execve_enter+0x9df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9df;
	}
x86_l_95e:
	/* 0x95e: mov    r12,QWORD PTR [rbp+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_965:
	/* 0x965: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_96b:
	/* 0x96b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_972:
	/* 0x972: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_977:
	/* 0x977: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_97c:
	/* 0x97c: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_97f:
	/* 0x97f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_981:
	/* 0x981: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_988:
	/* 0x988: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_98b:
	/* 0x98b: je     9cc <syscall__execve_enter+0x9cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9cc;
	}
x86_l_98d:
	/* 0x98d: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_990:
	/* 0x990: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_995:
	/* 0x995: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_999:
	/* 0x999: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_99e:
	/* 0x99e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_9a1:
	/* 0x9a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a3:
	/* 0x9a3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9a6:
	/* 0x9a6: jne    9c0 <syscall__execve_enter+0x9c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9c0;
	}
x86_l_9a8:
	/* 0x9a8: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_9ad:
	/* 0x9ad: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_9b1:
	/* 0x9b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9b6:
	/* 0x9b6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_9b9:
	/* 0x9b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9bb:
	/* 0x9bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9be:
	/* 0x9be: je     9cc <syscall__execve_enter+0x9cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9cc;
	}
x86_l_9c0:
	/* 0x9c0: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9c3:
	/* 0x9c3: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9c7:
	/* 0x9c7: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_9ca:
	/* 0x9ca: jmp    9ce <syscall__execve_enter+0x9ce> */
	goto x86_l_9ce;
x86_l_9cc:
	/* 0x9cc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9ce:
	/* 0x9ce: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_9d1:
	/* 0x9d1: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_9d4:
	/* 0x9d4: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_9d7:
	/* 0x9d7: and    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_9da:
	/* 0x9da: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9df:
	/* 0x9df: mov    rax,QWORD PTR [rbp+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_9e6:
	/* 0x9e6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9e9:
	/* 0x9e9: je     9f7 <syscall__execve_enter+0x9f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9f7;
	}
x86_l_9eb:
	/* 0x9eb: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_9f0:
	/* 0x9f0: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_9f4:
	/* 0x9f4: or     r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_9f7:
	/* 0x9f7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9f9:
	/* 0x9f9: and    r13,QWORD PTR [rbp+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_a00:
	/* 0xa00: mov    rcx,QWORD PTR [rbp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a07:
	/* 0xa07: and    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_a0a:
	/* 0xa0a: mov    QWORD PTR [rbp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a11:
	/* 0xa11: je     1192 <syscall__execve_enter+0x1192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4498ULL;
	}
x86_l_a17:
	/* 0xa17: lea    rbx,[rbp+0x7d8a] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_a1e:
	/* 0xa1e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_a21:
	/* 0xa21: cmp    rax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 32000ULL);
x86_l_a27:
	/* 0xa27: jb     a38 <syscall__execve_enter+0xa38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_a38;
	}
x86_l_a29:
	/* 0xa29: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a2e:
	/* 0xa2e: mov    r13,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a33:
	/* 0xa33: jmp    b9d <syscall__execve_enter+0xb9d> */
	goto x86_l_b9d;
x86_l_a38:
	/* 0xa38: mov    r13,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a3d:
	/* 0xa3d: mov    rdx,QWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a41:
	/* 0xa41: mov    BYTE PTR [rbp+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_a49:
	/* 0xa49: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_a50:
	/* 0xa50: mov    WORD PTR [rbp+0x7d8c],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_a57:
	/* 0xa57: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_a5e:
	/* 0xa5e: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a63:
	/* 0xa63: ja     ac7 <syscall__execve_enter+0xac7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ac7;
	}
x86_l_a65:
	/* 0xa65: add    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a68:
	/* 0xa68: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_a6f:
	/* 0xa6f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_a74:
	/* 0xa74: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_a79:
	/* 0xa79: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_a80:
	/* 0xa80: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_a84:
	/* 0xa84: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_a8b:
	/* 0xa8b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_a90:
	/* 0xa90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a92:
	/* 0xa92: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a94:
	/* 0xa94: jle    ac4 <syscall__execve_enter+0xac4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_ac4;
	}
x86_l_a96:
	/* 0xa96: movzx  ecx,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_a99:
	/* 0xa99: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_aa0:
	/* 0xaa0: ja     ac7 <syscall__execve_enter+0xac7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ac7;
	}
x86_l_aa2:
	/* 0xaa2: mov    DWORD PTR [rcx+rbp*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 138ULL);
x86_l_aa9:
	/* 0xaa9: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_ab0:
	/* 0xab0: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_ab3:
	/* 0xab3: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_aba:
	/* 0xaba: inc    BYTE PTR [rbp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_ac0:
	/* 0xac0: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_ac2:
	/* 0xac2: jmp    ac7 <syscall__execve_enter+0xac7> */
	goto x86_l_ac7;
x86_l_ac4:
	/* 0xac4: movzx  ecx,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_ac7:
	/* 0xac7: movzx  eax,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_aca:
	/* 0xaca: cmp    eax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31999ULL);
x86_l_acf:
	/* 0xacf: ja     b9d <syscall__execve_enter+0xb9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b9d;
	}
x86_l_ad5:
	/* 0xad5: mov    r13,QWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ad9:
	/* 0xad9: mov    BYTE PTR [rbp+rax*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519553ULL);
x86_l_ae1:
	/* 0xae1: movzx  r15d,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_ae9:
	/* 0xae9: lea    eax,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_aed:
	/* 0xaed: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_af4:
	/* 0xaf4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_afd:
	/* 0xafd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b02:
	/* 0xb02: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b07:
	/* 0xb07: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b0c:
	/* 0xb0c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b11:
	/* 0xb11: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_b14:
	/* 0xb14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b16:
	/* 0xb16: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b1b:
	/* 0xb1b: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_b1e:
	/* 0xb1e: je     b75 <syscall__execve_enter+0xb75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b75;
	}
x86_l_b20:
	/* 0xb20: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b23:
	/* 0xb23: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_b29:
	/* 0xb29: ja     b75 <syscall__execve_enter+0xb75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b75;
	}
x86_l_b2b:
	/* 0xb2b: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_b2f:
	/* 0xb2f: add    rdx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_b36:
	/* 0xb36: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_b3b:
	/* 0xb3b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_b40:
	/* 0xb40: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_b47:
	/* 0xb47: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_b4b:
	/* 0xb4b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_b52:
	/* 0xb52: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b57:
	/* 0xb57: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_b5c:
	/* 0xb5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b5e:
	/* 0xb5e: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b62:
	/* 0xb62: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b64:
	/* 0xb64: jle    b75 <syscall__execve_enter+0xb75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_b75;
	}
x86_l_b66:
	/* 0xb66: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b69:
	/* 0xb69: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_b6f:
	/* 0xb6f: jbe    11a8 <syscall__execve_enter+0x11a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 4520ULL;
	}
x86_l_b75:
	/* 0xb75: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b77:
	/* 0xb77: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b7c:
	/* 0xb7c: mov    r13,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b81:
	/* 0xb81: cmp    r15d,0x7cfe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 31998ULL);
x86_l_b88:
	/* 0xb88: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b8d:
	/* 0xb8d: ja     b9d <syscall__execve_enter+0xb9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b9d;
	}
x86_l_b8f:
	/* 0xb8f: mov    BYTE PTR [rbp+r15*1+0x8a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 138ULL);
x86_l_b97:
	/* 0xb97: inc    BYTE PTR [rbp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_b9d:
	/* 0xb9d: test   BYTE PTR [r12+0x4],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869185ULL);
x86_l_ba3:
	/* 0xba3: je     c79 <syscall__execve_enter+0xc79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c79;
	}
x86_l_ba9:
	/* 0xba9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_bac:
	/* 0xbac: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_bb2:
	/* 0xbb2: ja     c79 <syscall__execve_enter+0xc79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_c79;
	}
x86_l_bb8:
	/* 0xbb8: mov    r13,QWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_bbf:
	/* 0xbbf: mov    BYTE PTR [rbp+rax*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519554ULL);
x86_l_bc7:
	/* 0xbc7: movzx  r15d,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_bcf:
	/* 0xbcf: lea    eax,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_bd3:
	/* 0xbd3: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_bda:
	/* 0xbda: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_be3:
	/* 0xbe3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_be8:
	/* 0xbe8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_bed:
	/* 0xbed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bf2:
	/* 0xbf2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bf7:
	/* 0xbf7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_bfa:
	/* 0xbfa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bfc:
	/* 0xbfc: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c01:
	/* 0xc01: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_c04:
	/* 0xc04: je     c5b <syscall__execve_enter+0xc5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c5b;
	}
x86_l_c06:
	/* 0xc06: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c09:
	/* 0xc09: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_c0f:
	/* 0xc0f: ja     c5b <syscall__execve_enter+0xc5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_c5b;
	}
x86_l_c11:
	/* 0xc11: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_c15:
	/* 0xc15: add    rdx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_c1c:
	/* 0xc1c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_c21:
	/* 0xc21: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_c26:
	/* 0xc26: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_c2d:
	/* 0xc2d: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_c31:
	/* 0xc31: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_c38:
	/* 0xc38: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c3d:
	/* 0xc3d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_c42:
	/* 0xc42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c44:
	/* 0xc44: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c48:
	/* 0xc48: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c4a:
	/* 0xc4a: jle    c5b <syscall__execve_enter+0xc5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_c5b;
	}
x86_l_c4c:
	/* 0xc4c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c4f:
	/* 0xc4f: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_c55:
	/* 0xc55: jbe    347d <syscall__execve_enter+0x347d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13437ULL;
	}
x86_l_c5b:
	/* 0xc5b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c5d:
	/* 0xc5d: cmp    r15d,0x7cfe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 31998ULL);
x86_l_c64:
	/* 0xc64: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c69:
	/* 0xc69: ja     c79 <syscall__execve_enter+0xc79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_c79;
	}
x86_l_c6b:
	/* 0xc6b: mov    BYTE PTR [rbp+r15*1+0x8a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 138ULL);
x86_l_c73:
	/* 0xc73: inc    BYTE PTR [rbp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_c79:
	/* 0xc79: mov    rbx,QWORD PTR [rbp+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_c80:
	/* 0xc80: lea    r15,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c84:
	/* 0xc84: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c89:
	/* 0xc89: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c8e:
	/* 0xc8e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c93:
	/* 0xc93: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c98:
	/* 0xc98: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_c9b:
	/* 0xc9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c9d:
	/* 0xc9d: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ca2:
	/* 0xca2: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ca7:
	/* 0xca7: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cab:
	/* 0xcab: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cb0:
	/* 0xcb0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_cb5:
	/* 0xcb5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cba:
	/* 0xcba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cbf:
	/* 0xcbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cc1:
	/* 0xcc1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cc6:
	/* 0xcc6: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_cca:
	/* 0xcca: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ccf:
	/* 0xccf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_cd4:
	/* 0xcd4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cd9:
	/* 0xcd9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cde:
	/* 0xcde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ce0:
	/* 0xce0: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_ce3:
	/* 0xce3: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ce8:
	/* 0xce8: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_cec:
	/* 0xcec: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cf1:
	/* 0xcf1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_cf6:
	/* 0xcf6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cfb:
	/* 0xcfb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d00:
	/* 0xd00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d02:
	/* 0xd02: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d06:
	/* 0xd06: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_d0a:
	/* 0xd0a: lea    r12,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d0e:
	/* 0xd0e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d13:
	/* 0xd13: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d18:
	/* 0xd18: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d1d:
	/* 0xd1d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d22:
	/* 0xd22: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d25:
	/* 0xd25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d27:
	/* 0xd27: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 3372ULL;
}

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3372ULL: goto x86_l_d2c;
	case 3377ULL: goto x86_l_d31;
	case 3382ULL: goto x86_l_d36;
	case 3387ULL: goto x86_l_d3b;
	case 3392ULL: goto x86_l_d40;
	case 3395ULL: goto x86_l_d43;
	case 3397ULL: goto x86_l_d45;
	case 3401ULL: goto x86_l_d49;
	case 3405ULL: goto x86_l_d4d;
	case 3409ULL: goto x86_l_d51;
	case 3413ULL: goto x86_l_d55;
	case 3418ULL: goto x86_l_d5a;
	case 3423ULL: goto x86_l_d5f;
	case 3428ULL: goto x86_l_d64;
	case 3433ULL: goto x86_l_d69;
	case 3435ULL: goto x86_l_d6b;
	case 3439ULL: goto x86_l_d6f;
	case 3443ULL: goto x86_l_d73;
	case 3448ULL: goto x86_l_d78;
	case 3453ULL: goto x86_l_d7d;
	case 3458ULL: goto x86_l_d82;
	case 3463ULL: goto x86_l_d87;
	case 3466ULL: goto x86_l_d8a;
	case 3468ULL: goto x86_l_d8c;
	case 3473ULL: goto x86_l_d91;
	case 3477ULL: goto x86_l_d95;
	case 3482ULL: goto x86_l_d9a;
	case 3487ULL: goto x86_l_d9f;
	case 3492ULL: goto x86_l_da4;
	case 3497ULL: goto x86_l_da9;
	case 3499ULL: goto x86_l_dab;
	case 3504ULL: goto x86_l_db0;
	case 3509ULL: goto x86_l_db5;
	case 3514ULL: goto x86_l_dba;
	case 3519ULL: goto x86_l_dbf;
	case 3524ULL: goto x86_l_dc4;
	case 3527ULL: goto x86_l_dc7;
	case 3529ULL: goto x86_l_dc9;
	case 3533ULL: goto x86_l_dcd;
	case 3537ULL: goto x86_l_dd1;
	case 3541ULL: goto x86_l_dd5;
	case 3545ULL: goto x86_l_dd9;
	case 3550ULL: goto x86_l_dde;
	case 3555ULL: goto x86_l_de3;
	case 3560ULL: goto x86_l_de8;
	case 3565ULL: goto x86_l_ded;
	case 3567ULL: goto x86_l_def;
	case 3571ULL: goto x86_l_df3;
	case 3575ULL: goto x86_l_df7;
	case 3580ULL: goto x86_l_dfc;
	case 3585ULL: goto x86_l_e01;
	case 3590ULL: goto x86_l_e06;
	case 3595ULL: goto x86_l_e0b;
	case 3598ULL: goto x86_l_e0e;
	case 3600ULL: goto x86_l_e10;
	case 3605ULL: goto x86_l_e15;
	case 3610ULL: goto x86_l_e1a;
	case 3615ULL: goto x86_l_e1f;
	case 3620ULL: goto x86_l_e24;
	case 3625ULL: goto x86_l_e29;
	case 3628ULL: goto x86_l_e2c;
	case 3630ULL: goto x86_l_e2e;
	case 3634ULL: goto x86_l_e32;
	case 3638ULL: goto x86_l_e36;
	case 3642ULL: goto x86_l_e3a;
	case 3646ULL: goto x86_l_e3e;
	case 3651ULL: goto x86_l_e43;
	case 3656ULL: goto x86_l_e48;
	case 3661ULL: goto x86_l_e4d;
	case 3666ULL: goto x86_l_e52;
	case 3668ULL: goto x86_l_e54;
	case 3673ULL: goto x86_l_e59;
	case 3677ULL: goto x86_l_e5d;
	case 3682ULL: goto x86_l_e62;
	case 3687ULL: goto x86_l_e67;
	case 3692ULL: goto x86_l_e6c;
	case 3697ULL: goto x86_l_e71;
	case 3699ULL: goto x86_l_e73;
	case 3704ULL: goto x86_l_e78;
	case 3708ULL: goto x86_l_e7c;
	case 3713ULL: goto x86_l_e81;
	case 3718ULL: goto x86_l_e86;
	case 3723ULL: goto x86_l_e8b;
	case 3728ULL: goto x86_l_e90;
	case 3731ULL: goto x86_l_e93;
	case 3733ULL: goto x86_l_e95;
	case 3738ULL: goto x86_l_e9a;
	case 3743ULL: goto x86_l_e9f;
	case 3748ULL: goto x86_l_ea4;
	case 3753ULL: goto x86_l_ea9;
	case 3758ULL: goto x86_l_eae;
	case 3761ULL: goto x86_l_eb1;
	case 3763ULL: goto x86_l_eb3;
	case 3767ULL: goto x86_l_eb7;
	case 3771ULL: goto x86_l_ebb;
	case 3775ULL: goto x86_l_ebf;
	case 3779ULL: goto x86_l_ec3;
	case 3784ULL: goto x86_l_ec8;
	case 3789ULL: goto x86_l_ecd;
	case 3794ULL: goto x86_l_ed2;
	case 3799ULL: goto x86_l_ed7;
	case 3801ULL: goto x86_l_ed9;
	case 3806ULL: goto x86_l_ede;
	case 3810ULL: goto x86_l_ee2;
	case 3815ULL: goto x86_l_ee7;
	case 3820ULL: goto x86_l_eec;
	case 3825ULL: goto x86_l_ef1;
	case 3830ULL: goto x86_l_ef6;
	case 3832ULL: goto x86_l_ef8;
	case 3837ULL: goto x86_l_efd;
	case 3839ULL: goto x86_l_eff;
	case 3844ULL: goto x86_l_f04;
	case 3849ULL: goto x86_l_f09;
	case 3854ULL: goto x86_l_f0e;
	case 3859ULL: goto x86_l_f13;
	case 3862ULL: goto x86_l_f16;
	case 3864ULL: goto x86_l_f18;
	case 3869ULL: goto x86_l_f1d;
	case 3874ULL: goto x86_l_f22;
	case 3879ULL: goto x86_l_f27;
	case 3884ULL: goto x86_l_f2c;
	case 3889ULL: goto x86_l_f31;
	case 3892ULL: goto x86_l_f34;
	case 3894ULL: goto x86_l_f36;
	case 3898ULL: goto x86_l_f3a;
	case 3902ULL: goto x86_l_f3e;
	case 3906ULL: goto x86_l_f42;
	case 3910ULL: goto x86_l_f46;
	case 3915ULL: goto x86_l_f4b;
	case 3920ULL: goto x86_l_f50;
	case 3925ULL: goto x86_l_f55;
	case 3930ULL: goto x86_l_f5a;
	case 3932ULL: goto x86_l_f5c;
	case 3936ULL: goto x86_l_f60;
	case 3940ULL: goto x86_l_f64;
	case 3944ULL: goto x86_l_f68;
	case 3951ULL: goto x86_l_f6f;
	case 3956ULL: goto x86_l_f74;
	case 3961ULL: goto x86_l_f79;
	case 3966ULL: goto x86_l_f7e;
	case 3970ULL: goto x86_l_f82;
	case 3975ULL: goto x86_l_f87;
	case 3978ULL: goto x86_l_f8a;
	case 3980ULL: goto x86_l_f8c;
	case 3985ULL: goto x86_l_f91;
	case 3989ULL: goto x86_l_f95;
	case 3994ULL: goto x86_l_f9a;
	case 3999ULL: goto x86_l_f9f;
	case 4004ULL: goto x86_l_fa4;
	case 4009ULL: goto x86_l_fa9;
	case 4011ULL: goto x86_l_fab;
	case 4016ULL: goto x86_l_fb0;
	case 4021ULL: goto x86_l_fb5;
	case 4026ULL: goto x86_l_fba;
	case 4031ULL: goto x86_l_fbf;
	case 4036ULL: goto x86_l_fc4;
	case 4041ULL: goto x86_l_fc9;
	case 4043ULL: goto x86_l_fcb;
	case 4047ULL: goto x86_l_fcf;
	case 4051ULL: goto x86_l_fd3;
	case 4056ULL: goto x86_l_fd8;
	case 4058ULL: goto x86_l_fda;
	case 4062ULL: goto x86_l_fde;
	case 4066ULL: goto x86_l_fe2;
	case 4071ULL: goto x86_l_fe7;
	case 4076ULL: goto x86_l_fec;
	case 4081ULL: goto x86_l_ff1;
	case 4086ULL: goto x86_l_ff6;
	case 4088ULL: goto x86_l_ff8;
	case 4093ULL: goto x86_l_ffd;
	case 4097ULL: goto x86_l_1001;
	case 4102ULL: goto x86_l_1006;
	case 4106ULL: goto x86_l_100a;
	case 4111ULL: goto x86_l_100f;
	case 4116ULL: goto x86_l_1014;
	case 4121ULL: goto x86_l_1019;
	case 4126ULL: goto x86_l_101e;
	case 4128ULL: goto x86_l_1020;
	case 4133ULL: goto x86_l_1025;
	case 4137ULL: goto x86_l_1029;
	case 4141ULL: goto x86_l_102d;
	case 4146ULL: goto x86_l_1032;
	case 4151ULL: goto x86_l_1037;
	case 4156ULL: goto x86_l_103c;
	case 4161ULL: goto x86_l_1041;
	case 4164ULL: goto x86_l_1044;
	case 4166ULL: goto x86_l_1046;
	case 4171ULL: goto x86_l_104b;
	case 4175ULL: goto x86_l_104f;
	case 4180ULL: goto x86_l_1054;
	case 4185ULL: goto x86_l_1059;
	case 4190ULL: goto x86_l_105e;
	case 4195ULL: goto x86_l_1063;
	case 4198ULL: goto x86_l_1066;
	case 4200ULL: goto x86_l_1068;
	case 4205ULL: goto x86_l_106d;
	case 4207ULL: goto x86_l_106f;
	case 4212ULL: goto x86_l_1074;
	case 4220ULL: goto x86_l_107c;
	case 4224ULL: goto x86_l_1080;
	case 4232ULL: goto x86_l_1088;
	case 4237ULL: goto x86_l_108d;
	case 4242ULL: goto x86_l_1092;
	case 4247ULL: goto x86_l_1097;
	case 4249ULL: goto x86_l_1099;
	case 4254ULL: goto x86_l_109e;
	case 4259ULL: goto x86_l_10a3;
	case 4264ULL: goto x86_l_10a8;
	case 4269ULL: goto x86_l_10ad;
	case 4272ULL: goto x86_l_10b0;
	case 4274ULL: goto x86_l_10b2;
	case 4279ULL: goto x86_l_10b7;
	case 4284ULL: goto x86_l_10bc;
	case 4289ULL: goto x86_l_10c1;
	case 4294ULL: goto x86_l_10c6;
	case 4299ULL: goto x86_l_10cb;
	case 4301ULL: goto x86_l_10cd;
	case 4306ULL: goto x86_l_10d2;
	case 4311ULL: goto x86_l_10d7;
	case 4316ULL: goto x86_l_10dc;
	case 4321ULL: goto x86_l_10e1;
	case 4324ULL: goto x86_l_10e4;
	case 4329ULL: goto x86_l_10e9;
	case 4331ULL: goto x86_l_10eb;
	case 4334ULL: goto x86_l_10ee;
	case 4338ULL: goto x86_l_10f2;
	case 4343ULL: goto x86_l_10f7;
	case 4348ULL: goto x86_l_10fc;
	case 4353ULL: goto x86_l_1101;
	case 4356ULL: goto x86_l_1104;
	case 4358ULL: goto x86_l_1106;
	case 4363ULL: goto x86_l_110b;
	case 4368ULL: goto x86_l_1110;
	case 4373ULL: goto x86_l_1115;
	case 4378ULL: goto x86_l_111a;
	case 4381ULL: goto x86_l_111d;
	case 4383ULL: goto x86_l_111f;
	case 4388ULL: goto x86_l_1124;
	case 4392ULL: goto x86_l_1128;
	case 4400ULL: goto x86_l_1130;
	case 4402ULL: goto x86_l_1132;
	case 4409ULL: goto x86_l_1139;
	case 4414ULL: goto x86_l_113e;
	case 4419ULL: goto x86_l_1143;
	case 4424ULL: goto x86_l_1148;
	case 4427ULL: goto x86_l_114b;
	case 4429ULL: goto x86_l_114d;
	case 4431ULL: goto x86_l_114f;
	case 4433ULL: goto x86_l_1151;
	case 4437ULL: goto x86_l_1155;
	case 4445ULL: goto x86_l_115d;
	case 4450ULL: goto x86_l_1162;
	case 4455ULL: goto x86_l_1167;
	case 4458ULL: goto x86_l_116a;
	case 4464ULL: goto x86_l_1170;
	case 4468ULL: goto x86_l_1174;
	case 4475ULL: goto x86_l_117b;
	case 4480ULL: goto x86_l_1180;
	case 4485ULL: goto x86_l_1185;
	case 4490ULL: goto x86_l_118a;
	case 4493ULL: goto x86_l_118d;
	case 4496ULL: goto x86_l_1190;
	case 4498ULL: goto x86_l_1192;
	case 4505ULL: goto x86_l_1199;
	case 4506ULL: goto x86_l_119a;
	case 4508ULL: goto x86_l_119c;
	case 4510ULL: goto x86_l_119e;
	case 4512ULL: goto x86_l_11a0;
	case 4514ULL: goto x86_l_11a2;
	case 4515ULL: goto x86_l_11a3;
	case 4520ULL: goto x86_l_11a8;
	case 4524ULL: goto x86_l_11ac;
	case 4531ULL: goto x86_l_11b3;
	case 4536ULL: goto x86_l_11b8;
	case 4541ULL: goto x86_l_11bd;
	case 4546ULL: goto x86_l_11c2;
	case 4553ULL: goto x86_l_11c9;
	case 4557ULL: goto x86_l_11cd;
	case 4564ULL: goto x86_l_11d4;
	case 4569ULL: goto x86_l_11d9;
	case 4571ULL: goto x86_l_11db;
	case 4576ULL: goto x86_l_11e0;
	case 4583ULL: goto x86_l_11e7;
	case 4586ULL: goto x86_l_11ea;
	case 4593ULL: goto x86_l_11f1;
	case 4602ULL: goto x86_l_11fa;
	case 4606ULL: goto x86_l_11fe;
	case 4611ULL: goto x86_l_1203;
	case 4616ULL: goto x86_l_1208;
	case 4621ULL: goto x86_l_120d;
	case 4626ULL: goto x86_l_1212;
	case 4628ULL: goto x86_l_1214;
	case 4633ULL: goto x86_l_1219;
	case 4635ULL: goto x86_l_121b;
	case 4638ULL: goto x86_l_121e;
	case 4644ULL: goto x86_l_1224;
	case 4647ULL: goto x86_l_1227;
	case 4653ULL: goto x86_l_122d;
	case 4659ULL: goto x86_l_1233;
	case 4664ULL: goto x86_l_1238;
	case 4668ULL: goto x86_l_123c;
	case 4675ULL: goto x86_l_1243;
	case 4680ULL: goto x86_l_1248;
	case 4685ULL: goto x86_l_124d;
	case 4692ULL: goto x86_l_1254;
	case 4695ULL: goto x86_l_1257;
	case 4702ULL: goto x86_l_125e;
	case 4707ULL: goto x86_l_1263;
	case 4712ULL: goto x86_l_1268;
	case 4714ULL: goto x86_l_126a;
	case 4718ULL: goto x86_l_126e;
	case 4720ULL: goto x86_l_1270;
	case 4722ULL: goto x86_l_1272;
	case 4728ULL: goto x86_l_1278;
	case 4731ULL: goto x86_l_127b;
	case 4737ULL: goto x86_l_1281;
	case 4743ULL: goto x86_l_1287;
	case 4748ULL: goto x86_l_128c;
	case 4752ULL: goto x86_l_1290;
	case 4759ULL: goto x86_l_1297;
	case 4764ULL: goto x86_l_129c;
	case 4769ULL: goto x86_l_12a1;
	case 4774ULL: goto x86_l_12a6;
	case 4782ULL: goto x86_l_12ae;
	case 4786ULL: goto x86_l_12b2;
	case 4793ULL: goto x86_l_12b9;
	case 4798ULL: goto x86_l_12be;
	case 4800ULL: goto x86_l_12c0;
	case 4805ULL: goto x86_l_12c5;
	case 4813ULL: goto x86_l_12cd;
	case 4816ULL: goto x86_l_12d0;
	case 4824ULL: goto x86_l_12d8;
	case 4833ULL: goto x86_l_12e1;
	case 4837ULL: goto x86_l_12e5;
	case 4842ULL: goto x86_l_12ea;
	case 4847ULL: goto x86_l_12ef;
	case 4852ULL: goto x86_l_12f4;
	case 4857ULL: goto x86_l_12f9;
	case 4859ULL: goto x86_l_12fb;
	case 4864ULL: goto x86_l_1300;
	case 4866ULL: goto x86_l_1302;
	case 4869ULL: goto x86_l_1305;
	case 4875ULL: goto x86_l_130b;
	case 4878ULL: goto x86_l_130e;
	case 4884ULL: goto x86_l_1314;
	case 4890ULL: goto x86_l_131a;
	case 4895ULL: goto x86_l_131f;
	case 4899ULL: goto x86_l_1323;
	case 4906ULL: goto x86_l_132a;
	case 4911ULL: goto x86_l_132f;
	case 4916ULL: goto x86_l_1334;
	case 4923ULL: goto x86_l_133b;
	case 4926ULL: goto x86_l_133e;
	case 4933ULL: goto x86_l_1345;
	case 4938ULL: goto x86_l_134a;
	case 4943ULL: goto x86_l_134f;
	case 4945ULL: goto x86_l_1351;
	case 4949ULL: goto x86_l_1355;
	case 4951ULL: goto x86_l_1357;
	case 4953ULL: goto x86_l_1359;
	case 4959ULL: goto x86_l_135f;
	case 4962ULL: goto x86_l_1362;
	case 4968ULL: goto x86_l_1368;
	case 4974ULL: goto x86_l_136e;
	case 4979ULL: goto x86_l_1373;
	case 4983ULL: goto x86_l_1377;
	case 4990ULL: goto x86_l_137e;
	case 4995ULL: goto x86_l_1383;
	case 5000ULL: goto x86_l_1388;
	case 5005ULL: goto x86_l_138d;
	case 5013ULL: goto x86_l_1395;
	case 5017ULL: goto x86_l_1399;
	case 5024ULL: goto x86_l_13a0;
	case 5029ULL: goto x86_l_13a5;
	case 5031ULL: goto x86_l_13a7;
	case 5036ULL: goto x86_l_13ac;
	case 5044ULL: goto x86_l_13b4;
	case 5047ULL: goto x86_l_13b7;
	case 5055ULL: goto x86_l_13bf;
	case 5064ULL: goto x86_l_13c8;
	case 5068ULL: goto x86_l_13cc;
	case 5073ULL: goto x86_l_13d1;
	case 5078ULL: goto x86_l_13d6;
	case 5083ULL: goto x86_l_13db;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d2c:
	/* 0xd2c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d31:
	/* 0xd31: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d36:
	/* 0xd36: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d3b:
	/* 0xd3b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d40:
	/* 0xd40: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_d43:
	/* 0xd43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d45:
	/* 0xd45: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d49:
	/* 0xd49: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_d4d:
	/* 0xd4d: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_d51:
	/* 0xd51: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_d55:
	/* 0xd55: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d5a:
	/* 0xd5a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d5f:
	/* 0xd5f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d64:
	/* 0xd64: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d69:
	/* 0xd69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d6b:
	/* 0xd6b: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d6f:
	/* 0xd6f: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_d73:
	/* 0xd73: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d78:
	/* 0xd78: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d7d:
	/* 0xd7d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d82:
	/* 0xd82: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d87:
	/* 0xd87: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_d8a:
	/* 0xd8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d8c:
	/* 0xd8c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d91:
	/* 0xd91: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d95:
	/* 0xd95: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d9a:
	/* 0xd9a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d9f:
	/* 0xd9f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_da4:
	/* 0xda4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_da9:
	/* 0xda9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dab:
	/* 0xdab: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_db0:
	/* 0xdb0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_db5:
	/* 0xdb5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_dba:
	/* 0xdba: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_dbf:
	/* 0xdbf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_dc4:
	/* 0xdc4: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_dc7:
	/* 0xdc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dc9:
	/* 0xdc9: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dcd:
	/* 0xdcd: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_dd1:
	/* 0xdd1: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_dd5:
	/* 0xdd5: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_dd9:
	/* 0xdd9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dde:
	/* 0xdde: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_de3:
	/* 0xde3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_de8:
	/* 0xde8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ded:
	/* 0xded: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_def:
	/* 0xdef: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_df3:
	/* 0xdf3: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_df7:
	/* 0xdf7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dfc:
	/* 0xdfc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e01:
	/* 0xe01: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e06:
	/* 0xe06: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e0b:
	/* 0xe0b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_e0e:
	/* 0xe0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e10:
	/* 0xe10: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e15:
	/* 0xe15: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e1a:
	/* 0xe1a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e1f:
	/* 0xe1f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e24:
	/* 0xe24: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e29:
	/* 0xe29: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e2c:
	/* 0xe2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e2e:
	/* 0xe2e: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e32:
	/* 0xe32: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_e36:
	/* 0xe36: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_e3a:
	/* 0xe3a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_e3e:
	/* 0xe3e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e43:
	/* 0xe43: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e48:
	/* 0xe48: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e4d:
	/* 0xe4d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e52:
	/* 0xe52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e54:
	/* 0xe54: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e59:
	/* 0xe59: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_e5d:
	/* 0xe5d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e62:
	/* 0xe62: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e67:
	/* 0xe67: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e6c:
	/* 0xe6c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e71:
	/* 0xe71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e73:
	/* 0xe73: mov    r13d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e78:
	/* 0xe78: lea    r15,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e7c:
	/* 0xe7c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e81:
	/* 0xe81: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e86:
	/* 0xe86: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e8b:
	/* 0xe8b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e90:
	/* 0xe90: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e93:
	/* 0xe93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e95:
	/* 0xe95: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e9a:
	/* 0xe9a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e9f:
	/* 0xe9f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ea4:
	/* 0xea4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ea9:
	/* 0xea9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_eae:
	/* 0xeae: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_eb1:
	/* 0xeb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eb3:
	/* 0xeb3: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eb7:
	/* 0xeb7: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_ebb:
	/* 0xebb: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_ebf:
	/* 0xebf: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ec3:
	/* 0xec3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ec8:
	/* 0xec8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ecd:
	/* 0xecd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ed2:
	/* 0xed2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ed7:
	/* 0xed7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed9:
	/* 0xed9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ede:
	/* 0xede: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_ee2:
	/* 0xee2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ee7:
	/* 0xee7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_eec:
	/* 0xeec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ef1:
	/* 0xef1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ef6:
	/* 0xef6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef8:
	/* 0xef8: cmp    r13d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_efd:
	/* 0xefd: jne    f64 <syscall__execve_enter+0xf64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f64;
	}
x86_l_eff:
	/* 0xeff: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f04:
	/* 0xf04: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f09:
	/* 0xf09: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f0e:
	/* 0xf0e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f13:
	/* 0xf13: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_f16:
	/* 0xf16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f18:
	/* 0xf18: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f1d:
	/* 0xf1d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f22:
	/* 0xf22: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f27:
	/* 0xf27: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f2c:
	/* 0xf2c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f31:
	/* 0xf31: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_f34:
	/* 0xf34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f36:
	/* 0xf36: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f3a:
	/* 0xf3a: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_f3e:
	/* 0xf3e: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_f42:
	/* 0xf42: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_f46:
	/* 0xf46: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f4b:
	/* 0xf4b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f50:
	/* 0xf50: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f55:
	/* 0xf55: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f5a:
	/* 0xf5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f5c:
	/* 0xf5c: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f60:
	/* 0xf60: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f64:
	/* 0xf64: mov    DWORD PTR [r14+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f68:
	/* 0xf68: lea    r12,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_f6f:
	/* 0xf6f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f74:
	/* 0xf74: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f79:
	/* 0xf79: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f7e:
	/* 0xf7e: lea    r15,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f82:
	/* 0xf82: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f87:
	/* 0xf87: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_f8a:
	/* 0xf8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f8c:
	/* 0xf8c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f91:
	/* 0xf91: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f95:
	/* 0xf95: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f9a:
	/* 0xf9a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f9f:
	/* 0xf9f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fa4:
	/* 0xfa4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fa9:
	/* 0xfa9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fab:
	/* 0xfab: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fb0:
	/* 0xfb0: lea    rdi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_fb5:
	/* 0xfb5: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_fba:
	/* 0xfba: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fbf:
	/* 0xfbf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fc4:
	/* 0xfc4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fc9:
	/* 0xfc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fcb:
	/* 0xfcb: mov    eax,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_fcf:
	/* 0xfcf: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_fd3:
	/* 0xfd3: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_fd8:
	/* 0xfd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fda:
	/* 0xfda: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fde:
	/* 0xfde: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_fe2:
	/* 0xfe2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fe7:
	/* 0xfe7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fec:
	/* 0xfec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ff1:
	/* 0xff1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ff6:
	/* 0xff6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff8:
	/* 0xff8: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ffd:
	/* 0xffd: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1001:
	/* 0x1001: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1006:
	/* 0x1006: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_100a:
	/* 0x100a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_100f:
	/* 0x100f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1014:
	/* 0x1014: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1019:
	/* 0x1019: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_101e:
	/* 0x101e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1020:
	/* 0x1020: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1025:
	/* 0x1025: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1029:
	/* 0x1029: add    rbp,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_102d:
	/* 0x102d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1032:
	/* 0x1032: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1037:
	/* 0x1037: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_103c:
	/* 0x103c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1041:
	/* 0x1041: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1044:
	/* 0x1044: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1046:
	/* 0x1046: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_104b:
	/* 0x104b: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_104f:
	/* 0x104f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1054:
	/* 0x1054: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1059:
	/* 0x1059: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_105e:
	/* 0x105e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1063:
	/* 0x1063: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1066:
	/* 0x1066: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1068:
	/* 0x1068: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_106d:
	/* 0x106d: je     1074 <syscall__execve_enter+0x1074> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1074;
	}
x86_l_106f:
	/* 0x106f: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_1074:
	/* 0x1074: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_107c:
	/* 0x107c: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1080:
	/* 0x1080: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_1088:
	/* 0x1088: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_108d:
	/* 0x108d: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1092:
	/* 0x1092: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1097:
	/* 0x1097: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1099:
	/* 0x1099: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_109e:
	/* 0x109e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10a3:
	/* 0x10a3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10a8:
	/* 0x10a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10ad:
	/* 0x10ad: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_10b0:
	/* 0x10b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b2:
	/* 0x10b2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10b7:
	/* 0x10b7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10bc:
	/* 0x10bc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10c1:
	/* 0x10c1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10c6:
	/* 0x10c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10cb:
	/* 0x10cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10cd:
	/* 0x10cd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10d2:
	/* 0x10d2: lea    rbx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10d7:
	/* 0x10d7: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_10dc:
	/* 0x10dc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10e1:
	/* 0x10e1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10e4:
	/* 0x10e4: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_10e9:
	/* 0x10e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10eb:
	/* 0x10eb: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_10ee:
	/* 0x10ee: add    rdi,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_10f2:
	/* 0x10f2: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_10f7:
	/* 0x10f7: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_10fc:
	/* 0x10fc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1101:
	/* 0x1101: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1104:
	/* 0x1104: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1106:
	/* 0x1106: mov    ecx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 104ULL);
x86_l_110b:
	/* 0x110b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1110:
	/* 0x1110: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1115:
	/* 0x1115: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_111a:
	/* 0x111a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_111d:
	/* 0x111d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_111f:
	/* 0x111f: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1124:
	/* 0x1124: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_1128:
	/* 0x1128: mov    rbx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1130:
	/* 0x1130: je     1155 <syscall__execve_enter+0x1155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1155;
	}
x86_l_1132:
	/* 0x1132: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_1139:
	/* 0x1139: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_113e:
	/* 0x113e: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1143:
	/* 0x1143: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1148:
	/* 0x1148: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_114b:
	/* 0x114b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_114d:
	/* 0x114d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_114f:
	/* 0x114f: js     1155 <syscall__execve_enter+0x1155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1155;
	}
x86_l_1151:
	/* 0x1151: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1155:
	/* 0x1155: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_115d:
	/* 0x115d: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_1162:
	/* 0x1162: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_1167:
	/* 0x1167: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_116a:
	/* 0x116a: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_1170:
	/* 0x1170: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1174:
	/* 0x1174: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_117b:
	/* 0x117b: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_1180:
	/* 0x1180: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1185:
	/* 0x1185: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_118a:
	/* 0x118a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_118d:
	/* 0x118d: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_1190:
	/* 0x1190: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1192:
	/* 0x1192: add    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_1199:
	/* 0x1199: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_119a:
	/* 0x119a: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_119c:
	/* 0x119c: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_119e:
	/* 0x119e: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_11a0:
	/* 0x11a0: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_11a2:
	/* 0x11a2: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_11a3:
	/* 0x11a3: jmp    5736 <syscall__execve_enter+0x5736> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_11a8:
	/* 0x11a8: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_11ac:
	/* 0x11ac: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_11b3:
	/* 0x11b3: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_11b8:
	/* 0x11b8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_11bd:
	/* 0x11bd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11c2:
	/* 0x11c2: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_11c9:
	/* 0x11c9: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_11cd:
	/* 0x11cd: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_11d4:
	/* 0x11d4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_11d9:
	/* 0x11d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11db:
	/* 0x11db: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_11e0:
	/* 0x11e0: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_11e7:
	/* 0x11e7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_11ea:
	/* 0x11ea: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_11f1:
	/* 0x11f1: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_11fa:
	/* 0x11fa: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11fe:
	/* 0x11fe: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1203:
	/* 0x1203: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1208:
	/* 0x1208: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_120d:
	/* 0x120d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1212:
	/* 0x1212: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1214:
	/* 0x1214: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1219:
	/* 0x1219: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_121b:
	/* 0x121b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_121e:
	/* 0x121e: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_1224:
	/* 0x1224: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1227:
	/* 0x1227: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_122d:
	/* 0x122d: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_1233:
	/* 0x1233: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1238:
	/* 0x1238: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_123c:
	/* 0x123c: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1243:
	/* 0x1243: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1248:
	/* 0x1248: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_124d:
	/* 0x124d: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1254:
	/* 0x1254: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1257:
	/* 0x1257: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_125e:
	/* 0x125e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1263:
	/* 0x1263: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1268:
	/* 0x1268: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_126a:
	/* 0x126a: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_126e:
	/* 0x126e: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_1270:
	/* 0x1270: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1272:
	/* 0x1272: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_1278:
	/* 0x1278: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_127b:
	/* 0x127b: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1281:
	/* 0x1281: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_1287:
	/* 0x1287: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_128c:
	/* 0x128c: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1290:
	/* 0x1290: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1297:
	/* 0x1297: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_129c:
	/* 0x129c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12a1:
	/* 0x12a1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12a6:
	/* 0x12a6: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_12ae:
	/* 0x12ae: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_12b2:
	/* 0x12b2: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_12b9:
	/* 0x12b9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12be:
	/* 0x12be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12c0:
	/* 0x12c0: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_12c5:
	/* 0x12c5: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_12cd:
	/* 0x12cd: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_12d0:
	/* 0x12d0: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_12d8:
	/* 0x12d8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_12e1:
	/* 0x12e1: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12e5:
	/* 0x12e5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12ea:
	/* 0x12ea: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12ef:
	/* 0x12ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12f4:
	/* 0x12f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12f9:
	/* 0x12f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12fb:
	/* 0x12fb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1300:
	/* 0x1300: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_1302:
	/* 0x1302: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1305:
	/* 0x1305: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_130b:
	/* 0x130b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_130e:
	/* 0x130e: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1314:
	/* 0x1314: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_131a:
	/* 0x131a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_131f:
	/* 0x131f: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1323:
	/* 0x1323: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_132a:
	/* 0x132a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_132f:
	/* 0x132f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1334:
	/* 0x1334: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_133b:
	/* 0x133b: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_133e:
	/* 0x133e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1345:
	/* 0x1345: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_134a:
	/* 0x134a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_134f:
	/* 0x134f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1351:
	/* 0x1351: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1355:
	/* 0x1355: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_1357:
	/* 0x1357: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1359:
	/* 0x1359: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_135f:
	/* 0x135f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1362:
	/* 0x1362: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1368:
	/* 0x1368: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_136e:
	/* 0x136e: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1373:
	/* 0x1373: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1377:
	/* 0x1377: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_137e:
	/* 0x137e: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1383:
	/* 0x1383: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1388:
	/* 0x1388: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_138d:
	/* 0x138d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1395:
	/* 0x1395: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1399:
	/* 0x1399: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_13a0:
	/* 0x13a0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13a5:
	/* 0x13a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a7:
	/* 0x13a7: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_13ac:
	/* 0x13ac: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_13b4:
	/* 0x13b4: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_13b7:
	/* 0x13b7: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_13bf:
	/* 0x13bf: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_13c8:
	/* 0x13c8: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13cc:
	/* 0x13cc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13d1:
	/* 0x13d1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13d6:
	/* 0x13d6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13db:
	/* 0x13db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 5088ULL;
}

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5088ULL: goto x86_l_13e0;
	case 5090ULL: goto x86_l_13e2;
	case 5095ULL: goto x86_l_13e7;
	case 5097ULL: goto x86_l_13e9;
	case 5100ULL: goto x86_l_13ec;
	case 5106ULL: goto x86_l_13f2;
	case 5109ULL: goto x86_l_13f5;
	case 5115ULL: goto x86_l_13fb;
	case 5121ULL: goto x86_l_1401;
	case 5126ULL: goto x86_l_1406;
	case 5130ULL: goto x86_l_140a;
	case 5137ULL: goto x86_l_1411;
	case 5142ULL: goto x86_l_1416;
	case 5147ULL: goto x86_l_141b;
	case 5154ULL: goto x86_l_1422;
	case 5157ULL: goto x86_l_1425;
	case 5164ULL: goto x86_l_142c;
	case 5169ULL: goto x86_l_1431;
	case 5174ULL: goto x86_l_1436;
	case 5176ULL: goto x86_l_1438;
	case 5180ULL: goto x86_l_143c;
	case 5182ULL: goto x86_l_143e;
	case 5184ULL: goto x86_l_1440;
	case 5190ULL: goto x86_l_1446;
	case 5193ULL: goto x86_l_1449;
	case 5199ULL: goto x86_l_144f;
	case 5205ULL: goto x86_l_1455;
	case 5210ULL: goto x86_l_145a;
	case 5214ULL: goto x86_l_145e;
	case 5221ULL: goto x86_l_1465;
	case 5226ULL: goto x86_l_146a;
	case 5231ULL: goto x86_l_146f;
	case 5236ULL: goto x86_l_1474;
	case 5244ULL: goto x86_l_147c;
	case 5248ULL: goto x86_l_1480;
	case 5255ULL: goto x86_l_1487;
	case 5260ULL: goto x86_l_148c;
	case 5262ULL: goto x86_l_148e;
	case 5267ULL: goto x86_l_1493;
	case 5275ULL: goto x86_l_149b;
	case 5278ULL: goto x86_l_149e;
	case 5286ULL: goto x86_l_14a6;
	case 5295ULL: goto x86_l_14af;
	case 5299ULL: goto x86_l_14b3;
	case 5304ULL: goto x86_l_14b8;
	case 5309ULL: goto x86_l_14bd;
	case 5314ULL: goto x86_l_14c2;
	case 5319ULL: goto x86_l_14c7;
	case 5321ULL: goto x86_l_14c9;
	case 5326ULL: goto x86_l_14ce;
	case 5328ULL: goto x86_l_14d0;
	case 5331ULL: goto x86_l_14d3;
	case 5337ULL: goto x86_l_14d9;
	case 5340ULL: goto x86_l_14dc;
	case 5346ULL: goto x86_l_14e2;
	case 5352ULL: goto x86_l_14e8;
	case 5357ULL: goto x86_l_14ed;
	case 5361ULL: goto x86_l_14f1;
	case 5368ULL: goto x86_l_14f8;
	case 5373ULL: goto x86_l_14fd;
	case 5378ULL: goto x86_l_1502;
	case 5385ULL: goto x86_l_1509;
	case 5388ULL: goto x86_l_150c;
	case 5395ULL: goto x86_l_1513;
	case 5400ULL: goto x86_l_1518;
	case 5405ULL: goto x86_l_151d;
	case 5407ULL: goto x86_l_151f;
	case 5411ULL: goto x86_l_1523;
	case 5413ULL: goto x86_l_1525;
	case 5415ULL: goto x86_l_1527;
	case 5421ULL: goto x86_l_152d;
	case 5424ULL: goto x86_l_1530;
	case 5430ULL: goto x86_l_1536;
	case 5436ULL: goto x86_l_153c;
	case 5441ULL: goto x86_l_1541;
	case 5445ULL: goto x86_l_1545;
	case 5452ULL: goto x86_l_154c;
	case 5457ULL: goto x86_l_1551;
	case 5462ULL: goto x86_l_1556;
	case 5467ULL: goto x86_l_155b;
	case 5475ULL: goto x86_l_1563;
	case 5479ULL: goto x86_l_1567;
	case 5486ULL: goto x86_l_156e;
	case 5491ULL: goto x86_l_1573;
	case 5493ULL: goto x86_l_1575;
	case 5498ULL: goto x86_l_157a;
	case 5506ULL: goto x86_l_1582;
	case 5509ULL: goto x86_l_1585;
	case 5517ULL: goto x86_l_158d;
	case 5526ULL: goto x86_l_1596;
	case 5530ULL: goto x86_l_159a;
	case 5535ULL: goto x86_l_159f;
	case 5540ULL: goto x86_l_15a4;
	case 5545ULL: goto x86_l_15a9;
	case 5550ULL: goto x86_l_15ae;
	case 5552ULL: goto x86_l_15b0;
	case 5557ULL: goto x86_l_15b5;
	case 5559ULL: goto x86_l_15b7;
	case 5562ULL: goto x86_l_15ba;
	case 5568ULL: goto x86_l_15c0;
	case 5571ULL: goto x86_l_15c3;
	case 5577ULL: goto x86_l_15c9;
	case 5583ULL: goto x86_l_15cf;
	case 5588ULL: goto x86_l_15d4;
	case 5592ULL: goto x86_l_15d8;
	case 5599ULL: goto x86_l_15df;
	case 5604ULL: goto x86_l_15e4;
	case 5609ULL: goto x86_l_15e9;
	case 5616ULL: goto x86_l_15f0;
	case 5619ULL: goto x86_l_15f3;
	case 5626ULL: goto x86_l_15fa;
	case 5631ULL: goto x86_l_15ff;
	case 5636ULL: goto x86_l_1604;
	case 5638ULL: goto x86_l_1606;
	case 5642ULL: goto x86_l_160a;
	case 5644ULL: goto x86_l_160c;
	case 5646ULL: goto x86_l_160e;
	case 5652ULL: goto x86_l_1614;
	case 5655ULL: goto x86_l_1617;
	case 5661ULL: goto x86_l_161d;
	case 5667ULL: goto x86_l_1623;
	case 5672ULL: goto x86_l_1628;
	case 5676ULL: goto x86_l_162c;
	case 5683ULL: goto x86_l_1633;
	case 5688ULL: goto x86_l_1638;
	case 5693ULL: goto x86_l_163d;
	case 5698ULL: goto x86_l_1642;
	case 5706ULL: goto x86_l_164a;
	case 5710ULL: goto x86_l_164e;
	case 5717ULL: goto x86_l_1655;
	case 5722ULL: goto x86_l_165a;
	case 5724ULL: goto x86_l_165c;
	case 5729ULL: goto x86_l_1661;
	case 5737ULL: goto x86_l_1669;
	case 5740ULL: goto x86_l_166c;
	case 5748ULL: goto x86_l_1674;
	case 5757ULL: goto x86_l_167d;
	case 5761ULL: goto x86_l_1681;
	case 5766ULL: goto x86_l_1686;
	case 5771ULL: goto x86_l_168b;
	case 5776ULL: goto x86_l_1690;
	case 5781ULL: goto x86_l_1695;
	case 5783ULL: goto x86_l_1697;
	case 5788ULL: goto x86_l_169c;
	case 5790ULL: goto x86_l_169e;
	case 5793ULL: goto x86_l_16a1;
	case 5799ULL: goto x86_l_16a7;
	case 5802ULL: goto x86_l_16aa;
	case 5808ULL: goto x86_l_16b0;
	case 5814ULL: goto x86_l_16b6;
	case 5819ULL: goto x86_l_16bb;
	case 5823ULL: goto x86_l_16bf;
	case 5830ULL: goto x86_l_16c6;
	case 5835ULL: goto x86_l_16cb;
	case 5840ULL: goto x86_l_16d0;
	case 5847ULL: goto x86_l_16d7;
	case 5850ULL: goto x86_l_16da;
	case 5857ULL: goto x86_l_16e1;
	case 5862ULL: goto x86_l_16e6;
	case 5867ULL: goto x86_l_16eb;
	case 5869ULL: goto x86_l_16ed;
	case 5873ULL: goto x86_l_16f1;
	case 5875ULL: goto x86_l_16f3;
	case 5877ULL: goto x86_l_16f5;
	case 5883ULL: goto x86_l_16fb;
	case 5886ULL: goto x86_l_16fe;
	case 5892ULL: goto x86_l_1704;
	case 5898ULL: goto x86_l_170a;
	case 5903ULL: goto x86_l_170f;
	case 5907ULL: goto x86_l_1713;
	case 5914ULL: goto x86_l_171a;
	case 5919ULL: goto x86_l_171f;
	case 5924ULL: goto x86_l_1724;
	case 5929ULL: goto x86_l_1729;
	case 5937ULL: goto x86_l_1731;
	case 5941ULL: goto x86_l_1735;
	case 5948ULL: goto x86_l_173c;
	case 5953ULL: goto x86_l_1741;
	case 5955ULL: goto x86_l_1743;
	case 5960ULL: goto x86_l_1748;
	case 5968ULL: goto x86_l_1750;
	case 5971ULL: goto x86_l_1753;
	case 5979ULL: goto x86_l_175b;
	case 5988ULL: goto x86_l_1764;
	case 5992ULL: goto x86_l_1768;
	case 5997ULL: goto x86_l_176d;
	case 6002ULL: goto x86_l_1772;
	case 6007ULL: goto x86_l_1777;
	case 6012ULL: goto x86_l_177c;
	case 6014ULL: goto x86_l_177e;
	case 6019ULL: goto x86_l_1783;
	case 6021ULL: goto x86_l_1785;
	case 6024ULL: goto x86_l_1788;
	case 6030ULL: goto x86_l_178e;
	case 6033ULL: goto x86_l_1791;
	case 6039ULL: goto x86_l_1797;
	case 6045ULL: goto x86_l_179d;
	case 6050ULL: goto x86_l_17a2;
	case 6054ULL: goto x86_l_17a6;
	case 6061ULL: goto x86_l_17ad;
	case 6066ULL: goto x86_l_17b2;
	case 6071ULL: goto x86_l_17b7;
	case 6078ULL: goto x86_l_17be;
	case 6081ULL: goto x86_l_17c1;
	case 6088ULL: goto x86_l_17c8;
	case 6093ULL: goto x86_l_17cd;
	case 6098ULL: goto x86_l_17d2;
	case 6100ULL: goto x86_l_17d4;
	case 6104ULL: goto x86_l_17d8;
	case 6106ULL: goto x86_l_17da;
	case 6108ULL: goto x86_l_17dc;
	case 6114ULL: goto x86_l_17e2;
	case 6117ULL: goto x86_l_17e5;
	case 6123ULL: goto x86_l_17eb;
	case 6129ULL: goto x86_l_17f1;
	case 6134ULL: goto x86_l_17f6;
	case 6138ULL: goto x86_l_17fa;
	case 6145ULL: goto x86_l_1801;
	case 6150ULL: goto x86_l_1806;
	case 6155ULL: goto x86_l_180b;
	case 6160ULL: goto x86_l_1810;
	case 6168ULL: goto x86_l_1818;
	case 6172ULL: goto x86_l_181c;
	case 6179ULL: goto x86_l_1823;
	case 6184ULL: goto x86_l_1828;
	case 6186ULL: goto x86_l_182a;
	case 6191ULL: goto x86_l_182f;
	case 6199ULL: goto x86_l_1837;
	case 6202ULL: goto x86_l_183a;
	case 6210ULL: goto x86_l_1842;
	case 6219ULL: goto x86_l_184b;
	case 6223ULL: goto x86_l_184f;
	case 6228ULL: goto x86_l_1854;
	case 6233ULL: goto x86_l_1859;
	case 6238ULL: goto x86_l_185e;
	case 6243ULL: goto x86_l_1863;
	case 6245ULL: goto x86_l_1865;
	case 6250ULL: goto x86_l_186a;
	case 6252ULL: goto x86_l_186c;
	case 6255ULL: goto x86_l_186f;
	case 6261ULL: goto x86_l_1875;
	case 6264ULL: goto x86_l_1878;
	case 6270ULL: goto x86_l_187e;
	case 6276ULL: goto x86_l_1884;
	case 6281ULL: goto x86_l_1889;
	case 6285ULL: goto x86_l_188d;
	case 6292ULL: goto x86_l_1894;
	case 6297ULL: goto x86_l_1899;
	case 6302ULL: goto x86_l_189e;
	case 6309ULL: goto x86_l_18a5;
	case 6312ULL: goto x86_l_18a8;
	case 6319ULL: goto x86_l_18af;
	case 6324ULL: goto x86_l_18b4;
	case 6329ULL: goto x86_l_18b9;
	case 6331ULL: goto x86_l_18bb;
	case 6335ULL: goto x86_l_18bf;
	case 6337ULL: goto x86_l_18c1;
	case 6339ULL: goto x86_l_18c3;
	case 6345ULL: goto x86_l_18c9;
	case 6348ULL: goto x86_l_18cc;
	case 6354ULL: goto x86_l_18d2;
	case 6360ULL: goto x86_l_18d8;
	case 6365ULL: goto x86_l_18dd;
	case 6369ULL: goto x86_l_18e1;
	case 6376ULL: goto x86_l_18e8;
	case 6381ULL: goto x86_l_18ed;
	case 6386ULL: goto x86_l_18f2;
	case 6391ULL: goto x86_l_18f7;
	case 6399ULL: goto x86_l_18ff;
	case 6403ULL: goto x86_l_1903;
	case 6410ULL: goto x86_l_190a;
	case 6415ULL: goto x86_l_190f;
	case 6417ULL: goto x86_l_1911;
	case 6422ULL: goto x86_l_1916;
	case 6430ULL: goto x86_l_191e;
	case 6433ULL: goto x86_l_1921;
	case 6441ULL: goto x86_l_1929;
	case 6450ULL: goto x86_l_1932;
	case 6454ULL: goto x86_l_1936;
	case 6459ULL: goto x86_l_193b;
	case 6464ULL: goto x86_l_1940;
	case 6469ULL: goto x86_l_1945;
	case 6474ULL: goto x86_l_194a;
	case 6476ULL: goto x86_l_194c;
	case 6481ULL: goto x86_l_1951;
	case 6483ULL: goto x86_l_1953;
	case 6486ULL: goto x86_l_1956;
	case 6492ULL: goto x86_l_195c;
	case 6495ULL: goto x86_l_195f;
	case 6501ULL: goto x86_l_1965;
	case 6507ULL: goto x86_l_196b;
	case 6512ULL: goto x86_l_1970;
	case 6516ULL: goto x86_l_1974;
	case 6523ULL: goto x86_l_197b;
	case 6528ULL: goto x86_l_1980;
	case 6533ULL: goto x86_l_1985;
	case 6540ULL: goto x86_l_198c;
	case 6543ULL: goto x86_l_198f;
	case 6550ULL: goto x86_l_1996;
	case 6555ULL: goto x86_l_199b;
	case 6560ULL: goto x86_l_19a0;
	case 6562ULL: goto x86_l_19a2;
	case 6566ULL: goto x86_l_19a6;
	case 6568ULL: goto x86_l_19a8;
	case 6570ULL: goto x86_l_19aa;
	case 6576ULL: goto x86_l_19b0;
	case 6579ULL: goto x86_l_19b3;
	case 6585ULL: goto x86_l_19b9;
	case 6591ULL: goto x86_l_19bf;
	case 6596ULL: goto x86_l_19c4;
	case 6600ULL: goto x86_l_19c8;
	case 6607ULL: goto x86_l_19cf;
	case 6612ULL: goto x86_l_19d4;
	case 6617ULL: goto x86_l_19d9;
	case 6622ULL: goto x86_l_19de;
	case 6630ULL: goto x86_l_19e6;
	case 6634ULL: goto x86_l_19ea;
	case 6641ULL: goto x86_l_19f1;
	case 6646ULL: goto x86_l_19f6;
	case 6648ULL: goto x86_l_19f8;
	case 6653ULL: goto x86_l_19fd;
	case 6661ULL: goto x86_l_1a05;
	case 6664ULL: goto x86_l_1a08;
	case 6672ULL: goto x86_l_1a10;
	case 6681ULL: goto x86_l_1a19;
	case 6685ULL: goto x86_l_1a1d;
	case 6690ULL: goto x86_l_1a22;
	case 6695ULL: goto x86_l_1a27;
	case 6700ULL: goto x86_l_1a2c;
	case 6705ULL: goto x86_l_1a31;
	case 6707ULL: goto x86_l_1a33;
	case 6712ULL: goto x86_l_1a38;
	case 6714ULL: goto x86_l_1a3a;
	case 6717ULL: goto x86_l_1a3d;
	case 6723ULL: goto x86_l_1a43;
	case 6726ULL: goto x86_l_1a46;
	case 6732ULL: goto x86_l_1a4c;
	case 6738ULL: goto x86_l_1a52;
	case 6743ULL: goto x86_l_1a57;
	case 6747ULL: goto x86_l_1a5b;
	case 6754ULL: goto x86_l_1a62;
	case 6759ULL: goto x86_l_1a67;
	case 6764ULL: goto x86_l_1a6c;
	case 6771ULL: goto x86_l_1a73;
	case 6774ULL: goto x86_l_1a76;
	case 6781ULL: goto x86_l_1a7d;
	case 6786ULL: goto x86_l_1a82;
	case 6791ULL: goto x86_l_1a87;
	case 6793ULL: goto x86_l_1a89;
	case 6797ULL: goto x86_l_1a8d;
	case 6799ULL: goto x86_l_1a8f;
	case 6801ULL: goto x86_l_1a91;
	case 6807ULL: goto x86_l_1a97;
	case 6810ULL: goto x86_l_1a9a;
	case 6816ULL: goto x86_l_1aa0;
	case 6822ULL: goto x86_l_1aa6;
	case 6827ULL: goto x86_l_1aab;
	case 6831ULL: goto x86_l_1aaf;
	case 6838ULL: goto x86_l_1ab6;
	case 6843ULL: goto x86_l_1abb;
	case 6848ULL: goto x86_l_1ac0;
	case 6853ULL: goto x86_l_1ac5;
	case 6861ULL: goto x86_l_1acd;
	case 6865ULL: goto x86_l_1ad1;
	case 6872ULL: goto x86_l_1ad8;
	case 6877ULL: goto x86_l_1add;
	case 6879ULL: goto x86_l_1adf;
	case 6884ULL: goto x86_l_1ae4;
	case 6892ULL: goto x86_l_1aec;
	case 6895ULL: goto x86_l_1aef;
	case 6903ULL: goto x86_l_1af7;
	case 6912ULL: goto x86_l_1b00;
	case 6916ULL: goto x86_l_1b04;
	case 6921ULL: goto x86_l_1b09;
	case 6926ULL: goto x86_l_1b0e;
	case 6931ULL: goto x86_l_1b13;
	case 6936ULL: goto x86_l_1b18;
	case 6938ULL: goto x86_l_1b1a;
	case 6943ULL: goto x86_l_1b1f;
	case 6945ULL: goto x86_l_1b21;
	case 6948ULL: goto x86_l_1b24;
	case 6954ULL: goto x86_l_1b2a;
	case 6957ULL: goto x86_l_1b2d;
	case 6963ULL: goto x86_l_1b33;
	default: return 0xffffffffffffffffULL;
	}
x86_l_13e0:
	/* 0x13e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e2:
	/* 0x13e2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13e7:
	/* 0x13e7: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_13e9:
	/* 0x13e9: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_13ec:
	/* 0x13ec: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_13f2:
	/* 0x13f2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_13f5:
	/* 0x13f5: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_13fb:
	/* 0x13fb: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_1401:
	/* 0x1401: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1406:
	/* 0x1406: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_140a:
	/* 0x140a: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1411:
	/* 0x1411: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1416:
	/* 0x1416: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_141b:
	/* 0x141b: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1422:
	/* 0x1422: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1425:
	/* 0x1425: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_142c:
	/* 0x142c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1431:
	/* 0x1431: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1436:
	/* 0x1436: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1438:
	/* 0x1438: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_143c:
	/* 0x143c: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_143e:
	/* 0x143e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1440:
	/* 0x1440: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_1446:
	/* 0x1446: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1449:
	/* 0x1449: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_144f:
	/* 0x144f: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_1455:
	/* 0x1455: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_145a:
	/* 0x145a: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_145e:
	/* 0x145e: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1465:
	/* 0x1465: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_146a:
	/* 0x146a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_146f:
	/* 0x146f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1474:
	/* 0x1474: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_147c:
	/* 0x147c: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1480:
	/* 0x1480: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1487:
	/* 0x1487: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_148c:
	/* 0x148c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_148e:
	/* 0x148e: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1493:
	/* 0x1493: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_149b:
	/* 0x149b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_149e:
	/* 0x149e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_14a6:
	/* 0x14a6: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_14af:
	/* 0x14af: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14b3:
	/* 0x14b3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14b8:
	/* 0x14b8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14bd:
	/* 0x14bd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14c2:
	/* 0x14c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14c7:
	/* 0x14c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c9:
	/* 0x14c9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14ce:
	/* 0x14ce: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_14d0:
	/* 0x14d0: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_14d3:
	/* 0x14d3: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_14d9:
	/* 0x14d9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_14dc:
	/* 0x14dc: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_14e2:
	/* 0x14e2: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_14e8:
	/* 0x14e8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14ed:
	/* 0x14ed: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_14f1:
	/* 0x14f1: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_14f8:
	/* 0x14f8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_14fd:
	/* 0x14fd: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1502:
	/* 0x1502: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1509:
	/* 0x1509: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_150c:
	/* 0x150c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1513:
	/* 0x1513: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1518:
	/* 0x1518: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_151d:
	/* 0x151d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_151f:
	/* 0x151f: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1523:
	/* 0x1523: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_1525:
	/* 0x1525: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1527:
	/* 0x1527: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_152d:
	/* 0x152d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1530:
	/* 0x1530: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1536:
	/* 0x1536: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_153c:
	/* 0x153c: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1541:
	/* 0x1541: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1545:
	/* 0x1545: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_154c:
	/* 0x154c: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1551:
	/* 0x1551: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1556:
	/* 0x1556: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_155b:
	/* 0x155b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1563:
	/* 0x1563: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1567:
	/* 0x1567: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_156e:
	/* 0x156e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1573:
	/* 0x1573: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1575:
	/* 0x1575: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_157a:
	/* 0x157a: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1582:
	/* 0x1582: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1585:
	/* 0x1585: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_158d:
	/* 0x158d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1596:
	/* 0x1596: lea    rdx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_159a:
	/* 0x159a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_159f:
	/* 0x159f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_15a4:
	/* 0x15a4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15a9:
	/* 0x15a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15ae:
	/* 0x15ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15b0:
	/* 0x15b0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15b5:
	/* 0x15b5: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_15b7:
	/* 0x15b7: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_15ba:
	/* 0x15ba: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_15c0:
	/* 0x15c0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15c3:
	/* 0x15c3: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_15c9:
	/* 0x15c9: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_15cf:
	/* 0x15cf: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15d4:
	/* 0x15d4: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_15d8:
	/* 0x15d8: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_15df:
	/* 0x15df: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_15e4:
	/* 0x15e4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_15e9:
	/* 0x15e9: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_15f0:
	/* 0x15f0: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_15f3:
	/* 0x15f3: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_15fa:
	/* 0x15fa: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15ff:
	/* 0x15ff: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1604:
	/* 0x1604: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1606:
	/* 0x1606: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_160a:
	/* 0x160a: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_160c:
	/* 0x160c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_160e:
	/* 0x160e: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_1614:
	/* 0x1614: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1617:
	/* 0x1617: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_161d:
	/* 0x161d: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_1623:
	/* 0x1623: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1628:
	/* 0x1628: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_162c:
	/* 0x162c: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1633:
	/* 0x1633: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1638:
	/* 0x1638: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_163d:
	/* 0x163d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1642:
	/* 0x1642: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_164a:
	/* 0x164a: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_164e:
	/* 0x164e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1655:
	/* 0x1655: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_165a:
	/* 0x165a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_165c:
	/* 0x165c: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1661:
	/* 0x1661: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1669:
	/* 0x1669: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_166c:
	/* 0x166c: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1674:
	/* 0x1674: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_167d:
	/* 0x167d: lea    rdx,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1681:
	/* 0x1681: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1686:
	/* 0x1686: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_168b:
	/* 0x168b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1690:
	/* 0x1690: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1695:
	/* 0x1695: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1697:
	/* 0x1697: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_169c:
	/* 0x169c: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_169e:
	/* 0x169e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_16a1:
	/* 0x16a1: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_16a7:
	/* 0x16a7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_16aa:
	/* 0x16aa: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_16b0:
	/* 0x16b0: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_16b6:
	/* 0x16b6: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16bb:
	/* 0x16bb: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_16bf:
	/* 0x16bf: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_16c6:
	/* 0x16c6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_16cb:
	/* 0x16cb: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_16d0:
	/* 0x16d0: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_16d7:
	/* 0x16d7: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16da:
	/* 0x16da: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_16e1:
	/* 0x16e1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16e6:
	/* 0x16e6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_16eb:
	/* 0x16eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ed:
	/* 0x16ed: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16f1:
	/* 0x16f1: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_16f3:
	/* 0x16f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16f5:
	/* 0x16f5: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_16fb:
	/* 0x16fb: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_16fe:
	/* 0x16fe: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1704:
	/* 0x1704: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_170a:
	/* 0x170a: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_170f:
	/* 0x170f: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1713:
	/* 0x1713: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_171a:
	/* 0x171a: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_171f:
	/* 0x171f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1724:
	/* 0x1724: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1729:
	/* 0x1729: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1731:
	/* 0x1731: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1735:
	/* 0x1735: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_173c:
	/* 0x173c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1741:
	/* 0x1741: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1743:
	/* 0x1743: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1748:
	/* 0x1748: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1750:
	/* 0x1750: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1753:
	/* 0x1753: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_175b:
	/* 0x175b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1764:
	/* 0x1764: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1768:
	/* 0x1768: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_176d:
	/* 0x176d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1772:
	/* 0x1772: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1777:
	/* 0x1777: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_177c:
	/* 0x177c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_177e:
	/* 0x177e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1783:
	/* 0x1783: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_1785:
	/* 0x1785: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1788:
	/* 0x1788: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_178e:
	/* 0x178e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1791:
	/* 0x1791: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1797:
	/* 0x1797: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_179d:
	/* 0x179d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17a2:
	/* 0x17a2: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_17a6:
	/* 0x17a6: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_17ad:
	/* 0x17ad: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_17b2:
	/* 0x17b2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_17b7:
	/* 0x17b7: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_17be:
	/* 0x17be: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_17c1:
	/* 0x17c1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_17c8:
	/* 0x17c8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17cd:
	/* 0x17cd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_17d2:
	/* 0x17d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17d4:
	/* 0x17d4: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_17d8:
	/* 0x17d8: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_17da:
	/* 0x17da: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17dc:
	/* 0x17dc: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_17e2:
	/* 0x17e2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_17e5:
	/* 0x17e5: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_17eb:
	/* 0x17eb: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_17f1:
	/* 0x17f1: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17f6:
	/* 0x17f6: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_17fa:
	/* 0x17fa: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1801:
	/* 0x1801: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1806:
	/* 0x1806: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_180b:
	/* 0x180b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1810:
	/* 0x1810: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1818:
	/* 0x1818: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_181c:
	/* 0x181c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1823:
	/* 0x1823: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1828:
	/* 0x1828: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_182a:
	/* 0x182a: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_182f:
	/* 0x182f: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1837:
	/* 0x1837: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_183a:
	/* 0x183a: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1842:
	/* 0x1842: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_184b:
	/* 0x184b: lea    rdx,[r13+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_184f:
	/* 0x184f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1854:
	/* 0x1854: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1859:
	/* 0x1859: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_185e:
	/* 0x185e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1863:
	/* 0x1863: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1865:
	/* 0x1865: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_186a:
	/* 0x186a: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_186c:
	/* 0x186c: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_186f:
	/* 0x186f: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_1875:
	/* 0x1875: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1878:
	/* 0x1878: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_187e:
	/* 0x187e: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_1884:
	/* 0x1884: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1889:
	/* 0x1889: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_188d:
	/* 0x188d: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1894:
	/* 0x1894: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1899:
	/* 0x1899: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_189e:
	/* 0x189e: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_18a5:
	/* 0x18a5: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_18a8:
	/* 0x18a8: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_18af:
	/* 0x18af: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18b4:
	/* 0x18b4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_18b9:
	/* 0x18b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18bb:
	/* 0x18bb: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_18bf:
	/* 0x18bf: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_18c1:
	/* 0x18c1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18c3:
	/* 0x18c3: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_18c9:
	/* 0x18c9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18cc:
	/* 0x18cc: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_18d2:
	/* 0x18d2: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_18d8:
	/* 0x18d8: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18dd:
	/* 0x18dd: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_18e1:
	/* 0x18e1: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_18e8:
	/* 0x18e8: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_18ed:
	/* 0x18ed: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18f2:
	/* 0x18f2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18f7:
	/* 0x18f7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_18ff:
	/* 0x18ff: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1903:
	/* 0x1903: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_190a:
	/* 0x190a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_190f:
	/* 0x190f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1911:
	/* 0x1911: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1916:
	/* 0x1916: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_191e:
	/* 0x191e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1921:
	/* 0x1921: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1929:
	/* 0x1929: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1932:
	/* 0x1932: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1936:
	/* 0x1936: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_193b:
	/* 0x193b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1940:
	/* 0x1940: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1945:
	/* 0x1945: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_194a:
	/* 0x194a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_194c:
	/* 0x194c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1951:
	/* 0x1951: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_1953:
	/* 0x1953: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1956:
	/* 0x1956: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_195c:
	/* 0x195c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_195f:
	/* 0x195f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1965:
	/* 0x1965: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_196b:
	/* 0x196b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1970:
	/* 0x1970: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1974:
	/* 0x1974: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_197b:
	/* 0x197b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1980:
	/* 0x1980: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1985:
	/* 0x1985: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_198c:
	/* 0x198c: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_198f:
	/* 0x198f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1996:
	/* 0x1996: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_199b:
	/* 0x199b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_19a0:
	/* 0x19a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19a2:
	/* 0x19a2: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19a6:
	/* 0x19a6: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_19a8:
	/* 0x19a8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19aa:
	/* 0x19aa: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_19b0:
	/* 0x19b0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_19b3:
	/* 0x19b3: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_19b9:
	/* 0x19b9: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_19bf:
	/* 0x19bf: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19c4:
	/* 0x19c4: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_19c8:
	/* 0x19c8: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_19cf:
	/* 0x19cf: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19d4:
	/* 0x19d4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19d9:
	/* 0x19d9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19de:
	/* 0x19de: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_19e6:
	/* 0x19e6: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_19ea:
	/* 0x19ea: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_19f1:
	/* 0x19f1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19f6:
	/* 0x19f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19f8:
	/* 0x19f8: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_19fd:
	/* 0x19fd: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1a05:
	/* 0x1a05: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1a08:
	/* 0x1a08: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1a10:
	/* 0x1a10: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1a19:
	/* 0x1a19: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a1d:
	/* 0x1a1d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a22:
	/* 0x1a22: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a27:
	/* 0x1a27: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a2c:
	/* 0x1a2c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a31:
	/* 0x1a31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a33:
	/* 0x1a33: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a38:
	/* 0x1a38: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_1a3a:
	/* 0x1a3a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1a3d:
	/* 0x1a3d: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_1a43:
	/* 0x1a43: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a46:
	/* 0x1a46: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1a4c:
	/* 0x1a4c: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_1a52:
	/* 0x1a52: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a57:
	/* 0x1a57: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1a5b:
	/* 0x1a5b: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1a62:
	/* 0x1a62: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1a67:
	/* 0x1a67: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1a6c:
	/* 0x1a6c: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1a73:
	/* 0x1a73: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a76:
	/* 0x1a76: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1a7d:
	/* 0x1a7d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a82:
	/* 0x1a82: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1a87:
	/* 0x1a87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a89:
	/* 0x1a89: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a8d:
	/* 0x1a8d: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_1a8f:
	/* 0x1a8f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a91:
	/* 0x1a91: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_1a97:
	/* 0x1a97: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a9a:
	/* 0x1a9a: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1aa0:
	/* 0x1aa0: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_1aa6:
	/* 0x1aa6: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aab:
	/* 0x1aab: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1aaf:
	/* 0x1aaf: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1ab6:
	/* 0x1ab6: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1abb:
	/* 0x1abb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ac0:
	/* 0x1ac0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ac5:
	/* 0x1ac5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1acd:
	/* 0x1acd: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1ad1:
	/* 0x1ad1: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1ad8:
	/* 0x1ad8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1add:
	/* 0x1add: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1adf:
	/* 0x1adf: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1ae4:
	/* 0x1ae4: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1aec:
	/* 0x1aec: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1aef:
	/* 0x1aef: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1af7:
	/* 0x1af7: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1b00:
	/* 0x1b00: lea    rdx,[r13+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1b04:
	/* 0x1b04: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b09:
	/* 0x1b09: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b0e:
	/* 0x1b0e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b13:
	/* 0x1b13: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b18:
	/* 0x1b18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b1a:
	/* 0x1b1a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b1f:
	/* 0x1b1f: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_1b21:
	/* 0x1b21: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1b24:
	/* 0x1b24: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_1b2a:
	/* 0x1b2a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b2d:
	/* 0x1b2d: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1b33:
	/* 0x1b33: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
	return 6969ULL;
}

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6969ULL: goto x86_l_1b39;
	case 6974ULL: goto x86_l_1b3e;
	case 6978ULL: goto x86_l_1b42;
	case 6985ULL: goto x86_l_1b49;
	case 6990ULL: goto x86_l_1b4e;
	case 6995ULL: goto x86_l_1b53;
	case 7002ULL: goto x86_l_1b5a;
	case 7005ULL: goto x86_l_1b5d;
	case 7012ULL: goto x86_l_1b64;
	case 7017ULL: goto x86_l_1b69;
	case 7022ULL: goto x86_l_1b6e;
	case 7024ULL: goto x86_l_1b70;
	case 7028ULL: goto x86_l_1b74;
	case 7030ULL: goto x86_l_1b76;
	case 7032ULL: goto x86_l_1b78;
	case 7038ULL: goto x86_l_1b7e;
	case 7041ULL: goto x86_l_1b81;
	case 7047ULL: goto x86_l_1b87;
	case 7053ULL: goto x86_l_1b8d;
	case 7058ULL: goto x86_l_1b92;
	case 7062ULL: goto x86_l_1b96;
	case 7069ULL: goto x86_l_1b9d;
	case 7074ULL: goto x86_l_1ba2;
	case 7079ULL: goto x86_l_1ba7;
	case 7084ULL: goto x86_l_1bac;
	case 7092ULL: goto x86_l_1bb4;
	case 7096ULL: goto x86_l_1bb8;
	case 7103ULL: goto x86_l_1bbf;
	case 7108ULL: goto x86_l_1bc4;
	case 7110ULL: goto x86_l_1bc6;
	case 7115ULL: goto x86_l_1bcb;
	case 7123ULL: goto x86_l_1bd3;
	case 7126ULL: goto x86_l_1bd6;
	case 7134ULL: goto x86_l_1bde;
	case 7143ULL: goto x86_l_1be7;
	case 7147ULL: goto x86_l_1beb;
	case 7152ULL: goto x86_l_1bf0;
	case 7157ULL: goto x86_l_1bf5;
	case 7162ULL: goto x86_l_1bfa;
	case 7167ULL: goto x86_l_1bff;
	case 7169ULL: goto x86_l_1c01;
	case 7174ULL: goto x86_l_1c06;
	case 7176ULL: goto x86_l_1c08;
	case 7179ULL: goto x86_l_1c0b;
	case 7185ULL: goto x86_l_1c11;
	case 7188ULL: goto x86_l_1c14;
	case 7194ULL: goto x86_l_1c1a;
	case 7200ULL: goto x86_l_1c20;
	case 7205ULL: goto x86_l_1c25;
	case 7209ULL: goto x86_l_1c29;
	case 7216ULL: goto x86_l_1c30;
	case 7221ULL: goto x86_l_1c35;
	case 7226ULL: goto x86_l_1c3a;
	case 7233ULL: goto x86_l_1c41;
	case 7236ULL: goto x86_l_1c44;
	case 7243ULL: goto x86_l_1c4b;
	case 7248ULL: goto x86_l_1c50;
	case 7253ULL: goto x86_l_1c55;
	case 7255ULL: goto x86_l_1c57;
	case 7259ULL: goto x86_l_1c5b;
	case 7261ULL: goto x86_l_1c5d;
	case 7263ULL: goto x86_l_1c5f;
	case 7269ULL: goto x86_l_1c65;
	case 7272ULL: goto x86_l_1c68;
	case 7278ULL: goto x86_l_1c6e;
	case 7284ULL: goto x86_l_1c74;
	case 7289ULL: goto x86_l_1c79;
	case 7293ULL: goto x86_l_1c7d;
	case 7300ULL: goto x86_l_1c84;
	case 7305ULL: goto x86_l_1c89;
	case 7310ULL: goto x86_l_1c8e;
	case 7315ULL: goto x86_l_1c93;
	case 7323ULL: goto x86_l_1c9b;
	case 7327ULL: goto x86_l_1c9f;
	case 7334ULL: goto x86_l_1ca6;
	case 7339ULL: goto x86_l_1cab;
	case 7341ULL: goto x86_l_1cad;
	case 7346ULL: goto x86_l_1cb2;
	case 7354ULL: goto x86_l_1cba;
	case 7357ULL: goto x86_l_1cbd;
	case 7365ULL: goto x86_l_1cc5;
	case 7374ULL: goto x86_l_1cce;
	case 7378ULL: goto x86_l_1cd2;
	case 7383ULL: goto x86_l_1cd7;
	case 7388ULL: goto x86_l_1cdc;
	case 7393ULL: goto x86_l_1ce1;
	case 7398ULL: goto x86_l_1ce6;
	case 7400ULL: goto x86_l_1ce8;
	case 7405ULL: goto x86_l_1ced;
	case 7407ULL: goto x86_l_1cef;
	case 7410ULL: goto x86_l_1cf2;
	case 7416ULL: goto x86_l_1cf8;
	case 7419ULL: goto x86_l_1cfb;
	case 7425ULL: goto x86_l_1d01;
	case 7431ULL: goto x86_l_1d07;
	case 7436ULL: goto x86_l_1d0c;
	case 7440ULL: goto x86_l_1d10;
	case 7447ULL: goto x86_l_1d17;
	case 7452ULL: goto x86_l_1d1c;
	case 7457ULL: goto x86_l_1d21;
	case 7464ULL: goto x86_l_1d28;
	case 7467ULL: goto x86_l_1d2b;
	case 7474ULL: goto x86_l_1d32;
	case 7479ULL: goto x86_l_1d37;
	case 7484ULL: goto x86_l_1d3c;
	case 7486ULL: goto x86_l_1d3e;
	case 7490ULL: goto x86_l_1d42;
	case 7492ULL: goto x86_l_1d44;
	case 7494ULL: goto x86_l_1d46;
	case 7500ULL: goto x86_l_1d4c;
	case 7503ULL: goto x86_l_1d4f;
	case 7509ULL: goto x86_l_1d55;
	case 7515ULL: goto x86_l_1d5b;
	case 7520ULL: goto x86_l_1d60;
	case 7524ULL: goto x86_l_1d64;
	case 7531ULL: goto x86_l_1d6b;
	case 7536ULL: goto x86_l_1d70;
	case 7541ULL: goto x86_l_1d75;
	case 7546ULL: goto x86_l_1d7a;
	case 7554ULL: goto x86_l_1d82;
	case 7558ULL: goto x86_l_1d86;
	case 7565ULL: goto x86_l_1d8d;
	case 7570ULL: goto x86_l_1d92;
	case 7572ULL: goto x86_l_1d94;
	case 7577ULL: goto x86_l_1d99;
	case 7585ULL: goto x86_l_1da1;
	case 7588ULL: goto x86_l_1da4;
	case 7596ULL: goto x86_l_1dac;
	case 7605ULL: goto x86_l_1db5;
	case 7609ULL: goto x86_l_1db9;
	case 7614ULL: goto x86_l_1dbe;
	case 7619ULL: goto x86_l_1dc3;
	case 7624ULL: goto x86_l_1dc8;
	case 7629ULL: goto x86_l_1dcd;
	case 7631ULL: goto x86_l_1dcf;
	case 7636ULL: goto x86_l_1dd4;
	case 7638ULL: goto x86_l_1dd6;
	case 7641ULL: goto x86_l_1dd9;
	case 7647ULL: goto x86_l_1ddf;
	case 7650ULL: goto x86_l_1de2;
	case 7656ULL: goto x86_l_1de8;
	case 7662ULL: goto x86_l_1dee;
	case 7667ULL: goto x86_l_1df3;
	case 7671ULL: goto x86_l_1df7;
	case 7678ULL: goto x86_l_1dfe;
	case 7683ULL: goto x86_l_1e03;
	case 7688ULL: goto x86_l_1e08;
	case 7695ULL: goto x86_l_1e0f;
	case 7698ULL: goto x86_l_1e12;
	case 7705ULL: goto x86_l_1e19;
	case 7710ULL: goto x86_l_1e1e;
	case 7715ULL: goto x86_l_1e23;
	case 7717ULL: goto x86_l_1e25;
	case 7721ULL: goto x86_l_1e29;
	case 7723ULL: goto x86_l_1e2b;
	case 7725ULL: goto x86_l_1e2d;
	case 7731ULL: goto x86_l_1e33;
	case 7734ULL: goto x86_l_1e36;
	case 7740ULL: goto x86_l_1e3c;
	case 7746ULL: goto x86_l_1e42;
	case 7751ULL: goto x86_l_1e47;
	case 7755ULL: goto x86_l_1e4b;
	case 7762ULL: goto x86_l_1e52;
	case 7767ULL: goto x86_l_1e57;
	case 7772ULL: goto x86_l_1e5c;
	case 7777ULL: goto x86_l_1e61;
	case 7785ULL: goto x86_l_1e69;
	case 7789ULL: goto x86_l_1e6d;
	case 7796ULL: goto x86_l_1e74;
	case 7801ULL: goto x86_l_1e79;
	case 7803ULL: goto x86_l_1e7b;
	case 7808ULL: goto x86_l_1e80;
	case 7816ULL: goto x86_l_1e88;
	case 7819ULL: goto x86_l_1e8b;
	case 7827ULL: goto x86_l_1e93;
	case 7836ULL: goto x86_l_1e9c;
	case 7840ULL: goto x86_l_1ea0;
	case 7845ULL: goto x86_l_1ea5;
	case 7850ULL: goto x86_l_1eaa;
	case 7855ULL: goto x86_l_1eaf;
	case 7860ULL: goto x86_l_1eb4;
	case 7862ULL: goto x86_l_1eb6;
	case 7867ULL: goto x86_l_1ebb;
	case 7869ULL: goto x86_l_1ebd;
	case 7872ULL: goto x86_l_1ec0;
	case 7878ULL: goto x86_l_1ec6;
	case 7881ULL: goto x86_l_1ec9;
	case 7887ULL: goto x86_l_1ecf;
	case 7893ULL: goto x86_l_1ed5;
	case 7898ULL: goto x86_l_1eda;
	case 7902ULL: goto x86_l_1ede;
	case 7909ULL: goto x86_l_1ee5;
	case 7914ULL: goto x86_l_1eea;
	case 7919ULL: goto x86_l_1eef;
	case 7926ULL: goto x86_l_1ef6;
	case 7929ULL: goto x86_l_1ef9;
	case 7936ULL: goto x86_l_1f00;
	case 7941ULL: goto x86_l_1f05;
	case 7946ULL: goto x86_l_1f0a;
	case 7948ULL: goto x86_l_1f0c;
	case 7952ULL: goto x86_l_1f10;
	case 7954ULL: goto x86_l_1f12;
	case 7956ULL: goto x86_l_1f14;
	case 7962ULL: goto x86_l_1f1a;
	case 7965ULL: goto x86_l_1f1d;
	case 7971ULL: goto x86_l_1f23;
	case 7977ULL: goto x86_l_1f29;
	case 7982ULL: goto x86_l_1f2e;
	case 7986ULL: goto x86_l_1f32;
	case 7993ULL: goto x86_l_1f39;
	case 7998ULL: goto x86_l_1f3e;
	case 8003ULL: goto x86_l_1f43;
	case 8008ULL: goto x86_l_1f48;
	case 8016ULL: goto x86_l_1f50;
	case 8020ULL: goto x86_l_1f54;
	case 8027ULL: goto x86_l_1f5b;
	case 8032ULL: goto x86_l_1f60;
	case 8034ULL: goto x86_l_1f62;
	case 8039ULL: goto x86_l_1f67;
	case 8047ULL: goto x86_l_1f6f;
	case 8050ULL: goto x86_l_1f72;
	case 8058ULL: goto x86_l_1f7a;
	case 8067ULL: goto x86_l_1f83;
	case 8074ULL: goto x86_l_1f8a;
	case 8079ULL: goto x86_l_1f8f;
	case 8084ULL: goto x86_l_1f94;
	case 8089ULL: goto x86_l_1f99;
	case 8094ULL: goto x86_l_1f9e;
	case 8096ULL: goto x86_l_1fa0;
	case 8101ULL: goto x86_l_1fa5;
	case 8103ULL: goto x86_l_1fa7;
	case 8106ULL: goto x86_l_1faa;
	case 8112ULL: goto x86_l_1fb0;
	case 8115ULL: goto x86_l_1fb3;
	case 8121ULL: goto x86_l_1fb9;
	case 8127ULL: goto x86_l_1fbf;
	case 8132ULL: goto x86_l_1fc4;
	case 8136ULL: goto x86_l_1fc8;
	case 8143ULL: goto x86_l_1fcf;
	case 8148ULL: goto x86_l_1fd4;
	case 8153ULL: goto x86_l_1fd9;
	case 8160ULL: goto x86_l_1fe0;
	case 8163ULL: goto x86_l_1fe3;
	case 8170ULL: goto x86_l_1fea;
	case 8175ULL: goto x86_l_1fef;
	case 8180ULL: goto x86_l_1ff4;
	case 8182ULL: goto x86_l_1ff6;
	case 8186ULL: goto x86_l_1ffa;
	case 8188ULL: goto x86_l_1ffc;
	case 8190ULL: goto x86_l_1ffe;
	case 8196ULL: goto x86_l_2004;
	case 8199ULL: goto x86_l_2007;
	case 8205ULL: goto x86_l_200d;
	case 8211ULL: goto x86_l_2013;
	case 8216ULL: goto x86_l_2018;
	case 8220ULL: goto x86_l_201c;
	case 8227ULL: goto x86_l_2023;
	case 8232ULL: goto x86_l_2028;
	case 8237ULL: goto x86_l_202d;
	case 8242ULL: goto x86_l_2032;
	case 8250ULL: goto x86_l_203a;
	case 8254ULL: goto x86_l_203e;
	case 8261ULL: goto x86_l_2045;
	case 8266ULL: goto x86_l_204a;
	case 8268ULL: goto x86_l_204c;
	case 8273ULL: goto x86_l_2051;
	case 8281ULL: goto x86_l_2059;
	case 8284ULL: goto x86_l_205c;
	case 8292ULL: goto x86_l_2064;
	case 8301ULL: goto x86_l_206d;
	case 8308ULL: goto x86_l_2074;
	case 8313ULL: goto x86_l_2079;
	case 8318ULL: goto x86_l_207e;
	case 8323ULL: goto x86_l_2083;
	case 8328ULL: goto x86_l_2088;
	case 8330ULL: goto x86_l_208a;
	case 8335ULL: goto x86_l_208f;
	case 8337ULL: goto x86_l_2091;
	case 8340ULL: goto x86_l_2094;
	case 8346ULL: goto x86_l_209a;
	case 8349ULL: goto x86_l_209d;
	case 8355ULL: goto x86_l_20a3;
	case 8361ULL: goto x86_l_20a9;
	case 8366ULL: goto x86_l_20ae;
	case 8370ULL: goto x86_l_20b2;
	case 8377ULL: goto x86_l_20b9;
	case 8382ULL: goto x86_l_20be;
	case 8387ULL: goto x86_l_20c3;
	case 8394ULL: goto x86_l_20ca;
	case 8397ULL: goto x86_l_20cd;
	case 8404ULL: goto x86_l_20d4;
	case 8409ULL: goto x86_l_20d9;
	case 8414ULL: goto x86_l_20de;
	case 8416ULL: goto x86_l_20e0;
	case 8420ULL: goto x86_l_20e4;
	case 8422ULL: goto x86_l_20e6;
	case 8424ULL: goto x86_l_20e8;
	case 8430ULL: goto x86_l_20ee;
	case 8433ULL: goto x86_l_20f1;
	case 8439ULL: goto x86_l_20f7;
	case 8445ULL: goto x86_l_20fd;
	case 8450ULL: goto x86_l_2102;
	case 8454ULL: goto x86_l_2106;
	case 8461ULL: goto x86_l_210d;
	case 8466ULL: goto x86_l_2112;
	case 8471ULL: goto x86_l_2117;
	case 8476ULL: goto x86_l_211c;
	case 8484ULL: goto x86_l_2124;
	case 8488ULL: goto x86_l_2128;
	case 8495ULL: goto x86_l_212f;
	case 8500ULL: goto x86_l_2134;
	case 8502ULL: goto x86_l_2136;
	case 8507ULL: goto x86_l_213b;
	case 8515ULL: goto x86_l_2143;
	case 8518ULL: goto x86_l_2146;
	case 8526ULL: goto x86_l_214e;
	case 8535ULL: goto x86_l_2157;
	case 8542ULL: goto x86_l_215e;
	case 8547ULL: goto x86_l_2163;
	case 8552ULL: goto x86_l_2168;
	case 8557ULL: goto x86_l_216d;
	case 8562ULL: goto x86_l_2172;
	case 8564ULL: goto x86_l_2174;
	case 8569ULL: goto x86_l_2179;
	case 8571ULL: goto x86_l_217b;
	case 8574ULL: goto x86_l_217e;
	case 8580ULL: goto x86_l_2184;
	case 8583ULL: goto x86_l_2187;
	case 8589ULL: goto x86_l_218d;
	case 8595ULL: goto x86_l_2193;
	case 8600ULL: goto x86_l_2198;
	case 8604ULL: goto x86_l_219c;
	case 8611ULL: goto x86_l_21a3;
	case 8616ULL: goto x86_l_21a8;
	case 8621ULL: goto x86_l_21ad;
	case 8628ULL: goto x86_l_21b4;
	case 8631ULL: goto x86_l_21b7;
	case 8638ULL: goto x86_l_21be;
	case 8643ULL: goto x86_l_21c3;
	case 8648ULL: goto x86_l_21c8;
	case 8650ULL: goto x86_l_21ca;
	case 8654ULL: goto x86_l_21ce;
	case 8656ULL: goto x86_l_21d0;
	case 8658ULL: goto x86_l_21d2;
	case 8664ULL: goto x86_l_21d8;
	case 8667ULL: goto x86_l_21db;
	case 8673ULL: goto x86_l_21e1;
	case 8679ULL: goto x86_l_21e7;
	case 8684ULL: goto x86_l_21ec;
	case 8688ULL: goto x86_l_21f0;
	case 8695ULL: goto x86_l_21f7;
	case 8700ULL: goto x86_l_21fc;
	case 8705ULL: goto x86_l_2201;
	case 8710ULL: goto x86_l_2206;
	case 8718ULL: goto x86_l_220e;
	case 8722ULL: goto x86_l_2212;
	case 8729ULL: goto x86_l_2219;
	case 8734ULL: goto x86_l_221e;
	case 8736ULL: goto x86_l_2220;
	case 8741ULL: goto x86_l_2225;
	case 8749ULL: goto x86_l_222d;
	case 8752ULL: goto x86_l_2230;
	case 8760ULL: goto x86_l_2238;
	case 8769ULL: goto x86_l_2241;
	case 8776ULL: goto x86_l_2248;
	case 8781ULL: goto x86_l_224d;
	case 8786ULL: goto x86_l_2252;
	case 8791ULL: goto x86_l_2257;
	case 8796ULL: goto x86_l_225c;
	case 8798ULL: goto x86_l_225e;
	case 8803ULL: goto x86_l_2263;
	case 8805ULL: goto x86_l_2265;
	case 8808ULL: goto x86_l_2268;
	case 8814ULL: goto x86_l_226e;
	case 8817ULL: goto x86_l_2271;
	case 8823ULL: goto x86_l_2277;
	case 8829ULL: goto x86_l_227d;
	case 8834ULL: goto x86_l_2282;
	case 8838ULL: goto x86_l_2286;
	case 8845ULL: goto x86_l_228d;
	case 8850ULL: goto x86_l_2292;
	case 8855ULL: goto x86_l_2297;
	case 8862ULL: goto x86_l_229e;
	case 8865ULL: goto x86_l_22a1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b39:
	/* 0x1b39: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b3e:
	/* 0x1b3e: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1b42:
	/* 0x1b42: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1b49:
	/* 0x1b49: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1b4e:
	/* 0x1b4e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1b53:
	/* 0x1b53: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1b5a:
	/* 0x1b5a: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b5d:
	/* 0x1b5d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1b64:
	/* 0x1b64: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b69:
	/* 0x1b69: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1b6e:
	/* 0x1b6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b70:
	/* 0x1b70: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b74:
	/* 0x1b74: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_1b76:
	/* 0x1b76: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b78:
	/* 0x1b78: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_1b7e:
	/* 0x1b7e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b81:
	/* 0x1b81: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1b87:
	/* 0x1b87: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_1b8d:
	/* 0x1b8d: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b92:
	/* 0x1b92: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1b96:
	/* 0x1b96: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1b9d:
	/* 0x1b9d: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ba2:
	/* 0x1ba2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ba7:
	/* 0x1ba7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bac:
	/* 0x1bac: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1bb4:
	/* 0x1bb4: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1bb8:
	/* 0x1bb8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1bbf:
	/* 0x1bbf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bc4:
	/* 0x1bc4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bc6:
	/* 0x1bc6: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1bcb:
	/* 0x1bcb: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1bd3:
	/* 0x1bd3: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1bd6:
	/* 0x1bd6: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1bde:
	/* 0x1bde: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1be7:
	/* 0x1be7: lea    rdx,[r13+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1beb:
	/* 0x1beb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bf0:
	/* 0x1bf0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1bf5:
	/* 0x1bf5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bfa:
	/* 0x1bfa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bff:
	/* 0x1bff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c01:
	/* 0x1c01: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c06:
	/* 0x1c06: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_1c08:
	/* 0x1c08: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1c0b:
	/* 0x1c0b: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_1c11:
	/* 0x1c11: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1c14:
	/* 0x1c14: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1c1a:
	/* 0x1c1a: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_1c20:
	/* 0x1c20: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c25:
	/* 0x1c25: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1c29:
	/* 0x1c29: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1c30:
	/* 0x1c30: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1c35:
	/* 0x1c35: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1c3a:
	/* 0x1c3a: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c41:
	/* 0x1c41: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c44:
	/* 0x1c44: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1c4b:
	/* 0x1c4b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c50:
	/* 0x1c50: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1c55:
	/* 0x1c55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c57:
	/* 0x1c57: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c5b:
	/* 0x1c5b: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_1c5d:
	/* 0x1c5d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c5f:
	/* 0x1c5f: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_1c65:
	/* 0x1c65: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1c68:
	/* 0x1c68: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1c6e:
	/* 0x1c6e: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_1c74:
	/* 0x1c74: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c79:
	/* 0x1c79: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1c7d:
	/* 0x1c7d: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1c84:
	/* 0x1c84: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c89:
	/* 0x1c89: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c8e:
	/* 0x1c8e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c93:
	/* 0x1c93: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c9b:
	/* 0x1c9b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1c9f:
	/* 0x1c9f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1ca6:
	/* 0x1ca6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cab:
	/* 0x1cab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cad:
	/* 0x1cad: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1cb2:
	/* 0x1cb2: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1cba:
	/* 0x1cba: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1cbd:
	/* 0x1cbd: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1cc5:
	/* 0x1cc5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1cce:
	/* 0x1cce: lea    rdx,[r13+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1cd2:
	/* 0x1cd2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cd7:
	/* 0x1cd7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1cdc:
	/* 0x1cdc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ce1:
	/* 0x1ce1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ce6:
	/* 0x1ce6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ce8:
	/* 0x1ce8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ced:
	/* 0x1ced: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_1cef:
	/* 0x1cef: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1cf2:
	/* 0x1cf2: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_1cf8:
	/* 0x1cf8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1cfb:
	/* 0x1cfb: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1d01:
	/* 0x1d01: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_1d07:
	/* 0x1d07: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d0c:
	/* 0x1d0c: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1d10:
	/* 0x1d10: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1d17:
	/* 0x1d17: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1d1c:
	/* 0x1d1c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1d21:
	/* 0x1d21: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1d28:
	/* 0x1d28: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1d2b:
	/* 0x1d2b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1d32:
	/* 0x1d32: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d37:
	/* 0x1d37: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1d3c:
	/* 0x1d3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d3e:
	/* 0x1d3e: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d42:
	/* 0x1d42: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_1d44:
	/* 0x1d44: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d46:
	/* 0x1d46: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_1d4c:
	/* 0x1d4c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d4f:
	/* 0x1d4f: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1d55:
	/* 0x1d55: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_1d5b:
	/* 0x1d5b: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d60:
	/* 0x1d60: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1d64:
	/* 0x1d64: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1d6b:
	/* 0x1d6b: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d70:
	/* 0x1d70: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d75:
	/* 0x1d75: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d7a:
	/* 0x1d7a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1d82:
	/* 0x1d82: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1d86:
	/* 0x1d86: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1d8d:
	/* 0x1d8d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d92:
	/* 0x1d92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d94:
	/* 0x1d94: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1d99:
	/* 0x1d99: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1da1:
	/* 0x1da1: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1da4:
	/* 0x1da4: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1dac:
	/* 0x1dac: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1db5:
	/* 0x1db5: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1db9:
	/* 0x1db9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dbe:
	/* 0x1dbe: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1dc3:
	/* 0x1dc3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dc8:
	/* 0x1dc8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dcd:
	/* 0x1dcd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dcf:
	/* 0x1dcf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dd4:
	/* 0x1dd4: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_1dd6:
	/* 0x1dd6: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1dd9:
	/* 0x1dd9: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_1ddf:
	/* 0x1ddf: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1de2:
	/* 0x1de2: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1de8:
	/* 0x1de8: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_1dee:
	/* 0x1dee: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1df3:
	/* 0x1df3: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1df7:
	/* 0x1df7: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1dfe:
	/* 0x1dfe: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1e03:
	/* 0x1e03: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1e08:
	/* 0x1e08: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e0f:
	/* 0x1e0f: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1e12:
	/* 0x1e12: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1e19:
	/* 0x1e19: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e1e:
	/* 0x1e1e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1e23:
	/* 0x1e23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e25:
	/* 0x1e25: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e29:
	/* 0x1e29: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_1e2b:
	/* 0x1e2b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e2d:
	/* 0x1e2d: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_1e33:
	/* 0x1e33: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e36:
	/* 0x1e36: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1e3c:
	/* 0x1e3c: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_1e42:
	/* 0x1e42: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e47:
	/* 0x1e47: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1e4b:
	/* 0x1e4b: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1e52:
	/* 0x1e52: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e57:
	/* 0x1e57: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e5c:
	/* 0x1e5c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e61:
	/* 0x1e61: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e69:
	/* 0x1e69: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1e6d:
	/* 0x1e6d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1e74:
	/* 0x1e74: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e79:
	/* 0x1e79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e7b:
	/* 0x1e7b: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1e80:
	/* 0x1e80: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1e88:
	/* 0x1e88: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1e8b:
	/* 0x1e8b: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1e93:
	/* 0x1e93: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1e9c:
	/* 0x1e9c: lea    rdx,[r13+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1ea0:
	/* 0x1ea0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ea5:
	/* 0x1ea5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1eaa:
	/* 0x1eaa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1eaf:
	/* 0x1eaf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1eb4:
	/* 0x1eb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eb6:
	/* 0x1eb6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ebb:
	/* 0x1ebb: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_1ebd:
	/* 0x1ebd: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1ec0:
	/* 0x1ec0: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_1ec6:
	/* 0x1ec6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ec9:
	/* 0x1ec9: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1ecf:
	/* 0x1ecf: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_1ed5:
	/* 0x1ed5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1eda:
	/* 0x1eda: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1ede:
	/* 0x1ede: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1ee5:
	/* 0x1ee5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1eea:
	/* 0x1eea: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1eef:
	/* 0x1eef: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1ef6:
	/* 0x1ef6: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ef9:
	/* 0x1ef9: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1f00:
	/* 0x1f00: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f05:
	/* 0x1f05: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1f0a:
	/* 0x1f0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f0c:
	/* 0x1f0c: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f10:
	/* 0x1f10: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_1f12:
	/* 0x1f12: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f14:
	/* 0x1f14: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_1f1a:
	/* 0x1f1a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f1d:
	/* 0x1f1d: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1f23:
	/* 0x1f23: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_1f29:
	/* 0x1f29: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f2e:
	/* 0x1f2e: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1f32:
	/* 0x1f32: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1f39:
	/* 0x1f39: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f3e:
	/* 0x1f3e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f43:
	/* 0x1f43: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f48:
	/* 0x1f48: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f50:
	/* 0x1f50: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1f54:
	/* 0x1f54: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1f5b:
	/* 0x1f5b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f60:
	/* 0x1f60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f62:
	/* 0x1f62: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1f67:
	/* 0x1f67: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1f6f:
	/* 0x1f6f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1f72:
	/* 0x1f72: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1f7a:
	/* 0x1f7a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1f83:
	/* 0x1f83: lea    rdx,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1f8a:
	/* 0x1f8a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f8f:
	/* 0x1f8f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f94:
	/* 0x1f94: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f99:
	/* 0x1f99: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f9e:
	/* 0x1f9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fa0:
	/* 0x1fa0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fa5:
	/* 0x1fa5: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_1fa7:
	/* 0x1fa7: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1faa:
	/* 0x1faa: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_1fb0:
	/* 0x1fb0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1fb3:
	/* 0x1fb3: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1fb9:
	/* 0x1fb9: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_1fbf:
	/* 0x1fbf: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fc4:
	/* 0x1fc4: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1fc8:
	/* 0x1fc8: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1fcf:
	/* 0x1fcf: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1fd4:
	/* 0x1fd4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1fd9:
	/* 0x1fd9: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1fe0:
	/* 0x1fe0: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1fe3:
	/* 0x1fe3: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1fea:
	/* 0x1fea: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fef:
	/* 0x1fef: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1ff4:
	/* 0x1ff4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ff6:
	/* 0x1ff6: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ffa:
	/* 0x1ffa: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_1ffc:
	/* 0x1ffc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ffe:
	/* 0x1ffe: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_2004:
	/* 0x2004: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2007:
	/* 0x2007: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_200d:
	/* 0x200d: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_2013:
	/* 0x2013: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2018:
	/* 0x2018: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_201c:
	/* 0x201c: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2023:
	/* 0x2023: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2028:
	/* 0x2028: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_202d:
	/* 0x202d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2032:
	/* 0x2032: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_203a:
	/* 0x203a: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_203e:
	/* 0x203e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2045:
	/* 0x2045: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_204a:
	/* 0x204a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_204c:
	/* 0x204c: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2051:
	/* 0x2051: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2059:
	/* 0x2059: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_205c:
	/* 0x205c: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2064:
	/* 0x2064: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_206d:
	/* 0x206d: lea    rdx,[r13+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2074:
	/* 0x2074: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2079:
	/* 0x2079: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_207e:
	/* 0x207e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2083:
	/* 0x2083: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2088:
	/* 0x2088: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_208a:
	/* 0x208a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_208f:
	/* 0x208f: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_2091:
	/* 0x2091: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2094:
	/* 0x2094: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_209a:
	/* 0x209a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_209d:
	/* 0x209d: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_20a3:
	/* 0x20a3: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_20a9:
	/* 0x20a9: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20ae:
	/* 0x20ae: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_20b2:
	/* 0x20b2: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_20b9:
	/* 0x20b9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_20be:
	/* 0x20be: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_20c3:
	/* 0x20c3: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_20ca:
	/* 0x20ca: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_20cd:
	/* 0x20cd: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_20d4:
	/* 0x20d4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20d9:
	/* 0x20d9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_20de:
	/* 0x20de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20e0:
	/* 0x20e0: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_20e4:
	/* 0x20e4: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_20e6:
	/* 0x20e6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20e8:
	/* 0x20e8: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_20ee:
	/* 0x20ee: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_20f1:
	/* 0x20f1: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_20f7:
	/* 0x20f7: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_20fd:
	/* 0x20fd: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2102:
	/* 0x2102: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2106:
	/* 0x2106: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_210d:
	/* 0x210d: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2112:
	/* 0x2112: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2117:
	/* 0x2117: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_211c:
	/* 0x211c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2124:
	/* 0x2124: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2128:
	/* 0x2128: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_212f:
	/* 0x212f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2134:
	/* 0x2134: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2136:
	/* 0x2136: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_213b:
	/* 0x213b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2143:
	/* 0x2143: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2146:
	/* 0x2146: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_214e:
	/* 0x214e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2157:
	/* 0x2157: lea    rdx,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_215e:
	/* 0x215e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2163:
	/* 0x2163: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2168:
	/* 0x2168: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_216d:
	/* 0x216d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2172:
	/* 0x2172: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2174:
	/* 0x2174: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2179:
	/* 0x2179: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_217b:
	/* 0x217b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_217e:
	/* 0x217e: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_2184:
	/* 0x2184: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2187:
	/* 0x2187: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_218d:
	/* 0x218d: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_2193:
	/* 0x2193: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2198:
	/* 0x2198: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_219c:
	/* 0x219c: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_21a3:
	/* 0x21a3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_21a8:
	/* 0x21a8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_21ad:
	/* 0x21ad: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_21b4:
	/* 0x21b4: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_21b7:
	/* 0x21b7: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_21be:
	/* 0x21be: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21c3:
	/* 0x21c3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_21c8:
	/* 0x21c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21ca:
	/* 0x21ca: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_21ce:
	/* 0x21ce: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_21d0:
	/* 0x21d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21d2:
	/* 0x21d2: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_21d8:
	/* 0x21d8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_21db:
	/* 0x21db: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_21e1:
	/* 0x21e1: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_21e7:
	/* 0x21e7: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21ec:
	/* 0x21ec: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_21f0:
	/* 0x21f0: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_21f7:
	/* 0x21f7: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_21fc:
	/* 0x21fc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2201:
	/* 0x2201: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2206:
	/* 0x2206: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_220e:
	/* 0x220e: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2212:
	/* 0x2212: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2219:
	/* 0x2219: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_221e:
	/* 0x221e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2220:
	/* 0x2220: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2225:
	/* 0x2225: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_222d:
	/* 0x222d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2230:
	/* 0x2230: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2238:
	/* 0x2238: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2241:
	/* 0x2241: lea    rdx,[r13+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2248:
	/* 0x2248: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_224d:
	/* 0x224d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2252:
	/* 0x2252: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2257:
	/* 0x2257: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_225c:
	/* 0x225c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_225e:
	/* 0x225e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2263:
	/* 0x2263: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_2265:
	/* 0x2265: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2268:
	/* 0x2268: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_226e:
	/* 0x226e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2271:
	/* 0x2271: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2277:
	/* 0x2277: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_227d:
	/* 0x227d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2282:
	/* 0x2282: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2286:
	/* 0x2286: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_228d:
	/* 0x228d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2292:
	/* 0x2292: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2297:
	/* 0x2297: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_229e:
	/* 0x229e: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_22a1:
	/* 0x22a1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
	return 8872ULL;
}

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8872ULL: goto x86_l_22a8;
	case 8877ULL: goto x86_l_22ad;
	case 8882ULL: goto x86_l_22b2;
	case 8884ULL: goto x86_l_22b4;
	case 8888ULL: goto x86_l_22b8;
	case 8890ULL: goto x86_l_22ba;
	case 8892ULL: goto x86_l_22bc;
	case 8898ULL: goto x86_l_22c2;
	case 8901ULL: goto x86_l_22c5;
	case 8907ULL: goto x86_l_22cb;
	case 8913ULL: goto x86_l_22d1;
	case 8918ULL: goto x86_l_22d6;
	case 8922ULL: goto x86_l_22da;
	case 8929ULL: goto x86_l_22e1;
	case 8934ULL: goto x86_l_22e6;
	case 8939ULL: goto x86_l_22eb;
	case 8944ULL: goto x86_l_22f0;
	case 8952ULL: goto x86_l_22f8;
	case 8956ULL: goto x86_l_22fc;
	case 8963ULL: goto x86_l_2303;
	case 8968ULL: goto x86_l_2308;
	case 8970ULL: goto x86_l_230a;
	case 8975ULL: goto x86_l_230f;
	case 8983ULL: goto x86_l_2317;
	case 8986ULL: goto x86_l_231a;
	case 8994ULL: goto x86_l_2322;
	case 9003ULL: goto x86_l_232b;
	case 9010ULL: goto x86_l_2332;
	case 9015ULL: goto x86_l_2337;
	case 9020ULL: goto x86_l_233c;
	case 9025ULL: goto x86_l_2341;
	case 9030ULL: goto x86_l_2346;
	case 9032ULL: goto x86_l_2348;
	case 9037ULL: goto x86_l_234d;
	case 9039ULL: goto x86_l_234f;
	case 9042ULL: goto x86_l_2352;
	case 9048ULL: goto x86_l_2358;
	case 9051ULL: goto x86_l_235b;
	case 9057ULL: goto x86_l_2361;
	case 9063ULL: goto x86_l_2367;
	case 9068ULL: goto x86_l_236c;
	case 9072ULL: goto x86_l_2370;
	case 9079ULL: goto x86_l_2377;
	case 9084ULL: goto x86_l_237c;
	case 9089ULL: goto x86_l_2381;
	case 9096ULL: goto x86_l_2388;
	case 9099ULL: goto x86_l_238b;
	case 9106ULL: goto x86_l_2392;
	case 9111ULL: goto x86_l_2397;
	case 9116ULL: goto x86_l_239c;
	case 9118ULL: goto x86_l_239e;
	case 9122ULL: goto x86_l_23a2;
	case 9124ULL: goto x86_l_23a4;
	case 9126ULL: goto x86_l_23a6;
	case 9132ULL: goto x86_l_23ac;
	case 9135ULL: goto x86_l_23af;
	case 9141ULL: goto x86_l_23b5;
	case 9147ULL: goto x86_l_23bb;
	case 9152ULL: goto x86_l_23c0;
	case 9156ULL: goto x86_l_23c4;
	case 9163ULL: goto x86_l_23cb;
	case 9168ULL: goto x86_l_23d0;
	case 9173ULL: goto x86_l_23d5;
	case 9178ULL: goto x86_l_23da;
	case 9186ULL: goto x86_l_23e2;
	case 9190ULL: goto x86_l_23e6;
	case 9197ULL: goto x86_l_23ed;
	case 9202ULL: goto x86_l_23f2;
	case 9204ULL: goto x86_l_23f4;
	case 9209ULL: goto x86_l_23f9;
	case 9217ULL: goto x86_l_2401;
	case 9220ULL: goto x86_l_2404;
	case 9228ULL: goto x86_l_240c;
	case 9237ULL: goto x86_l_2415;
	case 9244ULL: goto x86_l_241c;
	case 9249ULL: goto x86_l_2421;
	case 9254ULL: goto x86_l_2426;
	case 9259ULL: goto x86_l_242b;
	case 9264ULL: goto x86_l_2430;
	case 9266ULL: goto x86_l_2432;
	case 9271ULL: goto x86_l_2437;
	case 9273ULL: goto x86_l_2439;
	case 9276ULL: goto x86_l_243c;
	case 9282ULL: goto x86_l_2442;
	case 9285ULL: goto x86_l_2445;
	case 9291ULL: goto x86_l_244b;
	case 9297ULL: goto x86_l_2451;
	case 9302ULL: goto x86_l_2456;
	case 9306ULL: goto x86_l_245a;
	case 9313ULL: goto x86_l_2461;
	case 9318ULL: goto x86_l_2466;
	case 9323ULL: goto x86_l_246b;
	case 9330ULL: goto x86_l_2472;
	case 9333ULL: goto x86_l_2475;
	case 9340ULL: goto x86_l_247c;
	case 9345ULL: goto x86_l_2481;
	case 9350ULL: goto x86_l_2486;
	case 9352ULL: goto x86_l_2488;
	case 9356ULL: goto x86_l_248c;
	case 9358ULL: goto x86_l_248e;
	case 9360ULL: goto x86_l_2490;
	case 9366ULL: goto x86_l_2496;
	case 9369ULL: goto x86_l_2499;
	case 9375ULL: goto x86_l_249f;
	case 9381ULL: goto x86_l_24a5;
	case 9386ULL: goto x86_l_24aa;
	case 9390ULL: goto x86_l_24ae;
	case 9397ULL: goto x86_l_24b5;
	case 9402ULL: goto x86_l_24ba;
	case 9407ULL: goto x86_l_24bf;
	case 9412ULL: goto x86_l_24c4;
	case 9420ULL: goto x86_l_24cc;
	case 9424ULL: goto x86_l_24d0;
	case 9431ULL: goto x86_l_24d7;
	case 9436ULL: goto x86_l_24dc;
	case 9438ULL: goto x86_l_24de;
	case 9443ULL: goto x86_l_24e3;
	case 9451ULL: goto x86_l_24eb;
	case 9454ULL: goto x86_l_24ee;
	case 9462ULL: goto x86_l_24f6;
	case 9471ULL: goto x86_l_24ff;
	case 9478ULL: goto x86_l_2506;
	case 9483ULL: goto x86_l_250b;
	case 9488ULL: goto x86_l_2510;
	case 9493ULL: goto x86_l_2515;
	case 9498ULL: goto x86_l_251a;
	case 9500ULL: goto x86_l_251c;
	case 9505ULL: goto x86_l_2521;
	case 9507ULL: goto x86_l_2523;
	case 9510ULL: goto x86_l_2526;
	case 9516ULL: goto x86_l_252c;
	case 9519ULL: goto x86_l_252f;
	case 9525ULL: goto x86_l_2535;
	case 9531ULL: goto x86_l_253b;
	case 9536ULL: goto x86_l_2540;
	case 9540ULL: goto x86_l_2544;
	case 9547ULL: goto x86_l_254b;
	case 9552ULL: goto x86_l_2550;
	case 9557ULL: goto x86_l_2555;
	case 9564ULL: goto x86_l_255c;
	case 9567ULL: goto x86_l_255f;
	case 9574ULL: goto x86_l_2566;
	case 9579ULL: goto x86_l_256b;
	case 9584ULL: goto x86_l_2570;
	case 9586ULL: goto x86_l_2572;
	case 9590ULL: goto x86_l_2576;
	case 9592ULL: goto x86_l_2578;
	case 9594ULL: goto x86_l_257a;
	case 9600ULL: goto x86_l_2580;
	case 9603ULL: goto x86_l_2583;
	case 9609ULL: goto x86_l_2589;
	case 9615ULL: goto x86_l_258f;
	case 9620ULL: goto x86_l_2594;
	case 9624ULL: goto x86_l_2598;
	case 9631ULL: goto x86_l_259f;
	case 9636ULL: goto x86_l_25a4;
	case 9641ULL: goto x86_l_25a9;
	case 9646ULL: goto x86_l_25ae;
	case 9654ULL: goto x86_l_25b6;
	case 9658ULL: goto x86_l_25ba;
	case 9665ULL: goto x86_l_25c1;
	case 9670ULL: goto x86_l_25c6;
	case 9672ULL: goto x86_l_25c8;
	case 9677ULL: goto x86_l_25cd;
	case 9685ULL: goto x86_l_25d5;
	case 9688ULL: goto x86_l_25d8;
	case 9696ULL: goto x86_l_25e0;
	case 9705ULL: goto x86_l_25e9;
	case 9712ULL: goto x86_l_25f0;
	case 9717ULL: goto x86_l_25f5;
	case 9722ULL: goto x86_l_25fa;
	case 9727ULL: goto x86_l_25ff;
	case 9732ULL: goto x86_l_2604;
	case 9734ULL: goto x86_l_2606;
	case 9739ULL: goto x86_l_260b;
	case 9741ULL: goto x86_l_260d;
	case 9744ULL: goto x86_l_2610;
	case 9750ULL: goto x86_l_2616;
	case 9753ULL: goto x86_l_2619;
	case 9759ULL: goto x86_l_261f;
	case 9765ULL: goto x86_l_2625;
	case 9770ULL: goto x86_l_262a;
	case 9774ULL: goto x86_l_262e;
	case 9781ULL: goto x86_l_2635;
	case 9786ULL: goto x86_l_263a;
	case 9791ULL: goto x86_l_263f;
	case 9798ULL: goto x86_l_2646;
	case 9801ULL: goto x86_l_2649;
	case 9808ULL: goto x86_l_2650;
	case 9813ULL: goto x86_l_2655;
	case 9818ULL: goto x86_l_265a;
	case 9820ULL: goto x86_l_265c;
	case 9824ULL: goto x86_l_2660;
	case 9826ULL: goto x86_l_2662;
	case 9828ULL: goto x86_l_2664;
	case 9834ULL: goto x86_l_266a;
	case 9837ULL: goto x86_l_266d;
	case 9843ULL: goto x86_l_2673;
	case 9849ULL: goto x86_l_2679;
	case 9854ULL: goto x86_l_267e;
	case 9858ULL: goto x86_l_2682;
	case 9865ULL: goto x86_l_2689;
	case 9870ULL: goto x86_l_268e;
	case 9875ULL: goto x86_l_2693;
	case 9880ULL: goto x86_l_2698;
	case 9888ULL: goto x86_l_26a0;
	case 9892ULL: goto x86_l_26a4;
	case 9899ULL: goto x86_l_26ab;
	case 9904ULL: goto x86_l_26b0;
	case 9906ULL: goto x86_l_26b2;
	case 9911ULL: goto x86_l_26b7;
	case 9919ULL: goto x86_l_26bf;
	case 9922ULL: goto x86_l_26c2;
	case 9930ULL: goto x86_l_26ca;
	case 9939ULL: goto x86_l_26d3;
	case 9946ULL: goto x86_l_26da;
	case 9951ULL: goto x86_l_26df;
	case 9956ULL: goto x86_l_26e4;
	case 9961ULL: goto x86_l_26e9;
	case 9966ULL: goto x86_l_26ee;
	case 9968ULL: goto x86_l_26f0;
	case 9973ULL: goto x86_l_26f5;
	case 9975ULL: goto x86_l_26f7;
	case 9978ULL: goto x86_l_26fa;
	case 9984ULL: goto x86_l_2700;
	case 9987ULL: goto x86_l_2703;
	case 9993ULL: goto x86_l_2709;
	case 9999ULL: goto x86_l_270f;
	case 10004ULL: goto x86_l_2714;
	case 10008ULL: goto x86_l_2718;
	case 10015ULL: goto x86_l_271f;
	case 10020ULL: goto x86_l_2724;
	case 10025ULL: goto x86_l_2729;
	case 10032ULL: goto x86_l_2730;
	case 10035ULL: goto x86_l_2733;
	case 10042ULL: goto x86_l_273a;
	case 10047ULL: goto x86_l_273f;
	case 10052ULL: goto x86_l_2744;
	case 10054ULL: goto x86_l_2746;
	case 10058ULL: goto x86_l_274a;
	case 10060ULL: goto x86_l_274c;
	case 10062ULL: goto x86_l_274e;
	case 10068ULL: goto x86_l_2754;
	case 10071ULL: goto x86_l_2757;
	case 10077ULL: goto x86_l_275d;
	case 10083ULL: goto x86_l_2763;
	case 10088ULL: goto x86_l_2768;
	case 10092ULL: goto x86_l_276c;
	case 10099ULL: goto x86_l_2773;
	case 10104ULL: goto x86_l_2778;
	case 10109ULL: goto x86_l_277d;
	case 10114ULL: goto x86_l_2782;
	case 10122ULL: goto x86_l_278a;
	case 10126ULL: goto x86_l_278e;
	case 10133ULL: goto x86_l_2795;
	case 10138ULL: goto x86_l_279a;
	case 10140ULL: goto x86_l_279c;
	case 10145ULL: goto x86_l_27a1;
	case 10153ULL: goto x86_l_27a9;
	case 10156ULL: goto x86_l_27ac;
	case 10164ULL: goto x86_l_27b4;
	case 10173ULL: goto x86_l_27bd;
	case 10180ULL: goto x86_l_27c4;
	case 10185ULL: goto x86_l_27c9;
	case 10190ULL: goto x86_l_27ce;
	case 10195ULL: goto x86_l_27d3;
	case 10200ULL: goto x86_l_27d8;
	case 10202ULL: goto x86_l_27da;
	case 10207ULL: goto x86_l_27df;
	case 10209ULL: goto x86_l_27e1;
	case 10212ULL: goto x86_l_27e4;
	case 10218ULL: goto x86_l_27ea;
	case 10221ULL: goto x86_l_27ed;
	case 10227ULL: goto x86_l_27f3;
	case 10233ULL: goto x86_l_27f9;
	case 10238ULL: goto x86_l_27fe;
	case 10242ULL: goto x86_l_2802;
	case 10249ULL: goto x86_l_2809;
	case 10254ULL: goto x86_l_280e;
	case 10259ULL: goto x86_l_2813;
	case 10266ULL: goto x86_l_281a;
	case 10269ULL: goto x86_l_281d;
	case 10276ULL: goto x86_l_2824;
	case 10281ULL: goto x86_l_2829;
	case 10286ULL: goto x86_l_282e;
	case 10288ULL: goto x86_l_2830;
	case 10292ULL: goto x86_l_2834;
	case 10294ULL: goto x86_l_2836;
	case 10296ULL: goto x86_l_2838;
	case 10302ULL: goto x86_l_283e;
	case 10305ULL: goto x86_l_2841;
	case 10311ULL: goto x86_l_2847;
	case 10317ULL: goto x86_l_284d;
	case 10322ULL: goto x86_l_2852;
	case 10326ULL: goto x86_l_2856;
	case 10333ULL: goto x86_l_285d;
	case 10338ULL: goto x86_l_2862;
	case 10343ULL: goto x86_l_2867;
	case 10348ULL: goto x86_l_286c;
	case 10356ULL: goto x86_l_2874;
	case 10360ULL: goto x86_l_2878;
	case 10367ULL: goto x86_l_287f;
	case 10372ULL: goto x86_l_2884;
	case 10374ULL: goto x86_l_2886;
	case 10379ULL: goto x86_l_288b;
	case 10387ULL: goto x86_l_2893;
	case 10390ULL: goto x86_l_2896;
	case 10398ULL: goto x86_l_289e;
	case 10407ULL: goto x86_l_28a7;
	case 10414ULL: goto x86_l_28ae;
	case 10419ULL: goto x86_l_28b3;
	case 10424ULL: goto x86_l_28b8;
	case 10429ULL: goto x86_l_28bd;
	case 10434ULL: goto x86_l_28c2;
	case 10436ULL: goto x86_l_28c4;
	case 10441ULL: goto x86_l_28c9;
	case 10443ULL: goto x86_l_28cb;
	case 10446ULL: goto x86_l_28ce;
	case 10452ULL: goto x86_l_28d4;
	case 10455ULL: goto x86_l_28d7;
	case 10461ULL: goto x86_l_28dd;
	case 10467ULL: goto x86_l_28e3;
	case 10472ULL: goto x86_l_28e8;
	case 10476ULL: goto x86_l_28ec;
	case 10483ULL: goto x86_l_28f3;
	case 10488ULL: goto x86_l_28f8;
	case 10493ULL: goto x86_l_28fd;
	case 10500ULL: goto x86_l_2904;
	case 10503ULL: goto x86_l_2907;
	case 10510ULL: goto x86_l_290e;
	case 10515ULL: goto x86_l_2913;
	case 10520ULL: goto x86_l_2918;
	case 10522ULL: goto x86_l_291a;
	case 10526ULL: goto x86_l_291e;
	case 10528ULL: goto x86_l_2920;
	case 10530ULL: goto x86_l_2922;
	case 10536ULL: goto x86_l_2928;
	case 10539ULL: goto x86_l_292b;
	case 10545ULL: goto x86_l_2931;
	case 10551ULL: goto x86_l_2937;
	case 10556ULL: goto x86_l_293c;
	case 10560ULL: goto x86_l_2940;
	case 10567ULL: goto x86_l_2947;
	case 10572ULL: goto x86_l_294c;
	case 10577ULL: goto x86_l_2951;
	case 10582ULL: goto x86_l_2956;
	case 10590ULL: goto x86_l_295e;
	case 10594ULL: goto x86_l_2962;
	case 10601ULL: goto x86_l_2969;
	case 10606ULL: goto x86_l_296e;
	case 10608ULL: goto x86_l_2970;
	case 10613ULL: goto x86_l_2975;
	case 10621ULL: goto x86_l_297d;
	case 10624ULL: goto x86_l_2980;
	case 10632ULL: goto x86_l_2988;
	case 10641ULL: goto x86_l_2991;
	case 10648ULL: goto x86_l_2998;
	case 10653ULL: goto x86_l_299d;
	case 10658ULL: goto x86_l_29a2;
	case 10663ULL: goto x86_l_29a7;
	case 10668ULL: goto x86_l_29ac;
	case 10670ULL: goto x86_l_29ae;
	case 10675ULL: goto x86_l_29b3;
	case 10677ULL: goto x86_l_29b5;
	case 10680ULL: goto x86_l_29b8;
	case 10686ULL: goto x86_l_29be;
	case 10689ULL: goto x86_l_29c1;
	case 10695ULL: goto x86_l_29c7;
	case 10701ULL: goto x86_l_29cd;
	case 10706ULL: goto x86_l_29d2;
	case 10710ULL: goto x86_l_29d6;
	case 10717ULL: goto x86_l_29dd;
	case 10722ULL: goto x86_l_29e2;
	case 10727ULL: goto x86_l_29e7;
	case 10734ULL: goto x86_l_29ee;
	case 10737ULL: goto x86_l_29f1;
	case 10744ULL: goto x86_l_29f8;
	case 10749ULL: goto x86_l_29fd;
	case 10754ULL: goto x86_l_2a02;
	case 10756ULL: goto x86_l_2a04;
	case 10760ULL: goto x86_l_2a08;
	case 10762ULL: goto x86_l_2a0a;
	case 10764ULL: goto x86_l_2a0c;
	case 10770ULL: goto x86_l_2a12;
	default: return 0xffffffffffffffffULL;
	}
x86_l_22a8:
	/* 0x22a8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22ad:
	/* 0x22ad: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_22b2:
	/* 0x22b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22b4:
	/* 0x22b4: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_22b8:
	/* 0x22b8: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_22ba:
	/* 0x22ba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22bc:
	/* 0x22bc: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_22c2:
	/* 0x22c2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_22c5:
	/* 0x22c5: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_22cb:
	/* 0x22cb: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_22d1:
	/* 0x22d1: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22d6:
	/* 0x22d6: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_22da:
	/* 0x22da: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_22e1:
	/* 0x22e1: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_22e6:
	/* 0x22e6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_22eb:
	/* 0x22eb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22f0:
	/* 0x22f0: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_22f8:
	/* 0x22f8: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_22fc:
	/* 0x22fc: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2303:
	/* 0x2303: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2308:
	/* 0x2308: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_230a:
	/* 0x230a: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_230f:
	/* 0x230f: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2317:
	/* 0x2317: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_231a:
	/* 0x231a: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2322:
	/* 0x2322: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_232b:
	/* 0x232b: lea    rdx,[r13+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2332:
	/* 0x2332: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2337:
	/* 0x2337: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_233c:
	/* 0x233c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2341:
	/* 0x2341: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2346:
	/* 0x2346: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2348:
	/* 0x2348: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_234d:
	/* 0x234d: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_234f:
	/* 0x234f: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2352:
	/* 0x2352: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_2358:
	/* 0x2358: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_235b:
	/* 0x235b: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2361:
	/* 0x2361: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_2367:
	/* 0x2367: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_236c:
	/* 0x236c: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2370:
	/* 0x2370: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2377:
	/* 0x2377: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_237c:
	/* 0x237c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2381:
	/* 0x2381: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2388:
	/* 0x2388: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_238b:
	/* 0x238b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2392:
	/* 0x2392: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2397:
	/* 0x2397: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_239c:
	/* 0x239c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_239e:
	/* 0x239e: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_23a2:
	/* 0x23a2: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_23a4:
	/* 0x23a4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23a6:
	/* 0x23a6: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_23ac:
	/* 0x23ac: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_23af:
	/* 0x23af: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_23b5:
	/* 0x23b5: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_23bb:
	/* 0x23bb: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23c0:
	/* 0x23c0: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_23c4:
	/* 0x23c4: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_23cb:
	/* 0x23cb: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_23d0:
	/* 0x23d0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_23d5:
	/* 0x23d5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23da:
	/* 0x23da: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_23e2:
	/* 0x23e2: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_23e6:
	/* 0x23e6: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_23ed:
	/* 0x23ed: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_23f2:
	/* 0x23f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23f4:
	/* 0x23f4: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_23f9:
	/* 0x23f9: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2401:
	/* 0x2401: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2404:
	/* 0x2404: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_240c:
	/* 0x240c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2415:
	/* 0x2415: lea    rdx,[r13+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_241c:
	/* 0x241c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2421:
	/* 0x2421: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2426:
	/* 0x2426: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_242b:
	/* 0x242b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2430:
	/* 0x2430: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2432:
	/* 0x2432: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2437:
	/* 0x2437: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_2439:
	/* 0x2439: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_243c:
	/* 0x243c: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_2442:
	/* 0x2442: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2445:
	/* 0x2445: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_244b:
	/* 0x244b: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_2451:
	/* 0x2451: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2456:
	/* 0x2456: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_245a:
	/* 0x245a: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2461:
	/* 0x2461: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2466:
	/* 0x2466: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_246b:
	/* 0x246b: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2472:
	/* 0x2472: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2475:
	/* 0x2475: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_247c:
	/* 0x247c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2481:
	/* 0x2481: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2486:
	/* 0x2486: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2488:
	/* 0x2488: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_248c:
	/* 0x248c: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_248e:
	/* 0x248e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2490:
	/* 0x2490: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_2496:
	/* 0x2496: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2499:
	/* 0x2499: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_249f:
	/* 0x249f: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_24a5:
	/* 0x24a5: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24aa:
	/* 0x24aa: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_24ae:
	/* 0x24ae: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_24b5:
	/* 0x24b5: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_24ba:
	/* 0x24ba: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_24bf:
	/* 0x24bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24c4:
	/* 0x24c4: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_24cc:
	/* 0x24cc: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_24d0:
	/* 0x24d0: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_24d7:
	/* 0x24d7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_24dc:
	/* 0x24dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24de:
	/* 0x24de: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_24e3:
	/* 0x24e3: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_24eb:
	/* 0x24eb: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_24ee:
	/* 0x24ee: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_24f6:
	/* 0x24f6: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_24ff:
	/* 0x24ff: lea    rdx,[r13+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2506:
	/* 0x2506: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_250b:
	/* 0x250b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2510:
	/* 0x2510: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2515:
	/* 0x2515: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_251a:
	/* 0x251a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_251c:
	/* 0x251c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2521:
	/* 0x2521: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_2523:
	/* 0x2523: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2526:
	/* 0x2526: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_252c:
	/* 0x252c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_252f:
	/* 0x252f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2535:
	/* 0x2535: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_253b:
	/* 0x253b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2540:
	/* 0x2540: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2544:
	/* 0x2544: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_254b:
	/* 0x254b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2550:
	/* 0x2550: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2555:
	/* 0x2555: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_255c:
	/* 0x255c: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_255f:
	/* 0x255f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2566:
	/* 0x2566: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_256b:
	/* 0x256b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2570:
	/* 0x2570: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2572:
	/* 0x2572: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2576:
	/* 0x2576: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_2578:
	/* 0x2578: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_257a:
	/* 0x257a: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_2580:
	/* 0x2580: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2583:
	/* 0x2583: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2589:
	/* 0x2589: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_258f:
	/* 0x258f: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2594:
	/* 0x2594: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2598:
	/* 0x2598: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_259f:
	/* 0x259f: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_25a4:
	/* 0x25a4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_25a9:
	/* 0x25a9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25ae:
	/* 0x25ae: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_25b6:
	/* 0x25b6: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_25ba:
	/* 0x25ba: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_25c1:
	/* 0x25c1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_25c6:
	/* 0x25c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25c8:
	/* 0x25c8: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_25cd:
	/* 0x25cd: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_25d5:
	/* 0x25d5: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_25d8:
	/* 0x25d8: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_25e0:
	/* 0x25e0: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_25e9:
	/* 0x25e9: lea    rdx,[r13+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_25f0:
	/* 0x25f0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25f5:
	/* 0x25f5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_25fa:
	/* 0x25fa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25ff:
	/* 0x25ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2604:
	/* 0x2604: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2606:
	/* 0x2606: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_260b:
	/* 0x260b: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_260d:
	/* 0x260d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2610:
	/* 0x2610: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_2616:
	/* 0x2616: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2619:
	/* 0x2619: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_261f:
	/* 0x261f: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_2625:
	/* 0x2625: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_262a:
	/* 0x262a: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_262e:
	/* 0x262e: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2635:
	/* 0x2635: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_263a:
	/* 0x263a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_263f:
	/* 0x263f: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2646:
	/* 0x2646: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2649:
	/* 0x2649: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2650:
	/* 0x2650: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2655:
	/* 0x2655: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_265a:
	/* 0x265a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_265c:
	/* 0x265c: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2660:
	/* 0x2660: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_2662:
	/* 0x2662: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2664:
	/* 0x2664: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_266a:
	/* 0x266a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_266d:
	/* 0x266d: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2673:
	/* 0x2673: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_2679:
	/* 0x2679: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_267e:
	/* 0x267e: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2682:
	/* 0x2682: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2689:
	/* 0x2689: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_268e:
	/* 0x268e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2693:
	/* 0x2693: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2698:
	/* 0x2698: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_26a0:
	/* 0x26a0: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_26a4:
	/* 0x26a4: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_26ab:
	/* 0x26ab: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_26b0:
	/* 0x26b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26b2:
	/* 0x26b2: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_26b7:
	/* 0x26b7: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_26bf:
	/* 0x26bf: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_26c2:
	/* 0x26c2: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_26ca:
	/* 0x26ca: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_26d3:
	/* 0x26d3: lea    rdx,[r13+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_26da:
	/* 0x26da: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26df:
	/* 0x26df: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_26e4:
	/* 0x26e4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26e9:
	/* 0x26e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26ee:
	/* 0x26ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f0:
	/* 0x26f0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26f5:
	/* 0x26f5: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_26f7:
	/* 0x26f7: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_26fa:
	/* 0x26fa: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_2700:
	/* 0x2700: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2703:
	/* 0x2703: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2709:
	/* 0x2709: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_270f:
	/* 0x270f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2714:
	/* 0x2714: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2718:
	/* 0x2718: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_271f:
	/* 0x271f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2724:
	/* 0x2724: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2729:
	/* 0x2729: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2730:
	/* 0x2730: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2733:
	/* 0x2733: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_273a:
	/* 0x273a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_273f:
	/* 0x273f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2744:
	/* 0x2744: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2746:
	/* 0x2746: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_274a:
	/* 0x274a: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_274c:
	/* 0x274c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_274e:
	/* 0x274e: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_2754:
	/* 0x2754: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2757:
	/* 0x2757: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_275d:
	/* 0x275d: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_2763:
	/* 0x2763: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2768:
	/* 0x2768: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_276c:
	/* 0x276c: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2773:
	/* 0x2773: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2778:
	/* 0x2778: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_277d:
	/* 0x277d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2782:
	/* 0x2782: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_278a:
	/* 0x278a: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_278e:
	/* 0x278e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2795:
	/* 0x2795: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_279a:
	/* 0x279a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_279c:
	/* 0x279c: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_27a1:
	/* 0x27a1: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_27a9:
	/* 0x27a9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_27ac:
	/* 0x27ac: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_27b4:
	/* 0x27b4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_27bd:
	/* 0x27bd: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_27c4:
	/* 0x27c4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27c9:
	/* 0x27c9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_27ce:
	/* 0x27ce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27d3:
	/* 0x27d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27d8:
	/* 0x27d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27da:
	/* 0x27da: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27df:
	/* 0x27df: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_27e1:
	/* 0x27e1: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_27e4:
	/* 0x27e4: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_27ea:
	/* 0x27ea: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_27ed:
	/* 0x27ed: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_27f3:
	/* 0x27f3: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_27f9:
	/* 0x27f9: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27fe:
	/* 0x27fe: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2802:
	/* 0x2802: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2809:
	/* 0x2809: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_280e:
	/* 0x280e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2813:
	/* 0x2813: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_281a:
	/* 0x281a: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_281d:
	/* 0x281d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2824:
	/* 0x2824: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2829:
	/* 0x2829: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_282e:
	/* 0x282e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2830:
	/* 0x2830: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2834:
	/* 0x2834: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_2836:
	/* 0x2836: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2838:
	/* 0x2838: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_283e:
	/* 0x283e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2841:
	/* 0x2841: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2847:
	/* 0x2847: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_284d:
	/* 0x284d: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2852:
	/* 0x2852: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2856:
	/* 0x2856: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_285d:
	/* 0x285d: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2862:
	/* 0x2862: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2867:
	/* 0x2867: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_286c:
	/* 0x286c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2874:
	/* 0x2874: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2878:
	/* 0x2878: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_287f:
	/* 0x287f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2884:
	/* 0x2884: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2886:
	/* 0x2886: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_288b:
	/* 0x288b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2893:
	/* 0x2893: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2896:
	/* 0x2896: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_289e:
	/* 0x289e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_28a7:
	/* 0x28a7: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_28ae:
	/* 0x28ae: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28b3:
	/* 0x28b3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_28b8:
	/* 0x28b8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28bd:
	/* 0x28bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28c2:
	/* 0x28c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28c4:
	/* 0x28c4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28c9:
	/* 0x28c9: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_28cb:
	/* 0x28cb: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_28ce:
	/* 0x28ce: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_28d4:
	/* 0x28d4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_28d7:
	/* 0x28d7: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_28dd:
	/* 0x28dd: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_28e3:
	/* 0x28e3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28e8:
	/* 0x28e8: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_28ec:
	/* 0x28ec: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_28f3:
	/* 0x28f3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_28f8:
	/* 0x28f8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_28fd:
	/* 0x28fd: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2904:
	/* 0x2904: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2907:
	/* 0x2907: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_290e:
	/* 0x290e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2913:
	/* 0x2913: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2918:
	/* 0x2918: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_291a:
	/* 0x291a: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_291e:
	/* 0x291e: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_2920:
	/* 0x2920: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2922:
	/* 0x2922: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_2928:
	/* 0x2928: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_292b:
	/* 0x292b: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2931:
	/* 0x2931: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_2937:
	/* 0x2937: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_293c:
	/* 0x293c: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2940:
	/* 0x2940: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2947:
	/* 0x2947: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_294c:
	/* 0x294c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2951:
	/* 0x2951: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2956:
	/* 0x2956: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_295e:
	/* 0x295e: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2962:
	/* 0x2962: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2969:
	/* 0x2969: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_296e:
	/* 0x296e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2970:
	/* 0x2970: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2975:
	/* 0x2975: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_297d:
	/* 0x297d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2980:
	/* 0x2980: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2988:
	/* 0x2988: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2991:
	/* 0x2991: lea    rdx,[r13+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2998:
	/* 0x2998: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_299d:
	/* 0x299d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_29a2:
	/* 0x29a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29a7:
	/* 0x29a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29ac:
	/* 0x29ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29ae:
	/* 0x29ae: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29b3:
	/* 0x29b3: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_29b5:
	/* 0x29b5: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_29b8:
	/* 0x29b8: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_29be:
	/* 0x29be: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_29c1:
	/* 0x29c1: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_29c7:
	/* 0x29c7: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_29cd:
	/* 0x29cd: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29d2:
	/* 0x29d2: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_29d6:
	/* 0x29d6: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_29dd:
	/* 0x29dd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_29e2:
	/* 0x29e2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_29e7:
	/* 0x29e7: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_29ee:
	/* 0x29ee: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29f1:
	/* 0x29f1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_29f8:
	/* 0x29f8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29fd:
	/* 0x29fd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2a02:
	/* 0x2a02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a04:
	/* 0x2a04: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2a08:
	/* 0x2a08: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_2a0a:
	/* 0x2a0a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a0c:
	/* 0x2a0c: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_2a12:
	/* 0x2a12: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
	return 10773ULL;
}

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10773ULL: goto x86_l_2a15;
	case 10779ULL: goto x86_l_2a1b;
	case 10785ULL: goto x86_l_2a21;
	case 10790ULL: goto x86_l_2a26;
	case 10794ULL: goto x86_l_2a2a;
	case 10801ULL: goto x86_l_2a31;
	case 10806ULL: goto x86_l_2a36;
	case 10811ULL: goto x86_l_2a3b;
	case 10816ULL: goto x86_l_2a40;
	case 10824ULL: goto x86_l_2a48;
	case 10828ULL: goto x86_l_2a4c;
	case 10835ULL: goto x86_l_2a53;
	case 10840ULL: goto x86_l_2a58;
	case 10842ULL: goto x86_l_2a5a;
	case 10847ULL: goto x86_l_2a5f;
	case 10855ULL: goto x86_l_2a67;
	case 10858ULL: goto x86_l_2a6a;
	case 10866ULL: goto x86_l_2a72;
	case 10875ULL: goto x86_l_2a7b;
	case 10882ULL: goto x86_l_2a82;
	case 10887ULL: goto x86_l_2a87;
	case 10892ULL: goto x86_l_2a8c;
	case 10897ULL: goto x86_l_2a91;
	case 10902ULL: goto x86_l_2a96;
	case 10904ULL: goto x86_l_2a98;
	case 10909ULL: goto x86_l_2a9d;
	case 10911ULL: goto x86_l_2a9f;
	case 10914ULL: goto x86_l_2aa2;
	case 10920ULL: goto x86_l_2aa8;
	case 10923ULL: goto x86_l_2aab;
	case 10929ULL: goto x86_l_2ab1;
	case 10935ULL: goto x86_l_2ab7;
	case 10940ULL: goto x86_l_2abc;
	case 10944ULL: goto x86_l_2ac0;
	case 10951ULL: goto x86_l_2ac7;
	case 10956ULL: goto x86_l_2acc;
	case 10961ULL: goto x86_l_2ad1;
	case 10968ULL: goto x86_l_2ad8;
	case 10971ULL: goto x86_l_2adb;
	case 10978ULL: goto x86_l_2ae2;
	case 10983ULL: goto x86_l_2ae7;
	case 10988ULL: goto x86_l_2aec;
	case 10990ULL: goto x86_l_2aee;
	case 10994ULL: goto x86_l_2af2;
	case 10996ULL: goto x86_l_2af4;
	case 10998ULL: goto x86_l_2af6;
	case 11004ULL: goto x86_l_2afc;
	case 11007ULL: goto x86_l_2aff;
	case 11013ULL: goto x86_l_2b05;
	case 11019ULL: goto x86_l_2b0b;
	case 11024ULL: goto x86_l_2b10;
	case 11028ULL: goto x86_l_2b14;
	case 11035ULL: goto x86_l_2b1b;
	case 11040ULL: goto x86_l_2b20;
	case 11045ULL: goto x86_l_2b25;
	case 11050ULL: goto x86_l_2b2a;
	case 11058ULL: goto x86_l_2b32;
	case 11062ULL: goto x86_l_2b36;
	case 11069ULL: goto x86_l_2b3d;
	case 11074ULL: goto x86_l_2b42;
	case 11076ULL: goto x86_l_2b44;
	case 11081ULL: goto x86_l_2b49;
	case 11089ULL: goto x86_l_2b51;
	case 11092ULL: goto x86_l_2b54;
	case 11100ULL: goto x86_l_2b5c;
	case 11109ULL: goto x86_l_2b65;
	case 11116ULL: goto x86_l_2b6c;
	case 11121ULL: goto x86_l_2b71;
	case 11126ULL: goto x86_l_2b76;
	case 11131ULL: goto x86_l_2b7b;
	case 11136ULL: goto x86_l_2b80;
	case 11138ULL: goto x86_l_2b82;
	case 11143ULL: goto x86_l_2b87;
	case 11145ULL: goto x86_l_2b89;
	case 11148ULL: goto x86_l_2b8c;
	case 11154ULL: goto x86_l_2b92;
	case 11157ULL: goto x86_l_2b95;
	case 11163ULL: goto x86_l_2b9b;
	case 11169ULL: goto x86_l_2ba1;
	case 11174ULL: goto x86_l_2ba6;
	case 11178ULL: goto x86_l_2baa;
	case 11185ULL: goto x86_l_2bb1;
	case 11190ULL: goto x86_l_2bb6;
	case 11195ULL: goto x86_l_2bbb;
	case 11202ULL: goto x86_l_2bc2;
	case 11205ULL: goto x86_l_2bc5;
	case 11212ULL: goto x86_l_2bcc;
	case 11217ULL: goto x86_l_2bd1;
	case 11222ULL: goto x86_l_2bd6;
	case 11224ULL: goto x86_l_2bd8;
	case 11228ULL: goto x86_l_2bdc;
	case 11230ULL: goto x86_l_2bde;
	case 11232ULL: goto x86_l_2be0;
	case 11238ULL: goto x86_l_2be6;
	case 11241ULL: goto x86_l_2be9;
	case 11247ULL: goto x86_l_2bef;
	case 11253ULL: goto x86_l_2bf5;
	case 11258ULL: goto x86_l_2bfa;
	case 11262ULL: goto x86_l_2bfe;
	case 11269ULL: goto x86_l_2c05;
	case 11274ULL: goto x86_l_2c0a;
	case 11279ULL: goto x86_l_2c0f;
	case 11284ULL: goto x86_l_2c14;
	case 11292ULL: goto x86_l_2c1c;
	case 11296ULL: goto x86_l_2c20;
	case 11303ULL: goto x86_l_2c27;
	case 11308ULL: goto x86_l_2c2c;
	case 11310ULL: goto x86_l_2c2e;
	case 11315ULL: goto x86_l_2c33;
	case 11323ULL: goto x86_l_2c3b;
	case 11326ULL: goto x86_l_2c3e;
	case 11334ULL: goto x86_l_2c46;
	case 11343ULL: goto x86_l_2c4f;
	case 11350ULL: goto x86_l_2c56;
	case 11355ULL: goto x86_l_2c5b;
	case 11360ULL: goto x86_l_2c60;
	case 11365ULL: goto x86_l_2c65;
	case 11370ULL: goto x86_l_2c6a;
	case 11372ULL: goto x86_l_2c6c;
	case 11377ULL: goto x86_l_2c71;
	case 11379ULL: goto x86_l_2c73;
	case 11382ULL: goto x86_l_2c76;
	case 11388ULL: goto x86_l_2c7c;
	case 11391ULL: goto x86_l_2c7f;
	case 11397ULL: goto x86_l_2c85;
	case 11403ULL: goto x86_l_2c8b;
	case 11408ULL: goto x86_l_2c90;
	case 11412ULL: goto x86_l_2c94;
	case 11419ULL: goto x86_l_2c9b;
	case 11424ULL: goto x86_l_2ca0;
	case 11429ULL: goto x86_l_2ca5;
	case 11436ULL: goto x86_l_2cac;
	case 11439ULL: goto x86_l_2caf;
	case 11446ULL: goto x86_l_2cb6;
	case 11451ULL: goto x86_l_2cbb;
	case 11456ULL: goto x86_l_2cc0;
	case 11458ULL: goto x86_l_2cc2;
	case 11462ULL: goto x86_l_2cc6;
	case 11464ULL: goto x86_l_2cc8;
	case 11466ULL: goto x86_l_2cca;
	case 11472ULL: goto x86_l_2cd0;
	case 11475ULL: goto x86_l_2cd3;
	case 11481ULL: goto x86_l_2cd9;
	case 11487ULL: goto x86_l_2cdf;
	case 11492ULL: goto x86_l_2ce4;
	case 11496ULL: goto x86_l_2ce8;
	case 11503ULL: goto x86_l_2cef;
	case 11508ULL: goto x86_l_2cf4;
	case 11513ULL: goto x86_l_2cf9;
	case 11518ULL: goto x86_l_2cfe;
	case 11526ULL: goto x86_l_2d06;
	case 11530ULL: goto x86_l_2d0a;
	case 11537ULL: goto x86_l_2d11;
	case 11542ULL: goto x86_l_2d16;
	case 11544ULL: goto x86_l_2d18;
	case 11549ULL: goto x86_l_2d1d;
	case 11557ULL: goto x86_l_2d25;
	case 11560ULL: goto x86_l_2d28;
	case 11568ULL: goto x86_l_2d30;
	case 11577ULL: goto x86_l_2d39;
	case 11584ULL: goto x86_l_2d40;
	case 11589ULL: goto x86_l_2d45;
	case 11594ULL: goto x86_l_2d4a;
	case 11599ULL: goto x86_l_2d4f;
	case 11604ULL: goto x86_l_2d54;
	case 11606ULL: goto x86_l_2d56;
	case 11611ULL: goto x86_l_2d5b;
	case 11613ULL: goto x86_l_2d5d;
	case 11616ULL: goto x86_l_2d60;
	case 11622ULL: goto x86_l_2d66;
	case 11625ULL: goto x86_l_2d69;
	case 11631ULL: goto x86_l_2d6f;
	case 11637ULL: goto x86_l_2d75;
	case 11642ULL: goto x86_l_2d7a;
	case 11646ULL: goto x86_l_2d7e;
	case 11653ULL: goto x86_l_2d85;
	case 11658ULL: goto x86_l_2d8a;
	case 11663ULL: goto x86_l_2d8f;
	case 11670ULL: goto x86_l_2d96;
	case 11673ULL: goto x86_l_2d99;
	case 11680ULL: goto x86_l_2da0;
	case 11685ULL: goto x86_l_2da5;
	case 11690ULL: goto x86_l_2daa;
	case 11692ULL: goto x86_l_2dac;
	case 11696ULL: goto x86_l_2db0;
	case 11698ULL: goto x86_l_2db2;
	case 11700ULL: goto x86_l_2db4;
	case 11706ULL: goto x86_l_2dba;
	case 11709ULL: goto x86_l_2dbd;
	case 11715ULL: goto x86_l_2dc3;
	case 11721ULL: goto x86_l_2dc9;
	case 11726ULL: goto x86_l_2dce;
	case 11730ULL: goto x86_l_2dd2;
	case 11737ULL: goto x86_l_2dd9;
	case 11742ULL: goto x86_l_2dde;
	case 11747ULL: goto x86_l_2de3;
	case 11752ULL: goto x86_l_2de8;
	case 11760ULL: goto x86_l_2df0;
	case 11764ULL: goto x86_l_2df4;
	case 11771ULL: goto x86_l_2dfb;
	case 11776ULL: goto x86_l_2e00;
	case 11778ULL: goto x86_l_2e02;
	case 11783ULL: goto x86_l_2e07;
	case 11791ULL: goto x86_l_2e0f;
	case 11794ULL: goto x86_l_2e12;
	case 11802ULL: goto x86_l_2e1a;
	case 11811ULL: goto x86_l_2e23;
	case 11818ULL: goto x86_l_2e2a;
	case 11823ULL: goto x86_l_2e2f;
	case 11828ULL: goto x86_l_2e34;
	case 11833ULL: goto x86_l_2e39;
	case 11838ULL: goto x86_l_2e3e;
	case 11840ULL: goto x86_l_2e40;
	case 11845ULL: goto x86_l_2e45;
	case 11847ULL: goto x86_l_2e47;
	case 11850ULL: goto x86_l_2e4a;
	case 11856ULL: goto x86_l_2e50;
	case 11859ULL: goto x86_l_2e53;
	case 11865ULL: goto x86_l_2e59;
	case 11871ULL: goto x86_l_2e5f;
	case 11876ULL: goto x86_l_2e64;
	case 11880ULL: goto x86_l_2e68;
	case 11887ULL: goto x86_l_2e6f;
	case 11892ULL: goto x86_l_2e74;
	case 11897ULL: goto x86_l_2e79;
	case 11904ULL: goto x86_l_2e80;
	case 11907ULL: goto x86_l_2e83;
	case 11914ULL: goto x86_l_2e8a;
	case 11919ULL: goto x86_l_2e8f;
	case 11924ULL: goto x86_l_2e94;
	case 11926ULL: goto x86_l_2e96;
	case 11930ULL: goto x86_l_2e9a;
	case 11932ULL: goto x86_l_2e9c;
	case 11934ULL: goto x86_l_2e9e;
	case 11940ULL: goto x86_l_2ea4;
	case 11943ULL: goto x86_l_2ea7;
	case 11949ULL: goto x86_l_2ead;
	case 11955ULL: goto x86_l_2eb3;
	case 11960ULL: goto x86_l_2eb8;
	case 11964ULL: goto x86_l_2ebc;
	case 11971ULL: goto x86_l_2ec3;
	case 11976ULL: goto x86_l_2ec8;
	case 11981ULL: goto x86_l_2ecd;
	case 11986ULL: goto x86_l_2ed2;
	case 11994ULL: goto x86_l_2eda;
	case 11998ULL: goto x86_l_2ede;
	case 12005ULL: goto x86_l_2ee5;
	case 12010ULL: goto x86_l_2eea;
	case 12012ULL: goto x86_l_2eec;
	case 12017ULL: goto x86_l_2ef1;
	case 12025ULL: goto x86_l_2ef9;
	case 12028ULL: goto x86_l_2efc;
	case 12036ULL: goto x86_l_2f04;
	case 12045ULL: goto x86_l_2f0d;
	case 12052ULL: goto x86_l_2f14;
	case 12057ULL: goto x86_l_2f19;
	case 12062ULL: goto x86_l_2f1e;
	case 12067ULL: goto x86_l_2f23;
	case 12072ULL: goto x86_l_2f28;
	case 12074ULL: goto x86_l_2f2a;
	case 12079ULL: goto x86_l_2f2f;
	case 12081ULL: goto x86_l_2f31;
	case 12084ULL: goto x86_l_2f34;
	case 12090ULL: goto x86_l_2f3a;
	case 12093ULL: goto x86_l_2f3d;
	case 12099ULL: goto x86_l_2f43;
	case 12105ULL: goto x86_l_2f49;
	case 12110ULL: goto x86_l_2f4e;
	case 12114ULL: goto x86_l_2f52;
	case 12121ULL: goto x86_l_2f59;
	case 12126ULL: goto x86_l_2f5e;
	case 12131ULL: goto x86_l_2f63;
	case 12138ULL: goto x86_l_2f6a;
	case 12141ULL: goto x86_l_2f6d;
	case 12148ULL: goto x86_l_2f74;
	case 12153ULL: goto x86_l_2f79;
	case 12158ULL: goto x86_l_2f7e;
	case 12160ULL: goto x86_l_2f80;
	case 12164ULL: goto x86_l_2f84;
	case 12166ULL: goto x86_l_2f86;
	case 12168ULL: goto x86_l_2f88;
	case 12174ULL: goto x86_l_2f8e;
	case 12177ULL: goto x86_l_2f91;
	case 12183ULL: goto x86_l_2f97;
	case 12189ULL: goto x86_l_2f9d;
	case 12194ULL: goto x86_l_2fa2;
	case 12198ULL: goto x86_l_2fa6;
	case 12205ULL: goto x86_l_2fad;
	case 12210ULL: goto x86_l_2fb2;
	case 12215ULL: goto x86_l_2fb7;
	case 12220ULL: goto x86_l_2fbc;
	case 12228ULL: goto x86_l_2fc4;
	case 12232ULL: goto x86_l_2fc8;
	case 12239ULL: goto x86_l_2fcf;
	case 12244ULL: goto x86_l_2fd4;
	case 12246ULL: goto x86_l_2fd6;
	case 12251ULL: goto x86_l_2fdb;
	case 12259ULL: goto x86_l_2fe3;
	case 12262ULL: goto x86_l_2fe6;
	case 12270ULL: goto x86_l_2fee;
	case 12279ULL: goto x86_l_2ff7;
	case 12286ULL: goto x86_l_2ffe;
	case 12291ULL: goto x86_l_3003;
	case 12296ULL: goto x86_l_3008;
	case 12301ULL: goto x86_l_300d;
	case 12306ULL: goto x86_l_3012;
	case 12308ULL: goto x86_l_3014;
	case 12313ULL: goto x86_l_3019;
	case 12315ULL: goto x86_l_301b;
	case 12318ULL: goto x86_l_301e;
	case 12324ULL: goto x86_l_3024;
	case 12327ULL: goto x86_l_3027;
	case 12333ULL: goto x86_l_302d;
	case 12339ULL: goto x86_l_3033;
	case 12344ULL: goto x86_l_3038;
	case 12348ULL: goto x86_l_303c;
	case 12355ULL: goto x86_l_3043;
	case 12360ULL: goto x86_l_3048;
	case 12365ULL: goto x86_l_304d;
	case 12372ULL: goto x86_l_3054;
	case 12375ULL: goto x86_l_3057;
	case 12382ULL: goto x86_l_305e;
	case 12387ULL: goto x86_l_3063;
	case 12392ULL: goto x86_l_3068;
	case 12394ULL: goto x86_l_306a;
	case 12398ULL: goto x86_l_306e;
	case 12400ULL: goto x86_l_3070;
	case 12402ULL: goto x86_l_3072;
	case 12408ULL: goto x86_l_3078;
	case 12411ULL: goto x86_l_307b;
	case 12417ULL: goto x86_l_3081;
	case 12423ULL: goto x86_l_3087;
	case 12428ULL: goto x86_l_308c;
	case 12432ULL: goto x86_l_3090;
	case 12439ULL: goto x86_l_3097;
	case 12444ULL: goto x86_l_309c;
	case 12449ULL: goto x86_l_30a1;
	case 12454ULL: goto x86_l_30a6;
	case 12462ULL: goto x86_l_30ae;
	case 12466ULL: goto x86_l_30b2;
	case 12473ULL: goto x86_l_30b9;
	case 12478ULL: goto x86_l_30be;
	case 12480ULL: goto x86_l_30c0;
	case 12485ULL: goto x86_l_30c5;
	case 12493ULL: goto x86_l_30cd;
	case 12496ULL: goto x86_l_30d0;
	case 12504ULL: goto x86_l_30d8;
	case 12513ULL: goto x86_l_30e1;
	case 12520ULL: goto x86_l_30e8;
	case 12525ULL: goto x86_l_30ed;
	case 12530ULL: goto x86_l_30f2;
	case 12535ULL: goto x86_l_30f7;
	case 12540ULL: goto x86_l_30fc;
	case 12542ULL: goto x86_l_30fe;
	case 12547ULL: goto x86_l_3103;
	case 12549ULL: goto x86_l_3105;
	case 12552ULL: goto x86_l_3108;
	case 12558ULL: goto x86_l_310e;
	case 12561ULL: goto x86_l_3111;
	case 12567ULL: goto x86_l_3117;
	case 12573ULL: goto x86_l_311d;
	case 12578ULL: goto x86_l_3122;
	case 12582ULL: goto x86_l_3126;
	case 12589ULL: goto x86_l_312d;
	case 12594ULL: goto x86_l_3132;
	case 12599ULL: goto x86_l_3137;
	case 12606ULL: goto x86_l_313e;
	case 12609ULL: goto x86_l_3141;
	case 12616ULL: goto x86_l_3148;
	case 12621ULL: goto x86_l_314d;
	case 12626ULL: goto x86_l_3152;
	case 12628ULL: goto x86_l_3154;
	case 12632ULL: goto x86_l_3158;
	case 12634ULL: goto x86_l_315a;
	case 12636ULL: goto x86_l_315c;
	case 12642ULL: goto x86_l_3162;
	case 12645ULL: goto x86_l_3165;
	case 12651ULL: goto x86_l_316b;
	case 12657ULL: goto x86_l_3171;
	case 12662ULL: goto x86_l_3176;
	case 12666ULL: goto x86_l_317a;
	case 12673ULL: goto x86_l_3181;
	case 12678ULL: goto x86_l_3186;
	case 12683ULL: goto x86_l_318b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a15:
	/* 0x2a15: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2a1b:
	/* 0x2a1b: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_2a21:
	/* 0x2a21: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a26:
	/* 0x2a26: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2a2a:
	/* 0x2a2a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2a31:
	/* 0x2a31: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2a36:
	/* 0x2a36: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a3b:
	/* 0x2a3b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a40:
	/* 0x2a40: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a48:
	/* 0x2a48: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2a4c:
	/* 0x2a4c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2a53:
	/* 0x2a53: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a58:
	/* 0x2a58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a5a:
	/* 0x2a5a: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2a5f:
	/* 0x2a5f: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2a67:
	/* 0x2a67: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2a6a:
	/* 0x2a6a: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2a72:
	/* 0x2a72: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2a7b:
	/* 0x2a7b: lea    rdx,[r13+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2a82:
	/* 0x2a82: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a87:
	/* 0x2a87: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a8c:
	/* 0x2a8c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a91:
	/* 0x2a91: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a96:
	/* 0x2a96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a98:
	/* 0x2a98: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a9d:
	/* 0x2a9d: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_2a9f:
	/* 0x2a9f: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2aa2:
	/* 0x2aa2: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_2aa8:
	/* 0x2aa8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2aab:
	/* 0x2aab: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2ab1:
	/* 0x2ab1: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_2ab7:
	/* 0x2ab7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2abc:
	/* 0x2abc: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2ac0:
	/* 0x2ac0: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2ac7:
	/* 0x2ac7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2acc:
	/* 0x2acc: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2ad1:
	/* 0x2ad1: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2ad8:
	/* 0x2ad8: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2adb:
	/* 0x2adb: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2ae2:
	/* 0x2ae2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ae7:
	/* 0x2ae7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2aec:
	/* 0x2aec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aee:
	/* 0x2aee: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2af2:
	/* 0x2af2: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_2af4:
	/* 0x2af4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2af6:
	/* 0x2af6: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_2afc:
	/* 0x2afc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2aff:
	/* 0x2aff: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2b05:
	/* 0x2b05: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_2b0b:
	/* 0x2b0b: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b10:
	/* 0x2b10: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2b14:
	/* 0x2b14: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2b1b:
	/* 0x2b1b: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2b20:
	/* 0x2b20: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b25:
	/* 0x2b25: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b2a:
	/* 0x2b2a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2b32:
	/* 0x2b32: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2b36:
	/* 0x2b36: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2b3d:
	/* 0x2b3d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b42:
	/* 0x2b42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b44:
	/* 0x2b44: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2b49:
	/* 0x2b49: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2b51:
	/* 0x2b51: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2b54:
	/* 0x2b54: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2b5c:
	/* 0x2b5c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2b65:
	/* 0x2b65: lea    rdx,[r13+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2b6c:
	/* 0x2b6c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b71:
	/* 0x2b71: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b76:
	/* 0x2b76: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b7b:
	/* 0x2b7b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b80:
	/* 0x2b80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b82:
	/* 0x2b82: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b87:
	/* 0x2b87: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_2b89:
	/* 0x2b89: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2b8c:
	/* 0x2b8c: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_2b92:
	/* 0x2b92: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b95:
	/* 0x2b95: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2b9b:
	/* 0x2b9b: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_2ba1:
	/* 0x2ba1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ba6:
	/* 0x2ba6: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2baa:
	/* 0x2baa: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2bb1:
	/* 0x2bb1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2bb6:
	/* 0x2bb6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2bbb:
	/* 0x2bbb: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2bc2:
	/* 0x2bc2: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2bc5:
	/* 0x2bc5: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2bcc:
	/* 0x2bcc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bd1:
	/* 0x2bd1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2bd6:
	/* 0x2bd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bd8:
	/* 0x2bd8: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2bdc:
	/* 0x2bdc: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_2bde:
	/* 0x2bde: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2be0:
	/* 0x2be0: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_2be6:
	/* 0x2be6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2be9:
	/* 0x2be9: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2bef:
	/* 0x2bef: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_2bf5:
	/* 0x2bf5: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bfa:
	/* 0x2bfa: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2bfe:
	/* 0x2bfe: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2c05:
	/* 0x2c05: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c0a:
	/* 0x2c0a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c0f:
	/* 0x2c0f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c14:
	/* 0x2c14: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2c1c:
	/* 0x2c1c: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2c20:
	/* 0x2c20: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2c27:
	/* 0x2c27: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c2c:
	/* 0x2c2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c2e:
	/* 0x2c2e: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2c33:
	/* 0x2c33: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2c3b:
	/* 0x2c3b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2c3e:
	/* 0x2c3e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2c46:
	/* 0x2c46: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2c4f:
	/* 0x2c4f: lea    rdx,[r13+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2c56:
	/* 0x2c56: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c5b:
	/* 0x2c5b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c60:
	/* 0x2c60: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c65:
	/* 0x2c65: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c6a:
	/* 0x2c6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c6c:
	/* 0x2c6c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c71:
	/* 0x2c71: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_2c73:
	/* 0x2c73: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2c76:
	/* 0x2c76: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_2c7c:
	/* 0x2c7c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c7f:
	/* 0x2c7f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2c85:
	/* 0x2c85: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_2c8b:
	/* 0x2c8b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c90:
	/* 0x2c90: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2c94:
	/* 0x2c94: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2c9b:
	/* 0x2c9b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2ca0:
	/* 0x2ca0: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2ca5:
	/* 0x2ca5: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2cac:
	/* 0x2cac: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2caf:
	/* 0x2caf: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2cb6:
	/* 0x2cb6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cbb:
	/* 0x2cbb: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2cc0:
	/* 0x2cc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cc2:
	/* 0x2cc2: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2cc6:
	/* 0x2cc6: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_2cc8:
	/* 0x2cc8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2cca:
	/* 0x2cca: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_2cd0:
	/* 0x2cd0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2cd3:
	/* 0x2cd3: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2cd9:
	/* 0x2cd9: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_2cdf:
	/* 0x2cdf: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ce4:
	/* 0x2ce4: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2ce8:
	/* 0x2ce8: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2cef:
	/* 0x2cef: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2cf4:
	/* 0x2cf4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2cf9:
	/* 0x2cf9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cfe:
	/* 0x2cfe: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2d06:
	/* 0x2d06: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2d0a:
	/* 0x2d0a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2d11:
	/* 0x2d11: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d16:
	/* 0x2d16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d18:
	/* 0x2d18: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2d1d:
	/* 0x2d1d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2d25:
	/* 0x2d25: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2d28:
	/* 0x2d28: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2d30:
	/* 0x2d30: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2d39:
	/* 0x2d39: lea    rdx,[r13+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2d40:
	/* 0x2d40: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d45:
	/* 0x2d45: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d4a:
	/* 0x2d4a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d4f:
	/* 0x2d4f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d54:
	/* 0x2d54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d56:
	/* 0x2d56: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d5b:
	/* 0x2d5b: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_2d5d:
	/* 0x2d5d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2d60:
	/* 0x2d60: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_2d66:
	/* 0x2d66: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d69:
	/* 0x2d69: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2d6f:
	/* 0x2d6f: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_2d75:
	/* 0x2d75: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d7a:
	/* 0x2d7a: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2d7e:
	/* 0x2d7e: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2d85:
	/* 0x2d85: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2d8a:
	/* 0x2d8a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2d8f:
	/* 0x2d8f: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2d96:
	/* 0x2d96: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d99:
	/* 0x2d99: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2da0:
	/* 0x2da0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2da5:
	/* 0x2da5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2daa:
	/* 0x2daa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dac:
	/* 0x2dac: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2db0:
	/* 0x2db0: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_2db2:
	/* 0x2db2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2db4:
	/* 0x2db4: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_2dba:
	/* 0x2dba: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2dbd:
	/* 0x2dbd: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2dc3:
	/* 0x2dc3: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_2dc9:
	/* 0x2dc9: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dce:
	/* 0x2dce: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2dd2:
	/* 0x2dd2: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2dd9:
	/* 0x2dd9: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2dde:
	/* 0x2dde: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2de3:
	/* 0x2de3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2de8:
	/* 0x2de8: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2df0:
	/* 0x2df0: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2df4:
	/* 0x2df4: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2dfb:
	/* 0x2dfb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e00:
	/* 0x2e00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e02:
	/* 0x2e02: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2e07:
	/* 0x2e07: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2e0f:
	/* 0x2e0f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2e12:
	/* 0x2e12: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2e1a:
	/* 0x2e1a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2e23:
	/* 0x2e23: lea    rdx,[r13+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2e2a:
	/* 0x2e2a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e2f:
	/* 0x2e2f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e34:
	/* 0x2e34: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e39:
	/* 0x2e39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e3e:
	/* 0x2e3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e40:
	/* 0x2e40: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e45:
	/* 0x2e45: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_2e47:
	/* 0x2e47: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2e4a:
	/* 0x2e4a: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_2e50:
	/* 0x2e50: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e53:
	/* 0x2e53: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2e59:
	/* 0x2e59: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_2e5f:
	/* 0x2e5f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e64:
	/* 0x2e64: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2e68:
	/* 0x2e68: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2e6f:
	/* 0x2e6f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2e74:
	/* 0x2e74: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2e79:
	/* 0x2e79: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2e80:
	/* 0x2e80: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e83:
	/* 0x2e83: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2e8a:
	/* 0x2e8a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e8f:
	/* 0x2e8f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2e94:
	/* 0x2e94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e96:
	/* 0x2e96: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2e9a:
	/* 0x2e9a: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_2e9c:
	/* 0x2e9c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e9e:
	/* 0x2e9e: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_2ea4:
	/* 0x2ea4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ea7:
	/* 0x2ea7: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2ead:
	/* 0x2ead: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_2eb3:
	/* 0x2eb3: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2eb8:
	/* 0x2eb8: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2ebc:
	/* 0x2ebc: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2ec3:
	/* 0x2ec3: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2ec8:
	/* 0x2ec8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ecd:
	/* 0x2ecd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ed2:
	/* 0x2ed2: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2eda:
	/* 0x2eda: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2ede:
	/* 0x2ede: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2ee5:
	/* 0x2ee5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2eea:
	/* 0x2eea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eec:
	/* 0x2eec: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2ef1:
	/* 0x2ef1: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2ef9:
	/* 0x2ef9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2efc:
	/* 0x2efc: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2f04:
	/* 0x2f04: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2f0d:
	/* 0x2f0d: lea    rdx,[r13+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2f14:
	/* 0x2f14: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f19:
	/* 0x2f19: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2f1e:
	/* 0x2f1e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f23:
	/* 0x2f23: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f28:
	/* 0x2f28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f2a:
	/* 0x2f2a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f2f:
	/* 0x2f2f: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_2f31:
	/* 0x2f31: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2f34:
	/* 0x2f34: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_2f3a:
	/* 0x2f3a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f3d:
	/* 0x2f3d: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2f43:
	/* 0x2f43: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_2f49:
	/* 0x2f49: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f4e:
	/* 0x2f4e: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2f52:
	/* 0x2f52: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2f59:
	/* 0x2f59: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2f5e:
	/* 0x2f5e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2f63:
	/* 0x2f63: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2f6a:
	/* 0x2f6a: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f6d:
	/* 0x2f6d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2f74:
	/* 0x2f74: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f79:
	/* 0x2f79: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2f7e:
	/* 0x2f7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f80:
	/* 0x2f80: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2f84:
	/* 0x2f84: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_2f86:
	/* 0x2f86: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f88:
	/* 0x2f88: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_2f8e:
	/* 0x2f8e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f91:
	/* 0x2f91: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2f97:
	/* 0x2f97: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_2f9d:
	/* 0x2f9d: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fa2:
	/* 0x2fa2: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2fa6:
	/* 0x2fa6: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2fad:
	/* 0x2fad: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2fb2:
	/* 0x2fb2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2fb7:
	/* 0x2fb7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2fbc:
	/* 0x2fbc: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2fc4:
	/* 0x2fc4: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2fc8:
	/* 0x2fc8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2fcf:
	/* 0x2fcf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2fd4:
	/* 0x2fd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fd6:
	/* 0x2fd6: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2fdb:
	/* 0x2fdb: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2fe3:
	/* 0x2fe3: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2fe6:
	/* 0x2fe6: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2fee:
	/* 0x2fee: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2ff7:
	/* 0x2ff7: lea    rdx,[r13+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_2ffe:
	/* 0x2ffe: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3003:
	/* 0x3003: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3008:
	/* 0x3008: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_300d:
	/* 0x300d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3012:
	/* 0x3012: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3014:
	/* 0x3014: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3019:
	/* 0x3019: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_301b:
	/* 0x301b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_301e:
	/* 0x301e: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_3024:
	/* 0x3024: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3027:
	/* 0x3027: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_302d:
	/* 0x302d: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_3033:
	/* 0x3033: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3038:
	/* 0x3038: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_303c:
	/* 0x303c: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3043:
	/* 0x3043: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3048:
	/* 0x3048: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_304d:
	/* 0x304d: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3054:
	/* 0x3054: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3057:
	/* 0x3057: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_305e:
	/* 0x305e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3063:
	/* 0x3063: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3068:
	/* 0x3068: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_306a:
	/* 0x306a: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_306e:
	/* 0x306e: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_3070:
	/* 0x3070: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3072:
	/* 0x3072: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_3078:
	/* 0x3078: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_307b:
	/* 0x307b: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3081:
	/* 0x3081: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_3087:
	/* 0x3087: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_308c:
	/* 0x308c: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3090:
	/* 0x3090: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3097:
	/* 0x3097: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_309c:
	/* 0x309c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_30a1:
	/* 0x30a1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30a6:
	/* 0x30a6: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_30ae:
	/* 0x30ae: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_30b2:
	/* 0x30b2: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_30b9:
	/* 0x30b9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_30be:
	/* 0x30be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30c0:
	/* 0x30c0: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_30c5:
	/* 0x30c5: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_30cd:
	/* 0x30cd: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_30d0:
	/* 0x30d0: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_30d8:
	/* 0x30d8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_30e1:
	/* 0x30e1: lea    rdx,[r13+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_30e8:
	/* 0x30e8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30ed:
	/* 0x30ed: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_30f2:
	/* 0x30f2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30f7:
	/* 0x30f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30fc:
	/* 0x30fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30fe:
	/* 0x30fe: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3103:
	/* 0x3103: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_3105:
	/* 0x3105: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3108:
	/* 0x3108: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_310e:
	/* 0x310e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3111:
	/* 0x3111: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3117:
	/* 0x3117: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_311d:
	/* 0x311d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3122:
	/* 0x3122: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3126:
	/* 0x3126: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_312d:
	/* 0x312d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3132:
	/* 0x3132: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3137:
	/* 0x3137: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_313e:
	/* 0x313e: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3141:
	/* 0x3141: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3148:
	/* 0x3148: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_314d:
	/* 0x314d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3152:
	/* 0x3152: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3154:
	/* 0x3154: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3158:
	/* 0x3158: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_315a:
	/* 0x315a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_315c:
	/* 0x315c: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_3162:
	/* 0x3162: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3165:
	/* 0x3165: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_316b:
	/* 0x316b: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_3171:
	/* 0x3171: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3176:
	/* 0x3176: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_317a:
	/* 0x317a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3181:
	/* 0x3181: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3186:
	/* 0x3186: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_318b:
	/* 0x318b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 12688ULL;
}

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12688ULL: goto x86_l_3190;
	case 12696ULL: goto x86_l_3198;
	case 12700ULL: goto x86_l_319c;
	case 12707ULL: goto x86_l_31a3;
	case 12712ULL: goto x86_l_31a8;
	case 12714ULL: goto x86_l_31aa;
	case 12719ULL: goto x86_l_31af;
	case 12727ULL: goto x86_l_31b7;
	case 12730ULL: goto x86_l_31ba;
	case 12738ULL: goto x86_l_31c2;
	case 12747ULL: goto x86_l_31cb;
	case 12754ULL: goto x86_l_31d2;
	case 12759ULL: goto x86_l_31d7;
	case 12764ULL: goto x86_l_31dc;
	case 12769ULL: goto x86_l_31e1;
	case 12774ULL: goto x86_l_31e6;
	case 12776ULL: goto x86_l_31e8;
	case 12781ULL: goto x86_l_31ed;
	case 12783ULL: goto x86_l_31ef;
	case 12786ULL: goto x86_l_31f2;
	case 12792ULL: goto x86_l_31f8;
	case 12795ULL: goto x86_l_31fb;
	case 12801ULL: goto x86_l_3201;
	case 12807ULL: goto x86_l_3207;
	case 12812ULL: goto x86_l_320c;
	case 12816ULL: goto x86_l_3210;
	case 12823ULL: goto x86_l_3217;
	case 12828ULL: goto x86_l_321c;
	case 12833ULL: goto x86_l_3221;
	case 12840ULL: goto x86_l_3228;
	case 12843ULL: goto x86_l_322b;
	case 12850ULL: goto x86_l_3232;
	case 12855ULL: goto x86_l_3237;
	case 12860ULL: goto x86_l_323c;
	case 12862ULL: goto x86_l_323e;
	case 12866ULL: goto x86_l_3242;
	case 12868ULL: goto x86_l_3244;
	case 12870ULL: goto x86_l_3246;
	case 12876ULL: goto x86_l_324c;
	case 12879ULL: goto x86_l_324f;
	case 12885ULL: goto x86_l_3255;
	case 12891ULL: goto x86_l_325b;
	case 12896ULL: goto x86_l_3260;
	case 12900ULL: goto x86_l_3264;
	case 12907ULL: goto x86_l_326b;
	case 12912ULL: goto x86_l_3270;
	case 12917ULL: goto x86_l_3275;
	case 12922ULL: goto x86_l_327a;
	case 12930ULL: goto x86_l_3282;
	case 12934ULL: goto x86_l_3286;
	case 12941ULL: goto x86_l_328d;
	case 12946ULL: goto x86_l_3292;
	case 12948ULL: goto x86_l_3294;
	case 12953ULL: goto x86_l_3299;
	case 12961ULL: goto x86_l_32a1;
	case 12964ULL: goto x86_l_32a4;
	case 12972ULL: goto x86_l_32ac;
	case 12981ULL: goto x86_l_32b5;
	case 12988ULL: goto x86_l_32bc;
	case 12993ULL: goto x86_l_32c1;
	case 12998ULL: goto x86_l_32c6;
	case 13003ULL: goto x86_l_32cb;
	case 13008ULL: goto x86_l_32d0;
	case 13011ULL: goto x86_l_32d3;
	case 13013ULL: goto x86_l_32d5;
	case 13018ULL: goto x86_l_32da;
	case 13020ULL: goto x86_l_32dc;
	case 13023ULL: goto x86_l_32df;
	case 13029ULL: goto x86_l_32e5;
	case 13032ULL: goto x86_l_32e8;
	case 13038ULL: goto x86_l_32ee;
	case 13044ULL: goto x86_l_32f4;
	case 13049ULL: goto x86_l_32f9;
	case 13053ULL: goto x86_l_32fd;
	case 13060ULL: goto x86_l_3304;
	case 13065ULL: goto x86_l_3309;
	case 13070ULL: goto x86_l_330e;
	case 13077ULL: goto x86_l_3315;
	case 13080ULL: goto x86_l_3318;
	case 13087ULL: goto x86_l_331f;
	case 13092ULL: goto x86_l_3324;
	case 13097ULL: goto x86_l_3329;
	case 13099ULL: goto x86_l_332b;
	case 13103ULL: goto x86_l_332f;
	case 13105ULL: goto x86_l_3331;
	case 13107ULL: goto x86_l_3333;
	case 13113ULL: goto x86_l_3339;
	case 13116ULL: goto x86_l_333c;
	case 13122ULL: goto x86_l_3342;
	case 13128ULL: goto x86_l_3348;
	case 13133ULL: goto x86_l_334d;
	case 13137ULL: goto x86_l_3351;
	case 13144ULL: goto x86_l_3358;
	case 13149ULL: goto x86_l_335d;
	case 13154ULL: goto x86_l_3362;
	case 13159ULL: goto x86_l_3367;
	case 13167ULL: goto x86_l_336f;
	case 13171ULL: goto x86_l_3373;
	case 13178ULL: goto x86_l_337a;
	case 13183ULL: goto x86_l_337f;
	case 13185ULL: goto x86_l_3381;
	case 13190ULL: goto x86_l_3386;
	case 13198ULL: goto x86_l_338e;
	case 13201ULL: goto x86_l_3391;
	case 13209ULL: goto x86_l_3399;
	case 13220ULL: goto x86_l_33a4;
	case 13223ULL: goto x86_l_33a7;
	case 13229ULL: goto x86_l_33ad;
	case 13231ULL: goto x86_l_33af;
	case 13236ULL: goto x86_l_33b4;
	case 13240ULL: goto x86_l_33b8;
	case 13243ULL: goto x86_l_33bb;
	case 13248ULL: goto x86_l_33c0;
	case 13252ULL: goto x86_l_33c4;
	case 13259ULL: goto x86_l_33cb;
	case 13267ULL: goto x86_l_33d3;
	case 13272ULL: goto x86_l_33d8;
	case 13277ULL: goto x86_l_33dd;
	case 13284ULL: goto x86_l_33e4;
	case 13287ULL: goto x86_l_33e7;
	case 13294ULL: goto x86_l_33ee;
	case 13299ULL: goto x86_l_33f3;
	case 13301ULL: goto x86_l_33f5;
	case 13308ULL: goto x86_l_33fc;
	case 13310ULL: goto x86_l_33fe;
	case 13312ULL: goto x86_l_3400;
	case 13318ULL: goto x86_l_3406;
	case 13321ULL: goto x86_l_3409;
	case 13327ULL: goto x86_l_340f;
	case 13332ULL: goto x86_l_3414;
	case 13337ULL: goto x86_l_3419;
	case 13343ULL: goto x86_l_341f;
	case 13348ULL: goto x86_l_3424;
	case 13352ULL: goto x86_l_3428;
	case 13359ULL: goto x86_l_342f;
	case 13367ULL: goto x86_l_3437;
	case 13372ULL: goto x86_l_343c;
	case 13377ULL: goto x86_l_3441;
	case 13385ULL: goto x86_l_3449;
	case 13389ULL: goto x86_l_344d;
	case 13396ULL: goto x86_l_3454;
	case 13401ULL: goto x86_l_3459;
	case 13403ULL: goto x86_l_345b;
	case 13411ULL: goto x86_l_3463;
	case 13419ULL: goto x86_l_346b;
	case 13422ULL: goto x86_l_346e;
	case 13430ULL: goto x86_l_3476;
	case 13432ULL: goto x86_l_3478;
	case 13437ULL: goto x86_l_347d;
	case 13441ULL: goto x86_l_3481;
	case 13448ULL: goto x86_l_3488;
	case 13453ULL: goto x86_l_348d;
	case 13458ULL: goto x86_l_3492;
	case 13463ULL: goto x86_l_3497;
	case 13470ULL: goto x86_l_349e;
	case 13474ULL: goto x86_l_34a2;
	case 13481ULL: goto x86_l_34a9;
	case 13486ULL: goto x86_l_34ae;
	case 13488ULL: goto x86_l_34b0;
	case 13493ULL: goto x86_l_34b5;
	case 13500ULL: goto x86_l_34bc;
	case 13503ULL: goto x86_l_34bf;
	case 13510ULL: goto x86_l_34c6;
	case 13519ULL: goto x86_l_34cf;
	case 13523ULL: goto x86_l_34d3;
	case 13528ULL: goto x86_l_34d8;
	case 13533ULL: goto x86_l_34dd;
	case 13538ULL: goto x86_l_34e2;
	case 13543ULL: goto x86_l_34e7;
	case 13545ULL: goto x86_l_34e9;
	case 13550ULL: goto x86_l_34ee;
	case 13552ULL: goto x86_l_34f0;
	case 13555ULL: goto x86_l_34f3;
	case 13561ULL: goto x86_l_34f9;
	case 13564ULL: goto x86_l_34fc;
	case 13570ULL: goto x86_l_3502;
	case 13576ULL: goto x86_l_3508;
	case 13581ULL: goto x86_l_350d;
	case 13585ULL: goto x86_l_3511;
	case 13592ULL: goto x86_l_3518;
	case 13597ULL: goto x86_l_351d;
	case 13602ULL: goto x86_l_3522;
	case 13609ULL: goto x86_l_3529;
	case 13612ULL: goto x86_l_352c;
	case 13619ULL: goto x86_l_3533;
	case 13624ULL: goto x86_l_3538;
	case 13629ULL: goto x86_l_353d;
	case 13631ULL: goto x86_l_353f;
	case 13635ULL: goto x86_l_3543;
	case 13637ULL: goto x86_l_3545;
	case 13639ULL: goto x86_l_3547;
	case 13645ULL: goto x86_l_354d;
	case 13648ULL: goto x86_l_3550;
	case 13654ULL: goto x86_l_3556;
	case 13660ULL: goto x86_l_355c;
	case 13665ULL: goto x86_l_3561;
	case 13669ULL: goto x86_l_3565;
	case 13676ULL: goto x86_l_356c;
	case 13681ULL: goto x86_l_3571;
	case 13686ULL: goto x86_l_3576;
	case 13691ULL: goto x86_l_357b;
	case 13699ULL: goto x86_l_3583;
	case 13703ULL: goto x86_l_3587;
	case 13710ULL: goto x86_l_358e;
	case 13715ULL: goto x86_l_3593;
	case 13717ULL: goto x86_l_3595;
	case 13722ULL: goto x86_l_359a;
	case 13730ULL: goto x86_l_35a2;
	case 13733ULL: goto x86_l_35a5;
	case 13741ULL: goto x86_l_35ad;
	case 13750ULL: goto x86_l_35b6;
	case 13754ULL: goto x86_l_35ba;
	case 13759ULL: goto x86_l_35bf;
	case 13764ULL: goto x86_l_35c4;
	case 13769ULL: goto x86_l_35c9;
	case 13774ULL: goto x86_l_35ce;
	case 13776ULL: goto x86_l_35d0;
	case 13781ULL: goto x86_l_35d5;
	case 13783ULL: goto x86_l_35d7;
	case 13786ULL: goto x86_l_35da;
	case 13792ULL: goto x86_l_35e0;
	case 13795ULL: goto x86_l_35e3;
	case 13801ULL: goto x86_l_35e9;
	case 13807ULL: goto x86_l_35ef;
	case 13812ULL: goto x86_l_35f4;
	case 13816ULL: goto x86_l_35f8;
	case 13823ULL: goto x86_l_35ff;
	case 13828ULL: goto x86_l_3604;
	case 13833ULL: goto x86_l_3609;
	case 13840ULL: goto x86_l_3610;
	case 13843ULL: goto x86_l_3613;
	case 13850ULL: goto x86_l_361a;
	case 13855ULL: goto x86_l_361f;
	case 13860ULL: goto x86_l_3624;
	case 13862ULL: goto x86_l_3626;
	case 13866ULL: goto x86_l_362a;
	case 13868ULL: goto x86_l_362c;
	case 13870ULL: goto x86_l_362e;
	case 13876ULL: goto x86_l_3634;
	case 13879ULL: goto x86_l_3637;
	case 13885ULL: goto x86_l_363d;
	case 13891ULL: goto x86_l_3643;
	case 13896ULL: goto x86_l_3648;
	case 13900ULL: goto x86_l_364c;
	case 13907ULL: goto x86_l_3653;
	case 13912ULL: goto x86_l_3658;
	case 13917ULL: goto x86_l_365d;
	case 13922ULL: goto x86_l_3662;
	case 13930ULL: goto x86_l_366a;
	case 13934ULL: goto x86_l_366e;
	case 13941ULL: goto x86_l_3675;
	case 13946ULL: goto x86_l_367a;
	case 13948ULL: goto x86_l_367c;
	case 13953ULL: goto x86_l_3681;
	case 13961ULL: goto x86_l_3689;
	case 13964ULL: goto x86_l_368c;
	case 13972ULL: goto x86_l_3694;
	case 13981ULL: goto x86_l_369d;
	case 13985ULL: goto x86_l_36a1;
	case 13990ULL: goto x86_l_36a6;
	case 13995ULL: goto x86_l_36ab;
	case 14000ULL: goto x86_l_36b0;
	case 14005ULL: goto x86_l_36b5;
	case 14007ULL: goto x86_l_36b7;
	case 14012ULL: goto x86_l_36bc;
	case 14014ULL: goto x86_l_36be;
	case 14017ULL: goto x86_l_36c1;
	case 14023ULL: goto x86_l_36c7;
	case 14026ULL: goto x86_l_36ca;
	case 14032ULL: goto x86_l_36d0;
	case 14038ULL: goto x86_l_36d6;
	case 14043ULL: goto x86_l_36db;
	case 14047ULL: goto x86_l_36df;
	case 14054ULL: goto x86_l_36e6;
	case 14059ULL: goto x86_l_36eb;
	case 14064ULL: goto x86_l_36f0;
	case 14071ULL: goto x86_l_36f7;
	case 14074ULL: goto x86_l_36fa;
	case 14081ULL: goto x86_l_3701;
	case 14086ULL: goto x86_l_3706;
	case 14091ULL: goto x86_l_370b;
	case 14093ULL: goto x86_l_370d;
	case 14097ULL: goto x86_l_3711;
	case 14099ULL: goto x86_l_3713;
	case 14101ULL: goto x86_l_3715;
	case 14107ULL: goto x86_l_371b;
	case 14110ULL: goto x86_l_371e;
	case 14116ULL: goto x86_l_3724;
	case 14122ULL: goto x86_l_372a;
	case 14127ULL: goto x86_l_372f;
	case 14131ULL: goto x86_l_3733;
	case 14138ULL: goto x86_l_373a;
	case 14143ULL: goto x86_l_373f;
	case 14148ULL: goto x86_l_3744;
	case 14153ULL: goto x86_l_3749;
	case 14161ULL: goto x86_l_3751;
	case 14165ULL: goto x86_l_3755;
	case 14172ULL: goto x86_l_375c;
	case 14177ULL: goto x86_l_3761;
	case 14179ULL: goto x86_l_3763;
	case 14184ULL: goto x86_l_3768;
	case 14192ULL: goto x86_l_3770;
	case 14195ULL: goto x86_l_3773;
	case 14203ULL: goto x86_l_377b;
	case 14212ULL: goto x86_l_3784;
	case 14216ULL: goto x86_l_3788;
	case 14221ULL: goto x86_l_378d;
	case 14226ULL: goto x86_l_3792;
	case 14231ULL: goto x86_l_3797;
	case 14236ULL: goto x86_l_379c;
	case 14238ULL: goto x86_l_379e;
	case 14243ULL: goto x86_l_37a3;
	case 14245ULL: goto x86_l_37a5;
	case 14248ULL: goto x86_l_37a8;
	case 14254ULL: goto x86_l_37ae;
	case 14257ULL: goto x86_l_37b1;
	case 14263ULL: goto x86_l_37b7;
	case 14269ULL: goto x86_l_37bd;
	case 14274ULL: goto x86_l_37c2;
	case 14278ULL: goto x86_l_37c6;
	case 14285ULL: goto x86_l_37cd;
	case 14290ULL: goto x86_l_37d2;
	case 14295ULL: goto x86_l_37d7;
	case 14302ULL: goto x86_l_37de;
	case 14305ULL: goto x86_l_37e1;
	case 14312ULL: goto x86_l_37e8;
	case 14317ULL: goto x86_l_37ed;
	case 14322ULL: goto x86_l_37f2;
	case 14324ULL: goto x86_l_37f4;
	case 14328ULL: goto x86_l_37f8;
	case 14330ULL: goto x86_l_37fa;
	case 14332ULL: goto x86_l_37fc;
	case 14338ULL: goto x86_l_3802;
	case 14341ULL: goto x86_l_3805;
	case 14347ULL: goto x86_l_380b;
	case 14353ULL: goto x86_l_3811;
	case 14358ULL: goto x86_l_3816;
	case 14362ULL: goto x86_l_381a;
	case 14369ULL: goto x86_l_3821;
	case 14374ULL: goto x86_l_3826;
	case 14379ULL: goto x86_l_382b;
	case 14384ULL: goto x86_l_3830;
	case 14392ULL: goto x86_l_3838;
	case 14396ULL: goto x86_l_383c;
	case 14403ULL: goto x86_l_3843;
	case 14408ULL: goto x86_l_3848;
	case 14410ULL: goto x86_l_384a;
	case 14415ULL: goto x86_l_384f;
	case 14423ULL: goto x86_l_3857;
	case 14426ULL: goto x86_l_385a;
	case 14434ULL: goto x86_l_3862;
	case 14443ULL: goto x86_l_386b;
	case 14447ULL: goto x86_l_386f;
	case 14452ULL: goto x86_l_3874;
	case 14457ULL: goto x86_l_3879;
	case 14462ULL: goto x86_l_387e;
	case 14467ULL: goto x86_l_3883;
	case 14469ULL: goto x86_l_3885;
	case 14474ULL: goto x86_l_388a;
	case 14476ULL: goto x86_l_388c;
	case 14479ULL: goto x86_l_388f;
	case 14485ULL: goto x86_l_3895;
	case 14488ULL: goto x86_l_3898;
	case 14494ULL: goto x86_l_389e;
	case 14500ULL: goto x86_l_38a4;
	case 14505ULL: goto x86_l_38a9;
	case 14509ULL: goto x86_l_38ad;
	case 14516ULL: goto x86_l_38b4;
	case 14521ULL: goto x86_l_38b9;
	case 14526ULL: goto x86_l_38be;
	case 14533ULL: goto x86_l_38c5;
	case 14536ULL: goto x86_l_38c8;
	case 14543ULL: goto x86_l_38cf;
	case 14548ULL: goto x86_l_38d4;
	case 14553ULL: goto x86_l_38d9;
	case 14555ULL: goto x86_l_38db;
	case 14559ULL: goto x86_l_38df;
	case 14561ULL: goto x86_l_38e1;
	case 14563ULL: goto x86_l_38e3;
	case 14569ULL: goto x86_l_38e9;
	case 14572ULL: goto x86_l_38ec;
	case 14578ULL: goto x86_l_38f2;
	case 14584ULL: goto x86_l_38f8;
	case 14589ULL: goto x86_l_38fd;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3190:
	/* 0x3190: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3198:
	/* 0x3198: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_319c:
	/* 0x319c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_31a3:
	/* 0x31a3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_31a8:
	/* 0x31a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31aa:
	/* 0x31aa: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_31af:
	/* 0x31af: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_31b7:
	/* 0x31b7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_31ba:
	/* 0x31ba: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_31c2:
	/* 0x31c2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_31cb:
	/* 0x31cb: lea    rdx,[r13+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_31d2:
	/* 0x31d2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31d7:
	/* 0x31d7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31dc:
	/* 0x31dc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31e1:
	/* 0x31e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31e6:
	/* 0x31e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31e8:
	/* 0x31e8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31ed:
	/* 0x31ed: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_31ef:
	/* 0x31ef: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_31f2:
	/* 0x31f2: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_31f8:
	/* 0x31f8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_31fb:
	/* 0x31fb: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3201:
	/* 0x3201: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_3207:
	/* 0x3207: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_320c:
	/* 0x320c: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3210:
	/* 0x3210: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3217:
	/* 0x3217: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_321c:
	/* 0x321c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3221:
	/* 0x3221: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3228:
	/* 0x3228: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_322b:
	/* 0x322b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3232:
	/* 0x3232: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3237:
	/* 0x3237: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_323c:
	/* 0x323c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_323e:
	/* 0x323e: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3242:
	/* 0x3242: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_3244:
	/* 0x3244: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3246:
	/* 0x3246: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_324c:
	/* 0x324c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_324f:
	/* 0x324f: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3255:
	/* 0x3255: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_325b:
	/* 0x325b: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3260:
	/* 0x3260: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3264:
	/* 0x3264: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_326b:
	/* 0x326b: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3270:
	/* 0x3270: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3275:
	/* 0x3275: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_327a:
	/* 0x327a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3282:
	/* 0x3282: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3286:
	/* 0x3286: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_328d:
	/* 0x328d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3292:
	/* 0x3292: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3294:
	/* 0x3294: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3299:
	/* 0x3299: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_32a1:
	/* 0x32a1: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_32a4:
	/* 0x32a4: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_32ac:
	/* 0x32ac: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_32b5:
	/* 0x32b5: add    r13,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_32bc:
	/* 0x32bc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32c1:
	/* 0x32c1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_32c6:
	/* 0x32c6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32cb:
	/* 0x32cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32d0:
	/* 0x32d0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_32d3:
	/* 0x32d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32d5:
	/* 0x32d5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32da:
	/* 0x32da: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_32dc:
	/* 0x32dc: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_32df:
	/* 0x32df: je     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2935ULL;
	}
x86_l_32e5:
	/* 0x32e5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_32e8:
	/* 0x32e8: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_32ee:
	/* 0x32ee: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_32f4:
	/* 0x32f4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32f9:
	/* 0x32f9: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_32fd:
	/* 0x32fd: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3304:
	/* 0x3304: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3309:
	/* 0x3309: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_330e:
	/* 0x330e: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3315:
	/* 0x3315: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3318:
	/* 0x3318: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_331f:
	/* 0x331f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3324:
	/* 0x3324: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3329:
	/* 0x3329: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_332b:
	/* 0x332b: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_332f:
	/* 0x332f: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_3331:
	/* 0x3331: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3333:
	/* 0x3333: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_3339:
	/* 0x3339: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_333c:
	/* 0x333c: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3342:
	/* 0x3342: ja     b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2935ULL;
	}
x86_l_3348:
	/* 0x3348: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_334d:
	/* 0x334d: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3351:
	/* 0x3351: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3358:
	/* 0x3358: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_335d:
	/* 0x335d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3362:
	/* 0x3362: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3367:
	/* 0x3367: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_336f:
	/* 0x336f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3373:
	/* 0x3373: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_337a:
	/* 0x337a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_337f:
	/* 0x337f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3381:
	/* 0x3381: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3386:
	/* 0x3386: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_338e:
	/* 0x338e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3391:
	/* 0x3391: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3399:
	/* 0x3399: mov    DWORD PTR [rsp+0x94],0x2e2e2e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635658186286ULL);
x86_l_33a4:
	/* 0x33a4: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_33a7:
	/* 0x33a7: cmp    ecx,0x6cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27901ULL);
x86_l_33ad:
	/* 0x33ad: jb     33b8 <syscall__execve_enter+0x33b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_33b8;
	}
x86_l_33af:
	/* 0x33af: mov    WORD PTR [rbx],0x6cfc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27900ULL);
x86_l_33b4:
	/* 0x33b4: mov    ax,0x6cfc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 27900ULL);
x86_l_33b8:
	/* 0x33b8: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_33bb:
	/* 0x33bb: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33c0:
	/* 0x33c0: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_33c4:
	/* 0x33c4: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_33cb:
	/* 0x33cb: lea    rdx,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_33d3:
	/* 0x33d3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_33d8:
	/* 0x33d8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_33dd:
	/* 0x33dd: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_33e4:
	/* 0x33e4: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_33e7:
	/* 0x33e7: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_33ee:
	/* 0x33ee: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_33f3:
	/* 0x33f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33f5:
	/* 0x33f5: mov    DWORD PTR [rsp+0x84],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_33fc:
	/* 0x33fc: mov    cl,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 38ULL);
x86_l_33fe:
	/* 0x33fe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3400:
	/* 0x3400: jle    b77 <syscall__execve_enter+0xb77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2935ULL;
	}
x86_l_3406:
	/* 0x3406: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3409:
	/* 0x3409: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_340f:
	/* 0x340f: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3414:
	/* 0x3414: mov    r13,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3419:
	/* 0x3419: ja     b81 <syscall__execve_enter+0xb81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2945ULL;
	}
x86_l_341f:
	/* 0x341f: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3424:
	/* 0x3424: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3428:
	/* 0x3428: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_342f:
	/* 0x342f: lea    rdx,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_3437:
	/* 0x3437: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_343c:
	/* 0x343c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3441:
	/* 0x3441: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3449:
	/* 0x3449: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_344d:
	/* 0x344d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3454:
	/* 0x3454: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3459:
	/* 0x3459: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_345b:
	/* 0x345b: movzx  eax,WORD PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 132ULL);
x86_l_3463:
	/* 0x3463: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_346b:
	/* 0x346b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_346e:
	/* 0x346e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3476:
	/* 0x3476: mov    cl,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 39ULL);
x86_l_3478:
	/* 0x3478: jmp    b81 <syscall__execve_enter+0xb81> */
	return 2945ULL;
x86_l_347d:
	/* 0x347d: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3481:
	/* 0x3481: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3488:
	/* 0x3488: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_348d:
	/* 0x348d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3492:
	/* 0x3492: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3497:
	/* 0x3497: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_349e:
	/* 0x349e: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_34a2:
	/* 0x34a2: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_34a9:
	/* 0x34a9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_34ae:
	/* 0x34ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34b0:
	/* 0x34b0: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_34b5:
	/* 0x34b5: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_34bc:
	/* 0x34bc: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_34bf:
	/* 0x34bf: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_34c6:
	/* 0x34c6: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_34cf:
	/* 0x34cf: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34d3:
	/* 0x34d3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34d8:
	/* 0x34d8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_34dd:
	/* 0x34dd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_34e2:
	/* 0x34e2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34e7:
	/* 0x34e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34e9:
	/* 0x34e9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34ee:
	/* 0x34ee: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_34f0:
	/* 0x34f0: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_34f3:
	/* 0x34f3: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_34f9:
	/* 0x34f9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_34fc:
	/* 0x34fc: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3502:
	/* 0x3502: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_3508:
	/* 0x3508: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_350d:
	/* 0x350d: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3511:
	/* 0x3511: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3518:
	/* 0x3518: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_351d:
	/* 0x351d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3522:
	/* 0x3522: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3529:
	/* 0x3529: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_352c:
	/* 0x352c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3533:
	/* 0x3533: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3538:
	/* 0x3538: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_353d:
	/* 0x353d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_353f:
	/* 0x353f: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3543:
	/* 0x3543: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_3545:
	/* 0x3545: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3547:
	/* 0x3547: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_354d:
	/* 0x354d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3550:
	/* 0x3550: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3556:
	/* 0x3556: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_355c:
	/* 0x355c: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3561:
	/* 0x3561: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3565:
	/* 0x3565: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_356c:
	/* 0x356c: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3571:
	/* 0x3571: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3576:
	/* 0x3576: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_357b:
	/* 0x357b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3583:
	/* 0x3583: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3587:
	/* 0x3587: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_358e:
	/* 0x358e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3593:
	/* 0x3593: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3595:
	/* 0x3595: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_359a:
	/* 0x359a: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_35a2:
	/* 0x35a2: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_35a5:
	/* 0x35a5: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_35ad:
	/* 0x35ad: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_35b6:
	/* 0x35b6: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35ba:
	/* 0x35ba: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35bf:
	/* 0x35bf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_35c4:
	/* 0x35c4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_35c9:
	/* 0x35c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35ce:
	/* 0x35ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35d0:
	/* 0x35d0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35d5:
	/* 0x35d5: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_35d7:
	/* 0x35d7: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_35da:
	/* 0x35da: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_35e0:
	/* 0x35e0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_35e3:
	/* 0x35e3: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_35e9:
	/* 0x35e9: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_35ef:
	/* 0x35ef: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35f4:
	/* 0x35f4: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_35f8:
	/* 0x35f8: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_35ff:
	/* 0x35ff: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3604:
	/* 0x3604: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3609:
	/* 0x3609: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3610:
	/* 0x3610: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3613:
	/* 0x3613: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_361a:
	/* 0x361a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_361f:
	/* 0x361f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3624:
	/* 0x3624: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3626:
	/* 0x3626: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_362a:
	/* 0x362a: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_362c:
	/* 0x362c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_362e:
	/* 0x362e: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_3634:
	/* 0x3634: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3637:
	/* 0x3637: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_363d:
	/* 0x363d: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_3643:
	/* 0x3643: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3648:
	/* 0x3648: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_364c:
	/* 0x364c: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3653:
	/* 0x3653: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3658:
	/* 0x3658: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_365d:
	/* 0x365d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3662:
	/* 0x3662: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_366a:
	/* 0x366a: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_366e:
	/* 0x366e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3675:
	/* 0x3675: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_367a:
	/* 0x367a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_367c:
	/* 0x367c: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3681:
	/* 0x3681: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3689:
	/* 0x3689: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_368c:
	/* 0x368c: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3694:
	/* 0x3694: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_369d:
	/* 0x369d: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_36a1:
	/* 0x36a1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36a6:
	/* 0x36a6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_36ab:
	/* 0x36ab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_36b0:
	/* 0x36b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36b5:
	/* 0x36b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36b7:
	/* 0x36b7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36bc:
	/* 0x36bc: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_36be:
	/* 0x36be: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_36c1:
	/* 0x36c1: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_36c7:
	/* 0x36c7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_36ca:
	/* 0x36ca: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_36d0:
	/* 0x36d0: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_36d6:
	/* 0x36d6: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36db:
	/* 0x36db: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_36df:
	/* 0x36df: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_36e6:
	/* 0x36e6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_36eb:
	/* 0x36eb: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_36f0:
	/* 0x36f0: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_36f7:
	/* 0x36f7: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_36fa:
	/* 0x36fa: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3701:
	/* 0x3701: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3706:
	/* 0x3706: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_370b:
	/* 0x370b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_370d:
	/* 0x370d: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3711:
	/* 0x3711: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_3713:
	/* 0x3713: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3715:
	/* 0x3715: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_371b:
	/* 0x371b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_371e:
	/* 0x371e: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3724:
	/* 0x3724: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_372a:
	/* 0x372a: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_372f:
	/* 0x372f: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3733:
	/* 0x3733: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_373a:
	/* 0x373a: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_373f:
	/* 0x373f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3744:
	/* 0x3744: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3749:
	/* 0x3749: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3751:
	/* 0x3751: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3755:
	/* 0x3755: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_375c:
	/* 0x375c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3761:
	/* 0x3761: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3763:
	/* 0x3763: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3768:
	/* 0x3768: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3770:
	/* 0x3770: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3773:
	/* 0x3773: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_377b:
	/* 0x377b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3784:
	/* 0x3784: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3788:
	/* 0x3788: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_378d:
	/* 0x378d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3792:
	/* 0x3792: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3797:
	/* 0x3797: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_379c:
	/* 0x379c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_379e:
	/* 0x379e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37a3:
	/* 0x37a3: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_37a5:
	/* 0x37a5: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_37a8:
	/* 0x37a8: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_37ae:
	/* 0x37ae: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_37b1:
	/* 0x37b1: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_37b7:
	/* 0x37b7: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_37bd:
	/* 0x37bd: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37c2:
	/* 0x37c2: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_37c6:
	/* 0x37c6: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_37cd:
	/* 0x37cd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_37d2:
	/* 0x37d2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_37d7:
	/* 0x37d7: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_37de:
	/* 0x37de: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_37e1:
	/* 0x37e1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_37e8:
	/* 0x37e8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37ed:
	/* 0x37ed: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_37f2:
	/* 0x37f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37f4:
	/* 0x37f4: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_37f8:
	/* 0x37f8: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_37fa:
	/* 0x37fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37fc:
	/* 0x37fc: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_3802:
	/* 0x3802: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3805:
	/* 0x3805: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_380b:
	/* 0x380b: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_3811:
	/* 0x3811: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3816:
	/* 0x3816: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_381a:
	/* 0x381a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3821:
	/* 0x3821: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3826:
	/* 0x3826: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_382b:
	/* 0x382b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3830:
	/* 0x3830: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3838:
	/* 0x3838: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_383c:
	/* 0x383c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3843:
	/* 0x3843: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3848:
	/* 0x3848: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_384a:
	/* 0x384a: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_384f:
	/* 0x384f: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3857:
	/* 0x3857: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_385a:
	/* 0x385a: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3862:
	/* 0x3862: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_386b:
	/* 0x386b: lea    rdx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_386f:
	/* 0x386f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3874:
	/* 0x3874: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3879:
	/* 0x3879: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_387e:
	/* 0x387e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3883:
	/* 0x3883: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3885:
	/* 0x3885: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_388a:
	/* 0x388a: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_388c:
	/* 0x388c: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_388f:
	/* 0x388f: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_3895:
	/* 0x3895: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3898:
	/* 0x3898: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_389e:
	/* 0x389e: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_38a4:
	/* 0x38a4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38a9:
	/* 0x38a9: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_38ad:
	/* 0x38ad: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_38b4:
	/* 0x38b4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_38b9:
	/* 0x38b9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_38be:
	/* 0x38be: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_38c5:
	/* 0x38c5: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_38c8:
	/* 0x38c8: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_38cf:
	/* 0x38cf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38d4:
	/* 0x38d4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_38d9:
	/* 0x38d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38db:
	/* 0x38db: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_38df:
	/* 0x38df: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_38e1:
	/* 0x38e1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38e3:
	/* 0x38e3: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_38e9:
	/* 0x38e9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_38ec:
	/* 0x38ec: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_38f2:
	/* 0x38f2: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_38f8:
	/* 0x38f8: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38fd:
	/* 0x38fd: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
	return 14593ULL;
}

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14593ULL: goto x86_l_3901;
	case 14600ULL: goto x86_l_3908;
	case 14605ULL: goto x86_l_390d;
	case 14610ULL: goto x86_l_3912;
	case 14615ULL: goto x86_l_3917;
	case 14623ULL: goto x86_l_391f;
	case 14627ULL: goto x86_l_3923;
	case 14634ULL: goto x86_l_392a;
	case 14639ULL: goto x86_l_392f;
	case 14641ULL: goto x86_l_3931;
	case 14646ULL: goto x86_l_3936;
	case 14654ULL: goto x86_l_393e;
	case 14657ULL: goto x86_l_3941;
	case 14665ULL: goto x86_l_3949;
	case 14674ULL: goto x86_l_3952;
	case 14678ULL: goto x86_l_3956;
	case 14683ULL: goto x86_l_395b;
	case 14688ULL: goto x86_l_3960;
	case 14693ULL: goto x86_l_3965;
	case 14698ULL: goto x86_l_396a;
	case 14700ULL: goto x86_l_396c;
	case 14705ULL: goto x86_l_3971;
	case 14707ULL: goto x86_l_3973;
	case 14710ULL: goto x86_l_3976;
	case 14716ULL: goto x86_l_397c;
	case 14719ULL: goto x86_l_397f;
	case 14725ULL: goto x86_l_3985;
	case 14731ULL: goto x86_l_398b;
	case 14736ULL: goto x86_l_3990;
	case 14740ULL: goto x86_l_3994;
	case 14747ULL: goto x86_l_399b;
	case 14752ULL: goto x86_l_39a0;
	case 14757ULL: goto x86_l_39a5;
	case 14764ULL: goto x86_l_39ac;
	case 14767ULL: goto x86_l_39af;
	case 14774ULL: goto x86_l_39b6;
	case 14779ULL: goto x86_l_39bb;
	case 14784ULL: goto x86_l_39c0;
	case 14786ULL: goto x86_l_39c2;
	case 14790ULL: goto x86_l_39c6;
	case 14792ULL: goto x86_l_39c8;
	case 14794ULL: goto x86_l_39ca;
	case 14800ULL: goto x86_l_39d0;
	case 14803ULL: goto x86_l_39d3;
	case 14809ULL: goto x86_l_39d9;
	case 14815ULL: goto x86_l_39df;
	case 14820ULL: goto x86_l_39e4;
	case 14824ULL: goto x86_l_39e8;
	case 14831ULL: goto x86_l_39ef;
	case 14836ULL: goto x86_l_39f4;
	case 14841ULL: goto x86_l_39f9;
	case 14846ULL: goto x86_l_39fe;
	case 14854ULL: goto x86_l_3a06;
	case 14858ULL: goto x86_l_3a0a;
	case 14865ULL: goto x86_l_3a11;
	case 14870ULL: goto x86_l_3a16;
	case 14872ULL: goto x86_l_3a18;
	case 14877ULL: goto x86_l_3a1d;
	case 14885ULL: goto x86_l_3a25;
	case 14888ULL: goto x86_l_3a28;
	case 14896ULL: goto x86_l_3a30;
	case 14905ULL: goto x86_l_3a39;
	case 14909ULL: goto x86_l_3a3d;
	case 14914ULL: goto x86_l_3a42;
	case 14919ULL: goto x86_l_3a47;
	case 14924ULL: goto x86_l_3a4c;
	case 14929ULL: goto x86_l_3a51;
	case 14931ULL: goto x86_l_3a53;
	case 14936ULL: goto x86_l_3a58;
	case 14938ULL: goto x86_l_3a5a;
	case 14941ULL: goto x86_l_3a5d;
	case 14947ULL: goto x86_l_3a63;
	case 14950ULL: goto x86_l_3a66;
	case 14956ULL: goto x86_l_3a6c;
	case 14962ULL: goto x86_l_3a72;
	case 14967ULL: goto x86_l_3a77;
	case 14971ULL: goto x86_l_3a7b;
	case 14978ULL: goto x86_l_3a82;
	case 14983ULL: goto x86_l_3a87;
	case 14988ULL: goto x86_l_3a8c;
	case 14995ULL: goto x86_l_3a93;
	case 14998ULL: goto x86_l_3a96;
	case 15005ULL: goto x86_l_3a9d;
	case 15010ULL: goto x86_l_3aa2;
	case 15015ULL: goto x86_l_3aa7;
	case 15017ULL: goto x86_l_3aa9;
	case 15021ULL: goto x86_l_3aad;
	case 15023ULL: goto x86_l_3aaf;
	case 15025ULL: goto x86_l_3ab1;
	case 15031ULL: goto x86_l_3ab7;
	case 15034ULL: goto x86_l_3aba;
	case 15040ULL: goto x86_l_3ac0;
	case 15046ULL: goto x86_l_3ac6;
	case 15051ULL: goto x86_l_3acb;
	case 15055ULL: goto x86_l_3acf;
	case 15062ULL: goto x86_l_3ad6;
	case 15067ULL: goto x86_l_3adb;
	case 15072ULL: goto x86_l_3ae0;
	case 15077ULL: goto x86_l_3ae5;
	case 15085ULL: goto x86_l_3aed;
	case 15089ULL: goto x86_l_3af1;
	case 15096ULL: goto x86_l_3af8;
	case 15101ULL: goto x86_l_3afd;
	case 15103ULL: goto x86_l_3aff;
	case 15108ULL: goto x86_l_3b04;
	case 15116ULL: goto x86_l_3b0c;
	case 15119ULL: goto x86_l_3b0f;
	case 15127ULL: goto x86_l_3b17;
	case 15136ULL: goto x86_l_3b20;
	case 15140ULL: goto x86_l_3b24;
	case 15145ULL: goto x86_l_3b29;
	case 15150ULL: goto x86_l_3b2e;
	case 15155ULL: goto x86_l_3b33;
	case 15160ULL: goto x86_l_3b38;
	case 15162ULL: goto x86_l_3b3a;
	case 15167ULL: goto x86_l_3b3f;
	case 15169ULL: goto x86_l_3b41;
	case 15172ULL: goto x86_l_3b44;
	case 15178ULL: goto x86_l_3b4a;
	case 15181ULL: goto x86_l_3b4d;
	case 15187ULL: goto x86_l_3b53;
	case 15193ULL: goto x86_l_3b59;
	case 15198ULL: goto x86_l_3b5e;
	case 15202ULL: goto x86_l_3b62;
	case 15209ULL: goto x86_l_3b69;
	case 15214ULL: goto x86_l_3b6e;
	case 15219ULL: goto x86_l_3b73;
	case 15226ULL: goto x86_l_3b7a;
	case 15229ULL: goto x86_l_3b7d;
	case 15236ULL: goto x86_l_3b84;
	case 15241ULL: goto x86_l_3b89;
	case 15246ULL: goto x86_l_3b8e;
	case 15248ULL: goto x86_l_3b90;
	case 15252ULL: goto x86_l_3b94;
	case 15254ULL: goto x86_l_3b96;
	case 15256ULL: goto x86_l_3b98;
	case 15262ULL: goto x86_l_3b9e;
	case 15265ULL: goto x86_l_3ba1;
	case 15271ULL: goto x86_l_3ba7;
	case 15277ULL: goto x86_l_3bad;
	case 15282ULL: goto x86_l_3bb2;
	case 15286ULL: goto x86_l_3bb6;
	case 15293ULL: goto x86_l_3bbd;
	case 15298ULL: goto x86_l_3bc2;
	case 15303ULL: goto x86_l_3bc7;
	case 15308ULL: goto x86_l_3bcc;
	case 15316ULL: goto x86_l_3bd4;
	case 15320ULL: goto x86_l_3bd8;
	case 15327ULL: goto x86_l_3bdf;
	case 15332ULL: goto x86_l_3be4;
	case 15334ULL: goto x86_l_3be6;
	case 15339ULL: goto x86_l_3beb;
	case 15347ULL: goto x86_l_3bf3;
	case 15350ULL: goto x86_l_3bf6;
	case 15358ULL: goto x86_l_3bfe;
	case 15367ULL: goto x86_l_3c07;
	case 15371ULL: goto x86_l_3c0b;
	case 15376ULL: goto x86_l_3c10;
	case 15381ULL: goto x86_l_3c15;
	case 15386ULL: goto x86_l_3c1a;
	case 15391ULL: goto x86_l_3c1f;
	case 15393ULL: goto x86_l_3c21;
	case 15398ULL: goto x86_l_3c26;
	case 15400ULL: goto x86_l_3c28;
	case 15403ULL: goto x86_l_3c2b;
	case 15409ULL: goto x86_l_3c31;
	case 15412ULL: goto x86_l_3c34;
	case 15418ULL: goto x86_l_3c3a;
	case 15424ULL: goto x86_l_3c40;
	case 15429ULL: goto x86_l_3c45;
	case 15433ULL: goto x86_l_3c49;
	case 15440ULL: goto x86_l_3c50;
	case 15445ULL: goto x86_l_3c55;
	case 15450ULL: goto x86_l_3c5a;
	case 15457ULL: goto x86_l_3c61;
	case 15460ULL: goto x86_l_3c64;
	case 15467ULL: goto x86_l_3c6b;
	case 15472ULL: goto x86_l_3c70;
	case 15477ULL: goto x86_l_3c75;
	case 15479ULL: goto x86_l_3c77;
	case 15483ULL: goto x86_l_3c7b;
	case 15485ULL: goto x86_l_3c7d;
	case 15487ULL: goto x86_l_3c7f;
	case 15493ULL: goto x86_l_3c85;
	case 15496ULL: goto x86_l_3c88;
	case 15502ULL: goto x86_l_3c8e;
	case 15508ULL: goto x86_l_3c94;
	case 15513ULL: goto x86_l_3c99;
	case 15517ULL: goto x86_l_3c9d;
	case 15524ULL: goto x86_l_3ca4;
	case 15529ULL: goto x86_l_3ca9;
	case 15534ULL: goto x86_l_3cae;
	case 15539ULL: goto x86_l_3cb3;
	case 15547ULL: goto x86_l_3cbb;
	case 15551ULL: goto x86_l_3cbf;
	case 15558ULL: goto x86_l_3cc6;
	case 15563ULL: goto x86_l_3ccb;
	case 15565ULL: goto x86_l_3ccd;
	case 15570ULL: goto x86_l_3cd2;
	case 15578ULL: goto x86_l_3cda;
	case 15581ULL: goto x86_l_3cdd;
	case 15589ULL: goto x86_l_3ce5;
	case 15598ULL: goto x86_l_3cee;
	case 15602ULL: goto x86_l_3cf2;
	case 15607ULL: goto x86_l_3cf7;
	case 15612ULL: goto x86_l_3cfc;
	case 15617ULL: goto x86_l_3d01;
	case 15622ULL: goto x86_l_3d06;
	case 15624ULL: goto x86_l_3d08;
	case 15629ULL: goto x86_l_3d0d;
	case 15631ULL: goto x86_l_3d0f;
	case 15634ULL: goto x86_l_3d12;
	case 15640ULL: goto x86_l_3d18;
	case 15643ULL: goto x86_l_3d1b;
	case 15649ULL: goto x86_l_3d21;
	case 15655ULL: goto x86_l_3d27;
	case 15660ULL: goto x86_l_3d2c;
	case 15664ULL: goto x86_l_3d30;
	case 15671ULL: goto x86_l_3d37;
	case 15676ULL: goto x86_l_3d3c;
	case 15681ULL: goto x86_l_3d41;
	case 15688ULL: goto x86_l_3d48;
	case 15691ULL: goto x86_l_3d4b;
	case 15698ULL: goto x86_l_3d52;
	case 15703ULL: goto x86_l_3d57;
	case 15708ULL: goto x86_l_3d5c;
	case 15710ULL: goto x86_l_3d5e;
	case 15714ULL: goto x86_l_3d62;
	case 15716ULL: goto x86_l_3d64;
	case 15718ULL: goto x86_l_3d66;
	case 15724ULL: goto x86_l_3d6c;
	case 15727ULL: goto x86_l_3d6f;
	case 15733ULL: goto x86_l_3d75;
	case 15739ULL: goto x86_l_3d7b;
	case 15744ULL: goto x86_l_3d80;
	case 15748ULL: goto x86_l_3d84;
	case 15755ULL: goto x86_l_3d8b;
	case 15760ULL: goto x86_l_3d90;
	case 15765ULL: goto x86_l_3d95;
	case 15770ULL: goto x86_l_3d9a;
	case 15778ULL: goto x86_l_3da2;
	case 15782ULL: goto x86_l_3da6;
	case 15789ULL: goto x86_l_3dad;
	case 15794ULL: goto x86_l_3db2;
	case 15796ULL: goto x86_l_3db4;
	case 15801ULL: goto x86_l_3db9;
	case 15809ULL: goto x86_l_3dc1;
	case 15812ULL: goto x86_l_3dc4;
	case 15820ULL: goto x86_l_3dcc;
	case 15829ULL: goto x86_l_3dd5;
	case 15833ULL: goto x86_l_3dd9;
	case 15838ULL: goto x86_l_3dde;
	case 15843ULL: goto x86_l_3de3;
	case 15848ULL: goto x86_l_3de8;
	case 15853ULL: goto x86_l_3ded;
	case 15855ULL: goto x86_l_3def;
	case 15860ULL: goto x86_l_3df4;
	case 15862ULL: goto x86_l_3df6;
	case 15865ULL: goto x86_l_3df9;
	case 15871ULL: goto x86_l_3dff;
	case 15874ULL: goto x86_l_3e02;
	case 15880ULL: goto x86_l_3e08;
	case 15886ULL: goto x86_l_3e0e;
	case 15891ULL: goto x86_l_3e13;
	case 15895ULL: goto x86_l_3e17;
	case 15902ULL: goto x86_l_3e1e;
	case 15907ULL: goto x86_l_3e23;
	case 15912ULL: goto x86_l_3e28;
	case 15919ULL: goto x86_l_3e2f;
	case 15922ULL: goto x86_l_3e32;
	case 15929ULL: goto x86_l_3e39;
	case 15934ULL: goto x86_l_3e3e;
	case 15939ULL: goto x86_l_3e43;
	case 15941ULL: goto x86_l_3e45;
	case 15945ULL: goto x86_l_3e49;
	case 15947ULL: goto x86_l_3e4b;
	case 15949ULL: goto x86_l_3e4d;
	case 15955ULL: goto x86_l_3e53;
	case 15958ULL: goto x86_l_3e56;
	case 15964ULL: goto x86_l_3e5c;
	case 15970ULL: goto x86_l_3e62;
	case 15975ULL: goto x86_l_3e67;
	case 15979ULL: goto x86_l_3e6b;
	case 15986ULL: goto x86_l_3e72;
	case 15991ULL: goto x86_l_3e77;
	case 15996ULL: goto x86_l_3e7c;
	case 16001ULL: goto x86_l_3e81;
	case 16009ULL: goto x86_l_3e89;
	case 16013ULL: goto x86_l_3e8d;
	case 16020ULL: goto x86_l_3e94;
	case 16025ULL: goto x86_l_3e99;
	case 16027ULL: goto x86_l_3e9b;
	case 16032ULL: goto x86_l_3ea0;
	case 16040ULL: goto x86_l_3ea8;
	case 16043ULL: goto x86_l_3eab;
	case 16051ULL: goto x86_l_3eb3;
	case 16060ULL: goto x86_l_3ebc;
	case 16064ULL: goto x86_l_3ec0;
	case 16069ULL: goto x86_l_3ec5;
	case 16074ULL: goto x86_l_3eca;
	case 16079ULL: goto x86_l_3ecf;
	case 16084ULL: goto x86_l_3ed4;
	case 16086ULL: goto x86_l_3ed6;
	case 16091ULL: goto x86_l_3edb;
	case 16093ULL: goto x86_l_3edd;
	case 16096ULL: goto x86_l_3ee0;
	case 16102ULL: goto x86_l_3ee6;
	case 16105ULL: goto x86_l_3ee9;
	case 16111ULL: goto x86_l_3eef;
	case 16117ULL: goto x86_l_3ef5;
	case 16122ULL: goto x86_l_3efa;
	case 16126ULL: goto x86_l_3efe;
	case 16133ULL: goto x86_l_3f05;
	case 16138ULL: goto x86_l_3f0a;
	case 16143ULL: goto x86_l_3f0f;
	case 16150ULL: goto x86_l_3f16;
	case 16153ULL: goto x86_l_3f19;
	case 16160ULL: goto x86_l_3f20;
	case 16165ULL: goto x86_l_3f25;
	case 16170ULL: goto x86_l_3f2a;
	case 16172ULL: goto x86_l_3f2c;
	case 16176ULL: goto x86_l_3f30;
	case 16178ULL: goto x86_l_3f32;
	case 16180ULL: goto x86_l_3f34;
	case 16186ULL: goto x86_l_3f3a;
	case 16189ULL: goto x86_l_3f3d;
	case 16195ULL: goto x86_l_3f43;
	case 16201ULL: goto x86_l_3f49;
	case 16206ULL: goto x86_l_3f4e;
	case 16210ULL: goto x86_l_3f52;
	case 16217ULL: goto x86_l_3f59;
	case 16222ULL: goto x86_l_3f5e;
	case 16227ULL: goto x86_l_3f63;
	case 16232ULL: goto x86_l_3f68;
	case 16240ULL: goto x86_l_3f70;
	case 16244ULL: goto x86_l_3f74;
	case 16251ULL: goto x86_l_3f7b;
	case 16256ULL: goto x86_l_3f80;
	case 16258ULL: goto x86_l_3f82;
	case 16263ULL: goto x86_l_3f87;
	case 16271ULL: goto x86_l_3f8f;
	case 16274ULL: goto x86_l_3f92;
	case 16282ULL: goto x86_l_3f9a;
	case 16291ULL: goto x86_l_3fa3;
	case 16295ULL: goto x86_l_3fa7;
	case 16300ULL: goto x86_l_3fac;
	case 16305ULL: goto x86_l_3fb1;
	case 16310ULL: goto x86_l_3fb6;
	case 16315ULL: goto x86_l_3fbb;
	case 16317ULL: goto x86_l_3fbd;
	case 16322ULL: goto x86_l_3fc2;
	case 16324ULL: goto x86_l_3fc4;
	case 16327ULL: goto x86_l_3fc7;
	case 16333ULL: goto x86_l_3fcd;
	case 16336ULL: goto x86_l_3fd0;
	case 16342ULL: goto x86_l_3fd6;
	case 16348ULL: goto x86_l_3fdc;
	case 16353ULL: goto x86_l_3fe1;
	case 16357ULL: goto x86_l_3fe5;
	case 16364ULL: goto x86_l_3fec;
	case 16369ULL: goto x86_l_3ff1;
	case 16374ULL: goto x86_l_3ff6;
	case 16381ULL: goto x86_l_3ffd;
	case 16384ULL: goto x86_l_4000;
	case 16391ULL: goto x86_l_4007;
	case 16396ULL: goto x86_l_400c;
	case 16401ULL: goto x86_l_4011;
	case 16403ULL: goto x86_l_4013;
	case 16407ULL: goto x86_l_4017;
	case 16409ULL: goto x86_l_4019;
	case 16411ULL: goto x86_l_401b;
	case 16417ULL: goto x86_l_4021;
	case 16420ULL: goto x86_l_4024;
	case 16426ULL: goto x86_l_402a;
	case 16432ULL: goto x86_l_4030;
	case 16437ULL: goto x86_l_4035;
	case 16441ULL: goto x86_l_4039;
	case 16448ULL: goto x86_l_4040;
	case 16453ULL: goto x86_l_4045;
	case 16458ULL: goto x86_l_404a;
	case 16463ULL: goto x86_l_404f;
	case 16471ULL: goto x86_l_4057;
	case 16475ULL: goto x86_l_405b;
	case 16482ULL: goto x86_l_4062;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3901:
	/* 0x3901: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3908:
	/* 0x3908: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_390d:
	/* 0x390d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3912:
	/* 0x3912: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3917:
	/* 0x3917: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_391f:
	/* 0x391f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3923:
	/* 0x3923: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_392a:
	/* 0x392a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_392f:
	/* 0x392f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3931:
	/* 0x3931: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3936:
	/* 0x3936: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_393e:
	/* 0x393e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3941:
	/* 0x3941: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3949:
	/* 0x3949: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3952:
	/* 0x3952: lea    rdx,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3956:
	/* 0x3956: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_395b:
	/* 0x395b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3960:
	/* 0x3960: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3965:
	/* 0x3965: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_396a:
	/* 0x396a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_396c:
	/* 0x396c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3971:
	/* 0x3971: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_3973:
	/* 0x3973: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3976:
	/* 0x3976: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_397c:
	/* 0x397c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_397f:
	/* 0x397f: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3985:
	/* 0x3985: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_398b:
	/* 0x398b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3990:
	/* 0x3990: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3994:
	/* 0x3994: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_399b:
	/* 0x399b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_39a0:
	/* 0x39a0: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_39a5:
	/* 0x39a5: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_39ac:
	/* 0x39ac: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_39af:
	/* 0x39af: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_39b6:
	/* 0x39b6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39bb:
	/* 0x39bb: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_39c0:
	/* 0x39c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39c2:
	/* 0x39c2: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_39c6:
	/* 0x39c6: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_39c8:
	/* 0x39c8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39ca:
	/* 0x39ca: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_39d0:
	/* 0x39d0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_39d3:
	/* 0x39d3: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_39d9:
	/* 0x39d9: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_39df:
	/* 0x39df: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39e4:
	/* 0x39e4: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_39e8:
	/* 0x39e8: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_39ef:
	/* 0x39ef: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_39f4:
	/* 0x39f4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_39f9:
	/* 0x39f9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_39fe:
	/* 0x39fe: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3a06:
	/* 0x3a06: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3a0a:
	/* 0x3a0a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3a11:
	/* 0x3a11: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3a16:
	/* 0x3a16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a18:
	/* 0x3a18: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3a1d:
	/* 0x3a1d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3a25:
	/* 0x3a25: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3a28:
	/* 0x3a28: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3a30:
	/* 0x3a30: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3a39:
	/* 0x3a39: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3a3d:
	/* 0x3a3d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a42:
	/* 0x3a42: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3a47:
	/* 0x3a47: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a4c:
	/* 0x3a4c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a51:
	/* 0x3a51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a53:
	/* 0x3a53: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a58:
	/* 0x3a58: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_3a5a:
	/* 0x3a5a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3a5d:
	/* 0x3a5d: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_3a63:
	/* 0x3a63: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3a66:
	/* 0x3a66: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3a6c:
	/* 0x3a6c: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_3a72:
	/* 0x3a72: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a77:
	/* 0x3a77: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3a7b:
	/* 0x3a7b: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3a82:
	/* 0x3a82: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3a87:
	/* 0x3a87: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3a8c:
	/* 0x3a8c: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3a93:
	/* 0x3a93: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3a96:
	/* 0x3a96: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3a9d:
	/* 0x3a9d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3aa2:
	/* 0x3aa2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3aa7:
	/* 0x3aa7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3aa9:
	/* 0x3aa9: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3aad:
	/* 0x3aad: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_3aaf:
	/* 0x3aaf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ab1:
	/* 0x3ab1: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_3ab7:
	/* 0x3ab7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3aba:
	/* 0x3aba: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3ac0:
	/* 0x3ac0: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_3ac6:
	/* 0x3ac6: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3acb:
	/* 0x3acb: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3acf:
	/* 0x3acf: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3ad6:
	/* 0x3ad6: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3adb:
	/* 0x3adb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3ae0:
	/* 0x3ae0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ae5:
	/* 0x3ae5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3aed:
	/* 0x3aed: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3af1:
	/* 0x3af1: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3af8:
	/* 0x3af8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3afd:
	/* 0x3afd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3aff:
	/* 0x3aff: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3b04:
	/* 0x3b04: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3b0c:
	/* 0x3b0c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3b0f:
	/* 0x3b0f: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3b17:
	/* 0x3b17: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3b20:
	/* 0x3b20: lea    rdx,[r13+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3b24:
	/* 0x3b24: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b29:
	/* 0x3b29: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3b2e:
	/* 0x3b2e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b33:
	/* 0x3b33: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3b38:
	/* 0x3b38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b3a:
	/* 0x3b3a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b3f:
	/* 0x3b3f: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_3b41:
	/* 0x3b41: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3b44:
	/* 0x3b44: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_3b4a:
	/* 0x3b4a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b4d:
	/* 0x3b4d: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3b53:
	/* 0x3b53: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_3b59:
	/* 0x3b59: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b5e:
	/* 0x3b5e: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3b62:
	/* 0x3b62: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3b69:
	/* 0x3b69: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3b6e:
	/* 0x3b6e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3b73:
	/* 0x3b73: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3b7a:
	/* 0x3b7a: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3b7d:
	/* 0x3b7d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3b84:
	/* 0x3b84: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b89:
	/* 0x3b89: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3b8e:
	/* 0x3b8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b90:
	/* 0x3b90: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3b94:
	/* 0x3b94: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_3b96:
	/* 0x3b96: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b98:
	/* 0x3b98: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_3b9e:
	/* 0x3b9e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ba1:
	/* 0x3ba1: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3ba7:
	/* 0x3ba7: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_3bad:
	/* 0x3bad: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bb2:
	/* 0x3bb2: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3bb6:
	/* 0x3bb6: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3bbd:
	/* 0x3bbd: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3bc2:
	/* 0x3bc2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3bc7:
	/* 0x3bc7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3bcc:
	/* 0x3bcc: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3bd4:
	/* 0x3bd4: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3bd8:
	/* 0x3bd8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3bdf:
	/* 0x3bdf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3be4:
	/* 0x3be4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3be6:
	/* 0x3be6: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3beb:
	/* 0x3beb: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3bf3:
	/* 0x3bf3: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3bf6:
	/* 0x3bf6: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3bfe:
	/* 0x3bfe: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3c07:
	/* 0x3c07: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3c0b:
	/* 0x3c0b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c10:
	/* 0x3c10: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3c15:
	/* 0x3c15: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c1a:
	/* 0x3c1a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c1f:
	/* 0x3c1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c21:
	/* 0x3c21: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c26:
	/* 0x3c26: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_3c28:
	/* 0x3c28: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3c2b:
	/* 0x3c2b: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_3c31:
	/* 0x3c31: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3c34:
	/* 0x3c34: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3c3a:
	/* 0x3c3a: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_3c40:
	/* 0x3c40: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c45:
	/* 0x3c45: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3c49:
	/* 0x3c49: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3c50:
	/* 0x3c50: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3c55:
	/* 0x3c55: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3c5a:
	/* 0x3c5a: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3c61:
	/* 0x3c61: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3c64:
	/* 0x3c64: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3c6b:
	/* 0x3c6b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c70:
	/* 0x3c70: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3c75:
	/* 0x3c75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c77:
	/* 0x3c77: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3c7b:
	/* 0x3c7b: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_3c7d:
	/* 0x3c7d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c7f:
	/* 0x3c7f: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_3c85:
	/* 0x3c85: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3c88:
	/* 0x3c88: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3c8e:
	/* 0x3c8e: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_3c94:
	/* 0x3c94: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c99:
	/* 0x3c99: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3c9d:
	/* 0x3c9d: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3ca4:
	/* 0x3ca4: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3ca9:
	/* 0x3ca9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3cae:
	/* 0x3cae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3cb3:
	/* 0x3cb3: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3cbb:
	/* 0x3cbb: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3cbf:
	/* 0x3cbf: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3cc6:
	/* 0x3cc6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3ccb:
	/* 0x3ccb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ccd:
	/* 0x3ccd: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3cd2:
	/* 0x3cd2: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3cda:
	/* 0x3cda: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3cdd:
	/* 0x3cdd: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3ce5:
	/* 0x3ce5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3cee:
	/* 0x3cee: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3cf2:
	/* 0x3cf2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cf7:
	/* 0x3cf7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3cfc:
	/* 0x3cfc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d01:
	/* 0x3d01: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d06:
	/* 0x3d06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d08:
	/* 0x3d08: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d0d:
	/* 0x3d0d: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_3d0f:
	/* 0x3d0f: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3d12:
	/* 0x3d12: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_3d18:
	/* 0x3d18: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3d1b:
	/* 0x3d1b: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3d21:
	/* 0x3d21: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_3d27:
	/* 0x3d27: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d2c:
	/* 0x3d2c: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3d30:
	/* 0x3d30: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3d37:
	/* 0x3d37: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3d3c:
	/* 0x3d3c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3d41:
	/* 0x3d41: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3d48:
	/* 0x3d48: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3d4b:
	/* 0x3d4b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3d52:
	/* 0x3d52: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d57:
	/* 0x3d57: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3d5c:
	/* 0x3d5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d5e:
	/* 0x3d5e: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3d62:
	/* 0x3d62: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_3d64:
	/* 0x3d64: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d66:
	/* 0x3d66: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_3d6c:
	/* 0x3d6c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3d6f:
	/* 0x3d6f: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3d75:
	/* 0x3d75: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_3d7b:
	/* 0x3d7b: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d80:
	/* 0x3d80: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3d84:
	/* 0x3d84: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3d8b:
	/* 0x3d8b: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3d90:
	/* 0x3d90: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3d95:
	/* 0x3d95: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d9a:
	/* 0x3d9a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3da2:
	/* 0x3da2: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3da6:
	/* 0x3da6: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3dad:
	/* 0x3dad: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3db2:
	/* 0x3db2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3db4:
	/* 0x3db4: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3db9:
	/* 0x3db9: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3dc1:
	/* 0x3dc1: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3dc4:
	/* 0x3dc4: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3dcc:
	/* 0x3dcc: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3dd5:
	/* 0x3dd5: lea    rdx,[r13+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3dd9:
	/* 0x3dd9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3dde:
	/* 0x3dde: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3de3:
	/* 0x3de3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3de8:
	/* 0x3de8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ded:
	/* 0x3ded: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3def:
	/* 0x3def: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3df4:
	/* 0x3df4: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_3df6:
	/* 0x3df6: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3df9:
	/* 0x3df9: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_3dff:
	/* 0x3dff: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e02:
	/* 0x3e02: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3e08:
	/* 0x3e08: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_3e0e:
	/* 0x3e0e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e13:
	/* 0x3e13: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3e17:
	/* 0x3e17: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3e1e:
	/* 0x3e1e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3e23:
	/* 0x3e23: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3e28:
	/* 0x3e28: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3e2f:
	/* 0x3e2f: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3e32:
	/* 0x3e32: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3e39:
	/* 0x3e39: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e3e:
	/* 0x3e3e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3e43:
	/* 0x3e43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e45:
	/* 0x3e45: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3e49:
	/* 0x3e49: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_3e4b:
	/* 0x3e4b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3e4d:
	/* 0x3e4d: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_3e53:
	/* 0x3e53: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e56:
	/* 0x3e56: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3e5c:
	/* 0x3e5c: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_3e62:
	/* 0x3e62: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e67:
	/* 0x3e67: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3e6b:
	/* 0x3e6b: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3e72:
	/* 0x3e72: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3e77:
	/* 0x3e77: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e7c:
	/* 0x3e7c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e81:
	/* 0x3e81: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3e89:
	/* 0x3e89: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3e8d:
	/* 0x3e8d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3e94:
	/* 0x3e94: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e99:
	/* 0x3e99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e9b:
	/* 0x3e9b: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3ea0:
	/* 0x3ea0: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3ea8:
	/* 0x3ea8: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3eab:
	/* 0x3eab: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3eb3:
	/* 0x3eb3: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3ebc:
	/* 0x3ebc: lea    rdx,[r13+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3ec0:
	/* 0x3ec0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ec5:
	/* 0x3ec5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3eca:
	/* 0x3eca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ecf:
	/* 0x3ecf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ed4:
	/* 0x3ed4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ed6:
	/* 0x3ed6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3edb:
	/* 0x3edb: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_3edd:
	/* 0x3edd: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3ee0:
	/* 0x3ee0: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_3ee6:
	/* 0x3ee6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ee9:
	/* 0x3ee9: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3eef:
	/* 0x3eef: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_3ef5:
	/* 0x3ef5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3efa:
	/* 0x3efa: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3efe:
	/* 0x3efe: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3f05:
	/* 0x3f05: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3f0a:
	/* 0x3f0a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3f0f:
	/* 0x3f0f: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3f16:
	/* 0x3f16: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3f19:
	/* 0x3f19: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3f20:
	/* 0x3f20: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f25:
	/* 0x3f25: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3f2a:
	/* 0x3f2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f2c:
	/* 0x3f2c: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3f30:
	/* 0x3f30: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_3f32:
	/* 0x3f32: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3f34:
	/* 0x3f34: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_3f3a:
	/* 0x3f3a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f3d:
	/* 0x3f3d: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3f43:
	/* 0x3f43: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_3f49:
	/* 0x3f49: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f4e:
	/* 0x3f4e: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3f52:
	/* 0x3f52: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3f59:
	/* 0x3f59: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3f5e:
	/* 0x3f5e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3f63:
	/* 0x3f63: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3f68:
	/* 0x3f68: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3f70:
	/* 0x3f70: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3f74:
	/* 0x3f74: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3f7b:
	/* 0x3f7b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3f80:
	/* 0x3f80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f82:
	/* 0x3f82: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3f87:
	/* 0x3f87: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3f8f:
	/* 0x3f8f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3f92:
	/* 0x3f92: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3f9a:
	/* 0x3f9a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3fa3:
	/* 0x3fa3: lea    rdx,[r13+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3fa7:
	/* 0x3fa7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3fac:
	/* 0x3fac: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3fb1:
	/* 0x3fb1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3fb6:
	/* 0x3fb6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3fbb:
	/* 0x3fbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fbd:
	/* 0x3fbd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3fc2:
	/* 0x3fc2: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_3fc4:
	/* 0x3fc4: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3fc7:
	/* 0x3fc7: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_3fcd:
	/* 0x3fcd: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3fd0:
	/* 0x3fd0: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3fd6:
	/* 0x3fd6: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_3fdc:
	/* 0x3fdc: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fe1:
	/* 0x3fe1: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3fe5:
	/* 0x3fe5: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3fec:
	/* 0x3fec: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3ff1:
	/* 0x3ff1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3ff6:
	/* 0x3ff6: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3ffd:
	/* 0x3ffd: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4000:
	/* 0x4000: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4007:
	/* 0x4007: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_400c:
	/* 0x400c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4011:
	/* 0x4011: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4013:
	/* 0x4013: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4017:
	/* 0x4017: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_4019:
	/* 0x4019: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_401b:
	/* 0x401b: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_4021:
	/* 0x4021: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4024:
	/* 0x4024: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_402a:
	/* 0x402a: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4030:
	/* 0x4030: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4035:
	/* 0x4035: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4039:
	/* 0x4039: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4040:
	/* 0x4040: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4045:
	/* 0x4045: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_404a:
	/* 0x404a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_404f:
	/* 0x404f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4057:
	/* 0x4057: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_405b:
	/* 0x405b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4062:
	/* 0x4062: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
	return 16487ULL;
}

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 16487ULL: goto x86_l_4067;
	case 16489ULL: goto x86_l_4069;
	case 16494ULL: goto x86_l_406e;
	case 16502ULL: goto x86_l_4076;
	case 16505ULL: goto x86_l_4079;
	case 16513ULL: goto x86_l_4081;
	case 16522ULL: goto x86_l_408a;
	case 16526ULL: goto x86_l_408e;
	case 16531ULL: goto x86_l_4093;
	case 16536ULL: goto x86_l_4098;
	case 16541ULL: goto x86_l_409d;
	case 16546ULL: goto x86_l_40a2;
	case 16548ULL: goto x86_l_40a4;
	case 16553ULL: goto x86_l_40a9;
	case 16555ULL: goto x86_l_40ab;
	case 16558ULL: goto x86_l_40ae;
	case 16564ULL: goto x86_l_40b4;
	case 16567ULL: goto x86_l_40b7;
	case 16573ULL: goto x86_l_40bd;
	case 16579ULL: goto x86_l_40c3;
	case 16584ULL: goto x86_l_40c8;
	case 16588ULL: goto x86_l_40cc;
	case 16595ULL: goto x86_l_40d3;
	case 16600ULL: goto x86_l_40d8;
	case 16605ULL: goto x86_l_40dd;
	case 16612ULL: goto x86_l_40e4;
	case 16615ULL: goto x86_l_40e7;
	case 16622ULL: goto x86_l_40ee;
	case 16627ULL: goto x86_l_40f3;
	case 16632ULL: goto x86_l_40f8;
	case 16634ULL: goto x86_l_40fa;
	case 16638ULL: goto x86_l_40fe;
	case 16640ULL: goto x86_l_4100;
	case 16642ULL: goto x86_l_4102;
	case 16648ULL: goto x86_l_4108;
	case 16651ULL: goto x86_l_410b;
	case 16657ULL: goto x86_l_4111;
	case 16663ULL: goto x86_l_4117;
	case 16668ULL: goto x86_l_411c;
	case 16672ULL: goto x86_l_4120;
	case 16679ULL: goto x86_l_4127;
	case 16684ULL: goto x86_l_412c;
	case 16689ULL: goto x86_l_4131;
	case 16694ULL: goto x86_l_4136;
	case 16702ULL: goto x86_l_413e;
	case 16706ULL: goto x86_l_4142;
	case 16713ULL: goto x86_l_4149;
	case 16718ULL: goto x86_l_414e;
	case 16720ULL: goto x86_l_4150;
	case 16725ULL: goto x86_l_4155;
	case 16733ULL: goto x86_l_415d;
	case 16736ULL: goto x86_l_4160;
	case 16744ULL: goto x86_l_4168;
	case 16753ULL: goto x86_l_4171;
	case 16757ULL: goto x86_l_4175;
	case 16762ULL: goto x86_l_417a;
	case 16767ULL: goto x86_l_417f;
	case 16772ULL: goto x86_l_4184;
	case 16777ULL: goto x86_l_4189;
	case 16779ULL: goto x86_l_418b;
	case 16784ULL: goto x86_l_4190;
	case 16786ULL: goto x86_l_4192;
	case 16789ULL: goto x86_l_4195;
	case 16795ULL: goto x86_l_419b;
	case 16798ULL: goto x86_l_419e;
	case 16804ULL: goto x86_l_41a4;
	case 16810ULL: goto x86_l_41aa;
	case 16815ULL: goto x86_l_41af;
	case 16819ULL: goto x86_l_41b3;
	case 16826ULL: goto x86_l_41ba;
	case 16831ULL: goto x86_l_41bf;
	case 16836ULL: goto x86_l_41c4;
	case 16843ULL: goto x86_l_41cb;
	case 16846ULL: goto x86_l_41ce;
	case 16853ULL: goto x86_l_41d5;
	case 16858ULL: goto x86_l_41da;
	case 16863ULL: goto x86_l_41df;
	case 16865ULL: goto x86_l_41e1;
	case 16869ULL: goto x86_l_41e5;
	case 16871ULL: goto x86_l_41e7;
	case 16873ULL: goto x86_l_41e9;
	case 16879ULL: goto x86_l_41ef;
	case 16882ULL: goto x86_l_41f2;
	case 16888ULL: goto x86_l_41f8;
	case 16894ULL: goto x86_l_41fe;
	case 16899ULL: goto x86_l_4203;
	case 16903ULL: goto x86_l_4207;
	case 16910ULL: goto x86_l_420e;
	case 16915ULL: goto x86_l_4213;
	case 16920ULL: goto x86_l_4218;
	case 16925ULL: goto x86_l_421d;
	case 16933ULL: goto x86_l_4225;
	case 16937ULL: goto x86_l_4229;
	case 16944ULL: goto x86_l_4230;
	case 16949ULL: goto x86_l_4235;
	case 16951ULL: goto x86_l_4237;
	case 16956ULL: goto x86_l_423c;
	case 16964ULL: goto x86_l_4244;
	case 16967ULL: goto x86_l_4247;
	case 16975ULL: goto x86_l_424f;
	case 16984ULL: goto x86_l_4258;
	case 16991ULL: goto x86_l_425f;
	case 16996ULL: goto x86_l_4264;
	case 17001ULL: goto x86_l_4269;
	case 17006ULL: goto x86_l_426e;
	case 17011ULL: goto x86_l_4273;
	case 17013ULL: goto x86_l_4275;
	case 17018ULL: goto x86_l_427a;
	case 17020ULL: goto x86_l_427c;
	case 17023ULL: goto x86_l_427f;
	case 17029ULL: goto x86_l_4285;
	case 17032ULL: goto x86_l_4288;
	case 17038ULL: goto x86_l_428e;
	case 17044ULL: goto x86_l_4294;
	case 17049ULL: goto x86_l_4299;
	case 17053ULL: goto x86_l_429d;
	case 17060ULL: goto x86_l_42a4;
	case 17065ULL: goto x86_l_42a9;
	case 17070ULL: goto x86_l_42ae;
	case 17077ULL: goto x86_l_42b5;
	case 17080ULL: goto x86_l_42b8;
	case 17087ULL: goto x86_l_42bf;
	case 17092ULL: goto x86_l_42c4;
	case 17097ULL: goto x86_l_42c9;
	case 17099ULL: goto x86_l_42cb;
	case 17103ULL: goto x86_l_42cf;
	case 17105ULL: goto x86_l_42d1;
	case 17107ULL: goto x86_l_42d3;
	case 17113ULL: goto x86_l_42d9;
	case 17116ULL: goto x86_l_42dc;
	case 17122ULL: goto x86_l_42e2;
	case 17128ULL: goto x86_l_42e8;
	case 17133ULL: goto x86_l_42ed;
	case 17137ULL: goto x86_l_42f1;
	case 17144ULL: goto x86_l_42f8;
	case 17149ULL: goto x86_l_42fd;
	case 17154ULL: goto x86_l_4302;
	case 17159ULL: goto x86_l_4307;
	case 17167ULL: goto x86_l_430f;
	case 17171ULL: goto x86_l_4313;
	case 17178ULL: goto x86_l_431a;
	case 17183ULL: goto x86_l_431f;
	case 17185ULL: goto x86_l_4321;
	case 17190ULL: goto x86_l_4326;
	case 17198ULL: goto x86_l_432e;
	case 17201ULL: goto x86_l_4331;
	case 17209ULL: goto x86_l_4339;
	case 17218ULL: goto x86_l_4342;
	case 17225ULL: goto x86_l_4349;
	case 17230ULL: goto x86_l_434e;
	case 17235ULL: goto x86_l_4353;
	case 17240ULL: goto x86_l_4358;
	case 17245ULL: goto x86_l_435d;
	case 17247ULL: goto x86_l_435f;
	case 17252ULL: goto x86_l_4364;
	case 17254ULL: goto x86_l_4366;
	case 17257ULL: goto x86_l_4369;
	case 17263ULL: goto x86_l_436f;
	case 17266ULL: goto x86_l_4372;
	case 17272ULL: goto x86_l_4378;
	case 17278ULL: goto x86_l_437e;
	case 17283ULL: goto x86_l_4383;
	case 17287ULL: goto x86_l_4387;
	case 17294ULL: goto x86_l_438e;
	case 17299ULL: goto x86_l_4393;
	case 17304ULL: goto x86_l_4398;
	case 17311ULL: goto x86_l_439f;
	case 17314ULL: goto x86_l_43a2;
	case 17321ULL: goto x86_l_43a9;
	case 17326ULL: goto x86_l_43ae;
	case 17331ULL: goto x86_l_43b3;
	case 17333ULL: goto x86_l_43b5;
	case 17337ULL: goto x86_l_43b9;
	case 17339ULL: goto x86_l_43bb;
	case 17341ULL: goto x86_l_43bd;
	case 17347ULL: goto x86_l_43c3;
	case 17350ULL: goto x86_l_43c6;
	case 17356ULL: goto x86_l_43cc;
	case 17362ULL: goto x86_l_43d2;
	case 17367ULL: goto x86_l_43d7;
	case 17371ULL: goto x86_l_43db;
	case 17378ULL: goto x86_l_43e2;
	case 17383ULL: goto x86_l_43e7;
	case 17388ULL: goto x86_l_43ec;
	case 17393ULL: goto x86_l_43f1;
	case 17401ULL: goto x86_l_43f9;
	case 17405ULL: goto x86_l_43fd;
	case 17412ULL: goto x86_l_4404;
	case 17417ULL: goto x86_l_4409;
	case 17419ULL: goto x86_l_440b;
	case 17424ULL: goto x86_l_4410;
	case 17432ULL: goto x86_l_4418;
	case 17435ULL: goto x86_l_441b;
	case 17443ULL: goto x86_l_4423;
	case 17452ULL: goto x86_l_442c;
	case 17459ULL: goto x86_l_4433;
	case 17464ULL: goto x86_l_4438;
	case 17469ULL: goto x86_l_443d;
	case 17474ULL: goto x86_l_4442;
	case 17479ULL: goto x86_l_4447;
	case 17481ULL: goto x86_l_4449;
	case 17486ULL: goto x86_l_444e;
	case 17488ULL: goto x86_l_4450;
	case 17491ULL: goto x86_l_4453;
	case 17497ULL: goto x86_l_4459;
	case 17500ULL: goto x86_l_445c;
	case 17506ULL: goto x86_l_4462;
	case 17512ULL: goto x86_l_4468;
	case 17517ULL: goto x86_l_446d;
	case 17521ULL: goto x86_l_4471;
	case 17528ULL: goto x86_l_4478;
	case 17533ULL: goto x86_l_447d;
	case 17538ULL: goto x86_l_4482;
	case 17545ULL: goto x86_l_4489;
	case 17548ULL: goto x86_l_448c;
	case 17555ULL: goto x86_l_4493;
	case 17560ULL: goto x86_l_4498;
	case 17565ULL: goto x86_l_449d;
	case 17567ULL: goto x86_l_449f;
	case 17571ULL: goto x86_l_44a3;
	case 17573ULL: goto x86_l_44a5;
	case 17575ULL: goto x86_l_44a7;
	case 17581ULL: goto x86_l_44ad;
	case 17584ULL: goto x86_l_44b0;
	case 17590ULL: goto x86_l_44b6;
	case 17596ULL: goto x86_l_44bc;
	case 17601ULL: goto x86_l_44c1;
	case 17605ULL: goto x86_l_44c5;
	case 17612ULL: goto x86_l_44cc;
	case 17617ULL: goto x86_l_44d1;
	case 17622ULL: goto x86_l_44d6;
	case 17627ULL: goto x86_l_44db;
	case 17635ULL: goto x86_l_44e3;
	case 17639ULL: goto x86_l_44e7;
	case 17646ULL: goto x86_l_44ee;
	case 17651ULL: goto x86_l_44f3;
	case 17653ULL: goto x86_l_44f5;
	case 17658ULL: goto x86_l_44fa;
	case 17666ULL: goto x86_l_4502;
	case 17669ULL: goto x86_l_4505;
	case 17677ULL: goto x86_l_450d;
	case 17686ULL: goto x86_l_4516;
	case 17693ULL: goto x86_l_451d;
	case 17698ULL: goto x86_l_4522;
	case 17703ULL: goto x86_l_4527;
	case 17708ULL: goto x86_l_452c;
	case 17713ULL: goto x86_l_4531;
	case 17715ULL: goto x86_l_4533;
	case 17720ULL: goto x86_l_4538;
	case 17722ULL: goto x86_l_453a;
	case 17725ULL: goto x86_l_453d;
	case 17731ULL: goto x86_l_4543;
	case 17734ULL: goto x86_l_4546;
	case 17740ULL: goto x86_l_454c;
	case 17746ULL: goto x86_l_4552;
	case 17751ULL: goto x86_l_4557;
	case 17755ULL: goto x86_l_455b;
	case 17762ULL: goto x86_l_4562;
	case 17767ULL: goto x86_l_4567;
	case 17772ULL: goto x86_l_456c;
	case 17779ULL: goto x86_l_4573;
	case 17782ULL: goto x86_l_4576;
	case 17789ULL: goto x86_l_457d;
	case 17794ULL: goto x86_l_4582;
	case 17799ULL: goto x86_l_4587;
	case 17801ULL: goto x86_l_4589;
	case 17805ULL: goto x86_l_458d;
	case 17807ULL: goto x86_l_458f;
	case 17809ULL: goto x86_l_4591;
	case 17815ULL: goto x86_l_4597;
	case 17818ULL: goto x86_l_459a;
	case 17824ULL: goto x86_l_45a0;
	case 17830ULL: goto x86_l_45a6;
	case 17835ULL: goto x86_l_45ab;
	case 17839ULL: goto x86_l_45af;
	case 17846ULL: goto x86_l_45b6;
	case 17851ULL: goto x86_l_45bb;
	case 17856ULL: goto x86_l_45c0;
	case 17861ULL: goto x86_l_45c5;
	case 17869ULL: goto x86_l_45cd;
	case 17873ULL: goto x86_l_45d1;
	case 17880ULL: goto x86_l_45d8;
	case 17885ULL: goto x86_l_45dd;
	case 17887ULL: goto x86_l_45df;
	case 17892ULL: goto x86_l_45e4;
	case 17900ULL: goto x86_l_45ec;
	case 17903ULL: goto x86_l_45ef;
	case 17911ULL: goto x86_l_45f7;
	case 17920ULL: goto x86_l_4600;
	case 17927ULL: goto x86_l_4607;
	case 17932ULL: goto x86_l_460c;
	case 17937ULL: goto x86_l_4611;
	case 17942ULL: goto x86_l_4616;
	case 17947ULL: goto x86_l_461b;
	case 17949ULL: goto x86_l_461d;
	case 17954ULL: goto x86_l_4622;
	case 17956ULL: goto x86_l_4624;
	case 17959ULL: goto x86_l_4627;
	case 17965ULL: goto x86_l_462d;
	case 17968ULL: goto x86_l_4630;
	case 17974ULL: goto x86_l_4636;
	case 17980ULL: goto x86_l_463c;
	case 17985ULL: goto x86_l_4641;
	case 17989ULL: goto x86_l_4645;
	case 17996ULL: goto x86_l_464c;
	case 18001ULL: goto x86_l_4651;
	case 18006ULL: goto x86_l_4656;
	case 18013ULL: goto x86_l_465d;
	case 18016ULL: goto x86_l_4660;
	case 18023ULL: goto x86_l_4667;
	case 18028ULL: goto x86_l_466c;
	case 18033ULL: goto x86_l_4671;
	case 18035ULL: goto x86_l_4673;
	case 18039ULL: goto x86_l_4677;
	case 18041ULL: goto x86_l_4679;
	case 18043ULL: goto x86_l_467b;
	case 18049ULL: goto x86_l_4681;
	case 18052ULL: goto x86_l_4684;
	case 18058ULL: goto x86_l_468a;
	case 18064ULL: goto x86_l_4690;
	case 18069ULL: goto x86_l_4695;
	case 18073ULL: goto x86_l_4699;
	case 18080ULL: goto x86_l_46a0;
	case 18085ULL: goto x86_l_46a5;
	case 18090ULL: goto x86_l_46aa;
	case 18095ULL: goto x86_l_46af;
	case 18103ULL: goto x86_l_46b7;
	case 18107ULL: goto x86_l_46bb;
	case 18114ULL: goto x86_l_46c2;
	case 18119ULL: goto x86_l_46c7;
	case 18121ULL: goto x86_l_46c9;
	case 18126ULL: goto x86_l_46ce;
	case 18134ULL: goto x86_l_46d6;
	case 18137ULL: goto x86_l_46d9;
	case 18145ULL: goto x86_l_46e1;
	case 18154ULL: goto x86_l_46ea;
	case 18161ULL: goto x86_l_46f1;
	case 18166ULL: goto x86_l_46f6;
	case 18171ULL: goto x86_l_46fb;
	case 18176ULL: goto x86_l_4700;
	case 18181ULL: goto x86_l_4705;
	case 18183ULL: goto x86_l_4707;
	case 18188ULL: goto x86_l_470c;
	case 18190ULL: goto x86_l_470e;
	case 18193ULL: goto x86_l_4711;
	case 18199ULL: goto x86_l_4717;
	case 18202ULL: goto x86_l_471a;
	case 18208ULL: goto x86_l_4720;
	case 18214ULL: goto x86_l_4726;
	case 18219ULL: goto x86_l_472b;
	case 18223ULL: goto x86_l_472f;
	case 18230ULL: goto x86_l_4736;
	case 18235ULL: goto x86_l_473b;
	case 18240ULL: goto x86_l_4740;
	case 18247ULL: goto x86_l_4747;
	case 18250ULL: goto x86_l_474a;
	case 18257ULL: goto x86_l_4751;
	case 18262ULL: goto x86_l_4756;
	case 18267ULL: goto x86_l_475b;
	case 18269ULL: goto x86_l_475d;
	case 18273ULL: goto x86_l_4761;
	case 18275ULL: goto x86_l_4763;
	case 18277ULL: goto x86_l_4765;
	case 18283ULL: goto x86_l_476b;
	case 18286ULL: goto x86_l_476e;
	case 18292ULL: goto x86_l_4774;
	case 18298ULL: goto x86_l_477a;
	case 18303ULL: goto x86_l_477f;
	case 18307ULL: goto x86_l_4783;
	case 18314ULL: goto x86_l_478a;
	case 18319ULL: goto x86_l_478f;
	case 18324ULL: goto x86_l_4794;
	case 18329ULL: goto x86_l_4799;
	case 18337ULL: goto x86_l_47a1;
	case 18341ULL: goto x86_l_47a5;
	case 18348ULL: goto x86_l_47ac;
	case 18353ULL: goto x86_l_47b1;
	case 18355ULL: goto x86_l_47b3;
	case 18360ULL: goto x86_l_47b8;
	case 18368ULL: goto x86_l_47c0;
	case 18371ULL: goto x86_l_47c3;
	case 18379ULL: goto x86_l_47cb;
	case 18388ULL: goto x86_l_47d4;
	case 18395ULL: goto x86_l_47db;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4067:
	/* 0x4067: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4069:
	/* 0x4069: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_406e:
	/* 0x406e: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4076:
	/* 0x4076: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4079:
	/* 0x4079: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4081:
	/* 0x4081: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_408a:
	/* 0x408a: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_408e:
	/* 0x408e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4093:
	/* 0x4093: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4098:
	/* 0x4098: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_409d:
	/* 0x409d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_40a2:
	/* 0x40a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40a4:
	/* 0x40a4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40a9:
	/* 0x40a9: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_40ab:
	/* 0x40ab: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_40ae:
	/* 0x40ae: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_40b4:
	/* 0x40b4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_40b7:
	/* 0x40b7: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_40bd:
	/* 0x40bd: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_40c3:
	/* 0x40c3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40c8:
	/* 0x40c8: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_40cc:
	/* 0x40cc: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_40d3:
	/* 0x40d3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_40d8:
	/* 0x40d8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_40dd:
	/* 0x40dd: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_40e4:
	/* 0x40e4: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_40e7:
	/* 0x40e7: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_40ee:
	/* 0x40ee: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40f3:
	/* 0x40f3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_40f8:
	/* 0x40f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40fa:
	/* 0x40fa: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_40fe:
	/* 0x40fe: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_4100:
	/* 0x4100: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4102:
	/* 0x4102: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_4108:
	/* 0x4108: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_410b:
	/* 0x410b: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4111:
	/* 0x4111: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4117:
	/* 0x4117: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_411c:
	/* 0x411c: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4120:
	/* 0x4120: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4127:
	/* 0x4127: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_412c:
	/* 0x412c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4131:
	/* 0x4131: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4136:
	/* 0x4136: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_413e:
	/* 0x413e: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4142:
	/* 0x4142: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4149:
	/* 0x4149: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_414e:
	/* 0x414e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4150:
	/* 0x4150: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4155:
	/* 0x4155: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_415d:
	/* 0x415d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4160:
	/* 0x4160: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4168:
	/* 0x4168: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4171:
	/* 0x4171: lea    rdx,[r13+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4175:
	/* 0x4175: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_417a:
	/* 0x417a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_417f:
	/* 0x417f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4184:
	/* 0x4184: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4189:
	/* 0x4189: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_418b:
	/* 0x418b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4190:
	/* 0x4190: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_4192:
	/* 0x4192: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4195:
	/* 0x4195: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_419b:
	/* 0x419b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_419e:
	/* 0x419e: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_41a4:
	/* 0x41a4: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_41aa:
	/* 0x41aa: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41af:
	/* 0x41af: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_41b3:
	/* 0x41b3: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_41ba:
	/* 0x41ba: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_41bf:
	/* 0x41bf: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_41c4:
	/* 0x41c4: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_41cb:
	/* 0x41cb: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_41ce:
	/* 0x41ce: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_41d5:
	/* 0x41d5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41da:
	/* 0x41da: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_41df:
	/* 0x41df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41e1:
	/* 0x41e1: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_41e5:
	/* 0x41e5: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_41e7:
	/* 0x41e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_41e9:
	/* 0x41e9: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_41ef:
	/* 0x41ef: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_41f2:
	/* 0x41f2: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_41f8:
	/* 0x41f8: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_41fe:
	/* 0x41fe: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4203:
	/* 0x4203: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4207:
	/* 0x4207: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_420e:
	/* 0x420e: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4213:
	/* 0x4213: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4218:
	/* 0x4218: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_421d:
	/* 0x421d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4225:
	/* 0x4225: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4229:
	/* 0x4229: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4230:
	/* 0x4230: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4235:
	/* 0x4235: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4237:
	/* 0x4237: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_423c:
	/* 0x423c: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4244:
	/* 0x4244: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4247:
	/* 0x4247: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_424f:
	/* 0x424f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4258:
	/* 0x4258: lea    rdx,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_425f:
	/* 0x425f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4264:
	/* 0x4264: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4269:
	/* 0x4269: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_426e:
	/* 0x426e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4273:
	/* 0x4273: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4275:
	/* 0x4275: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_427a:
	/* 0x427a: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_427c:
	/* 0x427c: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_427f:
	/* 0x427f: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_4285:
	/* 0x4285: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4288:
	/* 0x4288: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_428e:
	/* 0x428e: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4294:
	/* 0x4294: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4299:
	/* 0x4299: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_429d:
	/* 0x429d: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_42a4:
	/* 0x42a4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_42a9:
	/* 0x42a9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_42ae:
	/* 0x42ae: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_42b5:
	/* 0x42b5: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_42b8:
	/* 0x42b8: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_42bf:
	/* 0x42bf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_42c4:
	/* 0x42c4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_42c9:
	/* 0x42c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42cb:
	/* 0x42cb: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_42cf:
	/* 0x42cf: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_42d1:
	/* 0x42d1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42d3:
	/* 0x42d3: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_42d9:
	/* 0x42d9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_42dc:
	/* 0x42dc: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_42e2:
	/* 0x42e2: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_42e8:
	/* 0x42e8: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42ed:
	/* 0x42ed: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_42f1:
	/* 0x42f1: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_42f8:
	/* 0x42f8: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_42fd:
	/* 0x42fd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4302:
	/* 0x4302: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4307:
	/* 0x4307: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_430f:
	/* 0x430f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4313:
	/* 0x4313: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_431a:
	/* 0x431a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_431f:
	/* 0x431f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4321:
	/* 0x4321: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4326:
	/* 0x4326: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_432e:
	/* 0x432e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4331:
	/* 0x4331: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4339:
	/* 0x4339: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4342:
	/* 0x4342: lea    rdx,[r13+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_4349:
	/* 0x4349: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_434e:
	/* 0x434e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4353:
	/* 0x4353: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4358:
	/* 0x4358: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_435d:
	/* 0x435d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_435f:
	/* 0x435f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4364:
	/* 0x4364: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_4366:
	/* 0x4366: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4369:
	/* 0x4369: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_436f:
	/* 0x436f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4372:
	/* 0x4372: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4378:
	/* 0x4378: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_437e:
	/* 0x437e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4383:
	/* 0x4383: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4387:
	/* 0x4387: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_438e:
	/* 0x438e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4393:
	/* 0x4393: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4398:
	/* 0x4398: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_439f:
	/* 0x439f: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_43a2:
	/* 0x43a2: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_43a9:
	/* 0x43a9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43ae:
	/* 0x43ae: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_43b3:
	/* 0x43b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43b5:
	/* 0x43b5: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_43b9:
	/* 0x43b9: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_43bb:
	/* 0x43bb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_43bd:
	/* 0x43bd: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_43c3:
	/* 0x43c3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_43c6:
	/* 0x43c6: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_43cc:
	/* 0x43cc: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_43d2:
	/* 0x43d2: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43d7:
	/* 0x43d7: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_43db:
	/* 0x43db: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_43e2:
	/* 0x43e2: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_43e7:
	/* 0x43e7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_43ec:
	/* 0x43ec: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_43f1:
	/* 0x43f1: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_43f9:
	/* 0x43f9: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_43fd:
	/* 0x43fd: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4404:
	/* 0x4404: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4409:
	/* 0x4409: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_440b:
	/* 0x440b: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4410:
	/* 0x4410: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4418:
	/* 0x4418: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_441b:
	/* 0x441b: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4423:
	/* 0x4423: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_442c:
	/* 0x442c: lea    rdx,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4433:
	/* 0x4433: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4438:
	/* 0x4438: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_443d:
	/* 0x443d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4442:
	/* 0x4442: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4447:
	/* 0x4447: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4449:
	/* 0x4449: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_444e:
	/* 0x444e: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_4450:
	/* 0x4450: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4453:
	/* 0x4453: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_4459:
	/* 0x4459: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_445c:
	/* 0x445c: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4462:
	/* 0x4462: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4468:
	/* 0x4468: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_446d:
	/* 0x446d: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4471:
	/* 0x4471: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4478:
	/* 0x4478: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_447d:
	/* 0x447d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4482:
	/* 0x4482: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4489:
	/* 0x4489: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_448c:
	/* 0x448c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4493:
	/* 0x4493: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4498:
	/* 0x4498: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_449d:
	/* 0x449d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_449f:
	/* 0x449f: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_44a3:
	/* 0x44a3: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_44a5:
	/* 0x44a5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_44a7:
	/* 0x44a7: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_44ad:
	/* 0x44ad: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_44b0:
	/* 0x44b0: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_44b6:
	/* 0x44b6: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_44bc:
	/* 0x44bc: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44c1:
	/* 0x44c1: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_44c5:
	/* 0x44c5: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_44cc:
	/* 0x44cc: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_44d1:
	/* 0x44d1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_44d6:
	/* 0x44d6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_44db:
	/* 0x44db: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_44e3:
	/* 0x44e3: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_44e7:
	/* 0x44e7: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_44ee:
	/* 0x44ee: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_44f3:
	/* 0x44f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44f5:
	/* 0x44f5: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_44fa:
	/* 0x44fa: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4502:
	/* 0x4502: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4505:
	/* 0x4505: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_450d:
	/* 0x450d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4516:
	/* 0x4516: lea    rdx,[r13+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_451d:
	/* 0x451d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4522:
	/* 0x4522: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4527:
	/* 0x4527: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_452c:
	/* 0x452c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4531:
	/* 0x4531: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4533:
	/* 0x4533: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4538:
	/* 0x4538: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_453a:
	/* 0x453a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_453d:
	/* 0x453d: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_4543:
	/* 0x4543: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4546:
	/* 0x4546: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_454c:
	/* 0x454c: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4552:
	/* 0x4552: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4557:
	/* 0x4557: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_455b:
	/* 0x455b: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4562:
	/* 0x4562: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4567:
	/* 0x4567: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_456c:
	/* 0x456c: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4573:
	/* 0x4573: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4576:
	/* 0x4576: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_457d:
	/* 0x457d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4582:
	/* 0x4582: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4587:
	/* 0x4587: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4589:
	/* 0x4589: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_458d:
	/* 0x458d: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_458f:
	/* 0x458f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4591:
	/* 0x4591: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_4597:
	/* 0x4597: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_459a:
	/* 0x459a: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_45a0:
	/* 0x45a0: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_45a6:
	/* 0x45a6: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45ab:
	/* 0x45ab: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_45af:
	/* 0x45af: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_45b6:
	/* 0x45b6: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_45bb:
	/* 0x45bb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_45c0:
	/* 0x45c0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_45c5:
	/* 0x45c5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_45cd:
	/* 0x45cd: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_45d1:
	/* 0x45d1: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_45d8:
	/* 0x45d8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_45dd:
	/* 0x45dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45df:
	/* 0x45df: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_45e4:
	/* 0x45e4: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_45ec:
	/* 0x45ec: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_45ef:
	/* 0x45ef: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_45f7:
	/* 0x45f7: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4600:
	/* 0x4600: lea    rdx,[r13+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4607:
	/* 0x4607: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_460c:
	/* 0x460c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4611:
	/* 0x4611: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4616:
	/* 0x4616: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_461b:
	/* 0x461b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_461d:
	/* 0x461d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4622:
	/* 0x4622: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_4624:
	/* 0x4624: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4627:
	/* 0x4627: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_462d:
	/* 0x462d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4630:
	/* 0x4630: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4636:
	/* 0x4636: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_463c:
	/* 0x463c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4641:
	/* 0x4641: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4645:
	/* 0x4645: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_464c:
	/* 0x464c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4651:
	/* 0x4651: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4656:
	/* 0x4656: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_465d:
	/* 0x465d: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4660:
	/* 0x4660: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4667:
	/* 0x4667: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_466c:
	/* 0x466c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4671:
	/* 0x4671: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4673:
	/* 0x4673: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4677:
	/* 0x4677: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_4679:
	/* 0x4679: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_467b:
	/* 0x467b: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_4681:
	/* 0x4681: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4684:
	/* 0x4684: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_468a:
	/* 0x468a: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4690:
	/* 0x4690: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4695:
	/* 0x4695: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4699:
	/* 0x4699: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_46a0:
	/* 0x46a0: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_46a5:
	/* 0x46a5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_46aa:
	/* 0x46aa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_46af:
	/* 0x46af: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_46b7:
	/* 0x46b7: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_46bb:
	/* 0x46bb: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_46c2:
	/* 0x46c2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_46c7:
	/* 0x46c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46c9:
	/* 0x46c9: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_46ce:
	/* 0x46ce: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_46d6:
	/* 0x46d6: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_46d9:
	/* 0x46d9: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_46e1:
	/* 0x46e1: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_46ea:
	/* 0x46ea: lea    rdx,[r13+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_46f1:
	/* 0x46f1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46f6:
	/* 0x46f6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_46fb:
	/* 0x46fb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4700:
	/* 0x4700: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4705:
	/* 0x4705: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4707:
	/* 0x4707: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_470c:
	/* 0x470c: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_470e:
	/* 0x470e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4711:
	/* 0x4711: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_4717:
	/* 0x4717: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_471a:
	/* 0x471a: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4720:
	/* 0x4720: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4726:
	/* 0x4726: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_472b:
	/* 0x472b: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_472f:
	/* 0x472f: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4736:
	/* 0x4736: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_473b:
	/* 0x473b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4740:
	/* 0x4740: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4747:
	/* 0x4747: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_474a:
	/* 0x474a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4751:
	/* 0x4751: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4756:
	/* 0x4756: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_475b:
	/* 0x475b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_475d:
	/* 0x475d: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4761:
	/* 0x4761: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_4763:
	/* 0x4763: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4765:
	/* 0x4765: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_476b:
	/* 0x476b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_476e:
	/* 0x476e: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4774:
	/* 0x4774: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_477a:
	/* 0x477a: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_477f:
	/* 0x477f: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4783:
	/* 0x4783: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_478a:
	/* 0x478a: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_478f:
	/* 0x478f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4794:
	/* 0x4794: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4799:
	/* 0x4799: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_47a1:
	/* 0x47a1: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_47a5:
	/* 0x47a5: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_47ac:
	/* 0x47ac: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_47b1:
	/* 0x47b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47b3:
	/* 0x47b3: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_47b8:
	/* 0x47b8: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_47c0:
	/* 0x47c0: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_47c3:
	/* 0x47c3: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_47cb:
	/* 0x47cb: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_47d4:
	/* 0x47d4: lea    rdx,[r13+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_47db:
	/* 0x47db: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 18400ULL;
}

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 18400ULL: goto x86_l_47e0;
	case 18405ULL: goto x86_l_47e5;
	case 18410ULL: goto x86_l_47ea;
	case 18415ULL: goto x86_l_47ef;
	case 18417ULL: goto x86_l_47f1;
	case 18422ULL: goto x86_l_47f6;
	case 18424ULL: goto x86_l_47f8;
	case 18427ULL: goto x86_l_47fb;
	case 18433ULL: goto x86_l_4801;
	case 18436ULL: goto x86_l_4804;
	case 18442ULL: goto x86_l_480a;
	case 18448ULL: goto x86_l_4810;
	case 18453ULL: goto x86_l_4815;
	case 18457ULL: goto x86_l_4819;
	case 18464ULL: goto x86_l_4820;
	case 18469ULL: goto x86_l_4825;
	case 18474ULL: goto x86_l_482a;
	case 18481ULL: goto x86_l_4831;
	case 18484ULL: goto x86_l_4834;
	case 18491ULL: goto x86_l_483b;
	case 18496ULL: goto x86_l_4840;
	case 18501ULL: goto x86_l_4845;
	case 18503ULL: goto x86_l_4847;
	case 18507ULL: goto x86_l_484b;
	case 18509ULL: goto x86_l_484d;
	case 18511ULL: goto x86_l_484f;
	case 18517ULL: goto x86_l_4855;
	case 18520ULL: goto x86_l_4858;
	case 18526ULL: goto x86_l_485e;
	case 18532ULL: goto x86_l_4864;
	case 18537ULL: goto x86_l_4869;
	case 18541ULL: goto x86_l_486d;
	case 18548ULL: goto x86_l_4874;
	case 18553ULL: goto x86_l_4879;
	case 18558ULL: goto x86_l_487e;
	case 18563ULL: goto x86_l_4883;
	case 18571ULL: goto x86_l_488b;
	case 18575ULL: goto x86_l_488f;
	case 18582ULL: goto x86_l_4896;
	case 18587ULL: goto x86_l_489b;
	case 18589ULL: goto x86_l_489d;
	case 18594ULL: goto x86_l_48a2;
	case 18602ULL: goto x86_l_48aa;
	case 18605ULL: goto x86_l_48ad;
	case 18613ULL: goto x86_l_48b5;
	case 18622ULL: goto x86_l_48be;
	case 18629ULL: goto x86_l_48c5;
	case 18634ULL: goto x86_l_48ca;
	case 18639ULL: goto x86_l_48cf;
	case 18644ULL: goto x86_l_48d4;
	case 18649ULL: goto x86_l_48d9;
	case 18651ULL: goto x86_l_48db;
	case 18656ULL: goto x86_l_48e0;
	case 18658ULL: goto x86_l_48e2;
	case 18661ULL: goto x86_l_48e5;
	case 18667ULL: goto x86_l_48eb;
	case 18670ULL: goto x86_l_48ee;
	case 18676ULL: goto x86_l_48f4;
	case 18682ULL: goto x86_l_48fa;
	case 18687ULL: goto x86_l_48ff;
	case 18691ULL: goto x86_l_4903;
	case 18698ULL: goto x86_l_490a;
	case 18703ULL: goto x86_l_490f;
	case 18708ULL: goto x86_l_4914;
	case 18715ULL: goto x86_l_491b;
	case 18718ULL: goto x86_l_491e;
	case 18725ULL: goto x86_l_4925;
	case 18730ULL: goto x86_l_492a;
	case 18735ULL: goto x86_l_492f;
	case 18737ULL: goto x86_l_4931;
	case 18741ULL: goto x86_l_4935;
	case 18743ULL: goto x86_l_4937;
	case 18745ULL: goto x86_l_4939;
	case 18751ULL: goto x86_l_493f;
	case 18754ULL: goto x86_l_4942;
	case 18760ULL: goto x86_l_4948;
	case 18766ULL: goto x86_l_494e;
	case 18771ULL: goto x86_l_4953;
	case 18775ULL: goto x86_l_4957;
	case 18782ULL: goto x86_l_495e;
	case 18787ULL: goto x86_l_4963;
	case 18792ULL: goto x86_l_4968;
	case 18797ULL: goto x86_l_496d;
	case 18805ULL: goto x86_l_4975;
	case 18809ULL: goto x86_l_4979;
	case 18816ULL: goto x86_l_4980;
	case 18821ULL: goto x86_l_4985;
	case 18823ULL: goto x86_l_4987;
	case 18828ULL: goto x86_l_498c;
	case 18836ULL: goto x86_l_4994;
	case 18839ULL: goto x86_l_4997;
	case 18847ULL: goto x86_l_499f;
	case 18856ULL: goto x86_l_49a8;
	case 18863ULL: goto x86_l_49af;
	case 18868ULL: goto x86_l_49b4;
	case 18873ULL: goto x86_l_49b9;
	case 18878ULL: goto x86_l_49be;
	case 18883ULL: goto x86_l_49c3;
	case 18885ULL: goto x86_l_49c5;
	case 18890ULL: goto x86_l_49ca;
	case 18892ULL: goto x86_l_49cc;
	case 18895ULL: goto x86_l_49cf;
	case 18901ULL: goto x86_l_49d5;
	case 18904ULL: goto x86_l_49d8;
	case 18910ULL: goto x86_l_49de;
	case 18916ULL: goto x86_l_49e4;
	case 18921ULL: goto x86_l_49e9;
	case 18925ULL: goto x86_l_49ed;
	case 18932ULL: goto x86_l_49f4;
	case 18937ULL: goto x86_l_49f9;
	case 18942ULL: goto x86_l_49fe;
	case 18949ULL: goto x86_l_4a05;
	case 18952ULL: goto x86_l_4a08;
	case 18959ULL: goto x86_l_4a0f;
	case 18964ULL: goto x86_l_4a14;
	case 18969ULL: goto x86_l_4a19;
	case 18971ULL: goto x86_l_4a1b;
	case 18975ULL: goto x86_l_4a1f;
	case 18977ULL: goto x86_l_4a21;
	case 18979ULL: goto x86_l_4a23;
	case 18985ULL: goto x86_l_4a29;
	case 18988ULL: goto x86_l_4a2c;
	case 18994ULL: goto x86_l_4a32;
	case 19000ULL: goto x86_l_4a38;
	case 19005ULL: goto x86_l_4a3d;
	case 19009ULL: goto x86_l_4a41;
	case 19016ULL: goto x86_l_4a48;
	case 19021ULL: goto x86_l_4a4d;
	case 19026ULL: goto x86_l_4a52;
	case 19031ULL: goto x86_l_4a57;
	case 19039ULL: goto x86_l_4a5f;
	case 19043ULL: goto x86_l_4a63;
	case 19050ULL: goto x86_l_4a6a;
	case 19055ULL: goto x86_l_4a6f;
	case 19057ULL: goto x86_l_4a71;
	case 19062ULL: goto x86_l_4a76;
	case 19070ULL: goto x86_l_4a7e;
	case 19073ULL: goto x86_l_4a81;
	case 19081ULL: goto x86_l_4a89;
	case 19090ULL: goto x86_l_4a92;
	case 19097ULL: goto x86_l_4a99;
	case 19102ULL: goto x86_l_4a9e;
	case 19107ULL: goto x86_l_4aa3;
	case 19112ULL: goto x86_l_4aa8;
	case 19117ULL: goto x86_l_4aad;
	case 19119ULL: goto x86_l_4aaf;
	case 19124ULL: goto x86_l_4ab4;
	case 19126ULL: goto x86_l_4ab6;
	case 19129ULL: goto x86_l_4ab9;
	case 19135ULL: goto x86_l_4abf;
	case 19138ULL: goto x86_l_4ac2;
	case 19144ULL: goto x86_l_4ac8;
	case 19150ULL: goto x86_l_4ace;
	case 19155ULL: goto x86_l_4ad3;
	case 19159ULL: goto x86_l_4ad7;
	case 19166ULL: goto x86_l_4ade;
	case 19171ULL: goto x86_l_4ae3;
	case 19176ULL: goto x86_l_4ae8;
	case 19183ULL: goto x86_l_4aef;
	case 19186ULL: goto x86_l_4af2;
	case 19193ULL: goto x86_l_4af9;
	case 19198ULL: goto x86_l_4afe;
	case 19203ULL: goto x86_l_4b03;
	case 19205ULL: goto x86_l_4b05;
	case 19209ULL: goto x86_l_4b09;
	case 19211ULL: goto x86_l_4b0b;
	case 19213ULL: goto x86_l_4b0d;
	case 19219ULL: goto x86_l_4b13;
	case 19222ULL: goto x86_l_4b16;
	case 19228ULL: goto x86_l_4b1c;
	case 19234ULL: goto x86_l_4b22;
	case 19239ULL: goto x86_l_4b27;
	case 19243ULL: goto x86_l_4b2b;
	case 19250ULL: goto x86_l_4b32;
	case 19255ULL: goto x86_l_4b37;
	case 19260ULL: goto x86_l_4b3c;
	case 19265ULL: goto x86_l_4b41;
	case 19273ULL: goto x86_l_4b49;
	case 19277ULL: goto x86_l_4b4d;
	case 19284ULL: goto x86_l_4b54;
	case 19289ULL: goto x86_l_4b59;
	case 19291ULL: goto x86_l_4b5b;
	case 19296ULL: goto x86_l_4b60;
	case 19304ULL: goto x86_l_4b68;
	case 19307ULL: goto x86_l_4b6b;
	case 19315ULL: goto x86_l_4b73;
	case 19324ULL: goto x86_l_4b7c;
	case 19331ULL: goto x86_l_4b83;
	case 19336ULL: goto x86_l_4b88;
	case 19341ULL: goto x86_l_4b8d;
	case 19346ULL: goto x86_l_4b92;
	case 19351ULL: goto x86_l_4b97;
	case 19353ULL: goto x86_l_4b99;
	case 19358ULL: goto x86_l_4b9e;
	case 19360ULL: goto x86_l_4ba0;
	case 19363ULL: goto x86_l_4ba3;
	case 19369ULL: goto x86_l_4ba9;
	case 19372ULL: goto x86_l_4bac;
	case 19378ULL: goto x86_l_4bb2;
	case 19384ULL: goto x86_l_4bb8;
	case 19389ULL: goto x86_l_4bbd;
	case 19393ULL: goto x86_l_4bc1;
	case 19400ULL: goto x86_l_4bc8;
	case 19405ULL: goto x86_l_4bcd;
	case 19410ULL: goto x86_l_4bd2;
	case 19417ULL: goto x86_l_4bd9;
	case 19420ULL: goto x86_l_4bdc;
	case 19427ULL: goto x86_l_4be3;
	case 19432ULL: goto x86_l_4be8;
	case 19437ULL: goto x86_l_4bed;
	case 19439ULL: goto x86_l_4bef;
	case 19443ULL: goto x86_l_4bf3;
	case 19445ULL: goto x86_l_4bf5;
	case 19447ULL: goto x86_l_4bf7;
	case 19453ULL: goto x86_l_4bfd;
	case 19456ULL: goto x86_l_4c00;
	case 19462ULL: goto x86_l_4c06;
	case 19468ULL: goto x86_l_4c0c;
	case 19473ULL: goto x86_l_4c11;
	case 19477ULL: goto x86_l_4c15;
	case 19484ULL: goto x86_l_4c1c;
	case 19489ULL: goto x86_l_4c21;
	case 19494ULL: goto x86_l_4c26;
	case 19499ULL: goto x86_l_4c2b;
	case 19507ULL: goto x86_l_4c33;
	case 19511ULL: goto x86_l_4c37;
	case 19518ULL: goto x86_l_4c3e;
	case 19523ULL: goto x86_l_4c43;
	case 19525ULL: goto x86_l_4c45;
	case 19530ULL: goto x86_l_4c4a;
	case 19538ULL: goto x86_l_4c52;
	case 19541ULL: goto x86_l_4c55;
	case 19549ULL: goto x86_l_4c5d;
	case 19558ULL: goto x86_l_4c66;
	case 19565ULL: goto x86_l_4c6d;
	case 19570ULL: goto x86_l_4c72;
	case 19575ULL: goto x86_l_4c77;
	case 19580ULL: goto x86_l_4c7c;
	case 19585ULL: goto x86_l_4c81;
	case 19587ULL: goto x86_l_4c83;
	case 19592ULL: goto x86_l_4c88;
	case 19594ULL: goto x86_l_4c8a;
	case 19597ULL: goto x86_l_4c8d;
	case 19603ULL: goto x86_l_4c93;
	case 19606ULL: goto x86_l_4c96;
	case 19612ULL: goto x86_l_4c9c;
	case 19618ULL: goto x86_l_4ca2;
	case 19623ULL: goto x86_l_4ca7;
	case 19627ULL: goto x86_l_4cab;
	case 19634ULL: goto x86_l_4cb2;
	case 19639ULL: goto x86_l_4cb7;
	case 19644ULL: goto x86_l_4cbc;
	case 19651ULL: goto x86_l_4cc3;
	case 19654ULL: goto x86_l_4cc6;
	case 19661ULL: goto x86_l_4ccd;
	case 19666ULL: goto x86_l_4cd2;
	case 19671ULL: goto x86_l_4cd7;
	case 19673ULL: goto x86_l_4cd9;
	case 19677ULL: goto x86_l_4cdd;
	case 19679ULL: goto x86_l_4cdf;
	case 19681ULL: goto x86_l_4ce1;
	case 19687ULL: goto x86_l_4ce7;
	case 19690ULL: goto x86_l_4cea;
	case 19696ULL: goto x86_l_4cf0;
	case 19702ULL: goto x86_l_4cf6;
	case 19707ULL: goto x86_l_4cfb;
	case 19711ULL: goto x86_l_4cff;
	case 19718ULL: goto x86_l_4d06;
	case 19723ULL: goto x86_l_4d0b;
	case 19728ULL: goto x86_l_4d10;
	case 19733ULL: goto x86_l_4d15;
	case 19741ULL: goto x86_l_4d1d;
	case 19745ULL: goto x86_l_4d21;
	case 19752ULL: goto x86_l_4d28;
	case 19757ULL: goto x86_l_4d2d;
	case 19759ULL: goto x86_l_4d2f;
	case 19764ULL: goto x86_l_4d34;
	case 19772ULL: goto x86_l_4d3c;
	case 19775ULL: goto x86_l_4d3f;
	case 19783ULL: goto x86_l_4d47;
	case 19792ULL: goto x86_l_4d50;
	case 19799ULL: goto x86_l_4d57;
	case 19804ULL: goto x86_l_4d5c;
	case 19809ULL: goto x86_l_4d61;
	case 19814ULL: goto x86_l_4d66;
	case 19819ULL: goto x86_l_4d6b;
	case 19821ULL: goto x86_l_4d6d;
	case 19826ULL: goto x86_l_4d72;
	case 19828ULL: goto x86_l_4d74;
	case 19831ULL: goto x86_l_4d77;
	case 19837ULL: goto x86_l_4d7d;
	case 19840ULL: goto x86_l_4d80;
	case 19846ULL: goto x86_l_4d86;
	case 19852ULL: goto x86_l_4d8c;
	case 19857ULL: goto x86_l_4d91;
	case 19861ULL: goto x86_l_4d95;
	case 19868ULL: goto x86_l_4d9c;
	case 19873ULL: goto x86_l_4da1;
	case 19878ULL: goto x86_l_4da6;
	case 19885ULL: goto x86_l_4dad;
	case 19888ULL: goto x86_l_4db0;
	case 19895ULL: goto x86_l_4db7;
	case 19900ULL: goto x86_l_4dbc;
	case 19905ULL: goto x86_l_4dc1;
	case 19907ULL: goto x86_l_4dc3;
	case 19911ULL: goto x86_l_4dc7;
	case 19913ULL: goto x86_l_4dc9;
	case 19915ULL: goto x86_l_4dcb;
	case 19921ULL: goto x86_l_4dd1;
	case 19924ULL: goto x86_l_4dd4;
	case 19930ULL: goto x86_l_4dda;
	case 19936ULL: goto x86_l_4de0;
	case 19941ULL: goto x86_l_4de5;
	case 19945ULL: goto x86_l_4de9;
	case 19952ULL: goto x86_l_4df0;
	case 19957ULL: goto x86_l_4df5;
	case 19962ULL: goto x86_l_4dfa;
	case 19967ULL: goto x86_l_4dff;
	case 19975ULL: goto x86_l_4e07;
	case 19979ULL: goto x86_l_4e0b;
	case 19986ULL: goto x86_l_4e12;
	case 19991ULL: goto x86_l_4e17;
	case 19993ULL: goto x86_l_4e19;
	case 19998ULL: goto x86_l_4e1e;
	case 20006ULL: goto x86_l_4e26;
	case 20009ULL: goto x86_l_4e29;
	case 20017ULL: goto x86_l_4e31;
	case 20026ULL: goto x86_l_4e3a;
	case 20033ULL: goto x86_l_4e41;
	case 20038ULL: goto x86_l_4e46;
	case 20043ULL: goto x86_l_4e4b;
	case 20048ULL: goto x86_l_4e50;
	case 20053ULL: goto x86_l_4e55;
	case 20055ULL: goto x86_l_4e57;
	case 20060ULL: goto x86_l_4e5c;
	case 20062ULL: goto x86_l_4e5e;
	case 20065ULL: goto x86_l_4e61;
	case 20071ULL: goto x86_l_4e67;
	case 20074ULL: goto x86_l_4e6a;
	case 20080ULL: goto x86_l_4e70;
	case 20086ULL: goto x86_l_4e76;
	case 20091ULL: goto x86_l_4e7b;
	case 20095ULL: goto x86_l_4e7f;
	case 20102ULL: goto x86_l_4e86;
	case 20107ULL: goto x86_l_4e8b;
	case 20112ULL: goto x86_l_4e90;
	case 20119ULL: goto x86_l_4e97;
	case 20122ULL: goto x86_l_4e9a;
	case 20129ULL: goto x86_l_4ea1;
	case 20134ULL: goto x86_l_4ea6;
	case 20139ULL: goto x86_l_4eab;
	case 20141ULL: goto x86_l_4ead;
	case 20145ULL: goto x86_l_4eb1;
	case 20147ULL: goto x86_l_4eb3;
	case 20149ULL: goto x86_l_4eb5;
	case 20155ULL: goto x86_l_4ebb;
	case 20158ULL: goto x86_l_4ebe;
	case 20164ULL: goto x86_l_4ec4;
	case 20170ULL: goto x86_l_4eca;
	case 20175ULL: goto x86_l_4ecf;
	case 20179ULL: goto x86_l_4ed3;
	case 20186ULL: goto x86_l_4eda;
	case 20191ULL: goto x86_l_4edf;
	case 20196ULL: goto x86_l_4ee4;
	case 20201ULL: goto x86_l_4ee9;
	case 20209ULL: goto x86_l_4ef1;
	case 20213ULL: goto x86_l_4ef5;
	case 20220ULL: goto x86_l_4efc;
	case 20225ULL: goto x86_l_4f01;
	case 20227ULL: goto x86_l_4f03;
	case 20232ULL: goto x86_l_4f08;
	case 20240ULL: goto x86_l_4f10;
	case 20243ULL: goto x86_l_4f13;
	case 20251ULL: goto x86_l_4f1b;
	case 20260ULL: goto x86_l_4f24;
	case 20267ULL: goto x86_l_4f2b;
	case 20272ULL: goto x86_l_4f30;
	case 20277ULL: goto x86_l_4f35;
	case 20282ULL: goto x86_l_4f3a;
	case 20287ULL: goto x86_l_4f3f;
	case 20289ULL: goto x86_l_4f41;
	case 20294ULL: goto x86_l_4f46;
	case 20296ULL: goto x86_l_4f48;
	case 20299ULL: goto x86_l_4f4b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_47e0:
	/* 0x47e0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_47e5:
	/* 0x47e5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_47ea:
	/* 0x47ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47ef:
	/* 0x47ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47f1:
	/* 0x47f1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47f6:
	/* 0x47f6: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_47f8:
	/* 0x47f8: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_47fb:
	/* 0x47fb: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_4801:
	/* 0x4801: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4804:
	/* 0x4804: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_480a:
	/* 0x480a: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4810:
	/* 0x4810: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4815:
	/* 0x4815: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4819:
	/* 0x4819: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4820:
	/* 0x4820: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4825:
	/* 0x4825: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_482a:
	/* 0x482a: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4831:
	/* 0x4831: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4834:
	/* 0x4834: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_483b:
	/* 0x483b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4840:
	/* 0x4840: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4845:
	/* 0x4845: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4847:
	/* 0x4847: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_484b:
	/* 0x484b: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_484d:
	/* 0x484d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_484f:
	/* 0x484f: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_4855:
	/* 0x4855: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4858:
	/* 0x4858: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_485e:
	/* 0x485e: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4864:
	/* 0x4864: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4869:
	/* 0x4869: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_486d:
	/* 0x486d: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4874:
	/* 0x4874: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4879:
	/* 0x4879: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_487e:
	/* 0x487e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4883:
	/* 0x4883: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_488b:
	/* 0x488b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_488f:
	/* 0x488f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4896:
	/* 0x4896: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_489b:
	/* 0x489b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_489d:
	/* 0x489d: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_48a2:
	/* 0x48a2: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_48aa:
	/* 0x48aa: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_48ad:
	/* 0x48ad: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_48b5:
	/* 0x48b5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_48be:
	/* 0x48be: lea    rdx,[r13+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_48c5:
	/* 0x48c5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48ca:
	/* 0x48ca: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_48cf:
	/* 0x48cf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_48d4:
	/* 0x48d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48d9:
	/* 0x48d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48db:
	/* 0x48db: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48e0:
	/* 0x48e0: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_48e2:
	/* 0x48e2: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_48e5:
	/* 0x48e5: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_48eb:
	/* 0x48eb: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_48ee:
	/* 0x48ee: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_48f4:
	/* 0x48f4: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_48fa:
	/* 0x48fa: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48ff:
	/* 0x48ff: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4903:
	/* 0x4903: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_490a:
	/* 0x490a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_490f:
	/* 0x490f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4914:
	/* 0x4914: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_491b:
	/* 0x491b: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_491e:
	/* 0x491e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4925:
	/* 0x4925: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_492a:
	/* 0x492a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_492f:
	/* 0x492f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4931:
	/* 0x4931: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4935:
	/* 0x4935: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_4937:
	/* 0x4937: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4939:
	/* 0x4939: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_493f:
	/* 0x493f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4942:
	/* 0x4942: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4948:
	/* 0x4948: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_494e:
	/* 0x494e: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4953:
	/* 0x4953: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4957:
	/* 0x4957: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_495e:
	/* 0x495e: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4963:
	/* 0x4963: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4968:
	/* 0x4968: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_496d:
	/* 0x496d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4975:
	/* 0x4975: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4979:
	/* 0x4979: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4980:
	/* 0x4980: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4985:
	/* 0x4985: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4987:
	/* 0x4987: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_498c:
	/* 0x498c: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4994:
	/* 0x4994: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4997:
	/* 0x4997: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_499f:
	/* 0x499f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_49a8:
	/* 0x49a8: lea    rdx,[r13+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_49af:
	/* 0x49af: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_49b4:
	/* 0x49b4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_49b9:
	/* 0x49b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_49be:
	/* 0x49be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49c3:
	/* 0x49c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49c5:
	/* 0x49c5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_49ca:
	/* 0x49ca: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_49cc:
	/* 0x49cc: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_49cf:
	/* 0x49cf: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_49d5:
	/* 0x49d5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_49d8:
	/* 0x49d8: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_49de:
	/* 0x49de: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_49e4:
	/* 0x49e4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49e9:
	/* 0x49e9: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_49ed:
	/* 0x49ed: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_49f4:
	/* 0x49f4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_49f9:
	/* 0x49f9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_49fe:
	/* 0x49fe: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4a05:
	/* 0x4a05: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4a08:
	/* 0x4a08: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4a0f:
	/* 0x4a0f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a14:
	/* 0x4a14: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4a19:
	/* 0x4a19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a1b:
	/* 0x4a1b: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4a1f:
	/* 0x4a1f: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_4a21:
	/* 0x4a21: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a23:
	/* 0x4a23: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_4a29:
	/* 0x4a29: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4a2c:
	/* 0x4a2c: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4a32:
	/* 0x4a32: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4a38:
	/* 0x4a38: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a3d:
	/* 0x4a3d: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4a41:
	/* 0x4a41: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4a48:
	/* 0x4a48: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4a4d:
	/* 0x4a4d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4a52:
	/* 0x4a52: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4a57:
	/* 0x4a57: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4a5f:
	/* 0x4a5f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4a63:
	/* 0x4a63: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4a6a:
	/* 0x4a6a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4a6f:
	/* 0x4a6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a71:
	/* 0x4a71: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4a76:
	/* 0x4a76: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4a7e:
	/* 0x4a7e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4a81:
	/* 0x4a81: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4a89:
	/* 0x4a89: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4a92:
	/* 0x4a92: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_4a99:
	/* 0x4a99: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a9e:
	/* 0x4a9e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4aa3:
	/* 0x4aa3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4aa8:
	/* 0x4aa8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4aad:
	/* 0x4aad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4aaf:
	/* 0x4aaf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ab4:
	/* 0x4ab4: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_4ab6:
	/* 0x4ab6: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4ab9:
	/* 0x4ab9: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_4abf:
	/* 0x4abf: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4ac2:
	/* 0x4ac2: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4ac8:
	/* 0x4ac8: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4ace:
	/* 0x4ace: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ad3:
	/* 0x4ad3: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4ad7:
	/* 0x4ad7: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4ade:
	/* 0x4ade: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4ae3:
	/* 0x4ae3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4ae8:
	/* 0x4ae8: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4aef:
	/* 0x4aef: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4af2:
	/* 0x4af2: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4af9:
	/* 0x4af9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4afe:
	/* 0x4afe: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4b03:
	/* 0x4b03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b05:
	/* 0x4b05: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4b09:
	/* 0x4b09: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_4b0b:
	/* 0x4b0b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b0d:
	/* 0x4b0d: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_4b13:
	/* 0x4b13: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4b16:
	/* 0x4b16: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4b1c:
	/* 0x4b1c: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4b22:
	/* 0x4b22: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b27:
	/* 0x4b27: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4b2b:
	/* 0x4b2b: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4b32:
	/* 0x4b32: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4b37:
	/* 0x4b37: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4b3c:
	/* 0x4b3c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4b41:
	/* 0x4b41: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4b49:
	/* 0x4b49: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4b4d:
	/* 0x4b4d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4b54:
	/* 0x4b54: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4b59:
	/* 0x4b59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b5b:
	/* 0x4b5b: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4b60:
	/* 0x4b60: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4b68:
	/* 0x4b68: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4b6b:
	/* 0x4b6b: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4b73:
	/* 0x4b73: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4b7c:
	/* 0x4b7c: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_4b83:
	/* 0x4b83: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b88:
	/* 0x4b88: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4b8d:
	/* 0x4b8d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4b92:
	/* 0x4b92: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b97:
	/* 0x4b97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b99:
	/* 0x4b99: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b9e:
	/* 0x4b9e: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_4ba0:
	/* 0x4ba0: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4ba3:
	/* 0x4ba3: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_4ba9:
	/* 0x4ba9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4bac:
	/* 0x4bac: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4bb2:
	/* 0x4bb2: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4bb8:
	/* 0x4bb8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bbd:
	/* 0x4bbd: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4bc1:
	/* 0x4bc1: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4bc8:
	/* 0x4bc8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4bcd:
	/* 0x4bcd: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4bd2:
	/* 0x4bd2: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4bd9:
	/* 0x4bd9: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4bdc:
	/* 0x4bdc: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4be3:
	/* 0x4be3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4be8:
	/* 0x4be8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4bed:
	/* 0x4bed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bef:
	/* 0x4bef: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4bf3:
	/* 0x4bf3: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_4bf5:
	/* 0x4bf5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4bf7:
	/* 0x4bf7: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_4bfd:
	/* 0x4bfd: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4c00:
	/* 0x4c00: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4c06:
	/* 0x4c06: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4c0c:
	/* 0x4c0c: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c11:
	/* 0x4c11: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4c15:
	/* 0x4c15: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4c1c:
	/* 0x4c1c: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4c21:
	/* 0x4c21: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4c26:
	/* 0x4c26: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4c2b:
	/* 0x4c2b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4c33:
	/* 0x4c33: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4c37:
	/* 0x4c37: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4c3e:
	/* 0x4c3e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4c43:
	/* 0x4c43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c45:
	/* 0x4c45: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4c4a:
	/* 0x4c4a: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4c52:
	/* 0x4c52: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4c55:
	/* 0x4c55: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4c5d:
	/* 0x4c5d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4c66:
	/* 0x4c66: lea    rdx,[r13+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_4c6d:
	/* 0x4c6d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c72:
	/* 0x4c72: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4c77:
	/* 0x4c77: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4c7c:
	/* 0x4c7c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c81:
	/* 0x4c81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c83:
	/* 0x4c83: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c88:
	/* 0x4c88: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_4c8a:
	/* 0x4c8a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4c8d:
	/* 0x4c8d: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_4c93:
	/* 0x4c93: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4c96:
	/* 0x4c96: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4c9c:
	/* 0x4c9c: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4ca2:
	/* 0x4ca2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ca7:
	/* 0x4ca7: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4cab:
	/* 0x4cab: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4cb2:
	/* 0x4cb2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4cb7:
	/* 0x4cb7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4cbc:
	/* 0x4cbc: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4cc3:
	/* 0x4cc3: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4cc6:
	/* 0x4cc6: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4ccd:
	/* 0x4ccd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4cd2:
	/* 0x4cd2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4cd7:
	/* 0x4cd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cd9:
	/* 0x4cd9: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4cdd:
	/* 0x4cdd: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_4cdf:
	/* 0x4cdf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ce1:
	/* 0x4ce1: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_4ce7:
	/* 0x4ce7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4cea:
	/* 0x4cea: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4cf0:
	/* 0x4cf0: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4cf6:
	/* 0x4cf6: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cfb:
	/* 0x4cfb: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4cff:
	/* 0x4cff: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4d06:
	/* 0x4d06: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4d0b:
	/* 0x4d0b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4d10:
	/* 0x4d10: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4d15:
	/* 0x4d15: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4d1d:
	/* 0x4d1d: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4d21:
	/* 0x4d21: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4d28:
	/* 0x4d28: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4d2d:
	/* 0x4d2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d2f:
	/* 0x4d2f: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4d34:
	/* 0x4d34: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4d3c:
	/* 0x4d3c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4d3f:
	/* 0x4d3f: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4d47:
	/* 0x4d47: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4d50:
	/* 0x4d50: lea    rdx,[r13+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_4d57:
	/* 0x4d57: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d5c:
	/* 0x4d5c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4d61:
	/* 0x4d61: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4d66:
	/* 0x4d66: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d6b:
	/* 0x4d6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d6d:
	/* 0x4d6d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d72:
	/* 0x4d72: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_4d74:
	/* 0x4d74: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4d77:
	/* 0x4d77: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_4d7d:
	/* 0x4d7d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4d80:
	/* 0x4d80: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4d86:
	/* 0x4d86: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4d8c:
	/* 0x4d8c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d91:
	/* 0x4d91: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4d95:
	/* 0x4d95: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4d9c:
	/* 0x4d9c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4da1:
	/* 0x4da1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4da6:
	/* 0x4da6: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4dad:
	/* 0x4dad: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4db0:
	/* 0x4db0: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4db7:
	/* 0x4db7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4dbc:
	/* 0x4dbc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4dc1:
	/* 0x4dc1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dc3:
	/* 0x4dc3: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4dc7:
	/* 0x4dc7: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_4dc9:
	/* 0x4dc9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4dcb:
	/* 0x4dcb: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_4dd1:
	/* 0x4dd1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4dd4:
	/* 0x4dd4: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4dda:
	/* 0x4dda: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4de0:
	/* 0x4de0: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4de5:
	/* 0x4de5: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4de9:
	/* 0x4de9: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4df0:
	/* 0x4df0: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4df5:
	/* 0x4df5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4dfa:
	/* 0x4dfa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4dff:
	/* 0x4dff: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4e07:
	/* 0x4e07: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4e0b:
	/* 0x4e0b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4e12:
	/* 0x4e12: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4e17:
	/* 0x4e17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e19:
	/* 0x4e19: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4e1e:
	/* 0x4e1e: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4e26:
	/* 0x4e26: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4e29:
	/* 0x4e29: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4e31:
	/* 0x4e31: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4e3a:
	/* 0x4e3a: lea    rdx,[r13+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_4e41:
	/* 0x4e41: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e46:
	/* 0x4e46: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4e4b:
	/* 0x4e4b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4e50:
	/* 0x4e50: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e55:
	/* 0x4e55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e57:
	/* 0x4e57: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e5c:
	/* 0x4e5c: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_4e5e:
	/* 0x4e5e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4e61:
	/* 0x4e61: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_4e67:
	/* 0x4e67: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4e6a:
	/* 0x4e6a: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4e70:
	/* 0x4e70: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4e76:
	/* 0x4e76: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e7b:
	/* 0x4e7b: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4e7f:
	/* 0x4e7f: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4e86:
	/* 0x4e86: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4e8b:
	/* 0x4e8b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4e90:
	/* 0x4e90: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4e97:
	/* 0x4e97: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4e9a:
	/* 0x4e9a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4ea1:
	/* 0x4ea1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ea6:
	/* 0x4ea6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4eab:
	/* 0x4eab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ead:
	/* 0x4ead: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4eb1:
	/* 0x4eb1: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_4eb3:
	/* 0x4eb3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4eb5:
	/* 0x4eb5: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_4ebb:
	/* 0x4ebb: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4ebe:
	/* 0x4ebe: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4ec4:
	/* 0x4ec4: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4eca:
	/* 0x4eca: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ecf:
	/* 0x4ecf: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4ed3:
	/* 0x4ed3: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4eda:
	/* 0x4eda: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4edf:
	/* 0x4edf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4ee4:
	/* 0x4ee4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4ee9:
	/* 0x4ee9: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4ef1:
	/* 0x4ef1: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4ef5:
	/* 0x4ef5: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4efc:
	/* 0x4efc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4f01:
	/* 0x4f01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f03:
	/* 0x4f03: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4f08:
	/* 0x4f08: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4f10:
	/* 0x4f10: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4f13:
	/* 0x4f13: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4f1b:
	/* 0x4f1b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4f24:
	/* 0x4f24: lea    rdx,[r13+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_4f2b:
	/* 0x4f2b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f30:
	/* 0x4f30: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4f35:
	/* 0x4f35: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4f3a:
	/* 0x4f3a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f3f:
	/* 0x4f3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f41:
	/* 0x4f41: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f46:
	/* 0x4f46: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_4f48:
	/* 0x4f48: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4f4b:
	/* 0x4f4b: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
	return 20305ULL;
}

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 20305ULL: goto x86_l_4f51;
	case 20308ULL: goto x86_l_4f54;
	case 20314ULL: goto x86_l_4f5a;
	case 20320ULL: goto x86_l_4f60;
	case 20325ULL: goto x86_l_4f65;
	case 20329ULL: goto x86_l_4f69;
	case 20336ULL: goto x86_l_4f70;
	case 20341ULL: goto x86_l_4f75;
	case 20346ULL: goto x86_l_4f7a;
	case 20353ULL: goto x86_l_4f81;
	case 20356ULL: goto x86_l_4f84;
	case 20363ULL: goto x86_l_4f8b;
	case 20368ULL: goto x86_l_4f90;
	case 20373ULL: goto x86_l_4f95;
	case 20375ULL: goto x86_l_4f97;
	case 20379ULL: goto x86_l_4f9b;
	case 20381ULL: goto x86_l_4f9d;
	case 20383ULL: goto x86_l_4f9f;
	case 20389ULL: goto x86_l_4fa5;
	case 20392ULL: goto x86_l_4fa8;
	case 20398ULL: goto x86_l_4fae;
	case 20404ULL: goto x86_l_4fb4;
	case 20409ULL: goto x86_l_4fb9;
	case 20413ULL: goto x86_l_4fbd;
	case 20420ULL: goto x86_l_4fc4;
	case 20425ULL: goto x86_l_4fc9;
	case 20430ULL: goto x86_l_4fce;
	case 20435ULL: goto x86_l_4fd3;
	case 20443ULL: goto x86_l_4fdb;
	case 20447ULL: goto x86_l_4fdf;
	case 20454ULL: goto x86_l_4fe6;
	case 20459ULL: goto x86_l_4feb;
	case 20461ULL: goto x86_l_4fed;
	case 20466ULL: goto x86_l_4ff2;
	case 20474ULL: goto x86_l_4ffa;
	case 20477ULL: goto x86_l_4ffd;
	case 20485ULL: goto x86_l_5005;
	case 20494ULL: goto x86_l_500e;
	case 20501ULL: goto x86_l_5015;
	case 20506ULL: goto x86_l_501a;
	case 20511ULL: goto x86_l_501f;
	case 20516ULL: goto x86_l_5024;
	case 20521ULL: goto x86_l_5029;
	case 20523ULL: goto x86_l_502b;
	case 20528ULL: goto x86_l_5030;
	case 20530ULL: goto x86_l_5032;
	case 20533ULL: goto x86_l_5035;
	case 20539ULL: goto x86_l_503b;
	case 20542ULL: goto x86_l_503e;
	case 20548ULL: goto x86_l_5044;
	case 20554ULL: goto x86_l_504a;
	case 20559ULL: goto x86_l_504f;
	case 20563ULL: goto x86_l_5053;
	case 20570ULL: goto x86_l_505a;
	case 20575ULL: goto x86_l_505f;
	case 20580ULL: goto x86_l_5064;
	case 20587ULL: goto x86_l_506b;
	case 20590ULL: goto x86_l_506e;
	case 20597ULL: goto x86_l_5075;
	case 20602ULL: goto x86_l_507a;
	case 20607ULL: goto x86_l_507f;
	case 20609ULL: goto x86_l_5081;
	case 20613ULL: goto x86_l_5085;
	case 20615ULL: goto x86_l_5087;
	case 20617ULL: goto x86_l_5089;
	case 20623ULL: goto x86_l_508f;
	case 20626ULL: goto x86_l_5092;
	case 20632ULL: goto x86_l_5098;
	case 20638ULL: goto x86_l_509e;
	case 20643ULL: goto x86_l_50a3;
	case 20647ULL: goto x86_l_50a7;
	case 20654ULL: goto x86_l_50ae;
	case 20659ULL: goto x86_l_50b3;
	case 20664ULL: goto x86_l_50b8;
	case 20669ULL: goto x86_l_50bd;
	case 20677ULL: goto x86_l_50c5;
	case 20681ULL: goto x86_l_50c9;
	case 20688ULL: goto x86_l_50d0;
	case 20693ULL: goto x86_l_50d5;
	case 20695ULL: goto x86_l_50d7;
	case 20700ULL: goto x86_l_50dc;
	case 20708ULL: goto x86_l_50e4;
	case 20711ULL: goto x86_l_50e7;
	case 20719ULL: goto x86_l_50ef;
	case 20728ULL: goto x86_l_50f8;
	case 20735ULL: goto x86_l_50ff;
	case 20740ULL: goto x86_l_5104;
	case 20745ULL: goto x86_l_5109;
	case 20750ULL: goto x86_l_510e;
	case 20755ULL: goto x86_l_5113;
	case 20757ULL: goto x86_l_5115;
	case 20762ULL: goto x86_l_511a;
	case 20764ULL: goto x86_l_511c;
	case 20767ULL: goto x86_l_511f;
	case 20773ULL: goto x86_l_5125;
	case 20776ULL: goto x86_l_5128;
	case 20782ULL: goto x86_l_512e;
	case 20788ULL: goto x86_l_5134;
	case 20793ULL: goto x86_l_5139;
	case 20797ULL: goto x86_l_513d;
	case 20804ULL: goto x86_l_5144;
	case 20809ULL: goto x86_l_5149;
	case 20814ULL: goto x86_l_514e;
	case 20821ULL: goto x86_l_5155;
	case 20824ULL: goto x86_l_5158;
	case 20831ULL: goto x86_l_515f;
	case 20836ULL: goto x86_l_5164;
	case 20841ULL: goto x86_l_5169;
	case 20843ULL: goto x86_l_516b;
	case 20847ULL: goto x86_l_516f;
	case 20849ULL: goto x86_l_5171;
	case 20851ULL: goto x86_l_5173;
	case 20857ULL: goto x86_l_5179;
	case 20860ULL: goto x86_l_517c;
	case 20866ULL: goto x86_l_5182;
	case 20872ULL: goto x86_l_5188;
	case 20877ULL: goto x86_l_518d;
	case 20881ULL: goto x86_l_5191;
	case 20888ULL: goto x86_l_5198;
	case 20893ULL: goto x86_l_519d;
	case 20898ULL: goto x86_l_51a2;
	case 20903ULL: goto x86_l_51a7;
	case 20911ULL: goto x86_l_51af;
	case 20915ULL: goto x86_l_51b3;
	case 20922ULL: goto x86_l_51ba;
	case 20927ULL: goto x86_l_51bf;
	case 20929ULL: goto x86_l_51c1;
	case 20934ULL: goto x86_l_51c6;
	case 20942ULL: goto x86_l_51ce;
	case 20945ULL: goto x86_l_51d1;
	case 20953ULL: goto x86_l_51d9;
	case 20962ULL: goto x86_l_51e2;
	case 20969ULL: goto x86_l_51e9;
	case 20974ULL: goto x86_l_51ee;
	case 20979ULL: goto x86_l_51f3;
	case 20984ULL: goto x86_l_51f8;
	case 20989ULL: goto x86_l_51fd;
	case 20991ULL: goto x86_l_51ff;
	case 20996ULL: goto x86_l_5204;
	case 20998ULL: goto x86_l_5206;
	case 21001ULL: goto x86_l_5209;
	case 21007ULL: goto x86_l_520f;
	case 21010ULL: goto x86_l_5212;
	case 21016ULL: goto x86_l_5218;
	case 21022ULL: goto x86_l_521e;
	case 21027ULL: goto x86_l_5223;
	case 21031ULL: goto x86_l_5227;
	case 21038ULL: goto x86_l_522e;
	case 21043ULL: goto x86_l_5233;
	case 21048ULL: goto x86_l_5238;
	case 21055ULL: goto x86_l_523f;
	case 21058ULL: goto x86_l_5242;
	case 21065ULL: goto x86_l_5249;
	case 21070ULL: goto x86_l_524e;
	case 21075ULL: goto x86_l_5253;
	case 21077ULL: goto x86_l_5255;
	case 21081ULL: goto x86_l_5259;
	case 21083ULL: goto x86_l_525b;
	case 21085ULL: goto x86_l_525d;
	case 21091ULL: goto x86_l_5263;
	case 21094ULL: goto x86_l_5266;
	case 21100ULL: goto x86_l_526c;
	case 21106ULL: goto x86_l_5272;
	case 21111ULL: goto x86_l_5277;
	case 21115ULL: goto x86_l_527b;
	case 21122ULL: goto x86_l_5282;
	case 21127ULL: goto x86_l_5287;
	case 21132ULL: goto x86_l_528c;
	case 21137ULL: goto x86_l_5291;
	case 21145ULL: goto x86_l_5299;
	case 21149ULL: goto x86_l_529d;
	case 21156ULL: goto x86_l_52a4;
	case 21161ULL: goto x86_l_52a9;
	case 21163ULL: goto x86_l_52ab;
	case 21168ULL: goto x86_l_52b0;
	case 21176ULL: goto x86_l_52b8;
	case 21179ULL: goto x86_l_52bb;
	case 21187ULL: goto x86_l_52c3;
	case 21196ULL: goto x86_l_52cc;
	case 21203ULL: goto x86_l_52d3;
	case 21208ULL: goto x86_l_52d8;
	case 21213ULL: goto x86_l_52dd;
	case 21218ULL: goto x86_l_52e2;
	case 21223ULL: goto x86_l_52e7;
	case 21225ULL: goto x86_l_52e9;
	case 21230ULL: goto x86_l_52ee;
	case 21232ULL: goto x86_l_52f0;
	case 21235ULL: goto x86_l_52f3;
	case 21241ULL: goto x86_l_52f9;
	case 21244ULL: goto x86_l_52fc;
	case 21250ULL: goto x86_l_5302;
	case 21256ULL: goto x86_l_5308;
	case 21261ULL: goto x86_l_530d;
	case 21265ULL: goto x86_l_5311;
	case 21272ULL: goto x86_l_5318;
	case 21277ULL: goto x86_l_531d;
	case 21282ULL: goto x86_l_5322;
	case 21289ULL: goto x86_l_5329;
	case 21292ULL: goto x86_l_532c;
	case 21299ULL: goto x86_l_5333;
	case 21304ULL: goto x86_l_5338;
	case 21309ULL: goto x86_l_533d;
	case 21311ULL: goto x86_l_533f;
	case 21315ULL: goto x86_l_5343;
	case 21317ULL: goto x86_l_5345;
	case 21319ULL: goto x86_l_5347;
	case 21325ULL: goto x86_l_534d;
	case 21328ULL: goto x86_l_5350;
	case 21334ULL: goto x86_l_5356;
	case 21340ULL: goto x86_l_535c;
	case 21345ULL: goto x86_l_5361;
	case 21349ULL: goto x86_l_5365;
	case 21356ULL: goto x86_l_536c;
	case 21361ULL: goto x86_l_5371;
	case 21366ULL: goto x86_l_5376;
	case 21371ULL: goto x86_l_537b;
	case 21379ULL: goto x86_l_5383;
	case 21383ULL: goto x86_l_5387;
	case 21390ULL: goto x86_l_538e;
	case 21395ULL: goto x86_l_5393;
	case 21397ULL: goto x86_l_5395;
	case 21402ULL: goto x86_l_539a;
	case 21410ULL: goto x86_l_53a2;
	case 21413ULL: goto x86_l_53a5;
	case 21421ULL: goto x86_l_53ad;
	case 21430ULL: goto x86_l_53b6;
	case 21437ULL: goto x86_l_53bd;
	case 21442ULL: goto x86_l_53c2;
	case 21447ULL: goto x86_l_53c7;
	case 21452ULL: goto x86_l_53cc;
	case 21457ULL: goto x86_l_53d1;
	case 21459ULL: goto x86_l_53d3;
	case 21464ULL: goto x86_l_53d8;
	case 21466ULL: goto x86_l_53da;
	case 21469ULL: goto x86_l_53dd;
	case 21475ULL: goto x86_l_53e3;
	case 21478ULL: goto x86_l_53e6;
	case 21484ULL: goto x86_l_53ec;
	case 21490ULL: goto x86_l_53f2;
	case 21495ULL: goto x86_l_53f7;
	case 21499ULL: goto x86_l_53fb;
	case 21506ULL: goto x86_l_5402;
	case 21511ULL: goto x86_l_5407;
	case 21516ULL: goto x86_l_540c;
	case 21523ULL: goto x86_l_5413;
	case 21526ULL: goto x86_l_5416;
	case 21533ULL: goto x86_l_541d;
	case 21538ULL: goto x86_l_5422;
	case 21543ULL: goto x86_l_5427;
	case 21545ULL: goto x86_l_5429;
	case 21549ULL: goto x86_l_542d;
	case 21551ULL: goto x86_l_542f;
	case 21553ULL: goto x86_l_5431;
	case 21559ULL: goto x86_l_5437;
	case 21562ULL: goto x86_l_543a;
	case 21568ULL: goto x86_l_5440;
	case 21574ULL: goto x86_l_5446;
	case 21579ULL: goto x86_l_544b;
	case 21583ULL: goto x86_l_544f;
	case 21590ULL: goto x86_l_5456;
	case 21595ULL: goto x86_l_545b;
	case 21600ULL: goto x86_l_5460;
	case 21605ULL: goto x86_l_5465;
	case 21613ULL: goto x86_l_546d;
	case 21617ULL: goto x86_l_5471;
	case 21624ULL: goto x86_l_5478;
	case 21629ULL: goto x86_l_547d;
	case 21631ULL: goto x86_l_547f;
	case 21636ULL: goto x86_l_5484;
	case 21644ULL: goto x86_l_548c;
	case 21647ULL: goto x86_l_548f;
	case 21655ULL: goto x86_l_5497;
	case 21664ULL: goto x86_l_54a0;
	case 21671ULL: goto x86_l_54a7;
	case 21676ULL: goto x86_l_54ac;
	case 21681ULL: goto x86_l_54b1;
	case 21686ULL: goto x86_l_54b6;
	case 21691ULL: goto x86_l_54bb;
	case 21693ULL: goto x86_l_54bd;
	case 21698ULL: goto x86_l_54c2;
	case 21700ULL: goto x86_l_54c4;
	case 21703ULL: goto x86_l_54c7;
	case 21709ULL: goto x86_l_54cd;
	case 21712ULL: goto x86_l_54d0;
	case 21718ULL: goto x86_l_54d6;
	case 21724ULL: goto x86_l_54dc;
	case 21729ULL: goto x86_l_54e1;
	case 21733ULL: goto x86_l_54e5;
	case 21740ULL: goto x86_l_54ec;
	case 21745ULL: goto x86_l_54f1;
	case 21750ULL: goto x86_l_54f6;
	case 21757ULL: goto x86_l_54fd;
	case 21760ULL: goto x86_l_5500;
	case 21767ULL: goto x86_l_5507;
	case 21772ULL: goto x86_l_550c;
	case 21777ULL: goto x86_l_5511;
	case 21779ULL: goto x86_l_5513;
	case 21783ULL: goto x86_l_5517;
	case 21785ULL: goto x86_l_5519;
	case 21787ULL: goto x86_l_551b;
	case 21793ULL: goto x86_l_5521;
	case 21796ULL: goto x86_l_5524;
	case 21802ULL: goto x86_l_552a;
	case 21808ULL: goto x86_l_5530;
	case 21813ULL: goto x86_l_5535;
	case 21817ULL: goto x86_l_5539;
	case 21824ULL: goto x86_l_5540;
	case 21829ULL: goto x86_l_5545;
	case 21834ULL: goto x86_l_554a;
	case 21839ULL: goto x86_l_554f;
	case 21847ULL: goto x86_l_5557;
	case 21851ULL: goto x86_l_555b;
	case 21858ULL: goto x86_l_5562;
	case 21863ULL: goto x86_l_5567;
	case 21865ULL: goto x86_l_5569;
	case 21870ULL: goto x86_l_556e;
	case 21878ULL: goto x86_l_5576;
	case 21881ULL: goto x86_l_5579;
	case 21889ULL: goto x86_l_5581;
	case 21898ULL: goto x86_l_558a;
	case 21905ULL: goto x86_l_5591;
	case 21910ULL: goto x86_l_5596;
	case 21915ULL: goto x86_l_559b;
	case 21920ULL: goto x86_l_55a0;
	case 21925ULL: goto x86_l_55a5;
	case 21928ULL: goto x86_l_55a8;
	case 21930ULL: goto x86_l_55aa;
	case 21935ULL: goto x86_l_55af;
	case 21937ULL: goto x86_l_55b1;
	case 21940ULL: goto x86_l_55b4;
	case 21946ULL: goto x86_l_55ba;
	case 21949ULL: goto x86_l_55bd;
	case 21955ULL: goto x86_l_55c3;
	case 21961ULL: goto x86_l_55c9;
	case 21966ULL: goto x86_l_55ce;
	case 21970ULL: goto x86_l_55d2;
	case 21977ULL: goto x86_l_55d9;
	case 21982ULL: goto x86_l_55de;
	case 21987ULL: goto x86_l_55e3;
	case 21994ULL: goto x86_l_55ea;
	case 21997ULL: goto x86_l_55ed;
	case 22004ULL: goto x86_l_55f4;
	case 22009ULL: goto x86_l_55f9;
	case 22014ULL: goto x86_l_55fe;
	case 22016ULL: goto x86_l_5600;
	case 22020ULL: goto x86_l_5604;
	case 22022ULL: goto x86_l_5606;
	case 22024ULL: goto x86_l_5608;
	case 22030ULL: goto x86_l_560e;
	case 22033ULL: goto x86_l_5611;
	case 22039ULL: goto x86_l_5617;
	case 22045ULL: goto x86_l_561d;
	case 22050ULL: goto x86_l_5622;
	case 22054ULL: goto x86_l_5626;
	case 22061ULL: goto x86_l_562d;
	case 22066ULL: goto x86_l_5632;
	case 22071ULL: goto x86_l_5637;
	case 22076ULL: goto x86_l_563c;
	case 22084ULL: goto x86_l_5644;
	case 22088ULL: goto x86_l_5648;
	case 22095ULL: goto x86_l_564f;
	case 22100ULL: goto x86_l_5654;
	case 22102ULL: goto x86_l_5656;
	case 22107ULL: goto x86_l_565b;
	case 22115ULL: goto x86_l_5663;
	case 22118ULL: goto x86_l_5666;
	case 22126ULL: goto x86_l_566e;
	case 22134ULL: goto x86_l_5676;
	case 22137ULL: goto x86_l_5679;
	case 22143ULL: goto x86_l_567f;
	case 22145ULL: goto x86_l_5681;
	case 22150ULL: goto x86_l_5686;
	case 22154ULL: goto x86_l_568a;
	case 22157ULL: goto x86_l_568d;
	case 22162ULL: goto x86_l_5692;
	case 22166ULL: goto x86_l_5696;
	case 22173ULL: goto x86_l_569d;
	case 22178ULL: goto x86_l_56a2;
	case 22183ULL: goto x86_l_56a7;
	case 22188ULL: goto x86_l_56ac;
	case 22195ULL: goto x86_l_56b3;
	case 22198ULL: goto x86_l_56b6;
	case 22205ULL: goto x86_l_56bd;
	case 22210ULL: goto x86_l_56c2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4f51:
	/* 0x4f51: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4f54:
	/* 0x4f54: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4f5a:
	/* 0x4f5a: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4f60:
	/* 0x4f60: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f65:
	/* 0x4f65: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4f69:
	/* 0x4f69: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4f70:
	/* 0x4f70: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4f75:
	/* 0x4f75: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4f7a:
	/* 0x4f7a: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4f81:
	/* 0x4f81: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4f84:
	/* 0x4f84: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4f8b:
	/* 0x4f8b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f90:
	/* 0x4f90: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4f95:
	/* 0x4f95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f97:
	/* 0x4f97: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4f9b:
	/* 0x4f9b: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_4f9d:
	/* 0x4f9d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f9f:
	/* 0x4f9f: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_4fa5:
	/* 0x4fa5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4fa8:
	/* 0x4fa8: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4fae:
	/* 0x4fae: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_4fb4:
	/* 0x4fb4: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fb9:
	/* 0x4fb9: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4fbd:
	/* 0x4fbd: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4fc4:
	/* 0x4fc4: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4fc9:
	/* 0x4fc9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4fce:
	/* 0x4fce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4fd3:
	/* 0x4fd3: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4fdb:
	/* 0x4fdb: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4fdf:
	/* 0x4fdf: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4fe6:
	/* 0x4fe6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4feb:
	/* 0x4feb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fed:
	/* 0x4fed: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4ff2:
	/* 0x4ff2: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4ffa:
	/* 0x4ffa: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4ffd:
	/* 0x4ffd: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5005:
	/* 0x5005: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_500e:
	/* 0x500e: lea    rdx,[r13+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_5015:
	/* 0x5015: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_501a:
	/* 0x501a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_501f:
	/* 0x501f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5024:
	/* 0x5024: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5029:
	/* 0x5029: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_502b:
	/* 0x502b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5030:
	/* 0x5030: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_5032:
	/* 0x5032: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5035:
	/* 0x5035: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_503b:
	/* 0x503b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_503e:
	/* 0x503e: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5044:
	/* 0x5044: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_504a:
	/* 0x504a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_504f:
	/* 0x504f: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_5053:
	/* 0x5053: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_505a:
	/* 0x505a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_505f:
	/* 0x505f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5064:
	/* 0x5064: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_506b:
	/* 0x506b: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_506e:
	/* 0x506e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5075:
	/* 0x5075: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_507a:
	/* 0x507a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_507f:
	/* 0x507f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5081:
	/* 0x5081: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5085:
	/* 0x5085: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_5087:
	/* 0x5087: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5089:
	/* 0x5089: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_508f:
	/* 0x508f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5092:
	/* 0x5092: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5098:
	/* 0x5098: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_509e:
	/* 0x509e: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50a3:
	/* 0x50a3: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_50a7:
	/* 0x50a7: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_50ae:
	/* 0x50ae: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_50b3:
	/* 0x50b3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_50b8:
	/* 0x50b8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_50bd:
	/* 0x50bd: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_50c5:
	/* 0x50c5: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_50c9:
	/* 0x50c9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_50d0:
	/* 0x50d0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_50d5:
	/* 0x50d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50d7:
	/* 0x50d7: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_50dc:
	/* 0x50dc: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_50e4:
	/* 0x50e4: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_50e7:
	/* 0x50e7: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_50ef:
	/* 0x50ef: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_50f8:
	/* 0x50f8: lea    rdx,[r13+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_50ff:
	/* 0x50ff: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5104:
	/* 0x5104: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5109:
	/* 0x5109: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_510e:
	/* 0x510e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5113:
	/* 0x5113: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5115:
	/* 0x5115: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_511a:
	/* 0x511a: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_511c:
	/* 0x511c: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_511f:
	/* 0x511f: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_5125:
	/* 0x5125: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5128:
	/* 0x5128: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_512e:
	/* 0x512e: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_5134:
	/* 0x5134: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5139:
	/* 0x5139: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_513d:
	/* 0x513d: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5144:
	/* 0x5144: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5149:
	/* 0x5149: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_514e:
	/* 0x514e: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5155:
	/* 0x5155: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5158:
	/* 0x5158: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_515f:
	/* 0x515f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5164:
	/* 0x5164: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5169:
	/* 0x5169: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_516b:
	/* 0x516b: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_516f:
	/* 0x516f: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_5171:
	/* 0x5171: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5173:
	/* 0x5173: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_5179:
	/* 0x5179: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_517c:
	/* 0x517c: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5182:
	/* 0x5182: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_5188:
	/* 0x5188: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_518d:
	/* 0x518d: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_5191:
	/* 0x5191: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5198:
	/* 0x5198: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_519d:
	/* 0x519d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_51a2:
	/* 0x51a2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_51a7:
	/* 0x51a7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_51af:
	/* 0x51af: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_51b3:
	/* 0x51b3: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_51ba:
	/* 0x51ba: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_51bf:
	/* 0x51bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51c1:
	/* 0x51c1: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_51c6:
	/* 0x51c6: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_51ce:
	/* 0x51ce: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_51d1:
	/* 0x51d1: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_51d9:
	/* 0x51d9: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_51e2:
	/* 0x51e2: lea    rdx,[r13+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_51e9:
	/* 0x51e9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51ee:
	/* 0x51ee: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_51f3:
	/* 0x51f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_51f8:
	/* 0x51f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51fd:
	/* 0x51fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51ff:
	/* 0x51ff: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5204:
	/* 0x5204: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_5206:
	/* 0x5206: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5209:
	/* 0x5209: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_520f:
	/* 0x520f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5212:
	/* 0x5212: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5218:
	/* 0x5218: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_521e:
	/* 0x521e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5223:
	/* 0x5223: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_5227:
	/* 0x5227: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_522e:
	/* 0x522e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5233:
	/* 0x5233: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5238:
	/* 0x5238: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_523f:
	/* 0x523f: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5242:
	/* 0x5242: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5249:
	/* 0x5249: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_524e:
	/* 0x524e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5253:
	/* 0x5253: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5255:
	/* 0x5255: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5259:
	/* 0x5259: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_525b:
	/* 0x525b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_525d:
	/* 0x525d: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_5263:
	/* 0x5263: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5266:
	/* 0x5266: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_526c:
	/* 0x526c: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_5272:
	/* 0x5272: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5277:
	/* 0x5277: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_527b:
	/* 0x527b: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5282:
	/* 0x5282: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5287:
	/* 0x5287: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_528c:
	/* 0x528c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5291:
	/* 0x5291: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5299:
	/* 0x5299: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_529d:
	/* 0x529d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_52a4:
	/* 0x52a4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_52a9:
	/* 0x52a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52ab:
	/* 0x52ab: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_52b0:
	/* 0x52b0: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_52b8:
	/* 0x52b8: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_52bb:
	/* 0x52bb: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_52c3:
	/* 0x52c3: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_52cc:
	/* 0x52cc: lea    rdx,[r13+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_52d3:
	/* 0x52d3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52d8:
	/* 0x52d8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_52dd:
	/* 0x52dd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_52e2:
	/* 0x52e2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52e7:
	/* 0x52e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52e9:
	/* 0x52e9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52ee:
	/* 0x52ee: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_52f0:
	/* 0x52f0: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_52f3:
	/* 0x52f3: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_52f9:
	/* 0x52f9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_52fc:
	/* 0x52fc: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5302:
	/* 0x5302: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_5308:
	/* 0x5308: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_530d:
	/* 0x530d: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_5311:
	/* 0x5311: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5318:
	/* 0x5318: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_531d:
	/* 0x531d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5322:
	/* 0x5322: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5329:
	/* 0x5329: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_532c:
	/* 0x532c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5333:
	/* 0x5333: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5338:
	/* 0x5338: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_533d:
	/* 0x533d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_533f:
	/* 0x533f: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5343:
	/* 0x5343: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_5345:
	/* 0x5345: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5347:
	/* 0x5347: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_534d:
	/* 0x534d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5350:
	/* 0x5350: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5356:
	/* 0x5356: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_535c:
	/* 0x535c: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5361:
	/* 0x5361: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_5365:
	/* 0x5365: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_536c:
	/* 0x536c: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5371:
	/* 0x5371: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5376:
	/* 0x5376: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_537b:
	/* 0x537b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5383:
	/* 0x5383: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5387:
	/* 0x5387: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_538e:
	/* 0x538e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5393:
	/* 0x5393: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5395:
	/* 0x5395: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_539a:
	/* 0x539a: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_53a2:
	/* 0x53a2: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_53a5:
	/* 0x53a5: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_53ad:
	/* 0x53ad: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_53b6:
	/* 0x53b6: lea    rdx,[r13+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_53bd:
	/* 0x53bd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53c2:
	/* 0x53c2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_53c7:
	/* 0x53c7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_53cc:
	/* 0x53cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53d1:
	/* 0x53d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53d3:
	/* 0x53d3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53d8:
	/* 0x53d8: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_53da:
	/* 0x53da: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_53dd:
	/* 0x53dd: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_53e3:
	/* 0x53e3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_53e6:
	/* 0x53e6: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_53ec:
	/* 0x53ec: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_53f2:
	/* 0x53f2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53f7:
	/* 0x53f7: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_53fb:
	/* 0x53fb: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5402:
	/* 0x5402: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5407:
	/* 0x5407: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_540c:
	/* 0x540c: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5413:
	/* 0x5413: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5416:
	/* 0x5416: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_541d:
	/* 0x541d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5422:
	/* 0x5422: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5427:
	/* 0x5427: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5429:
	/* 0x5429: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_542d:
	/* 0x542d: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_542f:
	/* 0x542f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5431:
	/* 0x5431: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_5437:
	/* 0x5437: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_543a:
	/* 0x543a: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5440:
	/* 0x5440: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_5446:
	/* 0x5446: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_544b:
	/* 0x544b: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_544f:
	/* 0x544f: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5456:
	/* 0x5456: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_545b:
	/* 0x545b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5460:
	/* 0x5460: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5465:
	/* 0x5465: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_546d:
	/* 0x546d: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5471:
	/* 0x5471: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5478:
	/* 0x5478: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_547d:
	/* 0x547d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_547f:
	/* 0x547f: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_5484:
	/* 0x5484: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_548c:
	/* 0x548c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_548f:
	/* 0x548f: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5497:
	/* 0x5497: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_54a0:
	/* 0x54a0: lea    rdx,[r13+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_54a7:
	/* 0x54a7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54ac:
	/* 0x54ac: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_54b1:
	/* 0x54b1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_54b6:
	/* 0x54b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_54bb:
	/* 0x54bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54bd:
	/* 0x54bd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54c2:
	/* 0x54c2: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_54c4:
	/* 0x54c4: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_54c7:
	/* 0x54c7: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_54cd:
	/* 0x54cd: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_54d0:
	/* 0x54d0: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_54d6:
	/* 0x54d6: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_54dc:
	/* 0x54dc: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54e1:
	/* 0x54e1: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_54e5:
	/* 0x54e5: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_54ec:
	/* 0x54ec: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_54f1:
	/* 0x54f1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_54f6:
	/* 0x54f6: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_54fd:
	/* 0x54fd: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5500:
	/* 0x5500: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5507:
	/* 0x5507: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_550c:
	/* 0x550c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5511:
	/* 0x5511: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5513:
	/* 0x5513: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5517:
	/* 0x5517: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_5519:
	/* 0x5519: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_551b:
	/* 0x551b: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_5521:
	/* 0x5521: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5524:
	/* 0x5524: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_552a:
	/* 0x552a: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_5530:
	/* 0x5530: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5535:
	/* 0x5535: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_5539:
	/* 0x5539: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5540:
	/* 0x5540: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5545:
	/* 0x5545: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_554a:
	/* 0x554a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_554f:
	/* 0x554f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5557:
	/* 0x5557: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_555b:
	/* 0x555b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5562:
	/* 0x5562: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5567:
	/* 0x5567: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5569:
	/* 0x5569: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_556e:
	/* 0x556e: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5576:
	/* 0x5576: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5579:
	/* 0x5579: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5581:
	/* 0x5581: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_558a:
	/* 0x558a: add    r13,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_5591:
	/* 0x5591: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5596:
	/* 0x5596: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_559b:
	/* 0x559b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_55a0:
	/* 0x55a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55a5:
	/* 0x55a5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_55a8:
	/* 0x55a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55aa:
	/* 0x55aa: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55af:
	/* 0x55af: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_55b1:
	/* 0x55b1: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_55b4:
	/* 0x55b4: je     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3165ULL;
	}
x86_l_55ba:
	/* 0x55ba: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_55bd:
	/* 0x55bd: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_55c3:
	/* 0x55c3: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_55c9:
	/* 0x55c9: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55ce:
	/* 0x55ce: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_55d2:
	/* 0x55d2: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_55d9:
	/* 0x55d9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_55de:
	/* 0x55de: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_55e3:
	/* 0x55e3: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_55ea:
	/* 0x55ea: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_55ed:
	/* 0x55ed: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_55f4:
	/* 0x55f4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55f9:
	/* 0x55f9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_55fe:
	/* 0x55fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5600:
	/* 0x5600: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5604:
	/* 0x5604: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_5606:
	/* 0x5606: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5608:
	/* 0x5608: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_560e:
	/* 0x560e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5611:
	/* 0x5611: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5617:
	/* 0x5617: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_561d:
	/* 0x561d: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5622:
	/* 0x5622: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_5626:
	/* 0x5626: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_562d:
	/* 0x562d: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5632:
	/* 0x5632: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5637:
	/* 0x5637: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_563c:
	/* 0x563c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5644:
	/* 0x5644: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5648:
	/* 0x5648: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_564f:
	/* 0x564f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5654:
	/* 0x5654: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5656:
	/* 0x5656: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_565b:
	/* 0x565b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5663:
	/* 0x5663: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5666:
	/* 0x5666: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_566e:
	/* 0x566e: mov    DWORD PTR [rsp+0x10],0x2e2e2e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68722503214ULL);
x86_l_5676:
	/* 0x5676: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_5679:
	/* 0x5679: cmp    ecx,0x6cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27901ULL);
x86_l_567f:
	/* 0x567f: jb     568a <syscall__execve_enter+0x568a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_568a;
	}
x86_l_5681:
	/* 0x5681: mov    WORD PTR [rbx],0x6cfc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27900ULL);
x86_l_5686:
	/* 0x5686: mov    ax,0x6cfc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 27900ULL);
x86_l_568a:
	/* 0x568a: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_568d:
	/* 0x568d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5692:
	/* 0x5692: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_5696:
	/* 0x5696: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_569d:
	/* 0x569d: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_56a2:
	/* 0x56a2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_56a7:
	/* 0x56a7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_56ac:
	/* 0x56ac: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_56b3:
	/* 0x56b3: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_56b6:
	/* 0x56b6: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_56bd:
	/* 0x56bd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_56c2:
	/* 0x56c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 22212ULL;
}

static __noinline __u64 tracee_syscall__execve_enter_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 22212ULL: goto x86_l_56c4;
	case 22216ULL: goto x86_l_56c8;
	case 22218ULL: goto x86_l_56ca;
	case 22220ULL: goto x86_l_56cc;
	case 22226ULL: goto x86_l_56d2;
	case 22229ULL: goto x86_l_56d5;
	case 22235ULL: goto x86_l_56db;
	case 22241ULL: goto x86_l_56e1;
	case 22246ULL: goto x86_l_56e6;
	case 22250ULL: goto x86_l_56ea;
	case 22257ULL: goto x86_l_56f1;
	case 22262ULL: goto x86_l_56f6;
	case 22267ULL: goto x86_l_56fb;
	case 22272ULL: goto x86_l_5700;
	case 22279ULL: goto x86_l_5707;
	case 22283ULL: goto x86_l_570b;
	case 22290ULL: goto x86_l_5712;
	case 22295ULL: goto x86_l_5717;
	case 22297ULL: goto x86_l_5719;
	case 22302ULL: goto x86_l_571e;
	case 22309ULL: goto x86_l_5725;
	case 22312ULL: goto x86_l_5728;
	case 22319ULL: goto x86_l_572f;
	case 22321ULL: goto x86_l_5731;
	default: return 0xffffffffffffffffULL;
	}
x86_l_56c4:
	/* 0x56c4: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_56c8:
	/* 0x56c8: mov    cl,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 38ULL);
x86_l_56ca:
	/* 0x56ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56cc:
	/* 0x56cc: jle    c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3165ULL;
	}
x86_l_56d2:
	/* 0x56d2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_56d5:
	/* 0x56d5: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_56db:
	/* 0x56db: ja     c5d <syscall__execve_enter+0xc5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3165ULL;
	}
x86_l_56e1:
	/* 0x56e1: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56e6:
	/* 0x56e6: lea    rcx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_56ea:
	/* 0x56ea: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_56f1:
	/* 0x56f1: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_56f6:
	/* 0x56f6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_56fb:
	/* 0x56fb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5700:
	/* 0x5700: movzx  ecx,WORD PTR [rbx+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5707:
	/* 0x5707: lea    rdi,[rbx+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_570b:
	/* 0x570b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5712:
	/* 0x5712: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5717:
	/* 0x5717: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5719:
	/* 0x5719: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_571e:
	/* 0x571e: add    ax,WORD PTR [rbx+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5725:
	/* 0x5725: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5728:
	/* 0x5728: mov    WORD PTR [rbx+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_572f:
	/* 0x572f: mov    cl,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 39ULL);
x86_l_5731:
	/* 0x5731: jmp    c5d <syscall__execve_enter+0xc5d> */
	return 3165ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_syscall__execve_enter_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 18528U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1723ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1728ULL && __x86_pc <= 3367ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3372ULL && __x86_pc <= 5083ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5088ULL && __x86_pc <= 6963ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6969ULL && __x86_pc <= 8865ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8872ULL && __x86_pc <= 10770ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10773ULL && __x86_pc <= 12683ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12688ULL && __x86_pc <= 14589ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14593ULL && __x86_pc <= 16482ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 16487ULL && __x86_pc <= 18395ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 18400ULL && __x86_pc <= 20299ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 20305ULL && __x86_pc <= 22210ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 22212ULL && __x86_pc <= 22321ULL)
			__x86_pc = tracee_syscall__execve_enter_x86_chunk_12(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

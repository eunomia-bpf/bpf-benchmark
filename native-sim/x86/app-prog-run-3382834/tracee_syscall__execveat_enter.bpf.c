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

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_0(
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
	/* 0x32: je     20e <syscall__execveat_enter+0x20e> */
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
	/* 0x51: je     20e <syscall__execveat_enter+0x20e> */
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
	/* 0x72: je     20e <syscall__execveat_enter+0x20e> */
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
	/* 0x93: je     20e <syscall__execveat_enter+0x20e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20e;
	}
x86_l_99:
	/* 0x99: cmp    BYTE PTR [r13+0xb0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_a1:
	/* 0xa1: je     215 <syscall__execveat_enter+0x215> */
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
	/* 0xb7: mov    DWORD PTR [rbp+0x70],0x142 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337474ULL);
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
	/* 0x135: mov    DWORD PTR [rsp+0x10],0x142 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719477058ULL);
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
	/* 0x158: je     20e <syscall__execveat_enter+0x20e> */
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
	/* 0x170: je     20e <syscall__execveat_enter+0x20e> */
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
	/* 0x1e5: mov    QWORD PTR [rsp+0x58],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1ea:
	/* 0x1ea: mov    QWORD PTR [rsp+0xa0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1f2:
	/* 0x1f2: jne    21f <syscall__execveat_enter+0x21f> */
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
	/* 0x203: jne    a17 <syscall__execveat_enter+0xa17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2583ULL;
	}
x86_l_209:
	/* 0x209: jmp    1251 <syscall__execveat_enter+0x1251> */
	return 4689ULL;
x86_l_20e:
	/* 0x20e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_210:
	/* 0x210: jmp    1251 <syscall__execveat_enter+0x1251> */
	return 4689ULL;
x86_l_215:
	/* 0x215: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_21a:
	/* 0x21a: jmp    1251 <syscall__execveat_enter+0x1251> */
	return 4689ULL;
x86_l_21f:
	/* 0x21f: mov    rax,QWORD PTR [rbp+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_226:
	/* 0x226: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_229:
	/* 0x229: je     3d9 <syscall__execveat_enter+0x3d9> */
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
	/* 0x25e: je     284 <syscall__execveat_enter+0x284> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_284;
	}
x86_l_260:
	/* 0x260: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_262:
	/* 0x262: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
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
	/* 0x28e: je     2a9 <syscall__execveat_enter+0x2a9> */
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
	/* 0x2b3: je     2d1 <syscall__execveat_enter+0x2d1> */
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
	/* 0x2e6: je     446 <syscall__execveat_enter+0x446> */
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
	/* 0x30a: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
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
	/* 0x349: je     36b <syscall__execveat_enter+0x36b> */
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
	/* 0x35d: je     36b <syscall__execveat_enter+0x36b> */
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
	/* 0x369: jmp    36d <syscall__execveat_enter+0x36d> */
	goto x86_l_36d;
x86_l_36b:
	/* 0x36b: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36d:
	/* 0x36d: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_372:
	/* 0x372: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
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
	/* 0x382: jb     39a <syscall__execveat_enter+0x39a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_39a;
	}
x86_l_384:
	/* 0x384: cmp    rsi,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_388:
	/* 0x388: je     38f <syscall__execveat_enter+0x38f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38f;
	}
x86_l_38a:
	/* 0x38a: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_38d:
	/* 0x38d: jbe    39a <syscall__execveat_enter+0x39a> */
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
	/* 0x3b2: je     3f5 <syscall__execveat_enter+0x3f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f5;
	}
x86_l_3b4:
	/* 0x3b4: mov    QWORD PTR [rsp+0x60],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
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
	/* 0x3cb: je     401 <syscall__execveat_enter+0x401> */
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
	/* 0x3d7: jmp    403 <syscall__execveat_enter+0x403> */
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
	/* 0x3ea: jne    260 <syscall__execveat_enter+0x260> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_260;
	}
x86_l_3f0:
	/* 0x3f0: jmp    284 <syscall__execveat_enter+0x284> */
	goto x86_l_284;
x86_l_3f5:
	/* 0x3f5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f7:
	/* 0x3f7: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3ff:
	/* 0x3ff: jmp    415 <syscall__execveat_enter+0x415> */
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
	/* 0x410: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
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
	/* 0x420: jb     438 <syscall__execveat_enter+0x438> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_438;
	}
x86_l_422:
	/* 0x422: cmp    rsi,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_426:
	/* 0x426: je     42d <syscall__execveat_enter+0x42d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42d;
	}
x86_l_428:
	/* 0x428: cmp    rax,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_42b:
	/* 0x42b: jbe    438 <syscall__execveat_enter+0x438> */
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
	/* 0x44e: je     506 <syscall__execveat_enter+0x506> */
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
	/* 0x47f: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
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
	/* 0x4b2: je     4d1 <syscall__execveat_enter+0x4d1> */
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
	/* 0x4c3: je     4d1 <syscall__execveat_enter+0x4d1> */
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
	/* 0x4cf: jmp    4d3 <syscall__execveat_enter+0x4d3> */
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
	/* 0x4e1: jb     4fb <syscall__execveat_enter+0x4fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4fb;
	}
x86_l_4e3:
	/* 0x4e3: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4e8:
	/* 0x4e8: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_4ec:
	/* 0x4ec: je     4f3 <syscall__execveat_enter+0x4f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f3;
	}
x86_l_4ee:
	/* 0x4ee: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_4f1:
	/* 0x4f1: jbe    4fb <syscall__execveat_enter+0x4fb> */
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
	/* 0x50e: je     5e5 <syscall__execveat_enter+0x5e5> */
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
	/* 0x5b0: je     5d1 <syscall__execveat_enter+0x5d1> */
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
	/* 0x5c3: je     5d1 <syscall__execveat_enter+0x5d1> */
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
	/* 0x5cf: jmp    5d3 <syscall__execveat_enter+0x5d3> */
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
	/* 0x5ed: je     6e7 <syscall__execveat_enter+0x6e7> */
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
	/* 0x6b2: je     6d3 <syscall__execveat_enter+0x6d3> */
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

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_1(
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
	case 2594ULL: goto x86_l_a22;
	case 2601ULL: goto x86_l_a29;
	case 2603ULL: goto x86_l_a2b;
	case 2608ULL: goto x86_l_a30;
	case 2613ULL: goto x86_l_a35;
	case 2618ULL: goto x86_l_a3a;
	case 2627ULL: goto x86_l_a43;
	case 2634ULL: goto x86_l_a4a;
	case 2639ULL: goto x86_l_a4f;
	case 2644ULL: goto x86_l_a54;
	case 2646ULL: goto x86_l_a56;
	case 2650ULL: goto x86_l_a5a;
	case 2654ULL: goto x86_l_a5e;
	case 2661ULL: goto x86_l_a65;
	case 2666ULL: goto x86_l_a6a;
	case 2671ULL: goto x86_l_a6f;
	case 2676ULL: goto x86_l_a74;
	case 2678ULL: goto x86_l_a76;
	case 2681ULL: goto x86_l_a79;
	case 2683ULL: goto x86_l_a7b;
	case 2687ULL: goto x86_l_a7f;
	case 2695ULL: goto x86_l_a87;
	case 2701ULL: goto x86_l_a8d;
	case 2703ULL: goto x86_l_a8f;
	case 2707ULL: goto x86_l_a93;
	case 2711ULL: goto x86_l_a97;
	case 2716ULL: goto x86_l_a9c;
	case 2722ULL: goto x86_l_aa2;
	case 2726ULL: goto x86_l_aa6;
	case 2734ULL: goto x86_l_aae;
	case 2741ULL: goto x86_l_ab5;
	case 2748ULL: goto x86_l_abc;
	case 2755ULL: goto x86_l_ac3;
	case 2757ULL: goto x86_l_ac5;
	case 2760ULL: goto x86_l_ac8;
	case 2767ULL: goto x86_l_acf;
	case 2772ULL: goto x86_l_ad4;
	case 2777ULL: goto x86_l_ad9;
	case 2784ULL: goto x86_l_ae0;
	case 2788ULL: goto x86_l_ae4;
	case 2795ULL: goto x86_l_aeb;
	case 2800ULL: goto x86_l_af0;
	case 2802ULL: goto x86_l_af2;
	case 2804ULL: goto x86_l_af4;
	case 2806ULL: goto x86_l_af6;
	case 2809ULL: goto x86_l_af9;
	case 2816ULL: goto x86_l_b00;
	case 2818ULL: goto x86_l_b02;
	case 2825ULL: goto x86_l_b09;
	case 2832ULL: goto x86_l_b10;
	case 2835ULL: goto x86_l_b13;
	case 2842ULL: goto x86_l_b1a;
	case 2848ULL: goto x86_l_b20;
	case 2850ULL: goto x86_l_b22;
	case 2852ULL: goto x86_l_b24;
	case 2855ULL: goto x86_l_b27;
	case 2858ULL: goto x86_l_b2a;
	case 2863ULL: goto x86_l_b2f;
	case 2869ULL: goto x86_l_b35;
	case 2876ULL: goto x86_l_b3c;
	case 2884ULL: goto x86_l_b44;
	case 2892ULL: goto x86_l_b4c;
	case 2896ULL: goto x86_l_b50;
	case 2903ULL: goto x86_l_b57;
	case 2912ULL: goto x86_l_b60;
	case 2917ULL: goto x86_l_b65;
	case 2922ULL: goto x86_l_b6a;
	case 2927ULL: goto x86_l_b6f;
	case 2932ULL: goto x86_l_b74;
	case 2935ULL: goto x86_l_b77;
	case 2937ULL: goto x86_l_b79;
	case 2942ULL: goto x86_l_b7e;
	case 2945ULL: goto x86_l_b81;
	case 2947ULL: goto x86_l_b83;
	case 2950ULL: goto x86_l_b86;
	case 2956ULL: goto x86_l_b8c;
	case 2958ULL: goto x86_l_b8e;
	case 2962ULL: goto x86_l_b92;
	case 2969ULL: goto x86_l_b99;
	case 2974ULL: goto x86_l_b9e;
	case 2979ULL: goto x86_l_ba3;
	case 2986ULL: goto x86_l_baa;
	case 2990ULL: goto x86_l_bae;
	case 2997ULL: goto x86_l_bb5;
	case 3002ULL: goto x86_l_bba;
	case 3007ULL: goto x86_l_bbf;
	case 3009ULL: goto x86_l_bc1;
	case 3013ULL: goto x86_l_bc5;
	case 3015ULL: goto x86_l_bc7;
	case 3017ULL: goto x86_l_bc9;
	case 3020ULL: goto x86_l_bcc;
	case 3026ULL: goto x86_l_bd2;
	case 3032ULL: goto x86_l_bd8;
	case 3034ULL: goto x86_l_bda;
	case 3039ULL: goto x86_l_bdf;
	case 3044ULL: goto x86_l_be4;
	case 3051ULL: goto x86_l_beb;
	case 3056ULL: goto x86_l_bf0;
	case 3058ULL: goto x86_l_bf2;
	case 3066ULL: goto x86_l_bfa;
	case 3072ULL: goto x86_l_c00;
	case 3078ULL: goto x86_l_c06;
	case 3084ULL: goto x86_l_c0c;
	case 3087ULL: goto x86_l_c0f;
	case 3093ULL: goto x86_l_c15;
	case 3099ULL: goto x86_l_c1b;
	case 3106ULL: goto x86_l_c22;
	case 3114ULL: goto x86_l_c2a;
	case 3122ULL: goto x86_l_c32;
	case 3126ULL: goto x86_l_c36;
	case 3133ULL: goto x86_l_c3d;
	case 3142ULL: goto x86_l_c46;
	case 3147ULL: goto x86_l_c4b;
	case 3152ULL: goto x86_l_c50;
	case 3157ULL: goto x86_l_c55;
	case 3162ULL: goto x86_l_c5a;
	case 3165ULL: goto x86_l_c5d;
	case 3167ULL: goto x86_l_c5f;
	case 3172ULL: goto x86_l_c64;
	case 3175ULL: goto x86_l_c67;
	case 3177ULL: goto x86_l_c69;
	case 3180ULL: goto x86_l_c6c;
	case 3186ULL: goto x86_l_c72;
	case 3188ULL: goto x86_l_c74;
	case 3192ULL: goto x86_l_c78;
	case 3199ULL: goto x86_l_c7f;
	case 3204ULL: goto x86_l_c84;
	case 3209ULL: goto x86_l_c89;
	case 3216ULL: goto x86_l_c90;
	case 3220ULL: goto x86_l_c94;
	case 3227ULL: goto x86_l_c9b;
	case 3232ULL: goto x86_l_ca0;
	case 3237ULL: goto x86_l_ca5;
	case 3239ULL: goto x86_l_ca7;
	case 3243ULL: goto x86_l_cab;
	case 3245ULL: goto x86_l_cad;
	case 3247ULL: goto x86_l_caf;
	case 3250ULL: goto x86_l_cb2;
	case 3256ULL: goto x86_l_cb8;
	case 3262ULL: goto x86_l_cbe;
	case 3264ULL: goto x86_l_cc0;
	case 3269ULL: goto x86_l_cc5;
	case 3276ULL: goto x86_l_ccc;
	case 3281ULL: goto x86_l_cd1;
	case 3283ULL: goto x86_l_cd3;
	case 3291ULL: goto x86_l_cdb;
	case 3297ULL: goto x86_l_ce1;
	case 3300ULL: goto x86_l_ce4;
	case 3307ULL: goto x86_l_ceb;
	case 3309ULL: goto x86_l_ced;
	case 3317ULL: goto x86_l_cf5;
	case 3323ULL: goto x86_l_cfb;
	case 3325ULL: goto x86_l_cfd;
	case 3328ULL: goto x86_l_d00;
	case 3335ULL: goto x86_l_d07;
	case 3339ULL: goto x86_l_d0b;
	case 3346ULL: goto x86_l_d12;
	case 3351ULL: goto x86_l_d17;
	case 3356ULL: goto x86_l_d1c;
	case 3361ULL: goto x86_l_d21;
	case 3363ULL: goto x86_l_d23;
	case 3366ULL: goto x86_l_d26;
	case 3368ULL: goto x86_l_d28;
	case 3371ULL: goto x86_l_d2b;
	case 3378ULL: goto x86_l_d32;
	case 3384ULL: goto x86_l_d38;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6c0:
	/* 0x6c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c2:
	/* 0x6c2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6c5:
	/* 0x6c5: je     6d3 <syscall__execveat_enter+0x6d3> */
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
	/* 0x6d1: jmp    6d5 <syscall__execveat_enter+0x6d5> */
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
	/* 0x6ef: je     7d8 <syscall__execveat_enter+0x7d8> */
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
	/* 0x79f: je     7bf <syscall__execveat_enter+0x7bf> */
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
	/* 0x7b1: je     7bf <syscall__execveat_enter+0x7bf> */
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
	/* 0x7bd: jmp    7c1 <syscall__execveat_enter+0x7c1> */
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
	/* 0x7e0: je     86b <syscall__execveat_enter+0x86b> */
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
	/* 0x832: je     852 <syscall__execveat_enter+0x852> */
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
	/* 0x844: je     852 <syscall__execveat_enter+0x852> */
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
	/* 0x850: jmp    854 <syscall__execveat_enter+0x854> */
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
	/* 0x875: je     8e1 <syscall__execveat_enter+0x8e1> */
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
	/* 0x8ab: je     8cd <syscall__execveat_enter+0x8cd> */
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
	/* 0x8bf: je     8cd <syscall__execveat_enter+0x8cd> */
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
	/* 0x8cb: jmp    8cf <syscall__execveat_enter+0x8cf> */
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
	/* 0x8eb: je     94e <syscall__execveat_enter+0x94e> */
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
	/* 0x91a: je     93a <syscall__execveat_enter+0x93a> */
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
	/* 0x92c: je     93a <syscall__execveat_enter+0x93a> */
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
	/* 0x938: jmp    93c <syscall__execveat_enter+0x93c> */
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
	/* 0x958: je     9df <syscall__execveat_enter+0x9df> */
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
	/* 0x98b: je     9cc <syscall__execveat_enter+0x9cc> */
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
	/* 0x9a6: jne    9c0 <syscall__execveat_enter+0x9c0> */
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
	/* 0x9be: je     9cc <syscall__execveat_enter+0x9cc> */
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
	/* 0x9ca: jmp    9ce <syscall__execveat_enter+0x9ce> */
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
	/* 0x9e9: je     9f7 <syscall__execveat_enter+0x9f7> */
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
	/* 0xa11: je     1251 <syscall__execveat_enter+0x1251> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4689ULL;
	}
x86_l_a17:
	/* 0xa17: lea    rbx,[rbp+0x7d8a] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_a1e:
	/* 0xa1e: movzx  r14d,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_a22:
	/* 0xa22: cmp    r14,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 32000ULL);
x86_l_a29:
	/* 0xa29: jb     a3a <syscall__execveat_enter+0xa3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_a3a;
	}
x86_l_a2b:
	/* 0xa2b: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a30:
	/* 0xa30: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a35:
	/* 0xa35: jmp    c00 <syscall__execveat_enter+0xc00> */
	goto x86_l_c00;
x86_l_a3a:
	/* 0xa3a: mov    BYTE PTR [rbp+r14*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R14, 0), 588410519552ULL);
x86_l_a43:
	/* 0xa43: cmp    r14d,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 31995ULL);
x86_l_a4a:
	/* 0xa4a: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a4f:
	/* 0xa4f: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a54:
	/* 0xa54: ja     a8f <syscall__execveat_enter+0xa8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_a8f;
	}
x86_l_a56:
	/* 0xa56: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a5a:
	/* 0xa5a: lea    rdi,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_a5e:
	/* 0xa5e: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_a65:
	/* 0xa65: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a6a:
	/* 0xa6a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a6f:
	/* 0xa6f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a74:
	/* 0xa74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a76:
	/* 0xa76: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a79:
	/* 0xa79: js     a8f <syscall__execveat_enter+0xa8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_a8f;
	}
x86_l_a7b:
	/* 0xa7b: add    r14d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_a7f:
	/* 0xa7f: mov    WORD PTR [rbp+0x7d8a],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_a87:
	/* 0xa87: inc    BYTE PTR [rbp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_a8d:
	/* 0xa8d: jmp    a93 <syscall__execveat_enter+0xa93> */
	goto x86_l_a93;
x86_l_a8f:
	/* 0xa8f: movzx  r14d,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_a93:
	/* 0xa93: movzx  eax,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_a97:
	/* 0xa97: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_a9c:
	/* 0xa9c: jae    c00 <syscall__execveat_enter+0xc00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_c00;
	}
x86_l_aa2:
	/* 0xaa2: mov    rdx,QWORD PTR [r13+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_aa6:
	/* 0xaa6: mov    BYTE PTR [rbp+rax*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519553ULL);
x86_l_aae:
	/* 0xaae: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_ab5:
	/* 0xab5: mov    WORD PTR [rbp+0x7d8e],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32142ULL);
x86_l_abc:
	/* 0xabc: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_ac3:
	/* 0xac3: ja     b27 <syscall__execveat_enter+0xb27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b27;
	}
x86_l_ac5:
	/* 0xac5: add    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ac8:
	/* 0xac8: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_acf:
	/* 0xacf: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_ad4:
	/* 0xad4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_ad9:
	/* 0xad9: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_ae0:
	/* 0xae0: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_ae4:
	/* 0xae4: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_aeb:
	/* 0xaeb: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_af0:
	/* 0xaf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af2:
	/* 0xaf2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_af4:
	/* 0xaf4: jle    b24 <syscall__execveat_enter+0xb24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_b24;
	}
x86_l_af6:
	/* 0xaf6: movzx  ecx,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_af9:
	/* 0xaf9: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_b00:
	/* 0xb00: ja     b27 <syscall__execveat_enter+0xb27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b27;
	}
x86_l_b02:
	/* 0xb02: mov    DWORD PTR [rcx+rbp*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 138ULL);
x86_l_b09:
	/* 0xb09: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_b10:
	/* 0xb10: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_b13:
	/* 0xb13: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_b1a:
	/* 0xb1a: inc    BYTE PTR [rbp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_b20:
	/* 0xb20: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_b22:
	/* 0xb22: jmp    b27 <syscall__execveat_enter+0xb27> */
	goto x86_l_b27;
x86_l_b24:
	/* 0xb24: movzx  ecx,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b27:
	/* 0xb27: movzx  eax,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_b2a:
	/* 0xb2a: cmp    eax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31999ULL);
x86_l_b2f:
	/* 0xb2f: ja     c00 <syscall__execveat_enter+0xc00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_c00;
	}
x86_l_b35:
	/* 0xb35: mov    r13,QWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b3c:
	/* 0xb3c: mov    BYTE PTR [rbp+rax*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519554ULL);
x86_l_b44:
	/* 0xb44: movzx  r15d,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_b4c:
	/* 0xb4c: lea    eax,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_b50:
	/* 0xb50: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_b57:
	/* 0xb57: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_b60:
	/* 0xb60: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b65:
	/* 0xb65: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b6a:
	/* 0xb6a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b6f:
	/* 0xb6f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b74:
	/* 0xb74: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_b77:
	/* 0xb77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b79:
	/* 0xb79: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b7e:
	/* 0xb7e: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_b81:
	/* 0xb81: je     bd8 <syscall__execveat_enter+0xbd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bd8;
	}
x86_l_b83:
	/* 0xb83: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b86:
	/* 0xb86: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_b8c:
	/* 0xb8c: ja     bd8 <syscall__execveat_enter+0xbd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_bd8;
	}
x86_l_b8e:
	/* 0xb8e: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_b92:
	/* 0xb92: add    rdx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_b99:
	/* 0xb99: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_b9e:
	/* 0xb9e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_ba3:
	/* 0xba3: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_baa:
	/* 0xbaa: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_bae:
	/* 0xbae: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_bb5:
	/* 0xbb5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bba:
	/* 0xbba: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_bbf:
	/* 0xbbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bc1:
	/* 0xbc1: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bc5:
	/* 0xbc5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bc7:
	/* 0xbc7: jle    bd8 <syscall__execveat_enter+0xbd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_bd8;
	}
x86_l_bc9:
	/* 0xbc9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_bcc:
	/* 0xbcc: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_bd2:
	/* 0xbd2: jbe    3528 <syscall__execveat_enter+0x3528> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 13608ULL;
	}
x86_l_bd8:
	/* 0xbd8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bda:
	/* 0xbda: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_bdf:
	/* 0xbdf: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_be4:
	/* 0xbe4: cmp    r15d,0x7cfe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 31998ULL);
x86_l_beb:
	/* 0xbeb: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bf0:
	/* 0xbf0: ja     c00 <syscall__execveat_enter+0xc00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_c00;
	}
x86_l_bf2:
	/* 0xbf2: mov    BYTE PTR [rbp+r15*1+0x8a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 138ULL);
x86_l_bfa:
	/* 0xbfa: inc    BYTE PTR [rbp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_c00:
	/* 0xc00: test   BYTE PTR [r12+0x4],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869185ULL);
x86_l_c06:
	/* 0xc06: je     ce1 <syscall__execveat_enter+0xce1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ce1;
	}
x86_l_c0c:
	/* 0xc0c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c0f:
	/* 0xc0f: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_c15:
	/* 0xc15: ja     ce1 <syscall__execveat_enter+0xce1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ce1;
	}
x86_l_c1b:
	/* 0xc1b: mov    r13,QWORD PTR [r13+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c22:
	/* 0xc22: mov    BYTE PTR [rbp+rax*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519555ULL);
x86_l_c2a:
	/* 0xc2a: movzx  r15d,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_c32:
	/* 0xc32: lea    eax,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_c36:
	/* 0xc36: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_c3d:
	/* 0xc3d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_c46:
	/* 0xc46: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c4b:
	/* 0xc4b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c50:
	/* 0xc50: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c55:
	/* 0xc55: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c5a:
	/* 0xc5a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_c5d:
	/* 0xc5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c5f:
	/* 0xc5f: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c64:
	/* 0xc64: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_c67:
	/* 0xc67: je     cbe <syscall__execveat_enter+0xcbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cbe;
	}
x86_l_c69:
	/* 0xc69: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c6c:
	/* 0xc6c: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_c72:
	/* 0xc72: ja     cbe <syscall__execveat_enter+0xcbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_cbe;
	}
x86_l_c74:
	/* 0xc74: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_c78:
	/* 0xc78: add    rdx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_c7f:
	/* 0xc7f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_c84:
	/* 0xc84: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_c89:
	/* 0xc89: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_c90:
	/* 0xc90: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_c94:
	/* 0xc94: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_c9b:
	/* 0xc9b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ca0:
	/* 0xca0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_ca5:
	/* 0xca5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ca7:
	/* 0xca7: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_cab:
	/* 0xcab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cad:
	/* 0xcad: jle    cbe <syscall__execveat_enter+0xcbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_cbe;
	}
x86_l_caf:
	/* 0xcaf: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_cb2:
	/* 0xcb2: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_cb8:
	/* 0xcb8: jbe    1267 <syscall__execveat_enter+0x1267> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 4711ULL;
	}
x86_l_cbe:
	/* 0xcbe: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cc0:
	/* 0xcc0: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_cc5:
	/* 0xcc5: cmp    r15d,0x7cfe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 31998ULL);
x86_l_ccc:
	/* 0xccc: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cd1:
	/* 0xcd1: ja     ce1 <syscall__execveat_enter+0xce1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ce1;
	}
x86_l_cd3:
	/* 0xcd3: mov    BYTE PTR [rbp+r15*1+0x8a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 138ULL);
x86_l_cdb:
	/* 0xcdb: inc    BYTE PTR [rbp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_ce1:
	/* 0xce1: movzx  ebx,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_ce4:
	/* 0xce4: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_ceb:
	/* 0xceb: ja     d38 <syscall__execveat_enter+0xd38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_d38;
	}
x86_l_ced:
	/* 0xced: mov    BYTE PTR [rbp+rbx*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519556ULL);
x86_l_cf5:
	/* 0xcf5: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_cfb:
	/* 0xcfb: ja     d38 <syscall__execveat_enter+0xd38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_d38;
	}
x86_l_cfd:
	/* 0xcfd: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_d00:
	/* 0xd00: add    rdx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_d07:
	/* 0xd07: lea    rdi,[rbx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_d0b:
	/* 0xd0b: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_d12:
	/* 0xd12: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d17:
	/* 0xd17: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d1c:
	/* 0xd1c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d21:
	/* 0xd21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d23:
	/* 0xd23: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d26:
	/* 0xd26: js     d38 <syscall__execveat_enter+0xd38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_d38;
	}
x86_l_d28:
	/* 0xd28: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_d2b:
	/* 0xd2b: mov    WORD PTR [rbp+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_d32:
	/* 0xd32: inc    BYTE PTR [rbp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_d38:
	/* 0xd38: mov    rbx,QWORD PTR [rbp+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
	return 3391ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3391ULL: goto x86_l_d3f;
	case 3395ULL: goto x86_l_d43;
	case 3400ULL: goto x86_l_d48;
	case 3405ULL: goto x86_l_d4d;
	case 3410ULL: goto x86_l_d52;
	case 3415ULL: goto x86_l_d57;
	case 3418ULL: goto x86_l_d5a;
	case 3420ULL: goto x86_l_d5c;
	case 3425ULL: goto x86_l_d61;
	case 3430ULL: goto x86_l_d66;
	case 3434ULL: goto x86_l_d6a;
	case 3439ULL: goto x86_l_d6f;
	case 3444ULL: goto x86_l_d74;
	case 3449ULL: goto x86_l_d79;
	case 3454ULL: goto x86_l_d7e;
	case 3456ULL: goto x86_l_d80;
	case 3461ULL: goto x86_l_d85;
	case 3465ULL: goto x86_l_d89;
	case 3470ULL: goto x86_l_d8e;
	case 3475ULL: goto x86_l_d93;
	case 3480ULL: goto x86_l_d98;
	case 3485ULL: goto x86_l_d9d;
	case 3487ULL: goto x86_l_d9f;
	case 3490ULL: goto x86_l_da2;
	case 3495ULL: goto x86_l_da7;
	case 3499ULL: goto x86_l_dab;
	case 3504ULL: goto x86_l_db0;
	case 3509ULL: goto x86_l_db5;
	case 3514ULL: goto x86_l_dba;
	case 3519ULL: goto x86_l_dbf;
	case 3521ULL: goto x86_l_dc1;
	case 3525ULL: goto x86_l_dc5;
	case 3529ULL: goto x86_l_dc9;
	case 3533ULL: goto x86_l_dcd;
	case 3538ULL: goto x86_l_dd2;
	case 3543ULL: goto x86_l_dd7;
	case 3548ULL: goto x86_l_ddc;
	case 3553ULL: goto x86_l_de1;
	case 3556ULL: goto x86_l_de4;
	case 3558ULL: goto x86_l_de6;
	case 3563ULL: goto x86_l_deb;
	case 3568ULL: goto x86_l_df0;
	case 3573ULL: goto x86_l_df5;
	case 3578ULL: goto x86_l_dfa;
	case 3583ULL: goto x86_l_dff;
	case 3586ULL: goto x86_l_e02;
	case 3588ULL: goto x86_l_e04;
	case 3592ULL: goto x86_l_e08;
	case 3596ULL: goto x86_l_e0c;
	case 3600ULL: goto x86_l_e10;
	case 3604ULL: goto x86_l_e14;
	case 3609ULL: goto x86_l_e19;
	case 3614ULL: goto x86_l_e1e;
	case 3619ULL: goto x86_l_e23;
	case 3624ULL: goto x86_l_e28;
	case 3626ULL: goto x86_l_e2a;
	case 3630ULL: goto x86_l_e2e;
	case 3634ULL: goto x86_l_e32;
	case 3639ULL: goto x86_l_e37;
	case 3644ULL: goto x86_l_e3c;
	case 3649ULL: goto x86_l_e41;
	case 3654ULL: goto x86_l_e46;
	case 3657ULL: goto x86_l_e49;
	case 3659ULL: goto x86_l_e4b;
	case 3664ULL: goto x86_l_e50;
	case 3668ULL: goto x86_l_e54;
	case 3673ULL: goto x86_l_e59;
	case 3678ULL: goto x86_l_e5e;
	case 3683ULL: goto x86_l_e63;
	case 3688ULL: goto x86_l_e68;
	case 3690ULL: goto x86_l_e6a;
	case 3695ULL: goto x86_l_e6f;
	case 3700ULL: goto x86_l_e74;
	case 3705ULL: goto x86_l_e79;
	case 3710ULL: goto x86_l_e7e;
	case 3715ULL: goto x86_l_e83;
	case 3718ULL: goto x86_l_e86;
	case 3720ULL: goto x86_l_e88;
	case 3724ULL: goto x86_l_e8c;
	case 3728ULL: goto x86_l_e90;
	case 3732ULL: goto x86_l_e94;
	case 3736ULL: goto x86_l_e98;
	case 3741ULL: goto x86_l_e9d;
	case 3746ULL: goto x86_l_ea2;
	case 3751ULL: goto x86_l_ea7;
	case 3756ULL: goto x86_l_eac;
	case 3758ULL: goto x86_l_eae;
	case 3762ULL: goto x86_l_eb2;
	case 3766ULL: goto x86_l_eb6;
	case 3771ULL: goto x86_l_ebb;
	case 3776ULL: goto x86_l_ec0;
	case 3781ULL: goto x86_l_ec5;
	case 3786ULL: goto x86_l_eca;
	case 3789ULL: goto x86_l_ecd;
	case 3791ULL: goto x86_l_ecf;
	case 3796ULL: goto x86_l_ed4;
	case 3801ULL: goto x86_l_ed9;
	case 3806ULL: goto x86_l_ede;
	case 3811ULL: goto x86_l_ee3;
	case 3816ULL: goto x86_l_ee8;
	case 3819ULL: goto x86_l_eeb;
	case 3821ULL: goto x86_l_eed;
	case 3825ULL: goto x86_l_ef1;
	case 3829ULL: goto x86_l_ef5;
	case 3833ULL: goto x86_l_ef9;
	case 3837ULL: goto x86_l_efd;
	case 3842ULL: goto x86_l_f02;
	case 3847ULL: goto x86_l_f07;
	case 3852ULL: goto x86_l_f0c;
	case 3857ULL: goto x86_l_f11;
	case 3859ULL: goto x86_l_f13;
	case 3864ULL: goto x86_l_f18;
	case 3868ULL: goto x86_l_f1c;
	case 3873ULL: goto x86_l_f21;
	case 3878ULL: goto x86_l_f26;
	case 3883ULL: goto x86_l_f2b;
	case 3888ULL: goto x86_l_f30;
	case 3890ULL: goto x86_l_f32;
	case 3895ULL: goto x86_l_f37;
	case 3899ULL: goto x86_l_f3b;
	case 3904ULL: goto x86_l_f40;
	case 3909ULL: goto x86_l_f45;
	case 3914ULL: goto x86_l_f4a;
	case 3919ULL: goto x86_l_f4f;
	case 3922ULL: goto x86_l_f52;
	case 3924ULL: goto x86_l_f54;
	case 3929ULL: goto x86_l_f59;
	case 3934ULL: goto x86_l_f5e;
	case 3939ULL: goto x86_l_f63;
	case 3944ULL: goto x86_l_f68;
	case 3949ULL: goto x86_l_f6d;
	case 3952ULL: goto x86_l_f70;
	case 3954ULL: goto x86_l_f72;
	case 3958ULL: goto x86_l_f76;
	case 3962ULL: goto x86_l_f7a;
	case 3966ULL: goto x86_l_f7e;
	case 3970ULL: goto x86_l_f82;
	case 3975ULL: goto x86_l_f87;
	case 3980ULL: goto x86_l_f8c;
	case 3985ULL: goto x86_l_f91;
	case 3990ULL: goto x86_l_f96;
	case 3992ULL: goto x86_l_f98;
	case 3997ULL: goto x86_l_f9d;
	case 4001ULL: goto x86_l_fa1;
	case 4006ULL: goto x86_l_fa6;
	case 4011ULL: goto x86_l_fab;
	case 4016ULL: goto x86_l_fb0;
	case 4021ULL: goto x86_l_fb5;
	case 4023ULL: goto x86_l_fb7;
	case 4028ULL: goto x86_l_fbc;
	case 4030ULL: goto x86_l_fbe;
	case 4035ULL: goto x86_l_fc3;
	case 4040ULL: goto x86_l_fc8;
	case 4045ULL: goto x86_l_fcd;
	case 4050ULL: goto x86_l_fd2;
	case 4053ULL: goto x86_l_fd5;
	case 4055ULL: goto x86_l_fd7;
	case 4060ULL: goto x86_l_fdc;
	case 4065ULL: goto x86_l_fe1;
	case 4070ULL: goto x86_l_fe6;
	case 4075ULL: goto x86_l_feb;
	case 4080ULL: goto x86_l_ff0;
	case 4083ULL: goto x86_l_ff3;
	case 4085ULL: goto x86_l_ff5;
	case 4089ULL: goto x86_l_ff9;
	case 4093ULL: goto x86_l_ffd;
	case 4097ULL: goto x86_l_1001;
	case 4101ULL: goto x86_l_1005;
	case 4106ULL: goto x86_l_100a;
	case 4111ULL: goto x86_l_100f;
	case 4116ULL: goto x86_l_1014;
	case 4121ULL: goto x86_l_1019;
	case 4123ULL: goto x86_l_101b;
	case 4127ULL: goto x86_l_101f;
	case 4131ULL: goto x86_l_1023;
	case 4135ULL: goto x86_l_1027;
	case 4142ULL: goto x86_l_102e;
	case 4147ULL: goto x86_l_1033;
	case 4152ULL: goto x86_l_1038;
	case 4157ULL: goto x86_l_103d;
	case 4161ULL: goto x86_l_1041;
	case 4166ULL: goto x86_l_1046;
	case 4169ULL: goto x86_l_1049;
	case 4171ULL: goto x86_l_104b;
	case 4176ULL: goto x86_l_1050;
	case 4180ULL: goto x86_l_1054;
	case 4185ULL: goto x86_l_1059;
	case 4190ULL: goto x86_l_105e;
	case 4195ULL: goto x86_l_1063;
	case 4200ULL: goto x86_l_1068;
	case 4202ULL: goto x86_l_106a;
	case 4207ULL: goto x86_l_106f;
	case 4212ULL: goto x86_l_1074;
	case 4217ULL: goto x86_l_1079;
	case 4222ULL: goto x86_l_107e;
	case 4227ULL: goto x86_l_1083;
	case 4232ULL: goto x86_l_1088;
	case 4234ULL: goto x86_l_108a;
	case 4238ULL: goto x86_l_108e;
	case 4242ULL: goto x86_l_1092;
	case 4247ULL: goto x86_l_1097;
	case 4249ULL: goto x86_l_1099;
	case 4253ULL: goto x86_l_109d;
	case 4257ULL: goto x86_l_10a1;
	case 4262ULL: goto x86_l_10a6;
	case 4267ULL: goto x86_l_10ab;
	case 4272ULL: goto x86_l_10b0;
	case 4277ULL: goto x86_l_10b5;
	case 4279ULL: goto x86_l_10b7;
	case 4284ULL: goto x86_l_10bc;
	case 4288ULL: goto x86_l_10c0;
	case 4293ULL: goto x86_l_10c5;
	case 4297ULL: goto x86_l_10c9;
	case 4302ULL: goto x86_l_10ce;
	case 4307ULL: goto x86_l_10d3;
	case 4312ULL: goto x86_l_10d8;
	case 4317ULL: goto x86_l_10dd;
	case 4319ULL: goto x86_l_10df;
	case 4324ULL: goto x86_l_10e4;
	case 4328ULL: goto x86_l_10e8;
	case 4332ULL: goto x86_l_10ec;
	case 4337ULL: goto x86_l_10f1;
	case 4342ULL: goto x86_l_10f6;
	case 4347ULL: goto x86_l_10fb;
	case 4352ULL: goto x86_l_1100;
	case 4355ULL: goto x86_l_1103;
	case 4357ULL: goto x86_l_1105;
	case 4362ULL: goto x86_l_110a;
	case 4366ULL: goto x86_l_110e;
	case 4371ULL: goto x86_l_1113;
	case 4376ULL: goto x86_l_1118;
	case 4381ULL: goto x86_l_111d;
	case 4386ULL: goto x86_l_1122;
	case 4389ULL: goto x86_l_1125;
	case 4391ULL: goto x86_l_1127;
	case 4396ULL: goto x86_l_112c;
	case 4398ULL: goto x86_l_112e;
	case 4403ULL: goto x86_l_1133;
	case 4411ULL: goto x86_l_113b;
	case 4415ULL: goto x86_l_113f;
	case 4423ULL: goto x86_l_1147;
	case 4428ULL: goto x86_l_114c;
	case 4433ULL: goto x86_l_1151;
	case 4438ULL: goto x86_l_1156;
	case 4440ULL: goto x86_l_1158;
	case 4445ULL: goto x86_l_115d;
	case 4450ULL: goto x86_l_1162;
	case 4455ULL: goto x86_l_1167;
	case 4460ULL: goto x86_l_116c;
	case 4463ULL: goto x86_l_116f;
	case 4465ULL: goto x86_l_1171;
	case 4470ULL: goto x86_l_1176;
	case 4475ULL: goto x86_l_117b;
	case 4480ULL: goto x86_l_1180;
	case 4485ULL: goto x86_l_1185;
	case 4490ULL: goto x86_l_118a;
	case 4492ULL: goto x86_l_118c;
	case 4497ULL: goto x86_l_1191;
	case 4502ULL: goto x86_l_1196;
	case 4507ULL: goto x86_l_119b;
	case 4512ULL: goto x86_l_11a0;
	case 4515ULL: goto x86_l_11a3;
	case 4520ULL: goto x86_l_11a8;
	case 4522ULL: goto x86_l_11aa;
	case 4525ULL: goto x86_l_11ad;
	case 4529ULL: goto x86_l_11b1;
	case 4534ULL: goto x86_l_11b6;
	case 4539ULL: goto x86_l_11bb;
	case 4544ULL: goto x86_l_11c0;
	case 4547ULL: goto x86_l_11c3;
	case 4549ULL: goto x86_l_11c5;
	case 4554ULL: goto x86_l_11ca;
	case 4559ULL: goto x86_l_11cf;
	case 4564ULL: goto x86_l_11d4;
	case 4569ULL: goto x86_l_11d9;
	case 4572ULL: goto x86_l_11dc;
	case 4574ULL: goto x86_l_11de;
	case 4579ULL: goto x86_l_11e3;
	case 4583ULL: goto x86_l_11e7;
	case 4591ULL: goto x86_l_11ef;
	case 4593ULL: goto x86_l_11f1;
	case 4600ULL: goto x86_l_11f8;
	case 4605ULL: goto x86_l_11fd;
	case 4610ULL: goto x86_l_1202;
	case 4615ULL: goto x86_l_1207;
	case 4618ULL: goto x86_l_120a;
	case 4620ULL: goto x86_l_120c;
	case 4622ULL: goto x86_l_120e;
	case 4624ULL: goto x86_l_1210;
	case 4628ULL: goto x86_l_1214;
	case 4636ULL: goto x86_l_121c;
	case 4641ULL: goto x86_l_1221;
	case 4646ULL: goto x86_l_1226;
	case 4649ULL: goto x86_l_1229;
	case 4655ULL: goto x86_l_122f;
	case 4659ULL: goto x86_l_1233;
	case 4666ULL: goto x86_l_123a;
	case 4671ULL: goto x86_l_123f;
	case 4676ULL: goto x86_l_1244;
	case 4681ULL: goto x86_l_1249;
	case 4684ULL: goto x86_l_124c;
	case 4687ULL: goto x86_l_124f;
	case 4689ULL: goto x86_l_1251;
	case 4696ULL: goto x86_l_1258;
	case 4697ULL: goto x86_l_1259;
	case 4699ULL: goto x86_l_125b;
	case 4701ULL: goto x86_l_125d;
	case 4703ULL: goto x86_l_125f;
	case 4705ULL: goto x86_l_1261;
	case 4706ULL: goto x86_l_1262;
	case 4711ULL: goto x86_l_1267;
	case 4715ULL: goto x86_l_126b;
	case 4722ULL: goto x86_l_1272;
	case 4727ULL: goto x86_l_1277;
	case 4732ULL: goto x86_l_127c;
	case 4737ULL: goto x86_l_1281;
	case 4744ULL: goto x86_l_1288;
	case 4748ULL: goto x86_l_128c;
	case 4755ULL: goto x86_l_1293;
	case 4760ULL: goto x86_l_1298;
	case 4762ULL: goto x86_l_129a;
	case 4767ULL: goto x86_l_129f;
	case 4774ULL: goto x86_l_12a6;
	case 4777ULL: goto x86_l_12a9;
	case 4784ULL: goto x86_l_12b0;
	case 4793ULL: goto x86_l_12b9;
	case 4797ULL: goto x86_l_12bd;
	case 4802ULL: goto x86_l_12c2;
	case 4807ULL: goto x86_l_12c7;
	case 4812ULL: goto x86_l_12cc;
	case 4817ULL: goto x86_l_12d1;
	case 4819ULL: goto x86_l_12d3;
	case 4824ULL: goto x86_l_12d8;
	case 4826ULL: goto x86_l_12da;
	case 4829ULL: goto x86_l_12dd;
	case 4835ULL: goto x86_l_12e3;
	case 4838ULL: goto x86_l_12e6;
	case 4844ULL: goto x86_l_12ec;
	case 4850ULL: goto x86_l_12f2;
	case 4855ULL: goto x86_l_12f7;
	case 4859ULL: goto x86_l_12fb;
	case 4866ULL: goto x86_l_1302;
	case 4871ULL: goto x86_l_1307;
	case 4876ULL: goto x86_l_130c;
	case 4883ULL: goto x86_l_1313;
	case 4886ULL: goto x86_l_1316;
	case 4893ULL: goto x86_l_131d;
	case 4898ULL: goto x86_l_1322;
	case 4903ULL: goto x86_l_1327;
	case 4905ULL: goto x86_l_1329;
	case 4909ULL: goto x86_l_132d;
	case 4911ULL: goto x86_l_132f;
	case 4913ULL: goto x86_l_1331;
	case 4919ULL: goto x86_l_1337;
	case 4922ULL: goto x86_l_133a;
	case 4928ULL: goto x86_l_1340;
	case 4934ULL: goto x86_l_1346;
	case 4939ULL: goto x86_l_134b;
	case 4943ULL: goto x86_l_134f;
	case 4950ULL: goto x86_l_1356;
	case 4955ULL: goto x86_l_135b;
	case 4960ULL: goto x86_l_1360;
	case 4965ULL: goto x86_l_1365;
	case 4973ULL: goto x86_l_136d;
	case 4977ULL: goto x86_l_1371;
	case 4984ULL: goto x86_l_1378;
	case 4989ULL: goto x86_l_137d;
	case 4991ULL: goto x86_l_137f;
	case 4996ULL: goto x86_l_1384;
	case 5004ULL: goto x86_l_138c;
	case 5007ULL: goto x86_l_138f;
	case 5015ULL: goto x86_l_1397;
	case 5024ULL: goto x86_l_13a0;
	case 5028ULL: goto x86_l_13a4;
	case 5033ULL: goto x86_l_13a9;
	case 5038ULL: goto x86_l_13ae;
	case 5043ULL: goto x86_l_13b3;
	case 5048ULL: goto x86_l_13b8;
	case 5050ULL: goto x86_l_13ba;
	case 5055ULL: goto x86_l_13bf;
	case 5057ULL: goto x86_l_13c1;
	case 5060ULL: goto x86_l_13c4;
	case 5066ULL: goto x86_l_13ca;
	case 5069ULL: goto x86_l_13cd;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d3f:
	/* 0xd3f: lea    r15,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d43:
	/* 0xd43: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d48:
	/* 0xd48: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d4d:
	/* 0xd4d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d52:
	/* 0xd52: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d57:
	/* 0xd57: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_d5a:
	/* 0xd5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d5c:
	/* 0xd5c: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d61:
	/* 0xd61: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_d66:
	/* 0xd66: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d6a:
	/* 0xd6a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d6f:
	/* 0xd6f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d74:
	/* 0xd74: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d79:
	/* 0xd79: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d7e:
	/* 0xd7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d80:
	/* 0xd80: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d85:
	/* 0xd85: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_d89:
	/* 0xd89: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d8e:
	/* 0xd8e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d93:
	/* 0xd93: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d98:
	/* 0xd98: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d9d:
	/* 0xd9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d9f:
	/* 0xd9f: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_da2:
	/* 0xda2: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_da7:
	/* 0xda7: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_dab:
	/* 0xdab: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_db0:
	/* 0xdb0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_db5:
	/* 0xdb5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_dba:
	/* 0xdba: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_dbf:
	/* 0xdbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dc1:
	/* 0xdc1: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dc5:
	/* 0xdc5: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_dc9:
	/* 0xdc9: lea    r12,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dcd:
	/* 0xdcd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dd2:
	/* 0xdd2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_dd7:
	/* 0xdd7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ddc:
	/* 0xddc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_de1:
	/* 0xde1: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_de4:
	/* 0xde4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_de6:
	/* 0xde6: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_deb:
	/* 0xdeb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_df0:
	/* 0xdf0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_df5:
	/* 0xdf5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_dfa:
	/* 0xdfa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_dff:
	/* 0xdff: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_e02:
	/* 0xe02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e04:
	/* 0xe04: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e08:
	/* 0xe08: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_e0c:
	/* 0xe0c: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_e10:
	/* 0xe10: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_e14:
	/* 0xe14: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e19:
	/* 0xe19: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e1e:
	/* 0xe1e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e23:
	/* 0xe23: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e28:
	/* 0xe28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e2a:
	/* 0xe2a: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e2e:
	/* 0xe2e: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_e32:
	/* 0xe32: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e37:
	/* 0xe37: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e3c:
	/* 0xe3c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e41:
	/* 0xe41: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e46:
	/* 0xe46: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e49:
	/* 0xe49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e4b:
	/* 0xe4b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e50:
	/* 0xe50: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_e54:
	/* 0xe54: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e59:
	/* 0xe59: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e5e:
	/* 0xe5e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e63:
	/* 0xe63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e68:
	/* 0xe68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e6a:
	/* 0xe6a: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e6f:
	/* 0xe6f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e74:
	/* 0xe74: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e79:
	/* 0xe79: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e7e:
	/* 0xe7e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e83:
	/* 0xe83: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e86:
	/* 0xe86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e88:
	/* 0xe88: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e8c:
	/* 0xe8c: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_e90:
	/* 0xe90: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_e94:
	/* 0xe94: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_e98:
	/* 0xe98: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e9d:
	/* 0xe9d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ea2:
	/* 0xea2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ea7:
	/* 0xea7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_eac:
	/* 0xeac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eae:
	/* 0xeae: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eb2:
	/* 0xeb2: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_eb6:
	/* 0xeb6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ebb:
	/* 0xebb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ec0:
	/* 0xec0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ec5:
	/* 0xec5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_eca:
	/* 0xeca: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_ecd:
	/* 0xecd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ecf:
	/* 0xecf: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ed4:
	/* 0xed4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ed9:
	/* 0xed9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ede:
	/* 0xede: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ee3:
	/* 0xee3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ee8:
	/* 0xee8: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_eeb:
	/* 0xeeb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eed:
	/* 0xeed: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ef1:
	/* 0xef1: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_ef5:
	/* 0xef5: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_ef9:
	/* 0xef9: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_efd:
	/* 0xefd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f02:
	/* 0xf02: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f07:
	/* 0xf07: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f0c:
	/* 0xf0c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f11:
	/* 0xf11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f13:
	/* 0xf13: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f18:
	/* 0xf18: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_f1c:
	/* 0xf1c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f21:
	/* 0xf21: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f26:
	/* 0xf26: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f2b:
	/* 0xf2b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f30:
	/* 0xf30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f32:
	/* 0xf32: mov    r13d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f37:
	/* 0xf37: lea    r15,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f3b:
	/* 0xf3b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f40:
	/* 0xf40: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f45:
	/* 0xf45: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f4a:
	/* 0xf4a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f4f:
	/* 0xf4f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_f52:
	/* 0xf52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f54:
	/* 0xf54: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f59:
	/* 0xf59: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f5e:
	/* 0xf5e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f63:
	/* 0xf63: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f68:
	/* 0xf68: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f6d:
	/* 0xf6d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_f70:
	/* 0xf70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f72:
	/* 0xf72: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f76:
	/* 0xf76: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_f7a:
	/* 0xf7a: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_f7e:
	/* 0xf7e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f82:
	/* 0xf82: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f87:
	/* 0xf87: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f8c:
	/* 0xf8c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f91:
	/* 0xf91: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f96:
	/* 0xf96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f98:
	/* 0xf98: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f9d:
	/* 0xf9d: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_fa1:
	/* 0xfa1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fa6:
	/* 0xfa6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_fab:
	/* 0xfab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fb0:
	/* 0xfb0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fb5:
	/* 0xfb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb7:
	/* 0xfb7: cmp    r13d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_fbc:
	/* 0xfbc: jne    1023 <syscall__execveat_enter+0x1023> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1023;
	}
x86_l_fbe:
	/* 0xfbe: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fc3:
	/* 0xfc3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fc8:
	/* 0xfc8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fcd:
	/* 0xfcd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fd2:
	/* 0xfd2: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_fd5:
	/* 0xfd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fd7:
	/* 0xfd7: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fdc:
	/* 0xfdc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fe1:
	/* 0xfe1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_fe6:
	/* 0xfe6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_feb:
	/* 0xfeb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ff0:
	/* 0xff0: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_ff3:
	/* 0xff3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff5:
	/* 0xff5: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ff9:
	/* 0xff9: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_ffd:
	/* 0xffd: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1001:
	/* 0x1001: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1005:
	/* 0x1005: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_100a:
	/* 0x100a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_100f:
	/* 0x100f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1014:
	/* 0x1014: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1019:
	/* 0x1019: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_101b:
	/* 0x101b: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_101f:
	/* 0x101f: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1023:
	/* 0x1023: mov    DWORD PTR [r14+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1027:
	/* 0x1027: lea    r12,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_102e:
	/* 0x102e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1033:
	/* 0x1033: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1038:
	/* 0x1038: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_103d:
	/* 0x103d: lea    r15,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1041:
	/* 0x1041: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1046:
	/* 0x1046: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1049:
	/* 0x1049: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_104b:
	/* 0x104b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1050:
	/* 0x1050: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1054:
	/* 0x1054: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1059:
	/* 0x1059: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_105e:
	/* 0x105e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1063:
	/* 0x1063: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1068:
	/* 0x1068: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_106a:
	/* 0x106a: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_106f:
	/* 0x106f: lea    rdi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1074:
	/* 0x1074: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1079:
	/* 0x1079: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_107e:
	/* 0x107e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1083:
	/* 0x1083: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1088:
	/* 0x1088: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_108a:
	/* 0x108a: mov    eax,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_108e:
	/* 0x108e: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1092:
	/* 0x1092: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1097:
	/* 0x1097: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1099:
	/* 0x1099: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_109d:
	/* 0x109d: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_10a1:
	/* 0x10a1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10a6:
	/* 0x10a6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10ab:
	/* 0x10ab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10b0:
	/* 0x10b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10b5:
	/* 0x10b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b7:
	/* 0x10b7: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10bc:
	/* 0x10bc: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10c0:
	/* 0x10c0: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_10c5:
	/* 0x10c5: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_10c9:
	/* 0x10c9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10ce:
	/* 0x10ce: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10d3:
	/* 0x10d3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10d8:
	/* 0x10d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10dd:
	/* 0x10dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10df:
	/* 0x10df: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10e4:
	/* 0x10e4: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_10e8:
	/* 0x10e8: add    rbp,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_10ec:
	/* 0x10ec: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10f1:
	/* 0x10f1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10f6:
	/* 0x10f6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10fb:
	/* 0x10fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1100:
	/* 0x1100: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1103:
	/* 0x1103: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1105:
	/* 0x1105: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_110a:
	/* 0x110a: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_110e:
	/* 0x110e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1113:
	/* 0x1113: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1118:
	/* 0x1118: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_111d:
	/* 0x111d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1122:
	/* 0x1122: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1125:
	/* 0x1125: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1127:
	/* 0x1127: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_112c:
	/* 0x112c: je     1133 <syscall__execveat_enter+0x1133> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1133;
	}
x86_l_112e:
	/* 0x112e: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_1133:
	/* 0x1133: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_113b:
	/* 0x113b: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_113f:
	/* 0x113f: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_1147:
	/* 0x1147: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_114c:
	/* 0x114c: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1151:
	/* 0x1151: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1156:
	/* 0x1156: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1158:
	/* 0x1158: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_115d:
	/* 0x115d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1162:
	/* 0x1162: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1167:
	/* 0x1167: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_116c:
	/* 0x116c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_116f:
	/* 0x116f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1171:
	/* 0x1171: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1176:
	/* 0x1176: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_117b:
	/* 0x117b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1180:
	/* 0x1180: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1185:
	/* 0x1185: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_118a:
	/* 0x118a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_118c:
	/* 0x118c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1191:
	/* 0x1191: lea    rbx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1196:
	/* 0x1196: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_119b:
	/* 0x119b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11a0:
	/* 0x11a0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_11a3:
	/* 0x11a3: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_11a8:
	/* 0x11a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11aa:
	/* 0x11aa: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_11ad:
	/* 0x11ad: add    rdi,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_11b1:
	/* 0x11b1: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_11b6:
	/* 0x11b6: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_11bb:
	/* 0x11bb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_11c0:
	/* 0x11c0: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_11c3:
	/* 0x11c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11c5:
	/* 0x11c5: mov    ecx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 104ULL);
x86_l_11ca:
	/* 0x11ca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11cf:
	/* 0x11cf: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_11d4:
	/* 0x11d4: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_11d9:
	/* 0x11d9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_11dc:
	/* 0x11dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11de:
	/* 0x11de: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_11e3:
	/* 0x11e3: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_11e7:
	/* 0x11e7: mov    rbx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_11ef:
	/* 0x11ef: je     1214 <syscall__execveat_enter+0x1214> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1214;
	}
x86_l_11f1:
	/* 0x11f1: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_11f8:
	/* 0x11f8: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_11fd:
	/* 0x11fd: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1202:
	/* 0x1202: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1207:
	/* 0x1207: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_120a:
	/* 0x120a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_120c:
	/* 0x120c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_120e:
	/* 0x120e: js     1214 <syscall__execveat_enter+0x1214> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1214;
	}
x86_l_1210:
	/* 0x1210: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1214:
	/* 0x1214: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_121c:
	/* 0x121c: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_1221:
	/* 0x1221: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_1226:
	/* 0x1226: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_1229:
	/* 0x1229: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_122f:
	/* 0x122f: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1233:
	/* 0x1233: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_123a:
	/* 0x123a: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_123f:
	/* 0x123f: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1244:
	/* 0x1244: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1249:
	/* 0x1249: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_124c:
	/* 0x124c: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_124f:
	/* 0x124f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1251:
	/* 0x1251: add    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_1258:
	/* 0x1258: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1259:
	/* 0x1259: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_125b:
	/* 0x125b: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_125d:
	/* 0x125d: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_125f:
	/* 0x125f: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1261:
	/* 0x1261: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1262:
	/* 0x1262: jmp    57fd <syscall__execveat_enter+0x57fd> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1267:
	/* 0x1267: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_126b:
	/* 0x126b: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1272:
	/* 0x1272: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1277:
	/* 0x1277: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_127c:
	/* 0x127c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1281:
	/* 0x1281: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1288:
	/* 0x1288: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_128c:
	/* 0x128c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1293:
	/* 0x1293: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1298:
	/* 0x1298: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_129a:
	/* 0x129a: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_129f:
	/* 0x129f: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_12a6:
	/* 0x12a6: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_12a9:
	/* 0x12a9: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_12b0:
	/* 0x12b0: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_12b9:
	/* 0x12b9: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12bd:
	/* 0x12bd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12c2:
	/* 0x12c2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12c7:
	/* 0x12c7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12cc:
	/* 0x12cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12d1:
	/* 0x12d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d3:
	/* 0x12d3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12d8:
	/* 0x12d8: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_12da:
	/* 0x12da: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_12dd:
	/* 0x12dd: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_12e3:
	/* 0x12e3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_12e6:
	/* 0x12e6: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_12ec:
	/* 0x12ec: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_12f2:
	/* 0x12f2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12f7:
	/* 0x12f7: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_12fb:
	/* 0x12fb: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1302:
	/* 0x1302: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1307:
	/* 0x1307: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_130c:
	/* 0x130c: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1313:
	/* 0x1313: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1316:
	/* 0x1316: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_131d:
	/* 0x131d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1322:
	/* 0x1322: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1327:
	/* 0x1327: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1329:
	/* 0x1329: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_132d:
	/* 0x132d: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_132f:
	/* 0x132f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1331:
	/* 0x1331: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_1337:
	/* 0x1337: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_133a:
	/* 0x133a: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1340:
	/* 0x1340: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_1346:
	/* 0x1346: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_134b:
	/* 0x134b: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_134f:
	/* 0x134f: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1356:
	/* 0x1356: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_135b:
	/* 0x135b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1360:
	/* 0x1360: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1365:
	/* 0x1365: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_136d:
	/* 0x136d: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1371:
	/* 0x1371: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1378:
	/* 0x1378: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_137d:
	/* 0x137d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_137f:
	/* 0x137f: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1384:
	/* 0x1384: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_138c:
	/* 0x138c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_138f:
	/* 0x138f: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1397:
	/* 0x1397: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_13a0:
	/* 0x13a0: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13a4:
	/* 0x13a4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13a9:
	/* 0x13a9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13ae:
	/* 0x13ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13b3:
	/* 0x13b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13b8:
	/* 0x13b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13ba:
	/* 0x13ba: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13bf:
	/* 0x13bf: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_13c1:
	/* 0x13c1: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_13c4:
	/* 0x13c4: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_13ca:
	/* 0x13ca: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_13cd:
	/* 0x13cd: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
	return 5075ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5075ULL: goto x86_l_13d3;
	case 5081ULL: goto x86_l_13d9;
	case 5086ULL: goto x86_l_13de;
	case 5090ULL: goto x86_l_13e2;
	case 5097ULL: goto x86_l_13e9;
	case 5102ULL: goto x86_l_13ee;
	case 5107ULL: goto x86_l_13f3;
	case 5114ULL: goto x86_l_13fa;
	case 5117ULL: goto x86_l_13fd;
	case 5124ULL: goto x86_l_1404;
	case 5129ULL: goto x86_l_1409;
	case 5134ULL: goto x86_l_140e;
	case 5136ULL: goto x86_l_1410;
	case 5140ULL: goto x86_l_1414;
	case 5142ULL: goto x86_l_1416;
	case 5144ULL: goto x86_l_1418;
	case 5150ULL: goto x86_l_141e;
	case 5153ULL: goto x86_l_1421;
	case 5159ULL: goto x86_l_1427;
	case 5165ULL: goto x86_l_142d;
	case 5170ULL: goto x86_l_1432;
	case 5174ULL: goto x86_l_1436;
	case 5181ULL: goto x86_l_143d;
	case 5186ULL: goto x86_l_1442;
	case 5191ULL: goto x86_l_1447;
	case 5196ULL: goto x86_l_144c;
	case 5204ULL: goto x86_l_1454;
	case 5208ULL: goto x86_l_1458;
	case 5215ULL: goto x86_l_145f;
	case 5220ULL: goto x86_l_1464;
	case 5222ULL: goto x86_l_1466;
	case 5227ULL: goto x86_l_146b;
	case 5235ULL: goto x86_l_1473;
	case 5238ULL: goto x86_l_1476;
	case 5246ULL: goto x86_l_147e;
	case 5255ULL: goto x86_l_1487;
	case 5259ULL: goto x86_l_148b;
	case 5264ULL: goto x86_l_1490;
	case 5269ULL: goto x86_l_1495;
	case 5274ULL: goto x86_l_149a;
	case 5279ULL: goto x86_l_149f;
	case 5281ULL: goto x86_l_14a1;
	case 5286ULL: goto x86_l_14a6;
	case 5288ULL: goto x86_l_14a8;
	case 5291ULL: goto x86_l_14ab;
	case 5297ULL: goto x86_l_14b1;
	case 5300ULL: goto x86_l_14b4;
	case 5306ULL: goto x86_l_14ba;
	case 5312ULL: goto x86_l_14c0;
	case 5317ULL: goto x86_l_14c5;
	case 5321ULL: goto x86_l_14c9;
	case 5328ULL: goto x86_l_14d0;
	case 5333ULL: goto x86_l_14d5;
	case 5338ULL: goto x86_l_14da;
	case 5345ULL: goto x86_l_14e1;
	case 5348ULL: goto x86_l_14e4;
	case 5355ULL: goto x86_l_14eb;
	case 5360ULL: goto x86_l_14f0;
	case 5365ULL: goto x86_l_14f5;
	case 5367ULL: goto x86_l_14f7;
	case 5371ULL: goto x86_l_14fb;
	case 5373ULL: goto x86_l_14fd;
	case 5375ULL: goto x86_l_14ff;
	case 5381ULL: goto x86_l_1505;
	case 5384ULL: goto x86_l_1508;
	case 5390ULL: goto x86_l_150e;
	case 5396ULL: goto x86_l_1514;
	case 5401ULL: goto x86_l_1519;
	case 5405ULL: goto x86_l_151d;
	case 5412ULL: goto x86_l_1524;
	case 5417ULL: goto x86_l_1529;
	case 5422ULL: goto x86_l_152e;
	case 5427ULL: goto x86_l_1533;
	case 5435ULL: goto x86_l_153b;
	case 5439ULL: goto x86_l_153f;
	case 5446ULL: goto x86_l_1546;
	case 5451ULL: goto x86_l_154b;
	case 5453ULL: goto x86_l_154d;
	case 5458ULL: goto x86_l_1552;
	case 5466ULL: goto x86_l_155a;
	case 5469ULL: goto x86_l_155d;
	case 5477ULL: goto x86_l_1565;
	case 5486ULL: goto x86_l_156e;
	case 5490ULL: goto x86_l_1572;
	case 5495ULL: goto x86_l_1577;
	case 5500ULL: goto x86_l_157c;
	case 5505ULL: goto x86_l_1581;
	case 5510ULL: goto x86_l_1586;
	case 5512ULL: goto x86_l_1588;
	case 5517ULL: goto x86_l_158d;
	case 5519ULL: goto x86_l_158f;
	case 5522ULL: goto x86_l_1592;
	case 5528ULL: goto x86_l_1598;
	case 5531ULL: goto x86_l_159b;
	case 5537ULL: goto x86_l_15a1;
	case 5543ULL: goto x86_l_15a7;
	case 5548ULL: goto x86_l_15ac;
	case 5552ULL: goto x86_l_15b0;
	case 5559ULL: goto x86_l_15b7;
	case 5564ULL: goto x86_l_15bc;
	case 5569ULL: goto x86_l_15c1;
	case 5576ULL: goto x86_l_15c8;
	case 5579ULL: goto x86_l_15cb;
	case 5586ULL: goto x86_l_15d2;
	case 5591ULL: goto x86_l_15d7;
	case 5596ULL: goto x86_l_15dc;
	case 5598ULL: goto x86_l_15de;
	case 5602ULL: goto x86_l_15e2;
	case 5604ULL: goto x86_l_15e4;
	case 5606ULL: goto x86_l_15e6;
	case 5612ULL: goto x86_l_15ec;
	case 5615ULL: goto x86_l_15ef;
	case 5621ULL: goto x86_l_15f5;
	case 5627ULL: goto x86_l_15fb;
	case 5632ULL: goto x86_l_1600;
	case 5636ULL: goto x86_l_1604;
	case 5643ULL: goto x86_l_160b;
	case 5648ULL: goto x86_l_1610;
	case 5653ULL: goto x86_l_1615;
	case 5658ULL: goto x86_l_161a;
	case 5666ULL: goto x86_l_1622;
	case 5670ULL: goto x86_l_1626;
	case 5677ULL: goto x86_l_162d;
	case 5682ULL: goto x86_l_1632;
	case 5684ULL: goto x86_l_1634;
	case 5689ULL: goto x86_l_1639;
	case 5697ULL: goto x86_l_1641;
	case 5700ULL: goto x86_l_1644;
	case 5708ULL: goto x86_l_164c;
	case 5717ULL: goto x86_l_1655;
	case 5721ULL: goto x86_l_1659;
	case 5726ULL: goto x86_l_165e;
	case 5731ULL: goto x86_l_1663;
	case 5736ULL: goto x86_l_1668;
	case 5741ULL: goto x86_l_166d;
	case 5743ULL: goto x86_l_166f;
	case 5748ULL: goto x86_l_1674;
	case 5750ULL: goto x86_l_1676;
	case 5753ULL: goto x86_l_1679;
	case 5759ULL: goto x86_l_167f;
	case 5762ULL: goto x86_l_1682;
	case 5768ULL: goto x86_l_1688;
	case 5774ULL: goto x86_l_168e;
	case 5779ULL: goto x86_l_1693;
	case 5783ULL: goto x86_l_1697;
	case 5790ULL: goto x86_l_169e;
	case 5795ULL: goto x86_l_16a3;
	case 5800ULL: goto x86_l_16a8;
	case 5807ULL: goto x86_l_16af;
	case 5810ULL: goto x86_l_16b2;
	case 5817ULL: goto x86_l_16b9;
	case 5822ULL: goto x86_l_16be;
	case 5827ULL: goto x86_l_16c3;
	case 5829ULL: goto x86_l_16c5;
	case 5833ULL: goto x86_l_16c9;
	case 5835ULL: goto x86_l_16cb;
	case 5837ULL: goto x86_l_16cd;
	case 5843ULL: goto x86_l_16d3;
	case 5846ULL: goto x86_l_16d6;
	case 5852ULL: goto x86_l_16dc;
	case 5858ULL: goto x86_l_16e2;
	case 5863ULL: goto x86_l_16e7;
	case 5867ULL: goto x86_l_16eb;
	case 5874ULL: goto x86_l_16f2;
	case 5879ULL: goto x86_l_16f7;
	case 5884ULL: goto x86_l_16fc;
	case 5889ULL: goto x86_l_1701;
	case 5897ULL: goto x86_l_1709;
	case 5901ULL: goto x86_l_170d;
	case 5908ULL: goto x86_l_1714;
	case 5913ULL: goto x86_l_1719;
	case 5915ULL: goto x86_l_171b;
	case 5920ULL: goto x86_l_1720;
	case 5928ULL: goto x86_l_1728;
	case 5931ULL: goto x86_l_172b;
	case 5939ULL: goto x86_l_1733;
	case 5948ULL: goto x86_l_173c;
	case 5952ULL: goto x86_l_1740;
	case 5957ULL: goto x86_l_1745;
	case 5962ULL: goto x86_l_174a;
	case 5967ULL: goto x86_l_174f;
	case 5972ULL: goto x86_l_1754;
	case 5974ULL: goto x86_l_1756;
	case 5979ULL: goto x86_l_175b;
	case 5981ULL: goto x86_l_175d;
	case 5984ULL: goto x86_l_1760;
	case 5990ULL: goto x86_l_1766;
	case 5993ULL: goto x86_l_1769;
	case 5999ULL: goto x86_l_176f;
	case 6005ULL: goto x86_l_1775;
	case 6010ULL: goto x86_l_177a;
	case 6014ULL: goto x86_l_177e;
	case 6021ULL: goto x86_l_1785;
	case 6026ULL: goto x86_l_178a;
	case 6031ULL: goto x86_l_178f;
	case 6038ULL: goto x86_l_1796;
	case 6041ULL: goto x86_l_1799;
	case 6048ULL: goto x86_l_17a0;
	case 6053ULL: goto x86_l_17a5;
	case 6058ULL: goto x86_l_17aa;
	case 6060ULL: goto x86_l_17ac;
	case 6064ULL: goto x86_l_17b0;
	case 6066ULL: goto x86_l_17b2;
	case 6068ULL: goto x86_l_17b4;
	case 6074ULL: goto x86_l_17ba;
	case 6077ULL: goto x86_l_17bd;
	case 6083ULL: goto x86_l_17c3;
	case 6089ULL: goto x86_l_17c9;
	case 6094ULL: goto x86_l_17ce;
	case 6098ULL: goto x86_l_17d2;
	case 6105ULL: goto x86_l_17d9;
	case 6110ULL: goto x86_l_17de;
	case 6115ULL: goto x86_l_17e3;
	case 6120ULL: goto x86_l_17e8;
	case 6128ULL: goto x86_l_17f0;
	case 6132ULL: goto x86_l_17f4;
	case 6139ULL: goto x86_l_17fb;
	case 6144ULL: goto x86_l_1800;
	case 6146ULL: goto x86_l_1802;
	case 6151ULL: goto x86_l_1807;
	case 6159ULL: goto x86_l_180f;
	case 6162ULL: goto x86_l_1812;
	case 6170ULL: goto x86_l_181a;
	case 6179ULL: goto x86_l_1823;
	case 6183ULL: goto x86_l_1827;
	case 6188ULL: goto x86_l_182c;
	case 6193ULL: goto x86_l_1831;
	case 6198ULL: goto x86_l_1836;
	case 6203ULL: goto x86_l_183b;
	case 6205ULL: goto x86_l_183d;
	case 6210ULL: goto x86_l_1842;
	case 6212ULL: goto x86_l_1844;
	case 6215ULL: goto x86_l_1847;
	case 6221ULL: goto x86_l_184d;
	case 6224ULL: goto x86_l_1850;
	case 6230ULL: goto x86_l_1856;
	case 6236ULL: goto x86_l_185c;
	case 6241ULL: goto x86_l_1861;
	case 6245ULL: goto x86_l_1865;
	case 6252ULL: goto x86_l_186c;
	case 6257ULL: goto x86_l_1871;
	case 6262ULL: goto x86_l_1876;
	case 6269ULL: goto x86_l_187d;
	case 6272ULL: goto x86_l_1880;
	case 6279ULL: goto x86_l_1887;
	case 6284ULL: goto x86_l_188c;
	case 6289ULL: goto x86_l_1891;
	case 6291ULL: goto x86_l_1893;
	case 6295ULL: goto x86_l_1897;
	case 6297ULL: goto x86_l_1899;
	case 6299ULL: goto x86_l_189b;
	case 6305ULL: goto x86_l_18a1;
	case 6308ULL: goto x86_l_18a4;
	case 6314ULL: goto x86_l_18aa;
	case 6320ULL: goto x86_l_18b0;
	case 6325ULL: goto x86_l_18b5;
	case 6329ULL: goto x86_l_18b9;
	case 6336ULL: goto x86_l_18c0;
	case 6341ULL: goto x86_l_18c5;
	case 6346ULL: goto x86_l_18ca;
	case 6351ULL: goto x86_l_18cf;
	case 6359ULL: goto x86_l_18d7;
	case 6363ULL: goto x86_l_18db;
	case 6370ULL: goto x86_l_18e2;
	case 6375ULL: goto x86_l_18e7;
	case 6377ULL: goto x86_l_18e9;
	case 6382ULL: goto x86_l_18ee;
	case 6390ULL: goto x86_l_18f6;
	case 6393ULL: goto x86_l_18f9;
	case 6401ULL: goto x86_l_1901;
	case 6410ULL: goto x86_l_190a;
	case 6414ULL: goto x86_l_190e;
	case 6419ULL: goto x86_l_1913;
	case 6424ULL: goto x86_l_1918;
	case 6429ULL: goto x86_l_191d;
	case 6434ULL: goto x86_l_1922;
	case 6436ULL: goto x86_l_1924;
	case 6441ULL: goto x86_l_1929;
	case 6443ULL: goto x86_l_192b;
	case 6446ULL: goto x86_l_192e;
	case 6452ULL: goto x86_l_1934;
	case 6455ULL: goto x86_l_1937;
	case 6461ULL: goto x86_l_193d;
	case 6467ULL: goto x86_l_1943;
	case 6472ULL: goto x86_l_1948;
	case 6476ULL: goto x86_l_194c;
	case 6483ULL: goto x86_l_1953;
	case 6488ULL: goto x86_l_1958;
	case 6493ULL: goto x86_l_195d;
	case 6500ULL: goto x86_l_1964;
	case 6503ULL: goto x86_l_1967;
	case 6510ULL: goto x86_l_196e;
	case 6515ULL: goto x86_l_1973;
	case 6520ULL: goto x86_l_1978;
	case 6522ULL: goto x86_l_197a;
	case 6526ULL: goto x86_l_197e;
	case 6528ULL: goto x86_l_1980;
	case 6530ULL: goto x86_l_1982;
	case 6536ULL: goto x86_l_1988;
	case 6539ULL: goto x86_l_198b;
	case 6545ULL: goto x86_l_1991;
	case 6551ULL: goto x86_l_1997;
	case 6556ULL: goto x86_l_199c;
	case 6560ULL: goto x86_l_19a0;
	case 6567ULL: goto x86_l_19a7;
	case 6572ULL: goto x86_l_19ac;
	case 6577ULL: goto x86_l_19b1;
	case 6582ULL: goto x86_l_19b6;
	case 6590ULL: goto x86_l_19be;
	case 6594ULL: goto x86_l_19c2;
	case 6601ULL: goto x86_l_19c9;
	case 6606ULL: goto x86_l_19ce;
	case 6608ULL: goto x86_l_19d0;
	case 6613ULL: goto x86_l_19d5;
	case 6621ULL: goto x86_l_19dd;
	case 6624ULL: goto x86_l_19e0;
	case 6632ULL: goto x86_l_19e8;
	case 6641ULL: goto x86_l_19f1;
	case 6645ULL: goto x86_l_19f5;
	case 6650ULL: goto x86_l_19fa;
	case 6655ULL: goto x86_l_19ff;
	case 6660ULL: goto x86_l_1a04;
	case 6665ULL: goto x86_l_1a09;
	case 6667ULL: goto x86_l_1a0b;
	case 6672ULL: goto x86_l_1a10;
	case 6674ULL: goto x86_l_1a12;
	case 6677ULL: goto x86_l_1a15;
	case 6683ULL: goto x86_l_1a1b;
	case 6686ULL: goto x86_l_1a1e;
	case 6692ULL: goto x86_l_1a24;
	case 6698ULL: goto x86_l_1a2a;
	case 6703ULL: goto x86_l_1a2f;
	case 6707ULL: goto x86_l_1a33;
	case 6714ULL: goto x86_l_1a3a;
	case 6719ULL: goto x86_l_1a3f;
	case 6724ULL: goto x86_l_1a44;
	case 6731ULL: goto x86_l_1a4b;
	case 6734ULL: goto x86_l_1a4e;
	case 6741ULL: goto x86_l_1a55;
	case 6746ULL: goto x86_l_1a5a;
	case 6751ULL: goto x86_l_1a5f;
	case 6753ULL: goto x86_l_1a61;
	case 6757ULL: goto x86_l_1a65;
	case 6759ULL: goto x86_l_1a67;
	case 6761ULL: goto x86_l_1a69;
	case 6767ULL: goto x86_l_1a6f;
	case 6770ULL: goto x86_l_1a72;
	case 6776ULL: goto x86_l_1a78;
	case 6782ULL: goto x86_l_1a7e;
	case 6787ULL: goto x86_l_1a83;
	case 6791ULL: goto x86_l_1a87;
	case 6798ULL: goto x86_l_1a8e;
	case 6803ULL: goto x86_l_1a93;
	case 6808ULL: goto x86_l_1a98;
	case 6813ULL: goto x86_l_1a9d;
	case 6821ULL: goto x86_l_1aa5;
	case 6825ULL: goto x86_l_1aa9;
	case 6832ULL: goto x86_l_1ab0;
	case 6837ULL: goto x86_l_1ab5;
	case 6839ULL: goto x86_l_1ab7;
	case 6844ULL: goto x86_l_1abc;
	case 6852ULL: goto x86_l_1ac4;
	case 6855ULL: goto x86_l_1ac7;
	case 6863ULL: goto x86_l_1acf;
	case 6872ULL: goto x86_l_1ad8;
	case 6876ULL: goto x86_l_1adc;
	case 6881ULL: goto x86_l_1ae1;
	case 6886ULL: goto x86_l_1ae6;
	case 6891ULL: goto x86_l_1aeb;
	case 6896ULL: goto x86_l_1af0;
	case 6898ULL: goto x86_l_1af2;
	case 6903ULL: goto x86_l_1af7;
	case 6905ULL: goto x86_l_1af9;
	case 6908ULL: goto x86_l_1afc;
	case 6914ULL: goto x86_l_1b02;
	case 6917ULL: goto x86_l_1b05;
	case 6923ULL: goto x86_l_1b0b;
	case 6929ULL: goto x86_l_1b11;
	case 6934ULL: goto x86_l_1b16;
	case 6938ULL: goto x86_l_1b1a;
	case 6945ULL: goto x86_l_1b21;
	case 6950ULL: goto x86_l_1b26;
	case 6955ULL: goto x86_l_1b2b;
	case 6962ULL: goto x86_l_1b32;
	default: return 0xffffffffffffffffULL;
	}
x86_l_13d3:
	/* 0x13d3: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_13d9:
	/* 0x13d9: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13de:
	/* 0x13de: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_13e2:
	/* 0x13e2: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_13e9:
	/* 0x13e9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_13ee:
	/* 0x13ee: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_13f3:
	/* 0x13f3: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_13fa:
	/* 0x13fa: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_13fd:
	/* 0x13fd: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1404:
	/* 0x1404: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1409:
	/* 0x1409: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_140e:
	/* 0x140e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1410:
	/* 0x1410: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1414:
	/* 0x1414: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_1416:
	/* 0x1416: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1418:
	/* 0x1418: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_141e:
	/* 0x141e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1421:
	/* 0x1421: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1427:
	/* 0x1427: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_142d:
	/* 0x142d: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1432:
	/* 0x1432: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1436:
	/* 0x1436: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_143d:
	/* 0x143d: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1442:
	/* 0x1442: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1447:
	/* 0x1447: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_144c:
	/* 0x144c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1454:
	/* 0x1454: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1458:
	/* 0x1458: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_145f:
	/* 0x145f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1464:
	/* 0x1464: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1466:
	/* 0x1466: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_146b:
	/* 0x146b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1473:
	/* 0x1473: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1476:
	/* 0x1476: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_147e:
	/* 0x147e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1487:
	/* 0x1487: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_148b:
	/* 0x148b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1490:
	/* 0x1490: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1495:
	/* 0x1495: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_149a:
	/* 0x149a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_149f:
	/* 0x149f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14a1:
	/* 0x14a1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14a6:
	/* 0x14a6: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_14a8:
	/* 0x14a8: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_14ab:
	/* 0x14ab: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_14b1:
	/* 0x14b1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_14b4:
	/* 0x14b4: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_14ba:
	/* 0x14ba: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_14c0:
	/* 0x14c0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14c5:
	/* 0x14c5: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_14c9:
	/* 0x14c9: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_14d0:
	/* 0x14d0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_14d5:
	/* 0x14d5: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_14da:
	/* 0x14da: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_14e1:
	/* 0x14e1: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_14e4:
	/* 0x14e4: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_14eb:
	/* 0x14eb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14f0:
	/* 0x14f0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_14f5:
	/* 0x14f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14f7:
	/* 0x14f7: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14fb:
	/* 0x14fb: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_14fd:
	/* 0x14fd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14ff:
	/* 0x14ff: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_1505:
	/* 0x1505: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1508:
	/* 0x1508: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_150e:
	/* 0x150e: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_1514:
	/* 0x1514: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1519:
	/* 0x1519: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_151d:
	/* 0x151d: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1524:
	/* 0x1524: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1529:
	/* 0x1529: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_152e:
	/* 0x152e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1533:
	/* 0x1533: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_153b:
	/* 0x153b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_153f:
	/* 0x153f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1546:
	/* 0x1546: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_154b:
	/* 0x154b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_154d:
	/* 0x154d: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1552:
	/* 0x1552: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_155a:
	/* 0x155a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_155d:
	/* 0x155d: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1565:
	/* 0x1565: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_156e:
	/* 0x156e: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1572:
	/* 0x1572: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1577:
	/* 0x1577: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_157c:
	/* 0x157c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1581:
	/* 0x1581: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1586:
	/* 0x1586: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1588:
	/* 0x1588: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_158d:
	/* 0x158d: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_158f:
	/* 0x158f: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1592:
	/* 0x1592: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_1598:
	/* 0x1598: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_159b:
	/* 0x159b: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_15a1:
	/* 0x15a1: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_15a7:
	/* 0x15a7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15ac:
	/* 0x15ac: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_15b0:
	/* 0x15b0: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_15b7:
	/* 0x15b7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_15bc:
	/* 0x15bc: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_15c1:
	/* 0x15c1: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_15c8:
	/* 0x15c8: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_15cb:
	/* 0x15cb: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_15d2:
	/* 0x15d2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15d7:
	/* 0x15d7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_15dc:
	/* 0x15dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15de:
	/* 0x15de: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_15e2:
	/* 0x15e2: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_15e4:
	/* 0x15e4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15e6:
	/* 0x15e6: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_15ec:
	/* 0x15ec: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15ef:
	/* 0x15ef: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_15f5:
	/* 0x15f5: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_15fb:
	/* 0x15fb: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1600:
	/* 0x1600: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1604:
	/* 0x1604: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_160b:
	/* 0x160b: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1610:
	/* 0x1610: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1615:
	/* 0x1615: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_161a:
	/* 0x161a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1622:
	/* 0x1622: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1626:
	/* 0x1626: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_162d:
	/* 0x162d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1632:
	/* 0x1632: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1634:
	/* 0x1634: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1639:
	/* 0x1639: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1641:
	/* 0x1641: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1644:
	/* 0x1644: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_164c:
	/* 0x164c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1655:
	/* 0x1655: lea    rdx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1659:
	/* 0x1659: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_165e:
	/* 0x165e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1663:
	/* 0x1663: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1668:
	/* 0x1668: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_166d:
	/* 0x166d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_166f:
	/* 0x166f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1674:
	/* 0x1674: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_1676:
	/* 0x1676: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1679:
	/* 0x1679: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_167f:
	/* 0x167f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1682:
	/* 0x1682: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1688:
	/* 0x1688: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_168e:
	/* 0x168e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1693:
	/* 0x1693: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1697:
	/* 0x1697: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_169e:
	/* 0x169e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_16a3:
	/* 0x16a3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_16a8:
	/* 0x16a8: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_16af:
	/* 0x16af: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16b2:
	/* 0x16b2: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_16b9:
	/* 0x16b9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16be:
	/* 0x16be: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_16c3:
	/* 0x16c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c5:
	/* 0x16c5: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16c9:
	/* 0x16c9: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_16cb:
	/* 0x16cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16cd:
	/* 0x16cd: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_16d3:
	/* 0x16d3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_16d6:
	/* 0x16d6: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_16dc:
	/* 0x16dc: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_16e2:
	/* 0x16e2: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16e7:
	/* 0x16e7: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_16eb:
	/* 0x16eb: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_16f2:
	/* 0x16f2: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16f7:
	/* 0x16f7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16fc:
	/* 0x16fc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1701:
	/* 0x1701: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1709:
	/* 0x1709: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_170d:
	/* 0x170d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1714:
	/* 0x1714: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1719:
	/* 0x1719: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_171b:
	/* 0x171b: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1720:
	/* 0x1720: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1728:
	/* 0x1728: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_172b:
	/* 0x172b: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1733:
	/* 0x1733: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_173c:
	/* 0x173c: lea    rdx,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1740:
	/* 0x1740: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1745:
	/* 0x1745: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_174a:
	/* 0x174a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_174f:
	/* 0x174f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1754:
	/* 0x1754: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1756:
	/* 0x1756: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_175b:
	/* 0x175b: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_175d:
	/* 0x175d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1760:
	/* 0x1760: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_1766:
	/* 0x1766: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1769:
	/* 0x1769: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_176f:
	/* 0x176f: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_1775:
	/* 0x1775: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_177a:
	/* 0x177a: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_177e:
	/* 0x177e: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1785:
	/* 0x1785: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_178a:
	/* 0x178a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_178f:
	/* 0x178f: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1796:
	/* 0x1796: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1799:
	/* 0x1799: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_17a0:
	/* 0x17a0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17a5:
	/* 0x17a5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_17aa:
	/* 0x17aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ac:
	/* 0x17ac: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_17b0:
	/* 0x17b0: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_17b2:
	/* 0x17b2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17b4:
	/* 0x17b4: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_17ba:
	/* 0x17ba: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_17bd:
	/* 0x17bd: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_17c3:
	/* 0x17c3: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_17c9:
	/* 0x17c9: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17ce:
	/* 0x17ce: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_17d2:
	/* 0x17d2: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_17d9:
	/* 0x17d9: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_17de:
	/* 0x17de: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17e3:
	/* 0x17e3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17e8:
	/* 0x17e8: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_17f0:
	/* 0x17f0: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_17f4:
	/* 0x17f4: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_17fb:
	/* 0x17fb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1800:
	/* 0x1800: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1802:
	/* 0x1802: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1807:
	/* 0x1807: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_180f:
	/* 0x180f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1812:
	/* 0x1812: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_181a:
	/* 0x181a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1823:
	/* 0x1823: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1827:
	/* 0x1827: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_182c:
	/* 0x182c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1831:
	/* 0x1831: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1836:
	/* 0x1836: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_183b:
	/* 0x183b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_183d:
	/* 0x183d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1842:
	/* 0x1842: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_1844:
	/* 0x1844: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1847:
	/* 0x1847: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_184d:
	/* 0x184d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1850:
	/* 0x1850: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1856:
	/* 0x1856: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_185c:
	/* 0x185c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1861:
	/* 0x1861: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1865:
	/* 0x1865: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_186c:
	/* 0x186c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1871:
	/* 0x1871: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1876:
	/* 0x1876: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_187d:
	/* 0x187d: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1880:
	/* 0x1880: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1887:
	/* 0x1887: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_188c:
	/* 0x188c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1891:
	/* 0x1891: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1893:
	/* 0x1893: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1897:
	/* 0x1897: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_1899:
	/* 0x1899: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_189b:
	/* 0x189b: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_18a1:
	/* 0x18a1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18a4:
	/* 0x18a4: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_18aa:
	/* 0x18aa: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_18b0:
	/* 0x18b0: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18b5:
	/* 0x18b5: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_18b9:
	/* 0x18b9: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_18c0:
	/* 0x18c0: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_18c5:
	/* 0x18c5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18ca:
	/* 0x18ca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18cf:
	/* 0x18cf: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_18d7:
	/* 0x18d7: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_18db:
	/* 0x18db: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_18e2:
	/* 0x18e2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18e7:
	/* 0x18e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e9:
	/* 0x18e9: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_18ee:
	/* 0x18ee: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_18f6:
	/* 0x18f6: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_18f9:
	/* 0x18f9: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1901:
	/* 0x1901: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_190a:
	/* 0x190a: lea    rdx,[r13+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_190e:
	/* 0x190e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1913:
	/* 0x1913: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1918:
	/* 0x1918: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_191d:
	/* 0x191d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1922:
	/* 0x1922: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1924:
	/* 0x1924: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1929:
	/* 0x1929: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_192b:
	/* 0x192b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_192e:
	/* 0x192e: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_1934:
	/* 0x1934: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1937:
	/* 0x1937: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_193d:
	/* 0x193d: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_1943:
	/* 0x1943: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1948:
	/* 0x1948: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_194c:
	/* 0x194c: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1953:
	/* 0x1953: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1958:
	/* 0x1958: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_195d:
	/* 0x195d: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1964:
	/* 0x1964: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1967:
	/* 0x1967: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_196e:
	/* 0x196e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1973:
	/* 0x1973: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1978:
	/* 0x1978: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_197a:
	/* 0x197a: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_197e:
	/* 0x197e: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_1980:
	/* 0x1980: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1982:
	/* 0x1982: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_1988:
	/* 0x1988: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_198b:
	/* 0x198b: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1991:
	/* 0x1991: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_1997:
	/* 0x1997: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_199c:
	/* 0x199c: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_19a0:
	/* 0x19a0: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_19a7:
	/* 0x19a7: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19ac:
	/* 0x19ac: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19b1:
	/* 0x19b1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19b6:
	/* 0x19b6: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_19be:
	/* 0x19be: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_19c2:
	/* 0x19c2: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_19c9:
	/* 0x19c9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19ce:
	/* 0x19ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d0:
	/* 0x19d0: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_19d5:
	/* 0x19d5: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_19dd:
	/* 0x19dd: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_19e0:
	/* 0x19e0: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_19e8:
	/* 0x19e8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_19f1:
	/* 0x19f1: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_19f5:
	/* 0x19f5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19fa:
	/* 0x19fa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19ff:
	/* 0x19ff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a04:
	/* 0x1a04: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a09:
	/* 0x1a09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a0b:
	/* 0x1a0b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a10:
	/* 0x1a10: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_1a12:
	/* 0x1a12: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1a15:
	/* 0x1a15: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_1a1b:
	/* 0x1a1b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a1e:
	/* 0x1a1e: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1a24:
	/* 0x1a24: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_1a2a:
	/* 0x1a2a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a2f:
	/* 0x1a2f: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1a33:
	/* 0x1a33: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1a3a:
	/* 0x1a3a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1a3f:
	/* 0x1a3f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1a44:
	/* 0x1a44: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1a4b:
	/* 0x1a4b: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a4e:
	/* 0x1a4e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1a55:
	/* 0x1a55: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a5a:
	/* 0x1a5a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1a5f:
	/* 0x1a5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a61:
	/* 0x1a61: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a65:
	/* 0x1a65: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_1a67:
	/* 0x1a67: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a69:
	/* 0x1a69: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_1a6f:
	/* 0x1a6f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a72:
	/* 0x1a72: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1a78:
	/* 0x1a78: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_1a7e:
	/* 0x1a7e: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a83:
	/* 0x1a83: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1a87:
	/* 0x1a87: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1a8e:
	/* 0x1a8e: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a93:
	/* 0x1a93: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a98:
	/* 0x1a98: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a9d:
	/* 0x1a9d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1aa5:
	/* 0x1aa5: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1aa9:
	/* 0x1aa9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1ab0:
	/* 0x1ab0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ab5:
	/* 0x1ab5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ab7:
	/* 0x1ab7: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1abc:
	/* 0x1abc: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1ac4:
	/* 0x1ac4: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1ac7:
	/* 0x1ac7: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1acf:
	/* 0x1acf: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1ad8:
	/* 0x1ad8: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1adc:
	/* 0x1adc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ae1:
	/* 0x1ae1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ae6:
	/* 0x1ae6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1aeb:
	/* 0x1aeb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1af0:
	/* 0x1af0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1af2:
	/* 0x1af2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1af7:
	/* 0x1af7: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_1af9:
	/* 0x1af9: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1afc:
	/* 0x1afc: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_1b02:
	/* 0x1b02: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b05:
	/* 0x1b05: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1b0b:
	/* 0x1b0b: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_1b11:
	/* 0x1b11: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b16:
	/* 0x1b16: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1b1a:
	/* 0x1b1a: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1b21:
	/* 0x1b21: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1b26:
	/* 0x1b26: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1b2b:
	/* 0x1b2b: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1b32:
	/* 0x1b32: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
	return 6965ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6965ULL: goto x86_l_1b35;
	case 6972ULL: goto x86_l_1b3c;
	case 6977ULL: goto x86_l_1b41;
	case 6982ULL: goto x86_l_1b46;
	case 6984ULL: goto x86_l_1b48;
	case 6988ULL: goto x86_l_1b4c;
	case 6990ULL: goto x86_l_1b4e;
	case 6992ULL: goto x86_l_1b50;
	case 6998ULL: goto x86_l_1b56;
	case 7001ULL: goto x86_l_1b59;
	case 7007ULL: goto x86_l_1b5f;
	case 7013ULL: goto x86_l_1b65;
	case 7018ULL: goto x86_l_1b6a;
	case 7022ULL: goto x86_l_1b6e;
	case 7029ULL: goto x86_l_1b75;
	case 7034ULL: goto x86_l_1b7a;
	case 7039ULL: goto x86_l_1b7f;
	case 7044ULL: goto x86_l_1b84;
	case 7052ULL: goto x86_l_1b8c;
	case 7056ULL: goto x86_l_1b90;
	case 7063ULL: goto x86_l_1b97;
	case 7068ULL: goto x86_l_1b9c;
	case 7070ULL: goto x86_l_1b9e;
	case 7075ULL: goto x86_l_1ba3;
	case 7083ULL: goto x86_l_1bab;
	case 7086ULL: goto x86_l_1bae;
	case 7094ULL: goto x86_l_1bb6;
	case 7103ULL: goto x86_l_1bbf;
	case 7107ULL: goto x86_l_1bc3;
	case 7112ULL: goto x86_l_1bc8;
	case 7117ULL: goto x86_l_1bcd;
	case 7122ULL: goto x86_l_1bd2;
	case 7127ULL: goto x86_l_1bd7;
	case 7129ULL: goto x86_l_1bd9;
	case 7134ULL: goto x86_l_1bde;
	case 7136ULL: goto x86_l_1be0;
	case 7139ULL: goto x86_l_1be3;
	case 7145ULL: goto x86_l_1be9;
	case 7148ULL: goto x86_l_1bec;
	case 7154ULL: goto x86_l_1bf2;
	case 7160ULL: goto x86_l_1bf8;
	case 7165ULL: goto x86_l_1bfd;
	case 7169ULL: goto x86_l_1c01;
	case 7176ULL: goto x86_l_1c08;
	case 7181ULL: goto x86_l_1c0d;
	case 7186ULL: goto x86_l_1c12;
	case 7193ULL: goto x86_l_1c19;
	case 7196ULL: goto x86_l_1c1c;
	case 7203ULL: goto x86_l_1c23;
	case 7208ULL: goto x86_l_1c28;
	case 7213ULL: goto x86_l_1c2d;
	case 7215ULL: goto x86_l_1c2f;
	case 7219ULL: goto x86_l_1c33;
	case 7221ULL: goto x86_l_1c35;
	case 7223ULL: goto x86_l_1c37;
	case 7229ULL: goto x86_l_1c3d;
	case 7232ULL: goto x86_l_1c40;
	case 7238ULL: goto x86_l_1c46;
	case 7244ULL: goto x86_l_1c4c;
	case 7249ULL: goto x86_l_1c51;
	case 7253ULL: goto x86_l_1c55;
	case 7260ULL: goto x86_l_1c5c;
	case 7265ULL: goto x86_l_1c61;
	case 7270ULL: goto x86_l_1c66;
	case 7275ULL: goto x86_l_1c6b;
	case 7283ULL: goto x86_l_1c73;
	case 7287ULL: goto x86_l_1c77;
	case 7294ULL: goto x86_l_1c7e;
	case 7299ULL: goto x86_l_1c83;
	case 7301ULL: goto x86_l_1c85;
	case 7306ULL: goto x86_l_1c8a;
	case 7314ULL: goto x86_l_1c92;
	case 7317ULL: goto x86_l_1c95;
	case 7325ULL: goto x86_l_1c9d;
	case 7334ULL: goto x86_l_1ca6;
	case 7338ULL: goto x86_l_1caa;
	case 7343ULL: goto x86_l_1caf;
	case 7348ULL: goto x86_l_1cb4;
	case 7353ULL: goto x86_l_1cb9;
	case 7358ULL: goto x86_l_1cbe;
	case 7360ULL: goto x86_l_1cc0;
	case 7365ULL: goto x86_l_1cc5;
	case 7367ULL: goto x86_l_1cc7;
	case 7370ULL: goto x86_l_1cca;
	case 7376ULL: goto x86_l_1cd0;
	case 7379ULL: goto x86_l_1cd3;
	case 7385ULL: goto x86_l_1cd9;
	case 7391ULL: goto x86_l_1cdf;
	case 7396ULL: goto x86_l_1ce4;
	case 7400ULL: goto x86_l_1ce8;
	case 7407ULL: goto x86_l_1cef;
	case 7412ULL: goto x86_l_1cf4;
	case 7417ULL: goto x86_l_1cf9;
	case 7424ULL: goto x86_l_1d00;
	case 7427ULL: goto x86_l_1d03;
	case 7434ULL: goto x86_l_1d0a;
	case 7439ULL: goto x86_l_1d0f;
	case 7444ULL: goto x86_l_1d14;
	case 7446ULL: goto x86_l_1d16;
	case 7450ULL: goto x86_l_1d1a;
	case 7452ULL: goto x86_l_1d1c;
	case 7454ULL: goto x86_l_1d1e;
	case 7460ULL: goto x86_l_1d24;
	case 7463ULL: goto x86_l_1d27;
	case 7469ULL: goto x86_l_1d2d;
	case 7475ULL: goto x86_l_1d33;
	case 7480ULL: goto x86_l_1d38;
	case 7484ULL: goto x86_l_1d3c;
	case 7491ULL: goto x86_l_1d43;
	case 7496ULL: goto x86_l_1d48;
	case 7501ULL: goto x86_l_1d4d;
	case 7506ULL: goto x86_l_1d52;
	case 7514ULL: goto x86_l_1d5a;
	case 7518ULL: goto x86_l_1d5e;
	case 7525ULL: goto x86_l_1d65;
	case 7530ULL: goto x86_l_1d6a;
	case 7532ULL: goto x86_l_1d6c;
	case 7537ULL: goto x86_l_1d71;
	case 7545ULL: goto x86_l_1d79;
	case 7548ULL: goto x86_l_1d7c;
	case 7556ULL: goto x86_l_1d84;
	case 7565ULL: goto x86_l_1d8d;
	case 7569ULL: goto x86_l_1d91;
	case 7574ULL: goto x86_l_1d96;
	case 7579ULL: goto x86_l_1d9b;
	case 7584ULL: goto x86_l_1da0;
	case 7589ULL: goto x86_l_1da5;
	case 7591ULL: goto x86_l_1da7;
	case 7596ULL: goto x86_l_1dac;
	case 7598ULL: goto x86_l_1dae;
	case 7601ULL: goto x86_l_1db1;
	case 7607ULL: goto x86_l_1db7;
	case 7610ULL: goto x86_l_1dba;
	case 7616ULL: goto x86_l_1dc0;
	case 7622ULL: goto x86_l_1dc6;
	case 7627ULL: goto x86_l_1dcb;
	case 7631ULL: goto x86_l_1dcf;
	case 7638ULL: goto x86_l_1dd6;
	case 7643ULL: goto x86_l_1ddb;
	case 7648ULL: goto x86_l_1de0;
	case 7655ULL: goto x86_l_1de7;
	case 7658ULL: goto x86_l_1dea;
	case 7665ULL: goto x86_l_1df1;
	case 7670ULL: goto x86_l_1df6;
	case 7675ULL: goto x86_l_1dfb;
	case 7677ULL: goto x86_l_1dfd;
	case 7681ULL: goto x86_l_1e01;
	case 7683ULL: goto x86_l_1e03;
	case 7685ULL: goto x86_l_1e05;
	case 7691ULL: goto x86_l_1e0b;
	case 7694ULL: goto x86_l_1e0e;
	case 7700ULL: goto x86_l_1e14;
	case 7706ULL: goto x86_l_1e1a;
	case 7711ULL: goto x86_l_1e1f;
	case 7715ULL: goto x86_l_1e23;
	case 7722ULL: goto x86_l_1e2a;
	case 7727ULL: goto x86_l_1e2f;
	case 7732ULL: goto x86_l_1e34;
	case 7737ULL: goto x86_l_1e39;
	case 7745ULL: goto x86_l_1e41;
	case 7749ULL: goto x86_l_1e45;
	case 7756ULL: goto x86_l_1e4c;
	case 7761ULL: goto x86_l_1e51;
	case 7763ULL: goto x86_l_1e53;
	case 7768ULL: goto x86_l_1e58;
	case 7776ULL: goto x86_l_1e60;
	case 7779ULL: goto x86_l_1e63;
	case 7787ULL: goto x86_l_1e6b;
	case 7796ULL: goto x86_l_1e74;
	case 7800ULL: goto x86_l_1e78;
	case 7805ULL: goto x86_l_1e7d;
	case 7810ULL: goto x86_l_1e82;
	case 7815ULL: goto x86_l_1e87;
	case 7820ULL: goto x86_l_1e8c;
	case 7822ULL: goto x86_l_1e8e;
	case 7827ULL: goto x86_l_1e93;
	case 7829ULL: goto x86_l_1e95;
	case 7832ULL: goto x86_l_1e98;
	case 7838ULL: goto x86_l_1e9e;
	case 7841ULL: goto x86_l_1ea1;
	case 7847ULL: goto x86_l_1ea7;
	case 7853ULL: goto x86_l_1ead;
	case 7858ULL: goto x86_l_1eb2;
	case 7862ULL: goto x86_l_1eb6;
	case 7869ULL: goto x86_l_1ebd;
	case 7874ULL: goto x86_l_1ec2;
	case 7879ULL: goto x86_l_1ec7;
	case 7886ULL: goto x86_l_1ece;
	case 7889ULL: goto x86_l_1ed1;
	case 7896ULL: goto x86_l_1ed8;
	case 7901ULL: goto x86_l_1edd;
	case 7906ULL: goto x86_l_1ee2;
	case 7908ULL: goto x86_l_1ee4;
	case 7912ULL: goto x86_l_1ee8;
	case 7914ULL: goto x86_l_1eea;
	case 7916ULL: goto x86_l_1eec;
	case 7922ULL: goto x86_l_1ef2;
	case 7925ULL: goto x86_l_1ef5;
	case 7931ULL: goto x86_l_1efb;
	case 7937ULL: goto x86_l_1f01;
	case 7942ULL: goto x86_l_1f06;
	case 7946ULL: goto x86_l_1f0a;
	case 7953ULL: goto x86_l_1f11;
	case 7958ULL: goto x86_l_1f16;
	case 7963ULL: goto x86_l_1f1b;
	case 7968ULL: goto x86_l_1f20;
	case 7976ULL: goto x86_l_1f28;
	case 7980ULL: goto x86_l_1f2c;
	case 7987ULL: goto x86_l_1f33;
	case 7992ULL: goto x86_l_1f38;
	case 7994ULL: goto x86_l_1f3a;
	case 7999ULL: goto x86_l_1f3f;
	case 8007ULL: goto x86_l_1f47;
	case 8010ULL: goto x86_l_1f4a;
	case 8018ULL: goto x86_l_1f52;
	case 8027ULL: goto x86_l_1f5b;
	case 8031ULL: goto x86_l_1f5f;
	case 8036ULL: goto x86_l_1f64;
	case 8041ULL: goto x86_l_1f69;
	case 8046ULL: goto x86_l_1f6e;
	case 8051ULL: goto x86_l_1f73;
	case 8053ULL: goto x86_l_1f75;
	case 8058ULL: goto x86_l_1f7a;
	case 8060ULL: goto x86_l_1f7c;
	case 8063ULL: goto x86_l_1f7f;
	case 8069ULL: goto x86_l_1f85;
	case 8072ULL: goto x86_l_1f88;
	case 8078ULL: goto x86_l_1f8e;
	case 8084ULL: goto x86_l_1f94;
	case 8089ULL: goto x86_l_1f99;
	case 8093ULL: goto x86_l_1f9d;
	case 8100ULL: goto x86_l_1fa4;
	case 8105ULL: goto x86_l_1fa9;
	case 8110ULL: goto x86_l_1fae;
	case 8117ULL: goto x86_l_1fb5;
	case 8120ULL: goto x86_l_1fb8;
	case 8127ULL: goto x86_l_1fbf;
	case 8132ULL: goto x86_l_1fc4;
	case 8137ULL: goto x86_l_1fc9;
	case 8139ULL: goto x86_l_1fcb;
	case 8143ULL: goto x86_l_1fcf;
	case 8145ULL: goto x86_l_1fd1;
	case 8147ULL: goto x86_l_1fd3;
	case 8153ULL: goto x86_l_1fd9;
	case 8156ULL: goto x86_l_1fdc;
	case 8162ULL: goto x86_l_1fe2;
	case 8168ULL: goto x86_l_1fe8;
	case 8173ULL: goto x86_l_1fed;
	case 8177ULL: goto x86_l_1ff1;
	case 8184ULL: goto x86_l_1ff8;
	case 8189ULL: goto x86_l_1ffd;
	case 8194ULL: goto x86_l_2002;
	case 8199ULL: goto x86_l_2007;
	case 8207ULL: goto x86_l_200f;
	case 8211ULL: goto x86_l_2013;
	case 8218ULL: goto x86_l_201a;
	case 8223ULL: goto x86_l_201f;
	case 8225ULL: goto x86_l_2021;
	case 8230ULL: goto x86_l_2026;
	case 8238ULL: goto x86_l_202e;
	case 8241ULL: goto x86_l_2031;
	case 8249ULL: goto x86_l_2039;
	case 8258ULL: goto x86_l_2042;
	case 8265ULL: goto x86_l_2049;
	case 8270ULL: goto x86_l_204e;
	case 8275ULL: goto x86_l_2053;
	case 8280ULL: goto x86_l_2058;
	case 8285ULL: goto x86_l_205d;
	case 8287ULL: goto x86_l_205f;
	case 8292ULL: goto x86_l_2064;
	case 8294ULL: goto x86_l_2066;
	case 8297ULL: goto x86_l_2069;
	case 8303ULL: goto x86_l_206f;
	case 8306ULL: goto x86_l_2072;
	case 8312ULL: goto x86_l_2078;
	case 8318ULL: goto x86_l_207e;
	case 8323ULL: goto x86_l_2083;
	case 8327ULL: goto x86_l_2087;
	case 8334ULL: goto x86_l_208e;
	case 8339ULL: goto x86_l_2093;
	case 8344ULL: goto x86_l_2098;
	case 8351ULL: goto x86_l_209f;
	case 8354ULL: goto x86_l_20a2;
	case 8361ULL: goto x86_l_20a9;
	case 8366ULL: goto x86_l_20ae;
	case 8371ULL: goto x86_l_20b3;
	case 8373ULL: goto x86_l_20b5;
	case 8377ULL: goto x86_l_20b9;
	case 8379ULL: goto x86_l_20bb;
	case 8381ULL: goto x86_l_20bd;
	case 8387ULL: goto x86_l_20c3;
	case 8390ULL: goto x86_l_20c6;
	case 8396ULL: goto x86_l_20cc;
	case 8402ULL: goto x86_l_20d2;
	case 8407ULL: goto x86_l_20d7;
	case 8411ULL: goto x86_l_20db;
	case 8418ULL: goto x86_l_20e2;
	case 8423ULL: goto x86_l_20e7;
	case 8428ULL: goto x86_l_20ec;
	case 8433ULL: goto x86_l_20f1;
	case 8441ULL: goto x86_l_20f9;
	case 8445ULL: goto x86_l_20fd;
	case 8452ULL: goto x86_l_2104;
	case 8457ULL: goto x86_l_2109;
	case 8459ULL: goto x86_l_210b;
	case 8464ULL: goto x86_l_2110;
	case 8472ULL: goto x86_l_2118;
	case 8475ULL: goto x86_l_211b;
	case 8483ULL: goto x86_l_2123;
	case 8492ULL: goto x86_l_212c;
	case 8499ULL: goto x86_l_2133;
	case 8504ULL: goto x86_l_2138;
	case 8509ULL: goto x86_l_213d;
	case 8514ULL: goto x86_l_2142;
	case 8519ULL: goto x86_l_2147;
	case 8521ULL: goto x86_l_2149;
	case 8526ULL: goto x86_l_214e;
	case 8528ULL: goto x86_l_2150;
	case 8531ULL: goto x86_l_2153;
	case 8537ULL: goto x86_l_2159;
	case 8540ULL: goto x86_l_215c;
	case 8546ULL: goto x86_l_2162;
	case 8552ULL: goto x86_l_2168;
	case 8557ULL: goto x86_l_216d;
	case 8561ULL: goto x86_l_2171;
	case 8568ULL: goto x86_l_2178;
	case 8573ULL: goto x86_l_217d;
	case 8578ULL: goto x86_l_2182;
	case 8585ULL: goto x86_l_2189;
	case 8588ULL: goto x86_l_218c;
	case 8595ULL: goto x86_l_2193;
	case 8600ULL: goto x86_l_2198;
	case 8605ULL: goto x86_l_219d;
	case 8607ULL: goto x86_l_219f;
	case 8611ULL: goto x86_l_21a3;
	case 8613ULL: goto x86_l_21a5;
	case 8615ULL: goto x86_l_21a7;
	case 8621ULL: goto x86_l_21ad;
	case 8624ULL: goto x86_l_21b0;
	case 8630ULL: goto x86_l_21b6;
	case 8636ULL: goto x86_l_21bc;
	case 8641ULL: goto x86_l_21c1;
	case 8645ULL: goto x86_l_21c5;
	case 8652ULL: goto x86_l_21cc;
	case 8657ULL: goto x86_l_21d1;
	case 8662ULL: goto x86_l_21d6;
	case 8667ULL: goto x86_l_21db;
	case 8675ULL: goto x86_l_21e3;
	case 8679ULL: goto x86_l_21e7;
	case 8686ULL: goto x86_l_21ee;
	case 8691ULL: goto x86_l_21f3;
	case 8693ULL: goto x86_l_21f5;
	case 8698ULL: goto x86_l_21fa;
	case 8706ULL: goto x86_l_2202;
	case 8709ULL: goto x86_l_2205;
	case 8717ULL: goto x86_l_220d;
	case 8726ULL: goto x86_l_2216;
	case 8733ULL: goto x86_l_221d;
	case 8738ULL: goto x86_l_2222;
	case 8743ULL: goto x86_l_2227;
	case 8748ULL: goto x86_l_222c;
	case 8753ULL: goto x86_l_2231;
	case 8755ULL: goto x86_l_2233;
	case 8760ULL: goto x86_l_2238;
	case 8762ULL: goto x86_l_223a;
	case 8765ULL: goto x86_l_223d;
	case 8771ULL: goto x86_l_2243;
	case 8774ULL: goto x86_l_2246;
	case 8780ULL: goto x86_l_224c;
	case 8786ULL: goto x86_l_2252;
	case 8791ULL: goto x86_l_2257;
	case 8795ULL: goto x86_l_225b;
	case 8802ULL: goto x86_l_2262;
	case 8807ULL: goto x86_l_2267;
	case 8812ULL: goto x86_l_226c;
	case 8819ULL: goto x86_l_2273;
	case 8822ULL: goto x86_l_2276;
	case 8829ULL: goto x86_l_227d;
	case 8834ULL: goto x86_l_2282;
	case 8839ULL: goto x86_l_2287;
	case 8841ULL: goto x86_l_2289;
	case 8845ULL: goto x86_l_228d;
	case 8847ULL: goto x86_l_228f;
	case 8849ULL: goto x86_l_2291;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b35:
	/* 0x1b35: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1b3c:
	/* 0x1b3c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b41:
	/* 0x1b41: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1b46:
	/* 0x1b46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b48:
	/* 0x1b48: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b4c:
	/* 0x1b4c: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_1b4e:
	/* 0x1b4e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b50:
	/* 0x1b50: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_1b56:
	/* 0x1b56: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b59:
	/* 0x1b59: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1b5f:
	/* 0x1b5f: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_1b65:
	/* 0x1b65: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b6a:
	/* 0x1b6a: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1b6e:
	/* 0x1b6e: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1b75:
	/* 0x1b75: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b7a:
	/* 0x1b7a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b7f:
	/* 0x1b7f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b84:
	/* 0x1b84: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1b8c:
	/* 0x1b8c: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1b90:
	/* 0x1b90: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1b97:
	/* 0x1b97: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b9c:
	/* 0x1b9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b9e:
	/* 0x1b9e: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1ba3:
	/* 0x1ba3: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1bab:
	/* 0x1bab: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1bae:
	/* 0x1bae: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1bb6:
	/* 0x1bb6: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1bbf:
	/* 0x1bbf: lea    rdx,[r13+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1bc3:
	/* 0x1bc3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bc8:
	/* 0x1bc8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1bcd:
	/* 0x1bcd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bd2:
	/* 0x1bd2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bd7:
	/* 0x1bd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bd9:
	/* 0x1bd9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bde:
	/* 0x1bde: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_1be0:
	/* 0x1be0: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1be3:
	/* 0x1be3: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_1be9:
	/* 0x1be9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1bec:
	/* 0x1bec: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1bf2:
	/* 0x1bf2: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_1bf8:
	/* 0x1bf8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bfd:
	/* 0x1bfd: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1c01:
	/* 0x1c01: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1c08:
	/* 0x1c08: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1c0d:
	/* 0x1c0d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1c12:
	/* 0x1c12: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c19:
	/* 0x1c19: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c1c:
	/* 0x1c1c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1c23:
	/* 0x1c23: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c28:
	/* 0x1c28: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1c2d:
	/* 0x1c2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c2f:
	/* 0x1c2f: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c33:
	/* 0x1c33: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_1c35:
	/* 0x1c35: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c37:
	/* 0x1c37: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_1c3d:
	/* 0x1c3d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1c40:
	/* 0x1c40: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1c46:
	/* 0x1c46: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_1c4c:
	/* 0x1c4c: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c51:
	/* 0x1c51: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1c55:
	/* 0x1c55: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1c5c:
	/* 0x1c5c: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c61:
	/* 0x1c61: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c66:
	/* 0x1c66: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c6b:
	/* 0x1c6b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c73:
	/* 0x1c73: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1c77:
	/* 0x1c77: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1c7e:
	/* 0x1c7e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c83:
	/* 0x1c83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c85:
	/* 0x1c85: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1c8a:
	/* 0x1c8a: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1c92:
	/* 0x1c92: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1c95:
	/* 0x1c95: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1c9d:
	/* 0x1c9d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1ca6:
	/* 0x1ca6: lea    rdx,[r13+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1caa:
	/* 0x1caa: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1caf:
	/* 0x1caf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1cb4:
	/* 0x1cb4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cb9:
	/* 0x1cb9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cbe:
	/* 0x1cbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cc0:
	/* 0x1cc0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cc5:
	/* 0x1cc5: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_1cc7:
	/* 0x1cc7: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1cca:
	/* 0x1cca: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_1cd0:
	/* 0x1cd0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1cd3:
	/* 0x1cd3: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1cd9:
	/* 0x1cd9: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_1cdf:
	/* 0x1cdf: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ce4:
	/* 0x1ce4: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1ce8:
	/* 0x1ce8: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1cef:
	/* 0x1cef: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1cf4:
	/* 0x1cf4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1cf9:
	/* 0x1cf9: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1d00:
	/* 0x1d00: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1d03:
	/* 0x1d03: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1d0a:
	/* 0x1d0a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d0f:
	/* 0x1d0f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1d14:
	/* 0x1d14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d16:
	/* 0x1d16: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d1a:
	/* 0x1d1a: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_1d1c:
	/* 0x1d1c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d1e:
	/* 0x1d1e: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_1d24:
	/* 0x1d24: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d27:
	/* 0x1d27: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1d2d:
	/* 0x1d2d: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_1d33:
	/* 0x1d33: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d38:
	/* 0x1d38: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1d3c:
	/* 0x1d3c: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1d43:
	/* 0x1d43: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d48:
	/* 0x1d48: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d4d:
	/* 0x1d4d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d52:
	/* 0x1d52: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1d5a:
	/* 0x1d5a: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1d5e:
	/* 0x1d5e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1d65:
	/* 0x1d65: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d6a:
	/* 0x1d6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d6c:
	/* 0x1d6c: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1d71:
	/* 0x1d71: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1d79:
	/* 0x1d79: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1d7c:
	/* 0x1d7c: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1d84:
	/* 0x1d84: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1d8d:
	/* 0x1d8d: lea    rdx,[r13+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1d91:
	/* 0x1d91: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d96:
	/* 0x1d96: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d9b:
	/* 0x1d9b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1da0:
	/* 0x1da0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1da5:
	/* 0x1da5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1da7:
	/* 0x1da7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dac:
	/* 0x1dac: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_1dae:
	/* 0x1dae: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1db1:
	/* 0x1db1: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_1db7:
	/* 0x1db7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1dba:
	/* 0x1dba: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1dc0:
	/* 0x1dc0: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_1dc6:
	/* 0x1dc6: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dcb:
	/* 0x1dcb: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1dcf:
	/* 0x1dcf: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1dd6:
	/* 0x1dd6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1ddb:
	/* 0x1ddb: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1de0:
	/* 0x1de0: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1de7:
	/* 0x1de7: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1dea:
	/* 0x1dea: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1df1:
	/* 0x1df1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1df6:
	/* 0x1df6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1dfb:
	/* 0x1dfb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dfd:
	/* 0x1dfd: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e01:
	/* 0x1e01: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_1e03:
	/* 0x1e03: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e05:
	/* 0x1e05: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_1e0b:
	/* 0x1e0b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e0e:
	/* 0x1e0e: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1e14:
	/* 0x1e14: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_1e1a:
	/* 0x1e1a: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e1f:
	/* 0x1e1f: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1e23:
	/* 0x1e23: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1e2a:
	/* 0x1e2a: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e2f:
	/* 0x1e2f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e34:
	/* 0x1e34: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e39:
	/* 0x1e39: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e41:
	/* 0x1e41: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1e45:
	/* 0x1e45: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1e4c:
	/* 0x1e4c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e51:
	/* 0x1e51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e53:
	/* 0x1e53: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1e58:
	/* 0x1e58: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1e60:
	/* 0x1e60: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1e63:
	/* 0x1e63: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1e6b:
	/* 0x1e6b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1e74:
	/* 0x1e74: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1e78:
	/* 0x1e78: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e7d:
	/* 0x1e7d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e82:
	/* 0x1e82: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e87:
	/* 0x1e87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e8c:
	/* 0x1e8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e8e:
	/* 0x1e8e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e93:
	/* 0x1e93: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_1e95:
	/* 0x1e95: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1e98:
	/* 0x1e98: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_1e9e:
	/* 0x1e9e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ea1:
	/* 0x1ea1: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1ea7:
	/* 0x1ea7: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_1ead:
	/* 0x1ead: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1eb2:
	/* 0x1eb2: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1eb6:
	/* 0x1eb6: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1ebd:
	/* 0x1ebd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1ec2:
	/* 0x1ec2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1ec7:
	/* 0x1ec7: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1ece:
	/* 0x1ece: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ed1:
	/* 0x1ed1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1ed8:
	/* 0x1ed8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1edd:
	/* 0x1edd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1ee2:
	/* 0x1ee2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ee4:
	/* 0x1ee4: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ee8:
	/* 0x1ee8: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_1eea:
	/* 0x1eea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1eec:
	/* 0x1eec: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_1ef2:
	/* 0x1ef2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ef5:
	/* 0x1ef5: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1efb:
	/* 0x1efb: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_1f01:
	/* 0x1f01: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f06:
	/* 0x1f06: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1f0a:
	/* 0x1f0a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1f11:
	/* 0x1f11: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f16:
	/* 0x1f16: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f1b:
	/* 0x1f1b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f20:
	/* 0x1f20: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f28:
	/* 0x1f28: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1f2c:
	/* 0x1f2c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1f33:
	/* 0x1f33: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f38:
	/* 0x1f38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f3a:
	/* 0x1f3a: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1f3f:
	/* 0x1f3f: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1f47:
	/* 0x1f47: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1f4a:
	/* 0x1f4a: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1f52:
	/* 0x1f52: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1f5b:
	/* 0x1f5b: lea    rdx,[r13+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1f5f:
	/* 0x1f5f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f64:
	/* 0x1f64: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f69:
	/* 0x1f69: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f6e:
	/* 0x1f6e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f73:
	/* 0x1f73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f75:
	/* 0x1f75: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f7a:
	/* 0x1f7a: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_1f7c:
	/* 0x1f7c: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_1f7f:
	/* 0x1f7f: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_1f85:
	/* 0x1f85: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f88:
	/* 0x1f88: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_1f8e:
	/* 0x1f8e: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_1f94:
	/* 0x1f94: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f99:
	/* 0x1f99: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1f9d:
	/* 0x1f9d: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1fa4:
	/* 0x1fa4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1fa9:
	/* 0x1fa9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1fae:
	/* 0x1fae: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1fb5:
	/* 0x1fb5: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1fb8:
	/* 0x1fb8: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1fbf:
	/* 0x1fbf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fc4:
	/* 0x1fc4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1fc9:
	/* 0x1fc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fcb:
	/* 0x1fcb: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1fcf:
	/* 0x1fcf: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_1fd1:
	/* 0x1fd1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fd3:
	/* 0x1fd3: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_1fd9:
	/* 0x1fd9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1fdc:
	/* 0x1fdc: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_1fe2:
	/* 0x1fe2: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_1fe8:
	/* 0x1fe8: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fed:
	/* 0x1fed: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1ff1:
	/* 0x1ff1: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1ff8:
	/* 0x1ff8: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ffd:
	/* 0x1ffd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2002:
	/* 0x2002: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2007:
	/* 0x2007: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_200f:
	/* 0x200f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2013:
	/* 0x2013: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_201a:
	/* 0x201a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_201f:
	/* 0x201f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2021:
	/* 0x2021: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2026:
	/* 0x2026: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_202e:
	/* 0x202e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2031:
	/* 0x2031: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2039:
	/* 0x2039: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2042:
	/* 0x2042: lea    rdx,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2049:
	/* 0x2049: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_204e:
	/* 0x204e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2053:
	/* 0x2053: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2058:
	/* 0x2058: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_205d:
	/* 0x205d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_205f:
	/* 0x205f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2064:
	/* 0x2064: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_2066:
	/* 0x2066: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2069:
	/* 0x2069: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_206f:
	/* 0x206f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2072:
	/* 0x2072: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2078:
	/* 0x2078: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_207e:
	/* 0x207e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2083:
	/* 0x2083: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2087:
	/* 0x2087: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_208e:
	/* 0x208e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2093:
	/* 0x2093: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2098:
	/* 0x2098: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_209f:
	/* 0x209f: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_20a2:
	/* 0x20a2: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_20a9:
	/* 0x20a9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20ae:
	/* 0x20ae: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_20b3:
	/* 0x20b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20b5:
	/* 0x20b5: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_20b9:
	/* 0x20b9: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_20bb:
	/* 0x20bb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20bd:
	/* 0x20bd: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_20c3:
	/* 0x20c3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_20c6:
	/* 0x20c6: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_20cc:
	/* 0x20cc: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_20d2:
	/* 0x20d2: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20d7:
	/* 0x20d7: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_20db:
	/* 0x20db: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_20e2:
	/* 0x20e2: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_20e7:
	/* 0x20e7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_20ec:
	/* 0x20ec: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20f1:
	/* 0x20f1: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_20f9:
	/* 0x20f9: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_20fd:
	/* 0x20fd: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2104:
	/* 0x2104: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2109:
	/* 0x2109: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_210b:
	/* 0x210b: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2110:
	/* 0x2110: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2118:
	/* 0x2118: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_211b:
	/* 0x211b: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2123:
	/* 0x2123: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_212c:
	/* 0x212c: lea    rdx,[r13+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2133:
	/* 0x2133: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2138:
	/* 0x2138: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_213d:
	/* 0x213d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2142:
	/* 0x2142: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2147:
	/* 0x2147: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2149:
	/* 0x2149: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_214e:
	/* 0x214e: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_2150:
	/* 0x2150: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2153:
	/* 0x2153: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_2159:
	/* 0x2159: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_215c:
	/* 0x215c: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2162:
	/* 0x2162: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_2168:
	/* 0x2168: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_216d:
	/* 0x216d: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2171:
	/* 0x2171: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2178:
	/* 0x2178: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_217d:
	/* 0x217d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2182:
	/* 0x2182: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2189:
	/* 0x2189: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_218c:
	/* 0x218c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2193:
	/* 0x2193: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2198:
	/* 0x2198: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_219d:
	/* 0x219d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_219f:
	/* 0x219f: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_21a3:
	/* 0x21a3: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_21a5:
	/* 0x21a5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21a7:
	/* 0x21a7: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_21ad:
	/* 0x21ad: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_21b0:
	/* 0x21b0: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_21b6:
	/* 0x21b6: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_21bc:
	/* 0x21bc: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21c1:
	/* 0x21c1: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_21c5:
	/* 0x21c5: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_21cc:
	/* 0x21cc: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_21d1:
	/* 0x21d1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_21d6:
	/* 0x21d6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21db:
	/* 0x21db: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_21e3:
	/* 0x21e3: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_21e7:
	/* 0x21e7: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_21ee:
	/* 0x21ee: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_21f3:
	/* 0x21f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21f5:
	/* 0x21f5: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_21fa:
	/* 0x21fa: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2202:
	/* 0x2202: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2205:
	/* 0x2205: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_220d:
	/* 0x220d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2216:
	/* 0x2216: lea    rdx,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_221d:
	/* 0x221d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2222:
	/* 0x2222: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2227:
	/* 0x2227: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_222c:
	/* 0x222c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2231:
	/* 0x2231: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2233:
	/* 0x2233: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2238:
	/* 0x2238: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_223a:
	/* 0x223a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_223d:
	/* 0x223d: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_2243:
	/* 0x2243: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2246:
	/* 0x2246: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_224c:
	/* 0x224c: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_2252:
	/* 0x2252: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2257:
	/* 0x2257: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_225b:
	/* 0x225b: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2262:
	/* 0x2262: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2267:
	/* 0x2267: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_226c:
	/* 0x226c: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2273:
	/* 0x2273: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2276:
	/* 0x2276: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_227d:
	/* 0x227d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2282:
	/* 0x2282: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2287:
	/* 0x2287: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2289:
	/* 0x2289: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_228d:
	/* 0x228d: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_228f:
	/* 0x228f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2291:
	/* 0x2291: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
	return 8855ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8855ULL: goto x86_l_2297;
	case 8858ULL: goto x86_l_229a;
	case 8864ULL: goto x86_l_22a0;
	case 8870ULL: goto x86_l_22a6;
	case 8875ULL: goto x86_l_22ab;
	case 8879ULL: goto x86_l_22af;
	case 8886ULL: goto x86_l_22b6;
	case 8891ULL: goto x86_l_22bb;
	case 8896ULL: goto x86_l_22c0;
	case 8901ULL: goto x86_l_22c5;
	case 8909ULL: goto x86_l_22cd;
	case 8913ULL: goto x86_l_22d1;
	case 8920ULL: goto x86_l_22d8;
	case 8925ULL: goto x86_l_22dd;
	case 8927ULL: goto x86_l_22df;
	case 8932ULL: goto x86_l_22e4;
	case 8940ULL: goto x86_l_22ec;
	case 8943ULL: goto x86_l_22ef;
	case 8951ULL: goto x86_l_22f7;
	case 8960ULL: goto x86_l_2300;
	case 8967ULL: goto x86_l_2307;
	case 8972ULL: goto x86_l_230c;
	case 8977ULL: goto x86_l_2311;
	case 8982ULL: goto x86_l_2316;
	case 8987ULL: goto x86_l_231b;
	case 8989ULL: goto x86_l_231d;
	case 8994ULL: goto x86_l_2322;
	case 8996ULL: goto x86_l_2324;
	case 8999ULL: goto x86_l_2327;
	case 9005ULL: goto x86_l_232d;
	case 9008ULL: goto x86_l_2330;
	case 9014ULL: goto x86_l_2336;
	case 9020ULL: goto x86_l_233c;
	case 9025ULL: goto x86_l_2341;
	case 9029ULL: goto x86_l_2345;
	case 9036ULL: goto x86_l_234c;
	case 9041ULL: goto x86_l_2351;
	case 9046ULL: goto x86_l_2356;
	case 9053ULL: goto x86_l_235d;
	case 9056ULL: goto x86_l_2360;
	case 9063ULL: goto x86_l_2367;
	case 9068ULL: goto x86_l_236c;
	case 9073ULL: goto x86_l_2371;
	case 9075ULL: goto x86_l_2373;
	case 9079ULL: goto x86_l_2377;
	case 9081ULL: goto x86_l_2379;
	case 9083ULL: goto x86_l_237b;
	case 9089ULL: goto x86_l_2381;
	case 9092ULL: goto x86_l_2384;
	case 9098ULL: goto x86_l_238a;
	case 9104ULL: goto x86_l_2390;
	case 9109ULL: goto x86_l_2395;
	case 9113ULL: goto x86_l_2399;
	case 9120ULL: goto x86_l_23a0;
	case 9125ULL: goto x86_l_23a5;
	case 9130ULL: goto x86_l_23aa;
	case 9135ULL: goto x86_l_23af;
	case 9143ULL: goto x86_l_23b7;
	case 9147ULL: goto x86_l_23bb;
	case 9154ULL: goto x86_l_23c2;
	case 9159ULL: goto x86_l_23c7;
	case 9161ULL: goto x86_l_23c9;
	case 9166ULL: goto x86_l_23ce;
	case 9174ULL: goto x86_l_23d6;
	case 9177ULL: goto x86_l_23d9;
	case 9185ULL: goto x86_l_23e1;
	case 9194ULL: goto x86_l_23ea;
	case 9201ULL: goto x86_l_23f1;
	case 9206ULL: goto x86_l_23f6;
	case 9211ULL: goto x86_l_23fb;
	case 9216ULL: goto x86_l_2400;
	case 9221ULL: goto x86_l_2405;
	case 9223ULL: goto x86_l_2407;
	case 9228ULL: goto x86_l_240c;
	case 9230ULL: goto x86_l_240e;
	case 9233ULL: goto x86_l_2411;
	case 9239ULL: goto x86_l_2417;
	case 9242ULL: goto x86_l_241a;
	case 9248ULL: goto x86_l_2420;
	case 9254ULL: goto x86_l_2426;
	case 9259ULL: goto x86_l_242b;
	case 9263ULL: goto x86_l_242f;
	case 9270ULL: goto x86_l_2436;
	case 9275ULL: goto x86_l_243b;
	case 9280ULL: goto x86_l_2440;
	case 9287ULL: goto x86_l_2447;
	case 9290ULL: goto x86_l_244a;
	case 9297ULL: goto x86_l_2451;
	case 9302ULL: goto x86_l_2456;
	case 9307ULL: goto x86_l_245b;
	case 9309ULL: goto x86_l_245d;
	case 9313ULL: goto x86_l_2461;
	case 9315ULL: goto x86_l_2463;
	case 9317ULL: goto x86_l_2465;
	case 9323ULL: goto x86_l_246b;
	case 9326ULL: goto x86_l_246e;
	case 9332ULL: goto x86_l_2474;
	case 9338ULL: goto x86_l_247a;
	case 9343ULL: goto x86_l_247f;
	case 9347ULL: goto x86_l_2483;
	case 9354ULL: goto x86_l_248a;
	case 9359ULL: goto x86_l_248f;
	case 9364ULL: goto x86_l_2494;
	case 9369ULL: goto x86_l_2499;
	case 9377ULL: goto x86_l_24a1;
	case 9381ULL: goto x86_l_24a5;
	case 9388ULL: goto x86_l_24ac;
	case 9393ULL: goto x86_l_24b1;
	case 9395ULL: goto x86_l_24b3;
	case 9400ULL: goto x86_l_24b8;
	case 9408ULL: goto x86_l_24c0;
	case 9411ULL: goto x86_l_24c3;
	case 9419ULL: goto x86_l_24cb;
	case 9428ULL: goto x86_l_24d4;
	case 9435ULL: goto x86_l_24db;
	case 9440ULL: goto x86_l_24e0;
	case 9445ULL: goto x86_l_24e5;
	case 9450ULL: goto x86_l_24ea;
	case 9455ULL: goto x86_l_24ef;
	case 9457ULL: goto x86_l_24f1;
	case 9462ULL: goto x86_l_24f6;
	case 9464ULL: goto x86_l_24f8;
	case 9467ULL: goto x86_l_24fb;
	case 9473ULL: goto x86_l_2501;
	case 9476ULL: goto x86_l_2504;
	case 9482ULL: goto x86_l_250a;
	case 9488ULL: goto x86_l_2510;
	case 9493ULL: goto x86_l_2515;
	case 9497ULL: goto x86_l_2519;
	case 9504ULL: goto x86_l_2520;
	case 9509ULL: goto x86_l_2525;
	case 9514ULL: goto x86_l_252a;
	case 9521ULL: goto x86_l_2531;
	case 9524ULL: goto x86_l_2534;
	case 9531ULL: goto x86_l_253b;
	case 9536ULL: goto x86_l_2540;
	case 9541ULL: goto x86_l_2545;
	case 9543ULL: goto x86_l_2547;
	case 9547ULL: goto x86_l_254b;
	case 9549ULL: goto x86_l_254d;
	case 9551ULL: goto x86_l_254f;
	case 9557ULL: goto x86_l_2555;
	case 9560ULL: goto x86_l_2558;
	case 9566ULL: goto x86_l_255e;
	case 9572ULL: goto x86_l_2564;
	case 9577ULL: goto x86_l_2569;
	case 9581ULL: goto x86_l_256d;
	case 9588ULL: goto x86_l_2574;
	case 9593ULL: goto x86_l_2579;
	case 9598ULL: goto x86_l_257e;
	case 9603ULL: goto x86_l_2583;
	case 9611ULL: goto x86_l_258b;
	case 9615ULL: goto x86_l_258f;
	case 9622ULL: goto x86_l_2596;
	case 9627ULL: goto x86_l_259b;
	case 9629ULL: goto x86_l_259d;
	case 9634ULL: goto x86_l_25a2;
	case 9642ULL: goto x86_l_25aa;
	case 9645ULL: goto x86_l_25ad;
	case 9653ULL: goto x86_l_25b5;
	case 9662ULL: goto x86_l_25be;
	case 9669ULL: goto x86_l_25c5;
	case 9674ULL: goto x86_l_25ca;
	case 9679ULL: goto x86_l_25cf;
	case 9684ULL: goto x86_l_25d4;
	case 9689ULL: goto x86_l_25d9;
	case 9691ULL: goto x86_l_25db;
	case 9696ULL: goto x86_l_25e0;
	case 9698ULL: goto x86_l_25e2;
	case 9701ULL: goto x86_l_25e5;
	case 9707ULL: goto x86_l_25eb;
	case 9710ULL: goto x86_l_25ee;
	case 9716ULL: goto x86_l_25f4;
	case 9722ULL: goto x86_l_25fa;
	case 9727ULL: goto x86_l_25ff;
	case 9731ULL: goto x86_l_2603;
	case 9738ULL: goto x86_l_260a;
	case 9743ULL: goto x86_l_260f;
	case 9748ULL: goto x86_l_2614;
	case 9755ULL: goto x86_l_261b;
	case 9758ULL: goto x86_l_261e;
	case 9765ULL: goto x86_l_2625;
	case 9770ULL: goto x86_l_262a;
	case 9775ULL: goto x86_l_262f;
	case 9777ULL: goto x86_l_2631;
	case 9781ULL: goto x86_l_2635;
	case 9783ULL: goto x86_l_2637;
	case 9785ULL: goto x86_l_2639;
	case 9791ULL: goto x86_l_263f;
	case 9794ULL: goto x86_l_2642;
	case 9800ULL: goto x86_l_2648;
	case 9806ULL: goto x86_l_264e;
	case 9811ULL: goto x86_l_2653;
	case 9815ULL: goto x86_l_2657;
	case 9822ULL: goto x86_l_265e;
	case 9827ULL: goto x86_l_2663;
	case 9832ULL: goto x86_l_2668;
	case 9837ULL: goto x86_l_266d;
	case 9845ULL: goto x86_l_2675;
	case 9849ULL: goto x86_l_2679;
	case 9856ULL: goto x86_l_2680;
	case 9861ULL: goto x86_l_2685;
	case 9863ULL: goto x86_l_2687;
	case 9868ULL: goto x86_l_268c;
	case 9876ULL: goto x86_l_2694;
	case 9879ULL: goto x86_l_2697;
	case 9887ULL: goto x86_l_269f;
	case 9896ULL: goto x86_l_26a8;
	case 9903ULL: goto x86_l_26af;
	case 9908ULL: goto x86_l_26b4;
	case 9913ULL: goto x86_l_26b9;
	case 9918ULL: goto x86_l_26be;
	case 9923ULL: goto x86_l_26c3;
	case 9925ULL: goto x86_l_26c5;
	case 9930ULL: goto x86_l_26ca;
	case 9932ULL: goto x86_l_26cc;
	case 9935ULL: goto x86_l_26cf;
	case 9941ULL: goto x86_l_26d5;
	case 9944ULL: goto x86_l_26d8;
	case 9950ULL: goto x86_l_26de;
	case 9956ULL: goto x86_l_26e4;
	case 9961ULL: goto x86_l_26e9;
	case 9965ULL: goto x86_l_26ed;
	case 9972ULL: goto x86_l_26f4;
	case 9977ULL: goto x86_l_26f9;
	case 9982ULL: goto x86_l_26fe;
	case 9989ULL: goto x86_l_2705;
	case 9992ULL: goto x86_l_2708;
	case 9999ULL: goto x86_l_270f;
	case 10004ULL: goto x86_l_2714;
	case 10009ULL: goto x86_l_2719;
	case 10011ULL: goto x86_l_271b;
	case 10015ULL: goto x86_l_271f;
	case 10017ULL: goto x86_l_2721;
	case 10019ULL: goto x86_l_2723;
	case 10025ULL: goto x86_l_2729;
	case 10028ULL: goto x86_l_272c;
	case 10034ULL: goto x86_l_2732;
	case 10040ULL: goto x86_l_2738;
	case 10045ULL: goto x86_l_273d;
	case 10049ULL: goto x86_l_2741;
	case 10056ULL: goto x86_l_2748;
	case 10061ULL: goto x86_l_274d;
	case 10066ULL: goto x86_l_2752;
	case 10071ULL: goto x86_l_2757;
	case 10079ULL: goto x86_l_275f;
	case 10083ULL: goto x86_l_2763;
	case 10090ULL: goto x86_l_276a;
	case 10095ULL: goto x86_l_276f;
	case 10097ULL: goto x86_l_2771;
	case 10102ULL: goto x86_l_2776;
	case 10110ULL: goto x86_l_277e;
	case 10113ULL: goto x86_l_2781;
	case 10121ULL: goto x86_l_2789;
	case 10130ULL: goto x86_l_2792;
	case 10137ULL: goto x86_l_2799;
	case 10142ULL: goto x86_l_279e;
	case 10147ULL: goto x86_l_27a3;
	case 10152ULL: goto x86_l_27a8;
	case 10157ULL: goto x86_l_27ad;
	case 10159ULL: goto x86_l_27af;
	case 10164ULL: goto x86_l_27b4;
	case 10166ULL: goto x86_l_27b6;
	case 10169ULL: goto x86_l_27b9;
	case 10175ULL: goto x86_l_27bf;
	case 10178ULL: goto x86_l_27c2;
	case 10184ULL: goto x86_l_27c8;
	case 10190ULL: goto x86_l_27ce;
	case 10195ULL: goto x86_l_27d3;
	case 10199ULL: goto x86_l_27d7;
	case 10206ULL: goto x86_l_27de;
	case 10211ULL: goto x86_l_27e3;
	case 10216ULL: goto x86_l_27e8;
	case 10223ULL: goto x86_l_27ef;
	case 10226ULL: goto x86_l_27f2;
	case 10233ULL: goto x86_l_27f9;
	case 10238ULL: goto x86_l_27fe;
	case 10243ULL: goto x86_l_2803;
	case 10245ULL: goto x86_l_2805;
	case 10249ULL: goto x86_l_2809;
	case 10251ULL: goto x86_l_280b;
	case 10253ULL: goto x86_l_280d;
	case 10259ULL: goto x86_l_2813;
	case 10262ULL: goto x86_l_2816;
	case 10268ULL: goto x86_l_281c;
	case 10274ULL: goto x86_l_2822;
	case 10279ULL: goto x86_l_2827;
	case 10283ULL: goto x86_l_282b;
	case 10290ULL: goto x86_l_2832;
	case 10295ULL: goto x86_l_2837;
	case 10300ULL: goto x86_l_283c;
	case 10305ULL: goto x86_l_2841;
	case 10313ULL: goto x86_l_2849;
	case 10317ULL: goto x86_l_284d;
	case 10324ULL: goto x86_l_2854;
	case 10329ULL: goto x86_l_2859;
	case 10331ULL: goto x86_l_285b;
	case 10336ULL: goto x86_l_2860;
	case 10344ULL: goto x86_l_2868;
	case 10347ULL: goto x86_l_286b;
	case 10355ULL: goto x86_l_2873;
	case 10364ULL: goto x86_l_287c;
	case 10371ULL: goto x86_l_2883;
	case 10376ULL: goto x86_l_2888;
	case 10381ULL: goto x86_l_288d;
	case 10386ULL: goto x86_l_2892;
	case 10391ULL: goto x86_l_2897;
	case 10393ULL: goto x86_l_2899;
	case 10398ULL: goto x86_l_289e;
	case 10400ULL: goto x86_l_28a0;
	case 10403ULL: goto x86_l_28a3;
	case 10409ULL: goto x86_l_28a9;
	case 10412ULL: goto x86_l_28ac;
	case 10418ULL: goto x86_l_28b2;
	case 10424ULL: goto x86_l_28b8;
	case 10429ULL: goto x86_l_28bd;
	case 10433ULL: goto x86_l_28c1;
	case 10440ULL: goto x86_l_28c8;
	case 10445ULL: goto x86_l_28cd;
	case 10450ULL: goto x86_l_28d2;
	case 10457ULL: goto x86_l_28d9;
	case 10460ULL: goto x86_l_28dc;
	case 10467ULL: goto x86_l_28e3;
	case 10472ULL: goto x86_l_28e8;
	case 10477ULL: goto x86_l_28ed;
	case 10479ULL: goto x86_l_28ef;
	case 10483ULL: goto x86_l_28f3;
	case 10485ULL: goto x86_l_28f5;
	case 10487ULL: goto x86_l_28f7;
	case 10493ULL: goto x86_l_28fd;
	case 10496ULL: goto x86_l_2900;
	case 10502ULL: goto x86_l_2906;
	case 10508ULL: goto x86_l_290c;
	case 10513ULL: goto x86_l_2911;
	case 10517ULL: goto x86_l_2915;
	case 10524ULL: goto x86_l_291c;
	case 10529ULL: goto x86_l_2921;
	case 10534ULL: goto x86_l_2926;
	case 10539ULL: goto x86_l_292b;
	case 10547ULL: goto x86_l_2933;
	case 10551ULL: goto x86_l_2937;
	case 10558ULL: goto x86_l_293e;
	case 10563ULL: goto x86_l_2943;
	case 10565ULL: goto x86_l_2945;
	case 10570ULL: goto x86_l_294a;
	case 10578ULL: goto x86_l_2952;
	case 10581ULL: goto x86_l_2955;
	case 10589ULL: goto x86_l_295d;
	case 10598ULL: goto x86_l_2966;
	case 10605ULL: goto x86_l_296d;
	case 10610ULL: goto x86_l_2972;
	case 10615ULL: goto x86_l_2977;
	case 10620ULL: goto x86_l_297c;
	case 10625ULL: goto x86_l_2981;
	case 10627ULL: goto x86_l_2983;
	case 10632ULL: goto x86_l_2988;
	case 10634ULL: goto x86_l_298a;
	case 10637ULL: goto x86_l_298d;
	case 10643ULL: goto x86_l_2993;
	case 10646ULL: goto x86_l_2996;
	case 10652ULL: goto x86_l_299c;
	case 10658ULL: goto x86_l_29a2;
	case 10663ULL: goto x86_l_29a7;
	case 10667ULL: goto x86_l_29ab;
	case 10674ULL: goto x86_l_29b2;
	case 10679ULL: goto x86_l_29b7;
	case 10684ULL: goto x86_l_29bc;
	case 10691ULL: goto x86_l_29c3;
	case 10694ULL: goto x86_l_29c6;
	case 10701ULL: goto x86_l_29cd;
	case 10706ULL: goto x86_l_29d2;
	case 10711ULL: goto x86_l_29d7;
	case 10713ULL: goto x86_l_29d9;
	case 10717ULL: goto x86_l_29dd;
	case 10719ULL: goto x86_l_29df;
	case 10721ULL: goto x86_l_29e1;
	case 10727ULL: goto x86_l_29e7;
	case 10730ULL: goto x86_l_29ea;
	case 10736ULL: goto x86_l_29f0;
	case 10742ULL: goto x86_l_29f6;
	case 10747ULL: goto x86_l_29fb;
	case 10751ULL: goto x86_l_29ff;
	case 10758ULL: goto x86_l_2a06;
	case 10763ULL: goto x86_l_2a0b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2297:
	/* 0x2297: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_229a:
	/* 0x229a: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_22a0:
	/* 0x22a0: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_22a6:
	/* 0x22a6: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22ab:
	/* 0x22ab: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_22af:
	/* 0x22af: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_22b6:
	/* 0x22b6: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_22bb:
	/* 0x22bb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_22c0:
	/* 0x22c0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22c5:
	/* 0x22c5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_22cd:
	/* 0x22cd: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_22d1:
	/* 0x22d1: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_22d8:
	/* 0x22d8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_22dd:
	/* 0x22dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22df:
	/* 0x22df: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_22e4:
	/* 0x22e4: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_22ec:
	/* 0x22ec: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_22ef:
	/* 0x22ef: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_22f7:
	/* 0x22f7: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2300:
	/* 0x2300: lea    rdx,[r13+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2307:
	/* 0x2307: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_230c:
	/* 0x230c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2311:
	/* 0x2311: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2316:
	/* 0x2316: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_231b:
	/* 0x231b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_231d:
	/* 0x231d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2322:
	/* 0x2322: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_2324:
	/* 0x2324: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2327:
	/* 0x2327: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_232d:
	/* 0x232d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2330:
	/* 0x2330: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2336:
	/* 0x2336: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_233c:
	/* 0x233c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2341:
	/* 0x2341: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2345:
	/* 0x2345: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_234c:
	/* 0x234c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2351:
	/* 0x2351: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2356:
	/* 0x2356: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_235d:
	/* 0x235d: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2360:
	/* 0x2360: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2367:
	/* 0x2367: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_236c:
	/* 0x236c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2371:
	/* 0x2371: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2373:
	/* 0x2373: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2377:
	/* 0x2377: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_2379:
	/* 0x2379: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_237b:
	/* 0x237b: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_2381:
	/* 0x2381: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2384:
	/* 0x2384: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_238a:
	/* 0x238a: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_2390:
	/* 0x2390: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2395:
	/* 0x2395: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2399:
	/* 0x2399: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_23a0:
	/* 0x23a0: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_23a5:
	/* 0x23a5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_23aa:
	/* 0x23aa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23af:
	/* 0x23af: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_23b7:
	/* 0x23b7: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_23bb:
	/* 0x23bb: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_23c2:
	/* 0x23c2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_23c7:
	/* 0x23c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23c9:
	/* 0x23c9: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_23ce:
	/* 0x23ce: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_23d6:
	/* 0x23d6: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_23d9:
	/* 0x23d9: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_23e1:
	/* 0x23e1: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_23ea:
	/* 0x23ea: lea    rdx,[r13+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_23f1:
	/* 0x23f1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23f6:
	/* 0x23f6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_23fb:
	/* 0x23fb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2400:
	/* 0x2400: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2405:
	/* 0x2405: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2407:
	/* 0x2407: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_240c:
	/* 0x240c: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_240e:
	/* 0x240e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2411:
	/* 0x2411: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_2417:
	/* 0x2417: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_241a:
	/* 0x241a: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2420:
	/* 0x2420: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_2426:
	/* 0x2426: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_242b:
	/* 0x242b: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_242f:
	/* 0x242f: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2436:
	/* 0x2436: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_243b:
	/* 0x243b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2440:
	/* 0x2440: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2447:
	/* 0x2447: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_244a:
	/* 0x244a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2451:
	/* 0x2451: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2456:
	/* 0x2456: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_245b:
	/* 0x245b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_245d:
	/* 0x245d: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2461:
	/* 0x2461: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_2463:
	/* 0x2463: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2465:
	/* 0x2465: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_246b:
	/* 0x246b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_246e:
	/* 0x246e: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2474:
	/* 0x2474: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_247a:
	/* 0x247a: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_247f:
	/* 0x247f: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2483:
	/* 0x2483: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_248a:
	/* 0x248a: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_248f:
	/* 0x248f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2494:
	/* 0x2494: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2499:
	/* 0x2499: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_24a1:
	/* 0x24a1: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_24a5:
	/* 0x24a5: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_24ac:
	/* 0x24ac: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_24b1:
	/* 0x24b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b3:
	/* 0x24b3: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_24b8:
	/* 0x24b8: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_24c0:
	/* 0x24c0: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_24c3:
	/* 0x24c3: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_24cb:
	/* 0x24cb: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_24d4:
	/* 0x24d4: lea    rdx,[r13+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_24db:
	/* 0x24db: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24e0:
	/* 0x24e0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_24e5:
	/* 0x24e5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24ea:
	/* 0x24ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24ef:
	/* 0x24ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24f1:
	/* 0x24f1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24f6:
	/* 0x24f6: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_24f8:
	/* 0x24f8: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_24fb:
	/* 0x24fb: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_2501:
	/* 0x2501: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2504:
	/* 0x2504: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_250a:
	/* 0x250a: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_2510:
	/* 0x2510: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2515:
	/* 0x2515: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2519:
	/* 0x2519: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2520:
	/* 0x2520: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2525:
	/* 0x2525: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_252a:
	/* 0x252a: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2531:
	/* 0x2531: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2534:
	/* 0x2534: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_253b:
	/* 0x253b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2540:
	/* 0x2540: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2545:
	/* 0x2545: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2547:
	/* 0x2547: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_254b:
	/* 0x254b: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_254d:
	/* 0x254d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_254f:
	/* 0x254f: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_2555:
	/* 0x2555: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2558:
	/* 0x2558: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_255e:
	/* 0x255e: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_2564:
	/* 0x2564: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2569:
	/* 0x2569: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_256d:
	/* 0x256d: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2574:
	/* 0x2574: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2579:
	/* 0x2579: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_257e:
	/* 0x257e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2583:
	/* 0x2583: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_258b:
	/* 0x258b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_258f:
	/* 0x258f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2596:
	/* 0x2596: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_259b:
	/* 0x259b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_259d:
	/* 0x259d: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_25a2:
	/* 0x25a2: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_25aa:
	/* 0x25aa: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_25ad:
	/* 0x25ad: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_25b5:
	/* 0x25b5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_25be:
	/* 0x25be: lea    rdx,[r13+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_25c5:
	/* 0x25c5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25ca:
	/* 0x25ca: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_25cf:
	/* 0x25cf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25d4:
	/* 0x25d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25d9:
	/* 0x25d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25db:
	/* 0x25db: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25e0:
	/* 0x25e0: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_25e2:
	/* 0x25e2: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_25e5:
	/* 0x25e5: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_25eb:
	/* 0x25eb: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_25ee:
	/* 0x25ee: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_25f4:
	/* 0x25f4: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_25fa:
	/* 0x25fa: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25ff:
	/* 0x25ff: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2603:
	/* 0x2603: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_260a:
	/* 0x260a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_260f:
	/* 0x260f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2614:
	/* 0x2614: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_261b:
	/* 0x261b: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_261e:
	/* 0x261e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2625:
	/* 0x2625: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_262a:
	/* 0x262a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_262f:
	/* 0x262f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2631:
	/* 0x2631: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2635:
	/* 0x2635: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_2637:
	/* 0x2637: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2639:
	/* 0x2639: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_263f:
	/* 0x263f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2642:
	/* 0x2642: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2648:
	/* 0x2648: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_264e:
	/* 0x264e: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2653:
	/* 0x2653: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2657:
	/* 0x2657: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_265e:
	/* 0x265e: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2663:
	/* 0x2663: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2668:
	/* 0x2668: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_266d:
	/* 0x266d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2675:
	/* 0x2675: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2679:
	/* 0x2679: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2680:
	/* 0x2680: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2685:
	/* 0x2685: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2687:
	/* 0x2687: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_268c:
	/* 0x268c: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2694:
	/* 0x2694: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2697:
	/* 0x2697: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_269f:
	/* 0x269f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_26a8:
	/* 0x26a8: lea    rdx,[r13+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_26af:
	/* 0x26af: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26b4:
	/* 0x26b4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_26b9:
	/* 0x26b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26be:
	/* 0x26be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26c3:
	/* 0x26c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26c5:
	/* 0x26c5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26ca:
	/* 0x26ca: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_26cc:
	/* 0x26cc: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_26cf:
	/* 0x26cf: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_26d5:
	/* 0x26d5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_26d8:
	/* 0x26d8: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_26de:
	/* 0x26de: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_26e4:
	/* 0x26e4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26e9:
	/* 0x26e9: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_26ed:
	/* 0x26ed: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_26f4:
	/* 0x26f4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_26f9:
	/* 0x26f9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_26fe:
	/* 0x26fe: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2705:
	/* 0x2705: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2708:
	/* 0x2708: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_270f:
	/* 0x270f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2714:
	/* 0x2714: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2719:
	/* 0x2719: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_271b:
	/* 0x271b: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_271f:
	/* 0x271f: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_2721:
	/* 0x2721: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2723:
	/* 0x2723: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_2729:
	/* 0x2729: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_272c:
	/* 0x272c: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2732:
	/* 0x2732: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_2738:
	/* 0x2738: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_273d:
	/* 0x273d: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2741:
	/* 0x2741: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2748:
	/* 0x2748: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_274d:
	/* 0x274d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2752:
	/* 0x2752: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2757:
	/* 0x2757: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_275f:
	/* 0x275f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2763:
	/* 0x2763: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_276a:
	/* 0x276a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_276f:
	/* 0x276f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2771:
	/* 0x2771: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2776:
	/* 0x2776: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_277e:
	/* 0x277e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2781:
	/* 0x2781: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2789:
	/* 0x2789: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2792:
	/* 0x2792: lea    rdx,[r13+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2799:
	/* 0x2799: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_279e:
	/* 0x279e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_27a3:
	/* 0x27a3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27a8:
	/* 0x27a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27ad:
	/* 0x27ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27af:
	/* 0x27af: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27b4:
	/* 0x27b4: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_27b6:
	/* 0x27b6: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_27b9:
	/* 0x27b9: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_27bf:
	/* 0x27bf: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_27c2:
	/* 0x27c2: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_27c8:
	/* 0x27c8: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_27ce:
	/* 0x27ce: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27d3:
	/* 0x27d3: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_27d7:
	/* 0x27d7: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_27de:
	/* 0x27de: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_27e3:
	/* 0x27e3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_27e8:
	/* 0x27e8: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_27ef:
	/* 0x27ef: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_27f2:
	/* 0x27f2: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_27f9:
	/* 0x27f9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27fe:
	/* 0x27fe: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2803:
	/* 0x2803: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2805:
	/* 0x2805: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2809:
	/* 0x2809: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_280b:
	/* 0x280b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_280d:
	/* 0x280d: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_2813:
	/* 0x2813: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2816:
	/* 0x2816: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_281c:
	/* 0x281c: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_2822:
	/* 0x2822: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2827:
	/* 0x2827: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_282b:
	/* 0x282b: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2832:
	/* 0x2832: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2837:
	/* 0x2837: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_283c:
	/* 0x283c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2841:
	/* 0x2841: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2849:
	/* 0x2849: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_284d:
	/* 0x284d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2854:
	/* 0x2854: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2859:
	/* 0x2859: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_285b:
	/* 0x285b: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2860:
	/* 0x2860: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2868:
	/* 0x2868: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_286b:
	/* 0x286b: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2873:
	/* 0x2873: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_287c:
	/* 0x287c: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2883:
	/* 0x2883: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2888:
	/* 0x2888: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_288d:
	/* 0x288d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2892:
	/* 0x2892: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2897:
	/* 0x2897: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2899:
	/* 0x2899: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_289e:
	/* 0x289e: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_28a0:
	/* 0x28a0: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_28a3:
	/* 0x28a3: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_28a9:
	/* 0x28a9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_28ac:
	/* 0x28ac: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_28b2:
	/* 0x28b2: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_28b8:
	/* 0x28b8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28bd:
	/* 0x28bd: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_28c1:
	/* 0x28c1: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_28c8:
	/* 0x28c8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_28cd:
	/* 0x28cd: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_28d2:
	/* 0x28d2: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_28d9:
	/* 0x28d9: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28dc:
	/* 0x28dc: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_28e3:
	/* 0x28e3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28e8:
	/* 0x28e8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_28ed:
	/* 0x28ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28ef:
	/* 0x28ef: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_28f3:
	/* 0x28f3: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_28f5:
	/* 0x28f5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28f7:
	/* 0x28f7: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_28fd:
	/* 0x28fd: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2900:
	/* 0x2900: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2906:
	/* 0x2906: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_290c:
	/* 0x290c: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2911:
	/* 0x2911: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2915:
	/* 0x2915: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_291c:
	/* 0x291c: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2921:
	/* 0x2921: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2926:
	/* 0x2926: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_292b:
	/* 0x292b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2933:
	/* 0x2933: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2937:
	/* 0x2937: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_293e:
	/* 0x293e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2943:
	/* 0x2943: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2945:
	/* 0x2945: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_294a:
	/* 0x294a: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2952:
	/* 0x2952: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2955:
	/* 0x2955: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_295d:
	/* 0x295d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2966:
	/* 0x2966: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_296d:
	/* 0x296d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2972:
	/* 0x2972: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2977:
	/* 0x2977: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_297c:
	/* 0x297c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2981:
	/* 0x2981: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2983:
	/* 0x2983: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2988:
	/* 0x2988: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_298a:
	/* 0x298a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_298d:
	/* 0x298d: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_2993:
	/* 0x2993: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2996:
	/* 0x2996: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_299c:
	/* 0x299c: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_29a2:
	/* 0x29a2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29a7:
	/* 0x29a7: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_29ab:
	/* 0x29ab: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_29b2:
	/* 0x29b2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_29b7:
	/* 0x29b7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_29bc:
	/* 0x29bc: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_29c3:
	/* 0x29c3: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29c6:
	/* 0x29c6: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_29cd:
	/* 0x29cd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29d2:
	/* 0x29d2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_29d7:
	/* 0x29d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29d9:
	/* 0x29d9: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_29dd:
	/* 0x29dd: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_29df:
	/* 0x29df: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29e1:
	/* 0x29e1: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_29e7:
	/* 0x29e7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_29ea:
	/* 0x29ea: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_29f0:
	/* 0x29f0: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_29f6:
	/* 0x29f6: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29fb:
	/* 0x29fb: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_29ff:
	/* 0x29ff: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2a06:
	/* 0x2a06: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2a0b:
	/* 0x2a0b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
	return 10768ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10768ULL: goto x86_l_2a10;
	case 10773ULL: goto x86_l_2a15;
	case 10781ULL: goto x86_l_2a1d;
	case 10785ULL: goto x86_l_2a21;
	case 10792ULL: goto x86_l_2a28;
	case 10797ULL: goto x86_l_2a2d;
	case 10799ULL: goto x86_l_2a2f;
	case 10804ULL: goto x86_l_2a34;
	case 10812ULL: goto x86_l_2a3c;
	case 10815ULL: goto x86_l_2a3f;
	case 10823ULL: goto x86_l_2a47;
	case 10832ULL: goto x86_l_2a50;
	case 10839ULL: goto x86_l_2a57;
	case 10844ULL: goto x86_l_2a5c;
	case 10849ULL: goto x86_l_2a61;
	case 10854ULL: goto x86_l_2a66;
	case 10859ULL: goto x86_l_2a6b;
	case 10861ULL: goto x86_l_2a6d;
	case 10866ULL: goto x86_l_2a72;
	case 10868ULL: goto x86_l_2a74;
	case 10871ULL: goto x86_l_2a77;
	case 10877ULL: goto x86_l_2a7d;
	case 10880ULL: goto x86_l_2a80;
	case 10886ULL: goto x86_l_2a86;
	case 10892ULL: goto x86_l_2a8c;
	case 10897ULL: goto x86_l_2a91;
	case 10901ULL: goto x86_l_2a95;
	case 10908ULL: goto x86_l_2a9c;
	case 10913ULL: goto x86_l_2aa1;
	case 10918ULL: goto x86_l_2aa6;
	case 10925ULL: goto x86_l_2aad;
	case 10928ULL: goto x86_l_2ab0;
	case 10935ULL: goto x86_l_2ab7;
	case 10940ULL: goto x86_l_2abc;
	case 10945ULL: goto x86_l_2ac1;
	case 10947ULL: goto x86_l_2ac3;
	case 10951ULL: goto x86_l_2ac7;
	case 10953ULL: goto x86_l_2ac9;
	case 10955ULL: goto x86_l_2acb;
	case 10961ULL: goto x86_l_2ad1;
	case 10964ULL: goto x86_l_2ad4;
	case 10970ULL: goto x86_l_2ada;
	case 10976ULL: goto x86_l_2ae0;
	case 10981ULL: goto x86_l_2ae5;
	case 10985ULL: goto x86_l_2ae9;
	case 10992ULL: goto x86_l_2af0;
	case 10997ULL: goto x86_l_2af5;
	case 11002ULL: goto x86_l_2afa;
	case 11007ULL: goto x86_l_2aff;
	case 11015ULL: goto x86_l_2b07;
	case 11019ULL: goto x86_l_2b0b;
	case 11026ULL: goto x86_l_2b12;
	case 11031ULL: goto x86_l_2b17;
	case 11033ULL: goto x86_l_2b19;
	case 11038ULL: goto x86_l_2b1e;
	case 11046ULL: goto x86_l_2b26;
	case 11049ULL: goto x86_l_2b29;
	case 11057ULL: goto x86_l_2b31;
	case 11066ULL: goto x86_l_2b3a;
	case 11073ULL: goto x86_l_2b41;
	case 11078ULL: goto x86_l_2b46;
	case 11083ULL: goto x86_l_2b4b;
	case 11088ULL: goto x86_l_2b50;
	case 11093ULL: goto x86_l_2b55;
	case 11095ULL: goto x86_l_2b57;
	case 11100ULL: goto x86_l_2b5c;
	case 11102ULL: goto x86_l_2b5e;
	case 11105ULL: goto x86_l_2b61;
	case 11111ULL: goto x86_l_2b67;
	case 11114ULL: goto x86_l_2b6a;
	case 11120ULL: goto x86_l_2b70;
	case 11126ULL: goto x86_l_2b76;
	case 11131ULL: goto x86_l_2b7b;
	case 11135ULL: goto x86_l_2b7f;
	case 11142ULL: goto x86_l_2b86;
	case 11147ULL: goto x86_l_2b8b;
	case 11152ULL: goto x86_l_2b90;
	case 11159ULL: goto x86_l_2b97;
	case 11162ULL: goto x86_l_2b9a;
	case 11169ULL: goto x86_l_2ba1;
	case 11174ULL: goto x86_l_2ba6;
	case 11179ULL: goto x86_l_2bab;
	case 11181ULL: goto x86_l_2bad;
	case 11185ULL: goto x86_l_2bb1;
	case 11187ULL: goto x86_l_2bb3;
	case 11189ULL: goto x86_l_2bb5;
	case 11195ULL: goto x86_l_2bbb;
	case 11198ULL: goto x86_l_2bbe;
	case 11204ULL: goto x86_l_2bc4;
	case 11210ULL: goto x86_l_2bca;
	case 11215ULL: goto x86_l_2bcf;
	case 11219ULL: goto x86_l_2bd3;
	case 11226ULL: goto x86_l_2bda;
	case 11231ULL: goto x86_l_2bdf;
	case 11236ULL: goto x86_l_2be4;
	case 11241ULL: goto x86_l_2be9;
	case 11249ULL: goto x86_l_2bf1;
	case 11253ULL: goto x86_l_2bf5;
	case 11260ULL: goto x86_l_2bfc;
	case 11265ULL: goto x86_l_2c01;
	case 11267ULL: goto x86_l_2c03;
	case 11272ULL: goto x86_l_2c08;
	case 11280ULL: goto x86_l_2c10;
	case 11283ULL: goto x86_l_2c13;
	case 11291ULL: goto x86_l_2c1b;
	case 11300ULL: goto x86_l_2c24;
	case 11307ULL: goto x86_l_2c2b;
	case 11312ULL: goto x86_l_2c30;
	case 11317ULL: goto x86_l_2c35;
	case 11322ULL: goto x86_l_2c3a;
	case 11327ULL: goto x86_l_2c3f;
	case 11329ULL: goto x86_l_2c41;
	case 11334ULL: goto x86_l_2c46;
	case 11336ULL: goto x86_l_2c48;
	case 11339ULL: goto x86_l_2c4b;
	case 11345ULL: goto x86_l_2c51;
	case 11348ULL: goto x86_l_2c54;
	case 11354ULL: goto x86_l_2c5a;
	case 11360ULL: goto x86_l_2c60;
	case 11365ULL: goto x86_l_2c65;
	case 11369ULL: goto x86_l_2c69;
	case 11376ULL: goto x86_l_2c70;
	case 11381ULL: goto x86_l_2c75;
	case 11386ULL: goto x86_l_2c7a;
	case 11393ULL: goto x86_l_2c81;
	case 11396ULL: goto x86_l_2c84;
	case 11403ULL: goto x86_l_2c8b;
	case 11408ULL: goto x86_l_2c90;
	case 11413ULL: goto x86_l_2c95;
	case 11415ULL: goto x86_l_2c97;
	case 11419ULL: goto x86_l_2c9b;
	case 11421ULL: goto x86_l_2c9d;
	case 11423ULL: goto x86_l_2c9f;
	case 11429ULL: goto x86_l_2ca5;
	case 11432ULL: goto x86_l_2ca8;
	case 11438ULL: goto x86_l_2cae;
	case 11444ULL: goto x86_l_2cb4;
	case 11449ULL: goto x86_l_2cb9;
	case 11453ULL: goto x86_l_2cbd;
	case 11460ULL: goto x86_l_2cc4;
	case 11465ULL: goto x86_l_2cc9;
	case 11470ULL: goto x86_l_2cce;
	case 11475ULL: goto x86_l_2cd3;
	case 11483ULL: goto x86_l_2cdb;
	case 11487ULL: goto x86_l_2cdf;
	case 11494ULL: goto x86_l_2ce6;
	case 11499ULL: goto x86_l_2ceb;
	case 11501ULL: goto x86_l_2ced;
	case 11506ULL: goto x86_l_2cf2;
	case 11514ULL: goto x86_l_2cfa;
	case 11517ULL: goto x86_l_2cfd;
	case 11525ULL: goto x86_l_2d05;
	case 11534ULL: goto x86_l_2d0e;
	case 11541ULL: goto x86_l_2d15;
	case 11546ULL: goto x86_l_2d1a;
	case 11551ULL: goto x86_l_2d1f;
	case 11556ULL: goto x86_l_2d24;
	case 11561ULL: goto x86_l_2d29;
	case 11563ULL: goto x86_l_2d2b;
	case 11568ULL: goto x86_l_2d30;
	case 11570ULL: goto x86_l_2d32;
	case 11573ULL: goto x86_l_2d35;
	case 11579ULL: goto x86_l_2d3b;
	case 11582ULL: goto x86_l_2d3e;
	case 11588ULL: goto x86_l_2d44;
	case 11594ULL: goto x86_l_2d4a;
	case 11599ULL: goto x86_l_2d4f;
	case 11603ULL: goto x86_l_2d53;
	case 11610ULL: goto x86_l_2d5a;
	case 11615ULL: goto x86_l_2d5f;
	case 11620ULL: goto x86_l_2d64;
	case 11627ULL: goto x86_l_2d6b;
	case 11630ULL: goto x86_l_2d6e;
	case 11637ULL: goto x86_l_2d75;
	case 11642ULL: goto x86_l_2d7a;
	case 11647ULL: goto x86_l_2d7f;
	case 11649ULL: goto x86_l_2d81;
	case 11653ULL: goto x86_l_2d85;
	case 11655ULL: goto x86_l_2d87;
	case 11657ULL: goto x86_l_2d89;
	case 11663ULL: goto x86_l_2d8f;
	case 11666ULL: goto x86_l_2d92;
	case 11672ULL: goto x86_l_2d98;
	case 11678ULL: goto x86_l_2d9e;
	case 11683ULL: goto x86_l_2da3;
	case 11687ULL: goto x86_l_2da7;
	case 11694ULL: goto x86_l_2dae;
	case 11699ULL: goto x86_l_2db3;
	case 11704ULL: goto x86_l_2db8;
	case 11709ULL: goto x86_l_2dbd;
	case 11717ULL: goto x86_l_2dc5;
	case 11721ULL: goto x86_l_2dc9;
	case 11728ULL: goto x86_l_2dd0;
	case 11733ULL: goto x86_l_2dd5;
	case 11735ULL: goto x86_l_2dd7;
	case 11740ULL: goto x86_l_2ddc;
	case 11748ULL: goto x86_l_2de4;
	case 11751ULL: goto x86_l_2de7;
	case 11759ULL: goto x86_l_2def;
	case 11768ULL: goto x86_l_2df8;
	case 11775ULL: goto x86_l_2dff;
	case 11780ULL: goto x86_l_2e04;
	case 11785ULL: goto x86_l_2e09;
	case 11790ULL: goto x86_l_2e0e;
	case 11795ULL: goto x86_l_2e13;
	case 11797ULL: goto x86_l_2e15;
	case 11802ULL: goto x86_l_2e1a;
	case 11804ULL: goto x86_l_2e1c;
	case 11807ULL: goto x86_l_2e1f;
	case 11813ULL: goto x86_l_2e25;
	case 11816ULL: goto x86_l_2e28;
	case 11822ULL: goto x86_l_2e2e;
	case 11828ULL: goto x86_l_2e34;
	case 11833ULL: goto x86_l_2e39;
	case 11837ULL: goto x86_l_2e3d;
	case 11844ULL: goto x86_l_2e44;
	case 11849ULL: goto x86_l_2e49;
	case 11854ULL: goto x86_l_2e4e;
	case 11861ULL: goto x86_l_2e55;
	case 11864ULL: goto x86_l_2e58;
	case 11871ULL: goto x86_l_2e5f;
	case 11876ULL: goto x86_l_2e64;
	case 11881ULL: goto x86_l_2e69;
	case 11883ULL: goto x86_l_2e6b;
	case 11887ULL: goto x86_l_2e6f;
	case 11889ULL: goto x86_l_2e71;
	case 11891ULL: goto x86_l_2e73;
	case 11897ULL: goto x86_l_2e79;
	case 11900ULL: goto x86_l_2e7c;
	case 11906ULL: goto x86_l_2e82;
	case 11912ULL: goto x86_l_2e88;
	case 11917ULL: goto x86_l_2e8d;
	case 11921ULL: goto x86_l_2e91;
	case 11928ULL: goto x86_l_2e98;
	case 11933ULL: goto x86_l_2e9d;
	case 11938ULL: goto x86_l_2ea2;
	case 11943ULL: goto x86_l_2ea7;
	case 11951ULL: goto x86_l_2eaf;
	case 11955ULL: goto x86_l_2eb3;
	case 11962ULL: goto x86_l_2eba;
	case 11967ULL: goto x86_l_2ebf;
	case 11969ULL: goto x86_l_2ec1;
	case 11974ULL: goto x86_l_2ec6;
	case 11982ULL: goto x86_l_2ece;
	case 11985ULL: goto x86_l_2ed1;
	case 11993ULL: goto x86_l_2ed9;
	case 12002ULL: goto x86_l_2ee2;
	case 12009ULL: goto x86_l_2ee9;
	case 12014ULL: goto x86_l_2eee;
	case 12019ULL: goto x86_l_2ef3;
	case 12024ULL: goto x86_l_2ef8;
	case 12029ULL: goto x86_l_2efd;
	case 12031ULL: goto x86_l_2eff;
	case 12036ULL: goto x86_l_2f04;
	case 12038ULL: goto x86_l_2f06;
	case 12041ULL: goto x86_l_2f09;
	case 12047ULL: goto x86_l_2f0f;
	case 12050ULL: goto x86_l_2f12;
	case 12056ULL: goto x86_l_2f18;
	case 12062ULL: goto x86_l_2f1e;
	case 12067ULL: goto x86_l_2f23;
	case 12071ULL: goto x86_l_2f27;
	case 12078ULL: goto x86_l_2f2e;
	case 12083ULL: goto x86_l_2f33;
	case 12088ULL: goto x86_l_2f38;
	case 12095ULL: goto x86_l_2f3f;
	case 12098ULL: goto x86_l_2f42;
	case 12105ULL: goto x86_l_2f49;
	case 12110ULL: goto x86_l_2f4e;
	case 12115ULL: goto x86_l_2f53;
	case 12117ULL: goto x86_l_2f55;
	case 12121ULL: goto x86_l_2f59;
	case 12123ULL: goto x86_l_2f5b;
	case 12125ULL: goto x86_l_2f5d;
	case 12131ULL: goto x86_l_2f63;
	case 12134ULL: goto x86_l_2f66;
	case 12140ULL: goto x86_l_2f6c;
	case 12146ULL: goto x86_l_2f72;
	case 12151ULL: goto x86_l_2f77;
	case 12155ULL: goto x86_l_2f7b;
	case 12162ULL: goto x86_l_2f82;
	case 12167ULL: goto x86_l_2f87;
	case 12172ULL: goto x86_l_2f8c;
	case 12177ULL: goto x86_l_2f91;
	case 12185ULL: goto x86_l_2f99;
	case 12189ULL: goto x86_l_2f9d;
	case 12196ULL: goto x86_l_2fa4;
	case 12201ULL: goto x86_l_2fa9;
	case 12203ULL: goto x86_l_2fab;
	case 12208ULL: goto x86_l_2fb0;
	case 12216ULL: goto x86_l_2fb8;
	case 12219ULL: goto x86_l_2fbb;
	case 12227ULL: goto x86_l_2fc3;
	case 12236ULL: goto x86_l_2fcc;
	case 12243ULL: goto x86_l_2fd3;
	case 12248ULL: goto x86_l_2fd8;
	case 12253ULL: goto x86_l_2fdd;
	case 12258ULL: goto x86_l_2fe2;
	case 12263ULL: goto x86_l_2fe7;
	case 12265ULL: goto x86_l_2fe9;
	case 12270ULL: goto x86_l_2fee;
	case 12272ULL: goto x86_l_2ff0;
	case 12275ULL: goto x86_l_2ff3;
	case 12281ULL: goto x86_l_2ff9;
	case 12284ULL: goto x86_l_2ffc;
	case 12290ULL: goto x86_l_3002;
	case 12296ULL: goto x86_l_3008;
	case 12301ULL: goto x86_l_300d;
	case 12305ULL: goto x86_l_3011;
	case 12312ULL: goto x86_l_3018;
	case 12317ULL: goto x86_l_301d;
	case 12322ULL: goto x86_l_3022;
	case 12329ULL: goto x86_l_3029;
	case 12332ULL: goto x86_l_302c;
	case 12339ULL: goto x86_l_3033;
	case 12344ULL: goto x86_l_3038;
	case 12349ULL: goto x86_l_303d;
	case 12351ULL: goto x86_l_303f;
	case 12355ULL: goto x86_l_3043;
	case 12357ULL: goto x86_l_3045;
	case 12359ULL: goto x86_l_3047;
	case 12365ULL: goto x86_l_304d;
	case 12368ULL: goto x86_l_3050;
	case 12374ULL: goto x86_l_3056;
	case 12380ULL: goto x86_l_305c;
	case 12385ULL: goto x86_l_3061;
	case 12389ULL: goto x86_l_3065;
	case 12396ULL: goto x86_l_306c;
	case 12401ULL: goto x86_l_3071;
	case 12406ULL: goto x86_l_3076;
	case 12411ULL: goto x86_l_307b;
	case 12419ULL: goto x86_l_3083;
	case 12423ULL: goto x86_l_3087;
	case 12430ULL: goto x86_l_308e;
	case 12435ULL: goto x86_l_3093;
	case 12437ULL: goto x86_l_3095;
	case 12442ULL: goto x86_l_309a;
	case 12450ULL: goto x86_l_30a2;
	case 12453ULL: goto x86_l_30a5;
	case 12461ULL: goto x86_l_30ad;
	case 12470ULL: goto x86_l_30b6;
	case 12477ULL: goto x86_l_30bd;
	case 12482ULL: goto x86_l_30c2;
	case 12487ULL: goto x86_l_30c7;
	case 12492ULL: goto x86_l_30cc;
	case 12497ULL: goto x86_l_30d1;
	case 12499ULL: goto x86_l_30d3;
	case 12504ULL: goto x86_l_30d8;
	case 12506ULL: goto x86_l_30da;
	case 12509ULL: goto x86_l_30dd;
	case 12515ULL: goto x86_l_30e3;
	case 12518ULL: goto x86_l_30e6;
	case 12524ULL: goto x86_l_30ec;
	case 12530ULL: goto x86_l_30f2;
	case 12535ULL: goto x86_l_30f7;
	case 12539ULL: goto x86_l_30fb;
	case 12546ULL: goto x86_l_3102;
	case 12551ULL: goto x86_l_3107;
	case 12556ULL: goto x86_l_310c;
	case 12563ULL: goto x86_l_3113;
	case 12566ULL: goto x86_l_3116;
	case 12573ULL: goto x86_l_311d;
	case 12578ULL: goto x86_l_3122;
	case 12583ULL: goto x86_l_3127;
	case 12585ULL: goto x86_l_3129;
	case 12589ULL: goto x86_l_312d;
	case 12591ULL: goto x86_l_312f;
	case 12593ULL: goto x86_l_3131;
	case 12599ULL: goto x86_l_3137;
	case 12602ULL: goto x86_l_313a;
	case 12608ULL: goto x86_l_3140;
	case 12614ULL: goto x86_l_3146;
	case 12619ULL: goto x86_l_314b;
	case 12623ULL: goto x86_l_314f;
	case 12630ULL: goto x86_l_3156;
	case 12635ULL: goto x86_l_315b;
	case 12640ULL: goto x86_l_3160;
	case 12645ULL: goto x86_l_3165;
	case 12653ULL: goto x86_l_316d;
	case 12657ULL: goto x86_l_3171;
	case 12664ULL: goto x86_l_3178;
	case 12669ULL: goto x86_l_317d;
	case 12671ULL: goto x86_l_317f;
	case 12676ULL: goto x86_l_3184;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a10:
	/* 0x2a10: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a15:
	/* 0x2a15: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a1d:
	/* 0x2a1d: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2a21:
	/* 0x2a21: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2a28:
	/* 0x2a28: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a2d:
	/* 0x2a2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a2f:
	/* 0x2a2f: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2a34:
	/* 0x2a34: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2a3c:
	/* 0x2a3c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2a3f:
	/* 0x2a3f: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2a47:
	/* 0x2a47: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2a50:
	/* 0x2a50: lea    rdx,[r13+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2a57:
	/* 0x2a57: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a5c:
	/* 0x2a5c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a61:
	/* 0x2a61: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a66:
	/* 0x2a66: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a6b:
	/* 0x2a6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a6d:
	/* 0x2a6d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a72:
	/* 0x2a72: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_2a74:
	/* 0x2a74: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2a77:
	/* 0x2a77: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_2a7d:
	/* 0x2a7d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a80:
	/* 0x2a80: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2a86:
	/* 0x2a86: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_2a8c:
	/* 0x2a8c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a91:
	/* 0x2a91: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2a95:
	/* 0x2a95: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2a9c:
	/* 0x2a9c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2aa1:
	/* 0x2aa1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2aa6:
	/* 0x2aa6: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2aad:
	/* 0x2aad: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ab0:
	/* 0x2ab0: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2ab7:
	/* 0x2ab7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2abc:
	/* 0x2abc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2ac1:
	/* 0x2ac1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ac3:
	/* 0x2ac3: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2ac7:
	/* 0x2ac7: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_2ac9:
	/* 0x2ac9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2acb:
	/* 0x2acb: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_2ad1:
	/* 0x2ad1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ad4:
	/* 0x2ad4: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2ada:
	/* 0x2ada: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_2ae0:
	/* 0x2ae0: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ae5:
	/* 0x2ae5: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2ae9:
	/* 0x2ae9: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2af0:
	/* 0x2af0: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2af5:
	/* 0x2af5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2afa:
	/* 0x2afa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2aff:
	/* 0x2aff: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2b07:
	/* 0x2b07: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2b0b:
	/* 0x2b0b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2b12:
	/* 0x2b12: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b17:
	/* 0x2b17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b19:
	/* 0x2b19: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2b1e:
	/* 0x2b1e: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2b26:
	/* 0x2b26: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2b29:
	/* 0x2b29: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2b31:
	/* 0x2b31: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2b3a:
	/* 0x2b3a: lea    rdx,[r13+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2b41:
	/* 0x2b41: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b46:
	/* 0x2b46: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b4b:
	/* 0x2b4b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b50:
	/* 0x2b50: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b55:
	/* 0x2b55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b57:
	/* 0x2b57: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b5c:
	/* 0x2b5c: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_2b5e:
	/* 0x2b5e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2b61:
	/* 0x2b61: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_2b67:
	/* 0x2b67: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b6a:
	/* 0x2b6a: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2b70:
	/* 0x2b70: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_2b76:
	/* 0x2b76: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b7b:
	/* 0x2b7b: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2b7f:
	/* 0x2b7f: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2b86:
	/* 0x2b86: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2b8b:
	/* 0x2b8b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2b90:
	/* 0x2b90: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2b97:
	/* 0x2b97: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b9a:
	/* 0x2b9a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2ba1:
	/* 0x2ba1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ba6:
	/* 0x2ba6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2bab:
	/* 0x2bab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bad:
	/* 0x2bad: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2bb1:
	/* 0x2bb1: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_2bb3:
	/* 0x2bb3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bb5:
	/* 0x2bb5: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_2bbb:
	/* 0x2bbb: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2bbe:
	/* 0x2bbe: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2bc4:
	/* 0x2bc4: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_2bca:
	/* 0x2bca: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bcf:
	/* 0x2bcf: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2bd3:
	/* 0x2bd3: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2bda:
	/* 0x2bda: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2bdf:
	/* 0x2bdf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2be4:
	/* 0x2be4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2be9:
	/* 0x2be9: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2bf1:
	/* 0x2bf1: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2bf5:
	/* 0x2bf5: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2bfc:
	/* 0x2bfc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c01:
	/* 0x2c01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c03:
	/* 0x2c03: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2c08:
	/* 0x2c08: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2c10:
	/* 0x2c10: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2c13:
	/* 0x2c13: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2c1b:
	/* 0x2c1b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2c24:
	/* 0x2c24: lea    rdx,[r13+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2c2b:
	/* 0x2c2b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c30:
	/* 0x2c30: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c35:
	/* 0x2c35: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c3a:
	/* 0x2c3a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c3f:
	/* 0x2c3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c41:
	/* 0x2c41: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c46:
	/* 0x2c46: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_2c48:
	/* 0x2c48: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2c4b:
	/* 0x2c4b: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_2c51:
	/* 0x2c51: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c54:
	/* 0x2c54: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2c5a:
	/* 0x2c5a: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_2c60:
	/* 0x2c60: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c65:
	/* 0x2c65: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2c69:
	/* 0x2c69: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2c70:
	/* 0x2c70: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2c75:
	/* 0x2c75: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2c7a:
	/* 0x2c7a: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2c81:
	/* 0x2c81: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c84:
	/* 0x2c84: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2c8b:
	/* 0x2c8b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c90:
	/* 0x2c90: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2c95:
	/* 0x2c95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c97:
	/* 0x2c97: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c9b:
	/* 0x2c9b: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_2c9d:
	/* 0x2c9d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c9f:
	/* 0x2c9f: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_2ca5:
	/* 0x2ca5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ca8:
	/* 0x2ca8: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2cae:
	/* 0x2cae: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_2cb4:
	/* 0x2cb4: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cb9:
	/* 0x2cb9: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2cbd:
	/* 0x2cbd: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2cc4:
	/* 0x2cc4: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2cc9:
	/* 0x2cc9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2cce:
	/* 0x2cce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cd3:
	/* 0x2cd3: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2cdb:
	/* 0x2cdb: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2cdf:
	/* 0x2cdf: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2ce6:
	/* 0x2ce6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ceb:
	/* 0x2ceb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ced:
	/* 0x2ced: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2cf2:
	/* 0x2cf2: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2cfa:
	/* 0x2cfa: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2cfd:
	/* 0x2cfd: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2d05:
	/* 0x2d05: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2d0e:
	/* 0x2d0e: lea    rdx,[r13+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2d15:
	/* 0x2d15: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d1a:
	/* 0x2d1a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d1f:
	/* 0x2d1f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d24:
	/* 0x2d24: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d29:
	/* 0x2d29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d2b:
	/* 0x2d2b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d30:
	/* 0x2d30: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_2d32:
	/* 0x2d32: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2d35:
	/* 0x2d35: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_2d3b:
	/* 0x2d3b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d3e:
	/* 0x2d3e: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2d44:
	/* 0x2d44: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_2d4a:
	/* 0x2d4a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d4f:
	/* 0x2d4f: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2d53:
	/* 0x2d53: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2d5a:
	/* 0x2d5a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2d5f:
	/* 0x2d5f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2d64:
	/* 0x2d64: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2d6b:
	/* 0x2d6b: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d6e:
	/* 0x2d6e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2d75:
	/* 0x2d75: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d7a:
	/* 0x2d7a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2d7f:
	/* 0x2d7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d81:
	/* 0x2d81: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2d85:
	/* 0x2d85: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_2d87:
	/* 0x2d87: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d89:
	/* 0x2d89: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_2d8f:
	/* 0x2d8f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d92:
	/* 0x2d92: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2d98:
	/* 0x2d98: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_2d9e:
	/* 0x2d9e: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2da3:
	/* 0x2da3: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2da7:
	/* 0x2da7: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2dae:
	/* 0x2dae: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2db3:
	/* 0x2db3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2db8:
	/* 0x2db8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2dbd:
	/* 0x2dbd: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2dc5:
	/* 0x2dc5: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2dc9:
	/* 0x2dc9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2dd0:
	/* 0x2dd0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2dd5:
	/* 0x2dd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dd7:
	/* 0x2dd7: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2ddc:
	/* 0x2ddc: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2de4:
	/* 0x2de4: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2de7:
	/* 0x2de7: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2def:
	/* 0x2def: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2df8:
	/* 0x2df8: lea    rdx,[r13+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2dff:
	/* 0x2dff: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e04:
	/* 0x2e04: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2e09:
	/* 0x2e09: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e0e:
	/* 0x2e0e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e13:
	/* 0x2e13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e15:
	/* 0x2e15: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e1a:
	/* 0x2e1a: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_2e1c:
	/* 0x2e1c: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2e1f:
	/* 0x2e1f: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_2e25:
	/* 0x2e25: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e28:
	/* 0x2e28: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2e2e:
	/* 0x2e2e: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_2e34:
	/* 0x2e34: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e39:
	/* 0x2e39: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2e3d:
	/* 0x2e3d: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2e44:
	/* 0x2e44: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2e49:
	/* 0x2e49: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2e4e:
	/* 0x2e4e: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2e55:
	/* 0x2e55: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e58:
	/* 0x2e58: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2e5f:
	/* 0x2e5f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e64:
	/* 0x2e64: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2e69:
	/* 0x2e69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e6b:
	/* 0x2e6b: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2e6f:
	/* 0x2e6f: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_2e71:
	/* 0x2e71: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e73:
	/* 0x2e73: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_2e79:
	/* 0x2e79: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e7c:
	/* 0x2e7c: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2e82:
	/* 0x2e82: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_2e88:
	/* 0x2e88: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e8d:
	/* 0x2e8d: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2e91:
	/* 0x2e91: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2e98:
	/* 0x2e98: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2e9d:
	/* 0x2e9d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ea2:
	/* 0x2ea2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ea7:
	/* 0x2ea7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2eaf:
	/* 0x2eaf: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2eb3:
	/* 0x2eb3: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2eba:
	/* 0x2eba: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ebf:
	/* 0x2ebf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ec1:
	/* 0x2ec1: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2ec6:
	/* 0x2ec6: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2ece:
	/* 0x2ece: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2ed1:
	/* 0x2ed1: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2ed9:
	/* 0x2ed9: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2ee2:
	/* 0x2ee2: lea    rdx,[r13+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2ee9:
	/* 0x2ee9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eee:
	/* 0x2eee: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ef3:
	/* 0x2ef3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ef8:
	/* 0x2ef8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2efd:
	/* 0x2efd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eff:
	/* 0x2eff: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f04:
	/* 0x2f04: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_2f06:
	/* 0x2f06: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2f09:
	/* 0x2f09: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_2f0f:
	/* 0x2f0f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f12:
	/* 0x2f12: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_2f18:
	/* 0x2f18: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_2f1e:
	/* 0x2f1e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f23:
	/* 0x2f23: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2f27:
	/* 0x2f27: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2f2e:
	/* 0x2f2e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2f33:
	/* 0x2f33: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2f38:
	/* 0x2f38: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2f3f:
	/* 0x2f3f: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f42:
	/* 0x2f42: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2f49:
	/* 0x2f49: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f4e:
	/* 0x2f4e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2f53:
	/* 0x2f53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f55:
	/* 0x2f55: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2f59:
	/* 0x2f59: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_2f5b:
	/* 0x2f5b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f5d:
	/* 0x2f5d: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_2f63:
	/* 0x2f63: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f66:
	/* 0x2f66: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_2f6c:
	/* 0x2f6c: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_2f72:
	/* 0x2f72: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f77:
	/* 0x2f77: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2f7b:
	/* 0x2f7b: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2f82:
	/* 0x2f82: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2f87:
	/* 0x2f87: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2f8c:
	/* 0x2f8c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f91:
	/* 0x2f91: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2f99:
	/* 0x2f99: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2f9d:
	/* 0x2f9d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2fa4:
	/* 0x2fa4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2fa9:
	/* 0x2fa9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fab:
	/* 0x2fab: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2fb0:
	/* 0x2fb0: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2fb8:
	/* 0x2fb8: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2fbb:
	/* 0x2fbb: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2fc3:
	/* 0x2fc3: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2fcc:
	/* 0x2fcc: lea    rdx,[r13+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_2fd3:
	/* 0x2fd3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fd8:
	/* 0x2fd8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2fdd:
	/* 0x2fdd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2fe2:
	/* 0x2fe2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fe7:
	/* 0x2fe7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fe9:
	/* 0x2fe9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fee:
	/* 0x2fee: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_2ff0:
	/* 0x2ff0: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_2ff3:
	/* 0x2ff3: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_2ff9:
	/* 0x2ff9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ffc:
	/* 0x2ffc: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3002:
	/* 0x3002: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_3008:
	/* 0x3008: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_300d:
	/* 0x300d: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3011:
	/* 0x3011: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3018:
	/* 0x3018: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_301d:
	/* 0x301d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3022:
	/* 0x3022: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3029:
	/* 0x3029: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_302c:
	/* 0x302c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3033:
	/* 0x3033: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3038:
	/* 0x3038: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_303d:
	/* 0x303d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_303f:
	/* 0x303f: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3043:
	/* 0x3043: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_3045:
	/* 0x3045: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3047:
	/* 0x3047: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_304d:
	/* 0x304d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3050:
	/* 0x3050: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3056:
	/* 0x3056: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_305c:
	/* 0x305c: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3061:
	/* 0x3061: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3065:
	/* 0x3065: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_306c:
	/* 0x306c: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3071:
	/* 0x3071: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3076:
	/* 0x3076: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_307b:
	/* 0x307b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3083:
	/* 0x3083: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3087:
	/* 0x3087: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_308e:
	/* 0x308e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3093:
	/* 0x3093: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3095:
	/* 0x3095: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_309a:
	/* 0x309a: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_30a2:
	/* 0x30a2: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_30a5:
	/* 0x30a5: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_30ad:
	/* 0x30ad: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_30b6:
	/* 0x30b6: lea    rdx,[r13+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_30bd:
	/* 0x30bd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30c2:
	/* 0x30c2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_30c7:
	/* 0x30c7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30cc:
	/* 0x30cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30d1:
	/* 0x30d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30d3:
	/* 0x30d3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30d8:
	/* 0x30d8: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_30da:
	/* 0x30da: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_30dd:
	/* 0x30dd: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_30e3:
	/* 0x30e3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_30e6:
	/* 0x30e6: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_30ec:
	/* 0x30ec: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_30f2:
	/* 0x30f2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30f7:
	/* 0x30f7: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_30fb:
	/* 0x30fb: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3102:
	/* 0x3102: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3107:
	/* 0x3107: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_310c:
	/* 0x310c: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3113:
	/* 0x3113: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3116:
	/* 0x3116: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_311d:
	/* 0x311d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3122:
	/* 0x3122: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3127:
	/* 0x3127: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3129:
	/* 0x3129: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_312d:
	/* 0x312d: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_312f:
	/* 0x312f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3131:
	/* 0x3131: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_3137:
	/* 0x3137: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_313a:
	/* 0x313a: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3140:
	/* 0x3140: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_3146:
	/* 0x3146: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_314b:
	/* 0x314b: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_314f:
	/* 0x314f: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3156:
	/* 0x3156: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_315b:
	/* 0x315b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3160:
	/* 0x3160: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3165:
	/* 0x3165: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_316d:
	/* 0x316d: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3171:
	/* 0x3171: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3178:
	/* 0x3178: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_317d:
	/* 0x317d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_317f:
	/* 0x317f: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3184:
	/* 0x3184: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
	return 12684ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12684ULL: goto x86_l_318c;
	case 12687ULL: goto x86_l_318f;
	case 12695ULL: goto x86_l_3197;
	case 12704ULL: goto x86_l_31a0;
	case 12711ULL: goto x86_l_31a7;
	case 12716ULL: goto x86_l_31ac;
	case 12721ULL: goto x86_l_31b1;
	case 12726ULL: goto x86_l_31b6;
	case 12731ULL: goto x86_l_31bb;
	case 12733ULL: goto x86_l_31bd;
	case 12738ULL: goto x86_l_31c2;
	case 12740ULL: goto x86_l_31c4;
	case 12743ULL: goto x86_l_31c7;
	case 12749ULL: goto x86_l_31cd;
	case 12752ULL: goto x86_l_31d0;
	case 12758ULL: goto x86_l_31d6;
	case 12764ULL: goto x86_l_31dc;
	case 12769ULL: goto x86_l_31e1;
	case 12773ULL: goto x86_l_31e5;
	case 12780ULL: goto x86_l_31ec;
	case 12785ULL: goto x86_l_31f1;
	case 12790ULL: goto x86_l_31f6;
	case 12797ULL: goto x86_l_31fd;
	case 12800ULL: goto x86_l_3200;
	case 12807ULL: goto x86_l_3207;
	case 12812ULL: goto x86_l_320c;
	case 12817ULL: goto x86_l_3211;
	case 12819ULL: goto x86_l_3213;
	case 12823ULL: goto x86_l_3217;
	case 12825ULL: goto x86_l_3219;
	case 12827ULL: goto x86_l_321b;
	case 12833ULL: goto x86_l_3221;
	case 12836ULL: goto x86_l_3224;
	case 12842ULL: goto x86_l_322a;
	case 12848ULL: goto x86_l_3230;
	case 12853ULL: goto x86_l_3235;
	case 12857ULL: goto x86_l_3239;
	case 12864ULL: goto x86_l_3240;
	case 12869ULL: goto x86_l_3245;
	case 12874ULL: goto x86_l_324a;
	case 12879ULL: goto x86_l_324f;
	case 12887ULL: goto x86_l_3257;
	case 12891ULL: goto x86_l_325b;
	case 12898ULL: goto x86_l_3262;
	case 12903ULL: goto x86_l_3267;
	case 12905ULL: goto x86_l_3269;
	case 12910ULL: goto x86_l_326e;
	case 12918ULL: goto x86_l_3276;
	case 12921ULL: goto x86_l_3279;
	case 12929ULL: goto x86_l_3281;
	case 12938ULL: goto x86_l_328a;
	case 12945ULL: goto x86_l_3291;
	case 12950ULL: goto x86_l_3296;
	case 12955ULL: goto x86_l_329b;
	case 12960ULL: goto x86_l_32a0;
	case 12965ULL: goto x86_l_32a5;
	case 12967ULL: goto x86_l_32a7;
	case 12972ULL: goto x86_l_32ac;
	case 12974ULL: goto x86_l_32ae;
	case 12977ULL: goto x86_l_32b1;
	case 12983ULL: goto x86_l_32b7;
	case 12986ULL: goto x86_l_32ba;
	case 12992ULL: goto x86_l_32c0;
	case 12998ULL: goto x86_l_32c6;
	case 13003ULL: goto x86_l_32cb;
	case 13007ULL: goto x86_l_32cf;
	case 13014ULL: goto x86_l_32d6;
	case 13019ULL: goto x86_l_32db;
	case 13024ULL: goto x86_l_32e0;
	case 13031ULL: goto x86_l_32e7;
	case 13034ULL: goto x86_l_32ea;
	case 13041ULL: goto x86_l_32f1;
	case 13046ULL: goto x86_l_32f6;
	case 13051ULL: goto x86_l_32fb;
	case 13053ULL: goto x86_l_32fd;
	case 13057ULL: goto x86_l_3301;
	case 13059ULL: goto x86_l_3303;
	case 13061ULL: goto x86_l_3305;
	case 13067ULL: goto x86_l_330b;
	case 13070ULL: goto x86_l_330e;
	case 13076ULL: goto x86_l_3314;
	case 13082ULL: goto x86_l_331a;
	case 13087ULL: goto x86_l_331f;
	case 13091ULL: goto x86_l_3323;
	case 13098ULL: goto x86_l_332a;
	case 13103ULL: goto x86_l_332f;
	case 13108ULL: goto x86_l_3334;
	case 13113ULL: goto x86_l_3339;
	case 13121ULL: goto x86_l_3341;
	case 13125ULL: goto x86_l_3345;
	case 13132ULL: goto x86_l_334c;
	case 13137ULL: goto x86_l_3351;
	case 13139ULL: goto x86_l_3353;
	case 13144ULL: goto x86_l_3358;
	case 13152ULL: goto x86_l_3360;
	case 13155ULL: goto x86_l_3363;
	case 13163ULL: goto x86_l_336b;
	case 13172ULL: goto x86_l_3374;
	case 13179ULL: goto x86_l_337b;
	case 13184ULL: goto x86_l_3380;
	case 13189ULL: goto x86_l_3385;
	case 13194ULL: goto x86_l_338a;
	case 13199ULL: goto x86_l_338f;
	case 13202ULL: goto x86_l_3392;
	case 13204ULL: goto x86_l_3394;
	case 13209ULL: goto x86_l_3399;
	case 13211ULL: goto x86_l_339b;
	case 13214ULL: goto x86_l_339e;
	case 13220ULL: goto x86_l_33a4;
	case 13223ULL: goto x86_l_33a7;
	case 13229ULL: goto x86_l_33ad;
	case 13235ULL: goto x86_l_33b3;
	case 13240ULL: goto x86_l_33b8;
	case 13244ULL: goto x86_l_33bc;
	case 13251ULL: goto x86_l_33c3;
	case 13256ULL: goto x86_l_33c8;
	case 13261ULL: goto x86_l_33cd;
	case 13268ULL: goto x86_l_33d4;
	case 13271ULL: goto x86_l_33d7;
	case 13278ULL: goto x86_l_33de;
	case 13283ULL: goto x86_l_33e3;
	case 13288ULL: goto x86_l_33e8;
	case 13290ULL: goto x86_l_33ea;
	case 13294ULL: goto x86_l_33ee;
	case 13296ULL: goto x86_l_33f0;
	case 13298ULL: goto x86_l_33f2;
	case 13304ULL: goto x86_l_33f8;
	case 13307ULL: goto x86_l_33fb;
	case 13313ULL: goto x86_l_3401;
	case 13319ULL: goto x86_l_3407;
	case 13324ULL: goto x86_l_340c;
	case 13328ULL: goto x86_l_3410;
	case 13335ULL: goto x86_l_3417;
	case 13340ULL: goto x86_l_341c;
	case 13345ULL: goto x86_l_3421;
	case 13350ULL: goto x86_l_3426;
	case 13358ULL: goto x86_l_342e;
	case 13362ULL: goto x86_l_3432;
	case 13369ULL: goto x86_l_3439;
	case 13374ULL: goto x86_l_343e;
	case 13376ULL: goto x86_l_3440;
	case 13381ULL: goto x86_l_3445;
	case 13389ULL: goto x86_l_344d;
	case 13392ULL: goto x86_l_3450;
	case 13400ULL: goto x86_l_3458;
	case 13408ULL: goto x86_l_3460;
	case 13411ULL: goto x86_l_3463;
	case 13417ULL: goto x86_l_3469;
	case 13419ULL: goto x86_l_346b;
	case 13424ULL: goto x86_l_3470;
	case 13428ULL: goto x86_l_3474;
	case 13431ULL: goto x86_l_3477;
	case 13436ULL: goto x86_l_347c;
	case 13440ULL: goto x86_l_3480;
	case 13447ULL: goto x86_l_3487;
	case 13452ULL: goto x86_l_348c;
	case 13457ULL: goto x86_l_3491;
	case 13462ULL: goto x86_l_3496;
	case 13469ULL: goto x86_l_349d;
	case 13472ULL: goto x86_l_34a0;
	case 13479ULL: goto x86_l_34a7;
	case 13484ULL: goto x86_l_34ac;
	case 13486ULL: goto x86_l_34ae;
	case 13490ULL: goto x86_l_34b2;
	case 13492ULL: goto x86_l_34b4;
	case 13494ULL: goto x86_l_34b6;
	case 13500ULL: goto x86_l_34bc;
	case 13503ULL: goto x86_l_34bf;
	case 13509ULL: goto x86_l_34c5;
	case 13514ULL: goto x86_l_34ca;
	case 13520ULL: goto x86_l_34d0;
	case 13525ULL: goto x86_l_34d5;
	case 13529ULL: goto x86_l_34d9;
	case 13536ULL: goto x86_l_34e0;
	case 13541ULL: goto x86_l_34e5;
	case 13546ULL: goto x86_l_34ea;
	case 13551ULL: goto x86_l_34ef;
	case 13559ULL: goto x86_l_34f7;
	case 13563ULL: goto x86_l_34fb;
	case 13570ULL: goto x86_l_3502;
	case 13575ULL: goto x86_l_3507;
	case 13577ULL: goto x86_l_3509;
	case 13582ULL: goto x86_l_350e;
	case 13590ULL: goto x86_l_3516;
	case 13593ULL: goto x86_l_3519;
	case 13601ULL: goto x86_l_3521;
	case 13603ULL: goto x86_l_3523;
	case 13608ULL: goto x86_l_3528;
	case 13612ULL: goto x86_l_352c;
	case 13619ULL: goto x86_l_3533;
	case 13624ULL: goto x86_l_3538;
	case 13629ULL: goto x86_l_353d;
	case 13634ULL: goto x86_l_3542;
	case 13641ULL: goto x86_l_3549;
	case 13645ULL: goto x86_l_354d;
	case 13652ULL: goto x86_l_3554;
	case 13657ULL: goto x86_l_3559;
	case 13659ULL: goto x86_l_355b;
	case 13664ULL: goto x86_l_3560;
	case 13671ULL: goto x86_l_3567;
	case 13674ULL: goto x86_l_356a;
	case 13681ULL: goto x86_l_3571;
	case 13690ULL: goto x86_l_357a;
	case 13694ULL: goto x86_l_357e;
	case 13699ULL: goto x86_l_3583;
	case 13704ULL: goto x86_l_3588;
	case 13709ULL: goto x86_l_358d;
	case 13714ULL: goto x86_l_3592;
	case 13716ULL: goto x86_l_3594;
	case 13721ULL: goto x86_l_3599;
	case 13723ULL: goto x86_l_359b;
	case 13726ULL: goto x86_l_359e;
	case 13732ULL: goto x86_l_35a4;
	case 13735ULL: goto x86_l_35a7;
	case 13741ULL: goto x86_l_35ad;
	case 13747ULL: goto x86_l_35b3;
	case 13752ULL: goto x86_l_35b8;
	case 13756ULL: goto x86_l_35bc;
	case 13763ULL: goto x86_l_35c3;
	case 13768ULL: goto x86_l_35c8;
	case 13773ULL: goto x86_l_35cd;
	case 13780ULL: goto x86_l_35d4;
	case 13783ULL: goto x86_l_35d7;
	case 13790ULL: goto x86_l_35de;
	case 13795ULL: goto x86_l_35e3;
	case 13800ULL: goto x86_l_35e8;
	case 13802ULL: goto x86_l_35ea;
	case 13806ULL: goto x86_l_35ee;
	case 13808ULL: goto x86_l_35f0;
	case 13810ULL: goto x86_l_35f2;
	case 13816ULL: goto x86_l_35f8;
	case 13819ULL: goto x86_l_35fb;
	case 13825ULL: goto x86_l_3601;
	case 13831ULL: goto x86_l_3607;
	case 13836ULL: goto x86_l_360c;
	case 13840ULL: goto x86_l_3610;
	case 13847ULL: goto x86_l_3617;
	case 13852ULL: goto x86_l_361c;
	case 13857ULL: goto x86_l_3621;
	case 13862ULL: goto x86_l_3626;
	case 13870ULL: goto x86_l_362e;
	case 13874ULL: goto x86_l_3632;
	case 13881ULL: goto x86_l_3639;
	case 13886ULL: goto x86_l_363e;
	case 13888ULL: goto x86_l_3640;
	case 13893ULL: goto x86_l_3645;
	case 13901ULL: goto x86_l_364d;
	case 13904ULL: goto x86_l_3650;
	case 13912ULL: goto x86_l_3658;
	case 13921ULL: goto x86_l_3661;
	case 13925ULL: goto x86_l_3665;
	case 13930ULL: goto x86_l_366a;
	case 13935ULL: goto x86_l_366f;
	case 13940ULL: goto x86_l_3674;
	case 13945ULL: goto x86_l_3679;
	case 13947ULL: goto x86_l_367b;
	case 13952ULL: goto x86_l_3680;
	case 13954ULL: goto x86_l_3682;
	case 13957ULL: goto x86_l_3685;
	case 13963ULL: goto x86_l_368b;
	case 13966ULL: goto x86_l_368e;
	case 13972ULL: goto x86_l_3694;
	case 13978ULL: goto x86_l_369a;
	case 13983ULL: goto x86_l_369f;
	case 13987ULL: goto x86_l_36a3;
	case 13994ULL: goto x86_l_36aa;
	case 13999ULL: goto x86_l_36af;
	case 14004ULL: goto x86_l_36b4;
	case 14011ULL: goto x86_l_36bb;
	case 14014ULL: goto x86_l_36be;
	case 14021ULL: goto x86_l_36c5;
	case 14026ULL: goto x86_l_36ca;
	case 14031ULL: goto x86_l_36cf;
	case 14033ULL: goto x86_l_36d1;
	case 14037ULL: goto x86_l_36d5;
	case 14039ULL: goto x86_l_36d7;
	case 14041ULL: goto x86_l_36d9;
	case 14047ULL: goto x86_l_36df;
	case 14050ULL: goto x86_l_36e2;
	case 14056ULL: goto x86_l_36e8;
	case 14062ULL: goto x86_l_36ee;
	case 14067ULL: goto x86_l_36f3;
	case 14071ULL: goto x86_l_36f7;
	case 14078ULL: goto x86_l_36fe;
	case 14083ULL: goto x86_l_3703;
	case 14088ULL: goto x86_l_3708;
	case 14093ULL: goto x86_l_370d;
	case 14101ULL: goto x86_l_3715;
	case 14105ULL: goto x86_l_3719;
	case 14112ULL: goto x86_l_3720;
	case 14117ULL: goto x86_l_3725;
	case 14119ULL: goto x86_l_3727;
	case 14124ULL: goto x86_l_372c;
	case 14132ULL: goto x86_l_3734;
	case 14135ULL: goto x86_l_3737;
	case 14143ULL: goto x86_l_373f;
	case 14152ULL: goto x86_l_3748;
	case 14156ULL: goto x86_l_374c;
	case 14161ULL: goto x86_l_3751;
	case 14166ULL: goto x86_l_3756;
	case 14171ULL: goto x86_l_375b;
	case 14176ULL: goto x86_l_3760;
	case 14178ULL: goto x86_l_3762;
	case 14183ULL: goto x86_l_3767;
	case 14185ULL: goto x86_l_3769;
	case 14188ULL: goto x86_l_376c;
	case 14194ULL: goto x86_l_3772;
	case 14197ULL: goto x86_l_3775;
	case 14203ULL: goto x86_l_377b;
	case 14209ULL: goto x86_l_3781;
	case 14214ULL: goto x86_l_3786;
	case 14218ULL: goto x86_l_378a;
	case 14225ULL: goto x86_l_3791;
	case 14230ULL: goto x86_l_3796;
	case 14235ULL: goto x86_l_379b;
	case 14242ULL: goto x86_l_37a2;
	case 14245ULL: goto x86_l_37a5;
	case 14252ULL: goto x86_l_37ac;
	case 14257ULL: goto x86_l_37b1;
	case 14262ULL: goto x86_l_37b6;
	case 14264ULL: goto x86_l_37b8;
	case 14268ULL: goto x86_l_37bc;
	case 14270ULL: goto x86_l_37be;
	case 14272ULL: goto x86_l_37c0;
	case 14278ULL: goto x86_l_37c6;
	case 14281ULL: goto x86_l_37c9;
	case 14287ULL: goto x86_l_37cf;
	case 14293ULL: goto x86_l_37d5;
	case 14298ULL: goto x86_l_37da;
	case 14302ULL: goto x86_l_37de;
	case 14309ULL: goto x86_l_37e5;
	case 14314ULL: goto x86_l_37ea;
	case 14319ULL: goto x86_l_37ef;
	case 14324ULL: goto x86_l_37f4;
	case 14332ULL: goto x86_l_37fc;
	case 14336ULL: goto x86_l_3800;
	case 14343ULL: goto x86_l_3807;
	case 14348ULL: goto x86_l_380c;
	case 14350ULL: goto x86_l_380e;
	case 14355ULL: goto x86_l_3813;
	case 14363ULL: goto x86_l_381b;
	case 14366ULL: goto x86_l_381e;
	case 14374ULL: goto x86_l_3826;
	case 14383ULL: goto x86_l_382f;
	case 14387ULL: goto x86_l_3833;
	case 14392ULL: goto x86_l_3838;
	case 14397ULL: goto x86_l_383d;
	case 14402ULL: goto x86_l_3842;
	case 14407ULL: goto x86_l_3847;
	case 14409ULL: goto x86_l_3849;
	case 14414ULL: goto x86_l_384e;
	case 14416ULL: goto x86_l_3850;
	case 14419ULL: goto x86_l_3853;
	case 14425ULL: goto x86_l_3859;
	case 14428ULL: goto x86_l_385c;
	case 14434ULL: goto x86_l_3862;
	case 14440ULL: goto x86_l_3868;
	case 14445ULL: goto x86_l_386d;
	case 14449ULL: goto x86_l_3871;
	case 14456ULL: goto x86_l_3878;
	case 14461ULL: goto x86_l_387d;
	case 14466ULL: goto x86_l_3882;
	case 14473ULL: goto x86_l_3889;
	case 14476ULL: goto x86_l_388c;
	case 14483ULL: goto x86_l_3893;
	case 14488ULL: goto x86_l_3898;
	case 14493ULL: goto x86_l_389d;
	case 14495ULL: goto x86_l_389f;
	case 14499ULL: goto x86_l_38a3;
	case 14501ULL: goto x86_l_38a5;
	case 14503ULL: goto x86_l_38a7;
	case 14509ULL: goto x86_l_38ad;
	case 14512ULL: goto x86_l_38b0;
	case 14518ULL: goto x86_l_38b6;
	case 14524ULL: goto x86_l_38bc;
	case 14529ULL: goto x86_l_38c1;
	case 14533ULL: goto x86_l_38c5;
	case 14540ULL: goto x86_l_38cc;
	case 14545ULL: goto x86_l_38d1;
	case 14550ULL: goto x86_l_38d6;
	case 14555ULL: goto x86_l_38db;
	case 14563ULL: goto x86_l_38e3;
	case 14567ULL: goto x86_l_38e7;
	case 14574ULL: goto x86_l_38ee;
	default: return 0xffffffffffffffffULL;
	}
x86_l_318c:
	/* 0x318c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_318f:
	/* 0x318f: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3197:
	/* 0x3197: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_31a0:
	/* 0x31a0: lea    rdx,[r13+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_31a7:
	/* 0x31a7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31ac:
	/* 0x31ac: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31b1:
	/* 0x31b1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31b6:
	/* 0x31b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31bb:
	/* 0x31bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31bd:
	/* 0x31bd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31c2:
	/* 0x31c2: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_31c4:
	/* 0x31c4: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_31c7:
	/* 0x31c7: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_31cd:
	/* 0x31cd: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_31d0:
	/* 0x31d0: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_31d6:
	/* 0x31d6: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_31dc:
	/* 0x31dc: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31e1:
	/* 0x31e1: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_31e5:
	/* 0x31e5: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_31ec:
	/* 0x31ec: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_31f1:
	/* 0x31f1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_31f6:
	/* 0x31f6: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_31fd:
	/* 0x31fd: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3200:
	/* 0x3200: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3207:
	/* 0x3207: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_320c:
	/* 0x320c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3211:
	/* 0x3211: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3213:
	/* 0x3213: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3217:
	/* 0x3217: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_3219:
	/* 0x3219: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_321b:
	/* 0x321b: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_3221:
	/* 0x3221: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3224:
	/* 0x3224: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_322a:
	/* 0x322a: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_3230:
	/* 0x3230: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3235:
	/* 0x3235: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3239:
	/* 0x3239: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3240:
	/* 0x3240: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3245:
	/* 0x3245: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_324a:
	/* 0x324a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_324f:
	/* 0x324f: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3257:
	/* 0x3257: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_325b:
	/* 0x325b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3262:
	/* 0x3262: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3267:
	/* 0x3267: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3269:
	/* 0x3269: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_326e:
	/* 0x326e: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3276:
	/* 0x3276: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3279:
	/* 0x3279: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3281:
	/* 0x3281: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_328a:
	/* 0x328a: lea    rdx,[r13+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_3291:
	/* 0x3291: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3296:
	/* 0x3296: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_329b:
	/* 0x329b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32a0:
	/* 0x32a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32a5:
	/* 0x32a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32a7:
	/* 0x32a7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32ac:
	/* 0x32ac: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_32ae:
	/* 0x32ae: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_32b1:
	/* 0x32b1: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_32b7:
	/* 0x32b7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_32ba:
	/* 0x32ba: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_32c0:
	/* 0x32c0: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_32c6:
	/* 0x32c6: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32cb:
	/* 0x32cb: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_32cf:
	/* 0x32cf: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_32d6:
	/* 0x32d6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_32db:
	/* 0x32db: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_32e0:
	/* 0x32e0: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_32e7:
	/* 0x32e7: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_32ea:
	/* 0x32ea: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_32f1:
	/* 0x32f1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32f6:
	/* 0x32f6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_32fb:
	/* 0x32fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32fd:
	/* 0x32fd: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3301:
	/* 0x3301: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_3303:
	/* 0x3303: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3305:
	/* 0x3305: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_330b:
	/* 0x330b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_330e:
	/* 0x330e: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3314:
	/* 0x3314: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_331a:
	/* 0x331a: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_331f:
	/* 0x331f: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3323:
	/* 0x3323: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_332a:
	/* 0x332a: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_332f:
	/* 0x332f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3334:
	/* 0x3334: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3339:
	/* 0x3339: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3341:
	/* 0x3341: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3345:
	/* 0x3345: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_334c:
	/* 0x334c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3351:
	/* 0x3351: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3353:
	/* 0x3353: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3358:
	/* 0x3358: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3360:
	/* 0x3360: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3363:
	/* 0x3363: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_336b:
	/* 0x336b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3374:
	/* 0x3374: add    r13,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_337b:
	/* 0x337b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3380:
	/* 0x3380: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3385:
	/* 0x3385: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_338a:
	/* 0x338a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_338f:
	/* 0x338f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3392:
	/* 0x3392: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3394:
	/* 0x3394: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3399:
	/* 0x3399: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_339b:
	/* 0x339b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_339e:
	/* 0x339e: je     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3264ULL;
	}
x86_l_33a4:
	/* 0x33a4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_33a7:
	/* 0x33a7: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_33ad:
	/* 0x33ad: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_33b3:
	/* 0x33b3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33b8:
	/* 0x33b8: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_33bc:
	/* 0x33bc: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_33c3:
	/* 0x33c3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_33c8:
	/* 0x33c8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_33cd:
	/* 0x33cd: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_33d4:
	/* 0x33d4: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_33d7:
	/* 0x33d7: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_33de:
	/* 0x33de: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33e3:
	/* 0x33e3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_33e8:
	/* 0x33e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33ea:
	/* 0x33ea: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_33ee:
	/* 0x33ee: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_33f0:
	/* 0x33f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33f2:
	/* 0x33f2: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_33f8:
	/* 0x33f8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_33fb:
	/* 0x33fb: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3401:
	/* 0x3401: ja     cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3264ULL;
	}
x86_l_3407:
	/* 0x3407: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_340c:
	/* 0x340c: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3410:
	/* 0x3410: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3417:
	/* 0x3417: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_341c:
	/* 0x341c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3421:
	/* 0x3421: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3426:
	/* 0x3426: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_342e:
	/* 0x342e: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3432:
	/* 0x3432: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3439:
	/* 0x3439: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_343e:
	/* 0x343e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3440:
	/* 0x3440: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3445:
	/* 0x3445: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_344d:
	/* 0x344d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3450:
	/* 0x3450: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3458:
	/* 0x3458: mov    DWORD PTR [rsp+0x10],0x2e2e2e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68722503214ULL);
x86_l_3460:
	/* 0x3460: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3463:
	/* 0x3463: cmp    ecx,0x6cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27901ULL);
x86_l_3469:
	/* 0x3469: jb     3474 <syscall__execveat_enter+0x3474> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3474;
	}
x86_l_346b:
	/* 0x346b: mov    WORD PTR [rbx],0x6cfc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27900ULL);
x86_l_3470:
	/* 0x3470: mov    ax,0x6cfc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 27900ULL);
x86_l_3474:
	/* 0x3474: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3477:
	/* 0x3477: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_347c:
	/* 0x347c: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3480:
	/* 0x3480: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3487:
	/* 0x3487: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_348c:
	/* 0x348c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3491:
	/* 0x3491: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3496:
	/* 0x3496: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_349d:
	/* 0x349d: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_34a0:
	/* 0x34a0: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_34a7:
	/* 0x34a7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_34ac:
	/* 0x34ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34ae:
	/* 0x34ae: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_34b2:
	/* 0x34b2: mov    cl,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 38ULL);
x86_l_34b4:
	/* 0x34b4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34b6:
	/* 0x34b6: jle    cc0 <syscall__execveat_enter+0xcc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3264ULL;
	}
x86_l_34bc:
	/* 0x34bc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_34bf:
	/* 0x34bf: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_34c5:
	/* 0x34c5: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_34ca:
	/* 0x34ca: ja     cc5 <syscall__execveat_enter+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3269ULL;
	}
x86_l_34d0:
	/* 0x34d0: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34d5:
	/* 0x34d5: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_34d9:
	/* 0x34d9: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_34e0:
	/* 0x34e0: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_34e5:
	/* 0x34e5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_34ea:
	/* 0x34ea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_34ef:
	/* 0x34ef: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_34f7:
	/* 0x34f7: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_34fb:
	/* 0x34fb: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3502:
	/* 0x3502: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3507:
	/* 0x3507: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3509:
	/* 0x3509: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_350e:
	/* 0x350e: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3516:
	/* 0x3516: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3519:
	/* 0x3519: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3521:
	/* 0x3521: mov    cl,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 39ULL);
x86_l_3523:
	/* 0x3523: jmp    cc5 <syscall__execveat_enter+0xcc5> */
	return 3269ULL;
x86_l_3528:
	/* 0x3528: lea    rcx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_352c:
	/* 0x352c: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3533:
	/* 0x3533: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3538:
	/* 0x3538: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_353d:
	/* 0x353d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3542:
	/* 0x3542: movzx  ecx,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3549:
	/* 0x3549: lea    rdi,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_354d:
	/* 0x354d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3554:
	/* 0x3554: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3559:
	/* 0x3559: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_355b:
	/* 0x355b: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3560:
	/* 0x3560: add    ax,WORD PTR [rbp+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3567:
	/* 0x3567: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_356a:
	/* 0x356a: mov    WORD PTR [rbp+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3571:
	/* 0x3571: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_357a:
	/* 0x357a: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_357e:
	/* 0x357e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3583:
	/* 0x3583: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3588:
	/* 0x3588: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_358d:
	/* 0x358d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3592:
	/* 0x3592: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3594:
	/* 0x3594: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3599:
	/* 0x3599: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_359b:
	/* 0x359b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_359e:
	/* 0x359e: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_35a4:
	/* 0x35a4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_35a7:
	/* 0x35a7: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_35ad:
	/* 0x35ad: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_35b3:
	/* 0x35b3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35b8:
	/* 0x35b8: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_35bc:
	/* 0x35bc: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_35c3:
	/* 0x35c3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_35c8:
	/* 0x35c8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_35cd:
	/* 0x35cd: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_35d4:
	/* 0x35d4: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_35d7:
	/* 0x35d7: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_35de:
	/* 0x35de: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35e3:
	/* 0x35e3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_35e8:
	/* 0x35e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35ea:
	/* 0x35ea: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_35ee:
	/* 0x35ee: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_35f0:
	/* 0x35f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35f2:
	/* 0x35f2: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_35f8:
	/* 0x35f8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_35fb:
	/* 0x35fb: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3601:
	/* 0x3601: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_3607:
	/* 0x3607: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_360c:
	/* 0x360c: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3610:
	/* 0x3610: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3617:
	/* 0x3617: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_361c:
	/* 0x361c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3621:
	/* 0x3621: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3626:
	/* 0x3626: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_362e:
	/* 0x362e: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3632:
	/* 0x3632: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3639:
	/* 0x3639: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_363e:
	/* 0x363e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3640:
	/* 0x3640: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3645:
	/* 0x3645: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_364d:
	/* 0x364d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3650:
	/* 0x3650: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3658:
	/* 0x3658: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3661:
	/* 0x3661: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3665:
	/* 0x3665: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_366a:
	/* 0x366a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_366f:
	/* 0x366f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3674:
	/* 0x3674: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3679:
	/* 0x3679: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_367b:
	/* 0x367b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3680:
	/* 0x3680: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_3682:
	/* 0x3682: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3685:
	/* 0x3685: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_368b:
	/* 0x368b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_368e:
	/* 0x368e: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3694:
	/* 0x3694: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_369a:
	/* 0x369a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_369f:
	/* 0x369f: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_36a3:
	/* 0x36a3: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_36aa:
	/* 0x36aa: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_36af:
	/* 0x36af: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_36b4:
	/* 0x36b4: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_36bb:
	/* 0x36bb: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_36be:
	/* 0x36be: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_36c5:
	/* 0x36c5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36ca:
	/* 0x36ca: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_36cf:
	/* 0x36cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36d1:
	/* 0x36d1: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_36d5:
	/* 0x36d5: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_36d7:
	/* 0x36d7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36d9:
	/* 0x36d9: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_36df:
	/* 0x36df: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_36e2:
	/* 0x36e2: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_36e8:
	/* 0x36e8: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_36ee:
	/* 0x36ee: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36f3:
	/* 0x36f3: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_36f7:
	/* 0x36f7: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_36fe:
	/* 0x36fe: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3703:
	/* 0x3703: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3708:
	/* 0x3708: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_370d:
	/* 0x370d: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3715:
	/* 0x3715: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3719:
	/* 0x3719: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3720:
	/* 0x3720: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3725:
	/* 0x3725: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3727:
	/* 0x3727: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_372c:
	/* 0x372c: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3734:
	/* 0x3734: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3737:
	/* 0x3737: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_373f:
	/* 0x373f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3748:
	/* 0x3748: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_374c:
	/* 0x374c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3751:
	/* 0x3751: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3756:
	/* 0x3756: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_375b:
	/* 0x375b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3760:
	/* 0x3760: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3762:
	/* 0x3762: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3767:
	/* 0x3767: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_3769:
	/* 0x3769: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_376c:
	/* 0x376c: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_3772:
	/* 0x3772: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3775:
	/* 0x3775: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_377b:
	/* 0x377b: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_3781:
	/* 0x3781: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3786:
	/* 0x3786: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_378a:
	/* 0x378a: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3791:
	/* 0x3791: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3796:
	/* 0x3796: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_379b:
	/* 0x379b: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_37a2:
	/* 0x37a2: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_37a5:
	/* 0x37a5: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_37ac:
	/* 0x37ac: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37b1:
	/* 0x37b1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_37b6:
	/* 0x37b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37b8:
	/* 0x37b8: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_37bc:
	/* 0x37bc: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_37be:
	/* 0x37be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37c0:
	/* 0x37c0: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_37c6:
	/* 0x37c6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_37c9:
	/* 0x37c9: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_37cf:
	/* 0x37cf: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_37d5:
	/* 0x37d5: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37da:
	/* 0x37da: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_37de:
	/* 0x37de: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_37e5:
	/* 0x37e5: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_37ea:
	/* 0x37ea: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_37ef:
	/* 0x37ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37f4:
	/* 0x37f4: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_37fc:
	/* 0x37fc: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3800:
	/* 0x3800: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3807:
	/* 0x3807: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_380c:
	/* 0x380c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_380e:
	/* 0x380e: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3813:
	/* 0x3813: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_381b:
	/* 0x381b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_381e:
	/* 0x381e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3826:
	/* 0x3826: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_382f:
	/* 0x382f: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3833:
	/* 0x3833: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3838:
	/* 0x3838: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_383d:
	/* 0x383d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3842:
	/* 0x3842: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3847:
	/* 0x3847: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3849:
	/* 0x3849: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_384e:
	/* 0x384e: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_3850:
	/* 0x3850: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3853:
	/* 0x3853: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_3859:
	/* 0x3859: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_385c:
	/* 0x385c: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3862:
	/* 0x3862: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_3868:
	/* 0x3868: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_386d:
	/* 0x386d: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3871:
	/* 0x3871: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3878:
	/* 0x3878: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_387d:
	/* 0x387d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3882:
	/* 0x3882: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3889:
	/* 0x3889: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_388c:
	/* 0x388c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3893:
	/* 0x3893: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3898:
	/* 0x3898: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_389d:
	/* 0x389d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_389f:
	/* 0x389f: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_38a3:
	/* 0x38a3: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_38a5:
	/* 0x38a5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38a7:
	/* 0x38a7: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_38ad:
	/* 0x38ad: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_38b0:
	/* 0x38b0: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_38b6:
	/* 0x38b6: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_38bc:
	/* 0x38bc: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38c1:
	/* 0x38c1: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_38c5:
	/* 0x38c5: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_38cc:
	/* 0x38cc: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_38d1:
	/* 0x38d1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_38d6:
	/* 0x38d6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_38db:
	/* 0x38db: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_38e3:
	/* 0x38e3: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_38e7:
	/* 0x38e7: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_38ee:
	/* 0x38ee: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
	return 14579ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14579ULL: goto x86_l_38f3;
	case 14581ULL: goto x86_l_38f5;
	case 14586ULL: goto x86_l_38fa;
	case 14594ULL: goto x86_l_3902;
	case 14597ULL: goto x86_l_3905;
	case 14605ULL: goto x86_l_390d;
	case 14614ULL: goto x86_l_3916;
	case 14618ULL: goto x86_l_391a;
	case 14623ULL: goto x86_l_391f;
	case 14628ULL: goto x86_l_3924;
	case 14633ULL: goto x86_l_3929;
	case 14638ULL: goto x86_l_392e;
	case 14640ULL: goto x86_l_3930;
	case 14645ULL: goto x86_l_3935;
	case 14647ULL: goto x86_l_3937;
	case 14650ULL: goto x86_l_393a;
	case 14656ULL: goto x86_l_3940;
	case 14659ULL: goto x86_l_3943;
	case 14665ULL: goto x86_l_3949;
	case 14671ULL: goto x86_l_394f;
	case 14676ULL: goto x86_l_3954;
	case 14680ULL: goto x86_l_3958;
	case 14687ULL: goto x86_l_395f;
	case 14692ULL: goto x86_l_3964;
	case 14697ULL: goto x86_l_3969;
	case 14704ULL: goto x86_l_3970;
	case 14707ULL: goto x86_l_3973;
	case 14714ULL: goto x86_l_397a;
	case 14719ULL: goto x86_l_397f;
	case 14724ULL: goto x86_l_3984;
	case 14726ULL: goto x86_l_3986;
	case 14730ULL: goto x86_l_398a;
	case 14732ULL: goto x86_l_398c;
	case 14734ULL: goto x86_l_398e;
	case 14740ULL: goto x86_l_3994;
	case 14743ULL: goto x86_l_3997;
	case 14749ULL: goto x86_l_399d;
	case 14755ULL: goto x86_l_39a3;
	case 14760ULL: goto x86_l_39a8;
	case 14764ULL: goto x86_l_39ac;
	case 14771ULL: goto x86_l_39b3;
	case 14776ULL: goto x86_l_39b8;
	case 14781ULL: goto x86_l_39bd;
	case 14786ULL: goto x86_l_39c2;
	case 14794ULL: goto x86_l_39ca;
	case 14798ULL: goto x86_l_39ce;
	case 14805ULL: goto x86_l_39d5;
	case 14810ULL: goto x86_l_39da;
	case 14812ULL: goto x86_l_39dc;
	case 14817ULL: goto x86_l_39e1;
	case 14825ULL: goto x86_l_39e9;
	case 14828ULL: goto x86_l_39ec;
	case 14836ULL: goto x86_l_39f4;
	case 14845ULL: goto x86_l_39fd;
	case 14849ULL: goto x86_l_3a01;
	case 14854ULL: goto x86_l_3a06;
	case 14859ULL: goto x86_l_3a0b;
	case 14864ULL: goto x86_l_3a10;
	case 14869ULL: goto x86_l_3a15;
	case 14871ULL: goto x86_l_3a17;
	case 14876ULL: goto x86_l_3a1c;
	case 14878ULL: goto x86_l_3a1e;
	case 14881ULL: goto x86_l_3a21;
	case 14887ULL: goto x86_l_3a27;
	case 14890ULL: goto x86_l_3a2a;
	case 14896ULL: goto x86_l_3a30;
	case 14902ULL: goto x86_l_3a36;
	case 14907ULL: goto x86_l_3a3b;
	case 14911ULL: goto x86_l_3a3f;
	case 14918ULL: goto x86_l_3a46;
	case 14923ULL: goto x86_l_3a4b;
	case 14928ULL: goto x86_l_3a50;
	case 14935ULL: goto x86_l_3a57;
	case 14938ULL: goto x86_l_3a5a;
	case 14945ULL: goto x86_l_3a61;
	case 14950ULL: goto x86_l_3a66;
	case 14955ULL: goto x86_l_3a6b;
	case 14957ULL: goto x86_l_3a6d;
	case 14961ULL: goto x86_l_3a71;
	case 14963ULL: goto x86_l_3a73;
	case 14965ULL: goto x86_l_3a75;
	case 14971ULL: goto x86_l_3a7b;
	case 14974ULL: goto x86_l_3a7e;
	case 14980ULL: goto x86_l_3a84;
	case 14986ULL: goto x86_l_3a8a;
	case 14991ULL: goto x86_l_3a8f;
	case 14995ULL: goto x86_l_3a93;
	case 15002ULL: goto x86_l_3a9a;
	case 15007ULL: goto x86_l_3a9f;
	case 15012ULL: goto x86_l_3aa4;
	case 15017ULL: goto x86_l_3aa9;
	case 15025ULL: goto x86_l_3ab1;
	case 15029ULL: goto x86_l_3ab5;
	case 15036ULL: goto x86_l_3abc;
	case 15041ULL: goto x86_l_3ac1;
	case 15043ULL: goto x86_l_3ac3;
	case 15048ULL: goto x86_l_3ac8;
	case 15056ULL: goto x86_l_3ad0;
	case 15059ULL: goto x86_l_3ad3;
	case 15067ULL: goto x86_l_3adb;
	case 15076ULL: goto x86_l_3ae4;
	case 15080ULL: goto x86_l_3ae8;
	case 15085ULL: goto x86_l_3aed;
	case 15090ULL: goto x86_l_3af2;
	case 15095ULL: goto x86_l_3af7;
	case 15100ULL: goto x86_l_3afc;
	case 15102ULL: goto x86_l_3afe;
	case 15107ULL: goto x86_l_3b03;
	case 15109ULL: goto x86_l_3b05;
	case 15112ULL: goto x86_l_3b08;
	case 15118ULL: goto x86_l_3b0e;
	case 15121ULL: goto x86_l_3b11;
	case 15127ULL: goto x86_l_3b17;
	case 15133ULL: goto x86_l_3b1d;
	case 15138ULL: goto x86_l_3b22;
	case 15142ULL: goto x86_l_3b26;
	case 15149ULL: goto x86_l_3b2d;
	case 15154ULL: goto x86_l_3b32;
	case 15159ULL: goto x86_l_3b37;
	case 15166ULL: goto x86_l_3b3e;
	case 15169ULL: goto x86_l_3b41;
	case 15176ULL: goto x86_l_3b48;
	case 15181ULL: goto x86_l_3b4d;
	case 15186ULL: goto x86_l_3b52;
	case 15188ULL: goto x86_l_3b54;
	case 15192ULL: goto x86_l_3b58;
	case 15194ULL: goto x86_l_3b5a;
	case 15196ULL: goto x86_l_3b5c;
	case 15202ULL: goto x86_l_3b62;
	case 15205ULL: goto x86_l_3b65;
	case 15211ULL: goto x86_l_3b6b;
	case 15217ULL: goto x86_l_3b71;
	case 15222ULL: goto x86_l_3b76;
	case 15226ULL: goto x86_l_3b7a;
	case 15233ULL: goto x86_l_3b81;
	case 15238ULL: goto x86_l_3b86;
	case 15243ULL: goto x86_l_3b8b;
	case 15248ULL: goto x86_l_3b90;
	case 15256ULL: goto x86_l_3b98;
	case 15260ULL: goto x86_l_3b9c;
	case 15267ULL: goto x86_l_3ba3;
	case 15272ULL: goto x86_l_3ba8;
	case 15274ULL: goto x86_l_3baa;
	case 15279ULL: goto x86_l_3baf;
	case 15287ULL: goto x86_l_3bb7;
	case 15290ULL: goto x86_l_3bba;
	case 15298ULL: goto x86_l_3bc2;
	case 15307ULL: goto x86_l_3bcb;
	case 15311ULL: goto x86_l_3bcf;
	case 15316ULL: goto x86_l_3bd4;
	case 15321ULL: goto x86_l_3bd9;
	case 15326ULL: goto x86_l_3bde;
	case 15331ULL: goto x86_l_3be3;
	case 15333ULL: goto x86_l_3be5;
	case 15338ULL: goto x86_l_3bea;
	case 15340ULL: goto x86_l_3bec;
	case 15343ULL: goto x86_l_3bef;
	case 15349ULL: goto x86_l_3bf5;
	case 15352ULL: goto x86_l_3bf8;
	case 15358ULL: goto x86_l_3bfe;
	case 15364ULL: goto x86_l_3c04;
	case 15369ULL: goto x86_l_3c09;
	case 15373ULL: goto x86_l_3c0d;
	case 15380ULL: goto x86_l_3c14;
	case 15385ULL: goto x86_l_3c19;
	case 15390ULL: goto x86_l_3c1e;
	case 15397ULL: goto x86_l_3c25;
	case 15400ULL: goto x86_l_3c28;
	case 15407ULL: goto x86_l_3c2f;
	case 15412ULL: goto x86_l_3c34;
	case 15417ULL: goto x86_l_3c39;
	case 15419ULL: goto x86_l_3c3b;
	case 15423ULL: goto x86_l_3c3f;
	case 15425ULL: goto x86_l_3c41;
	case 15427ULL: goto x86_l_3c43;
	case 15433ULL: goto x86_l_3c49;
	case 15436ULL: goto x86_l_3c4c;
	case 15442ULL: goto x86_l_3c52;
	case 15448ULL: goto x86_l_3c58;
	case 15453ULL: goto x86_l_3c5d;
	case 15457ULL: goto x86_l_3c61;
	case 15464ULL: goto x86_l_3c68;
	case 15469ULL: goto x86_l_3c6d;
	case 15474ULL: goto x86_l_3c72;
	case 15479ULL: goto x86_l_3c77;
	case 15487ULL: goto x86_l_3c7f;
	case 15491ULL: goto x86_l_3c83;
	case 15498ULL: goto x86_l_3c8a;
	case 15503ULL: goto x86_l_3c8f;
	case 15505ULL: goto x86_l_3c91;
	case 15510ULL: goto x86_l_3c96;
	case 15518ULL: goto x86_l_3c9e;
	case 15521ULL: goto x86_l_3ca1;
	case 15529ULL: goto x86_l_3ca9;
	case 15538ULL: goto x86_l_3cb2;
	case 15542ULL: goto x86_l_3cb6;
	case 15547ULL: goto x86_l_3cbb;
	case 15552ULL: goto x86_l_3cc0;
	case 15557ULL: goto x86_l_3cc5;
	case 15562ULL: goto x86_l_3cca;
	case 15564ULL: goto x86_l_3ccc;
	case 15569ULL: goto x86_l_3cd1;
	case 15571ULL: goto x86_l_3cd3;
	case 15574ULL: goto x86_l_3cd6;
	case 15580ULL: goto x86_l_3cdc;
	case 15583ULL: goto x86_l_3cdf;
	case 15589ULL: goto x86_l_3ce5;
	case 15595ULL: goto x86_l_3ceb;
	case 15600ULL: goto x86_l_3cf0;
	case 15604ULL: goto x86_l_3cf4;
	case 15611ULL: goto x86_l_3cfb;
	case 15616ULL: goto x86_l_3d00;
	case 15621ULL: goto x86_l_3d05;
	case 15628ULL: goto x86_l_3d0c;
	case 15631ULL: goto x86_l_3d0f;
	case 15638ULL: goto x86_l_3d16;
	case 15643ULL: goto x86_l_3d1b;
	case 15648ULL: goto x86_l_3d20;
	case 15650ULL: goto x86_l_3d22;
	case 15654ULL: goto x86_l_3d26;
	case 15656ULL: goto x86_l_3d28;
	case 15658ULL: goto x86_l_3d2a;
	case 15664ULL: goto x86_l_3d30;
	case 15667ULL: goto x86_l_3d33;
	case 15673ULL: goto x86_l_3d39;
	case 15679ULL: goto x86_l_3d3f;
	case 15684ULL: goto x86_l_3d44;
	case 15688ULL: goto x86_l_3d48;
	case 15695ULL: goto x86_l_3d4f;
	case 15700ULL: goto x86_l_3d54;
	case 15705ULL: goto x86_l_3d59;
	case 15710ULL: goto x86_l_3d5e;
	case 15718ULL: goto x86_l_3d66;
	case 15722ULL: goto x86_l_3d6a;
	case 15729ULL: goto x86_l_3d71;
	case 15734ULL: goto x86_l_3d76;
	case 15736ULL: goto x86_l_3d78;
	case 15741ULL: goto x86_l_3d7d;
	case 15749ULL: goto x86_l_3d85;
	case 15752ULL: goto x86_l_3d88;
	case 15760ULL: goto x86_l_3d90;
	case 15769ULL: goto x86_l_3d99;
	case 15773ULL: goto x86_l_3d9d;
	case 15778ULL: goto x86_l_3da2;
	case 15783ULL: goto x86_l_3da7;
	case 15788ULL: goto x86_l_3dac;
	case 15793ULL: goto x86_l_3db1;
	case 15795ULL: goto x86_l_3db3;
	case 15800ULL: goto x86_l_3db8;
	case 15802ULL: goto x86_l_3dba;
	case 15805ULL: goto x86_l_3dbd;
	case 15811ULL: goto x86_l_3dc3;
	case 15814ULL: goto x86_l_3dc6;
	case 15820ULL: goto x86_l_3dcc;
	case 15826ULL: goto x86_l_3dd2;
	case 15831ULL: goto x86_l_3dd7;
	case 15835ULL: goto x86_l_3ddb;
	case 15842ULL: goto x86_l_3de2;
	case 15847ULL: goto x86_l_3de7;
	case 15852ULL: goto x86_l_3dec;
	case 15859ULL: goto x86_l_3df3;
	case 15862ULL: goto x86_l_3df6;
	case 15869ULL: goto x86_l_3dfd;
	case 15874ULL: goto x86_l_3e02;
	case 15879ULL: goto x86_l_3e07;
	case 15881ULL: goto x86_l_3e09;
	case 15885ULL: goto x86_l_3e0d;
	case 15887ULL: goto x86_l_3e0f;
	case 15889ULL: goto x86_l_3e11;
	case 15895ULL: goto x86_l_3e17;
	case 15898ULL: goto x86_l_3e1a;
	case 15904ULL: goto x86_l_3e20;
	case 15910ULL: goto x86_l_3e26;
	case 15915ULL: goto x86_l_3e2b;
	case 15919ULL: goto x86_l_3e2f;
	case 15926ULL: goto x86_l_3e36;
	case 15931ULL: goto x86_l_3e3b;
	case 15936ULL: goto x86_l_3e40;
	case 15941ULL: goto x86_l_3e45;
	case 15949ULL: goto x86_l_3e4d;
	case 15953ULL: goto x86_l_3e51;
	case 15960ULL: goto x86_l_3e58;
	case 15965ULL: goto x86_l_3e5d;
	case 15967ULL: goto x86_l_3e5f;
	case 15972ULL: goto x86_l_3e64;
	case 15980ULL: goto x86_l_3e6c;
	case 15983ULL: goto x86_l_3e6f;
	case 15991ULL: goto x86_l_3e77;
	case 16000ULL: goto x86_l_3e80;
	case 16004ULL: goto x86_l_3e84;
	case 16009ULL: goto x86_l_3e89;
	case 16014ULL: goto x86_l_3e8e;
	case 16019ULL: goto x86_l_3e93;
	case 16024ULL: goto x86_l_3e98;
	case 16026ULL: goto x86_l_3e9a;
	case 16031ULL: goto x86_l_3e9f;
	case 16033ULL: goto x86_l_3ea1;
	case 16036ULL: goto x86_l_3ea4;
	case 16042ULL: goto x86_l_3eaa;
	case 16045ULL: goto x86_l_3ead;
	case 16051ULL: goto x86_l_3eb3;
	case 16057ULL: goto x86_l_3eb9;
	case 16062ULL: goto x86_l_3ebe;
	case 16066ULL: goto x86_l_3ec2;
	case 16073ULL: goto x86_l_3ec9;
	case 16078ULL: goto x86_l_3ece;
	case 16083ULL: goto x86_l_3ed3;
	case 16090ULL: goto x86_l_3eda;
	case 16093ULL: goto x86_l_3edd;
	case 16100ULL: goto x86_l_3ee4;
	case 16105ULL: goto x86_l_3ee9;
	case 16110ULL: goto x86_l_3eee;
	case 16112ULL: goto x86_l_3ef0;
	case 16116ULL: goto x86_l_3ef4;
	case 16118ULL: goto x86_l_3ef6;
	case 16120ULL: goto x86_l_3ef8;
	case 16126ULL: goto x86_l_3efe;
	case 16129ULL: goto x86_l_3f01;
	case 16135ULL: goto x86_l_3f07;
	case 16141ULL: goto x86_l_3f0d;
	case 16146ULL: goto x86_l_3f12;
	case 16150ULL: goto x86_l_3f16;
	case 16157ULL: goto x86_l_3f1d;
	case 16162ULL: goto x86_l_3f22;
	case 16167ULL: goto x86_l_3f27;
	case 16172ULL: goto x86_l_3f2c;
	case 16180ULL: goto x86_l_3f34;
	case 16184ULL: goto x86_l_3f38;
	case 16191ULL: goto x86_l_3f3f;
	case 16196ULL: goto x86_l_3f44;
	case 16198ULL: goto x86_l_3f46;
	case 16203ULL: goto x86_l_3f4b;
	case 16211ULL: goto x86_l_3f53;
	case 16214ULL: goto x86_l_3f56;
	case 16222ULL: goto x86_l_3f5e;
	case 16231ULL: goto x86_l_3f67;
	case 16235ULL: goto x86_l_3f6b;
	case 16240ULL: goto x86_l_3f70;
	case 16245ULL: goto x86_l_3f75;
	case 16250ULL: goto x86_l_3f7a;
	case 16255ULL: goto x86_l_3f7f;
	case 16257ULL: goto x86_l_3f81;
	case 16262ULL: goto x86_l_3f86;
	case 16264ULL: goto x86_l_3f88;
	case 16267ULL: goto x86_l_3f8b;
	case 16273ULL: goto x86_l_3f91;
	case 16276ULL: goto x86_l_3f94;
	case 16282ULL: goto x86_l_3f9a;
	case 16288ULL: goto x86_l_3fa0;
	case 16293ULL: goto x86_l_3fa5;
	case 16297ULL: goto x86_l_3fa9;
	case 16304ULL: goto x86_l_3fb0;
	case 16309ULL: goto x86_l_3fb5;
	case 16314ULL: goto x86_l_3fba;
	case 16321ULL: goto x86_l_3fc1;
	case 16324ULL: goto x86_l_3fc4;
	case 16331ULL: goto x86_l_3fcb;
	case 16336ULL: goto x86_l_3fd0;
	case 16341ULL: goto x86_l_3fd5;
	case 16343ULL: goto x86_l_3fd7;
	case 16347ULL: goto x86_l_3fdb;
	case 16349ULL: goto x86_l_3fdd;
	case 16351ULL: goto x86_l_3fdf;
	case 16357ULL: goto x86_l_3fe5;
	case 16360ULL: goto x86_l_3fe8;
	case 16366ULL: goto x86_l_3fee;
	case 16372ULL: goto x86_l_3ff4;
	case 16377ULL: goto x86_l_3ff9;
	case 16381ULL: goto x86_l_3ffd;
	case 16388ULL: goto x86_l_4004;
	case 16393ULL: goto x86_l_4009;
	case 16398ULL: goto x86_l_400e;
	case 16403ULL: goto x86_l_4013;
	case 16411ULL: goto x86_l_401b;
	case 16415ULL: goto x86_l_401f;
	case 16422ULL: goto x86_l_4026;
	case 16427ULL: goto x86_l_402b;
	case 16429ULL: goto x86_l_402d;
	case 16434ULL: goto x86_l_4032;
	case 16442ULL: goto x86_l_403a;
	case 16445ULL: goto x86_l_403d;
	case 16453ULL: goto x86_l_4045;
	case 16462ULL: goto x86_l_404e;
	case 16466ULL: goto x86_l_4052;
	default: return 0xffffffffffffffffULL;
	}
x86_l_38f3:
	/* 0x38f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38f5:
	/* 0x38f5: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_38fa:
	/* 0x38fa: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3902:
	/* 0x3902: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3905:
	/* 0x3905: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_390d:
	/* 0x390d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3916:
	/* 0x3916: lea    rdx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_391a:
	/* 0x391a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_391f:
	/* 0x391f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3924:
	/* 0x3924: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3929:
	/* 0x3929: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_392e:
	/* 0x392e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3930:
	/* 0x3930: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3935:
	/* 0x3935: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_3937:
	/* 0x3937: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_393a:
	/* 0x393a: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_3940:
	/* 0x3940: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3943:
	/* 0x3943: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3949:
	/* 0x3949: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_394f:
	/* 0x394f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3954:
	/* 0x3954: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3958:
	/* 0x3958: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_395f:
	/* 0x395f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3964:
	/* 0x3964: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3969:
	/* 0x3969: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3970:
	/* 0x3970: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3973:
	/* 0x3973: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_397a:
	/* 0x397a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_397f:
	/* 0x397f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3984:
	/* 0x3984: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3986:
	/* 0x3986: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_398a:
	/* 0x398a: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_398c:
	/* 0x398c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_398e:
	/* 0x398e: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_3994:
	/* 0x3994: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3997:
	/* 0x3997: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_399d:
	/* 0x399d: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_39a3:
	/* 0x39a3: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39a8:
	/* 0x39a8: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_39ac:
	/* 0x39ac: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_39b3:
	/* 0x39b3: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_39b8:
	/* 0x39b8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_39bd:
	/* 0x39bd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_39c2:
	/* 0x39c2: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_39ca:
	/* 0x39ca: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_39ce:
	/* 0x39ce: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_39d5:
	/* 0x39d5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_39da:
	/* 0x39da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39dc:
	/* 0x39dc: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_39e1:
	/* 0x39e1: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_39e9:
	/* 0x39e9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_39ec:
	/* 0x39ec: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_39f4:
	/* 0x39f4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_39fd:
	/* 0x39fd: lea    rdx,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3a01:
	/* 0x3a01: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a06:
	/* 0x3a06: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3a0b:
	/* 0x3a0b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a10:
	/* 0x3a10: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a15:
	/* 0x3a15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a17:
	/* 0x3a17: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a1c:
	/* 0x3a1c: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_3a1e:
	/* 0x3a1e: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3a21:
	/* 0x3a21: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_3a27:
	/* 0x3a27: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3a2a:
	/* 0x3a2a: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3a30:
	/* 0x3a30: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_3a36:
	/* 0x3a36: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a3b:
	/* 0x3a3b: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3a3f:
	/* 0x3a3f: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3a46:
	/* 0x3a46: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3a4b:
	/* 0x3a4b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3a50:
	/* 0x3a50: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3a57:
	/* 0x3a57: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3a5a:
	/* 0x3a5a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3a61:
	/* 0x3a61: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a66:
	/* 0x3a66: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3a6b:
	/* 0x3a6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a6d:
	/* 0x3a6d: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3a71:
	/* 0x3a71: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_3a73:
	/* 0x3a73: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a75:
	/* 0x3a75: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_3a7b:
	/* 0x3a7b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3a7e:
	/* 0x3a7e: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3a84:
	/* 0x3a84: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_3a8a:
	/* 0x3a8a: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a8f:
	/* 0x3a8f: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3a93:
	/* 0x3a93: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3a9a:
	/* 0x3a9a: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3a9f:
	/* 0x3a9f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3aa4:
	/* 0x3aa4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3aa9:
	/* 0x3aa9: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3ab1:
	/* 0x3ab1: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3ab5:
	/* 0x3ab5: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3abc:
	/* 0x3abc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3ac1:
	/* 0x3ac1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ac3:
	/* 0x3ac3: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3ac8:
	/* 0x3ac8: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3ad0:
	/* 0x3ad0: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3ad3:
	/* 0x3ad3: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3adb:
	/* 0x3adb: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3ae4:
	/* 0x3ae4: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3ae8:
	/* 0x3ae8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3aed:
	/* 0x3aed: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3af2:
	/* 0x3af2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3af7:
	/* 0x3af7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3afc:
	/* 0x3afc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3afe:
	/* 0x3afe: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b03:
	/* 0x3b03: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_3b05:
	/* 0x3b05: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3b08:
	/* 0x3b08: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_3b0e:
	/* 0x3b0e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b11:
	/* 0x3b11: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3b17:
	/* 0x3b17: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_3b1d:
	/* 0x3b1d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b22:
	/* 0x3b22: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3b26:
	/* 0x3b26: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3b2d:
	/* 0x3b2d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3b32:
	/* 0x3b32: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3b37:
	/* 0x3b37: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3b3e:
	/* 0x3b3e: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3b41:
	/* 0x3b41: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3b48:
	/* 0x3b48: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b4d:
	/* 0x3b4d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3b52:
	/* 0x3b52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b54:
	/* 0x3b54: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3b58:
	/* 0x3b58: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_3b5a:
	/* 0x3b5a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b5c:
	/* 0x3b5c: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_3b62:
	/* 0x3b62: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b65:
	/* 0x3b65: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3b6b:
	/* 0x3b6b: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_3b71:
	/* 0x3b71: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b76:
	/* 0x3b76: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3b7a:
	/* 0x3b7a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3b81:
	/* 0x3b81: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3b86:
	/* 0x3b86: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3b8b:
	/* 0x3b8b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b90:
	/* 0x3b90: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3b98:
	/* 0x3b98: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3b9c:
	/* 0x3b9c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3ba3:
	/* 0x3ba3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3ba8:
	/* 0x3ba8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3baa:
	/* 0x3baa: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3baf:
	/* 0x3baf: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3bb7:
	/* 0x3bb7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3bba:
	/* 0x3bba: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3bc2:
	/* 0x3bc2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3bcb:
	/* 0x3bcb: lea    rdx,[r13+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3bcf:
	/* 0x3bcf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bd4:
	/* 0x3bd4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3bd9:
	/* 0x3bd9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3bde:
	/* 0x3bde: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3be3:
	/* 0x3be3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3be5:
	/* 0x3be5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bea:
	/* 0x3bea: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_3bec:
	/* 0x3bec: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3bef:
	/* 0x3bef: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_3bf5:
	/* 0x3bf5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3bf8:
	/* 0x3bf8: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3bfe:
	/* 0x3bfe: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_3c04:
	/* 0x3c04: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c09:
	/* 0x3c09: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3c0d:
	/* 0x3c0d: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3c14:
	/* 0x3c14: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3c19:
	/* 0x3c19: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3c1e:
	/* 0x3c1e: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3c25:
	/* 0x3c25: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3c28:
	/* 0x3c28: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3c2f:
	/* 0x3c2f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c34:
	/* 0x3c34: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3c39:
	/* 0x3c39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c3b:
	/* 0x3c3b: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3c3f:
	/* 0x3c3f: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_3c41:
	/* 0x3c41: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c43:
	/* 0x3c43: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_3c49:
	/* 0x3c49: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3c4c:
	/* 0x3c4c: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3c52:
	/* 0x3c52: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_3c58:
	/* 0x3c58: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c5d:
	/* 0x3c5d: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3c61:
	/* 0x3c61: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3c68:
	/* 0x3c68: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3c6d:
	/* 0x3c6d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3c72:
	/* 0x3c72: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c77:
	/* 0x3c77: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3c7f:
	/* 0x3c7f: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3c83:
	/* 0x3c83: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3c8a:
	/* 0x3c8a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3c8f:
	/* 0x3c8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c91:
	/* 0x3c91: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3c96:
	/* 0x3c96: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3c9e:
	/* 0x3c9e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3ca1:
	/* 0x3ca1: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3ca9:
	/* 0x3ca9: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3cb2:
	/* 0x3cb2: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3cb6:
	/* 0x3cb6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cbb:
	/* 0x3cbb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3cc0:
	/* 0x3cc0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3cc5:
	/* 0x3cc5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cca:
	/* 0x3cca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ccc:
	/* 0x3ccc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cd1:
	/* 0x3cd1: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_3cd3:
	/* 0x3cd3: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3cd6:
	/* 0x3cd6: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_3cdc:
	/* 0x3cdc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3cdf:
	/* 0x3cdf: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3ce5:
	/* 0x3ce5: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_3ceb:
	/* 0x3ceb: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3cf0:
	/* 0x3cf0: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3cf4:
	/* 0x3cf4: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3cfb:
	/* 0x3cfb: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3d00:
	/* 0x3d00: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3d05:
	/* 0x3d05: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3d0c:
	/* 0x3d0c: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3d0f:
	/* 0x3d0f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3d16:
	/* 0x3d16: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d1b:
	/* 0x3d1b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3d20:
	/* 0x3d20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d22:
	/* 0x3d22: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3d26:
	/* 0x3d26: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_3d28:
	/* 0x3d28: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d2a:
	/* 0x3d2a: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_3d30:
	/* 0x3d30: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3d33:
	/* 0x3d33: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3d39:
	/* 0x3d39: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_3d3f:
	/* 0x3d3f: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d44:
	/* 0x3d44: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3d48:
	/* 0x3d48: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3d4f:
	/* 0x3d4f: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3d54:
	/* 0x3d54: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3d59:
	/* 0x3d59: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d5e:
	/* 0x3d5e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3d66:
	/* 0x3d66: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3d6a:
	/* 0x3d6a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3d71:
	/* 0x3d71: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3d76:
	/* 0x3d76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d78:
	/* 0x3d78: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3d7d:
	/* 0x3d7d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3d85:
	/* 0x3d85: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3d88:
	/* 0x3d88: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3d90:
	/* 0x3d90: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3d99:
	/* 0x3d99: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3d9d:
	/* 0x3d9d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3da2:
	/* 0x3da2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3da7:
	/* 0x3da7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3dac:
	/* 0x3dac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3db1:
	/* 0x3db1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3db3:
	/* 0x3db3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3db8:
	/* 0x3db8: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_3dba:
	/* 0x3dba: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3dbd:
	/* 0x3dbd: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_3dc3:
	/* 0x3dc3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3dc6:
	/* 0x3dc6: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3dcc:
	/* 0x3dcc: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_3dd2:
	/* 0x3dd2: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3dd7:
	/* 0x3dd7: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3ddb:
	/* 0x3ddb: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3de2:
	/* 0x3de2: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3de7:
	/* 0x3de7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3dec:
	/* 0x3dec: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3df3:
	/* 0x3df3: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3df6:
	/* 0x3df6: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3dfd:
	/* 0x3dfd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e02:
	/* 0x3e02: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3e07:
	/* 0x3e07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e09:
	/* 0x3e09: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3e0d:
	/* 0x3e0d: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_3e0f:
	/* 0x3e0f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3e11:
	/* 0x3e11: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_3e17:
	/* 0x3e17: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e1a:
	/* 0x3e1a: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3e20:
	/* 0x3e20: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_3e26:
	/* 0x3e26: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e2b:
	/* 0x3e2b: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3e2f:
	/* 0x3e2f: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3e36:
	/* 0x3e36: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3e3b:
	/* 0x3e3b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e40:
	/* 0x3e40: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e45:
	/* 0x3e45: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3e4d:
	/* 0x3e4d: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3e51:
	/* 0x3e51: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3e58:
	/* 0x3e58: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e5d:
	/* 0x3e5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e5f:
	/* 0x3e5f: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3e64:
	/* 0x3e64: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3e6c:
	/* 0x3e6c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3e6f:
	/* 0x3e6f: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3e77:
	/* 0x3e77: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3e80:
	/* 0x3e80: lea    rdx,[r13+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3e84:
	/* 0x3e84: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e89:
	/* 0x3e89: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3e8e:
	/* 0x3e8e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e93:
	/* 0x3e93: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e98:
	/* 0x3e98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e9a:
	/* 0x3e9a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e9f:
	/* 0x3e9f: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_3ea1:
	/* 0x3ea1: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3ea4:
	/* 0x3ea4: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_3eaa:
	/* 0x3eaa: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ead:
	/* 0x3ead: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3eb3:
	/* 0x3eb3: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_3eb9:
	/* 0x3eb9: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ebe:
	/* 0x3ebe: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3ec2:
	/* 0x3ec2: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3ec9:
	/* 0x3ec9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3ece:
	/* 0x3ece: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3ed3:
	/* 0x3ed3: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3eda:
	/* 0x3eda: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3edd:
	/* 0x3edd: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3ee4:
	/* 0x3ee4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ee9:
	/* 0x3ee9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3eee:
	/* 0x3eee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ef0:
	/* 0x3ef0: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3ef4:
	/* 0x3ef4: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_3ef6:
	/* 0x3ef6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ef8:
	/* 0x3ef8: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_3efe:
	/* 0x3efe: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f01:
	/* 0x3f01: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3f07:
	/* 0x3f07: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_3f0d:
	/* 0x3f0d: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f12:
	/* 0x3f12: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3f16:
	/* 0x3f16: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3f1d:
	/* 0x3f1d: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3f22:
	/* 0x3f22: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3f27:
	/* 0x3f27: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3f2c:
	/* 0x3f2c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3f34:
	/* 0x3f34: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3f38:
	/* 0x3f38: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3f3f:
	/* 0x3f3f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3f44:
	/* 0x3f44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f46:
	/* 0x3f46: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3f4b:
	/* 0x3f4b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3f53:
	/* 0x3f53: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3f56:
	/* 0x3f56: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3f5e:
	/* 0x3f5e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3f67:
	/* 0x3f67: lea    rdx,[r13+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3f6b:
	/* 0x3f6b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f70:
	/* 0x3f70: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3f75:
	/* 0x3f75: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3f7a:
	/* 0x3f7a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f7f:
	/* 0x3f7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f81:
	/* 0x3f81: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f86:
	/* 0x3f86: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_3f88:
	/* 0x3f88: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_3f8b:
	/* 0x3f8b: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_3f91:
	/* 0x3f91: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f94:
	/* 0x3f94: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_3f9a:
	/* 0x3f9a: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_3fa0:
	/* 0x3fa0: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fa5:
	/* 0x3fa5: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_3fa9:
	/* 0x3fa9: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3fb0:
	/* 0x3fb0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3fb5:
	/* 0x3fb5: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3fba:
	/* 0x3fba: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3fc1:
	/* 0x3fc1: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3fc4:
	/* 0x3fc4: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3fcb:
	/* 0x3fcb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3fd0:
	/* 0x3fd0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3fd5:
	/* 0x3fd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fd7:
	/* 0x3fd7: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3fdb:
	/* 0x3fdb: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_3fdd:
	/* 0x3fdd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3fdf:
	/* 0x3fdf: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_3fe5:
	/* 0x3fe5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3fe8:
	/* 0x3fe8: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_3fee:
	/* 0x3fee: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_3ff4:
	/* 0x3ff4: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ff9:
	/* 0x3ff9: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3ffd:
	/* 0x3ffd: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4004:
	/* 0x4004: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4009:
	/* 0x4009: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_400e:
	/* 0x400e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4013:
	/* 0x4013: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_401b:
	/* 0x401b: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_401f:
	/* 0x401f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4026:
	/* 0x4026: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_402b:
	/* 0x402b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_402d:
	/* 0x402d: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4032:
	/* 0x4032: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_403a:
	/* 0x403a: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_403d:
	/* 0x403d: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4045:
	/* 0x4045: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_404e:
	/* 0x404e: lea    rdx,[r13+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4052:
	/* 0x4052: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
	return 16471ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 16471ULL: goto x86_l_4057;
	case 16476ULL: goto x86_l_405c;
	case 16481ULL: goto x86_l_4061;
	case 16486ULL: goto x86_l_4066;
	case 16488ULL: goto x86_l_4068;
	case 16493ULL: goto x86_l_406d;
	case 16495ULL: goto x86_l_406f;
	case 16498ULL: goto x86_l_4072;
	case 16504ULL: goto x86_l_4078;
	case 16507ULL: goto x86_l_407b;
	case 16513ULL: goto x86_l_4081;
	case 16519ULL: goto x86_l_4087;
	case 16524ULL: goto x86_l_408c;
	case 16528ULL: goto x86_l_4090;
	case 16535ULL: goto x86_l_4097;
	case 16540ULL: goto x86_l_409c;
	case 16545ULL: goto x86_l_40a1;
	case 16552ULL: goto x86_l_40a8;
	case 16555ULL: goto x86_l_40ab;
	case 16562ULL: goto x86_l_40b2;
	case 16567ULL: goto x86_l_40b7;
	case 16572ULL: goto x86_l_40bc;
	case 16574ULL: goto x86_l_40be;
	case 16578ULL: goto x86_l_40c2;
	case 16580ULL: goto x86_l_40c4;
	case 16582ULL: goto x86_l_40c6;
	case 16588ULL: goto x86_l_40cc;
	case 16591ULL: goto x86_l_40cf;
	case 16597ULL: goto x86_l_40d5;
	case 16603ULL: goto x86_l_40db;
	case 16608ULL: goto x86_l_40e0;
	case 16612ULL: goto x86_l_40e4;
	case 16619ULL: goto x86_l_40eb;
	case 16624ULL: goto x86_l_40f0;
	case 16629ULL: goto x86_l_40f5;
	case 16634ULL: goto x86_l_40fa;
	case 16642ULL: goto x86_l_4102;
	case 16646ULL: goto x86_l_4106;
	case 16653ULL: goto x86_l_410d;
	case 16658ULL: goto x86_l_4112;
	case 16660ULL: goto x86_l_4114;
	case 16665ULL: goto x86_l_4119;
	case 16673ULL: goto x86_l_4121;
	case 16676ULL: goto x86_l_4124;
	case 16684ULL: goto x86_l_412c;
	case 16693ULL: goto x86_l_4135;
	case 16697ULL: goto x86_l_4139;
	case 16702ULL: goto x86_l_413e;
	case 16707ULL: goto x86_l_4143;
	case 16712ULL: goto x86_l_4148;
	case 16717ULL: goto x86_l_414d;
	case 16719ULL: goto x86_l_414f;
	case 16724ULL: goto x86_l_4154;
	case 16726ULL: goto x86_l_4156;
	case 16729ULL: goto x86_l_4159;
	case 16735ULL: goto x86_l_415f;
	case 16738ULL: goto x86_l_4162;
	case 16744ULL: goto x86_l_4168;
	case 16750ULL: goto x86_l_416e;
	case 16755ULL: goto x86_l_4173;
	case 16759ULL: goto x86_l_4177;
	case 16766ULL: goto x86_l_417e;
	case 16771ULL: goto x86_l_4183;
	case 16776ULL: goto x86_l_4188;
	case 16783ULL: goto x86_l_418f;
	case 16786ULL: goto x86_l_4192;
	case 16793ULL: goto x86_l_4199;
	case 16798ULL: goto x86_l_419e;
	case 16803ULL: goto x86_l_41a3;
	case 16805ULL: goto x86_l_41a5;
	case 16809ULL: goto x86_l_41a9;
	case 16811ULL: goto x86_l_41ab;
	case 16813ULL: goto x86_l_41ad;
	case 16819ULL: goto x86_l_41b3;
	case 16822ULL: goto x86_l_41b6;
	case 16828ULL: goto x86_l_41bc;
	case 16834ULL: goto x86_l_41c2;
	case 16839ULL: goto x86_l_41c7;
	case 16843ULL: goto x86_l_41cb;
	case 16850ULL: goto x86_l_41d2;
	case 16855ULL: goto x86_l_41d7;
	case 16860ULL: goto x86_l_41dc;
	case 16865ULL: goto x86_l_41e1;
	case 16873ULL: goto x86_l_41e9;
	case 16877ULL: goto x86_l_41ed;
	case 16884ULL: goto x86_l_41f4;
	case 16889ULL: goto x86_l_41f9;
	case 16891ULL: goto x86_l_41fb;
	case 16896ULL: goto x86_l_4200;
	case 16904ULL: goto x86_l_4208;
	case 16907ULL: goto x86_l_420b;
	case 16915ULL: goto x86_l_4213;
	case 16924ULL: goto x86_l_421c;
	case 16928ULL: goto x86_l_4220;
	case 16933ULL: goto x86_l_4225;
	case 16938ULL: goto x86_l_422a;
	case 16943ULL: goto x86_l_422f;
	case 16948ULL: goto x86_l_4234;
	case 16950ULL: goto x86_l_4236;
	case 16955ULL: goto x86_l_423b;
	case 16957ULL: goto x86_l_423d;
	case 16960ULL: goto x86_l_4240;
	case 16966ULL: goto x86_l_4246;
	case 16969ULL: goto x86_l_4249;
	case 16975ULL: goto x86_l_424f;
	case 16981ULL: goto x86_l_4255;
	case 16986ULL: goto x86_l_425a;
	case 16990ULL: goto x86_l_425e;
	case 16997ULL: goto x86_l_4265;
	case 17002ULL: goto x86_l_426a;
	case 17007ULL: goto x86_l_426f;
	case 17014ULL: goto x86_l_4276;
	case 17017ULL: goto x86_l_4279;
	case 17024ULL: goto x86_l_4280;
	case 17029ULL: goto x86_l_4285;
	case 17034ULL: goto x86_l_428a;
	case 17036ULL: goto x86_l_428c;
	case 17040ULL: goto x86_l_4290;
	case 17042ULL: goto x86_l_4292;
	case 17044ULL: goto x86_l_4294;
	case 17050ULL: goto x86_l_429a;
	case 17053ULL: goto x86_l_429d;
	case 17059ULL: goto x86_l_42a3;
	case 17065ULL: goto x86_l_42a9;
	case 17070ULL: goto x86_l_42ae;
	case 17074ULL: goto x86_l_42b2;
	case 17081ULL: goto x86_l_42b9;
	case 17086ULL: goto x86_l_42be;
	case 17091ULL: goto x86_l_42c3;
	case 17096ULL: goto x86_l_42c8;
	case 17104ULL: goto x86_l_42d0;
	case 17108ULL: goto x86_l_42d4;
	case 17115ULL: goto x86_l_42db;
	case 17120ULL: goto x86_l_42e0;
	case 17122ULL: goto x86_l_42e2;
	case 17127ULL: goto x86_l_42e7;
	case 17135ULL: goto x86_l_42ef;
	case 17138ULL: goto x86_l_42f2;
	case 17146ULL: goto x86_l_42fa;
	case 17155ULL: goto x86_l_4303;
	case 17162ULL: goto x86_l_430a;
	case 17167ULL: goto x86_l_430f;
	case 17172ULL: goto x86_l_4314;
	case 17177ULL: goto x86_l_4319;
	case 17182ULL: goto x86_l_431e;
	case 17184ULL: goto x86_l_4320;
	case 17189ULL: goto x86_l_4325;
	case 17191ULL: goto x86_l_4327;
	case 17194ULL: goto x86_l_432a;
	case 17200ULL: goto x86_l_4330;
	case 17203ULL: goto x86_l_4333;
	case 17209ULL: goto x86_l_4339;
	case 17215ULL: goto x86_l_433f;
	case 17220ULL: goto x86_l_4344;
	case 17224ULL: goto x86_l_4348;
	case 17231ULL: goto x86_l_434f;
	case 17236ULL: goto x86_l_4354;
	case 17241ULL: goto x86_l_4359;
	case 17248ULL: goto x86_l_4360;
	case 17251ULL: goto x86_l_4363;
	case 17258ULL: goto x86_l_436a;
	case 17263ULL: goto x86_l_436f;
	case 17268ULL: goto x86_l_4374;
	case 17270ULL: goto x86_l_4376;
	case 17274ULL: goto x86_l_437a;
	case 17276ULL: goto x86_l_437c;
	case 17278ULL: goto x86_l_437e;
	case 17284ULL: goto x86_l_4384;
	case 17287ULL: goto x86_l_4387;
	case 17293ULL: goto x86_l_438d;
	case 17299ULL: goto x86_l_4393;
	case 17304ULL: goto x86_l_4398;
	case 17308ULL: goto x86_l_439c;
	case 17315ULL: goto x86_l_43a3;
	case 17320ULL: goto x86_l_43a8;
	case 17325ULL: goto x86_l_43ad;
	case 17330ULL: goto x86_l_43b2;
	case 17338ULL: goto x86_l_43ba;
	case 17342ULL: goto x86_l_43be;
	case 17349ULL: goto x86_l_43c5;
	case 17354ULL: goto x86_l_43ca;
	case 17356ULL: goto x86_l_43cc;
	case 17361ULL: goto x86_l_43d1;
	case 17369ULL: goto x86_l_43d9;
	case 17372ULL: goto x86_l_43dc;
	case 17380ULL: goto x86_l_43e4;
	case 17389ULL: goto x86_l_43ed;
	case 17396ULL: goto x86_l_43f4;
	case 17401ULL: goto x86_l_43f9;
	case 17406ULL: goto x86_l_43fe;
	case 17411ULL: goto x86_l_4403;
	case 17416ULL: goto x86_l_4408;
	case 17418ULL: goto x86_l_440a;
	case 17423ULL: goto x86_l_440f;
	case 17425ULL: goto x86_l_4411;
	case 17428ULL: goto x86_l_4414;
	case 17434ULL: goto x86_l_441a;
	case 17437ULL: goto x86_l_441d;
	case 17443ULL: goto x86_l_4423;
	case 17449ULL: goto x86_l_4429;
	case 17454ULL: goto x86_l_442e;
	case 17458ULL: goto x86_l_4432;
	case 17465ULL: goto x86_l_4439;
	case 17470ULL: goto x86_l_443e;
	case 17475ULL: goto x86_l_4443;
	case 17482ULL: goto x86_l_444a;
	case 17485ULL: goto x86_l_444d;
	case 17492ULL: goto x86_l_4454;
	case 17497ULL: goto x86_l_4459;
	case 17502ULL: goto x86_l_445e;
	case 17504ULL: goto x86_l_4460;
	case 17508ULL: goto x86_l_4464;
	case 17510ULL: goto x86_l_4466;
	case 17512ULL: goto x86_l_4468;
	case 17518ULL: goto x86_l_446e;
	case 17521ULL: goto x86_l_4471;
	case 17527ULL: goto x86_l_4477;
	case 17533ULL: goto x86_l_447d;
	case 17538ULL: goto x86_l_4482;
	case 17542ULL: goto x86_l_4486;
	case 17549ULL: goto x86_l_448d;
	case 17554ULL: goto x86_l_4492;
	case 17559ULL: goto x86_l_4497;
	case 17564ULL: goto x86_l_449c;
	case 17572ULL: goto x86_l_44a4;
	case 17576ULL: goto x86_l_44a8;
	case 17583ULL: goto x86_l_44af;
	case 17588ULL: goto x86_l_44b4;
	case 17590ULL: goto x86_l_44b6;
	case 17595ULL: goto x86_l_44bb;
	case 17603ULL: goto x86_l_44c3;
	case 17606ULL: goto x86_l_44c6;
	case 17614ULL: goto x86_l_44ce;
	case 17623ULL: goto x86_l_44d7;
	case 17630ULL: goto x86_l_44de;
	case 17635ULL: goto x86_l_44e3;
	case 17640ULL: goto x86_l_44e8;
	case 17645ULL: goto x86_l_44ed;
	case 17650ULL: goto x86_l_44f2;
	case 17652ULL: goto x86_l_44f4;
	case 17657ULL: goto x86_l_44f9;
	case 17659ULL: goto x86_l_44fb;
	case 17662ULL: goto x86_l_44fe;
	case 17668ULL: goto x86_l_4504;
	case 17671ULL: goto x86_l_4507;
	case 17677ULL: goto x86_l_450d;
	case 17683ULL: goto x86_l_4513;
	case 17688ULL: goto x86_l_4518;
	case 17692ULL: goto x86_l_451c;
	case 17699ULL: goto x86_l_4523;
	case 17704ULL: goto x86_l_4528;
	case 17709ULL: goto x86_l_452d;
	case 17716ULL: goto x86_l_4534;
	case 17719ULL: goto x86_l_4537;
	case 17726ULL: goto x86_l_453e;
	case 17731ULL: goto x86_l_4543;
	case 17736ULL: goto x86_l_4548;
	case 17738ULL: goto x86_l_454a;
	case 17742ULL: goto x86_l_454e;
	case 17744ULL: goto x86_l_4550;
	case 17746ULL: goto x86_l_4552;
	case 17752ULL: goto x86_l_4558;
	case 17755ULL: goto x86_l_455b;
	case 17761ULL: goto x86_l_4561;
	case 17767ULL: goto x86_l_4567;
	case 17772ULL: goto x86_l_456c;
	case 17776ULL: goto x86_l_4570;
	case 17783ULL: goto x86_l_4577;
	case 17788ULL: goto x86_l_457c;
	case 17793ULL: goto x86_l_4581;
	case 17798ULL: goto x86_l_4586;
	case 17806ULL: goto x86_l_458e;
	case 17810ULL: goto x86_l_4592;
	case 17817ULL: goto x86_l_4599;
	case 17822ULL: goto x86_l_459e;
	case 17824ULL: goto x86_l_45a0;
	case 17829ULL: goto x86_l_45a5;
	case 17837ULL: goto x86_l_45ad;
	case 17840ULL: goto x86_l_45b0;
	case 17848ULL: goto x86_l_45b8;
	case 17857ULL: goto x86_l_45c1;
	case 17864ULL: goto x86_l_45c8;
	case 17869ULL: goto x86_l_45cd;
	case 17874ULL: goto x86_l_45d2;
	case 17879ULL: goto x86_l_45d7;
	case 17884ULL: goto x86_l_45dc;
	case 17886ULL: goto x86_l_45de;
	case 17891ULL: goto x86_l_45e3;
	case 17893ULL: goto x86_l_45e5;
	case 17896ULL: goto x86_l_45e8;
	case 17902ULL: goto x86_l_45ee;
	case 17905ULL: goto x86_l_45f1;
	case 17911ULL: goto x86_l_45f7;
	case 17917ULL: goto x86_l_45fd;
	case 17922ULL: goto x86_l_4602;
	case 17926ULL: goto x86_l_4606;
	case 17933ULL: goto x86_l_460d;
	case 17938ULL: goto x86_l_4612;
	case 17943ULL: goto x86_l_4617;
	case 17950ULL: goto x86_l_461e;
	case 17953ULL: goto x86_l_4621;
	case 17960ULL: goto x86_l_4628;
	case 17965ULL: goto x86_l_462d;
	case 17970ULL: goto x86_l_4632;
	case 17972ULL: goto x86_l_4634;
	case 17976ULL: goto x86_l_4638;
	case 17978ULL: goto x86_l_463a;
	case 17980ULL: goto x86_l_463c;
	case 17986ULL: goto x86_l_4642;
	case 17989ULL: goto x86_l_4645;
	case 17995ULL: goto x86_l_464b;
	case 18001ULL: goto x86_l_4651;
	case 18006ULL: goto x86_l_4656;
	case 18010ULL: goto x86_l_465a;
	case 18017ULL: goto x86_l_4661;
	case 18022ULL: goto x86_l_4666;
	case 18027ULL: goto x86_l_466b;
	case 18032ULL: goto x86_l_4670;
	case 18040ULL: goto x86_l_4678;
	case 18044ULL: goto x86_l_467c;
	case 18051ULL: goto x86_l_4683;
	case 18056ULL: goto x86_l_4688;
	case 18058ULL: goto x86_l_468a;
	case 18063ULL: goto x86_l_468f;
	case 18071ULL: goto x86_l_4697;
	case 18074ULL: goto x86_l_469a;
	case 18082ULL: goto x86_l_46a2;
	case 18091ULL: goto x86_l_46ab;
	case 18098ULL: goto x86_l_46b2;
	case 18103ULL: goto x86_l_46b7;
	case 18108ULL: goto x86_l_46bc;
	case 18113ULL: goto x86_l_46c1;
	case 18118ULL: goto x86_l_46c6;
	case 18120ULL: goto x86_l_46c8;
	case 18125ULL: goto x86_l_46cd;
	case 18127ULL: goto x86_l_46cf;
	case 18130ULL: goto x86_l_46d2;
	case 18136ULL: goto x86_l_46d8;
	case 18139ULL: goto x86_l_46db;
	case 18145ULL: goto x86_l_46e1;
	case 18151ULL: goto x86_l_46e7;
	case 18156ULL: goto x86_l_46ec;
	case 18160ULL: goto x86_l_46f0;
	case 18167ULL: goto x86_l_46f7;
	case 18172ULL: goto x86_l_46fc;
	case 18177ULL: goto x86_l_4701;
	case 18184ULL: goto x86_l_4708;
	case 18187ULL: goto x86_l_470b;
	case 18194ULL: goto x86_l_4712;
	case 18199ULL: goto x86_l_4717;
	case 18204ULL: goto x86_l_471c;
	case 18206ULL: goto x86_l_471e;
	case 18210ULL: goto x86_l_4722;
	case 18212ULL: goto x86_l_4724;
	case 18214ULL: goto x86_l_4726;
	case 18220ULL: goto x86_l_472c;
	case 18223ULL: goto x86_l_472f;
	case 18229ULL: goto x86_l_4735;
	case 18235ULL: goto x86_l_473b;
	case 18240ULL: goto x86_l_4740;
	case 18244ULL: goto x86_l_4744;
	case 18251ULL: goto x86_l_474b;
	case 18256ULL: goto x86_l_4750;
	case 18261ULL: goto x86_l_4755;
	case 18266ULL: goto x86_l_475a;
	case 18274ULL: goto x86_l_4762;
	case 18278ULL: goto x86_l_4766;
	case 18285ULL: goto x86_l_476d;
	case 18290ULL: goto x86_l_4772;
	case 18292ULL: goto x86_l_4774;
	case 18297ULL: goto x86_l_4779;
	case 18305ULL: goto x86_l_4781;
	case 18308ULL: goto x86_l_4784;
	case 18316ULL: goto x86_l_478c;
	case 18325ULL: goto x86_l_4795;
	case 18332ULL: goto x86_l_479c;
	case 18337ULL: goto x86_l_47a1;
	case 18342ULL: goto x86_l_47a6;
	case 18347ULL: goto x86_l_47ab;
	case 18352ULL: goto x86_l_47b0;
	case 18354ULL: goto x86_l_47b2;
	case 18359ULL: goto x86_l_47b7;
	case 18361ULL: goto x86_l_47b9;
	case 18364ULL: goto x86_l_47bc;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4057:
	/* 0x4057: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_405c:
	/* 0x405c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4061:
	/* 0x4061: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4066:
	/* 0x4066: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4068:
	/* 0x4068: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_406d:
	/* 0x406d: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_406f:
	/* 0x406f: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4072:
	/* 0x4072: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_4078:
	/* 0x4078: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_407b:
	/* 0x407b: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4081:
	/* 0x4081: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_4087:
	/* 0x4087: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_408c:
	/* 0x408c: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4090:
	/* 0x4090: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4097:
	/* 0x4097: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_409c:
	/* 0x409c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_40a1:
	/* 0x40a1: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_40a8:
	/* 0x40a8: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_40ab:
	/* 0x40ab: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_40b2:
	/* 0x40b2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40b7:
	/* 0x40b7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_40bc:
	/* 0x40bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40be:
	/* 0x40be: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_40c2:
	/* 0x40c2: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_40c4:
	/* 0x40c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_40c6:
	/* 0x40c6: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_40cc:
	/* 0x40cc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_40cf:
	/* 0x40cf: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_40d5:
	/* 0x40d5: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_40db:
	/* 0x40db: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40e0:
	/* 0x40e0: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_40e4:
	/* 0x40e4: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_40eb:
	/* 0x40eb: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_40f0:
	/* 0x40f0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_40f5:
	/* 0x40f5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_40fa:
	/* 0x40fa: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4102:
	/* 0x4102: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4106:
	/* 0x4106: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_410d:
	/* 0x410d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4112:
	/* 0x4112: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4114:
	/* 0x4114: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4119:
	/* 0x4119: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4121:
	/* 0x4121: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4124:
	/* 0x4124: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_412c:
	/* 0x412c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4135:
	/* 0x4135: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4139:
	/* 0x4139: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_413e:
	/* 0x413e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4143:
	/* 0x4143: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4148:
	/* 0x4148: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_414d:
	/* 0x414d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_414f:
	/* 0x414f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4154:
	/* 0x4154: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_4156:
	/* 0x4156: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4159:
	/* 0x4159: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_415f:
	/* 0x415f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4162:
	/* 0x4162: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4168:
	/* 0x4168: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_416e:
	/* 0x416e: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4173:
	/* 0x4173: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4177:
	/* 0x4177: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_417e:
	/* 0x417e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4183:
	/* 0x4183: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4188:
	/* 0x4188: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_418f:
	/* 0x418f: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4192:
	/* 0x4192: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4199:
	/* 0x4199: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_419e:
	/* 0x419e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_41a3:
	/* 0x41a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41a5:
	/* 0x41a5: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_41a9:
	/* 0x41a9: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_41ab:
	/* 0x41ab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_41ad:
	/* 0x41ad: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_41b3:
	/* 0x41b3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_41b6:
	/* 0x41b6: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_41bc:
	/* 0x41bc: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_41c2:
	/* 0x41c2: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41c7:
	/* 0x41c7: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_41cb:
	/* 0x41cb: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_41d2:
	/* 0x41d2: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_41d7:
	/* 0x41d7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_41dc:
	/* 0x41dc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_41e1:
	/* 0x41e1: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_41e9:
	/* 0x41e9: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_41ed:
	/* 0x41ed: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_41f4:
	/* 0x41f4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_41f9:
	/* 0x41f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41fb:
	/* 0x41fb: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4200:
	/* 0x4200: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4208:
	/* 0x4208: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_420b:
	/* 0x420b: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4213:
	/* 0x4213: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_421c:
	/* 0x421c: lea    rdx,[r13+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4220:
	/* 0x4220: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4225:
	/* 0x4225: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_422a:
	/* 0x422a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_422f:
	/* 0x422f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4234:
	/* 0x4234: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4236:
	/* 0x4236: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_423b:
	/* 0x423b: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_423d:
	/* 0x423d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4240:
	/* 0x4240: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_4246:
	/* 0x4246: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4249:
	/* 0x4249: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_424f:
	/* 0x424f: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_4255:
	/* 0x4255: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_425a:
	/* 0x425a: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_425e:
	/* 0x425e: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4265:
	/* 0x4265: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_426a:
	/* 0x426a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_426f:
	/* 0x426f: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4276:
	/* 0x4276: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4279:
	/* 0x4279: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4280:
	/* 0x4280: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4285:
	/* 0x4285: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_428a:
	/* 0x428a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_428c:
	/* 0x428c: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4290:
	/* 0x4290: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_4292:
	/* 0x4292: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4294:
	/* 0x4294: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_429a:
	/* 0x429a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_429d:
	/* 0x429d: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_42a3:
	/* 0x42a3: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_42a9:
	/* 0x42a9: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42ae:
	/* 0x42ae: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_42b2:
	/* 0x42b2: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_42b9:
	/* 0x42b9: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_42be:
	/* 0x42be: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_42c3:
	/* 0x42c3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_42c8:
	/* 0x42c8: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_42d0:
	/* 0x42d0: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_42d4:
	/* 0x42d4: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_42db:
	/* 0x42db: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_42e0:
	/* 0x42e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42e2:
	/* 0x42e2: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_42e7:
	/* 0x42e7: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_42ef:
	/* 0x42ef: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_42f2:
	/* 0x42f2: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_42fa:
	/* 0x42fa: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4303:
	/* 0x4303: lea    rdx,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_430a:
	/* 0x430a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_430f:
	/* 0x430f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4314:
	/* 0x4314: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4319:
	/* 0x4319: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_431e:
	/* 0x431e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4320:
	/* 0x4320: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4325:
	/* 0x4325: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_4327:
	/* 0x4327: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_432a:
	/* 0x432a: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_4330:
	/* 0x4330: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4333:
	/* 0x4333: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4339:
	/* 0x4339: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_433f:
	/* 0x433f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4344:
	/* 0x4344: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4348:
	/* 0x4348: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_434f:
	/* 0x434f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4354:
	/* 0x4354: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4359:
	/* 0x4359: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4360:
	/* 0x4360: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4363:
	/* 0x4363: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_436a:
	/* 0x436a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_436f:
	/* 0x436f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4374:
	/* 0x4374: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4376:
	/* 0x4376: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_437a:
	/* 0x437a: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_437c:
	/* 0x437c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_437e:
	/* 0x437e: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_4384:
	/* 0x4384: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4387:
	/* 0x4387: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_438d:
	/* 0x438d: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_4393:
	/* 0x4393: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4398:
	/* 0x4398: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_439c:
	/* 0x439c: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_43a3:
	/* 0x43a3: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_43a8:
	/* 0x43a8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_43ad:
	/* 0x43ad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_43b2:
	/* 0x43b2: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_43ba:
	/* 0x43ba: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_43be:
	/* 0x43be: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_43c5:
	/* 0x43c5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_43ca:
	/* 0x43ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43cc:
	/* 0x43cc: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_43d1:
	/* 0x43d1: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_43d9:
	/* 0x43d9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_43dc:
	/* 0x43dc: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_43e4:
	/* 0x43e4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_43ed:
	/* 0x43ed: lea    rdx,[r13+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_43f4:
	/* 0x43f4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_43f9:
	/* 0x43f9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_43fe:
	/* 0x43fe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4403:
	/* 0x4403: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4408:
	/* 0x4408: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_440a:
	/* 0x440a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_440f:
	/* 0x440f: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_4411:
	/* 0x4411: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4414:
	/* 0x4414: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_441a:
	/* 0x441a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_441d:
	/* 0x441d: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4423:
	/* 0x4423: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_4429:
	/* 0x4429: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_442e:
	/* 0x442e: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4432:
	/* 0x4432: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4439:
	/* 0x4439: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_443e:
	/* 0x443e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4443:
	/* 0x4443: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_444a:
	/* 0x444a: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_444d:
	/* 0x444d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4454:
	/* 0x4454: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4459:
	/* 0x4459: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_445e:
	/* 0x445e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4460:
	/* 0x4460: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4464:
	/* 0x4464: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_4466:
	/* 0x4466: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4468:
	/* 0x4468: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_446e:
	/* 0x446e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4471:
	/* 0x4471: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4477:
	/* 0x4477: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_447d:
	/* 0x447d: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4482:
	/* 0x4482: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4486:
	/* 0x4486: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_448d:
	/* 0x448d: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4492:
	/* 0x4492: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4497:
	/* 0x4497: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_449c:
	/* 0x449c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_44a4:
	/* 0x44a4: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_44a8:
	/* 0x44a8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_44af:
	/* 0x44af: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_44b4:
	/* 0x44b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44b6:
	/* 0x44b6: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_44bb:
	/* 0x44bb: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_44c3:
	/* 0x44c3: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_44c6:
	/* 0x44c6: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_44ce:
	/* 0x44ce: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_44d7:
	/* 0x44d7: lea    rdx,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_44de:
	/* 0x44de: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44e3:
	/* 0x44e3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_44e8:
	/* 0x44e8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_44ed:
	/* 0x44ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44f2:
	/* 0x44f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44f4:
	/* 0x44f4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44f9:
	/* 0x44f9: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_44fb:
	/* 0x44fb: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_44fe:
	/* 0x44fe: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_4504:
	/* 0x4504: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4507:
	/* 0x4507: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_450d:
	/* 0x450d: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_4513:
	/* 0x4513: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4518:
	/* 0x4518: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_451c:
	/* 0x451c: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4523:
	/* 0x4523: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4528:
	/* 0x4528: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_452d:
	/* 0x452d: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4534:
	/* 0x4534: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4537:
	/* 0x4537: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_453e:
	/* 0x453e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4543:
	/* 0x4543: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4548:
	/* 0x4548: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_454a:
	/* 0x454a: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_454e:
	/* 0x454e: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_4550:
	/* 0x4550: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4552:
	/* 0x4552: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_4558:
	/* 0x4558: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_455b:
	/* 0x455b: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4561:
	/* 0x4561: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_4567:
	/* 0x4567: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_456c:
	/* 0x456c: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4570:
	/* 0x4570: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4577:
	/* 0x4577: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_457c:
	/* 0x457c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4581:
	/* 0x4581: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4586:
	/* 0x4586: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_458e:
	/* 0x458e: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4592:
	/* 0x4592: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4599:
	/* 0x4599: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_459e:
	/* 0x459e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45a0:
	/* 0x45a0: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_45a5:
	/* 0x45a5: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_45ad:
	/* 0x45ad: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_45b0:
	/* 0x45b0: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_45b8:
	/* 0x45b8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_45c1:
	/* 0x45c1: lea    rdx,[r13+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_45c8:
	/* 0x45c8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45cd:
	/* 0x45cd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_45d2:
	/* 0x45d2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_45d7:
	/* 0x45d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45dc:
	/* 0x45dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45de:
	/* 0x45de: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45e3:
	/* 0x45e3: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_45e5:
	/* 0x45e5: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_45e8:
	/* 0x45e8: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_45ee:
	/* 0x45ee: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_45f1:
	/* 0x45f1: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_45f7:
	/* 0x45f7: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_45fd:
	/* 0x45fd: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4602:
	/* 0x4602: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4606:
	/* 0x4606: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_460d:
	/* 0x460d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4612:
	/* 0x4612: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4617:
	/* 0x4617: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_461e:
	/* 0x461e: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4621:
	/* 0x4621: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4628:
	/* 0x4628: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_462d:
	/* 0x462d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4632:
	/* 0x4632: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4634:
	/* 0x4634: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4638:
	/* 0x4638: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_463a:
	/* 0x463a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_463c:
	/* 0x463c: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_4642:
	/* 0x4642: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4645:
	/* 0x4645: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_464b:
	/* 0x464b: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_4651:
	/* 0x4651: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4656:
	/* 0x4656: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_465a:
	/* 0x465a: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4661:
	/* 0x4661: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4666:
	/* 0x4666: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_466b:
	/* 0x466b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4670:
	/* 0x4670: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4678:
	/* 0x4678: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_467c:
	/* 0x467c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4683:
	/* 0x4683: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4688:
	/* 0x4688: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_468a:
	/* 0x468a: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_468f:
	/* 0x468f: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4697:
	/* 0x4697: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_469a:
	/* 0x469a: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_46a2:
	/* 0x46a2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_46ab:
	/* 0x46ab: lea    rdx,[r13+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_46b2:
	/* 0x46b2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46b7:
	/* 0x46b7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_46bc:
	/* 0x46bc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_46c1:
	/* 0x46c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46c6:
	/* 0x46c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46c8:
	/* 0x46c8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46cd:
	/* 0x46cd: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_46cf:
	/* 0x46cf: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_46d2:
	/* 0x46d2: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_46d8:
	/* 0x46d8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_46db:
	/* 0x46db: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_46e1:
	/* 0x46e1: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_46e7:
	/* 0x46e7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46ec:
	/* 0x46ec: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_46f0:
	/* 0x46f0: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_46f7:
	/* 0x46f7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_46fc:
	/* 0x46fc: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4701:
	/* 0x4701: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4708:
	/* 0x4708: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_470b:
	/* 0x470b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4712:
	/* 0x4712: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4717:
	/* 0x4717: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_471c:
	/* 0x471c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_471e:
	/* 0x471e: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4722:
	/* 0x4722: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_4724:
	/* 0x4724: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4726:
	/* 0x4726: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_472c:
	/* 0x472c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_472f:
	/* 0x472f: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4735:
	/* 0x4735: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_473b:
	/* 0x473b: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4740:
	/* 0x4740: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4744:
	/* 0x4744: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_474b:
	/* 0x474b: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4750:
	/* 0x4750: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4755:
	/* 0x4755: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_475a:
	/* 0x475a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4762:
	/* 0x4762: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4766:
	/* 0x4766: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_476d:
	/* 0x476d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4772:
	/* 0x4772: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4774:
	/* 0x4774: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4779:
	/* 0x4779: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4781:
	/* 0x4781: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4784:
	/* 0x4784: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_478c:
	/* 0x478c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4795:
	/* 0x4795: lea    rdx,[r13+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_479c:
	/* 0x479c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47a1:
	/* 0x47a1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_47a6:
	/* 0x47a6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_47ab:
	/* 0x47ab: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47b0:
	/* 0x47b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47b2:
	/* 0x47b2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47b7:
	/* 0x47b7: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_47b9:
	/* 0x47b9: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_47bc:
	/* 0x47bc: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
	return 18370ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 18370ULL: goto x86_l_47c2;
	case 18373ULL: goto x86_l_47c5;
	case 18379ULL: goto x86_l_47cb;
	case 18385ULL: goto x86_l_47d1;
	case 18390ULL: goto x86_l_47d6;
	case 18394ULL: goto x86_l_47da;
	case 18401ULL: goto x86_l_47e1;
	case 18406ULL: goto x86_l_47e6;
	case 18411ULL: goto x86_l_47eb;
	case 18418ULL: goto x86_l_47f2;
	case 18421ULL: goto x86_l_47f5;
	case 18428ULL: goto x86_l_47fc;
	case 18433ULL: goto x86_l_4801;
	case 18438ULL: goto x86_l_4806;
	case 18440ULL: goto x86_l_4808;
	case 18444ULL: goto x86_l_480c;
	case 18446ULL: goto x86_l_480e;
	case 18448ULL: goto x86_l_4810;
	case 18454ULL: goto x86_l_4816;
	case 18457ULL: goto x86_l_4819;
	case 18463ULL: goto x86_l_481f;
	case 18469ULL: goto x86_l_4825;
	case 18474ULL: goto x86_l_482a;
	case 18478ULL: goto x86_l_482e;
	case 18485ULL: goto x86_l_4835;
	case 18490ULL: goto x86_l_483a;
	case 18495ULL: goto x86_l_483f;
	case 18500ULL: goto x86_l_4844;
	case 18508ULL: goto x86_l_484c;
	case 18512ULL: goto x86_l_4850;
	case 18519ULL: goto x86_l_4857;
	case 18524ULL: goto x86_l_485c;
	case 18526ULL: goto x86_l_485e;
	case 18531ULL: goto x86_l_4863;
	case 18539ULL: goto x86_l_486b;
	case 18542ULL: goto x86_l_486e;
	case 18550ULL: goto x86_l_4876;
	case 18559ULL: goto x86_l_487f;
	case 18566ULL: goto x86_l_4886;
	case 18571ULL: goto x86_l_488b;
	case 18576ULL: goto x86_l_4890;
	case 18581ULL: goto x86_l_4895;
	case 18586ULL: goto x86_l_489a;
	case 18588ULL: goto x86_l_489c;
	case 18593ULL: goto x86_l_48a1;
	case 18595ULL: goto x86_l_48a3;
	case 18598ULL: goto x86_l_48a6;
	case 18604ULL: goto x86_l_48ac;
	case 18607ULL: goto x86_l_48af;
	case 18613ULL: goto x86_l_48b5;
	case 18619ULL: goto x86_l_48bb;
	case 18624ULL: goto x86_l_48c0;
	case 18628ULL: goto x86_l_48c4;
	case 18635ULL: goto x86_l_48cb;
	case 18640ULL: goto x86_l_48d0;
	case 18645ULL: goto x86_l_48d5;
	case 18652ULL: goto x86_l_48dc;
	case 18655ULL: goto x86_l_48df;
	case 18662ULL: goto x86_l_48e6;
	case 18667ULL: goto x86_l_48eb;
	case 18672ULL: goto x86_l_48f0;
	case 18674ULL: goto x86_l_48f2;
	case 18678ULL: goto x86_l_48f6;
	case 18680ULL: goto x86_l_48f8;
	case 18682ULL: goto x86_l_48fa;
	case 18688ULL: goto x86_l_4900;
	case 18691ULL: goto x86_l_4903;
	case 18697ULL: goto x86_l_4909;
	case 18703ULL: goto x86_l_490f;
	case 18708ULL: goto x86_l_4914;
	case 18712ULL: goto x86_l_4918;
	case 18719ULL: goto x86_l_491f;
	case 18724ULL: goto x86_l_4924;
	case 18729ULL: goto x86_l_4929;
	case 18734ULL: goto x86_l_492e;
	case 18742ULL: goto x86_l_4936;
	case 18746ULL: goto x86_l_493a;
	case 18753ULL: goto x86_l_4941;
	case 18758ULL: goto x86_l_4946;
	case 18760ULL: goto x86_l_4948;
	case 18765ULL: goto x86_l_494d;
	case 18773ULL: goto x86_l_4955;
	case 18776ULL: goto x86_l_4958;
	case 18784ULL: goto x86_l_4960;
	case 18793ULL: goto x86_l_4969;
	case 18800ULL: goto x86_l_4970;
	case 18805ULL: goto x86_l_4975;
	case 18810ULL: goto x86_l_497a;
	case 18815ULL: goto x86_l_497f;
	case 18820ULL: goto x86_l_4984;
	case 18822ULL: goto x86_l_4986;
	case 18827ULL: goto x86_l_498b;
	case 18829ULL: goto x86_l_498d;
	case 18832ULL: goto x86_l_4990;
	case 18838ULL: goto x86_l_4996;
	case 18841ULL: goto x86_l_4999;
	case 18847ULL: goto x86_l_499f;
	case 18853ULL: goto x86_l_49a5;
	case 18858ULL: goto x86_l_49aa;
	case 18862ULL: goto x86_l_49ae;
	case 18869ULL: goto x86_l_49b5;
	case 18874ULL: goto x86_l_49ba;
	case 18879ULL: goto x86_l_49bf;
	case 18886ULL: goto x86_l_49c6;
	case 18889ULL: goto x86_l_49c9;
	case 18896ULL: goto x86_l_49d0;
	case 18901ULL: goto x86_l_49d5;
	case 18906ULL: goto x86_l_49da;
	case 18908ULL: goto x86_l_49dc;
	case 18912ULL: goto x86_l_49e0;
	case 18914ULL: goto x86_l_49e2;
	case 18916ULL: goto x86_l_49e4;
	case 18922ULL: goto x86_l_49ea;
	case 18925ULL: goto x86_l_49ed;
	case 18931ULL: goto x86_l_49f3;
	case 18937ULL: goto x86_l_49f9;
	case 18942ULL: goto x86_l_49fe;
	case 18946ULL: goto x86_l_4a02;
	case 18953ULL: goto x86_l_4a09;
	case 18958ULL: goto x86_l_4a0e;
	case 18963ULL: goto x86_l_4a13;
	case 18968ULL: goto x86_l_4a18;
	case 18976ULL: goto x86_l_4a20;
	case 18980ULL: goto x86_l_4a24;
	case 18987ULL: goto x86_l_4a2b;
	case 18992ULL: goto x86_l_4a30;
	case 18994ULL: goto x86_l_4a32;
	case 18999ULL: goto x86_l_4a37;
	case 19007ULL: goto x86_l_4a3f;
	case 19010ULL: goto x86_l_4a42;
	case 19018ULL: goto x86_l_4a4a;
	case 19027ULL: goto x86_l_4a53;
	case 19034ULL: goto x86_l_4a5a;
	case 19039ULL: goto x86_l_4a5f;
	case 19044ULL: goto x86_l_4a64;
	case 19049ULL: goto x86_l_4a69;
	case 19054ULL: goto x86_l_4a6e;
	case 19056ULL: goto x86_l_4a70;
	case 19061ULL: goto x86_l_4a75;
	case 19063ULL: goto x86_l_4a77;
	case 19066ULL: goto x86_l_4a7a;
	case 19072ULL: goto x86_l_4a80;
	case 19075ULL: goto x86_l_4a83;
	case 19081ULL: goto x86_l_4a89;
	case 19087ULL: goto x86_l_4a8f;
	case 19092ULL: goto x86_l_4a94;
	case 19096ULL: goto x86_l_4a98;
	case 19103ULL: goto x86_l_4a9f;
	case 19108ULL: goto x86_l_4aa4;
	case 19113ULL: goto x86_l_4aa9;
	case 19120ULL: goto x86_l_4ab0;
	case 19123ULL: goto x86_l_4ab3;
	case 19130ULL: goto x86_l_4aba;
	case 19135ULL: goto x86_l_4abf;
	case 19140ULL: goto x86_l_4ac4;
	case 19142ULL: goto x86_l_4ac6;
	case 19146ULL: goto x86_l_4aca;
	case 19148ULL: goto x86_l_4acc;
	case 19150ULL: goto x86_l_4ace;
	case 19156ULL: goto x86_l_4ad4;
	case 19159ULL: goto x86_l_4ad7;
	case 19165ULL: goto x86_l_4add;
	case 19171ULL: goto x86_l_4ae3;
	case 19176ULL: goto x86_l_4ae8;
	case 19180ULL: goto x86_l_4aec;
	case 19187ULL: goto x86_l_4af3;
	case 19192ULL: goto x86_l_4af8;
	case 19197ULL: goto x86_l_4afd;
	case 19202ULL: goto x86_l_4b02;
	case 19210ULL: goto x86_l_4b0a;
	case 19214ULL: goto x86_l_4b0e;
	case 19221ULL: goto x86_l_4b15;
	case 19226ULL: goto x86_l_4b1a;
	case 19228ULL: goto x86_l_4b1c;
	case 19233ULL: goto x86_l_4b21;
	case 19241ULL: goto x86_l_4b29;
	case 19244ULL: goto x86_l_4b2c;
	case 19252ULL: goto x86_l_4b34;
	case 19261ULL: goto x86_l_4b3d;
	case 19268ULL: goto x86_l_4b44;
	case 19273ULL: goto x86_l_4b49;
	case 19278ULL: goto x86_l_4b4e;
	case 19283ULL: goto x86_l_4b53;
	case 19288ULL: goto x86_l_4b58;
	case 19290ULL: goto x86_l_4b5a;
	case 19295ULL: goto x86_l_4b5f;
	case 19297ULL: goto x86_l_4b61;
	case 19300ULL: goto x86_l_4b64;
	case 19306ULL: goto x86_l_4b6a;
	case 19309ULL: goto x86_l_4b6d;
	case 19315ULL: goto x86_l_4b73;
	case 19321ULL: goto x86_l_4b79;
	case 19326ULL: goto x86_l_4b7e;
	case 19330ULL: goto x86_l_4b82;
	case 19337ULL: goto x86_l_4b89;
	case 19342ULL: goto x86_l_4b8e;
	case 19347ULL: goto x86_l_4b93;
	case 19354ULL: goto x86_l_4b9a;
	case 19357ULL: goto x86_l_4b9d;
	case 19364ULL: goto x86_l_4ba4;
	case 19369ULL: goto x86_l_4ba9;
	case 19374ULL: goto x86_l_4bae;
	case 19376ULL: goto x86_l_4bb0;
	case 19380ULL: goto x86_l_4bb4;
	case 19382ULL: goto x86_l_4bb6;
	case 19384ULL: goto x86_l_4bb8;
	case 19390ULL: goto x86_l_4bbe;
	case 19393ULL: goto x86_l_4bc1;
	case 19399ULL: goto x86_l_4bc7;
	case 19405ULL: goto x86_l_4bcd;
	case 19410ULL: goto x86_l_4bd2;
	case 19414ULL: goto x86_l_4bd6;
	case 19421ULL: goto x86_l_4bdd;
	case 19426ULL: goto x86_l_4be2;
	case 19431ULL: goto x86_l_4be7;
	case 19436ULL: goto x86_l_4bec;
	case 19444ULL: goto x86_l_4bf4;
	case 19448ULL: goto x86_l_4bf8;
	case 19455ULL: goto x86_l_4bff;
	case 19460ULL: goto x86_l_4c04;
	case 19462ULL: goto x86_l_4c06;
	case 19467ULL: goto x86_l_4c0b;
	case 19475ULL: goto x86_l_4c13;
	case 19478ULL: goto x86_l_4c16;
	case 19486ULL: goto x86_l_4c1e;
	case 19495ULL: goto x86_l_4c27;
	case 19502ULL: goto x86_l_4c2e;
	case 19507ULL: goto x86_l_4c33;
	case 19512ULL: goto x86_l_4c38;
	case 19517ULL: goto x86_l_4c3d;
	case 19522ULL: goto x86_l_4c42;
	case 19524ULL: goto x86_l_4c44;
	case 19529ULL: goto x86_l_4c49;
	case 19531ULL: goto x86_l_4c4b;
	case 19534ULL: goto x86_l_4c4e;
	case 19540ULL: goto x86_l_4c54;
	case 19543ULL: goto x86_l_4c57;
	case 19549ULL: goto x86_l_4c5d;
	case 19555ULL: goto x86_l_4c63;
	case 19560ULL: goto x86_l_4c68;
	case 19564ULL: goto x86_l_4c6c;
	case 19571ULL: goto x86_l_4c73;
	case 19576ULL: goto x86_l_4c78;
	case 19581ULL: goto x86_l_4c7d;
	case 19588ULL: goto x86_l_4c84;
	case 19591ULL: goto x86_l_4c87;
	case 19598ULL: goto x86_l_4c8e;
	case 19603ULL: goto x86_l_4c93;
	case 19608ULL: goto x86_l_4c98;
	case 19610ULL: goto x86_l_4c9a;
	case 19614ULL: goto x86_l_4c9e;
	case 19616ULL: goto x86_l_4ca0;
	case 19618ULL: goto x86_l_4ca2;
	case 19624ULL: goto x86_l_4ca8;
	case 19627ULL: goto x86_l_4cab;
	case 19633ULL: goto x86_l_4cb1;
	case 19639ULL: goto x86_l_4cb7;
	case 19644ULL: goto x86_l_4cbc;
	case 19648ULL: goto x86_l_4cc0;
	case 19655ULL: goto x86_l_4cc7;
	case 19660ULL: goto x86_l_4ccc;
	case 19665ULL: goto x86_l_4cd1;
	case 19670ULL: goto x86_l_4cd6;
	case 19678ULL: goto x86_l_4cde;
	case 19682ULL: goto x86_l_4ce2;
	case 19689ULL: goto x86_l_4ce9;
	case 19694ULL: goto x86_l_4cee;
	case 19696ULL: goto x86_l_4cf0;
	case 19701ULL: goto x86_l_4cf5;
	case 19709ULL: goto x86_l_4cfd;
	case 19712ULL: goto x86_l_4d00;
	case 19720ULL: goto x86_l_4d08;
	case 19729ULL: goto x86_l_4d11;
	case 19736ULL: goto x86_l_4d18;
	case 19741ULL: goto x86_l_4d1d;
	case 19746ULL: goto x86_l_4d22;
	case 19751ULL: goto x86_l_4d27;
	case 19756ULL: goto x86_l_4d2c;
	case 19758ULL: goto x86_l_4d2e;
	case 19763ULL: goto x86_l_4d33;
	case 19765ULL: goto x86_l_4d35;
	case 19768ULL: goto x86_l_4d38;
	case 19774ULL: goto x86_l_4d3e;
	case 19777ULL: goto x86_l_4d41;
	case 19783ULL: goto x86_l_4d47;
	case 19789ULL: goto x86_l_4d4d;
	case 19794ULL: goto x86_l_4d52;
	case 19798ULL: goto x86_l_4d56;
	case 19805ULL: goto x86_l_4d5d;
	case 19810ULL: goto x86_l_4d62;
	case 19815ULL: goto x86_l_4d67;
	case 19822ULL: goto x86_l_4d6e;
	case 19825ULL: goto x86_l_4d71;
	case 19832ULL: goto x86_l_4d78;
	case 19837ULL: goto x86_l_4d7d;
	case 19842ULL: goto x86_l_4d82;
	case 19844ULL: goto x86_l_4d84;
	case 19848ULL: goto x86_l_4d88;
	case 19850ULL: goto x86_l_4d8a;
	case 19852ULL: goto x86_l_4d8c;
	case 19858ULL: goto x86_l_4d92;
	case 19861ULL: goto x86_l_4d95;
	case 19867ULL: goto x86_l_4d9b;
	case 19873ULL: goto x86_l_4da1;
	case 19878ULL: goto x86_l_4da6;
	case 19882ULL: goto x86_l_4daa;
	case 19889ULL: goto x86_l_4db1;
	case 19894ULL: goto x86_l_4db6;
	case 19899ULL: goto x86_l_4dbb;
	case 19904ULL: goto x86_l_4dc0;
	case 19912ULL: goto x86_l_4dc8;
	case 19916ULL: goto x86_l_4dcc;
	case 19923ULL: goto x86_l_4dd3;
	case 19928ULL: goto x86_l_4dd8;
	case 19930ULL: goto x86_l_4dda;
	case 19935ULL: goto x86_l_4ddf;
	case 19943ULL: goto x86_l_4de7;
	case 19946ULL: goto x86_l_4dea;
	case 19954ULL: goto x86_l_4df2;
	case 19963ULL: goto x86_l_4dfb;
	case 19970ULL: goto x86_l_4e02;
	case 19975ULL: goto x86_l_4e07;
	case 19980ULL: goto x86_l_4e0c;
	case 19985ULL: goto x86_l_4e11;
	case 19990ULL: goto x86_l_4e16;
	case 19992ULL: goto x86_l_4e18;
	case 19997ULL: goto x86_l_4e1d;
	case 19999ULL: goto x86_l_4e1f;
	case 20002ULL: goto x86_l_4e22;
	case 20008ULL: goto x86_l_4e28;
	case 20011ULL: goto x86_l_4e2b;
	case 20017ULL: goto x86_l_4e31;
	case 20023ULL: goto x86_l_4e37;
	case 20028ULL: goto x86_l_4e3c;
	case 20032ULL: goto x86_l_4e40;
	case 20039ULL: goto x86_l_4e47;
	case 20044ULL: goto x86_l_4e4c;
	case 20049ULL: goto x86_l_4e51;
	case 20056ULL: goto x86_l_4e58;
	case 20059ULL: goto x86_l_4e5b;
	case 20066ULL: goto x86_l_4e62;
	case 20071ULL: goto x86_l_4e67;
	case 20076ULL: goto x86_l_4e6c;
	case 20078ULL: goto x86_l_4e6e;
	case 20082ULL: goto x86_l_4e72;
	case 20084ULL: goto x86_l_4e74;
	case 20086ULL: goto x86_l_4e76;
	case 20092ULL: goto x86_l_4e7c;
	case 20095ULL: goto x86_l_4e7f;
	case 20101ULL: goto x86_l_4e85;
	case 20107ULL: goto x86_l_4e8b;
	case 20112ULL: goto x86_l_4e90;
	case 20116ULL: goto x86_l_4e94;
	case 20123ULL: goto x86_l_4e9b;
	case 20128ULL: goto x86_l_4ea0;
	case 20133ULL: goto x86_l_4ea5;
	case 20138ULL: goto x86_l_4eaa;
	case 20146ULL: goto x86_l_4eb2;
	case 20150ULL: goto x86_l_4eb6;
	case 20157ULL: goto x86_l_4ebd;
	case 20162ULL: goto x86_l_4ec2;
	case 20164ULL: goto x86_l_4ec4;
	case 20169ULL: goto x86_l_4ec9;
	case 20177ULL: goto x86_l_4ed1;
	case 20180ULL: goto x86_l_4ed4;
	case 20188ULL: goto x86_l_4edc;
	case 20197ULL: goto x86_l_4ee5;
	case 20204ULL: goto x86_l_4eec;
	case 20209ULL: goto x86_l_4ef1;
	case 20214ULL: goto x86_l_4ef6;
	case 20219ULL: goto x86_l_4efb;
	case 20224ULL: goto x86_l_4f00;
	case 20226ULL: goto x86_l_4f02;
	case 20231ULL: goto x86_l_4f07;
	case 20233ULL: goto x86_l_4f09;
	case 20236ULL: goto x86_l_4f0c;
	case 20242ULL: goto x86_l_4f12;
	case 20245ULL: goto x86_l_4f15;
	case 20251ULL: goto x86_l_4f1b;
	case 20257ULL: goto x86_l_4f21;
	case 20262ULL: goto x86_l_4f26;
	case 20266ULL: goto x86_l_4f2a;
	case 20273ULL: goto x86_l_4f31;
	case 20278ULL: goto x86_l_4f36;
	default: return 0xffffffffffffffffULL;
	}
x86_l_47c2:
	/* 0x47c2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_47c5:
	/* 0x47c5: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_47cb:
	/* 0x47cb: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_47d1:
	/* 0x47d1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47d6:
	/* 0x47d6: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_47da:
	/* 0x47da: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_47e1:
	/* 0x47e1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_47e6:
	/* 0x47e6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_47eb:
	/* 0x47eb: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_47f2:
	/* 0x47f2: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_47f5:
	/* 0x47f5: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_47fc:
	/* 0x47fc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4801:
	/* 0x4801: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4806:
	/* 0x4806: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4808:
	/* 0x4808: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_480c:
	/* 0x480c: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_480e:
	/* 0x480e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4810:
	/* 0x4810: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_4816:
	/* 0x4816: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4819:
	/* 0x4819: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_481f:
	/* 0x481f: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_4825:
	/* 0x4825: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_482a:
	/* 0x482a: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_482e:
	/* 0x482e: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4835:
	/* 0x4835: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_483a:
	/* 0x483a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_483f:
	/* 0x483f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4844:
	/* 0x4844: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_484c:
	/* 0x484c: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4850:
	/* 0x4850: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4857:
	/* 0x4857: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_485c:
	/* 0x485c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_485e:
	/* 0x485e: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4863:
	/* 0x4863: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_486b:
	/* 0x486b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_486e:
	/* 0x486e: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4876:
	/* 0x4876: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_487f:
	/* 0x487f: lea    rdx,[r13+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_4886:
	/* 0x4886: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_488b:
	/* 0x488b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4890:
	/* 0x4890: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4895:
	/* 0x4895: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_489a:
	/* 0x489a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_489c:
	/* 0x489c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48a1:
	/* 0x48a1: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_48a3:
	/* 0x48a3: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_48a6:
	/* 0x48a6: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_48ac:
	/* 0x48ac: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_48af:
	/* 0x48af: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_48b5:
	/* 0x48b5: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_48bb:
	/* 0x48bb: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48c0:
	/* 0x48c0: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_48c4:
	/* 0x48c4: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_48cb:
	/* 0x48cb: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_48d0:
	/* 0x48d0: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_48d5:
	/* 0x48d5: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_48dc:
	/* 0x48dc: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_48df:
	/* 0x48df: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_48e6:
	/* 0x48e6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48eb:
	/* 0x48eb: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_48f0:
	/* 0x48f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48f2:
	/* 0x48f2: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_48f6:
	/* 0x48f6: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_48f8:
	/* 0x48f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_48fa:
	/* 0x48fa: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_4900:
	/* 0x4900: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4903:
	/* 0x4903: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4909:
	/* 0x4909: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_490f:
	/* 0x490f: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4914:
	/* 0x4914: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4918:
	/* 0x4918: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_491f:
	/* 0x491f: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4924:
	/* 0x4924: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4929:
	/* 0x4929: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_492e:
	/* 0x492e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4936:
	/* 0x4936: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_493a:
	/* 0x493a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4941:
	/* 0x4941: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4946:
	/* 0x4946: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4948:
	/* 0x4948: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_494d:
	/* 0x494d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4955:
	/* 0x4955: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4958:
	/* 0x4958: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4960:
	/* 0x4960: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4969:
	/* 0x4969: lea    rdx,[r13+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_4970:
	/* 0x4970: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4975:
	/* 0x4975: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_497a:
	/* 0x497a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_497f:
	/* 0x497f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4984:
	/* 0x4984: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4986:
	/* 0x4986: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_498b:
	/* 0x498b: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_498d:
	/* 0x498d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4990:
	/* 0x4990: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_4996:
	/* 0x4996: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4999:
	/* 0x4999: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_499f:
	/* 0x499f: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_49a5:
	/* 0x49a5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49aa:
	/* 0x49aa: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_49ae:
	/* 0x49ae: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_49b5:
	/* 0x49b5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_49ba:
	/* 0x49ba: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_49bf:
	/* 0x49bf: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_49c6:
	/* 0x49c6: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_49c9:
	/* 0x49c9: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_49d0:
	/* 0x49d0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_49d5:
	/* 0x49d5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_49da:
	/* 0x49da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49dc:
	/* 0x49dc: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_49e0:
	/* 0x49e0: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_49e2:
	/* 0x49e2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_49e4:
	/* 0x49e4: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_49ea:
	/* 0x49ea: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_49ed:
	/* 0x49ed: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_49f3:
	/* 0x49f3: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_49f9:
	/* 0x49f9: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49fe:
	/* 0x49fe: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4a02:
	/* 0x4a02: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4a09:
	/* 0x4a09: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4a0e:
	/* 0x4a0e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4a13:
	/* 0x4a13: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4a18:
	/* 0x4a18: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4a20:
	/* 0x4a20: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4a24:
	/* 0x4a24: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4a2b:
	/* 0x4a2b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4a30:
	/* 0x4a30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a32:
	/* 0x4a32: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4a37:
	/* 0x4a37: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4a3f:
	/* 0x4a3f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4a42:
	/* 0x4a42: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4a4a:
	/* 0x4a4a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4a53:
	/* 0x4a53: lea    rdx,[r13+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_4a5a:
	/* 0x4a5a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a5f:
	/* 0x4a5f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4a64:
	/* 0x4a64: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4a69:
	/* 0x4a69: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a6e:
	/* 0x4a6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a70:
	/* 0x4a70: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a75:
	/* 0x4a75: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_4a77:
	/* 0x4a77: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4a7a:
	/* 0x4a7a: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_4a80:
	/* 0x4a80: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4a83:
	/* 0x4a83: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4a89:
	/* 0x4a89: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_4a8f:
	/* 0x4a8f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a94:
	/* 0x4a94: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4a98:
	/* 0x4a98: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4a9f:
	/* 0x4a9f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4aa4:
	/* 0x4aa4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4aa9:
	/* 0x4aa9: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4ab0:
	/* 0x4ab0: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4ab3:
	/* 0x4ab3: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4aba:
	/* 0x4aba: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4abf:
	/* 0x4abf: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4ac4:
	/* 0x4ac4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ac6:
	/* 0x4ac6: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4aca:
	/* 0x4aca: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_4acc:
	/* 0x4acc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ace:
	/* 0x4ace: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_4ad4:
	/* 0x4ad4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4ad7:
	/* 0x4ad7: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4add:
	/* 0x4add: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_4ae3:
	/* 0x4ae3: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ae8:
	/* 0x4ae8: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4aec:
	/* 0x4aec: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4af3:
	/* 0x4af3: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4af8:
	/* 0x4af8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4afd:
	/* 0x4afd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4b02:
	/* 0x4b02: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4b0a:
	/* 0x4b0a: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4b0e:
	/* 0x4b0e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4b15:
	/* 0x4b15: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4b1a:
	/* 0x4b1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b1c:
	/* 0x4b1c: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4b21:
	/* 0x4b21: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4b29:
	/* 0x4b29: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4b2c:
	/* 0x4b2c: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4b34:
	/* 0x4b34: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4b3d:
	/* 0x4b3d: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_4b44:
	/* 0x4b44: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b49:
	/* 0x4b49: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4b4e:
	/* 0x4b4e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4b53:
	/* 0x4b53: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b58:
	/* 0x4b58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b5a:
	/* 0x4b5a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b5f:
	/* 0x4b5f: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_4b61:
	/* 0x4b61: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4b64:
	/* 0x4b64: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_4b6a:
	/* 0x4b6a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4b6d:
	/* 0x4b6d: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4b73:
	/* 0x4b73: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_4b79:
	/* 0x4b79: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b7e:
	/* 0x4b7e: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4b82:
	/* 0x4b82: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4b89:
	/* 0x4b89: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4b8e:
	/* 0x4b8e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4b93:
	/* 0x4b93: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4b9a:
	/* 0x4b9a: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4b9d:
	/* 0x4b9d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4ba4:
	/* 0x4ba4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ba9:
	/* 0x4ba9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4bae:
	/* 0x4bae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bb0:
	/* 0x4bb0: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4bb4:
	/* 0x4bb4: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_4bb6:
	/* 0x4bb6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4bb8:
	/* 0x4bb8: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_4bbe:
	/* 0x4bbe: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4bc1:
	/* 0x4bc1: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4bc7:
	/* 0x4bc7: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_4bcd:
	/* 0x4bcd: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4bd2:
	/* 0x4bd2: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4bd6:
	/* 0x4bd6: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4bdd:
	/* 0x4bdd: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4be2:
	/* 0x4be2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4be7:
	/* 0x4be7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4bec:
	/* 0x4bec: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4bf4:
	/* 0x4bf4: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4bf8:
	/* 0x4bf8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4bff:
	/* 0x4bff: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4c04:
	/* 0x4c04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c06:
	/* 0x4c06: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4c0b:
	/* 0x4c0b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4c13:
	/* 0x4c13: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4c16:
	/* 0x4c16: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4c1e:
	/* 0x4c1e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4c27:
	/* 0x4c27: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_4c2e:
	/* 0x4c2e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c33:
	/* 0x4c33: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4c38:
	/* 0x4c38: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4c3d:
	/* 0x4c3d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c42:
	/* 0x4c42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c44:
	/* 0x4c44: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c49:
	/* 0x4c49: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_4c4b:
	/* 0x4c4b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4c4e:
	/* 0x4c4e: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_4c54:
	/* 0x4c54: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4c57:
	/* 0x4c57: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4c5d:
	/* 0x4c5d: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_4c63:
	/* 0x4c63: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c68:
	/* 0x4c68: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4c6c:
	/* 0x4c6c: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4c73:
	/* 0x4c73: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4c78:
	/* 0x4c78: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4c7d:
	/* 0x4c7d: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4c84:
	/* 0x4c84: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4c87:
	/* 0x4c87: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4c8e:
	/* 0x4c8e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c93:
	/* 0x4c93: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4c98:
	/* 0x4c98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c9a:
	/* 0x4c9a: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4c9e:
	/* 0x4c9e: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_4ca0:
	/* 0x4ca0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ca2:
	/* 0x4ca2: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_4ca8:
	/* 0x4ca8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4cab:
	/* 0x4cab: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4cb1:
	/* 0x4cb1: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_4cb7:
	/* 0x4cb7: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cbc:
	/* 0x4cbc: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4cc0:
	/* 0x4cc0: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4cc7:
	/* 0x4cc7: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4ccc:
	/* 0x4ccc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4cd1:
	/* 0x4cd1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4cd6:
	/* 0x4cd6: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4cde:
	/* 0x4cde: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4ce2:
	/* 0x4ce2: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4ce9:
	/* 0x4ce9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4cee:
	/* 0x4cee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cf0:
	/* 0x4cf0: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4cf5:
	/* 0x4cf5: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4cfd:
	/* 0x4cfd: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4d00:
	/* 0x4d00: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4d08:
	/* 0x4d08: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4d11:
	/* 0x4d11: lea    rdx,[r13+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_4d18:
	/* 0x4d18: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d1d:
	/* 0x4d1d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4d22:
	/* 0x4d22: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4d27:
	/* 0x4d27: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d2c:
	/* 0x4d2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d2e:
	/* 0x4d2e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d33:
	/* 0x4d33: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_4d35:
	/* 0x4d35: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4d38:
	/* 0x4d38: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_4d3e:
	/* 0x4d3e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4d41:
	/* 0x4d41: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4d47:
	/* 0x4d47: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_4d4d:
	/* 0x4d4d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d52:
	/* 0x4d52: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4d56:
	/* 0x4d56: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4d5d:
	/* 0x4d5d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4d62:
	/* 0x4d62: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4d67:
	/* 0x4d67: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4d6e:
	/* 0x4d6e: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4d71:
	/* 0x4d71: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4d78:
	/* 0x4d78: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d7d:
	/* 0x4d7d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4d82:
	/* 0x4d82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d84:
	/* 0x4d84: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4d88:
	/* 0x4d88: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_4d8a:
	/* 0x4d8a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d8c:
	/* 0x4d8c: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_4d92:
	/* 0x4d92: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4d95:
	/* 0x4d95: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4d9b:
	/* 0x4d9b: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_4da1:
	/* 0x4da1: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4da6:
	/* 0x4da6: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4daa:
	/* 0x4daa: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4db1:
	/* 0x4db1: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4db6:
	/* 0x4db6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4dbb:
	/* 0x4dbb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4dc0:
	/* 0x4dc0: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4dc8:
	/* 0x4dc8: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4dcc:
	/* 0x4dcc: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4dd3:
	/* 0x4dd3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4dd8:
	/* 0x4dd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dda:
	/* 0x4dda: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4ddf:
	/* 0x4ddf: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4de7:
	/* 0x4de7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4dea:
	/* 0x4dea: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4df2:
	/* 0x4df2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4dfb:
	/* 0x4dfb: lea    rdx,[r13+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_4e02:
	/* 0x4e02: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e07:
	/* 0x4e07: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4e0c:
	/* 0x4e0c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4e11:
	/* 0x4e11: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e16:
	/* 0x4e16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e18:
	/* 0x4e18: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e1d:
	/* 0x4e1d: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_4e1f:
	/* 0x4e1f: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4e22:
	/* 0x4e22: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_4e28:
	/* 0x4e28: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4e2b:
	/* 0x4e2b: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4e31:
	/* 0x4e31: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_4e37:
	/* 0x4e37: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e3c:
	/* 0x4e3c: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4e40:
	/* 0x4e40: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4e47:
	/* 0x4e47: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4e4c:
	/* 0x4e4c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4e51:
	/* 0x4e51: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4e58:
	/* 0x4e58: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4e5b:
	/* 0x4e5b: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4e62:
	/* 0x4e62: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e67:
	/* 0x4e67: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4e6c:
	/* 0x4e6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e6e:
	/* 0x4e6e: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4e72:
	/* 0x4e72: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_4e74:
	/* 0x4e74: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e76:
	/* 0x4e76: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_4e7c:
	/* 0x4e7c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4e7f:
	/* 0x4e7f: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4e85:
	/* 0x4e85: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_4e8b:
	/* 0x4e8b: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e90:
	/* 0x4e90: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4e94:
	/* 0x4e94: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4e9b:
	/* 0x4e9b: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4ea0:
	/* 0x4ea0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4ea5:
	/* 0x4ea5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4eaa:
	/* 0x4eaa: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4eb2:
	/* 0x4eb2: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4eb6:
	/* 0x4eb6: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4ebd:
	/* 0x4ebd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4ec2:
	/* 0x4ec2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ec4:
	/* 0x4ec4: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4ec9:
	/* 0x4ec9: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4ed1:
	/* 0x4ed1: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4ed4:
	/* 0x4ed4: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4edc:
	/* 0x4edc: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4ee5:
	/* 0x4ee5: lea    rdx,[r13+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_4eec:
	/* 0x4eec: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ef1:
	/* 0x4ef1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4ef6:
	/* 0x4ef6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4efb:
	/* 0x4efb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f00:
	/* 0x4f00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f02:
	/* 0x4f02: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f07:
	/* 0x4f07: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_4f09:
	/* 0x4f09: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4f0c:
	/* 0x4f0c: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_4f12:
	/* 0x4f12: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4f15:
	/* 0x4f15: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_4f1b:
	/* 0x4f1b: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_4f21:
	/* 0x4f21: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f26:
	/* 0x4f26: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_4f2a:
	/* 0x4f2a: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4f31:
	/* 0x4f31: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4f36:
	/* 0x4f36: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
	return 20283ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 20283ULL: goto x86_l_4f3b;
	case 20290ULL: goto x86_l_4f42;
	case 20293ULL: goto x86_l_4f45;
	case 20300ULL: goto x86_l_4f4c;
	case 20305ULL: goto x86_l_4f51;
	case 20310ULL: goto x86_l_4f56;
	case 20312ULL: goto x86_l_4f58;
	case 20316ULL: goto x86_l_4f5c;
	case 20318ULL: goto x86_l_4f5e;
	case 20320ULL: goto x86_l_4f60;
	case 20326ULL: goto x86_l_4f66;
	case 20329ULL: goto x86_l_4f69;
	case 20335ULL: goto x86_l_4f6f;
	case 20341ULL: goto x86_l_4f75;
	case 20346ULL: goto x86_l_4f7a;
	case 20350ULL: goto x86_l_4f7e;
	case 20357ULL: goto x86_l_4f85;
	case 20362ULL: goto x86_l_4f8a;
	case 20367ULL: goto x86_l_4f8f;
	case 20372ULL: goto x86_l_4f94;
	case 20380ULL: goto x86_l_4f9c;
	case 20384ULL: goto x86_l_4fa0;
	case 20391ULL: goto x86_l_4fa7;
	case 20396ULL: goto x86_l_4fac;
	case 20398ULL: goto x86_l_4fae;
	case 20403ULL: goto x86_l_4fb3;
	case 20411ULL: goto x86_l_4fbb;
	case 20414ULL: goto x86_l_4fbe;
	case 20422ULL: goto x86_l_4fc6;
	case 20431ULL: goto x86_l_4fcf;
	case 20438ULL: goto x86_l_4fd6;
	case 20443ULL: goto x86_l_4fdb;
	case 20448ULL: goto x86_l_4fe0;
	case 20453ULL: goto x86_l_4fe5;
	case 20458ULL: goto x86_l_4fea;
	case 20460ULL: goto x86_l_4fec;
	case 20465ULL: goto x86_l_4ff1;
	case 20467ULL: goto x86_l_4ff3;
	case 20470ULL: goto x86_l_4ff6;
	case 20476ULL: goto x86_l_4ffc;
	case 20479ULL: goto x86_l_4fff;
	case 20485ULL: goto x86_l_5005;
	case 20491ULL: goto x86_l_500b;
	case 20496ULL: goto x86_l_5010;
	case 20500ULL: goto x86_l_5014;
	case 20507ULL: goto x86_l_501b;
	case 20512ULL: goto x86_l_5020;
	case 20517ULL: goto x86_l_5025;
	case 20524ULL: goto x86_l_502c;
	case 20527ULL: goto x86_l_502f;
	case 20534ULL: goto x86_l_5036;
	case 20539ULL: goto x86_l_503b;
	case 20544ULL: goto x86_l_5040;
	case 20546ULL: goto x86_l_5042;
	case 20550ULL: goto x86_l_5046;
	case 20552ULL: goto x86_l_5048;
	case 20554ULL: goto x86_l_504a;
	case 20560ULL: goto x86_l_5050;
	case 20563ULL: goto x86_l_5053;
	case 20569ULL: goto x86_l_5059;
	case 20575ULL: goto x86_l_505f;
	case 20580ULL: goto x86_l_5064;
	case 20584ULL: goto x86_l_5068;
	case 20591ULL: goto x86_l_506f;
	case 20596ULL: goto x86_l_5074;
	case 20601ULL: goto x86_l_5079;
	case 20606ULL: goto x86_l_507e;
	case 20614ULL: goto x86_l_5086;
	case 20618ULL: goto x86_l_508a;
	case 20625ULL: goto x86_l_5091;
	case 20630ULL: goto x86_l_5096;
	case 20632ULL: goto x86_l_5098;
	case 20637ULL: goto x86_l_509d;
	case 20645ULL: goto x86_l_50a5;
	case 20648ULL: goto x86_l_50a8;
	case 20656ULL: goto x86_l_50b0;
	case 20665ULL: goto x86_l_50b9;
	case 20672ULL: goto x86_l_50c0;
	case 20677ULL: goto x86_l_50c5;
	case 20682ULL: goto x86_l_50ca;
	case 20687ULL: goto x86_l_50cf;
	case 20692ULL: goto x86_l_50d4;
	case 20694ULL: goto x86_l_50d6;
	case 20699ULL: goto x86_l_50db;
	case 20701ULL: goto x86_l_50dd;
	case 20704ULL: goto x86_l_50e0;
	case 20710ULL: goto x86_l_50e6;
	case 20713ULL: goto x86_l_50e9;
	case 20719ULL: goto x86_l_50ef;
	case 20725ULL: goto x86_l_50f5;
	case 20730ULL: goto x86_l_50fa;
	case 20734ULL: goto x86_l_50fe;
	case 20741ULL: goto x86_l_5105;
	case 20746ULL: goto x86_l_510a;
	case 20751ULL: goto x86_l_510f;
	case 20758ULL: goto x86_l_5116;
	case 20761ULL: goto x86_l_5119;
	case 20768ULL: goto x86_l_5120;
	case 20773ULL: goto x86_l_5125;
	case 20778ULL: goto x86_l_512a;
	case 20780ULL: goto x86_l_512c;
	case 20784ULL: goto x86_l_5130;
	case 20786ULL: goto x86_l_5132;
	case 20788ULL: goto x86_l_5134;
	case 20794ULL: goto x86_l_513a;
	case 20797ULL: goto x86_l_513d;
	case 20803ULL: goto x86_l_5143;
	case 20809ULL: goto x86_l_5149;
	case 20814ULL: goto x86_l_514e;
	case 20818ULL: goto x86_l_5152;
	case 20825ULL: goto x86_l_5159;
	case 20830ULL: goto x86_l_515e;
	case 20835ULL: goto x86_l_5163;
	case 20840ULL: goto x86_l_5168;
	case 20848ULL: goto x86_l_5170;
	case 20852ULL: goto x86_l_5174;
	case 20859ULL: goto x86_l_517b;
	case 20864ULL: goto x86_l_5180;
	case 20866ULL: goto x86_l_5182;
	case 20871ULL: goto x86_l_5187;
	case 20879ULL: goto x86_l_518f;
	case 20882ULL: goto x86_l_5192;
	case 20890ULL: goto x86_l_519a;
	case 20899ULL: goto x86_l_51a3;
	case 20906ULL: goto x86_l_51aa;
	case 20911ULL: goto x86_l_51af;
	case 20916ULL: goto x86_l_51b4;
	case 20921ULL: goto x86_l_51b9;
	case 20926ULL: goto x86_l_51be;
	case 20928ULL: goto x86_l_51c0;
	case 20933ULL: goto x86_l_51c5;
	case 20935ULL: goto x86_l_51c7;
	case 20938ULL: goto x86_l_51ca;
	case 20944ULL: goto x86_l_51d0;
	case 20947ULL: goto x86_l_51d3;
	case 20953ULL: goto x86_l_51d9;
	case 20959ULL: goto x86_l_51df;
	case 20964ULL: goto x86_l_51e4;
	case 20968ULL: goto x86_l_51e8;
	case 20975ULL: goto x86_l_51ef;
	case 20980ULL: goto x86_l_51f4;
	case 20985ULL: goto x86_l_51f9;
	case 20992ULL: goto x86_l_5200;
	case 20995ULL: goto x86_l_5203;
	case 21002ULL: goto x86_l_520a;
	case 21007ULL: goto x86_l_520f;
	case 21012ULL: goto x86_l_5214;
	case 21014ULL: goto x86_l_5216;
	case 21018ULL: goto x86_l_521a;
	case 21020ULL: goto x86_l_521c;
	case 21022ULL: goto x86_l_521e;
	case 21028ULL: goto x86_l_5224;
	case 21031ULL: goto x86_l_5227;
	case 21037ULL: goto x86_l_522d;
	case 21043ULL: goto x86_l_5233;
	case 21048ULL: goto x86_l_5238;
	case 21052ULL: goto x86_l_523c;
	case 21059ULL: goto x86_l_5243;
	case 21064ULL: goto x86_l_5248;
	case 21069ULL: goto x86_l_524d;
	case 21074ULL: goto x86_l_5252;
	case 21082ULL: goto x86_l_525a;
	case 21086ULL: goto x86_l_525e;
	case 21093ULL: goto x86_l_5265;
	case 21098ULL: goto x86_l_526a;
	case 21100ULL: goto x86_l_526c;
	case 21105ULL: goto x86_l_5271;
	case 21113ULL: goto x86_l_5279;
	case 21116ULL: goto x86_l_527c;
	case 21124ULL: goto x86_l_5284;
	case 21133ULL: goto x86_l_528d;
	case 21140ULL: goto x86_l_5294;
	case 21145ULL: goto x86_l_5299;
	case 21150ULL: goto x86_l_529e;
	case 21155ULL: goto x86_l_52a3;
	case 21160ULL: goto x86_l_52a8;
	case 21162ULL: goto x86_l_52aa;
	case 21167ULL: goto x86_l_52af;
	case 21169ULL: goto x86_l_52b1;
	case 21172ULL: goto x86_l_52b4;
	case 21178ULL: goto x86_l_52ba;
	case 21181ULL: goto x86_l_52bd;
	case 21187ULL: goto x86_l_52c3;
	case 21193ULL: goto x86_l_52c9;
	case 21198ULL: goto x86_l_52ce;
	case 21202ULL: goto x86_l_52d2;
	case 21209ULL: goto x86_l_52d9;
	case 21214ULL: goto x86_l_52de;
	case 21219ULL: goto x86_l_52e3;
	case 21226ULL: goto x86_l_52ea;
	case 21229ULL: goto x86_l_52ed;
	case 21236ULL: goto x86_l_52f4;
	case 21241ULL: goto x86_l_52f9;
	case 21246ULL: goto x86_l_52fe;
	case 21248ULL: goto x86_l_5300;
	case 21252ULL: goto x86_l_5304;
	case 21254ULL: goto x86_l_5306;
	case 21256ULL: goto x86_l_5308;
	case 21262ULL: goto x86_l_530e;
	case 21265ULL: goto x86_l_5311;
	case 21271ULL: goto x86_l_5317;
	case 21277ULL: goto x86_l_531d;
	case 21282ULL: goto x86_l_5322;
	case 21286ULL: goto x86_l_5326;
	case 21293ULL: goto x86_l_532d;
	case 21298ULL: goto x86_l_5332;
	case 21303ULL: goto x86_l_5337;
	case 21308ULL: goto x86_l_533c;
	case 21316ULL: goto x86_l_5344;
	case 21320ULL: goto x86_l_5348;
	case 21327ULL: goto x86_l_534f;
	case 21332ULL: goto x86_l_5354;
	case 21334ULL: goto x86_l_5356;
	case 21339ULL: goto x86_l_535b;
	case 21347ULL: goto x86_l_5363;
	case 21350ULL: goto x86_l_5366;
	case 21358ULL: goto x86_l_536e;
	case 21367ULL: goto x86_l_5377;
	case 21374ULL: goto x86_l_537e;
	case 21379ULL: goto x86_l_5383;
	case 21384ULL: goto x86_l_5388;
	case 21389ULL: goto x86_l_538d;
	case 21394ULL: goto x86_l_5392;
	case 21396ULL: goto x86_l_5394;
	case 21401ULL: goto x86_l_5399;
	case 21403ULL: goto x86_l_539b;
	case 21406ULL: goto x86_l_539e;
	case 21412ULL: goto x86_l_53a4;
	case 21415ULL: goto x86_l_53a7;
	case 21421ULL: goto x86_l_53ad;
	case 21427ULL: goto x86_l_53b3;
	case 21432ULL: goto x86_l_53b8;
	case 21436ULL: goto x86_l_53bc;
	case 21443ULL: goto x86_l_53c3;
	case 21448ULL: goto x86_l_53c8;
	case 21453ULL: goto x86_l_53cd;
	case 21460ULL: goto x86_l_53d4;
	case 21463ULL: goto x86_l_53d7;
	case 21470ULL: goto x86_l_53de;
	case 21475ULL: goto x86_l_53e3;
	case 21480ULL: goto x86_l_53e8;
	case 21482ULL: goto x86_l_53ea;
	case 21486ULL: goto x86_l_53ee;
	case 21488ULL: goto x86_l_53f0;
	case 21490ULL: goto x86_l_53f2;
	case 21496ULL: goto x86_l_53f8;
	case 21499ULL: goto x86_l_53fb;
	case 21505ULL: goto x86_l_5401;
	case 21511ULL: goto x86_l_5407;
	case 21516ULL: goto x86_l_540c;
	case 21520ULL: goto x86_l_5410;
	case 21527ULL: goto x86_l_5417;
	case 21532ULL: goto x86_l_541c;
	case 21537ULL: goto x86_l_5421;
	case 21542ULL: goto x86_l_5426;
	case 21550ULL: goto x86_l_542e;
	case 21554ULL: goto x86_l_5432;
	case 21561ULL: goto x86_l_5439;
	case 21566ULL: goto x86_l_543e;
	case 21568ULL: goto x86_l_5440;
	case 21573ULL: goto x86_l_5445;
	case 21581ULL: goto x86_l_544d;
	case 21584ULL: goto x86_l_5450;
	case 21592ULL: goto x86_l_5458;
	case 21601ULL: goto x86_l_5461;
	case 21608ULL: goto x86_l_5468;
	case 21613ULL: goto x86_l_546d;
	case 21618ULL: goto x86_l_5472;
	case 21623ULL: goto x86_l_5477;
	case 21628ULL: goto x86_l_547c;
	case 21630ULL: goto x86_l_547e;
	case 21635ULL: goto x86_l_5483;
	case 21637ULL: goto x86_l_5485;
	case 21640ULL: goto x86_l_5488;
	case 21646ULL: goto x86_l_548e;
	case 21649ULL: goto x86_l_5491;
	case 21655ULL: goto x86_l_5497;
	case 21661ULL: goto x86_l_549d;
	case 21666ULL: goto x86_l_54a2;
	case 21670ULL: goto x86_l_54a6;
	case 21677ULL: goto x86_l_54ad;
	case 21682ULL: goto x86_l_54b2;
	case 21687ULL: goto x86_l_54b7;
	case 21694ULL: goto x86_l_54be;
	case 21697ULL: goto x86_l_54c1;
	case 21704ULL: goto x86_l_54c8;
	case 21709ULL: goto x86_l_54cd;
	case 21714ULL: goto x86_l_54d2;
	case 21716ULL: goto x86_l_54d4;
	case 21720ULL: goto x86_l_54d8;
	case 21722ULL: goto x86_l_54da;
	case 21724ULL: goto x86_l_54dc;
	case 21730ULL: goto x86_l_54e2;
	case 21733ULL: goto x86_l_54e5;
	case 21739ULL: goto x86_l_54eb;
	case 21745ULL: goto x86_l_54f1;
	case 21750ULL: goto x86_l_54f6;
	case 21754ULL: goto x86_l_54fa;
	case 21761ULL: goto x86_l_5501;
	case 21766ULL: goto x86_l_5506;
	case 21771ULL: goto x86_l_550b;
	case 21776ULL: goto x86_l_5510;
	case 21784ULL: goto x86_l_5518;
	case 21788ULL: goto x86_l_551c;
	case 21795ULL: goto x86_l_5523;
	case 21800ULL: goto x86_l_5528;
	case 21802ULL: goto x86_l_552a;
	case 21807ULL: goto x86_l_552f;
	case 21815ULL: goto x86_l_5537;
	case 21818ULL: goto x86_l_553a;
	case 21826ULL: goto x86_l_5542;
	case 21835ULL: goto x86_l_554b;
	case 21842ULL: goto x86_l_5552;
	case 21847ULL: goto x86_l_5557;
	case 21852ULL: goto x86_l_555c;
	case 21857ULL: goto x86_l_5561;
	case 21862ULL: goto x86_l_5566;
	case 21864ULL: goto x86_l_5568;
	case 21869ULL: goto x86_l_556d;
	case 21871ULL: goto x86_l_556f;
	case 21874ULL: goto x86_l_5572;
	case 21880ULL: goto x86_l_5578;
	case 21883ULL: goto x86_l_557b;
	case 21889ULL: goto x86_l_5581;
	case 21895ULL: goto x86_l_5587;
	case 21900ULL: goto x86_l_558c;
	case 21904ULL: goto x86_l_5590;
	case 21911ULL: goto x86_l_5597;
	case 21916ULL: goto x86_l_559c;
	case 21921ULL: goto x86_l_55a1;
	case 21928ULL: goto x86_l_55a8;
	case 21931ULL: goto x86_l_55ab;
	case 21938ULL: goto x86_l_55b2;
	case 21943ULL: goto x86_l_55b7;
	case 21948ULL: goto x86_l_55bc;
	case 21950ULL: goto x86_l_55be;
	case 21954ULL: goto x86_l_55c2;
	case 21956ULL: goto x86_l_55c4;
	case 21958ULL: goto x86_l_55c6;
	case 21964ULL: goto x86_l_55cc;
	case 21967ULL: goto x86_l_55cf;
	case 21973ULL: goto x86_l_55d5;
	case 21979ULL: goto x86_l_55db;
	case 21984ULL: goto x86_l_55e0;
	case 21988ULL: goto x86_l_55e4;
	case 21995ULL: goto x86_l_55eb;
	case 22000ULL: goto x86_l_55f0;
	case 22005ULL: goto x86_l_55f5;
	case 22010ULL: goto x86_l_55fa;
	case 22018ULL: goto x86_l_5602;
	case 22022ULL: goto x86_l_5606;
	case 22029ULL: goto x86_l_560d;
	case 22034ULL: goto x86_l_5612;
	case 22036ULL: goto x86_l_5614;
	case 22041ULL: goto x86_l_5619;
	case 22049ULL: goto x86_l_5621;
	case 22052ULL: goto x86_l_5624;
	case 22060ULL: goto x86_l_562c;
	case 22069ULL: goto x86_l_5635;
	case 22076ULL: goto x86_l_563c;
	case 22081ULL: goto x86_l_5641;
	case 22086ULL: goto x86_l_5646;
	case 22091ULL: goto x86_l_564b;
	case 22096ULL: goto x86_l_5650;
	case 22099ULL: goto x86_l_5653;
	case 22101ULL: goto x86_l_5655;
	case 22106ULL: goto x86_l_565a;
	case 22108ULL: goto x86_l_565c;
	case 22111ULL: goto x86_l_565f;
	case 22117ULL: goto x86_l_5665;
	case 22120ULL: goto x86_l_5668;
	case 22126ULL: goto x86_l_566e;
	case 22132ULL: goto x86_l_5674;
	case 22137ULL: goto x86_l_5679;
	case 22141ULL: goto x86_l_567d;
	case 22148ULL: goto x86_l_5684;
	case 22153ULL: goto x86_l_5689;
	case 22158ULL: goto x86_l_568e;
	case 22165ULL: goto x86_l_5695;
	case 22168ULL: goto x86_l_5698;
	case 22175ULL: goto x86_l_569f;
	case 22180ULL: goto x86_l_56a4;
	case 22185ULL: goto x86_l_56a9;
	case 22187ULL: goto x86_l_56ab;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4f3b:
	/* 0x4f3b: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4f42:
	/* 0x4f42: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4f45:
	/* 0x4f45: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4f4c:
	/* 0x4f4c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f51:
	/* 0x4f51: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4f56:
	/* 0x4f56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f58:
	/* 0x4f58: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4f5c:
	/* 0x4f5c: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_4f5e:
	/* 0x4f5e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f60:
	/* 0x4f60: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_4f66:
	/* 0x4f66: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4f69:
	/* 0x4f69: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_4f6f:
	/* 0x4f6f: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_4f75:
	/* 0x4f75: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f7a:
	/* 0x4f7a: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4f7e:
	/* 0x4f7e: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4f85:
	/* 0x4f85: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4f8a:
	/* 0x4f8a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4f8f:
	/* 0x4f8f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4f94:
	/* 0x4f94: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4f9c:
	/* 0x4f9c: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4fa0:
	/* 0x4fa0: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4fa7:
	/* 0x4fa7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4fac:
	/* 0x4fac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fae:
	/* 0x4fae: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_4fb3:
	/* 0x4fb3: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4fbb:
	/* 0x4fbb: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4fbe:
	/* 0x4fbe: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4fc6:
	/* 0x4fc6: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4fcf:
	/* 0x4fcf: lea    rdx,[r13+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_4fd6:
	/* 0x4fd6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4fdb:
	/* 0x4fdb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4fe0:
	/* 0x4fe0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4fe5:
	/* 0x4fe5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4fea:
	/* 0x4fea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fec:
	/* 0x4fec: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ff1:
	/* 0x4ff1: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_4ff3:
	/* 0x4ff3: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_4ff6:
	/* 0x4ff6: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_4ffc:
	/* 0x4ffc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4fff:
	/* 0x4fff: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5005:
	/* 0x5005: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_500b:
	/* 0x500b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5010:
	/* 0x5010: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_5014:
	/* 0x5014: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_501b:
	/* 0x501b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5020:
	/* 0x5020: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5025:
	/* 0x5025: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_502c:
	/* 0x502c: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_502f:
	/* 0x502f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5036:
	/* 0x5036: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_503b:
	/* 0x503b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5040:
	/* 0x5040: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5042:
	/* 0x5042: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5046:
	/* 0x5046: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_5048:
	/* 0x5048: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_504a:
	/* 0x504a: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_5050:
	/* 0x5050: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5053:
	/* 0x5053: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5059:
	/* 0x5059: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_505f:
	/* 0x505f: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5064:
	/* 0x5064: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_5068:
	/* 0x5068: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_506f:
	/* 0x506f: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5074:
	/* 0x5074: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5079:
	/* 0x5079: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_507e:
	/* 0x507e: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5086:
	/* 0x5086: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_508a:
	/* 0x508a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5091:
	/* 0x5091: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5096:
	/* 0x5096: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5098:
	/* 0x5098: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_509d:
	/* 0x509d: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_50a5:
	/* 0x50a5: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_50a8:
	/* 0x50a8: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_50b0:
	/* 0x50b0: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_50b9:
	/* 0x50b9: lea    rdx,[r13+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_50c0:
	/* 0x50c0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_50c5:
	/* 0x50c5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_50ca:
	/* 0x50ca: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_50cf:
	/* 0x50cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_50d4:
	/* 0x50d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50d6:
	/* 0x50d6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_50db:
	/* 0x50db: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_50dd:
	/* 0x50dd: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_50e0:
	/* 0x50e0: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_50e6:
	/* 0x50e6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_50e9:
	/* 0x50e9: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_50ef:
	/* 0x50ef: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_50f5:
	/* 0x50f5: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50fa:
	/* 0x50fa: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_50fe:
	/* 0x50fe: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5105:
	/* 0x5105: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_510a:
	/* 0x510a: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_510f:
	/* 0x510f: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5116:
	/* 0x5116: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5119:
	/* 0x5119: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5120:
	/* 0x5120: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5125:
	/* 0x5125: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_512a:
	/* 0x512a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_512c:
	/* 0x512c: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5130:
	/* 0x5130: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_5132:
	/* 0x5132: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5134:
	/* 0x5134: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_513a:
	/* 0x513a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_513d:
	/* 0x513d: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5143:
	/* 0x5143: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_5149:
	/* 0x5149: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_514e:
	/* 0x514e: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_5152:
	/* 0x5152: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5159:
	/* 0x5159: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_515e:
	/* 0x515e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5163:
	/* 0x5163: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5168:
	/* 0x5168: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5170:
	/* 0x5170: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5174:
	/* 0x5174: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_517b:
	/* 0x517b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5180:
	/* 0x5180: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5182:
	/* 0x5182: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_5187:
	/* 0x5187: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_518f:
	/* 0x518f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5192:
	/* 0x5192: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_519a:
	/* 0x519a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_51a3:
	/* 0x51a3: lea    rdx,[r13+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_51aa:
	/* 0x51aa: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51af:
	/* 0x51af: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_51b4:
	/* 0x51b4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_51b9:
	/* 0x51b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51be:
	/* 0x51be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51c0:
	/* 0x51c0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51c5:
	/* 0x51c5: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_51c7:
	/* 0x51c7: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_51ca:
	/* 0x51ca: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_51d0:
	/* 0x51d0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_51d3:
	/* 0x51d3: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_51d9:
	/* 0x51d9: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_51df:
	/* 0x51df: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51e4:
	/* 0x51e4: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_51e8:
	/* 0x51e8: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_51ef:
	/* 0x51ef: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_51f4:
	/* 0x51f4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_51f9:
	/* 0x51f9: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5200:
	/* 0x5200: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5203:
	/* 0x5203: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_520a:
	/* 0x520a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_520f:
	/* 0x520f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5214:
	/* 0x5214: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5216:
	/* 0x5216: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_521a:
	/* 0x521a: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_521c:
	/* 0x521c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_521e:
	/* 0x521e: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_5224:
	/* 0x5224: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5227:
	/* 0x5227: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_522d:
	/* 0x522d: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_5233:
	/* 0x5233: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5238:
	/* 0x5238: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_523c:
	/* 0x523c: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5243:
	/* 0x5243: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5248:
	/* 0x5248: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_524d:
	/* 0x524d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5252:
	/* 0x5252: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_525a:
	/* 0x525a: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_525e:
	/* 0x525e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5265:
	/* 0x5265: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_526a:
	/* 0x526a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_526c:
	/* 0x526c: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_5271:
	/* 0x5271: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5279:
	/* 0x5279: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_527c:
	/* 0x527c: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5284:
	/* 0x5284: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_528d:
	/* 0x528d: lea    rdx,[r13+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_5294:
	/* 0x5294: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5299:
	/* 0x5299: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_529e:
	/* 0x529e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_52a3:
	/* 0x52a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52a8:
	/* 0x52a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52aa:
	/* 0x52aa: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52af:
	/* 0x52af: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_52b1:
	/* 0x52b1: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_52b4:
	/* 0x52b4: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_52ba:
	/* 0x52ba: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_52bd:
	/* 0x52bd: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_52c3:
	/* 0x52c3: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_52c9:
	/* 0x52c9: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52ce:
	/* 0x52ce: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_52d2:
	/* 0x52d2: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_52d9:
	/* 0x52d9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_52de:
	/* 0x52de: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_52e3:
	/* 0x52e3: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_52ea:
	/* 0x52ea: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_52ed:
	/* 0x52ed: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_52f4:
	/* 0x52f4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52f9:
	/* 0x52f9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_52fe:
	/* 0x52fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5300:
	/* 0x5300: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5304:
	/* 0x5304: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_5306:
	/* 0x5306: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5308:
	/* 0x5308: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_530e:
	/* 0x530e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5311:
	/* 0x5311: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5317:
	/* 0x5317: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_531d:
	/* 0x531d: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5322:
	/* 0x5322: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_5326:
	/* 0x5326: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_532d:
	/* 0x532d: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5332:
	/* 0x5332: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5337:
	/* 0x5337: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_533c:
	/* 0x533c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5344:
	/* 0x5344: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5348:
	/* 0x5348: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_534f:
	/* 0x534f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5354:
	/* 0x5354: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5356:
	/* 0x5356: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_535b:
	/* 0x535b: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5363:
	/* 0x5363: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5366:
	/* 0x5366: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_536e:
	/* 0x536e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5377:
	/* 0x5377: lea    rdx,[r13+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_537e:
	/* 0x537e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5383:
	/* 0x5383: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5388:
	/* 0x5388: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_538d:
	/* 0x538d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5392:
	/* 0x5392: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5394:
	/* 0x5394: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5399:
	/* 0x5399: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_539b:
	/* 0x539b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_539e:
	/* 0x539e: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_53a4:
	/* 0x53a4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_53a7:
	/* 0x53a7: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_53ad:
	/* 0x53ad: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_53b3:
	/* 0x53b3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53b8:
	/* 0x53b8: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_53bc:
	/* 0x53bc: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_53c3:
	/* 0x53c3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_53c8:
	/* 0x53c8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_53cd:
	/* 0x53cd: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_53d4:
	/* 0x53d4: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_53d7:
	/* 0x53d7: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_53de:
	/* 0x53de: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53e3:
	/* 0x53e3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_53e8:
	/* 0x53e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53ea:
	/* 0x53ea: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_53ee:
	/* 0x53ee: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_53f0:
	/* 0x53f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_53f2:
	/* 0x53f2: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_53f8:
	/* 0x53f8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_53fb:
	/* 0x53fb: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_5401:
	/* 0x5401: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_5407:
	/* 0x5407: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_540c:
	/* 0x540c: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_5410:
	/* 0x5410: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5417:
	/* 0x5417: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_541c:
	/* 0x541c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5421:
	/* 0x5421: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5426:
	/* 0x5426: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_542e:
	/* 0x542e: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5432:
	/* 0x5432: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5439:
	/* 0x5439: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_543e:
	/* 0x543e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5440:
	/* 0x5440: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_5445:
	/* 0x5445: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_544d:
	/* 0x544d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5450:
	/* 0x5450: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5458:
	/* 0x5458: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5461:
	/* 0x5461: lea    rdx,[r13+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_5468:
	/* 0x5468: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_546d:
	/* 0x546d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5472:
	/* 0x5472: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5477:
	/* 0x5477: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_547c:
	/* 0x547c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_547e:
	/* 0x547e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5483:
	/* 0x5483: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_5485:
	/* 0x5485: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5488:
	/* 0x5488: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_548e:
	/* 0x548e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5491:
	/* 0x5491: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5497:
	/* 0x5497: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_549d:
	/* 0x549d: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54a2:
	/* 0x54a2: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_54a6:
	/* 0x54a6: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_54ad:
	/* 0x54ad: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_54b2:
	/* 0x54b2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_54b7:
	/* 0x54b7: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_54be:
	/* 0x54be: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_54c1:
	/* 0x54c1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_54c8:
	/* 0x54c8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54cd:
	/* 0x54cd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_54d2:
	/* 0x54d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54d4:
	/* 0x54d4: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_54d8:
	/* 0x54d8: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_54da:
	/* 0x54da: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_54dc:
	/* 0x54dc: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_54e2:
	/* 0x54e2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_54e5:
	/* 0x54e5: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_54eb:
	/* 0x54eb: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_54f1:
	/* 0x54f1: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54f6:
	/* 0x54f6: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_54fa:
	/* 0x54fa: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5501:
	/* 0x5501: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5506:
	/* 0x5506: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_550b:
	/* 0x550b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5510:
	/* 0x5510: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5518:
	/* 0x5518: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_551c:
	/* 0x551c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5523:
	/* 0x5523: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5528:
	/* 0x5528: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_552a:
	/* 0x552a: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_552f:
	/* 0x552f: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5537:
	/* 0x5537: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_553a:
	/* 0x553a: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5542:
	/* 0x5542: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_554b:
	/* 0x554b: lea    rdx,[r13+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_5552:
	/* 0x5552: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5557:
	/* 0x5557: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_555c:
	/* 0x555c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5561:
	/* 0x5561: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5566:
	/* 0x5566: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5568:
	/* 0x5568: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_556d:
	/* 0x556d: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_556f:
	/* 0x556f: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_5572:
	/* 0x5572: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_5578:
	/* 0x5578: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_557b:
	/* 0x557b: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_5581:
	/* 0x5581: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_5587:
	/* 0x5587: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_558c:
	/* 0x558c: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_5590:
	/* 0x5590: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5597:
	/* 0x5597: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_559c:
	/* 0x559c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_55a1:
	/* 0x55a1: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_55a8:
	/* 0x55a8: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_55ab:
	/* 0x55ab: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_55b2:
	/* 0x55b2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55b7:
	/* 0x55b7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_55bc:
	/* 0x55bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55be:
	/* 0x55be: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_55c2:
	/* 0x55c2: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_55c4:
	/* 0x55c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_55c6:
	/* 0x55c6: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_55cc:
	/* 0x55cc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_55cf:
	/* 0x55cf: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_55d5:
	/* 0x55d5: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_55db:
	/* 0x55db: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55e0:
	/* 0x55e0: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_55e4:
	/* 0x55e4: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_55eb:
	/* 0x55eb: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_55f0:
	/* 0x55f0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_55f5:
	/* 0x55f5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_55fa:
	/* 0x55fa: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5602:
	/* 0x5602: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5606:
	/* 0x5606: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_560d:
	/* 0x560d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5612:
	/* 0x5612: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5614:
	/* 0x5614: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_5619:
	/* 0x5619: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5621:
	/* 0x5621: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5624:
	/* 0x5624: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_562c:
	/* 0x562c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5635:
	/* 0x5635: add    r13,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_563c:
	/* 0x563c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5641:
	/* 0x5641: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5646:
	/* 0x5646: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_564b:
	/* 0x564b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5650:
	/* 0x5650: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5653:
	/* 0x5653: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5655:
	/* 0x5655: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_565a:
	/* 0x565a: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_565c:
	/* 0x565c: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_565f:
	/* 0x565f: je     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3034ULL;
	}
x86_l_5665:
	/* 0x5665: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5668:
	/* 0x5668: cmp    rax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27900ULL);
x86_l_566e:
	/* 0x566e: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_5674:
	/* 0x5674: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5679:
	/* 0x5679: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_567d:
	/* 0x567d: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5684:
	/* 0x5684: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5689:
	/* 0x5689: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_568e:
	/* 0x568e: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5695:
	/* 0x5695: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5698:
	/* 0x5698: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_569f:
	/* 0x569f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_56a4:
	/* 0x56a4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_56a9:
	/* 0x56a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56ab:
	/* 0x56ab: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
	return 22191ULL;
}

static __noinline __u64 tracee_syscall__execveat_enter_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 22191ULL: goto x86_l_56af;
	case 22193ULL: goto x86_l_56b1;
	case 22195ULL: goto x86_l_56b3;
	case 22201ULL: goto x86_l_56b9;
	case 22204ULL: goto x86_l_56bc;
	case 22210ULL: goto x86_l_56c2;
	case 22216ULL: goto x86_l_56c8;
	case 22221ULL: goto x86_l_56cd;
	case 22225ULL: goto x86_l_56d1;
	case 22232ULL: goto x86_l_56d8;
	case 22237ULL: goto x86_l_56dd;
	case 22242ULL: goto x86_l_56e2;
	case 22247ULL: goto x86_l_56e7;
	case 22255ULL: goto x86_l_56ef;
	case 22259ULL: goto x86_l_56f3;
	case 22266ULL: goto x86_l_56fa;
	case 22271ULL: goto x86_l_56ff;
	case 22273ULL: goto x86_l_5701;
	case 22278ULL: goto x86_l_5706;
	case 22286ULL: goto x86_l_570e;
	case 22289ULL: goto x86_l_5711;
	case 22297ULL: goto x86_l_5719;
	case 22308ULL: goto x86_l_5724;
	case 22311ULL: goto x86_l_5727;
	case 22317ULL: goto x86_l_572d;
	case 22319ULL: goto x86_l_572f;
	case 22324ULL: goto x86_l_5734;
	case 22328ULL: goto x86_l_5738;
	case 22331ULL: goto x86_l_573b;
	case 22336ULL: goto x86_l_5740;
	case 22340ULL: goto x86_l_5744;
	case 22347ULL: goto x86_l_574b;
	case 22355ULL: goto x86_l_5753;
	case 22360ULL: goto x86_l_5758;
	case 22365ULL: goto x86_l_575d;
	case 22372ULL: goto x86_l_5764;
	case 22375ULL: goto x86_l_5767;
	case 22382ULL: goto x86_l_576e;
	case 22387ULL: goto x86_l_5773;
	case 22389ULL: goto x86_l_5775;
	case 22396ULL: goto x86_l_577c;
	case 22398ULL: goto x86_l_577e;
	case 22400ULL: goto x86_l_5780;
	case 22406ULL: goto x86_l_5786;
	case 22409ULL: goto x86_l_5789;
	case 22415ULL: goto x86_l_578f;
	case 22420ULL: goto x86_l_5794;
	case 22425ULL: goto x86_l_5799;
	case 22431ULL: goto x86_l_579f;
	case 22436ULL: goto x86_l_57a4;
	case 22440ULL: goto x86_l_57a8;
	case 22447ULL: goto x86_l_57af;
	case 22455ULL: goto x86_l_57b7;
	case 22460ULL: goto x86_l_57bc;
	case 22465ULL: goto x86_l_57c1;
	case 22473ULL: goto x86_l_57c9;
	case 22477ULL: goto x86_l_57cd;
	case 22484ULL: goto x86_l_57d4;
	case 22489ULL: goto x86_l_57d9;
	case 22491ULL: goto x86_l_57db;
	case 22499ULL: goto x86_l_57e3;
	case 22507ULL: goto x86_l_57eb;
	case 22510ULL: goto x86_l_57ee;
	case 22518ULL: goto x86_l_57f6;
	case 22520ULL: goto x86_l_57f8;
	default: return 0xffffffffffffffffULL;
	}
x86_l_56af:
	/* 0x56af: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_56b1:
	/* 0x56b1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56b3:
	/* 0x56b3: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_56b9:
	/* 0x56b9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_56bc:
	/* 0x56bc: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_56c2:
	/* 0x56c2: ja     bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3034ULL;
	}
x86_l_56c8:
	/* 0x56c8: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56cd:
	/* 0x56cd: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_56d1:
	/* 0x56d1: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_56d8:
	/* 0x56d8: lea    rdx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_56dd:
	/* 0x56dd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_56e2:
	/* 0x56e2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_56e7:
	/* 0x56e7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_56ef:
	/* 0x56ef: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_56f3:
	/* 0x56f3: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_56fa:
	/* 0x56fa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_56ff:
	/* 0x56ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5701:
	/* 0x5701: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_5706:
	/* 0x5706: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_570e:
	/* 0x570e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5711:
	/* 0x5711: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5719:
	/* 0x5719: mov    DWORD PTR [rsp+0x94],0x2e2e2e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635658186286ULL);
x86_l_5724:
	/* 0x5724: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_5727:
	/* 0x5727: cmp    ecx,0x6cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27901ULL);
x86_l_572d:
	/* 0x572d: jb     5738 <syscall__execveat_enter+0x5738> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5738;
	}
x86_l_572f:
	/* 0x572f: mov    WORD PTR [rbx],0x6cfc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27900ULL);
x86_l_5734:
	/* 0x5734: mov    ax,0x6cfc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 27900ULL);
x86_l_5738:
	/* 0x5738: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_573b:
	/* 0x573b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5740:
	/* 0x5740: lea    rcx,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_5744:
	/* 0x5744: add    rcx,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_574b:
	/* 0x574b: lea    rdx,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_5753:
	/* 0x5753: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5758:
	/* 0x5758: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_575d:
	/* 0x575d: movzx  ecx,WORD PTR [rdi+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5764:
	/* 0x5764: add    rdi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5767:
	/* 0x5767: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_576e:
	/* 0x576e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5773:
	/* 0x5773: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5775:
	/* 0x5775: mov    DWORD PTR [rsp+0x84],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_577c:
	/* 0x577c: mov    cl,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 38ULL);
x86_l_577e:
	/* 0x577e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5780:
	/* 0x5780: jle    bda <syscall__execveat_enter+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3034ULL;
	}
x86_l_5786:
	/* 0x5786: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5789:
	/* 0x5789: cmp    rax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31996ULL);
x86_l_578f:
	/* 0x578f: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5794:
	/* 0x5794: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5799:
	/* 0x5799: ja     be4 <syscall__execveat_enter+0xbe4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3044ULL;
	}
x86_l_579f:
	/* 0x579f: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57a4:
	/* 0x57a4: lea    rcx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_57a8:
	/* 0x57a8: add    rcx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_57af:
	/* 0x57af: lea    rdx,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_57b7:
	/* 0x57b7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_57bc:
	/* 0x57bc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_57c1:
	/* 0x57c1: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_57c9:
	/* 0x57c9: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_57cd:
	/* 0x57cd: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_57d4:
	/* 0x57d4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_57d9:
	/* 0x57d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57db:
	/* 0x57db: movzx  eax,WORD PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 132ULL);
x86_l_57e3:
	/* 0x57e3: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_57eb:
	/* 0x57eb: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_57ee:
	/* 0x57ee: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_57f6:
	/* 0x57f6: mov    cl,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 39ULL);
x86_l_57f8:
	/* 0x57f8: jmp    be4 <syscall__execveat_enter+0xbe4> */
	return 3044ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_syscall__execveat_enter_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 18692U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1723ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1728ULL && __x86_pc <= 3384ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3391ULL && __x86_pc <= 5069ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5075ULL && __x86_pc <= 6962ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6965ULL && __x86_pc <= 8849ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8855ULL && __x86_pc <= 10763ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10768ULL && __x86_pc <= 12676ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12684ULL && __x86_pc <= 14574ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14579ULL && __x86_pc <= 16466ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 16471ULL && __x86_pc <= 18364ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 18370ULL && __x86_pc <= 20278ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 20283ULL && __x86_pc <= 22187ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 22191ULL && __x86_pc <= 22520ULL)
			__x86_pc = tracee_syscall__execveat_enter_x86_chunk_12(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

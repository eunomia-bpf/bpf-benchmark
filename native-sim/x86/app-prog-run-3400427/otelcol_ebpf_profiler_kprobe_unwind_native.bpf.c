extern char exe_id_to_10_stack_deltas;
extern char exe_id_to_11_stack_deltas;
extern char exe_id_to_12_stack_deltas;
extern char exe_id_to_13_stack_deltas;
extern char exe_id_to_14_stack_deltas;
extern char exe_id_to_15_stack_deltas;
extern char exe_id_to_16_stack_deltas;
extern char exe_id_to_17_stack_deltas;
extern char exe_id_to_18_stack_deltas;
extern char exe_id_to_19_stack_deltas;
extern char exe_id_to_20_stack_deltas;
extern char exe_id_to_21_stack_deltas;
extern char exe_id_to_22_stack_deltas;
extern char exe_id_to_23_stack_deltas;
extern char exe_id_to_8_stack_deltas;
extern char exe_id_to_9_stack_deltas;
extern char interpreter_offsets;
extern char metrics;
extern char per_cpu_records;
extern char perf_progs;
extern char pid_page_to_mapping_info;
extern char stack_delta_page_to_info;
extern char unwind_info_array;
extern char with_debug_output;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_0(
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
	case 70ULL: goto x86_l_46;
	case 73ULL: goto x86_l_49;
	case 80ULL: goto x86_l_50;
	case 85ULL: goto x86_l_55;
	case 91ULL: goto x86_l_5b;
	case 99ULL: goto x86_l_63;
	case 106ULL: goto x86_l_6a;
	case 111ULL: goto x86_l_6f;
	case 116ULL: goto x86_l_74;
	case 118ULL: goto x86_l_76;
	case 121ULL: goto x86_l_79;
	case 127ULL: goto x86_l_7f;
	case 130ULL: goto x86_l_82;
	case 135ULL: goto x86_l_87;
	case 141ULL: goto x86_l_8d;
	case 151ULL: goto x86_l_97;
	case 159ULL: goto x86_l_9f;
	case 169ULL: goto x86_l_a9;
	case 177ULL: goto x86_l_b1;
	case 187ULL: goto x86_l_bb;
	case 195ULL: goto x86_l_c3;
	case 205ULL: goto x86_l_cd;
	case 213ULL: goto x86_l_d5;
	case 223ULL: goto x86_l_df;
	case 231ULL: goto x86_l_e7;
	case 242ULL: goto x86_l_f2;
	case 250ULL: goto x86_l_fa;
	case 255ULL: goto x86_l_ff;
	case 261ULL: goto x86_l_105;
	case 268ULL: goto x86_l_10c;
	case 275ULL: goto x86_l_113;
	case 282ULL: goto x86_l_11a;
	case 287ULL: goto x86_l_11f;
	case 289ULL: goto x86_l_121;
	case 292ULL: goto x86_l_124;
	case 294ULL: goto x86_l_126;
	case 299ULL: goto x86_l_12b;
	case 305ULL: goto x86_l_131;
	case 311ULL: goto x86_l_137;
	case 315ULL: goto x86_l_13b;
	case 321ULL: goto x86_l_141;
	case 326ULL: goto x86_l_146;
	case 332ULL: goto x86_l_14c;
	case 340ULL: goto x86_l_154;
	case 347ULL: goto x86_l_15b;
	case 352ULL: goto x86_l_160;
	case 357ULL: goto x86_l_165;
	case 359ULL: goto x86_l_167;
	case 362ULL: goto x86_l_16a;
	case 368ULL: goto x86_l_170;
	case 371ULL: goto x86_l_173;
	case 374ULL: goto x86_l_176;
	case 379ULL: goto x86_l_17b;
	case 385ULL: goto x86_l_181;
	case 391ULL: goto x86_l_187;
	case 401ULL: goto x86_l_191;
	case 409ULL: goto x86_l_199;
	case 419ULL: goto x86_l_1a3;
	case 427ULL: goto x86_l_1ab;
	case 437ULL: goto x86_l_1b5;
	case 445ULL: goto x86_l_1bd;
	case 455ULL: goto x86_l_1c7;
	case 463ULL: goto x86_l_1cf;
	case 471ULL: goto x86_l_1d7;
	case 476ULL: goto x86_l_1dc;
	case 481ULL: goto x86_l_1e1;
	case 484ULL: goto x86_l_1e4;
	case 489ULL: goto x86_l_1e9;
	case 491ULL: goto x86_l_1eb;
	case 493ULL: goto x86_l_1ed;
	case 498ULL: goto x86_l_1f2;
	case 505ULL: goto x86_l_1f9;
	case 512ULL: goto x86_l_200;
	case 519ULL: goto x86_l_207;
	case 522ULL: goto x86_l_20a;
	case 528ULL: goto x86_l_210;
	case 532ULL: goto x86_l_214;
	case 540ULL: goto x86_l_21c;
	case 548ULL: goto x86_l_224;
	case 556ULL: goto x86_l_22c;
	case 563ULL: goto x86_l_233;
	case 574ULL: goto x86_l_23e;
	case 584ULL: goto x86_l_248;
	case 595ULL: goto x86_l_253;
	case 602ULL: goto x86_l_25a;
	case 610ULL: goto x86_l_262;
	case 615ULL: goto x86_l_267;
	case 622ULL: goto x86_l_26e;
	case 629ULL: goto x86_l_275;
	case 637ULL: goto x86_l_27d;
	case 642ULL: goto x86_l_282;
	case 648ULL: goto x86_l_288;
	case 655ULL: goto x86_l_28f;
	case 660ULL: goto x86_l_294;
	case 665ULL: goto x86_l_299;
	case 667ULL: goto x86_l_29b;
	case 670ULL: goto x86_l_29e;
	case 676ULL: goto x86_l_2a4;
	case 679ULL: goto x86_l_2a7;
	case 684ULL: goto x86_l_2ac;
	case 687ULL: goto x86_l_2af;
	case 691ULL: goto x86_l_2b3;
	case 695ULL: goto x86_l_2b7;
	case 698ULL: goto x86_l_2ba;
	case 700ULL: goto x86_l_2bc;
	case 703ULL: goto x86_l_2bf;
	case 705ULL: goto x86_l_2c1;
	case 708ULL: goto x86_l_2c4;
	case 714ULL: goto x86_l_2ca;
	case 717ULL: goto x86_l_2cd;
	case 723ULL: goto x86_l_2d3;
	case 726ULL: goto x86_l_2d6;
	case 732ULL: goto x86_l_2dc;
	case 739ULL: goto x86_l_2e3;
	case 744ULL: goto x86_l_2e8;
	case 749ULL: goto x86_l_2ed;
	case 755ULL: goto x86_l_2f3;
	case 761ULL: goto x86_l_2f9;
	case 764ULL: goto x86_l_2fc;
	case 769ULL: goto x86_l_301;
	case 772ULL: goto x86_l_304;
	case 774ULL: goto x86_l_306;
	case 777ULL: goto x86_l_309;
	case 783ULL: goto x86_l_30f;
	case 786ULL: goto x86_l_312;
	case 792ULL: goto x86_l_318;
	case 795ULL: goto x86_l_31b;
	case 801ULL: goto x86_l_321;
	case 808ULL: goto x86_l_328;
	case 813ULL: goto x86_l_32d;
	case 816ULL: goto x86_l_330;
	case 818ULL: goto x86_l_332;
	case 821ULL: goto x86_l_335;
	case 827ULL: goto x86_l_33b;
	case 830ULL: goto x86_l_33e;
	case 836ULL: goto x86_l_344;
	case 843ULL: goto x86_l_34b;
	case 848ULL: goto x86_l_350;
	case 851ULL: goto x86_l_353;
	case 853ULL: goto x86_l_355;
	case 856ULL: goto x86_l_358;
	case 862ULL: goto x86_l_35e;
	case 865ULL: goto x86_l_361;
	case 871ULL: goto x86_l_367;
	case 878ULL: goto x86_l_36e;
	case 883ULL: goto x86_l_373;
	case 886ULL: goto x86_l_376;
	case 892ULL: goto x86_l_37c;
	case 895ULL: goto x86_l_37f;
	case 901ULL: goto x86_l_385;
	case 908ULL: goto x86_l_38c;
	case 913ULL: goto x86_l_391;
	case 916ULL: goto x86_l_394;
	case 918ULL: goto x86_l_396;
	case 921ULL: goto x86_l_399;
	case 927ULL: goto x86_l_39f;
	case 934ULL: goto x86_l_3a6;
	case 936ULL: goto x86_l_3a8;
	case 939ULL: goto x86_l_3ab;
	case 941ULL: goto x86_l_3ad;
	case 944ULL: goto x86_l_3b0;
	case 950ULL: goto x86_l_3b6;
	case 957ULL: goto x86_l_3bd;
	case 959ULL: goto x86_l_3bf;
	case 962ULL: goto x86_l_3c2;
	case 964ULL: goto x86_l_3c4;
	case 967ULL: goto x86_l_3c7;
	case 973ULL: goto x86_l_3cd;
	case 980ULL: goto x86_l_3d4;
	case 982ULL: goto x86_l_3d6;
	case 989ULL: goto x86_l_3dd;
	case 991ULL: goto x86_l_3df;
	case 998ULL: goto x86_l_3e6;
	case 1000ULL: goto x86_l_3e8;
	case 1007ULL: goto x86_l_3ef;
	case 1009ULL: goto x86_l_3f1;
	case 1016ULL: goto x86_l_3f8;
	case 1018ULL: goto x86_l_3fa;
	case 1025ULL: goto x86_l_401;
	case 1027ULL: goto x86_l_403;
	case 1034ULL: goto x86_l_40a;
	case 1036ULL: goto x86_l_40c;
	case 1043ULL: goto x86_l_413;
	case 1045ULL: goto x86_l_415;
	case 1052ULL: goto x86_l_41c;
	case 1060ULL: goto x86_l_424;
	case 1065ULL: goto x86_l_429;
	case 1067ULL: goto x86_l_42b;
	case 1070ULL: goto x86_l_42e;
	case 1076ULL: goto x86_l_434;
	case 1079ULL: goto x86_l_437;
	case 1082ULL: goto x86_l_43a;
	case 1090ULL: goto x86_l_442;
	case 1097ULL: goto x86_l_449;
	case 1102ULL: goto x86_l_44e;
	case 1107ULL: goto x86_l_453;
	case 1110ULL: goto x86_l_456;
	case 1116ULL: goto x86_l_45c;
	case 1119ULL: goto x86_l_45f;
	case 1126ULL: goto x86_l_466;
	case 1129ULL: goto x86_l_469;
	case 1135ULL: goto x86_l_46f;
	case 1139ULL: goto x86_l_473;
	case 1141ULL: goto x86_l_475;
	case 1145ULL: goto x86_l_479;
	case 1150ULL: goto x86_l_47e;
	case 1155ULL: goto x86_l_483;
	case 1158ULL: goto x86_l_486;
	case 1160ULL: goto x86_l_488;
	case 1163ULL: goto x86_l_48b;
	case 1169ULL: goto x86_l_491;
	case 1173ULL: goto x86_l_495;
	case 1176ULL: goto x86_l_498;
	case 1181ULL: goto x86_l_49d;
	case 1184ULL: goto x86_l_4a0;
	case 1188ULL: goto x86_l_4a4;
	case 1192ULL: goto x86_l_4a8;
	case 1195ULL: goto x86_l_4ab;
	case 1201ULL: goto x86_l_4b1;
	case 1206ULL: goto x86_l_4b6;
	case 1208ULL: goto x86_l_4b8;
	case 1212ULL: goto x86_l_4bc;
	case 1217ULL: goto x86_l_4c1;
	case 1222ULL: goto x86_l_4c6;
	case 1225ULL: goto x86_l_4c9;
	case 1227ULL: goto x86_l_4cb;
	case 1230ULL: goto x86_l_4ce;
	case 1236ULL: goto x86_l_4d4;
	case 1240ULL: goto x86_l_4d8;
	case 1244ULL: goto x86_l_4dc;
	case 1249ULL: goto x86_l_4e1;
	case 1252ULL: goto x86_l_4e4;
	case 1256ULL: goto x86_l_4e8;
	case 1260ULL: goto x86_l_4ec;
	case 1263ULL: goto x86_l_4ef;
	case 1269ULL: goto x86_l_4f5;
	case 1273ULL: goto x86_l_4f9;
	case 1275ULL: goto x86_l_4fb;
	case 1279ULL: goto x86_l_4ff;
	case 1284ULL: goto x86_l_504;
	case 1289ULL: goto x86_l_509;
	case 1292ULL: goto x86_l_50c;
	case 1294ULL: goto x86_l_50e;
	case 1297ULL: goto x86_l_511;
	case 1303ULL: goto x86_l_517;
	case 1307ULL: goto x86_l_51b;
	case 1310ULL: goto x86_l_51e;
	case 1315ULL: goto x86_l_523;
	case 1318ULL: goto x86_l_526;
	case 1322ULL: goto x86_l_52a;
	case 1326ULL: goto x86_l_52e;
	case 1329ULL: goto x86_l_531;
	case 1335ULL: goto x86_l_537;
	case 1340ULL: goto x86_l_53c;
	case 1342ULL: goto x86_l_53e;
	case 1346ULL: goto x86_l_542;
	case 1351ULL: goto x86_l_547;
	case 1356ULL: goto x86_l_54c;
	case 1359ULL: goto x86_l_54f;
	case 1361ULL: goto x86_l_551;
	case 1364ULL: goto x86_l_554;
	case 1370ULL: goto x86_l_55a;
	case 1374ULL: goto x86_l_55e;
	case 1378ULL: goto x86_l_562;
	case 1383ULL: goto x86_l_567;
	case 1386ULL: goto x86_l_56a;
	case 1390ULL: goto x86_l_56e;
	case 1394ULL: goto x86_l_572;
	case 1397ULL: goto x86_l_575;
	case 1403ULL: goto x86_l_57b;
	case 1407ULL: goto x86_l_57f;
	case 1409ULL: goto x86_l_581;
	case 1413ULL: goto x86_l_585;
	case 1418ULL: goto x86_l_58a;
	case 1423ULL: goto x86_l_58f;
	case 1426ULL: goto x86_l_592;
	case 1428ULL: goto x86_l_594;
	case 1431ULL: goto x86_l_597;
	case 1437ULL: goto x86_l_59d;
	case 1441ULL: goto x86_l_5a1;
	case 1444ULL: goto x86_l_5a4;
	case 1449ULL: goto x86_l_5a9;
	case 1452ULL: goto x86_l_5ac;
	case 1456ULL: goto x86_l_5b0;
	case 1460ULL: goto x86_l_5b4;
	case 1463ULL: goto x86_l_5b7;
	case 1469ULL: goto x86_l_5bd;
	case 1474ULL: goto x86_l_5c2;
	case 1476ULL: goto x86_l_5c4;
	case 1480ULL: goto x86_l_5c8;
	case 1485ULL: goto x86_l_5cd;
	case 1490ULL: goto x86_l_5d2;
	case 1493ULL: goto x86_l_5d5;
	case 1495ULL: goto x86_l_5d7;
	case 1498ULL: goto x86_l_5da;
	case 1504ULL: goto x86_l_5e0;
	case 1508ULL: goto x86_l_5e4;
	case 1512ULL: goto x86_l_5e8;
	case 1517ULL: goto x86_l_5ed;
	case 1520ULL: goto x86_l_5f0;
	case 1524ULL: goto x86_l_5f4;
	case 1528ULL: goto x86_l_5f8;
	case 1531ULL: goto x86_l_5fb;
	case 1537ULL: goto x86_l_601;
	case 1541ULL: goto x86_l_605;
	case 1543ULL: goto x86_l_607;
	case 1547ULL: goto x86_l_60b;
	case 1552ULL: goto x86_l_610;
	case 1557ULL: goto x86_l_615;
	case 1560ULL: goto x86_l_618;
	case 1562ULL: goto x86_l_61a;
	case 1565ULL: goto x86_l_61d;
	case 1571ULL: goto x86_l_623;
	case 1575ULL: goto x86_l_627;
	case 1578ULL: goto x86_l_62a;
	case 1583ULL: goto x86_l_62f;
	case 1586ULL: goto x86_l_632;
	case 1590ULL: goto x86_l_636;
	case 1594ULL: goto x86_l_63a;
	case 1597ULL: goto x86_l_63d;
	case 1603ULL: goto x86_l_643;
	case 1608ULL: goto x86_l_648;
	case 1610ULL: goto x86_l_64a;
	case 1614ULL: goto x86_l_64e;
	case 1619ULL: goto x86_l_653;
	case 1624ULL: goto x86_l_658;
	case 1627ULL: goto x86_l_65b;
	case 1629ULL: goto x86_l_65d;
	case 1632ULL: goto x86_l_660;
	case 1638ULL: goto x86_l_666;
	case 1642ULL: goto x86_l_66a;
	case 1646ULL: goto x86_l_66e;
	case 1651ULL: goto x86_l_673;
	case 1654ULL: goto x86_l_676;
	case 1658ULL: goto x86_l_67a;
	case 1662ULL: goto x86_l_67e;
	case 1665ULL: goto x86_l_681;
	case 1671ULL: goto x86_l_687;
	case 1675ULL: goto x86_l_68b;
	case 1677ULL: goto x86_l_68d;
	case 1681ULL: goto x86_l_691;
	case 1686ULL: goto x86_l_696;
	case 1691ULL: goto x86_l_69b;
	case 1694ULL: goto x86_l_69e;
	case 1696ULL: goto x86_l_6a0;
	case 1699ULL: goto x86_l_6a3;
	case 1705ULL: goto x86_l_6a9;
	case 1709ULL: goto x86_l_6ad;
	case 1712ULL: goto x86_l_6b0;
	case 1717ULL: goto x86_l_6b5;
	case 1720ULL: goto x86_l_6b8;
	case 1724ULL: goto x86_l_6bc;
	case 1728ULL: goto x86_l_6c0;
	case 1731ULL: goto x86_l_6c3;
	case 1737ULL: goto x86_l_6c9;
	case 1742ULL: goto x86_l_6ce;
	case 1744ULL: goto x86_l_6d0;
	case 1748ULL: goto x86_l_6d4;
	case 1753ULL: goto x86_l_6d9;
	case 1758ULL: goto x86_l_6de;
	case 1761ULL: goto x86_l_6e1;
	case 1763ULL: goto x86_l_6e3;
	case 1766ULL: goto x86_l_6e6;
	case 1772ULL: goto x86_l_6ec;
	case 1776ULL: goto x86_l_6f0;
	case 1780ULL: goto x86_l_6f4;
	case 1785ULL: goto x86_l_6f9;
	case 1788ULL: goto x86_l_6fc;
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
	/* 0xa: sub    rsp,0x168 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 360ULL);
x86_l_11:
	/* 0x11: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    DWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_1f:
	/* 0x1f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&per_cpu_records)));
x86_l_26:
	/* 0x26: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
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
	/* 0x38: je     601e <kprobe_unwind_native+0x601e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24606ULL;
	}
x86_l_3e:
	/* 0x3e: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_46:
	/* 0x46: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_49:
	/* 0x49: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_50:
	/* 0x50: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55:
	/* 0x55: jne    ec4 <kprobe_unwind_native+0xec4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3780ULL;
	}
x86_l_5b:
	/* 0x5b: mov    DWORD PTR [rsp+0x10],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476741ULL);
x86_l_63:
	/* 0x63: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_6a:
	/* 0x6a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6f:
	/* 0x6f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_74:
	/* 0x74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76:
	/* 0x76: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_79:
	/* 0x79: je     126 <kprobe_unwind_native+0x126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_126;
	}
x86_l_7f:
	/* 0x7f: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_82:
	/* 0x82: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_87:
	/* 0x87: je     131 <kprobe_unwind_native+0x131> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_131;
	}
x86_l_8d:
	/* 0x8d: movabs rax,0x63617473206e6f20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7161132920309968672ULL);
x86_l_97:
	/* 0x97: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_9f:
	/* 0x9f: movabs rax,0x7525206e6f697469 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8441188735263536233ULL);
x86_l_a9:
	/* 0xa9: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_b1:
	/* 0xb1: movabs rax,0x736f70206f742078 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8317990321387741304ULL);
x86_l_bb:
	/* 0xbb: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_c3:
	/* 0xc3: movabs rax,0x6c6c2520786c6c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660274970520613ULL);
x86_l_cd:
	/* 0xcd: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_d5:
	/* 0xd5: movabs rax,0x20676e6968737550 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334956330817910096ULL);
x86_l_df:
	/* 0xdf: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_e7:
	/* 0xe7: mov    DWORD PTR [rsp+0xc7],0xa6b63 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 854699174755ULL);
x86_l_f2:
	/* 0xf2: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_fa:
	/* 0xfa: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_ff:
	/* 0xff: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_105:
	/* 0x105: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_10c:
	/* 0x10c: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_113:
	/* 0x113: mov    r8d,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_11a:
	/* 0x11a: mov    esi,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 43ULL);
x86_l_11f:
	/* 0x11f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_121:
	/* 0x121: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_124:
	/* 0x124: jmp    131 <kprobe_unwind_native+0x131> */
	goto x86_l_131;
x86_l_126:
	/* 0x126: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12b:
	/* 0x12b: jne    1013 <kprobe_unwind_native+0x1013> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4115ULL;
	}
x86_l_131:
	/* 0x131: mov    eax,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_137:
	/* 0x137: cmp    rax,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 127ULL);
x86_l_13b:
	/* 0x13b: jb     1f2 <kprobe_unwind_native+0x1f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f2;
	}
x86_l_141:
	/* 0x141: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_146:
	/* 0x146: jne    f2b <kprobe_unwind_native+0xf2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3883ULL;
	}
x86_l_14c:
	/* 0x14c: mov    DWORD PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_154:
	/* 0x154: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_15b:
	/* 0x15b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_160:
	/* 0x160: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_165:
	/* 0x165: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_167:
	/* 0x167: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16a:
	/* 0x16a: je     2e8 <kprobe_unwind_native+0x2e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e8;
	}
x86_l_170:
	/* 0x170: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_173:
	/* 0x173: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_176:
	/* 0x176: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17b:
	/* 0x17b: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_181:
	/* 0x181: je     5f60 <kprobe_unwind_native+0x5f60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24416ULL;
	}
x86_l_187:
	/* 0x187: movabs rax,0xa656d61726620 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926270227834400ULL);
x86_l_191:
	/* 0x191: mov    QWORD PTR [rsp+0xb5],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 181ULL);
x86_l_199:
	/* 0x199: movabs rax,0x7266206576697461 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243311788098679905ULL);
x86_l_1a3:
	/* 0x1a3: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1ab:
	/* 0x1ab: movabs rax,0x6e2068737570206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7935457388527624303ULL);
x86_l_1b5:
	/* 0x1b5: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1bd:
	/* 0x1bd: movabs rax,0x742064656c696166 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701606ULL);
x86_l_1c7:
	/* 0x1c7: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1cf:
	/* 0x1cf: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1d7:
	/* 0x1d7: mov    eax,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_1dc:
	/* 0x1dc: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1e1:
	/* 0x1e1: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e4:
	/* 0x1e4: mov    esi,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 29ULL);
x86_l_1e9:
	/* 0x1e9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1eb:
	/* 0x1eb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1ed:
	/* 0x1ed: jmp    5f60 <kprobe_unwind_native+0x5f60> */
	return 24416ULL;
x86_l_1f2:
	/* 0x1f2: movzx  ecx,BYTE PTR [rbx+0xf30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3888ULL);
x86_l_1f9:
	/* 0x1f9: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_200:
	/* 0x200: mov    rsi,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_207:
	/* 0x207: lea    edi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_20a:
	/* 0x20a: mov    DWORD PTR [rbx+0x2c0],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_210:
	/* 0x210: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_214:
	/* 0x214: mov    QWORD PTR [rbx+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_21c:
	/* 0x21c: mov    QWORD PTR [rbx+rax*8+0x2d8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_224:
	/* 0x224: mov    BYTE PTR [rbx+rax*8+0x2e0],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 3161095929859ULL);
x86_l_22c:
	/* 0x22c: mov    BYTE PTR [rbx+rax*8+0x2e1],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 737ULL);
x86_l_233:
	/* 0x233: mov    DWORD PTR [rbx+rax*8+0x2e2],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3169685864448ULL);
x86_l_23e:
	/* 0x23e: mov    WORD PTR [rbx+rax*8+0x2e6],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3186865733632ULL);
x86_l_248:
	/* 0x248: mov    DWORD PTR [rsp+0x8c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_253:
	/* 0x253: mov    rax,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_25a:
	/* 0x25a: mov    QWORD PTR [rsp+0x160],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_262:
	/* 0x262: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_267:
	/* 0x267: mov    rax,0xffffffffffff0000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 18446744073709486080ULL);
x86_l_26e:
	/* 0x26e: and    rax,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 3864ULL);
x86_l_275:
	/* 0x275: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_27d:
	/* 0x27d: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_282:
	/* 0x282: jne    fa5 <kprobe_unwind_native+0xfa5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4005ULL;
	}
x86_l_288:
	/* 0x288: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&stack_delta_page_to_info)));
x86_l_28f:
	/* 0x28f: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_294:
	/* 0x294: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_299:
	/* 0x299: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29b:
	/* 0x29b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29e:
	/* 0x29e: je     56a4 <kprobe_unwind_native+0x56a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22180ULL;
	}
x86_l_2a4:
	/* 0x2a4: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_2a7:
	/* 0x2a7: mov    QWORD PTR [rsp+0x68],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2ac:
	/* 0x2ac: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2af:
	/* 0x2af: add    rbp,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_2b3:
	/* 0x2b3: movzx  eax,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_2b7:
	/* 0x2b7: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_2ba:
	/* 0x2ba: jg     301 <kprobe_unwind_native+0x301> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_301;
	}
x86_l_2bc:
	/* 0x2bc: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_2bf:
	/* 0x2bf: jg     32d <kprobe_unwind_native+0x32d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_32d;
	}
x86_l_2c1:
	/* 0x2c1: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_2c4:
	/* 0x2c4: jg     373 <kprobe_unwind_native+0x373> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_373;
	}
x86_l_2ca:
	/* 0x2ca: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_2cd:
	/* 0x2cd: je     3d6 <kprobe_unwind_native+0x3d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d6;
	}
x86_l_2d3:
	/* 0x2d3: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_2d6:
	/* 0x2d6: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_2dc:
	/* 0x2dc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_9_stack_deltas)));
x86_l_2e3:
	/* 0x2e3: jmp    41c <kprobe_unwind_native+0x41c> */
	goto x86_l_41c;
x86_l_2e8:
	/* 0x2e8: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ed:
	/* 0x2ed: jne    10ae <kprobe_unwind_native+0x10ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4270ULL;
	}
x86_l_2f3:
	/* 0x2f3: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_2f9:
	/* 0x2f9: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fc:
	/* 0x2fc: jmp    5f60 <kprobe_unwind_native+0x5f60> */
	return 24416ULL;
x86_l_301:
	/* 0x301: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_304:
	/* 0x304: jg     350 <kprobe_unwind_native+0x350> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_350;
	}
x86_l_306:
	/* 0x306: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_309:
	/* 0x309: jg     391 <kprobe_unwind_native+0x391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_391;
	}
x86_l_30f:
	/* 0x30f: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_312:
	/* 0x312: je     3df <kprobe_unwind_native+0x3df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3df;
	}
x86_l_318:
	/* 0x318: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_31b:
	/* 0x31b: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_321:
	/* 0x321: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_17_stack_deltas)));
x86_l_328:
	/* 0x328: jmp    41c <kprobe_unwind_native+0x41c> */
	goto x86_l_41c;
x86_l_32d:
	/* 0x32d: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_330:
	/* 0x330: jg     3a8 <kprobe_unwind_native+0x3a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3a8;
	}
x86_l_332:
	/* 0x332: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_335:
	/* 0x335: je     3e8 <kprobe_unwind_native+0x3e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e8;
	}
x86_l_33b:
	/* 0x33b: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_33e:
	/* 0x33e: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_344:
	/* 0x344: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_13_stack_deltas)));
x86_l_34b:
	/* 0x34b: jmp    41c <kprobe_unwind_native+0x41c> */
	goto x86_l_41c;
x86_l_350:
	/* 0x350: cmp    eax,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_353:
	/* 0x353: jg     3bf <kprobe_unwind_native+0x3bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3bf;
	}
x86_l_355:
	/* 0x355: cmp    eax,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 20ULL);
x86_l_358:
	/* 0x358: je     3f1 <kprobe_unwind_native+0x3f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f1;
	}
x86_l_35e:
	/* 0x35e: cmp    eax,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_361:
	/* 0x361: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_367:
	/* 0x367: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_21_stack_deltas)));
x86_l_36e:
	/* 0x36e: jmp    41c <kprobe_unwind_native+0x41c> */
	goto x86_l_41c;
x86_l_373:
	/* 0x373: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_376:
	/* 0x376: je     3fa <kprobe_unwind_native+0x3fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fa;
	}
x86_l_37c:
	/* 0x37c: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_37f:
	/* 0x37f: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_385:
	/* 0x385: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_11_stack_deltas)));
x86_l_38c:
	/* 0x38c: jmp    41c <kprobe_unwind_native+0x41c> */
	goto x86_l_41c;
x86_l_391:
	/* 0x391: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_394:
	/* 0x394: je     403 <kprobe_unwind_native+0x403> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_403;
	}
x86_l_396:
	/* 0x396: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_399:
	/* 0x399: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_39f:
	/* 0x39f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_19_stack_deltas)));
x86_l_3a6:
	/* 0x3a6: jmp    41c <kprobe_unwind_native+0x41c> */
	goto x86_l_41c;
x86_l_3a8:
	/* 0x3a8: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3ab:
	/* 0x3ab: je     40c <kprobe_unwind_native+0x40c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40c;
	}
x86_l_3ad:
	/* 0x3ad: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_3b0:
	/* 0x3b0: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_3b6:
	/* 0x3b6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_15_stack_deltas)));
x86_l_3bd:
	/* 0x3bd: jmp    41c <kprobe_unwind_native+0x41c> */
	goto x86_l_41c;
x86_l_3bf:
	/* 0x3bf: cmp    eax,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 22ULL);
x86_l_3c2:
	/* 0x3c2: je     415 <kprobe_unwind_native+0x415> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_415;
	}
x86_l_3c4:
	/* 0x3c4: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_3c7:
	/* 0x3c7: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_3cd:
	/* 0x3cd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_23_stack_deltas)));
x86_l_3d4:
	/* 0x3d4: jmp    41c <kprobe_unwind_native+0x41c> */
	goto x86_l_41c;
x86_l_3d6:
	/* 0x3d6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_8_stack_deltas)));
x86_l_3dd:
	/* 0x3dd: jmp    41c <kprobe_unwind_native+0x41c> */
	goto x86_l_41c;
x86_l_3df:
	/* 0x3df: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_16_stack_deltas)));
x86_l_3e6:
	/* 0x3e6: jmp    41c <kprobe_unwind_native+0x41c> */
	goto x86_l_41c;
x86_l_3e8:
	/* 0x3e8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_12_stack_deltas)));
x86_l_3ef:
	/* 0x3ef: jmp    41c <kprobe_unwind_native+0x41c> */
	goto x86_l_41c;
x86_l_3f1:
	/* 0x3f1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_20_stack_deltas)));
x86_l_3f8:
	/* 0x3f8: jmp    41c <kprobe_unwind_native+0x41c> */
	goto x86_l_41c;
x86_l_3fa:
	/* 0x3fa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_10_stack_deltas)));
x86_l_401:
	/* 0x401: jmp    41c <kprobe_unwind_native+0x41c> */
	goto x86_l_41c;
x86_l_403:
	/* 0x403: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_18_stack_deltas)));
x86_l_40a:
	/* 0x40a: jmp    41c <kprobe_unwind_native+0x41c> */
	goto x86_l_41c;
x86_l_40c:
	/* 0x40c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_14_stack_deltas)));
x86_l_413:
	/* 0x413: jmp    41c <kprobe_unwind_native+0x41c> */
	goto x86_l_41c;
x86_l_415:
	/* 0x415: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_22_stack_deltas)));
x86_l_41c:
	/* 0x41c: lea    rsi,[rsp+0x160] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_424:
	/* 0x424: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_429:
	/* 0x429: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42b:
	/* 0x42b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_42e:
	/* 0x42e: je     5f2b <kprobe_unwind_native+0x5f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24363ULL;
	}
x86_l_434:
	/* 0x434: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_437:
	/* 0x437: mov    r12d,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43a:
	/* 0x43a: mov    DWORD PTR [rsp+0x90],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_442:
	/* 0x442: mov    rax,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_449:
	/* 0x449: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_44e:
	/* 0x44e: movzx  r13d,WORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_453:
	/* 0x453: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_456:
	/* 0x456: je     8a5 <kprobe_unwind_native+0x8a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2213ULL;
	}
x86_l_45c:
	/* 0x45c: add    r13d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_45f:
	/* 0x45f: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_466:
	/* 0x466: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_469:
	/* 0x469: jne    1152 <kprobe_unwind_native+0x1152> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4434ULL;
	}
x86_l_46f:
	/* 0x46f: lea    eax,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_473:
	/* 0x473: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_475:
	/* 0x475: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_479:
	/* 0x479: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47e:
	/* 0x47e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_483:
	/* 0x483: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_486:
	/* 0x486: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_488:
	/* 0x488: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_48b:
	/* 0x48b: je     969 <kprobe_unwind_native+0x969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2409ULL;
	}
x86_l_491:
	/* 0x491: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_495:
	/* 0x495: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_498:
	/* 0x498: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_49d:
	/* 0x49d: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a0:
	/* 0x4a0: cmova  ebp,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R12, X86_WIDTH_32, X86_CC_A);
x86_l_4a4:
	/* 0x4a4: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_4a8:
	/* 0x4a8: cmp    ebp,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_4ab:
	/* 0x4ab: jae    899 <kprobe_unwind_native+0x899> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2201ULL;
	}
x86_l_4b1:
	/* 0x4b1: lea    eax,[r13+rbp*1+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4b6:
	/* 0x4b6: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_4b8:
	/* 0x4b8: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4bc:
	/* 0x4bc: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c1:
	/* 0x4c1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4c6:
	/* 0x4c6: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_4c9:
	/* 0x4c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cb:
	/* 0x4cb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4ce:
	/* 0x4ce: je     969 <kprobe_unwind_native+0x969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2409ULL;
	}
x86_l_4d4:
	/* 0x4d4: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d8:
	/* 0x4d8: lea    r12d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4dc:
	/* 0x4dc: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4e1:
	/* 0x4e1: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e4:
	/* 0x4e4: cmova  r12d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_4e8:
	/* 0x4e8: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_4ec:
	/* 0x4ec: cmp    r12d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R13, X86_WIDTH_32);
x86_l_4ef:
	/* 0x4ef: jae    899 <kprobe_unwind_native+0x899> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2201ULL;
	}
x86_l_4f5:
	/* 0x4f5: lea    eax,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_4f9:
	/* 0x4f9: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_4fb:
	/* 0x4fb: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ff:
	/* 0x4ff: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_504:
	/* 0x504: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_509:
	/* 0x509: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_50c:
	/* 0x50c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50e:
	/* 0x50e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_511:
	/* 0x511: je     969 <kprobe_unwind_native+0x969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2409ULL;
	}
x86_l_517:
	/* 0x517: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51b:
	/* 0x51b: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_51e:
	/* 0x51e: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_523:
	/* 0x523: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_526:
	/* 0x526: cmova  ebp,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R12, X86_WIDTH_32, X86_CC_A);
x86_l_52a:
	/* 0x52a: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_52e:
	/* 0x52e: cmp    ebp,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_531:
	/* 0x531: jae    899 <kprobe_unwind_native+0x899> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2201ULL;
	}
x86_l_537:
	/* 0x537: lea    eax,[r13+rbp*1+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_53c:
	/* 0x53c: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_53e:
	/* 0x53e: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_542:
	/* 0x542: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_547:
	/* 0x547: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_54c:
	/* 0x54c: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_54f:
	/* 0x54f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_551:
	/* 0x551: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_554:
	/* 0x554: je     969 <kprobe_unwind_native+0x969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2409ULL;
	}
x86_l_55a:
	/* 0x55a: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55e:
	/* 0x55e: lea    r12d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_562:
	/* 0x562: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_567:
	/* 0x567: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56a:
	/* 0x56a: cmova  r12d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_56e:
	/* 0x56e: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_572:
	/* 0x572: cmp    r12d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R13, X86_WIDTH_32);
x86_l_575:
	/* 0x575: jae    899 <kprobe_unwind_native+0x899> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2201ULL;
	}
x86_l_57b:
	/* 0x57b: lea    eax,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_57f:
	/* 0x57f: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_581:
	/* 0x581: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_585:
	/* 0x585: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_58a:
	/* 0x58a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_58f:
	/* 0x58f: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_592:
	/* 0x592: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_594:
	/* 0x594: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_597:
	/* 0x597: je     969 <kprobe_unwind_native+0x969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2409ULL;
	}
x86_l_59d:
	/* 0x59d: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a1:
	/* 0x5a1: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5a4:
	/* 0x5a4: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5a9:
	/* 0x5a9: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ac:
	/* 0x5ac: cmova  ebp,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R12, X86_WIDTH_32, X86_CC_A);
x86_l_5b0:
	/* 0x5b0: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5b4:
	/* 0x5b4: cmp    ebp,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_5b7:
	/* 0x5b7: jae    899 <kprobe_unwind_native+0x899> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2201ULL;
	}
x86_l_5bd:
	/* 0x5bd: lea    eax,[r13+rbp*1+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5c2:
	/* 0x5c2: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5c4:
	/* 0x5c4: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c8:
	/* 0x5c8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5cd:
	/* 0x5cd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5d2:
	/* 0x5d2: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_5d5:
	/* 0x5d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d7:
	/* 0x5d7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5da:
	/* 0x5da: je     969 <kprobe_unwind_native+0x969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2409ULL;
	}
x86_l_5e0:
	/* 0x5e0: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e4:
	/* 0x5e4: lea    r12d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5e8:
	/* 0x5e8: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5ed:
	/* 0x5ed: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f0:
	/* 0x5f0: cmova  r12d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_5f4:
	/* 0x5f4: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5f8:
	/* 0x5f8: cmp    r12d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R13, X86_WIDTH_32);
x86_l_5fb:
	/* 0x5fb: jae    899 <kprobe_unwind_native+0x899> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2201ULL;
	}
x86_l_601:
	/* 0x601: lea    eax,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_605:
	/* 0x605: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_607:
	/* 0x607: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_60b:
	/* 0x60b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_610:
	/* 0x610: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_615:
	/* 0x615: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_618:
	/* 0x618: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61a:
	/* 0x61a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_61d:
	/* 0x61d: je     969 <kprobe_unwind_native+0x969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2409ULL;
	}
x86_l_623:
	/* 0x623: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_627:
	/* 0x627: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_62a:
	/* 0x62a: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_62f:
	/* 0x62f: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_632:
	/* 0x632: cmova  ebp,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R12, X86_WIDTH_32, X86_CC_A);
x86_l_636:
	/* 0x636: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_63a:
	/* 0x63a: cmp    ebp,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_63d:
	/* 0x63d: jae    899 <kprobe_unwind_native+0x899> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2201ULL;
	}
x86_l_643:
	/* 0x643: lea    eax,[r13+rbp*1+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_648:
	/* 0x648: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_64a:
	/* 0x64a: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64e:
	/* 0x64e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_653:
	/* 0x653: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_658:
	/* 0x658: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_65b:
	/* 0x65b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65d:
	/* 0x65d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_660:
	/* 0x660: je     969 <kprobe_unwind_native+0x969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2409ULL;
	}
x86_l_666:
	/* 0x666: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_66a:
	/* 0x66a: lea    r12d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_66e:
	/* 0x66e: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_673:
	/* 0x673: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_676:
	/* 0x676: cmova  r12d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_67a:
	/* 0x67a: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_67e:
	/* 0x67e: cmp    r12d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R13, X86_WIDTH_32);
x86_l_681:
	/* 0x681: jae    899 <kprobe_unwind_native+0x899> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2201ULL;
	}
x86_l_687:
	/* 0x687: lea    eax,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_68b:
	/* 0x68b: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_68d:
	/* 0x68d: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_691:
	/* 0x691: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_696:
	/* 0x696: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_69b:
	/* 0x69b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_69e:
	/* 0x69e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a0:
	/* 0x6a0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6a3:
	/* 0x6a3: je     969 <kprobe_unwind_native+0x969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2409ULL;
	}
x86_l_6a9:
	/* 0x6a9: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6ad:
	/* 0x6ad: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_6b0:
	/* 0x6b0: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6b5:
	/* 0x6b5: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6b8:
	/* 0x6b8: cmova  ebp,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R12, X86_WIDTH_32, X86_CC_A);
x86_l_6bc:
	/* 0x6bc: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_6c0:
	/* 0x6c0: cmp    ebp,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_6c3:
	/* 0x6c3: jae    899 <kprobe_unwind_native+0x899> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2201ULL;
	}
x86_l_6c9:
	/* 0x6c9: lea    eax,[r13+rbp*1+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_6ce:
	/* 0x6ce: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_6d0:
	/* 0x6d0: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6d4:
	/* 0x6d4: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6d9:
	/* 0x6d9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6de:
	/* 0x6de: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6e1:
	/* 0x6e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e3:
	/* 0x6e3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6e6:
	/* 0x6e6: je     969 <kprobe_unwind_native+0x969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2409ULL;
	}
x86_l_6ec:
	/* 0x6ec: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6f0:
	/* 0x6f0: lea    r12d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_6f4:
	/* 0x6f4: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6f9:
	/* 0x6f9: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6fc:
	/* 0x6fc: cmova  r12d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_32, X86_CC_A);
	return 1792ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1792ULL: goto x86_l_700;
	case 1796ULL: goto x86_l_704;
	case 1799ULL: goto x86_l_707;
	case 1805ULL: goto x86_l_70d;
	case 1809ULL: goto x86_l_711;
	case 1811ULL: goto x86_l_713;
	case 1815ULL: goto x86_l_717;
	case 1820ULL: goto x86_l_71c;
	case 1825ULL: goto x86_l_721;
	case 1828ULL: goto x86_l_724;
	case 1830ULL: goto x86_l_726;
	case 1833ULL: goto x86_l_729;
	case 1839ULL: goto x86_l_72f;
	case 1843ULL: goto x86_l_733;
	case 1846ULL: goto x86_l_736;
	case 1851ULL: goto x86_l_73b;
	case 1854ULL: goto x86_l_73e;
	case 1858ULL: goto x86_l_742;
	case 1862ULL: goto x86_l_746;
	case 1865ULL: goto x86_l_749;
	case 1871ULL: goto x86_l_74f;
	case 1876ULL: goto x86_l_754;
	case 1878ULL: goto x86_l_756;
	case 1882ULL: goto x86_l_75a;
	case 1887ULL: goto x86_l_75f;
	case 1892ULL: goto x86_l_764;
	case 1895ULL: goto x86_l_767;
	case 1897ULL: goto x86_l_769;
	case 1900ULL: goto x86_l_76c;
	case 1906ULL: goto x86_l_772;
	case 1910ULL: goto x86_l_776;
	case 1914ULL: goto x86_l_77a;
	case 1919ULL: goto x86_l_77f;
	case 1922ULL: goto x86_l_782;
	case 1926ULL: goto x86_l_786;
	case 1930ULL: goto x86_l_78a;
	case 1933ULL: goto x86_l_78d;
	case 1939ULL: goto x86_l_793;
	case 1943ULL: goto x86_l_797;
	case 1945ULL: goto x86_l_799;
	case 1949ULL: goto x86_l_79d;
	case 1954ULL: goto x86_l_7a2;
	case 1959ULL: goto x86_l_7a7;
	case 1962ULL: goto x86_l_7aa;
	case 1964ULL: goto x86_l_7ac;
	case 1967ULL: goto x86_l_7af;
	case 1973ULL: goto x86_l_7b5;
	case 1977ULL: goto x86_l_7b9;
	case 1980ULL: goto x86_l_7bc;
	case 1985ULL: goto x86_l_7c1;
	case 1988ULL: goto x86_l_7c4;
	case 1992ULL: goto x86_l_7c8;
	case 1996ULL: goto x86_l_7cc;
	case 1999ULL: goto x86_l_7cf;
	case 2005ULL: goto x86_l_7d5;
	case 2010ULL: goto x86_l_7da;
	case 2012ULL: goto x86_l_7dc;
	case 2016ULL: goto x86_l_7e0;
	case 2021ULL: goto x86_l_7e5;
	case 2026ULL: goto x86_l_7ea;
	case 2029ULL: goto x86_l_7ed;
	case 2031ULL: goto x86_l_7ef;
	case 2034ULL: goto x86_l_7f2;
	case 2040ULL: goto x86_l_7f8;
	case 2044ULL: goto x86_l_7fc;
	case 2048ULL: goto x86_l_800;
	case 2053ULL: goto x86_l_805;
	case 2056ULL: goto x86_l_808;
	case 2060ULL: goto x86_l_80c;
	case 2064ULL: goto x86_l_810;
	case 2067ULL: goto x86_l_813;
	case 2073ULL: goto x86_l_819;
	case 2077ULL: goto x86_l_81d;
	case 2079ULL: goto x86_l_81f;
	case 2083ULL: goto x86_l_823;
	case 2088ULL: goto x86_l_828;
	case 2093ULL: goto x86_l_82d;
	case 2096ULL: goto x86_l_830;
	case 2098ULL: goto x86_l_832;
	case 2101ULL: goto x86_l_835;
	case 2107ULL: goto x86_l_83b;
	case 2111ULL: goto x86_l_83f;
	case 2114ULL: goto x86_l_842;
	case 2119ULL: goto x86_l_847;
	case 2122ULL: goto x86_l_84a;
	case 2126ULL: goto x86_l_84e;
	case 2130ULL: goto x86_l_852;
	case 2133ULL: goto x86_l_855;
	case 2135ULL: goto x86_l_857;
	case 2140ULL: goto x86_l_85c;
	case 2142ULL: goto x86_l_85e;
	case 2146ULL: goto x86_l_862;
	case 2151ULL: goto x86_l_867;
	case 2156ULL: goto x86_l_86c;
	case 2159ULL: goto x86_l_86f;
	case 2161ULL: goto x86_l_871;
	case 2164ULL: goto x86_l_874;
	case 2170ULL: goto x86_l_87a;
	case 2174ULL: goto x86_l_87e;
	case 2177ULL: goto x86_l_881;
	case 2182ULL: goto x86_l_886;
	case 2185ULL: goto x86_l_889;
	case 2188ULL: goto x86_l_88c;
	case 2192ULL: goto x86_l_890;
	case 2195ULL: goto x86_l_893;
	case 2201ULL: goto x86_l_899;
	case 2204ULL: goto x86_l_89c;
	case 2207ULL: goto x86_l_89f;
	case 2213ULL: goto x86_l_8a5;
	case 2216ULL: goto x86_l_8a8;
	case 2224ULL: goto x86_l_8b0;
	case 2232ULL: goto x86_l_8b8;
	case 2237ULL: goto x86_l_8bd;
	case 2240ULL: goto x86_l_8c0;
	case 2242ULL: goto x86_l_8c2;
	case 2247ULL: goto x86_l_8c7;
	case 2252ULL: goto x86_l_8cc;
	case 2255ULL: goto x86_l_8cf;
	case 2261ULL: goto x86_l_8d5;
	case 2268ULL: goto x86_l_8dc;
	case 2273ULL: goto x86_l_8e1;
	case 2279ULL: goto x86_l_8e7;
	case 2284ULL: goto x86_l_8ec;
	case 2287ULL: goto x86_l_8ef;
	case 2289ULL: goto x86_l_8f1;
	case 2296ULL: goto x86_l_8f8;
	case 2299ULL: goto x86_l_8fb;
	case 2305ULL: goto x86_l_901;
	case 2308ULL: goto x86_l_904;
	case 2312ULL: goto x86_l_908;
	case 2319ULL: goto x86_l_90f;
	case 2325ULL: goto x86_l_915;
	case 2333ULL: goto x86_l_91d;
	case 2339ULL: goto x86_l_923;
	case 2345ULL: goto x86_l_929;
	case 2351ULL: goto x86_l_92f;
	case 2362ULL: goto x86_l_93a;
	case 2369ULL: goto x86_l_941;
	case 2377ULL: goto x86_l_949;
	case 2382ULL: goto x86_l_94e;
	case 2384ULL: goto x86_l_950;
	case 2387ULL: goto x86_l_953;
	case 2393ULL: goto x86_l_959;
	case 2396ULL: goto x86_l_95c;
	case 2404ULL: goto x86_l_964;
	case 2409ULL: goto x86_l_969;
	case 2414ULL: goto x86_l_96e;
	case 2419ULL: goto x86_l_973;
	case 2426ULL: goto x86_l_97a;
	case 2429ULL: goto x86_l_97d;
	case 2435ULL: goto x86_l_983;
	case 2445ULL: goto x86_l_98d;
	case 2450ULL: goto x86_l_992;
	case 2460ULL: goto x86_l_99c;
	case 2465ULL: goto x86_l_9a1;
	case 2475ULL: goto x86_l_9ab;
	case 2480ULL: goto x86_l_9b0;
	case 2490ULL: goto x86_l_9ba;
	case 2495ULL: goto x86_l_9bf;
	case 2505ULL: goto x86_l_9c9;
	case 2510ULL: goto x86_l_9ce;
	case 2518ULL: goto x86_l_9d6;
	case 2523ULL: goto x86_l_9db;
	case 2528ULL: goto x86_l_9e0;
	case 2533ULL: goto x86_l_9e5;
	case 2538ULL: goto x86_l_9ea;
	case 2540ULL: goto x86_l_9ec;
	case 2542ULL: goto x86_l_9ee;
	case 2547ULL: goto x86_l_9f3;
	case 2552ULL: goto x86_l_9f8;
	case 2557ULL: goto x86_l_9fd;
	case 2562ULL: goto x86_l_a02;
	case 2570ULL: goto x86_l_a0a;
	case 2576ULL: goto x86_l_a10;
	case 2583ULL: goto x86_l_a17;
	case 2590ULL: goto x86_l_a1e;
	case 2597ULL: goto x86_l_a25;
	case 2604ULL: goto x86_l_a2c;
	case 2611ULL: goto x86_l_a33;
	case 2618ULL: goto x86_l_a3a;
	case 2625ULL: goto x86_l_a41;
	case 2631ULL: goto x86_l_a47;
	case 2634ULL: goto x86_l_a4a;
	case 2639ULL: goto x86_l_a4f;
	case 2645ULL: goto x86_l_a55;
	case 2653ULL: goto x86_l_a5d;
	case 2661ULL: goto x86_l_a65;
	case 2669ULL: goto x86_l_a6d;
	case 2677ULL: goto x86_l_a75;
	case 2684ULL: goto x86_l_a7c;
	case 2692ULL: goto x86_l_a84;
	case 2697ULL: goto x86_l_a89;
	case 2699ULL: goto x86_l_a8b;
	case 2702ULL: goto x86_l_a8e;
	case 2708ULL: goto x86_l_a94;
	case 2712ULL: goto x86_l_a98;
	case 2716ULL: goto x86_l_a9c;
	case 2718ULL: goto x86_l_a9e;
	case 2726ULL: goto x86_l_aa6;
	case 2732ULL: goto x86_l_aac;
	case 2739ULL: goto x86_l_ab3;
	case 2742ULL: goto x86_l_ab6;
	case 2748ULL: goto x86_l_abc;
	case 2750ULL: goto x86_l_abe;
	case 2753ULL: goto x86_l_ac1;
	case 2756ULL: goto x86_l_ac4;
	case 2758ULL: goto x86_l_ac6;
	case 2766ULL: goto x86_l_ace;
	case 2771ULL: goto x86_l_ad3;
	case 2773ULL: goto x86_l_ad5;
	case 2775ULL: goto x86_l_ad7;
	case 2777ULL: goto x86_l_ad9;
	case 2781ULL: goto x86_l_add;
	case 2784ULL: goto x86_l_ae0;
	case 2787ULL: goto x86_l_ae3;
	case 2791ULL: goto x86_l_ae7;
	case 2798ULL: goto x86_l_aee;
	case 2801ULL: goto x86_l_af1;
	case 2807ULL: goto x86_l_af7;
	case 2810ULL: goto x86_l_afa;
	case 2815ULL: goto x86_l_aff;
	case 2821ULL: goto x86_l_b05;
	case 2827ULL: goto x86_l_b0b;
	case 2830ULL: goto x86_l_b0e;
	case 2836ULL: goto x86_l_b14;
	case 2839ULL: goto x86_l_b17;
	case 2844ULL: goto x86_l_b1c;
	case 2850ULL: goto x86_l_b22;
	case 2853ULL: goto x86_l_b25;
	case 2859ULL: goto x86_l_b2b;
	case 2867ULL: goto x86_l_b33;
	case 2875ULL: goto x86_l_b3b;
	case 2883ULL: goto x86_l_b43;
	case 2891ULL: goto x86_l_b4b;
	case 2899ULL: goto x86_l_b53;
	case 2902ULL: goto x86_l_b56;
	case 2905ULL: goto x86_l_b59;
	case 2909ULL: goto x86_l_b5d;
	case 2912ULL: goto x86_l_b60;
	case 2914ULL: goto x86_l_b62;
	case 2917ULL: goto x86_l_b65;
	case 2920ULL: goto x86_l_b68;
	case 2924ULL: goto x86_l_b6c;
	case 2928ULL: goto x86_l_b70;
	case 2935ULL: goto x86_l_b77;
	case 2938ULL: goto x86_l_b7a;
	case 2944ULL: goto x86_l_b80;
	case 2954ULL: goto x86_l_b8a;
	case 2959ULL: goto x86_l_b8f;
	case 2969ULL: goto x86_l_b99;
	case 2974ULL: goto x86_l_b9e;
	case 2979ULL: goto x86_l_ba3;
	case 2984ULL: goto x86_l_ba8;
	case 2989ULL: goto x86_l_bad;
	case 2994ULL: goto x86_l_bb2;
	case 2997ULL: goto x86_l_bb5;
	case 2999ULL: goto x86_l_bb7;
	case 3001ULL: goto x86_l_bb9;
	case 3006ULL: goto x86_l_bbe;
	case 3009ULL: goto x86_l_bc1;
	case 3014ULL: goto x86_l_bc6;
	case 3020ULL: goto x86_l_bcc;
	case 3023ULL: goto x86_l_bcf;
	case 3029ULL: goto x86_l_bd5;
	case 3037ULL: goto x86_l_bdd;
	case 3045ULL: goto x86_l_be5;
	case 3053ULL: goto x86_l_bed;
	case 3061ULL: goto x86_l_bf5;
	case 3064ULL: goto x86_l_bf8;
	case 3069ULL: goto x86_l_bfd;
	case 3074ULL: goto x86_l_c02;
	case 3080ULL: goto x86_l_c08;
	case 3083ULL: goto x86_l_c0b;
	case 3088ULL: goto x86_l_c10;
	case 3091ULL: goto x86_l_c13;
	case 3094ULL: goto x86_l_c16;
	case 3100ULL: goto x86_l_c1c;
	case 3108ULL: goto x86_l_c24;
	case 3115ULL: goto x86_l_c2b;
	case 3119ULL: goto x86_l_c2f;
	case 3126ULL: goto x86_l_c36;
	case 3131ULL: goto x86_l_c3b;
	case 3138ULL: goto x86_l_c42;
	case 3143ULL: goto x86_l_c47;
	case 3150ULL: goto x86_l_c4e;
	case 3157ULL: goto x86_l_c55;
	case 3164ULL: goto x86_l_c5c;
	case 3169ULL: goto x86_l_c61;
	case 3172ULL: goto x86_l_c64;
	case 3180ULL: goto x86_l_c6c;
	case 3185ULL: goto x86_l_c71;
	case 3188ULL: goto x86_l_c74;
	case 3191ULL: goto x86_l_c77;
	case 3194ULL: goto x86_l_c7a;
	case 3196ULL: goto x86_l_c7c;
	case 3200ULL: goto x86_l_c80;
	case 3203ULL: goto x86_l_c83;
	case 3207ULL: goto x86_l_c87;
	case 3210ULL: goto x86_l_c8a;
	case 3214ULL: goto x86_l_c8e;
	case 3216ULL: goto x86_l_c90;
	case 3220ULL: goto x86_l_c94;
	case 3226ULL: goto x86_l_c9a;
	case 3234ULL: goto x86_l_ca2;
	case 3238ULL: goto x86_l_ca6;
	case 3240ULL: goto x86_l_ca8;
	case 3245ULL: goto x86_l_cad;
	case 3248ULL: goto x86_l_cb0;
	case 3252ULL: goto x86_l_cb4;
	case 3254ULL: goto x86_l_cb6;
	case 3258ULL: goto x86_l_cba;
	case 3264ULL: goto x86_l_cc0;
	case 3267ULL: goto x86_l_cc3;
	case 3269ULL: goto x86_l_cc5;
	case 3272ULL: goto x86_l_cc8;
	case 3275ULL: goto x86_l_ccb;
	case 3280ULL: goto x86_l_cd0;
	case 3287ULL: goto x86_l_cd7;
	case 3290ULL: goto x86_l_cda;
	case 3296ULL: goto x86_l_ce0;
	case 3300ULL: goto x86_l_ce4;
	case 3303ULL: goto x86_l_ce7;
	case 3307ULL: goto x86_l_ceb;
	case 3313ULL: goto x86_l_cf1;
	case 3321ULL: goto x86_l_cf9;
	case 3324ULL: goto x86_l_cfc;
	case 3330ULL: goto x86_l_d02;
	case 3338ULL: goto x86_l_d0a;
	case 3342ULL: goto x86_l_d0e;
	case 3348ULL: goto x86_l_d14;
	case 3353ULL: goto x86_l_d19;
	case 3356ULL: goto x86_l_d1c;
	case 3359ULL: goto x86_l_d1f;
	case 3362ULL: goto x86_l_d22;
	case 3365ULL: goto x86_l_d25;
	case 3367ULL: goto x86_l_d27;
	case 3373ULL: goto x86_l_d2d;
	case 3376ULL: goto x86_l_d30;
	case 3381ULL: goto x86_l_d35;
	case 3386ULL: goto x86_l_d3a;
	case 3391ULL: goto x86_l_d3f;
	case 3396ULL: goto x86_l_d44;
	case 3399ULL: goto x86_l_d47;
	case 3401ULL: goto x86_l_d49;
	case 3404ULL: goto x86_l_d4c;
	case 3410ULL: goto x86_l_d52;
	case 3417ULL: goto x86_l_d59;
	case 3420ULL: goto x86_l_d5c;
	case 3428ULL: goto x86_l_d64;
	case 3433ULL: goto x86_l_d69;
	case 3439ULL: goto x86_l_d6f;
	case 3442ULL: goto x86_l_d72;
	case 3445ULL: goto x86_l_d75;
	case 3450ULL: goto x86_l_d7a;
	case 3458ULL: goto x86_l_d82;
	case 3466ULL: goto x86_l_d8a;
	case 3474ULL: goto x86_l_d92;
	case 3482ULL: goto x86_l_d9a;
	case 3485ULL: goto x86_l_d9d;
	case 3489ULL: goto x86_l_da1;
	case 3497ULL: goto x86_l_da9;
	case 3502ULL: goto x86_l_dae;
	case 3508ULL: goto x86_l_db4;
	case 3516ULL: goto x86_l_dbc;
	case 3519ULL: goto x86_l_dbf;
	case 3523ULL: goto x86_l_dc3;
	case 3528ULL: goto x86_l_dc8;
	case 3531ULL: goto x86_l_dcb;
	case 3534ULL: goto x86_l_dce;
	case 3540ULL: goto x86_l_dd4;
	case 3548ULL: goto x86_l_ddc;
	case 3555ULL: goto x86_l_de3;
	case 3563ULL: goto x86_l_deb;
	case 3570ULL: goto x86_l_df2;
	case 3578ULL: goto x86_l_dfa;
	case 3585ULL: goto x86_l_e01;
	case 3593ULL: goto x86_l_e09;
	case 3600ULL: goto x86_l_e10;
	case 3608ULL: goto x86_l_e18;
	case 3615ULL: goto x86_l_e1f;
	case 3623ULL: goto x86_l_e27;
	case 3630ULL: goto x86_l_e2e;
	case 3638ULL: goto x86_l_e36;
	case 3645ULL: goto x86_l_e3d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_700:
	/* 0x700: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_704:
	/* 0x704: cmp    r12d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R13, X86_WIDTH_32);
x86_l_707:
	/* 0x707: jae    899 <kprobe_unwind_native+0x899> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_899;
	}
x86_l_70d:
	/* 0x70d: lea    eax,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_711:
	/* 0x711: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_713:
	/* 0x713: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_717:
	/* 0x717: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_71c:
	/* 0x71c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_721:
	/* 0x721: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_724:
	/* 0x724: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_726:
	/* 0x726: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_729:
	/* 0x729: je     969 <kprobe_unwind_native+0x969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_969;
	}
x86_l_72f:
	/* 0x72f: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_733:
	/* 0x733: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_736:
	/* 0x736: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_73b:
	/* 0x73b: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_73e:
	/* 0x73e: cmova  ebp,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R12, X86_WIDTH_32, X86_CC_A);
x86_l_742:
	/* 0x742: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_746:
	/* 0x746: cmp    ebp,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_749:
	/* 0x749: jae    899 <kprobe_unwind_native+0x899> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_899;
	}
x86_l_74f:
	/* 0x74f: lea    eax,[r13+rbp*1+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_754:
	/* 0x754: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_756:
	/* 0x756: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_75a:
	/* 0x75a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_75f:
	/* 0x75f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_764:
	/* 0x764: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_767:
	/* 0x767: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_769:
	/* 0x769: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_76c:
	/* 0x76c: je     969 <kprobe_unwind_native+0x969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_969;
	}
x86_l_772:
	/* 0x772: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_776:
	/* 0x776: lea    r12d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_77a:
	/* 0x77a: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_77f:
	/* 0x77f: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_782:
	/* 0x782: cmova  r12d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_786:
	/* 0x786: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_78a:
	/* 0x78a: cmp    r12d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R13, X86_WIDTH_32);
x86_l_78d:
	/* 0x78d: jae    899 <kprobe_unwind_native+0x899> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_899;
	}
x86_l_793:
	/* 0x793: lea    eax,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_797:
	/* 0x797: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_799:
	/* 0x799: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_79d:
	/* 0x79d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7a2:
	/* 0x7a2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7a7:
	/* 0x7a7: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_7aa:
	/* 0x7aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ac:
	/* 0x7ac: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7af:
	/* 0x7af: je     969 <kprobe_unwind_native+0x969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_969;
	}
x86_l_7b5:
	/* 0x7b5: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7b9:
	/* 0x7b9: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_7bc:
	/* 0x7bc: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7c1:
	/* 0x7c1: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7c4:
	/* 0x7c4: cmova  ebp,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R12, X86_WIDTH_32, X86_CC_A);
x86_l_7c8:
	/* 0x7c8: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_7cc:
	/* 0x7cc: cmp    ebp,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_7cf:
	/* 0x7cf: jae    899 <kprobe_unwind_native+0x899> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_899;
	}
x86_l_7d5:
	/* 0x7d5: lea    eax,[r13+rbp*1+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_7da:
	/* 0x7da: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_7dc:
	/* 0x7dc: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7e0:
	/* 0x7e0: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7e5:
	/* 0x7e5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7ea:
	/* 0x7ea: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_7ed:
	/* 0x7ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ef:
	/* 0x7ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7f2:
	/* 0x7f2: je     969 <kprobe_unwind_native+0x969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_969;
	}
x86_l_7f8:
	/* 0x7f8: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7fc:
	/* 0x7fc: lea    r12d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_800:
	/* 0x800: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_805:
	/* 0x805: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_808:
	/* 0x808: cmova  r12d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_80c:
	/* 0x80c: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_810:
	/* 0x810: cmp    r12d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R13, X86_WIDTH_32);
x86_l_813:
	/* 0x813: jae    899 <kprobe_unwind_native+0x899> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_899;
	}
x86_l_819:
	/* 0x819: lea    eax,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_81d:
	/* 0x81d: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_81f:
	/* 0x81f: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_823:
	/* 0x823: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_828:
	/* 0x828: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_82d:
	/* 0x82d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_830:
	/* 0x830: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_832:
	/* 0x832: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_835:
	/* 0x835: je     969 <kprobe_unwind_native+0x969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_969;
	}
x86_l_83b:
	/* 0x83b: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_83f:
	/* 0x83f: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_842:
	/* 0x842: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_847:
	/* 0x847: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_84a:
	/* 0x84a: cmova  ebp,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R12, X86_WIDTH_32, X86_CC_A);
x86_l_84e:
	/* 0x84e: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_852:
	/* 0x852: cmp    ebp,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_855:
	/* 0x855: jae    899 <kprobe_unwind_native+0x899> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_899;
	}
x86_l_857:
	/* 0x857: lea    eax,[r13+rbp*1+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_85c:
	/* 0x85c: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_85e:
	/* 0x85e: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_862:
	/* 0x862: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_867:
	/* 0x867: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_86c:
	/* 0x86c: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_86f:
	/* 0x86f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_871:
	/* 0x871: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_874:
	/* 0x874: je     969 <kprobe_unwind_native+0x969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_969;
	}
x86_l_87a:
	/* 0x87a: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_87e:
	/* 0x87e: lea    edx,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_881:
	/* 0x881: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_886:
	/* 0x886: cmp    WORD PTR [rax],si */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_889:
	/* 0x889: cmova  edx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_88c:
	/* 0x88c: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_890:
	/* 0x890: cmp    edx,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_893:
	/* 0x893: jb     969 <kprobe_unwind_native+0x969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_969;
	}
x86_l_899:
	/* 0x899: mov    r12d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_32);
x86_l_89c:
	/* 0x89c: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_89f:
	/* 0x89f: je     969 <kprobe_unwind_native+0x969> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_969;
	}
x86_l_8a5:
	/* 0x8a5: dec    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_8a8:
	/* 0x8a8: mov    DWORD PTR [rsp+0x90],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8b0:
	/* 0x8b0: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8b8:
	/* 0x8b8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8bd:
	/* 0x8bd: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_8c0:
	/* 0x8c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c2:
	/* 0x8c2: mov    ecx,0xfa4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4004ULL);
x86_l_8c7:
	/* 0x8c7: mov    edx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_8cc:
	/* 0x8cc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8cf:
	/* 0x8cf: je     42ef <kprobe_unwind_native+0x42ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17135ULL;
	}
x86_l_8d5:
	/* 0x8d5: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_8dc:
	/* 0x8dc: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8e1:
	/* 0x8e1: jne    11d6 <kprobe_unwind_native+0x11d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4566ULL;
	}
x86_l_8e7:
	/* 0x8e7: movzx  ecx,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_8ec:
	/* 0x8ec: movzx  edx,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_8ef:
	/* 0x8ef: sub    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_8f1:
	/* 0x8f1: mov    edx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8f8:
	/* 0x8f8: cmp    edx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_8fb:
	/* 0x8fb: lea    ebp,[rcx+0x10000] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 65536ULL);
x86_l_901:
	/* 0x901: cmovae ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_904:
	/* 0x904: movzx  ecx,WORD PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_908:
	/* 0x908: mov    DWORD PTR [rsp+0x8c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_90f:
	/* 0x90f: cmp    ecx,0x8000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32768ULL);
x86_l_915:
	/* 0x915: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_91d:
	/* 0x91d: je     42e5 <kprobe_unwind_native+0x42e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17125ULL;
	}
x86_l_923:
	/* 0x923: cmp    ecx,0x8001 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32769ULL);
x86_l_929:
	/* 0x929: jne    a17 <kprobe_unwind_native+0xa17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a17;
	}
x86_l_92f:
	/* 0x92f: mov    DWORD PTR [rsp+0x94],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159815ULL);
x86_l_93a:
	/* 0x93a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_941:
	/* 0x941: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_949:
	/* 0x949: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_94e:
	/* 0x94e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_950:
	/* 0x950: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_953:
	/* 0x953: je     9fd <kprobe_unwind_native+0x9fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9fd;
	}
x86_l_959:
	/* 0x959: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_95c:
	/* 0x95c: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_964:
	/* 0x964: jmp    a10 <kprobe_unwind_native+0xa10> */
	goto x86_l_a10;
x86_l_969:
	/* 0x969: mov    ecx,0xfa3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4003ULL);
x86_l_96e:
	/* 0x96e: mov    edx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_973:
	/* 0x973: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_97a:
	/* 0x97a: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_97d:
	/* 0x97d: je     42ef <kprobe_unwind_native+0x42ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17135ULL;
	}
x86_l_983:
	/* 0x983: movabs rax,0x6174616420747075 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7022344801646571637ULL);
x86_l_98d:
	/* 0x98d: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_992:
	/* 0x992: movabs rax,0x72726f43202e7370 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8246776201762206576ULL);
x86_l_99c:
	/* 0x99c: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9a1:
	/* 0x9a1: movabs rax,0x657473203631206e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310594677314494574ULL);
x86_l_9ab:
	/* 0x9ab: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9b0:
	/* 0x9b0: movabs rax,0x6920686372616573 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575169349567210867ULL);
x86_l_9ba:
	/* 0x9ba: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9bf:
	/* 0x9bf: movabs rax,0x622064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7070761801744998726ULL);
x86_l_9c9:
	/* 0x9c9: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9ce:
	/* 0x9ce: mov    DWORD PTR [rsp+0x37],0xa3f61 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 236223872865ULL);
x86_l_9d6:
	/* 0x9d6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9db:
	/* 0x9db: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_9e0:
	/* 0x9e0: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_9e5:
	/* 0x9e5: mov    esi,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 43ULL);
x86_l_9ea:
	/* 0x9ea: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9ec:
	/* 0x9ec: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_9ee:
	/* 0x9ee: mov    edx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_9f3:
	/* 0x9f3: mov    ecx,0xfa3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4003ULL);
x86_l_9f8:
	/* 0x9f8: jmp    42ef <kprobe_unwind_native+0x42ef> */
	return 17135ULL;
x86_l_9fd:
	/* 0x9fd: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a02:
	/* 0xa02: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_a0a:
	/* 0xa0a: jne    12d5 <kprobe_unwind_native+0x12d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4821ULL;
	}
x86_l_a10:
	/* 0xa10: mov    ecx,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_a17:
	/* 0xa17: lea    r12,[rax+0xed0] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_a1e:
	/* 0xa1e: lea    rdx,[rax+0xee0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_a25:
	/* 0xa25: lea    r15,[rax+0xed8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_a2c:
	/* 0xa2c: lea    rsi,[rax+0xee8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3816ULL);
x86_l_a33:
	/* 0xa33: lea    rdi,[rax+0xef0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3824ULL);
x86_l_a3a:
	/* 0xa3a: lea    r8,[rax+0xef8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3832ULL);
x86_l_a41:
	/* 0xa41: add    rax,0xf08 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 3848ULL);
x86_l_a47:
	/* 0xa47: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_a4a:
	/* 0xa4a: mov    QWORD PTR [rsp+0x60],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a4f:
	/* 0xa4f: js     aff <kprobe_unwind_native+0xaff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_aff;
	}
x86_l_a55:
	/* 0xa55: mov    QWORD PTR [rsp+0x150],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_a5d:
	/* 0xa5d: mov    QWORD PTR [rsp+0x148],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_a65:
	/* 0xa65: mov    QWORD PTR [rsp+0x138],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_a6d:
	/* 0xa6d: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_a75:
	/* 0xa75: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&unwind_info_array)));
x86_l_a7c:
	/* 0xa7c: lea    rsi,[rsp+0x8c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_a84:
	/* 0xa84: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a89:
	/* 0xa89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a8b:
	/* 0xa8b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a8e:
	/* 0xa8e: je     6323 <kprobe_unwind_native+0x6323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25379ULL;
	}
x86_l_a94:
	/* 0xa94: mov    r13d,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a98:
	/* 0xa98: movzx  edx,BYTE PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_a9c:
	/* 0xa9c: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_a9e:
	/* 0xa9e: mov    QWORD PTR [rsp+0x158],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_aa6:
	/* 0xaa6: je     c61 <kprobe_unwind_native+0xc61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c61;
	}
x86_l_aac:
	/* 0xaac: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_ab3:
	/* 0xab3: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ab6:
	/* 0xab6: jne    1264 <kprobe_unwind_native+0x1264> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4708ULL;
	}
x86_l_abc:
	/* 0xabc: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_abe:
	/* 0xabe: and    cl,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_ac1:
	/* 0xac1: movzx  ecx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ac4:
	/* 0xac4: cmp    ebp,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RCX, X86_WIDTH_32);
x86_l_ac6:
	/* 0xac6: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ace:
	/* 0xace: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ad3:
	/* 0xad3: jl     af7 <kprobe_unwind_native+0xaf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_af7;
	}
x86_l_ad5:
	/* 0xad5: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ad7:
	/* 0xad7: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_ad9:
	/* 0xad9: setns  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_NS);
x86_l_add:
	/* 0xadd: shl    esi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_ae0:
	/* 0xae0: add    r13d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ae3:
	/* 0xae3: add    r13d,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4294967288ULL);
x86_l_ae7:
	/* 0xae7: mov    rdx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_aee:
	/* 0xaee: cmp    DWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af1:
	/* 0xaf1: jne    1353 <kprobe_unwind_native+0x1353> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4947ULL;
	}
x86_l_af7:
	/* 0xaf7: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_afa:
	/* 0xafa: jmp    c71 <kprobe_unwind_native+0xc71> */
	goto x86_l_c71;
x86_l_aff:
	/* 0xaff: and    ecx,0xffff7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294934527ULL);
x86_l_b05:
	/* 0xb05: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_b0b:
	/* 0xb0b: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b0e:
	/* 0xb0e: jg     bbe <kprobe_unwind_native+0xbbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_bbe;
	}
x86_l_b14:
	/* 0xb14: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b17:
	/* 0xb17: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b1c:
	/* 0xb1c: je     6482 <kprobe_unwind_native+0x6482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25730ULL;
	}
x86_l_b22:
	/* 0xb22: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b25:
	/* 0xb25: jne    5f53 <kprobe_unwind_native+0x5f53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24403ULL;
	}
x86_l_b2b:
	/* 0xb2b: mov    QWORD PTR [rsp+0x150],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_b33:
	/* 0xb33: mov    QWORD PTR [rsp+0x148],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_b3b:
	/* 0xb3b: mov    QWORD PTR [rsp+0x138],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_b43:
	/* 0xb43: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_b4b:
	/* 0xb4b: mov    QWORD PTR [rsp+0x158],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_b53:
	/* 0xb53: mov    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b56:
	/* 0xb56: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_b59:
	/* 0xb59: mov    ecx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b5d:
	/* 0xb5d: and    ecx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_b60:
	/* 0xb60: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b62:
	/* 0xb62: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_b65:
	/* 0xb65: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_b68:
	/* 0xb68: lea    r12,[rax+rdx*8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_b6c:
	/* 0xb6c: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_b70:
	/* 0xb70: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_b77:
	/* 0xb77: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b7a:
	/* 0xb7a: je     1624 <kprobe_unwind_native+0x1624> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5668ULL;
	}
x86_l_b80:
	/* 0xb80: movabs rax,0xa786c2578303d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541309ULL);
x86_l_b8a:
	/* 0xb8a: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b8f:
	/* 0xb8f: movabs rax,0x616663202c544c50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018406059137322064ULL);
x86_l_b99:
	/* 0xb99: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b9e:
	/* 0xb9e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ba3:
	/* 0xba3: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_ba8:
	/* 0xba8: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_bad:
	/* 0xbad: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_bb2:
	/* 0xbb2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_bb5:
	/* 0xbb5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bb7:
	/* 0xbb7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_bb9:
	/* 0xbb9: jmp    1624 <kprobe_unwind_native+0x1624> */
	return 5668ULL;
x86_l_bbe:
	/* 0xbbe: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_bc1:
	/* 0xbc1: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_bc6:
	/* 0xbc6: je     d7a <kprobe_unwind_native+0xd7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d7a;
	}
x86_l_bcc:
	/* 0xbcc: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_bcf:
	/* 0xbcf: jne    5f53 <kprobe_unwind_native+0x5f53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24403ULL;
	}
x86_l_bd5:
	/* 0xbd5: mov    QWORD PTR [rsp+0x150],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_bdd:
	/* 0xbdd: mov    QWORD PTR [rsp+0x148],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_be5:
	/* 0xbe5: mov    QWORD PTR [rsp+0x138],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_bed:
	/* 0xbed: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_bf5:
	/* 0xbf5: mov    rax,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bf8:
	/* 0xbf8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bfd:
	/* 0xbfd: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_c02:
	/* 0xc02: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_c08:
	/* 0xc08: mov    rdx,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c0b:
	/* 0xc0b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_c10:
	/* 0xc10: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_c13:
	/* 0xc13: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c16:
	/* 0xc16: jne    1647 <kprobe_unwind_native+0x1647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5703ULL;
	}
x86_l_c1c:
	/* 0xc1c: mov    QWORD PTR [rsp+0x158],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_c24:
	/* 0xc24: mov    rax,QWORD PTR [rbx+0xee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_c2b:
	/* 0xc2b: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_c2f:
	/* 0xc2f: mov    QWORD PTR [rbx+0xed8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_c36:
	/* 0xc36: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c3b:
	/* 0xc3b: mov    QWORD PTR [rbx+0xee0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_c42:
	/* 0xc42: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c47:
	/* 0xc47: mov    QWORD PTR [rbx+0xed0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_c4e:
	/* 0xc4e: mov    BYTE PTR [rbx+0xf30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16698832846849ULL);
x86_l_c55:
	/* 0xc55: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_c5c:
	/* 0xc5c: jmp    16a8 <kprobe_unwind_native+0x16a8> */
	return 5800ULL;
x86_l_c61:
	/* 0xc61: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_c64:
	/* 0xc64: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c6c:
	/* 0xc6c: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c71:
	/* 0xc71: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_c74:
	/* 0xc74: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_c77:
	/* 0xc77: and    esi,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_c7a:
	/* 0xc7a: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_c7c:
	/* 0xc7c: cmovns esi,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R13, X86_WIDTH_32, X86_CC_NS);
x86_l_c80:
	/* 0xc80: mov    r9d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDX, X86_WIDTH_32);
x86_l_c83:
	/* 0xc83: and    r9d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_c87:
	/* 0xc87: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c8a:
	/* 0xc8a: cmp    r9d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 2ULL);
x86_l_c8e:
	/* 0xc8e: jg     cad <kprobe_unwind_native+0xcad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_cad;
	}
x86_l_c90:
	/* 0xc90: cmp    r9d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 1ULL);
x86_l_c94:
	/* 0xc94: je     d1c <kprobe_unwind_native+0xd1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1c;
	}
x86_l_c9a:
	/* 0xc9a: mov    r8,QWORD PTR [rsp+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_ca2:
	/* 0xca2: cmp    r9d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 2ULL);
x86_l_ca6:
	/* 0xca6: je     d19 <kprobe_unwind_native+0xd19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d19;
	}
x86_l_ca8:
	/* 0xca8: jmp    1458 <kprobe_unwind_native+0x1458> */
	return 5208ULL;
x86_l_cad:
	/* 0xcad: mov    r8,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RDI, X86_WIDTH_64);
x86_l_cb0:
	/* 0xcb0: cmp    r9d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 3ULL);
x86_l_cb4:
	/* 0xcb4: je     d19 <kprobe_unwind_native+0xd19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d19;
	}
x86_l_cb6:
	/* 0xcb6: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_cba:
	/* 0xcba: jne    1458 <kprobe_unwind_native+0x1458> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5208ULL;
	}
x86_l_cc0:
	/* 0xcc0: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_cc3:
	/* 0xcc3: sar    edx,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_cc5:
	/* 0xcc5: and    edx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_cc8:
	/* 0xcc8: movsxd rdx,edx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RDX, X86_RDX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_ccb:
	/* 0xccb: mov    QWORD PTR [rsp+0x78],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_cd0:
	/* 0xcd0: mov    rdx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_cd7:
	/* 0xcd7: cmp    DWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cda:
	/* 0xcda: jne    13d0 <kprobe_unwind_native+0x13d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5072ULL;
	}
x86_l_ce0:
	/* 0xce0: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_ce4:
	/* 0xce4: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ce7:
	/* 0xce7: cmp    r13d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 10ULL);
x86_l_ceb:
	/* 0xceb: jg     1439 <kprobe_unwind_native+0x1439> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5177ULL;
	}
x86_l_cf1:
	/* 0xcf1: mov    rdx,QWORD PTR [rsp+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_cf9:
	/* 0xcf9: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_cfc:
	/* 0xcfc: je     1450 <kprobe_unwind_native+0x1450> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5200ULL;
	}
x86_l_d02:
	/* 0xd02: mov    rdx,QWORD PTR [rsp+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_d0a:
	/* 0xd0a: cmp    r13d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 9ULL);
x86_l_d0e:
	/* 0xd0e: je     1450 <kprobe_unwind_native+0x1450> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5200ULL;
	}
x86_l_d14:
	/* 0xd14: jmp    1458 <kprobe_unwind_native+0x1458> */
	return 5208ULL;
x86_l_d19:
	/* 0xd19: mov    r12,QWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d1c:
	/* 0xd1c: mov    r8,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_64);
x86_l_d1f:
	/* 0xd1f: movsxd r12,esi */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_R12, X86_RSI, X86_WIDTH_64, X86_WIDTH_32);
x86_l_d22:
	/* 0xd22: add    r12,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R8, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d25:
	/* 0xd25: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_d27:
	/* 0xd27: jns    1458 <kprobe_unwind_native+0x1458> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 5208ULL;
	}
x86_l_d2d:
	/* 0xd2d: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_d30:
	/* 0xd30: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_d35:
	/* 0xd35: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_d3a:
	/* 0xd3a: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_d3f:
	/* 0xd3f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d44:
	/* 0xd44: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d47:
	/* 0xd47: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d49:
	/* 0xd49: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d4c:
	/* 0xd4c: je     e9f <kprobe_unwind_native+0xe9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3743ULL;
	}
x86_l_d52:
	/* 0xd52: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_d59:
	/* 0xd59: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d5c:
	/* 0xd5c: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_d64:
	/* 0xd64: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_d69:
	/* 0xd69: jne    1b04 <kprobe_unwind_native+0x1b04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6916ULL;
	}
x86_l_d6f:
	/* 0xd6f: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_d72:
	/* 0xd72: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d75:
	/* 0xd75: jmp    1458 <kprobe_unwind_native+0x1458> */
	return 5208ULL;
x86_l_d7a:
	/* 0xd7a: mov    QWORD PTR [rsp+0x150],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_d82:
	/* 0xd82: mov    QWORD PTR [rsp+0x148],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_d8a:
	/* 0xd8a: mov    QWORD PTR [rsp+0x138],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_d92:
	/* 0xd92: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_d9a:
	/* 0xd9a: mov    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d9d:
	/* 0xd9d: add    rax,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_da1:
	/* 0xda1: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_da9:
	/* 0xda9: mov    ecx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 144ULL);
x86_l_dae:
	/* 0xdae: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_db4:
	/* 0xdb4: mov    QWORD PTR [rsp+0x158],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_dbc:
	/* 0xdbc: mov    rdx,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dbf:
	/* 0xdbf: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_dc3:
	/* 0xdc3: mov    esi,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 144ULL);
x86_l_dc8:
	/* 0xdc8: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_dcb:
	/* 0xdcb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dce:
	/* 0xdce: jne    1647 <kprobe_unwind_native+0x1647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5703ULL;
	}
x86_l_dd4:
	/* 0xdd4: mov    rax,QWORD PTR [rsp+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_ddc:
	/* 0xddc: mov    QWORD PTR [rbx+0xee8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3816ULL);
x86_l_de3:
	/* 0xde3: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_deb:
	/* 0xdeb: mov    QWORD PTR [rbx+0xef0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3824ULL);
x86_l_df2:
	/* 0xdf2: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_dfa:
	/* 0xdfa: mov    QWORD PTR [rbx+0xef8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3832ULL);
x86_l_e01:
	/* 0xe01: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_e09:
	/* 0xe09: mov    QWORD PTR [rbx+0xf00],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3840ULL);
x86_l_e10:
	/* 0xe10: mov    rax,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_e18:
	/* 0xe18: mov    QWORD PTR [rbx+0xf08],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3848ULL);
x86_l_e1f:
	/* 0xe1f: mov    rax,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_e27:
	/* 0xe27: mov    QWORD PTR [rbx+0xee0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_e2e:
	/* 0xe2e: mov    rax,QWORD PTR [rsp+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_e36:
	/* 0xe36: mov    QWORD PTR [rbx+0xed8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_e3d:
	/* 0xe3d: mov    rax,QWORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
	return 3653ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3653ULL: goto x86_l_e45;
	case 3660ULL: goto x86_l_e4c;
	case 3667ULL: goto x86_l_e53;
	case 3674ULL: goto x86_l_e5a;
	case 3678ULL: goto x86_l_e5e;
	case 3684ULL: goto x86_l_e64;
	case 3694ULL: goto x86_l_e6e;
	case 3699ULL: goto x86_l_e73;
	case 3709ULL: goto x86_l_e7d;
	case 3714ULL: goto x86_l_e82;
	case 3719ULL: goto x86_l_e87;
	case 3724ULL: goto x86_l_e8c;
	case 3729ULL: goto x86_l_e91;
	case 3734ULL: goto x86_l_e96;
	case 3736ULL: goto x86_l_e98;
	case 3738ULL: goto x86_l_e9a;
	case 3743ULL: goto x86_l_e9f;
	case 3747ULL: goto x86_l_ea3;
	case 3751ULL: goto x86_l_ea7;
	case 3756ULL: goto x86_l_eac;
	case 3759ULL: goto x86_l_eaf;
	case 3767ULL: goto x86_l_eb7;
	case 3770ULL: goto x86_l_eba;
	case 3775ULL: goto x86_l_ebf;
	case 3780ULL: goto x86_l_ec4;
	case 3786ULL: goto x86_l_eca;
	case 3796ULL: goto x86_l_ed4;
	case 3804ULL: goto x86_l_edc;
	case 3814ULL: goto x86_l_ee6;
	case 3822ULL: goto x86_l_eee;
	case 3832ULL: goto x86_l_ef8;
	case 3840ULL: goto x86_l_f00;
	case 3851ULL: goto x86_l_f0b;
	case 3859ULL: goto x86_l_f13;
	case 3864ULL: goto x86_l_f18;
	case 3869ULL: goto x86_l_f1d;
	case 3874ULL: goto x86_l_f22;
	case 3876ULL: goto x86_l_f24;
	case 3878ULL: goto x86_l_f26;
	case 3883ULL: goto x86_l_f2b;
	case 3893ULL: goto x86_l_f35;
	case 3901ULL: goto x86_l_f3d;
	case 3911ULL: goto x86_l_f47;
	case 3919ULL: goto x86_l_f4f;
	case 3929ULL: goto x86_l_f59;
	case 3937ULL: goto x86_l_f61;
	case 3947ULL: goto x86_l_f6b;
	case 3955ULL: goto x86_l_f73;
	case 3965ULL: goto x86_l_f7d;
	case 3973ULL: goto x86_l_f85;
	case 3981ULL: goto x86_l_f8d;
	case 3986ULL: goto x86_l_f92;
	case 3991ULL: goto x86_l_f97;
	case 3996ULL: goto x86_l_f9c;
	case 3998ULL: goto x86_l_f9e;
	case 4000ULL: goto x86_l_fa0;
	case 4005ULL: goto x86_l_fa5;
	case 4015ULL: goto x86_l_faf;
	case 4020ULL: goto x86_l_fb4;
	case 4030ULL: goto x86_l_fbe;
	case 4035ULL: goto x86_l_fc3;
	case 4045ULL: goto x86_l_fcd;
	case 4050ULL: goto x86_l_fd2;
	case 4060ULL: goto x86_l_fdc;
	case 4065ULL: goto x86_l_fe1;
	case 4070ULL: goto x86_l_fe6;
	case 4075ULL: goto x86_l_feb;
	case 4080ULL: goto x86_l_ff0;
	case 4086ULL: goto x86_l_ff6;
	case 4093ULL: goto x86_l_ffd;
	case 4100ULL: goto x86_l_1004;
	case 4105ULL: goto x86_l_1009;
	case 4107ULL: goto x86_l_100b;
	case 4110ULL: goto x86_l_100e;
	case 4115ULL: goto x86_l_1013;
	case 4125ULL: goto x86_l_101d;
	case 4133ULL: goto x86_l_1025;
	case 4143ULL: goto x86_l_102f;
	case 4151ULL: goto x86_l_1037;
	case 4161ULL: goto x86_l_1041;
	case 4169ULL: goto x86_l_1049;
	case 4179ULL: goto x86_l_1053;
	case 4187ULL: goto x86_l_105b;
	case 4197ULL: goto x86_l_1065;
	case 4205ULL: goto x86_l_106d;
	case 4215ULL: goto x86_l_1077;
	case 4223ULL: goto x86_l_107f;
	case 4231ULL: goto x86_l_1087;
	case 4236ULL: goto x86_l_108c;
	case 4241ULL: goto x86_l_1091;
	case 4245ULL: goto x86_l_1095;
	case 4250ULL: goto x86_l_109a;
	case 4252ULL: goto x86_l_109c;
	case 4254ULL: goto x86_l_109e;
	case 4259ULL: goto x86_l_10a3;
	case 4265ULL: goto x86_l_10a9;
	case 4270ULL: goto x86_l_10ae;
	case 4280ULL: goto x86_l_10b8;
	case 4288ULL: goto x86_l_10c0;
	case 4298ULL: goto x86_l_10ca;
	case 4306ULL: goto x86_l_10d2;
	case 4316ULL: goto x86_l_10dc;
	case 4324ULL: goto x86_l_10e4;
	case 4334ULL: goto x86_l_10ee;
	case 4342ULL: goto x86_l_10f6;
	case 4352ULL: goto x86_l_1100;
	case 4360ULL: goto x86_l_1108;
	case 4370ULL: goto x86_l_1112;
	case 4378ULL: goto x86_l_111a;
	case 4386ULL: goto x86_l_1122;
	case 4391ULL: goto x86_l_1127;
	case 4396ULL: goto x86_l_112c;
	case 4400ULL: goto x86_l_1130;
	case 4405ULL: goto x86_l_1135;
	case 4407ULL: goto x86_l_1137;
	case 4409ULL: goto x86_l_1139;
	case 4412ULL: goto x86_l_113c;
	case 4417ULL: goto x86_l_1141;
	case 4423ULL: goto x86_l_1147;
	case 4429ULL: goto x86_l_114d;
	case 4434ULL: goto x86_l_1152;
	case 4444ULL: goto x86_l_115c;
	case 4449ULL: goto x86_l_1161;
	case 4459ULL: goto x86_l_116b;
	case 4464ULL: goto x86_l_1170;
	case 4474ULL: goto x86_l_117a;
	case 4479ULL: goto x86_l_117f;
	case 4489ULL: goto x86_l_1189;
	case 4494ULL: goto x86_l_118e;
	case 4504ULL: goto x86_l_1198;
	case 4509ULL: goto x86_l_119d;
	case 4519ULL: goto x86_l_11a7;
	case 4524ULL: goto x86_l_11ac;
	case 4529ULL: goto x86_l_11b1;
	case 4534ULL: goto x86_l_11b6;
	case 4540ULL: goto x86_l_11bc;
	case 4543ULL: goto x86_l_11bf;
	case 4548ULL: goto x86_l_11c4;
	case 4553ULL: goto x86_l_11c9;
	case 4556ULL: goto x86_l_11cc;
	case 4558ULL: goto x86_l_11ce;
	case 4561ULL: goto x86_l_11d1;
	case 4566ULL: goto x86_l_11d6;
	case 4576ULL: goto x86_l_11e0;
	case 4581ULL: goto x86_l_11e5;
	case 4591ULL: goto x86_l_11ef;
	case 4596ULL: goto x86_l_11f4;
	case 4606ULL: goto x86_l_11fe;
	case 4611ULL: goto x86_l_1203;
	case 4621ULL: goto x86_l_120d;
	case 4626ULL: goto x86_l_1212;
	case 4636ULL: goto x86_l_121c;
	case 4641ULL: goto x86_l_1221;
	case 4651ULL: goto x86_l_122b;
	case 4656ULL: goto x86_l_1230;
	case 4661ULL: goto x86_l_1235;
	case 4666ULL: goto x86_l_123a;
	case 4672ULL: goto x86_l_1240;
	case 4679ULL: goto x86_l_1247;
	case 4682ULL: goto x86_l_124a;
	case 4687ULL: goto x86_l_124f;
	case 4692ULL: goto x86_l_1254;
	case 4695ULL: goto x86_l_1257;
	case 4697ULL: goto x86_l_1259;
	case 4700ULL: goto x86_l_125c;
	case 4703ULL: goto x86_l_125f;
	case 4708ULL: goto x86_l_1264;
	case 4718ULL: goto x86_l_126e;
	case 4723ULL: goto x86_l_1273;
	case 4733ULL: goto x86_l_127d;
	case 4738ULL: goto x86_l_1282;
	case 4748ULL: goto x86_l_128c;
	case 4753ULL: goto x86_l_1291;
	case 4763ULL: goto x86_l_129b;
	case 4768ULL: goto x86_l_12a0;
	case 4773ULL: goto x86_l_12a5;
	case 4778ULL: goto x86_l_12aa;
	case 4783ULL: goto x86_l_12af;
	case 4789ULL: goto x86_l_12b5;
	case 4793ULL: goto x86_l_12b9;
	case 4798ULL: goto x86_l_12be;
	case 4800ULL: goto x86_l_12c0;
	case 4803ULL: goto x86_l_12c3;
	case 4805ULL: goto x86_l_12c5;
	case 4808ULL: goto x86_l_12c8;
	case 4811ULL: goto x86_l_12cb;
	case 4816ULL: goto x86_l_12d0;
	case 4821ULL: goto x86_l_12d5;
	case 4831ULL: goto x86_l_12df;
	case 4836ULL: goto x86_l_12e4;
	case 4846ULL: goto x86_l_12ee;
	case 4851ULL: goto x86_l_12f3;
	case 4861ULL: goto x86_l_12fd;
	case 4866ULL: goto x86_l_1302;
	case 4876ULL: goto x86_l_130c;
	case 4881ULL: goto x86_l_1311;
	case 4891ULL: goto x86_l_131b;
	case 4896ULL: goto x86_l_1320;
	case 4906ULL: goto x86_l_132a;
	case 4911ULL: goto x86_l_132f;
	case 4916ULL: goto x86_l_1334;
	case 4921ULL: goto x86_l_1339;
	case 4926ULL: goto x86_l_133e;
	case 4933ULL: goto x86_l_1345;
	case 4938ULL: goto x86_l_134a;
	case 4940ULL: goto x86_l_134c;
	case 4942ULL: goto x86_l_134e;
	case 4947ULL: goto x86_l_1353;
	case 4950ULL: goto x86_l_1356;
	case 4960ULL: goto x86_l_1360;
	case 4965ULL: goto x86_l_1365;
	case 4975ULL: goto x86_l_136f;
	case 4980ULL: goto x86_l_1374;
	case 4990ULL: goto x86_l_137e;
	case 4995ULL: goto x86_l_1383;
	case 5005ULL: goto x86_l_138d;
	case 5010ULL: goto x86_l_1392;
	case 5015ULL: goto x86_l_1397;
	case 5020ULL: goto x86_l_139c;
	case 5025ULL: goto x86_l_13a1;
	case 5031ULL: goto x86_l_13a7;
	case 5038ULL: goto x86_l_13ae;
	case 5043ULL: goto x86_l_13b3;
	case 5046ULL: goto x86_l_13b6;
	case 5048ULL: goto x86_l_13b8;
	case 5051ULL: goto x86_l_13bb;
	case 5056ULL: goto x86_l_13c0;
	case 5059ULL: goto x86_l_13c3;
	case 5067ULL: goto x86_l_13cb;
	case 5072ULL: goto x86_l_13d0;
	case 5082ULL: goto x86_l_13da;
	case 5087ULL: goto x86_l_13df;
	case 5097ULL: goto x86_l_13e9;
	case 5102ULL: goto x86_l_13ee;
	case 5107ULL: goto x86_l_13f3;
	case 5112ULL: goto x86_l_13f8;
	case 5117ULL: goto x86_l_13fd;
	case 5123ULL: goto x86_l_1403;
	case 5127ULL: goto x86_l_1407;
	case 5132ULL: goto x86_l_140c;
	case 5137ULL: goto x86_l_1411;
	case 5140ULL: goto x86_l_1414;
	case 5143ULL: goto x86_l_1417;
	case 5145ULL: goto x86_l_1419;
	case 5148ULL: goto x86_l_141c;
	case 5153ULL: goto x86_l_1421;
	case 5156ULL: goto x86_l_1424;
	case 5164ULL: goto x86_l_142c;
	case 5167ULL: goto x86_l_142f;
	case 5171ULL: goto x86_l_1433;
	case 5177ULL: goto x86_l_1439;
	case 5185ULL: goto x86_l_1441;
	case 5189ULL: goto x86_l_1445;
	case 5191ULL: goto x86_l_1447;
	case 5195ULL: goto x86_l_144b;
	case 5197ULL: goto x86_l_144d;
	case 5200ULL: goto x86_l_1450;
	case 5205ULL: goto x86_l_1455;
	case 5208ULL: goto x86_l_1458;
	case 5212ULL: goto x86_l_145c;
	case 5216ULL: goto x86_l_1460;
	case 5219ULL: goto x86_l_1463;
	case 5222ULL: goto x86_l_1466;
	case 5225ULL: goto x86_l_1469;
	case 5229ULL: goto x86_l_146d;
	case 5232ULL: goto x86_l_1470;
	case 5236ULL: goto x86_l_1474;
	case 5240ULL: goto x86_l_1478;
	case 5242ULL: goto x86_l_147a;
	case 5245ULL: goto x86_l_147d;
	case 5249ULL: goto x86_l_1481;
	case 5255ULL: goto x86_l_1487;
	case 5263ULL: goto x86_l_148f;
	case 5267ULL: goto x86_l_1493;
	case 5269ULL: goto x86_l_1495;
	case 5274ULL: goto x86_l_149a;
	case 5277ULL: goto x86_l_149d;
	case 5281ULL: goto x86_l_14a1;
	case 5283ULL: goto x86_l_14a3;
	case 5287ULL: goto x86_l_14a7;
	case 5293ULL: goto x86_l_14ad;
	case 5296ULL: goto x86_l_14b0;
	case 5298ULL: goto x86_l_14b2;
	case 5301ULL: goto x86_l_14b5;
	case 5304ULL: goto x86_l_14b8;
	case 5309ULL: goto x86_l_14bd;
	case 5316ULL: goto x86_l_14c4;
	case 5319ULL: goto x86_l_14c7;
	case 5325ULL: goto x86_l_14cd;
	case 5329ULL: goto x86_l_14d1;
	case 5333ULL: goto x86_l_14d5;
	case 5339ULL: goto x86_l_14db;
	case 5347ULL: goto x86_l_14e3;
	case 5350ULL: goto x86_l_14e6;
	case 5356ULL: goto x86_l_14ec;
	case 5364ULL: goto x86_l_14f4;
	case 5368ULL: goto x86_l_14f8;
	case 5374ULL: goto x86_l_14fe;
	case 5376ULL: goto x86_l_1500;
	case 5379ULL: goto x86_l_1503;
	case 5382ULL: goto x86_l_1506;
	case 5385ULL: goto x86_l_1509;
	case 5388ULL: goto x86_l_150c;
	case 5394ULL: goto x86_l_1512;
	case 5397ULL: goto x86_l_1515;
	case 5402ULL: goto x86_l_151a;
	case 5407ULL: goto x86_l_151f;
	case 5412ULL: goto x86_l_1524;
	case 5417ULL: goto x86_l_1529;
	case 5420ULL: goto x86_l_152c;
	case 5422ULL: goto x86_l_152e;
	case 5425ULL: goto x86_l_1531;
	case 5427ULL: goto x86_l_1533;
	case 5434ULL: goto x86_l_153a;
	case 5437ULL: goto x86_l_153d;
	case 5440ULL: goto x86_l_1540;
	case 5445ULL: goto x86_l_1545;
	case 5451ULL: goto x86_l_154b;
	case 5456ULL: goto x86_l_1550;
	case 5461ULL: goto x86_l_1555;
	case 5465ULL: goto x86_l_1559;
	case 5469ULL: goto x86_l_155d;
	case 5474ULL: goto x86_l_1562;
	case 5477ULL: goto x86_l_1565;
	case 5480ULL: goto x86_l_1568;
	case 5485ULL: goto x86_l_156d;
	case 5490ULL: goto x86_l_1572;
	case 5500ULL: goto x86_l_157c;
	case 5505ULL: goto x86_l_1581;
	case 5515ULL: goto x86_l_158b;
	case 5520ULL: goto x86_l_1590;
	case 5525ULL: goto x86_l_1595;
	case 5530ULL: goto x86_l_159a;
	case 5535ULL: goto x86_l_159f;
	case 5541ULL: goto x86_l_15a5;
	case 5545ULL: goto x86_l_15a9;
	case 5550ULL: goto x86_l_15ae;
	case 5555ULL: goto x86_l_15b3;
	case 5558ULL: goto x86_l_15b6;
	case 5561ULL: goto x86_l_15b9;
	case 5563ULL: goto x86_l_15bb;
	case 5566ULL: goto x86_l_15be;
	case 5571ULL: goto x86_l_15c3;
	case 5574ULL: goto x86_l_15c6;
	case 5582ULL: goto x86_l_15ce;
	case 5586ULL: goto x86_l_15d2;
	case 5592ULL: goto x86_l_15d8;
	case 5600ULL: goto x86_l_15e0;
	case 5604ULL: goto x86_l_15e4;
	case 5606ULL: goto x86_l_15e6;
	case 5610ULL: goto x86_l_15ea;
	case 5616ULL: goto x86_l_15f0;
	case 5619ULL: goto x86_l_15f3;
	case 5624ULL: goto x86_l_15f8;
	case 5627ULL: goto x86_l_15fb;
	case 5630ULL: goto x86_l_15fe;
	case 5635ULL: goto x86_l_1603;
	case 5637ULL: goto x86_l_1605;
	case 5642ULL: goto x86_l_160a;
	case 5647ULL: goto x86_l_160f;
	case 5652ULL: goto x86_l_1614;
	case 5654ULL: goto x86_l_1616;
	case 5656ULL: goto x86_l_1618;
	case 5659ULL: goto x86_l_161b;
	case 5661ULL: goto x86_l_161d;
	case 5668ULL: goto x86_l_1624;
	case 5671ULL: goto x86_l_1627;
	case 5673ULL: goto x86_l_1629;
	case 5678ULL: goto x86_l_162e;
	case 5683ULL: goto x86_l_1633;
	case 5688ULL: goto x86_l_1638;
	case 5691ULL: goto x86_l_163b;
	case 5696ULL: goto x86_l_1640;
	case 5698ULL: goto x86_l_1642;
	case 5701ULL: goto x86_l_1645;
	case 5703ULL: goto x86_l_1647;
	case 5711ULL: goto x86_l_164f;
	case 5718ULL: goto x86_l_1656;
	case 5723ULL: goto x86_l_165b;
	case 5728ULL: goto x86_l_1660;
	case 5730ULL: goto x86_l_1662;
	case 5733ULL: goto x86_l_1665;
	case 5735ULL: goto x86_l_1667;
	case 5738ULL: goto x86_l_166a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e45:
	/* 0xe45: mov    QWORD PTR [rbx+0xed0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_e4c:
	/* 0xe4c: mov    BYTE PTR [rbx+0xf30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16698832846848ULL);
x86_l_e53:
	/* 0xe53: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_e5a:
	/* 0xe5a: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e5e:
	/* 0xe5e: je     16a8 <kprobe_unwind_native+0x16a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5800ULL;
	}
x86_l_e64:
	/* 0xe64: movabs rax,0xa656d61726620 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926270227834400ULL);
x86_l_e6e:
	/* 0xe6e: mov    QWORD PTR [rsp+0x16],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_e73:
	/* 0xe73: movabs rax,0x66206c616e676973 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7359000956843288947ULL);
x86_l_e7d:
	/* 0xe7d: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e82:
	/* 0xe82: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e87:
	/* 0xe87: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_e8c:
	/* 0xe8c: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_e91:
	/* 0xe91: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_e96:
	/* 0xe96: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e98:
	/* 0xe98: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e9a:
	/* 0xe9a: jmp    16a8 <kprobe_unwind_native+0x16a8> */
	return 5800ULL;
x86_l_e9f:
	/* 0xe9f: shl    r13d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_ea3:
	/* 0xea3: and    r13d,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 56ULL);
x86_l_ea7:
	/* 0xea7: add    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_eac:
	/* 0xeac: mov    r12,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_64);
x86_l_eaf:
	/* 0xeaf: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_eb7:
	/* 0xeb7: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_eba:
	/* 0xeba: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ebf:
	/* 0xebf: jmp    1458 <kprobe_unwind_native+0x1458> */
	goto x86_l_1458;
x86_l_ec4:
	/* 0xec4: mov    edx,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_eca:
	/* 0xeca: movabs rax,0x3d3d206425206576 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4412718824384652662ULL);
x86_l_ed4:
	/* 0xed4: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_edc:
	/* 0xedc: movabs rax,0x6974616e5f646e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598805597955583593ULL);
x86_l_ee6:
	/* 0xee6: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_eee:
	/* 0xeee: movabs rax,0x776e75203d3d3d3d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8605944719278423357ULL);
x86_l_ef8:
	/* 0xef8: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_f00:
	/* 0xf00: mov    DWORD PTR [rsp+0xb8],0xa3d3d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 790274653501ULL);
x86_l_f0b:
	/* 0xf0b: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_f13:
	/* 0xf13: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_f18:
	/* 0xf18: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_f1d:
	/* 0xf1d: mov    esi,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 28ULL);
x86_l_f22:
	/* 0xf22: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f24:
	/* 0xf24: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f26:
	/* 0xf26: jmp    5b <kprobe_unwind_native+0x5b> */
	return 91ULL;
x86_l_f2b:
	/* 0xf2b: movabs rax,0xa6c6c75662073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2933962849001587ULL);
x86_l_f35:
	/* 0xf35: mov    QWORD PTR [rsp+0xbd],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 189ULL);
x86_l_f3d:
	/* 0xf3d: movabs rax,0x66207369206b6361 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7359008686476059489ULL);
x86_l_f47:
	/* 0xf47: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_f4f:
	/* 0xf4f: movabs rax,0x7473203a656d6172 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8391085965903225202ULL);
x86_l_f59:
	/* 0xf59: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_f61:
	/* 0xf61: movabs rax,0x662068737570206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358996636224200815ULL);
x86_l_f6b:
	/* 0xf6b: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_f73:
	/* 0xf73: movabs rax,0x7420656c62616e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367799623835807349ULL);
x86_l_f7d:
	/* 0xf7d: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_f85:
	/* 0xf85: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_f8d:
	/* 0xf8d: mov    eax,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_f92:
	/* 0xf92: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_f97:
	/* 0xf97: mov    esi,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 37ULL);
x86_l_f9c:
	/* 0xf9c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f9e:
	/* 0xf9e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_fa0:
	/* 0xfa0: jmp    14c <kprobe_unwind_native+0x14c> */
	return 332ULL;
x86_l_fa5:
	/* 0xfa5: movabs rax,0xa786c253a786c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 754471844735118373ULL);
x86_l_faf:
	/* 0xfaf: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fb4:
	/* 0xfb4: movabs rax,0x20726f662061746c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338053640979313772ULL);
x86_l_fbe:
	/* 0xfbe: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fc3:
	/* 0xfc3: movabs rax,0x6564206b63617473 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7306000141102707827ULL);
x86_l_fcd:
	/* 0xfcd: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_fd2:
	/* 0xfd2: movabs rax,0x207075206b6f6f4c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337496988707155788ULL);
x86_l_fdc:
	/* 0xfdc: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fe1:
	/* 0xfe1: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_fe6:
	/* 0xfe6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_feb:
	/* 0xfeb: mov    eax,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_ff0:
	/* 0xff0: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_ff6:
	/* 0xff6: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_ffd:
	/* 0xffd: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_1004:
	/* 0x1004: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_1009:
	/* 0x1009: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_100b:
	/* 0x100b: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_100e:
	/* 0x100e: jmp    288 <kprobe_unwind_native+0x288> */
	return 648ULL;
x86_l_1013:
	/* 0x1013: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_101d:
	/* 0x101d: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_1025:
	/* 0x1025: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_102f:
	/* 0x102f: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1037:
	/* 0x1037: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1041:
	/* 0x1041: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1049:
	/* 0x1049: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1053:
	/* 0x1053: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_105b:
	/* 0x105b: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1065:
	/* 0x1065: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_106d:
	/* 0x106d: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1077:
	/* 0x1077: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_107f:
	/* 0x107f: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1087:
	/* 0x1087: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_108c:
	/* 0x108c: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1091:
	/* 0x1091: mov    edx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1095:
	/* 0x1095: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_109a:
	/* 0x109a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_109c:
	/* 0x109c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_109e:
	/* 0x109e: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10a3:
	/* 0x10a3: je     131 <kprobe_unwind_native+0x131> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 305ULL;
	}
x86_l_10a9:
	/* 0x10a9: jmp    8d <kprobe_unwind_native+0x8d> */
	return 141ULL;
x86_l_10ae:
	/* 0x10ae: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_10b8:
	/* 0x10b8: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_10c0:
	/* 0x10c0: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_10ca:
	/* 0x10ca: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_10d2:
	/* 0x10d2: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_10dc:
	/* 0x10dc: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_10e4:
	/* 0x10e4: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_10ee:
	/* 0x10ee: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_10f6:
	/* 0x10f6: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1100:
	/* 0x1100: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1108:
	/* 0x1108: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1112:
	/* 0x1112: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_111a:
	/* 0x111a: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1122:
	/* 0x1122: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1127:
	/* 0x1127: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_112c:
	/* 0x112c: mov    edx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1130:
	/* 0x1130: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1135:
	/* 0x1135: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1137:
	/* 0x1137: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1139:
	/* 0x1139: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_113c:
	/* 0x113c: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1141:
	/* 0x1141: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_1147:
	/* 0x1147: je     5f60 <kprobe_unwind_native+0x5f60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24416ULL;
	}
x86_l_114d:
	/* 0x114d: jmp    187 <kprobe_unwind_native+0x187> */
	return 391ULL;
x86_l_1152:
	/* 0x1152: movabs rax,0xa296425204449 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2860259863446601ULL);
x86_l_115c:
	/* 0x115c: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1161:
	/* 0x1161: movabs rax,0x70616d2820756c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8097873624099548197ULL);
x86_l_116b:
	/* 0x116b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1170:
	/* 0x1170: movabs rax,0x206f7420756c2520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414386373920ULL);
x86_l_117a:
	/* 0x117a: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_117f:
	/* 0x117f: movabs rax,0x6d6f726620656220 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7885647255504773664ULL);
x86_l_1189:
	/* 0x1189: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_118e:
	/* 0x118e: movabs rax,0x646c756f68732073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7236287822631739507ULL);
x86_l_1198:
	/* 0x1198: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_119d:
	/* 0x119d: movabs rax,0x6c61767265746e49 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7809653462537629257ULL);
x86_l_11a7:
	/* 0x11a7: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11ac:
	/* 0x11ac: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11b1:
	/* 0x11b1: mov    eax,0x30 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 48ULL);
x86_l_11b6:
	/* 0x11b6: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_11bc:
	/* 0x11bc: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_11bf:
	/* 0x11bf: movzx  r8d,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_11c4:
	/* 0x11c4: mov    esi,0x30 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 48ULL);
x86_l_11c9:
	/* 0x11c9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_11cc:
	/* 0x11cc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11ce:
	/* 0x11ce: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_11d1:
	/* 0x11d1: jmp    46f <kprobe_unwind_native+0x46f> */
	return 1135ULL;
x86_l_11d6:
	/* 0x11d6: movabs rcx,0xa6425206f666e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2924860387845742ULL);
x86_l_11e0:
	/* 0x11e0: mov    QWORD PTR [rsp+0x35],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_11e5:
	/* 0x11e5: movabs rcx,0x6f666e49646e6977 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 8027224647331113335ULL);
x86_l_11ef:
	/* 0x11ef: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11f4:
	/* 0x11f4: movabs rcx,0x6e75202c78257830 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 7959303291813591088ULL);
x86_l_11fe:
	/* 0x11fe: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1203:
	/* 0x1203: movabs rcx,0x20776f4c72646461 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2339460905569641569ULL);
x86_l_120d:
	/* 0x120d: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1212:
	/* 0x1212: movabs rcx,0x202c642520786564 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2318338018810291556ULL);
x86_l_121c:
	/* 0x121c: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1221:
	/* 0x1221: movabs rcx,0x6e692061746c6564 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 7955925819663869284ULL);
x86_l_122b:
	/* 0x122b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1230:
	/* 0x1230: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1235:
	/* 0x1235: mov    ecx,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 45ULL);
x86_l_123a:
	/* 0x123a: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1240:
	/* 0x1240: mov    edx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1247:
	/* 0x1247: movzx  ecx,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_124a:
	/* 0x124a: movzx  r8d,WORD PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_124f:
	/* 0x124f: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_1254:
	/* 0x1254: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1257:
	/* 0x1257: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1259:
	/* 0x1259: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_125c:
	/* 0x125c: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_125f:
	/* 0x125f: jmp    8e7 <kprobe_unwind_native+0x8e7> */
	return 2279ULL;
x86_l_1264:
	/* 0x1264: movabs rcx,0xa78323023252061 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 754408119914012769ULL);
x86_l_126e:
	/* 0x126e: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1273:
	/* 0x1273: movabs rcx,0x746c656420646567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 8389191686598976871ULL);
x86_l_127d:
	/* 0x127d: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1282:
	/* 0x1282: movabs rcx,0x72656d202c642520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 8243114677922702624ULL);
x86_l_128c:
	/* 0x128c: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1291:
	/* 0x1291: movabs rcx,0x6666694472646441 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 7378700782191010881ULL);
x86_l_129b:
	/* 0x129b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12a0:
	/* 0x12a0: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_12a5:
	/* 0x12a5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12aa:
	/* 0x12aa: mov    ecx,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 33ULL);
x86_l_12af:
	/* 0x12af: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_12b5:
	/* 0x12b5: movzx  ecx,BYTE PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_12b9:
	/* 0x12b9: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_12be:
	/* 0x12be: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_12c0:
	/* 0x12c0: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_12c3:
	/* 0x12c3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12c5:
	/* 0x12c5: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_12c8:
	/* 0x12c8: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_12cb:
	/* 0x12cb: movzx  edx,BYTE PTR [r14+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_12d0:
	/* 0x12d0: jmp    abc <kprobe_unwind_native+0xabc> */
	return 2748ULL;
x86_l_12d5:
	/* 0x12d5: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_12df:
	/* 0x12df: mov    QWORD PTR [rsp+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_12e4:
	/* 0x12e4: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_12ee:
	/* 0x12ee: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12f3:
	/* 0x12f3: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_12fd:
	/* 0x12fd: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1302:
	/* 0x1302: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_130c:
	/* 0x130c: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1311:
	/* 0x1311: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_131b:
	/* 0x131b: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1320:
	/* 0x1320: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_132a:
	/* 0x132a: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_132f:
	/* 0x132f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1334:
	/* 0x1334: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1339:
	/* 0x1339: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_133e:
	/* 0x133e: mov    edx,DWORD PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_1345:
	/* 0x1345: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_134a:
	/* 0x134a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_134c:
	/* 0x134c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_134e:
	/* 0x134e: jmp    95c <kprobe_unwind_native+0x95c> */
	return 2396ULL;
x86_l_1353:
	/* 0x1353: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_1356:
	/* 0x1356: movabs rcx,0xa64253d61746c65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 748764383608597605ULL);
x86_l_1360:
	/* 0x1360: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1365:
	/* 0x1365: movabs rcx,0x44616663203a6863 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 4927332043248527459ULL);
x86_l_136f:
	/* 0x136f: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1374:
	/* 0x1374: movabs rcx,0x74616d2061746c65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 8386103966981975141ULL);
x86_l_137e:
	/* 0x137e: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1383:
	/* 0x1383: movabs rcx,0x642064656772654d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 7214876989737559373ULL);
x86_l_138d:
	/* 0x138d: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1392:
	/* 0x1392: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1397:
	/* 0x1397: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_139c:
	/* 0x139c: mov    ecx,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 33ULL);
x86_l_13a1:
	/* 0x13a1: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_13a7:
	/* 0x13a7: mov    edx,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_13ae:
	/* 0x13ae: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_13b3:
	/* 0x13b3: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_13b6:
	/* 0x13b6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13b8:
	/* 0x13b8: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_13bb:
	/* 0x13bb: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_13c0:
	/* 0x13c0: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_13c3:
	/* 0x13c3: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_13cb:
	/* 0x13cb: jmp    c71 <kprobe_unwind_native+0xc71> */
	return 3185ULL;
x86_l_13d0:
	/* 0x13d0: movabs rcx,0xa756c252b642572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 753627419551999346ULL);
x86_l_13da:
	/* 0x13da: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13df:
	/* 0x13df: movabs rcx,0x203a646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2322278983241526901ULL);
x86_l_13e9:
	/* 0x13e9: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13ee:
	/* 0x13ee: mov    BYTE PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_13f3:
	/* 0x13f3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13f8:
	/* 0x13f8: mov    ecx,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_13fd:
	/* 0x13fd: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_1403:
	/* 0x1403: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1407:
	/* 0x1407: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_140c:
	/* 0x140c: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1411:
	/* 0x1411: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_1414:
	/* 0x1414: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1417:
	/* 0x1417: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1419:
	/* 0x1419: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_141c:
	/* 0x141c: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1421:
	/* 0x1421: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_1424:
	/* 0x1424: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_142c:
	/* 0x142c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_142f:
	/* 0x142f: cmp    r13d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 10ULL);
x86_l_1433:
	/* 0x1433: jle    cf1 <kprobe_unwind_native+0xcf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3313ULL;
	}
x86_l_1439:
	/* 0x1439: mov    rdx,QWORD PTR [rsp+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_1441:
	/* 0x1441: cmp    r13d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 11ULL);
x86_l_1445:
	/* 0x1445: je     1450 <kprobe_unwind_native+0x1450> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1450;
	}
x86_l_1447:
	/* 0x1447: cmp    r13d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 15ULL);
x86_l_144b:
	/* 0x144b: jne    1458 <kprobe_unwind_native+0x1458> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1458;
	}
x86_l_144d:
	/* 0x144d: mov    rdx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1450:
	/* 0x1450: mov    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1455:
	/* 0x1455: add    r12,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1458:
	/* 0x1458: movzx  esi,BYTE PTR [rax+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_145c:
	/* 0x145c: mov    r13d,DWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1460:
	/* 0x1460: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_1463:
	/* 0x1463: and    edx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_1466:
	/* 0x1466: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_1469:
	/* 0x1469: cmovns edx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R13, X86_WIDTH_32, X86_CC_NS);
x86_l_146d:
	/* 0x146d: mov    r9d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RSI, X86_WIDTH_32);
x86_l_1470:
	/* 0x1470: and    r9d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_1474:
	/* 0x1474: cmp    r9d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 2ULL);
x86_l_1478:
	/* 0x1478: jg     149a <kprobe_unwind_native+0x149a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_149a;
	}
x86_l_147a:
	/* 0x147a: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_147d:
	/* 0x147d: cmp    r9d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 1ULL);
x86_l_1481:
	/* 0x1481: je     1503 <kprobe_unwind_native+0x1503> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1503;
	}
x86_l_1487:
	/* 0x1487: mov    r8,QWORD PTR [rsp+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_148f:
	/* 0x148f: cmp    r9d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 2ULL);
x86_l_1493:
	/* 0x1493: je     1500 <kprobe_unwind_native+0x1500> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1500;
	}
x86_l_1495:
	/* 0x1495: jmp    154b <kprobe_unwind_native+0x154b> */
	goto x86_l_154b;
x86_l_149a:
	/* 0x149a: mov    r8,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RDI, X86_WIDTH_64);
x86_l_149d:
	/* 0x149d: cmp    r9d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 3ULL);
x86_l_14a1:
	/* 0x14a1: je     1500 <kprobe_unwind_native+0x1500> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1500;
	}
x86_l_14a3:
	/* 0x14a3: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_14a7:
	/* 0x14a7: jne    154b <kprobe_unwind_native+0x154b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_154b;
	}
x86_l_14ad:
	/* 0x14ad: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_14b0:
	/* 0x14b0: sar    edx,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_14b2:
	/* 0x14b2: and    edx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_14b5:
	/* 0x14b5: movsxd rdx,edx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RDX, X86_RDX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_14b8:
	/* 0x14b8: mov    QWORD PTR [rsp+0x78],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_14bd:
	/* 0x14bd: mov    rdx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_14c4:
	/* 0x14c4: cmp    DWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14c7:
	/* 0x14c7: jne    1572 <kprobe_unwind_native+0x1572> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1572;
	}
x86_l_14cd:
	/* 0x14cd: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_14d1:
	/* 0x14d1: cmp    r13d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 10ULL);
x86_l_14d5:
	/* 0x14d5: jg     15d8 <kprobe_unwind_native+0x15d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_15d8;
	}
x86_l_14db:
	/* 0x14db: mov    rsi,QWORD PTR [rsp+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_14e3:
	/* 0x14e3: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_14e6:
	/* 0x14e6: je     15f3 <kprobe_unwind_native+0x15f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15f3;
	}
x86_l_14ec:
	/* 0x14ec: mov    rsi,QWORD PTR [rsp+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_14f4:
	/* 0x14f4: cmp    r13d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 9ULL);
x86_l_14f8:
	/* 0x14f8: je     15f3 <kprobe_unwind_native+0x15f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15f3;
	}
x86_l_14fe:
	/* 0x14fe: jmp    154b <kprobe_unwind_native+0x154b> */
	goto x86_l_154b;
x86_l_1500:
	/* 0x1500: mov    rcx,QWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1503:
	/* 0x1503: movsxd rdx,edx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RDX, X86_RDX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_1506:
	/* 0x1506: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1509:
	/* 0x1509: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_150c:
	/* 0x150c: jns    15fb <kprobe_unwind_native+0x15fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_15fb;
	}
x86_l_1512:
	/* 0x1512: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1515:
	/* 0x1515: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_151a:
	/* 0x151a: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_151f:
	/* 0x151f: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_1524:
	/* 0x1524: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1529:
	/* 0x1529: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_152c:
	/* 0x152c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_152e:
	/* 0x152e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1531:
	/* 0x1531: je     1555 <kprobe_unwind_native+0x1555> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1555;
	}
x86_l_1533:
	/* 0x1533: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_153a:
	/* 0x153a: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_153d:
	/* 0x153d: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_1540:
	/* 0x1540: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1545:
	/* 0x1545: jne    1b8a <kprobe_unwind_native+0x1b8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7050ULL;
	}
x86_l_154b:
	/* 0x154b: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1550:
	/* 0x1550: jmp    1618 <kprobe_unwind_native+0x1618> */
	goto x86_l_1618;
x86_l_1555:
	/* 0x1555: shl    r13d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1559:
	/* 0x1559: and    r13d,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 56ULL);
x86_l_155d:
	/* 0x155d: add    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_1562:
	/* 0x1562: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1565:
	/* 0x1565: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_1568:
	/* 0x1568: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_156d:
	/* 0x156d: jmp    15fb <kprobe_unwind_native+0x15fb> */
	goto x86_l_15fb;
x86_l_1572:
	/* 0x1572: movabs rcx,0xa756c252b642572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 753627419551999346ULL);
x86_l_157c:
	/* 0x157c: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1581:
	/* 0x1581: movabs rcx,0x203a646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2322278983241526901ULL);
x86_l_158b:
	/* 0x158b: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1590:
	/* 0x1590: mov    BYTE PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1595:
	/* 0x1595: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_159a:
	/* 0x159a: mov    ecx,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_159f:
	/* 0x159f: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_15a5:
	/* 0x15a5: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_15a9:
	/* 0x15a9: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_15ae:
	/* 0x15ae: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_15b3:
	/* 0x15b3: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_15b6:
	/* 0x15b6: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_15b9:
	/* 0x15b9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15bb:
	/* 0x15bb: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_15be:
	/* 0x15be: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_15c3:
	/* 0x15c3: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_15c6:
	/* 0x15c6: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_15ce:
	/* 0x15ce: cmp    r13d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 10ULL);
x86_l_15d2:
	/* 0x15d2: jle    14db <kprobe_unwind_native+0x14db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_14db;
	}
x86_l_15d8:
	/* 0x15d8: mov    rsi,QWORD PTR [rsp+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_15e0:
	/* 0x15e0: cmp    r13d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 11ULL);
x86_l_15e4:
	/* 0x15e4: je     15f3 <kprobe_unwind_native+0x15f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15f3;
	}
x86_l_15e6:
	/* 0x15e6: cmp    r13d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 15ULL);
x86_l_15ea:
	/* 0x15ea: jne    154b <kprobe_unwind_native+0x154b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_154b;
	}
x86_l_15f0:
	/* 0x15f0: mov    rsi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_15f3:
	/* 0x15f3: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_15f8:
	/* 0x15f8: add    rdx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_15fb:
	/* 0x15fb: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_15fe:
	/* 0x15fe: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1603:
	/* 0x1603: je     1618 <kprobe_unwind_native+0x1618> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1618;
	}
x86_l_1605:
	/* 0x1605: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_160a:
	/* 0x160a: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_160f:
	/* 0x160f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1614:
	/* 0x1614: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1616:
	/* 0x1616: jmp    1624 <kprobe_unwind_native+0x1624> */
	goto x86_l_1624;
x86_l_1618:
	/* 0x1618: cmp    BYTE PTR [rax],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_161b:
	/* 0x161b: jne    1624 <kprobe_unwind_native+0x1624> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1624;
	}
x86_l_161d:
	/* 0x161d: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1624:
	/* 0x1624: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_1627:
	/* 0x1627: je     1647 <kprobe_unwind_native+0x1647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1647;
	}
x86_l_1629:
	/* 0x1629: lea    rdx,[r12-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_162e:
	/* 0x162e: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1633:
	/* 0x1633: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_1638:
	/* 0x1638: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_163b:
	/* 0x163b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1640:
	/* 0x1640: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1642:
	/* 0x1642: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1645:
	/* 0x1645: je     1690 <kprobe_unwind_native+0x1690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5776ULL;
	}
x86_l_1647:
	/* 0x1647: mov    DWORD PTR [rsp+0x78],0xe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075534ULL);
x86_l_164f:
	/* 0x164f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_1656:
	/* 0x1656: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_165b:
	/* 0x165b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1660:
	/* 0x1660: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1662:
	/* 0x1662: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1665:
	/* 0x1665: je     1675 <kprobe_unwind_native+0x1675> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5749ULL;
	}
x86_l_1667:
	/* 0x1667: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_166a:
	/* 0x166a: mov    r13d,0xfa7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4007ULL);
	return 5744ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5744ULL: goto x86_l_1670;
	case 5749ULL: goto x86_l_1675;
	case 5756ULL: goto x86_l_167c;
	case 5759ULL: goto x86_l_167f;
	case 5765ULL: goto x86_l_1685;
	case 5771ULL: goto x86_l_168b;
	case 5776ULL: goto x86_l_1690;
	case 5783ULL: goto x86_l_1697;
	case 5790ULL: goto x86_l_169e;
	case 5797ULL: goto x86_l_16a5;
	case 5800ULL: goto x86_l_16a8;
	case 5808ULL: goto x86_l_16b0;
	case 5815ULL: goto x86_l_16b7;
	case 5820ULL: goto x86_l_16bc;
	case 5825ULL: goto x86_l_16c1;
	case 5827ULL: goto x86_l_16c3;
	case 5830ULL: goto x86_l_16c6;
	case 5836ULL: goto x86_l_16cc;
	case 5839ULL: goto x86_l_16cf;
	case 5841ULL: goto x86_l_16d1;
	case 5845ULL: goto x86_l_16d5;
	case 5851ULL: goto x86_l_16db;
	case 5861ULL: goto x86_l_16e5;
	case 5869ULL: goto x86_l_16ed;
	case 5879ULL: goto x86_l_16f7;
	case 5887ULL: goto x86_l_16ff;
	case 5897ULL: goto x86_l_1709;
	case 5905ULL: goto x86_l_1711;
	case 5915ULL: goto x86_l_171b;
	case 5923ULL: goto x86_l_1723;
	case 5931ULL: goto x86_l_172b;
	case 5936ULL: goto x86_l_1730;
	case 5942ULL: goto x86_l_1736;
	case 5946ULL: goto x86_l_173a;
	case 5954ULL: goto x86_l_1742;
	case 5957ULL: goto x86_l_1745;
	case 5962ULL: goto x86_l_174a;
	case 5965ULL: goto x86_l_174d;
	case 5970ULL: goto x86_l_1752;
	case 5972ULL: goto x86_l_1754;
	case 5975ULL: goto x86_l_1757;
	case 5982ULL: goto x86_l_175e;
	case 5984ULL: goto x86_l_1760;
	case 5986ULL: goto x86_l_1762;
	case 5990ULL: goto x86_l_1766;
	case 5996ULL: goto x86_l_176c;
	case 5998ULL: goto x86_l_176e;
	case 6002ULL: goto x86_l_1772;
	case 6005ULL: goto x86_l_1775;
	case 6011ULL: goto x86_l_177b;
	case 6013ULL: goto x86_l_177d;
	case 6019ULL: goto x86_l_1783;
	case 6022ULL: goto x86_l_1786;
	case 6026ULL: goto x86_l_178a;
	case 6032ULL: goto x86_l_1790;
	case 6039ULL: goto x86_l_1797;
	case 6042ULL: goto x86_l_179a;
	case 6048ULL: goto x86_l_17a0;
	case 6058ULL: goto x86_l_17aa;
	case 6064ULL: goto x86_l_17b0;
	case 6069ULL: goto x86_l_17b5;
	case 6079ULL: goto x86_l_17bf;
	case 6084ULL: goto x86_l_17c4;
	case 6094ULL: goto x86_l_17ce;
	case 6099ULL: goto x86_l_17d3;
	case 6109ULL: goto x86_l_17dd;
	case 6114ULL: goto x86_l_17e2;
	case 6124ULL: goto x86_l_17ec;
	case 6129ULL: goto x86_l_17f1;
	case 6139ULL: goto x86_l_17fb;
	case 6144ULL: goto x86_l_1800;
	case 6154ULL: goto x86_l_180a;
	case 6159ULL: goto x86_l_180f;
	case 6164ULL: goto x86_l_1814;
	case 6169ULL: goto x86_l_1819;
	case 6174ULL: goto x86_l_181e;
	case 6178ULL: goto x86_l_1822;
	case 6183ULL: goto x86_l_1827;
	case 6185ULL: goto x86_l_1829;
	case 6187ULL: goto x86_l_182b;
	case 6192ULL: goto x86_l_1830;
	case 6202ULL: goto x86_l_183a;
	case 6210ULL: goto x86_l_1842;
	case 6220ULL: goto x86_l_184c;
	case 6228ULL: goto x86_l_1854;
	case 6238ULL: goto x86_l_185e;
	case 6246ULL: goto x86_l_1866;
	case 6256ULL: goto x86_l_1870;
	case 6264ULL: goto x86_l_1878;
	case 6274ULL: goto x86_l_1882;
	case 6282ULL: goto x86_l_188a;
	case 6292ULL: goto x86_l_1894;
	case 6300ULL: goto x86_l_189c;
	case 6308ULL: goto x86_l_18a4;
	case 6316ULL: goto x86_l_18ac;
	case 6321ULL: goto x86_l_18b1;
	case 6326ULL: goto x86_l_18b6;
	case 6332ULL: goto x86_l_18bc;
	case 6337ULL: goto x86_l_18c1;
	case 6339ULL: goto x86_l_18c3;
	case 6341ULL: goto x86_l_18c5;
	case 6348ULL: goto x86_l_18cc;
	case 6351ULL: goto x86_l_18cf;
	case 6355ULL: goto x86_l_18d3;
	case 6361ULL: goto x86_l_18d9;
	case 6368ULL: goto x86_l_18e0;
	case 6370ULL: goto x86_l_18e2;
	case 6377ULL: goto x86_l_18e9;
	case 6380ULL: goto x86_l_18ec;
	case 6386ULL: goto x86_l_18f2;
	case 6396ULL: goto x86_l_18fc;
	case 6402ULL: goto x86_l_1902;
	case 6407ULL: goto x86_l_1907;
	case 6409ULL: goto x86_l_1909;
	case 6417ULL: goto x86_l_1911;
	case 6423ULL: goto x86_l_1917;
	case 6430ULL: goto x86_l_191e;
	case 6437ULL: goto x86_l_1925;
	case 6442ULL: goto x86_l_192a;
	case 6447ULL: goto x86_l_192f;
	case 6449ULL: goto x86_l_1931;
	case 6452ULL: goto x86_l_1934;
	case 6458ULL: goto x86_l_193a;
	case 6466ULL: goto x86_l_1942;
	case 6476ULL: goto x86_l_194c;
	case 6480ULL: goto x86_l_1950;
	case 6483ULL: goto x86_l_1953;
	case 6486ULL: goto x86_l_1956;
	case 6493ULL: goto x86_l_195d;
	case 6496ULL: goto x86_l_1960;
	case 6503ULL: goto x86_l_1967;
	case 6507ULL: goto x86_l_196b;
	case 6510ULL: goto x86_l_196e;
	case 6513ULL: goto x86_l_1971;
	case 6520ULL: goto x86_l_1978;
	case 6527ULL: goto x86_l_197f;
	case 6530ULL: goto x86_l_1982;
	case 6536ULL: goto x86_l_1988;
	case 6540ULL: goto x86_l_198c;
	case 6546ULL: goto x86_l_1992;
	case 6553ULL: goto x86_l_1999;
	case 6558ULL: goto x86_l_199e;
	case 6565ULL: goto x86_l_19a5;
	case 6572ULL: goto x86_l_19ac;
	case 6577ULL: goto x86_l_19b1;
	case 6582ULL: goto x86_l_19b6;
	case 6584ULL: goto x86_l_19b8;
	case 6590ULL: goto x86_l_19be;
	case 6593ULL: goto x86_l_19c1;
	case 6599ULL: goto x86_l_19c7;
	case 6602ULL: goto x86_l_19ca;
	case 6605ULL: goto x86_l_19cd;
	case 6607ULL: goto x86_l_19cf;
	case 6611ULL: goto x86_l_19d3;
	case 6613ULL: goto x86_l_19d5;
	case 6617ULL: goto x86_l_19d9;
	case 6623ULL: goto x86_l_19df;
	case 6627ULL: goto x86_l_19e3;
	case 6633ULL: goto x86_l_19e9;
	case 6640ULL: goto x86_l_19f0;
	case 6643ULL: goto x86_l_19f3;
	case 6649ULL: goto x86_l_19f9;
	case 6655ULL: goto x86_l_19ff;
	case 6659ULL: goto x86_l_1a03;
	case 6662ULL: goto x86_l_1a06;
	case 6668ULL: goto x86_l_1a0c;
	case 6675ULL: goto x86_l_1a13;
	case 6678ULL: goto x86_l_1a16;
	case 6684ULL: goto x86_l_1a1c;
	case 6694ULL: goto x86_l_1a26;
	case 6702ULL: goto x86_l_1a2e;
	case 6712ULL: goto x86_l_1a38;
	case 6720ULL: goto x86_l_1a40;
	case 6730ULL: goto x86_l_1a4a;
	case 6738ULL: goto x86_l_1a52;
	case 6749ULL: goto x86_l_1a5d;
	case 6757ULL: goto x86_l_1a65;
	case 6762ULL: goto x86_l_1a6a;
	case 6767ULL: goto x86_l_1a6f;
	case 6772ULL: goto x86_l_1a74;
	case 6774ULL: goto x86_l_1a76;
	case 6776ULL: goto x86_l_1a78;
	case 6781ULL: goto x86_l_1a7d;
	case 6791ULL: goto x86_l_1a87;
	case 6796ULL: goto x86_l_1a8c;
	case 6806ULL: goto x86_l_1a96;
	case 6811ULL: goto x86_l_1a9b;
	case 6821ULL: goto x86_l_1aa5;
	case 6826ULL: goto x86_l_1aaa;
	case 6836ULL: goto x86_l_1ab4;
	case 6841ULL: goto x86_l_1ab9;
	case 6851ULL: goto x86_l_1ac3;
	case 6856ULL: goto x86_l_1ac8;
	case 6866ULL: goto x86_l_1ad2;
	case 6871ULL: goto x86_l_1ad7;
	case 6876ULL: goto x86_l_1adc;
	case 6881ULL: goto x86_l_1ae1;
	case 6886ULL: goto x86_l_1ae6;
	case 6890ULL: goto x86_l_1aea;
	case 6895ULL: goto x86_l_1aef;
	case 6897ULL: goto x86_l_1af1;
	case 6899ULL: goto x86_l_1af3;
	case 6901ULL: goto x86_l_1af5;
	case 6905ULL: goto x86_l_1af9;
	case 6911ULL: goto x86_l_1aff;
	case 6916ULL: goto x86_l_1b04;
	case 6926ULL: goto x86_l_1b0e;
	case 6931ULL: goto x86_l_1b13;
	case 6941ULL: goto x86_l_1b1d;
	case 6946ULL: goto x86_l_1b22;
	case 6956ULL: goto x86_l_1b2c;
	case 6961ULL: goto x86_l_1b31;
	case 6971ULL: goto x86_l_1b3b;
	case 6976ULL: goto x86_l_1b40;
	case 6986ULL: goto x86_l_1b4a;
	case 6991ULL: goto x86_l_1b4f;
	case 6999ULL: goto x86_l_1b57;
	case 7004ULL: goto x86_l_1b5c;
	case 7009ULL: goto x86_l_1b61;
	case 7014ULL: goto x86_l_1b66;
	case 7019ULL: goto x86_l_1b6b;
	case 7022ULL: goto x86_l_1b6e;
	case 7024ULL: goto x86_l_1b70;
	case 7026ULL: goto x86_l_1b72;
	case 7031ULL: goto x86_l_1b77;
	case 7034ULL: goto x86_l_1b7a;
	case 7042ULL: goto x86_l_1b82;
	case 7045ULL: goto x86_l_1b85;
	case 7050ULL: goto x86_l_1b8a;
	case 7060ULL: goto x86_l_1b94;
	case 7065ULL: goto x86_l_1b99;
	case 7075ULL: goto x86_l_1ba3;
	case 7080ULL: goto x86_l_1ba8;
	case 7090ULL: goto x86_l_1bb2;
	case 7095ULL: goto x86_l_1bb7;
	case 7105ULL: goto x86_l_1bc1;
	case 7110ULL: goto x86_l_1bc6;
	case 7120ULL: goto x86_l_1bd0;
	case 7125ULL: goto x86_l_1bd5;
	case 7133ULL: goto x86_l_1bdd;
	case 7138ULL: goto x86_l_1be2;
	case 7143ULL: goto x86_l_1be7;
	case 7148ULL: goto x86_l_1bec;
	case 7153ULL: goto x86_l_1bf1;
	case 7156ULL: goto x86_l_1bf4;
	case 7158ULL: goto x86_l_1bf6;
	case 7160ULL: goto x86_l_1bf8;
	case 7165ULL: goto x86_l_1bfd;
	case 7168ULL: goto x86_l_1c00;
	case 7173ULL: goto x86_l_1c05;
	case 7183ULL: goto x86_l_1c0f;
	case 7191ULL: goto x86_l_1c17;
	case 7201ULL: goto x86_l_1c21;
	case 7209ULL: goto x86_l_1c29;
	case 7219ULL: goto x86_l_1c33;
	case 7227ULL: goto x86_l_1c3b;
	case 7237ULL: goto x86_l_1c45;
	case 7245ULL: goto x86_l_1c4d;
	case 7255ULL: goto x86_l_1c57;
	case 7263ULL: goto x86_l_1c5f;
	case 7273ULL: goto x86_l_1c69;
	case 7281ULL: goto x86_l_1c71;
	case 7291ULL: goto x86_l_1c7b;
	case 7299ULL: goto x86_l_1c83;
	case 7304ULL: goto x86_l_1c88;
	case 7310ULL: goto x86_l_1c8e;
	case 7317ULL: goto x86_l_1c95;
	case 7322ULL: goto x86_l_1c9a;
	case 7325ULL: goto x86_l_1c9d;
	case 7328ULL: goto x86_l_1ca0;
	case 7330ULL: goto x86_l_1ca2;
	case 7333ULL: goto x86_l_1ca5;
	case 7340ULL: goto x86_l_1cac;
	case 7343ULL: goto x86_l_1caf;
	case 7349ULL: goto x86_l_1cb5;
	case 7359ULL: goto x86_l_1cbf;
	case 7367ULL: goto x86_l_1cc7;
	case 7377ULL: goto x86_l_1cd1;
	case 7385ULL: goto x86_l_1cd9;
	case 7395ULL: goto x86_l_1ce3;
	case 7403ULL: goto x86_l_1ceb;
	case 7413ULL: goto x86_l_1cf5;
	case 7421ULL: goto x86_l_1cfd;
	case 7431ULL: goto x86_l_1d07;
	case 7439ULL: goto x86_l_1d0f;
	case 7447ULL: goto x86_l_1d17;
	case 7455ULL: goto x86_l_1d1f;
	case 7460ULL: goto x86_l_1d24;
	case 7466ULL: goto x86_l_1d2a;
	case 7473ULL: goto x86_l_1d31;
	case 7480ULL: goto x86_l_1d38;
	case 7485ULL: goto x86_l_1d3d;
	case 7487ULL: goto x86_l_1d3f;
	case 7490ULL: goto x86_l_1d42;
	case 7495ULL: goto x86_l_1d47;
	case 7505ULL: goto x86_l_1d51;
	case 7513ULL: goto x86_l_1d59;
	case 7523ULL: goto x86_l_1d63;
	case 7531ULL: goto x86_l_1d6b;
	case 7541ULL: goto x86_l_1d75;
	case 7549ULL: goto x86_l_1d7d;
	case 7559ULL: goto x86_l_1d87;
	case 7567ULL: goto x86_l_1d8f;
	case 7575ULL: goto x86_l_1d97;
	case 7580ULL: goto x86_l_1d9c;
	case 7585ULL: goto x86_l_1da1;
	case 7590ULL: goto x86_l_1da6;
	case 7595ULL: goto x86_l_1dab;
	case 7597ULL: goto x86_l_1dad;
	case 7599ULL: goto x86_l_1daf;
	case 7605ULL: goto x86_l_1db5;
	case 7609ULL: goto x86_l_1db9;
	case 7612ULL: goto x86_l_1dbc;
	case 7618ULL: goto x86_l_1dc2;
	case 7626ULL: goto x86_l_1dca;
	case 7633ULL: goto x86_l_1dd1;
	case 7638ULL: goto x86_l_1dd6;
	case 7643ULL: goto x86_l_1ddb;
	case 7645ULL: goto x86_l_1ddd;
	case 7648ULL: goto x86_l_1de0;
	case 7650ULL: goto x86_l_1de2;
	case 7653ULL: goto x86_l_1de5;
	case 7655ULL: goto x86_l_1de7;
	case 7662ULL: goto x86_l_1dee;
	case 7665ULL: goto x86_l_1df1;
	case 7671ULL: goto x86_l_1df7;
	case 7676ULL: goto x86_l_1dfc;
	case 7681ULL: goto x86_l_1e01;
	case 7684ULL: goto x86_l_1e04;
	case 7688ULL: goto x86_l_1e08;
	case 7695ULL: goto x86_l_1e0f;
	case 7701ULL: goto x86_l_1e15;
	case 7706ULL: goto x86_l_1e1a;
	case 7712ULL: goto x86_l_1e20;
	case 7720ULL: goto x86_l_1e28;
	case 7727ULL: goto x86_l_1e2f;
	case 7732ULL: goto x86_l_1e34;
	case 7737ULL: goto x86_l_1e39;
	case 7739ULL: goto x86_l_1e3b;
	case 7742ULL: goto x86_l_1e3e;
	case 7748ULL: goto x86_l_1e44;
	case 7751ULL: goto x86_l_1e47;
	case 7756ULL: goto x86_l_1e4c;
	case 7762ULL: goto x86_l_1e52;
	case 7772ULL: goto x86_l_1e5c;
	case 7780ULL: goto x86_l_1e64;
	case 7790ULL: goto x86_l_1e6e;
	case 7798ULL: goto x86_l_1e76;
	case 7808ULL: goto x86_l_1e80;
	case 7816ULL: goto x86_l_1e88;
	case 7826ULL: goto x86_l_1e92;
	case 7834ULL: goto x86_l_1e9a;
	case 7844ULL: goto x86_l_1ea4;
	case 7852ULL: goto x86_l_1eac;
	case 7863ULL: goto x86_l_1eb7;
	case 7871ULL: goto x86_l_1ebf;
	case 7876ULL: goto x86_l_1ec4;
	case 7882ULL: goto x86_l_1eca;
	case 7889ULL: goto x86_l_1ed1;
	case 7896ULL: goto x86_l_1ed8;
	case 7903ULL: goto x86_l_1edf;
	case 7908ULL: goto x86_l_1ee4;
	case 7910ULL: goto x86_l_1ee6;
	case 7913ULL: goto x86_l_1ee9;
	case 7915ULL: goto x86_l_1eeb;
	case 7920ULL: goto x86_l_1ef0;
	case 7926ULL: goto x86_l_1ef6;
	case 7932ULL: goto x86_l_1efc;
	case 7936ULL: goto x86_l_1f00;
	case 7942ULL: goto x86_l_1f06;
	case 7949ULL: goto x86_l_1f0d;
	case 7956ULL: goto x86_l_1f14;
	case 7963ULL: goto x86_l_1f1b;
	case 7966ULL: goto x86_l_1f1e;
	case 7972ULL: goto x86_l_1f24;
	case 7976ULL: goto x86_l_1f28;
	case 7984ULL: goto x86_l_1f30;
	case 7992ULL: goto x86_l_1f38;
	case 8000ULL: goto x86_l_1f40;
	case 8007ULL: goto x86_l_1f47;
	case 8018ULL: goto x86_l_1f52;
	case 8028ULL: goto x86_l_1f5c;
	case 8039ULL: goto x86_l_1f67;
	case 8046ULL: goto x86_l_1f6e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1670:
	/* 0x1670: jmp    5f53 <kprobe_unwind_native+0x5f53> */
	return 24403ULL;
x86_l_1675:
	/* 0x1675: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_167c:
	/* 0x167c: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_167f:
	/* 0x167f: jne    17b5 <kprobe_unwind_native+0x17b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_17b5;
	}
x86_l_1685:
	/* 0x1685: mov    r13d,0xfa7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4007ULL);
x86_l_168b:
	/* 0x168b: jmp    5f53 <kprobe_unwind_native+0x5f53> */
	return 24403ULL;
x86_l_1690:
	/* 0x1690: mov    QWORD PTR [rbx+0xed8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_1697:
	/* 0x1697: mov    BYTE PTR [rbx+0xf30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16698832846849ULL);
x86_l_169e:
	/* 0x169e: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_16a5:
	/* 0x16a5: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_16a8:
	/* 0x16a8: mov    DWORD PTR [rsp+0x78],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075526ULL);
x86_l_16b0:
	/* 0x16b0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_16b7:
	/* 0x16b7: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_16bc:
	/* 0x16bc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16c1:
	/* 0x16c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c3:
	/* 0x16c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16c6:
	/* 0x16c6: je     1762 <kprobe_unwind_native+0x1762> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1762;
	}
x86_l_16cc:
	/* 0x16cc: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_16cf:
	/* 0x16cf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16d1:
	/* 0x16d1: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16d5:
	/* 0x16d5: je     176e <kprobe_unwind_native+0x176e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_176e;
	}
x86_l_16db:
	/* 0x16db: movabs rax,0xa786c6c25203a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947156833280058ULL);
x86_l_16e5:
	/* 0x16e5: mov    QWORD PTR [rsp+0xb5],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 181ULL);
x86_l_16ed:
	/* 0x16ed: movabs rax,0x25203a706620786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675202433082226796ULL);
x86_l_16f7:
	/* 0x16f7: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_16ff:
	/* 0x16ff: movabs rax,0x6c25203a70732078 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7792670165601296504ULL);
x86_l_1709:
	/* 0x1709: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1711:
	/* 0x1711: movabs rax,0x6c6c25203a637020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660273929744416ULL);
x86_l_171b:
	/* 0x171b: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1723:
	/* 0x1723: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_172b:
	/* 0x172b: mov    eax,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_1730:
	/* 0x1730: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1736:
	/* 0x1736: mov    rdx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_173a:
	/* 0x173a: mov    rax,QWORD PTR [rsp+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_1742:
	/* 0x1742: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1745:
	/* 0x1745: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_174a:
	/* 0x174a: mov    r8,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_174d:
	/* 0x174d: mov    esi,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 29ULL);
x86_l_1752:
	/* 0x1752: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1754:
	/* 0x1754: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_1757:
	/* 0x1757: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_175e:
	/* 0x175e: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1760:
	/* 0x1760: jmp    176e <kprobe_unwind_native+0x176e> */
	goto x86_l_176e;
x86_l_1762:
	/* 0x1762: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1766:
	/* 0x1766: jne    1a7d <kprobe_unwind_native+0x1a7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a7d;
	}
x86_l_176c:
	/* 0x176c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_176e:
	/* 0x176e: mov    r13,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1772:
	/* 0x1772: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1775:
	/* 0x1775: je     707e <kprobe_unwind_native+0x707e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28798ULL;
	}
x86_l_177b:
	/* 0x177b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_177d:
	/* 0x177d: jne    1830 <kprobe_unwind_native+0x1830> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1830;
	}
x86_l_1783:
	/* 0x1783: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_1786:
	/* 0x1786: shr    rax,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_178a:
	/* 0x178a: je     18d9 <kprobe_unwind_native+0x18d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18d9;
	}
x86_l_1790:
	/* 0x1790: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1797:
	/* 0x1797: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_179a:
	/* 0x179a: jne    33b3 <kprobe_unwind_native+0x33b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13235ULL;
	}
x86_l_17a0:
	/* 0x17a0: mov    DWORD PTR [rbx+0xf28],0xb */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16664473108491ULL);
x86_l_17aa:
	/* 0x17aa: mov    r14d,0xfab */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4011ULL);
x86_l_17b0:
	/* 0x17b0: jmp    7156 <kprobe_unwind_native+0x7156> */
	return 29014ULL;
x86_l_17b5:
	/* 0x17b5: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_17bf:
	/* 0x17bf: mov    QWORD PTR [rsp+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_17c4:
	/* 0x17c4: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_17ce:
	/* 0x17ce: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17d3:
	/* 0x17d3: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_17dd:
	/* 0x17dd: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17e2:
	/* 0x17e2: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_17ec:
	/* 0x17ec: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17f1:
	/* 0x17f1: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_17fb:
	/* 0x17fb: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1800:
	/* 0x1800: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_180a:
	/* 0x180a: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_180f:
	/* 0x180f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1814:
	/* 0x1814: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1819:
	/* 0x1819: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_181e:
	/* 0x181e: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1822:
	/* 0x1822: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1827:
	/* 0x1827: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1829:
	/* 0x1829: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_182b:
	/* 0x182b: jmp    1685 <kprobe_unwind_native+0x1685> */
	goto x86_l_1685;
x86_l_1830:
	/* 0x1830: movabs rax,0xa3d3d3d3d206425 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 737813247186461733ULL);
x86_l_183a:
	/* 0x183a: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1842:
	/* 0x1842: movabs rax,0x20656d617266203a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334392247160021050ULL);
x86_l_184c:
	/* 0x184c: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1854:
	/* 0x1854: movabs rax,0x7265646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243105118350175861ULL);
x86_l_185e:
	/* 0x185e: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1866:
	/* 0x1866: movabs rax,0x20656d6172662074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334392247160021108ULL);
x86_l_1870:
	/* 0x1870: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1878:
	/* 0x1878: movabs rax,0x78656e2065766c6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8675461342619397231ULL);
x86_l_1882:
	/* 0x1882: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_188a:
	/* 0x188a: movabs rax,0x736552203d3d3d3d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8315142585429343549ULL);
x86_l_1894:
	/* 0x1894: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_189c:
	/* 0x189c: mov    BYTE PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_18a4:
	/* 0x18a4: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_18ac:
	/* 0x18ac: mov    eax,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 49ULL);
x86_l_18b1:
	/* 0x18b1: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_18b6:
	/* 0x18b6: mov    edx,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_18bc:
	/* 0x18bc: mov    esi,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 49ULL);
x86_l_18c1:
	/* 0x18c1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18c3:
	/* 0x18c3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_18c5:
	/* 0x18c5: mov    r13,QWORD PTR [rbx+0xed0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_18cc:
	/* 0x18cc: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_18cf:
	/* 0x18cf: shr    rax,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_18d3:
	/* 0x18d3: jne    1790 <kprobe_unwind_native+0x1790> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1790;
	}
x86_l_18d9:
	/* 0x18d9: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_18e0:
	/* 0x18e0: ja     1907 <kprobe_unwind_native+0x1907> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1907;
	}
x86_l_18e2:
	/* 0x18e2: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_18e9:
	/* 0x18e9: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18ec:
	/* 0x18ec: jne    34f9 <kprobe_unwind_native+0x34f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13561ULL;
	}
x86_l_18f2:
	/* 0x18f2: mov    DWORD PTR [rbx+0xf28],0x31 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16664473108529ULL);
x86_l_18fc:
	/* 0x18fc: mov    r14d,0xfae */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4014ULL);
x86_l_1902:
	/* 0x1902: jmp    7156 <kprobe_unwind_native+0x7156> */
	return 29014ULL;
x86_l_1907:
	/* 0x1907: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1909:
	/* 0x1909: mov    DWORD PTR [rsp+0x10],0x60 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476832ULL);
x86_l_1911:
	/* 0x1911: movbe  DWORD PTR [rsp+0x14],eax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1917:
	/* 0x1917: movbe  QWORD PTR [rsp+0x18],r13 */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_191e:
	/* 0x191e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_page_to_mapping_info)));
x86_l_1925:
	/* 0x1925: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_192a:
	/* 0x192a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_192f:
	/* 0x192f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1931:
	/* 0x1931: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1934:
	/* 0x1934: je     713a <kprobe_unwind_native+0x713a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28986ULL;
	}
x86_l_193a:
	/* 0x193a: mov    QWORD PTR [rsp+0x140],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_1942:
	/* 0x1942: movabs rdx,0xffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 72057594037927935ULL);
x86_l_194c:
	/* 0x194c: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1950:
	/* 0x1950: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_1953:
	/* 0x1953: and    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1956:
	/* 0x1956: mov    QWORD PTR [rbx+0xf20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3872ULL);
x86_l_195d:
	/* 0x195d: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1960:
	/* 0x1960: mov    QWORD PTR [rbx+0xf10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_1967:
	/* 0x1967: shr    r12,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_196b:
	/* 0x196b: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_196e:
	/* 0x196e: sub    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1971:
	/* 0x1971: mov    QWORD PTR [rbx+0xf18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_1978:
	/* 0x1978: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_197f:
	/* 0x197f: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1982:
	/* 0x1982: jne    1c05 <kprobe_unwind_native+0x1c05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c05;
	}
x86_l_1988:
	/* 0x1988: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_198c:
	/* 0x198c: jne    1e01 <kprobe_unwind_native+0x1e01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e01;
	}
x86_l_1992:
	/* 0x1992: mov    rax,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_1999:
	/* 0x1999: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_199e:
	/* 0x199e: mov    r14,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_19a5:
	/* 0x19a5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&interpreter_offsets)));
x86_l_19ac:
	/* 0x19ac: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19b1:
	/* 0x19b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19b6:
	/* 0x19b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b8:
	/* 0x19b8: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_19be:
	/* 0x19be: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19c1:
	/* 0x19c1: je     1e01 <kprobe_unwind_native+0x1e01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e01;
	}
x86_l_19c7:
	/* 0x19c7: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_19ca:
	/* 0x19ca: cmp    QWORD PTR [rax],r14 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19cd:
	/* 0x19cd: ja     19d5 <kprobe_unwind_native+0x19d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_19d5;
	}
x86_l_19cf:
	/* 0x19cf: cmp    QWORD PTR [r13+0x8],r14 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19d3:
	/* 0x19d3: jae    19e9 <kprobe_unwind_native+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_19e9;
	}
x86_l_19d5:
	/* 0x19d5: cmp    QWORD PTR [r13+0x10],r14 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19d9:
	/* 0x19d9: ja     1e01 <kprobe_unwind_native+0x1e01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e01;
	}
x86_l_19df:
	/* 0x19df: cmp    QWORD PTR [r13+0x18],r14 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19e3:
	/* 0x19e3: jb     1e01 <kprobe_unwind_native+0x1e01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1e01;
	}
x86_l_19e9:
	/* 0x19e9: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_19f0:
	/* 0x19f0: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19f3:
	/* 0x19f3: jne    1d47 <kprobe_unwind_native+0x1d47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d47;
	}
x86_l_19f9:
	/* 0x19f9: mov    eax,DWORD PTR [rbx+0x1380] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4992ULL);
x86_l_19ff:
	/* 0x19ff: mov    ecx,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a03:
	/* 0x1a03: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1a06:
	/* 0x1a06: jae    1dc2 <kprobe_unwind_native+0x1dc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1dc2;
	}
x86_l_1a0c:
	/* 0x1a0c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1a13:
	/* 0x1a13: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a16:
	/* 0x1a16: je     1dfc <kprobe_unwind_native+0x1dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dfc;
	}
x86_l_1a1c:
	/* 0x1a1c: movabs rax,0x6e6f64207265646e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7957689157107934318ULL);
x86_l_1a26:
	/* 0x1a26: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1a2e:
	/* 0x1a2e: movabs rax,0x69776e7520726574 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7599664345545598324ULL);
x86_l_1a38:
	/* 0x1a38: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1a40:
	/* 0x1a40: movabs rax,0x6572707265746e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310028781806448233ULL);
x86_l_1a4a:
	/* 0x1a4a: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1a52:
	/* 0x1a52: mov    DWORD PTR [rsp+0xb7],0xa656e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 785979696494ULL);
x86_l_1a5d:
	/* 0x1a5d: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1a65:
	/* 0x1a65: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1a6a:
	/* 0x1a6a: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1a6f:
	/* 0x1a6f: mov    esi,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 27ULL);
x86_l_1a74:
	/* 0x1a74: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a76:
	/* 0x1a76: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1a78:
	/* 0x1a78: jmp    1dfc <kprobe_unwind_native+0x1dfc> */
	goto x86_l_1dfc;
x86_l_1a7d:
	/* 0x1a7d: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1a87:
	/* 0x1a87: mov    QWORD PTR [rsp+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_1a8c:
	/* 0x1a8c: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1a96:
	/* 0x1a96: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a9b:
	/* 0x1a9b: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1aa5:
	/* 0x1aa5: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1aaa:
	/* 0x1aaa: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1ab4:
	/* 0x1ab4: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ab9:
	/* 0x1ab9: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1ac3:
	/* 0x1ac3: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ac8:
	/* 0x1ac8: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1ad2:
	/* 0x1ad2: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ad7:
	/* 0x1ad7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1adc:
	/* 0x1adc: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1ae1:
	/* 0x1ae1: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1ae6:
	/* 0x1ae6: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1aea:
	/* 0x1aea: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1aef:
	/* 0x1aef: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1af1:
	/* 0x1af1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1af3:
	/* 0x1af3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1af5:
	/* 0x1af5: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1af9:
	/* 0x1af9: je     176e <kprobe_unwind_native+0x176e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_176e;
	}
x86_l_1aff:
	/* 0x1aff: jmp    16db <kprobe_unwind_native+0x16db> */
	goto x86_l_16db;
x86_l_1b04:
	/* 0x1b04: movabs rax,0x2578302073736572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2699960892542641522ULL);
x86_l_1b0e:
	/* 0x1b0e: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b13:
	/* 0x1b13: movabs rax,0x6464612065636e65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7234013693231722085ULL);
x86_l_1b1d:
	/* 0x1b1d: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b22:
	/* 0x1b22: movabs rax,0x7265666572656420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243107278868538400ULL);
x86_l_1b2c:
	/* 0x1b2c: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b31:
	/* 0x1b31: movabs rax,0x6f742064656c6961 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8031079651078859105ULL);
x86_l_1b3b:
	/* 0x1b3b: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b40:
	/* 0x1b40: movabs rax,0x6620646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358992216502005365ULL);
x86_l_1b4a:
	/* 0x1b4a: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b4f:
	/* 0x1b4f: mov    DWORD PTR [rsp+0x38],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518854764ULL);
x86_l_1b57:
	/* 0x1b57: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b5c:
	/* 0x1b5c: mov    eax,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_1b61:
	/* 0x1b61: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1b66:
	/* 0x1b66: mov    esi,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_1b6b:
	/* 0x1b6b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1b6e:
	/* 0x1b6e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b70:
	/* 0x1b70: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1b72:
	/* 0x1b72: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1b77:
	/* 0x1b77: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_1b7a:
	/* 0x1b7a: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1b82:
	/* 0x1b82: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b85:
	/* 0x1b85: jmp    1458 <kprobe_unwind_native+0x1458> */
	return 5208ULL;
x86_l_1b8a:
	/* 0x1b8a: movabs rax,0x2578302073736572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2699960892542641522ULL);
x86_l_1b94:
	/* 0x1b94: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b99:
	/* 0x1b99: movabs rax,0x6464612065636e65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7234013693231722085ULL);
x86_l_1ba3:
	/* 0x1ba3: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ba8:
	/* 0x1ba8: movabs rax,0x7265666572656420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243107278868538400ULL);
x86_l_1bb2:
	/* 0x1bb2: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bb7:
	/* 0x1bb7: movabs rax,0x6f742064656c6961 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8031079651078859105ULL);
x86_l_1bc1:
	/* 0x1bc1: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bc6:
	/* 0x1bc6: movabs rax,0x6620646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358992216502005365ULL);
x86_l_1bd0:
	/* 0x1bd0: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bd5:
	/* 0x1bd5: mov    DWORD PTR [rsp+0x38],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518854764ULL);
x86_l_1bdd:
	/* 0x1bdd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1be2:
	/* 0x1be2: mov    eax,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_1be7:
	/* 0x1be7: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1bec:
	/* 0x1bec: mov    esi,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_1bf1:
	/* 0x1bf1: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1bf4:
	/* 0x1bf4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bf6:
	/* 0x1bf6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1bf8:
	/* 0x1bf8: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1bfd:
	/* 0x1bfd: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_1c00:
	/* 0x1c00: jmp    154b <kprobe_unwind_native+0x154b> */
	return 5451ULL;
x86_l_1c05:
	/* 0x1c05: movabs rax,0x296425207265646e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2982549674514539630ULL);
x86_l_1c0f:
	/* 0x1c0f: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1c17:
	/* 0x1c17: movabs rax,0x69776e752820786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7599664345674446956ULL);
x86_l_1c21:
	/* 0x1c21: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1c29:
	/* 0x1c29: movabs rax,0x6c2520736920786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7792670410291574892ULL);
x86_l_1c33:
	/* 0x1c33: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1c3b:
	/* 0x1c3b: movabs rax,0x2520435020726f66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675212190078889830ULL);
x86_l_1c45:
	/* 0x1c45: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1c4d:
	/* 0x1c4d: movabs rax,0x206469206e6f6974 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334106094897424756ULL);
x86_l_1c57:
	/* 0x1c57: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1c5f:
	/* 0x1c5f: movabs r14,0x6365732074786554 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 7162257365632836948ULL);
x86_l_1c69:
	/* 0x1c69: mov    QWORD PTR [rsp+0xa0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1c71:
	/* 0x1c71: mov    WORD PTR [rsp+0xd0],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 893353197578ULL);
x86_l_1c7b:
	/* 0x1c7b: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1c83:
	/* 0x1c83: mov    eax,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_1c88:
	/* 0x1c88: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1c8e:
	/* 0x1c8e: mov    rcx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_1c95:
	/* 0x1c95: mov    esi,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 50ULL);
x86_l_1c9a:
	/* 0x1c9a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1c9d:
	/* 0x1c9d: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1ca0:
	/* 0x1ca0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ca2:
	/* 0x1ca2: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_1ca5:
	/* 0x1ca5: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1cac:
	/* 0x1cac: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1caf:
	/* 0x1caf: je     1988 <kprobe_unwind_native+0x1988> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1988;
	}
x86_l_1cb5:
	/* 0x1cb5: movabs rax,0xa786c6c252073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947156833280115ULL);
x86_l_1cbf:
	/* 0x1cbf: mov    QWORD PTR [rsp+0xc7],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 199ULL);
x86_l_1cc7:
	/* 0x1cc7: movabs rax,0x7369207465736666 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8316213871206688358ULL);
x86_l_1cd1:
	/* 0x1cd1: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1cd9:
	/* 0x1cd9: movabs rax,0x6f20646e61202c78 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8007510562703420536ULL);
x86_l_1ce3:
	/* 0x1ce3: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1ceb:
	/* 0x1ceb: movabs rax,0x6c6c252073692073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660274886418547ULL);
x86_l_1cf5:
	/* 0x1cf5: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1cfd:
	/* 0x1cfd: movabs rax,0x616962206e6f6974 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7019249385664899444ULL);
x86_l_1d07:
	/* 0x1d07: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1d0f:
	/* 0x1d0f: mov    QWORD PTR [rsp+0xa0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1d17:
	/* 0x1d17: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1d1f:
	/* 0x1d1f: mov    eax,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 47ULL);
x86_l_1d24:
	/* 0x1d24: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_1d2a:
	/* 0x1d2a: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_1d31:
	/* 0x1d31: mov    rdx,QWORD PTR [rbx+0xf20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3872ULL);
x86_l_1d38:
	/* 0x1d38: mov    esi,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 47ULL);
x86_l_1d3d:
	/* 0x1d3d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d3f:
	/* 0x1d3f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1d42:
	/* 0x1d42: jmp    1988 <kprobe_unwind_native+0x1988> */
	goto x86_l_1988;
x86_l_1d47:
	/* 0x1d47: movabs rax,0xa642520686374 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860387386228ULL);
x86_l_1d51:
	/* 0x1d51: mov    QWORD PTR [rsp+0xb6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_1d59:
	/* 0x1d59: movabs rax,0x6374616d20737465 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7166460028377068645ULL);
x86_l_1d63:
	/* 0x1d63: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1d6b:
	/* 0x1d6b: movabs rax,0x7366666f5f726574 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8315446390514935156ULL);
x86_l_1d75:
	/* 0x1d75: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1d7d:
	/* 0x1d7d: movabs rax,0x6572707265746e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310028781806448233ULL);
x86_l_1d87:
	/* 0x1d87: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1d8f:
	/* 0x1d8f: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1d97:
	/* 0x1d97: mov    eax,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 30ULL);
x86_l_1d9c:
	/* 0x1d9c: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1da1:
	/* 0x1da1: movzx  edx,WORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1da6:
	/* 0x1da6: mov    esi,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 30ULL);
x86_l_1dab:
	/* 0x1dab: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dad:
	/* 0x1dad: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1daf:
	/* 0x1daf: mov    eax,DWORD PTR [rbx+0x1380] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4992ULL);
x86_l_1db5:
	/* 0x1db5: mov    ecx,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1db9:
	/* 0x1db9: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1dbc:
	/* 0x1dbc: jb     1a0c <kprobe_unwind_native+0x1a0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a0c;
	}
x86_l_1dc2:
	/* 0x1dc2: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_1dca:
	/* 0x1dca: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_1dd1:
	/* 0x1dd1: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1dd6:
	/* 0x1dd6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ddb:
	/* 0x1ddb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ddd:
	/* 0x1ddd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1de0:
	/* 0x1de0: je     1de7 <kprobe_unwind_native+0x1de7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1de7;
	}
x86_l_1de2:
	/* 0x1de2: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1de5:
	/* 0x1de5: jmp    1df7 <kprobe_unwind_native+0x1df7> */
	goto x86_l_1df7;
x86_l_1de7:
	/* 0x1de7: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1dee:
	/* 0x1dee: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1df1:
	/* 0x1df1: jne    2deb <kprobe_unwind_native+0x2deb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11755ULL;
	}
x86_l_1df7:
	/* 0x1df7: movzx  r12d,WORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1dfc:
	/* 0x1dfc: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1e01:
	/* 0x1e01: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e04:
	/* 0x1e04: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_1e08:
	/* 0x1e08: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1e0f:
	/* 0x1e0f: jne    5f60 <kprobe_unwind_native+0x5f60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24416ULL;
	}
x86_l_1e15:
	/* 0x1e15: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e1a:
	/* 0x1e1a: jne    2afe <kprobe_unwind_native+0x2afe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11006ULL;
	}
x86_l_1e20:
	/* 0x1e20: mov    DWORD PTR [rsp+0x10],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476741ULL);
x86_l_1e28:
	/* 0x1e28: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_1e2f:
	/* 0x1e2f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e34:
	/* 0x1e34: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e39:
	/* 0x1e39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e3b:
	/* 0x1e3b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e3e:
	/* 0x1e3e: je     1eeb <kprobe_unwind_native+0x1eeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1eeb;
	}
x86_l_1e44:
	/* 0x1e44: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1e47:
	/* 0x1e47: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e4c:
	/* 0x1e4c: je     1ef6 <kprobe_unwind_native+0x1ef6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ef6;
	}
x86_l_1e52:
	/* 0x1e52: movabs rax,0x63617473206e6f20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7161132920309968672ULL);
x86_l_1e5c:
	/* 0x1e5c: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1e64:
	/* 0x1e64: movabs rax,0x7525206e6f697469 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8441188735263536233ULL);
x86_l_1e6e:
	/* 0x1e6e: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1e76:
	/* 0x1e76: movabs rax,0x736f70206f742078 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8317990321387741304ULL);
x86_l_1e80:
	/* 0x1e80: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1e88:
	/* 0x1e88: movabs rax,0x6c6c2520786c6c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660274970520613ULL);
x86_l_1e92:
	/* 0x1e92: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1e9a:
	/* 0x1e9a: movabs rax,0x20676e6968737550 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334956330817910096ULL);
x86_l_1ea4:
	/* 0x1ea4: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1eac:
	/* 0x1eac: mov    DWORD PTR [rsp+0xc7],0xa6b63 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 854699174755ULL);
x86_l_1eb7:
	/* 0x1eb7: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1ebf:
	/* 0x1ebf: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1ec4:
	/* 0x1ec4: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1eca:
	/* 0x1eca: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_1ed1:
	/* 0x1ed1: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_1ed8:
	/* 0x1ed8: mov    r8d,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_1edf:
	/* 0x1edf: mov    esi,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 43ULL);
x86_l_1ee4:
	/* 0x1ee4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ee6:
	/* 0x1ee6: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_1ee9:
	/* 0x1ee9: jmp    1ef6 <kprobe_unwind_native+0x1ef6> */
	goto x86_l_1ef6;
x86_l_1eeb:
	/* 0x1eeb: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ef0:
	/* 0x1ef0: jne    2bd3 <kprobe_unwind_native+0x2bd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11219ULL;
	}
x86_l_1ef6:
	/* 0x1ef6: mov    eax,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_1efc:
	/* 0x1efc: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_1f00:
	/* 0x1f00: ja     141 <kprobe_unwind_native+0x141> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 321ULL;
	}
x86_l_1f06:
	/* 0x1f06: movzx  ecx,BYTE PTR [rbx+0xf30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3888ULL);
x86_l_1f0d:
	/* 0x1f0d: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_1f14:
	/* 0x1f14: mov    rsi,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_1f1b:
	/* 0x1f1b: lea    edi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1f1e:
	/* 0x1f1e: mov    DWORD PTR [rbx+0x2c0],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_1f24:
	/* 0x1f24: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_1f28:
	/* 0x1f28: mov    QWORD PTR [rbx+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_1f30:
	/* 0x1f30: mov    QWORD PTR [rbx+rax*8+0x2d8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_1f38:
	/* 0x1f38: mov    BYTE PTR [rbx+rax*8+0x2e0],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 3161095929859ULL);
x86_l_1f40:
	/* 0x1f40: mov    BYTE PTR [rbx+rax*8+0x2e1],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 737ULL);
x86_l_1f47:
	/* 0x1f47: mov    DWORD PTR [rbx+rax*8+0x2e2],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3169685864448ULL);
x86_l_1f52:
	/* 0x1f52: mov    WORD PTR [rbx+rax*8+0x2e6],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3186865733632ULL);
x86_l_1f5c:
	/* 0x1f5c: mov    DWORD PTR [rsp+0x8c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1f67:
	/* 0x1f67: mov    rax,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_1f6e:
	/* 0x1f6e: mov    QWORD PTR [rsp+0x160],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
	return 8054ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8054ULL: goto x86_l_1f76;
	case 8059ULL: goto x86_l_1f7b;
	case 8066ULL: goto x86_l_1f82;
	case 8073ULL: goto x86_l_1f89;
	case 8081ULL: goto x86_l_1f91;
	case 8086ULL: goto x86_l_1f96;
	case 8092ULL: goto x86_l_1f9c;
	case 8099ULL: goto x86_l_1fa3;
	case 8104ULL: goto x86_l_1fa8;
	case 8109ULL: goto x86_l_1fad;
	case 8111ULL: goto x86_l_1faf;
	case 8114ULL: goto x86_l_1fb2;
	case 8120ULL: goto x86_l_1fb8;
	case 8123ULL: goto x86_l_1fbb;
	case 8126ULL: goto x86_l_1fbe;
	case 8130ULL: goto x86_l_1fc2;
	case 8134ULL: goto x86_l_1fc6;
	case 8137ULL: goto x86_l_1fc9;
	case 8139ULL: goto x86_l_1fcb;
	case 8142ULL: goto x86_l_1fce;
	case 8144ULL: goto x86_l_1fd0;
	case 8147ULL: goto x86_l_1fd3;
	case 8153ULL: goto x86_l_1fd9;
	case 8156ULL: goto x86_l_1fdc;
	case 8162ULL: goto x86_l_1fe2;
	case 8165ULL: goto x86_l_1fe5;
	case 8171ULL: goto x86_l_1feb;
	case 8178ULL: goto x86_l_1ff2;
	case 8183ULL: goto x86_l_1ff7;
	case 8186ULL: goto x86_l_1ffa;
	case 8188ULL: goto x86_l_1ffc;
	case 8191ULL: goto x86_l_1fff;
	case 8197ULL: goto x86_l_2005;
	case 8200ULL: goto x86_l_2008;
	case 8206ULL: goto x86_l_200e;
	case 8209ULL: goto x86_l_2011;
	case 8215ULL: goto x86_l_2017;
	case 8222ULL: goto x86_l_201e;
	case 8227ULL: goto x86_l_2023;
	case 8230ULL: goto x86_l_2026;
	case 8232ULL: goto x86_l_2028;
	case 8235ULL: goto x86_l_202b;
	case 8241ULL: goto x86_l_2031;
	case 8244ULL: goto x86_l_2034;
	case 8250ULL: goto x86_l_203a;
	case 8257ULL: goto x86_l_2041;
	case 8262ULL: goto x86_l_2046;
	case 8265ULL: goto x86_l_2049;
	case 8267ULL: goto x86_l_204b;
	case 8270ULL: goto x86_l_204e;
	case 8276ULL: goto x86_l_2054;
	case 8279ULL: goto x86_l_2057;
	case 8285ULL: goto x86_l_205d;
	case 8292ULL: goto x86_l_2064;
	case 8297ULL: goto x86_l_2069;
	case 8300ULL: goto x86_l_206c;
	case 8306ULL: goto x86_l_2072;
	case 8309ULL: goto x86_l_2075;
	case 8315ULL: goto x86_l_207b;
	case 8322ULL: goto x86_l_2082;
	case 8327ULL: goto x86_l_2087;
	case 8330ULL: goto x86_l_208a;
	case 8332ULL: goto x86_l_208c;
	case 8335ULL: goto x86_l_208f;
	case 8341ULL: goto x86_l_2095;
	case 8348ULL: goto x86_l_209c;
	case 8350ULL: goto x86_l_209e;
	case 8353ULL: goto x86_l_20a1;
	case 8355ULL: goto x86_l_20a3;
	case 8358ULL: goto x86_l_20a6;
	case 8364ULL: goto x86_l_20ac;
	case 8371ULL: goto x86_l_20b3;
	case 8373ULL: goto x86_l_20b5;
	case 8376ULL: goto x86_l_20b8;
	case 8378ULL: goto x86_l_20ba;
	case 8381ULL: goto x86_l_20bd;
	case 8387ULL: goto x86_l_20c3;
	case 8394ULL: goto x86_l_20ca;
	case 8396ULL: goto x86_l_20cc;
	case 8403ULL: goto x86_l_20d3;
	case 8405ULL: goto x86_l_20d5;
	case 8412ULL: goto x86_l_20dc;
	case 8414ULL: goto x86_l_20de;
	case 8421ULL: goto x86_l_20e5;
	case 8423ULL: goto x86_l_20e7;
	case 8430ULL: goto x86_l_20ee;
	case 8432ULL: goto x86_l_20f0;
	case 8439ULL: goto x86_l_20f7;
	case 8441ULL: goto x86_l_20f9;
	case 8448ULL: goto x86_l_2100;
	case 8450ULL: goto x86_l_2102;
	case 8457ULL: goto x86_l_2109;
	case 8459ULL: goto x86_l_210b;
	case 8466ULL: goto x86_l_2112;
	case 8474ULL: goto x86_l_211a;
	case 8479ULL: goto x86_l_211f;
	case 8481ULL: goto x86_l_2121;
	case 8486ULL: goto x86_l_2126;
	case 8489ULL: goto x86_l_2129;
	case 8495ULL: goto x86_l_212f;
	case 8499ULL: goto x86_l_2133;
	case 8507ULL: goto x86_l_213b;
	case 8514ULL: goto x86_l_2142;
	case 8519ULL: goto x86_l_2147;
	case 8525ULL: goto x86_l_214d;
	case 8527ULL: goto x86_l_214f;
	case 8533ULL: goto x86_l_2155;
	case 8536ULL: goto x86_l_2158;
	case 8539ULL: goto x86_l_215b;
	case 8546ULL: goto x86_l_2162;
	case 8549ULL: goto x86_l_2165;
	case 8555ULL: goto x86_l_216b;
	case 8559ULL: goto x86_l_216f;
	case 8561ULL: goto x86_l_2171;
	case 8565ULL: goto x86_l_2175;
	case 8570ULL: goto x86_l_217a;
	case 8575ULL: goto x86_l_217f;
	case 8580ULL: goto x86_l_2184;
	case 8582ULL: goto x86_l_2186;
	case 8585ULL: goto x86_l_2189;
	case 8591ULL: goto x86_l_218f;
	case 8595ULL: goto x86_l_2193;
	case 8598ULL: goto x86_l_2196;
	case 8603ULL: goto x86_l_219b;
	case 8606ULL: goto x86_l_219e;
	case 8610ULL: goto x86_l_21a2;
	case 8614ULL: goto x86_l_21a6;
	case 8619ULL: goto x86_l_21ab;
	case 8622ULL: goto x86_l_21ae;
	case 8628ULL: goto x86_l_21b4;
	case 8633ULL: goto x86_l_21b9;
	case 8635ULL: goto x86_l_21bb;
	case 8637ULL: goto x86_l_21bd;
	case 8641ULL: goto x86_l_21c1;
	case 8646ULL: goto x86_l_21c6;
	case 8651ULL: goto x86_l_21cb;
	case 8656ULL: goto x86_l_21d0;
	case 8658ULL: goto x86_l_21d2;
	case 8661ULL: goto x86_l_21d5;
	case 8667ULL: goto x86_l_21db;
	case 8671ULL: goto x86_l_21df;
	case 8675ULL: goto x86_l_21e3;
	case 8680ULL: goto x86_l_21e8;
	case 8683ULL: goto x86_l_21eb;
	case 8687ULL: goto x86_l_21ef;
	case 8692ULL: goto x86_l_21f4;
	case 8695ULL: goto x86_l_21f7;
	case 8700ULL: goto x86_l_21fc;
	case 8703ULL: goto x86_l_21ff;
	case 8709ULL: goto x86_l_2205;
	case 8714ULL: goto x86_l_220a;
	case 8717ULL: goto x86_l_220d;
	case 8719ULL: goto x86_l_220f;
	case 8723ULL: goto x86_l_2213;
	case 8728ULL: goto x86_l_2218;
	case 8733ULL: goto x86_l_221d;
	case 8738ULL: goto x86_l_2222;
	case 8740ULL: goto x86_l_2224;
	case 8743ULL: goto x86_l_2227;
	case 8749ULL: goto x86_l_222d;
	case 8753ULL: goto x86_l_2231;
	case 8756ULL: goto x86_l_2234;
	case 8761ULL: goto x86_l_2239;
	case 8764ULL: goto x86_l_223c;
	case 8768ULL: goto x86_l_2240;
	case 8773ULL: goto x86_l_2245;
	case 8776ULL: goto x86_l_2248;
	case 8781ULL: goto x86_l_224d;
	case 8783ULL: goto x86_l_224f;
	case 8789ULL: goto x86_l_2255;
	case 8794ULL: goto x86_l_225a;
	case 8796ULL: goto x86_l_225c;
	case 8798ULL: goto x86_l_225e;
	case 8802ULL: goto x86_l_2262;
	case 8807ULL: goto x86_l_2267;
	case 8812ULL: goto x86_l_226c;
	case 8817ULL: goto x86_l_2271;
	case 8819ULL: goto x86_l_2273;
	case 8822ULL: goto x86_l_2276;
	case 8828ULL: goto x86_l_227c;
	case 8832ULL: goto x86_l_2280;
	case 8836ULL: goto x86_l_2284;
	case 8841ULL: goto x86_l_2289;
	case 8844ULL: goto x86_l_228c;
	case 8848ULL: goto x86_l_2290;
	case 8853ULL: goto x86_l_2295;
	case 8856ULL: goto x86_l_2298;
	case 8861ULL: goto x86_l_229d;
	case 8864ULL: goto x86_l_22a0;
	case 8870ULL: goto x86_l_22a6;
	case 8875ULL: goto x86_l_22ab;
	case 8878ULL: goto x86_l_22ae;
	case 8880ULL: goto x86_l_22b0;
	case 8884ULL: goto x86_l_22b4;
	case 8889ULL: goto x86_l_22b9;
	case 8894ULL: goto x86_l_22be;
	case 8899ULL: goto x86_l_22c3;
	case 8901ULL: goto x86_l_22c5;
	case 8904ULL: goto x86_l_22c8;
	case 8910ULL: goto x86_l_22ce;
	case 8914ULL: goto x86_l_22d2;
	case 8917ULL: goto x86_l_22d5;
	case 8922ULL: goto x86_l_22da;
	case 8925ULL: goto x86_l_22dd;
	case 8929ULL: goto x86_l_22e1;
	case 8934ULL: goto x86_l_22e6;
	case 8937ULL: goto x86_l_22e9;
	case 8942ULL: goto x86_l_22ee;
	case 8944ULL: goto x86_l_22f0;
	case 8950ULL: goto x86_l_22f6;
	case 8955ULL: goto x86_l_22fb;
	case 8957ULL: goto x86_l_22fd;
	case 8959ULL: goto x86_l_22ff;
	case 8963ULL: goto x86_l_2303;
	case 8968ULL: goto x86_l_2308;
	case 8973ULL: goto x86_l_230d;
	case 8978ULL: goto x86_l_2312;
	case 8980ULL: goto x86_l_2314;
	case 8983ULL: goto x86_l_2317;
	case 8989ULL: goto x86_l_231d;
	case 8993ULL: goto x86_l_2321;
	case 8997ULL: goto x86_l_2325;
	case 9002ULL: goto x86_l_232a;
	case 9005ULL: goto x86_l_232d;
	case 9009ULL: goto x86_l_2331;
	case 9014ULL: goto x86_l_2336;
	case 9017ULL: goto x86_l_2339;
	case 9022ULL: goto x86_l_233e;
	case 9025ULL: goto x86_l_2341;
	case 9031ULL: goto x86_l_2347;
	case 9036ULL: goto x86_l_234c;
	case 9039ULL: goto x86_l_234f;
	case 9041ULL: goto x86_l_2351;
	case 9045ULL: goto x86_l_2355;
	case 9050ULL: goto x86_l_235a;
	case 9055ULL: goto x86_l_235f;
	case 9060ULL: goto x86_l_2364;
	case 9062ULL: goto x86_l_2366;
	case 9065ULL: goto x86_l_2369;
	case 9071ULL: goto x86_l_236f;
	case 9075ULL: goto x86_l_2373;
	case 9078ULL: goto x86_l_2376;
	case 9083ULL: goto x86_l_237b;
	case 9086ULL: goto x86_l_237e;
	case 9090ULL: goto x86_l_2382;
	case 9095ULL: goto x86_l_2387;
	case 9098ULL: goto x86_l_238a;
	case 9103ULL: goto x86_l_238f;
	case 9105ULL: goto x86_l_2391;
	case 9111ULL: goto x86_l_2397;
	case 9116ULL: goto x86_l_239c;
	case 9118ULL: goto x86_l_239e;
	case 9120ULL: goto x86_l_23a0;
	case 9124ULL: goto x86_l_23a4;
	case 9129ULL: goto x86_l_23a9;
	case 9134ULL: goto x86_l_23ae;
	case 9139ULL: goto x86_l_23b3;
	case 9141ULL: goto x86_l_23b5;
	case 9144ULL: goto x86_l_23b8;
	case 9150ULL: goto x86_l_23be;
	case 9154ULL: goto x86_l_23c2;
	case 9158ULL: goto x86_l_23c6;
	case 9163ULL: goto x86_l_23cb;
	case 9166ULL: goto x86_l_23ce;
	case 9170ULL: goto x86_l_23d2;
	case 9175ULL: goto x86_l_23d7;
	case 9178ULL: goto x86_l_23da;
	case 9183ULL: goto x86_l_23df;
	case 9186ULL: goto x86_l_23e2;
	case 9192ULL: goto x86_l_23e8;
	case 9197ULL: goto x86_l_23ed;
	case 9200ULL: goto x86_l_23f0;
	case 9202ULL: goto x86_l_23f2;
	case 9206ULL: goto x86_l_23f6;
	case 9211ULL: goto x86_l_23fb;
	case 9216ULL: goto x86_l_2400;
	case 9221ULL: goto x86_l_2405;
	case 9223ULL: goto x86_l_2407;
	case 9226ULL: goto x86_l_240a;
	case 9232ULL: goto x86_l_2410;
	case 9236ULL: goto x86_l_2414;
	case 9239ULL: goto x86_l_2417;
	case 9244ULL: goto x86_l_241c;
	case 9247ULL: goto x86_l_241f;
	case 9251ULL: goto x86_l_2423;
	case 9256ULL: goto x86_l_2428;
	case 9259ULL: goto x86_l_242b;
	case 9264ULL: goto x86_l_2430;
	case 9266ULL: goto x86_l_2432;
	case 9272ULL: goto x86_l_2438;
	case 9277ULL: goto x86_l_243d;
	case 9279ULL: goto x86_l_243f;
	case 9281ULL: goto x86_l_2441;
	case 9285ULL: goto x86_l_2445;
	case 9290ULL: goto x86_l_244a;
	case 9295ULL: goto x86_l_244f;
	case 9300ULL: goto x86_l_2454;
	case 9302ULL: goto x86_l_2456;
	case 9305ULL: goto x86_l_2459;
	case 9311ULL: goto x86_l_245f;
	case 9315ULL: goto x86_l_2463;
	case 9319ULL: goto x86_l_2467;
	case 9324ULL: goto x86_l_246c;
	case 9327ULL: goto x86_l_246f;
	case 9331ULL: goto x86_l_2473;
	case 9336ULL: goto x86_l_2478;
	case 9339ULL: goto x86_l_247b;
	case 9344ULL: goto x86_l_2480;
	case 9347ULL: goto x86_l_2483;
	case 9353ULL: goto x86_l_2489;
	case 9358ULL: goto x86_l_248e;
	case 9361ULL: goto x86_l_2491;
	case 9363ULL: goto x86_l_2493;
	case 9367ULL: goto x86_l_2497;
	case 9372ULL: goto x86_l_249c;
	case 9377ULL: goto x86_l_24a1;
	case 9382ULL: goto x86_l_24a6;
	case 9384ULL: goto x86_l_24a8;
	case 9387ULL: goto x86_l_24ab;
	case 9393ULL: goto x86_l_24b1;
	case 9397ULL: goto x86_l_24b5;
	case 9400ULL: goto x86_l_24b8;
	case 9405ULL: goto x86_l_24bd;
	case 9408ULL: goto x86_l_24c0;
	case 9412ULL: goto x86_l_24c4;
	case 9417ULL: goto x86_l_24c9;
	case 9420ULL: goto x86_l_24cc;
	case 9425ULL: goto x86_l_24d1;
	case 9427ULL: goto x86_l_24d3;
	case 9433ULL: goto x86_l_24d9;
	case 9438ULL: goto x86_l_24de;
	case 9440ULL: goto x86_l_24e0;
	case 9442ULL: goto x86_l_24e2;
	case 9446ULL: goto x86_l_24e6;
	case 9451ULL: goto x86_l_24eb;
	case 9456ULL: goto x86_l_24f0;
	case 9461ULL: goto x86_l_24f5;
	case 9463ULL: goto x86_l_24f7;
	case 9466ULL: goto x86_l_24fa;
	case 9472ULL: goto x86_l_2500;
	case 9476ULL: goto x86_l_2504;
	case 9480ULL: goto x86_l_2508;
	case 9485ULL: goto x86_l_250d;
	case 9488ULL: goto x86_l_2510;
	case 9492ULL: goto x86_l_2514;
	case 9497ULL: goto x86_l_2519;
	case 9500ULL: goto x86_l_251c;
	case 9505ULL: goto x86_l_2521;
	case 9508ULL: goto x86_l_2524;
	case 9514ULL: goto x86_l_252a;
	case 9519ULL: goto x86_l_252f;
	case 9522ULL: goto x86_l_2532;
	case 9524ULL: goto x86_l_2534;
	case 9528ULL: goto x86_l_2538;
	case 9533ULL: goto x86_l_253d;
	case 9538ULL: goto x86_l_2542;
	case 9543ULL: goto x86_l_2547;
	case 9545ULL: goto x86_l_2549;
	case 9548ULL: goto x86_l_254c;
	case 9554ULL: goto x86_l_2552;
	case 9558ULL: goto x86_l_2556;
	case 9561ULL: goto x86_l_2559;
	case 9566ULL: goto x86_l_255e;
	case 9569ULL: goto x86_l_2561;
	case 9573ULL: goto x86_l_2565;
	case 9578ULL: goto x86_l_256a;
	case 9581ULL: goto x86_l_256d;
	case 9586ULL: goto x86_l_2572;
	case 9588ULL: goto x86_l_2574;
	case 9594ULL: goto x86_l_257a;
	case 9599ULL: goto x86_l_257f;
	case 9601ULL: goto x86_l_2581;
	case 9603ULL: goto x86_l_2583;
	case 9607ULL: goto x86_l_2587;
	case 9612ULL: goto x86_l_258c;
	case 9617ULL: goto x86_l_2591;
	case 9622ULL: goto x86_l_2596;
	case 9624ULL: goto x86_l_2598;
	case 9627ULL: goto x86_l_259b;
	case 9633ULL: goto x86_l_25a1;
	case 9637ULL: goto x86_l_25a5;
	case 9641ULL: goto x86_l_25a9;
	case 9646ULL: goto x86_l_25ae;
	case 9649ULL: goto x86_l_25b1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1f76:
	/* 0x1f76: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1f7b:
	/* 0x1f7b: mov    rax,0xffffffffffff0000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 18446744073709486080ULL);
x86_l_1f82:
	/* 0x1f82: and    rax,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 3864ULL);
x86_l_1f89:
	/* 0x1f89: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1f91:
	/* 0x1f91: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f96:
	/* 0x1f96: jne    2b65 <kprobe_unwind_native+0x2b65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11109ULL;
	}
x86_l_1f9c:
	/* 0x1f9c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&stack_delta_page_to_info)));
x86_l_1fa3:
	/* 0x1fa3: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1fa8:
	/* 0x1fa8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fad:
	/* 0x1fad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1faf:
	/* 0x1faf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fb2:
	/* 0x1fb2: je     56a4 <kprobe_unwind_native+0x56a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22180ULL;
	}
x86_l_1fb8:
	/* 0x1fb8: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1fbb:
	/* 0x1fbb: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1fbe:
	/* 0x1fbe: add    rbp,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_1fc2:
	/* 0x1fc2: movzx  eax,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_1fc6:
	/* 0x1fc6: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1fc9:
	/* 0x1fc9: jg     1ff7 <kprobe_unwind_native+0x1ff7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1ff7;
	}
x86_l_1fcb:
	/* 0x1fcb: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1fce:
	/* 0x1fce: jg     2023 <kprobe_unwind_native+0x2023> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2023;
	}
x86_l_1fd0:
	/* 0x1fd0: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1fd3:
	/* 0x1fd3: jg     2069 <kprobe_unwind_native+0x2069> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2069;
	}
x86_l_1fd9:
	/* 0x1fd9: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1fdc:
	/* 0x1fdc: je     20cc <kprobe_unwind_native+0x20cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20cc;
	}
x86_l_1fe2:
	/* 0x1fe2: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1fe5:
	/* 0x1fe5: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_1feb:
	/* 0x1feb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_9_stack_deltas)));
x86_l_1ff2:
	/* 0x1ff2: jmp    2112 <kprobe_unwind_native+0x2112> */
	goto x86_l_2112;
x86_l_1ff7:
	/* 0x1ff7: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_1ffa:
	/* 0x1ffa: jg     2046 <kprobe_unwind_native+0x2046> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2046;
	}
x86_l_1ffc:
	/* 0x1ffc: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1fff:
	/* 0x1fff: jg     2087 <kprobe_unwind_native+0x2087> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2087;
	}
x86_l_2005:
	/* 0x2005: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_2008:
	/* 0x2008: je     20d5 <kprobe_unwind_native+0x20d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20d5;
	}
x86_l_200e:
	/* 0x200e: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2011:
	/* 0x2011: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_2017:
	/* 0x2017: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_17_stack_deltas)));
x86_l_201e:
	/* 0x201e: jmp    2112 <kprobe_unwind_native+0x2112> */
	goto x86_l_2112;
x86_l_2023:
	/* 0x2023: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_2026:
	/* 0x2026: jg     209e <kprobe_unwind_native+0x209e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_209e;
	}
x86_l_2028:
	/* 0x2028: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_202b:
	/* 0x202b: je     20de <kprobe_unwind_native+0x20de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20de;
	}
x86_l_2031:
	/* 0x2031: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_2034:
	/* 0x2034: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_203a:
	/* 0x203a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_13_stack_deltas)));
x86_l_2041:
	/* 0x2041: jmp    2112 <kprobe_unwind_native+0x2112> */
	goto x86_l_2112;
x86_l_2046:
	/* 0x2046: cmp    eax,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_2049:
	/* 0x2049: jg     20b5 <kprobe_unwind_native+0x20b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_20b5;
	}
x86_l_204b:
	/* 0x204b: cmp    eax,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 20ULL);
x86_l_204e:
	/* 0x204e: je     20e7 <kprobe_unwind_native+0x20e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20e7;
	}
x86_l_2054:
	/* 0x2054: cmp    eax,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_2057:
	/* 0x2057: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_205d:
	/* 0x205d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_21_stack_deltas)));
x86_l_2064:
	/* 0x2064: jmp    2112 <kprobe_unwind_native+0x2112> */
	goto x86_l_2112;
x86_l_2069:
	/* 0x2069: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_206c:
	/* 0x206c: je     20f0 <kprobe_unwind_native+0x20f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20f0;
	}
x86_l_2072:
	/* 0x2072: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_2075:
	/* 0x2075: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_207b:
	/* 0x207b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_11_stack_deltas)));
x86_l_2082:
	/* 0x2082: jmp    2112 <kprobe_unwind_native+0x2112> */
	goto x86_l_2112;
x86_l_2087:
	/* 0x2087: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_208a:
	/* 0x208a: je     20f9 <kprobe_unwind_native+0x20f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20f9;
	}
x86_l_208c:
	/* 0x208c: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_208f:
	/* 0x208f: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_2095:
	/* 0x2095: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_19_stack_deltas)));
x86_l_209c:
	/* 0x209c: jmp    2112 <kprobe_unwind_native+0x2112> */
	goto x86_l_2112;
x86_l_209e:
	/* 0x209e: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_20a1:
	/* 0x20a1: je     2102 <kprobe_unwind_native+0x2102> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2102;
	}
x86_l_20a3:
	/* 0x20a3: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_20a6:
	/* 0x20a6: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_20ac:
	/* 0x20ac: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_15_stack_deltas)));
x86_l_20b3:
	/* 0x20b3: jmp    2112 <kprobe_unwind_native+0x2112> */
	goto x86_l_2112;
x86_l_20b5:
	/* 0x20b5: cmp    eax,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 22ULL);
x86_l_20b8:
	/* 0x20b8: je     210b <kprobe_unwind_native+0x210b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_210b;
	}
x86_l_20ba:
	/* 0x20ba: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_20bd:
	/* 0x20bd: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_20c3:
	/* 0x20c3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_23_stack_deltas)));
x86_l_20ca:
	/* 0x20ca: jmp    2112 <kprobe_unwind_native+0x2112> */
	goto x86_l_2112;
x86_l_20cc:
	/* 0x20cc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_8_stack_deltas)));
x86_l_20d3:
	/* 0x20d3: jmp    2112 <kprobe_unwind_native+0x2112> */
	goto x86_l_2112;
x86_l_20d5:
	/* 0x20d5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_16_stack_deltas)));
x86_l_20dc:
	/* 0x20dc: jmp    2112 <kprobe_unwind_native+0x2112> */
	goto x86_l_2112;
x86_l_20de:
	/* 0x20de: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_12_stack_deltas)));
x86_l_20e5:
	/* 0x20e5: jmp    2112 <kprobe_unwind_native+0x2112> */
	goto x86_l_2112;
x86_l_20e7:
	/* 0x20e7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_20_stack_deltas)));
x86_l_20ee:
	/* 0x20ee: jmp    2112 <kprobe_unwind_native+0x2112> */
	goto x86_l_2112;
x86_l_20f0:
	/* 0x20f0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_10_stack_deltas)));
x86_l_20f7:
	/* 0x20f7: jmp    2112 <kprobe_unwind_native+0x2112> */
	goto x86_l_2112;
x86_l_20f9:
	/* 0x20f9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_18_stack_deltas)));
x86_l_2100:
	/* 0x2100: jmp    2112 <kprobe_unwind_native+0x2112> */
	goto x86_l_2112;
x86_l_2102:
	/* 0x2102: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_14_stack_deltas)));
x86_l_2109:
	/* 0x2109: jmp    2112 <kprobe_unwind_native+0x2112> */
	goto x86_l_2112;
x86_l_210b:
	/* 0x210b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_22_stack_deltas)));
x86_l_2112:
	/* 0x2112: lea    rsi,[rsp+0x160] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_211a:
	/* 0x211a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_211f:
	/* 0x211f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2121:
	/* 0x2121: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2126:
	/* 0x2126: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2129:
	/* 0x2129: je     5f2b <kprobe_unwind_native+0x5f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24363ULL;
	}
x86_l_212f:
	/* 0x212f: mov    r13d,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2133:
	/* 0x2133: mov    DWORD PTR [rsp+0x90],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_213b:
	/* 0x213b: mov    rax,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_2142:
	/* 0x2142: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2147:
	/* 0x2147: movzx  eax,WORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_214d:
	/* 0x214d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_214f:
	/* 0x214f: je     2675 <kprobe_unwind_native+0x2675> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9845ULL;
	}
x86_l_2155:
	/* 0x2155: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2158:
	/* 0x2158: add    r15d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_215b:
	/* 0x215b: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_2162:
	/* 0x2162: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2165:
	/* 0x2165: jne    2c6e <kprobe_unwind_native+0x2c6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11374ULL;
	}
x86_l_216b:
	/* 0x216b: lea    eax,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_216f:
	/* 0x216f: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_2171:
	/* 0x2171: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2175:
	/* 0x2175: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_217a:
	/* 0x217a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_217f:
	/* 0x217f: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2184:
	/* 0x2184: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2186:
	/* 0x2186: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2189:
	/* 0x2189: je     2719 <kprobe_unwind_native+0x2719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10009ULL;
	}
x86_l_218f:
	/* 0x218f: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2193:
	/* 0x2193: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2196:
	/* 0x2196: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_219b:
	/* 0x219b: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_219e:
	/* 0x219e: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_21a2:
	/* 0x21a2: cmova  r15d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_21a6:
	/* 0x21a6: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21ab:
	/* 0x21ab: cmp    ebp,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R15, X86_WIDTH_32);
x86_l_21ae:
	/* 0x21ae: jae    2665 <kprobe_unwind_native+0x2665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9829ULL;
	}
x86_l_21b4:
	/* 0x21b4: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21b9:
	/* 0x21b9: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_21bb:
	/* 0x21bb: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_21bd:
	/* 0x21bd: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21c1:
	/* 0x21c1: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21c6:
	/* 0x21c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21cb:
	/* 0x21cb: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_21d0:
	/* 0x21d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21d2:
	/* 0x21d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21d5:
	/* 0x21d5: je     2719 <kprobe_unwind_native+0x2719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10009ULL;
	}
x86_l_21db:
	/* 0x21db: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21df:
	/* 0x21df: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_21e3:
	/* 0x21e3: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_21e8:
	/* 0x21e8: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21eb:
	/* 0x21eb: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_21ef:
	/* 0x21ef: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21f4:
	/* 0x21f4: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_21f7:
	/* 0x21f7: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21fc:
	/* 0x21fc: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_21ff:
	/* 0x21ff: jae    2665 <kprobe_unwind_native+0x2665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9829ULL;
	}
x86_l_2205:
	/* 0x2205: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_220a:
	/* 0x220a: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_220d:
	/* 0x220d: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_220f:
	/* 0x220f: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2213:
	/* 0x2213: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2218:
	/* 0x2218: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_221d:
	/* 0x221d: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2222:
	/* 0x2222: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2224:
	/* 0x2224: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2227:
	/* 0x2227: je     2719 <kprobe_unwind_native+0x2719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10009ULL;
	}
x86_l_222d:
	/* 0x222d: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2231:
	/* 0x2231: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2234:
	/* 0x2234: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2239:
	/* 0x2239: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_223c:
	/* 0x223c: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_2240:
	/* 0x2240: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2245:
	/* 0x2245: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_2248:
	/* 0x2248: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_224d:
	/* 0x224d: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_224f:
	/* 0x224f: jae    2665 <kprobe_unwind_native+0x2665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9829ULL;
	}
x86_l_2255:
	/* 0x2255: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_225a:
	/* 0x225a: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_225c:
	/* 0x225c: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_225e:
	/* 0x225e: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2262:
	/* 0x2262: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2267:
	/* 0x2267: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_226c:
	/* 0x226c: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2271:
	/* 0x2271: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2273:
	/* 0x2273: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2276:
	/* 0x2276: je     2719 <kprobe_unwind_native+0x2719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10009ULL;
	}
x86_l_227c:
	/* 0x227c: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2280:
	/* 0x2280: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2284:
	/* 0x2284: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2289:
	/* 0x2289: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_228c:
	/* 0x228c: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_2290:
	/* 0x2290: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2295:
	/* 0x2295: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_2298:
	/* 0x2298: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_229d:
	/* 0x229d: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_22a0:
	/* 0x22a0: jae    2665 <kprobe_unwind_native+0x2665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9829ULL;
	}
x86_l_22a6:
	/* 0x22a6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22ab:
	/* 0x22ab: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_22ae:
	/* 0x22ae: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_22b0:
	/* 0x22b0: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22b4:
	/* 0x22b4: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22b9:
	/* 0x22b9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22be:
	/* 0x22be: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_22c3:
	/* 0x22c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22c5:
	/* 0x22c5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22c8:
	/* 0x22c8: je     2719 <kprobe_unwind_native+0x2719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10009ULL;
	}
x86_l_22ce:
	/* 0x22ce: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22d2:
	/* 0x22d2: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_22d5:
	/* 0x22d5: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_22da:
	/* 0x22da: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22dd:
	/* 0x22dd: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_22e1:
	/* 0x22e1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22e6:
	/* 0x22e6: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_22e9:
	/* 0x22e9: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22ee:
	/* 0x22ee: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_22f0:
	/* 0x22f0: jae    2665 <kprobe_unwind_native+0x2665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9829ULL;
	}
x86_l_22f6:
	/* 0x22f6: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22fb:
	/* 0x22fb: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_22fd:
	/* 0x22fd: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_22ff:
	/* 0x22ff: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2303:
	/* 0x2303: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2308:
	/* 0x2308: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_230d:
	/* 0x230d: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2312:
	/* 0x2312: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2314:
	/* 0x2314: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2317:
	/* 0x2317: je     2719 <kprobe_unwind_native+0x2719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10009ULL;
	}
x86_l_231d:
	/* 0x231d: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2321:
	/* 0x2321: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2325:
	/* 0x2325: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_232a:
	/* 0x232a: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_232d:
	/* 0x232d: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_2331:
	/* 0x2331: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2336:
	/* 0x2336: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_2339:
	/* 0x2339: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_233e:
	/* 0x233e: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_2341:
	/* 0x2341: jae    2665 <kprobe_unwind_native+0x2665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9829ULL;
	}
x86_l_2347:
	/* 0x2347: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_234c:
	/* 0x234c: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_234f:
	/* 0x234f: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_2351:
	/* 0x2351: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2355:
	/* 0x2355: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_235a:
	/* 0x235a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_235f:
	/* 0x235f: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2364:
	/* 0x2364: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2366:
	/* 0x2366: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2369:
	/* 0x2369: je     2719 <kprobe_unwind_native+0x2719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10009ULL;
	}
x86_l_236f:
	/* 0x236f: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2373:
	/* 0x2373: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2376:
	/* 0x2376: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_237b:
	/* 0x237b: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_237e:
	/* 0x237e: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_2382:
	/* 0x2382: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2387:
	/* 0x2387: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_238a:
	/* 0x238a: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_238f:
	/* 0x238f: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_2391:
	/* 0x2391: jae    2665 <kprobe_unwind_native+0x2665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9829ULL;
	}
x86_l_2397:
	/* 0x2397: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_239c:
	/* 0x239c: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_239e:
	/* 0x239e: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_23a0:
	/* 0x23a0: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23a4:
	/* 0x23a4: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23a9:
	/* 0x23a9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23ae:
	/* 0x23ae: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_23b3:
	/* 0x23b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23b5:
	/* 0x23b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23b8:
	/* 0x23b8: je     2719 <kprobe_unwind_native+0x2719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10009ULL;
	}
x86_l_23be:
	/* 0x23be: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23c2:
	/* 0x23c2: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_23c6:
	/* 0x23c6: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_23cb:
	/* 0x23cb: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23ce:
	/* 0x23ce: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_23d2:
	/* 0x23d2: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23d7:
	/* 0x23d7: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_23da:
	/* 0x23da: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23df:
	/* 0x23df: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_23e2:
	/* 0x23e2: jae    2665 <kprobe_unwind_native+0x2665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9829ULL;
	}
x86_l_23e8:
	/* 0x23e8: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23ed:
	/* 0x23ed: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_23f0:
	/* 0x23f0: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_23f2:
	/* 0x23f2: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23f6:
	/* 0x23f6: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23fb:
	/* 0x23fb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2400:
	/* 0x2400: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2405:
	/* 0x2405: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2407:
	/* 0x2407: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_240a:
	/* 0x240a: je     2719 <kprobe_unwind_native+0x2719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10009ULL;
	}
x86_l_2410:
	/* 0x2410: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2414:
	/* 0x2414: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2417:
	/* 0x2417: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_241c:
	/* 0x241c: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_241f:
	/* 0x241f: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_2423:
	/* 0x2423: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2428:
	/* 0x2428: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_242b:
	/* 0x242b: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2430:
	/* 0x2430: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_2432:
	/* 0x2432: jae    2665 <kprobe_unwind_native+0x2665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9829ULL;
	}
x86_l_2438:
	/* 0x2438: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_243d:
	/* 0x243d: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_243f:
	/* 0x243f: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_2441:
	/* 0x2441: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2445:
	/* 0x2445: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_244a:
	/* 0x244a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_244f:
	/* 0x244f: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2454:
	/* 0x2454: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2456:
	/* 0x2456: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2459:
	/* 0x2459: je     2719 <kprobe_unwind_native+0x2719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10009ULL;
	}
x86_l_245f:
	/* 0x245f: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2463:
	/* 0x2463: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2467:
	/* 0x2467: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_246c:
	/* 0x246c: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_246f:
	/* 0x246f: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_2473:
	/* 0x2473: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2478:
	/* 0x2478: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_247b:
	/* 0x247b: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2480:
	/* 0x2480: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_2483:
	/* 0x2483: jae    2665 <kprobe_unwind_native+0x2665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9829ULL;
	}
x86_l_2489:
	/* 0x2489: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_248e:
	/* 0x248e: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2491:
	/* 0x2491: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_2493:
	/* 0x2493: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2497:
	/* 0x2497: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_249c:
	/* 0x249c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24a1:
	/* 0x24a1: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_24a6:
	/* 0x24a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24a8:
	/* 0x24a8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24ab:
	/* 0x24ab: je     2719 <kprobe_unwind_native+0x2719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10009ULL;
	}
x86_l_24b1:
	/* 0x24b1: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24b5:
	/* 0x24b5: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_24b8:
	/* 0x24b8: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_24bd:
	/* 0x24bd: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24c0:
	/* 0x24c0: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_24c4:
	/* 0x24c4: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24c9:
	/* 0x24c9: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_24cc:
	/* 0x24cc: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24d1:
	/* 0x24d1: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_24d3:
	/* 0x24d3: jae    2665 <kprobe_unwind_native+0x2665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9829ULL;
	}
x86_l_24d9:
	/* 0x24d9: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24de:
	/* 0x24de: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_24e0:
	/* 0x24e0: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_24e2:
	/* 0x24e2: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24e6:
	/* 0x24e6: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24eb:
	/* 0x24eb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24f0:
	/* 0x24f0: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_24f5:
	/* 0x24f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24f7:
	/* 0x24f7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24fa:
	/* 0x24fa: je     2719 <kprobe_unwind_native+0x2719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10009ULL;
	}
x86_l_2500:
	/* 0x2500: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2504:
	/* 0x2504: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2508:
	/* 0x2508: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_250d:
	/* 0x250d: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2510:
	/* 0x2510: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_2514:
	/* 0x2514: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2519:
	/* 0x2519: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_251c:
	/* 0x251c: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2521:
	/* 0x2521: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_2524:
	/* 0x2524: jae    2665 <kprobe_unwind_native+0x2665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9829ULL;
	}
x86_l_252a:
	/* 0x252a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_252f:
	/* 0x252f: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2532:
	/* 0x2532: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_2534:
	/* 0x2534: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2538:
	/* 0x2538: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_253d:
	/* 0x253d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2542:
	/* 0x2542: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2547:
	/* 0x2547: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2549:
	/* 0x2549: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_254c:
	/* 0x254c: je     2719 <kprobe_unwind_native+0x2719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10009ULL;
	}
x86_l_2552:
	/* 0x2552: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2556:
	/* 0x2556: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2559:
	/* 0x2559: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_255e:
	/* 0x255e: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2561:
	/* 0x2561: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_2565:
	/* 0x2565: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_256a:
	/* 0x256a: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_256d:
	/* 0x256d: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2572:
	/* 0x2572: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_2574:
	/* 0x2574: jae    2665 <kprobe_unwind_native+0x2665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9829ULL;
	}
x86_l_257a:
	/* 0x257a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_257f:
	/* 0x257f: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2581:
	/* 0x2581: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_2583:
	/* 0x2583: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2587:
	/* 0x2587: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_258c:
	/* 0x258c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2591:
	/* 0x2591: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2596:
	/* 0x2596: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2598:
	/* 0x2598: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_259b:
	/* 0x259b: je     2719 <kprobe_unwind_native+0x2719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10009ULL;
	}
x86_l_25a1:
	/* 0x25a1: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25a5:
	/* 0x25a5: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_25a9:
	/* 0x25a9: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_25ae:
	/* 0x25ae: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25b1:
	/* 0x25b1: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
	return 9653ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9653ULL: goto x86_l_25b5;
	case 9658ULL: goto x86_l_25ba;
	case 9661ULL: goto x86_l_25bd;
	case 9666ULL: goto x86_l_25c2;
	case 9669ULL: goto x86_l_25c5;
	case 9675ULL: goto x86_l_25cb;
	case 9680ULL: goto x86_l_25d0;
	case 9683ULL: goto x86_l_25d3;
	case 9685ULL: goto x86_l_25d5;
	case 9689ULL: goto x86_l_25d9;
	case 9694ULL: goto x86_l_25de;
	case 9699ULL: goto x86_l_25e3;
	case 9704ULL: goto x86_l_25e8;
	case 9706ULL: goto x86_l_25ea;
	case 9709ULL: goto x86_l_25ed;
	case 9715ULL: goto x86_l_25f3;
	case 9719ULL: goto x86_l_25f7;
	case 9722ULL: goto x86_l_25fa;
	case 9727ULL: goto x86_l_25ff;
	case 9730ULL: goto x86_l_2602;
	case 9734ULL: goto x86_l_2606;
	case 9739ULL: goto x86_l_260b;
	case 9742ULL: goto x86_l_260e;
	case 9747ULL: goto x86_l_2613;
	case 9749ULL: goto x86_l_2615;
	case 9751ULL: goto x86_l_2617;
	case 9756ULL: goto x86_l_261c;
	case 9758ULL: goto x86_l_261e;
	case 9760ULL: goto x86_l_2620;
	case 9764ULL: goto x86_l_2624;
	case 9769ULL: goto x86_l_2629;
	case 9774ULL: goto x86_l_262e;
	case 9779ULL: goto x86_l_2633;
	case 9781ULL: goto x86_l_2635;
	case 9784ULL: goto x86_l_2638;
	case 9790ULL: goto x86_l_263e;
	case 9794ULL: goto x86_l_2642;
	case 9797ULL: goto x86_l_2645;
	case 9802ULL: goto x86_l_264a;
	case 9805ULL: goto x86_l_264d;
	case 9808ULL: goto x86_l_2650;
	case 9813ULL: goto x86_l_2655;
	case 9816ULL: goto x86_l_2658;
	case 9821ULL: goto x86_l_265d;
	case 9823ULL: goto x86_l_265f;
	case 9829ULL: goto x86_l_2665;
	case 9834ULL: goto x86_l_266a;
	case 9837ULL: goto x86_l_266d;
	case 9839ULL: goto x86_l_266f;
	case 9845ULL: goto x86_l_2675;
	case 9848ULL: goto x86_l_2678;
	case 9856ULL: goto x86_l_2680;
	case 9864ULL: goto x86_l_2688;
	case 9869ULL: goto x86_l_268d;
	case 9874ULL: goto x86_l_2692;
	case 9876ULL: goto x86_l_2694;
	case 9879ULL: goto x86_l_2697;
	case 9885ULL: goto x86_l_269d;
	case 9888ULL: goto x86_l_26a0;
	case 9895ULL: goto x86_l_26a7;
	case 9898ULL: goto x86_l_26aa;
	case 9904ULL: goto x86_l_26b0;
	case 9909ULL: goto x86_l_26b5;
	case 9913ULL: goto x86_l_26b9;
	case 9915ULL: goto x86_l_26bb;
	case 9922ULL: goto x86_l_26c2;
	case 9926ULL: goto x86_l_26c6;
	case 9933ULL: goto x86_l_26cd;
	case 9937ULL: goto x86_l_26d1;
	case 9941ULL: goto x86_l_26d5;
	case 9948ULL: goto x86_l_26dc;
	case 9953ULL: goto x86_l_26e1;
	case 9959ULL: goto x86_l_26e7;
	case 9964ULL: goto x86_l_26ec;
	case 9966ULL: goto x86_l_26ee;
	case 9977ULL: goto x86_l_26f9;
	case 9984ULL: goto x86_l_2700;
	case 9992ULL: goto x86_l_2708;
	case 9997ULL: goto x86_l_270d;
	case 9999ULL: goto x86_l_270f;
	case 10002ULL: goto x86_l_2712;
	case 10004ULL: goto x86_l_2714;
	case 10007ULL: goto x86_l_2717;
	case 10009ULL: goto x86_l_2719;
	case 10016ULL: goto x86_l_2720;
	case 10019ULL: goto x86_l_2723;
	case 10025ULL: goto x86_l_2729;
	case 10030ULL: goto x86_l_272e;
	case 10035ULL: goto x86_l_2733;
	case 10040ULL: goto x86_l_2738;
	case 10047ULL: goto x86_l_273f;
	case 10050ULL: goto x86_l_2742;
	case 10056ULL: goto x86_l_2748;
	case 10063ULL: goto x86_l_274f;
	case 10066ULL: goto x86_l_2752;
	case 10072ULL: goto x86_l_2758;
	case 10079ULL: goto x86_l_275f;
	case 10087ULL: goto x86_l_2767;
	case 10092ULL: goto x86_l_276c;
	case 10094ULL: goto x86_l_276e;
	case 10099ULL: goto x86_l_2773;
	case 10102ULL: goto x86_l_2776;
	case 10110ULL: goto x86_l_277e;
	case 10116ULL: goto x86_l_2784;
	case 10121ULL: goto x86_l_2789;
	case 10124ULL: goto x86_l_278c;
	case 10128ULL: goto x86_l_2790;
	case 10130ULL: goto x86_l_2792;
	case 10132ULL: goto x86_l_2794;
	case 10139ULL: goto x86_l_279b;
	case 10142ULL: goto x86_l_279e;
	case 10148ULL: goto x86_l_27a4;
	case 10150ULL: goto x86_l_27a6;
	case 10153ULL: goto x86_l_27a9;
	case 10156ULL: goto x86_l_27ac;
	case 10159ULL: goto x86_l_27af;
	case 10161ULL: goto x86_l_27b1;
	case 10163ULL: goto x86_l_27b3;
	case 10165ULL: goto x86_l_27b5;
	case 10168ULL: goto x86_l_27b8;
	case 10171ULL: goto x86_l_27bb;
	case 10173ULL: goto x86_l_27bd;
	case 10176ULL: goto x86_l_27c0;
	case 10183ULL: goto x86_l_27c7;
	case 10186ULL: goto x86_l_27ca;
	case 10192ULL: goto x86_l_27d0;
	case 10197ULL: goto x86_l_27d5;
	case 10200ULL: goto x86_l_27d8;
	case 10202ULL: goto x86_l_27da;
	case 10205ULL: goto x86_l_27dd;
	case 10207ULL: goto x86_l_27df;
	case 10210ULL: goto x86_l_27e2;
	case 10212ULL: goto x86_l_27e4;
	case 10215ULL: goto x86_l_27e7;
	case 10218ULL: goto x86_l_27ea;
	case 10221ULL: goto x86_l_27ed;
	case 10227ULL: goto x86_l_27f3;
	case 10230ULL: goto x86_l_27f6;
	case 10236ULL: goto x86_l_27fc;
	case 10239ULL: goto x86_l_27ff;
	case 10242ULL: goto x86_l_2802;
	case 10248ULL: goto x86_l_2808;
	case 10253ULL: goto x86_l_280d;
	case 10258ULL: goto x86_l_2812;
	case 10264ULL: goto x86_l_2818;
	case 10267ULL: goto x86_l_281b;
	case 10273ULL: goto x86_l_2821;
	case 10276ULL: goto x86_l_2824;
	case 10281ULL: goto x86_l_2829;
	case 10289ULL: goto x86_l_2831;
	case 10297ULL: goto x86_l_2839;
	case 10303ULL: goto x86_l_283f;
	case 10306ULL: goto x86_l_2842;
	case 10312ULL: goto x86_l_2848;
	case 10315ULL: goto x86_l_284b;
	case 10318ULL: goto x86_l_284e;
	case 10320ULL: goto x86_l_2850;
	case 10323ULL: goto x86_l_2853;
	case 10325ULL: goto x86_l_2855;
	case 10328ULL: goto x86_l_2858;
	case 10331ULL: goto x86_l_285b;
	case 10335ULL: goto x86_l_285f;
	case 10339ULL: goto x86_l_2863;
	case 10346ULL: goto x86_l_286a;
	case 10349ULL: goto x86_l_286d;
	case 10355ULL: goto x86_l_2873;
	case 10365ULL: goto x86_l_287d;
	case 10370ULL: goto x86_l_2882;
	case 10380ULL: goto x86_l_288c;
	case 10385ULL: goto x86_l_2891;
	case 10390ULL: goto x86_l_2896;
	case 10395ULL: goto x86_l_289b;
	case 10400ULL: goto x86_l_28a0;
	case 10405ULL: goto x86_l_28a5;
	case 10408ULL: goto x86_l_28a8;
	case 10410ULL: goto x86_l_28aa;
	case 10412ULL: goto x86_l_28ac;
	case 10417ULL: goto x86_l_28b1;
	case 10420ULL: goto x86_l_28b4;
	case 10426ULL: goto x86_l_28ba;
	case 10429ULL: goto x86_l_28bd;
	case 10434ULL: goto x86_l_28c2;
	case 10439ULL: goto x86_l_28c7;
	case 10447ULL: goto x86_l_28cf;
	case 10453ULL: goto x86_l_28d5;
	case 10456ULL: goto x86_l_28d8;
	case 10461ULL: goto x86_l_28dd;
	case 10466ULL: goto x86_l_28e2;
	case 10472ULL: goto x86_l_28e8;
	case 10475ULL: goto x86_l_28eb;
	case 10480ULL: goto x86_l_28f0;
	case 10483ULL: goto x86_l_28f3;
	case 10486ULL: goto x86_l_28f6;
	case 10492ULL: goto x86_l_28fc;
	case 10499ULL: goto x86_l_2903;
	case 10503ULL: goto x86_l_2907;
	case 10510ULL: goto x86_l_290e;
	case 10515ULL: goto x86_l_2913;
	case 10522ULL: goto x86_l_291a;
	case 10527ULL: goto x86_l_291f;
	case 10534ULL: goto x86_l_2926;
	case 10539ULL: goto x86_l_292b;
	case 10542ULL: goto x86_l_292e;
	case 10548ULL: goto x86_l_2934;
	case 10551ULL: goto x86_l_2937;
	case 10557ULL: goto x86_l_293d;
	case 10559ULL: goto x86_l_293f;
	case 10561ULL: goto x86_l_2941;
	case 10564ULL: goto x86_l_2944;
	case 10566ULL: goto x86_l_2946;
	case 10571ULL: goto x86_l_294b;
	case 10578ULL: goto x86_l_2952;
	case 10581ULL: goto x86_l_2955;
	case 10587ULL: goto x86_l_295b;
	case 10590ULL: goto x86_l_295e;
	case 10593ULL: goto x86_l_2961;
	case 10596ULL: goto x86_l_2964;
	case 10602ULL: goto x86_l_296a;
	case 10610ULL: goto x86_l_2972;
	case 10612ULL: goto x86_l_2974;
	case 10618ULL: goto x86_l_297a;
	case 10621ULL: goto x86_l_297d;
	case 10627ULL: goto x86_l_2983;
	case 10635ULL: goto x86_l_298b;
	case 10640ULL: goto x86_l_2990;
	case 10648ULL: goto x86_l_2998;
	case 10651ULL: goto x86_l_299b;
	case 10655ULL: goto x86_l_299f;
	case 10663ULL: goto x86_l_29a7;
	case 10668ULL: goto x86_l_29ac;
	case 10674ULL: goto x86_l_29b2;
	case 10677ULL: goto x86_l_29b5;
	case 10680ULL: goto x86_l_29b8;
	case 10684ULL: goto x86_l_29bc;
	case 10689ULL: goto x86_l_29c1;
	case 10692ULL: goto x86_l_29c4;
	case 10695ULL: goto x86_l_29c7;
	case 10700ULL: goto x86_l_29cc;
	case 10706ULL: goto x86_l_29d2;
	case 10714ULL: goto x86_l_29da;
	case 10721ULL: goto x86_l_29e1;
	case 10729ULL: goto x86_l_29e9;
	case 10736ULL: goto x86_l_29f0;
	case 10744ULL: goto x86_l_29f8;
	case 10751ULL: goto x86_l_29ff;
	case 10759ULL: goto x86_l_2a07;
	case 10766ULL: goto x86_l_2a0e;
	case 10774ULL: goto x86_l_2a16;
	case 10781ULL: goto x86_l_2a1d;
	case 10789ULL: goto x86_l_2a25;
	case 10796ULL: goto x86_l_2a2c;
	case 10804ULL: goto x86_l_2a34;
	case 10811ULL: goto x86_l_2a3b;
	case 10819ULL: goto x86_l_2a43;
	case 10826ULL: goto x86_l_2a4a;
	case 10833ULL: goto x86_l_2a51;
	case 10840ULL: goto x86_l_2a58;
	case 10843ULL: goto x86_l_2a5b;
	case 10849ULL: goto x86_l_2a61;
	case 10859ULL: goto x86_l_2a6b;
	case 10864ULL: goto x86_l_2a70;
	case 10874ULL: goto x86_l_2a7a;
	case 10879ULL: goto x86_l_2a7f;
	case 10884ULL: goto x86_l_2a84;
	case 10889ULL: goto x86_l_2a89;
	case 10894ULL: goto x86_l_2a8e;
	case 10899ULL: goto x86_l_2a93;
	case 10901ULL: goto x86_l_2a95;
	case 10903ULL: goto x86_l_2a97;
	case 10908ULL: goto x86_l_2a9c;
	case 10913ULL: goto x86_l_2aa1;
	case 10916ULL: goto x86_l_2aa4;
	case 10919ULL: goto x86_l_2aa7;
	case 10922ULL: goto x86_l_2aaa;
	case 10925ULL: goto x86_l_2aad;
	case 10927ULL: goto x86_l_2aaf;
	case 10933ULL: goto x86_l_2ab5;
	case 10938ULL: goto x86_l_2aba;
	case 10943ULL: goto x86_l_2abf;
	case 10948ULL: goto x86_l_2ac4;
	case 10953ULL: goto x86_l_2ac9;
	case 10956ULL: goto x86_l_2acc;
	case 10958ULL: goto x86_l_2ace;
	case 10961ULL: goto x86_l_2ad1;
	case 10963ULL: goto x86_l_2ad3;
	case 10970ULL: goto x86_l_2ada;
	case 10973ULL: goto x86_l_2add;
	case 10979ULL: goto x86_l_2ae3;
	case 10982ULL: goto x86_l_2ae6;
	case 10987ULL: goto x86_l_2aeb;
	case 10990ULL: goto x86_l_2aee;
	case 10993ULL: goto x86_l_2af1;
	case 10998ULL: goto x86_l_2af6;
	case 11001ULL: goto x86_l_2af9;
	case 11006ULL: goto x86_l_2afe;
	case 11012ULL: goto x86_l_2b04;
	case 11022ULL: goto x86_l_2b0e;
	case 11030ULL: goto x86_l_2b16;
	case 11040ULL: goto x86_l_2b20;
	case 11048ULL: goto x86_l_2b28;
	case 11058ULL: goto x86_l_2b32;
	case 11066ULL: goto x86_l_2b3a;
	case 11077ULL: goto x86_l_2b45;
	case 11085ULL: goto x86_l_2b4d;
	case 11090ULL: goto x86_l_2b52;
	case 11095ULL: goto x86_l_2b57;
	case 11100ULL: goto x86_l_2b5c;
	case 11102ULL: goto x86_l_2b5e;
	case 11104ULL: goto x86_l_2b60;
	case 11109ULL: goto x86_l_2b65;
	case 11119ULL: goto x86_l_2b6f;
	case 11124ULL: goto x86_l_2b74;
	case 11134ULL: goto x86_l_2b7e;
	case 11139ULL: goto x86_l_2b83;
	case 11149ULL: goto x86_l_2b8d;
	case 11154ULL: goto x86_l_2b92;
	case 11164ULL: goto x86_l_2b9c;
	case 11169ULL: goto x86_l_2ba1;
	case 11174ULL: goto x86_l_2ba6;
	case 11179ULL: goto x86_l_2bab;
	case 11184ULL: goto x86_l_2bb0;
	case 11190ULL: goto x86_l_2bb6;
	case 11197ULL: goto x86_l_2bbd;
	case 11204ULL: goto x86_l_2bc4;
	case 11209ULL: goto x86_l_2bc9;
	case 11211ULL: goto x86_l_2bcb;
	case 11214ULL: goto x86_l_2bce;
	case 11219ULL: goto x86_l_2bd3;
	case 11229ULL: goto x86_l_2bdd;
	case 11237ULL: goto x86_l_2be5;
	case 11247ULL: goto x86_l_2bef;
	case 11255ULL: goto x86_l_2bf7;
	case 11265ULL: goto x86_l_2c01;
	case 11273ULL: goto x86_l_2c09;
	case 11283ULL: goto x86_l_2c13;
	case 11291ULL: goto x86_l_2c1b;
	case 11301ULL: goto x86_l_2c25;
	case 11309ULL: goto x86_l_2c2d;
	case 11319ULL: goto x86_l_2c37;
	case 11327ULL: goto x86_l_2c3f;
	case 11335ULL: goto x86_l_2c47;
	case 11340ULL: goto x86_l_2c4c;
	case 11345ULL: goto x86_l_2c51;
	case 11349ULL: goto x86_l_2c55;
	case 11354ULL: goto x86_l_2c5a;
	case 11356ULL: goto x86_l_2c5c;
	case 11358ULL: goto x86_l_2c5e;
	case 11363ULL: goto x86_l_2c63;
	case 11369ULL: goto x86_l_2c69;
	case 11374ULL: goto x86_l_2c6e;
	case 11384ULL: goto x86_l_2c78;
	case 11389ULL: goto x86_l_2c7d;
	case 11399ULL: goto x86_l_2c87;
	case 11404ULL: goto x86_l_2c8c;
	case 11414ULL: goto x86_l_2c96;
	case 11419ULL: goto x86_l_2c9b;
	case 11429ULL: goto x86_l_2ca5;
	case 11434ULL: goto x86_l_2caa;
	case 11444ULL: goto x86_l_2cb4;
	case 11449ULL: goto x86_l_2cb9;
	case 11459ULL: goto x86_l_2cc3;
	case 11464ULL: goto x86_l_2cc8;
	case 11469ULL: goto x86_l_2ccd;
	case 11474ULL: goto x86_l_2cd2;
	case 11480ULL: goto x86_l_2cd8;
	case 11483ULL: goto x86_l_2cdb;
	case 11488ULL: goto x86_l_2ce0;
	case 11493ULL: goto x86_l_2ce5;
	case 11496ULL: goto x86_l_2ce8;
	case 11498ULL: goto x86_l_2cea;
	case 11501ULL: goto x86_l_2ced;
	case 11506ULL: goto x86_l_2cf2;
	case 11516ULL: goto x86_l_2cfc;
	case 11521ULL: goto x86_l_2d01;
	case 11531ULL: goto x86_l_2d0b;
	case 11536ULL: goto x86_l_2d10;
	case 11546ULL: goto x86_l_2d1a;
	case 11551ULL: goto x86_l_2d1f;
	case 11561ULL: goto x86_l_2d29;
	case 11566ULL: goto x86_l_2d2e;
	case 11576ULL: goto x86_l_2d38;
	case 11581ULL: goto x86_l_2d3d;
	case 11589ULL: goto x86_l_2d45;
	case 11594ULL: goto x86_l_2d4a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_25b5:
	/* 0x25b5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25ba:
	/* 0x25ba: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_25bd:
	/* 0x25bd: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25c2:
	/* 0x25c2: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_25c5:
	/* 0x25c5: jae    2665 <kprobe_unwind_native+0x2665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2665;
	}
x86_l_25cb:
	/* 0x25cb: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25d0:
	/* 0x25d0: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_25d3:
	/* 0x25d3: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_25d5:
	/* 0x25d5: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25d9:
	/* 0x25d9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25de:
	/* 0x25de: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_25e3:
	/* 0x25e3: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_25e8:
	/* 0x25e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25ea:
	/* 0x25ea: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25ed:
	/* 0x25ed: je     2719 <kprobe_unwind_native+0x2719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2719;
	}
x86_l_25f3:
	/* 0x25f3: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25f7:
	/* 0x25f7: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_25fa:
	/* 0x25fa: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_25ff:
	/* 0x25ff: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2602:
	/* 0x2602: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_2606:
	/* 0x2606: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_260b:
	/* 0x260b: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_260e:
	/* 0x260e: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2613:
	/* 0x2613: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_2615:
	/* 0x2615: jae    2665 <kprobe_unwind_native+0x2665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2665;
	}
x86_l_2617:
	/* 0x2617: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_261c:
	/* 0x261c: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_261e:
	/* 0x261e: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_2620:
	/* 0x2620: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2624:
	/* 0x2624: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2629:
	/* 0x2629: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_262e:
	/* 0x262e: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2633:
	/* 0x2633: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2635:
	/* 0x2635: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2638:
	/* 0x2638: je     2719 <kprobe_unwind_native+0x2719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2719;
	}
x86_l_263e:
	/* 0x263e: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2642:
	/* 0x2642: lea    edx,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2645:
	/* 0x2645: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_264a:
	/* 0x264a: cmp    WORD PTR [rax],si */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_264d:
	/* 0x264d: cmova  edx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_2650:
	/* 0x2650: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2655:
	/* 0x2655: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_2658:
	/* 0x2658: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_265d:
	/* 0x265d: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_265f:
	/* 0x265f: jb     2719 <kprobe_unwind_native+0x2719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2719;
	}
x86_l_2665:
	/* 0x2665: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_266a:
	/* 0x266a: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_266d:
	/* 0x266d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_266f:
	/* 0x266f: je     2719 <kprobe_unwind_native+0x2719> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2719;
	}
x86_l_2675:
	/* 0x2675: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2678:
	/* 0x2678: mov    DWORD PTR [rsp+0x90],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2680:
	/* 0x2680: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2688:
	/* 0x2688: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_268d:
	/* 0x268d: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2692:
	/* 0x2692: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2694:
	/* 0x2694: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2697:
	/* 0x2697: je     4302 <kprobe_unwind_native+0x4302> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17154ULL;
	}
x86_l_269d:
	/* 0x269d: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_26a0:
	/* 0x26a0: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_26a7:
	/* 0x26a7: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26aa:
	/* 0x26aa: jne    2d62 <kprobe_unwind_native+0x2d62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11618ULL;
	}
x86_l_26b0:
	/* 0x26b0: movzx  eax,WORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 88ULL);
x86_l_26b5:
	/* 0x26b5: movzx  ecx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_26b9:
	/* 0x26b9: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_26bb:
	/* 0x26bb: mov    ecx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_26c2:
	/* 0x26c2: cmp    ecx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_26c6:
	/* 0x26c6: lea    r13d,[rax+0x10000] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 65536ULL);
x86_l_26cd:
	/* 0x26cd: cmovae r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_26d1:
	/* 0x26d1: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_26d5:
	/* 0x26d5: mov    DWORD PTR [rsp+0x8c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_26dc:
	/* 0x26dc: cmp    eax,0x8000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32768ULL);
x86_l_26e1:
	/* 0x26e1: je     42e5 <kprobe_unwind_native+0x42e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17125ULL;
	}
x86_l_26e7:
	/* 0x26e7: cmp    eax,0x8001 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32769ULL);
x86_l_26ec:
	/* 0x26ec: jne    274f <kprobe_unwind_native+0x274f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_274f;
	}
x86_l_26ee:
	/* 0x26ee: mov    DWORD PTR [rsp+0x94],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159815ULL);
x86_l_26f9:
	/* 0x26f9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_2700:
	/* 0x2700: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_2708:
	/* 0x2708: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_270d:
	/* 0x270d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_270f:
	/* 0x270f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2712:
	/* 0x2712: je     2738 <kprobe_unwind_native+0x2738> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2738;
	}
x86_l_2714:
	/* 0x2714: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2717:
	/* 0x2717: jmp    2748 <kprobe_unwind_native+0x2748> */
	goto x86_l_2748;
x86_l_2719:
	/* 0x2719: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_2720:
	/* 0x2720: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2723:
	/* 0x2723: jne    2cf2 <kprobe_unwind_native+0x2cf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cf2;
	}
x86_l_2729:
	/* 0x2729: mov    ecx,0xfa3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4003ULL);
x86_l_272e:
	/* 0x272e: mov    edx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_2733:
	/* 0x2733: jmp    42ef <kprobe_unwind_native+0x42ef> */
	return 17135ULL;
x86_l_2738:
	/* 0x2738: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_273f:
	/* 0x273f: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2742:
	/* 0x2742: jne    2eef <kprobe_unwind_native+0x2eef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12015ULL;
	}
x86_l_2748:
	/* 0x2748: mov    eax,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_274f:
	/* 0x274f: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2752:
	/* 0x2752: js     280d <kprobe_unwind_native+0x280d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_280d;
	}
x86_l_2758:
	/* 0x2758: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&unwind_info_array)));
x86_l_275f:
	/* 0x275f: lea    rsi,[rsp+0x8c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_2767:
	/* 0x2767: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_276c:
	/* 0x276c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_276e:
	/* 0x276e: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2773:
	/* 0x2773: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2776:
	/* 0x2776: mov    r15,QWORD PTR [rsp+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_277e:
	/* 0x277e: je     6323 <kprobe_unwind_native+0x6323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25379ULL;
	}
x86_l_2784:
	/* 0x2784: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2789:
	/* 0x2789: mov    ebp,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_278c:
	/* 0x278c: movzx  eax,BYTE PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_2790:
	/* 0x2790: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2792:
	/* 0x2792: je     27d0 <kprobe_unwind_native+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d0;
	}
x86_l_2794:
	/* 0x2794: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_279b:
	/* 0x279b: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_279e:
	/* 0x279e: jne    2e7b <kprobe_unwind_native+0x2e7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11899ULL;
	}
x86_l_27a4:
	/* 0x27a4: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_27a6:
	/* 0x27a6: and    cl,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_27a9:
	/* 0x27a9: movzx  ecx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_27ac:
	/* 0x27ac: cmp    r13d,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RCX, X86_WIDTH_32);
x86_l_27af:
	/* 0x27af: jl     27d0 <kprobe_unwind_native+0x27d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_27d0;
	}
x86_l_27b1:
	/* 0x27b1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27b3:
	/* 0x27b3: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_27b5:
	/* 0x27b5: setns  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NS);
x86_l_27b8:
	/* 0x27b8: shl    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_27bb:
	/* 0x27bb: add    ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_27bd:
	/* 0x27bd: add    ebp,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4294967288ULL);
x86_l_27c0:
	/* 0x27c0: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_27c7:
	/* 0x27c7: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27ca:
	/* 0x27ca: jne    2f6d <kprobe_unwind_native+0x2f6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12141ULL;
	}
x86_l_27d0:
	/* 0x27d0: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_27d5:
	/* 0x27d5: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_27d8:
	/* 0x27d8: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_27da:
	/* 0x27da: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_27dd:
	/* 0x27dd: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_27df:
	/* 0x27df: cmovns ecx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBP, X86_WIDTH_32, X86_CC_NS);
x86_l_27e2:
	/* 0x27e2: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_27e4:
	/* 0x27e4: and    edx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_27e7:
	/* 0x27e7: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27ea:
	/* 0x27ea: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_27ed:
	/* 0x27ed: jg     292b <kprobe_unwind_native+0x292b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_292b;
	}
x86_l_27f3:
	/* 0x27f3: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_27f6:
	/* 0x27f6: je     2aa4 <kprobe_unwind_native+0x2aa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aa4;
	}
x86_l_27fc:
	/* 0x27fc: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_27ff:
	/* 0x27ff: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2802:
	/* 0x2802: je     2aa1 <kprobe_unwind_native+0x2aa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aa1;
	}
x86_l_2808:
	/* 0x2808: jmp    3047 <kprobe_unwind_native+0x3047> */
	return 12359ULL;
x86_l_280d:
	/* 0x280d: and    eax,0xffff7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294934527ULL);
x86_l_2812:
	/* 0x2812: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_2818:
	/* 0x2818: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_281b:
	/* 0x281b: jg     28b1 <kprobe_unwind_native+0x28b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_28b1;
	}
x86_l_2821:
	/* 0x2821: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2824:
	/* 0x2824: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2829:
	/* 0x2829: mov    rcx,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_2831:
	/* 0x2831: mov    rdx,QWORD PTR [rsp+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_2839:
	/* 0x2839: je     6482 <kprobe_unwind_native+0x6482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25730ULL;
	}
x86_l_283f:
	/* 0x283f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2842:
	/* 0x2842: jne    5f53 <kprobe_unwind_native+0x5f53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24403ULL;
	}
x86_l_2848:
	/* 0x2848: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_284b:
	/* 0x284b: mov    rax,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_284e:
	/* 0x284e: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2850:
	/* 0x2850: and    ecx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2853:
	/* 0x2853: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2855:
	/* 0x2855: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_2858:
	/* 0x2858: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_285b:
	/* 0x285b: lea    r13,[rax+rdx*8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_285f:
	/* 0x285f: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2863:
	/* 0x2863: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_286a:
	/* 0x286a: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_286d:
	/* 0x286d: je     325c <kprobe_unwind_native+0x325c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12892ULL;
	}
x86_l_2873:
	/* 0x2873: movabs rax,0xa786c2578303d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541309ULL);
x86_l_287d:
	/* 0x287d: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2882:
	/* 0x2882: movabs rax,0x616663202c544c50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018406059137322064ULL);
x86_l_288c:
	/* 0x288c: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2891:
	/* 0x2891: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2896:
	/* 0x2896: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_289b:
	/* 0x289b: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_28a0:
	/* 0x28a0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_28a5:
	/* 0x28a5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_28a8:
	/* 0x28a8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28aa:
	/* 0x28aa: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_28ac:
	/* 0x28ac: jmp    325c <kprobe_unwind_native+0x325c> */
	return 12892ULL;
x86_l_28b1:
	/* 0x28b1: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_28b4:
	/* 0x28b4: je     2990 <kprobe_unwind_native+0x2990> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2990;
	}
x86_l_28ba:
	/* 0x28ba: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28bd:
	/* 0x28bd: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_28c2:
	/* 0x28c2: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_28c7:
	/* 0x28c7: mov    r15,QWORD PTR [rsp+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_28cf:
	/* 0x28cf: jne    5f53 <kprobe_unwind_native+0x5f53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24403ULL;
	}
x86_l_28d5:
	/* 0x28d5: mov    rax,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28d8:
	/* 0x28d8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28dd:
	/* 0x28dd: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_28e2:
	/* 0x28e2: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_28e8:
	/* 0x28e8: mov    rdx,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28eb:
	/* 0x28eb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_28f0:
	/* 0x28f0: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_28f3:
	/* 0x28f3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28f6:
	/* 0x28f6: jne    1647 <kprobe_unwind_native+0x1647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5703ULL;
	}
x86_l_28fc:
	/* 0x28fc: mov    rax,QWORD PTR [rbx+0xee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_2903:
	/* 0x2903: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2907:
	/* 0x2907: mov    QWORD PTR [rbx+0xed8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_290e:
	/* 0x290e: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2913:
	/* 0x2913: mov    QWORD PTR [rbx+0xee0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_291a:
	/* 0x291a: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_291f:
	/* 0x291f: mov    QWORD PTR [rbx+0xed0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_2926:
	/* 0x2926: jmp    3297 <kprobe_unwind_native+0x3297> */
	return 12951ULL;
x86_l_292b:
	/* 0x292b: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_292e:
	/* 0x292e: je     2a9c <kprobe_unwind_native+0x2a9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a9c;
	}
x86_l_2934:
	/* 0x2934: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_2937:
	/* 0x2937: jne    3047 <kprobe_unwind_native+0x3047> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12359ULL;
	}
x86_l_293d:
	/* 0x293d: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_293f:
	/* 0x293f: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_2941:
	/* 0x2941: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_2944:
	/* 0x2944: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_2946:
	/* 0x2946: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_294b:
	/* 0x294b: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_2952:
	/* 0x2952: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2955:
	/* 0x2955: jne    2fd2 <kprobe_unwind_native+0x2fd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12242ULL;
	}
x86_l_295b:
	/* 0x295b: and    ebp,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_295e:
	/* 0x295e: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2961:
	/* 0x2961: cmp    ebp,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_2964:
	/* 0x2964: jg     3025 <kprobe_unwind_native+0x3025> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 12325ULL;
	}
x86_l_296a:
	/* 0x296a: mov    rax,QWORD PTR [rsp+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_2972:
	/* 0x2972: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_2974:
	/* 0x2974: je     303f <kprobe_unwind_native+0x303f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12351ULL;
	}
x86_l_297a:
	/* 0x297a: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_297d:
	/* 0x297d: jne    3047 <kprobe_unwind_native+0x3047> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12359ULL;
	}
x86_l_2983:
	/* 0x2983: mov    rax,QWORD PTR [rsp+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_298b:
	/* 0x298b: jmp    303f <kprobe_unwind_native+0x303f> */
	return 12351ULL;
x86_l_2990:
	/* 0x2990: mov    rdx,QWORD PTR [rsp+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_2998:
	/* 0x2998: mov    rax,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_299b:
	/* 0x299b: add    rax,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_299f:
	/* 0x299f: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_29a7:
	/* 0x29a7: mov    ecx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 144ULL);
x86_l_29ac:
	/* 0x29ac: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_29b2:
	/* 0x29b2: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_29b5:
	/* 0x29b5: mov    rdx,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29b8:
	/* 0x29b8: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_29bc:
	/* 0x29bc: mov    esi,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 144ULL);
x86_l_29c1:
	/* 0x29c1: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_29c4:
	/* 0x29c4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29c7:
	/* 0x29c7: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_29cc:
	/* 0x29cc: jne    1647 <kprobe_unwind_native+0x1647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5703ULL;
	}
x86_l_29d2:
	/* 0x29d2: mov    rax,QWORD PTR [rsp+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_29da:
	/* 0x29da: mov    QWORD PTR [rbx+0xee8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3816ULL);
x86_l_29e1:
	/* 0x29e1: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_29e9:
	/* 0x29e9: mov    QWORD PTR [rbx+0xef0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3824ULL);
x86_l_29f0:
	/* 0x29f0: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_29f8:
	/* 0x29f8: mov    QWORD PTR [rbx+0xef8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3832ULL);
x86_l_29ff:
	/* 0x29ff: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2a07:
	/* 0x2a07: mov    QWORD PTR [rbx+0xf00],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3840ULL);
x86_l_2a0e:
	/* 0x2a0e: mov    rax,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2a16:
	/* 0x2a16: mov    QWORD PTR [rbx+0xf08],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3848ULL);
x86_l_2a1d:
	/* 0x2a1d: mov    rax,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2a25:
	/* 0x2a25: mov    QWORD PTR [rbx+0xee0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_2a2c:
	/* 0x2a2c: mov    rax,QWORD PTR [rsp+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2a34:
	/* 0x2a34: mov    QWORD PTR [rbx+0xed8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_2a3b:
	/* 0x2a3b: mov    rax,QWORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2a43:
	/* 0x2a43: mov    QWORD PTR [rbx+0xed0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_2a4a:
	/* 0x2a4a: mov    BYTE PTR [rbx+0xf30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16698832846848ULL);
x86_l_2a51:
	/* 0x2a51: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_2a58:
	/* 0x2a58: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a5b:
	/* 0x2a5b: je     329e <kprobe_unwind_native+0x329e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12958ULL;
	}
x86_l_2a61:
	/* 0x2a61: movabs rax,0xa656d61726620 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926270227834400ULL);
x86_l_2a6b:
	/* 0x2a6b: mov    QWORD PTR [rsp+0x16],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_2a70:
	/* 0x2a70: movabs rax,0x66206c616e676973 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7359000956843288947ULL);
x86_l_2a7a:
	/* 0x2a7a: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a7f:
	/* 0x2a7f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a84:
	/* 0x2a84: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2a89:
	/* 0x2a89: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2a8e:
	/* 0x2a8e: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_2a93:
	/* 0x2a93: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a95:
	/* 0x2a95: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2a97:
	/* 0x2a97: jmp    329e <kprobe_unwind_native+0x329e> */
	return 12958ULL;
x86_l_2a9c:
	/* 0x2a9c: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2aa1:
	/* 0x2aa1: mov    r13,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2aa4:
	/* 0x2aa4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2aa7:
	/* 0x2aa7: movsxd r13,ecx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_2aaa:
	/* 0x2aaa: add    r13,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2aad:
	/* 0x2aad: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2aaf:
	/* 0x2aaf: jns    3047 <kprobe_unwind_native+0x3047> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 12359ULL;
	}
x86_l_2ab5:
	/* 0x2ab5: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2aba:
	/* 0x2aba: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_2abf:
	/* 0x2abf: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_2ac4:
	/* 0x2ac4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ac9:
	/* 0x2ac9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2acc:
	/* 0x2acc: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2ace:
	/* 0x2ace: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ad1:
	/* 0x2ad1: je     2aeb <kprobe_unwind_native+0x2aeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aeb;
	}
x86_l_2ad3:
	/* 0x2ad3: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_2ada:
	/* 0x2ada: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2add:
	/* 0x2add: jne    375f <kprobe_unwind_native+0x375f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14175ULL;
	}
x86_l_2ae3:
	/* 0x2ae3: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ae6:
	/* 0x2ae6: jmp    3047 <kprobe_unwind_native+0x3047> */
	return 12359ULL;
x86_l_2aeb:
	/* 0x2aeb: shl    ebp,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_2aee:
	/* 0x2aee: and    ebp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 56ULL);
x86_l_2af1:
	/* 0x2af1: add    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_2af6:
	/* 0x2af6: mov    r13,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_2af9:
	/* 0x2af9: jmp    3047 <kprobe_unwind_native+0x3047> */
	return 12359ULL;
x86_l_2afe:
	/* 0x2afe: mov    edx,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_2b04:
	/* 0x2b04: movabs rax,0x3d3d206425206576 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4412718824384652662ULL);
x86_l_2b0e:
	/* 0x2b0e: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2b16:
	/* 0x2b16: movabs rax,0x6974616e5f646e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598805597955583593ULL);
x86_l_2b20:
	/* 0x2b20: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2b28:
	/* 0x2b28: movabs rax,0x776e75203d3d3d3d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8605944719278423357ULL);
x86_l_2b32:
	/* 0x2b32: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2b3a:
	/* 0x2b3a: mov    DWORD PTR [rsp+0xb8],0xa3d3d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 790274653501ULL);
x86_l_2b45:
	/* 0x2b45: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2b4d:
	/* 0x2b4d: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_2b52:
	/* 0x2b52: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2b57:
	/* 0x2b57: mov    esi,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 28ULL);
x86_l_2b5c:
	/* 0x2b5c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b5e:
	/* 0x2b5e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2b60:
	/* 0x2b60: jmp    1e20 <kprobe_unwind_native+0x1e20> */
	return 7712ULL;
x86_l_2b65:
	/* 0x2b65: movabs rax,0xa786c253a786c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 754471844735118373ULL);
x86_l_2b6f:
	/* 0x2b6f: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b74:
	/* 0x2b74: movabs rax,0x20726f662061746c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338053640979313772ULL);
x86_l_2b7e:
	/* 0x2b7e: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b83:
	/* 0x2b83: movabs rax,0x6564206b63617473 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7306000141102707827ULL);
x86_l_2b8d:
	/* 0x2b8d: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b92:
	/* 0x2b92: movabs rax,0x207075206b6f6f4c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337496988707155788ULL);
x86_l_2b9c:
	/* 0x2b9c: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ba1:
	/* 0x2ba1: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2ba6:
	/* 0x2ba6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bab:
	/* 0x2bab: mov    eax,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_2bb0:
	/* 0x2bb0: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_2bb6:
	/* 0x2bb6: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_2bbd:
	/* 0x2bbd: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_2bc4:
	/* 0x2bc4: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_2bc9:
	/* 0x2bc9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bcb:
	/* 0x2bcb: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2bce:
	/* 0x2bce: jmp    1f9c <kprobe_unwind_native+0x1f9c> */
	return 8092ULL;
x86_l_2bd3:
	/* 0x2bd3: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_2bdd:
	/* 0x2bdd: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_2be5:
	/* 0x2be5: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_2bef:
	/* 0x2bef: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2bf7:
	/* 0x2bf7: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_2c01:
	/* 0x2c01: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2c09:
	/* 0x2c09: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_2c13:
	/* 0x2c13: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2c1b:
	/* 0x2c1b: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_2c25:
	/* 0x2c25: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2c2d:
	/* 0x2c2d: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2c37:
	/* 0x2c37: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2c3f:
	/* 0x2c3f: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2c47:
	/* 0x2c47: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2c4c:
	/* 0x2c4c: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2c51:
	/* 0x2c51: mov    edx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c55:
	/* 0x2c55: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2c5a:
	/* 0x2c5a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c5c:
	/* 0x2c5c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2c5e:
	/* 0x2c5e: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c63:
	/* 0x2c63: je     1ef6 <kprobe_unwind_native+0x1ef6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7926ULL;
	}
x86_l_2c69:
	/* 0x2c69: jmp    1e52 <kprobe_unwind_native+0x1e52> */
	return 7762ULL;
x86_l_2c6e:
	/* 0x2c6e: movabs rax,0xa296425204449 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2860259863446601ULL);
x86_l_2c78:
	/* 0x2c78: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2c7d:
	/* 0x2c7d: movabs rax,0x70616d2820756c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8097873624099548197ULL);
x86_l_2c87:
	/* 0x2c87: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c8c:
	/* 0x2c8c: movabs rax,0x206f7420756c2520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414386373920ULL);
x86_l_2c96:
	/* 0x2c96: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c9b:
	/* 0x2c9b: movabs rax,0x6d6f726620656220 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7885647255504773664ULL);
x86_l_2ca5:
	/* 0x2ca5: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2caa:
	/* 0x2caa: movabs rax,0x646c756f68732073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7236287822631739507ULL);
x86_l_2cb4:
	/* 0x2cb4: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cb9:
	/* 0x2cb9: movabs rax,0x6c61767265746e49 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7809653462537629257ULL);
x86_l_2cc3:
	/* 0x2cc3: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cc8:
	/* 0x2cc8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ccd:
	/* 0x2ccd: mov    eax,0x30 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 48ULL);
x86_l_2cd2:
	/* 0x2cd2: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_2cd8:
	/* 0x2cd8: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_2cdb:
	/* 0x2cdb: movzx  r8d,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ce0:
	/* 0x2ce0: mov    esi,0x30 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 48ULL);
x86_l_2ce5:
	/* 0x2ce5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2ce8:
	/* 0x2ce8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cea:
	/* 0x2cea: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_2ced:
	/* 0x2ced: jmp    216b <kprobe_unwind_native+0x216b> */
	return 8555ULL;
x86_l_2cf2:
	/* 0x2cf2: movabs rax,0x6174616420747075 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7022344801646571637ULL);
x86_l_2cfc:
	/* 0x2cfc: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d01:
	/* 0x2d01: movabs rax,0x72726f43202e7370 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8246776201762206576ULL);
x86_l_2d0b:
	/* 0x2d0b: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d10:
	/* 0x2d10: movabs rax,0x657473203631206e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310594677314494574ULL);
x86_l_2d1a:
	/* 0x2d1a: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d1f:
	/* 0x2d1f: movabs rax,0x6920686372616573 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575169349567210867ULL);
x86_l_2d29:
	/* 0x2d29: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d2e:
	/* 0x2d2e: movabs rax,0x622064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7070761801744998726ULL);
x86_l_2d38:
	/* 0x2d38: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d3d:
	/* 0x2d3d: mov    DWORD PTR [rsp+0x37],0xa3f61 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 236223872865ULL);
x86_l_2d45:
	/* 0x2d45: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d4a:
	/* 0x2d4a: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
	return 11599ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11599ULL: goto x86_l_2d4f;
	case 11604ULL: goto x86_l_2d54;
	case 11609ULL: goto x86_l_2d59;
	case 11611ULL: goto x86_l_2d5b;
	case 11613ULL: goto x86_l_2d5d;
	case 11618ULL: goto x86_l_2d62;
	case 11628ULL: goto x86_l_2d6c;
	case 11633ULL: goto x86_l_2d71;
	case 11643ULL: goto x86_l_2d7b;
	case 11648ULL: goto x86_l_2d80;
	case 11658ULL: goto x86_l_2d8a;
	case 11663ULL: goto x86_l_2d8f;
	case 11673ULL: goto x86_l_2d99;
	case 11678ULL: goto x86_l_2d9e;
	case 11688ULL: goto x86_l_2da8;
	case 11693ULL: goto x86_l_2dad;
	case 11703ULL: goto x86_l_2db7;
	case 11708ULL: goto x86_l_2dbc;
	case 11713ULL: goto x86_l_2dc1;
	case 11718ULL: goto x86_l_2dc6;
	case 11724ULL: goto x86_l_2dcc;
	case 11731ULL: goto x86_l_2dd3;
	case 11735ULL: goto x86_l_2dd7;
	case 11740ULL: goto x86_l_2ddc;
	case 11745ULL: goto x86_l_2de1;
	case 11747ULL: goto x86_l_2de3;
	case 11750ULL: goto x86_l_2de6;
	case 11755ULL: goto x86_l_2deb;
	case 11765ULL: goto x86_l_2df5;
	case 11773ULL: goto x86_l_2dfd;
	case 11783ULL: goto x86_l_2e07;
	case 11791ULL: goto x86_l_2e0f;
	case 11801ULL: goto x86_l_2e19;
	case 11809ULL: goto x86_l_2e21;
	case 11819ULL: goto x86_l_2e2b;
	case 11827ULL: goto x86_l_2e33;
	case 11837ULL: goto x86_l_2e3d;
	case 11845ULL: goto x86_l_2e45;
	case 11855ULL: goto x86_l_2e4f;
	case 11863ULL: goto x86_l_2e57;
	case 11871ULL: goto x86_l_2e5f;
	case 11876ULL: goto x86_l_2e64;
	case 11881ULL: goto x86_l_2e69;
	case 11885ULL: goto x86_l_2e6d;
	case 11890ULL: goto x86_l_2e72;
	case 11892ULL: goto x86_l_2e74;
	case 11894ULL: goto x86_l_2e76;
	case 11899ULL: goto x86_l_2e7b;
	case 11909ULL: goto x86_l_2e85;
	case 11914ULL: goto x86_l_2e8a;
	case 11924ULL: goto x86_l_2e94;
	case 11929ULL: goto x86_l_2e99;
	case 11939ULL: goto x86_l_2ea3;
	case 11944ULL: goto x86_l_2ea8;
	case 11954ULL: goto x86_l_2eb2;
	case 11959ULL: goto x86_l_2eb7;
	case 11964ULL: goto x86_l_2ebc;
	case 11969ULL: goto x86_l_2ec1;
	case 11974ULL: goto x86_l_2ec6;
	case 11980ULL: goto x86_l_2ecc;
	case 11985ULL: goto x86_l_2ed1;
	case 11991ULL: goto x86_l_2ed7;
	case 11996ULL: goto x86_l_2edc;
	case 11999ULL: goto x86_l_2edf;
	case 12001ULL: goto x86_l_2ee1;
	case 12004ULL: goto x86_l_2ee4;
	case 12010ULL: goto x86_l_2eea;
	case 12015ULL: goto x86_l_2eef;
	case 12025ULL: goto x86_l_2ef9;
	case 12030ULL: goto x86_l_2efe;
	case 12040ULL: goto x86_l_2f08;
	case 12045ULL: goto x86_l_2f0d;
	case 12055ULL: goto x86_l_2f17;
	case 12060ULL: goto x86_l_2f1c;
	case 12070ULL: goto x86_l_2f26;
	case 12075ULL: goto x86_l_2f2b;
	case 12085ULL: goto x86_l_2f35;
	case 12090ULL: goto x86_l_2f3a;
	case 12100ULL: goto x86_l_2f44;
	case 12105ULL: goto x86_l_2f49;
	case 12110ULL: goto x86_l_2f4e;
	case 12115ULL: goto x86_l_2f53;
	case 12120ULL: goto x86_l_2f58;
	case 12127ULL: goto x86_l_2f5f;
	case 12132ULL: goto x86_l_2f64;
	case 12134ULL: goto x86_l_2f66;
	case 12136ULL: goto x86_l_2f68;
	case 12141ULL: goto x86_l_2f6d;
	case 12151ULL: goto x86_l_2f77;
	case 12156ULL: goto x86_l_2f7c;
	case 12166ULL: goto x86_l_2f86;
	case 12171ULL: goto x86_l_2f8b;
	case 12181ULL: goto x86_l_2f95;
	case 12186ULL: goto x86_l_2f9a;
	case 12196ULL: goto x86_l_2fa4;
	case 12201ULL: goto x86_l_2fa9;
	case 12206ULL: goto x86_l_2fae;
	case 12211ULL: goto x86_l_2fb3;
	case 12216ULL: goto x86_l_2fb8;
	case 12221ULL: goto x86_l_2fbd;
	case 12228ULL: goto x86_l_2fc4;
	case 12233ULL: goto x86_l_2fc9;
	case 12235ULL: goto x86_l_2fcb;
	case 12237ULL: goto x86_l_2fcd;
	case 12242ULL: goto x86_l_2fd2;
	case 12252ULL: goto x86_l_2fdc;
	case 12257ULL: goto x86_l_2fe1;
	case 12267ULL: goto x86_l_2feb;
	case 12272ULL: goto x86_l_2ff0;
	case 12277ULL: goto x86_l_2ff5;
	case 12282ULL: goto x86_l_2ffa;
	case 12287ULL: goto x86_l_2fff;
	case 12293ULL: goto x86_l_3005;
	case 12296ULL: goto x86_l_3008;
	case 12301ULL: goto x86_l_300d;
	case 12306ULL: goto x86_l_3012;
	case 12308ULL: goto x86_l_3014;
	case 12310ULL: goto x86_l_3016;
	case 12313ULL: goto x86_l_3019;
	case 12316ULL: goto x86_l_301c;
	case 12319ULL: goto x86_l_301f;
	case 12325ULL: goto x86_l_3025;
	case 12333ULL: goto x86_l_302d;
	case 12336ULL: goto x86_l_3030;
	case 12338ULL: goto x86_l_3032;
	case 12346ULL: goto x86_l_303a;
	case 12349ULL: goto x86_l_303d;
	case 12351ULL: goto x86_l_303f;
	case 12356ULL: goto x86_l_3044;
	case 12359ULL: goto x86_l_3047;
	case 12364ULL: goto x86_l_304c;
	case 12368ULL: goto x86_l_3050;
	case 12372ULL: goto x86_l_3054;
	case 12375ULL: goto x86_l_3057;
	case 12378ULL: goto x86_l_305a;
	case 12380ULL: goto x86_l_305c;
	case 12384ULL: goto x86_l_3060;
	case 12386ULL: goto x86_l_3062;
	case 12389ULL: goto x86_l_3065;
	case 12392ULL: goto x86_l_3068;
	case 12394ULL: goto x86_l_306a;
	case 12397ULL: goto x86_l_306d;
	case 12400ULL: goto x86_l_3070;
	case 12402ULL: goto x86_l_3072;
	case 12405ULL: goto x86_l_3075;
	case 12408ULL: goto x86_l_3078;
	case 12410ULL: goto x86_l_307a;
	case 12415ULL: goto x86_l_307f;
	case 12418ULL: goto x86_l_3082;
	case 12420ULL: goto x86_l_3084;
	case 12423ULL: goto x86_l_3087;
	case 12429ULL: goto x86_l_308d;
	case 12432ULL: goto x86_l_3090;
	case 12434ULL: goto x86_l_3092;
	case 12437ULL: goto x86_l_3095;
	case 12439ULL: goto x86_l_3097;
	case 12444ULL: goto x86_l_309c;
	case 12451ULL: goto x86_l_30a3;
	case 12454ULL: goto x86_l_30a6;
	case 12460ULL: goto x86_l_30ac;
	case 12464ULL: goto x86_l_30b0;
	case 12468ULL: goto x86_l_30b4;
	case 12474ULL: goto x86_l_30ba;
	case 12482ULL: goto x86_l_30c2;
	case 12485ULL: goto x86_l_30c5;
	case 12491ULL: goto x86_l_30cb;
	case 12495ULL: goto x86_l_30cf;
	case 12501ULL: goto x86_l_30d5;
	case 12509ULL: goto x86_l_30dd;
	case 12514ULL: goto x86_l_30e2;
	case 12519ULL: goto x86_l_30e7;
	case 12522ULL: goto x86_l_30ea;
	case 12525ULL: goto x86_l_30ed;
	case 12528ULL: goto x86_l_30f0;
	case 12530ULL: goto x86_l_30f2;
	case 12536ULL: goto x86_l_30f8;
	case 12541ULL: goto x86_l_30fd;
	case 12546ULL: goto x86_l_3102;
	case 12551ULL: goto x86_l_3107;
	case 12556ULL: goto x86_l_310c;
	case 12559ULL: goto x86_l_310f;
	case 12561ULL: goto x86_l_3111;
	case 12564ULL: goto x86_l_3114;
	case 12570ULL: goto x86_l_311a;
	case 12577ULL: goto x86_l_3121;
	case 12580ULL: goto x86_l_3124;
	case 12586ULL: goto x86_l_312a;
	case 12596ULL: goto x86_l_3134;
	case 12601ULL: goto x86_l_3139;
	case 12611ULL: goto x86_l_3143;
	case 12616ULL: goto x86_l_3148;
	case 12626ULL: goto x86_l_3152;
	case 12631ULL: goto x86_l_3157;
	case 12641ULL: goto x86_l_3161;
	case 12646ULL: goto x86_l_3166;
	case 12656ULL: goto x86_l_3170;
	case 12661ULL: goto x86_l_3175;
	case 12669ULL: goto x86_l_317d;
	case 12674ULL: goto x86_l_3182;
	case 12679ULL: goto x86_l_3187;
	case 12684ULL: goto x86_l_318c;
	case 12689ULL: goto x86_l_3191;
	case 12692ULL: goto x86_l_3194;
	case 12694ULL: goto x86_l_3196;
	case 12696ULL: goto x86_l_3198;
	case 12701ULL: goto x86_l_319d;
	case 12705ULL: goto x86_l_31a1;
	case 12709ULL: goto x86_l_31a5;
	case 12714ULL: goto x86_l_31aa;
	case 12717ULL: goto x86_l_31ad;
	case 12719ULL: goto x86_l_31af;
	case 12729ULL: goto x86_l_31b9;
	case 12734ULL: goto x86_l_31be;
	case 12744ULL: goto x86_l_31c8;
	case 12749ULL: goto x86_l_31cd;
	case 12754ULL: goto x86_l_31d2;
	case 12759ULL: goto x86_l_31d7;
	case 12764ULL: goto x86_l_31dc;
	case 12770ULL: goto x86_l_31e2;
	case 12774ULL: goto x86_l_31e6;
	case 12779ULL: goto x86_l_31eb;
	case 12784ULL: goto x86_l_31f0;
	case 12787ULL: goto x86_l_31f3;
	case 12789ULL: goto x86_l_31f5;
	case 12792ULL: goto x86_l_31f8;
	case 12796ULL: goto x86_l_31fc;
	case 12802ULL: goto x86_l_3202;
	case 12810ULL: goto x86_l_320a;
	case 12814ULL: goto x86_l_320e;
	case 12816ULL: goto x86_l_3210;
	case 12824ULL: goto x86_l_3218;
	case 12828ULL: goto x86_l_321c;
	case 12830ULL: goto x86_l_321e;
	case 12835ULL: goto x86_l_3223;
	case 12838ULL: goto x86_l_3226;
	case 12841ULL: goto x86_l_3229;
	case 12843ULL: goto x86_l_322b;
	case 12848ULL: goto x86_l_3230;
	case 12853ULL: goto x86_l_3235;
	case 12858ULL: goto x86_l_323a;
	case 12863ULL: goto x86_l_323f;
	case 12866ULL: goto x86_l_3242;
	case 12868ULL: goto x86_l_3244;
	case 12870ULL: goto x86_l_3246;
	case 12875ULL: goto x86_l_324b;
	case 12878ULL: goto x86_l_324e;
	case 12880ULL: goto x86_l_3250;
	case 12885ULL: goto x86_l_3255;
	case 12892ULL: goto x86_l_325c;
	case 12895ULL: goto x86_l_325f;
	case 12900ULL: goto x86_l_3264;
	case 12906ULL: goto x86_l_326a;
	case 12910ULL: goto x86_l_326e;
	case 12915ULL: goto x86_l_3273;
	case 12920ULL: goto x86_l_3278;
	case 12928ULL: goto x86_l_3280;
	case 12933ULL: goto x86_l_3285;
	case 12935ULL: goto x86_l_3287;
	case 12938ULL: goto x86_l_328a;
	case 12944ULL: goto x86_l_3290;
	case 12951ULL: goto x86_l_3297;
	case 12958ULL: goto x86_l_329e;
	case 12966ULL: goto x86_l_32a6;
	case 12973ULL: goto x86_l_32ad;
	case 12978ULL: goto x86_l_32b2;
	case 12983ULL: goto x86_l_32b7;
	case 12985ULL: goto x86_l_32b9;
	case 12988ULL: goto x86_l_32bc;
	case 12994ULL: goto x86_l_32c2;
	case 12997ULL: goto x86_l_32c5;
	case 12999ULL: goto x86_l_32c7;
	case 13006ULL: goto x86_l_32ce;
	case 13009ULL: goto x86_l_32d1;
	case 13015ULL: goto x86_l_32d7;
	case 13025ULL: goto x86_l_32e1;
	case 13033ULL: goto x86_l_32e9;
	case 13043ULL: goto x86_l_32f3;
	case 13051ULL: goto x86_l_32fb;
	case 13061ULL: goto x86_l_3305;
	case 13069ULL: goto x86_l_330d;
	case 13079ULL: goto x86_l_3317;
	case 13087ULL: goto x86_l_331f;
	case 13095ULL: goto x86_l_3327;
	case 13100ULL: goto x86_l_332c;
	case 13106ULL: goto x86_l_3332;
	case 13114ULL: goto x86_l_333a;
	case 13117ULL: goto x86_l_333d;
	case 13120ULL: goto x86_l_3340;
	case 13125ULL: goto x86_l_3345;
	case 13128ULL: goto x86_l_3348;
	case 13133ULL: goto x86_l_334d;
	case 13135ULL: goto x86_l_334f;
	case 13138ULL: goto x86_l_3352;
	case 13145ULL: goto x86_l_3359;
	case 13147ULL: goto x86_l_335b;
	case 13149ULL: goto x86_l_335d;
	case 13156ULL: goto x86_l_3364;
	case 13159ULL: goto x86_l_3367;
	case 13165ULL: goto x86_l_336d;
	case 13167ULL: goto x86_l_336f;
	case 13175ULL: goto x86_l_3377;
	case 13178ULL: goto x86_l_337a;
	case 13181ULL: goto x86_l_337d;
	case 13187ULL: goto x86_l_3383;
	case 13189ULL: goto x86_l_3385;
	case 13195ULL: goto x86_l_338b;
	case 13205ULL: goto x86_l_3395;
	case 13208ULL: goto x86_l_3398;
	case 13214ULL: goto x86_l_339e;
	case 13219ULL: goto x86_l_33a3;
	case 13226ULL: goto x86_l_33aa;
	case 13229ULL: goto x86_l_33ad;
	case 13235ULL: goto x86_l_33b3;
	case 13245ULL: goto x86_l_33bd;
	case 13253ULL: goto x86_l_33c5;
	case 13263ULL: goto x86_l_33cf;
	case 13271ULL: goto x86_l_33d7;
	case 13281ULL: goto x86_l_33e1;
	case 13289ULL: goto x86_l_33e9;
	case 13299ULL: goto x86_l_33f3;
	case 13307ULL: goto x86_l_33fb;
	case 13317ULL: goto x86_l_3405;
	case 13325ULL: goto x86_l_340d;
	case 13330ULL: goto x86_l_3412;
	case 13335ULL: goto x86_l_3417;
	case 13340ULL: goto x86_l_341c;
	case 13343ULL: goto x86_l_341f;
	case 13345ULL: goto x86_l_3421;
	case 13347ULL: goto x86_l_3423;
	case 13352ULL: goto x86_l_3428;
	case 13362ULL: goto x86_l_3432;
	case 13370ULL: goto x86_l_343a;
	case 13380ULL: goto x86_l_3444;
	case 13388ULL: goto x86_l_344c;
	case 13398ULL: goto x86_l_3456;
	case 13406ULL: goto x86_l_345e;
	case 13416ULL: goto x86_l_3468;
	case 13424ULL: goto x86_l_3470;
	case 13434ULL: goto x86_l_347a;
	case 13442ULL: goto x86_l_3482;
	case 13452ULL: goto x86_l_348c;
	case 13460ULL: goto x86_l_3494;
	case 13468ULL: goto x86_l_349c;
	case 13476ULL: goto x86_l_34a4;
	case 13481ULL: goto x86_l_34a9;
	case 13486ULL: goto x86_l_34ae;
	case 13492ULL: goto x86_l_34b4;
	case 13497ULL: goto x86_l_34b9;
	case 13499ULL: goto x86_l_34bb;
	case 13501ULL: goto x86_l_34bd;
	case 13508ULL: goto x86_l_34c4;
	case 13518ULL: goto x86_l_34ce;
	case 13521ULL: goto x86_l_34d1;
	case 13527ULL: goto x86_l_34d7;
	case 13534ULL: goto x86_l_34de;
	case 13540ULL: goto x86_l_34e4;
	case 13545ULL: goto x86_l_34e9;
	case 13552ULL: goto x86_l_34f0;
	case 13555ULL: goto x86_l_34f3;
	case 13561ULL: goto x86_l_34f9;
	case 13571ULL: goto x86_l_3503;
	case 13579ULL: goto x86_l_350b;
	case 13589ULL: goto x86_l_3515;
	case 13597ULL: goto x86_l_351d;
	case 13607ULL: goto x86_l_3527;
	case 13615ULL: goto x86_l_352f;
	case 13625ULL: goto x86_l_3539;
	case 13633ULL: goto x86_l_3541;
	case 13641ULL: goto x86_l_3549;
	case 13646ULL: goto x86_l_354e;
	case 13651ULL: goto x86_l_3553;
	case 13656ULL: goto x86_l_3558;
	case 13659ULL: goto x86_l_355b;
	case 13661ULL: goto x86_l_355d;
	case 13663ULL: goto x86_l_355f;
	case 13668ULL: goto x86_l_3564;
	case 13670ULL: goto x86_l_3566;
	case 13678ULL: goto x86_l_356e;
	case 13684ULL: goto x86_l_3574;
	case 13691ULL: goto x86_l_357b;
	case 13698ULL: goto x86_l_3582;
	case 13703ULL: goto x86_l_3587;
	case 13708ULL: goto x86_l_358c;
	case 13710ULL: goto x86_l_358e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2d4f:
	/* 0x2d4f: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2d54:
	/* 0x2d54: mov    esi,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 43ULL);
x86_l_2d59:
	/* 0x2d59: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d5b:
	/* 0x2d5b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2d5d:
	/* 0x2d5d: jmp    2729 <kprobe_unwind_native+0x2729> */
	return 10025ULL;
x86_l_2d62:
	/* 0x2d62: movabs rax,0xa6425206f666e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860387845742ULL);
x86_l_2d6c:
	/* 0x2d6c: mov    QWORD PTR [rsp+0x35],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_2d71:
	/* 0x2d71: movabs rax,0x6f666e49646e6977 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8027224647331113335ULL);
x86_l_2d7b:
	/* 0x2d7b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d80:
	/* 0x2d80: movabs rax,0x6e75202c78257830 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7959303291813591088ULL);
x86_l_2d8a:
	/* 0x2d8a: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d8f:
	/* 0x2d8f: movabs rax,0x20776f4c72646461 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2339460905569641569ULL);
x86_l_2d99:
	/* 0x2d99: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d9e:
	/* 0x2d9e: movabs rax,0x202c642520786564 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2318338018810291556ULL);
x86_l_2da8:
	/* 0x2da8: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2dad:
	/* 0x2dad: movabs rax,0x6e692061746c6564 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7955925819663869284ULL);
x86_l_2db7:
	/* 0x2db7: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dbc:
	/* 0x2dbc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dc1:
	/* 0x2dc1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2dc6:
	/* 0x2dc6: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_2dcc:
	/* 0x2dcc: mov    edx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2dd3:
	/* 0x2dd3: movzx  ecx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2dd7:
	/* 0x2dd7: movzx  r8d,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2ddc:
	/* 0x2ddc: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_2de1:
	/* 0x2de1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2de3:
	/* 0x2de3: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_2de6:
	/* 0x2de6: jmp    26b0 <kprobe_unwind_native+0x26b0> */
	return 9904ULL;
x86_l_2deb:
	/* 0x2deb: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_2df5:
	/* 0x2df5: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_2dfd:
	/* 0x2dfd: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_2e07:
	/* 0x2e07: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2e0f:
	/* 0x2e0f: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_2e19:
	/* 0x2e19: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2e21:
	/* 0x2e21: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_2e2b:
	/* 0x2e2b: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2e33:
	/* 0x2e33: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_2e3d:
	/* 0x2e3d: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2e45:
	/* 0x2e45: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2e4f:
	/* 0x2e4f: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2e57:
	/* 0x2e57: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2e5f:
	/* 0x2e5f: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2e64:
	/* 0x2e64: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2e69:
	/* 0x2e69: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2e6d:
	/* 0x2e6d: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2e72:
	/* 0x2e72: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e74:
	/* 0x2e74: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2e76:
	/* 0x2e76: jmp    1df7 <kprobe_unwind_native+0x1df7> */
	return 7671ULL;
x86_l_2e7b:
	/* 0x2e7b: movabs rax,0xa78323023252061 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 754408119914012769ULL);
x86_l_2e85:
	/* 0x2e85: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e8a:
	/* 0x2e8a: movabs rax,0x746c656420646567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8389191686598976871ULL);
x86_l_2e94:
	/* 0x2e94: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e99:
	/* 0x2e99: movabs rax,0x72656d202c642520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243114677922702624ULL);
x86_l_2ea3:
	/* 0x2ea3: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ea8:
	/* 0x2ea8: movabs rax,0x6666694472646441 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7378700782191010881ULL);
x86_l_2eb2:
	/* 0x2eb2: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eb7:
	/* 0x2eb7: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2ebc:
	/* 0x2ebc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ec1:
	/* 0x2ec1: mov    eax,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_2ec6:
	/* 0x2ec6: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_2ecc:
	/* 0x2ecc: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2ed1:
	/* 0x2ed1: movzx  ecx,BYTE PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_2ed7:
	/* 0x2ed7: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_2edc:
	/* 0x2edc: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_2edf:
	/* 0x2edf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ee1:
	/* 0x2ee1: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2ee4:
	/* 0x2ee4: movzx  eax,BYTE PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_2eea:
	/* 0x2eea: jmp    27a4 <kprobe_unwind_native+0x27a4> */
	return 10148ULL;
x86_l_2eef:
	/* 0x2eef: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_2ef9:
	/* 0x2ef9: mov    QWORD PTR [rsp+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_2efe:
	/* 0x2efe: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_2f08:
	/* 0x2f08: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f0d:
	/* 0x2f0d: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_2f17:
	/* 0x2f17: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f1c:
	/* 0x2f1c: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_2f26:
	/* 0x2f26: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f2b:
	/* 0x2f2b: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_2f35:
	/* 0x2f35: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f3a:
	/* 0x2f3a: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2f44:
	/* 0x2f44: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f49:
	/* 0x2f49: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f4e:
	/* 0x2f4e: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2f53:
	/* 0x2f53: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2f58:
	/* 0x2f58: mov    edx,DWORD PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_2f5f:
	/* 0x2f5f: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2f64:
	/* 0x2f64: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f66:
	/* 0x2f66: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2f68:
	/* 0x2f68: jmp    2748 <kprobe_unwind_native+0x2748> */
	return 10056ULL;
x86_l_2f6d:
	/* 0x2f6d: movabs rax,0xa64253d61746c65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 748764383608597605ULL);
x86_l_2f77:
	/* 0x2f77: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f7c:
	/* 0x2f7c: movabs rax,0x44616663203a6863 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4927332043248527459ULL);
x86_l_2f86:
	/* 0x2f86: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f8b:
	/* 0x2f8b: movabs rax,0x74616d2061746c65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8386103966981975141ULL);
x86_l_2f95:
	/* 0x2f95: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f9a:
	/* 0x2f9a: movabs rax,0x642064656772654d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7214876989737559373ULL);
x86_l_2fa4:
	/* 0x2fa4: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fa9:
	/* 0x2fa9: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2fae:
	/* 0x2fae: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fb3:
	/* 0x2fb3: mov    eax,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_2fb8:
	/* 0x2fb8: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2fbd:
	/* 0x2fbd: mov    edx,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_2fc4:
	/* 0x2fc4: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_2fc9:
	/* 0x2fc9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fcb:
	/* 0x2fcb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2fcd:
	/* 0x2fcd: jmp    27d0 <kprobe_unwind_native+0x27d0> */
	return 10192ULL;
x86_l_2fd2:
	/* 0x2fd2: movabs rax,0xa756c252b642572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 753627419551999346ULL);
x86_l_2fdc:
	/* 0x2fdc: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2fe1:
	/* 0x2fe1: movabs rax,0x203a646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2322278983241526901ULL);
x86_l_2feb:
	/* 0x2feb: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ff0:
	/* 0x2ff0: mov    BYTE PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2ff5:
	/* 0x2ff5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ffa:
	/* 0x2ffa: mov    eax,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2fff:
	/* 0x2fff: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_3005:
	/* 0x3005: and    ebp,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_3008:
	/* 0x3008: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_300d:
	/* 0x300d: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_3012:
	/* 0x3012: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_3014:
	/* 0x3014: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3016:
	/* 0x3016: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3019:
	/* 0x3019: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_301c:
	/* 0x301c: cmp    ebp,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_301f:
	/* 0x301f: jle    296a <kprobe_unwind_native+0x296a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 10602ULL;
	}
x86_l_3025:
	/* 0x3025: mov    rax,QWORD PTR [rsp+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_302d:
	/* 0x302d: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_3030:
	/* 0x3030: je     303f <kprobe_unwind_native+0x303f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_303f;
	}
x86_l_3032:
	/* 0x3032: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_303a:
	/* 0x303a: cmp    ebp,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 15ULL);
x86_l_303d:
	/* 0x303d: jne    3047 <kprobe_unwind_native+0x3047> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3047;
	}
x86_l_303f:
	/* 0x303f: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3044:
	/* 0x3044: add    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3047:
	/* 0x3047: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_304c:
	/* 0x304c: movzx  eax,BYTE PTR [rcx+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_3050:
	/* 0x3050: mov    r12d,DWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3054:
	/* 0x3054: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_3057:
	/* 0x3057: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_305a:
	/* 0x305a: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_305c:
	/* 0x305c: cmovns ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_NS);
x86_l_3060:
	/* 0x3060: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_3062:
	/* 0x3062: and    edx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_3065:
	/* 0x3065: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3068:
	/* 0x3068: jg     307f <kprobe_unwind_native+0x307f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_307f;
	}
x86_l_306a:
	/* 0x306a: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_306d:
	/* 0x306d: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_3070:
	/* 0x3070: je     30ea <kprobe_unwind_native+0x30ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30ea;
	}
x86_l_3072:
	/* 0x3072: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3075:
	/* 0x3075: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3078:
	/* 0x3078: je     30e7 <kprobe_unwind_native+0x30e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30e7;
	}
x86_l_307a:
	/* 0x307a: jmp    3246 <kprobe_unwind_native+0x3246> */
	goto x86_l_3246;
x86_l_307f:
	/* 0x307f: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3082:
	/* 0x3082: je     30e2 <kprobe_unwind_native+0x30e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30e2;
	}
x86_l_3084:
	/* 0x3084: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_3087:
	/* 0x3087: jne    3246 <kprobe_unwind_native+0x3246> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3246;
	}
x86_l_308d:
	/* 0x308d: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_3090:
	/* 0x3090: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_3092:
	/* 0x3092: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_3095:
	/* 0x3095: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3097:
	/* 0x3097: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_309c:
	/* 0x309c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_30a3:
	/* 0x30a3: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30a6:
	/* 0x30a6: jne    31af <kprobe_unwind_native+0x31af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_31af;
	}
x86_l_30ac:
	/* 0x30ac: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_30b0:
	/* 0x30b0: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_30b4:
	/* 0x30b4: jg     3202 <kprobe_unwind_native+0x3202> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3202;
	}
x86_l_30ba:
	/* 0x30ba: mov    rax,QWORD PTR [rsp+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_30c2:
	/* 0x30c2: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_30c5:
	/* 0x30c5: je     321e <kprobe_unwind_native+0x321e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_321e;
	}
x86_l_30cb:
	/* 0x30cb: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_30cf:
	/* 0x30cf: jne    3246 <kprobe_unwind_native+0x3246> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3246;
	}
x86_l_30d5:
	/* 0x30d5: mov    rax,QWORD PTR [rsp+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_30dd:
	/* 0x30dd: jmp    321e <kprobe_unwind_native+0x321e> */
	goto x86_l_321e;
x86_l_30e2:
	/* 0x30e2: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_30e7:
	/* 0x30e7: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30ea:
	/* 0x30ea: movsxd rbp,ecx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_30ed:
	/* 0x30ed: add    rbp,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30f0:
	/* 0x30f0: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_30f2:
	/* 0x30f2: jns    3226 <kprobe_unwind_native+0x3226> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_3226;
	}
x86_l_30f8:
	/* 0x30f8: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_30fd:
	/* 0x30fd: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_3102:
	/* 0x3102: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_3107:
	/* 0x3107: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_310c:
	/* 0x310c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_310f:
	/* 0x310f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3111:
	/* 0x3111: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3114:
	/* 0x3114: je     319d <kprobe_unwind_native+0x319d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_319d;
	}
x86_l_311a:
	/* 0x311a: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3121:
	/* 0x3121: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3124:
	/* 0x3124: je     3246 <kprobe_unwind_native+0x3246> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3246;
	}
x86_l_312a:
	/* 0x312a: movabs rax,0x2578302073736572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2699960892542641522ULL);
x86_l_3134:
	/* 0x3134: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3139:
	/* 0x3139: movabs rax,0x6464612065636e65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7234013693231722085ULL);
x86_l_3143:
	/* 0x3143: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3148:
	/* 0x3148: movabs rax,0x7265666572656420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243107278868538400ULL);
x86_l_3152:
	/* 0x3152: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3157:
	/* 0x3157: movabs rax,0x6f742064656c6961 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8031079651078859105ULL);
x86_l_3161:
	/* 0x3161: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3166:
	/* 0x3166: movabs rax,0x6620646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358992216502005365ULL);
x86_l_3170:
	/* 0x3170: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3175:
	/* 0x3175: mov    DWORD PTR [rsp+0x38],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518854764ULL);
x86_l_317d:
	/* 0x317d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3182:
	/* 0x3182: mov    eax,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_3187:
	/* 0x3187: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_318c:
	/* 0x318c: mov    esi,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_3191:
	/* 0x3191: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3194:
	/* 0x3194: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3196:
	/* 0x3196: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3198:
	/* 0x3198: jmp    3246 <kprobe_unwind_native+0x3246> */
	goto x86_l_3246;
x86_l_319d:
	/* 0x319d: shl    r12d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_31a1:
	/* 0x31a1: and    r12d,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 56ULL);
x86_l_31a5:
	/* 0x31a5: add    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_31aa:
	/* 0x31aa: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_31ad:
	/* 0x31ad: jmp    3226 <kprobe_unwind_native+0x3226> */
	goto x86_l_3226;
x86_l_31af:
	/* 0x31af: movabs rax,0xa756c252b642572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 753627419551999346ULL);
x86_l_31b9:
	/* 0x31b9: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31be:
	/* 0x31be: movabs rax,0x203a646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2322278983241526901ULL);
x86_l_31c8:
	/* 0x31c8: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31cd:
	/* 0x31cd: mov    BYTE PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_31d2:
	/* 0x31d2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31d7:
	/* 0x31d7: mov    eax,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_31dc:
	/* 0x31dc: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_31e2:
	/* 0x31e2: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_31e6:
	/* 0x31e6: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_31eb:
	/* 0x31eb: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_31f0:
	/* 0x31f0: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_31f3:
	/* 0x31f3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31f5:
	/* 0x31f5: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_31f8:
	/* 0x31f8: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_31fc:
	/* 0x31fc: jle    30ba <kprobe_unwind_native+0x30ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_30ba;
	}
x86_l_3202:
	/* 0x3202: mov    rax,QWORD PTR [rsp+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_320a:
	/* 0x320a: cmp    r12d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 11ULL);
x86_l_320e:
	/* 0x320e: je     321e <kprobe_unwind_native+0x321e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_321e;
	}
x86_l_3210:
	/* 0x3210: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3218:
	/* 0x3218: cmp    r12d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 15ULL);
x86_l_321c:
	/* 0x321c: jne    3246 <kprobe_unwind_native+0x3246> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3246;
	}
x86_l_321e:
	/* 0x321e: mov    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3223:
	/* 0x3223: add    rbp,QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3226:
	/* 0x3226: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_3229:
	/* 0x3229: je     3246 <kprobe_unwind_native+0x3246> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3246;
	}
x86_l_322b:
	/* 0x322b: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_3230:
	/* 0x3230: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_3235:
	/* 0x3235: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_323a:
	/* 0x323a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_323f:
	/* 0x323f: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3242:
	/* 0x3242: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3244:
	/* 0x3244: jmp    325c <kprobe_unwind_native+0x325c> */
	goto x86_l_325c;
x86_l_3246:
	/* 0x3246: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_324b:
	/* 0x324b: cmp    BYTE PTR [rax],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_324e:
	/* 0x324e: jne    325c <kprobe_unwind_native+0x325c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_325c;
	}
x86_l_3250:
	/* 0x3250: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3255:
	/* 0x3255: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_325c:
	/* 0x325c: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_325f:
	/* 0x325f: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3264:
	/* 0x3264: je     1647 <kprobe_unwind_native+0x1647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5703ULL;
	}
x86_l_326a:
	/* 0x326a: lea    rdx,[r13-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_326e:
	/* 0x326e: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_3273:
	/* 0x3273: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_3278:
	/* 0x3278: mov    rdi,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_3280:
	/* 0x3280: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3285:
	/* 0x3285: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3287:
	/* 0x3287: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_328a:
	/* 0x328a: jne    1647 <kprobe_unwind_native+0x1647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5703ULL;
	}
x86_l_3290:
	/* 0x3290: mov    QWORD PTR [rbx+0xed8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_3297:
	/* 0x3297: mov    BYTE PTR [rbx+0xf30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16698832846849ULL);
x86_l_329e:
	/* 0x329e: mov    DWORD PTR [rsp+0x78],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075526ULL);
x86_l_32a6:
	/* 0x32a6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_32ad:
	/* 0x32ad: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_32b2:
	/* 0x32b2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32b7:
	/* 0x32b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32b9:
	/* 0x32b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32bc:
	/* 0x32bc: je     335d <kprobe_unwind_native+0x335d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_335d;
	}
x86_l_32c2:
	/* 0x32c2: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_32c5:
	/* 0x32c5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32c7:
	/* 0x32c7: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_32ce:
	/* 0x32ce: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32d1:
	/* 0x32d1: je     336f <kprobe_unwind_native+0x336f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_336f;
	}
x86_l_32d7:
	/* 0x32d7: movabs rax,0xa786c6c25203a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947156833280058ULL);
x86_l_32e1:
	/* 0x32e1: mov    QWORD PTR [rsp+0xb5],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 181ULL);
x86_l_32e9:
	/* 0x32e9: movabs rax,0x25203a706620786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675202433082226796ULL);
x86_l_32f3:
	/* 0x32f3: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_32fb:
	/* 0x32fb: movabs rax,0x6c25203a70732078 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7792670165601296504ULL);
x86_l_3305:
	/* 0x3305: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_330d:
	/* 0x330d: movabs rax,0x6c6c25203a637020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660273929744416ULL);
x86_l_3317:
	/* 0x3317: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_331f:
	/* 0x331f: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3327:
	/* 0x3327: mov    eax,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_332c:
	/* 0x332c: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_3332:
	/* 0x3332: mov    rax,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_333a:
	/* 0x333a: mov    rdx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_333d:
	/* 0x333d: mov    rcx,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3340:
	/* 0x3340: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3345:
	/* 0x3345: mov    r8,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3348:
	/* 0x3348: mov    esi,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 29ULL);
x86_l_334d:
	/* 0x334d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_334f:
	/* 0x334f: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_3352:
	/* 0x3352: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3359:
	/* 0x3359: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_335b:
	/* 0x335b: jmp    336f <kprobe_unwind_native+0x336f> */
	goto x86_l_336f;
x86_l_335d:
	/* 0x335d: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3364:
	/* 0x3364: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3367:
	/* 0x3367: jne    36d2 <kprobe_unwind_native+0x36d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14034ULL;
	}
x86_l_336d:
	/* 0x336d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_336f:
	/* 0x336f: mov    rcx,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_3377:
	/* 0x3377: mov    r13,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_337a:
	/* 0x337a: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_337d:
	/* 0x337d: je     7079 <kprobe_unwind_native+0x7079> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28793ULL;
	}
x86_l_3383:
	/* 0x3383: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3385:
	/* 0x3385: jne    3428 <kprobe_unwind_native+0x3428> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3428;
	}
x86_l_338b:
	/* 0x338b: movabs rax,0xffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72057594037927935ULL);
x86_l_3395:
	/* 0x3395: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3398:
	/* 0x3398: jbe    34d7 <kprobe_unwind_native+0x34d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_34d7;
	}
x86_l_339e:
	/* 0x339e: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_33a3:
	/* 0x33a3: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_33aa:
	/* 0x33aa: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33ad:
	/* 0x33ad: je     17a0 <kprobe_unwind_native+0x17a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6048ULL;
	}
x86_l_33b3:
	/* 0x33b3: movabs rax,0x7373657264646120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8319104478668415264ULL);
x86_l_33bd:
	/* 0x33bd: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_33c5:
	/* 0x33c5: movabs rax,0x6c656e72656b2061 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7810770566350839905ULL);
x86_l_33cf:
	/* 0x33cf: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_33d7:
	/* 0x33d7: movabs rax,0x20736920786c2520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338328219715642656ULL);
x86_l_33e1:
	/* 0x33e1: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_33e9:
	/* 0x33e9: movabs rax,0x65756c6176204350 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310868735955321680ULL);
x86_l_33f3:
	/* 0x33f3: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_33fb:
	/* 0x33fb: mov    WORD PTR [rsp+0xc0],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 824633720842ULL);
x86_l_3405:
	/* 0x3405: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_340d:
	/* 0x340d: mov    eax,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_3412:
	/* 0x3412: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3417:
	/* 0x3417: mov    esi,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 34ULL);
x86_l_341c:
	/* 0x341c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_341f:
	/* 0x341f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3421:
	/* 0x3421: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3423:
	/* 0x3423: jmp    17a0 <kprobe_unwind_native+0x17a0> */
	return 6048ULL;
x86_l_3428:
	/* 0x3428: movabs rax,0xa3d3d3d3d206425 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 737813247186461733ULL);
x86_l_3432:
	/* 0x3432: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_343a:
	/* 0x343a: movabs rax,0x20656d617266203a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334392247160021050ULL);
x86_l_3444:
	/* 0x3444: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_344c:
	/* 0x344c: movabs rax,0x7265646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243105118350175861ULL);
x86_l_3456:
	/* 0x3456: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_345e:
	/* 0x345e: movabs rax,0x20656d6172662074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334392247160021108ULL);
x86_l_3468:
	/* 0x3468: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3470:
	/* 0x3470: movabs rax,0x78656e2065766c6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8675461342619397231ULL);
x86_l_347a:
	/* 0x347a: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3482:
	/* 0x3482: movabs rax,0x736552203d3d3d3d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8315142585429343549ULL);
x86_l_348c:
	/* 0x348c: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3494:
	/* 0x3494: mov    BYTE PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_349c:
	/* 0x349c: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_34a4:
	/* 0x34a4: mov    eax,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 49ULL);
x86_l_34a9:
	/* 0x34a9: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_34ae:
	/* 0x34ae: mov    edx,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_34b4:
	/* 0x34b4: mov    esi,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 49ULL);
x86_l_34b9:
	/* 0x34b9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34bb:
	/* 0x34bb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_34bd:
	/* 0x34bd: mov    r13,QWORD PTR [rbx+0xed0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_34c4:
	/* 0x34c4: movabs rax,0xffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72057594037927935ULL);
x86_l_34ce:
	/* 0x34ce: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_34d1:
	/* 0x34d1: ja     339e <kprobe_unwind_native+0x339e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_339e;
	}
x86_l_34d7:
	/* 0x34d7: cmp    r13,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4096ULL);
x86_l_34de:
	/* 0x34de: jae    3564 <kprobe_unwind_native+0x3564> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3564;
	}
x86_l_34e4:
	/* 0x34e4: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_34e9:
	/* 0x34e9: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_34f0:
	/* 0x34f0: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34f3:
	/* 0x34f3: je     18f2 <kprobe_unwind_native+0x18f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6386ULL;
	}
x86_l_34f9:
	/* 0x34f9: movabs rax,0xa676e69726f6e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2928473680277358ULL);
x86_l_3503:
	/* 0x3503: mov    QWORD PTR [rsp+0xb6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_350b:
	/* 0x350b: movabs rax,0x6f6e6769202c786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8029468886857185388ULL);
x86_l_3515:
	/* 0x3515: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_351d:
	/* 0x351d: movabs rax,0x252065756c617620 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675249733661980192ULL);
x86_l_3527:
	/* 0x3527: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_352f:
	/* 0x352f: movabs rax,0x6370206c6c616d73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7165262657193340275ULL);
x86_l_3539:
	/* 0x3539: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3541:
	/* 0x3541: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3549:
	/* 0x3549: mov    eax,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 30ULL);
x86_l_354e:
	/* 0x354e: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3553:
	/* 0x3553: mov    esi,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 30ULL);
x86_l_3558:
	/* 0x3558: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_355b:
	/* 0x355b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_355d:
	/* 0x355d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_355f:
	/* 0x355f: jmp    18f2 <kprobe_unwind_native+0x18f2> */
	return 6386ULL;
x86_l_3564:
	/* 0x3564: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3566:
	/* 0x3566: mov    DWORD PTR [rsp+0x10],0x60 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476832ULL);
x86_l_356e:
	/* 0x356e: movbe  DWORD PTR [rsp+0x14],eax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_3574:
	/* 0x3574: movbe  QWORD PTR [rsp+0x18],r13 */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_357b:
	/* 0x357b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_page_to_mapping_info)));
x86_l_3582:
	/* 0x3582: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3587:
	/* 0x3587: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_358c:
	/* 0x358c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_358e:
	/* 0x358e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
	return 13713ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13713ULL: goto x86_l_3591;
	case 13719ULL: goto x86_l_3597;
	case 13723ULL: goto x86_l_359b;
	case 13726ULL: goto x86_l_359e;
	case 13736ULL: goto x86_l_35a8;
	case 13739ULL: goto x86_l_35ab;
	case 13746ULL: goto x86_l_35b2;
	case 13749ULL: goto x86_l_35b5;
	case 13756ULL: goto x86_l_35bc;
	case 13760ULL: goto x86_l_35c0;
	case 13763ULL: goto x86_l_35c3;
	case 13766ULL: goto x86_l_35c6;
	case 13773ULL: goto x86_l_35cd;
	case 13780ULL: goto x86_l_35d4;
	case 13783ULL: goto x86_l_35d7;
	case 13789ULL: goto x86_l_35dd;
	case 13793ULL: goto x86_l_35e1;
	case 13799ULL: goto x86_l_35e7;
	case 13806ULL: goto x86_l_35ee;
	case 13811ULL: goto x86_l_35f3;
	case 13818ULL: goto x86_l_35fa;
	case 13825ULL: goto x86_l_3601;
	case 13830ULL: goto x86_l_3606;
	case 13835ULL: goto x86_l_360b;
	case 13837ULL: goto x86_l_360d;
	case 13843ULL: goto x86_l_3613;
	case 13846ULL: goto x86_l_3616;
	case 13852ULL: goto x86_l_361c;
	case 13855ULL: goto x86_l_361f;
	case 13858ULL: goto x86_l_3622;
	case 13860ULL: goto x86_l_3624;
	case 13864ULL: goto x86_l_3628;
	case 13866ULL: goto x86_l_362a;
	case 13870ULL: goto x86_l_362e;
	case 13876ULL: goto x86_l_3634;
	case 13880ULL: goto x86_l_3638;
	case 13886ULL: goto x86_l_363e;
	case 13893ULL: goto x86_l_3645;
	case 13896ULL: goto x86_l_3648;
	case 13902ULL: goto x86_l_364e;
	case 13908ULL: goto x86_l_3654;
	case 13912ULL: goto x86_l_3658;
	case 13915ULL: goto x86_l_365b;
	case 13921ULL: goto x86_l_3661;
	case 13928ULL: goto x86_l_3668;
	case 13931ULL: goto x86_l_366b;
	case 13937ULL: goto x86_l_3671;
	case 13947ULL: goto x86_l_367b;
	case 13955ULL: goto x86_l_3683;
	case 13965ULL: goto x86_l_368d;
	case 13973ULL: goto x86_l_3695;
	case 13983ULL: goto x86_l_369f;
	case 13991ULL: goto x86_l_36a7;
	case 14002ULL: goto x86_l_36b2;
	case 14010ULL: goto x86_l_36ba;
	case 14015ULL: goto x86_l_36bf;
	case 14020ULL: goto x86_l_36c4;
	case 14025ULL: goto x86_l_36c9;
	case 14027ULL: goto x86_l_36cb;
	case 14029ULL: goto x86_l_36cd;
	case 14034ULL: goto x86_l_36d2;
	case 14044ULL: goto x86_l_36dc;
	case 14049ULL: goto x86_l_36e1;
	case 14059ULL: goto x86_l_36eb;
	case 14064ULL: goto x86_l_36f0;
	case 14074ULL: goto x86_l_36fa;
	case 14079ULL: goto x86_l_36ff;
	case 14089ULL: goto x86_l_3709;
	case 14094ULL: goto x86_l_370e;
	case 14104ULL: goto x86_l_3718;
	case 14109ULL: goto x86_l_371d;
	case 14119ULL: goto x86_l_3727;
	case 14124ULL: goto x86_l_372c;
	case 14129ULL: goto x86_l_3731;
	case 14134ULL: goto x86_l_3736;
	case 14139ULL: goto x86_l_373b;
	case 14143ULL: goto x86_l_373f;
	case 14148ULL: goto x86_l_3744;
	case 14150ULL: goto x86_l_3746;
	case 14152ULL: goto x86_l_3748;
	case 14154ULL: goto x86_l_374a;
	case 14161ULL: goto x86_l_3751;
	case 14164ULL: goto x86_l_3754;
	case 14170ULL: goto x86_l_375a;
	case 14175ULL: goto x86_l_375f;
	case 14185ULL: goto x86_l_3769;
	case 14190ULL: goto x86_l_376e;
	case 14200ULL: goto x86_l_3778;
	case 14205ULL: goto x86_l_377d;
	case 14215ULL: goto x86_l_3787;
	case 14220ULL: goto x86_l_378c;
	case 14230ULL: goto x86_l_3796;
	case 14235ULL: goto x86_l_379b;
	case 14245ULL: goto x86_l_37a5;
	case 14250ULL: goto x86_l_37aa;
	case 14258ULL: goto x86_l_37b2;
	case 14263ULL: goto x86_l_37b7;
	case 14268ULL: goto x86_l_37bc;
	case 14273ULL: goto x86_l_37c1;
	case 14278ULL: goto x86_l_37c6;
	case 14281ULL: goto x86_l_37c9;
	case 14283ULL: goto x86_l_37cb;
	case 14285ULL: goto x86_l_37cd;
	case 14288ULL: goto x86_l_37d0;
	case 14293ULL: goto x86_l_37d5;
	case 14303ULL: goto x86_l_37df;
	case 14311ULL: goto x86_l_37e7;
	case 14321ULL: goto x86_l_37f1;
	case 14329ULL: goto x86_l_37f9;
	case 14339ULL: goto x86_l_3803;
	case 14347ULL: goto x86_l_380b;
	case 14357ULL: goto x86_l_3815;
	case 14365ULL: goto x86_l_381d;
	case 14375ULL: goto x86_l_3827;
	case 14383ULL: goto x86_l_382f;
	case 14393ULL: goto x86_l_3839;
	case 14401ULL: goto x86_l_3841;
	case 14411ULL: goto x86_l_384b;
	case 14419ULL: goto x86_l_3853;
	case 14424ULL: goto x86_l_3858;
	case 14430ULL: goto x86_l_385e;
	case 14437ULL: goto x86_l_3865;
	case 14442ULL: goto x86_l_386a;
	case 14445ULL: goto x86_l_386d;
	case 14448ULL: goto x86_l_3870;
	case 14450ULL: goto x86_l_3872;
	case 14453ULL: goto x86_l_3875;
	case 14460ULL: goto x86_l_387c;
	case 14463ULL: goto x86_l_387f;
	case 14469ULL: goto x86_l_3885;
	case 14479ULL: goto x86_l_388f;
	case 14487ULL: goto x86_l_3897;
	case 14497ULL: goto x86_l_38a1;
	case 14505ULL: goto x86_l_38a9;
	case 14515ULL: goto x86_l_38b3;
	case 14523ULL: goto x86_l_38bb;
	case 14533ULL: goto x86_l_38c5;
	case 14541ULL: goto x86_l_38cd;
	case 14551ULL: goto x86_l_38d7;
	case 14559ULL: goto x86_l_38df;
	case 14567ULL: goto x86_l_38e7;
	case 14575ULL: goto x86_l_38ef;
	case 14580ULL: goto x86_l_38f4;
	case 14586ULL: goto x86_l_38fa;
	case 14593ULL: goto x86_l_3901;
	case 14600ULL: goto x86_l_3908;
	case 14605ULL: goto x86_l_390d;
	case 14607ULL: goto x86_l_390f;
	case 14610ULL: goto x86_l_3912;
	case 14615ULL: goto x86_l_3917;
	case 14625ULL: goto x86_l_3921;
	case 14633ULL: goto x86_l_3929;
	case 14643ULL: goto x86_l_3933;
	case 14651ULL: goto x86_l_393b;
	case 14661ULL: goto x86_l_3945;
	case 14669ULL: goto x86_l_394d;
	case 14679ULL: goto x86_l_3957;
	case 14687ULL: goto x86_l_395f;
	case 14695ULL: goto x86_l_3967;
	case 14700ULL: goto x86_l_396c;
	case 14705ULL: goto x86_l_3971;
	case 14710ULL: goto x86_l_3976;
	case 14715ULL: goto x86_l_397b;
	case 14717ULL: goto x86_l_397d;
	case 14719ULL: goto x86_l_397f;
	case 14725ULL: goto x86_l_3985;
	case 14729ULL: goto x86_l_3989;
	case 14732ULL: goto x86_l_398c;
	case 14738ULL: goto x86_l_3992;
	case 14746ULL: goto x86_l_399a;
	case 14753ULL: goto x86_l_39a1;
	case 14758ULL: goto x86_l_39a6;
	case 14763ULL: goto x86_l_39ab;
	case 14765ULL: goto x86_l_39ad;
	case 14768ULL: goto x86_l_39b0;
	case 14770ULL: goto x86_l_39b2;
	case 14773ULL: goto x86_l_39b5;
	case 14775ULL: goto x86_l_39b7;
	case 14782ULL: goto x86_l_39be;
	case 14785ULL: goto x86_l_39c1;
	case 14791ULL: goto x86_l_39c7;
	case 14796ULL: goto x86_l_39cc;
	case 14800ULL: goto x86_l_39d0;
	case 14806ULL: goto x86_l_39d6;
	case 14813ULL: goto x86_l_39dd;
	case 14816ULL: goto x86_l_39e0;
	case 14822ULL: goto x86_l_39e6;
	case 14830ULL: goto x86_l_39ee;
	case 14837ULL: goto x86_l_39f5;
	case 14842ULL: goto x86_l_39fa;
	case 14847ULL: goto x86_l_39ff;
	case 14849ULL: goto x86_l_3a01;
	case 14852ULL: goto x86_l_3a04;
	case 14858ULL: goto x86_l_3a0a;
	case 14861ULL: goto x86_l_3a0d;
	case 14868ULL: goto x86_l_3a14;
	case 14871ULL: goto x86_l_3a17;
	case 14877ULL: goto x86_l_3a1d;
	case 14887ULL: goto x86_l_3a27;
	case 14895ULL: goto x86_l_3a2f;
	case 14905ULL: goto x86_l_3a39;
	case 14913ULL: goto x86_l_3a41;
	case 14923ULL: goto x86_l_3a4b;
	case 14931ULL: goto x86_l_3a53;
	case 14941ULL: goto x86_l_3a5d;
	case 14949ULL: goto x86_l_3a65;
	case 14959ULL: goto x86_l_3a6f;
	case 14967ULL: goto x86_l_3a77;
	case 14978ULL: goto x86_l_3a82;
	case 14986ULL: goto x86_l_3a8a;
	case 14991ULL: goto x86_l_3a8f;
	case 14997ULL: goto x86_l_3a95;
	case 15004ULL: goto x86_l_3a9c;
	case 15011ULL: goto x86_l_3aa3;
	case 15018ULL: goto x86_l_3aaa;
	case 15023ULL: goto x86_l_3aaf;
	case 15025ULL: goto x86_l_3ab1;
	case 15028ULL: goto x86_l_3ab4;
	case 15030ULL: goto x86_l_3ab6;
	case 15037ULL: goto x86_l_3abd;
	case 15040ULL: goto x86_l_3ac0;
	case 15046ULL: goto x86_l_3ac6;
	case 15052ULL: goto x86_l_3acc;
	case 15056ULL: goto x86_l_3ad0;
	case 15061ULL: goto x86_l_3ad5;
	case 15068ULL: goto x86_l_3adc;
	case 15074ULL: goto x86_l_3ae2;
	case 15081ULL: goto x86_l_3ae9;
	case 15088ULL: goto x86_l_3af0;
	case 15095ULL: goto x86_l_3af7;
	case 15098ULL: goto x86_l_3afa;
	case 15104ULL: goto x86_l_3b00;
	case 15108ULL: goto x86_l_3b04;
	case 15116ULL: goto x86_l_3b0c;
	case 15124ULL: goto x86_l_3b14;
	case 15132ULL: goto x86_l_3b1c;
	case 15139ULL: goto x86_l_3b23;
	case 15150ULL: goto x86_l_3b2e;
	case 15160ULL: goto x86_l_3b38;
	case 15171ULL: goto x86_l_3b43;
	case 15178ULL: goto x86_l_3b4a;
	case 15186ULL: goto x86_l_3b52;
	case 15191ULL: goto x86_l_3b57;
	case 15198ULL: goto x86_l_3b5e;
	case 15205ULL: goto x86_l_3b65;
	case 15213ULL: goto x86_l_3b6d;
	case 15218ULL: goto x86_l_3b72;
	case 15224ULL: goto x86_l_3b78;
	case 15231ULL: goto x86_l_3b7f;
	case 15236ULL: goto x86_l_3b84;
	case 15241ULL: goto x86_l_3b89;
	case 15243ULL: goto x86_l_3b8b;
	case 15248ULL: goto x86_l_3b90;
	case 15251ULL: goto x86_l_3b93;
	case 15256ULL: goto x86_l_3b98;
	case 15263ULL: goto x86_l_3b9f;
	case 15269ULL: goto x86_l_3ba5;
	case 15274ULL: goto x86_l_3baa;
	case 15277ULL: goto x86_l_3bad;
	case 15281ULL: goto x86_l_3bb1;
	case 15285ULL: goto x86_l_3bb5;
	case 15288ULL: goto x86_l_3bb8;
	case 15290ULL: goto x86_l_3bba;
	case 15293ULL: goto x86_l_3bbd;
	case 15295ULL: goto x86_l_3bbf;
	case 15298ULL: goto x86_l_3bc2;
	case 15304ULL: goto x86_l_3bc8;
	case 15307ULL: goto x86_l_3bcb;
	case 15313ULL: goto x86_l_3bd1;
	case 15316ULL: goto x86_l_3bd4;
	case 15322ULL: goto x86_l_3bda;
	case 15329ULL: goto x86_l_3be1;
	case 15334ULL: goto x86_l_3be6;
	case 15337ULL: goto x86_l_3be9;
	case 15339ULL: goto x86_l_3beb;
	case 15342ULL: goto x86_l_3bee;
	case 15348ULL: goto x86_l_3bf4;
	case 15351ULL: goto x86_l_3bf7;
	case 15357ULL: goto x86_l_3bfd;
	case 15360ULL: goto x86_l_3c00;
	case 15366ULL: goto x86_l_3c06;
	case 15373ULL: goto x86_l_3c0d;
	case 15378ULL: goto x86_l_3c12;
	case 15381ULL: goto x86_l_3c15;
	case 15383ULL: goto x86_l_3c17;
	case 15386ULL: goto x86_l_3c1a;
	case 15392ULL: goto x86_l_3c20;
	case 15395ULL: goto x86_l_3c23;
	case 15401ULL: goto x86_l_3c29;
	case 15408ULL: goto x86_l_3c30;
	case 15413ULL: goto x86_l_3c35;
	case 15416ULL: goto x86_l_3c38;
	case 15418ULL: goto x86_l_3c3a;
	case 15421ULL: goto x86_l_3c3d;
	case 15427ULL: goto x86_l_3c43;
	case 15430ULL: goto x86_l_3c46;
	case 15436ULL: goto x86_l_3c4c;
	case 15443ULL: goto x86_l_3c53;
	case 15448ULL: goto x86_l_3c58;
	case 15451ULL: goto x86_l_3c5b;
	case 15457ULL: goto x86_l_3c61;
	case 15460ULL: goto x86_l_3c64;
	case 15466ULL: goto x86_l_3c6a;
	case 15473ULL: goto x86_l_3c71;
	case 15478ULL: goto x86_l_3c76;
	case 15481ULL: goto x86_l_3c79;
	case 15483ULL: goto x86_l_3c7b;
	case 15486ULL: goto x86_l_3c7e;
	case 15492ULL: goto x86_l_3c84;
	case 15499ULL: goto x86_l_3c8b;
	case 15501ULL: goto x86_l_3c8d;
	case 15504ULL: goto x86_l_3c90;
	case 15506ULL: goto x86_l_3c92;
	case 15509ULL: goto x86_l_3c95;
	case 15515ULL: goto x86_l_3c9b;
	case 15522ULL: goto x86_l_3ca2;
	case 15524ULL: goto x86_l_3ca4;
	case 15527ULL: goto x86_l_3ca7;
	case 15529ULL: goto x86_l_3ca9;
	case 15532ULL: goto x86_l_3cac;
	case 15538ULL: goto x86_l_3cb2;
	case 15545ULL: goto x86_l_3cb9;
	case 15547ULL: goto x86_l_3cbb;
	case 15554ULL: goto x86_l_3cc2;
	case 15556ULL: goto x86_l_3cc4;
	case 15563ULL: goto x86_l_3ccb;
	case 15565ULL: goto x86_l_3ccd;
	case 15572ULL: goto x86_l_3cd4;
	case 15574ULL: goto x86_l_3cd6;
	case 15581ULL: goto x86_l_3cdd;
	case 15583ULL: goto x86_l_3cdf;
	case 15590ULL: goto x86_l_3ce6;
	case 15592ULL: goto x86_l_3ce8;
	case 15599ULL: goto x86_l_3cef;
	case 15601ULL: goto x86_l_3cf1;
	case 15608ULL: goto x86_l_3cf8;
	case 15610ULL: goto x86_l_3cfa;
	case 15617ULL: goto x86_l_3d01;
	case 15625ULL: goto x86_l_3d09;
	case 15630ULL: goto x86_l_3d0e;
	case 15632ULL: goto x86_l_3d10;
	case 15637ULL: goto x86_l_3d15;
	case 15640ULL: goto x86_l_3d18;
	case 15646ULL: goto x86_l_3d1e;
	case 15651ULL: goto x86_l_3d23;
	case 15654ULL: goto x86_l_3d26;
	case 15662ULL: goto x86_l_3d2e;
	case 15669ULL: goto x86_l_3d35;
	case 15674ULL: goto x86_l_3d3a;
	case 15678ULL: goto x86_l_3d3e;
	case 15680ULL: goto x86_l_3d40;
	case 15686ULL: goto x86_l_3d46;
	case 15689ULL: goto x86_l_3d49;
	case 15692ULL: goto x86_l_3d4c;
	case 15699ULL: goto x86_l_3d53;
	case 15702ULL: goto x86_l_3d56;
	case 15708ULL: goto x86_l_3d5c;
	case 15712ULL: goto x86_l_3d60;
	case 15714ULL: goto x86_l_3d62;
	case 15718ULL: goto x86_l_3d66;
	case 15723ULL: goto x86_l_3d6b;
	case 15728ULL: goto x86_l_3d70;
	case 15733ULL: goto x86_l_3d75;
	case 15735ULL: goto x86_l_3d77;
	case 15738ULL: goto x86_l_3d7a;
	case 15744ULL: goto x86_l_3d80;
	case 15748ULL: goto x86_l_3d84;
	case 15751ULL: goto x86_l_3d87;
	case 15756ULL: goto x86_l_3d8c;
	case 15759ULL: goto x86_l_3d8f;
	case 15763ULL: goto x86_l_3d93;
	case 15767ULL: goto x86_l_3d97;
	case 15771ULL: goto x86_l_3d9b;
	case 15774ULL: goto x86_l_3d9e;
	case 15780ULL: goto x86_l_3da4;
	case 15784ULL: goto x86_l_3da8;
	case 15786ULL: goto x86_l_3daa;
	case 15788ULL: goto x86_l_3dac;
	case 15792ULL: goto x86_l_3db0;
	case 15797ULL: goto x86_l_3db5;
	case 15802ULL: goto x86_l_3dba;
	case 15807ULL: goto x86_l_3dbf;
	case 15809ULL: goto x86_l_3dc1;
	case 15812ULL: goto x86_l_3dc4;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3591:
	/* 0x3591: je     7135 <kprobe_unwind_native+0x7135> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28981ULL;
	}
x86_l_3597:
	/* 0x3597: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_359b:
	/* 0x359b: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_359e:
	/* 0x359e: movabs rdx,0xffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 72057594037927935ULL);
x86_l_35a8:
	/* 0x35a8: and    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_AND);
x86_l_35ab:
	/* 0x35ab: mov    QWORD PTR [rbx+0xf20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3872ULL);
x86_l_35b2:
	/* 0x35b2: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35b5:
	/* 0x35b5: mov    QWORD PTR [rbx+0xf10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_35bc:
	/* 0x35bc: shr    r12,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_35c0:
	/* 0x35c0: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_35c3:
	/* 0x35c3: sub    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_35c6:
	/* 0x35c6: mov    QWORD PTR [rbx+0xf18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_35cd:
	/* 0x35cd: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_35d4:
	/* 0x35d4: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35d7:
	/* 0x35d7: jne    37d5 <kprobe_unwind_native+0x37d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_37d5;
	}
x86_l_35dd:
	/* 0x35dd: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_35e1:
	/* 0x35e1: jne    39cc <kprobe_unwind_native+0x39cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_39cc;
	}
x86_l_35e7:
	/* 0x35e7: mov    rax,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_35ee:
	/* 0x35ee: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35f3:
	/* 0x35f3: mov    rbp,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_35fa:
	/* 0x35fa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&interpreter_offsets)));
x86_l_3601:
	/* 0x3601: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3606:
	/* 0x3606: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_360b:
	/* 0x360b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_360d:
	/* 0x360d: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_3613:
	/* 0x3613: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3616:
	/* 0x3616: je     39cc <kprobe_unwind_native+0x39cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39cc;
	}
x86_l_361c:
	/* 0x361c: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_361f:
	/* 0x361f: cmp    QWORD PTR [rax],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3622:
	/* 0x3622: ja     362a <kprobe_unwind_native+0x362a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_362a;
	}
x86_l_3624:
	/* 0x3624: cmp    QWORD PTR [r13+0x8],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3628:
	/* 0x3628: jae    363e <kprobe_unwind_native+0x363e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_363e;
	}
x86_l_362a:
	/* 0x362a: cmp    QWORD PTR [r13+0x10],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_362e:
	/* 0x362e: ja     39cc <kprobe_unwind_native+0x39cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_39cc;
	}
x86_l_3634:
	/* 0x3634: cmp    QWORD PTR [r13+0x18],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3638:
	/* 0x3638: jb     39cc <kprobe_unwind_native+0x39cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_39cc;
	}
x86_l_363e:
	/* 0x363e: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3645:
	/* 0x3645: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3648:
	/* 0x3648: jne    3917 <kprobe_unwind_native+0x3917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3917;
	}
x86_l_364e:
	/* 0x364e: mov    eax,DWORD PTR [rbx+0x1380] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4992ULL);
x86_l_3654:
	/* 0x3654: mov    ecx,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3658:
	/* 0x3658: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_365b:
	/* 0x365b: jae    3992 <kprobe_unwind_native+0x3992> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3992;
	}
x86_l_3661:
	/* 0x3661: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3668:
	/* 0x3668: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_366b:
	/* 0x366b: je     39cc <kprobe_unwind_native+0x39cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39cc;
	}
x86_l_3671:
	/* 0x3671: movabs rax,0x6e6f64207265646e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7957689157107934318ULL);
x86_l_367b:
	/* 0x367b: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3683:
	/* 0x3683: movabs rax,0x69776e7520726574 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7599664345545598324ULL);
x86_l_368d:
	/* 0x368d: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3695:
	/* 0x3695: movabs rax,0x6572707265746e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310028781806448233ULL);
x86_l_369f:
	/* 0x369f: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_36a7:
	/* 0x36a7: mov    DWORD PTR [rsp+0xb7],0xa656e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 785979696494ULL);
x86_l_36b2:
	/* 0x36b2: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_36ba:
	/* 0x36ba: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_36bf:
	/* 0x36bf: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_36c4:
	/* 0x36c4: mov    esi,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 27ULL);
x86_l_36c9:
	/* 0x36c9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36cb:
	/* 0x36cb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_36cd:
	/* 0x36cd: jmp    39cc <kprobe_unwind_native+0x39cc> */
	goto x86_l_39cc;
x86_l_36d2:
	/* 0x36d2: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_36dc:
	/* 0x36dc: mov    QWORD PTR [rsp+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_36e1:
	/* 0x36e1: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_36eb:
	/* 0x36eb: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_36f0:
	/* 0x36f0: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_36fa:
	/* 0x36fa: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_36ff:
	/* 0x36ff: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_3709:
	/* 0x3709: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_370e:
	/* 0x370e: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_3718:
	/* 0x3718: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_371d:
	/* 0x371d: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_3727:
	/* 0x3727: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_372c:
	/* 0x372c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3731:
	/* 0x3731: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_3736:
	/* 0x3736: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_373b:
	/* 0x373b: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_373f:
	/* 0x373f: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_3744:
	/* 0x3744: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3746:
	/* 0x3746: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3748:
	/* 0x3748: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_374a:
	/* 0x374a: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3751:
	/* 0x3751: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3754:
	/* 0x3754: je     336f <kprobe_unwind_native+0x336f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13167ULL;
	}
x86_l_375a:
	/* 0x375a: jmp    32d7 <kprobe_unwind_native+0x32d7> */
	return 13015ULL;
x86_l_375f:
	/* 0x375f: movabs rax,0x2578302073736572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2699960892542641522ULL);
x86_l_3769:
	/* 0x3769: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_376e:
	/* 0x376e: movabs rax,0x6464612065636e65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7234013693231722085ULL);
x86_l_3778:
	/* 0x3778: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_377d:
	/* 0x377d: movabs rax,0x7265666572656420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243107278868538400ULL);
x86_l_3787:
	/* 0x3787: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_378c:
	/* 0x378c: movabs rax,0x6f742064656c6961 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8031079651078859105ULL);
x86_l_3796:
	/* 0x3796: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_379b:
	/* 0x379b: movabs rax,0x6620646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358992216502005365ULL);
x86_l_37a5:
	/* 0x37a5: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37aa:
	/* 0x37aa: mov    DWORD PTR [rsp+0x38],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518854764ULL);
x86_l_37b2:
	/* 0x37b2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37b7:
	/* 0x37b7: mov    eax,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_37bc:
	/* 0x37bc: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_37c1:
	/* 0x37c1: mov    esi,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_37c6:
	/* 0x37c6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_37c9:
	/* 0x37c9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37cb:
	/* 0x37cb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_37cd:
	/* 0x37cd: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37d0:
	/* 0x37d0: jmp    3047 <kprobe_unwind_native+0x3047> */
	return 12359ULL;
x86_l_37d5:
	/* 0x37d5: movabs rax,0x296425207265646e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2982549674514539630ULL);
x86_l_37df:
	/* 0x37df: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_37e7:
	/* 0x37e7: movabs rax,0x69776e752820786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7599664345674446956ULL);
x86_l_37f1:
	/* 0x37f1: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_37f9:
	/* 0x37f9: movabs rax,0x6c2520736920786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7792670410291574892ULL);
x86_l_3803:
	/* 0x3803: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_380b:
	/* 0x380b: movabs rax,0x2520435020726f66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675212190078889830ULL);
x86_l_3815:
	/* 0x3815: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_381d:
	/* 0x381d: movabs rax,0x206469206e6f6974 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334106094897424756ULL);
x86_l_3827:
	/* 0x3827: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_382f:
	/* 0x382f: movabs rbp,0x6365732074786554 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 7162257365632836948ULL);
x86_l_3839:
	/* 0x3839: mov    QWORD PTR [rsp+0xa0],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3841:
	/* 0x3841: mov    WORD PTR [rsp+0xd0],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 893353197578ULL);
x86_l_384b:
	/* 0x384b: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3853:
	/* 0x3853: mov    eax,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_3858:
	/* 0x3858: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_385e:
	/* 0x385e: mov    rcx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_3865:
	/* 0x3865: mov    esi,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 50ULL);
x86_l_386a:
	/* 0x386a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_386d:
	/* 0x386d: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_3870:
	/* 0x3870: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3872:
	/* 0x3872: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_3875:
	/* 0x3875: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_387c:
	/* 0x387c: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_387f:
	/* 0x387f: je     35dd <kprobe_unwind_native+0x35dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35dd;
	}
x86_l_3885:
	/* 0x3885: movabs rax,0xa786c6c252073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947156833280115ULL);
x86_l_388f:
	/* 0x388f: mov    QWORD PTR [rsp+0xc7],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 199ULL);
x86_l_3897:
	/* 0x3897: movabs rax,0x7369207465736666 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8316213871206688358ULL);
x86_l_38a1:
	/* 0x38a1: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_38a9:
	/* 0x38a9: movabs rax,0x6f20646e61202c78 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8007510562703420536ULL);
x86_l_38b3:
	/* 0x38b3: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_38bb:
	/* 0x38bb: movabs rax,0x6c6c252073692073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660274886418547ULL);
x86_l_38c5:
	/* 0x38c5: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_38cd:
	/* 0x38cd: movabs rax,0x616962206e6f6974 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7019249385664899444ULL);
x86_l_38d7:
	/* 0x38d7: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_38df:
	/* 0x38df: mov    QWORD PTR [rsp+0xa0],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_38e7:
	/* 0x38e7: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_38ef:
	/* 0x38ef: mov    eax,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 47ULL);
x86_l_38f4:
	/* 0x38f4: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_38fa:
	/* 0x38fa: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_3901:
	/* 0x3901: mov    rdx,QWORD PTR [rbx+0xf20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3872ULL);
x86_l_3908:
	/* 0x3908: mov    esi,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 47ULL);
x86_l_390d:
	/* 0x390d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_390f:
	/* 0x390f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3912:
	/* 0x3912: jmp    35dd <kprobe_unwind_native+0x35dd> */
	goto x86_l_35dd;
x86_l_3917:
	/* 0x3917: movabs rax,0xa642520686374 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860387386228ULL);
x86_l_3921:
	/* 0x3921: mov    QWORD PTR [rsp+0xb6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_3929:
	/* 0x3929: movabs rax,0x6374616d20737465 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7166460028377068645ULL);
x86_l_3933:
	/* 0x3933: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_393b:
	/* 0x393b: movabs rax,0x7366666f5f726574 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8315446390514935156ULL);
x86_l_3945:
	/* 0x3945: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_394d:
	/* 0x394d: movabs rax,0x6572707265746e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310028781806448233ULL);
x86_l_3957:
	/* 0x3957: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_395f:
	/* 0x395f: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3967:
	/* 0x3967: mov    eax,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 30ULL);
x86_l_396c:
	/* 0x396c: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3971:
	/* 0x3971: movzx  edx,WORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_3976:
	/* 0x3976: mov    esi,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 30ULL);
x86_l_397b:
	/* 0x397b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_397d:
	/* 0x397d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_397f:
	/* 0x397f: mov    eax,DWORD PTR [rbx+0x1380] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4992ULL);
x86_l_3985:
	/* 0x3985: mov    ecx,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3989:
	/* 0x3989: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_398c:
	/* 0x398c: jb     3661 <kprobe_unwind_native+0x3661> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3661;
	}
x86_l_3992:
	/* 0x3992: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_399a:
	/* 0x399a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_39a1:
	/* 0x39a1: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_39a6:
	/* 0x39a6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_39ab:
	/* 0x39ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39ad:
	/* 0x39ad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_39b0:
	/* 0x39b0: je     39b7 <kprobe_unwind_native+0x39b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39b7;
	}
x86_l_39b2:
	/* 0x39b2: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_39b5:
	/* 0x39b5: jmp    39c7 <kprobe_unwind_native+0x39c7> */
	goto x86_l_39c7;
x86_l_39b7:
	/* 0x39b7: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_39be:
	/* 0x39be: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39c1:
	/* 0x39c1: jne    49aa <kprobe_unwind_native+0x49aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18858ULL;
	}
x86_l_39c7:
	/* 0x39c7: movzx  r12d,WORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_39cc:
	/* 0x39cc: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_39d0:
	/* 0x39d0: jne    75bf <kprobe_unwind_native+0x75bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 30143ULL;
	}
x86_l_39d6:
	/* 0x39d6: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_39dd:
	/* 0x39dd: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39e0:
	/* 0x39e0: jne    4728 <kprobe_unwind_native+0x4728> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18216ULL;
	}
x86_l_39e6:
	/* 0x39e6: mov    DWORD PTR [rsp+0x10],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476741ULL);
x86_l_39ee:
	/* 0x39ee: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_39f5:
	/* 0x39f5: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39fa:
	/* 0x39fa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_39ff:
	/* 0x39ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a01:
	/* 0x3a01: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a04:
	/* 0x3a04: je     3ab6 <kprobe_unwind_native+0x3ab6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ab6;
	}
x86_l_3a0a:
	/* 0x3a0a: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3a0d:
	/* 0x3a0d: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3a14:
	/* 0x3a14: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a17:
	/* 0x3a17: je     3ac6 <kprobe_unwind_native+0x3ac6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ac6;
	}
x86_l_3a1d:
	/* 0x3a1d: movabs rax,0x63617473206e6f20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7161132920309968672ULL);
x86_l_3a27:
	/* 0x3a27: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_3a2f:
	/* 0x3a2f: movabs rax,0x7525206e6f697469 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8441188735263536233ULL);
x86_l_3a39:
	/* 0x3a39: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3a41:
	/* 0x3a41: movabs rax,0x736f70206f742078 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8317990321387741304ULL);
x86_l_3a4b:
	/* 0x3a4b: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3a53:
	/* 0x3a53: movabs rax,0x6c6c2520786c6c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660274970520613ULL);
x86_l_3a5d:
	/* 0x3a5d: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3a65:
	/* 0x3a65: movabs rax,0x20676e6968737550 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334956330817910096ULL);
x86_l_3a6f:
	/* 0x3a6f: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3a77:
	/* 0x3a77: mov    DWORD PTR [rsp+0xc7],0xa6b63 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 854699174755ULL);
x86_l_3a82:
	/* 0x3a82: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3a8a:
	/* 0x3a8a: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_3a8f:
	/* 0x3a8f: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_3a95:
	/* 0x3a95: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_3a9c:
	/* 0x3a9c: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_3aa3:
	/* 0x3aa3: mov    r8d,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3aaa:
	/* 0x3aaa: mov    esi,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 43ULL);
x86_l_3aaf:
	/* 0x3aaf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ab1:
	/* 0x3ab1: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_3ab4:
	/* 0x3ab4: jmp    3ac6 <kprobe_unwind_native+0x3ac6> */
	goto x86_l_3ac6;
x86_l_3ab6:
	/* 0x3ab6: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3abd:
	/* 0x3abd: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ac0:
	/* 0x3ac0: jne    47fd <kprobe_unwind_native+0x47fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18429ULL;
	}
x86_l_3ac6:
	/* 0x3ac6: mov    eax,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3acc:
	/* 0x3acc: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_3ad0:
	/* 0x3ad0: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3ad5:
	/* 0x3ad5: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3adc:
	/* 0x3adc: ja     141 <kprobe_unwind_native+0x141> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 321ULL;
	}
x86_l_3ae2:
	/* 0x3ae2: movzx  ecx,BYTE PTR [rbx+0xf30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3888ULL);
x86_l_3ae9:
	/* 0x3ae9: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_3af0:
	/* 0x3af0: mov    rsi,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_3af7:
	/* 0x3af7: lea    edi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3afa:
	/* 0x3afa: mov    DWORD PTR [rbx+0x2c0],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3b00:
	/* 0x3b00: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_3b04:
	/* 0x3b04: mov    QWORD PTR [rbx+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_3b0c:
	/* 0x3b0c: mov    QWORD PTR [rbx+rax*8+0x2d8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_3b14:
	/* 0x3b14: mov    BYTE PTR [rbx+rax*8+0x2e0],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 3161095929859ULL);
x86_l_3b1c:
	/* 0x3b1c: mov    BYTE PTR [rbx+rax*8+0x2e1],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 737ULL);
x86_l_3b23:
	/* 0x3b23: mov    DWORD PTR [rbx+rax*8+0x2e2],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3169685864448ULL);
x86_l_3b2e:
	/* 0x3b2e: mov    WORD PTR [rbx+rax*8+0x2e6],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3186865733632ULL);
x86_l_3b38:
	/* 0x3b38: mov    DWORD PTR [rsp+0x8c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_3b43:
	/* 0x3b43: mov    rax,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_3b4a:
	/* 0x3b4a: mov    QWORD PTR [rsp+0x160],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_3b52:
	/* 0x3b52: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3b57:
	/* 0x3b57: mov    rax,0xffffffffffff0000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 18446744073709486080ULL);
x86_l_3b5e:
	/* 0x3b5e: and    rax,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 3864ULL);
x86_l_3b65:
	/* 0x3b65: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3b6d:
	/* 0x3b6d: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b72:
	/* 0x3b72: jne    478f <kprobe_unwind_native+0x478f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18319ULL;
	}
x86_l_3b78:
	/* 0x3b78: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&stack_delta_page_to_info)));
x86_l_3b7f:
	/* 0x3b7f: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3b84:
	/* 0x3b84: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3b89:
	/* 0x3b89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b8b:
	/* 0x3b8b: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3b90:
	/* 0x3b90: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3b93:
	/* 0x3b93: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3b98:
	/* 0x3b98: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3b9f:
	/* 0x3b9f: je     56a4 <kprobe_unwind_native+0x56a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22180ULL;
	}
x86_l_3ba5:
	/* 0x3ba5: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3baa:
	/* 0x3baa: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_3bad:
	/* 0x3bad: add    rbp,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_3bb1:
	/* 0x3bb1: movzx  eax,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_3bb5:
	/* 0x3bb5: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_3bb8:
	/* 0x3bb8: jg     3be6 <kprobe_unwind_native+0x3be6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3be6;
	}
x86_l_3bba:
	/* 0x3bba: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_3bbd:
	/* 0x3bbd: jg     3c12 <kprobe_unwind_native+0x3c12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3c12;
	}
x86_l_3bbf:
	/* 0x3bbf: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_3bc2:
	/* 0x3bc2: jg     3c58 <kprobe_unwind_native+0x3c58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3c58;
	}
x86_l_3bc8:
	/* 0x3bc8: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_3bcb:
	/* 0x3bcb: je     3cbb <kprobe_unwind_native+0x3cbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cbb;
	}
x86_l_3bd1:
	/* 0x3bd1: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_3bd4:
	/* 0x3bd4: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_3bda:
	/* 0x3bda: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_9_stack_deltas)));
x86_l_3be1:
	/* 0x3be1: jmp    3d01 <kprobe_unwind_native+0x3d01> */
	goto x86_l_3d01;
x86_l_3be6:
	/* 0x3be6: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_3be9:
	/* 0x3be9: jg     3c35 <kprobe_unwind_native+0x3c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3c35;
	}
x86_l_3beb:
	/* 0x3beb: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_3bee:
	/* 0x3bee: jg     3c76 <kprobe_unwind_native+0x3c76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3c76;
	}
x86_l_3bf4:
	/* 0x3bf4: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_3bf7:
	/* 0x3bf7: je     3cc4 <kprobe_unwind_native+0x3cc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cc4;
	}
x86_l_3bfd:
	/* 0x3bfd: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_3c00:
	/* 0x3c00: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_3c06:
	/* 0x3c06: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_17_stack_deltas)));
x86_l_3c0d:
	/* 0x3c0d: jmp    3d01 <kprobe_unwind_native+0x3d01> */
	goto x86_l_3d01;
x86_l_3c12:
	/* 0x3c12: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_3c15:
	/* 0x3c15: jg     3c8d <kprobe_unwind_native+0x3c8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3c8d;
	}
x86_l_3c17:
	/* 0x3c17: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3c1a:
	/* 0x3c1a: je     3ccd <kprobe_unwind_native+0x3ccd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ccd;
	}
x86_l_3c20:
	/* 0x3c20: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_3c23:
	/* 0x3c23: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_3c29:
	/* 0x3c29: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_13_stack_deltas)));
x86_l_3c30:
	/* 0x3c30: jmp    3d01 <kprobe_unwind_native+0x3d01> */
	goto x86_l_3d01;
x86_l_3c35:
	/* 0x3c35: cmp    eax,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_3c38:
	/* 0x3c38: jg     3ca4 <kprobe_unwind_native+0x3ca4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3ca4;
	}
x86_l_3c3a:
	/* 0x3c3a: cmp    eax,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 20ULL);
x86_l_3c3d:
	/* 0x3c3d: je     3cd6 <kprobe_unwind_native+0x3cd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cd6;
	}
x86_l_3c43:
	/* 0x3c43: cmp    eax,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_3c46:
	/* 0x3c46: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_3c4c:
	/* 0x3c4c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_21_stack_deltas)));
x86_l_3c53:
	/* 0x3c53: jmp    3d01 <kprobe_unwind_native+0x3d01> */
	goto x86_l_3d01;
x86_l_3c58:
	/* 0x3c58: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_3c5b:
	/* 0x3c5b: je     3cdf <kprobe_unwind_native+0x3cdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cdf;
	}
x86_l_3c61:
	/* 0x3c61: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_3c64:
	/* 0x3c64: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_3c6a:
	/* 0x3c6a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_11_stack_deltas)));
x86_l_3c71:
	/* 0x3c71: jmp    3d01 <kprobe_unwind_native+0x3d01> */
	goto x86_l_3d01;
x86_l_3c76:
	/* 0x3c76: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_3c79:
	/* 0x3c79: je     3ce8 <kprobe_unwind_native+0x3ce8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ce8;
	}
x86_l_3c7b:
	/* 0x3c7b: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_3c7e:
	/* 0x3c7e: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_3c84:
	/* 0x3c84: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_19_stack_deltas)));
x86_l_3c8b:
	/* 0x3c8b: jmp    3d01 <kprobe_unwind_native+0x3d01> */
	goto x86_l_3d01;
x86_l_3c8d:
	/* 0x3c8d: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3c90:
	/* 0x3c90: je     3cf1 <kprobe_unwind_native+0x3cf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cf1;
	}
x86_l_3c92:
	/* 0x3c92: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_3c95:
	/* 0x3c95: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_3c9b:
	/* 0x3c9b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_15_stack_deltas)));
x86_l_3ca2:
	/* 0x3ca2: jmp    3d01 <kprobe_unwind_native+0x3d01> */
	goto x86_l_3d01;
x86_l_3ca4:
	/* 0x3ca4: cmp    eax,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 22ULL);
x86_l_3ca7:
	/* 0x3ca7: je     3cfa <kprobe_unwind_native+0x3cfa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cfa;
	}
x86_l_3ca9:
	/* 0x3ca9: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_3cac:
	/* 0x3cac: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22570ULL;
	}
x86_l_3cb2:
	/* 0x3cb2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_23_stack_deltas)));
x86_l_3cb9:
	/* 0x3cb9: jmp    3d01 <kprobe_unwind_native+0x3d01> */
	goto x86_l_3d01;
x86_l_3cbb:
	/* 0x3cbb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_8_stack_deltas)));
x86_l_3cc2:
	/* 0x3cc2: jmp    3d01 <kprobe_unwind_native+0x3d01> */
	goto x86_l_3d01;
x86_l_3cc4:
	/* 0x3cc4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_16_stack_deltas)));
x86_l_3ccb:
	/* 0x3ccb: jmp    3d01 <kprobe_unwind_native+0x3d01> */
	goto x86_l_3d01;
x86_l_3ccd:
	/* 0x3ccd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_12_stack_deltas)));
x86_l_3cd4:
	/* 0x3cd4: jmp    3d01 <kprobe_unwind_native+0x3d01> */
	goto x86_l_3d01;
x86_l_3cd6:
	/* 0x3cd6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_20_stack_deltas)));
x86_l_3cdd:
	/* 0x3cdd: jmp    3d01 <kprobe_unwind_native+0x3d01> */
	goto x86_l_3d01;
x86_l_3cdf:
	/* 0x3cdf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_10_stack_deltas)));
x86_l_3ce6:
	/* 0x3ce6: jmp    3d01 <kprobe_unwind_native+0x3d01> */
	goto x86_l_3d01;
x86_l_3ce8:
	/* 0x3ce8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_18_stack_deltas)));
x86_l_3cef:
	/* 0x3cef: jmp    3d01 <kprobe_unwind_native+0x3d01> */
	goto x86_l_3d01;
x86_l_3cf1:
	/* 0x3cf1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_14_stack_deltas)));
x86_l_3cf8:
	/* 0x3cf8: jmp    3d01 <kprobe_unwind_native+0x3d01> */
	goto x86_l_3d01;
x86_l_3cfa:
	/* 0x3cfa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_22_stack_deltas)));
x86_l_3d01:
	/* 0x3d01: lea    rsi,[rsp+0x160] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_3d09:
	/* 0x3d09: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3d0e:
	/* 0x3d0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d10:
	/* 0x3d10: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3d15:
	/* 0x3d15: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3d18:
	/* 0x3d18: je     5f2b <kprobe_unwind_native+0x5f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24363ULL;
	}
x86_l_3d1e:
	/* 0x3d1e: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3d23:
	/* 0x3d23: mov    r13d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d26:
	/* 0x3d26: mov    DWORD PTR [rsp+0x90],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3d2e:
	/* 0x3d2e: mov    rax,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_3d35:
	/* 0x3d35: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d3a:
	/* 0x3d3a: movzx  eax,WORD PTR [rcx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3d3e:
	/* 0x3d3e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d40:
	/* 0x3d40: je     4237 <kprobe_unwind_native+0x4237> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16951ULL;
	}
x86_l_3d46:
	/* 0x3d46: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_3d49:
	/* 0x3d49: add    r12d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3d4c:
	/* 0x3d4c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3d53:
	/* 0x3d53: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d56:
	/* 0x3d56: jne    489d <kprobe_unwind_native+0x489d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18589ULL;
	}
x86_l_3d5c:
	/* 0x3d5c: lea    eax,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3d60:
	/* 0x3d60: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_3d62:
	/* 0x3d62: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d66:
	/* 0x3d66: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d6b:
	/* 0x3d6b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3d70:
	/* 0x3d70: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3d75:
	/* 0x3d75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d77:
	/* 0x3d77: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3d7a:
	/* 0x3d7a: je     430e <kprobe_unwind_native+0x430e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17166ULL;
	}
x86_l_3d80:
	/* 0x3d80: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d84:
	/* 0x3d84: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3d87:
	/* 0x3d87: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d8c:
	/* 0x3d8c: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d8f:
	/* 0x3d8f: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_3d93:
	/* 0x3d93: cmova  r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_3d97:
	/* 0x3d97: mov    QWORD PTR [rsp],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d9b:
	/* 0x3d9b: cmp    ebp,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R12, X86_WIDTH_32);
x86_l_3d9e:
	/* 0x3d9e: jae    4228 <kprobe_unwind_native+0x4228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 16936ULL;
	}
x86_l_3da4:
	/* 0x3da4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3da8:
	/* 0x3da8: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3daa:
	/* 0x3daa: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_3dac:
	/* 0x3dac: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3db0:
	/* 0x3db0: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3db5:
	/* 0x3db5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3dba:
	/* 0x3dba: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3dbf:
	/* 0x3dbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dc1:
	/* 0x3dc1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3dc4:
	/* 0x3dc4: je     430e <kprobe_unwind_native+0x430e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17166ULL;
	}
	return 15818ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15818ULL: goto x86_l_3dca;
	case 15822ULL: goto x86_l_3dce;
	case 15826ULL: goto x86_l_3dd2;
	case 15831ULL: goto x86_l_3dd7;
	case 15834ULL: goto x86_l_3dda;
	case 15838ULL: goto x86_l_3dde;
	case 15842ULL: goto x86_l_3de2;
	case 15845ULL: goto x86_l_3de5;
	case 15849ULL: goto x86_l_3de9;
	case 15852ULL: goto x86_l_3dec;
	case 15858ULL: goto x86_l_3df2;
	case 15862ULL: goto x86_l_3df6;
	case 15865ULL: goto x86_l_3df9;
	case 15867ULL: goto x86_l_3dfb;
	case 15871ULL: goto x86_l_3dff;
	case 15876ULL: goto x86_l_3e04;
	case 15881ULL: goto x86_l_3e09;
	case 15886ULL: goto x86_l_3e0e;
	case 15888ULL: goto x86_l_3e10;
	case 15891ULL: goto x86_l_3e13;
	case 15897ULL: goto x86_l_3e19;
	case 15901ULL: goto x86_l_3e1d;
	case 15904ULL: goto x86_l_3e20;
	case 15909ULL: goto x86_l_3e25;
	case 15912ULL: goto x86_l_3e28;
	case 15916ULL: goto x86_l_3e2c;
	case 15920ULL: goto x86_l_3e30;
	case 15923ULL: goto x86_l_3e33;
	case 15927ULL: goto x86_l_3e37;
	case 15929ULL: goto x86_l_3e39;
	case 15935ULL: goto x86_l_3e3f;
	case 15939ULL: goto x86_l_3e43;
	case 15941ULL: goto x86_l_3e45;
	case 15943ULL: goto x86_l_3e47;
	case 15947ULL: goto x86_l_3e4b;
	case 15952ULL: goto x86_l_3e50;
	case 15957ULL: goto x86_l_3e55;
	case 15962ULL: goto x86_l_3e5a;
	case 15964ULL: goto x86_l_3e5c;
	case 15967ULL: goto x86_l_3e5f;
	case 15973ULL: goto x86_l_3e65;
	case 15977ULL: goto x86_l_3e69;
	case 15981ULL: goto x86_l_3e6d;
	case 15986ULL: goto x86_l_3e72;
	case 15989ULL: goto x86_l_3e75;
	case 15993ULL: goto x86_l_3e79;
	case 15997ULL: goto x86_l_3e7d;
	case 16000ULL: goto x86_l_3e80;
	case 16004ULL: goto x86_l_3e84;
	case 16007ULL: goto x86_l_3e87;
	case 16013ULL: goto x86_l_3e8d;
	case 16017ULL: goto x86_l_3e91;
	case 16020ULL: goto x86_l_3e94;
	case 16022ULL: goto x86_l_3e96;
	case 16026ULL: goto x86_l_3e9a;
	case 16031ULL: goto x86_l_3e9f;
	case 16036ULL: goto x86_l_3ea4;
	case 16041ULL: goto x86_l_3ea9;
	case 16043ULL: goto x86_l_3eab;
	case 16046ULL: goto x86_l_3eae;
	case 16052ULL: goto x86_l_3eb4;
	case 16056ULL: goto x86_l_3eb8;
	case 16059ULL: goto x86_l_3ebb;
	case 16064ULL: goto x86_l_3ec0;
	case 16067ULL: goto x86_l_3ec3;
	case 16071ULL: goto x86_l_3ec7;
	case 16075ULL: goto x86_l_3ecb;
	case 16078ULL: goto x86_l_3ece;
	case 16082ULL: goto x86_l_3ed2;
	case 16084ULL: goto x86_l_3ed4;
	case 16090ULL: goto x86_l_3eda;
	case 16094ULL: goto x86_l_3ede;
	case 16096ULL: goto x86_l_3ee0;
	case 16098ULL: goto x86_l_3ee2;
	case 16102ULL: goto x86_l_3ee6;
	case 16107ULL: goto x86_l_3eeb;
	case 16112ULL: goto x86_l_3ef0;
	case 16117ULL: goto x86_l_3ef5;
	case 16119ULL: goto x86_l_3ef7;
	case 16122ULL: goto x86_l_3efa;
	case 16128ULL: goto x86_l_3f00;
	case 16132ULL: goto x86_l_3f04;
	case 16136ULL: goto x86_l_3f08;
	case 16141ULL: goto x86_l_3f0d;
	case 16144ULL: goto x86_l_3f10;
	case 16148ULL: goto x86_l_3f14;
	case 16152ULL: goto x86_l_3f18;
	case 16155ULL: goto x86_l_3f1b;
	case 16159ULL: goto x86_l_3f1f;
	case 16162ULL: goto x86_l_3f22;
	case 16168ULL: goto x86_l_3f28;
	case 16172ULL: goto x86_l_3f2c;
	case 16175ULL: goto x86_l_3f2f;
	case 16177ULL: goto x86_l_3f31;
	case 16181ULL: goto x86_l_3f35;
	case 16186ULL: goto x86_l_3f3a;
	case 16191ULL: goto x86_l_3f3f;
	case 16196ULL: goto x86_l_3f44;
	case 16198ULL: goto x86_l_3f46;
	case 16201ULL: goto x86_l_3f49;
	case 16207ULL: goto x86_l_3f4f;
	case 16211ULL: goto x86_l_3f53;
	case 16214ULL: goto x86_l_3f56;
	case 16219ULL: goto x86_l_3f5b;
	case 16222ULL: goto x86_l_3f5e;
	case 16226ULL: goto x86_l_3f62;
	case 16230ULL: goto x86_l_3f66;
	case 16233ULL: goto x86_l_3f69;
	case 16237ULL: goto x86_l_3f6d;
	case 16239ULL: goto x86_l_3f6f;
	case 16245ULL: goto x86_l_3f75;
	case 16249ULL: goto x86_l_3f79;
	case 16251ULL: goto x86_l_3f7b;
	case 16253ULL: goto x86_l_3f7d;
	case 16257ULL: goto x86_l_3f81;
	case 16262ULL: goto x86_l_3f86;
	case 16267ULL: goto x86_l_3f8b;
	case 16272ULL: goto x86_l_3f90;
	case 16274ULL: goto x86_l_3f92;
	case 16277ULL: goto x86_l_3f95;
	case 16283ULL: goto x86_l_3f9b;
	case 16287ULL: goto x86_l_3f9f;
	case 16291ULL: goto x86_l_3fa3;
	case 16296ULL: goto x86_l_3fa8;
	case 16299ULL: goto x86_l_3fab;
	case 16303ULL: goto x86_l_3faf;
	case 16307ULL: goto x86_l_3fb3;
	case 16310ULL: goto x86_l_3fb6;
	case 16314ULL: goto x86_l_3fba;
	case 16317ULL: goto x86_l_3fbd;
	case 16323ULL: goto x86_l_3fc3;
	case 16327ULL: goto x86_l_3fc7;
	case 16330ULL: goto x86_l_3fca;
	case 16332ULL: goto x86_l_3fcc;
	case 16336ULL: goto x86_l_3fd0;
	case 16341ULL: goto x86_l_3fd5;
	case 16346ULL: goto x86_l_3fda;
	case 16351ULL: goto x86_l_3fdf;
	case 16353ULL: goto x86_l_3fe1;
	case 16356ULL: goto x86_l_3fe4;
	case 16362ULL: goto x86_l_3fea;
	case 16366ULL: goto x86_l_3fee;
	case 16369ULL: goto x86_l_3ff1;
	case 16374ULL: goto x86_l_3ff6;
	case 16377ULL: goto x86_l_3ff9;
	case 16381ULL: goto x86_l_3ffd;
	case 16385ULL: goto x86_l_4001;
	case 16388ULL: goto x86_l_4004;
	case 16392ULL: goto x86_l_4008;
	case 16394ULL: goto x86_l_400a;
	case 16400ULL: goto x86_l_4010;
	case 16404ULL: goto x86_l_4014;
	case 16406ULL: goto x86_l_4016;
	case 16408ULL: goto x86_l_4018;
	case 16412ULL: goto x86_l_401c;
	case 16417ULL: goto x86_l_4021;
	case 16422ULL: goto x86_l_4026;
	case 16427ULL: goto x86_l_402b;
	case 16429ULL: goto x86_l_402d;
	case 16432ULL: goto x86_l_4030;
	case 16438ULL: goto x86_l_4036;
	case 16442ULL: goto x86_l_403a;
	case 16446ULL: goto x86_l_403e;
	case 16451ULL: goto x86_l_4043;
	case 16454ULL: goto x86_l_4046;
	case 16458ULL: goto x86_l_404a;
	case 16462ULL: goto x86_l_404e;
	case 16465ULL: goto x86_l_4051;
	case 16469ULL: goto x86_l_4055;
	case 16472ULL: goto x86_l_4058;
	case 16478ULL: goto x86_l_405e;
	case 16482ULL: goto x86_l_4062;
	case 16485ULL: goto x86_l_4065;
	case 16487ULL: goto x86_l_4067;
	case 16491ULL: goto x86_l_406b;
	case 16496ULL: goto x86_l_4070;
	case 16501ULL: goto x86_l_4075;
	case 16506ULL: goto x86_l_407a;
	case 16508ULL: goto x86_l_407c;
	case 16511ULL: goto x86_l_407f;
	case 16517ULL: goto x86_l_4085;
	case 16521ULL: goto x86_l_4089;
	case 16524ULL: goto x86_l_408c;
	case 16529ULL: goto x86_l_4091;
	case 16532ULL: goto x86_l_4094;
	case 16536ULL: goto x86_l_4098;
	case 16540ULL: goto x86_l_409c;
	case 16543ULL: goto x86_l_409f;
	case 16547ULL: goto x86_l_40a3;
	case 16549ULL: goto x86_l_40a5;
	case 16555ULL: goto x86_l_40ab;
	case 16559ULL: goto x86_l_40af;
	case 16561ULL: goto x86_l_40b1;
	case 16563ULL: goto x86_l_40b3;
	case 16567ULL: goto x86_l_40b7;
	case 16572ULL: goto x86_l_40bc;
	case 16577ULL: goto x86_l_40c1;
	case 16582ULL: goto x86_l_40c6;
	case 16584ULL: goto x86_l_40c8;
	case 16587ULL: goto x86_l_40cb;
	case 16593ULL: goto x86_l_40d1;
	case 16597ULL: goto x86_l_40d5;
	case 16601ULL: goto x86_l_40d9;
	case 16606ULL: goto x86_l_40de;
	case 16609ULL: goto x86_l_40e1;
	case 16613ULL: goto x86_l_40e5;
	case 16617ULL: goto x86_l_40e9;
	case 16620ULL: goto x86_l_40ec;
	case 16624ULL: goto x86_l_40f0;
	case 16627ULL: goto x86_l_40f3;
	case 16633ULL: goto x86_l_40f9;
	case 16637ULL: goto x86_l_40fd;
	case 16640ULL: goto x86_l_4100;
	case 16642ULL: goto x86_l_4102;
	case 16646ULL: goto x86_l_4106;
	case 16651ULL: goto x86_l_410b;
	case 16656ULL: goto x86_l_4110;
	case 16661ULL: goto x86_l_4115;
	case 16663ULL: goto x86_l_4117;
	case 16666ULL: goto x86_l_411a;
	case 16672ULL: goto x86_l_4120;
	case 16676ULL: goto x86_l_4124;
	case 16679ULL: goto x86_l_4127;
	case 16684ULL: goto x86_l_412c;
	case 16687ULL: goto x86_l_412f;
	case 16691ULL: goto x86_l_4133;
	case 16695ULL: goto x86_l_4137;
	case 16698ULL: goto x86_l_413a;
	case 16702ULL: goto x86_l_413e;
	case 16704ULL: goto x86_l_4140;
	case 16710ULL: goto x86_l_4146;
	case 16714ULL: goto x86_l_414a;
	case 16716ULL: goto x86_l_414c;
	case 16718ULL: goto x86_l_414e;
	case 16722ULL: goto x86_l_4152;
	case 16727ULL: goto x86_l_4157;
	case 16732ULL: goto x86_l_415c;
	case 16737ULL: goto x86_l_4161;
	case 16739ULL: goto x86_l_4163;
	case 16742ULL: goto x86_l_4166;
	case 16748ULL: goto x86_l_416c;
	case 16752ULL: goto x86_l_4170;
	case 16756ULL: goto x86_l_4174;
	case 16761ULL: goto x86_l_4179;
	case 16764ULL: goto x86_l_417c;
	case 16768ULL: goto x86_l_4180;
	case 16772ULL: goto x86_l_4184;
	case 16775ULL: goto x86_l_4187;
	case 16779ULL: goto x86_l_418b;
	case 16782ULL: goto x86_l_418e;
	case 16788ULL: goto x86_l_4194;
	case 16792ULL: goto x86_l_4198;
	case 16795ULL: goto x86_l_419b;
	case 16797ULL: goto x86_l_419d;
	case 16801ULL: goto x86_l_41a1;
	case 16806ULL: goto x86_l_41a6;
	case 16811ULL: goto x86_l_41ab;
	case 16816ULL: goto x86_l_41b0;
	case 16818ULL: goto x86_l_41b2;
	case 16821ULL: goto x86_l_41b5;
	case 16827ULL: goto x86_l_41bb;
	case 16831ULL: goto x86_l_41bf;
	case 16834ULL: goto x86_l_41c2;
	case 16839ULL: goto x86_l_41c7;
	case 16842ULL: goto x86_l_41ca;
	case 16846ULL: goto x86_l_41ce;
	case 16850ULL: goto x86_l_41d2;
	case 16853ULL: goto x86_l_41d5;
	case 16857ULL: goto x86_l_41d9;
	case 16859ULL: goto x86_l_41db;
	case 16861ULL: goto x86_l_41dd;
	case 16865ULL: goto x86_l_41e1;
	case 16867ULL: goto x86_l_41e3;
	case 16869ULL: goto x86_l_41e5;
	case 16873ULL: goto x86_l_41e9;
	case 16878ULL: goto x86_l_41ee;
	case 16883ULL: goto x86_l_41f3;
	case 16888ULL: goto x86_l_41f8;
	case 16890ULL: goto x86_l_41fa;
	case 16893ULL: goto x86_l_41fd;
	case 16899ULL: goto x86_l_4203;
	case 16903ULL: goto x86_l_4207;
	case 16906ULL: goto x86_l_420a;
	case 16911ULL: goto x86_l_420f;
	case 16914ULL: goto x86_l_4212;
	case 16917ULL: goto x86_l_4215;
	case 16921ULL: goto x86_l_4219;
	case 16924ULL: goto x86_l_421c;
	case 16928ULL: goto x86_l_4220;
	case 16930ULL: goto x86_l_4222;
	case 16936ULL: goto x86_l_4228;
	case 16940ULL: goto x86_l_422c;
	case 16943ULL: goto x86_l_422f;
	case 16945ULL: goto x86_l_4231;
	case 16951ULL: goto x86_l_4237;
	case 16954ULL: goto x86_l_423a;
	case 16962ULL: goto x86_l_4242;
	case 16970ULL: goto x86_l_424a;
	case 16975ULL: goto x86_l_424f;
	case 16980ULL: goto x86_l_4254;
	case 16982ULL: goto x86_l_4256;
	case 16985ULL: goto x86_l_4259;
	case 16991ULL: goto x86_l_425f;
	case 16994ULL: goto x86_l_4262;
	case 17001ULL: goto x86_l_4269;
	case 17004ULL: goto x86_l_426c;
	case 17010ULL: goto x86_l_4272;
	case 17015ULL: goto x86_l_4277;
	case 17019ULL: goto x86_l_427b;
	case 17021ULL: goto x86_l_427d;
	case 17028ULL: goto x86_l_4284;
	case 17033ULL: goto x86_l_4289;
	case 17035ULL: goto x86_l_428b;
	case 17042ULL: goto x86_l_4292;
	case 17046ULL: goto x86_l_4296;
	case 17050ULL: goto x86_l_429a;
	case 17057ULL: goto x86_l_42a1;
	case 17062ULL: goto x86_l_42a6;
	case 17064ULL: goto x86_l_42a8;
	case 17069ULL: goto x86_l_42ad;
	case 17075ULL: goto x86_l_42b3;
	case 17086ULL: goto x86_l_42be;
	case 17093ULL: goto x86_l_42c5;
	case 17101ULL: goto x86_l_42cd;
	case 17106ULL: goto x86_l_42d2;
	case 17108ULL: goto x86_l_42d4;
	case 17111ULL: goto x86_l_42d7;
	case 17117ULL: goto x86_l_42dd;
	case 17120ULL: goto x86_l_42e0;
	case 17125ULL: goto x86_l_42e5;
	case 17130ULL: goto x86_l_42ea;
	case 17135ULL: goto x86_l_42ef;
	case 17141ULL: goto x86_l_42f5;
	case 17144ULL: goto x86_l_42f8;
	case 17149ULL: goto x86_l_42fd;
	case 17154ULL: goto x86_l_4302;
	case 17159ULL: goto x86_l_4307;
	case 17164ULL: goto x86_l_430c;
	case 17166ULL: goto x86_l_430e;
	case 17173ULL: goto x86_l_4315;
	case 17176ULL: goto x86_l_4318;
	case 17182ULL: goto x86_l_431e;
	case 17192ULL: goto x86_l_4328;
	case 17197ULL: goto x86_l_432d;
	case 17207ULL: goto x86_l_4337;
	case 17212ULL: goto x86_l_433c;
	case 17222ULL: goto x86_l_4346;
	case 17227ULL: goto x86_l_434b;
	case 17237ULL: goto x86_l_4355;
	case 17242ULL: goto x86_l_435a;
	case 17252ULL: goto x86_l_4364;
	case 17257ULL: goto x86_l_4369;
	case 17265ULL: goto x86_l_4371;
	case 17270ULL: goto x86_l_4376;
	case 17275ULL: goto x86_l_437b;
	case 17280ULL: goto x86_l_4380;
	case 17285ULL: goto x86_l_4385;
	case 17292ULL: goto x86_l_438c;
	case 17295ULL: goto x86_l_438f;
	case 17301ULL: goto x86_l_4395;
	case 17308ULL: goto x86_l_439c;
	case 17311ULL: goto x86_l_439f;
	case 17317ULL: goto x86_l_43a5;
	case 17324ULL: goto x86_l_43ac;
	case 17332ULL: goto x86_l_43b4;
	case 17337ULL: goto x86_l_43b9;
	case 17339ULL: goto x86_l_43bb;
	case 17344ULL: goto x86_l_43c0;
	case 17347ULL: goto x86_l_43c3;
	case 17353ULL: goto x86_l_43c9;
	case 17358ULL: goto x86_l_43ce;
	case 17361ULL: goto x86_l_43d1;
	case 17365ULL: goto x86_l_43d5;
	case 17367ULL: goto x86_l_43d7;
	case 17369ULL: goto x86_l_43d9;
	case 17376ULL: goto x86_l_43e0;
	case 17379ULL: goto x86_l_43e3;
	case 17385ULL: goto x86_l_43e9;
	case 17387ULL: goto x86_l_43eb;
	case 17390ULL: goto x86_l_43ee;
	case 17393ULL: goto x86_l_43f1;
	case 17396ULL: goto x86_l_43f4;
	case 17398ULL: goto x86_l_43f6;
	case 17400ULL: goto x86_l_43f8;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3dca:
	/* 0x3dca: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3dce:
	/* 0x3dce: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3dd2:
	/* 0x3dd2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3dd7:
	/* 0x3dd7: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3dda:
	/* 0x3dda: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_3dde:
	/* 0x3dde: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3de2:
	/* 0x3de2: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_3de5:
	/* 0x3de5: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3de9:
	/* 0x3de9: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_3dec:
	/* 0x3dec: jae    4228 <kprobe_unwind_native+0x4228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4228;
	}
x86_l_3df2:
	/* 0x3df2: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3df6:
	/* 0x3df6: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3df9:
	/* 0x3df9: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_3dfb:
	/* 0x3dfb: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3dff:
	/* 0x3dff: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e04:
	/* 0x3e04: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e09:
	/* 0x3e09: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3e0e:
	/* 0x3e0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e10:
	/* 0x3e10: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e13:
	/* 0x3e13: je     430e <kprobe_unwind_native+0x430e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_430e;
	}
x86_l_3e19:
	/* 0x3e19: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e1d:
	/* 0x3e1d: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3e20:
	/* 0x3e20: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e25:
	/* 0x3e25: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e28:
	/* 0x3e28: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_3e2c:
	/* 0x3e2c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e30:
	/* 0x3e30: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_3e33:
	/* 0x3e33: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e37:
	/* 0x3e37: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_3e39:
	/* 0x3e39: jae    4228 <kprobe_unwind_native+0x4228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4228;
	}
x86_l_3e3f:
	/* 0x3e3f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e43:
	/* 0x3e43: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3e45:
	/* 0x3e45: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_3e47:
	/* 0x3e47: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e4b:
	/* 0x3e4b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e50:
	/* 0x3e50: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e55:
	/* 0x3e55: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3e5a:
	/* 0x3e5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e5c:
	/* 0x3e5c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e5f:
	/* 0x3e5f: je     430e <kprobe_unwind_native+0x430e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_430e;
	}
x86_l_3e65:
	/* 0x3e65: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e69:
	/* 0x3e69: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3e6d:
	/* 0x3e6d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e72:
	/* 0x3e72: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e75:
	/* 0x3e75: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_3e79:
	/* 0x3e79: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e7d:
	/* 0x3e7d: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_3e80:
	/* 0x3e80: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e84:
	/* 0x3e84: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_3e87:
	/* 0x3e87: jae    4228 <kprobe_unwind_native+0x4228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4228;
	}
x86_l_3e8d:
	/* 0x3e8d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e91:
	/* 0x3e91: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3e94:
	/* 0x3e94: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_3e96:
	/* 0x3e96: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e9a:
	/* 0x3e9a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e9f:
	/* 0x3e9f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3ea4:
	/* 0x3ea4: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3ea9:
	/* 0x3ea9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3eab:
	/* 0x3eab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3eae:
	/* 0x3eae: je     430e <kprobe_unwind_native+0x430e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_430e;
	}
x86_l_3eb4:
	/* 0x3eb4: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3eb8:
	/* 0x3eb8: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3ebb:
	/* 0x3ebb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ec0:
	/* 0x3ec0: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ec3:
	/* 0x3ec3: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_3ec7:
	/* 0x3ec7: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ecb:
	/* 0x3ecb: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_3ece:
	/* 0x3ece: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ed2:
	/* 0x3ed2: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_3ed4:
	/* 0x3ed4: jae    4228 <kprobe_unwind_native+0x4228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4228;
	}
x86_l_3eda:
	/* 0x3eda: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ede:
	/* 0x3ede: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3ee0:
	/* 0x3ee0: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_3ee2:
	/* 0x3ee2: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ee6:
	/* 0x3ee6: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3eeb:
	/* 0x3eeb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3ef0:
	/* 0x3ef0: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3ef5:
	/* 0x3ef5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ef7:
	/* 0x3ef7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3efa:
	/* 0x3efa: je     430e <kprobe_unwind_native+0x430e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_430e;
	}
x86_l_3f00:
	/* 0x3f00: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f04:
	/* 0x3f04: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3f08:
	/* 0x3f08: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f0d:
	/* 0x3f0d: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f10:
	/* 0x3f10: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_3f14:
	/* 0x3f14: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f18:
	/* 0x3f18: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_3f1b:
	/* 0x3f1b: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f1f:
	/* 0x3f1f: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_3f22:
	/* 0x3f22: jae    4228 <kprobe_unwind_native+0x4228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4228;
	}
x86_l_3f28:
	/* 0x3f28: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f2c:
	/* 0x3f2c: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3f2f:
	/* 0x3f2f: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_3f31:
	/* 0x3f31: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f35:
	/* 0x3f35: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f3a:
	/* 0x3f3a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3f3f:
	/* 0x3f3f: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3f44:
	/* 0x3f44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f46:
	/* 0x3f46: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f49:
	/* 0x3f49: je     430e <kprobe_unwind_native+0x430e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_430e;
	}
x86_l_3f4f:
	/* 0x3f4f: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f53:
	/* 0x3f53: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3f56:
	/* 0x3f56: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f5b:
	/* 0x3f5b: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f5e:
	/* 0x3f5e: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_3f62:
	/* 0x3f62: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f66:
	/* 0x3f66: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_3f69:
	/* 0x3f69: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f6d:
	/* 0x3f6d: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_3f6f:
	/* 0x3f6f: jae    4228 <kprobe_unwind_native+0x4228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4228;
	}
x86_l_3f75:
	/* 0x3f75: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f79:
	/* 0x3f79: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3f7b:
	/* 0x3f7b: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_3f7d:
	/* 0x3f7d: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f81:
	/* 0x3f81: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f86:
	/* 0x3f86: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3f8b:
	/* 0x3f8b: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3f90:
	/* 0x3f90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f92:
	/* 0x3f92: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f95:
	/* 0x3f95: je     430e <kprobe_unwind_native+0x430e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_430e;
	}
x86_l_3f9b:
	/* 0x3f9b: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f9f:
	/* 0x3f9f: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3fa3:
	/* 0x3fa3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fa8:
	/* 0x3fa8: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fab:
	/* 0x3fab: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_3faf:
	/* 0x3faf: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fb3:
	/* 0x3fb3: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_3fb6:
	/* 0x3fb6: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fba:
	/* 0x3fba: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_3fbd:
	/* 0x3fbd: jae    4228 <kprobe_unwind_native+0x4228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4228;
	}
x86_l_3fc3:
	/* 0x3fc3: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fc7:
	/* 0x3fc7: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3fca:
	/* 0x3fca: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_3fcc:
	/* 0x3fcc: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3fd0:
	/* 0x3fd0: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3fd5:
	/* 0x3fd5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3fda:
	/* 0x3fda: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3fdf:
	/* 0x3fdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fe1:
	/* 0x3fe1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3fe4:
	/* 0x3fe4: je     430e <kprobe_unwind_native+0x430e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_430e;
	}
x86_l_3fea:
	/* 0x3fea: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3fee:
	/* 0x3fee: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3ff1:
	/* 0x3ff1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ff6:
	/* 0x3ff6: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ff9:
	/* 0x3ff9: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_3ffd:
	/* 0x3ffd: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4001:
	/* 0x4001: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_4004:
	/* 0x4004: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4008:
	/* 0x4008: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_400a:
	/* 0x400a: jae    4228 <kprobe_unwind_native+0x4228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4228;
	}
x86_l_4010:
	/* 0x4010: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4014:
	/* 0x4014: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4016:
	/* 0x4016: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_4018:
	/* 0x4018: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_401c:
	/* 0x401c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4021:
	/* 0x4021: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4026:
	/* 0x4026: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_402b:
	/* 0x402b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_402d:
	/* 0x402d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4030:
	/* 0x4030: je     430e <kprobe_unwind_native+0x430e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_430e;
	}
x86_l_4036:
	/* 0x4036: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_403a:
	/* 0x403a: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_403e:
	/* 0x403e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4043:
	/* 0x4043: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4046:
	/* 0x4046: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_404a:
	/* 0x404a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_404e:
	/* 0x404e: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_4051:
	/* 0x4051: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4055:
	/* 0x4055: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_4058:
	/* 0x4058: jae    4228 <kprobe_unwind_native+0x4228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4228;
	}
x86_l_405e:
	/* 0x405e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4062:
	/* 0x4062: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4065:
	/* 0x4065: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_4067:
	/* 0x4067: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_406b:
	/* 0x406b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4070:
	/* 0x4070: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4075:
	/* 0x4075: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_407a:
	/* 0x407a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_407c:
	/* 0x407c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_407f:
	/* 0x407f: je     430e <kprobe_unwind_native+0x430e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_430e;
	}
x86_l_4085:
	/* 0x4085: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4089:
	/* 0x4089: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_408c:
	/* 0x408c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4091:
	/* 0x4091: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4094:
	/* 0x4094: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_4098:
	/* 0x4098: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_409c:
	/* 0x409c: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_409f:
	/* 0x409f: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40a3:
	/* 0x40a3: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_40a5:
	/* 0x40a5: jae    4228 <kprobe_unwind_native+0x4228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4228;
	}
x86_l_40ab:
	/* 0x40ab: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40af:
	/* 0x40af: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_40b1:
	/* 0x40b1: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_40b3:
	/* 0x40b3: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40b7:
	/* 0x40b7: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40bc:
	/* 0x40bc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_40c1:
	/* 0x40c1: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_40c6:
	/* 0x40c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40c8:
	/* 0x40c8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_40cb:
	/* 0x40cb: je     430e <kprobe_unwind_native+0x430e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_430e;
	}
x86_l_40d1:
	/* 0x40d1: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40d5:
	/* 0x40d5: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_40d9:
	/* 0x40d9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40de:
	/* 0x40de: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40e1:
	/* 0x40e1: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_40e5:
	/* 0x40e5: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40e9:
	/* 0x40e9: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_40ec:
	/* 0x40ec: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40f0:
	/* 0x40f0: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_40f3:
	/* 0x40f3: jae    4228 <kprobe_unwind_native+0x4228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4228;
	}
x86_l_40f9:
	/* 0x40f9: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40fd:
	/* 0x40fd: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4100:
	/* 0x4100: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_4102:
	/* 0x4102: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4106:
	/* 0x4106: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_410b:
	/* 0x410b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4110:
	/* 0x4110: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4115:
	/* 0x4115: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4117:
	/* 0x4117: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_411a:
	/* 0x411a: je     430e <kprobe_unwind_native+0x430e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_430e;
	}
x86_l_4120:
	/* 0x4120: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4124:
	/* 0x4124: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4127:
	/* 0x4127: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_412c:
	/* 0x412c: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_412f:
	/* 0x412f: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_4133:
	/* 0x4133: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4137:
	/* 0x4137: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_413a:
	/* 0x413a: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_413e:
	/* 0x413e: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_4140:
	/* 0x4140: jae    4228 <kprobe_unwind_native+0x4228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4228;
	}
x86_l_4146:
	/* 0x4146: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_414a:
	/* 0x414a: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_414c:
	/* 0x414c: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_414e:
	/* 0x414e: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4152:
	/* 0x4152: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4157:
	/* 0x4157: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_415c:
	/* 0x415c: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4161:
	/* 0x4161: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4163:
	/* 0x4163: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4166:
	/* 0x4166: je     430e <kprobe_unwind_native+0x430e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_430e;
	}
x86_l_416c:
	/* 0x416c: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4170:
	/* 0x4170: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4174:
	/* 0x4174: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4179:
	/* 0x4179: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_417c:
	/* 0x417c: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_4180:
	/* 0x4180: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4184:
	/* 0x4184: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_4187:
	/* 0x4187: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_418b:
	/* 0x418b: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_418e:
	/* 0x418e: jae    4228 <kprobe_unwind_native+0x4228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4228;
	}
x86_l_4194:
	/* 0x4194: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4198:
	/* 0x4198: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_419b:
	/* 0x419b: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_419d:
	/* 0x419d: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41a1:
	/* 0x41a1: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41a6:
	/* 0x41a6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_41ab:
	/* 0x41ab: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_41b0:
	/* 0x41b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41b2:
	/* 0x41b2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_41b5:
	/* 0x41b5: je     430e <kprobe_unwind_native+0x430e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_430e;
	}
x86_l_41bb:
	/* 0x41bb: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41bf:
	/* 0x41bf: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_41c2:
	/* 0x41c2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41c7:
	/* 0x41c7: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41ca:
	/* 0x41ca: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_41ce:
	/* 0x41ce: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41d2:
	/* 0x41d2: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_41d5:
	/* 0x41d5: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41d9:
	/* 0x41d9: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_41db:
	/* 0x41db: jae    4228 <kprobe_unwind_native+0x4228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4228;
	}
x86_l_41dd:
	/* 0x41dd: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41e1:
	/* 0x41e1: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_41e3:
	/* 0x41e3: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_41e5:
	/* 0x41e5: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41e9:
	/* 0x41e9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41ee:
	/* 0x41ee: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_41f3:
	/* 0x41f3: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_41f8:
	/* 0x41f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41fa:
	/* 0x41fa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_41fd:
	/* 0x41fd: je     430e <kprobe_unwind_native+0x430e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_430e;
	}
x86_l_4203:
	/* 0x4203: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4207:
	/* 0x4207: lea    edx,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_420a:
	/* 0x420a: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_420f:
	/* 0x420f: cmp    WORD PTR [rax],si */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4212:
	/* 0x4212: cmova  edx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_4215:
	/* 0x4215: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4219:
	/* 0x4219: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_421c:
	/* 0x421c: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4220:
	/* 0x4220: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_4222:
	/* 0x4222: jb     430e <kprobe_unwind_native+0x430e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_430e;
	}
x86_l_4228:
	/* 0x4228: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_422c:
	/* 0x422c: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_422f:
	/* 0x422f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4231:
	/* 0x4231: je     430e <kprobe_unwind_native+0x430e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_430e;
	}
x86_l_4237:
	/* 0x4237: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_423a:
	/* 0x423a: mov    DWORD PTR [rsp+0x90],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4242:
	/* 0x4242: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_424a:
	/* 0x424a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_424f:
	/* 0x424f: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4254:
	/* 0x4254: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4256:
	/* 0x4256: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4259:
	/* 0x4259: je     4302 <kprobe_unwind_native+0x4302> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4302;
	}
x86_l_425f:
	/* 0x425f: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_4262:
	/* 0x4262: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4269:
	/* 0x4269: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_426c:
	/* 0x426c: jne    4921 <kprobe_unwind_native+0x4921> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18721ULL;
	}
x86_l_4272:
	/* 0x4272: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_4277:
	/* 0x4277: movzx  ecx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_427b:
	/* 0x427b: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_427d:
	/* 0x427d: mov    ecx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4284:
	/* 0x4284: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4289:
	/* 0x4289: cmp    ecx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_428b:
	/* 0x428b: lea    r13d,[rax+0x10000] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 65536ULL);
x86_l_4292:
	/* 0x4292: cmovae r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_4296:
	/* 0x4296: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_429a:
	/* 0x429a: mov    DWORD PTR [rsp+0x8c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_42a1:
	/* 0x42a1: cmp    eax,0x8000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32768ULL);
x86_l_42a6:
	/* 0x42a6: je     42e5 <kprobe_unwind_native+0x42e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42e5;
	}
x86_l_42a8:
	/* 0x42a8: cmp    eax,0x8001 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32769ULL);
x86_l_42ad:
	/* 0x42ad: jne    439c <kprobe_unwind_native+0x439c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_439c;
	}
x86_l_42b3:
	/* 0x42b3: mov    DWORD PTR [rsp+0x94],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159815ULL);
x86_l_42be:
	/* 0x42be: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_42c5:
	/* 0x42c5: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_42cd:
	/* 0x42cd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_42d2:
	/* 0x42d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42d4:
	/* 0x42d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_42d7:
	/* 0x42d7: je     4385 <kprobe_unwind_native+0x4385> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4385;
	}
x86_l_42dd:
	/* 0x42dd: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_42e0:
	/* 0x42e0: jmp    4395 <kprobe_unwind_native+0x4395> */
	goto x86_l_4395;
x86_l_42e5:
	/* 0x42e5: mov    edx,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_42ea:
	/* 0x42ea: mov    ecx,0xfa5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4005ULL);
x86_l_42ef:
	/* 0x42ef: mov    DWORD PTR [rbx+0xf28],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3880ULL);
x86_l_42f5:
	/* 0x42f5: mov    r13d,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_32);
x86_l_42f8:
	/* 0x42f8: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_42fd:
	/* 0x42fd: jmp    5f53 <kprobe_unwind_native+0x5f53> */
	return 24403ULL;
x86_l_4302:
	/* 0x4302: mov    ecx,0xfa4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4004ULL);
x86_l_4307:
	/* 0x4307: mov    edx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_430c:
	/* 0x430c: jmp    42ef <kprobe_unwind_native+0x42ef> */
	goto x86_l_42ef;
x86_l_430e:
	/* 0x430e: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4315:
	/* 0x4315: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4318:
	/* 0x4318: je     2729 <kprobe_unwind_native+0x2729> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10025ULL;
	}
x86_l_431e:
	/* 0x431e: movabs rax,0x6174616420747075 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7022344801646571637ULL);
x86_l_4328:
	/* 0x4328: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_432d:
	/* 0x432d: movabs rax,0x72726f43202e7370 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8246776201762206576ULL);
x86_l_4337:
	/* 0x4337: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_433c:
	/* 0x433c: movabs rax,0x657473203631206e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310594677314494574ULL);
x86_l_4346:
	/* 0x4346: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_434b:
	/* 0x434b: movabs rax,0x6920686372616573 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575169349567210867ULL);
x86_l_4355:
	/* 0x4355: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_435a:
	/* 0x435a: movabs rax,0x622064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7070761801744998726ULL);
x86_l_4364:
	/* 0x4364: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4369:
	/* 0x4369: mov    DWORD PTR [rsp+0x37],0xa3f61 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 236223872865ULL);
x86_l_4371:
	/* 0x4371: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4376:
	/* 0x4376: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_437b:
	/* 0x437b: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4380:
	/* 0x4380: jmp    2d54 <kprobe_unwind_native+0x2d54> */
	return 11604ULL;
x86_l_4385:
	/* 0x4385: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_438c:
	/* 0x438c: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_438f:
	/* 0x438f: jne    4aae <kprobe_unwind_native+0x4aae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19118ULL;
	}
x86_l_4395:
	/* 0x4395: mov    eax,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_439c:
	/* 0x439c: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_439f:
	/* 0x439f: js     4452 <kprobe_unwind_native+0x4452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 17490ULL;
	}
x86_l_43a5:
	/* 0x43a5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&unwind_info_array)));
x86_l_43ac:
	/* 0x43ac: lea    rsi,[rsp+0x8c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_43b4:
	/* 0x43b4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_43b9:
	/* 0x43b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43bb:
	/* 0x43bb: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_43c0:
	/* 0x43c0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_43c3:
	/* 0x43c3: je     6323 <kprobe_unwind_native+0x6323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25379ULL;
	}
x86_l_43c9:
	/* 0x43c9: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_43ce:
	/* 0x43ce: mov    ebp,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_43d1:
	/* 0x43d1: movzx  eax,BYTE PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_43d5:
	/* 0x43d5: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_43d7:
	/* 0x43d7: je     4415 <kprobe_unwind_native+0x4415> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17429ULL;
	}
x86_l_43d9:
	/* 0x43d9: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_43e0:
	/* 0x43e0: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43e3:
	/* 0x43e3: jne    4a3a <kprobe_unwind_native+0x4a3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19002ULL;
	}
x86_l_43e9:
	/* 0x43e9: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_43eb:
	/* 0x43eb: and    cl,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_43ee:
	/* 0x43ee: movzx  ecx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_43f1:
	/* 0x43f1: cmp    r13d,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RCX, X86_WIDTH_32);
x86_l_43f4:
	/* 0x43f4: jl     4415 <kprobe_unwind_native+0x4415> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 17429ULL;
	}
x86_l_43f6:
	/* 0x43f6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_43f8:
	/* 0x43f8: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
	return 17402ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 17402ULL: goto x86_l_43fa;
	case 17405ULL: goto x86_l_43fd;
	case 17408ULL: goto x86_l_4400;
	case 17410ULL: goto x86_l_4402;
	case 17413ULL: goto x86_l_4405;
	case 17420ULL: goto x86_l_440c;
	case 17423ULL: goto x86_l_440f;
	case 17429ULL: goto x86_l_4415;
	case 17434ULL: goto x86_l_441a;
	case 17437ULL: goto x86_l_441d;
	case 17439ULL: goto x86_l_441f;
	case 17442ULL: goto x86_l_4422;
	case 17444ULL: goto x86_l_4424;
	case 17447ULL: goto x86_l_4427;
	case 17449ULL: goto x86_l_4429;
	case 17452ULL: goto x86_l_442c;
	case 17455ULL: goto x86_l_442f;
	case 17458ULL: goto x86_l_4432;
	case 17464ULL: goto x86_l_4438;
	case 17467ULL: goto x86_l_443b;
	case 17473ULL: goto x86_l_4441;
	case 17476ULL: goto x86_l_4444;
	case 17479ULL: goto x86_l_4447;
	case 17485ULL: goto x86_l_444d;
	case 17490ULL: goto x86_l_4452;
	case 17495ULL: goto x86_l_4457;
	case 17501ULL: goto x86_l_445d;
	case 17504ULL: goto x86_l_4460;
	case 17510ULL: goto x86_l_4466;
	case 17513ULL: goto x86_l_4469;
	case 17518ULL: goto x86_l_446e;
	case 17526ULL: goto x86_l_4476;
	case 17532ULL: goto x86_l_447c;
	case 17535ULL: goto x86_l_447f;
	case 17541ULL: goto x86_l_4485;
	case 17544ULL: goto x86_l_4488;
	case 17547ULL: goto x86_l_448b;
	case 17549ULL: goto x86_l_448d;
	case 17552ULL: goto x86_l_4490;
	case 17554ULL: goto x86_l_4492;
	case 17557ULL: goto x86_l_4495;
	case 17560ULL: goto x86_l_4498;
	case 17564ULL: goto x86_l_449c;
	case 17568ULL: goto x86_l_44a0;
	case 17575ULL: goto x86_l_44a7;
	case 17578ULL: goto x86_l_44aa;
	case 17584ULL: goto x86_l_44b0;
	case 17594ULL: goto x86_l_44ba;
	case 17599ULL: goto x86_l_44bf;
	case 17609ULL: goto x86_l_44c9;
	case 17614ULL: goto x86_l_44ce;
	case 17619ULL: goto x86_l_44d3;
	case 17624ULL: goto x86_l_44d8;
	case 17629ULL: goto x86_l_44dd;
	case 17634ULL: goto x86_l_44e2;
	case 17637ULL: goto x86_l_44e5;
	case 17639ULL: goto x86_l_44e7;
	case 17641ULL: goto x86_l_44e9;
	case 17646ULL: goto x86_l_44ee;
	case 17649ULL: goto x86_l_44f1;
	case 17655ULL: goto x86_l_44f7;
	case 17658ULL: goto x86_l_44fa;
	case 17663ULL: goto x86_l_44ff;
	case 17668ULL: goto x86_l_4504;
	case 17674ULL: goto x86_l_450a;
	case 17677ULL: goto x86_l_450d;
	case 17682ULL: goto x86_l_4512;
	case 17687ULL: goto x86_l_4517;
	case 17693ULL: goto x86_l_451d;
	case 17696ULL: goto x86_l_4520;
	case 17701ULL: goto x86_l_4525;
	case 17704ULL: goto x86_l_4528;
	case 17707ULL: goto x86_l_452b;
	case 17713ULL: goto x86_l_4531;
	case 17720ULL: goto x86_l_4538;
	case 17724ULL: goto x86_l_453c;
	case 17731ULL: goto x86_l_4543;
	case 17736ULL: goto x86_l_4548;
	case 17743ULL: goto x86_l_454f;
	case 17748ULL: goto x86_l_4554;
	case 17755ULL: goto x86_l_455b;
	case 17760ULL: goto x86_l_4560;
	case 17763ULL: goto x86_l_4563;
	case 17769ULL: goto x86_l_4569;
	case 17772ULL: goto x86_l_456c;
	case 17778ULL: goto x86_l_4572;
	case 17780ULL: goto x86_l_4574;
	case 17782ULL: goto x86_l_4576;
	case 17785ULL: goto x86_l_4579;
	case 17787ULL: goto x86_l_457b;
	case 17792ULL: goto x86_l_4580;
	case 17799ULL: goto x86_l_4587;
	case 17802ULL: goto x86_l_458a;
	case 17808ULL: goto x86_l_4590;
	case 17811ULL: goto x86_l_4593;
	case 17814ULL: goto x86_l_4596;
	case 17817ULL: goto x86_l_4599;
	case 17823ULL: goto x86_l_459f;
	case 17831ULL: goto x86_l_45a7;
	case 17833ULL: goto x86_l_45a9;
	case 17839ULL: goto x86_l_45af;
	case 17842ULL: goto x86_l_45b2;
	case 17848ULL: goto x86_l_45b8;
	case 17856ULL: goto x86_l_45c0;
	case 17861ULL: goto x86_l_45c5;
	case 17864ULL: goto x86_l_45c8;
	case 17868ULL: goto x86_l_45cc;
	case 17876ULL: goto x86_l_45d4;
	case 17881ULL: goto x86_l_45d9;
	case 17887ULL: goto x86_l_45df;
	case 17890ULL: goto x86_l_45e2;
	case 17894ULL: goto x86_l_45e6;
	case 17899ULL: goto x86_l_45eb;
	case 17902ULL: goto x86_l_45ee;
	case 17905ULL: goto x86_l_45f1;
	case 17910ULL: goto x86_l_45f6;
	case 17916ULL: goto x86_l_45fc;
	case 17924ULL: goto x86_l_4604;
	case 17931ULL: goto x86_l_460b;
	case 17939ULL: goto x86_l_4613;
	case 17946ULL: goto x86_l_461a;
	case 17954ULL: goto x86_l_4622;
	case 17961ULL: goto x86_l_4629;
	case 17969ULL: goto x86_l_4631;
	case 17976ULL: goto x86_l_4638;
	case 17984ULL: goto x86_l_4640;
	case 17991ULL: goto x86_l_4647;
	case 17999ULL: goto x86_l_464f;
	case 18006ULL: goto x86_l_4656;
	case 18014ULL: goto x86_l_465e;
	case 18021ULL: goto x86_l_4665;
	case 18029ULL: goto x86_l_466d;
	case 18036ULL: goto x86_l_4674;
	case 18043ULL: goto x86_l_467b;
	case 18050ULL: goto x86_l_4682;
	case 18053ULL: goto x86_l_4685;
	case 18059ULL: goto x86_l_468b;
	case 18069ULL: goto x86_l_4695;
	case 18074ULL: goto x86_l_469a;
	case 18084ULL: goto x86_l_46a4;
	case 18089ULL: goto x86_l_46a9;
	case 18094ULL: goto x86_l_46ae;
	case 18099ULL: goto x86_l_46b3;
	case 18104ULL: goto x86_l_46b8;
	case 18109ULL: goto x86_l_46bd;
	case 18111ULL: goto x86_l_46bf;
	case 18113ULL: goto x86_l_46c1;
	case 18118ULL: goto x86_l_46c6;
	case 18123ULL: goto x86_l_46cb;
	case 18126ULL: goto x86_l_46ce;
	case 18129ULL: goto x86_l_46d1;
	case 18132ULL: goto x86_l_46d4;
	case 18135ULL: goto x86_l_46d7;
	case 18137ULL: goto x86_l_46d9;
	case 18143ULL: goto x86_l_46df;
	case 18148ULL: goto x86_l_46e4;
	case 18153ULL: goto x86_l_46e9;
	case 18158ULL: goto x86_l_46ee;
	case 18163ULL: goto x86_l_46f3;
	case 18166ULL: goto x86_l_46f6;
	case 18168ULL: goto x86_l_46f8;
	case 18171ULL: goto x86_l_46fb;
	case 18173ULL: goto x86_l_46fd;
	case 18180ULL: goto x86_l_4704;
	case 18183ULL: goto x86_l_4707;
	case 18189ULL: goto x86_l_470d;
	case 18192ULL: goto x86_l_4710;
	case 18197ULL: goto x86_l_4715;
	case 18200ULL: goto x86_l_4718;
	case 18203ULL: goto x86_l_471b;
	case 18208ULL: goto x86_l_4720;
	case 18211ULL: goto x86_l_4723;
	case 18216ULL: goto x86_l_4728;
	case 18222ULL: goto x86_l_472e;
	case 18232ULL: goto x86_l_4738;
	case 18240ULL: goto x86_l_4740;
	case 18250ULL: goto x86_l_474a;
	case 18258ULL: goto x86_l_4752;
	case 18268ULL: goto x86_l_475c;
	case 18276ULL: goto x86_l_4764;
	case 18287ULL: goto x86_l_476f;
	case 18295ULL: goto x86_l_4777;
	case 18300ULL: goto x86_l_477c;
	case 18305ULL: goto x86_l_4781;
	case 18310ULL: goto x86_l_4786;
	case 18312ULL: goto x86_l_4788;
	case 18314ULL: goto x86_l_478a;
	case 18319ULL: goto x86_l_478f;
	case 18329ULL: goto x86_l_4799;
	case 18334ULL: goto x86_l_479e;
	case 18344ULL: goto x86_l_47a8;
	case 18349ULL: goto x86_l_47ad;
	case 18359ULL: goto x86_l_47b7;
	case 18364ULL: goto x86_l_47bc;
	case 18374ULL: goto x86_l_47c6;
	case 18379ULL: goto x86_l_47cb;
	case 18384ULL: goto x86_l_47d0;
	case 18389ULL: goto x86_l_47d5;
	case 18394ULL: goto x86_l_47da;
	case 18400ULL: goto x86_l_47e0;
	case 18407ULL: goto x86_l_47e7;
	case 18414ULL: goto x86_l_47ee;
	case 18419ULL: goto x86_l_47f3;
	case 18421ULL: goto x86_l_47f5;
	case 18424ULL: goto x86_l_47f8;
	case 18429ULL: goto x86_l_47fd;
	case 18439ULL: goto x86_l_4807;
	case 18447ULL: goto x86_l_480f;
	case 18457ULL: goto x86_l_4819;
	case 18465ULL: goto x86_l_4821;
	case 18475ULL: goto x86_l_482b;
	case 18483ULL: goto x86_l_4833;
	case 18493ULL: goto x86_l_483d;
	case 18501ULL: goto x86_l_4845;
	case 18511ULL: goto x86_l_484f;
	case 18519ULL: goto x86_l_4857;
	case 18529ULL: goto x86_l_4861;
	case 18537ULL: goto x86_l_4869;
	case 18545ULL: goto x86_l_4871;
	case 18550ULL: goto x86_l_4876;
	case 18555ULL: goto x86_l_487b;
	case 18559ULL: goto x86_l_487f;
	case 18564ULL: goto x86_l_4884;
	case 18566ULL: goto x86_l_4886;
	case 18568ULL: goto x86_l_4888;
	case 18575ULL: goto x86_l_488f;
	case 18578ULL: goto x86_l_4892;
	case 18584ULL: goto x86_l_4898;
	case 18589ULL: goto x86_l_489d;
	case 18599ULL: goto x86_l_48a7;
	case 18604ULL: goto x86_l_48ac;
	case 18614ULL: goto x86_l_48b6;
	case 18619ULL: goto x86_l_48bb;
	case 18629ULL: goto x86_l_48c5;
	case 18634ULL: goto x86_l_48ca;
	case 18644ULL: goto x86_l_48d4;
	case 18649ULL: goto x86_l_48d9;
	case 18659ULL: goto x86_l_48e3;
	case 18664ULL: goto x86_l_48e8;
	case 18674ULL: goto x86_l_48f2;
	case 18679ULL: goto x86_l_48f7;
	case 18684ULL: goto x86_l_48fc;
	case 18689ULL: goto x86_l_4901;
	case 18695ULL: goto x86_l_4907;
	case 18698ULL: goto x86_l_490a;
	case 18703ULL: goto x86_l_490f;
	case 18708ULL: goto x86_l_4914;
	case 18711ULL: goto x86_l_4917;
	case 18713ULL: goto x86_l_4919;
	case 18716ULL: goto x86_l_491c;
	case 18721ULL: goto x86_l_4921;
	case 18731ULL: goto x86_l_492b;
	case 18736ULL: goto x86_l_4930;
	case 18746ULL: goto x86_l_493a;
	case 18751ULL: goto x86_l_493f;
	case 18761ULL: goto x86_l_4949;
	case 18766ULL: goto x86_l_494e;
	case 18776ULL: goto x86_l_4958;
	case 18781ULL: goto x86_l_495d;
	case 18791ULL: goto x86_l_4967;
	case 18796ULL: goto x86_l_496c;
	case 18806ULL: goto x86_l_4976;
	case 18811ULL: goto x86_l_497b;
	case 18816ULL: goto x86_l_4980;
	case 18821ULL: goto x86_l_4985;
	case 18827ULL: goto x86_l_498b;
	case 18834ULL: goto x86_l_4992;
	case 18838ULL: goto x86_l_4996;
	case 18843ULL: goto x86_l_499b;
	case 18848ULL: goto x86_l_49a0;
	case 18850ULL: goto x86_l_49a2;
	case 18853ULL: goto x86_l_49a5;
	case 18858ULL: goto x86_l_49aa;
	case 18868ULL: goto x86_l_49b4;
	case 18876ULL: goto x86_l_49bc;
	case 18886ULL: goto x86_l_49c6;
	case 18894ULL: goto x86_l_49ce;
	case 18904ULL: goto x86_l_49d8;
	case 18912ULL: goto x86_l_49e0;
	case 18922ULL: goto x86_l_49ea;
	case 18930ULL: goto x86_l_49f2;
	case 18940ULL: goto x86_l_49fc;
	case 18948ULL: goto x86_l_4a04;
	case 18958ULL: goto x86_l_4a0e;
	case 18966ULL: goto x86_l_4a16;
	case 18974ULL: goto x86_l_4a1e;
	case 18979ULL: goto x86_l_4a23;
	case 18984ULL: goto x86_l_4a28;
	case 18988ULL: goto x86_l_4a2c;
	case 18993ULL: goto x86_l_4a31;
	case 18995ULL: goto x86_l_4a33;
	case 18997ULL: goto x86_l_4a35;
	case 19002ULL: goto x86_l_4a3a;
	case 19012ULL: goto x86_l_4a44;
	case 19017ULL: goto x86_l_4a49;
	case 19027ULL: goto x86_l_4a53;
	case 19032ULL: goto x86_l_4a58;
	case 19042ULL: goto x86_l_4a62;
	case 19047ULL: goto x86_l_4a67;
	case 19057ULL: goto x86_l_4a71;
	case 19062ULL: goto x86_l_4a76;
	case 19067ULL: goto x86_l_4a7b;
	case 19072ULL: goto x86_l_4a80;
	case 19077ULL: goto x86_l_4a85;
	case 19083ULL: goto x86_l_4a8b;
	case 19088ULL: goto x86_l_4a90;
	case 19094ULL: goto x86_l_4a96;
	case 19099ULL: goto x86_l_4a9b;
	case 19102ULL: goto x86_l_4a9e;
	case 19104ULL: goto x86_l_4aa0;
	case 19107ULL: goto x86_l_4aa3;
	case 19113ULL: goto x86_l_4aa9;
	case 19118ULL: goto x86_l_4aae;
	case 19128ULL: goto x86_l_4ab8;
	case 19133ULL: goto x86_l_4abd;
	case 19143ULL: goto x86_l_4ac7;
	case 19148ULL: goto x86_l_4acc;
	case 19158ULL: goto x86_l_4ad6;
	case 19163ULL: goto x86_l_4adb;
	case 19173ULL: goto x86_l_4ae5;
	case 19178ULL: goto x86_l_4aea;
	case 19188ULL: goto x86_l_4af4;
	case 19193ULL: goto x86_l_4af9;
	case 19203ULL: goto x86_l_4b03;
	case 19208ULL: goto x86_l_4b08;
	case 19213ULL: goto x86_l_4b0d;
	case 19218ULL: goto x86_l_4b12;
	case 19223ULL: goto x86_l_4b17;
	case 19230ULL: goto x86_l_4b1e;
	case 19235ULL: goto x86_l_4b23;
	case 19237ULL: goto x86_l_4b25;
	case 19239ULL: goto x86_l_4b27;
	case 19244ULL: goto x86_l_4b2c;
	case 19254ULL: goto x86_l_4b36;
	case 19259ULL: goto x86_l_4b3b;
	case 19269ULL: goto x86_l_4b45;
	case 19274ULL: goto x86_l_4b4a;
	case 19284ULL: goto x86_l_4b54;
	case 19289ULL: goto x86_l_4b59;
	case 19299ULL: goto x86_l_4b63;
	case 19304ULL: goto x86_l_4b68;
	case 19309ULL: goto x86_l_4b6d;
	case 19314ULL: goto x86_l_4b72;
	case 19319ULL: goto x86_l_4b77;
	case 19324ULL: goto x86_l_4b7c;
	case 19331ULL: goto x86_l_4b83;
	case 19336ULL: goto x86_l_4b88;
	case 19338ULL: goto x86_l_4b8a;
	case 19340ULL: goto x86_l_4b8c;
	case 19345ULL: goto x86_l_4b91;
	case 19355ULL: goto x86_l_4b9b;
	case 19360ULL: goto x86_l_4ba0;
	case 19370ULL: goto x86_l_4baa;
	case 19375ULL: goto x86_l_4baf;
	case 19380ULL: goto x86_l_4bb4;
	case 19385ULL: goto x86_l_4bb9;
	case 19390ULL: goto x86_l_4bbe;
	case 19396ULL: goto x86_l_4bc4;
	case 19399ULL: goto x86_l_4bc7;
	case 19404ULL: goto x86_l_4bcc;
	case 19409ULL: goto x86_l_4bd1;
	case 19411ULL: goto x86_l_4bd3;
	case 19413ULL: goto x86_l_4bd5;
	case 19416ULL: goto x86_l_4bd8;
	case 19419ULL: goto x86_l_4bdb;
	case 19422ULL: goto x86_l_4bde;
	case 19428ULL: goto x86_l_4be4;
	case 19436ULL: goto x86_l_4bec;
	case 19439ULL: goto x86_l_4bef;
	case 19441ULL: goto x86_l_4bf1;
	case 19449ULL: goto x86_l_4bf9;
	case 19452ULL: goto x86_l_4bfc;
	case 19454ULL: goto x86_l_4bfe;
	case 19459ULL: goto x86_l_4c03;
	case 19462ULL: goto x86_l_4c06;
	case 19467ULL: goto x86_l_4c0b;
	case 19471ULL: goto x86_l_4c0f;
	case 19475ULL: goto x86_l_4c13;
	case 19478ULL: goto x86_l_4c16;
	case 19481ULL: goto x86_l_4c19;
	case 19483ULL: goto x86_l_4c1b;
	case 19487ULL: goto x86_l_4c1f;
	case 19489ULL: goto x86_l_4c21;
	case 19492ULL: goto x86_l_4c24;
	default: return 0xffffffffffffffffULL;
	}
x86_l_43fa:
	/* 0x43fa: setns  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NS);
x86_l_43fd:
	/* 0x43fd: shl    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_4400:
	/* 0x4400: add    ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4402:
	/* 0x4402: add    ebp,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4294967288ULL);
x86_l_4405:
	/* 0x4405: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_440c:
	/* 0x440c: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_440f:
	/* 0x440f: jne    4b2c <kprobe_unwind_native+0x4b2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4b2c;
	}
x86_l_4415:
	/* 0x4415: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_441a:
	/* 0x441a: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_441d:
	/* 0x441d: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_441f:
	/* 0x441f: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_4422:
	/* 0x4422: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_4424:
	/* 0x4424: cmovns ecx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBP, X86_WIDTH_32, X86_CC_NS);
x86_l_4427:
	/* 0x4427: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_4429:
	/* 0x4429: and    edx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_442c:
	/* 0x442c: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_442f:
	/* 0x442f: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_4432:
	/* 0x4432: jg     4560 <kprobe_unwind_native+0x4560> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4560;
	}
x86_l_4438:
	/* 0x4438: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_443b:
	/* 0x443b: je     46ce <kprobe_unwind_native+0x46ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46ce;
	}
x86_l_4441:
	/* 0x4441: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_4444:
	/* 0x4444: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_4447:
	/* 0x4447: je     46cb <kprobe_unwind_native+0x46cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46cb;
	}
x86_l_444d:
	/* 0x444d: jmp    4c06 <kprobe_unwind_native+0x4c06> */
	goto x86_l_4c06;
x86_l_4452:
	/* 0x4452: and    eax,0xffff7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294934527ULL);
x86_l_4457:
	/* 0x4457: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_445d:
	/* 0x445d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4460:
	/* 0x4460: jg     44ee <kprobe_unwind_native+0x44ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_44ee;
	}
x86_l_4466:
	/* 0x4466: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4469:
	/* 0x4469: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_446e:
	/* 0x446e: mov    rcx,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_4476:
	/* 0x4476: je     6482 <kprobe_unwind_native+0x6482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25730ULL;
	}
x86_l_447c:
	/* 0x447c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_447f:
	/* 0x447f: jne    5f53 <kprobe_unwind_native+0x5f53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24403ULL;
	}
x86_l_4485:
	/* 0x4485: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4488:
	/* 0x4488: mov    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_448b:
	/* 0x448b: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_448d:
	/* 0x448d: and    ecx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_4490:
	/* 0x4490: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4492:
	/* 0x4492: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_4495:
	/* 0x4495: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_4498:
	/* 0x4498: lea    r13,[rax+rdx*8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_449c:
	/* 0x449c: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_44a0:
	/* 0x44a0: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_44a7:
	/* 0x44a7: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44aa:
	/* 0x44aa: je     4e1b <kprobe_unwind_native+0x4e1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19995ULL;
	}
x86_l_44b0:
	/* 0x44b0: movabs rax,0xa786c2578303d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541309ULL);
x86_l_44ba:
	/* 0x44ba: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_44bf:
	/* 0x44bf: movabs rax,0x616663202c544c50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018406059137322064ULL);
x86_l_44c9:
	/* 0x44c9: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44ce:
	/* 0x44ce: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44d3:
	/* 0x44d3: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_44d8:
	/* 0x44d8: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_44dd:
	/* 0x44dd: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_44e2:
	/* 0x44e2: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_44e5:
	/* 0x44e5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_44e7:
	/* 0x44e7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_44e9:
	/* 0x44e9: jmp    4e1b <kprobe_unwind_native+0x4e1b> */
	return 19995ULL;
x86_l_44ee:
	/* 0x44ee: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_44f1:
	/* 0x44f1: je     45c5 <kprobe_unwind_native+0x45c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45c5;
	}
x86_l_44f7:
	/* 0x44f7: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_44fa:
	/* 0x44fa: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_44ff:
	/* 0x44ff: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4504:
	/* 0x4504: jne    5f53 <kprobe_unwind_native+0x5f53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24403ULL;
	}
x86_l_450a:
	/* 0x450a: mov    rax,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_450d:
	/* 0x450d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4512:
	/* 0x4512: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4517:
	/* 0x4517: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_451d:
	/* 0x451d: mov    rdx,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4520:
	/* 0x4520: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4525:
	/* 0x4525: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4528:
	/* 0x4528: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_452b:
	/* 0x452b: jne    1647 <kprobe_unwind_native+0x1647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5703ULL;
	}
x86_l_4531:
	/* 0x4531: mov    rax,QWORD PTR [rbx+0xee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_4538:
	/* 0x4538: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_453c:
	/* 0x453c: mov    QWORD PTR [rbx+0xed8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_4543:
	/* 0x4543: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4548:
	/* 0x4548: mov    QWORD PTR [rbx+0xee0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_454f:
	/* 0x454f: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4554:
	/* 0x4554: mov    QWORD PTR [rbx+0xed0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_455b:
	/* 0x455b: jmp    4e56 <kprobe_unwind_native+0x4e56> */
	return 20054ULL;
x86_l_4560:
	/* 0x4560: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4563:
	/* 0x4563: je     46c6 <kprobe_unwind_native+0x46c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46c6;
	}
x86_l_4569:
	/* 0x4569: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_456c:
	/* 0x456c: jne    4c06 <kprobe_unwind_native+0x4c06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4c06;
	}
x86_l_4572:
	/* 0x4572: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_4574:
	/* 0x4574: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_4576:
	/* 0x4576: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_4579:
	/* 0x4579: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_457b:
	/* 0x457b: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4580:
	/* 0x4580: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4587:
	/* 0x4587: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_458a:
	/* 0x458a: jne    4b91 <kprobe_unwind_native+0x4b91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4b91;
	}
x86_l_4590:
	/* 0x4590: and    ebp,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_4593:
	/* 0x4593: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4596:
	/* 0x4596: cmp    ebp,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_4599:
	/* 0x4599: jg     4be4 <kprobe_unwind_native+0x4be4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4be4;
	}
x86_l_459f:
	/* 0x459f: mov    rax,QWORD PTR [rsp+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_45a7:
	/* 0x45a7: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_45a9:
	/* 0x45a9: je     4bfe <kprobe_unwind_native+0x4bfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bfe;
	}
x86_l_45af:
	/* 0x45af: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_45b2:
	/* 0x45b2: jne    4c06 <kprobe_unwind_native+0x4c06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4c06;
	}
x86_l_45b8:
	/* 0x45b8: mov    rax,QWORD PTR [rsp+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_45c0:
	/* 0x45c0: jmp    4bfe <kprobe_unwind_native+0x4bfe> */
	goto x86_l_4bfe;
x86_l_45c5:
	/* 0x45c5: mov    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45c8:
	/* 0x45c8: add    rax,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_45cc:
	/* 0x45cc: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_45d4:
	/* 0x45d4: mov    ecx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 144ULL);
x86_l_45d9:
	/* 0x45d9: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_45df:
	/* 0x45df: mov    rdx,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45e2:
	/* 0x45e2: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_45e6:
	/* 0x45e6: mov    esi,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 144ULL);
x86_l_45eb:
	/* 0x45eb: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_45ee:
	/* 0x45ee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_45f1:
	/* 0x45f1: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_45f6:
	/* 0x45f6: jne    1647 <kprobe_unwind_native+0x1647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5703ULL;
	}
x86_l_45fc:
	/* 0x45fc: mov    rax,QWORD PTR [rsp+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_4604:
	/* 0x4604: mov    QWORD PTR [rbx+0xee8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3816ULL);
x86_l_460b:
	/* 0x460b: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4613:
	/* 0x4613: mov    QWORD PTR [rbx+0xef0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3824ULL);
x86_l_461a:
	/* 0x461a: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_4622:
	/* 0x4622: mov    QWORD PTR [rbx+0xef8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3832ULL);
x86_l_4629:
	/* 0x4629: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_4631:
	/* 0x4631: mov    QWORD PTR [rbx+0xf00],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3840ULL);
x86_l_4638:
	/* 0x4638: mov    rax,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_4640:
	/* 0x4640: mov    QWORD PTR [rbx+0xf08],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3848ULL);
x86_l_4647:
	/* 0x4647: mov    rax,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_464f:
	/* 0x464f: mov    QWORD PTR [rbx+0xee0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_4656:
	/* 0x4656: mov    rax,QWORD PTR [rsp+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_465e:
	/* 0x465e: mov    QWORD PTR [rbx+0xed8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_4665:
	/* 0x4665: mov    rax,QWORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_466d:
	/* 0x466d: mov    QWORD PTR [rbx+0xed0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_4674:
	/* 0x4674: mov    BYTE PTR [rbx+0xf30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16698832846848ULL);
x86_l_467b:
	/* 0x467b: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4682:
	/* 0x4682: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4685:
	/* 0x4685: je     4e5d <kprobe_unwind_native+0x4e5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20061ULL;
	}
x86_l_468b:
	/* 0x468b: movabs rax,0xa656d61726620 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926270227834400ULL);
x86_l_4695:
	/* 0x4695: mov    QWORD PTR [rsp+0x16],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_469a:
	/* 0x469a: movabs rax,0x66206c616e676973 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7359000956843288947ULL);
x86_l_46a4:
	/* 0x46a4: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46a9:
	/* 0x46a9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46ae:
	/* 0x46ae: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_46b3:
	/* 0x46b3: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_46b8:
	/* 0x46b8: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_46bd:
	/* 0x46bd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_46bf:
	/* 0x46bf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_46c1:
	/* 0x46c1: jmp    4e5d <kprobe_unwind_native+0x4e5d> */
	return 20061ULL;
x86_l_46c6:
	/* 0x46c6: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_46cb:
	/* 0x46cb: mov    r13,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46ce:
	/* 0x46ce: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_46d1:
	/* 0x46d1: movsxd r13,ecx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_46d4:
	/* 0x46d4: add    r13,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_46d7:
	/* 0x46d7: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_46d9:
	/* 0x46d9: jns    4c06 <kprobe_unwind_native+0x4c06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_4c06;
	}
x86_l_46df:
	/* 0x46df: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_46e4:
	/* 0x46e4: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_46e9:
	/* 0x46e9: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_46ee:
	/* 0x46ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46f3:
	/* 0x46f3: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_46f6:
	/* 0x46f6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_46f8:
	/* 0x46f8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_46fb:
	/* 0x46fb: je     4715 <kprobe_unwind_native+0x4715> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4715;
	}
x86_l_46fd:
	/* 0x46fd: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4704:
	/* 0x4704: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4707:
	/* 0x4707: jne    5219 <kprobe_unwind_native+0x5219> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 21017ULL;
	}
x86_l_470d:
	/* 0x470d: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4710:
	/* 0x4710: jmp    4c06 <kprobe_unwind_native+0x4c06> */
	goto x86_l_4c06;
x86_l_4715:
	/* 0x4715: shl    ebp,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_4718:
	/* 0x4718: and    ebp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 56ULL);
x86_l_471b:
	/* 0x471b: add    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_4720:
	/* 0x4720: mov    r13,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_4723:
	/* 0x4723: jmp    4c06 <kprobe_unwind_native+0x4c06> */
	goto x86_l_4c06;
x86_l_4728:
	/* 0x4728: mov    edx,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_472e:
	/* 0x472e: movabs rax,0x3d3d206425206576 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4412718824384652662ULL);
x86_l_4738:
	/* 0x4738: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_4740:
	/* 0x4740: movabs rax,0x6974616e5f646e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598805597955583593ULL);
x86_l_474a:
	/* 0x474a: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4752:
	/* 0x4752: movabs rax,0x776e75203d3d3d3d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8605944719278423357ULL);
x86_l_475c:
	/* 0x475c: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4764:
	/* 0x4764: mov    DWORD PTR [rsp+0xb8],0xa3d3d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 790274653501ULL);
x86_l_476f:
	/* 0x476f: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4777:
	/* 0x4777: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_477c:
	/* 0x477c: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4781:
	/* 0x4781: mov    esi,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 28ULL);
x86_l_4786:
	/* 0x4786: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4788:
	/* 0x4788: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_478a:
	/* 0x478a: jmp    39e6 <kprobe_unwind_native+0x39e6> */
	return 14822ULL;
x86_l_478f:
	/* 0x478f: movabs rax,0xa786c253a786c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 754471844735118373ULL);
x86_l_4799:
	/* 0x4799: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_479e:
	/* 0x479e: movabs rax,0x20726f662061746c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338053640979313772ULL);
x86_l_47a8:
	/* 0x47a8: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_47ad:
	/* 0x47ad: movabs rax,0x6564206b63617473 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7306000141102707827ULL);
x86_l_47b7:
	/* 0x47b7: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_47bc:
	/* 0x47bc: movabs rax,0x207075206b6f6f4c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337496988707155788ULL);
x86_l_47c6:
	/* 0x47c6: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47cb:
	/* 0x47cb: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_47d0:
	/* 0x47d0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47d5:
	/* 0x47d5: mov    eax,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_47da:
	/* 0x47da: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_47e0:
	/* 0x47e0: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_47e7:
	/* 0x47e7: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_47ee:
	/* 0x47ee: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_47f3:
	/* 0x47f3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_47f5:
	/* 0x47f5: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_47f8:
	/* 0x47f8: jmp    3b78 <kprobe_unwind_native+0x3b78> */
	return 15224ULL;
x86_l_47fd:
	/* 0x47fd: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_4807:
	/* 0x4807: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_480f:
	/* 0x480f: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_4819:
	/* 0x4819: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_4821:
	/* 0x4821: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_482b:
	/* 0x482b: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_4833:
	/* 0x4833: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_483d:
	/* 0x483d: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_4845:
	/* 0x4845: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_484f:
	/* 0x484f: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4857:
	/* 0x4857: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_4861:
	/* 0x4861: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4869:
	/* 0x4869: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4871:
	/* 0x4871: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_4876:
	/* 0x4876: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_487b:
	/* 0x487b: mov    edx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_487f:
	/* 0x487f: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_4884:
	/* 0x4884: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4886:
	/* 0x4886: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4888:
	/* 0x4888: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_488f:
	/* 0x488f: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4892:
	/* 0x4892: je     3ac6 <kprobe_unwind_native+0x3ac6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15046ULL;
	}
x86_l_4898:
	/* 0x4898: jmp    3a1d <kprobe_unwind_native+0x3a1d> */
	return 14877ULL;
x86_l_489d:
	/* 0x489d: movabs rax,0xa296425204449 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2860259863446601ULL);
x86_l_48a7:
	/* 0x48a7: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_48ac:
	/* 0x48ac: movabs rax,0x70616d2820756c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8097873624099548197ULL);
x86_l_48b6:
	/* 0x48b6: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_48bb:
	/* 0x48bb: movabs rax,0x206f7420756c2520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414386373920ULL);
x86_l_48c5:
	/* 0x48c5: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_48ca:
	/* 0x48ca: movabs rax,0x6d6f726620656220 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7885647255504773664ULL);
x86_l_48d4:
	/* 0x48d4: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_48d9:
	/* 0x48d9: movabs rax,0x646c756f68732073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7236287822631739507ULL);
x86_l_48e3:
	/* 0x48e3: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_48e8:
	/* 0x48e8: movabs rax,0x6c61767265746e49 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7809653462537629257ULL);
x86_l_48f2:
	/* 0x48f2: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48f7:
	/* 0x48f7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48fc:
	/* 0x48fc: mov    eax,0x30 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 48ULL);
x86_l_4901:
	/* 0x4901: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_4907:
	/* 0x4907: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_490a:
	/* 0x490a: movzx  r8d,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_490f:
	/* 0x490f: mov    esi,0x30 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 48ULL);
x86_l_4914:
	/* 0x4914: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4917:
	/* 0x4917: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4919:
	/* 0x4919: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_491c:
	/* 0x491c: jmp    3d5c <kprobe_unwind_native+0x3d5c> */
	return 15708ULL;
x86_l_4921:
	/* 0x4921: movabs rax,0xa6425206f666e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860387845742ULL);
x86_l_492b:
	/* 0x492b: mov    QWORD PTR [rsp+0x35],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_4930:
	/* 0x4930: movabs rax,0x6f666e49646e6977 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8027224647331113335ULL);
x86_l_493a:
	/* 0x493a: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_493f:
	/* 0x493f: movabs rax,0x6e75202c78257830 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7959303291813591088ULL);
x86_l_4949:
	/* 0x4949: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_494e:
	/* 0x494e: movabs rax,0x20776f4c72646461 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2339460905569641569ULL);
x86_l_4958:
	/* 0x4958: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_495d:
	/* 0x495d: movabs rax,0x202c642520786564 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2318338018810291556ULL);
x86_l_4967:
	/* 0x4967: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_496c:
	/* 0x496c: movabs rax,0x6e692061746c6564 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7955925819663869284ULL);
x86_l_4976:
	/* 0x4976: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_497b:
	/* 0x497b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4980:
	/* 0x4980: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4985:
	/* 0x4985: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_498b:
	/* 0x498b: mov    edx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4992:
	/* 0x4992: movzx  ecx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4996:
	/* 0x4996: movzx  r8d,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_499b:
	/* 0x499b: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_49a0:
	/* 0x49a0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_49a2:
	/* 0x49a2: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_49a5:
	/* 0x49a5: jmp    4272 <kprobe_unwind_native+0x4272> */
	return 17010ULL;
x86_l_49aa:
	/* 0x49aa: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_49b4:
	/* 0x49b4: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_49bc:
	/* 0x49bc: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_49c6:
	/* 0x49c6: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_49ce:
	/* 0x49ce: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_49d8:
	/* 0x49d8: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_49e0:
	/* 0x49e0: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_49ea:
	/* 0x49ea: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_49f2:
	/* 0x49f2: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_49fc:
	/* 0x49fc: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4a04:
	/* 0x4a04: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_4a0e:
	/* 0x4a0e: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4a16:
	/* 0x4a16: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4a1e:
	/* 0x4a1e: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_4a23:
	/* 0x4a23: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4a28:
	/* 0x4a28: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4a2c:
	/* 0x4a2c: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_4a31:
	/* 0x4a31: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4a33:
	/* 0x4a33: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4a35:
	/* 0x4a35: jmp    39c7 <kprobe_unwind_native+0x39c7> */
	return 14791ULL;
x86_l_4a3a:
	/* 0x4a3a: movabs rax,0xa78323023252061 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 754408119914012769ULL);
x86_l_4a44:
	/* 0x4a44: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4a49:
	/* 0x4a49: movabs rax,0x746c656420646567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8389191686598976871ULL);
x86_l_4a53:
	/* 0x4a53: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4a58:
	/* 0x4a58: movabs rax,0x72656d202c642520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243114677922702624ULL);
x86_l_4a62:
	/* 0x4a62: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a67:
	/* 0x4a67: movabs rax,0x6666694472646441 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7378700782191010881ULL);
x86_l_4a71:
	/* 0x4a71: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a76:
	/* 0x4a76: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_4a7b:
	/* 0x4a7b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a80:
	/* 0x4a80: mov    eax,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_4a85:
	/* 0x4a85: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_4a8b:
	/* 0x4a8b: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4a90:
	/* 0x4a90: movzx  ecx,BYTE PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_4a96:
	/* 0x4a96: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_4a9b:
	/* 0x4a9b: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_4a9e:
	/* 0x4a9e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4aa0:
	/* 0x4aa0: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4aa3:
	/* 0x4aa3: movzx  eax,BYTE PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_4aa9:
	/* 0x4aa9: jmp    43e9 <kprobe_unwind_native+0x43e9> */
	return 17385ULL;
x86_l_4aae:
	/* 0x4aae: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_4ab8:
	/* 0x4ab8: mov    QWORD PTR [rsp+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_4abd:
	/* 0x4abd: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_4ac7:
	/* 0x4ac7: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4acc:
	/* 0x4acc: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_4ad6:
	/* 0x4ad6: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4adb:
	/* 0x4adb: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_4ae5:
	/* 0x4ae5: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4aea:
	/* 0x4aea: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_4af4:
	/* 0x4af4: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4af9:
	/* 0x4af9: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_4b03:
	/* 0x4b03: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b08:
	/* 0x4b08: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b0d:
	/* 0x4b0d: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_4b12:
	/* 0x4b12: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4b17:
	/* 0x4b17: mov    edx,DWORD PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_4b1e:
	/* 0x4b1e: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_4b23:
	/* 0x4b23: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4b25:
	/* 0x4b25: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4b27:
	/* 0x4b27: jmp    4395 <kprobe_unwind_native+0x4395> */
	return 17301ULL;
x86_l_4b2c:
	/* 0x4b2c: movabs rax,0xa64253d61746c65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 748764383608597605ULL);
x86_l_4b36:
	/* 0x4b36: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4b3b:
	/* 0x4b3b: movabs rax,0x44616663203a6863 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4927332043248527459ULL);
x86_l_4b45:
	/* 0x4b45: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4b4a:
	/* 0x4b4a: movabs rax,0x74616d2061746c65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8386103966981975141ULL);
x86_l_4b54:
	/* 0x4b54: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b59:
	/* 0x4b59: movabs rax,0x642064656772654d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7214876989737559373ULL);
x86_l_4b63:
	/* 0x4b63: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b68:
	/* 0x4b68: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_4b6d:
	/* 0x4b6d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b72:
	/* 0x4b72: mov    eax,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_4b77:
	/* 0x4b77: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4b7c:
	/* 0x4b7c: mov    edx,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_4b83:
	/* 0x4b83: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_4b88:
	/* 0x4b88: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4b8a:
	/* 0x4b8a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4b8c:
	/* 0x4b8c: jmp    4415 <kprobe_unwind_native+0x4415> */
	goto x86_l_4415;
x86_l_4b91:
	/* 0x4b91: movabs rax,0xa756c252b642572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 753627419551999346ULL);
x86_l_4b9b:
	/* 0x4b9b: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4ba0:
	/* 0x4ba0: movabs rax,0x203a646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2322278983241526901ULL);
x86_l_4baa:
	/* 0x4baa: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4baf:
	/* 0x4baf: mov    BYTE PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4bb4:
	/* 0x4bb4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4bb9:
	/* 0x4bb9: mov    eax,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_4bbe:
	/* 0x4bbe: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_4bc4:
	/* 0x4bc4: and    ebp,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_4bc7:
	/* 0x4bc7: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4bcc:
	/* 0x4bcc: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_4bd1:
	/* 0x4bd1: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_4bd3:
	/* 0x4bd3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4bd5:
	/* 0x4bd5: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4bd8:
	/* 0x4bd8: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4bdb:
	/* 0x4bdb: cmp    ebp,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_4bde:
	/* 0x4bde: jle    459f <kprobe_unwind_native+0x459f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_459f;
	}
x86_l_4be4:
	/* 0x4be4: mov    rax,QWORD PTR [rsp+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_4bec:
	/* 0x4bec: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_4bef:
	/* 0x4bef: je     4bfe <kprobe_unwind_native+0x4bfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bfe;
	}
x86_l_4bf1:
	/* 0x4bf1: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4bf9:
	/* 0x4bf9: cmp    ebp,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 15ULL);
x86_l_4bfc:
	/* 0x4bfc: jne    4c06 <kprobe_unwind_native+0x4c06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4c06;
	}
x86_l_4bfe:
	/* 0x4bfe: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4c03:
	/* 0x4c03: add    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4c06:
	/* 0x4c06: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4c0b:
	/* 0x4c0b: movzx  eax,BYTE PTR [rcx+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_4c0f:
	/* 0x4c0f: mov    r12d,DWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c13:
	/* 0x4c13: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_4c16:
	/* 0x4c16: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_4c19:
	/* 0x4c19: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_4c1b:
	/* 0x4c1b: cmovns ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_NS);
x86_l_4c1f:
	/* 0x4c1f: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_4c21:
	/* 0x4c21: and    edx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_4c24:
	/* 0x4c24: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
	return 19495ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 19495ULL: goto x86_l_4c27;
	case 19497ULL: goto x86_l_4c29;
	case 19500ULL: goto x86_l_4c2c;
	case 19503ULL: goto x86_l_4c2f;
	case 19505ULL: goto x86_l_4c31;
	case 19508ULL: goto x86_l_4c34;
	case 19511ULL: goto x86_l_4c37;
	case 19513ULL: goto x86_l_4c39;
	case 19518ULL: goto x86_l_4c3e;
	case 19521ULL: goto x86_l_4c41;
	case 19523ULL: goto x86_l_4c43;
	case 19526ULL: goto x86_l_4c46;
	case 19532ULL: goto x86_l_4c4c;
	case 19535ULL: goto x86_l_4c4f;
	case 19537ULL: goto x86_l_4c51;
	case 19540ULL: goto x86_l_4c54;
	case 19542ULL: goto x86_l_4c56;
	case 19547ULL: goto x86_l_4c5b;
	case 19554ULL: goto x86_l_4c62;
	case 19557ULL: goto x86_l_4c65;
	case 19563ULL: goto x86_l_4c6b;
	case 19567ULL: goto x86_l_4c6f;
	case 19571ULL: goto x86_l_4c73;
	case 19577ULL: goto x86_l_4c79;
	case 19585ULL: goto x86_l_4c81;
	case 19588ULL: goto x86_l_4c84;
	case 19594ULL: goto x86_l_4c8a;
	case 19598ULL: goto x86_l_4c8e;
	case 19604ULL: goto x86_l_4c94;
	case 19612ULL: goto x86_l_4c9c;
	case 19617ULL: goto x86_l_4ca1;
	case 19622ULL: goto x86_l_4ca6;
	case 19625ULL: goto x86_l_4ca9;
	case 19628ULL: goto x86_l_4cac;
	case 19631ULL: goto x86_l_4caf;
	case 19633ULL: goto x86_l_4cb1;
	case 19639ULL: goto x86_l_4cb7;
	case 19644ULL: goto x86_l_4cbc;
	case 19649ULL: goto x86_l_4cc1;
	case 19654ULL: goto x86_l_4cc6;
	case 19659ULL: goto x86_l_4ccb;
	case 19662ULL: goto x86_l_4cce;
	case 19664ULL: goto x86_l_4cd0;
	case 19667ULL: goto x86_l_4cd3;
	case 19673ULL: goto x86_l_4cd9;
	case 19680ULL: goto x86_l_4ce0;
	case 19683ULL: goto x86_l_4ce3;
	case 19689ULL: goto x86_l_4ce9;
	case 19699ULL: goto x86_l_4cf3;
	case 19704ULL: goto x86_l_4cf8;
	case 19714ULL: goto x86_l_4d02;
	case 19719ULL: goto x86_l_4d07;
	case 19729ULL: goto x86_l_4d11;
	case 19734ULL: goto x86_l_4d16;
	case 19744ULL: goto x86_l_4d20;
	case 19749ULL: goto x86_l_4d25;
	case 19759ULL: goto x86_l_4d2f;
	case 19764ULL: goto x86_l_4d34;
	case 19772ULL: goto x86_l_4d3c;
	case 19777ULL: goto x86_l_4d41;
	case 19782ULL: goto x86_l_4d46;
	case 19787ULL: goto x86_l_4d4b;
	case 19792ULL: goto x86_l_4d50;
	case 19795ULL: goto x86_l_4d53;
	case 19797ULL: goto x86_l_4d55;
	case 19799ULL: goto x86_l_4d57;
	case 19804ULL: goto x86_l_4d5c;
	case 19808ULL: goto x86_l_4d60;
	case 19812ULL: goto x86_l_4d64;
	case 19817ULL: goto x86_l_4d69;
	case 19820ULL: goto x86_l_4d6c;
	case 19822ULL: goto x86_l_4d6e;
	case 19832ULL: goto x86_l_4d78;
	case 19837ULL: goto x86_l_4d7d;
	case 19847ULL: goto x86_l_4d87;
	case 19852ULL: goto x86_l_4d8c;
	case 19857ULL: goto x86_l_4d91;
	case 19862ULL: goto x86_l_4d96;
	case 19867ULL: goto x86_l_4d9b;
	case 19873ULL: goto x86_l_4da1;
	case 19877ULL: goto x86_l_4da5;
	case 19882ULL: goto x86_l_4daa;
	case 19887ULL: goto x86_l_4daf;
	case 19890ULL: goto x86_l_4db2;
	case 19892ULL: goto x86_l_4db4;
	case 19895ULL: goto x86_l_4db7;
	case 19899ULL: goto x86_l_4dbb;
	case 19905ULL: goto x86_l_4dc1;
	case 19913ULL: goto x86_l_4dc9;
	case 19917ULL: goto x86_l_4dcd;
	case 19919ULL: goto x86_l_4dcf;
	case 19927ULL: goto x86_l_4dd7;
	case 19931ULL: goto x86_l_4ddb;
	case 19933ULL: goto x86_l_4ddd;
	case 19938ULL: goto x86_l_4de2;
	case 19941ULL: goto x86_l_4de5;
	case 19944ULL: goto x86_l_4de8;
	case 19946ULL: goto x86_l_4dea;
	case 19951ULL: goto x86_l_4def;
	case 19956ULL: goto x86_l_4df4;
	case 19961ULL: goto x86_l_4df9;
	case 19966ULL: goto x86_l_4dfe;
	case 19969ULL: goto x86_l_4e01;
	case 19971ULL: goto x86_l_4e03;
	case 19973ULL: goto x86_l_4e05;
	case 19978ULL: goto x86_l_4e0a;
	case 19981ULL: goto x86_l_4e0d;
	case 19983ULL: goto x86_l_4e0f;
	case 19988ULL: goto x86_l_4e14;
	case 19995ULL: goto x86_l_4e1b;
	case 19998ULL: goto x86_l_4e1e;
	case 20003ULL: goto x86_l_4e23;
	case 20009ULL: goto x86_l_4e29;
	case 20013ULL: goto x86_l_4e2d;
	case 20018ULL: goto x86_l_4e32;
	case 20023ULL: goto x86_l_4e37;
	case 20031ULL: goto x86_l_4e3f;
	case 20036ULL: goto x86_l_4e44;
	case 20038ULL: goto x86_l_4e46;
	case 20041ULL: goto x86_l_4e49;
	case 20047ULL: goto x86_l_4e4f;
	case 20054ULL: goto x86_l_4e56;
	case 20061ULL: goto x86_l_4e5d;
	case 20069ULL: goto x86_l_4e65;
	case 20076ULL: goto x86_l_4e6c;
	case 20081ULL: goto x86_l_4e71;
	case 20086ULL: goto x86_l_4e76;
	case 20088ULL: goto x86_l_4e78;
	case 20091ULL: goto x86_l_4e7b;
	case 20097ULL: goto x86_l_4e81;
	case 20100ULL: goto x86_l_4e84;
	case 20102ULL: goto x86_l_4e86;
	case 20109ULL: goto x86_l_4e8d;
	case 20112ULL: goto x86_l_4e90;
	case 20118ULL: goto x86_l_4e96;
	case 20128ULL: goto x86_l_4ea0;
	case 20136ULL: goto x86_l_4ea8;
	case 20146ULL: goto x86_l_4eb2;
	case 20154ULL: goto x86_l_4eba;
	case 20164ULL: goto x86_l_4ec4;
	case 20172ULL: goto x86_l_4ecc;
	case 20182ULL: goto x86_l_4ed6;
	case 20190ULL: goto x86_l_4ede;
	case 20198ULL: goto x86_l_4ee6;
	case 20203ULL: goto x86_l_4eeb;
	case 20209ULL: goto x86_l_4ef1;
	case 20217ULL: goto x86_l_4ef9;
	case 20220ULL: goto x86_l_4efc;
	case 20223ULL: goto x86_l_4eff;
	case 20228ULL: goto x86_l_4f04;
	case 20231ULL: goto x86_l_4f07;
	case 20236ULL: goto x86_l_4f0c;
	case 20238ULL: goto x86_l_4f0e;
	case 20241ULL: goto x86_l_4f11;
	case 20248ULL: goto x86_l_4f18;
	case 20250ULL: goto x86_l_4f1a;
	case 20252ULL: goto x86_l_4f1c;
	case 20259ULL: goto x86_l_4f23;
	case 20262ULL: goto x86_l_4f26;
	case 20268ULL: goto x86_l_4f2c;
	case 20270ULL: goto x86_l_4f2e;
	case 20278ULL: goto x86_l_4f36;
	case 20281ULL: goto x86_l_4f39;
	case 20284ULL: goto x86_l_4f3c;
	case 20290ULL: goto x86_l_4f42;
	case 20292ULL: goto x86_l_4f44;
	case 20298ULL: goto x86_l_4f4a;
	case 20308ULL: goto x86_l_4f54;
	case 20311ULL: goto x86_l_4f57;
	case 20317ULL: goto x86_l_4f5d;
	case 20324ULL: goto x86_l_4f64;
	case 20330ULL: goto x86_l_4f6a;
	case 20332ULL: goto x86_l_4f6c;
	case 20340ULL: goto x86_l_4f74;
	case 20346ULL: goto x86_l_4f7a;
	case 20353ULL: goto x86_l_4f81;
	case 20360ULL: goto x86_l_4f88;
	case 20365ULL: goto x86_l_4f8d;
	case 20370ULL: goto x86_l_4f92;
	case 20372ULL: goto x86_l_4f94;
	case 20375ULL: goto x86_l_4f97;
	case 20381ULL: goto x86_l_4f9d;
	case 20385ULL: goto x86_l_4fa1;
	case 20388ULL: goto x86_l_4fa4;
	case 20398ULL: goto x86_l_4fae;
	case 20401ULL: goto x86_l_4fb1;
	case 20408ULL: goto x86_l_4fb8;
	case 20411ULL: goto x86_l_4fbb;
	case 20418ULL: goto x86_l_4fc2;
	case 20422ULL: goto x86_l_4fc6;
	case 20425ULL: goto x86_l_4fc9;
	case 20428ULL: goto x86_l_4fcc;
	case 20435ULL: goto x86_l_4fd3;
	case 20442ULL: goto x86_l_4fda;
	case 20445ULL: goto x86_l_4fdd;
	case 20451ULL: goto x86_l_4fe3;
	case 20455ULL: goto x86_l_4fe7;
	case 20461ULL: goto x86_l_4fed;
	case 20468ULL: goto x86_l_4ff4;
	case 20473ULL: goto x86_l_4ff9;
	case 20480ULL: goto x86_l_5000;
	case 20487ULL: goto x86_l_5007;
	case 20492ULL: goto x86_l_500c;
	case 20497ULL: goto x86_l_5011;
	case 20499ULL: goto x86_l_5013;
	case 20505ULL: goto x86_l_5019;
	case 20508ULL: goto x86_l_501c;
	case 20514ULL: goto x86_l_5022;
	case 20517ULL: goto x86_l_5025;
	case 20520ULL: goto x86_l_5028;
	case 20522ULL: goto x86_l_502a;
	case 20526ULL: goto x86_l_502e;
	case 20528ULL: goto x86_l_5030;
	case 20532ULL: goto x86_l_5034;
	case 20538ULL: goto x86_l_503a;
	case 20542ULL: goto x86_l_503e;
	case 20548ULL: goto x86_l_5044;
	case 20555ULL: goto x86_l_504b;
	case 20558ULL: goto x86_l_504e;
	case 20564ULL: goto x86_l_5054;
	case 20570ULL: goto x86_l_505a;
	case 20574ULL: goto x86_l_505e;
	case 20577ULL: goto x86_l_5061;
	case 20583ULL: goto x86_l_5067;
	case 20590ULL: goto x86_l_506e;
	case 20593ULL: goto x86_l_5071;
	case 20599ULL: goto x86_l_5077;
	case 20609ULL: goto x86_l_5081;
	case 20617ULL: goto x86_l_5089;
	case 20627ULL: goto x86_l_5093;
	case 20635ULL: goto x86_l_509b;
	case 20645ULL: goto x86_l_50a5;
	case 20653ULL: goto x86_l_50ad;
	case 20664ULL: goto x86_l_50b8;
	case 20672ULL: goto x86_l_50c0;
	case 20677ULL: goto x86_l_50c5;
	case 20682ULL: goto x86_l_50ca;
	case 20687ULL: goto x86_l_50cf;
	case 20689ULL: goto x86_l_50d1;
	case 20691ULL: goto x86_l_50d3;
	case 20696ULL: goto x86_l_50d8;
	case 20706ULL: goto x86_l_50e2;
	case 20714ULL: goto x86_l_50ea;
	case 20724ULL: goto x86_l_50f4;
	case 20732ULL: goto x86_l_50fc;
	case 20742ULL: goto x86_l_5106;
	case 20750ULL: goto x86_l_510e;
	case 20760ULL: goto x86_l_5118;
	case 20768ULL: goto x86_l_5120;
	case 20778ULL: goto x86_l_512a;
	case 20786ULL: goto x86_l_5132;
	case 20796ULL: goto x86_l_513c;
	case 20804ULL: goto x86_l_5144;
	case 20812ULL: goto x86_l_514c;
	case 20820ULL: goto x86_l_5154;
	case 20825ULL: goto x86_l_5159;
	case 20830ULL: goto x86_l_515e;
	case 20836ULL: goto x86_l_5164;
	case 20841ULL: goto x86_l_5169;
	case 20843ULL: goto x86_l_516b;
	case 20845ULL: goto x86_l_516d;
	case 20852ULL: goto x86_l_5174;
	case 20862ULL: goto x86_l_517e;
	case 20865ULL: goto x86_l_5181;
	case 20871ULL: goto x86_l_5187;
	case 20876ULL: goto x86_l_518c;
	case 20886ULL: goto x86_l_5196;
	case 20891ULL: goto x86_l_519b;
	case 20901ULL: goto x86_l_51a5;
	case 20906ULL: goto x86_l_51aa;
	case 20916ULL: goto x86_l_51b4;
	case 20921ULL: goto x86_l_51b9;
	case 20931ULL: goto x86_l_51c3;
	case 20936ULL: goto x86_l_51c8;
	case 20946ULL: goto x86_l_51d2;
	case 20951ULL: goto x86_l_51d7;
	case 20961ULL: goto x86_l_51e1;
	case 20966ULL: goto x86_l_51e6;
	case 20971ULL: goto x86_l_51eb;
	case 20976ULL: goto x86_l_51f0;
	case 20981ULL: goto x86_l_51f5;
	case 20985ULL: goto x86_l_51f9;
	case 20990ULL: goto x86_l_51fe;
	case 20992ULL: goto x86_l_5200;
	case 20994ULL: goto x86_l_5202;
	case 20996ULL: goto x86_l_5204;
	case 21003ULL: goto x86_l_520b;
	case 21006ULL: goto x86_l_520e;
	case 21012ULL: goto x86_l_5214;
	case 21017ULL: goto x86_l_5219;
	case 21027ULL: goto x86_l_5223;
	case 21032ULL: goto x86_l_5228;
	case 21042ULL: goto x86_l_5232;
	case 21047ULL: goto x86_l_5237;
	case 21057ULL: goto x86_l_5241;
	case 21062ULL: goto x86_l_5246;
	case 21072ULL: goto x86_l_5250;
	case 21077ULL: goto x86_l_5255;
	case 21087ULL: goto x86_l_525f;
	case 21092ULL: goto x86_l_5264;
	case 21100ULL: goto x86_l_526c;
	case 21105ULL: goto x86_l_5271;
	case 21110ULL: goto x86_l_5276;
	case 21115ULL: goto x86_l_527b;
	case 21120ULL: goto x86_l_5280;
	case 21123ULL: goto x86_l_5283;
	case 21125ULL: goto x86_l_5285;
	case 21127ULL: goto x86_l_5287;
	case 21130ULL: goto x86_l_528a;
	case 21135ULL: goto x86_l_528f;
	case 21145ULL: goto x86_l_5299;
	case 21153ULL: goto x86_l_52a1;
	case 21163ULL: goto x86_l_52ab;
	case 21171ULL: goto x86_l_52b3;
	case 21181ULL: goto x86_l_52bd;
	case 21189ULL: goto x86_l_52c5;
	case 21199ULL: goto x86_l_52cf;
	case 21207ULL: goto x86_l_52d7;
	case 21217ULL: goto x86_l_52e1;
	case 21225ULL: goto x86_l_52e9;
	case 21235ULL: goto x86_l_52f3;
	case 21243ULL: goto x86_l_52fb;
	case 21253ULL: goto x86_l_5305;
	case 21261ULL: goto x86_l_530d;
	case 21266ULL: goto x86_l_5312;
	case 21272ULL: goto x86_l_5318;
	case 21279ULL: goto x86_l_531f;
	case 21284ULL: goto x86_l_5324;
	case 21287ULL: goto x86_l_5327;
	case 21290ULL: goto x86_l_532a;
	case 21292ULL: goto x86_l_532c;
	case 21295ULL: goto x86_l_532f;
	case 21302ULL: goto x86_l_5336;
	case 21305ULL: goto x86_l_5339;
	case 21311ULL: goto x86_l_533f;
	case 21321ULL: goto x86_l_5349;
	case 21329ULL: goto x86_l_5351;
	case 21339ULL: goto x86_l_535b;
	case 21347ULL: goto x86_l_5363;
	case 21357ULL: goto x86_l_536d;
	case 21365ULL: goto x86_l_5375;
	case 21375ULL: goto x86_l_537f;
	case 21383ULL: goto x86_l_5387;
	case 21393ULL: goto x86_l_5391;
	case 21401ULL: goto x86_l_5399;
	case 21409ULL: goto x86_l_53a1;
	case 21417ULL: goto x86_l_53a9;
	case 21422ULL: goto x86_l_53ae;
	case 21428ULL: goto x86_l_53b4;
	case 21435ULL: goto x86_l_53bb;
	case 21442ULL: goto x86_l_53c2;
	case 21447ULL: goto x86_l_53c7;
	case 21449ULL: goto x86_l_53c9;
	case 21452ULL: goto x86_l_53cc;
	case 21457ULL: goto x86_l_53d1;
	case 21467ULL: goto x86_l_53db;
	case 21475ULL: goto x86_l_53e3;
	case 21485ULL: goto x86_l_53ed;
	case 21493ULL: goto x86_l_53f5;
	case 21503ULL: goto x86_l_53ff;
	case 21511ULL: goto x86_l_5407;
	case 21521ULL: goto x86_l_5411;
	case 21529ULL: goto x86_l_5419;
	case 21537ULL: goto x86_l_5421;
	case 21542ULL: goto x86_l_5426;
	case 21547ULL: goto x86_l_542b;
	case 21552ULL: goto x86_l_5430;
	case 21557ULL: goto x86_l_5435;
	case 21559ULL: goto x86_l_5437;
	case 21561ULL: goto x86_l_5439;
	case 21567ULL: goto x86_l_543f;
	case 21571ULL: goto x86_l_5443;
	case 21574ULL: goto x86_l_5446;
	case 21580ULL: goto x86_l_544c;
	case 21588ULL: goto x86_l_5454;
	case 21595ULL: goto x86_l_545b;
	case 21600ULL: goto x86_l_5460;
	case 21605ULL: goto x86_l_5465;
	case 21607ULL: goto x86_l_5467;
	case 21610ULL: goto x86_l_546a;
	case 21612ULL: goto x86_l_546c;
	case 21615ULL: goto x86_l_546f;
	case 21617ULL: goto x86_l_5471;
	case 21624ULL: goto x86_l_5478;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4c27:
	/* 0x4c27: jg     4c3e <kprobe_unwind_native+0x4c3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4c3e;
	}
x86_l_4c29:
	/* 0x4c29: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_4c2c:
	/* 0x4c2c: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4c2f:
	/* 0x4c2f: je     4ca9 <kprobe_unwind_native+0x4ca9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ca9;
	}
x86_l_4c31:
	/* 0x4c31: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_4c34:
	/* 0x4c34: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_4c37:
	/* 0x4c37: je     4ca6 <kprobe_unwind_native+0x4ca6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ca6;
	}
x86_l_4c39:
	/* 0x4c39: jmp    4e05 <kprobe_unwind_native+0x4e05> */
	goto x86_l_4e05;
x86_l_4c3e:
	/* 0x4c3e: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4c41:
	/* 0x4c41: je     4ca1 <kprobe_unwind_native+0x4ca1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ca1;
	}
x86_l_4c43:
	/* 0x4c43: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4c46:
	/* 0x4c46: jne    4e05 <kprobe_unwind_native+0x4e05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4e05;
	}
x86_l_4c4c:
	/* 0x4c4c: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_4c4f:
	/* 0x4c4f: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_4c51:
	/* 0x4c51: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_4c54:
	/* 0x4c54: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_4c56:
	/* 0x4c56: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4c5b:
	/* 0x4c5b: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4c62:
	/* 0x4c62: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c65:
	/* 0x4c65: jne    4d6e <kprobe_unwind_native+0x4d6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4d6e;
	}
x86_l_4c6b:
	/* 0x4c6b: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_4c6f:
	/* 0x4c6f: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_4c73:
	/* 0x4c73: jg     4dc1 <kprobe_unwind_native+0x4dc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4dc1;
	}
x86_l_4c79:
	/* 0x4c79: mov    rax,QWORD PTR [rsp+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_4c81:
	/* 0x4c81: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_4c84:
	/* 0x4c84: je     4ddd <kprobe_unwind_native+0x4ddd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ddd;
	}
x86_l_4c8a:
	/* 0x4c8a: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_4c8e:
	/* 0x4c8e: jne    4e05 <kprobe_unwind_native+0x4e05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4e05;
	}
x86_l_4c94:
	/* 0x4c94: mov    rax,QWORD PTR [rsp+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_4c9c:
	/* 0x4c9c: jmp    4ddd <kprobe_unwind_native+0x4ddd> */
	goto x86_l_4ddd;
x86_l_4ca1:
	/* 0x4ca1: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4ca6:
	/* 0x4ca6: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ca9:
	/* 0x4ca9: movsxd rbp,ecx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_4cac:
	/* 0x4cac: add    rbp,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4caf:
	/* 0x4caf: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_4cb1:
	/* 0x4cb1: jns    4de5 <kprobe_unwind_native+0x4de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_4de5;
	}
x86_l_4cb7:
	/* 0x4cb7: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4cbc:
	/* 0x4cbc: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_4cc1:
	/* 0x4cc1: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_4cc6:
	/* 0x4cc6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ccb:
	/* 0x4ccb: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4cce:
	/* 0x4cce: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4cd0:
	/* 0x4cd0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4cd3:
	/* 0x4cd3: je     4d5c <kprobe_unwind_native+0x4d5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d5c;
	}
x86_l_4cd9:
	/* 0x4cd9: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4ce0:
	/* 0x4ce0: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ce3:
	/* 0x4ce3: je     4e05 <kprobe_unwind_native+0x4e05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e05;
	}
x86_l_4ce9:
	/* 0x4ce9: movabs rax,0x2578302073736572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2699960892542641522ULL);
x86_l_4cf3:
	/* 0x4cf3: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4cf8:
	/* 0x4cf8: movabs rax,0x6464612065636e65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7234013693231722085ULL);
x86_l_4d02:
	/* 0x4d02: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4d07:
	/* 0x4d07: movabs rax,0x7265666572656420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243107278868538400ULL);
x86_l_4d11:
	/* 0x4d11: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4d16:
	/* 0x4d16: movabs rax,0x6f742064656c6961 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8031079651078859105ULL);
x86_l_4d20:
	/* 0x4d20: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4d25:
	/* 0x4d25: movabs rax,0x6620646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358992216502005365ULL);
x86_l_4d2f:
	/* 0x4d2f: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d34:
	/* 0x4d34: mov    DWORD PTR [rsp+0x38],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518854764ULL);
x86_l_4d3c:
	/* 0x4d3c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d41:
	/* 0x4d41: mov    eax,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_4d46:
	/* 0x4d46: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4d4b:
	/* 0x4d4b: mov    esi,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_4d50:
	/* 0x4d50: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4d53:
	/* 0x4d53: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4d55:
	/* 0x4d55: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4d57:
	/* 0x4d57: jmp    4e05 <kprobe_unwind_native+0x4e05> */
	goto x86_l_4e05;
x86_l_4d5c:
	/* 0x4d5c: shl    r12d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_4d60:
	/* 0x4d60: and    r12d,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 56ULL);
x86_l_4d64:
	/* 0x4d64: add    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_4d69:
	/* 0x4d69: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_4d6c:
	/* 0x4d6c: jmp    4de5 <kprobe_unwind_native+0x4de5> */
	goto x86_l_4de5;
x86_l_4d6e:
	/* 0x4d6e: movabs rax,0xa756c252b642572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 753627419551999346ULL);
x86_l_4d78:
	/* 0x4d78: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4d7d:
	/* 0x4d7d: movabs rax,0x203a646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2322278983241526901ULL);
x86_l_4d87:
	/* 0x4d87: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d8c:
	/* 0x4d8c: mov    BYTE PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4d91:
	/* 0x4d91: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d96:
	/* 0x4d96: mov    eax,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_4d9b:
	/* 0x4d9b: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_4da1:
	/* 0x4da1: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_4da5:
	/* 0x4da5: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4daa:
	/* 0x4daa: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_4daf:
	/* 0x4daf: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_4db2:
	/* 0x4db2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4db4:
	/* 0x4db4: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4db7:
	/* 0x4db7: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_4dbb:
	/* 0x4dbb: jle    4c79 <kprobe_unwind_native+0x4c79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4c79;
	}
x86_l_4dc1:
	/* 0x4dc1: mov    rax,QWORD PTR [rsp+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_4dc9:
	/* 0x4dc9: cmp    r12d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 11ULL);
x86_l_4dcd:
	/* 0x4dcd: je     4ddd <kprobe_unwind_native+0x4ddd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4ddd;
	}
x86_l_4dcf:
	/* 0x4dcf: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4dd7:
	/* 0x4dd7: cmp    r12d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 15ULL);
x86_l_4ddb:
	/* 0x4ddb: jne    4e05 <kprobe_unwind_native+0x4e05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4e05;
	}
x86_l_4ddd:
	/* 0x4ddd: mov    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4de2:
	/* 0x4de2: add    rbp,QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4de5:
	/* 0x4de5: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_4de8:
	/* 0x4de8: je     4e05 <kprobe_unwind_native+0x4e05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e05;
	}
x86_l_4dea:
	/* 0x4dea: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_4def:
	/* 0x4def: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_4df4:
	/* 0x4df4: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4df9:
	/* 0x4df9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4dfe:
	/* 0x4dfe: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4e01:
	/* 0x4e01: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4e03:
	/* 0x4e03: jmp    4e1b <kprobe_unwind_native+0x4e1b> */
	goto x86_l_4e1b;
x86_l_4e05:
	/* 0x4e05: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4e0a:
	/* 0x4e0a: cmp    BYTE PTR [rax],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_4e0d:
	/* 0x4e0d: jne    4e1b <kprobe_unwind_native+0x4e1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4e1b;
	}
x86_l_4e0f:
	/* 0x4e0f: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4e14:
	/* 0x4e14: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e1b:
	/* 0x4e1b: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_4e1e:
	/* 0x4e1e: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4e23:
	/* 0x4e23: je     1647 <kprobe_unwind_native+0x1647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5703ULL;
	}
x86_l_4e29:
	/* 0x4e29: lea    rdx,[r13-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_4e2d:
	/* 0x4e2d: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_4e32:
	/* 0x4e32: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_4e37:
	/* 0x4e37: mov    rdi,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_4e3f:
	/* 0x4e3f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e44:
	/* 0x4e44: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4e46:
	/* 0x4e46: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e49:
	/* 0x4e49: jne    1647 <kprobe_unwind_native+0x1647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5703ULL;
	}
x86_l_4e4f:
	/* 0x4e4f: mov    QWORD PTR [rbx+0xed8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_4e56:
	/* 0x4e56: mov    BYTE PTR [rbx+0xf30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16698832846849ULL);
x86_l_4e5d:
	/* 0x4e5d: mov    DWORD PTR [rsp+0x78],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075526ULL);
x86_l_4e65:
	/* 0x4e65: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_4e6c:
	/* 0x4e6c: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4e71:
	/* 0x4e71: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e76:
	/* 0x4e76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e78:
	/* 0x4e78: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e7b:
	/* 0x4e7b: je     4f1c <kprobe_unwind_native+0x4f1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f1c;
	}
x86_l_4e81:
	/* 0x4e81: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4e84:
	/* 0x4e84: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4e86:
	/* 0x4e86: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4e8d:
	/* 0x4e8d: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e90:
	/* 0x4e90: je     4f2e <kprobe_unwind_native+0x4f2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f2e;
	}
x86_l_4e96:
	/* 0x4e96: movabs rax,0xa786c6c25203a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947156833280058ULL);
x86_l_4ea0:
	/* 0x4ea0: mov    QWORD PTR [rsp+0xb5],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 181ULL);
x86_l_4ea8:
	/* 0x4ea8: movabs rax,0x25203a706620786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675202433082226796ULL);
x86_l_4eb2:
	/* 0x4eb2: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_4eba:
	/* 0x4eba: movabs rax,0x6c25203a70732078 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7792670165601296504ULL);
x86_l_4ec4:
	/* 0x4ec4: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4ecc:
	/* 0x4ecc: movabs rax,0x6c6c25203a637020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660273929744416ULL);
x86_l_4ed6:
	/* 0x4ed6: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4ede:
	/* 0x4ede: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4ee6:
	/* 0x4ee6: mov    eax,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_4eeb:
	/* 0x4eeb: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_4ef1:
	/* 0x4ef1: mov    rax,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_4ef9:
	/* 0x4ef9: mov    rdx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4efc:
	/* 0x4efc: mov    rcx,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4eff:
	/* 0x4eff: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4f04:
	/* 0x4f04: mov    r8,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f07:
	/* 0x4f07: mov    esi,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 29ULL);
x86_l_4f0c:
	/* 0x4f0c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f0e:
	/* 0x4f0e: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_4f11:
	/* 0x4f11: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4f18:
	/* 0x4f18: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f1a:
	/* 0x4f1a: jmp    4f2e <kprobe_unwind_native+0x4f2e> */
	goto x86_l_4f2e;
x86_l_4f1c:
	/* 0x4f1c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4f23:
	/* 0x4f23: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f26:
	/* 0x4f26: jne    518c <kprobe_unwind_native+0x518c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_518c;
	}
x86_l_4f2c:
	/* 0x4f2c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f2e:
	/* 0x4f2e: mov    rcx,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_4f36:
	/* 0x4f36: mov    r13,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f39:
	/* 0x4f39: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_4f3c:
	/* 0x4f3c: je     7079 <kprobe_unwind_native+0x7079> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28793ULL;
	}
x86_l_4f42:
	/* 0x4f42: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f44:
	/* 0x4f44: jne    50d8 <kprobe_unwind_native+0x50d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_50d8;
	}
x86_l_4f4a:
	/* 0x4f4a: movabs rax,0xffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72057594037927935ULL);
x86_l_4f54:
	/* 0x4f54: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_4f57:
	/* 0x4f57: ja     339e <kprobe_unwind_native+0x339e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13214ULL;
	}
x86_l_4f5d:
	/* 0x4f5d: cmp    r13,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4096ULL);
x86_l_4f64:
	/* 0x4f64: jb     34e4 <kprobe_unwind_native+0x34e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13540ULL;
	}
x86_l_4f6a:
	/* 0x4f6a: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f6c:
	/* 0x4f6c: mov    DWORD PTR [rsp+0x10],0x60 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476832ULL);
x86_l_4f74:
	/* 0x4f74: movbe  DWORD PTR [rsp+0x14],eax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_4f7a:
	/* 0x4f7a: movbe  QWORD PTR [rsp+0x18],r13 */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_4f81:
	/* 0x4f81: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_page_to_mapping_info)));
x86_l_4f88:
	/* 0x4f88: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f8d:
	/* 0x4f8d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4f92:
	/* 0x4f92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f94:
	/* 0x4f94: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4f97:
	/* 0x4f97: je     7135 <kprobe_unwind_native+0x7135> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28981ULL;
	}
x86_l_4f9d:
	/* 0x4f9d: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fa1:
	/* 0x4fa1: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_4fa4:
	/* 0x4fa4: movabs rdx,0xffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 72057594037927935ULL);
x86_l_4fae:
	/* 0x4fae: and    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_AND);
x86_l_4fb1:
	/* 0x4fb1: mov    QWORD PTR [rbx+0xf20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3872ULL);
x86_l_4fb8:
	/* 0x4fb8: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fbb:
	/* 0x4fbb: mov    QWORD PTR [rbx+0xf10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_4fc2:
	/* 0x4fc2: shr    r12,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_4fc6:
	/* 0x4fc6: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_4fc9:
	/* 0x4fc9: sub    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_4fcc:
	/* 0x4fcc: mov    QWORD PTR [rbx+0xf18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_4fd3:
	/* 0x4fd3: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4fda:
	/* 0x4fda: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fdd:
	/* 0x4fdd: jne    528f <kprobe_unwind_native+0x528f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_528f;
	}
x86_l_4fe3:
	/* 0x4fe3: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_4fe7:
	/* 0x4fe7: jne    5486 <kprobe_unwind_native+0x5486> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 21638ULL;
	}
x86_l_4fed:
	/* 0x4fed: mov    rax,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_4ff4:
	/* 0x4ff4: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ff9:
	/* 0x4ff9: mov    rbp,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_5000:
	/* 0x5000: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&interpreter_offsets)));
x86_l_5007:
	/* 0x5007: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_500c:
	/* 0x500c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5011:
	/* 0x5011: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5013:
	/* 0x5013: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_5019:
	/* 0x5019: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_501c:
	/* 0x501c: je     5486 <kprobe_unwind_native+0x5486> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21638ULL;
	}
x86_l_5022:
	/* 0x5022: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_5025:
	/* 0x5025: cmp    QWORD PTR [rax],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5028:
	/* 0x5028: ja     5030 <kprobe_unwind_native+0x5030> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_5030;
	}
x86_l_502a:
	/* 0x502a: cmp    QWORD PTR [r13+0x8],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_502e:
	/* 0x502e: jae    5044 <kprobe_unwind_native+0x5044> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5044;
	}
x86_l_5030:
	/* 0x5030: cmp    QWORD PTR [r13+0x10],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5034:
	/* 0x5034: ja     5486 <kprobe_unwind_native+0x5486> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 21638ULL;
	}
x86_l_503a:
	/* 0x503a: cmp    QWORD PTR [r13+0x18],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_503e:
	/* 0x503e: jb     5486 <kprobe_unwind_native+0x5486> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 21638ULL;
	}
x86_l_5044:
	/* 0x5044: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_504b:
	/* 0x504b: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_504e:
	/* 0x504e: jne    53d1 <kprobe_unwind_native+0x53d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_53d1;
	}
x86_l_5054:
	/* 0x5054: mov    eax,DWORD PTR [rbx+0x1380] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4992ULL);
x86_l_505a:
	/* 0x505a: mov    ecx,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_505e:
	/* 0x505e: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_5061:
	/* 0x5061: jae    544c <kprobe_unwind_native+0x544c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_544c;
	}
x86_l_5067:
	/* 0x5067: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_506e:
	/* 0x506e: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5071:
	/* 0x5071: je     5486 <kprobe_unwind_native+0x5486> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21638ULL;
	}
x86_l_5077:
	/* 0x5077: movabs rax,0x6e6f64207265646e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7957689157107934318ULL);
x86_l_5081:
	/* 0x5081: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_5089:
	/* 0x5089: movabs rax,0x69776e7520726574 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7599664345545598324ULL);
x86_l_5093:
	/* 0x5093: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_509b:
	/* 0x509b: movabs rax,0x6572707265746e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310028781806448233ULL);
x86_l_50a5:
	/* 0x50a5: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_50ad:
	/* 0x50ad: mov    DWORD PTR [rsp+0xb7],0xa656e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 785979696494ULL);
x86_l_50b8:
	/* 0x50b8: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_50c0:
	/* 0x50c0: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_50c5:
	/* 0x50c5: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_50ca:
	/* 0x50ca: mov    esi,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 27ULL);
x86_l_50cf:
	/* 0x50cf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_50d1:
	/* 0x50d1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_50d3:
	/* 0x50d3: jmp    5486 <kprobe_unwind_native+0x5486> */
	return 21638ULL;
x86_l_50d8:
	/* 0x50d8: movabs rax,0xa3d3d3d3d206425 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 737813247186461733ULL);
x86_l_50e2:
	/* 0x50e2: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_50ea:
	/* 0x50ea: movabs rax,0x20656d617266203a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334392247160021050ULL);
x86_l_50f4:
	/* 0x50f4: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_50fc:
	/* 0x50fc: movabs rax,0x7265646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243105118350175861ULL);
x86_l_5106:
	/* 0x5106: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_510e:
	/* 0x510e: movabs rax,0x20656d6172662074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334392247160021108ULL);
x86_l_5118:
	/* 0x5118: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_5120:
	/* 0x5120: movabs rax,0x78656e2065766c6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8675461342619397231ULL);
x86_l_512a:
	/* 0x512a: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_5132:
	/* 0x5132: movabs rax,0x736552203d3d3d3d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8315142585429343549ULL);
x86_l_513c:
	/* 0x513c: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_5144:
	/* 0x5144: mov    BYTE PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_514c:
	/* 0x514c: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_5154:
	/* 0x5154: mov    eax,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 49ULL);
x86_l_5159:
	/* 0x5159: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_515e:
	/* 0x515e: mov    edx,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_5164:
	/* 0x5164: mov    esi,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 49ULL);
x86_l_5169:
	/* 0x5169: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_516b:
	/* 0x516b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_516d:
	/* 0x516d: mov    r13,QWORD PTR [rbx+0xed0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_5174:
	/* 0x5174: movabs rax,0xffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72057594037927935ULL);
x86_l_517e:
	/* 0x517e: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_5181:
	/* 0x5181: ja     339e <kprobe_unwind_native+0x339e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13214ULL;
	}
x86_l_5187:
	/* 0x5187: jmp    4f5d <kprobe_unwind_native+0x4f5d> */
	goto x86_l_4f5d;
x86_l_518c:
	/* 0x518c: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_5196:
	/* 0x5196: mov    QWORD PTR [rsp+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_519b:
	/* 0x519b: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_51a5:
	/* 0x51a5: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_51aa:
	/* 0x51aa: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_51b4:
	/* 0x51b4: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_51b9:
	/* 0x51b9: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_51c3:
	/* 0x51c3: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_51c8:
	/* 0x51c8: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_51d2:
	/* 0x51d2: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_51d7:
	/* 0x51d7: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_51e1:
	/* 0x51e1: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51e6:
	/* 0x51e6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51eb:
	/* 0x51eb: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_51f0:
	/* 0x51f0: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_51f5:
	/* 0x51f5: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_51f9:
	/* 0x51f9: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_51fe:
	/* 0x51fe: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5200:
	/* 0x5200: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5202:
	/* 0x5202: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5204:
	/* 0x5204: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_520b:
	/* 0x520b: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_520e:
	/* 0x520e: je     4f2e <kprobe_unwind_native+0x4f2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f2e;
	}
x86_l_5214:
	/* 0x5214: jmp    4e96 <kprobe_unwind_native+0x4e96> */
	goto x86_l_4e96;
x86_l_5219:
	/* 0x5219: movabs rax,0x2578302073736572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2699960892542641522ULL);
x86_l_5223:
	/* 0x5223: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5228:
	/* 0x5228: movabs rax,0x6464612065636e65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7234013693231722085ULL);
x86_l_5232:
	/* 0x5232: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5237:
	/* 0x5237: movabs rax,0x7265666572656420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243107278868538400ULL);
x86_l_5241:
	/* 0x5241: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5246:
	/* 0x5246: movabs rax,0x6f742064656c6961 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8031079651078859105ULL);
x86_l_5250:
	/* 0x5250: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5255:
	/* 0x5255: movabs rax,0x6620646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358992216502005365ULL);
x86_l_525f:
	/* 0x525f: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5264:
	/* 0x5264: mov    DWORD PTR [rsp+0x38],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518854764ULL);
x86_l_526c:
	/* 0x526c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5271:
	/* 0x5271: mov    eax,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_5276:
	/* 0x5276: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_527b:
	/* 0x527b: mov    esi,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_5280:
	/* 0x5280: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5283:
	/* 0x5283: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5285:
	/* 0x5285: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5287:
	/* 0x5287: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_528a:
	/* 0x528a: jmp    4c06 <kprobe_unwind_native+0x4c06> */
	return 19462ULL;
x86_l_528f:
	/* 0x528f: movabs rax,0x296425207265646e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2982549674514539630ULL);
x86_l_5299:
	/* 0x5299: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_52a1:
	/* 0x52a1: movabs rax,0x69776e752820786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7599664345674446956ULL);
x86_l_52ab:
	/* 0x52ab: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_52b3:
	/* 0x52b3: movabs rax,0x6c2520736920786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7792670410291574892ULL);
x86_l_52bd:
	/* 0x52bd: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_52c5:
	/* 0x52c5: movabs rax,0x2520435020726f66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675212190078889830ULL);
x86_l_52cf:
	/* 0x52cf: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_52d7:
	/* 0x52d7: movabs rax,0x206469206e6f6974 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334106094897424756ULL);
x86_l_52e1:
	/* 0x52e1: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_52e9:
	/* 0x52e9: movabs rbp,0x6365732074786554 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 7162257365632836948ULL);
x86_l_52f3:
	/* 0x52f3: mov    QWORD PTR [rsp+0xa0],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_52fb:
	/* 0x52fb: mov    WORD PTR [rsp+0xd0],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 893353197578ULL);
x86_l_5305:
	/* 0x5305: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_530d:
	/* 0x530d: mov    eax,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_5312:
	/* 0x5312: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_5318:
	/* 0x5318: mov    rcx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_531f:
	/* 0x531f: mov    esi,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 50ULL);
x86_l_5324:
	/* 0x5324: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5327:
	/* 0x5327: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_532a:
	/* 0x532a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_532c:
	/* 0x532c: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_532f:
	/* 0x532f: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5336:
	/* 0x5336: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5339:
	/* 0x5339: je     4fe3 <kprobe_unwind_native+0x4fe3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fe3;
	}
x86_l_533f:
	/* 0x533f: movabs rax,0xa786c6c252073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947156833280115ULL);
x86_l_5349:
	/* 0x5349: mov    QWORD PTR [rsp+0xc7],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 199ULL);
x86_l_5351:
	/* 0x5351: movabs rax,0x7369207465736666 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8316213871206688358ULL);
x86_l_535b:
	/* 0x535b: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_5363:
	/* 0x5363: movabs rax,0x6f20646e61202c78 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8007510562703420536ULL);
x86_l_536d:
	/* 0x536d: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_5375:
	/* 0x5375: movabs rax,0x6c6c252073692073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660274886418547ULL);
x86_l_537f:
	/* 0x537f: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_5387:
	/* 0x5387: movabs rax,0x616962206e6f6974 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7019249385664899444ULL);
x86_l_5391:
	/* 0x5391: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_5399:
	/* 0x5399: mov    QWORD PTR [rsp+0xa0],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_53a1:
	/* 0x53a1: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_53a9:
	/* 0x53a9: mov    eax,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 47ULL);
x86_l_53ae:
	/* 0x53ae: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_53b4:
	/* 0x53b4: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_53bb:
	/* 0x53bb: mov    rdx,QWORD PTR [rbx+0xf20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3872ULL);
x86_l_53c2:
	/* 0x53c2: mov    esi,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 47ULL);
x86_l_53c7:
	/* 0x53c7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_53c9:
	/* 0x53c9: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_53cc:
	/* 0x53cc: jmp    4fe3 <kprobe_unwind_native+0x4fe3> */
	goto x86_l_4fe3;
x86_l_53d1:
	/* 0x53d1: movabs rax,0xa642520686374 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860387386228ULL);
x86_l_53db:
	/* 0x53db: mov    QWORD PTR [rsp+0xb6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_53e3:
	/* 0x53e3: movabs rax,0x6374616d20737465 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7166460028377068645ULL);
x86_l_53ed:
	/* 0x53ed: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_53f5:
	/* 0x53f5: movabs rax,0x7366666f5f726574 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8315446390514935156ULL);
x86_l_53ff:
	/* 0x53ff: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_5407:
	/* 0x5407: movabs rax,0x6572707265746e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310028781806448233ULL);
x86_l_5411:
	/* 0x5411: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_5419:
	/* 0x5419: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_5421:
	/* 0x5421: mov    eax,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 30ULL);
x86_l_5426:
	/* 0x5426: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_542b:
	/* 0x542b: movzx  edx,WORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_5430:
	/* 0x5430: mov    esi,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 30ULL);
x86_l_5435:
	/* 0x5435: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5437:
	/* 0x5437: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5439:
	/* 0x5439: mov    eax,DWORD PTR [rbx+0x1380] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4992ULL);
x86_l_543f:
	/* 0x543f: mov    ecx,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5443:
	/* 0x5443: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_5446:
	/* 0x5446: jb     5067 <kprobe_unwind_native+0x5067> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5067;
	}
x86_l_544c:
	/* 0x544c: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_5454:
	/* 0x5454: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_545b:
	/* 0x545b: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_5460:
	/* 0x5460: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5465:
	/* 0x5465: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5467:
	/* 0x5467: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_546a:
	/* 0x546a: je     5471 <kprobe_unwind_native+0x5471> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5471;
	}
x86_l_546c:
	/* 0x546c: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_546f:
	/* 0x546f: jmp    5481 <kprobe_unwind_native+0x5481> */
	return 21633ULL;
x86_l_5471:
	/* 0x5471: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5478:
	/* 0x5478: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 21627ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 21627ULL: goto x86_l_547b;
	case 21633ULL: goto x86_l_5481;
	case 21638ULL: goto x86_l_5486;
	case 21642ULL: goto x86_l_548a;
	case 21648ULL: goto x86_l_5490;
	case 21655ULL: goto x86_l_5497;
	case 21658ULL: goto x86_l_549a;
	case 21664ULL: goto x86_l_54a0;
	case 21672ULL: goto x86_l_54a8;
	case 21679ULL: goto x86_l_54af;
	case 21684ULL: goto x86_l_54b4;
	case 21689ULL: goto x86_l_54b9;
	case 21691ULL: goto x86_l_54bb;
	case 21694ULL: goto x86_l_54be;
	case 21700ULL: goto x86_l_54c4;
	case 21703ULL: goto x86_l_54c7;
	case 21710ULL: goto x86_l_54ce;
	case 21713ULL: goto x86_l_54d1;
	case 21719ULL: goto x86_l_54d7;
	case 21729ULL: goto x86_l_54e1;
	case 21737ULL: goto x86_l_54e9;
	case 21747ULL: goto x86_l_54f3;
	case 21755ULL: goto x86_l_54fb;
	case 21765ULL: goto x86_l_5505;
	case 21773ULL: goto x86_l_550d;
	case 21783ULL: goto x86_l_5517;
	case 21791ULL: goto x86_l_551f;
	case 21801ULL: goto x86_l_5529;
	case 21809ULL: goto x86_l_5531;
	case 21820ULL: goto x86_l_553c;
	case 21828ULL: goto x86_l_5544;
	case 21833ULL: goto x86_l_5549;
	case 21839ULL: goto x86_l_554f;
	case 21846ULL: goto x86_l_5556;
	case 21853ULL: goto x86_l_555d;
	case 21860ULL: goto x86_l_5564;
	case 21865ULL: goto x86_l_5569;
	case 21867ULL: goto x86_l_556b;
	case 21870ULL: goto x86_l_556e;
	case 21872ULL: goto x86_l_5570;
	case 21879ULL: goto x86_l_5577;
	case 21882ULL: goto x86_l_557a;
	case 21888ULL: goto x86_l_5580;
	case 21894ULL: goto x86_l_5586;
	case 21898ULL: goto x86_l_558a;
	case 21903ULL: goto x86_l_558f;
	case 21910ULL: goto x86_l_5596;
	case 21916ULL: goto x86_l_559c;
	case 21923ULL: goto x86_l_55a3;
	case 21930ULL: goto x86_l_55aa;
	case 21937ULL: goto x86_l_55b1;
	case 21940ULL: goto x86_l_55b4;
	case 21946ULL: goto x86_l_55ba;
	case 21950ULL: goto x86_l_55be;
	case 21958ULL: goto x86_l_55c6;
	case 21966ULL: goto x86_l_55ce;
	case 21974ULL: goto x86_l_55d6;
	case 21981ULL: goto x86_l_55dd;
	case 21992ULL: goto x86_l_55e8;
	case 22002ULL: goto x86_l_55f2;
	case 22013ULL: goto x86_l_55fd;
	case 22020ULL: goto x86_l_5604;
	case 22028ULL: goto x86_l_560c;
	case 22033ULL: goto x86_l_5611;
	case 22040ULL: goto x86_l_5618;
	case 22047ULL: goto x86_l_561f;
	case 22055ULL: goto x86_l_5627;
	case 22060ULL: goto x86_l_562c;
	case 22066ULL: goto x86_l_5632;
	case 22073ULL: goto x86_l_5639;
	case 22078ULL: goto x86_l_563e;
	case 22083ULL: goto x86_l_5643;
	case 22085ULL: goto x86_l_5645;
	case 22090ULL: goto x86_l_564a;
	case 22093ULL: goto x86_l_564d;
	case 22098ULL: goto x86_l_5652;
	case 22105ULL: goto x86_l_5659;
	case 22107ULL: goto x86_l_565b;
	case 22112ULL: goto x86_l_5660;
	case 22115ULL: goto x86_l_5663;
	case 22119ULL: goto x86_l_5667;
	case 22123ULL: goto x86_l_566b;
	case 22126ULL: goto x86_l_566e;
	case 22132ULL: goto x86_l_5674;
	case 22135ULL: goto x86_l_5677;
	case 22141ULL: goto x86_l_567d;
	case 22144ULL: goto x86_l_5680;
	case 22150ULL: goto x86_l_5686;
	case 22153ULL: goto x86_l_5689;
	case 22159ULL: goto x86_l_568f;
	case 22162ULL: goto x86_l_5692;
	case 22168ULL: goto x86_l_5698;
	case 22175ULL: goto x86_l_569f;
	case 22180ULL: goto x86_l_56a4;
	case 22183ULL: goto x86_l_56a7;
	case 22189ULL: goto x86_l_56ad;
	case 22195ULL: goto x86_l_56b3;
	case 22198ULL: goto x86_l_56b6;
	case 22204ULL: goto x86_l_56bc;
	case 22214ULL: goto x86_l_56c6;
	case 22219ULL: goto x86_l_56cb;
	case 22229ULL: goto x86_l_56d5;
	case 22234ULL: goto x86_l_56da;
	case 22244ULL: goto x86_l_56e4;
	case 22249ULL: goto x86_l_56e9;
	case 22259ULL: goto x86_l_56f3;
	case 22264ULL: goto x86_l_56f8;
	case 22274ULL: goto x86_l_5702;
	case 22279ULL: goto x86_l_5707;
	case 22289ULL: goto x86_l_5711;
	case 22294ULL: goto x86_l_5716;
	case 22304ULL: goto x86_l_5720;
	case 22309ULL: goto x86_l_5725;
	case 22316ULL: goto x86_l_572c;
	case 22321ULL: goto x86_l_5731;
	case 22326ULL: goto x86_l_5736;
	case 22332ULL: goto x86_l_573c;
	case 22337ULL: goto x86_l_5741;
	case 22345ULL: goto x86_l_5749;
	case 22350ULL: goto x86_l_574e;
	case 22352ULL: goto x86_l_5750;
	case 22355ULL: goto x86_l_5753;
	case 22360ULL: goto x86_l_5758;
	case 22363ULL: goto x86_l_575b;
	case 22365ULL: goto x86_l_575d;
	case 22368ULL: goto x86_l_5760;
	case 22370ULL: goto x86_l_5762;
	case 22373ULL: goto x86_l_5765;
	case 22379ULL: goto x86_l_576b;
	case 22382ULL: goto x86_l_576e;
	case 22388ULL: goto x86_l_5774;
	case 22395ULL: goto x86_l_577b;
	case 22400ULL: goto x86_l_5780;
	case 22403ULL: goto x86_l_5783;
	case 22405ULL: goto x86_l_5785;
	case 22408ULL: goto x86_l_5788;
	case 22414ULL: goto x86_l_578e;
	case 22417ULL: goto x86_l_5791;
	case 22423ULL: goto x86_l_5797;
	case 22430ULL: goto x86_l_579e;
	case 22435ULL: goto x86_l_57a3;
	case 22438ULL: goto x86_l_57a6;
	case 22440ULL: goto x86_l_57a8;
	case 22443ULL: goto x86_l_57ab;
	case 22449ULL: goto x86_l_57b1;
	case 22452ULL: goto x86_l_57b4;
	case 22454ULL: goto x86_l_57b6;
	case 22461ULL: goto x86_l_57bd;
	case 22466ULL: goto x86_l_57c2;
	case 22469ULL: goto x86_l_57c5;
	case 22475ULL: goto x86_l_57cb;
	case 22478ULL: goto x86_l_57ce;
	case 22480ULL: goto x86_l_57d0;
	case 22487ULL: goto x86_l_57d7;
	case 22492ULL: goto x86_l_57dc;
	case 22495ULL: goto x86_l_57df;
	case 22501ULL: goto x86_l_57e5;
	case 22504ULL: goto x86_l_57e8;
	case 22506ULL: goto x86_l_57ea;
	case 22513ULL: goto x86_l_57f1;
	case 22518ULL: goto x86_l_57f6;
	case 22521ULL: goto x86_l_57f9;
	case 22527ULL: goto x86_l_57ff;
	case 22530ULL: goto x86_l_5802;
	case 22532ULL: goto x86_l_5804;
	case 22539ULL: goto x86_l_580b;
	case 22544ULL: goto x86_l_5810;
	case 22547ULL: goto x86_l_5813;
	case 22553ULL: goto x86_l_5819;
	case 22556ULL: goto x86_l_581c;
	case 22558ULL: goto x86_l_581e;
	case 22565ULL: goto x86_l_5825;
	case 22570ULL: goto x86_l_582a;
	case 22576ULL: goto x86_l_5830;
	case 22582ULL: goto x86_l_5836;
	case 22589ULL: goto x86_l_583d;
	case 22592ULL: goto x86_l_5840;
	case 22598ULL: goto x86_l_5846;
	case 22608ULL: goto x86_l_5850;
	case 22613ULL: goto x86_l_5855;
	case 22623ULL: goto x86_l_585f;
	case 22628ULL: goto x86_l_5864;
	case 22638ULL: goto x86_l_586e;
	case 22643ULL: goto x86_l_5873;
	case 22653ULL: goto x86_l_587d;
	case 22658ULL: goto x86_l_5882;
	case 22668ULL: goto x86_l_588c;
	case 22673ULL: goto x86_l_5891;
	case 22683ULL: goto x86_l_589b;
	case 22688ULL: goto x86_l_58a0;
	case 22698ULL: goto x86_l_58aa;
	case 22703ULL: goto x86_l_58af;
	case 22713ULL: goto x86_l_58b9;
	case 22718ULL: goto x86_l_58be;
	case 22723ULL: goto x86_l_58c3;
	case 22728ULL: goto x86_l_58c8;
	case 22734ULL: goto x86_l_58ce;
	case 22742ULL: goto x86_l_58d6;
	case 22746ULL: goto x86_l_58da;
	case 22751ULL: goto x86_l_58df;
	case 22753ULL: goto x86_l_58e1;
	case 22756ULL: goto x86_l_58e4;
	case 22761ULL: goto x86_l_58e9;
	case 22768ULL: goto x86_l_58f0;
	case 22770ULL: goto x86_l_58f2;
	case 22777ULL: goto x86_l_58f9;
	case 22779ULL: goto x86_l_58fb;
	case 22786ULL: goto x86_l_5902;
	case 22788ULL: goto x86_l_5904;
	case 22795ULL: goto x86_l_590b;
	case 22797ULL: goto x86_l_590d;
	case 22804ULL: goto x86_l_5914;
	case 22806ULL: goto x86_l_5916;
	case 22813ULL: goto x86_l_591d;
	case 22815ULL: goto x86_l_591f;
	case 22822ULL: goto x86_l_5926;
	case 22824ULL: goto x86_l_5928;
	case 22831ULL: goto x86_l_592f;
	case 22839ULL: goto x86_l_5937;
	case 22844ULL: goto x86_l_593c;
	case 22846ULL: goto x86_l_593e;
	case 22851ULL: goto x86_l_5943;
	case 22854ULL: goto x86_l_5946;
	case 22860ULL: goto x86_l_594c;
	case 22865ULL: goto x86_l_5951;
	case 22868ULL: goto x86_l_5954;
	case 22876ULL: goto x86_l_595c;
	case 22883ULL: goto x86_l_5963;
	case 22888ULL: goto x86_l_5968;
	case 22892ULL: goto x86_l_596c;
	case 22894ULL: goto x86_l_596e;
	case 22900ULL: goto x86_l_5974;
	case 22903ULL: goto x86_l_5977;
	case 22906ULL: goto x86_l_597a;
	case 22913ULL: goto x86_l_5981;
	case 22916ULL: goto x86_l_5984;
	case 22922ULL: goto x86_l_598a;
	case 22926ULL: goto x86_l_598e;
	case 22928ULL: goto x86_l_5990;
	case 22932ULL: goto x86_l_5994;
	case 22937ULL: goto x86_l_5999;
	case 22942ULL: goto x86_l_599e;
	case 22947ULL: goto x86_l_59a3;
	case 22949ULL: goto x86_l_59a5;
	case 22952ULL: goto x86_l_59a8;
	case 22958ULL: goto x86_l_59ae;
	case 22962ULL: goto x86_l_59b2;
	case 22965ULL: goto x86_l_59b5;
	case 22970ULL: goto x86_l_59ba;
	case 22973ULL: goto x86_l_59bd;
	case 22977ULL: goto x86_l_59c1;
	case 22981ULL: goto x86_l_59c5;
	case 22985ULL: goto x86_l_59c9;
	case 22988ULL: goto x86_l_59cc;
	case 22994ULL: goto x86_l_59d2;
	case 22998ULL: goto x86_l_59d6;
	case 23000ULL: goto x86_l_59d8;
	case 23002ULL: goto x86_l_59da;
	case 23006ULL: goto x86_l_59de;
	case 23011ULL: goto x86_l_59e3;
	case 23016ULL: goto x86_l_59e8;
	case 23021ULL: goto x86_l_59ed;
	case 23023ULL: goto x86_l_59ef;
	case 23026ULL: goto x86_l_59f2;
	case 23032ULL: goto x86_l_59f8;
	case 23036ULL: goto x86_l_59fc;
	case 23040ULL: goto x86_l_5a00;
	case 23045ULL: goto x86_l_5a05;
	case 23048ULL: goto x86_l_5a08;
	case 23052ULL: goto x86_l_5a0c;
	case 23056ULL: goto x86_l_5a10;
	case 23059ULL: goto x86_l_5a13;
	case 23063ULL: goto x86_l_5a17;
	case 23066ULL: goto x86_l_5a1a;
	case 23072ULL: goto x86_l_5a20;
	case 23076ULL: goto x86_l_5a24;
	case 23079ULL: goto x86_l_5a27;
	case 23081ULL: goto x86_l_5a29;
	case 23085ULL: goto x86_l_5a2d;
	case 23090ULL: goto x86_l_5a32;
	case 23095ULL: goto x86_l_5a37;
	case 23100ULL: goto x86_l_5a3c;
	case 23102ULL: goto x86_l_5a3e;
	case 23105ULL: goto x86_l_5a41;
	case 23111ULL: goto x86_l_5a47;
	case 23115ULL: goto x86_l_5a4b;
	case 23118ULL: goto x86_l_5a4e;
	case 23123ULL: goto x86_l_5a53;
	case 23126ULL: goto x86_l_5a56;
	case 23130ULL: goto x86_l_5a5a;
	case 23134ULL: goto x86_l_5a5e;
	case 23137ULL: goto x86_l_5a61;
	case 23141ULL: goto x86_l_5a65;
	case 23143ULL: goto x86_l_5a67;
	case 23149ULL: goto x86_l_5a6d;
	case 23153ULL: goto x86_l_5a71;
	case 23155ULL: goto x86_l_5a73;
	case 23157ULL: goto x86_l_5a75;
	case 23161ULL: goto x86_l_5a79;
	case 23166ULL: goto x86_l_5a7e;
	case 23171ULL: goto x86_l_5a83;
	case 23176ULL: goto x86_l_5a88;
	case 23178ULL: goto x86_l_5a8a;
	case 23181ULL: goto x86_l_5a8d;
	case 23187ULL: goto x86_l_5a93;
	case 23191ULL: goto x86_l_5a97;
	case 23195ULL: goto x86_l_5a9b;
	case 23200ULL: goto x86_l_5aa0;
	case 23203ULL: goto x86_l_5aa3;
	case 23207ULL: goto x86_l_5aa7;
	case 23211ULL: goto x86_l_5aab;
	case 23214ULL: goto x86_l_5aae;
	case 23218ULL: goto x86_l_5ab2;
	case 23221ULL: goto x86_l_5ab5;
	case 23227ULL: goto x86_l_5abb;
	case 23231ULL: goto x86_l_5abf;
	case 23234ULL: goto x86_l_5ac2;
	case 23236ULL: goto x86_l_5ac4;
	case 23240ULL: goto x86_l_5ac8;
	case 23245ULL: goto x86_l_5acd;
	case 23250ULL: goto x86_l_5ad2;
	case 23255ULL: goto x86_l_5ad7;
	case 23257ULL: goto x86_l_5ad9;
	case 23260ULL: goto x86_l_5adc;
	case 23266ULL: goto x86_l_5ae2;
	case 23270ULL: goto x86_l_5ae6;
	case 23273ULL: goto x86_l_5ae9;
	case 23278ULL: goto x86_l_5aee;
	case 23281ULL: goto x86_l_5af1;
	case 23285ULL: goto x86_l_5af5;
	case 23289ULL: goto x86_l_5af9;
	case 23292ULL: goto x86_l_5afc;
	case 23296ULL: goto x86_l_5b00;
	case 23298ULL: goto x86_l_5b02;
	case 23304ULL: goto x86_l_5b08;
	case 23308ULL: goto x86_l_5b0c;
	case 23310ULL: goto x86_l_5b0e;
	case 23312ULL: goto x86_l_5b10;
	case 23316ULL: goto x86_l_5b14;
	case 23321ULL: goto x86_l_5b19;
	case 23326ULL: goto x86_l_5b1e;
	case 23331ULL: goto x86_l_5b23;
	case 23333ULL: goto x86_l_5b25;
	case 23336ULL: goto x86_l_5b28;
	case 23342ULL: goto x86_l_5b2e;
	case 23346ULL: goto x86_l_5b32;
	case 23350ULL: goto x86_l_5b36;
	case 23355ULL: goto x86_l_5b3b;
	case 23358ULL: goto x86_l_5b3e;
	case 23362ULL: goto x86_l_5b42;
	case 23366ULL: goto x86_l_5b46;
	case 23369ULL: goto x86_l_5b49;
	case 23373ULL: goto x86_l_5b4d;
	case 23376ULL: goto x86_l_5b50;
	case 23382ULL: goto x86_l_5b56;
	case 23386ULL: goto x86_l_5b5a;
	case 23389ULL: goto x86_l_5b5d;
	case 23391ULL: goto x86_l_5b5f;
	case 23395ULL: goto x86_l_5b63;
	case 23400ULL: goto x86_l_5b68;
	case 23405ULL: goto x86_l_5b6d;
	case 23410ULL: goto x86_l_5b72;
	case 23412ULL: goto x86_l_5b74;
	case 23415ULL: goto x86_l_5b77;
	case 23421ULL: goto x86_l_5b7d;
	case 23425ULL: goto x86_l_5b81;
	case 23428ULL: goto x86_l_5b84;
	case 23433ULL: goto x86_l_5b89;
	case 23436ULL: goto x86_l_5b8c;
	case 23440ULL: goto x86_l_5b90;
	case 23444ULL: goto x86_l_5b94;
	case 23447ULL: goto x86_l_5b97;
	case 23451ULL: goto x86_l_5b9b;
	case 23453ULL: goto x86_l_5b9d;
	case 23459ULL: goto x86_l_5ba3;
	case 23463ULL: goto x86_l_5ba7;
	case 23465ULL: goto x86_l_5ba9;
	case 23467ULL: goto x86_l_5bab;
	case 23471ULL: goto x86_l_5baf;
	case 23476ULL: goto x86_l_5bb4;
	case 23481ULL: goto x86_l_5bb9;
	case 23486ULL: goto x86_l_5bbe;
	case 23488ULL: goto x86_l_5bc0;
	case 23491ULL: goto x86_l_5bc3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_547b:
	/* 0x547b: jne    6946 <kprobe_unwind_native+0x6946> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 26950ULL;
	}
x86_l_5481:
	/* 0x5481: movzx  r12d,WORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_5486:
	/* 0x5486: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_548a:
	/* 0x548a: jne    75bf <kprobe_unwind_native+0x75bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 30143ULL;
	}
x86_l_5490:
	/* 0x5490: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5497:
	/* 0x5497: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_549a:
	/* 0x549a: jne    66c4 <kprobe_unwind_native+0x66c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 26308ULL;
	}
x86_l_54a0:
	/* 0x54a0: mov    DWORD PTR [rsp+0x10],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476741ULL);
x86_l_54a8:
	/* 0x54a8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_54af:
	/* 0x54af: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54b4:
	/* 0x54b4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_54b9:
	/* 0x54b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54bb:
	/* 0x54bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_54be:
	/* 0x54be: je     5570 <kprobe_unwind_native+0x5570> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5570;
	}
x86_l_54c4:
	/* 0x54c4: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_54c7:
	/* 0x54c7: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_54ce:
	/* 0x54ce: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54d1:
	/* 0x54d1: je     5580 <kprobe_unwind_native+0x5580> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5580;
	}
x86_l_54d7:
	/* 0x54d7: movabs rax,0x63617473206e6f20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7161132920309968672ULL);
x86_l_54e1:
	/* 0x54e1: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_54e9:
	/* 0x54e9: movabs rax,0x7525206e6f697469 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8441188735263536233ULL);
x86_l_54f3:
	/* 0x54f3: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_54fb:
	/* 0x54fb: movabs rax,0x736f70206f742078 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8317990321387741304ULL);
x86_l_5505:
	/* 0x5505: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_550d:
	/* 0x550d: movabs rax,0x6c6c2520786c6c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660274970520613ULL);
x86_l_5517:
	/* 0x5517: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_551f:
	/* 0x551f: movabs rax,0x20676e6968737550 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334956330817910096ULL);
x86_l_5529:
	/* 0x5529: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_5531:
	/* 0x5531: mov    DWORD PTR [rsp+0xc7],0xa6b63 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 854699174755ULL);
x86_l_553c:
	/* 0x553c: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_5544:
	/* 0x5544: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_5549:
	/* 0x5549: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_554f:
	/* 0x554f: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_5556:
	/* 0x5556: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_555d:
	/* 0x555d: mov    r8d,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_5564:
	/* 0x5564: mov    esi,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 43ULL);
x86_l_5569:
	/* 0x5569: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_556b:
	/* 0x556b: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_556e:
	/* 0x556e: jmp    5580 <kprobe_unwind_native+0x5580> */
	goto x86_l_5580;
x86_l_5570:
	/* 0x5570: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5577:
	/* 0x5577: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_557a:
	/* 0x557a: jne    6799 <kprobe_unwind_native+0x6799> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 26521ULL;
	}
x86_l_5580:
	/* 0x5580: mov    eax,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_5586:
	/* 0x5586: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_558a:
	/* 0x558a: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_558f:
	/* 0x558f: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5596:
	/* 0x5596: ja     141 <kprobe_unwind_native+0x141> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 321ULL;
	}
x86_l_559c:
	/* 0x559c: movzx  ecx,BYTE PTR [rbx+0xf30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3888ULL);
x86_l_55a3:
	/* 0x55a3: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_55aa:
	/* 0x55aa: mov    rsi,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_55b1:
	/* 0x55b1: lea    edi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_55b4:
	/* 0x55b4: mov    DWORD PTR [rbx+0x2c0],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_55ba:
	/* 0x55ba: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_55be:
	/* 0x55be: mov    QWORD PTR [rbx+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_55c6:
	/* 0x55c6: mov    QWORD PTR [rbx+rax*8+0x2d8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_55ce:
	/* 0x55ce: mov    BYTE PTR [rbx+rax*8+0x2e0],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 3161095929859ULL);
x86_l_55d6:
	/* 0x55d6: mov    BYTE PTR [rbx+rax*8+0x2e1],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 737ULL);
x86_l_55dd:
	/* 0x55dd: mov    DWORD PTR [rbx+rax*8+0x2e2],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3169685864448ULL);
x86_l_55e8:
	/* 0x55e8: mov    WORD PTR [rbx+rax*8+0x2e6],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3186865733632ULL);
x86_l_55f2:
	/* 0x55f2: mov    DWORD PTR [rsp+0x8c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_55fd:
	/* 0x55fd: mov    rax,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_5604:
	/* 0x5604: mov    QWORD PTR [rsp+0x160],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_560c:
	/* 0x560c: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_5611:
	/* 0x5611: mov    rax,0xffffffffffff0000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 18446744073709486080ULL);
x86_l_5618:
	/* 0x5618: and    rax,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 3864ULL);
x86_l_561f:
	/* 0x561f: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5627:
	/* 0x5627: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_562c:
	/* 0x562c: jne    672b <kprobe_unwind_native+0x672b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 26411ULL;
	}
x86_l_5632:
	/* 0x5632: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&stack_delta_page_to_info)));
x86_l_5639:
	/* 0x5639: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_563e:
	/* 0x563e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5643:
	/* 0x5643: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5645:
	/* 0x5645: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_564a:
	/* 0x564a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_564d:
	/* 0x564d: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5652:
	/* 0x5652: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5659:
	/* 0x5659: je     56a4 <kprobe_unwind_native+0x56a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_56a4;
	}
x86_l_565b:
	/* 0x565b: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5660:
	/* 0x5660: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_5663:
	/* 0x5663: add    rbp,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_5667:
	/* 0x5667: movzx  eax,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_566b:
	/* 0x566b: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_566e:
	/* 0x566e: jg     5758 <kprobe_unwind_native+0x5758> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_5758;
	}
x86_l_5674:
	/* 0x5674: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_5677:
	/* 0x5677: jg     5780 <kprobe_unwind_native+0x5780> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_5780;
	}
x86_l_567d:
	/* 0x567d: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_5680:
	/* 0x5680: jg     57c2 <kprobe_unwind_native+0x57c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_57c2;
	}
x86_l_5686:
	/* 0x5686: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_5689:
	/* 0x5689: je     58e9 <kprobe_unwind_native+0x58e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58e9;
	}
x86_l_568f:
	/* 0x568f: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_5692:
	/* 0x5692: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_582a;
	}
x86_l_5698:
	/* 0x5698: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_9_stack_deltas)));
x86_l_569f:
	/* 0x569f: jmp    592f <kprobe_unwind_native+0x592f> */
	goto x86_l_592f;
x86_l_56a4:
	/* 0x56a4: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_56a7:
	/* 0x56a7: mov    r13d,0xfa0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4000ULL);
x86_l_56ad:
	/* 0x56ad: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_56b3:
	/* 0x56b3: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56b6:
	/* 0x56b6: je     5f4c <kprobe_unwind_native+0x5f4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24396ULL;
	}
x86_l_56bc:
	/* 0x56bc: movabs rax,0x786c252065676170 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8677351403106558320ULL);
x86_l_56c6:
	/* 0x56c6: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_56cb:
	/* 0x56cb: movabs rax,0x202c786c25204449 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2318360314063635529ULL);
x86_l_56d5:
	/* 0x56d5: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_56da:
	/* 0x56da: movabs rax,0x656c696620656761 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7308332182666569569ULL);
x86_l_56e4:
	/* 0x56e4: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_56e9:
	/* 0x56e9: movabs rax,0x702061746c656420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8079564884165354528ULL);
x86_l_56f3:
	/* 0x56f3: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_56f8:
	/* 0x56f8: movabs rax,0x6b63617473207075 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7738135737528250485ULL);
x86_l_5702:
	/* 0x5702: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5707:
	/* 0x5707: movabs rax,0x206b6f6f6c206f74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2336083356067852148ULL);
x86_l_5711:
	/* 0x5711: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5716:
	/* 0x5716: movabs rax,0x206572756c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334397830517055814ULL);
x86_l_5720:
	/* 0x5720: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5725:
	/* 0x5725: mov    WORD PTR [rsp+0x48],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 309237645322ULL);
x86_l_572c:
	/* 0x572c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5731:
	/* 0x5731: mov    eax,0x3a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_5736:
	/* 0x5736: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_573c:
	/* 0x573c: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_5741:
	/* 0x5741: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5749:
	/* 0x5749: mov    esi,0x3a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 58ULL);
x86_l_574e:
	/* 0x574e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5750:
	/* 0x5750: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5753:
	/* 0x5753: jmp    5f4c <kprobe_unwind_native+0x5f4c> */
	return 24396ULL;
x86_l_5758:
	/* 0x5758: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_575b:
	/* 0x575b: jg     57a3 <kprobe_unwind_native+0x57a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_57a3;
	}
x86_l_575d:
	/* 0x575d: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_5760:
	/* 0x5760: jg     57dc <kprobe_unwind_native+0x57dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_57dc;
	}
x86_l_5762:
	/* 0x5762: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_5765:
	/* 0x5765: je     58f2 <kprobe_unwind_native+0x58f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58f2;
	}
x86_l_576b:
	/* 0x576b: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_576e:
	/* 0x576e: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_582a;
	}
x86_l_5774:
	/* 0x5774: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_17_stack_deltas)));
x86_l_577b:
	/* 0x577b: jmp    592f <kprobe_unwind_native+0x592f> */
	goto x86_l_592f;
x86_l_5780:
	/* 0x5780: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_5783:
	/* 0x5783: jg     57f6 <kprobe_unwind_native+0x57f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_57f6;
	}
x86_l_5785:
	/* 0x5785: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_5788:
	/* 0x5788: je     58fb <kprobe_unwind_native+0x58fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58fb;
	}
x86_l_578e:
	/* 0x578e: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_5791:
	/* 0x5791: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_582a;
	}
x86_l_5797:
	/* 0x5797: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_13_stack_deltas)));
x86_l_579e:
	/* 0x579e: jmp    592f <kprobe_unwind_native+0x592f> */
	goto x86_l_592f;
x86_l_57a3:
	/* 0x57a3: cmp    eax,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_57a6:
	/* 0x57a6: jg     5810 <kprobe_unwind_native+0x5810> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_5810;
	}
x86_l_57a8:
	/* 0x57a8: cmp    eax,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 20ULL);
x86_l_57ab:
	/* 0x57ab: je     5904 <kprobe_unwind_native+0x5904> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5904;
	}
x86_l_57b1:
	/* 0x57b1: cmp    eax,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_57b4:
	/* 0x57b4: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_582a;
	}
x86_l_57b6:
	/* 0x57b6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_21_stack_deltas)));
x86_l_57bd:
	/* 0x57bd: jmp    592f <kprobe_unwind_native+0x592f> */
	goto x86_l_592f;
x86_l_57c2:
	/* 0x57c2: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_57c5:
	/* 0x57c5: je     590d <kprobe_unwind_native+0x590d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_590d;
	}
x86_l_57cb:
	/* 0x57cb: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_57ce:
	/* 0x57ce: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_582a;
	}
x86_l_57d0:
	/* 0x57d0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_11_stack_deltas)));
x86_l_57d7:
	/* 0x57d7: jmp    592f <kprobe_unwind_native+0x592f> */
	goto x86_l_592f;
x86_l_57dc:
	/* 0x57dc: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_57df:
	/* 0x57df: je     5916 <kprobe_unwind_native+0x5916> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5916;
	}
x86_l_57e5:
	/* 0x57e5: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_57e8:
	/* 0x57e8: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_582a;
	}
x86_l_57ea:
	/* 0x57ea: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_19_stack_deltas)));
x86_l_57f1:
	/* 0x57f1: jmp    592f <kprobe_unwind_native+0x592f> */
	goto x86_l_592f;
x86_l_57f6:
	/* 0x57f6: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_57f9:
	/* 0x57f9: je     591f <kprobe_unwind_native+0x591f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_591f;
	}
x86_l_57ff:
	/* 0x57ff: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_5802:
	/* 0x5802: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_582a;
	}
x86_l_5804:
	/* 0x5804: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_15_stack_deltas)));
x86_l_580b:
	/* 0x580b: jmp    592f <kprobe_unwind_native+0x592f> */
	goto x86_l_592f;
x86_l_5810:
	/* 0x5810: cmp    eax,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 22ULL);
x86_l_5813:
	/* 0x5813: je     5928 <kprobe_unwind_native+0x5928> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5928;
	}
x86_l_5819:
	/* 0x5819: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_581c:
	/* 0x581c: jne    582a <kprobe_unwind_native+0x582a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_582a;
	}
x86_l_581e:
	/* 0x581e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_23_stack_deltas)));
x86_l_5825:
	/* 0x5825: jmp    592f <kprobe_unwind_native+0x592f> */
	goto x86_l_592f;
x86_l_582a:
	/* 0x582a: mov    r13d,0xfa1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4001ULL);
x86_l_5830:
	/* 0x5830: mov    r14d,0x33 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 51ULL);
x86_l_5836:
	/* 0x5836: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_583d:
	/* 0x583d: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5840:
	/* 0x5840: je     5f47 <kprobe_unwind_native+0x5f47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24391ULL;
	}
x86_l_5846:
	/* 0x5846: movabs rax,0xa642520444970 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020272ULL);
x86_l_5850:
	/* 0x5850: mov    QWORD PTR [rsp+0x47],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_5855:
	/* 0x5855: movabs rax,0x70616d206e692078 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8097873591047626872ULL);
x86_l_585f:
	/* 0x585f: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5864:
	/* 0x5864: movabs rax,0x6c25206e6f697463 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7792670388922184803ULL);
x86_l_586e:
	/* 0x586e: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5873:
	/* 0x5873: movabs rax,0x6573207478657420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310222304760656928ULL);
x86_l_587d:
	/* 0x587d: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5882:
	/* 0x5882: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_588c:
	/* 0x588c: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5891:
	/* 0x5891: movabs rax,0x726574756f207075 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243122740695953525ULL);
x86_l_589b:
	/* 0x589b: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_58a0:
	/* 0x58a0: movabs rax,0x206b6f6f6c206f74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2336083356067852148ULL);
x86_l_58aa:
	/* 0x58aa: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_58af:
	/* 0x58af: movabs rax,0x206572756c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334397830517055814ULL);
x86_l_58b9:
	/* 0x58b9: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_58be:
	/* 0x58be: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_58c3:
	/* 0x58c3: mov    eax,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 63ULL);
x86_l_58c8:
	/* 0x58c8: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_58ce:
	/* 0x58ce: mov    rdx,QWORD PTR [rsp+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_58d6:
	/* 0x58d6: movzx  ecx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_58da:
	/* 0x58da: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_58df:
	/* 0x58df: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_58e1:
	/* 0x58e1: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_58e4:
	/* 0x58e4: jmp    5f47 <kprobe_unwind_native+0x5f47> */
	return 24391ULL;
x86_l_58e9:
	/* 0x58e9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_8_stack_deltas)));
x86_l_58f0:
	/* 0x58f0: jmp    592f <kprobe_unwind_native+0x592f> */
	goto x86_l_592f;
x86_l_58f2:
	/* 0x58f2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_16_stack_deltas)));
x86_l_58f9:
	/* 0x58f9: jmp    592f <kprobe_unwind_native+0x592f> */
	goto x86_l_592f;
x86_l_58fb:
	/* 0x58fb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_12_stack_deltas)));
x86_l_5902:
	/* 0x5902: jmp    592f <kprobe_unwind_native+0x592f> */
	goto x86_l_592f;
x86_l_5904:
	/* 0x5904: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_20_stack_deltas)));
x86_l_590b:
	/* 0x590b: jmp    592f <kprobe_unwind_native+0x592f> */
	goto x86_l_592f;
x86_l_590d:
	/* 0x590d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_10_stack_deltas)));
x86_l_5914:
	/* 0x5914: jmp    592f <kprobe_unwind_native+0x592f> */
	goto x86_l_592f;
x86_l_5916:
	/* 0x5916: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_18_stack_deltas)));
x86_l_591d:
	/* 0x591d: jmp    592f <kprobe_unwind_native+0x592f> */
	goto x86_l_592f;
x86_l_591f:
	/* 0x591f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_14_stack_deltas)));
x86_l_5926:
	/* 0x5926: jmp    592f <kprobe_unwind_native+0x592f> */
	goto x86_l_592f;
x86_l_5928:
	/* 0x5928: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_22_stack_deltas)));
x86_l_592f:
	/* 0x592f: lea    rsi,[rsp+0x160] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_5937:
	/* 0x5937: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_593c:
	/* 0x593c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_593e:
	/* 0x593e: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5943:
	/* 0x5943: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5946:
	/* 0x5946: je     5f2b <kprobe_unwind_native+0x5f2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24363ULL;
	}
x86_l_594c:
	/* 0x594c: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5951:
	/* 0x5951: mov    r13d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5954:
	/* 0x5954: mov    DWORD PTR [rsp+0x90],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_595c:
	/* 0x595c: mov    rax,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_5963:
	/* 0x5963: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5968:
	/* 0x5968: movzx  eax,WORD PTR [rcx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_596c:
	/* 0x596c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_596e:
	/* 0x596e: je     5e65 <kprobe_unwind_native+0x5e65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24165ULL;
	}
x86_l_5974:
	/* 0x5974: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_5977:
	/* 0x5977: add    r12d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_597a:
	/* 0x597a: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5981:
	/* 0x5981: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5984:
	/* 0x5984: jne    6839 <kprobe_unwind_native+0x6839> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 26681ULL;
	}
x86_l_598a:
	/* 0x598a: lea    eax,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_598e:
	/* 0x598e: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5990:
	/* 0x5990: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5994:
	/* 0x5994: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5999:
	/* 0x5999: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_599e:
	/* 0x599e: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_59a3:
	/* 0x59a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59a5:
	/* 0x59a5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_59a8:
	/* 0x59a8: je     61df <kprobe_unwind_native+0x61df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25055ULL;
	}
x86_l_59ae:
	/* 0x59ae: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_59b2:
	/* 0x59b2: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_59b5:
	/* 0x59b5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59ba:
	/* 0x59ba: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59bd:
	/* 0x59bd: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_59c1:
	/* 0x59c1: cmova  r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_59c5:
	/* 0x59c5: mov    QWORD PTR [rsp],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59c9:
	/* 0x59c9: cmp    ebp,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R12, X86_WIDTH_32);
x86_l_59cc:
	/* 0x59cc: jae    5e56 <kprobe_unwind_native+0x5e56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 24150ULL;
	}
x86_l_59d2:
	/* 0x59d2: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59d6:
	/* 0x59d6: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_59d8:
	/* 0x59d8: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_59da:
	/* 0x59da: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_59de:
	/* 0x59de: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_59e3:
	/* 0x59e3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_59e8:
	/* 0x59e8: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_59ed:
	/* 0x59ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59ef:
	/* 0x59ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_59f2:
	/* 0x59f2: je     61df <kprobe_unwind_native+0x61df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25055ULL;
	}
x86_l_59f8:
	/* 0x59f8: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_59fc:
	/* 0x59fc: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5a00:
	/* 0x5a00: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a05:
	/* 0x5a05: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a08:
	/* 0x5a08: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_5a0c:
	/* 0x5a0c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a10:
	/* 0x5a10: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5a13:
	/* 0x5a13: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a17:
	/* 0x5a17: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_5a1a:
	/* 0x5a1a: jae    5e56 <kprobe_unwind_native+0x5e56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 24150ULL;
	}
x86_l_5a20:
	/* 0x5a20: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a24:
	/* 0x5a24: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5a27:
	/* 0x5a27: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5a29:
	/* 0x5a29: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a2d:
	/* 0x5a2d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a32:
	/* 0x5a32: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5a37:
	/* 0x5a37: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5a3c:
	/* 0x5a3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a3e:
	/* 0x5a3e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5a41:
	/* 0x5a41: je     61df <kprobe_unwind_native+0x61df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25055ULL;
	}
x86_l_5a47:
	/* 0x5a47: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a4b:
	/* 0x5a4b: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5a4e:
	/* 0x5a4e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a53:
	/* 0x5a53: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a56:
	/* 0x5a56: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_5a5a:
	/* 0x5a5a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a5e:
	/* 0x5a5e: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5a61:
	/* 0x5a61: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a65:
	/* 0x5a65: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_5a67:
	/* 0x5a67: jae    5e56 <kprobe_unwind_native+0x5e56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 24150ULL;
	}
x86_l_5a6d:
	/* 0x5a6d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a71:
	/* 0x5a71: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5a73:
	/* 0x5a73: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5a75:
	/* 0x5a75: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a79:
	/* 0x5a79: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a7e:
	/* 0x5a7e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5a83:
	/* 0x5a83: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5a88:
	/* 0x5a88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a8a:
	/* 0x5a8a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5a8d:
	/* 0x5a8d: je     61df <kprobe_unwind_native+0x61df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25055ULL;
	}
x86_l_5a93:
	/* 0x5a93: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a97:
	/* 0x5a97: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5a9b:
	/* 0x5a9b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5aa0:
	/* 0x5aa0: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5aa3:
	/* 0x5aa3: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_5aa7:
	/* 0x5aa7: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5aab:
	/* 0x5aab: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5aae:
	/* 0x5aae: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ab2:
	/* 0x5ab2: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_5ab5:
	/* 0x5ab5: jae    5e56 <kprobe_unwind_native+0x5e56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 24150ULL;
	}
x86_l_5abb:
	/* 0x5abb: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5abf:
	/* 0x5abf: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5ac2:
	/* 0x5ac2: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5ac4:
	/* 0x5ac4: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ac8:
	/* 0x5ac8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5acd:
	/* 0x5acd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5ad2:
	/* 0x5ad2: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5ad7:
	/* 0x5ad7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ad9:
	/* 0x5ad9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5adc:
	/* 0x5adc: je     61df <kprobe_unwind_native+0x61df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25055ULL;
	}
x86_l_5ae2:
	/* 0x5ae2: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ae6:
	/* 0x5ae6: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5ae9:
	/* 0x5ae9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5aee:
	/* 0x5aee: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5af1:
	/* 0x5af1: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_5af5:
	/* 0x5af5: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5af9:
	/* 0x5af9: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5afc:
	/* 0x5afc: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b00:
	/* 0x5b00: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_5b02:
	/* 0x5b02: jae    5e56 <kprobe_unwind_native+0x5e56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 24150ULL;
	}
x86_l_5b08:
	/* 0x5b08: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b0c:
	/* 0x5b0c: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5b0e:
	/* 0x5b0e: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5b10:
	/* 0x5b10: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b14:
	/* 0x5b14: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b19:
	/* 0x5b19: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5b1e:
	/* 0x5b1e: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5b23:
	/* 0x5b23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b25:
	/* 0x5b25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b28:
	/* 0x5b28: je     61df <kprobe_unwind_native+0x61df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25055ULL;
	}
x86_l_5b2e:
	/* 0x5b2e: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b32:
	/* 0x5b32: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5b36:
	/* 0x5b36: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b3b:
	/* 0x5b3b: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b3e:
	/* 0x5b3e: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_5b42:
	/* 0x5b42: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b46:
	/* 0x5b46: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5b49:
	/* 0x5b49: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b4d:
	/* 0x5b4d: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_5b50:
	/* 0x5b50: jae    5e56 <kprobe_unwind_native+0x5e56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 24150ULL;
	}
x86_l_5b56:
	/* 0x5b56: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b5a:
	/* 0x5b5a: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5b5d:
	/* 0x5b5d: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5b5f:
	/* 0x5b5f: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b63:
	/* 0x5b63: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b68:
	/* 0x5b68: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5b6d:
	/* 0x5b6d: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5b72:
	/* 0x5b72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b74:
	/* 0x5b74: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b77:
	/* 0x5b77: je     61df <kprobe_unwind_native+0x61df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25055ULL;
	}
x86_l_5b7d:
	/* 0x5b7d: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b81:
	/* 0x5b81: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5b84:
	/* 0x5b84: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b89:
	/* 0x5b89: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b8c:
	/* 0x5b8c: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_5b90:
	/* 0x5b90: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b94:
	/* 0x5b94: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5b97:
	/* 0x5b97: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b9b:
	/* 0x5b9b: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_5b9d:
	/* 0x5b9d: jae    5e56 <kprobe_unwind_native+0x5e56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 24150ULL;
	}
x86_l_5ba3:
	/* 0x5ba3: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ba7:
	/* 0x5ba7: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5ba9:
	/* 0x5ba9: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5bab:
	/* 0x5bab: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5baf:
	/* 0x5baf: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5bb4:
	/* 0x5bb4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5bb9:
	/* 0x5bb9: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5bbe:
	/* 0x5bbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bc0:
	/* 0x5bc0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5bc3:
	/* 0x5bc3: je     61df <kprobe_unwind_native+0x61df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25055ULL;
	}
	return 23497ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 23497ULL: goto x86_l_5bc9;
	case 23501ULL: goto x86_l_5bcd;
	case 23505ULL: goto x86_l_5bd1;
	case 23510ULL: goto x86_l_5bd6;
	case 23513ULL: goto x86_l_5bd9;
	case 23517ULL: goto x86_l_5bdd;
	case 23521ULL: goto x86_l_5be1;
	case 23524ULL: goto x86_l_5be4;
	case 23528ULL: goto x86_l_5be8;
	case 23531ULL: goto x86_l_5beb;
	case 23537ULL: goto x86_l_5bf1;
	case 23541ULL: goto x86_l_5bf5;
	case 23544ULL: goto x86_l_5bf8;
	case 23546ULL: goto x86_l_5bfa;
	case 23550ULL: goto x86_l_5bfe;
	case 23555ULL: goto x86_l_5c03;
	case 23560ULL: goto x86_l_5c08;
	case 23565ULL: goto x86_l_5c0d;
	case 23567ULL: goto x86_l_5c0f;
	case 23570ULL: goto x86_l_5c12;
	case 23576ULL: goto x86_l_5c18;
	case 23580ULL: goto x86_l_5c1c;
	case 23583ULL: goto x86_l_5c1f;
	case 23588ULL: goto x86_l_5c24;
	case 23591ULL: goto x86_l_5c27;
	case 23595ULL: goto x86_l_5c2b;
	case 23599ULL: goto x86_l_5c2f;
	case 23602ULL: goto x86_l_5c32;
	case 23606ULL: goto x86_l_5c36;
	case 23608ULL: goto x86_l_5c38;
	case 23614ULL: goto x86_l_5c3e;
	case 23618ULL: goto x86_l_5c42;
	case 23620ULL: goto x86_l_5c44;
	case 23622ULL: goto x86_l_5c46;
	case 23626ULL: goto x86_l_5c4a;
	case 23631ULL: goto x86_l_5c4f;
	case 23636ULL: goto x86_l_5c54;
	case 23641ULL: goto x86_l_5c59;
	case 23643ULL: goto x86_l_5c5b;
	case 23646ULL: goto x86_l_5c5e;
	case 23652ULL: goto x86_l_5c64;
	case 23656ULL: goto x86_l_5c68;
	case 23660ULL: goto x86_l_5c6c;
	case 23665ULL: goto x86_l_5c71;
	case 23668ULL: goto x86_l_5c74;
	case 23672ULL: goto x86_l_5c78;
	case 23676ULL: goto x86_l_5c7c;
	case 23679ULL: goto x86_l_5c7f;
	case 23683ULL: goto x86_l_5c83;
	case 23686ULL: goto x86_l_5c86;
	case 23692ULL: goto x86_l_5c8c;
	case 23696ULL: goto x86_l_5c90;
	case 23699ULL: goto x86_l_5c93;
	case 23701ULL: goto x86_l_5c95;
	case 23705ULL: goto x86_l_5c99;
	case 23710ULL: goto x86_l_5c9e;
	case 23715ULL: goto x86_l_5ca3;
	case 23720ULL: goto x86_l_5ca8;
	case 23722ULL: goto x86_l_5caa;
	case 23725ULL: goto x86_l_5cad;
	case 23731ULL: goto x86_l_5cb3;
	case 23735ULL: goto x86_l_5cb7;
	case 23738ULL: goto x86_l_5cba;
	case 23743ULL: goto x86_l_5cbf;
	case 23746ULL: goto x86_l_5cc2;
	case 23750ULL: goto x86_l_5cc6;
	case 23754ULL: goto x86_l_5cca;
	case 23757ULL: goto x86_l_5ccd;
	case 23761ULL: goto x86_l_5cd1;
	case 23763ULL: goto x86_l_5cd3;
	case 23769ULL: goto x86_l_5cd9;
	case 23773ULL: goto x86_l_5cdd;
	case 23775ULL: goto x86_l_5cdf;
	case 23777ULL: goto x86_l_5ce1;
	case 23781ULL: goto x86_l_5ce5;
	case 23786ULL: goto x86_l_5cea;
	case 23791ULL: goto x86_l_5cef;
	case 23796ULL: goto x86_l_5cf4;
	case 23798ULL: goto x86_l_5cf6;
	case 23801ULL: goto x86_l_5cf9;
	case 23807ULL: goto x86_l_5cff;
	case 23811ULL: goto x86_l_5d03;
	case 23815ULL: goto x86_l_5d07;
	case 23820ULL: goto x86_l_5d0c;
	case 23823ULL: goto x86_l_5d0f;
	case 23827ULL: goto x86_l_5d13;
	case 23831ULL: goto x86_l_5d17;
	case 23834ULL: goto x86_l_5d1a;
	case 23838ULL: goto x86_l_5d1e;
	case 23841ULL: goto x86_l_5d21;
	case 23847ULL: goto x86_l_5d27;
	case 23851ULL: goto x86_l_5d2b;
	case 23854ULL: goto x86_l_5d2e;
	case 23856ULL: goto x86_l_5d30;
	case 23860ULL: goto x86_l_5d34;
	case 23865ULL: goto x86_l_5d39;
	case 23870ULL: goto x86_l_5d3e;
	case 23875ULL: goto x86_l_5d43;
	case 23877ULL: goto x86_l_5d45;
	case 23880ULL: goto x86_l_5d48;
	case 23886ULL: goto x86_l_5d4e;
	case 23890ULL: goto x86_l_5d52;
	case 23893ULL: goto x86_l_5d55;
	case 23898ULL: goto x86_l_5d5a;
	case 23901ULL: goto x86_l_5d5d;
	case 23905ULL: goto x86_l_5d61;
	case 23909ULL: goto x86_l_5d65;
	case 23912ULL: goto x86_l_5d68;
	case 23916ULL: goto x86_l_5d6c;
	case 23918ULL: goto x86_l_5d6e;
	case 23924ULL: goto x86_l_5d74;
	case 23928ULL: goto x86_l_5d78;
	case 23930ULL: goto x86_l_5d7a;
	case 23932ULL: goto x86_l_5d7c;
	case 23936ULL: goto x86_l_5d80;
	case 23941ULL: goto x86_l_5d85;
	case 23946ULL: goto x86_l_5d8a;
	case 23951ULL: goto x86_l_5d8f;
	case 23953ULL: goto x86_l_5d91;
	case 23956ULL: goto x86_l_5d94;
	case 23962ULL: goto x86_l_5d9a;
	case 23966ULL: goto x86_l_5d9e;
	case 23970ULL: goto x86_l_5da2;
	case 23975ULL: goto x86_l_5da7;
	case 23978ULL: goto x86_l_5daa;
	case 23982ULL: goto x86_l_5dae;
	case 23986ULL: goto x86_l_5db2;
	case 23989ULL: goto x86_l_5db5;
	case 23993ULL: goto x86_l_5db9;
	case 23996ULL: goto x86_l_5dbc;
	case 24002ULL: goto x86_l_5dc2;
	case 24006ULL: goto x86_l_5dc6;
	case 24009ULL: goto x86_l_5dc9;
	case 24011ULL: goto x86_l_5dcb;
	case 24015ULL: goto x86_l_5dcf;
	case 24020ULL: goto x86_l_5dd4;
	case 24025ULL: goto x86_l_5dd9;
	case 24030ULL: goto x86_l_5dde;
	case 24032ULL: goto x86_l_5de0;
	case 24035ULL: goto x86_l_5de3;
	case 24041ULL: goto x86_l_5de9;
	case 24045ULL: goto x86_l_5ded;
	case 24048ULL: goto x86_l_5df0;
	case 24053ULL: goto x86_l_5df5;
	case 24056ULL: goto x86_l_5df8;
	case 24060ULL: goto x86_l_5dfc;
	case 24064ULL: goto x86_l_5e00;
	case 24067ULL: goto x86_l_5e03;
	case 24071ULL: goto x86_l_5e07;
	case 24073ULL: goto x86_l_5e09;
	case 24075ULL: goto x86_l_5e0b;
	case 24079ULL: goto x86_l_5e0f;
	case 24081ULL: goto x86_l_5e11;
	case 24083ULL: goto x86_l_5e13;
	case 24087ULL: goto x86_l_5e17;
	case 24092ULL: goto x86_l_5e1c;
	case 24097ULL: goto x86_l_5e21;
	case 24102ULL: goto x86_l_5e26;
	case 24104ULL: goto x86_l_5e28;
	case 24107ULL: goto x86_l_5e2b;
	case 24113ULL: goto x86_l_5e31;
	case 24117ULL: goto x86_l_5e35;
	case 24120ULL: goto x86_l_5e38;
	case 24125ULL: goto x86_l_5e3d;
	case 24128ULL: goto x86_l_5e40;
	case 24131ULL: goto x86_l_5e43;
	case 24135ULL: goto x86_l_5e47;
	case 24138ULL: goto x86_l_5e4a;
	case 24142ULL: goto x86_l_5e4e;
	case 24144ULL: goto x86_l_5e50;
	case 24150ULL: goto x86_l_5e56;
	case 24154ULL: goto x86_l_5e5a;
	case 24157ULL: goto x86_l_5e5d;
	case 24159ULL: goto x86_l_5e5f;
	case 24165ULL: goto x86_l_5e65;
	case 24168ULL: goto x86_l_5e68;
	case 24176ULL: goto x86_l_5e70;
	case 24184ULL: goto x86_l_5e78;
	case 24189ULL: goto x86_l_5e7d;
	case 24194ULL: goto x86_l_5e82;
	case 24196ULL: goto x86_l_5e84;
	case 24199ULL: goto x86_l_5e87;
	case 24204ULL: goto x86_l_5e8c;
	case 24209ULL: goto x86_l_5e91;
	case 24215ULL: goto x86_l_5e97;
	case 24218ULL: goto x86_l_5e9a;
	case 24225ULL: goto x86_l_5ea1;
	case 24228ULL: goto x86_l_5ea4;
	case 24234ULL: goto x86_l_5eaa;
	case 24239ULL: goto x86_l_5eaf;
	case 24243ULL: goto x86_l_5eb3;
	case 24245ULL: goto x86_l_5eb5;
	case 24252ULL: goto x86_l_5ebc;
	case 24259ULL: goto x86_l_5ec3;
	case 24264ULL: goto x86_l_5ec8;
	case 24266ULL: goto x86_l_5eca;
	case 24270ULL: goto x86_l_5ece;
	case 24274ULL: goto x86_l_5ed2;
	case 24281ULL: goto x86_l_5ed9;
	case 24286ULL: goto x86_l_5ede;
	case 24291ULL: goto x86_l_5ee3;
	case 24296ULL: goto x86_l_5ee8;
	case 24302ULL: goto x86_l_5eee;
	case 24307ULL: goto x86_l_5ef3;
	case 24313ULL: goto x86_l_5ef9;
	case 24324ULL: goto x86_l_5f04;
	case 24331ULL: goto x86_l_5f0b;
	case 24339ULL: goto x86_l_5f13;
	case 24344ULL: goto x86_l_5f18;
	case 24346ULL: goto x86_l_5f1a;
	case 24349ULL: goto x86_l_5f1d;
	case 24355ULL: goto x86_l_5f23;
	case 24358ULL: goto x86_l_5f26;
	case 24363ULL: goto x86_l_5f2b;
	case 24369ULL: goto x86_l_5f31;
	case 24375ULL: goto x86_l_5f37;
	case 24382ULL: goto x86_l_5f3e;
	case 24385ULL: goto x86_l_5f41;
	case 24391ULL: goto x86_l_5f47;
	case 24396ULL: goto x86_l_5f4c;
	case 24403ULL: goto x86_l_5f53;
	case 24406ULL: goto x86_l_5f56;
	case 24409ULL: goto x86_l_5f59;
	case 24416ULL: goto x86_l_5f60;
	case 24423ULL: goto x86_l_5f67;
	case 24434ULL: goto x86_l_5f72;
	case 24441ULL: goto x86_l_5f79;
	case 24449ULL: goto x86_l_5f81;
	case 24454ULL: goto x86_l_5f86;
	case 24456ULL: goto x86_l_5f88;
	case 24459ULL: goto x86_l_5f8b;
	case 24461ULL: goto x86_l_5f8d;
	case 24468ULL: goto x86_l_5f94;
	case 24471ULL: goto x86_l_5f97;
	case 24474ULL: goto x86_l_5f9a;
	case 24476ULL: goto x86_l_5f9c;
	case 24479ULL: goto x86_l_5f9f;
	case 24489ULL: goto x86_l_5fa9;
	case 24497ULL: goto x86_l_5fb1;
	case 24504ULL: goto x86_l_5fb8;
	case 24509ULL: goto x86_l_5fbd;
	case 24514ULL: goto x86_l_5fc2;
	case 24516ULL: goto x86_l_5fc4;
	case 24519ULL: goto x86_l_5fc7;
	case 24521ULL: goto x86_l_5fc9;
	case 24524ULL: goto x86_l_5fcc;
	case 24526ULL: goto x86_l_5fce;
	case 24533ULL: goto x86_l_5fd5;
	case 24535ULL: goto x86_l_5fd7;
	case 24540ULL: goto x86_l_5fdc;
	case 24542ULL: goto x86_l_5fde;
	case 24547ULL: goto x86_l_5fe3;
	case 24553ULL: goto x86_l_5fe9;
	case 24556ULL: goto x86_l_5fec;
	case 24563ULL: goto x86_l_5ff3;
	case 24565ULL: goto x86_l_5ff5;
	case 24567ULL: goto x86_l_5ff7;
	case 24573ULL: goto x86_l_5ffd;
	case 24575ULL: goto x86_l_5fff;
	case 24582ULL: goto x86_l_6006;
	case 24587ULL: goto x86_l_600b;
	case 24594ULL: goto x86_l_6012;
	case 24597ULL: goto x86_l_6015;
	case 24599ULL: goto x86_l_6017;
	case 24604ULL: goto x86_l_601c;
	case 24606ULL: goto x86_l_601e;
	case 24611ULL: goto x86_l_6023;
	case 24618ULL: goto x86_l_602a;
	case 24619ULL: goto x86_l_602b;
	case 24621ULL: goto x86_l_602d;
	case 24623ULL: goto x86_l_602f;
	case 24625ULL: goto x86_l_6031;
	case 24627ULL: goto x86_l_6033;
	case 24628ULL: goto x86_l_6034;
	case 24633ULL: goto x86_l_6039;
	case 24643ULL: goto x86_l_6043;
	case 24651ULL: goto x86_l_604b;
	case 24661ULL: goto x86_l_6055;
	case 24669ULL: goto x86_l_605d;
	case 24679ULL: goto x86_l_6067;
	case 24687ULL: goto x86_l_606f;
	case 24697ULL: goto x86_l_6079;
	case 24705ULL: goto x86_l_6081;
	case 24715ULL: goto x86_l_608b;
	case 24723ULL: goto x86_l_6093;
	case 24733ULL: goto x86_l_609d;
	case 24741ULL: goto x86_l_60a5;
	case 24749ULL: goto x86_l_60ad;
	case 24754ULL: goto x86_l_60b2;
	case 24759ULL: goto x86_l_60b7;
	case 24764ULL: goto x86_l_60bc;
	case 24767ULL: goto x86_l_60bf;
	case 24769ULL: goto x86_l_60c1;
	case 24771ULL: goto x86_l_60c3;
	case 24776ULL: goto x86_l_60c8;
	case 24786ULL: goto x86_l_60d2;
	case 24794ULL: goto x86_l_60da;
	case 24804ULL: goto x86_l_60e4;
	case 24812ULL: goto x86_l_60ec;
	case 24822ULL: goto x86_l_60f6;
	case 24830ULL: goto x86_l_60fe;
	case 24840ULL: goto x86_l_6108;
	case 24848ULL: goto x86_l_6110;
	case 24858ULL: goto x86_l_611a;
	case 24866ULL: goto x86_l_6122;
	case 24876ULL: goto x86_l_612c;
	case 24884ULL: goto x86_l_6134;
	case 24892ULL: goto x86_l_613c;
	case 24897ULL: goto x86_l_6141;
	case 24902ULL: goto x86_l_6146;
	case 24906ULL: goto x86_l_614a;
	case 24911ULL: goto x86_l_614f;
	case 24913ULL: goto x86_l_6151;
	case 24915ULL: goto x86_l_6153;
	case 24920ULL: goto x86_l_6158;
	case 24930ULL: goto x86_l_6162;
	case 24935ULL: goto x86_l_6167;
	case 24945ULL: goto x86_l_6171;
	case 24950ULL: goto x86_l_6176;
	case 24960ULL: goto x86_l_6180;
	case 24965ULL: goto x86_l_6185;
	case 24975ULL: goto x86_l_618f;
	case 24980ULL: goto x86_l_6194;
	case 24990ULL: goto x86_l_619e;
	case 24995ULL: goto x86_l_61a3;
	case 25005ULL: goto x86_l_61ad;
	case 25010ULL: goto x86_l_61b2;
	case 25018ULL: goto x86_l_61ba;
	case 25023ULL: goto x86_l_61bf;
	case 25028ULL: goto x86_l_61c4;
	case 25033ULL: goto x86_l_61c9;
	case 25041ULL: goto x86_l_61d1;
	case 25046ULL: goto x86_l_61d6;
	case 25048ULL: goto x86_l_61d8;
	case 25050ULL: goto x86_l_61da;
	case 25055ULL: goto x86_l_61df;
	case 25062ULL: goto x86_l_61e6;
	case 25065ULL: goto x86_l_61e9;
	case 25071ULL: goto x86_l_61ef;
	case 25081ULL: goto x86_l_61f9;
	case 25086ULL: goto x86_l_61fe;
	case 25096ULL: goto x86_l_6208;
	case 25101ULL: goto x86_l_620d;
	case 25111ULL: goto x86_l_6217;
	case 25116ULL: goto x86_l_621c;
	case 25126ULL: goto x86_l_6226;
	case 25131ULL: goto x86_l_622b;
	case 25141ULL: goto x86_l_6235;
	case 25146ULL: goto x86_l_623a;
	case 25154ULL: goto x86_l_6242;
	case 25159ULL: goto x86_l_6247;
	case 25164ULL: goto x86_l_624c;
	case 25169ULL: goto x86_l_6251;
	case 25174ULL: goto x86_l_6256;
	case 25181ULL: goto x86_l_625d;
	case 25184ULL: goto x86_l_6260;
	case 25190ULL: goto x86_l_6266;
	case 25197ULL: goto x86_l_626d;
	case 25200ULL: goto x86_l_6270;
	case 25206ULL: goto x86_l_6276;
	case 25213ULL: goto x86_l_627d;
	case 25221ULL: goto x86_l_6285;
	case 25226ULL: goto x86_l_628a;
	case 25228ULL: goto x86_l_628c;
	case 25233ULL: goto x86_l_6291;
	case 25236ULL: goto x86_l_6294;
	case 25242ULL: goto x86_l_629a;
	case 25247ULL: goto x86_l_629f;
	case 25250ULL: goto x86_l_62a2;
	case 25254ULL: goto x86_l_62a6;
	case 25256ULL: goto x86_l_62a8;
	case 25258ULL: goto x86_l_62aa;
	case 25265ULL: goto x86_l_62b1;
	case 25268ULL: goto x86_l_62b4;
	case 25274ULL: goto x86_l_62ba;
	case 25276ULL: goto x86_l_62bc;
	case 25279ULL: goto x86_l_62bf;
	case 25282ULL: goto x86_l_62c2;
	case 25285ULL: goto x86_l_62c5;
	case 25287ULL: goto x86_l_62c7;
	case 25289ULL: goto x86_l_62c9;
	case 25291ULL: goto x86_l_62cb;
	case 25294ULL: goto x86_l_62ce;
	case 25297ULL: goto x86_l_62d1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5bc9:
	/* 0x5bc9: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5bcd:
	/* 0x5bcd: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5bd1:
	/* 0x5bd1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bd6:
	/* 0x5bd6: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5bd9:
	/* 0x5bd9: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_5bdd:
	/* 0x5bdd: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5be1:
	/* 0x5be1: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5be4:
	/* 0x5be4: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5be8:
	/* 0x5be8: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_5beb:
	/* 0x5beb: jae    5e56 <kprobe_unwind_native+0x5e56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5e56;
	}
x86_l_5bf1:
	/* 0x5bf1: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5bf5:
	/* 0x5bf5: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5bf8:
	/* 0x5bf8: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5bfa:
	/* 0x5bfa: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5bfe:
	/* 0x5bfe: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c03:
	/* 0x5c03: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5c08:
	/* 0x5c08: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5c0d:
	/* 0x5c0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c0f:
	/* 0x5c0f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5c12:
	/* 0x5c12: je     61df <kprobe_unwind_native+0x61df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61df;
	}
x86_l_5c18:
	/* 0x5c18: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c1c:
	/* 0x5c1c: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5c1f:
	/* 0x5c1f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c24:
	/* 0x5c24: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c27:
	/* 0x5c27: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_5c2b:
	/* 0x5c2b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c2f:
	/* 0x5c2f: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5c32:
	/* 0x5c32: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c36:
	/* 0x5c36: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_5c38:
	/* 0x5c38: jae    5e56 <kprobe_unwind_native+0x5e56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5e56;
	}
x86_l_5c3e:
	/* 0x5c3e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c42:
	/* 0x5c42: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5c44:
	/* 0x5c44: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5c46:
	/* 0x5c46: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c4a:
	/* 0x5c4a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c4f:
	/* 0x5c4f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5c54:
	/* 0x5c54: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5c59:
	/* 0x5c59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c5b:
	/* 0x5c5b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5c5e:
	/* 0x5c5e: je     61df <kprobe_unwind_native+0x61df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61df;
	}
x86_l_5c64:
	/* 0x5c64: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c68:
	/* 0x5c68: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5c6c:
	/* 0x5c6c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c71:
	/* 0x5c71: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c74:
	/* 0x5c74: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_5c78:
	/* 0x5c78: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c7c:
	/* 0x5c7c: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5c7f:
	/* 0x5c7f: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c83:
	/* 0x5c83: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_5c86:
	/* 0x5c86: jae    5e56 <kprobe_unwind_native+0x5e56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5e56;
	}
x86_l_5c8c:
	/* 0x5c8c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c90:
	/* 0x5c90: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5c93:
	/* 0x5c93: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5c95:
	/* 0x5c95: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c99:
	/* 0x5c99: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c9e:
	/* 0x5c9e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5ca3:
	/* 0x5ca3: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5ca8:
	/* 0x5ca8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5caa:
	/* 0x5caa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5cad:
	/* 0x5cad: je     61df <kprobe_unwind_native+0x61df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61df;
	}
x86_l_5cb3:
	/* 0x5cb3: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5cb7:
	/* 0x5cb7: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5cba:
	/* 0x5cba: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cbf:
	/* 0x5cbf: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cc2:
	/* 0x5cc2: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_5cc6:
	/* 0x5cc6: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cca:
	/* 0x5cca: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5ccd:
	/* 0x5ccd: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cd1:
	/* 0x5cd1: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_5cd3:
	/* 0x5cd3: jae    5e56 <kprobe_unwind_native+0x5e56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5e56;
	}
x86_l_5cd9:
	/* 0x5cd9: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cdd:
	/* 0x5cdd: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5cdf:
	/* 0x5cdf: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5ce1:
	/* 0x5ce1: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ce5:
	/* 0x5ce5: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5cea:
	/* 0x5cea: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5cef:
	/* 0x5cef: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5cf4:
	/* 0x5cf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cf6:
	/* 0x5cf6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5cf9:
	/* 0x5cf9: je     61df <kprobe_unwind_native+0x61df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61df;
	}
x86_l_5cff:
	/* 0x5cff: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d03:
	/* 0x5d03: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5d07:
	/* 0x5d07: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d0c:
	/* 0x5d0c: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d0f:
	/* 0x5d0f: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_5d13:
	/* 0x5d13: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d17:
	/* 0x5d17: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5d1a:
	/* 0x5d1a: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d1e:
	/* 0x5d1e: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_5d21:
	/* 0x5d21: jae    5e56 <kprobe_unwind_native+0x5e56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5e56;
	}
x86_l_5d27:
	/* 0x5d27: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d2b:
	/* 0x5d2b: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5d2e:
	/* 0x5d2e: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5d30:
	/* 0x5d30: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d34:
	/* 0x5d34: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d39:
	/* 0x5d39: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5d3e:
	/* 0x5d3e: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5d43:
	/* 0x5d43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d45:
	/* 0x5d45: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5d48:
	/* 0x5d48: je     61df <kprobe_unwind_native+0x61df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61df;
	}
x86_l_5d4e:
	/* 0x5d4e: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d52:
	/* 0x5d52: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5d55:
	/* 0x5d55: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d5a:
	/* 0x5d5a: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d5d:
	/* 0x5d5d: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_5d61:
	/* 0x5d61: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d65:
	/* 0x5d65: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5d68:
	/* 0x5d68: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d6c:
	/* 0x5d6c: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_5d6e:
	/* 0x5d6e: jae    5e56 <kprobe_unwind_native+0x5e56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5e56;
	}
x86_l_5d74:
	/* 0x5d74: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d78:
	/* 0x5d78: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5d7a:
	/* 0x5d7a: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5d7c:
	/* 0x5d7c: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d80:
	/* 0x5d80: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d85:
	/* 0x5d85: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5d8a:
	/* 0x5d8a: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5d8f:
	/* 0x5d8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d91:
	/* 0x5d91: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5d94:
	/* 0x5d94: je     61df <kprobe_unwind_native+0x61df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61df;
	}
x86_l_5d9a:
	/* 0x5d9a: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d9e:
	/* 0x5d9e: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5da2:
	/* 0x5da2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5da7:
	/* 0x5da7: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5daa:
	/* 0x5daa: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_5dae:
	/* 0x5dae: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5db2:
	/* 0x5db2: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5db5:
	/* 0x5db5: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5db9:
	/* 0x5db9: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_5dbc:
	/* 0x5dbc: jae    5e56 <kprobe_unwind_native+0x5e56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5e56;
	}
x86_l_5dc2:
	/* 0x5dc2: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5dc6:
	/* 0x5dc6: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5dc9:
	/* 0x5dc9: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5dcb:
	/* 0x5dcb: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5dcf:
	/* 0x5dcf: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5dd4:
	/* 0x5dd4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5dd9:
	/* 0x5dd9: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5dde:
	/* 0x5dde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5de0:
	/* 0x5de0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5de3:
	/* 0x5de3: je     61df <kprobe_unwind_native+0x61df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61df;
	}
x86_l_5de9:
	/* 0x5de9: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ded:
	/* 0x5ded: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5df0:
	/* 0x5df0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5df5:
	/* 0x5df5: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5df8:
	/* 0x5df8: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_5dfc:
	/* 0x5dfc: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e00:
	/* 0x5e00: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5e03:
	/* 0x5e03: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e07:
	/* 0x5e07: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_5e09:
	/* 0x5e09: jae    5e56 <kprobe_unwind_native+0x5e56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5e56;
	}
x86_l_5e0b:
	/* 0x5e0b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e0f:
	/* 0x5e0f: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5e11:
	/* 0x5e11: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5e13:
	/* 0x5e13: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e17:
	/* 0x5e17: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e1c:
	/* 0x5e1c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5e21:
	/* 0x5e21: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5e26:
	/* 0x5e26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e28:
	/* 0x5e28: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5e2b:
	/* 0x5e2b: je     61df <kprobe_unwind_native+0x61df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61df;
	}
x86_l_5e31:
	/* 0x5e31: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e35:
	/* 0x5e35: lea    edx,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5e38:
	/* 0x5e38: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e3d:
	/* 0x5e3d: cmp    WORD PTR [rax],si */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e40:
	/* 0x5e40: cmova  edx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_5e43:
	/* 0x5e43: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e47:
	/* 0x5e47: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5e4a:
	/* 0x5e4a: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e4e:
	/* 0x5e4e: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_5e50:
	/* 0x5e50: jb     61df <kprobe_unwind_native+0x61df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_61df;
	}
x86_l_5e56:
	/* 0x5e56: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e5a:
	/* 0x5e5a: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_5e5d:
	/* 0x5e5d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5e5f:
	/* 0x5e5f: je     61df <kprobe_unwind_native+0x61df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61df;
	}
x86_l_5e65:
	/* 0x5e65: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_5e68:
	/* 0x5e68: mov    DWORD PTR [rsp+0x90],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_5e70:
	/* 0x5e70: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_5e78:
	/* 0x5e78: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5e7d:
	/* 0x5e7d: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5e82:
	/* 0x5e82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e84:
	/* 0x5e84: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5e87:
	/* 0x5e87: mov    ecx,0xfa4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4004ULL);
x86_l_5e8c:
	/* 0x5e8c: mov    edx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_5e91:
	/* 0x5e91: je     42ef <kprobe_unwind_native+0x42ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17135ULL;
	}
x86_l_5e97:
	/* 0x5e97: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_5e9a:
	/* 0x5e9a: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5ea1:
	/* 0x5ea1: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ea4:
	/* 0x5ea4: jne    68bd <kprobe_unwind_native+0x68bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 26813ULL;
	}
x86_l_5eaa:
	/* 0x5eaa: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_5eaf:
	/* 0x5eaf: movzx  ecx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5eb3:
	/* 0x5eb3: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5eb5:
	/* 0x5eb5: mov    ecx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_5ebc:
	/* 0x5ebc: lea    r13d,[rax+0x10000] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 65536ULL);
x86_l_5ec3:
	/* 0x5ec3: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5ec8:
	/* 0x5ec8: cmp    ecx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_5eca:
	/* 0x5eca: cmovae r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_5ece:
	/* 0x5ece: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_5ed2:
	/* 0x5ed2: mov    DWORD PTR [rsp+0x8c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_5ed9:
	/* 0x5ed9: mov    edx,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_5ede:
	/* 0x5ede: mov    ecx,0xfa5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4005ULL);
x86_l_5ee3:
	/* 0x5ee3: cmp    eax,0x8000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32768ULL);
x86_l_5ee8:
	/* 0x5ee8: je     42ef <kprobe_unwind_native+0x42ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17135ULL;
	}
x86_l_5eee:
	/* 0x5eee: cmp    eax,0x8001 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32769ULL);
x86_l_5ef3:
	/* 0x5ef3: jne    626d <kprobe_unwind_native+0x626d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_626d;
	}
x86_l_5ef9:
	/* 0x5ef9: mov    DWORD PTR [rsp+0x94],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159815ULL);
x86_l_5f04:
	/* 0x5f04: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_5f0b:
	/* 0x5f0b: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_5f13:
	/* 0x5f13: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5f18:
	/* 0x5f18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f1a:
	/* 0x5f1a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5f1d:
	/* 0x5f1d: je     6256 <kprobe_unwind_native+0x6256> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6256;
	}
x86_l_5f23:
	/* 0x5f23: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_5f26:
	/* 0x5f26: jmp    6266 <kprobe_unwind_native+0x6266> */
	goto x86_l_6266;
x86_l_5f2b:
	/* 0x5f2b: mov    r13d,0xfa2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4002ULL);
x86_l_5f31:
	/* 0x5f31: mov    r14d,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 50ULL);
x86_l_5f37:
	/* 0x5f37: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5f3e:
	/* 0x5f3e: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f41:
	/* 0x5f41: jne    6158 <kprobe_unwind_native+0x6158> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6158;
	}
x86_l_5f47:
	/* 0x5f47: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5f4c:
	/* 0x5f4c: mov    DWORD PTR [rbx+0xf28],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3880ULL);
x86_l_5f53:
	/* 0x5f53: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f56:
	/* 0x5f56: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_5f59:
	/* 0x5f59: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5f60:
	/* 0x5f60: mov    DWORD PTR [rbx+0xf2c],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3884ULL);
x86_l_5f67:
	/* 0x5f67: mov    DWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_5f72:
	/* 0x5f72: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&per_cpu_records)));
x86_l_5f79:
	/* 0x5f79: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_5f81:
	/* 0x5f81: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5f86:
	/* 0x5f86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f88:
	/* 0x5f88: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5f8b:
	/* 0x5f8b: je     5fce <kprobe_unwind_native+0x5fce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5fce;
	}
x86_l_5f8d:
	/* 0x5f8d: movzx  ecx,BYTE PTR [rax+0x1384] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4996ULL);
x86_l_5f94:
	/* 0x5f94: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_5f97:
	/* 0x5f97: cmp    cl,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_5f9a:
	/* 0x5f9a: jb     5ff5 <kprobe_unwind_native+0x5ff5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5ff5;
	}
x86_l_5f9c:
	/* 0x5f9c: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_5f9f:
	/* 0x5f9f: mov    DWORD PTR [rax+0xf2c],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16681652977669ULL);
x86_l_5fa9:
	/* 0x5fa9: mov    DWORD PTR [rsp+0x10],0x44 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476804ULL);
x86_l_5fb1:
	/* 0x5fb1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_5fb8:
	/* 0x5fb8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5fbd:
	/* 0x5fbd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5fc2:
	/* 0x5fc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fc4:
	/* 0x5fc4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5fc7:
	/* 0x5fc7: je     5fde <kprobe_unwind_native+0x5fde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5fde;
	}
x86_l_5fc9:
	/* 0x5fc9: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_5fcc:
	/* 0x5fcc: jmp    5fe9 <kprobe_unwind_native+0x5fe9> */
	goto x86_l_5fe9;
x86_l_5fce:
	/* 0x5fce: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&perf_progs)));
x86_l_5fd5:
	/* 0x5fd5: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5fd7:
	/* 0x5fd7: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_5fdc:
	/* 0x5fdc: jmp    600b <kprobe_unwind_native+0x600b> */
	goto x86_l_600b;
x86_l_5fde:
	/* 0x5fde: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5fe3:
	/* 0x5fe3: jne    60c8 <kprobe_unwind_native+0x60c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_60c8;
	}
x86_l_5fe9:
	/* 0x5fe9: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_5fec:
	/* 0x5fec: movzx  ecx,BYTE PTR [rbx+0x1384] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4996ULL);
x86_l_5ff3:
	/* 0x5ff3: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ff5:
	/* 0x5ff5: inc    cl */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_INC, 1);
x86_l_5ff7:
	/* 0x5ff7: mov    BYTE PTR [rax+0x1384],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4996ULL);
x86_l_5ffd:
	/* 0x5ffd: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_5fff:
	/* 0x5fff: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&perf_progs)));
x86_l_6006:
	/* 0x6006: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_600b:
	/* 0x600b: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&perf_progs)));
x86_l_6012:
	/* 0x6012: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_6015:
	/* 0x6015: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6017:
	/* 0x6017: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_601c:
	/* 0x601c: jne    6039 <kprobe_unwind_native+0x6039> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6039;
	}
x86_l_601e:
	/* 0x601e: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_6023:
	/* 0x6023: add    rsp,0x168 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 360ULL);
x86_l_602a:
	/* 0x602a: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_602b:
	/* 0x602b: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_602d:
	/* 0x602d: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_602f:
	/* 0x602f: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_6031:
	/* 0x6031: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_6033:
	/* 0x6033: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_6034:
	/* 0x6034: jmp    7659 <kprobe_unwind_native+0x7659> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_6039:
	/* 0x6039: movabs rax,0xa65766974616e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926309016887662ULL);
x86_l_6043:
	/* 0x6043: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_604b:
	/* 0x604b: movabs rax,0x616e5f646e69776e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7020653754070955886ULL);
x86_l_6055:
	/* 0x6055: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_605d:
	/* 0x605d: movabs rax,0x75206e6920642520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8439867099486364960ULL);
x86_l_6067:
	/* 0x6067: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_606f:
	/* 0x606f: movabs rax,0x726f662064656c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732048022633ULL);
x86_l_6079:
	/* 0x6079: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_6081:
	/* 0x6081: movabs rax,0x6166206c6c616320 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332719350375200ULL);
x86_l_608b:
	/* 0x608b: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_6093:
	/* 0x6093: movabs rax,0x6c6961745f667062 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7811882181095485538ULL);
x86_l_609d:
	/* 0x609d: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_60a5:
	/* 0x60a5: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_60ad:
	/* 0x60ad: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_60b2:
	/* 0x60b2: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_60b7:
	/* 0x60b7: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_60bc:
	/* 0x60bc: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_60bf:
	/* 0x60bf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_60c1:
	/* 0x60c1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_60c3:
	/* 0x60c3: jmp    601e <kprobe_unwind_native+0x601e> */
	goto x86_l_601e;
x86_l_60c8:
	/* 0x60c8: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_60d2:
	/* 0x60d2: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_60da:
	/* 0x60da: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_60e4:
	/* 0x60e4: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_60ec:
	/* 0x60ec: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_60f6:
	/* 0x60f6: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_60fe:
	/* 0x60fe: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_6108:
	/* 0x6108: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_6110:
	/* 0x6110: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_611a:
	/* 0x611a: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_6122:
	/* 0x6122: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_612c:
	/* 0x612c: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_6134:
	/* 0x6134: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_613c:
	/* 0x613c: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_6141:
	/* 0x6141: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6146:
	/* 0x6146: mov    edx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_614a:
	/* 0x614a: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_614f:
	/* 0x614f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6151:
	/* 0x6151: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6153:
	/* 0x6153: jmp    5fe9 <kprobe_unwind_native+0x5fe9> */
	goto x86_l_5fe9;
x86_l_6158:
	/* 0x6158: movabs rax,0x6c25206e6f697463 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7792670388922184803ULL);
x86_l_6162:
	/* 0x6162: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6167:
	/* 0x6167: movabs rax,0x6573207478657420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310222304760656928ULL);
x86_l_6171:
	/* 0x6171: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6176:
	/* 0x6176: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_6180:
	/* 0x6180: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6185:
	/* 0x6185: movabs rax,0x72656e6e69207075 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243116113460752501ULL);
x86_l_618f:
	/* 0x618f: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6194:
	/* 0x6194: movabs rax,0x206b6f6f6c206f74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2336083356067852148ULL);
x86_l_619e:
	/* 0x619e: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_61a3:
	/* 0x61a3: movabs rax,0x206572756c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334397830517055814ULL);
x86_l_61ad:
	/* 0x61ad: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_61b2:
	/* 0x61b2: mov    DWORD PTR [rsp+0x3f],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 270583625836ULL);
x86_l_61ba:
	/* 0x61ba: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_61bf:
	/* 0x61bf: mov    eax,0x33 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_61c4:
	/* 0x61c4: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_61c9:
	/* 0x61c9: mov    rdx,QWORD PTR [rsp+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_61d1:
	/* 0x61d1: mov    esi,0x33 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 51ULL);
x86_l_61d6:
	/* 0x61d6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_61d8:
	/* 0x61d8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_61da:
	/* 0x61da: jmp    5f47 <kprobe_unwind_native+0x5f47> */
	goto x86_l_5f47;
x86_l_61df:
	/* 0x61df: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_61e6:
	/* 0x61e6: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_61e9:
	/* 0x61e9: je     2729 <kprobe_unwind_native+0x2729> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10025ULL;
	}
x86_l_61ef:
	/* 0x61ef: movabs rax,0x6174616420747075 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7022344801646571637ULL);
x86_l_61f9:
	/* 0x61f9: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_61fe:
	/* 0x61fe: movabs rax,0x72726f43202e7370 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8246776201762206576ULL);
x86_l_6208:
	/* 0x6208: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_620d:
	/* 0x620d: movabs rax,0x657473203631206e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310594677314494574ULL);
x86_l_6217:
	/* 0x6217: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_621c:
	/* 0x621c: movabs rax,0x6920686372616573 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575169349567210867ULL);
x86_l_6226:
	/* 0x6226: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_622b:
	/* 0x622b: movabs rax,0x622064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7070761801744998726ULL);
x86_l_6235:
	/* 0x6235: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_623a:
	/* 0x623a: mov    DWORD PTR [rsp+0x37],0xa3f61 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 236223872865ULL);
x86_l_6242:
	/* 0x6242: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6247:
	/* 0x6247: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_624c:
	/* 0x624c: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6251:
	/* 0x6251: jmp    2d54 <kprobe_unwind_native+0x2d54> */
	return 11604ULL;
x86_l_6256:
	/* 0x6256: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_625d:
	/* 0x625d: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6260:
	/* 0x6260: jne    6a4a <kprobe_unwind_native+0x6a4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 27210ULL;
	}
x86_l_6266:
	/* 0x6266: mov    eax,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_626d:
	/* 0x626d: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_6270:
	/* 0x6270: js     63ea <kprobe_unwind_native+0x63ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25578ULL;
	}
x86_l_6276:
	/* 0x6276: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&unwind_info_array)));
x86_l_627d:
	/* 0x627d: lea    rsi,[rsp+0x8c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_6285:
	/* 0x6285: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_628a:
	/* 0x628a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_628c:
	/* 0x628c: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6291:
	/* 0x6291: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6294:
	/* 0x6294: je     6323 <kprobe_unwind_native+0x6323> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25379ULL;
	}
x86_l_629a:
	/* 0x629a: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_629f:
	/* 0x629f: mov    ebp,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_62a2:
	/* 0x62a2: movzx  eax,BYTE PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_62a6:
	/* 0x62a6: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_62a8:
	/* 0x62a8: je     62e6 <kprobe_unwind_native+0x62e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25318ULL;
	}
x86_l_62aa:
	/* 0x62aa: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_62b1:
	/* 0x62b1: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62b4:
	/* 0x62b4: jne    69d6 <kprobe_unwind_native+0x69d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 27094ULL;
	}
x86_l_62ba:
	/* 0x62ba: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_62bc:
	/* 0x62bc: and    cl,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_62bf:
	/* 0x62bf: movzx  ecx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_62c2:
	/* 0x62c2: cmp    r13d,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RCX, X86_WIDTH_32);
x86_l_62c5:
	/* 0x62c5: jl     62e6 <kprobe_unwind_native+0x62e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 25318ULL;
	}
x86_l_62c7:
	/* 0x62c7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_62c9:
	/* 0x62c9: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_62cb:
	/* 0x62cb: setns  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NS);
x86_l_62ce:
	/* 0x62ce: shl    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_62d1:
	/* 0x62d1: add    ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
	return 25299ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 25299ULL: goto x86_l_62d3;
	case 25302ULL: goto x86_l_62d6;
	case 25309ULL: goto x86_l_62dd;
	case 25312ULL: goto x86_l_62e0;
	case 25318ULL: goto x86_l_62e6;
	case 25323ULL: goto x86_l_62eb;
	case 25326ULL: goto x86_l_62ee;
	case 25328ULL: goto x86_l_62f0;
	case 25331ULL: goto x86_l_62f3;
	case 25333ULL: goto x86_l_62f5;
	case 25336ULL: goto x86_l_62f8;
	case 25338ULL: goto x86_l_62fa;
	case 25341ULL: goto x86_l_62fd;
	case 25344ULL: goto x86_l_6300;
	case 25347ULL: goto x86_l_6303;
	case 25353ULL: goto x86_l_6309;
	case 25356ULL: goto x86_l_630c;
	case 25362ULL: goto x86_l_6312;
	case 25365ULL: goto x86_l_6315;
	case 25368ULL: goto x86_l_6318;
	case 25374ULL: goto x86_l_631e;
	case 25379ULL: goto x86_l_6323;
	case 25387ULL: goto x86_l_632b;
	case 25394ULL: goto x86_l_6332;
	case 25399ULL: goto x86_l_6337;
	case 25404ULL: goto x86_l_633c;
	case 25406ULL: goto x86_l_633e;
	case 25409ULL: goto x86_l_6341;
	case 25411ULL: goto x86_l_6343;
	case 25414ULL: goto x86_l_6346;
	case 25419ULL: goto x86_l_634b;
	case 25421ULL: goto x86_l_634d;
	case 25428ULL: goto x86_l_6354;
	case 25431ULL: goto x86_l_6357;
	case 25436ULL: goto x86_l_635c;
	case 25438ULL: goto x86_l_635e;
	case 25444ULL: goto x86_l_6364;
	case 25449ULL: goto x86_l_6369;
	case 25459ULL: goto x86_l_6373;
	case 25464ULL: goto x86_l_6378;
	case 25474ULL: goto x86_l_6382;
	case 25479ULL: goto x86_l_6387;
	case 25489ULL: goto x86_l_6391;
	case 25494ULL: goto x86_l_6396;
	case 25504ULL: goto x86_l_63a0;
	case 25509ULL: goto x86_l_63a5;
	case 25519ULL: goto x86_l_63af;
	case 25524ULL: goto x86_l_63b4;
	case 25534ULL: goto x86_l_63be;
	case 25539ULL: goto x86_l_63c3;
	case 25544ULL: goto x86_l_63c8;
	case 25549ULL: goto x86_l_63cd;
	case 25554ULL: goto x86_l_63d2;
	case 25558ULL: goto x86_l_63d6;
	case 25563ULL: goto x86_l_63db;
	case 25565ULL: goto x86_l_63dd;
	case 25567ULL: goto x86_l_63df;
	case 25573ULL: goto x86_l_63e5;
	case 25578ULL: goto x86_l_63ea;
	case 25583ULL: goto x86_l_63ef;
	case 25589ULL: goto x86_l_63f5;
	case 25592ULL: goto x86_l_63f8;
	case 25598ULL: goto x86_l_63fe;
	case 25601ULL: goto x86_l_6401;
	case 25606ULL: goto x86_l_6406;
	case 25614ULL: goto x86_l_640e;
	case 25616ULL: goto x86_l_6410;
	case 25619ULL: goto x86_l_6413;
	case 25625ULL: goto x86_l_6419;
	case 25628ULL: goto x86_l_641c;
	case 25631ULL: goto x86_l_641f;
	case 25633ULL: goto x86_l_6421;
	case 25636ULL: goto x86_l_6424;
	case 25638ULL: goto x86_l_6426;
	case 25641ULL: goto x86_l_6429;
	case 25644ULL: goto x86_l_642c;
	case 25648ULL: goto x86_l_6430;
	case 25652ULL: goto x86_l_6434;
	case 25659ULL: goto x86_l_643b;
	case 25662ULL: goto x86_l_643e;
	case 25668ULL: goto x86_l_6444;
	case 25678ULL: goto x86_l_644e;
	case 25683ULL: goto x86_l_6453;
	case 25693ULL: goto x86_l_645d;
	case 25698ULL: goto x86_l_6462;
	case 25703ULL: goto x86_l_6467;
	case 25708ULL: goto x86_l_646c;
	case 25713ULL: goto x86_l_6471;
	case 25718ULL: goto x86_l_6476;
	case 25721ULL: goto x86_l_6479;
	case 25723ULL: goto x86_l_647b;
	case 25725ULL: goto x86_l_647d;
	case 25730ULL: goto x86_l_6482;
	case 25733ULL: goto x86_l_6485;
	case 25738ULL: goto x86_l_648a;
	case 25741ULL: goto x86_l_648d;
	case 25747ULL: goto x86_l_6493;
	case 25750ULL: goto x86_l_6496;
	case 25755ULL: goto x86_l_649b;
	case 25760ULL: goto x86_l_64a0;
	case 25766ULL: goto x86_l_64a6;
	case 25769ULL: goto x86_l_64a9;
	case 25774ULL: goto x86_l_64ae;
	case 25779ULL: goto x86_l_64b3;
	case 25785ULL: goto x86_l_64b9;
	case 25788ULL: goto x86_l_64bc;
	case 25793ULL: goto x86_l_64c1;
	case 25796ULL: goto x86_l_64c4;
	case 25799ULL: goto x86_l_64c7;
	case 25805ULL: goto x86_l_64cd;
	case 25812ULL: goto x86_l_64d4;
	case 25816ULL: goto x86_l_64d8;
	case 25823ULL: goto x86_l_64df;
	case 25828ULL: goto x86_l_64e4;
	case 25835ULL: goto x86_l_64eb;
	case 25840ULL: goto x86_l_64f0;
	case 25847ULL: goto x86_l_64f7;
	case 25852ULL: goto x86_l_64fc;
	case 25855ULL: goto x86_l_64ff;
	case 25861ULL: goto x86_l_6505;
	case 25864ULL: goto x86_l_6508;
	case 25870ULL: goto x86_l_650e;
	case 25872ULL: goto x86_l_6510;
	case 25874ULL: goto x86_l_6512;
	case 25877ULL: goto x86_l_6515;
	case 25879ULL: goto x86_l_6517;
	case 25884ULL: goto x86_l_651c;
	case 25891ULL: goto x86_l_6523;
	case 25894ULL: goto x86_l_6526;
	case 25900ULL: goto x86_l_652c;
	case 25903ULL: goto x86_l_652f;
	case 25906ULL: goto x86_l_6532;
	case 25909ULL: goto x86_l_6535;
	case 25915ULL: goto x86_l_653b;
	case 25923ULL: goto x86_l_6543;
	case 25925ULL: goto x86_l_6545;
	case 25931ULL: goto x86_l_654b;
	case 25934ULL: goto x86_l_654e;
	case 25940ULL: goto x86_l_6554;
	case 25948ULL: goto x86_l_655c;
	case 25953ULL: goto x86_l_6561;
	case 25956ULL: goto x86_l_6564;
	case 25960ULL: goto x86_l_6568;
	case 25968ULL: goto x86_l_6570;
	case 25973ULL: goto x86_l_6575;
	case 25979ULL: goto x86_l_657b;
	case 25982ULL: goto x86_l_657e;
	case 25986ULL: goto x86_l_6582;
	case 25991ULL: goto x86_l_6587;
	case 25994ULL: goto x86_l_658a;
	case 25997ULL: goto x86_l_658d;
	case 26002ULL: goto x86_l_6592;
	case 26008ULL: goto x86_l_6598;
	case 26016ULL: goto x86_l_65a0;
	case 26023ULL: goto x86_l_65a7;
	case 26031ULL: goto x86_l_65af;
	case 26038ULL: goto x86_l_65b6;
	case 26046ULL: goto x86_l_65be;
	case 26053ULL: goto x86_l_65c5;
	case 26061ULL: goto x86_l_65cd;
	case 26068ULL: goto x86_l_65d4;
	case 26076ULL: goto x86_l_65dc;
	case 26083ULL: goto x86_l_65e3;
	case 26091ULL: goto x86_l_65eb;
	case 26098ULL: goto x86_l_65f2;
	case 26106ULL: goto x86_l_65fa;
	case 26113ULL: goto x86_l_6601;
	case 26121ULL: goto x86_l_6609;
	case 26128ULL: goto x86_l_6610;
	case 26135ULL: goto x86_l_6617;
	case 26142ULL: goto x86_l_661e;
	case 26145ULL: goto x86_l_6621;
	case 26151ULL: goto x86_l_6627;
	case 26161ULL: goto x86_l_6631;
	case 26166ULL: goto x86_l_6636;
	case 26176ULL: goto x86_l_6640;
	case 26181ULL: goto x86_l_6645;
	case 26186ULL: goto x86_l_664a;
	case 26191ULL: goto x86_l_664f;
	case 26196ULL: goto x86_l_6654;
	case 26201ULL: goto x86_l_6659;
	case 26203ULL: goto x86_l_665b;
	case 26205ULL: goto x86_l_665d;
	case 26210ULL: goto x86_l_6662;
	case 26215ULL: goto x86_l_6667;
	case 26218ULL: goto x86_l_666a;
	case 26221ULL: goto x86_l_666d;
	case 26224ULL: goto x86_l_6670;
	case 26227ULL: goto x86_l_6673;
	case 26229ULL: goto x86_l_6675;
	case 26235ULL: goto x86_l_667b;
	case 26240ULL: goto x86_l_6680;
	case 26245ULL: goto x86_l_6685;
	case 26250ULL: goto x86_l_668a;
	case 26255ULL: goto x86_l_668f;
	case 26258ULL: goto x86_l_6692;
	case 26260ULL: goto x86_l_6694;
	case 26263ULL: goto x86_l_6697;
	case 26265ULL: goto x86_l_6699;
	case 26272ULL: goto x86_l_66a0;
	case 26275ULL: goto x86_l_66a3;
	case 26281ULL: goto x86_l_66a9;
	case 26284ULL: goto x86_l_66ac;
	case 26289ULL: goto x86_l_66b1;
	case 26292ULL: goto x86_l_66b4;
	case 26295ULL: goto x86_l_66b7;
	case 26300ULL: goto x86_l_66bc;
	case 26303ULL: goto x86_l_66bf;
	case 26308ULL: goto x86_l_66c4;
	case 26314ULL: goto x86_l_66ca;
	case 26324ULL: goto x86_l_66d4;
	case 26332ULL: goto x86_l_66dc;
	case 26342ULL: goto x86_l_66e6;
	case 26350ULL: goto x86_l_66ee;
	case 26360ULL: goto x86_l_66f8;
	case 26368ULL: goto x86_l_6700;
	case 26379ULL: goto x86_l_670b;
	case 26387ULL: goto x86_l_6713;
	case 26392ULL: goto x86_l_6718;
	case 26397ULL: goto x86_l_671d;
	case 26402ULL: goto x86_l_6722;
	case 26404ULL: goto x86_l_6724;
	case 26406ULL: goto x86_l_6726;
	case 26411ULL: goto x86_l_672b;
	case 26421ULL: goto x86_l_6735;
	case 26426ULL: goto x86_l_673a;
	case 26436ULL: goto x86_l_6744;
	case 26441ULL: goto x86_l_6749;
	case 26451ULL: goto x86_l_6753;
	case 26456ULL: goto x86_l_6758;
	case 26466ULL: goto x86_l_6762;
	case 26471ULL: goto x86_l_6767;
	case 26476ULL: goto x86_l_676c;
	case 26481ULL: goto x86_l_6771;
	case 26486ULL: goto x86_l_6776;
	case 26492ULL: goto x86_l_677c;
	case 26499ULL: goto x86_l_6783;
	case 26506ULL: goto x86_l_678a;
	case 26511ULL: goto x86_l_678f;
	case 26513ULL: goto x86_l_6791;
	case 26516ULL: goto x86_l_6794;
	case 26521ULL: goto x86_l_6799;
	case 26531ULL: goto x86_l_67a3;
	case 26539ULL: goto x86_l_67ab;
	case 26549ULL: goto x86_l_67b5;
	case 26557ULL: goto x86_l_67bd;
	case 26567ULL: goto x86_l_67c7;
	case 26575ULL: goto x86_l_67cf;
	case 26585ULL: goto x86_l_67d9;
	case 26593ULL: goto x86_l_67e1;
	case 26603ULL: goto x86_l_67eb;
	case 26611ULL: goto x86_l_67f3;
	case 26621ULL: goto x86_l_67fd;
	case 26629ULL: goto x86_l_6805;
	case 26637ULL: goto x86_l_680d;
	case 26642ULL: goto x86_l_6812;
	case 26647ULL: goto x86_l_6817;
	case 26651ULL: goto x86_l_681b;
	case 26656ULL: goto x86_l_6820;
	case 26658ULL: goto x86_l_6822;
	case 26660ULL: goto x86_l_6824;
	case 26667ULL: goto x86_l_682b;
	case 26670ULL: goto x86_l_682e;
	case 26676ULL: goto x86_l_6834;
	case 26681ULL: goto x86_l_6839;
	case 26691ULL: goto x86_l_6843;
	case 26696ULL: goto x86_l_6848;
	case 26706ULL: goto x86_l_6852;
	case 26711ULL: goto x86_l_6857;
	case 26721ULL: goto x86_l_6861;
	case 26726ULL: goto x86_l_6866;
	case 26736ULL: goto x86_l_6870;
	case 26741ULL: goto x86_l_6875;
	case 26751ULL: goto x86_l_687f;
	case 26756ULL: goto x86_l_6884;
	case 26766ULL: goto x86_l_688e;
	case 26771ULL: goto x86_l_6893;
	case 26776ULL: goto x86_l_6898;
	case 26781ULL: goto x86_l_689d;
	case 26787ULL: goto x86_l_68a3;
	case 26790ULL: goto x86_l_68a6;
	case 26795ULL: goto x86_l_68ab;
	case 26800ULL: goto x86_l_68b0;
	case 26803ULL: goto x86_l_68b3;
	case 26805ULL: goto x86_l_68b5;
	case 26808ULL: goto x86_l_68b8;
	case 26813ULL: goto x86_l_68bd;
	case 26823ULL: goto x86_l_68c7;
	case 26828ULL: goto x86_l_68cc;
	case 26838ULL: goto x86_l_68d6;
	case 26843ULL: goto x86_l_68db;
	case 26853ULL: goto x86_l_68e5;
	case 26858ULL: goto x86_l_68ea;
	case 26868ULL: goto x86_l_68f4;
	case 26873ULL: goto x86_l_68f9;
	case 26883ULL: goto x86_l_6903;
	case 26888ULL: goto x86_l_6908;
	case 26898ULL: goto x86_l_6912;
	case 26903ULL: goto x86_l_6917;
	case 26908ULL: goto x86_l_691c;
	case 26913ULL: goto x86_l_6921;
	case 26919ULL: goto x86_l_6927;
	case 26926ULL: goto x86_l_692e;
	case 26930ULL: goto x86_l_6932;
	case 26935ULL: goto x86_l_6937;
	case 26940ULL: goto x86_l_693c;
	case 26942ULL: goto x86_l_693e;
	case 26945ULL: goto x86_l_6941;
	case 26950ULL: goto x86_l_6946;
	case 26960ULL: goto x86_l_6950;
	case 26968ULL: goto x86_l_6958;
	case 26978ULL: goto x86_l_6962;
	case 26986ULL: goto x86_l_696a;
	case 26996ULL: goto x86_l_6974;
	case 27004ULL: goto x86_l_697c;
	case 27014ULL: goto x86_l_6986;
	case 27022ULL: goto x86_l_698e;
	case 27032ULL: goto x86_l_6998;
	case 27040ULL: goto x86_l_69a0;
	case 27050ULL: goto x86_l_69aa;
	case 27058ULL: goto x86_l_69b2;
	case 27066ULL: goto x86_l_69ba;
	case 27071ULL: goto x86_l_69bf;
	case 27076ULL: goto x86_l_69c4;
	case 27080ULL: goto x86_l_69c8;
	case 27085ULL: goto x86_l_69cd;
	case 27087ULL: goto x86_l_69cf;
	case 27089ULL: goto x86_l_69d1;
	case 27094ULL: goto x86_l_69d6;
	case 27104ULL: goto x86_l_69e0;
	case 27109ULL: goto x86_l_69e5;
	case 27119ULL: goto x86_l_69ef;
	case 27124ULL: goto x86_l_69f4;
	case 27134ULL: goto x86_l_69fe;
	case 27139ULL: goto x86_l_6a03;
	case 27149ULL: goto x86_l_6a0d;
	case 27154ULL: goto x86_l_6a12;
	case 27159ULL: goto x86_l_6a17;
	case 27164ULL: goto x86_l_6a1c;
	case 27169ULL: goto x86_l_6a21;
	case 27175ULL: goto x86_l_6a27;
	case 27180ULL: goto x86_l_6a2c;
	case 27186ULL: goto x86_l_6a32;
	case 27191ULL: goto x86_l_6a37;
	case 27194ULL: goto x86_l_6a3a;
	case 27196ULL: goto x86_l_6a3c;
	case 27199ULL: goto x86_l_6a3f;
	case 27205ULL: goto x86_l_6a45;
	case 27210ULL: goto x86_l_6a4a;
	case 27220ULL: goto x86_l_6a54;
	case 27225ULL: goto x86_l_6a59;
	case 27235ULL: goto x86_l_6a63;
	case 27240ULL: goto x86_l_6a68;
	case 27250ULL: goto x86_l_6a72;
	case 27255ULL: goto x86_l_6a77;
	case 27265ULL: goto x86_l_6a81;
	case 27270ULL: goto x86_l_6a86;
	case 27280ULL: goto x86_l_6a90;
	case 27285ULL: goto x86_l_6a95;
	case 27295ULL: goto x86_l_6a9f;
	case 27300ULL: goto x86_l_6aa4;
	case 27305ULL: goto x86_l_6aa9;
	case 27310ULL: goto x86_l_6aae;
	case 27315ULL: goto x86_l_6ab3;
	case 27322ULL: goto x86_l_6aba;
	case 27327ULL: goto x86_l_6abf;
	case 27329ULL: goto x86_l_6ac1;
	case 27331ULL: goto x86_l_6ac3;
	case 27336ULL: goto x86_l_6ac8;
	case 27346ULL: goto x86_l_6ad2;
	case 27351ULL: goto x86_l_6ad7;
	case 27361ULL: goto x86_l_6ae1;
	case 27366ULL: goto x86_l_6ae6;
	case 27376ULL: goto x86_l_6af0;
	case 27381ULL: goto x86_l_6af5;
	case 27391ULL: goto x86_l_6aff;
	case 27396ULL: goto x86_l_6b04;
	case 27401ULL: goto x86_l_6b09;
	case 27406ULL: goto x86_l_6b0e;
	case 27411ULL: goto x86_l_6b13;
	case 27416ULL: goto x86_l_6b18;
	case 27423ULL: goto x86_l_6b1f;
	case 27428ULL: goto x86_l_6b24;
	case 27430ULL: goto x86_l_6b26;
	default: return 0xffffffffffffffffULL;
	}
x86_l_62d3:
	/* 0x62d3: add    ebp,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4294967288ULL);
x86_l_62d6:
	/* 0x62d6: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_62dd:
	/* 0x62dd: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62e0:
	/* 0x62e0: jne    6ac8 <kprobe_unwind_native+0x6ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6ac8;
	}
x86_l_62e6:
	/* 0x62e6: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_62eb:
	/* 0x62eb: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_62ee:
	/* 0x62ee: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_62f0:
	/* 0x62f0: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_62f3:
	/* 0x62f3: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_62f5:
	/* 0x62f5: cmovns ecx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBP, X86_WIDTH_32, X86_CC_NS);
x86_l_62f8:
	/* 0x62f8: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_62fa:
	/* 0x62fa: and    edx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_62fd:
	/* 0x62fd: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6300:
	/* 0x6300: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_6303:
	/* 0x6303: jg     64fc <kprobe_unwind_native+0x64fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_64fc;
	}
x86_l_6309:
	/* 0x6309: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_630c:
	/* 0x630c: je     666a <kprobe_unwind_native+0x666a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_666a;
	}
x86_l_6312:
	/* 0x6312: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_6315:
	/* 0x6315: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_6318:
	/* 0x6318: je     6667 <kprobe_unwind_native+0x6667> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6667;
	}
x86_l_631e:
	/* 0x631e: jmp    6ba2 <kprobe_unwind_native+0x6ba2> */
	return 27554ULL;
x86_l_6323:
	/* 0x6323: mov    DWORD PTR [rsp+0x78],0x55 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075605ULL);
x86_l_632b:
	/* 0x632b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_6332:
	/* 0x6332: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6337:
	/* 0x6337: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_633c:
	/* 0x633c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_633e:
	/* 0x633e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6341:
	/* 0x6341: je     634d <kprobe_unwind_native+0x634d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_634d;
	}
x86_l_6343:
	/* 0x6343: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6346:
	/* 0x6346: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_634b:
	/* 0x634b: jmp    635e <kprobe_unwind_native+0x635e> */
	goto x86_l_635e;
x86_l_634d:
	/* 0x634d: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6354:
	/* 0x6354: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6357:
	/* 0x6357: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_635c:
	/* 0x635c: jne    6369 <kprobe_unwind_native+0x6369> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6369;
	}
x86_l_635e:
	/* 0x635e: mov    r13d,0xfaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4015ULL);
x86_l_6364:
	/* 0x6364: jmp    5f53 <kprobe_unwind_native+0x5f53> */
	return 24403ULL;
x86_l_6369:
	/* 0x6369: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_6373:
	/* 0x6373: mov    QWORD PTR [rsp+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_6378:
	/* 0x6378: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_6382:
	/* 0x6382: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6387:
	/* 0x6387: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_6391:
	/* 0x6391: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6396:
	/* 0x6396: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_63a0:
	/* 0x63a0: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_63a5:
	/* 0x63a5: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_63af:
	/* 0x63af: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_63b4:
	/* 0x63b4: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_63be:
	/* 0x63be: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_63c3:
	/* 0x63c3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_63c8:
	/* 0x63c8: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_63cd:
	/* 0x63cd: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_63d2:
	/* 0x63d2: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_63d6:
	/* 0x63d6: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_63db:
	/* 0x63db: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_63dd:
	/* 0x63dd: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_63df:
	/* 0x63df: mov    r13d,0xfaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4015ULL);
x86_l_63e5:
	/* 0x63e5: jmp    5f53 <kprobe_unwind_native+0x5f53> */
	return 24403ULL;
x86_l_63ea:
	/* 0x63ea: and    eax,0xffff7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294934527ULL);
x86_l_63ef:
	/* 0x63ef: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_63f5:
	/* 0x63f5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_63f8:
	/* 0x63f8: jg     648a <kprobe_unwind_native+0x648a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_648a;
	}
x86_l_63fe:
	/* 0x63fe: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6401:
	/* 0x6401: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6406:
	/* 0x6406: mov    rcx,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_640e:
	/* 0x640e: je     6482 <kprobe_unwind_native+0x6482> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6482;
	}
x86_l_6410:
	/* 0x6410: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6413:
	/* 0x6413: jne    5f53 <kprobe_unwind_native+0x5f53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24403ULL;
	}
x86_l_6419:
	/* 0x6419: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_641c:
	/* 0x641c: mov    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_641f:
	/* 0x641f: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6421:
	/* 0x6421: and    ecx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_6424:
	/* 0x6424: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6426:
	/* 0x6426: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_6429:
	/* 0x6429: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_642c:
	/* 0x642c: lea    r13,[rax+rdx*8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_6430:
	/* 0x6430: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6434:
	/* 0x6434: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_643b:
	/* 0x643b: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_643e:
	/* 0x643e: je     6e48 <kprobe_unwind_native+0x6e48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28232ULL;
	}
x86_l_6444:
	/* 0x6444: movabs rax,0xa786c2578303d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541309ULL);
x86_l_644e:
	/* 0x644e: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6453:
	/* 0x6453: movabs rax,0x616663202c544c50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018406059137322064ULL);
x86_l_645d:
	/* 0x645d: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6462:
	/* 0x6462: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6467:
	/* 0x6467: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_646c:
	/* 0x646c: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6471:
	/* 0x6471: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6476:
	/* 0x6476: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_6479:
	/* 0x6479: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_647b:
	/* 0x647b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_647d:
	/* 0x647d: jmp    6e48 <kprobe_unwind_native+0x6e48> */
	return 28232ULL;
x86_l_6482:
	/* 0x6482: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6485:
	/* 0x6485: jmp    5f53 <kprobe_unwind_native+0x5f53> */
	return 24403ULL;
x86_l_648a:
	/* 0x648a: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_648d:
	/* 0x648d: je     6561 <kprobe_unwind_native+0x6561> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6561;
	}
x86_l_6493:
	/* 0x6493: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6496:
	/* 0x6496: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_649b:
	/* 0x649b: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_64a0:
	/* 0x64a0: jne    5f53 <kprobe_unwind_native+0x5f53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24403ULL;
	}
x86_l_64a6:
	/* 0x64a6: mov    rax,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_64a9:
	/* 0x64a9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64ae:
	/* 0x64ae: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_64b3:
	/* 0x64b3: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_64b9:
	/* 0x64b9: mov    rdx,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_64bc:
	/* 0x64bc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_64c1:
	/* 0x64c1: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_64c4:
	/* 0x64c4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_64c7:
	/* 0x64c7: jne    1647 <kprobe_unwind_native+0x1647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5703ULL;
	}
x86_l_64cd:
	/* 0x64cd: mov    rax,QWORD PTR [rbx+0xee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_64d4:
	/* 0x64d4: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_64d8:
	/* 0x64d8: mov    QWORD PTR [rbx+0xed8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_64df:
	/* 0x64df: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64e4:
	/* 0x64e4: mov    QWORD PTR [rbx+0xee0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_64eb:
	/* 0x64eb: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_64f0:
	/* 0x64f0: mov    QWORD PTR [rbx+0xed0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_64f7:
	/* 0x64f7: jmp    6e83 <kprobe_unwind_native+0x6e83> */
	return 28291ULL;
x86_l_64fc:
	/* 0x64fc: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_64ff:
	/* 0x64ff: je     6662 <kprobe_unwind_native+0x6662> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6662;
	}
x86_l_6505:
	/* 0x6505: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_6508:
	/* 0x6508: jne    6ba2 <kprobe_unwind_native+0x6ba2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 27554ULL;
	}
x86_l_650e:
	/* 0x650e: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_6510:
	/* 0x6510: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_6512:
	/* 0x6512: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_6515:
	/* 0x6515: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_6517:
	/* 0x6517: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_651c:
	/* 0x651c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6523:
	/* 0x6523: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6526:
	/* 0x6526: jne    6b2d <kprobe_unwind_native+0x6b2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 27437ULL;
	}
x86_l_652c:
	/* 0x652c: and    ebp,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_652f:
	/* 0x652f: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6532:
	/* 0x6532: cmp    ebp,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_6535:
	/* 0x6535: jg     6b80 <kprobe_unwind_native+0x6b80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 27520ULL;
	}
x86_l_653b:
	/* 0x653b: mov    rax,QWORD PTR [rsp+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_6543:
	/* 0x6543: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_6545:
	/* 0x6545: je     6b9a <kprobe_unwind_native+0x6b9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 27546ULL;
	}
x86_l_654b:
	/* 0x654b: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_654e:
	/* 0x654e: jne    6ba2 <kprobe_unwind_native+0x6ba2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 27554ULL;
	}
x86_l_6554:
	/* 0x6554: mov    rax,QWORD PTR [rsp+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_655c:
	/* 0x655c: jmp    6b9a <kprobe_unwind_native+0x6b9a> */
	return 27546ULL;
x86_l_6561:
	/* 0x6561: mov    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6564:
	/* 0x6564: add    rax,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_6568:
	/* 0x6568: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_6570:
	/* 0x6570: mov    ecx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 144ULL);
x86_l_6575:
	/* 0x6575: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_657b:
	/* 0x657b: mov    rdx,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_657e:
	/* 0x657e: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_6582:
	/* 0x6582: mov    esi,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 144ULL);
x86_l_6587:
	/* 0x6587: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_658a:
	/* 0x658a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_658d:
	/* 0x658d: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6592:
	/* 0x6592: jne    1647 <kprobe_unwind_native+0x1647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5703ULL;
	}
x86_l_6598:
	/* 0x6598: mov    rax,QWORD PTR [rsp+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_65a0:
	/* 0x65a0: mov    QWORD PTR [rbx+0xee8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3816ULL);
x86_l_65a7:
	/* 0x65a7: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_65af:
	/* 0x65af: mov    QWORD PTR [rbx+0xef0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3824ULL);
x86_l_65b6:
	/* 0x65b6: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_65be:
	/* 0x65be: mov    QWORD PTR [rbx+0xef8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3832ULL);
x86_l_65c5:
	/* 0x65c5: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_65cd:
	/* 0x65cd: mov    QWORD PTR [rbx+0xf00],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3840ULL);
x86_l_65d4:
	/* 0x65d4: mov    rax,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_65dc:
	/* 0x65dc: mov    QWORD PTR [rbx+0xf08],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3848ULL);
x86_l_65e3:
	/* 0x65e3: mov    rax,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_65eb:
	/* 0x65eb: mov    QWORD PTR [rbx+0xee0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_65f2:
	/* 0x65f2: mov    rax,QWORD PTR [rsp+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_65fa:
	/* 0x65fa: mov    QWORD PTR [rbx+0xed8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_6601:
	/* 0x6601: mov    rax,QWORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_6609:
	/* 0x6609: mov    QWORD PTR [rbx+0xed0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_6610:
	/* 0x6610: mov    BYTE PTR [rbx+0xf30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16698832846848ULL);
x86_l_6617:
	/* 0x6617: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_661e:
	/* 0x661e: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6621:
	/* 0x6621: je     6e8a <kprobe_unwind_native+0x6e8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28298ULL;
	}
x86_l_6627:
	/* 0x6627: movabs rax,0xa656d61726620 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926270227834400ULL);
x86_l_6631:
	/* 0x6631: mov    QWORD PTR [rsp+0x16],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_6636:
	/* 0x6636: movabs rax,0x66206c616e676973 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7359000956843288947ULL);
x86_l_6640:
	/* 0x6640: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6645:
	/* 0x6645: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_664a:
	/* 0x664a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_664f:
	/* 0x664f: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6654:
	/* 0x6654: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_6659:
	/* 0x6659: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_665b:
	/* 0x665b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_665d:
	/* 0x665d: jmp    6e8a <kprobe_unwind_native+0x6e8a> */
	return 28298ULL;
x86_l_6662:
	/* 0x6662: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6667:
	/* 0x6667: mov    r13,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_666a:
	/* 0x666a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_666d:
	/* 0x666d: movsxd r13,ecx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_6670:
	/* 0x6670: add    r13,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6673:
	/* 0x6673: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_6675:
	/* 0x6675: jns    6ba2 <kprobe_unwind_native+0x6ba2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 27554ULL;
	}
x86_l_667b:
	/* 0x667b: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6680:
	/* 0x6680: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6685:
	/* 0x6685: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_668a:
	/* 0x668a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_668f:
	/* 0x668f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_6692:
	/* 0x6692: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6694:
	/* 0x6694: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6697:
	/* 0x6697: je     66b1 <kprobe_unwind_native+0x66b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_66b1;
	}
x86_l_6699:
	/* 0x6699: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_66a0:
	/* 0x66a0: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66a3:
	/* 0x66a3: jne    6d0d <kprobe_unwind_native+0x6d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 27917ULL;
	}
x86_l_66a9:
	/* 0x66a9: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_66ac:
	/* 0x66ac: jmp    6ba2 <kprobe_unwind_native+0x6ba2> */
	return 27554ULL;
x86_l_66b1:
	/* 0x66b1: shl    ebp,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_66b4:
	/* 0x66b4: and    ebp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 56ULL);
x86_l_66b7:
	/* 0x66b7: add    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_66bc:
	/* 0x66bc: mov    r13,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_66bf:
	/* 0x66bf: jmp    6ba2 <kprobe_unwind_native+0x6ba2> */
	return 27554ULL;
x86_l_66c4:
	/* 0x66c4: mov    edx,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_66ca:
	/* 0x66ca: movabs rax,0x3d3d206425206576 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4412718824384652662ULL);
x86_l_66d4:
	/* 0x66d4: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_66dc:
	/* 0x66dc: movabs rax,0x6974616e5f646e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598805597955583593ULL);
x86_l_66e6:
	/* 0x66e6: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_66ee:
	/* 0x66ee: movabs rax,0x776e75203d3d3d3d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8605944719278423357ULL);
x86_l_66f8:
	/* 0x66f8: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_6700:
	/* 0x6700: mov    DWORD PTR [rsp+0xb8],0xa3d3d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 790274653501ULL);
x86_l_670b:
	/* 0x670b: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_6713:
	/* 0x6713: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_6718:
	/* 0x6718: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_671d:
	/* 0x671d: mov    esi,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 28ULL);
x86_l_6722:
	/* 0x6722: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6724:
	/* 0x6724: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6726:
	/* 0x6726: jmp    54a0 <kprobe_unwind_native+0x54a0> */
	return 21664ULL;
x86_l_672b:
	/* 0x672b: movabs rax,0xa786c253a786c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 754471844735118373ULL);
x86_l_6735:
	/* 0x6735: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_673a:
	/* 0x673a: movabs rax,0x20726f662061746c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338053640979313772ULL);
x86_l_6744:
	/* 0x6744: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6749:
	/* 0x6749: movabs rax,0x6564206b63617473 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7306000141102707827ULL);
x86_l_6753:
	/* 0x6753: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6758:
	/* 0x6758: movabs rax,0x207075206b6f6f4c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337496988707155788ULL);
x86_l_6762:
	/* 0x6762: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6767:
	/* 0x6767: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_676c:
	/* 0x676c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6771:
	/* 0x6771: mov    eax,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_6776:
	/* 0x6776: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_677c:
	/* 0x677c: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_6783:
	/* 0x6783: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_678a:
	/* 0x678a: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_678f:
	/* 0x678f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6791:
	/* 0x6791: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6794:
	/* 0x6794: jmp    5632 <kprobe_unwind_native+0x5632> */
	return 22066ULL;
x86_l_6799:
	/* 0x6799: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_67a3:
	/* 0x67a3: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_67ab:
	/* 0x67ab: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_67b5:
	/* 0x67b5: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_67bd:
	/* 0x67bd: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_67c7:
	/* 0x67c7: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_67cf:
	/* 0x67cf: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_67d9:
	/* 0x67d9: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_67e1:
	/* 0x67e1: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_67eb:
	/* 0x67eb: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_67f3:
	/* 0x67f3: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_67fd:
	/* 0x67fd: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_6805:
	/* 0x6805: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_680d:
	/* 0x680d: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_6812:
	/* 0x6812: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6817:
	/* 0x6817: mov    edx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_681b:
	/* 0x681b: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_6820:
	/* 0x6820: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6822:
	/* 0x6822: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6824:
	/* 0x6824: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_682b:
	/* 0x682b: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_682e:
	/* 0x682e: je     5580 <kprobe_unwind_native+0x5580> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21888ULL;
	}
x86_l_6834:
	/* 0x6834: jmp    54d7 <kprobe_unwind_native+0x54d7> */
	return 21719ULL;
x86_l_6839:
	/* 0x6839: movabs rax,0xa296425204449 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2860259863446601ULL);
x86_l_6843:
	/* 0x6843: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6848:
	/* 0x6848: movabs rax,0x70616d2820756c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8097873624099548197ULL);
x86_l_6852:
	/* 0x6852: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6857:
	/* 0x6857: movabs rax,0x206f7420756c2520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414386373920ULL);
x86_l_6861:
	/* 0x6861: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6866:
	/* 0x6866: movabs rax,0x6d6f726620656220 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7885647255504773664ULL);
x86_l_6870:
	/* 0x6870: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6875:
	/* 0x6875: movabs rax,0x646c756f68732073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7236287822631739507ULL);
x86_l_687f:
	/* 0x687f: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6884:
	/* 0x6884: movabs rax,0x6c61767265746e49 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7809653462537629257ULL);
x86_l_688e:
	/* 0x688e: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6893:
	/* 0x6893: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6898:
	/* 0x6898: mov    eax,0x30 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 48ULL);
x86_l_689d:
	/* 0x689d: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_68a3:
	/* 0x68a3: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_68a6:
	/* 0x68a6: movzx  r8d,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_68ab:
	/* 0x68ab: mov    esi,0x30 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 48ULL);
x86_l_68b0:
	/* 0x68b0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_68b3:
	/* 0x68b3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68b5:
	/* 0x68b5: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_68b8:
	/* 0x68b8: jmp    598a <kprobe_unwind_native+0x598a> */
	return 22922ULL;
x86_l_68bd:
	/* 0x68bd: movabs rax,0xa6425206f666e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860387845742ULL);
x86_l_68c7:
	/* 0x68c7: mov    QWORD PTR [rsp+0x35],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_68cc:
	/* 0x68cc: movabs rax,0x6f666e49646e6977 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8027224647331113335ULL);
x86_l_68d6:
	/* 0x68d6: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_68db:
	/* 0x68db: movabs rax,0x6e75202c78257830 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7959303291813591088ULL);
x86_l_68e5:
	/* 0x68e5: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_68ea:
	/* 0x68ea: movabs rax,0x20776f4c72646461 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2339460905569641569ULL);
x86_l_68f4:
	/* 0x68f4: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_68f9:
	/* 0x68f9: movabs rax,0x202c642520786564 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2318338018810291556ULL);
x86_l_6903:
	/* 0x6903: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6908:
	/* 0x6908: movabs rax,0x6e692061746c6564 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7955925819663869284ULL);
x86_l_6912:
	/* 0x6912: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6917:
	/* 0x6917: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_691c:
	/* 0x691c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_6921:
	/* 0x6921: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_6927:
	/* 0x6927: mov    edx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_692e:
	/* 0x692e: movzx  ecx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_6932:
	/* 0x6932: movzx  r8d,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_6937:
	/* 0x6937: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_693c:
	/* 0x693c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_693e:
	/* 0x693e: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_6941:
	/* 0x6941: jmp    5eaa <kprobe_unwind_native+0x5eaa> */
	return 24234ULL;
x86_l_6946:
	/* 0x6946: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_6950:
	/* 0x6950: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_6958:
	/* 0x6958: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_6962:
	/* 0x6962: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_696a:
	/* 0x696a: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_6974:
	/* 0x6974: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_697c:
	/* 0x697c: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_6986:
	/* 0x6986: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_698e:
	/* 0x698e: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_6998:
	/* 0x6998: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_69a0:
	/* 0x69a0: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_69aa:
	/* 0x69aa: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_69b2:
	/* 0x69b2: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_69ba:
	/* 0x69ba: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_69bf:
	/* 0x69bf: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_69c4:
	/* 0x69c4: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_69c8:
	/* 0x69c8: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_69cd:
	/* 0x69cd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69cf:
	/* 0x69cf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_69d1:
	/* 0x69d1: jmp    5481 <kprobe_unwind_native+0x5481> */
	return 21633ULL;
x86_l_69d6:
	/* 0x69d6: movabs rax,0xa78323023252061 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 754408119914012769ULL);
x86_l_69e0:
	/* 0x69e0: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69e5:
	/* 0x69e5: movabs rax,0x746c656420646567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8389191686598976871ULL);
x86_l_69ef:
	/* 0x69ef: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_69f4:
	/* 0x69f4: movabs rax,0x72656d202c642520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243114677922702624ULL);
x86_l_69fe:
	/* 0x69fe: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6a03:
	/* 0x6a03: movabs rax,0x6666694472646441 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7378700782191010881ULL);
x86_l_6a0d:
	/* 0x6a0d: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6a12:
	/* 0x6a12: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_6a17:
	/* 0x6a17: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6a1c:
	/* 0x6a1c: mov    eax,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_6a21:
	/* 0x6a21: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_6a27:
	/* 0x6a27: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6a2c:
	/* 0x6a2c: movzx  ecx,BYTE PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_6a32:
	/* 0x6a32: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_6a37:
	/* 0x6a37: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_6a3a:
	/* 0x6a3a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a3c:
	/* 0x6a3c: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6a3f:
	/* 0x6a3f: movzx  eax,BYTE PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_6a45:
	/* 0x6a45: jmp    62ba <kprobe_unwind_native+0x62ba> */
	return 25274ULL;
x86_l_6a4a:
	/* 0x6a4a: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_6a54:
	/* 0x6a54: mov    QWORD PTR [rsp+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_6a59:
	/* 0x6a59: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_6a63:
	/* 0x6a63: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6a68:
	/* 0x6a68: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_6a72:
	/* 0x6a72: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a77:
	/* 0x6a77: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_6a81:
	/* 0x6a81: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6a86:
	/* 0x6a86: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_6a90:
	/* 0x6a90: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6a95:
	/* 0x6a95: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_6a9f:
	/* 0x6a9f: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6aa4:
	/* 0x6aa4: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6aa9:
	/* 0x6aa9: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_6aae:
	/* 0x6aae: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6ab3:
	/* 0x6ab3: mov    edx,DWORD PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_6aba:
	/* 0x6aba: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_6abf:
	/* 0x6abf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ac1:
	/* 0x6ac1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6ac3:
	/* 0x6ac3: jmp    6266 <kprobe_unwind_native+0x6266> */
	return 25190ULL;
x86_l_6ac8:
	/* 0x6ac8: movabs rax,0xa64253d61746c65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 748764383608597605ULL);
x86_l_6ad2:
	/* 0x6ad2: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6ad7:
	/* 0x6ad7: movabs rax,0x44616663203a6863 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4927332043248527459ULL);
x86_l_6ae1:
	/* 0x6ae1: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6ae6:
	/* 0x6ae6: movabs rax,0x74616d2061746c65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8386103966981975141ULL);
x86_l_6af0:
	/* 0x6af0: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6af5:
	/* 0x6af5: movabs rax,0x642064656772654d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7214876989737559373ULL);
x86_l_6aff:
	/* 0x6aff: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b04:
	/* 0x6b04: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_6b09:
	/* 0x6b09: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b0e:
	/* 0x6b0e: mov    eax,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_6b13:
	/* 0x6b13: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6b18:
	/* 0x6b18: mov    edx,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_6b1f:
	/* 0x6b1f: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_6b24:
	/* 0x6b24: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b26:
	/* 0x6b26: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
	return 27432ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_14(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 27432ULL: goto x86_l_6b28;
	case 27437ULL: goto x86_l_6b2d;
	case 27447ULL: goto x86_l_6b37;
	case 27452ULL: goto x86_l_6b3c;
	case 27462ULL: goto x86_l_6b46;
	case 27467ULL: goto x86_l_6b4b;
	case 27472ULL: goto x86_l_6b50;
	case 27477ULL: goto x86_l_6b55;
	case 27482ULL: goto x86_l_6b5a;
	case 27488ULL: goto x86_l_6b60;
	case 27491ULL: goto x86_l_6b63;
	case 27496ULL: goto x86_l_6b68;
	case 27501ULL: goto x86_l_6b6d;
	case 27503ULL: goto x86_l_6b6f;
	case 27505ULL: goto x86_l_6b71;
	case 27508ULL: goto x86_l_6b74;
	case 27511ULL: goto x86_l_6b77;
	case 27514ULL: goto x86_l_6b7a;
	case 27520ULL: goto x86_l_6b80;
	case 27528ULL: goto x86_l_6b88;
	case 27531ULL: goto x86_l_6b8b;
	case 27533ULL: goto x86_l_6b8d;
	case 27541ULL: goto x86_l_6b95;
	case 27544ULL: goto x86_l_6b98;
	case 27546ULL: goto x86_l_6b9a;
	case 27551ULL: goto x86_l_6b9f;
	case 27554ULL: goto x86_l_6ba2;
	case 27559ULL: goto x86_l_6ba7;
	case 27563ULL: goto x86_l_6bab;
	case 27567ULL: goto x86_l_6baf;
	case 27570ULL: goto x86_l_6bb2;
	case 27573ULL: goto x86_l_6bb5;
	case 27575ULL: goto x86_l_6bb7;
	case 27579ULL: goto x86_l_6bbb;
	case 27581ULL: goto x86_l_6bbd;
	case 27584ULL: goto x86_l_6bc0;
	case 27587ULL: goto x86_l_6bc3;
	case 27589ULL: goto x86_l_6bc5;
	case 27592ULL: goto x86_l_6bc8;
	case 27595ULL: goto x86_l_6bcb;
	case 27597ULL: goto x86_l_6bcd;
	case 27600ULL: goto x86_l_6bd0;
	case 27603ULL: goto x86_l_6bd3;
	case 27605ULL: goto x86_l_6bd5;
	case 27610ULL: goto x86_l_6bda;
	case 27613ULL: goto x86_l_6bdd;
	case 27615ULL: goto x86_l_6bdf;
	case 27618ULL: goto x86_l_6be2;
	case 27624ULL: goto x86_l_6be8;
	case 27627ULL: goto x86_l_6beb;
	case 27629ULL: goto x86_l_6bed;
	case 27632ULL: goto x86_l_6bf0;
	case 27634ULL: goto x86_l_6bf2;
	case 27639ULL: goto x86_l_6bf7;
	case 27646ULL: goto x86_l_6bfe;
	case 27649ULL: goto x86_l_6c01;
	case 27655ULL: goto x86_l_6c07;
	case 27659ULL: goto x86_l_6c0b;
	case 27663ULL: goto x86_l_6c0f;
	case 27669ULL: goto x86_l_6c15;
	case 27672ULL: goto x86_l_6c18;
	case 27678ULL: goto x86_l_6c1e;
	case 27682ULL: goto x86_l_6c22;
	case 27688ULL: goto x86_l_6c28;
	case 27696ULL: goto x86_l_6c30;
	case 27704ULL: goto x86_l_6c38;
	case 27709ULL: goto x86_l_6c3d;
	case 27714ULL: goto x86_l_6c42;
	case 27717ULL: goto x86_l_6c45;
	case 27720ULL: goto x86_l_6c48;
	case 27723ULL: goto x86_l_6c4b;
	case 27725ULL: goto x86_l_6c4d;
	case 27731ULL: goto x86_l_6c53;
	case 27736ULL: goto x86_l_6c58;
	case 27741ULL: goto x86_l_6c5d;
	case 27746ULL: goto x86_l_6c62;
	case 27751ULL: goto x86_l_6c67;
	case 27754ULL: goto x86_l_6c6a;
	case 27756ULL: goto x86_l_6c6c;
	case 27759ULL: goto x86_l_6c6f;
	case 27765ULL: goto x86_l_6c75;
	case 27772ULL: goto x86_l_6c7c;
	case 27775ULL: goto x86_l_6c7f;
	case 27781ULL: goto x86_l_6c85;
	case 27791ULL: goto x86_l_6c8f;
	case 27796ULL: goto x86_l_6c94;
	case 27806ULL: goto x86_l_6c9e;
	case 27811ULL: goto x86_l_6ca3;
	case 27821ULL: goto x86_l_6cad;
	case 27826ULL: goto x86_l_6cb2;
	case 27836ULL: goto x86_l_6cbc;
	case 27841ULL: goto x86_l_6cc1;
	case 27851ULL: goto x86_l_6ccb;
	case 27856ULL: goto x86_l_6cd0;
	case 27864ULL: goto x86_l_6cd8;
	case 27869ULL: goto x86_l_6cdd;
	case 27874ULL: goto x86_l_6ce2;
	case 27879ULL: goto x86_l_6ce7;
	case 27884ULL: goto x86_l_6cec;
	case 27887ULL: goto x86_l_6cef;
	case 27889ULL: goto x86_l_6cf1;
	case 27891ULL: goto x86_l_6cf3;
	case 27896ULL: goto x86_l_6cf8;
	case 27900ULL: goto x86_l_6cfc;
	case 27904ULL: goto x86_l_6d00;
	case 27909ULL: goto x86_l_6d05;
	case 27912ULL: goto x86_l_6d08;
	case 27917ULL: goto x86_l_6d0d;
	case 27927ULL: goto x86_l_6d17;
	case 27932ULL: goto x86_l_6d1c;
	case 27942ULL: goto x86_l_6d26;
	case 27947ULL: goto x86_l_6d2b;
	case 27957ULL: goto x86_l_6d35;
	case 27962ULL: goto x86_l_6d3a;
	case 27972ULL: goto x86_l_6d44;
	case 27977ULL: goto x86_l_6d49;
	case 27987ULL: goto x86_l_6d53;
	case 27992ULL: goto x86_l_6d58;
	case 28000ULL: goto x86_l_6d60;
	case 28005ULL: goto x86_l_6d65;
	case 28010ULL: goto x86_l_6d6a;
	case 28015ULL: goto x86_l_6d6f;
	case 28020ULL: goto x86_l_6d74;
	case 28023ULL: goto x86_l_6d77;
	case 28025ULL: goto x86_l_6d79;
	case 28027ULL: goto x86_l_6d7b;
	case 28030ULL: goto x86_l_6d7e;
	case 28035ULL: goto x86_l_6d83;
	case 28045ULL: goto x86_l_6d8d;
	case 28050ULL: goto x86_l_6d92;
	case 28060ULL: goto x86_l_6d9c;
	case 28065ULL: goto x86_l_6da1;
	case 28070ULL: goto x86_l_6da6;
	case 28075ULL: goto x86_l_6dab;
	case 28080ULL: goto x86_l_6db0;
	case 28086ULL: goto x86_l_6db6;
	case 28090ULL: goto x86_l_6dba;
	case 28095ULL: goto x86_l_6dbf;
	case 28100ULL: goto x86_l_6dc4;
	case 28103ULL: goto x86_l_6dc7;
	case 28105ULL: goto x86_l_6dc9;
	case 28108ULL: goto x86_l_6dcc;
	case 28112ULL: goto x86_l_6dd0;
	case 28118ULL: goto x86_l_6dd6;
	case 28126ULL: goto x86_l_6dde;
	case 28134ULL: goto x86_l_6de6;
	case 28138ULL: goto x86_l_6dea;
	case 28140ULL: goto x86_l_6dec;
	case 28148ULL: goto x86_l_6df4;
	case 28156ULL: goto x86_l_6dfc;
	case 28160ULL: goto x86_l_6e00;
	case 28162ULL: goto x86_l_6e02;
	case 28167ULL: goto x86_l_6e07;
	case 28175ULL: goto x86_l_6e0f;
	case 28178ULL: goto x86_l_6e12;
	case 28181ULL: goto x86_l_6e15;
	case 28183ULL: goto x86_l_6e17;
	case 28188ULL: goto x86_l_6e1c;
	case 28193ULL: goto x86_l_6e21;
	case 28198ULL: goto x86_l_6e26;
	case 28203ULL: goto x86_l_6e2b;
	case 28206ULL: goto x86_l_6e2e;
	case 28208ULL: goto x86_l_6e30;
	case 28210ULL: goto x86_l_6e32;
	case 28215ULL: goto x86_l_6e37;
	case 28218ULL: goto x86_l_6e3a;
	case 28220ULL: goto x86_l_6e3c;
	case 28225ULL: goto x86_l_6e41;
	case 28232ULL: goto x86_l_6e48;
	case 28235ULL: goto x86_l_6e4b;
	case 28240ULL: goto x86_l_6e50;
	case 28246ULL: goto x86_l_6e56;
	case 28250ULL: goto x86_l_6e5a;
	case 28255ULL: goto x86_l_6e5f;
	case 28260ULL: goto x86_l_6e64;
	case 28268ULL: goto x86_l_6e6c;
	case 28273ULL: goto x86_l_6e71;
	case 28275ULL: goto x86_l_6e73;
	case 28278ULL: goto x86_l_6e76;
	case 28284ULL: goto x86_l_6e7c;
	case 28291ULL: goto x86_l_6e83;
	case 28298ULL: goto x86_l_6e8a;
	case 28306ULL: goto x86_l_6e92;
	case 28313ULL: goto x86_l_6e99;
	case 28318ULL: goto x86_l_6e9e;
	case 28323ULL: goto x86_l_6ea3;
	case 28325ULL: goto x86_l_6ea5;
	case 28328ULL: goto x86_l_6ea8;
	case 28330ULL: goto x86_l_6eaa;
	case 28333ULL: goto x86_l_6ead;
	case 28335ULL: goto x86_l_6eaf;
	case 28342ULL: goto x86_l_6eb6;
	case 28345ULL: goto x86_l_6eb9;
	case 28347ULL: goto x86_l_6ebb;
	case 28352ULL: goto x86_l_6ec0;
	case 28359ULL: goto x86_l_6ec7;
	case 28362ULL: goto x86_l_6eca;
	case 28368ULL: goto x86_l_6ed0;
	case 28370ULL: goto x86_l_6ed2;
	case 28378ULL: goto x86_l_6eda;
	case 28381ULL: goto x86_l_6edd;
	case 28384ULL: goto x86_l_6ee0;
	case 28390ULL: goto x86_l_6ee6;
	case 28392ULL: goto x86_l_6ee8;
	case 28398ULL: goto x86_l_6eee;
	case 28408ULL: goto x86_l_6ef8;
	case 28411ULL: goto x86_l_6efb;
	case 28417ULL: goto x86_l_6f01;
	case 28424ULL: goto x86_l_6f08;
	case 28430ULL: goto x86_l_6f0e;
	case 28432ULL: goto x86_l_6f10;
	case 28440ULL: goto x86_l_6f18;
	case 28446ULL: goto x86_l_6f1e;
	case 28453ULL: goto x86_l_6f25;
	case 28460ULL: goto x86_l_6f2c;
	case 28465ULL: goto x86_l_6f31;
	case 28470ULL: goto x86_l_6f36;
	case 28472ULL: goto x86_l_6f38;
	case 28475ULL: goto x86_l_6f3b;
	case 28481ULL: goto x86_l_6f41;
	case 28485ULL: goto x86_l_6f45;
	case 28495ULL: goto x86_l_6f4f;
	case 28498ULL: goto x86_l_6f52;
	case 28505ULL: goto x86_l_6f59;
	case 28508ULL: goto x86_l_6f5c;
	case 28515ULL: goto x86_l_6f63;
	case 28519ULL: goto x86_l_6f67;
	case 28522ULL: goto x86_l_6f6a;
	case 28525ULL: goto x86_l_6f6d;
	case 28532ULL: goto x86_l_6f74;
	case 28539ULL: goto x86_l_6f7b;
	case 28542ULL: goto x86_l_6f7e;
	case 28548ULL: goto x86_l_6f84;
	case 28552ULL: goto x86_l_6f88;
	case 28558ULL: goto x86_l_6f8e;
	case 28565ULL: goto x86_l_6f95;
	case 28570ULL: goto x86_l_6f9a;
	case 28577ULL: goto x86_l_6fa1;
	case 28584ULL: goto x86_l_6fa8;
	case 28589ULL: goto x86_l_6fad;
	case 28594ULL: goto x86_l_6fb2;
	case 28596ULL: goto x86_l_6fb4;
	case 28602ULL: goto x86_l_6fba;
	case 28605ULL: goto x86_l_6fbd;
	case 28611ULL: goto x86_l_6fc3;
	case 28614ULL: goto x86_l_6fc6;
	case 28617ULL: goto x86_l_6fc9;
	case 28619ULL: goto x86_l_6fcb;
	case 28623ULL: goto x86_l_6fcf;
	case 28625ULL: goto x86_l_6fd1;
	case 28629ULL: goto x86_l_6fd5;
	case 28635ULL: goto x86_l_6fdb;
	case 28639ULL: goto x86_l_6fdf;
	case 28645ULL: goto x86_l_6fe5;
	case 28652ULL: goto x86_l_6fec;
	case 28655ULL: goto x86_l_6fef;
	case 28661ULL: goto x86_l_6ff5;
	case 28667ULL: goto x86_l_6ffb;
	case 28671ULL: goto x86_l_6fff;
	case 28674ULL: goto x86_l_7002;
	case 28680ULL: goto x86_l_7008;
	case 28687ULL: goto x86_l_700f;
	case 28690ULL: goto x86_l_7012;
	case 28696ULL: goto x86_l_7018;
	case 28706ULL: goto x86_l_7022;
	case 28714ULL: goto x86_l_702a;
	case 28724ULL: goto x86_l_7034;
	case 28732ULL: goto x86_l_703c;
	case 28742ULL: goto x86_l_7046;
	case 28750ULL: goto x86_l_704e;
	case 28761ULL: goto x86_l_7059;
	case 28769ULL: goto x86_l_7061;
	case 28774ULL: goto x86_l_7066;
	case 28779ULL: goto x86_l_706b;
	case 28784ULL: goto x86_l_7070;
	case 28786ULL: goto x86_l_7072;
	case 28788ULL: goto x86_l_7074;
	case 28793ULL: goto x86_l_7079;
	case 28798ULL: goto x86_l_707e;
	case 28800ULL: goto x86_l_7080;
	case 28807ULL: goto x86_l_7087;
	case 28809ULL: goto x86_l_7089;
	case 28819ULL: goto x86_l_7093;
	case 28825ULL: goto x86_l_7099;
	case 28828ULL: goto x86_l_709c;
	case 28833ULL: goto x86_l_70a1;
	case 28843ULL: goto x86_l_70ab;
	case 28851ULL: goto x86_l_70b3;
	case 28861ULL: goto x86_l_70bd;
	case 28869ULL: goto x86_l_70c5;
	case 28879ULL: goto x86_l_70cf;
	case 28887ULL: goto x86_l_70d7;
	case 28897ULL: goto x86_l_70e1;
	case 28905ULL: goto x86_l_70e9;
	case 28915ULL: goto x86_l_70f3;
	case 28923ULL: goto x86_l_70fb;
	case 28933ULL: goto x86_l_7105;
	case 28941ULL: goto x86_l_710d;
	case 28949ULL: goto x86_l_7115;
	case 28957ULL: goto x86_l_711d;
	case 28962ULL: goto x86_l_7122;
	case 28967ULL: goto x86_l_7127;
	case 28972ULL: goto x86_l_712c;
	case 28974ULL: goto x86_l_712e;
	case 28976ULL: goto x86_l_7130;
	case 28981ULL: goto x86_l_7135;
	case 28986ULL: goto x86_l_713a;
	case 28993ULL: goto x86_l_7141;
	case 28996ULL: goto x86_l_7144;
	case 28998ULL: goto x86_l_7146;
	case 29008ULL: goto x86_l_7150;
	case 29014ULL: goto x86_l_7156;
	case 29017ULL: goto x86_l_7159;
	case 29022ULL: goto x86_l_715e;
	case 29032ULL: goto x86_l_7168;
	case 29040ULL: goto x86_l_7170;
	case 29050ULL: goto x86_l_717a;
	case 29058ULL: goto x86_l_7182;
	case 29068ULL: goto x86_l_718c;
	case 29076ULL: goto x86_l_7194;
	case 29086ULL: goto x86_l_719e;
	case 29094ULL: goto x86_l_71a6;
	case 29104ULL: goto x86_l_71b0;
	case 29112ULL: goto x86_l_71b8;
	case 29122ULL: goto x86_l_71c2;
	case 29130ULL: goto x86_l_71ca;
	case 29140ULL: goto x86_l_71d4;
	case 29148ULL: goto x86_l_71dc;
	case 29156ULL: goto x86_l_71e4;
	case 29164ULL: goto x86_l_71ec;
	case 29169ULL: goto x86_l_71f1;
	case 29174ULL: goto x86_l_71f6;
	case 29179ULL: goto x86_l_71fb;
	case 29182ULL: goto x86_l_71fe;
	case 29184ULL: goto x86_l_7200;
	case 29186ULL: goto x86_l_7202;
	case 29191ULL: goto x86_l_7207;
	case 29201ULL: goto x86_l_7211;
	case 29206ULL: goto x86_l_7216;
	case 29216ULL: goto x86_l_7220;
	case 29221ULL: goto x86_l_7225;
	case 29231ULL: goto x86_l_722f;
	case 29236ULL: goto x86_l_7234;
	case 29246ULL: goto x86_l_723e;
	case 29251ULL: goto x86_l_7243;
	case 29261ULL: goto x86_l_724d;
	case 29266ULL: goto x86_l_7252;
	case 29276ULL: goto x86_l_725c;
	case 29281ULL: goto x86_l_7261;
	case 29286ULL: goto x86_l_7266;
	case 29291ULL: goto x86_l_726b;
	case 29296ULL: goto x86_l_7270;
	case 29300ULL: goto x86_l_7274;
	case 29305ULL: goto x86_l_7279;
	case 29307ULL: goto x86_l_727b;
	case 29309ULL: goto x86_l_727d;
	case 29311ULL: goto x86_l_727f;
	case 29318ULL: goto x86_l_7286;
	case 29321ULL: goto x86_l_7289;
	case 29327ULL: goto x86_l_728f;
	case 29337ULL: goto x86_l_7299;
	case 29345ULL: goto x86_l_72a1;
	case 29355ULL: goto x86_l_72ab;
	case 29363ULL: goto x86_l_72b3;
	case 29373ULL: goto x86_l_72bd;
	case 29381ULL: goto x86_l_72c5;
	case 29391ULL: goto x86_l_72cf;
	case 29399ULL: goto x86_l_72d7;
	case 29407ULL: goto x86_l_72df;
	case 29412ULL: goto x86_l_72e4;
	case 29418ULL: goto x86_l_72ea;
	case 29426ULL: goto x86_l_72f2;
	case 29429ULL: goto x86_l_72f5;
	case 29432ULL: goto x86_l_72f8;
	case 29437ULL: goto x86_l_72fd;
	case 29440ULL: goto x86_l_7300;
	case 29445ULL: goto x86_l_7305;
	case 29447ULL: goto x86_l_7307;
	case 29450ULL: goto x86_l_730a;
	case 29457ULL: goto x86_l_7311;
	case 29459ULL: goto x86_l_7313;
	case 29464ULL: goto x86_l_7318;
	case 29474ULL: goto x86_l_7322;
	case 29482ULL: goto x86_l_732a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6b28:
	/* 0x6b28: jmp    62e6 <kprobe_unwind_native+0x62e6> */
	return 25318ULL;
x86_l_6b2d:
	/* 0x6b2d: movabs rax,0xa756c252b642572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 753627419551999346ULL);
x86_l_6b37:
	/* 0x6b37: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6b3c:
	/* 0x6b3c: movabs rax,0x203a646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2322278983241526901ULL);
x86_l_6b46:
	/* 0x6b46: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b4b:
	/* 0x6b4b: mov    BYTE PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_6b50:
	/* 0x6b50: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b55:
	/* 0x6b55: mov    eax,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_6b5a:
	/* 0x6b5a: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_6b60:
	/* 0x6b60: and    ebp,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_6b63:
	/* 0x6b63: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6b68:
	/* 0x6b68: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_6b6d:
	/* 0x6b6d: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_6b6f:
	/* 0x6b6f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b71:
	/* 0x6b71: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6b74:
	/* 0x6b74: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b77:
	/* 0x6b77: cmp    ebp,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_6b7a:
	/* 0x6b7a: jle    653b <kprobe_unwind_native+0x653b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 25915ULL;
	}
x86_l_6b80:
	/* 0x6b80: mov    rax,QWORD PTR [rsp+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_6b88:
	/* 0x6b88: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_6b8b:
	/* 0x6b8b: je     6b9a <kprobe_unwind_native+0x6b9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6b9a;
	}
x86_l_6b8d:
	/* 0x6b8d: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_6b95:
	/* 0x6b95: cmp    ebp,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 15ULL);
x86_l_6b98:
	/* 0x6b98: jne    6ba2 <kprobe_unwind_native+0x6ba2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6ba2;
	}
x86_l_6b9a:
	/* 0x6b9a: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6b9f:
	/* 0x6b9f: add    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_6ba2:
	/* 0x6ba2: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6ba7:
	/* 0x6ba7: movzx  eax,BYTE PTR [rcx+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_6bab:
	/* 0x6bab: mov    r12d,DWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6baf:
	/* 0x6baf: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_6bb2:
	/* 0x6bb2: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_6bb5:
	/* 0x6bb5: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_6bb7:
	/* 0x6bb7: cmovns ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_NS);
x86_l_6bbb:
	/* 0x6bbb: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_6bbd:
	/* 0x6bbd: and    edx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_6bc0:
	/* 0x6bc0: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_6bc3:
	/* 0x6bc3: jg     6bda <kprobe_unwind_native+0x6bda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_6bda;
	}
x86_l_6bc5:
	/* 0x6bc5: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_6bc8:
	/* 0x6bc8: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_6bcb:
	/* 0x6bcb: je     6c45 <kprobe_unwind_native+0x6c45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6c45;
	}
x86_l_6bcd:
	/* 0x6bcd: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_6bd0:
	/* 0x6bd0: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_6bd3:
	/* 0x6bd3: je     6c42 <kprobe_unwind_native+0x6c42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6c42;
	}
x86_l_6bd5:
	/* 0x6bd5: jmp    6e32 <kprobe_unwind_native+0x6e32> */
	goto x86_l_6e32;
x86_l_6bda:
	/* 0x6bda: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_6bdd:
	/* 0x6bdd: je     6c3d <kprobe_unwind_native+0x6c3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6c3d;
	}
x86_l_6bdf:
	/* 0x6bdf: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_6be2:
	/* 0x6be2: jne    6e32 <kprobe_unwind_native+0x6e32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6e32;
	}
x86_l_6be8:
	/* 0x6be8: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_6beb:
	/* 0x6beb: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_6bed:
	/* 0x6bed: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_6bf0:
	/* 0x6bf0: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_6bf2:
	/* 0x6bf2: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6bf7:
	/* 0x6bf7: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6bfe:
	/* 0x6bfe: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6c01:
	/* 0x6c01: jne    6d83 <kprobe_unwind_native+0x6d83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6d83;
	}
x86_l_6c07:
	/* 0x6c07: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_6c0b:
	/* 0x6c0b: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_6c0f:
	/* 0x6c0f: jg     6dd6 <kprobe_unwind_native+0x6dd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_6dd6;
	}
x86_l_6c15:
	/* 0x6c15: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_6c18:
	/* 0x6c18: je     6e02 <kprobe_unwind_native+0x6e02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6e02;
	}
x86_l_6c1e:
	/* 0x6c1e: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_6c22:
	/* 0x6c22: jne    6e32 <kprobe_unwind_native+0x6e32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6e32;
	}
x86_l_6c28:
	/* 0x6c28: mov    rax,QWORD PTR [rsp+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_6c30:
	/* 0x6c30: mov    QWORD PTR [rsp+0x138],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_6c38:
	/* 0x6c38: jmp    6e02 <kprobe_unwind_native+0x6e02> */
	goto x86_l_6e02;
x86_l_6c3d:
	/* 0x6c3d: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6c42:
	/* 0x6c42: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6c45:
	/* 0x6c45: movsxd rbp,ecx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_6c48:
	/* 0x6c48: add    rbp,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6c4b:
	/* 0x6c4b: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_6c4d:
	/* 0x6c4d: jns    6e12 <kprobe_unwind_native+0x6e12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_6e12;
	}
x86_l_6c53:
	/* 0x6c53: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6c58:
	/* 0x6c58: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6c5d:
	/* 0x6c5d: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_6c62:
	/* 0x6c62: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6c67:
	/* 0x6c67: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6c6a:
	/* 0x6c6a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6c6c:
	/* 0x6c6c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6c6f:
	/* 0x6c6f: je     6cf8 <kprobe_unwind_native+0x6cf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6cf8;
	}
x86_l_6c75:
	/* 0x6c75: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6c7c:
	/* 0x6c7c: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6c7f:
	/* 0x6c7f: je     6e32 <kprobe_unwind_native+0x6e32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6e32;
	}
x86_l_6c85:
	/* 0x6c85: movabs rax,0x2578302073736572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2699960892542641522ULL);
x86_l_6c8f:
	/* 0x6c8f: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6c94:
	/* 0x6c94: movabs rax,0x6464612065636e65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7234013693231722085ULL);
x86_l_6c9e:
	/* 0x6c9e: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6ca3:
	/* 0x6ca3: movabs rax,0x7265666572656420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243107278868538400ULL);
x86_l_6cad:
	/* 0x6cad: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6cb2:
	/* 0x6cb2: movabs rax,0x6f742064656c6961 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8031079651078859105ULL);
x86_l_6cbc:
	/* 0x6cbc: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6cc1:
	/* 0x6cc1: movabs rax,0x6620646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358992216502005365ULL);
x86_l_6ccb:
	/* 0x6ccb: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6cd0:
	/* 0x6cd0: mov    DWORD PTR [rsp+0x38],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518854764ULL);
x86_l_6cd8:
	/* 0x6cd8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6cdd:
	/* 0x6cdd: mov    eax,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_6ce2:
	/* 0x6ce2: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6ce7:
	/* 0x6ce7: mov    esi,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_6cec:
	/* 0x6cec: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6cef:
	/* 0x6cef: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6cf1:
	/* 0x6cf1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6cf3:
	/* 0x6cf3: jmp    6e32 <kprobe_unwind_native+0x6e32> */
	goto x86_l_6e32;
x86_l_6cf8:
	/* 0x6cf8: shl    r12d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_6cfc:
	/* 0x6cfc: and    r12d,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 56ULL);
x86_l_6d00:
	/* 0x6d00: add    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_6d05:
	/* 0x6d05: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_6d08:
	/* 0x6d08: jmp    6e12 <kprobe_unwind_native+0x6e12> */
	goto x86_l_6e12;
x86_l_6d0d:
	/* 0x6d0d: movabs rax,0x2578302073736572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2699960892542641522ULL);
x86_l_6d17:
	/* 0x6d17: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6d1c:
	/* 0x6d1c: movabs rax,0x6464612065636e65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7234013693231722085ULL);
x86_l_6d26:
	/* 0x6d26: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6d2b:
	/* 0x6d2b: movabs rax,0x7265666572656420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243107278868538400ULL);
x86_l_6d35:
	/* 0x6d35: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6d3a:
	/* 0x6d3a: movabs rax,0x6f742064656c6961 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8031079651078859105ULL);
x86_l_6d44:
	/* 0x6d44: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6d49:
	/* 0x6d49: movabs rax,0x6620646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358992216502005365ULL);
x86_l_6d53:
	/* 0x6d53: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6d58:
	/* 0x6d58: mov    DWORD PTR [rsp+0x38],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518854764ULL);
x86_l_6d60:
	/* 0x6d60: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6d65:
	/* 0x6d65: mov    eax,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_6d6a:
	/* 0x6d6a: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6d6f:
	/* 0x6d6f: mov    esi,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_6d74:
	/* 0x6d74: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_6d77:
	/* 0x6d77: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6d79:
	/* 0x6d79: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6d7b:
	/* 0x6d7b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6d7e:
	/* 0x6d7e: jmp    6ba2 <kprobe_unwind_native+0x6ba2> */
	goto x86_l_6ba2;
x86_l_6d83:
	/* 0x6d83: movabs rax,0xa756c252b642572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 753627419551999346ULL);
x86_l_6d8d:
	/* 0x6d8d: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6d92:
	/* 0x6d92: movabs rax,0x203a646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2322278983241526901ULL);
x86_l_6d9c:
	/* 0x6d9c: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6da1:
	/* 0x6da1: mov    BYTE PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_6da6:
	/* 0x6da6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6dab:
	/* 0x6dab: mov    eax,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_6db0:
	/* 0x6db0: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_6db6:
	/* 0x6db6: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_6dba:
	/* 0x6dba: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6dbf:
	/* 0x6dbf: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_6dc4:
	/* 0x6dc4: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_6dc7:
	/* 0x6dc7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6dc9:
	/* 0x6dc9: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6dcc:
	/* 0x6dcc: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_6dd0:
	/* 0x6dd0: jle    6c15 <kprobe_unwind_native+0x6c15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_6c15;
	}
x86_l_6dd6:
	/* 0x6dd6: mov    rax,QWORD PTR [rsp+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_6dde:
	/* 0x6dde: mov    QWORD PTR [rsp+0x138],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_6de6:
	/* 0x6de6: cmp    r12d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 11ULL);
x86_l_6dea:
	/* 0x6dea: je     6e02 <kprobe_unwind_native+0x6e02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6e02;
	}
x86_l_6dec:
	/* 0x6dec: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_6df4:
	/* 0x6df4: mov    QWORD PTR [rsp+0x138],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_6dfc:
	/* 0x6dfc: cmp    r12d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 15ULL);
x86_l_6e00:
	/* 0x6e00: jne    6e32 <kprobe_unwind_native+0x6e32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6e32;
	}
x86_l_6e02:
	/* 0x6e02: mov    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6e07:
	/* 0x6e07: mov    rax,QWORD PTR [rsp+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_6e0f:
	/* 0x6e0f: add    rbp,QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_6e12:
	/* 0x6e12: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_6e15:
	/* 0x6e15: je     6e32 <kprobe_unwind_native+0x6e32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6e32;
	}
x86_l_6e17:
	/* 0x6e17: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6e1c:
	/* 0x6e1c: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_6e21:
	/* 0x6e21: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6e26:
	/* 0x6e26: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6e2b:
	/* 0x6e2b: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6e2e:
	/* 0x6e2e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6e30:
	/* 0x6e30: jmp    6e48 <kprobe_unwind_native+0x6e48> */
	goto x86_l_6e48;
x86_l_6e32:
	/* 0x6e32: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6e37:
	/* 0x6e37: cmp    BYTE PTR [rax],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_6e3a:
	/* 0x6e3a: jne    6e48 <kprobe_unwind_native+0x6e48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6e48;
	}
x86_l_6e3c:
	/* 0x6e3c: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6e41:
	/* 0x6e41: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6e48:
	/* 0x6e48: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_6e4b:
	/* 0x6e4b: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6e50:
	/* 0x6e50: je     1647 <kprobe_unwind_native+0x1647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5703ULL;
	}
x86_l_6e56:
	/* 0x6e56: lea    rdx,[r13-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_6e5a:
	/* 0x6e5a: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6e5f:
	/* 0x6e5f: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_6e64:
	/* 0x6e64: mov    rdi,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_6e6c:
	/* 0x6e6c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6e71:
	/* 0x6e71: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6e73:
	/* 0x6e73: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6e76:
	/* 0x6e76: jne    1647 <kprobe_unwind_native+0x1647> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5703ULL;
	}
x86_l_6e7c:
	/* 0x6e7c: mov    QWORD PTR [rbx+0xed8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_6e83:
	/* 0x6e83: mov    BYTE PTR [rbx+0xf30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16698832846849ULL);
x86_l_6e8a:
	/* 0x6e8a: mov    DWORD PTR [rsp+0x78],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075526ULL);
x86_l_6e92:
	/* 0x6e92: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_6e99:
	/* 0x6e99: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6e9e:
	/* 0x6e9e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6ea3:
	/* 0x6ea3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ea5:
	/* 0x6ea5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6ea8:
	/* 0x6ea8: je     6ec0 <kprobe_unwind_native+0x6ec0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6ec0;
	}
x86_l_6eaa:
	/* 0x6eaa: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6ead:
	/* 0x6ead: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6eaf:
	/* 0x6eaf: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6eb6:
	/* 0x6eb6: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6eb9:
	/* 0x6eb9: je     6ed2 <kprobe_unwind_native+0x6ed2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6ed2;
	}
x86_l_6ebb:
	/* 0x6ebb: jmp    728f <kprobe_unwind_native+0x728f> */
	goto x86_l_728f;
x86_l_6ec0:
	/* 0x6ec0: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6ec7:
	/* 0x6ec7: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6eca:
	/* 0x6eca: jne    7207 <kprobe_unwind_native+0x7207> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7207;
	}
x86_l_6ed0:
	/* 0x6ed0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ed2:
	/* 0x6ed2: mov    rcx,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_6eda:
	/* 0x6eda: mov    r13,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6edd:
	/* 0x6edd: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_6ee0:
	/* 0x6ee0: je     7079 <kprobe_unwind_native+0x7079> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7079;
	}
x86_l_6ee6:
	/* 0x6ee6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6ee8:
	/* 0x6ee8: jne    7318 <kprobe_unwind_native+0x7318> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7318;
	}
x86_l_6eee:
	/* 0x6eee: movabs rax,0xffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72057594037927935ULL);
x86_l_6ef8:
	/* 0x6ef8: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_6efb:
	/* 0x6efb: ja     339e <kprobe_unwind_native+0x339e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13214ULL;
	}
x86_l_6f01:
	/* 0x6f01: cmp    r13,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4096ULL);
x86_l_6f08:
	/* 0x6f08: jb     34e4 <kprobe_unwind_native+0x34e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13540ULL;
	}
x86_l_6f0e:
	/* 0x6f0e: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6f10:
	/* 0x6f10: mov    DWORD PTR [rsp+0x10],0x60 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476832ULL);
x86_l_6f18:
	/* 0x6f18: movbe  DWORD PTR [rsp+0x14],eax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_6f1e:
	/* 0x6f1e: movbe  QWORD PTR [rsp+0x18],r13 */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_6f25:
	/* 0x6f25: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_page_to_mapping_info)));
x86_l_6f2c:
	/* 0x6f2c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6f31:
	/* 0x6f31: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6f36:
	/* 0x6f36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f38:
	/* 0x6f38: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6f3b:
	/* 0x6f3b: je     7135 <kprobe_unwind_native+0x7135> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7135;
	}
x86_l_6f41:
	/* 0x6f41: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6f45:
	/* 0x6f45: movabs rcx,0xffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 72057594037927935ULL);
x86_l_6f4f:
	/* 0x6f4f: and    rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_6f52:
	/* 0x6f52: mov    QWORD PTR [rbx+0xf20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3872ULL);
x86_l_6f59:
	/* 0x6f59: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6f5c:
	/* 0x6f5c: mov    QWORD PTR [rbx+0xf10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_6f63:
	/* 0x6f63: shr    r12,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_6f67:
	/* 0x6f67: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_6f6a:
	/* 0x6f6a: sub    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_6f6d:
	/* 0x6f6d: mov    QWORD PTR [rbx+0xf18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_6f74:
	/* 0x6f74: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6f7b:
	/* 0x6f7b: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6f7e:
	/* 0x6f7e: jne    73cc <kprobe_unwind_native+0x73cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 29644ULL;
	}
x86_l_6f84:
	/* 0x6f84: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_6f88:
	/* 0x6f88: jne    75bf <kprobe_unwind_native+0x75bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 30143ULL;
	}
x86_l_6f8e:
	/* 0x6f8e: mov    rax,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_6f95:
	/* 0x6f95: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6f9a:
	/* 0x6f9a: mov    r13,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_6fa1:
	/* 0x6fa1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&interpreter_offsets)));
x86_l_6fa8:
	/* 0x6fa8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6fad:
	/* 0x6fad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6fb2:
	/* 0x6fb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6fb4:
	/* 0x6fb4: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_6fba:
	/* 0x6fba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6fbd:
	/* 0x6fbd: je     75bf <kprobe_unwind_native+0x75bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 30143ULL;
	}
x86_l_6fc3:
	/* 0x6fc3: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_6fc6:
	/* 0x6fc6: cmp    QWORD PTR [rax],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6fc9:
	/* 0x6fc9: ja     6fd1 <kprobe_unwind_native+0x6fd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_6fd1;
	}
x86_l_6fcb:
	/* 0x6fcb: cmp    QWORD PTR [r15+0x8],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6fcf:
	/* 0x6fcf: jae    6fe5 <kprobe_unwind_native+0x6fe5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_6fe5;
	}
x86_l_6fd1:
	/* 0x6fd1: cmp    QWORD PTR [r15+0x10],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6fd5:
	/* 0x6fd5: ja     75bf <kprobe_unwind_native+0x75bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 30143ULL;
	}
x86_l_6fdb:
	/* 0x6fdb: cmp    QWORD PTR [r15+0x18],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6fdf:
	/* 0x6fdf: jb     75bf <kprobe_unwind_native+0x75bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 30143ULL;
	}
x86_l_6fe5:
	/* 0x6fe5: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6fec:
	/* 0x6fec: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6fef:
	/* 0x6fef: jne    750e <kprobe_unwind_native+0x750e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 29966ULL;
	}
x86_l_6ff5:
	/* 0x6ff5: mov    eax,DWORD PTR [rbx+0x1380] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4992ULL);
x86_l_6ffb:
	/* 0x6ffb: mov    ecx,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6fff:
	/* 0x6fff: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_7002:
	/* 0x7002: jae    7589 <kprobe_unwind_native+0x7589> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 30089ULL;
	}
x86_l_7008:
	/* 0x7008: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_700f:
	/* 0x700f: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7012:
	/* 0x7012: je     75bf <kprobe_unwind_native+0x75bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 30143ULL;
	}
x86_l_7018:
	/* 0x7018: movabs rax,0x6e6f64207265646e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7957689157107934318ULL);
x86_l_7022:
	/* 0x7022: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_702a:
	/* 0x702a: movabs rax,0x69776e7520726574 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7599664345545598324ULL);
x86_l_7034:
	/* 0x7034: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_703c:
	/* 0x703c: movabs rax,0x6572707265746e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310028781806448233ULL);
x86_l_7046:
	/* 0x7046: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_704e:
	/* 0x704e: mov    DWORD PTR [rsp+0xb7],0xa656e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 785979696494ULL);
x86_l_7059:
	/* 0x7059: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_7061:
	/* 0x7061: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_7066:
	/* 0x7066: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_706b:
	/* 0x706b: mov    esi,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 27ULL);
x86_l_7070:
	/* 0x7070: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7072:
	/* 0x7072: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7074:
	/* 0x7074: jmp    75bf <kprobe_unwind_native+0x75bf> */
	return 30143ULL;
x86_l_7079:
	/* 0x7079: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_707e:
	/* 0x707e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7080:
	/* 0x7080: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_7087:
	/* 0x7087: jne    70a1 <kprobe_unwind_native+0x70a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_70a1;
	}
x86_l_7089:
	/* 0x7089: mov    DWORD PTR [rbx+0xf28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16664473108481ULL);
x86_l_7093:
	/* 0x7093: mov    r14d,0xfad */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4013ULL);
x86_l_7099:
	/* 0x7099: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_709c:
	/* 0x709c: jmp    5f60 <kprobe_unwind_native+0x5f60> */
	return 24416ULL;
x86_l_70a1:
	/* 0x70a1: movabs rax,0xa2930203d3d2043 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 732169329448919107ULL);
x86_l_70ab:
	/* 0x70ab: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_70b3:
	/* 0x70b3: movabs rax,0x5028206572756c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5775902142186744937ULL);
x86_l_70bd:
	/* 0x70bd: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_70c5:
	/* 0x70c5: movabs rax,0x616620646e69776e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332685024720750ULL);
x86_l_70cf:
	/* 0x70cf: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_70d7:
	/* 0x70d7: movabs rax,0x75206f7420657564 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8439868246242719076ULL);
x86_l_70e1:
	/* 0x70e1: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_70e9:
	/* 0x70e9: movabs rax,0x20646e69776e7520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334111906139108640ULL);
x86_l_70f3:
	/* 0x70f3: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_70fb:
	/* 0x70fb: movabs rax,0x676e6970706f7453 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7453010364988355667ULL);
x86_l_7105:
	/* 0x7105: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_710d:
	/* 0x710d: mov    BYTE PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_7115:
	/* 0x7115: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_711d:
	/* 0x711d: mov    eax,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 49ULL);
x86_l_7122:
	/* 0x7122: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_7127:
	/* 0x7127: mov    esi,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 49ULL);
x86_l_712c:
	/* 0x712c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_712e:
	/* 0x712e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7130:
	/* 0x7130: jmp    7089 <kprobe_unwind_native+0x7089> */
	goto x86_l_7089;
x86_l_7135:
	/* 0x7135: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_713a:
	/* 0x713a: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_7141:
	/* 0x7141: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7144:
	/* 0x7144: jne    715e <kprobe_unwind_native+0x715e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_715e;
	}
x86_l_7146:
	/* 0x7146: mov    DWORD PTR [rbx+0xf28],0xc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16664473108492ULL);
x86_l_7150:
	/* 0x7150: mov    r14d,0xfac */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4012ULL);
x86_l_7156:
	/* 0x7156: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7159:
	/* 0x7159: jmp    5f59 <kprobe_unwind_native+0x5f59> */
	return 24409ULL;
x86_l_715e:
	/* 0x715e: movabs rax,0xa786c2578302043 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 754471845770567747ULL);
x86_l_7168:
	/* 0x7168: mov    QWORD PTR [rsp+0xd0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_7170:
	/* 0x7170: movabs rax,0x5020726f6620676e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5773740545069311854ULL);
x86_l_717a:
	/* 0x717a: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_7182:
	/* 0x7182: movabs rax,0x697070616d207972 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7597696135119010162ULL);
x86_l_718c:
	/* 0x718c: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_7194:
	/* 0x7194: movabs rax,0x6f6d656d206c6176 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8029185230041276790ULL);
x86_l_719e:
	/* 0x719e: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_71a6:
	/* 0x71a6: movabs rax,0x7265746e69207075 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243122710530519157ULL);
x86_l_71b0:
	/* 0x71b0: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_71b8:
	/* 0x71b8: movabs rax,0x206b6f6f6c206f74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2336083356067852148ULL);
x86_l_71c2:
	/* 0x71c2: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_71ca:
	/* 0x71ca: movabs rax,0x206572756c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334397830517055814ULL);
x86_l_71d4:
	/* 0x71d4: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_71dc:
	/* 0x71dc: mov    BYTE PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_71e4:
	/* 0x71e4: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_71ec:
	/* 0x71ec: mov    eax,0x39 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 57ULL);
x86_l_71f1:
	/* 0x71f1: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_71f6:
	/* 0x71f6: mov    esi,0x39 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 57ULL);
x86_l_71fb:
	/* 0x71fb: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_71fe:
	/* 0x71fe: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7200:
	/* 0x7200: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7202:
	/* 0x7202: jmp    7146 <kprobe_unwind_native+0x7146> */
	goto x86_l_7146;
x86_l_7207:
	/* 0x7207: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_7211:
	/* 0x7211: mov    QWORD PTR [rsp+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_7216:
	/* 0x7216: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_7220:
	/* 0x7220: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7225:
	/* 0x7225: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_722f:
	/* 0x722f: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7234:
	/* 0x7234: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_723e:
	/* 0x723e: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7243:
	/* 0x7243: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_724d:
	/* 0x724d: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7252:
	/* 0x7252: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_725c:
	/* 0x725c: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7261:
	/* 0x7261: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7266:
	/* 0x7266: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_726b:
	/* 0x726b: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_7270:
	/* 0x7270: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_7274:
	/* 0x7274: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_7279:
	/* 0x7279: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_727b:
	/* 0x727b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_727d:
	/* 0x727d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_727f:
	/* 0x727f: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_7286:
	/* 0x7286: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7289:
	/* 0x7289: je     6ed2 <kprobe_unwind_native+0x6ed2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6ed2;
	}
x86_l_728f:
	/* 0x728f: movabs rax,0xa786c6c25203a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947156833280058ULL);
x86_l_7299:
	/* 0x7299: mov    QWORD PTR [rsp+0xb5],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 181ULL);
x86_l_72a1:
	/* 0x72a1: movabs rax,0x25203a706620786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675202433082226796ULL);
x86_l_72ab:
	/* 0x72ab: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_72b3:
	/* 0x72b3: movabs rax,0x6c25203a70732078 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7792670165601296504ULL);
x86_l_72bd:
	/* 0x72bd: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_72c5:
	/* 0x72c5: movabs rax,0x6c6c25203a637020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660273929744416ULL);
x86_l_72cf:
	/* 0x72cf: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_72d7:
	/* 0x72d7: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_72df:
	/* 0x72df: mov    eax,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_72e4:
	/* 0x72e4: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_72ea:
	/* 0x72ea: mov    rax,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_72f2:
	/* 0x72f2: mov    rdx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_72f5:
	/* 0x72f5: mov    rcx,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_72f8:
	/* 0x72f8: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_72fd:
	/* 0x72fd: mov    r8,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7300:
	/* 0x7300: mov    esi,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 29ULL);
x86_l_7305:
	/* 0x7305: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7307:
	/* 0x7307: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_730a:
	/* 0x730a: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_7311:
	/* 0x7311: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7313:
	/* 0x7313: jmp    6ed2 <kprobe_unwind_native+0x6ed2> */
	goto x86_l_6ed2;
x86_l_7318:
	/* 0x7318: movabs rax,0xa3d3d3d3d206425 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 737813247186461733ULL);
x86_l_7322:
	/* 0x7322: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_732a:
	/* 0x732a: movabs rax,0x20656d617266203a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334392247160021050ULL);
	return 29492ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_15(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 29492ULL: goto x86_l_7334;
	case 29500ULL: goto x86_l_733c;
	case 29510ULL: goto x86_l_7346;
	case 29518ULL: goto x86_l_734e;
	case 29528ULL: goto x86_l_7358;
	case 29536ULL: goto x86_l_7360;
	case 29546ULL: goto x86_l_736a;
	case 29554ULL: goto x86_l_7372;
	case 29564ULL: goto x86_l_737c;
	case 29572ULL: goto x86_l_7384;
	case 29580ULL: goto x86_l_738c;
	case 29588ULL: goto x86_l_7394;
	case 29593ULL: goto x86_l_7399;
	case 29598ULL: goto x86_l_739e;
	case 29604ULL: goto x86_l_73a4;
	case 29609ULL: goto x86_l_73a9;
	case 29611ULL: goto x86_l_73ab;
	case 29613ULL: goto x86_l_73ad;
	case 29620ULL: goto x86_l_73b4;
	case 29630ULL: goto x86_l_73be;
	case 29633ULL: goto x86_l_73c1;
	case 29639ULL: goto x86_l_73c7;
	case 29644ULL: goto x86_l_73cc;
	case 29654ULL: goto x86_l_73d6;
	case 29662ULL: goto x86_l_73de;
	case 29672ULL: goto x86_l_73e8;
	case 29680ULL: goto x86_l_73f0;
	case 29690ULL: goto x86_l_73fa;
	case 29698ULL: goto x86_l_7402;
	case 29708ULL: goto x86_l_740c;
	case 29716ULL: goto x86_l_7414;
	case 29726ULL: goto x86_l_741e;
	case 29734ULL: goto x86_l_7426;
	case 29744ULL: goto x86_l_7430;
	case 29752ULL: goto x86_l_7438;
	case 29762ULL: goto x86_l_7442;
	case 29770ULL: goto x86_l_744a;
	case 29775ULL: goto x86_l_744f;
	case 29781ULL: goto x86_l_7455;
	case 29788ULL: goto x86_l_745c;
	case 29793ULL: goto x86_l_7461;
	case 29796ULL: goto x86_l_7464;
	case 29799ULL: goto x86_l_7467;
	case 29801ULL: goto x86_l_7469;
	case 29804ULL: goto x86_l_746c;
	case 29811ULL: goto x86_l_7473;
	case 29814ULL: goto x86_l_7476;
	case 29820ULL: goto x86_l_747c;
	case 29830ULL: goto x86_l_7486;
	case 29838ULL: goto x86_l_748e;
	case 29848ULL: goto x86_l_7498;
	case 29856ULL: goto x86_l_74a0;
	case 29866ULL: goto x86_l_74aa;
	case 29874ULL: goto x86_l_74b2;
	case 29884ULL: goto x86_l_74bc;
	case 29892ULL: goto x86_l_74c4;
	case 29902ULL: goto x86_l_74ce;
	case 29910ULL: goto x86_l_74d6;
	case 29918ULL: goto x86_l_74de;
	case 29926ULL: goto x86_l_74e6;
	case 29931ULL: goto x86_l_74eb;
	case 29937ULL: goto x86_l_74f1;
	case 29944ULL: goto x86_l_74f8;
	case 29951ULL: goto x86_l_74ff;
	case 29956ULL: goto x86_l_7504;
	case 29958ULL: goto x86_l_7506;
	case 29961ULL: goto x86_l_7509;
	case 29966ULL: goto x86_l_750e;
	case 29976ULL: goto x86_l_7518;
	case 29984ULL: goto x86_l_7520;
	case 29994ULL: goto x86_l_752a;
	case 30002ULL: goto x86_l_7532;
	case 30012ULL: goto x86_l_753c;
	case 30020ULL: goto x86_l_7544;
	case 30030ULL: goto x86_l_754e;
	case 30038ULL: goto x86_l_7556;
	case 30046ULL: goto x86_l_755e;
	case 30051ULL: goto x86_l_7563;
	case 30056ULL: goto x86_l_7568;
	case 30061ULL: goto x86_l_756d;
	case 30066ULL: goto x86_l_7572;
	case 30068ULL: goto x86_l_7574;
	case 30070ULL: goto x86_l_7576;
	case 30076ULL: goto x86_l_757c;
	case 30080ULL: goto x86_l_7580;
	case 30083ULL: goto x86_l_7583;
	case 30089ULL: goto x86_l_7589;
	case 30097ULL: goto x86_l_7591;
	case 30104ULL: goto x86_l_7598;
	case 30109ULL: goto x86_l_759d;
	case 30114ULL: goto x86_l_75a2;
	case 30116ULL: goto x86_l_75a4;
	case 30119ULL: goto x86_l_75a7;
	case 30121ULL: goto x86_l_75a9;
	case 30124ULL: goto x86_l_75ac;
	case 30126ULL: goto x86_l_75ae;
	case 30133ULL: goto x86_l_75b5;
	case 30136ULL: goto x86_l_75b8;
	case 30138ULL: goto x86_l_75ba;
	case 30143ULL: goto x86_l_75bf;
	case 30148ULL: goto x86_l_75c4;
	case 30153ULL: goto x86_l_75c9;
	case 30163ULL: goto x86_l_75d3;
	case 30171ULL: goto x86_l_75db;
	case 30181ULL: goto x86_l_75e5;
	case 30189ULL: goto x86_l_75ed;
	case 30199ULL: goto x86_l_75f7;
	case 30207ULL: goto x86_l_75ff;
	case 30217ULL: goto x86_l_7609;
	case 30225ULL: goto x86_l_7611;
	case 30235ULL: goto x86_l_761b;
	case 30243ULL: goto x86_l_7623;
	case 30253ULL: goto x86_l_762d;
	case 30261ULL: goto x86_l_7635;
	case 30269ULL: goto x86_l_763d;
	case 30274ULL: goto x86_l_7642;
	case 30279ULL: goto x86_l_7647;
	case 30283ULL: goto x86_l_764b;
	case 30288ULL: goto x86_l_7650;
	case 30290ULL: goto x86_l_7652;
	case 30292ULL: goto x86_l_7654;
	default: return 0xffffffffffffffffULL;
	}
x86_l_7334:
	/* 0x7334: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_733c:
	/* 0x733c: movabs rax,0x7265646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243105118350175861ULL);
x86_l_7346:
	/* 0x7346: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_734e:
	/* 0x734e: movabs rax,0x20656d6172662074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334392247160021108ULL);
x86_l_7358:
	/* 0x7358: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7360:
	/* 0x7360: movabs rax,0x78656e2065766c6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8675461342619397231ULL);
x86_l_736a:
	/* 0x736a: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_7372:
	/* 0x7372: movabs rax,0x736552203d3d3d3d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8315142585429343549ULL);
x86_l_737c:
	/* 0x737c: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_7384:
	/* 0x7384: mov    BYTE PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_738c:
	/* 0x738c: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_7394:
	/* 0x7394: mov    eax,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 49ULL);
x86_l_7399:
	/* 0x7399: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_739e:
	/* 0x739e: mov    edx,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_73a4:
	/* 0x73a4: mov    esi,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 49ULL);
x86_l_73a9:
	/* 0x73a9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_73ab:
	/* 0x73ab: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_73ad:
	/* 0x73ad: mov    r13,QWORD PTR [rbx+0xed0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_73b4:
	/* 0x73b4: movabs rax,0xffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72057594037927935ULL);
x86_l_73be:
	/* 0x73be: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_73c1:
	/* 0x73c1: ja     339e <kprobe_unwind_native+0x339e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13214ULL;
	}
x86_l_73c7:
	/* 0x73c7: jmp    6f01 <kprobe_unwind_native+0x6f01> */
	return 28417ULL;
x86_l_73cc:
	/* 0x73cc: movabs rax,0x296425207265646e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2982549674514539630ULL);
x86_l_73d6:
	/* 0x73d6: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_73de:
	/* 0x73de: movabs rax,0x69776e752820786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7599664345674446956ULL);
x86_l_73e8:
	/* 0x73e8: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_73f0:
	/* 0x73f0: movabs rax,0x6c2520736920786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7792670410291574892ULL);
x86_l_73fa:
	/* 0x73fa: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_7402:
	/* 0x7402: movabs rax,0x2520435020726f66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675212190078889830ULL);
x86_l_740c:
	/* 0x740c: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7414:
	/* 0x7414: movabs rax,0x206469206e6f6974 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334106094897424756ULL);
x86_l_741e:
	/* 0x741e: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_7426:
	/* 0x7426: movabs r15,0x6365732074786554 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 7162257365632836948ULL);
x86_l_7430:
	/* 0x7430: mov    QWORD PTR [rsp+0xa0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_7438:
	/* 0x7438: mov    WORD PTR [rsp+0xd0],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 893353197578ULL);
x86_l_7442:
	/* 0x7442: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_744a:
	/* 0x744a: mov    eax,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_744f:
	/* 0x744f: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_7455:
	/* 0x7455: mov    rcx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_745c:
	/* 0x745c: mov    esi,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 50ULL);
x86_l_7461:
	/* 0x7461: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_7464:
	/* 0x7464: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_7467:
	/* 0x7467: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7469:
	/* 0x7469: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_746c:
	/* 0x746c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_7473:
	/* 0x7473: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7476:
	/* 0x7476: je     6f84 <kprobe_unwind_native+0x6f84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28548ULL;
	}
x86_l_747c:
	/* 0x747c: movabs rax,0xa786c6c252073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947156833280115ULL);
x86_l_7486:
	/* 0x7486: mov    QWORD PTR [rsp+0xc7],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 199ULL);
x86_l_748e:
	/* 0x748e: movabs rax,0x7369207465736666 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8316213871206688358ULL);
x86_l_7498:
	/* 0x7498: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_74a0:
	/* 0x74a0: movabs rax,0x6f20646e61202c78 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8007510562703420536ULL);
x86_l_74aa:
	/* 0x74aa: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_74b2:
	/* 0x74b2: movabs rax,0x6c6c252073692073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660274886418547ULL);
x86_l_74bc:
	/* 0x74bc: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_74c4:
	/* 0x74c4: movabs rax,0x616962206e6f6974 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7019249385664899444ULL);
x86_l_74ce:
	/* 0x74ce: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_74d6:
	/* 0x74d6: mov    QWORD PTR [rsp+0xa0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_74de:
	/* 0x74de: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_74e6:
	/* 0x74e6: mov    eax,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 47ULL);
x86_l_74eb:
	/* 0x74eb: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_74f1:
	/* 0x74f1: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_74f8:
	/* 0x74f8: mov    rdx,QWORD PTR [rbx+0xf20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3872ULL);
x86_l_74ff:
	/* 0x74ff: mov    esi,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 47ULL);
x86_l_7504:
	/* 0x7504: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7506:
	/* 0x7506: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_7509:
	/* 0x7509: jmp    6f84 <kprobe_unwind_native+0x6f84> */
	return 28548ULL;
x86_l_750e:
	/* 0x750e: movabs rax,0xa642520686374 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860387386228ULL);
x86_l_7518:
	/* 0x7518: mov    QWORD PTR [rsp+0xb6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_7520:
	/* 0x7520: movabs rax,0x6374616d20737465 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7166460028377068645ULL);
x86_l_752a:
	/* 0x752a: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7532:
	/* 0x7532: movabs rax,0x7366666f5f726574 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8315446390514935156ULL);
x86_l_753c:
	/* 0x753c: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_7544:
	/* 0x7544: movabs rax,0x6572707265746e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310028781806448233ULL);
x86_l_754e:
	/* 0x754e: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_7556:
	/* 0x7556: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_755e:
	/* 0x755e: mov    eax,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 30ULL);
x86_l_7563:
	/* 0x7563: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_7568:
	/* 0x7568: movzx  edx,WORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_756d:
	/* 0x756d: mov    esi,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 30ULL);
x86_l_7572:
	/* 0x7572: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7574:
	/* 0x7574: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7576:
	/* 0x7576: mov    eax,DWORD PTR [rbx+0x1380] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4992ULL);
x86_l_757c:
	/* 0x757c: mov    ecx,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7580:
	/* 0x7580: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_7583:
	/* 0x7583: jb     7008 <kprobe_unwind_native+0x7008> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 28680ULL;
	}
x86_l_7589:
	/* 0x7589: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_7591:
	/* 0x7591: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_7598:
	/* 0x7598: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_759d:
	/* 0x759d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_75a2:
	/* 0x75a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_75a4:
	/* 0x75a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_75a7:
	/* 0x75a7: je     75ae <kprobe_unwind_native+0x75ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_75ae;
	}
x86_l_75a9:
	/* 0x75a9: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_75ac:
	/* 0x75ac: jmp    75ba <kprobe_unwind_native+0x75ba> */
	goto x86_l_75ba;
x86_l_75ae:
	/* 0x75ae: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_75b5:
	/* 0x75b5: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_75b8:
	/* 0x75b8: jne    75c9 <kprobe_unwind_native+0x75c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_75c9;
	}
x86_l_75ba:
	/* 0x75ba: movzx  r12d,WORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_75bf:
	/* 0x75bf: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_75c4:
	/* 0x75c4: jmp    5f59 <kprobe_unwind_native+0x5f59> */
	return 24409ULL;
x86_l_75c9:
	/* 0x75c9: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_75d3:
	/* 0x75d3: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_75db:
	/* 0x75db: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_75e5:
	/* 0x75e5: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_75ed:
	/* 0x75ed: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_75f7:
	/* 0x75f7: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_75ff:
	/* 0x75ff: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_7609:
	/* 0x7609: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7611:
	/* 0x7611: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_761b:
	/* 0x761b: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_7623:
	/* 0x7623: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_762d:
	/* 0x762d: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_7635:
	/* 0x7635: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_763d:
	/* 0x763d: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_7642:
	/* 0x7642: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_7647:
	/* 0x7647: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_764b:
	/* 0x764b: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_7650:
	/* 0x7650: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7652:
	/* 0x7652: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7654:
	/* 0x7654: jmp    75ba <kprobe_unwind_native+0x75ba> */
	goto x86_l_75ba;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int otelcol_ebpf_profiler_kprobe_unwind_native_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 23524U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1788ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1792ULL && __x86_pc <= 3645ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3653ULL && __x86_pc <= 5738ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5744ULL && __x86_pc <= 8046ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 8054ULL && __x86_pc <= 9649ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9653ULL && __x86_pc <= 11594ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 11599ULL && __x86_pc <= 13710ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 13713ULL && __x86_pc <= 15812ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 15818ULL && __x86_pc <= 17400ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 17402ULL && __x86_pc <= 19492ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 19495ULL && __x86_pc <= 21624ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 21627ULL && __x86_pc <= 23491ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 23497ULL && __x86_pc <= 25297ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 25299ULL && __x86_pc <= 27430ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_13(__x86_state, __x86_pc);
		else if (__x86_pc >= 27432ULL && __x86_pc <= 29482ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_14(__x86_state, __x86_pc);
		else if (__x86_pc >= 29492ULL && __x86_pc <= 30292ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_15(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

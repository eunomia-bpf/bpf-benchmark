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
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 24ULL: goto x86_l_18;
	case 31ULL: goto x86_l_1f;
	case 39ULL: goto x86_l_27;
	case 44ULL: goto x86_l_2c;
	case 46ULL: goto x86_l_2e;
	case 49ULL: goto x86_l_31;
	case 55ULL: goto x86_l_37;
	case 63ULL: goto x86_l_3f;
	case 66ULL: goto x86_l_42;
	case 73ULL: goto x86_l_49;
	case 78ULL: goto x86_l_4e;
	case 84ULL: goto x86_l_54;
	case 92ULL: goto x86_l_5c;
	case 99ULL: goto x86_l_63;
	case 104ULL: goto x86_l_68;
	case 109ULL: goto x86_l_6d;
	case 111ULL: goto x86_l_6f;
	case 114ULL: goto x86_l_72;
	case 120ULL: goto x86_l_78;
	case 123ULL: goto x86_l_7b;
	case 128ULL: goto x86_l_80;
	case 134ULL: goto x86_l_86;
	case 144ULL: goto x86_l_90;
	case 152ULL: goto x86_l_98;
	case 162ULL: goto x86_l_a2;
	case 170ULL: goto x86_l_aa;
	case 180ULL: goto x86_l_b4;
	case 188ULL: goto x86_l_bc;
	case 198ULL: goto x86_l_c6;
	case 206ULL: goto x86_l_ce;
	case 216ULL: goto x86_l_d8;
	case 224ULL: goto x86_l_e0;
	case 235ULL: goto x86_l_eb;
	case 243ULL: goto x86_l_f3;
	case 248ULL: goto x86_l_f8;
	case 254ULL: goto x86_l_fe;
	case 261ULL: goto x86_l_105;
	case 268ULL: goto x86_l_10c;
	case 275ULL: goto x86_l_113;
	case 280ULL: goto x86_l_118;
	case 282ULL: goto x86_l_11a;
	case 285ULL: goto x86_l_11d;
	case 287ULL: goto x86_l_11f;
	case 292ULL: goto x86_l_124;
	case 298ULL: goto x86_l_12a;
	case 304ULL: goto x86_l_130;
	case 308ULL: goto x86_l_134;
	case 314ULL: goto x86_l_13a;
	case 319ULL: goto x86_l_13f;
	case 325ULL: goto x86_l_145;
	case 333ULL: goto x86_l_14d;
	case 340ULL: goto x86_l_154;
	case 345ULL: goto x86_l_159;
	case 350ULL: goto x86_l_15e;
	case 352ULL: goto x86_l_160;
	case 355ULL: goto x86_l_163;
	case 361ULL: goto x86_l_169;
	case 364ULL: goto x86_l_16c;
	case 367ULL: goto x86_l_16f;
	case 372ULL: goto x86_l_174;
	case 378ULL: goto x86_l_17a;
	case 384ULL: goto x86_l_180;
	case 394ULL: goto x86_l_18a;
	case 402ULL: goto x86_l_192;
	case 412ULL: goto x86_l_19c;
	case 420ULL: goto x86_l_1a4;
	case 430ULL: goto x86_l_1ae;
	case 438ULL: goto x86_l_1b6;
	case 448ULL: goto x86_l_1c0;
	case 456ULL: goto x86_l_1c8;
	case 464ULL: goto x86_l_1d0;
	case 469ULL: goto x86_l_1d5;
	case 474ULL: goto x86_l_1da;
	case 477ULL: goto x86_l_1dd;
	case 482ULL: goto x86_l_1e2;
	case 484ULL: goto x86_l_1e4;
	case 486ULL: goto x86_l_1e6;
	case 491ULL: goto x86_l_1eb;
	case 498ULL: goto x86_l_1f2;
	case 505ULL: goto x86_l_1f9;
	case 512ULL: goto x86_l_200;
	case 515ULL: goto x86_l_203;
	case 521ULL: goto x86_l_209;
	case 525ULL: goto x86_l_20d;
	case 533ULL: goto x86_l_215;
	case 541ULL: goto x86_l_21d;
	case 549ULL: goto x86_l_225;
	case 556ULL: goto x86_l_22c;
	case 567ULL: goto x86_l_237;
	case 577ULL: goto x86_l_241;
	case 588ULL: goto x86_l_24c;
	case 595ULL: goto x86_l_253;
	case 603ULL: goto x86_l_25b;
	case 608ULL: goto x86_l_260;
	case 615ULL: goto x86_l_267;
	case 622ULL: goto x86_l_26e;
	case 630ULL: goto x86_l_276;
	case 635ULL: goto x86_l_27b;
	case 641ULL: goto x86_l_281;
	case 648ULL: goto x86_l_288;
	case 653ULL: goto x86_l_28d;
	case 658ULL: goto x86_l_292;
	case 660ULL: goto x86_l_294;
	case 663ULL: goto x86_l_297;
	case 669ULL: goto x86_l_29d;
	case 672ULL: goto x86_l_2a0;
	case 677ULL: goto x86_l_2a5;
	case 680ULL: goto x86_l_2a8;
	case 684ULL: goto x86_l_2ac;
	case 688ULL: goto x86_l_2b0;
	case 691ULL: goto x86_l_2b3;
	case 693ULL: goto x86_l_2b5;
	case 696ULL: goto x86_l_2b8;
	case 698ULL: goto x86_l_2ba;
	case 701ULL: goto x86_l_2bd;
	case 707ULL: goto x86_l_2c3;
	case 710ULL: goto x86_l_2c6;
	case 716ULL: goto x86_l_2cc;
	case 719ULL: goto x86_l_2cf;
	case 725ULL: goto x86_l_2d5;
	case 732ULL: goto x86_l_2dc;
	case 737ULL: goto x86_l_2e1;
	case 742ULL: goto x86_l_2e6;
	case 748ULL: goto x86_l_2ec;
	case 754ULL: goto x86_l_2f2;
	case 757ULL: goto x86_l_2f5;
	case 762ULL: goto x86_l_2fa;
	case 765ULL: goto x86_l_2fd;
	case 767ULL: goto x86_l_2ff;
	case 770ULL: goto x86_l_302;
	case 776ULL: goto x86_l_308;
	case 779ULL: goto x86_l_30b;
	case 785ULL: goto x86_l_311;
	case 788ULL: goto x86_l_314;
	case 794ULL: goto x86_l_31a;
	case 801ULL: goto x86_l_321;
	case 806ULL: goto x86_l_326;
	case 809ULL: goto x86_l_329;
	case 811ULL: goto x86_l_32b;
	case 814ULL: goto x86_l_32e;
	case 820ULL: goto x86_l_334;
	case 823ULL: goto x86_l_337;
	case 829ULL: goto x86_l_33d;
	case 836ULL: goto x86_l_344;
	case 841ULL: goto x86_l_349;
	case 844ULL: goto x86_l_34c;
	case 846ULL: goto x86_l_34e;
	case 849ULL: goto x86_l_351;
	case 855ULL: goto x86_l_357;
	case 858ULL: goto x86_l_35a;
	case 864ULL: goto x86_l_360;
	case 871ULL: goto x86_l_367;
	case 876ULL: goto x86_l_36c;
	case 879ULL: goto x86_l_36f;
	case 885ULL: goto x86_l_375;
	case 888ULL: goto x86_l_378;
	case 894ULL: goto x86_l_37e;
	case 901ULL: goto x86_l_385;
	case 906ULL: goto x86_l_38a;
	case 909ULL: goto x86_l_38d;
	case 911ULL: goto x86_l_38f;
	case 914ULL: goto x86_l_392;
	case 920ULL: goto x86_l_398;
	case 927ULL: goto x86_l_39f;
	case 929ULL: goto x86_l_3a1;
	case 932ULL: goto x86_l_3a4;
	case 934ULL: goto x86_l_3a6;
	case 937ULL: goto x86_l_3a9;
	case 943ULL: goto x86_l_3af;
	case 950ULL: goto x86_l_3b6;
	case 952ULL: goto x86_l_3b8;
	case 955ULL: goto x86_l_3bb;
	case 957ULL: goto x86_l_3bd;
	case 960ULL: goto x86_l_3c0;
	case 966ULL: goto x86_l_3c6;
	case 973ULL: goto x86_l_3cd;
	case 975ULL: goto x86_l_3cf;
	case 982ULL: goto x86_l_3d6;
	case 984ULL: goto x86_l_3d8;
	case 991ULL: goto x86_l_3df;
	case 993ULL: goto x86_l_3e1;
	case 1000ULL: goto x86_l_3e8;
	case 1002ULL: goto x86_l_3ea;
	case 1009ULL: goto x86_l_3f1;
	case 1011ULL: goto x86_l_3f3;
	case 1018ULL: goto x86_l_3fa;
	case 1020ULL: goto x86_l_3fc;
	case 1027ULL: goto x86_l_403;
	case 1029ULL: goto x86_l_405;
	case 1036ULL: goto x86_l_40c;
	case 1038ULL: goto x86_l_40e;
	case 1045ULL: goto x86_l_415;
	case 1053ULL: goto x86_l_41d;
	case 1058ULL: goto x86_l_422;
	case 1060ULL: goto x86_l_424;
	case 1063ULL: goto x86_l_427;
	case 1069ULL: goto x86_l_42d;
	case 1072ULL: goto x86_l_430;
	case 1075ULL: goto x86_l_433;
	case 1083ULL: goto x86_l_43b;
	case 1090ULL: goto x86_l_442;
	case 1095ULL: goto x86_l_447;
	case 1100ULL: goto x86_l_44c;
	case 1103ULL: goto x86_l_44f;
	case 1109ULL: goto x86_l_455;
	case 1112ULL: goto x86_l_458;
	case 1119ULL: goto x86_l_45f;
	case 1122ULL: goto x86_l_462;
	case 1128ULL: goto x86_l_468;
	case 1132ULL: goto x86_l_46c;
	case 1134ULL: goto x86_l_46e;
	case 1138ULL: goto x86_l_472;
	case 1143ULL: goto x86_l_477;
	case 1148ULL: goto x86_l_47c;
	case 1151ULL: goto x86_l_47f;
	case 1153ULL: goto x86_l_481;
	case 1156ULL: goto x86_l_484;
	case 1162ULL: goto x86_l_48a;
	case 1166ULL: goto x86_l_48e;
	case 1169ULL: goto x86_l_491;
	case 1174ULL: goto x86_l_496;
	case 1177ULL: goto x86_l_499;
	case 1181ULL: goto x86_l_49d;
	case 1185ULL: goto x86_l_4a1;
	case 1188ULL: goto x86_l_4a4;
	case 1194ULL: goto x86_l_4aa;
	case 1199ULL: goto x86_l_4af;
	case 1201ULL: goto x86_l_4b1;
	case 1205ULL: goto x86_l_4b5;
	case 1210ULL: goto x86_l_4ba;
	case 1215ULL: goto x86_l_4bf;
	case 1218ULL: goto x86_l_4c2;
	case 1220ULL: goto x86_l_4c4;
	case 1223ULL: goto x86_l_4c7;
	case 1229ULL: goto x86_l_4cd;
	case 1233ULL: goto x86_l_4d1;
	case 1237ULL: goto x86_l_4d5;
	case 1242ULL: goto x86_l_4da;
	case 1245ULL: goto x86_l_4dd;
	case 1249ULL: goto x86_l_4e1;
	case 1253ULL: goto x86_l_4e5;
	case 1256ULL: goto x86_l_4e8;
	case 1262ULL: goto x86_l_4ee;
	case 1266ULL: goto x86_l_4f2;
	case 1268ULL: goto x86_l_4f4;
	case 1272ULL: goto x86_l_4f8;
	case 1277ULL: goto x86_l_4fd;
	case 1282ULL: goto x86_l_502;
	case 1285ULL: goto x86_l_505;
	case 1287ULL: goto x86_l_507;
	case 1290ULL: goto x86_l_50a;
	case 1296ULL: goto x86_l_510;
	case 1300ULL: goto x86_l_514;
	case 1303ULL: goto x86_l_517;
	case 1308ULL: goto x86_l_51c;
	case 1311ULL: goto x86_l_51f;
	case 1315ULL: goto x86_l_523;
	case 1319ULL: goto x86_l_527;
	case 1322ULL: goto x86_l_52a;
	case 1328ULL: goto x86_l_530;
	case 1333ULL: goto x86_l_535;
	case 1335ULL: goto x86_l_537;
	case 1339ULL: goto x86_l_53b;
	case 1344ULL: goto x86_l_540;
	case 1349ULL: goto x86_l_545;
	case 1352ULL: goto x86_l_548;
	case 1354ULL: goto x86_l_54a;
	case 1357ULL: goto x86_l_54d;
	case 1363ULL: goto x86_l_553;
	case 1367ULL: goto x86_l_557;
	case 1371ULL: goto x86_l_55b;
	case 1376ULL: goto x86_l_560;
	case 1379ULL: goto x86_l_563;
	case 1383ULL: goto x86_l_567;
	case 1387ULL: goto x86_l_56b;
	case 1390ULL: goto x86_l_56e;
	case 1396ULL: goto x86_l_574;
	case 1400ULL: goto x86_l_578;
	case 1402ULL: goto x86_l_57a;
	case 1406ULL: goto x86_l_57e;
	case 1411ULL: goto x86_l_583;
	case 1416ULL: goto x86_l_588;
	case 1419ULL: goto x86_l_58b;
	case 1421ULL: goto x86_l_58d;
	case 1424ULL: goto x86_l_590;
	case 1430ULL: goto x86_l_596;
	case 1434ULL: goto x86_l_59a;
	case 1437ULL: goto x86_l_59d;
	case 1442ULL: goto x86_l_5a2;
	case 1445ULL: goto x86_l_5a5;
	case 1449ULL: goto x86_l_5a9;
	case 1453ULL: goto x86_l_5ad;
	case 1456ULL: goto x86_l_5b0;
	case 1462ULL: goto x86_l_5b6;
	case 1467ULL: goto x86_l_5bb;
	case 1469ULL: goto x86_l_5bd;
	case 1473ULL: goto x86_l_5c1;
	case 1478ULL: goto x86_l_5c6;
	case 1483ULL: goto x86_l_5cb;
	case 1486ULL: goto x86_l_5ce;
	case 1488ULL: goto x86_l_5d0;
	case 1491ULL: goto x86_l_5d3;
	case 1497ULL: goto x86_l_5d9;
	case 1501ULL: goto x86_l_5dd;
	case 1505ULL: goto x86_l_5e1;
	case 1510ULL: goto x86_l_5e6;
	case 1513ULL: goto x86_l_5e9;
	case 1517ULL: goto x86_l_5ed;
	case 1521ULL: goto x86_l_5f1;
	case 1524ULL: goto x86_l_5f4;
	case 1530ULL: goto x86_l_5fa;
	case 1534ULL: goto x86_l_5fe;
	case 1536ULL: goto x86_l_600;
	case 1540ULL: goto x86_l_604;
	case 1545ULL: goto x86_l_609;
	case 1550ULL: goto x86_l_60e;
	case 1553ULL: goto x86_l_611;
	case 1555ULL: goto x86_l_613;
	case 1558ULL: goto x86_l_616;
	case 1564ULL: goto x86_l_61c;
	case 1568ULL: goto x86_l_620;
	case 1571ULL: goto x86_l_623;
	case 1576ULL: goto x86_l_628;
	case 1579ULL: goto x86_l_62b;
	case 1583ULL: goto x86_l_62f;
	case 1587ULL: goto x86_l_633;
	case 1590ULL: goto x86_l_636;
	case 1596ULL: goto x86_l_63c;
	case 1601ULL: goto x86_l_641;
	case 1603ULL: goto x86_l_643;
	case 1607ULL: goto x86_l_647;
	case 1612ULL: goto x86_l_64c;
	case 1617ULL: goto x86_l_651;
	case 1620ULL: goto x86_l_654;
	case 1622ULL: goto x86_l_656;
	case 1625ULL: goto x86_l_659;
	case 1631ULL: goto x86_l_65f;
	case 1635ULL: goto x86_l_663;
	case 1639ULL: goto x86_l_667;
	case 1644ULL: goto x86_l_66c;
	case 1647ULL: goto x86_l_66f;
	case 1651ULL: goto x86_l_673;
	case 1655ULL: goto x86_l_677;
	case 1658ULL: goto x86_l_67a;
	case 1664ULL: goto x86_l_680;
	case 1668ULL: goto x86_l_684;
	case 1670ULL: goto x86_l_686;
	case 1674ULL: goto x86_l_68a;
	case 1679ULL: goto x86_l_68f;
	case 1684ULL: goto x86_l_694;
	case 1687ULL: goto x86_l_697;
	case 1689ULL: goto x86_l_699;
	case 1692ULL: goto x86_l_69c;
	case 1698ULL: goto x86_l_6a2;
	case 1702ULL: goto x86_l_6a6;
	case 1705ULL: goto x86_l_6a9;
	case 1710ULL: goto x86_l_6ae;
	case 1713ULL: goto x86_l_6b1;
	case 1717ULL: goto x86_l_6b5;
	case 1721ULL: goto x86_l_6b9;
	case 1724ULL: goto x86_l_6bc;
	case 1730ULL: goto x86_l_6c2;
	case 1735ULL: goto x86_l_6c7;
	case 1737ULL: goto x86_l_6c9;
	case 1741ULL: goto x86_l_6cd;
	case 1746ULL: goto x86_l_6d2;
	case 1751ULL: goto x86_l_6d7;
	case 1754ULL: goto x86_l_6da;
	case 1756ULL: goto x86_l_6dc;
	case 1759ULL: goto x86_l_6df;
	case 1765ULL: goto x86_l_6e5;
	case 1769ULL: goto x86_l_6e9;
	case 1773ULL: goto x86_l_6ed;
	case 1778ULL: goto x86_l_6f2;
	case 1781ULL: goto x86_l_6f5;
	case 1785ULL: goto x86_l_6f9;
	case 1789ULL: goto x86_l_6fd;
	case 1792ULL: goto x86_l_700;
	case 1798ULL: goto x86_l_706;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x168 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 360ULL);
x86_l_a:
	/* 0xa: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_18:
	/* 0x18: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&per_cpu_records)));
x86_l_1f:
	/* 0x1f: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
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
	/* 0x31: je     6017 <kprobe_unwind_native+0x6017> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24599ULL;
	}
x86_l_37:
	/* 0x37: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3f:
	/* 0x3f: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_42:
	/* 0x42: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_49:
	/* 0x49: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e:
	/* 0x4e: jne    ebd <kprobe_unwind_native+0xebd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3773ULL;
	}
x86_l_54:
	/* 0x54: mov    DWORD PTR [rsp+0x10],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476741ULL);
x86_l_5c:
	/* 0x5c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_63:
	/* 0x63: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_68:
	/* 0x68: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6d:
	/* 0x6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f:
	/* 0x6f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_72:
	/* 0x72: je     11f <kprobe_unwind_native+0x11f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11f;
	}
x86_l_78:
	/* 0x78: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_7b:
	/* 0x7b: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_80:
	/* 0x80: je     12a <kprobe_unwind_native+0x12a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a;
	}
x86_l_86:
	/* 0x86: movabs rax,0x63617473206e6f20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7161132920309968672ULL);
x86_l_90:
	/* 0x90: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_98:
	/* 0x98: movabs rax,0x7525206e6f697469 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8441188735263536233ULL);
x86_l_a2:
	/* 0xa2: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_aa:
	/* 0xaa: movabs rax,0x736f70206f742078 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8317990321387741304ULL);
x86_l_b4:
	/* 0xb4: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_bc:
	/* 0xbc: movabs rax,0x6c6c2520786c6c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660274970520613ULL);
x86_l_c6:
	/* 0xc6: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_ce:
	/* 0xce: movabs rax,0x20676e6968737550 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334956330817910096ULL);
x86_l_d8:
	/* 0xd8: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_e0:
	/* 0xe0: mov    DWORD PTR [rsp+0xc7],0xa6b63 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 854699174755ULL);
x86_l_eb:
	/* 0xeb: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_f3:
	/* 0xf3: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_f8:
	/* 0xf8: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_fe:
	/* 0xfe: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_105:
	/* 0x105: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_10c:
	/* 0x10c: mov    r8d,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_113:
	/* 0x113: mov    esi,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 43ULL);
x86_l_118:
	/* 0x118: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11a:
	/* 0x11a: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_11d:
	/* 0x11d: jmp    12a <kprobe_unwind_native+0x12a> */
	goto x86_l_12a;
x86_l_11f:
	/* 0x11f: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_124:
	/* 0x124: jne    100c <kprobe_unwind_native+0x100c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4108ULL;
	}
x86_l_12a:
	/* 0x12a: mov    eax,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_130:
	/* 0x130: cmp    rax,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 127ULL);
x86_l_134:
	/* 0x134: jb     1eb <kprobe_unwind_native+0x1eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1eb;
	}
x86_l_13a:
	/* 0x13a: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13f:
	/* 0x13f: jne    f24 <kprobe_unwind_native+0xf24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3876ULL;
	}
x86_l_145:
	/* 0x145: mov    DWORD PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_14d:
	/* 0x14d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_154:
	/* 0x154: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_159:
	/* 0x159: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15e:
	/* 0x15e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_160:
	/* 0x160: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_163:
	/* 0x163: je     2e1 <kprobe_unwind_native+0x2e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e1;
	}
x86_l_169:
	/* 0x169: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_16c:
	/* 0x16c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16f:
	/* 0x16f: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_174:
	/* 0x174: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_17a:
	/* 0x17a: je     5f59 <kprobe_unwind_native+0x5f59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24409ULL;
	}
x86_l_180:
	/* 0x180: movabs rax,0xa656d61726620 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926270227834400ULL);
x86_l_18a:
	/* 0x18a: mov    QWORD PTR [rsp+0xb5],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 181ULL);
x86_l_192:
	/* 0x192: movabs rax,0x7266206576697461 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243311788098679905ULL);
x86_l_19c:
	/* 0x19c: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1a4:
	/* 0x1a4: movabs rax,0x6e2068737570206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7935457388527624303ULL);
x86_l_1ae:
	/* 0x1ae: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1b6:
	/* 0x1b6: movabs rax,0x742064656c696166 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701606ULL);
x86_l_1c0:
	/* 0x1c0: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1c8:
	/* 0x1c8: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1d0:
	/* 0x1d0: mov    eax,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_1d5:
	/* 0x1d5: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1da:
	/* 0x1da: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dd:
	/* 0x1dd: mov    esi,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 29ULL);
x86_l_1e2:
	/* 0x1e2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e4:
	/* 0x1e4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1e6:
	/* 0x1e6: jmp    5f59 <kprobe_unwind_native+0x5f59> */
	return 24409ULL;
x86_l_1eb:
	/* 0x1eb: movzx  ecx,BYTE PTR [rbx+0xf30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3888ULL);
x86_l_1f2:
	/* 0x1f2: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_1f9:
	/* 0x1f9: mov    rsi,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_200:
	/* 0x200: lea    edi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_203:
	/* 0x203: mov    DWORD PTR [rbx+0x2c0],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_209:
	/* 0x209: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_20d:
	/* 0x20d: mov    QWORD PTR [rbx+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_215:
	/* 0x215: mov    QWORD PTR [rbx+rax*8+0x2d8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_21d:
	/* 0x21d: mov    BYTE PTR [rbx+rax*8+0x2e0],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 3161095929859ULL);
x86_l_225:
	/* 0x225: mov    BYTE PTR [rbx+rax*8+0x2e1],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 737ULL);
x86_l_22c:
	/* 0x22c: mov    DWORD PTR [rbx+rax*8+0x2e2],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3169685864448ULL);
x86_l_237:
	/* 0x237: mov    WORD PTR [rbx+rax*8+0x2e6],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3186865733632ULL);
x86_l_241:
	/* 0x241: mov    DWORD PTR [rsp+0x8c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_24c:
	/* 0x24c: mov    rax,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_253:
	/* 0x253: mov    QWORD PTR [rsp+0x160],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_25b:
	/* 0x25b: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_260:
	/* 0x260: mov    rax,0xffffffffffff0000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 18446744073709486080ULL);
x86_l_267:
	/* 0x267: and    rax,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 3864ULL);
x86_l_26e:
	/* 0x26e: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_276:
	/* 0x276: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27b:
	/* 0x27b: jne    f9e <kprobe_unwind_native+0xf9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3998ULL;
	}
x86_l_281:
	/* 0x281: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&stack_delta_page_to_info)));
x86_l_288:
	/* 0x288: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_28d:
	/* 0x28d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_292:
	/* 0x292: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_294:
	/* 0x294: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_297:
	/* 0x297: je     569d <kprobe_unwind_native+0x569d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22173ULL;
	}
x86_l_29d:
	/* 0x29d: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_2a0:
	/* 0x2a0: mov    QWORD PTR [rsp+0x68],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2a5:
	/* 0x2a5: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2a8:
	/* 0x2a8: add    rbp,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_2ac:
	/* 0x2ac: movzx  eax,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_2b0:
	/* 0x2b0: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_2b3:
	/* 0x2b3: jg     2fa <kprobe_unwind_native+0x2fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2fa;
	}
x86_l_2b5:
	/* 0x2b5: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_2b8:
	/* 0x2b8: jg     326 <kprobe_unwind_native+0x326> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_326;
	}
x86_l_2ba:
	/* 0x2ba: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_2bd:
	/* 0x2bd: jg     36c <kprobe_unwind_native+0x36c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_36c;
	}
x86_l_2c3:
	/* 0x2c3: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_2c6:
	/* 0x2c6: je     3cf <kprobe_unwind_native+0x3cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cf;
	}
x86_l_2cc:
	/* 0x2cc: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_2cf:
	/* 0x2cf: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_2d5:
	/* 0x2d5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_9_stack_deltas)));
x86_l_2dc:
	/* 0x2dc: jmp    415 <kprobe_unwind_native+0x415> */
	goto x86_l_415;
x86_l_2e1:
	/* 0x2e1: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e6:
	/* 0x2e6: jne    10a7 <kprobe_unwind_native+0x10a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4263ULL;
	}
x86_l_2ec:
	/* 0x2ec: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_2f2:
	/* 0x2f2: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f5:
	/* 0x2f5: jmp    5f59 <kprobe_unwind_native+0x5f59> */
	return 24409ULL;
x86_l_2fa:
	/* 0x2fa: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_2fd:
	/* 0x2fd: jg     349 <kprobe_unwind_native+0x349> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_349;
	}
x86_l_2ff:
	/* 0x2ff: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_302:
	/* 0x302: jg     38a <kprobe_unwind_native+0x38a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_38a;
	}
x86_l_308:
	/* 0x308: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_30b:
	/* 0x30b: je     3d8 <kprobe_unwind_native+0x3d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d8;
	}
x86_l_311:
	/* 0x311: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_314:
	/* 0x314: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_31a:
	/* 0x31a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_17_stack_deltas)));
x86_l_321:
	/* 0x321: jmp    415 <kprobe_unwind_native+0x415> */
	goto x86_l_415;
x86_l_326:
	/* 0x326: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_329:
	/* 0x329: jg     3a1 <kprobe_unwind_native+0x3a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3a1;
	}
x86_l_32b:
	/* 0x32b: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_32e:
	/* 0x32e: je     3e1 <kprobe_unwind_native+0x3e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e1;
	}
x86_l_334:
	/* 0x334: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_337:
	/* 0x337: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_33d:
	/* 0x33d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_13_stack_deltas)));
x86_l_344:
	/* 0x344: jmp    415 <kprobe_unwind_native+0x415> */
	goto x86_l_415;
x86_l_349:
	/* 0x349: cmp    eax,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_34c:
	/* 0x34c: jg     3b8 <kprobe_unwind_native+0x3b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3b8;
	}
x86_l_34e:
	/* 0x34e: cmp    eax,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 20ULL);
x86_l_351:
	/* 0x351: je     3ea <kprobe_unwind_native+0x3ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea;
	}
x86_l_357:
	/* 0x357: cmp    eax,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_35a:
	/* 0x35a: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_360:
	/* 0x360: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_21_stack_deltas)));
x86_l_367:
	/* 0x367: jmp    415 <kprobe_unwind_native+0x415> */
	goto x86_l_415;
x86_l_36c:
	/* 0x36c: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_36f:
	/* 0x36f: je     3f3 <kprobe_unwind_native+0x3f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f3;
	}
x86_l_375:
	/* 0x375: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_378:
	/* 0x378: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_37e:
	/* 0x37e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_11_stack_deltas)));
x86_l_385:
	/* 0x385: jmp    415 <kprobe_unwind_native+0x415> */
	goto x86_l_415;
x86_l_38a:
	/* 0x38a: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_38d:
	/* 0x38d: je     3fc <kprobe_unwind_native+0x3fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fc;
	}
x86_l_38f:
	/* 0x38f: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_392:
	/* 0x392: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_398:
	/* 0x398: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_19_stack_deltas)));
x86_l_39f:
	/* 0x39f: jmp    415 <kprobe_unwind_native+0x415> */
	goto x86_l_415;
x86_l_3a1:
	/* 0x3a1: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3a4:
	/* 0x3a4: je     405 <kprobe_unwind_native+0x405> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_405;
	}
x86_l_3a6:
	/* 0x3a6: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_3a9:
	/* 0x3a9: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_3af:
	/* 0x3af: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_15_stack_deltas)));
x86_l_3b6:
	/* 0x3b6: jmp    415 <kprobe_unwind_native+0x415> */
	goto x86_l_415;
x86_l_3b8:
	/* 0x3b8: cmp    eax,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 22ULL);
x86_l_3bb:
	/* 0x3bb: je     40e <kprobe_unwind_native+0x40e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40e;
	}
x86_l_3bd:
	/* 0x3bd: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_3c0:
	/* 0x3c0: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_3c6:
	/* 0x3c6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_23_stack_deltas)));
x86_l_3cd:
	/* 0x3cd: jmp    415 <kprobe_unwind_native+0x415> */
	goto x86_l_415;
x86_l_3cf:
	/* 0x3cf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_8_stack_deltas)));
x86_l_3d6:
	/* 0x3d6: jmp    415 <kprobe_unwind_native+0x415> */
	goto x86_l_415;
x86_l_3d8:
	/* 0x3d8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_16_stack_deltas)));
x86_l_3df:
	/* 0x3df: jmp    415 <kprobe_unwind_native+0x415> */
	goto x86_l_415;
x86_l_3e1:
	/* 0x3e1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_12_stack_deltas)));
x86_l_3e8:
	/* 0x3e8: jmp    415 <kprobe_unwind_native+0x415> */
	goto x86_l_415;
x86_l_3ea:
	/* 0x3ea: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_20_stack_deltas)));
x86_l_3f1:
	/* 0x3f1: jmp    415 <kprobe_unwind_native+0x415> */
	goto x86_l_415;
x86_l_3f3:
	/* 0x3f3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_10_stack_deltas)));
x86_l_3fa:
	/* 0x3fa: jmp    415 <kprobe_unwind_native+0x415> */
	goto x86_l_415;
x86_l_3fc:
	/* 0x3fc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_18_stack_deltas)));
x86_l_403:
	/* 0x403: jmp    415 <kprobe_unwind_native+0x415> */
	goto x86_l_415;
x86_l_405:
	/* 0x405: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_14_stack_deltas)));
x86_l_40c:
	/* 0x40c: jmp    415 <kprobe_unwind_native+0x415> */
	goto x86_l_415;
x86_l_40e:
	/* 0x40e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_22_stack_deltas)));
x86_l_415:
	/* 0x415: lea    rsi,[rsp+0x160] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_41d:
	/* 0x41d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_422:
	/* 0x422: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_424:
	/* 0x424: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_427:
	/* 0x427: je     5f24 <kprobe_unwind_native+0x5f24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24356ULL;
	}
x86_l_42d:
	/* 0x42d: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_430:
	/* 0x430: mov    r12d,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_433:
	/* 0x433: mov    DWORD PTR [rsp+0x90],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_43b:
	/* 0x43b: mov    rax,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_442:
	/* 0x442: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_447:
	/* 0x447: movzx  r13d,WORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_44c:
	/* 0x44c: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_44f:
	/* 0x44f: je     89e <kprobe_unwind_native+0x89e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2206ULL;
	}
x86_l_455:
	/* 0x455: add    r13d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_458:
	/* 0x458: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_45f:
	/* 0x45f: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_462:
	/* 0x462: jne    114b <kprobe_unwind_native+0x114b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4427ULL;
	}
x86_l_468:
	/* 0x468: lea    eax,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_46c:
	/* 0x46c: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_46e:
	/* 0x46e: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_472:
	/* 0x472: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_477:
	/* 0x477: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_47c:
	/* 0x47c: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_47f:
	/* 0x47f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_481:
	/* 0x481: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_484:
	/* 0x484: je     962 <kprobe_unwind_native+0x962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2402ULL;
	}
x86_l_48a:
	/* 0x48a: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48e:
	/* 0x48e: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_491:
	/* 0x491: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_496:
	/* 0x496: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_499:
	/* 0x499: cmova  ebp,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R12, X86_WIDTH_32, X86_CC_A);
x86_l_49d:
	/* 0x49d: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_4a1:
	/* 0x4a1: cmp    ebp,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_4a4:
	/* 0x4a4: jae    892 <kprobe_unwind_native+0x892> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2194ULL;
	}
x86_l_4aa:
	/* 0x4aa: lea    eax,[r13+rbp*1+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_4af:
	/* 0x4af: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_4b1:
	/* 0x4b1: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b5:
	/* 0x4b5: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ba:
	/* 0x4ba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4bf:
	/* 0x4bf: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_4c2:
	/* 0x4c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c4:
	/* 0x4c4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4c7:
	/* 0x4c7: je     962 <kprobe_unwind_native+0x962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2402ULL;
	}
x86_l_4cd:
	/* 0x4cd: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d1:
	/* 0x4d1: lea    r12d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4d5:
	/* 0x4d5: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4da:
	/* 0x4da: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dd:
	/* 0x4dd: cmova  r12d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_4e1:
	/* 0x4e1: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_4e5:
	/* 0x4e5: cmp    r12d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R13, X86_WIDTH_32);
x86_l_4e8:
	/* 0x4e8: jae    892 <kprobe_unwind_native+0x892> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2194ULL;
	}
x86_l_4ee:
	/* 0x4ee: lea    eax,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_4f2:
	/* 0x4f2: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_4f4:
	/* 0x4f4: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f8:
	/* 0x4f8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4fd:
	/* 0x4fd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_502:
	/* 0x502: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_505:
	/* 0x505: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_507:
	/* 0x507: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_50a:
	/* 0x50a: je     962 <kprobe_unwind_native+0x962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2402ULL;
	}
x86_l_510:
	/* 0x510: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_514:
	/* 0x514: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_517:
	/* 0x517: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_51c:
	/* 0x51c: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51f:
	/* 0x51f: cmova  ebp,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R12, X86_WIDTH_32, X86_CC_A);
x86_l_523:
	/* 0x523: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_527:
	/* 0x527: cmp    ebp,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_52a:
	/* 0x52a: jae    892 <kprobe_unwind_native+0x892> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2194ULL;
	}
x86_l_530:
	/* 0x530: lea    eax,[r13+rbp*1+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_535:
	/* 0x535: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_537:
	/* 0x537: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_53b:
	/* 0x53b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_540:
	/* 0x540: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_545:
	/* 0x545: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_548:
	/* 0x548: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54a:
	/* 0x54a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_54d:
	/* 0x54d: je     962 <kprobe_unwind_native+0x962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2402ULL;
	}
x86_l_553:
	/* 0x553: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_557:
	/* 0x557: lea    r12d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_55b:
	/* 0x55b: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_560:
	/* 0x560: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_563:
	/* 0x563: cmova  r12d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_567:
	/* 0x567: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_56b:
	/* 0x56b: cmp    r12d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R13, X86_WIDTH_32);
x86_l_56e:
	/* 0x56e: jae    892 <kprobe_unwind_native+0x892> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2194ULL;
	}
x86_l_574:
	/* 0x574: lea    eax,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_578:
	/* 0x578: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_57a:
	/* 0x57a: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_57e:
	/* 0x57e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_583:
	/* 0x583: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_588:
	/* 0x588: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_58b:
	/* 0x58b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58d:
	/* 0x58d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_590:
	/* 0x590: je     962 <kprobe_unwind_native+0x962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2402ULL;
	}
x86_l_596:
	/* 0x596: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_59a:
	/* 0x59a: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_59d:
	/* 0x59d: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5a2:
	/* 0x5a2: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a5:
	/* 0x5a5: cmova  ebp,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R12, X86_WIDTH_32, X86_CC_A);
x86_l_5a9:
	/* 0x5a9: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5ad:
	/* 0x5ad: cmp    ebp,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_5b0:
	/* 0x5b0: jae    892 <kprobe_unwind_native+0x892> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2194ULL;
	}
x86_l_5b6:
	/* 0x5b6: lea    eax,[r13+rbp*1+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_5bb:
	/* 0x5bb: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5bd:
	/* 0x5bd: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c1:
	/* 0x5c1: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c6:
	/* 0x5c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5cb:
	/* 0x5cb: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_5ce:
	/* 0x5ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d0:
	/* 0x5d0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5d3:
	/* 0x5d3: je     962 <kprobe_unwind_native+0x962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2402ULL;
	}
x86_l_5d9:
	/* 0x5d9: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5dd:
	/* 0x5dd: lea    r12d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5e1:
	/* 0x5e1: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5e6:
	/* 0x5e6: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e9:
	/* 0x5e9: cmova  r12d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_5ed:
	/* 0x5ed: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5f1:
	/* 0x5f1: cmp    r12d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R13, X86_WIDTH_32);
x86_l_5f4:
	/* 0x5f4: jae    892 <kprobe_unwind_native+0x892> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2194ULL;
	}
x86_l_5fa:
	/* 0x5fa: lea    eax,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_5fe:
	/* 0x5fe: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_600:
	/* 0x600: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_604:
	/* 0x604: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_609:
	/* 0x609: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_60e:
	/* 0x60e: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_611:
	/* 0x611: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_613:
	/* 0x613: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_616:
	/* 0x616: je     962 <kprobe_unwind_native+0x962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2402ULL;
	}
x86_l_61c:
	/* 0x61c: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_620:
	/* 0x620: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_623:
	/* 0x623: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_628:
	/* 0x628: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62b:
	/* 0x62b: cmova  ebp,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R12, X86_WIDTH_32, X86_CC_A);
x86_l_62f:
	/* 0x62f: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_633:
	/* 0x633: cmp    ebp,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_636:
	/* 0x636: jae    892 <kprobe_unwind_native+0x892> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2194ULL;
	}
x86_l_63c:
	/* 0x63c: lea    eax,[r13+rbp*1+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_641:
	/* 0x641: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_643:
	/* 0x643: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_647:
	/* 0x647: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64c:
	/* 0x64c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_651:
	/* 0x651: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_654:
	/* 0x654: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_656:
	/* 0x656: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_659:
	/* 0x659: je     962 <kprobe_unwind_native+0x962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2402ULL;
	}
x86_l_65f:
	/* 0x65f: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_663:
	/* 0x663: lea    r12d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_667:
	/* 0x667: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_66c:
	/* 0x66c: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66f:
	/* 0x66f: cmova  r12d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_673:
	/* 0x673: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_677:
	/* 0x677: cmp    r12d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R13, X86_WIDTH_32);
x86_l_67a:
	/* 0x67a: jae    892 <kprobe_unwind_native+0x892> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2194ULL;
	}
x86_l_680:
	/* 0x680: lea    eax,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_684:
	/* 0x684: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_686:
	/* 0x686: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_68a:
	/* 0x68a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_68f:
	/* 0x68f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_694:
	/* 0x694: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_697:
	/* 0x697: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_699:
	/* 0x699: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_69c:
	/* 0x69c: je     962 <kprobe_unwind_native+0x962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2402ULL;
	}
x86_l_6a2:
	/* 0x6a2: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6a6:
	/* 0x6a6: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_6a9:
	/* 0x6a9: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6ae:
	/* 0x6ae: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6b1:
	/* 0x6b1: cmova  ebp,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R12, X86_WIDTH_32, X86_CC_A);
x86_l_6b5:
	/* 0x6b5: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_6b9:
	/* 0x6b9: cmp    ebp,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_6bc:
	/* 0x6bc: jae    892 <kprobe_unwind_native+0x892> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2194ULL;
	}
x86_l_6c2:
	/* 0x6c2: lea    eax,[r13+rbp*1+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_6c7:
	/* 0x6c7: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_6c9:
	/* 0x6c9: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6cd:
	/* 0x6cd: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6d2:
	/* 0x6d2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6d7:
	/* 0x6d7: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6da:
	/* 0x6da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6dc:
	/* 0x6dc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6df:
	/* 0x6df: je     962 <kprobe_unwind_native+0x962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2402ULL;
	}
x86_l_6e5:
	/* 0x6e5: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6e9:
	/* 0x6e9: lea    r12d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_6ed:
	/* 0x6ed: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6f2:
	/* 0x6f2: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6f5:
	/* 0x6f5: cmova  r12d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_6f9:
	/* 0x6f9: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_6fd:
	/* 0x6fd: cmp    r12d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R13, X86_WIDTH_32);
x86_l_700:
	/* 0x700: jae    892 <kprobe_unwind_native+0x892> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2194ULL;
	}
x86_l_706:
	/* 0x706: lea    eax,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
	return 1802ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1802ULL: goto x86_l_70a;
	case 1804ULL: goto x86_l_70c;
	case 1808ULL: goto x86_l_710;
	case 1813ULL: goto x86_l_715;
	case 1818ULL: goto x86_l_71a;
	case 1821ULL: goto x86_l_71d;
	case 1823ULL: goto x86_l_71f;
	case 1826ULL: goto x86_l_722;
	case 1832ULL: goto x86_l_728;
	case 1836ULL: goto x86_l_72c;
	case 1839ULL: goto x86_l_72f;
	case 1844ULL: goto x86_l_734;
	case 1847ULL: goto x86_l_737;
	case 1851ULL: goto x86_l_73b;
	case 1855ULL: goto x86_l_73f;
	case 1858ULL: goto x86_l_742;
	case 1864ULL: goto x86_l_748;
	case 1869ULL: goto x86_l_74d;
	case 1871ULL: goto x86_l_74f;
	case 1875ULL: goto x86_l_753;
	case 1880ULL: goto x86_l_758;
	case 1885ULL: goto x86_l_75d;
	case 1888ULL: goto x86_l_760;
	case 1890ULL: goto x86_l_762;
	case 1893ULL: goto x86_l_765;
	case 1899ULL: goto x86_l_76b;
	case 1903ULL: goto x86_l_76f;
	case 1907ULL: goto x86_l_773;
	case 1912ULL: goto x86_l_778;
	case 1915ULL: goto x86_l_77b;
	case 1919ULL: goto x86_l_77f;
	case 1923ULL: goto x86_l_783;
	case 1926ULL: goto x86_l_786;
	case 1932ULL: goto x86_l_78c;
	case 1936ULL: goto x86_l_790;
	case 1938ULL: goto x86_l_792;
	case 1942ULL: goto x86_l_796;
	case 1947ULL: goto x86_l_79b;
	case 1952ULL: goto x86_l_7a0;
	case 1955ULL: goto x86_l_7a3;
	case 1957ULL: goto x86_l_7a5;
	case 1960ULL: goto x86_l_7a8;
	case 1966ULL: goto x86_l_7ae;
	case 1970ULL: goto x86_l_7b2;
	case 1973ULL: goto x86_l_7b5;
	case 1978ULL: goto x86_l_7ba;
	case 1981ULL: goto x86_l_7bd;
	case 1985ULL: goto x86_l_7c1;
	case 1989ULL: goto x86_l_7c5;
	case 1992ULL: goto x86_l_7c8;
	case 1998ULL: goto x86_l_7ce;
	case 2003ULL: goto x86_l_7d3;
	case 2005ULL: goto x86_l_7d5;
	case 2009ULL: goto x86_l_7d9;
	case 2014ULL: goto x86_l_7de;
	case 2019ULL: goto x86_l_7e3;
	case 2022ULL: goto x86_l_7e6;
	case 2024ULL: goto x86_l_7e8;
	case 2027ULL: goto x86_l_7eb;
	case 2033ULL: goto x86_l_7f1;
	case 2037ULL: goto x86_l_7f5;
	case 2041ULL: goto x86_l_7f9;
	case 2046ULL: goto x86_l_7fe;
	case 2049ULL: goto x86_l_801;
	case 2053ULL: goto x86_l_805;
	case 2057ULL: goto x86_l_809;
	case 2060ULL: goto x86_l_80c;
	case 2066ULL: goto x86_l_812;
	case 2070ULL: goto x86_l_816;
	case 2072ULL: goto x86_l_818;
	case 2076ULL: goto x86_l_81c;
	case 2081ULL: goto x86_l_821;
	case 2086ULL: goto x86_l_826;
	case 2089ULL: goto x86_l_829;
	case 2091ULL: goto x86_l_82b;
	case 2094ULL: goto x86_l_82e;
	case 2100ULL: goto x86_l_834;
	case 2104ULL: goto x86_l_838;
	case 2107ULL: goto x86_l_83b;
	case 2112ULL: goto x86_l_840;
	case 2115ULL: goto x86_l_843;
	case 2119ULL: goto x86_l_847;
	case 2123ULL: goto x86_l_84b;
	case 2126ULL: goto x86_l_84e;
	case 2128ULL: goto x86_l_850;
	case 2133ULL: goto x86_l_855;
	case 2135ULL: goto x86_l_857;
	case 2139ULL: goto x86_l_85b;
	case 2144ULL: goto x86_l_860;
	case 2149ULL: goto x86_l_865;
	case 2152ULL: goto x86_l_868;
	case 2154ULL: goto x86_l_86a;
	case 2157ULL: goto x86_l_86d;
	case 2163ULL: goto x86_l_873;
	case 2167ULL: goto x86_l_877;
	case 2170ULL: goto x86_l_87a;
	case 2175ULL: goto x86_l_87f;
	case 2178ULL: goto x86_l_882;
	case 2181ULL: goto x86_l_885;
	case 2185ULL: goto x86_l_889;
	case 2188ULL: goto x86_l_88c;
	case 2194ULL: goto x86_l_892;
	case 2197ULL: goto x86_l_895;
	case 2200ULL: goto x86_l_898;
	case 2206ULL: goto x86_l_89e;
	case 2209ULL: goto x86_l_8a1;
	case 2217ULL: goto x86_l_8a9;
	case 2225ULL: goto x86_l_8b1;
	case 2230ULL: goto x86_l_8b6;
	case 2233ULL: goto x86_l_8b9;
	case 2235ULL: goto x86_l_8bb;
	case 2240ULL: goto x86_l_8c0;
	case 2245ULL: goto x86_l_8c5;
	case 2248ULL: goto x86_l_8c8;
	case 2254ULL: goto x86_l_8ce;
	case 2261ULL: goto x86_l_8d5;
	case 2266ULL: goto x86_l_8da;
	case 2272ULL: goto x86_l_8e0;
	case 2277ULL: goto x86_l_8e5;
	case 2280ULL: goto x86_l_8e8;
	case 2282ULL: goto x86_l_8ea;
	case 2289ULL: goto x86_l_8f1;
	case 2292ULL: goto x86_l_8f4;
	case 2298ULL: goto x86_l_8fa;
	case 2301ULL: goto x86_l_8fd;
	case 2305ULL: goto x86_l_901;
	case 2312ULL: goto x86_l_908;
	case 2318ULL: goto x86_l_90e;
	case 2326ULL: goto x86_l_916;
	case 2332ULL: goto x86_l_91c;
	case 2338ULL: goto x86_l_922;
	case 2344ULL: goto x86_l_928;
	case 2355ULL: goto x86_l_933;
	case 2362ULL: goto x86_l_93a;
	case 2370ULL: goto x86_l_942;
	case 2375ULL: goto x86_l_947;
	case 2377ULL: goto x86_l_949;
	case 2380ULL: goto x86_l_94c;
	case 2386ULL: goto x86_l_952;
	case 2389ULL: goto x86_l_955;
	case 2397ULL: goto x86_l_95d;
	case 2402ULL: goto x86_l_962;
	case 2407ULL: goto x86_l_967;
	case 2412ULL: goto x86_l_96c;
	case 2419ULL: goto x86_l_973;
	case 2422ULL: goto x86_l_976;
	case 2428ULL: goto x86_l_97c;
	case 2438ULL: goto x86_l_986;
	case 2443ULL: goto x86_l_98b;
	case 2453ULL: goto x86_l_995;
	case 2458ULL: goto x86_l_99a;
	case 2468ULL: goto x86_l_9a4;
	case 2473ULL: goto x86_l_9a9;
	case 2483ULL: goto x86_l_9b3;
	case 2488ULL: goto x86_l_9b8;
	case 2498ULL: goto x86_l_9c2;
	case 2503ULL: goto x86_l_9c7;
	case 2511ULL: goto x86_l_9cf;
	case 2516ULL: goto x86_l_9d4;
	case 2521ULL: goto x86_l_9d9;
	case 2526ULL: goto x86_l_9de;
	case 2531ULL: goto x86_l_9e3;
	case 2533ULL: goto x86_l_9e5;
	case 2535ULL: goto x86_l_9e7;
	case 2540ULL: goto x86_l_9ec;
	case 2545ULL: goto x86_l_9f1;
	case 2550ULL: goto x86_l_9f6;
	case 2555ULL: goto x86_l_9fb;
	case 2563ULL: goto x86_l_a03;
	case 2569ULL: goto x86_l_a09;
	case 2576ULL: goto x86_l_a10;
	case 2583ULL: goto x86_l_a17;
	case 2590ULL: goto x86_l_a1e;
	case 2597ULL: goto x86_l_a25;
	case 2604ULL: goto x86_l_a2c;
	case 2611ULL: goto x86_l_a33;
	case 2618ULL: goto x86_l_a3a;
	case 2624ULL: goto x86_l_a40;
	case 2627ULL: goto x86_l_a43;
	case 2632ULL: goto x86_l_a48;
	case 2638ULL: goto x86_l_a4e;
	case 2646ULL: goto x86_l_a56;
	case 2654ULL: goto x86_l_a5e;
	case 2662ULL: goto x86_l_a66;
	case 2670ULL: goto x86_l_a6e;
	case 2677ULL: goto x86_l_a75;
	case 2685ULL: goto x86_l_a7d;
	case 2690ULL: goto x86_l_a82;
	case 2692ULL: goto x86_l_a84;
	case 2695ULL: goto x86_l_a87;
	case 2701ULL: goto x86_l_a8d;
	case 2705ULL: goto x86_l_a91;
	case 2709ULL: goto x86_l_a95;
	case 2711ULL: goto x86_l_a97;
	case 2719ULL: goto x86_l_a9f;
	case 2725ULL: goto x86_l_aa5;
	case 2732ULL: goto x86_l_aac;
	case 2735ULL: goto x86_l_aaf;
	case 2741ULL: goto x86_l_ab5;
	case 2743ULL: goto x86_l_ab7;
	case 2746ULL: goto x86_l_aba;
	case 2749ULL: goto x86_l_abd;
	case 2751ULL: goto x86_l_abf;
	case 2759ULL: goto x86_l_ac7;
	case 2764ULL: goto x86_l_acc;
	case 2766ULL: goto x86_l_ace;
	case 2768ULL: goto x86_l_ad0;
	case 2770ULL: goto x86_l_ad2;
	case 2774ULL: goto x86_l_ad6;
	case 2777ULL: goto x86_l_ad9;
	case 2780ULL: goto x86_l_adc;
	case 2784ULL: goto x86_l_ae0;
	case 2791ULL: goto x86_l_ae7;
	case 2794ULL: goto x86_l_aea;
	case 2800ULL: goto x86_l_af0;
	case 2803ULL: goto x86_l_af3;
	case 2808ULL: goto x86_l_af8;
	case 2814ULL: goto x86_l_afe;
	case 2820ULL: goto x86_l_b04;
	case 2823ULL: goto x86_l_b07;
	case 2829ULL: goto x86_l_b0d;
	case 2832ULL: goto x86_l_b10;
	case 2837ULL: goto x86_l_b15;
	case 2843ULL: goto x86_l_b1b;
	case 2846ULL: goto x86_l_b1e;
	case 2852ULL: goto x86_l_b24;
	case 2860ULL: goto x86_l_b2c;
	case 2868ULL: goto x86_l_b34;
	case 2876ULL: goto x86_l_b3c;
	case 2884ULL: goto x86_l_b44;
	case 2892ULL: goto x86_l_b4c;
	case 2895ULL: goto x86_l_b4f;
	case 2898ULL: goto x86_l_b52;
	case 2902ULL: goto x86_l_b56;
	case 2905ULL: goto x86_l_b59;
	case 2907ULL: goto x86_l_b5b;
	case 2910ULL: goto x86_l_b5e;
	case 2913ULL: goto x86_l_b61;
	case 2917ULL: goto x86_l_b65;
	case 2921ULL: goto x86_l_b69;
	case 2928ULL: goto x86_l_b70;
	case 2931ULL: goto x86_l_b73;
	case 2937ULL: goto x86_l_b79;
	case 2947ULL: goto x86_l_b83;
	case 2952ULL: goto x86_l_b88;
	case 2962ULL: goto x86_l_b92;
	case 2967ULL: goto x86_l_b97;
	case 2972ULL: goto x86_l_b9c;
	case 2977ULL: goto x86_l_ba1;
	case 2982ULL: goto x86_l_ba6;
	case 2987ULL: goto x86_l_bab;
	case 2990ULL: goto x86_l_bae;
	case 2992ULL: goto x86_l_bb0;
	case 2994ULL: goto x86_l_bb2;
	case 2999ULL: goto x86_l_bb7;
	case 3002ULL: goto x86_l_bba;
	case 3007ULL: goto x86_l_bbf;
	case 3013ULL: goto x86_l_bc5;
	case 3016ULL: goto x86_l_bc8;
	case 3022ULL: goto x86_l_bce;
	case 3030ULL: goto x86_l_bd6;
	case 3038ULL: goto x86_l_bde;
	case 3046ULL: goto x86_l_be6;
	case 3054ULL: goto x86_l_bee;
	case 3057ULL: goto x86_l_bf1;
	case 3062ULL: goto x86_l_bf6;
	case 3067ULL: goto x86_l_bfb;
	case 3073ULL: goto x86_l_c01;
	case 3076ULL: goto x86_l_c04;
	case 3081ULL: goto x86_l_c09;
	case 3084ULL: goto x86_l_c0c;
	case 3087ULL: goto x86_l_c0f;
	case 3093ULL: goto x86_l_c15;
	case 3101ULL: goto x86_l_c1d;
	case 3108ULL: goto x86_l_c24;
	case 3112ULL: goto x86_l_c28;
	case 3119ULL: goto x86_l_c2f;
	case 3124ULL: goto x86_l_c34;
	case 3131ULL: goto x86_l_c3b;
	case 3136ULL: goto x86_l_c40;
	case 3143ULL: goto x86_l_c47;
	case 3150ULL: goto x86_l_c4e;
	case 3157ULL: goto x86_l_c55;
	case 3162ULL: goto x86_l_c5a;
	case 3165ULL: goto x86_l_c5d;
	case 3173ULL: goto x86_l_c65;
	case 3178ULL: goto x86_l_c6a;
	case 3181ULL: goto x86_l_c6d;
	case 3184ULL: goto x86_l_c70;
	case 3187ULL: goto x86_l_c73;
	case 3189ULL: goto x86_l_c75;
	case 3193ULL: goto x86_l_c79;
	case 3196ULL: goto x86_l_c7c;
	case 3200ULL: goto x86_l_c80;
	case 3203ULL: goto x86_l_c83;
	case 3207ULL: goto x86_l_c87;
	case 3209ULL: goto x86_l_c89;
	case 3213ULL: goto x86_l_c8d;
	case 3219ULL: goto x86_l_c93;
	case 3227ULL: goto x86_l_c9b;
	case 3231ULL: goto x86_l_c9f;
	case 3233ULL: goto x86_l_ca1;
	case 3238ULL: goto x86_l_ca6;
	case 3241ULL: goto x86_l_ca9;
	case 3245ULL: goto x86_l_cad;
	case 3247ULL: goto x86_l_caf;
	case 3251ULL: goto x86_l_cb3;
	case 3257ULL: goto x86_l_cb9;
	case 3260ULL: goto x86_l_cbc;
	case 3262ULL: goto x86_l_cbe;
	case 3265ULL: goto x86_l_cc1;
	case 3268ULL: goto x86_l_cc4;
	case 3273ULL: goto x86_l_cc9;
	case 3280ULL: goto x86_l_cd0;
	case 3283ULL: goto x86_l_cd3;
	case 3289ULL: goto x86_l_cd9;
	case 3293ULL: goto x86_l_cdd;
	case 3296ULL: goto x86_l_ce0;
	case 3300ULL: goto x86_l_ce4;
	case 3306ULL: goto x86_l_cea;
	case 3314ULL: goto x86_l_cf2;
	case 3317ULL: goto x86_l_cf5;
	case 3323ULL: goto x86_l_cfb;
	case 3331ULL: goto x86_l_d03;
	case 3335ULL: goto x86_l_d07;
	case 3341ULL: goto x86_l_d0d;
	case 3346ULL: goto x86_l_d12;
	case 3349ULL: goto x86_l_d15;
	case 3352ULL: goto x86_l_d18;
	case 3355ULL: goto x86_l_d1b;
	case 3358ULL: goto x86_l_d1e;
	case 3360ULL: goto x86_l_d20;
	case 3366ULL: goto x86_l_d26;
	case 3369ULL: goto x86_l_d29;
	case 3374ULL: goto x86_l_d2e;
	case 3379ULL: goto x86_l_d33;
	case 3384ULL: goto x86_l_d38;
	case 3389ULL: goto x86_l_d3d;
	case 3392ULL: goto x86_l_d40;
	case 3394ULL: goto x86_l_d42;
	case 3397ULL: goto x86_l_d45;
	case 3403ULL: goto x86_l_d4b;
	case 3410ULL: goto x86_l_d52;
	case 3413ULL: goto x86_l_d55;
	case 3421ULL: goto x86_l_d5d;
	case 3426ULL: goto x86_l_d62;
	case 3432ULL: goto x86_l_d68;
	case 3435ULL: goto x86_l_d6b;
	case 3438ULL: goto x86_l_d6e;
	case 3443ULL: goto x86_l_d73;
	case 3451ULL: goto x86_l_d7b;
	case 3459ULL: goto x86_l_d83;
	case 3467ULL: goto x86_l_d8b;
	case 3475ULL: goto x86_l_d93;
	case 3478ULL: goto x86_l_d96;
	case 3482ULL: goto x86_l_d9a;
	case 3490ULL: goto x86_l_da2;
	case 3495ULL: goto x86_l_da7;
	case 3501ULL: goto x86_l_dad;
	case 3509ULL: goto x86_l_db5;
	case 3512ULL: goto x86_l_db8;
	case 3516ULL: goto x86_l_dbc;
	case 3521ULL: goto x86_l_dc1;
	case 3524ULL: goto x86_l_dc4;
	case 3527ULL: goto x86_l_dc7;
	case 3533ULL: goto x86_l_dcd;
	case 3541ULL: goto x86_l_dd5;
	case 3548ULL: goto x86_l_ddc;
	case 3556ULL: goto x86_l_de4;
	case 3563ULL: goto x86_l_deb;
	case 3571ULL: goto x86_l_df3;
	case 3578ULL: goto x86_l_dfa;
	case 3586ULL: goto x86_l_e02;
	case 3593ULL: goto x86_l_e09;
	case 3601ULL: goto x86_l_e11;
	case 3608ULL: goto x86_l_e18;
	case 3616ULL: goto x86_l_e20;
	case 3623ULL: goto x86_l_e27;
	case 3631ULL: goto x86_l_e2f;
	case 3638ULL: goto x86_l_e36;
	case 3646ULL: goto x86_l_e3e;
	case 3653ULL: goto x86_l_e45;
	case 3660ULL: goto x86_l_e4c;
	case 3667ULL: goto x86_l_e53;
	default: return 0xffffffffffffffffULL;
	}
x86_l_70a:
	/* 0x70a: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_70c:
	/* 0x70c: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_710:
	/* 0x710: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_715:
	/* 0x715: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_71a:
	/* 0x71a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_71d:
	/* 0x71d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_71f:
	/* 0x71f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_722:
	/* 0x722: je     962 <kprobe_unwind_native+0x962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_962;
	}
x86_l_728:
	/* 0x728: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_72c:
	/* 0x72c: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_72f:
	/* 0x72f: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_734:
	/* 0x734: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_737:
	/* 0x737: cmova  ebp,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R12, X86_WIDTH_32, X86_CC_A);
x86_l_73b:
	/* 0x73b: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_73f:
	/* 0x73f: cmp    ebp,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_742:
	/* 0x742: jae    892 <kprobe_unwind_native+0x892> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_892;
	}
x86_l_748:
	/* 0x748: lea    eax,[r13+rbp*1+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_74d:
	/* 0x74d: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_74f:
	/* 0x74f: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_753:
	/* 0x753: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_758:
	/* 0x758: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_75d:
	/* 0x75d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_760:
	/* 0x760: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_762:
	/* 0x762: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_765:
	/* 0x765: je     962 <kprobe_unwind_native+0x962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_962;
	}
x86_l_76b:
	/* 0x76b: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_76f:
	/* 0x76f: lea    r12d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_773:
	/* 0x773: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_778:
	/* 0x778: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_77b:
	/* 0x77b: cmova  r12d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_77f:
	/* 0x77f: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_783:
	/* 0x783: cmp    r12d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R13, X86_WIDTH_32);
x86_l_786:
	/* 0x786: jae    892 <kprobe_unwind_native+0x892> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_892;
	}
x86_l_78c:
	/* 0x78c: lea    eax,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_790:
	/* 0x790: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_792:
	/* 0x792: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_796:
	/* 0x796: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_79b:
	/* 0x79b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7a0:
	/* 0x7a0: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_7a3:
	/* 0x7a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a5:
	/* 0x7a5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7a8:
	/* 0x7a8: je     962 <kprobe_unwind_native+0x962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_962;
	}
x86_l_7ae:
	/* 0x7ae: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7b2:
	/* 0x7b2: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_7b5:
	/* 0x7b5: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7ba:
	/* 0x7ba: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7bd:
	/* 0x7bd: cmova  ebp,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R12, X86_WIDTH_32, X86_CC_A);
x86_l_7c1:
	/* 0x7c1: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_7c5:
	/* 0x7c5: cmp    ebp,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_7c8:
	/* 0x7c8: jae    892 <kprobe_unwind_native+0x892> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_892;
	}
x86_l_7ce:
	/* 0x7ce: lea    eax,[r13+rbp*1+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_7d3:
	/* 0x7d3: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_7d5:
	/* 0x7d5: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7d9:
	/* 0x7d9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7de:
	/* 0x7de: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7e3:
	/* 0x7e3: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_7e6:
	/* 0x7e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e8:
	/* 0x7e8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7eb:
	/* 0x7eb: je     962 <kprobe_unwind_native+0x962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_962;
	}
x86_l_7f1:
	/* 0x7f1: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7f5:
	/* 0x7f5: lea    r12d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_7f9:
	/* 0x7f9: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7fe:
	/* 0x7fe: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_801:
	/* 0x801: cmova  r12d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_805:
	/* 0x805: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_809:
	/* 0x809: cmp    r12d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R13, X86_WIDTH_32);
x86_l_80c:
	/* 0x80c: jae    892 <kprobe_unwind_native+0x892> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_892;
	}
x86_l_812:
	/* 0x812: lea    eax,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_816:
	/* 0x816: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_818:
	/* 0x818: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_81c:
	/* 0x81c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_821:
	/* 0x821: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_826:
	/* 0x826: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_829:
	/* 0x829: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_82b:
	/* 0x82b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_82e:
	/* 0x82e: je     962 <kprobe_unwind_native+0x962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_962;
	}
x86_l_834:
	/* 0x834: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_838:
	/* 0x838: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_83b:
	/* 0x83b: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_840:
	/* 0x840: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_843:
	/* 0x843: cmova  ebp,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R12, X86_WIDTH_32, X86_CC_A);
x86_l_847:
	/* 0x847: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_84b:
	/* 0x84b: cmp    ebp,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_84e:
	/* 0x84e: jae    892 <kprobe_unwind_native+0x892> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_892;
	}
x86_l_850:
	/* 0x850: lea    eax,[r13+rbp*1+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_855:
	/* 0x855: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_857:
	/* 0x857: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_85b:
	/* 0x85b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_860:
	/* 0x860: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_865:
	/* 0x865: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_868:
	/* 0x868: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_86a:
	/* 0x86a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_86d:
	/* 0x86d: je     962 <kprobe_unwind_native+0x962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_962;
	}
x86_l_873:
	/* 0x873: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_877:
	/* 0x877: lea    edx,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_87a:
	/* 0x87a: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_87f:
	/* 0x87f: cmp    WORD PTR [rax],si */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_882:
	/* 0x882: cmova  edx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_885:
	/* 0x885: cmova  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_889:
	/* 0x889: cmp    edx,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_88c:
	/* 0x88c: jb     962 <kprobe_unwind_native+0x962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_962;
	}
x86_l_892:
	/* 0x892: mov    r12d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_32);
x86_l_895:
	/* 0x895: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_898:
	/* 0x898: je     962 <kprobe_unwind_native+0x962> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_962;
	}
x86_l_89e:
	/* 0x89e: dec    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_8a1:
	/* 0x8a1: mov    DWORD PTR [rsp+0x90],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8a9:
	/* 0x8a9: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8b1:
	/* 0x8b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8b6:
	/* 0x8b6: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_8b9:
	/* 0x8b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8bb:
	/* 0x8bb: mov    ecx,0xfa4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4004ULL);
x86_l_8c0:
	/* 0x8c0: mov    edx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_8c5:
	/* 0x8c5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8c8:
	/* 0x8c8: je     42e8 <kprobe_unwind_native+0x42e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17128ULL;
	}
x86_l_8ce:
	/* 0x8ce: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_8d5:
	/* 0x8d5: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8da:
	/* 0x8da: jne    11cf <kprobe_unwind_native+0x11cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4559ULL;
	}
x86_l_8e0:
	/* 0x8e0: movzx  ecx,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_8e5:
	/* 0x8e5: movzx  edx,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_8e8:
	/* 0x8e8: sub    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_8ea:
	/* 0x8ea: mov    edx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8f1:
	/* 0x8f1: cmp    edx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_8f4:
	/* 0x8f4: lea    ebp,[rcx+0x10000] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 65536ULL);
x86_l_8fa:
	/* 0x8fa: cmovae ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_8fd:
	/* 0x8fd: movzx  ecx,WORD PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_901:
	/* 0x901: mov    DWORD PTR [rsp+0x8c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_908:
	/* 0x908: cmp    ecx,0x8000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32768ULL);
x86_l_90e:
	/* 0x90e: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_916:
	/* 0x916: je     42de <kprobe_unwind_native+0x42de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17118ULL;
	}
x86_l_91c:
	/* 0x91c: cmp    ecx,0x8001 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32769ULL);
x86_l_922:
	/* 0x922: jne    a10 <kprobe_unwind_native+0xa10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a10;
	}
x86_l_928:
	/* 0x928: mov    DWORD PTR [rsp+0x94],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159815ULL);
x86_l_933:
	/* 0x933: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_93a:
	/* 0x93a: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_942:
	/* 0x942: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_947:
	/* 0x947: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_949:
	/* 0x949: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_94c:
	/* 0x94c: je     9f6 <kprobe_unwind_native+0x9f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9f6;
	}
x86_l_952:
	/* 0x952: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_955:
	/* 0x955: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_95d:
	/* 0x95d: jmp    a09 <kprobe_unwind_native+0xa09> */
	goto x86_l_a09;
x86_l_962:
	/* 0x962: mov    ecx,0xfa3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4003ULL);
x86_l_967:
	/* 0x967: mov    edx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_96c:
	/* 0x96c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_973:
	/* 0x973: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_976:
	/* 0x976: je     42e8 <kprobe_unwind_native+0x42e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17128ULL;
	}
x86_l_97c:
	/* 0x97c: movabs rax,0x6174616420747075 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7022344801646571637ULL);
x86_l_986:
	/* 0x986: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_98b:
	/* 0x98b: movabs rax,0x72726f43202e7370 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8246776201762206576ULL);
x86_l_995:
	/* 0x995: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_99a:
	/* 0x99a: movabs rax,0x657473203631206e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310594677314494574ULL);
x86_l_9a4:
	/* 0x9a4: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9a9:
	/* 0x9a9: movabs rax,0x6920686372616573 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575169349567210867ULL);
x86_l_9b3:
	/* 0x9b3: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9b8:
	/* 0x9b8: movabs rax,0x622064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7070761801744998726ULL);
x86_l_9c2:
	/* 0x9c2: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9c7:
	/* 0x9c7: mov    DWORD PTR [rsp+0x37],0xa3f61 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 236223872865ULL);
x86_l_9cf:
	/* 0x9cf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9d4:
	/* 0x9d4: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_9d9:
	/* 0x9d9: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_9de:
	/* 0x9de: mov    esi,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 43ULL);
x86_l_9e3:
	/* 0x9e3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9e5:
	/* 0x9e5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_9e7:
	/* 0x9e7: mov    edx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_9ec:
	/* 0x9ec: mov    ecx,0xfa3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4003ULL);
x86_l_9f1:
	/* 0x9f1: jmp    42e8 <kprobe_unwind_native+0x42e8> */
	return 17128ULL;
x86_l_9f6:
	/* 0x9f6: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9fb:
	/* 0x9fb: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_a03:
	/* 0xa03: jne    12ce <kprobe_unwind_native+0x12ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4814ULL;
	}
x86_l_a09:
	/* 0xa09: mov    ecx,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_a10:
	/* 0xa10: lea    r12,[rax+0xed0] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_a17:
	/* 0xa17: lea    rdx,[rax+0xee0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_a1e:
	/* 0xa1e: lea    r15,[rax+0xed8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_a25:
	/* 0xa25: lea    rsi,[rax+0xee8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3816ULL);
x86_l_a2c:
	/* 0xa2c: lea    rdi,[rax+0xef0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3824ULL);
x86_l_a33:
	/* 0xa33: lea    r8,[rax+0xef8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3832ULL);
x86_l_a3a:
	/* 0xa3a: add    rax,0xf08 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 3848ULL);
x86_l_a40:
	/* 0xa40: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_a43:
	/* 0xa43: mov    QWORD PTR [rsp+0x60],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a48:
	/* 0xa48: js     af8 <kprobe_unwind_native+0xaf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_af8;
	}
x86_l_a4e:
	/* 0xa4e: mov    QWORD PTR [rsp+0x150],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_a56:
	/* 0xa56: mov    QWORD PTR [rsp+0x148],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_a5e:
	/* 0xa5e: mov    QWORD PTR [rsp+0x138],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_a66:
	/* 0xa66: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_a6e:
	/* 0xa6e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&unwind_info_array)));
x86_l_a75:
	/* 0xa75: lea    rsi,[rsp+0x8c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_a7d:
	/* 0xa7d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a82:
	/* 0xa82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a84:
	/* 0xa84: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a87:
	/* 0xa87: je     6315 <kprobe_unwind_native+0x6315> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25365ULL;
	}
x86_l_a8d:
	/* 0xa8d: mov    r13d,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a91:
	/* 0xa91: movzx  edx,BYTE PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_a95:
	/* 0xa95: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_a97:
	/* 0xa97: mov    QWORD PTR [rsp+0x158],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_a9f:
	/* 0xa9f: je     c5a <kprobe_unwind_native+0xc5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c5a;
	}
x86_l_aa5:
	/* 0xaa5: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_aac:
	/* 0xaac: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aaf:
	/* 0xaaf: jne    125d <kprobe_unwind_native+0x125d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4701ULL;
	}
x86_l_ab5:
	/* 0xab5: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_ab7:
	/* 0xab7: and    cl,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_aba:
	/* 0xaba: movzx  ecx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_abd:
	/* 0xabd: cmp    ebp,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RCX, X86_WIDTH_32);
x86_l_abf:
	/* 0xabf: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ac7:
	/* 0xac7: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_acc:
	/* 0xacc: jl     af0 <kprobe_unwind_native+0xaf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_af0;
	}
x86_l_ace:
	/* 0xace: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ad0:
	/* 0xad0: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_ad2:
	/* 0xad2: setns  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_NS);
x86_l_ad6:
	/* 0xad6: shl    esi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_ad9:
	/* 0xad9: add    r13d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_adc:
	/* 0xadc: add    r13d,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 4294967288ULL);
x86_l_ae0:
	/* 0xae0: mov    rdx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_ae7:
	/* 0xae7: cmp    DWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aea:
	/* 0xaea: jne    134c <kprobe_unwind_native+0x134c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4940ULL;
	}
x86_l_af0:
	/* 0xaf0: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_af3:
	/* 0xaf3: jmp    c6a <kprobe_unwind_native+0xc6a> */
	goto x86_l_c6a;
x86_l_af8:
	/* 0xaf8: and    ecx,0xffff7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294934527ULL);
x86_l_afe:
	/* 0xafe: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_b04:
	/* 0xb04: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b07:
	/* 0xb07: jg     bb7 <kprobe_unwind_native+0xbb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_bb7;
	}
x86_l_b0d:
	/* 0xb0d: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b10:
	/* 0xb10: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b15:
	/* 0xb15: je     6474 <kprobe_unwind_native+0x6474> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25716ULL;
	}
x86_l_b1b:
	/* 0xb1b: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b1e:
	/* 0xb1e: jne    5f4c <kprobe_unwind_native+0x5f4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24396ULL;
	}
x86_l_b24:
	/* 0xb24: mov    QWORD PTR [rsp+0x150],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_b2c:
	/* 0xb2c: mov    QWORD PTR [rsp+0x148],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_b34:
	/* 0xb34: mov    QWORD PTR [rsp+0x138],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_b3c:
	/* 0xb3c: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_b44:
	/* 0xb44: mov    QWORD PTR [rsp+0x158],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_b4c:
	/* 0xb4c: mov    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b4f:
	/* 0xb4f: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_b52:
	/* 0xb52: mov    ecx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b56:
	/* 0xb56: and    ecx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_b59:
	/* 0xb59: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b5b:
	/* 0xb5b: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_b5e:
	/* 0xb5e: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_b61:
	/* 0xb61: lea    r12,[rax+rdx*8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_b65:
	/* 0xb65: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_b69:
	/* 0xb69: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_b70:
	/* 0xb70: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b73:
	/* 0xb73: je     161d <kprobe_unwind_native+0x161d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5661ULL;
	}
x86_l_b79:
	/* 0xb79: movabs rax,0xa786c2578303d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541309ULL);
x86_l_b83:
	/* 0xb83: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b88:
	/* 0xb88: movabs rax,0x616663202c544c50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018406059137322064ULL);
x86_l_b92:
	/* 0xb92: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b97:
	/* 0xb97: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b9c:
	/* 0xb9c: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_ba1:
	/* 0xba1: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_ba6:
	/* 0xba6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_bab:
	/* 0xbab: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_bae:
	/* 0xbae: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bb0:
	/* 0xbb0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_bb2:
	/* 0xbb2: jmp    161d <kprobe_unwind_native+0x161d> */
	return 5661ULL;
x86_l_bb7:
	/* 0xbb7: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_bba:
	/* 0xbba: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_bbf:
	/* 0xbbf: je     d73 <kprobe_unwind_native+0xd73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d73;
	}
x86_l_bc5:
	/* 0xbc5: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_bc8:
	/* 0xbc8: jne    5f4c <kprobe_unwind_native+0x5f4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24396ULL;
	}
x86_l_bce:
	/* 0xbce: mov    QWORD PTR [rsp+0x150],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_bd6:
	/* 0xbd6: mov    QWORD PTR [rsp+0x148],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_bde:
	/* 0xbde: mov    QWORD PTR [rsp+0x138],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_be6:
	/* 0xbe6: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_bee:
	/* 0xbee: mov    rax,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bf1:
	/* 0xbf1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bf6:
	/* 0xbf6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_bfb:
	/* 0xbfb: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_c01:
	/* 0xc01: mov    rdx,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c04:
	/* 0xc04: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_c09:
	/* 0xc09: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_c0c:
	/* 0xc0c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c0f:
	/* 0xc0f: jne    1640 <kprobe_unwind_native+0x1640> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5696ULL;
	}
x86_l_c15:
	/* 0xc15: mov    QWORD PTR [rsp+0x158],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_c1d:
	/* 0xc1d: mov    rax,QWORD PTR [rbx+0xee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_c24:
	/* 0xc24: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_c28:
	/* 0xc28: mov    QWORD PTR [rbx+0xed8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_c2f:
	/* 0xc2f: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c34:
	/* 0xc34: mov    QWORD PTR [rbx+0xee0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_c3b:
	/* 0xc3b: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c40:
	/* 0xc40: mov    QWORD PTR [rbx+0xed0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_c47:
	/* 0xc47: mov    BYTE PTR [rbx+0xf30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16698832846849ULL);
x86_l_c4e:
	/* 0xc4e: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_c55:
	/* 0xc55: jmp    16a1 <kprobe_unwind_native+0x16a1> */
	return 5793ULL;
x86_l_c5a:
	/* 0xc5a: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_c5d:
	/* 0xc5d: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c65:
	/* 0xc65: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c6a:
	/* 0xc6a: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_c6d:
	/* 0xc6d: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_c70:
	/* 0xc70: and    esi,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_c73:
	/* 0xc73: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_c75:
	/* 0xc75: cmovns esi,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R13, X86_WIDTH_32, X86_CC_NS);
x86_l_c79:
	/* 0xc79: mov    r9d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDX, X86_WIDTH_32);
x86_l_c7c:
	/* 0xc7c: and    r9d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_c80:
	/* 0xc80: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c83:
	/* 0xc83: cmp    r9d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 2ULL);
x86_l_c87:
	/* 0xc87: jg     ca6 <kprobe_unwind_native+0xca6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_ca6;
	}
x86_l_c89:
	/* 0xc89: cmp    r9d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 1ULL);
x86_l_c8d:
	/* 0xc8d: je     d15 <kprobe_unwind_native+0xd15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d15;
	}
x86_l_c93:
	/* 0xc93: mov    r8,QWORD PTR [rsp+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_c9b:
	/* 0xc9b: cmp    r9d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 2ULL);
x86_l_c9f:
	/* 0xc9f: je     d12 <kprobe_unwind_native+0xd12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d12;
	}
x86_l_ca1:
	/* 0xca1: jmp    1451 <kprobe_unwind_native+0x1451> */
	return 5201ULL;
x86_l_ca6:
	/* 0xca6: mov    r8,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RDI, X86_WIDTH_64);
x86_l_ca9:
	/* 0xca9: cmp    r9d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 3ULL);
x86_l_cad:
	/* 0xcad: je     d12 <kprobe_unwind_native+0xd12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d12;
	}
x86_l_caf:
	/* 0xcaf: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_cb3:
	/* 0xcb3: jne    1451 <kprobe_unwind_native+0x1451> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5201ULL;
	}
x86_l_cb9:
	/* 0xcb9: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_cbc:
	/* 0xcbc: sar    edx,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_cbe:
	/* 0xcbe: and    edx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_cc1:
	/* 0xcc1: movsxd rdx,edx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RDX, X86_RDX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_cc4:
	/* 0xcc4: mov    QWORD PTR [rsp+0x78],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_cc9:
	/* 0xcc9: mov    rdx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_cd0:
	/* 0xcd0: cmp    DWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cd3:
	/* 0xcd3: jne    13c9 <kprobe_unwind_native+0x13c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5065ULL;
	}
x86_l_cd9:
	/* 0xcd9: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_cdd:
	/* 0xcdd: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ce0:
	/* 0xce0: cmp    r13d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 10ULL);
x86_l_ce4:
	/* 0xce4: jg     1432 <kprobe_unwind_native+0x1432> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 5170ULL;
	}
x86_l_cea:
	/* 0xcea: mov    rdx,QWORD PTR [rsp+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_cf2:
	/* 0xcf2: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_cf5:
	/* 0xcf5: je     1449 <kprobe_unwind_native+0x1449> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5193ULL;
	}
x86_l_cfb:
	/* 0xcfb: mov    rdx,QWORD PTR [rsp+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_d03:
	/* 0xd03: cmp    r13d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 9ULL);
x86_l_d07:
	/* 0xd07: je     1449 <kprobe_unwind_native+0x1449> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5193ULL;
	}
x86_l_d0d:
	/* 0xd0d: jmp    1451 <kprobe_unwind_native+0x1451> */
	return 5201ULL;
x86_l_d12:
	/* 0xd12: mov    r12,QWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d15:
	/* 0xd15: mov    r8,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_64);
x86_l_d18:
	/* 0xd18: movsxd r12,esi */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_R12, X86_RSI, X86_WIDTH_64, X86_WIDTH_32);
x86_l_d1b:
	/* 0xd1b: add    r12,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R8, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d1e:
	/* 0xd1e: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_d20:
	/* 0xd20: jns    1451 <kprobe_unwind_native+0x1451> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 5201ULL;
	}
x86_l_d26:
	/* 0xd26: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_d29:
	/* 0xd29: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_d2e:
	/* 0xd2e: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_d33:
	/* 0xd33: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_d38:
	/* 0xd38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d3d:
	/* 0xd3d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d40:
	/* 0xd40: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d42:
	/* 0xd42: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d45:
	/* 0xd45: je     e98 <kprobe_unwind_native+0xe98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3736ULL;
	}
x86_l_d4b:
	/* 0xd4b: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_d52:
	/* 0xd52: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d55:
	/* 0xd55: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_d5d:
	/* 0xd5d: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_d62:
	/* 0xd62: jne    1afd <kprobe_unwind_native+0x1afd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6909ULL;
	}
x86_l_d68:
	/* 0xd68: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_d6b:
	/* 0xd6b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d6e:
	/* 0xd6e: jmp    1451 <kprobe_unwind_native+0x1451> */
	return 5201ULL;
x86_l_d73:
	/* 0xd73: mov    QWORD PTR [rsp+0x150],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_d7b:
	/* 0xd7b: mov    QWORD PTR [rsp+0x148],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_d83:
	/* 0xd83: mov    QWORD PTR [rsp+0x138],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_d8b:
	/* 0xd8b: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_d93:
	/* 0xd93: mov    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d96:
	/* 0xd96: add    rax,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_d9a:
	/* 0xd9a: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_da2:
	/* 0xda2: mov    ecx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 144ULL);
x86_l_da7:
	/* 0xda7: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_dad:
	/* 0xdad: mov    QWORD PTR [rsp+0x158],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_db5:
	/* 0xdb5: mov    rdx,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_db8:
	/* 0xdb8: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_dbc:
	/* 0xdbc: mov    esi,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 144ULL);
x86_l_dc1:
	/* 0xdc1: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_dc4:
	/* 0xdc4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dc7:
	/* 0xdc7: jne    1640 <kprobe_unwind_native+0x1640> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5696ULL;
	}
x86_l_dcd:
	/* 0xdcd: mov    rax,QWORD PTR [rsp+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_dd5:
	/* 0xdd5: mov    QWORD PTR [rbx+0xee8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3816ULL);
x86_l_ddc:
	/* 0xddc: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_de4:
	/* 0xde4: mov    QWORD PTR [rbx+0xef0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3824ULL);
x86_l_deb:
	/* 0xdeb: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_df3:
	/* 0xdf3: mov    QWORD PTR [rbx+0xef8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3832ULL);
x86_l_dfa:
	/* 0xdfa: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_e02:
	/* 0xe02: mov    QWORD PTR [rbx+0xf00],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3840ULL);
x86_l_e09:
	/* 0xe09: mov    rax,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_e11:
	/* 0xe11: mov    QWORD PTR [rbx+0xf08],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3848ULL);
x86_l_e18:
	/* 0xe18: mov    rax,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_e20:
	/* 0xe20: mov    QWORD PTR [rbx+0xee0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_e27:
	/* 0xe27: mov    rax,QWORD PTR [rsp+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_e2f:
	/* 0xe2f: mov    QWORD PTR [rbx+0xed8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_e36:
	/* 0xe36: mov    rax,QWORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_e3e:
	/* 0xe3e: mov    QWORD PTR [rbx+0xed0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_e45:
	/* 0xe45: mov    BYTE PTR [rbx+0xf30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16698832846848ULL);
x86_l_e4c:
	/* 0xe4c: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_e53:
	/* 0xe53: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 3671ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3671ULL: goto x86_l_e57;
	case 3677ULL: goto x86_l_e5d;
	case 3687ULL: goto x86_l_e67;
	case 3692ULL: goto x86_l_e6c;
	case 3702ULL: goto x86_l_e76;
	case 3707ULL: goto x86_l_e7b;
	case 3712ULL: goto x86_l_e80;
	case 3717ULL: goto x86_l_e85;
	case 3722ULL: goto x86_l_e8a;
	case 3727ULL: goto x86_l_e8f;
	case 3729ULL: goto x86_l_e91;
	case 3731ULL: goto x86_l_e93;
	case 3736ULL: goto x86_l_e98;
	case 3740ULL: goto x86_l_e9c;
	case 3744ULL: goto x86_l_ea0;
	case 3749ULL: goto x86_l_ea5;
	case 3752ULL: goto x86_l_ea8;
	case 3760ULL: goto x86_l_eb0;
	case 3763ULL: goto x86_l_eb3;
	case 3768ULL: goto x86_l_eb8;
	case 3773ULL: goto x86_l_ebd;
	case 3779ULL: goto x86_l_ec3;
	case 3789ULL: goto x86_l_ecd;
	case 3797ULL: goto x86_l_ed5;
	case 3807ULL: goto x86_l_edf;
	case 3815ULL: goto x86_l_ee7;
	case 3825ULL: goto x86_l_ef1;
	case 3833ULL: goto x86_l_ef9;
	case 3844ULL: goto x86_l_f04;
	case 3852ULL: goto x86_l_f0c;
	case 3857ULL: goto x86_l_f11;
	case 3862ULL: goto x86_l_f16;
	case 3867ULL: goto x86_l_f1b;
	case 3869ULL: goto x86_l_f1d;
	case 3871ULL: goto x86_l_f1f;
	case 3876ULL: goto x86_l_f24;
	case 3886ULL: goto x86_l_f2e;
	case 3894ULL: goto x86_l_f36;
	case 3904ULL: goto x86_l_f40;
	case 3912ULL: goto x86_l_f48;
	case 3922ULL: goto x86_l_f52;
	case 3930ULL: goto x86_l_f5a;
	case 3940ULL: goto x86_l_f64;
	case 3948ULL: goto x86_l_f6c;
	case 3958ULL: goto x86_l_f76;
	case 3966ULL: goto x86_l_f7e;
	case 3974ULL: goto x86_l_f86;
	case 3979ULL: goto x86_l_f8b;
	case 3984ULL: goto x86_l_f90;
	case 3989ULL: goto x86_l_f95;
	case 3991ULL: goto x86_l_f97;
	case 3993ULL: goto x86_l_f99;
	case 3998ULL: goto x86_l_f9e;
	case 4008ULL: goto x86_l_fa8;
	case 4013ULL: goto x86_l_fad;
	case 4023ULL: goto x86_l_fb7;
	case 4028ULL: goto x86_l_fbc;
	case 4038ULL: goto x86_l_fc6;
	case 4043ULL: goto x86_l_fcb;
	case 4053ULL: goto x86_l_fd5;
	case 4058ULL: goto x86_l_fda;
	case 4063ULL: goto x86_l_fdf;
	case 4068ULL: goto x86_l_fe4;
	case 4073ULL: goto x86_l_fe9;
	case 4079ULL: goto x86_l_fef;
	case 4086ULL: goto x86_l_ff6;
	case 4093ULL: goto x86_l_ffd;
	case 4098ULL: goto x86_l_1002;
	case 4100ULL: goto x86_l_1004;
	case 4103ULL: goto x86_l_1007;
	case 4108ULL: goto x86_l_100c;
	case 4118ULL: goto x86_l_1016;
	case 4126ULL: goto x86_l_101e;
	case 4136ULL: goto x86_l_1028;
	case 4144ULL: goto x86_l_1030;
	case 4154ULL: goto x86_l_103a;
	case 4162ULL: goto x86_l_1042;
	case 4172ULL: goto x86_l_104c;
	case 4180ULL: goto x86_l_1054;
	case 4190ULL: goto x86_l_105e;
	case 4198ULL: goto x86_l_1066;
	case 4208ULL: goto x86_l_1070;
	case 4216ULL: goto x86_l_1078;
	case 4224ULL: goto x86_l_1080;
	case 4229ULL: goto x86_l_1085;
	case 4234ULL: goto x86_l_108a;
	case 4238ULL: goto x86_l_108e;
	case 4243ULL: goto x86_l_1093;
	case 4245ULL: goto x86_l_1095;
	case 4247ULL: goto x86_l_1097;
	case 4252ULL: goto x86_l_109c;
	case 4258ULL: goto x86_l_10a2;
	case 4263ULL: goto x86_l_10a7;
	case 4273ULL: goto x86_l_10b1;
	case 4281ULL: goto x86_l_10b9;
	case 4291ULL: goto x86_l_10c3;
	case 4299ULL: goto x86_l_10cb;
	case 4309ULL: goto x86_l_10d5;
	case 4317ULL: goto x86_l_10dd;
	case 4327ULL: goto x86_l_10e7;
	case 4335ULL: goto x86_l_10ef;
	case 4345ULL: goto x86_l_10f9;
	case 4353ULL: goto x86_l_1101;
	case 4363ULL: goto x86_l_110b;
	case 4371ULL: goto x86_l_1113;
	case 4379ULL: goto x86_l_111b;
	case 4384ULL: goto x86_l_1120;
	case 4389ULL: goto x86_l_1125;
	case 4393ULL: goto x86_l_1129;
	case 4398ULL: goto x86_l_112e;
	case 4400ULL: goto x86_l_1130;
	case 4402ULL: goto x86_l_1132;
	case 4405ULL: goto x86_l_1135;
	case 4410ULL: goto x86_l_113a;
	case 4416ULL: goto x86_l_1140;
	case 4422ULL: goto x86_l_1146;
	case 4427ULL: goto x86_l_114b;
	case 4437ULL: goto x86_l_1155;
	case 4442ULL: goto x86_l_115a;
	case 4452ULL: goto x86_l_1164;
	case 4457ULL: goto x86_l_1169;
	case 4467ULL: goto x86_l_1173;
	case 4472ULL: goto x86_l_1178;
	case 4482ULL: goto x86_l_1182;
	case 4487ULL: goto x86_l_1187;
	case 4497ULL: goto x86_l_1191;
	case 4502ULL: goto x86_l_1196;
	case 4512ULL: goto x86_l_11a0;
	case 4517ULL: goto x86_l_11a5;
	case 4522ULL: goto x86_l_11aa;
	case 4527ULL: goto x86_l_11af;
	case 4533ULL: goto x86_l_11b5;
	case 4536ULL: goto x86_l_11b8;
	case 4541ULL: goto x86_l_11bd;
	case 4546ULL: goto x86_l_11c2;
	case 4549ULL: goto x86_l_11c5;
	case 4551ULL: goto x86_l_11c7;
	case 4554ULL: goto x86_l_11ca;
	case 4559ULL: goto x86_l_11cf;
	case 4569ULL: goto x86_l_11d9;
	case 4574ULL: goto x86_l_11de;
	case 4584ULL: goto x86_l_11e8;
	case 4589ULL: goto x86_l_11ed;
	case 4599ULL: goto x86_l_11f7;
	case 4604ULL: goto x86_l_11fc;
	case 4614ULL: goto x86_l_1206;
	case 4619ULL: goto x86_l_120b;
	case 4629ULL: goto x86_l_1215;
	case 4634ULL: goto x86_l_121a;
	case 4644ULL: goto x86_l_1224;
	case 4649ULL: goto x86_l_1229;
	case 4654ULL: goto x86_l_122e;
	case 4659ULL: goto x86_l_1233;
	case 4665ULL: goto x86_l_1239;
	case 4672ULL: goto x86_l_1240;
	case 4675ULL: goto x86_l_1243;
	case 4680ULL: goto x86_l_1248;
	case 4685ULL: goto x86_l_124d;
	case 4688ULL: goto x86_l_1250;
	case 4690ULL: goto x86_l_1252;
	case 4693ULL: goto x86_l_1255;
	case 4696ULL: goto x86_l_1258;
	case 4701ULL: goto x86_l_125d;
	case 4711ULL: goto x86_l_1267;
	case 4716ULL: goto x86_l_126c;
	case 4726ULL: goto x86_l_1276;
	case 4731ULL: goto x86_l_127b;
	case 4741ULL: goto x86_l_1285;
	case 4746ULL: goto x86_l_128a;
	case 4756ULL: goto x86_l_1294;
	case 4761ULL: goto x86_l_1299;
	case 4766ULL: goto x86_l_129e;
	case 4771ULL: goto x86_l_12a3;
	case 4776ULL: goto x86_l_12a8;
	case 4782ULL: goto x86_l_12ae;
	case 4786ULL: goto x86_l_12b2;
	case 4791ULL: goto x86_l_12b7;
	case 4793ULL: goto x86_l_12b9;
	case 4796ULL: goto x86_l_12bc;
	case 4798ULL: goto x86_l_12be;
	case 4801ULL: goto x86_l_12c1;
	case 4804ULL: goto x86_l_12c4;
	case 4809ULL: goto x86_l_12c9;
	case 4814ULL: goto x86_l_12ce;
	case 4824ULL: goto x86_l_12d8;
	case 4829ULL: goto x86_l_12dd;
	case 4839ULL: goto x86_l_12e7;
	case 4844ULL: goto x86_l_12ec;
	case 4854ULL: goto x86_l_12f6;
	case 4859ULL: goto x86_l_12fb;
	case 4869ULL: goto x86_l_1305;
	case 4874ULL: goto x86_l_130a;
	case 4884ULL: goto x86_l_1314;
	case 4889ULL: goto x86_l_1319;
	case 4899ULL: goto x86_l_1323;
	case 4904ULL: goto x86_l_1328;
	case 4909ULL: goto x86_l_132d;
	case 4914ULL: goto x86_l_1332;
	case 4919ULL: goto x86_l_1337;
	case 4926ULL: goto x86_l_133e;
	case 4931ULL: goto x86_l_1343;
	case 4933ULL: goto x86_l_1345;
	case 4935ULL: goto x86_l_1347;
	case 4940ULL: goto x86_l_134c;
	case 4943ULL: goto x86_l_134f;
	case 4953ULL: goto x86_l_1359;
	case 4958ULL: goto x86_l_135e;
	case 4968ULL: goto x86_l_1368;
	case 4973ULL: goto x86_l_136d;
	case 4983ULL: goto x86_l_1377;
	case 4988ULL: goto x86_l_137c;
	case 4998ULL: goto x86_l_1386;
	case 5003ULL: goto x86_l_138b;
	case 5008ULL: goto x86_l_1390;
	case 5013ULL: goto x86_l_1395;
	case 5018ULL: goto x86_l_139a;
	case 5024ULL: goto x86_l_13a0;
	case 5031ULL: goto x86_l_13a7;
	case 5036ULL: goto x86_l_13ac;
	case 5039ULL: goto x86_l_13af;
	case 5041ULL: goto x86_l_13b1;
	case 5044ULL: goto x86_l_13b4;
	case 5049ULL: goto x86_l_13b9;
	case 5052ULL: goto x86_l_13bc;
	case 5060ULL: goto x86_l_13c4;
	case 5065ULL: goto x86_l_13c9;
	case 5075ULL: goto x86_l_13d3;
	case 5080ULL: goto x86_l_13d8;
	case 5090ULL: goto x86_l_13e2;
	case 5095ULL: goto x86_l_13e7;
	case 5100ULL: goto x86_l_13ec;
	case 5105ULL: goto x86_l_13f1;
	case 5110ULL: goto x86_l_13f6;
	case 5116ULL: goto x86_l_13fc;
	case 5120ULL: goto x86_l_1400;
	case 5125ULL: goto x86_l_1405;
	case 5130ULL: goto x86_l_140a;
	case 5133ULL: goto x86_l_140d;
	case 5136ULL: goto x86_l_1410;
	case 5138ULL: goto x86_l_1412;
	case 5141ULL: goto x86_l_1415;
	case 5146ULL: goto x86_l_141a;
	case 5149ULL: goto x86_l_141d;
	case 5157ULL: goto x86_l_1425;
	case 5160ULL: goto x86_l_1428;
	case 5164ULL: goto x86_l_142c;
	case 5170ULL: goto x86_l_1432;
	case 5178ULL: goto x86_l_143a;
	case 5182ULL: goto x86_l_143e;
	case 5184ULL: goto x86_l_1440;
	case 5188ULL: goto x86_l_1444;
	case 5190ULL: goto x86_l_1446;
	case 5193ULL: goto x86_l_1449;
	case 5198ULL: goto x86_l_144e;
	case 5201ULL: goto x86_l_1451;
	case 5205ULL: goto x86_l_1455;
	case 5209ULL: goto x86_l_1459;
	case 5212ULL: goto x86_l_145c;
	case 5215ULL: goto x86_l_145f;
	case 5218ULL: goto x86_l_1462;
	case 5222ULL: goto x86_l_1466;
	case 5225ULL: goto x86_l_1469;
	case 5229ULL: goto x86_l_146d;
	case 5233ULL: goto x86_l_1471;
	case 5235ULL: goto x86_l_1473;
	case 5238ULL: goto x86_l_1476;
	case 5242ULL: goto x86_l_147a;
	case 5248ULL: goto x86_l_1480;
	case 5256ULL: goto x86_l_1488;
	case 5260ULL: goto x86_l_148c;
	case 5262ULL: goto x86_l_148e;
	case 5267ULL: goto x86_l_1493;
	case 5270ULL: goto x86_l_1496;
	case 5274ULL: goto x86_l_149a;
	case 5276ULL: goto x86_l_149c;
	case 5280ULL: goto x86_l_14a0;
	case 5286ULL: goto x86_l_14a6;
	case 5289ULL: goto x86_l_14a9;
	case 5291ULL: goto x86_l_14ab;
	case 5294ULL: goto x86_l_14ae;
	case 5297ULL: goto x86_l_14b1;
	case 5302ULL: goto x86_l_14b6;
	case 5309ULL: goto x86_l_14bd;
	case 5312ULL: goto x86_l_14c0;
	case 5318ULL: goto x86_l_14c6;
	case 5322ULL: goto x86_l_14ca;
	case 5326ULL: goto x86_l_14ce;
	case 5332ULL: goto x86_l_14d4;
	case 5340ULL: goto x86_l_14dc;
	case 5343ULL: goto x86_l_14df;
	case 5349ULL: goto x86_l_14e5;
	case 5357ULL: goto x86_l_14ed;
	case 5361ULL: goto x86_l_14f1;
	case 5367ULL: goto x86_l_14f7;
	case 5369ULL: goto x86_l_14f9;
	case 5372ULL: goto x86_l_14fc;
	case 5375ULL: goto x86_l_14ff;
	case 5378ULL: goto x86_l_1502;
	case 5381ULL: goto x86_l_1505;
	case 5387ULL: goto x86_l_150b;
	case 5390ULL: goto x86_l_150e;
	case 5395ULL: goto x86_l_1513;
	case 5400ULL: goto x86_l_1518;
	case 5405ULL: goto x86_l_151d;
	case 5410ULL: goto x86_l_1522;
	case 5413ULL: goto x86_l_1525;
	case 5415ULL: goto x86_l_1527;
	case 5418ULL: goto x86_l_152a;
	case 5420ULL: goto x86_l_152c;
	case 5427ULL: goto x86_l_1533;
	case 5430ULL: goto x86_l_1536;
	case 5433ULL: goto x86_l_1539;
	case 5438ULL: goto x86_l_153e;
	case 5444ULL: goto x86_l_1544;
	case 5449ULL: goto x86_l_1549;
	case 5454ULL: goto x86_l_154e;
	case 5458ULL: goto x86_l_1552;
	case 5462ULL: goto x86_l_1556;
	case 5467ULL: goto x86_l_155b;
	case 5470ULL: goto x86_l_155e;
	case 5473ULL: goto x86_l_1561;
	case 5478ULL: goto x86_l_1566;
	case 5483ULL: goto x86_l_156b;
	case 5493ULL: goto x86_l_1575;
	case 5498ULL: goto x86_l_157a;
	case 5508ULL: goto x86_l_1584;
	case 5513ULL: goto x86_l_1589;
	case 5518ULL: goto x86_l_158e;
	case 5523ULL: goto x86_l_1593;
	case 5528ULL: goto x86_l_1598;
	case 5534ULL: goto x86_l_159e;
	case 5538ULL: goto x86_l_15a2;
	case 5543ULL: goto x86_l_15a7;
	case 5548ULL: goto x86_l_15ac;
	case 5551ULL: goto x86_l_15af;
	case 5554ULL: goto x86_l_15b2;
	case 5556ULL: goto x86_l_15b4;
	case 5559ULL: goto x86_l_15b7;
	case 5564ULL: goto x86_l_15bc;
	case 5567ULL: goto x86_l_15bf;
	case 5575ULL: goto x86_l_15c7;
	case 5579ULL: goto x86_l_15cb;
	case 5585ULL: goto x86_l_15d1;
	case 5593ULL: goto x86_l_15d9;
	case 5597ULL: goto x86_l_15dd;
	case 5599ULL: goto x86_l_15df;
	case 5603ULL: goto x86_l_15e3;
	case 5609ULL: goto x86_l_15e9;
	case 5612ULL: goto x86_l_15ec;
	case 5617ULL: goto x86_l_15f1;
	case 5620ULL: goto x86_l_15f4;
	case 5623ULL: goto x86_l_15f7;
	case 5628ULL: goto x86_l_15fc;
	case 5630ULL: goto x86_l_15fe;
	case 5635ULL: goto x86_l_1603;
	case 5640ULL: goto x86_l_1608;
	case 5645ULL: goto x86_l_160d;
	case 5647ULL: goto x86_l_160f;
	case 5649ULL: goto x86_l_1611;
	case 5652ULL: goto x86_l_1614;
	case 5654ULL: goto x86_l_1616;
	case 5661ULL: goto x86_l_161d;
	case 5664ULL: goto x86_l_1620;
	case 5666ULL: goto x86_l_1622;
	case 5671ULL: goto x86_l_1627;
	case 5676ULL: goto x86_l_162c;
	case 5681ULL: goto x86_l_1631;
	case 5684ULL: goto x86_l_1634;
	case 5689ULL: goto x86_l_1639;
	case 5691ULL: goto x86_l_163b;
	case 5694ULL: goto x86_l_163e;
	case 5696ULL: goto x86_l_1640;
	case 5704ULL: goto x86_l_1648;
	case 5711ULL: goto x86_l_164f;
	case 5716ULL: goto x86_l_1654;
	case 5721ULL: goto x86_l_1659;
	case 5723ULL: goto x86_l_165b;
	case 5726ULL: goto x86_l_165e;
	case 5728ULL: goto x86_l_1660;
	case 5731ULL: goto x86_l_1663;
	case 5737ULL: goto x86_l_1669;
	case 5742ULL: goto x86_l_166e;
	case 5749ULL: goto x86_l_1675;
	case 5752ULL: goto x86_l_1678;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e57:
	/* 0xe57: je     16a1 <kprobe_unwind_native+0x16a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5793ULL;
	}
x86_l_e5d:
	/* 0xe5d: movabs rax,0xa656d61726620 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926270227834400ULL);
x86_l_e67:
	/* 0xe67: mov    QWORD PTR [rsp+0x16],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_e6c:
	/* 0xe6c: movabs rax,0x66206c616e676973 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7359000956843288947ULL);
x86_l_e76:
	/* 0xe76: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e7b:
	/* 0xe7b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e80:
	/* 0xe80: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_e85:
	/* 0xe85: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_e8a:
	/* 0xe8a: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_e8f:
	/* 0xe8f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e91:
	/* 0xe91: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e93:
	/* 0xe93: jmp    16a1 <kprobe_unwind_native+0x16a1> */
	return 5793ULL;
x86_l_e98:
	/* 0xe98: shl    r13d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_e9c:
	/* 0xe9c: and    r13d,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 56ULL);
x86_l_ea0:
	/* 0xea0: add    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_ea5:
	/* 0xea5: mov    r12,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_64);
x86_l_ea8:
	/* 0xea8: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_eb0:
	/* 0xeb0: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_eb3:
	/* 0xeb3: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_eb8:
	/* 0xeb8: jmp    1451 <kprobe_unwind_native+0x1451> */
	goto x86_l_1451;
x86_l_ebd:
	/* 0xebd: mov    edx,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_ec3:
	/* 0xec3: movabs rax,0x3d3d206425206576 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4412718824384652662ULL);
x86_l_ecd:
	/* 0xecd: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_ed5:
	/* 0xed5: movabs rax,0x6974616e5f646e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598805597955583593ULL);
x86_l_edf:
	/* 0xedf: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_ee7:
	/* 0xee7: movabs rax,0x776e75203d3d3d3d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8605944719278423357ULL);
x86_l_ef1:
	/* 0xef1: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_ef9:
	/* 0xef9: mov    DWORD PTR [rsp+0xb8],0xa3d3d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 790274653501ULL);
x86_l_f04:
	/* 0xf04: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_f0c:
	/* 0xf0c: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_f11:
	/* 0xf11: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_f16:
	/* 0xf16: mov    esi,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 28ULL);
x86_l_f1b:
	/* 0xf1b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f1d:
	/* 0xf1d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f1f:
	/* 0xf1f: jmp    54 <kprobe_unwind_native+0x54> */
	return 84ULL;
x86_l_f24:
	/* 0xf24: movabs rax,0xa6c6c75662073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2933962849001587ULL);
x86_l_f2e:
	/* 0xf2e: mov    QWORD PTR [rsp+0xbd],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 189ULL);
x86_l_f36:
	/* 0xf36: movabs rax,0x66207369206b6361 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7359008686476059489ULL);
x86_l_f40:
	/* 0xf40: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_f48:
	/* 0xf48: movabs rax,0x7473203a656d6172 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8391085965903225202ULL);
x86_l_f52:
	/* 0xf52: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_f5a:
	/* 0xf5a: movabs rax,0x662068737570206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358996636224200815ULL);
x86_l_f64:
	/* 0xf64: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_f6c:
	/* 0xf6c: movabs rax,0x7420656c62616e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367799623835807349ULL);
x86_l_f76:
	/* 0xf76: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_f7e:
	/* 0xf7e: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_f86:
	/* 0xf86: mov    eax,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_f8b:
	/* 0xf8b: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_f90:
	/* 0xf90: mov    esi,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 37ULL);
x86_l_f95:
	/* 0xf95: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f97:
	/* 0xf97: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f99:
	/* 0xf99: jmp    145 <kprobe_unwind_native+0x145> */
	return 325ULL;
x86_l_f9e:
	/* 0xf9e: movabs rax,0xa786c253a786c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 754471844735118373ULL);
x86_l_fa8:
	/* 0xfa8: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fad:
	/* 0xfad: movabs rax,0x20726f662061746c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338053640979313772ULL);
x86_l_fb7:
	/* 0xfb7: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fbc:
	/* 0xfbc: movabs rax,0x6564206b63617473 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7306000141102707827ULL);
x86_l_fc6:
	/* 0xfc6: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_fcb:
	/* 0xfcb: movabs rax,0x207075206b6f6f4c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337496988707155788ULL);
x86_l_fd5:
	/* 0xfd5: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fda:
	/* 0xfda: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_fdf:
	/* 0xfdf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fe4:
	/* 0xfe4: mov    eax,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_fe9:
	/* 0xfe9: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_fef:
	/* 0xfef: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_ff6:
	/* 0xff6: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_ffd:
	/* 0xffd: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_1002:
	/* 0x1002: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1004:
	/* 0x1004: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1007:
	/* 0x1007: jmp    281 <kprobe_unwind_native+0x281> */
	return 641ULL;
x86_l_100c:
	/* 0x100c: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1016:
	/* 0x1016: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_101e:
	/* 0x101e: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1028:
	/* 0x1028: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1030:
	/* 0x1030: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_103a:
	/* 0x103a: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1042:
	/* 0x1042: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_104c:
	/* 0x104c: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1054:
	/* 0x1054: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_105e:
	/* 0x105e: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1066:
	/* 0x1066: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1070:
	/* 0x1070: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1078:
	/* 0x1078: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1080:
	/* 0x1080: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1085:
	/* 0x1085: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_108a:
	/* 0x108a: mov    edx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_108e:
	/* 0x108e: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1093:
	/* 0x1093: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1095:
	/* 0x1095: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1097:
	/* 0x1097: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_109c:
	/* 0x109c: je     12a <kprobe_unwind_native+0x12a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 298ULL;
	}
x86_l_10a2:
	/* 0x10a2: jmp    86 <kprobe_unwind_native+0x86> */
	return 134ULL;
x86_l_10a7:
	/* 0x10a7: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_10b1:
	/* 0x10b1: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_10b9:
	/* 0x10b9: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_10c3:
	/* 0x10c3: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_10cb:
	/* 0x10cb: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_10d5:
	/* 0x10d5: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_10dd:
	/* 0x10dd: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_10e7:
	/* 0x10e7: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_10ef:
	/* 0x10ef: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_10f9:
	/* 0x10f9: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1101:
	/* 0x1101: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_110b:
	/* 0x110b: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1113:
	/* 0x1113: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_111b:
	/* 0x111b: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1120:
	/* 0x1120: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1125:
	/* 0x1125: mov    edx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1129:
	/* 0x1129: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_112e:
	/* 0x112e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1130:
	/* 0x1130: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1132:
	/* 0x1132: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1135:
	/* 0x1135: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_113a:
	/* 0x113a: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_1140:
	/* 0x1140: je     5f59 <kprobe_unwind_native+0x5f59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24409ULL;
	}
x86_l_1146:
	/* 0x1146: jmp    180 <kprobe_unwind_native+0x180> */
	return 384ULL;
x86_l_114b:
	/* 0x114b: movabs rax,0xa296425204449 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2860259863446601ULL);
x86_l_1155:
	/* 0x1155: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_115a:
	/* 0x115a: movabs rax,0x70616d2820756c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8097873624099548197ULL);
x86_l_1164:
	/* 0x1164: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1169:
	/* 0x1169: movabs rax,0x206f7420756c2520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414386373920ULL);
x86_l_1173:
	/* 0x1173: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1178:
	/* 0x1178: movabs rax,0x6d6f726620656220 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7885647255504773664ULL);
x86_l_1182:
	/* 0x1182: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1187:
	/* 0x1187: movabs rax,0x646c756f68732073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7236287822631739507ULL);
x86_l_1191:
	/* 0x1191: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1196:
	/* 0x1196: movabs rax,0x6c61767265746e49 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7809653462537629257ULL);
x86_l_11a0:
	/* 0x11a0: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11a5:
	/* 0x11a5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11aa:
	/* 0x11aa: mov    eax,0x30 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 48ULL);
x86_l_11af:
	/* 0x11af: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_11b5:
	/* 0x11b5: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_11b8:
	/* 0x11b8: movzx  r8d,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_11bd:
	/* 0x11bd: mov    esi,0x30 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 48ULL);
x86_l_11c2:
	/* 0x11c2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_11c5:
	/* 0x11c5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11c7:
	/* 0x11c7: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_11ca:
	/* 0x11ca: jmp    468 <kprobe_unwind_native+0x468> */
	return 1128ULL;
x86_l_11cf:
	/* 0x11cf: movabs rcx,0xa6425206f666e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2924860387845742ULL);
x86_l_11d9:
	/* 0x11d9: mov    QWORD PTR [rsp+0x35],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_11de:
	/* 0x11de: movabs rcx,0x6f666e49646e6977 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 8027224647331113335ULL);
x86_l_11e8:
	/* 0x11e8: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11ed:
	/* 0x11ed: movabs rcx,0x6e75202c78257830 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 7959303291813591088ULL);
x86_l_11f7:
	/* 0x11f7: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11fc:
	/* 0x11fc: movabs rcx,0x20776f4c72646461 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2339460905569641569ULL);
x86_l_1206:
	/* 0x1206: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_120b:
	/* 0x120b: movabs rcx,0x202c642520786564 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2318338018810291556ULL);
x86_l_1215:
	/* 0x1215: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_121a:
	/* 0x121a: movabs rcx,0x6e692061746c6564 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 7955925819663869284ULL);
x86_l_1224:
	/* 0x1224: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1229:
	/* 0x1229: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_122e:
	/* 0x122e: mov    ecx,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 45ULL);
x86_l_1233:
	/* 0x1233: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1239:
	/* 0x1239: mov    edx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1240:
	/* 0x1240: movzx  ecx,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1243:
	/* 0x1243: movzx  r8d,WORD PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1248:
	/* 0x1248: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_124d:
	/* 0x124d: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1250:
	/* 0x1250: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1252:
	/* 0x1252: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_1255:
	/* 0x1255: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1258:
	/* 0x1258: jmp    8e0 <kprobe_unwind_native+0x8e0> */
	return 2272ULL;
x86_l_125d:
	/* 0x125d: movabs rcx,0xa78323023252061 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 754408119914012769ULL);
x86_l_1267:
	/* 0x1267: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_126c:
	/* 0x126c: movabs rcx,0x746c656420646567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 8389191686598976871ULL);
x86_l_1276:
	/* 0x1276: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_127b:
	/* 0x127b: movabs rcx,0x72656d202c642520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 8243114677922702624ULL);
x86_l_1285:
	/* 0x1285: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_128a:
	/* 0x128a: movabs rcx,0x6666694472646441 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 7378700782191010881ULL);
x86_l_1294:
	/* 0x1294: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1299:
	/* 0x1299: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_129e:
	/* 0x129e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12a3:
	/* 0x12a3: mov    ecx,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 33ULL);
x86_l_12a8:
	/* 0x12a8: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_12ae:
	/* 0x12ae: movzx  ecx,BYTE PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_12b2:
	/* 0x12b2: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_12b7:
	/* 0x12b7: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_12b9:
	/* 0x12b9: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_12bc:
	/* 0x12bc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12be:
	/* 0x12be: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_12c1:
	/* 0x12c1: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_12c4:
	/* 0x12c4: movzx  edx,BYTE PTR [r14+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_12c9:
	/* 0x12c9: jmp    ab5 <kprobe_unwind_native+0xab5> */
	return 2741ULL;
x86_l_12ce:
	/* 0x12ce: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_12d8:
	/* 0x12d8: mov    QWORD PTR [rsp+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_12dd:
	/* 0x12dd: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_12e7:
	/* 0x12e7: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12ec:
	/* 0x12ec: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_12f6:
	/* 0x12f6: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12fb:
	/* 0x12fb: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1305:
	/* 0x1305: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_130a:
	/* 0x130a: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1314:
	/* 0x1314: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1319:
	/* 0x1319: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1323:
	/* 0x1323: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1328:
	/* 0x1328: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_132d:
	/* 0x132d: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1332:
	/* 0x1332: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1337:
	/* 0x1337: mov    edx,DWORD PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_133e:
	/* 0x133e: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1343:
	/* 0x1343: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1345:
	/* 0x1345: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1347:
	/* 0x1347: jmp    955 <kprobe_unwind_native+0x955> */
	return 2389ULL;
x86_l_134c:
	/* 0x134c: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_134f:
	/* 0x134f: movabs rcx,0xa64253d61746c65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 748764383608597605ULL);
x86_l_1359:
	/* 0x1359: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_135e:
	/* 0x135e: movabs rcx,0x44616663203a6863 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 4927332043248527459ULL);
x86_l_1368:
	/* 0x1368: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_136d:
	/* 0x136d: movabs rcx,0x74616d2061746c65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 8386103966981975141ULL);
x86_l_1377:
	/* 0x1377: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_137c:
	/* 0x137c: movabs rcx,0x642064656772654d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 7214876989737559373ULL);
x86_l_1386:
	/* 0x1386: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_138b:
	/* 0x138b: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1390:
	/* 0x1390: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1395:
	/* 0x1395: mov    ecx,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 33ULL);
x86_l_139a:
	/* 0x139a: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_13a0:
	/* 0x13a0: mov    edx,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_13a7:
	/* 0x13a7: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_13ac:
	/* 0x13ac: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_13af:
	/* 0x13af: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13b1:
	/* 0x13b1: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_13b4:
	/* 0x13b4: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_13b9:
	/* 0x13b9: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_13bc:
	/* 0x13bc: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_13c4:
	/* 0x13c4: jmp    c6a <kprobe_unwind_native+0xc6a> */
	return 3178ULL;
x86_l_13c9:
	/* 0x13c9: movabs rcx,0xa756c252b642572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 753627419551999346ULL);
x86_l_13d3:
	/* 0x13d3: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13d8:
	/* 0x13d8: movabs rcx,0x203a646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2322278983241526901ULL);
x86_l_13e2:
	/* 0x13e2: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13e7:
	/* 0x13e7: mov    BYTE PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_13ec:
	/* 0x13ec: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13f1:
	/* 0x13f1: mov    ecx,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_13f6:
	/* 0x13f6: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_13fc:
	/* 0x13fc: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1400:
	/* 0x1400: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1405:
	/* 0x1405: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_140a:
	/* 0x140a: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_140d:
	/* 0x140d: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1410:
	/* 0x1410: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1412:
	/* 0x1412: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1415:
	/* 0x1415: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_141a:
	/* 0x141a: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_141d:
	/* 0x141d: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1425:
	/* 0x1425: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1428:
	/* 0x1428: cmp    r13d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 10ULL);
x86_l_142c:
	/* 0x142c: jle    cea <kprobe_unwind_native+0xcea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3306ULL;
	}
x86_l_1432:
	/* 0x1432: mov    rdx,QWORD PTR [rsp+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_143a:
	/* 0x143a: cmp    r13d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 11ULL);
x86_l_143e:
	/* 0x143e: je     1449 <kprobe_unwind_native+0x1449> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1449;
	}
x86_l_1440:
	/* 0x1440: cmp    r13d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 15ULL);
x86_l_1444:
	/* 0x1444: jne    1451 <kprobe_unwind_native+0x1451> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1451;
	}
x86_l_1446:
	/* 0x1446: mov    rdx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1449:
	/* 0x1449: mov    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_144e:
	/* 0x144e: add    r12,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1451:
	/* 0x1451: movzx  esi,BYTE PTR [rax+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_1455:
	/* 0x1455: mov    r13d,DWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1459:
	/* 0x1459: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_145c:
	/* 0x145c: and    edx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_145f:
	/* 0x145f: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_1462:
	/* 0x1462: cmovns edx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R13, X86_WIDTH_32, X86_CC_NS);
x86_l_1466:
	/* 0x1466: mov    r9d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RSI, X86_WIDTH_32);
x86_l_1469:
	/* 0x1469: and    r9d,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_146d:
	/* 0x146d: cmp    r9d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 2ULL);
x86_l_1471:
	/* 0x1471: jg     1493 <kprobe_unwind_native+0x1493> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1493;
	}
x86_l_1473:
	/* 0x1473: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_1476:
	/* 0x1476: cmp    r9d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 1ULL);
x86_l_147a:
	/* 0x147a: je     14fc <kprobe_unwind_native+0x14fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14fc;
	}
x86_l_1480:
	/* 0x1480: mov    r8,QWORD PTR [rsp+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_1488:
	/* 0x1488: cmp    r9d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 2ULL);
x86_l_148c:
	/* 0x148c: je     14f9 <kprobe_unwind_native+0x14f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14f9;
	}
x86_l_148e:
	/* 0x148e: jmp    1544 <kprobe_unwind_native+0x1544> */
	goto x86_l_1544;
x86_l_1493:
	/* 0x1493: mov    r8,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RDI, X86_WIDTH_64);
x86_l_1496:
	/* 0x1496: cmp    r9d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 3ULL);
x86_l_149a:
	/* 0x149a: je     14f9 <kprobe_unwind_native+0x14f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14f9;
	}
x86_l_149c:
	/* 0x149c: cmp    r9d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 5ULL);
x86_l_14a0:
	/* 0x14a0: jne    1544 <kprobe_unwind_native+0x1544> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1544;
	}
x86_l_14a6:
	/* 0x14a6: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_14a9:
	/* 0x14a9: sar    edx,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_14ab:
	/* 0x14ab: and    edx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_14ae:
	/* 0x14ae: movsxd rdx,edx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RDX, X86_RDX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_14b1:
	/* 0x14b1: mov    QWORD PTR [rsp+0x78],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_14b6:
	/* 0x14b6: mov    rdx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_14bd:
	/* 0x14bd: cmp    DWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14c0:
	/* 0x14c0: jne    156b <kprobe_unwind_native+0x156b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_156b;
	}
x86_l_14c6:
	/* 0x14c6: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_14ca:
	/* 0x14ca: cmp    r13d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 10ULL);
x86_l_14ce:
	/* 0x14ce: jg     15d1 <kprobe_unwind_native+0x15d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_15d1;
	}
x86_l_14d4:
	/* 0x14d4: mov    rsi,QWORD PTR [rsp+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_14dc:
	/* 0x14dc: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_14df:
	/* 0x14df: je     15ec <kprobe_unwind_native+0x15ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15ec;
	}
x86_l_14e5:
	/* 0x14e5: mov    rsi,QWORD PTR [rsp+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_14ed:
	/* 0x14ed: cmp    r13d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 9ULL);
x86_l_14f1:
	/* 0x14f1: je     15ec <kprobe_unwind_native+0x15ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15ec;
	}
x86_l_14f7:
	/* 0x14f7: jmp    1544 <kprobe_unwind_native+0x1544> */
	goto x86_l_1544;
x86_l_14f9:
	/* 0x14f9: mov    rcx,QWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14fc:
	/* 0x14fc: movsxd rdx,edx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RDX, X86_RDX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_14ff:
	/* 0x14ff: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1502:
	/* 0x1502: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_1505:
	/* 0x1505: jns    15f4 <kprobe_unwind_native+0x15f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_15f4;
	}
x86_l_150b:
	/* 0x150b: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_150e:
	/* 0x150e: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1513:
	/* 0x1513: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1518:
	/* 0x1518: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_151d:
	/* 0x151d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1522:
	/* 0x1522: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_1525:
	/* 0x1525: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1527:
	/* 0x1527: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_152a:
	/* 0x152a: je     154e <kprobe_unwind_native+0x154e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_154e;
	}
x86_l_152c:
	/* 0x152c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1533:
	/* 0x1533: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1536:
	/* 0x1536: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_1539:
	/* 0x1539: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_153e:
	/* 0x153e: jne    1b83 <kprobe_unwind_native+0x1b83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7043ULL;
	}
x86_l_1544:
	/* 0x1544: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1549:
	/* 0x1549: jmp    1611 <kprobe_unwind_native+0x1611> */
	goto x86_l_1611;
x86_l_154e:
	/* 0x154e: shl    r13d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1552:
	/* 0x1552: and    r13d,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 56ULL);
x86_l_1556:
	/* 0x1556: add    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_155b:
	/* 0x155b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_155e:
	/* 0x155e: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_1561:
	/* 0x1561: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1566:
	/* 0x1566: jmp    15f4 <kprobe_unwind_native+0x15f4> */
	goto x86_l_15f4;
x86_l_156b:
	/* 0x156b: movabs rcx,0xa756c252b642572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 753627419551999346ULL);
x86_l_1575:
	/* 0x1575: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_157a:
	/* 0x157a: movabs rcx,0x203a646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2322278983241526901ULL);
x86_l_1584:
	/* 0x1584: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1589:
	/* 0x1589: mov    BYTE PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_158e:
	/* 0x158e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1593:
	/* 0x1593: mov    ecx,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_1598:
	/* 0x1598: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_159e:
	/* 0x159e: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_15a2:
	/* 0x15a2: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_15a7:
	/* 0x15a7: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_15ac:
	/* 0x15ac: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_15af:
	/* 0x15af: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_15b2:
	/* 0x15b2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15b4:
	/* 0x15b4: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_15b7:
	/* 0x15b7: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_15bc:
	/* 0x15bc: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_15bf:
	/* 0x15bf: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_15c7:
	/* 0x15c7: cmp    r13d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 10ULL);
x86_l_15cb:
	/* 0x15cb: jle    14d4 <kprobe_unwind_native+0x14d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_14d4;
	}
x86_l_15d1:
	/* 0x15d1: mov    rsi,QWORD PTR [rsp+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_15d9:
	/* 0x15d9: cmp    r13d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 11ULL);
x86_l_15dd:
	/* 0x15dd: je     15ec <kprobe_unwind_native+0x15ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15ec;
	}
x86_l_15df:
	/* 0x15df: cmp    r13d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 15ULL);
x86_l_15e3:
	/* 0x15e3: jne    1544 <kprobe_unwind_native+0x1544> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1544;
	}
x86_l_15e9:
	/* 0x15e9: mov    rsi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_15ec:
	/* 0x15ec: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_15f1:
	/* 0x15f1: add    rdx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_15f4:
	/* 0x15f4: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_15f7:
	/* 0x15f7: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_15fc:
	/* 0x15fc: je     1611 <kprobe_unwind_native+0x1611> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1611;
	}
x86_l_15fe:
	/* 0x15fe: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1603:
	/* 0x1603: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_1608:
	/* 0x1608: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_160d:
	/* 0x160d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_160f:
	/* 0x160f: jmp    161d <kprobe_unwind_native+0x161d> */
	goto x86_l_161d;
x86_l_1611:
	/* 0x1611: cmp    BYTE PTR [rax],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_1614:
	/* 0x1614: jne    161d <kprobe_unwind_native+0x161d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_161d;
	}
x86_l_1616:
	/* 0x1616: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_161d:
	/* 0x161d: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_1620:
	/* 0x1620: je     1640 <kprobe_unwind_native+0x1640> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1640;
	}
x86_l_1622:
	/* 0x1622: lea    rdx,[r12-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_1627:
	/* 0x1627: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_162c:
	/* 0x162c: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_1631:
	/* 0x1631: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1634:
	/* 0x1634: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1639:
	/* 0x1639: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_163b:
	/* 0x163b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_163e:
	/* 0x163e: je     1689 <kprobe_unwind_native+0x1689> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5769ULL;
	}
x86_l_1640:
	/* 0x1640: mov    DWORD PTR [rsp+0x78],0xe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075534ULL);
x86_l_1648:
	/* 0x1648: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_164f:
	/* 0x164f: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1654:
	/* 0x1654: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1659:
	/* 0x1659: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_165b:
	/* 0x165b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_165e:
	/* 0x165e: je     166e <kprobe_unwind_native+0x166e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_166e;
	}
x86_l_1660:
	/* 0x1660: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1663:
	/* 0x1663: mov    r13d,0xfa7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4007ULL);
x86_l_1669:
	/* 0x1669: jmp    5f4c <kprobe_unwind_native+0x5f4c> */
	return 24396ULL;
x86_l_166e:
	/* 0x166e: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1675:
	/* 0x1675: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1678:
	/* 0x1678: jne    17ae <kprobe_unwind_native+0x17ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6062ULL;
	}
	return 5758ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5758ULL: goto x86_l_167e;
	case 5764ULL: goto x86_l_1684;
	case 5769ULL: goto x86_l_1689;
	case 5776ULL: goto x86_l_1690;
	case 5783ULL: goto x86_l_1697;
	case 5790ULL: goto x86_l_169e;
	case 5793ULL: goto x86_l_16a1;
	case 5801ULL: goto x86_l_16a9;
	case 5808ULL: goto x86_l_16b0;
	case 5813ULL: goto x86_l_16b5;
	case 5818ULL: goto x86_l_16ba;
	case 5820ULL: goto x86_l_16bc;
	case 5823ULL: goto x86_l_16bf;
	case 5829ULL: goto x86_l_16c5;
	case 5832ULL: goto x86_l_16c8;
	case 5834ULL: goto x86_l_16ca;
	case 5838ULL: goto x86_l_16ce;
	case 5844ULL: goto x86_l_16d4;
	case 5854ULL: goto x86_l_16de;
	case 5862ULL: goto x86_l_16e6;
	case 5872ULL: goto x86_l_16f0;
	case 5880ULL: goto x86_l_16f8;
	case 5890ULL: goto x86_l_1702;
	case 5898ULL: goto x86_l_170a;
	case 5908ULL: goto x86_l_1714;
	case 5916ULL: goto x86_l_171c;
	case 5924ULL: goto x86_l_1724;
	case 5929ULL: goto x86_l_1729;
	case 5935ULL: goto x86_l_172f;
	case 5939ULL: goto x86_l_1733;
	case 5947ULL: goto x86_l_173b;
	case 5950ULL: goto x86_l_173e;
	case 5955ULL: goto x86_l_1743;
	case 5958ULL: goto x86_l_1746;
	case 5963ULL: goto x86_l_174b;
	case 5965ULL: goto x86_l_174d;
	case 5968ULL: goto x86_l_1750;
	case 5975ULL: goto x86_l_1757;
	case 5977ULL: goto x86_l_1759;
	case 5979ULL: goto x86_l_175b;
	case 5983ULL: goto x86_l_175f;
	case 5989ULL: goto x86_l_1765;
	case 5991ULL: goto x86_l_1767;
	case 5995ULL: goto x86_l_176b;
	case 5998ULL: goto x86_l_176e;
	case 6004ULL: goto x86_l_1774;
	case 6006ULL: goto x86_l_1776;
	case 6012ULL: goto x86_l_177c;
	case 6015ULL: goto x86_l_177f;
	case 6019ULL: goto x86_l_1783;
	case 6025ULL: goto x86_l_1789;
	case 6032ULL: goto x86_l_1790;
	case 6035ULL: goto x86_l_1793;
	case 6041ULL: goto x86_l_1799;
	case 6051ULL: goto x86_l_17a3;
	case 6057ULL: goto x86_l_17a9;
	case 6062ULL: goto x86_l_17ae;
	case 6072ULL: goto x86_l_17b8;
	case 6077ULL: goto x86_l_17bd;
	case 6087ULL: goto x86_l_17c7;
	case 6092ULL: goto x86_l_17cc;
	case 6102ULL: goto x86_l_17d6;
	case 6107ULL: goto x86_l_17db;
	case 6117ULL: goto x86_l_17e5;
	case 6122ULL: goto x86_l_17ea;
	case 6132ULL: goto x86_l_17f4;
	case 6137ULL: goto x86_l_17f9;
	case 6147ULL: goto x86_l_1803;
	case 6152ULL: goto x86_l_1808;
	case 6157ULL: goto x86_l_180d;
	case 6162ULL: goto x86_l_1812;
	case 6167ULL: goto x86_l_1817;
	case 6171ULL: goto x86_l_181b;
	case 6176ULL: goto x86_l_1820;
	case 6178ULL: goto x86_l_1822;
	case 6180ULL: goto x86_l_1824;
	case 6185ULL: goto x86_l_1829;
	case 6195ULL: goto x86_l_1833;
	case 6203ULL: goto x86_l_183b;
	case 6213ULL: goto x86_l_1845;
	case 6221ULL: goto x86_l_184d;
	case 6231ULL: goto x86_l_1857;
	case 6239ULL: goto x86_l_185f;
	case 6249ULL: goto x86_l_1869;
	case 6257ULL: goto x86_l_1871;
	case 6267ULL: goto x86_l_187b;
	case 6275ULL: goto x86_l_1883;
	case 6285ULL: goto x86_l_188d;
	case 6293ULL: goto x86_l_1895;
	case 6301ULL: goto x86_l_189d;
	case 6309ULL: goto x86_l_18a5;
	case 6314ULL: goto x86_l_18aa;
	case 6319ULL: goto x86_l_18af;
	case 6325ULL: goto x86_l_18b5;
	case 6330ULL: goto x86_l_18ba;
	case 6332ULL: goto x86_l_18bc;
	case 6334ULL: goto x86_l_18be;
	case 6341ULL: goto x86_l_18c5;
	case 6344ULL: goto x86_l_18c8;
	case 6348ULL: goto x86_l_18cc;
	case 6354ULL: goto x86_l_18d2;
	case 6361ULL: goto x86_l_18d9;
	case 6363ULL: goto x86_l_18db;
	case 6370ULL: goto x86_l_18e2;
	case 6373ULL: goto x86_l_18e5;
	case 6379ULL: goto x86_l_18eb;
	case 6389ULL: goto x86_l_18f5;
	case 6395ULL: goto x86_l_18fb;
	case 6400ULL: goto x86_l_1900;
	case 6402ULL: goto x86_l_1902;
	case 6410ULL: goto x86_l_190a;
	case 6416ULL: goto x86_l_1910;
	case 6423ULL: goto x86_l_1917;
	case 6430ULL: goto x86_l_191e;
	case 6435ULL: goto x86_l_1923;
	case 6440ULL: goto x86_l_1928;
	case 6442ULL: goto x86_l_192a;
	case 6445ULL: goto x86_l_192d;
	case 6451ULL: goto x86_l_1933;
	case 6459ULL: goto x86_l_193b;
	case 6469ULL: goto x86_l_1945;
	case 6473ULL: goto x86_l_1949;
	case 6476ULL: goto x86_l_194c;
	case 6479ULL: goto x86_l_194f;
	case 6486ULL: goto x86_l_1956;
	case 6489ULL: goto x86_l_1959;
	case 6496ULL: goto x86_l_1960;
	case 6500ULL: goto x86_l_1964;
	case 6503ULL: goto x86_l_1967;
	case 6506ULL: goto x86_l_196a;
	case 6513ULL: goto x86_l_1971;
	case 6520ULL: goto x86_l_1978;
	case 6523ULL: goto x86_l_197b;
	case 6529ULL: goto x86_l_1981;
	case 6533ULL: goto x86_l_1985;
	case 6539ULL: goto x86_l_198b;
	case 6546ULL: goto x86_l_1992;
	case 6551ULL: goto x86_l_1997;
	case 6558ULL: goto x86_l_199e;
	case 6565ULL: goto x86_l_19a5;
	case 6570ULL: goto x86_l_19aa;
	case 6575ULL: goto x86_l_19af;
	case 6577ULL: goto x86_l_19b1;
	case 6583ULL: goto x86_l_19b7;
	case 6586ULL: goto x86_l_19ba;
	case 6592ULL: goto x86_l_19c0;
	case 6595ULL: goto x86_l_19c3;
	case 6598ULL: goto x86_l_19c6;
	case 6600ULL: goto x86_l_19c8;
	case 6604ULL: goto x86_l_19cc;
	case 6606ULL: goto x86_l_19ce;
	case 6610ULL: goto x86_l_19d2;
	case 6616ULL: goto x86_l_19d8;
	case 6620ULL: goto x86_l_19dc;
	case 6626ULL: goto x86_l_19e2;
	case 6633ULL: goto x86_l_19e9;
	case 6636ULL: goto x86_l_19ec;
	case 6642ULL: goto x86_l_19f2;
	case 6648ULL: goto x86_l_19f8;
	case 6652ULL: goto x86_l_19fc;
	case 6655ULL: goto x86_l_19ff;
	case 6661ULL: goto x86_l_1a05;
	case 6668ULL: goto x86_l_1a0c;
	case 6671ULL: goto x86_l_1a0f;
	case 6677ULL: goto x86_l_1a15;
	case 6687ULL: goto x86_l_1a1f;
	case 6695ULL: goto x86_l_1a27;
	case 6705ULL: goto x86_l_1a31;
	case 6713ULL: goto x86_l_1a39;
	case 6723ULL: goto x86_l_1a43;
	case 6731ULL: goto x86_l_1a4b;
	case 6742ULL: goto x86_l_1a56;
	case 6750ULL: goto x86_l_1a5e;
	case 6755ULL: goto x86_l_1a63;
	case 6760ULL: goto x86_l_1a68;
	case 6765ULL: goto x86_l_1a6d;
	case 6767ULL: goto x86_l_1a6f;
	case 6769ULL: goto x86_l_1a71;
	case 6774ULL: goto x86_l_1a76;
	case 6784ULL: goto x86_l_1a80;
	case 6789ULL: goto x86_l_1a85;
	case 6799ULL: goto x86_l_1a8f;
	case 6804ULL: goto x86_l_1a94;
	case 6814ULL: goto x86_l_1a9e;
	case 6819ULL: goto x86_l_1aa3;
	case 6829ULL: goto x86_l_1aad;
	case 6834ULL: goto x86_l_1ab2;
	case 6844ULL: goto x86_l_1abc;
	case 6849ULL: goto x86_l_1ac1;
	case 6859ULL: goto x86_l_1acb;
	case 6864ULL: goto x86_l_1ad0;
	case 6869ULL: goto x86_l_1ad5;
	case 6874ULL: goto x86_l_1ada;
	case 6879ULL: goto x86_l_1adf;
	case 6883ULL: goto x86_l_1ae3;
	case 6888ULL: goto x86_l_1ae8;
	case 6890ULL: goto x86_l_1aea;
	case 6892ULL: goto x86_l_1aec;
	case 6894ULL: goto x86_l_1aee;
	case 6898ULL: goto x86_l_1af2;
	case 6904ULL: goto x86_l_1af8;
	case 6909ULL: goto x86_l_1afd;
	case 6919ULL: goto x86_l_1b07;
	case 6924ULL: goto x86_l_1b0c;
	case 6934ULL: goto x86_l_1b16;
	case 6939ULL: goto x86_l_1b1b;
	case 6949ULL: goto x86_l_1b25;
	case 6954ULL: goto x86_l_1b2a;
	case 6964ULL: goto x86_l_1b34;
	case 6969ULL: goto x86_l_1b39;
	case 6979ULL: goto x86_l_1b43;
	case 6984ULL: goto x86_l_1b48;
	case 6992ULL: goto x86_l_1b50;
	case 6997ULL: goto x86_l_1b55;
	case 7002ULL: goto x86_l_1b5a;
	case 7007ULL: goto x86_l_1b5f;
	case 7012ULL: goto x86_l_1b64;
	case 7015ULL: goto x86_l_1b67;
	case 7017ULL: goto x86_l_1b69;
	case 7019ULL: goto x86_l_1b6b;
	case 7024ULL: goto x86_l_1b70;
	case 7027ULL: goto x86_l_1b73;
	case 7035ULL: goto x86_l_1b7b;
	case 7038ULL: goto x86_l_1b7e;
	case 7043ULL: goto x86_l_1b83;
	case 7053ULL: goto x86_l_1b8d;
	case 7058ULL: goto x86_l_1b92;
	case 7068ULL: goto x86_l_1b9c;
	case 7073ULL: goto x86_l_1ba1;
	case 7083ULL: goto x86_l_1bab;
	case 7088ULL: goto x86_l_1bb0;
	case 7098ULL: goto x86_l_1bba;
	case 7103ULL: goto x86_l_1bbf;
	case 7113ULL: goto x86_l_1bc9;
	case 7118ULL: goto x86_l_1bce;
	case 7126ULL: goto x86_l_1bd6;
	case 7131ULL: goto x86_l_1bdb;
	case 7136ULL: goto x86_l_1be0;
	case 7141ULL: goto x86_l_1be5;
	case 7146ULL: goto x86_l_1bea;
	case 7149ULL: goto x86_l_1bed;
	case 7151ULL: goto x86_l_1bef;
	case 7153ULL: goto x86_l_1bf1;
	case 7158ULL: goto x86_l_1bf6;
	case 7161ULL: goto x86_l_1bf9;
	case 7166ULL: goto x86_l_1bfe;
	case 7176ULL: goto x86_l_1c08;
	case 7184ULL: goto x86_l_1c10;
	case 7194ULL: goto x86_l_1c1a;
	case 7202ULL: goto x86_l_1c22;
	case 7212ULL: goto x86_l_1c2c;
	case 7220ULL: goto x86_l_1c34;
	case 7230ULL: goto x86_l_1c3e;
	case 7238ULL: goto x86_l_1c46;
	case 7248ULL: goto x86_l_1c50;
	case 7256ULL: goto x86_l_1c58;
	case 7266ULL: goto x86_l_1c62;
	case 7274ULL: goto x86_l_1c6a;
	case 7284ULL: goto x86_l_1c74;
	case 7292ULL: goto x86_l_1c7c;
	case 7297ULL: goto x86_l_1c81;
	case 7303ULL: goto x86_l_1c87;
	case 7310ULL: goto x86_l_1c8e;
	case 7315ULL: goto x86_l_1c93;
	case 7318ULL: goto x86_l_1c96;
	case 7321ULL: goto x86_l_1c99;
	case 7323ULL: goto x86_l_1c9b;
	case 7326ULL: goto x86_l_1c9e;
	case 7333ULL: goto x86_l_1ca5;
	case 7336ULL: goto x86_l_1ca8;
	case 7342ULL: goto x86_l_1cae;
	case 7352ULL: goto x86_l_1cb8;
	case 7360ULL: goto x86_l_1cc0;
	case 7370ULL: goto x86_l_1cca;
	case 7378ULL: goto x86_l_1cd2;
	case 7388ULL: goto x86_l_1cdc;
	case 7396ULL: goto x86_l_1ce4;
	case 7406ULL: goto x86_l_1cee;
	case 7414ULL: goto x86_l_1cf6;
	case 7424ULL: goto x86_l_1d00;
	case 7432ULL: goto x86_l_1d08;
	case 7440ULL: goto x86_l_1d10;
	case 7448ULL: goto x86_l_1d18;
	case 7453ULL: goto x86_l_1d1d;
	case 7459ULL: goto x86_l_1d23;
	case 7466ULL: goto x86_l_1d2a;
	case 7473ULL: goto x86_l_1d31;
	case 7478ULL: goto x86_l_1d36;
	case 7480ULL: goto x86_l_1d38;
	case 7483ULL: goto x86_l_1d3b;
	case 7488ULL: goto x86_l_1d40;
	case 7498ULL: goto x86_l_1d4a;
	case 7506ULL: goto x86_l_1d52;
	case 7516ULL: goto x86_l_1d5c;
	case 7524ULL: goto x86_l_1d64;
	case 7534ULL: goto x86_l_1d6e;
	case 7542ULL: goto x86_l_1d76;
	case 7552ULL: goto x86_l_1d80;
	case 7560ULL: goto x86_l_1d88;
	case 7568ULL: goto x86_l_1d90;
	case 7573ULL: goto x86_l_1d95;
	case 7578ULL: goto x86_l_1d9a;
	case 7583ULL: goto x86_l_1d9f;
	case 7588ULL: goto x86_l_1da4;
	case 7590ULL: goto x86_l_1da6;
	case 7592ULL: goto x86_l_1da8;
	case 7598ULL: goto x86_l_1dae;
	case 7602ULL: goto x86_l_1db2;
	case 7605ULL: goto x86_l_1db5;
	case 7611ULL: goto x86_l_1dbb;
	case 7619ULL: goto x86_l_1dc3;
	case 7626ULL: goto x86_l_1dca;
	case 7631ULL: goto x86_l_1dcf;
	case 7636ULL: goto x86_l_1dd4;
	case 7638ULL: goto x86_l_1dd6;
	case 7641ULL: goto x86_l_1dd9;
	case 7643ULL: goto x86_l_1ddb;
	case 7646ULL: goto x86_l_1dde;
	case 7648ULL: goto x86_l_1de0;
	case 7655ULL: goto x86_l_1de7;
	case 7658ULL: goto x86_l_1dea;
	case 7664ULL: goto x86_l_1df0;
	case 7669ULL: goto x86_l_1df5;
	case 7674ULL: goto x86_l_1dfa;
	case 7677ULL: goto x86_l_1dfd;
	case 7681ULL: goto x86_l_1e01;
	case 7688ULL: goto x86_l_1e08;
	case 7694ULL: goto x86_l_1e0e;
	case 7699ULL: goto x86_l_1e13;
	case 7705ULL: goto x86_l_1e19;
	case 7713ULL: goto x86_l_1e21;
	case 7720ULL: goto x86_l_1e28;
	case 7725ULL: goto x86_l_1e2d;
	case 7730ULL: goto x86_l_1e32;
	case 7732ULL: goto x86_l_1e34;
	case 7735ULL: goto x86_l_1e37;
	case 7741ULL: goto x86_l_1e3d;
	case 7744ULL: goto x86_l_1e40;
	case 7749ULL: goto x86_l_1e45;
	case 7755ULL: goto x86_l_1e4b;
	case 7765ULL: goto x86_l_1e55;
	case 7773ULL: goto x86_l_1e5d;
	case 7783ULL: goto x86_l_1e67;
	case 7791ULL: goto x86_l_1e6f;
	case 7801ULL: goto x86_l_1e79;
	case 7809ULL: goto x86_l_1e81;
	case 7819ULL: goto x86_l_1e8b;
	case 7827ULL: goto x86_l_1e93;
	case 7837ULL: goto x86_l_1e9d;
	case 7845ULL: goto x86_l_1ea5;
	case 7856ULL: goto x86_l_1eb0;
	case 7864ULL: goto x86_l_1eb8;
	case 7869ULL: goto x86_l_1ebd;
	case 7875ULL: goto x86_l_1ec3;
	case 7882ULL: goto x86_l_1eca;
	case 7889ULL: goto x86_l_1ed1;
	case 7896ULL: goto x86_l_1ed8;
	case 7901ULL: goto x86_l_1edd;
	case 7903ULL: goto x86_l_1edf;
	case 7906ULL: goto x86_l_1ee2;
	case 7908ULL: goto x86_l_1ee4;
	case 7913ULL: goto x86_l_1ee9;
	case 7919ULL: goto x86_l_1eef;
	case 7925ULL: goto x86_l_1ef5;
	case 7929ULL: goto x86_l_1ef9;
	case 7935ULL: goto x86_l_1eff;
	case 7942ULL: goto x86_l_1f06;
	case 7949ULL: goto x86_l_1f0d;
	case 7956ULL: goto x86_l_1f14;
	case 7959ULL: goto x86_l_1f17;
	case 7965ULL: goto x86_l_1f1d;
	case 7969ULL: goto x86_l_1f21;
	case 7977ULL: goto x86_l_1f29;
	case 7985ULL: goto x86_l_1f31;
	case 7993ULL: goto x86_l_1f39;
	case 8000ULL: goto x86_l_1f40;
	case 8011ULL: goto x86_l_1f4b;
	case 8021ULL: goto x86_l_1f55;
	case 8032ULL: goto x86_l_1f60;
	case 8039ULL: goto x86_l_1f67;
	case 8047ULL: goto x86_l_1f6f;
	case 8052ULL: goto x86_l_1f74;
	case 8059ULL: goto x86_l_1f7b;
	case 8066ULL: goto x86_l_1f82;
	default: return 0xffffffffffffffffULL;
	}
x86_l_167e:
	/* 0x167e: mov    r13d,0xfa7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4007ULL);
x86_l_1684:
	/* 0x1684: jmp    5f4c <kprobe_unwind_native+0x5f4c> */
	return 24396ULL;
x86_l_1689:
	/* 0x1689: mov    QWORD PTR [rbx+0xed8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_1690:
	/* 0x1690: mov    BYTE PTR [rbx+0xf30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16698832846849ULL);
x86_l_1697:
	/* 0x1697: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_169e:
	/* 0x169e: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_16a1:
	/* 0x16a1: mov    DWORD PTR [rsp+0x78],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075526ULL);
x86_l_16a9:
	/* 0x16a9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_16b0:
	/* 0x16b0: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_16b5:
	/* 0x16b5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16ba:
	/* 0x16ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16bc:
	/* 0x16bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16bf:
	/* 0x16bf: je     175b <kprobe_unwind_native+0x175b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_175b;
	}
x86_l_16c5:
	/* 0x16c5: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_16c8:
	/* 0x16c8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16ca:
	/* 0x16ca: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16ce:
	/* 0x16ce: je     1767 <kprobe_unwind_native+0x1767> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1767;
	}
x86_l_16d4:
	/* 0x16d4: movabs rax,0xa786c6c25203a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947156833280058ULL);
x86_l_16de:
	/* 0x16de: mov    QWORD PTR [rsp+0xb5],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 181ULL);
x86_l_16e6:
	/* 0x16e6: movabs rax,0x25203a706620786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675202433082226796ULL);
x86_l_16f0:
	/* 0x16f0: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_16f8:
	/* 0x16f8: movabs rax,0x6c25203a70732078 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7792670165601296504ULL);
x86_l_1702:
	/* 0x1702: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_170a:
	/* 0x170a: movabs rax,0x6c6c25203a637020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660273929744416ULL);
x86_l_1714:
	/* 0x1714: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_171c:
	/* 0x171c: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1724:
	/* 0x1724: mov    eax,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_1729:
	/* 0x1729: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_172f:
	/* 0x172f: mov    rdx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1733:
	/* 0x1733: mov    rax,QWORD PTR [rsp+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_173b:
	/* 0x173b: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_173e:
	/* 0x173e: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1743:
	/* 0x1743: mov    r8,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1746:
	/* 0x1746: mov    esi,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 29ULL);
x86_l_174b:
	/* 0x174b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_174d:
	/* 0x174d: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_1750:
	/* 0x1750: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1757:
	/* 0x1757: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1759:
	/* 0x1759: jmp    1767 <kprobe_unwind_native+0x1767> */
	goto x86_l_1767;
x86_l_175b:
	/* 0x175b: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_175f:
	/* 0x175f: jne    1a76 <kprobe_unwind_native+0x1a76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a76;
	}
x86_l_1765:
	/* 0x1765: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1767:
	/* 0x1767: mov    r13,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_176b:
	/* 0x176b: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_176e:
	/* 0x176e: je     7070 <kprobe_unwind_native+0x7070> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28784ULL;
	}
x86_l_1774:
	/* 0x1774: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1776:
	/* 0x1776: jne    1829 <kprobe_unwind_native+0x1829> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1829;
	}
x86_l_177c:
	/* 0x177c: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_177f:
	/* 0x177f: shr    rax,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_1783:
	/* 0x1783: je     18d2 <kprobe_unwind_native+0x18d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18d2;
	}
x86_l_1789:
	/* 0x1789: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1790:
	/* 0x1790: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1793:
	/* 0x1793: jne    33ac <kprobe_unwind_native+0x33ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13228ULL;
	}
x86_l_1799:
	/* 0x1799: mov    DWORD PTR [rbx+0xf28],0xb */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16664473108491ULL);
x86_l_17a3:
	/* 0x17a3: mov    r14d,0xfab */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4011ULL);
x86_l_17a9:
	/* 0x17a9: jmp    7148 <kprobe_unwind_native+0x7148> */
	return 29000ULL;
x86_l_17ae:
	/* 0x17ae: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_17b8:
	/* 0x17b8: mov    QWORD PTR [rsp+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_17bd:
	/* 0x17bd: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_17c7:
	/* 0x17c7: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17cc:
	/* 0x17cc: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_17d6:
	/* 0x17d6: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17db:
	/* 0x17db: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_17e5:
	/* 0x17e5: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17ea:
	/* 0x17ea: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_17f4:
	/* 0x17f4: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17f9:
	/* 0x17f9: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1803:
	/* 0x1803: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1808:
	/* 0x1808: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_180d:
	/* 0x180d: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1812:
	/* 0x1812: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1817:
	/* 0x1817: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_181b:
	/* 0x181b: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1820:
	/* 0x1820: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1822:
	/* 0x1822: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1824:
	/* 0x1824: jmp    167e <kprobe_unwind_native+0x167e> */
	goto x86_l_167e;
x86_l_1829:
	/* 0x1829: movabs rax,0xa3d3d3d3d206425 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 737813247186461733ULL);
x86_l_1833:
	/* 0x1833: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_183b:
	/* 0x183b: movabs rax,0x20656d617266203a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334392247160021050ULL);
x86_l_1845:
	/* 0x1845: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_184d:
	/* 0x184d: movabs rax,0x7265646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243105118350175861ULL);
x86_l_1857:
	/* 0x1857: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_185f:
	/* 0x185f: movabs rax,0x20656d6172662074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334392247160021108ULL);
x86_l_1869:
	/* 0x1869: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1871:
	/* 0x1871: movabs rax,0x78656e2065766c6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8675461342619397231ULL);
x86_l_187b:
	/* 0x187b: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1883:
	/* 0x1883: movabs rax,0x736552203d3d3d3d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8315142585429343549ULL);
x86_l_188d:
	/* 0x188d: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1895:
	/* 0x1895: mov    BYTE PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_189d:
	/* 0x189d: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_18a5:
	/* 0x18a5: mov    eax,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 49ULL);
x86_l_18aa:
	/* 0x18aa: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_18af:
	/* 0x18af: mov    edx,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_18b5:
	/* 0x18b5: mov    esi,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 49ULL);
x86_l_18ba:
	/* 0x18ba: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18bc:
	/* 0x18bc: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_18be:
	/* 0x18be: mov    r13,QWORD PTR [rbx+0xed0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_18c5:
	/* 0x18c5: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_18c8:
	/* 0x18c8: shr    rax,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_18cc:
	/* 0x18cc: jne    1789 <kprobe_unwind_native+0x1789> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1789;
	}
x86_l_18d2:
	/* 0x18d2: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_18d9:
	/* 0x18d9: ja     1900 <kprobe_unwind_native+0x1900> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1900;
	}
x86_l_18db:
	/* 0x18db: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_18e2:
	/* 0x18e2: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18e5:
	/* 0x18e5: jne    34f2 <kprobe_unwind_native+0x34f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13554ULL;
	}
x86_l_18eb:
	/* 0x18eb: mov    DWORD PTR [rbx+0xf28],0x31 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16664473108529ULL);
x86_l_18f5:
	/* 0x18f5: mov    r14d,0xfae */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4014ULL);
x86_l_18fb:
	/* 0x18fb: jmp    7148 <kprobe_unwind_native+0x7148> */
	return 29000ULL;
x86_l_1900:
	/* 0x1900: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1902:
	/* 0x1902: mov    DWORD PTR [rsp+0x10],0x60 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476832ULL);
x86_l_190a:
	/* 0x190a: movbe  DWORD PTR [rsp+0x14],eax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1910:
	/* 0x1910: movbe  QWORD PTR [rsp+0x18],r13 */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1917:
	/* 0x1917: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_page_to_mapping_info)));
x86_l_191e:
	/* 0x191e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1923:
	/* 0x1923: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1928:
	/* 0x1928: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_192a:
	/* 0x192a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_192d:
	/* 0x192d: je     712c <kprobe_unwind_native+0x712c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28972ULL;
	}
x86_l_1933:
	/* 0x1933: mov    QWORD PTR [rsp+0x140],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_193b:
	/* 0x193b: movabs rdx,0xffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 72057594037927935ULL);
x86_l_1945:
	/* 0x1945: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1949:
	/* 0x1949: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_194c:
	/* 0x194c: and    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_AND);
x86_l_194f:
	/* 0x194f: mov    QWORD PTR [rbx+0xf20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3872ULL);
x86_l_1956:
	/* 0x1956: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1959:
	/* 0x1959: mov    QWORD PTR [rbx+0xf10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_1960:
	/* 0x1960: shr    r12,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_1964:
	/* 0x1964: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_1967:
	/* 0x1967: sub    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_196a:
	/* 0x196a: mov    QWORD PTR [rbx+0xf18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_1971:
	/* 0x1971: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1978:
	/* 0x1978: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_197b:
	/* 0x197b: jne    1bfe <kprobe_unwind_native+0x1bfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bfe;
	}
x86_l_1981:
	/* 0x1981: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_1985:
	/* 0x1985: jne    1dfa <kprobe_unwind_native+0x1dfa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1dfa;
	}
x86_l_198b:
	/* 0x198b: mov    rax,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_1992:
	/* 0x1992: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1997:
	/* 0x1997: mov    r14,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_199e:
	/* 0x199e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&interpreter_offsets)));
x86_l_19a5:
	/* 0x19a5: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19aa:
	/* 0x19aa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19af:
	/* 0x19af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b1:
	/* 0x19b1: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_19b7:
	/* 0x19b7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19ba:
	/* 0x19ba: je     1dfa <kprobe_unwind_native+0x1dfa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dfa;
	}
x86_l_19c0:
	/* 0x19c0: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_19c3:
	/* 0x19c3: cmp    QWORD PTR [rax],r14 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19c6:
	/* 0x19c6: ja     19ce <kprobe_unwind_native+0x19ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_19ce;
	}
x86_l_19c8:
	/* 0x19c8: cmp    QWORD PTR [r13+0x8],r14 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19cc:
	/* 0x19cc: jae    19e2 <kprobe_unwind_native+0x19e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_19e2;
	}
x86_l_19ce:
	/* 0x19ce: cmp    QWORD PTR [r13+0x10],r14 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19d2:
	/* 0x19d2: ja     1dfa <kprobe_unwind_native+0x1dfa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1dfa;
	}
x86_l_19d8:
	/* 0x19d8: cmp    QWORD PTR [r13+0x18],r14 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19dc:
	/* 0x19dc: jb     1dfa <kprobe_unwind_native+0x1dfa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1dfa;
	}
x86_l_19e2:
	/* 0x19e2: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_19e9:
	/* 0x19e9: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19ec:
	/* 0x19ec: jne    1d40 <kprobe_unwind_native+0x1d40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d40;
	}
x86_l_19f2:
	/* 0x19f2: mov    eax,DWORD PTR [rbx+0x1380] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4992ULL);
x86_l_19f8:
	/* 0x19f8: mov    ecx,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19fc:
	/* 0x19fc: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_19ff:
	/* 0x19ff: jae    1dbb <kprobe_unwind_native+0x1dbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1dbb;
	}
x86_l_1a05:
	/* 0x1a05: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1a0c:
	/* 0x1a0c: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a0f:
	/* 0x1a0f: je     1df5 <kprobe_unwind_native+0x1df5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1df5;
	}
x86_l_1a15:
	/* 0x1a15: movabs rax,0x6e6f64207265646e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7957689157107934318ULL);
x86_l_1a1f:
	/* 0x1a1f: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1a27:
	/* 0x1a27: movabs rax,0x69776e7520726574 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7599664345545598324ULL);
x86_l_1a31:
	/* 0x1a31: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1a39:
	/* 0x1a39: movabs rax,0x6572707265746e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310028781806448233ULL);
x86_l_1a43:
	/* 0x1a43: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1a4b:
	/* 0x1a4b: mov    DWORD PTR [rsp+0xb7],0xa656e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 785979696494ULL);
x86_l_1a56:
	/* 0x1a56: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1a5e:
	/* 0x1a5e: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1a63:
	/* 0x1a63: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1a68:
	/* 0x1a68: mov    esi,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 27ULL);
x86_l_1a6d:
	/* 0x1a6d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a6f:
	/* 0x1a6f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1a71:
	/* 0x1a71: jmp    1df5 <kprobe_unwind_native+0x1df5> */
	goto x86_l_1df5;
x86_l_1a76:
	/* 0x1a76: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_1a80:
	/* 0x1a80: mov    QWORD PTR [rsp+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_1a85:
	/* 0x1a85: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_1a8f:
	/* 0x1a8f: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a94:
	/* 0x1a94: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_1a9e:
	/* 0x1a9e: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1aa3:
	/* 0x1aa3: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_1aad:
	/* 0x1aad: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ab2:
	/* 0x1ab2: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_1abc:
	/* 0x1abc: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ac1:
	/* 0x1ac1: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_1acb:
	/* 0x1acb: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ad0:
	/* 0x1ad0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ad5:
	/* 0x1ad5: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1ada:
	/* 0x1ada: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1adf:
	/* 0x1adf: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1ae3:
	/* 0x1ae3: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_1ae8:
	/* 0x1ae8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1aea:
	/* 0x1aea: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1aec:
	/* 0x1aec: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1aee:
	/* 0x1aee: cmp    DWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1af2:
	/* 0x1af2: je     1767 <kprobe_unwind_native+0x1767> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1767;
	}
x86_l_1af8:
	/* 0x1af8: jmp    16d4 <kprobe_unwind_native+0x16d4> */
	goto x86_l_16d4;
x86_l_1afd:
	/* 0x1afd: movabs rax,0x2578302073736572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2699960892542641522ULL);
x86_l_1b07:
	/* 0x1b07: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b0c:
	/* 0x1b0c: movabs rax,0x6464612065636e65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7234013693231722085ULL);
x86_l_1b16:
	/* 0x1b16: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b1b:
	/* 0x1b1b: movabs rax,0x7265666572656420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243107278868538400ULL);
x86_l_1b25:
	/* 0x1b25: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b2a:
	/* 0x1b2a: movabs rax,0x6f742064656c6961 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8031079651078859105ULL);
x86_l_1b34:
	/* 0x1b34: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b39:
	/* 0x1b39: movabs rax,0x6620646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358992216502005365ULL);
x86_l_1b43:
	/* 0x1b43: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b48:
	/* 0x1b48: mov    DWORD PTR [rsp+0x38],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518854764ULL);
x86_l_1b50:
	/* 0x1b50: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b55:
	/* 0x1b55: mov    eax,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_1b5a:
	/* 0x1b5a: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1b5f:
	/* 0x1b5f: mov    esi,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_1b64:
	/* 0x1b64: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1b67:
	/* 0x1b67: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b69:
	/* 0x1b69: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1b6b:
	/* 0x1b6b: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1b70:
	/* 0x1b70: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_1b73:
	/* 0x1b73: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1b7b:
	/* 0x1b7b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b7e:
	/* 0x1b7e: jmp    1451 <kprobe_unwind_native+0x1451> */
	return 5201ULL;
x86_l_1b83:
	/* 0x1b83: movabs rax,0x2578302073736572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2699960892542641522ULL);
x86_l_1b8d:
	/* 0x1b8d: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b92:
	/* 0x1b92: movabs rax,0x6464612065636e65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7234013693231722085ULL);
x86_l_1b9c:
	/* 0x1b9c: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ba1:
	/* 0x1ba1: movabs rax,0x7265666572656420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243107278868538400ULL);
x86_l_1bab:
	/* 0x1bab: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bb0:
	/* 0x1bb0: movabs rax,0x6f742064656c6961 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8031079651078859105ULL);
x86_l_1bba:
	/* 0x1bba: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bbf:
	/* 0x1bbf: movabs rax,0x6620646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358992216502005365ULL);
x86_l_1bc9:
	/* 0x1bc9: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bce:
	/* 0x1bce: mov    DWORD PTR [rsp+0x38],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518854764ULL);
x86_l_1bd6:
	/* 0x1bd6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bdb:
	/* 0x1bdb: mov    eax,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_1be0:
	/* 0x1be0: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1be5:
	/* 0x1be5: mov    esi,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_1bea:
	/* 0x1bea: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1bed:
	/* 0x1bed: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bef:
	/* 0x1bef: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1bf1:
	/* 0x1bf1: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1bf6:
	/* 0x1bf6: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_1bf9:
	/* 0x1bf9: jmp    1544 <kprobe_unwind_native+0x1544> */
	return 5444ULL;
x86_l_1bfe:
	/* 0x1bfe: movabs rax,0x296425207265646e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2982549674514539630ULL);
x86_l_1c08:
	/* 0x1c08: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1c10:
	/* 0x1c10: movabs rax,0x69776e752820786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7599664345674446956ULL);
x86_l_1c1a:
	/* 0x1c1a: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1c22:
	/* 0x1c22: movabs rax,0x6c2520736920786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7792670410291574892ULL);
x86_l_1c2c:
	/* 0x1c2c: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1c34:
	/* 0x1c34: movabs rax,0x2520435020726f66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675212190078889830ULL);
x86_l_1c3e:
	/* 0x1c3e: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1c46:
	/* 0x1c46: movabs rax,0x206469206e6f6974 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334106094897424756ULL);
x86_l_1c50:
	/* 0x1c50: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1c58:
	/* 0x1c58: movabs r14,0x6365732074786554 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 7162257365632836948ULL);
x86_l_1c62:
	/* 0x1c62: mov    QWORD PTR [rsp+0xa0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1c6a:
	/* 0x1c6a: mov    WORD PTR [rsp+0xd0],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 893353197578ULL);
x86_l_1c74:
	/* 0x1c74: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1c7c:
	/* 0x1c7c: mov    eax,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_1c81:
	/* 0x1c81: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1c87:
	/* 0x1c87: mov    rcx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_1c8e:
	/* 0x1c8e: mov    esi,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 50ULL);
x86_l_1c93:
	/* 0x1c93: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1c96:
	/* 0x1c96: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1c99:
	/* 0x1c99: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c9b:
	/* 0x1c9b: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_1c9e:
	/* 0x1c9e: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1ca5:
	/* 0x1ca5: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ca8:
	/* 0x1ca8: je     1981 <kprobe_unwind_native+0x1981> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1981;
	}
x86_l_1cae:
	/* 0x1cae: movabs rax,0xa786c6c252073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947156833280115ULL);
x86_l_1cb8:
	/* 0x1cb8: mov    QWORD PTR [rsp+0xc7],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 199ULL);
x86_l_1cc0:
	/* 0x1cc0: movabs rax,0x7369207465736666 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8316213871206688358ULL);
x86_l_1cca:
	/* 0x1cca: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1cd2:
	/* 0x1cd2: movabs rax,0x6f20646e61202c78 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8007510562703420536ULL);
x86_l_1cdc:
	/* 0x1cdc: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1ce4:
	/* 0x1ce4: movabs rax,0x6c6c252073692073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660274886418547ULL);
x86_l_1cee:
	/* 0x1cee: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1cf6:
	/* 0x1cf6: movabs rax,0x616962206e6f6974 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7019249385664899444ULL);
x86_l_1d00:
	/* 0x1d00: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1d08:
	/* 0x1d08: mov    QWORD PTR [rsp+0xa0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1d10:
	/* 0x1d10: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1d18:
	/* 0x1d18: mov    eax,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 47ULL);
x86_l_1d1d:
	/* 0x1d1d: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_1d23:
	/* 0x1d23: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_1d2a:
	/* 0x1d2a: mov    rdx,QWORD PTR [rbx+0xf20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3872ULL);
x86_l_1d31:
	/* 0x1d31: mov    esi,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 47ULL);
x86_l_1d36:
	/* 0x1d36: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d38:
	/* 0x1d38: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1d3b:
	/* 0x1d3b: jmp    1981 <kprobe_unwind_native+0x1981> */
	goto x86_l_1981;
x86_l_1d40:
	/* 0x1d40: movabs rax,0xa642520686374 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860387386228ULL);
x86_l_1d4a:
	/* 0x1d4a: mov    QWORD PTR [rsp+0xb6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_1d52:
	/* 0x1d52: movabs rax,0x6374616d20737465 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7166460028377068645ULL);
x86_l_1d5c:
	/* 0x1d5c: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1d64:
	/* 0x1d64: movabs rax,0x7366666f5f726574 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8315446390514935156ULL);
x86_l_1d6e:
	/* 0x1d6e: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1d76:
	/* 0x1d76: movabs rax,0x6572707265746e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310028781806448233ULL);
x86_l_1d80:
	/* 0x1d80: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1d88:
	/* 0x1d88: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1d90:
	/* 0x1d90: mov    eax,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 30ULL);
x86_l_1d95:
	/* 0x1d95: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1d9a:
	/* 0x1d9a: movzx  edx,WORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1d9f:
	/* 0x1d9f: mov    esi,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 30ULL);
x86_l_1da4:
	/* 0x1da4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1da6:
	/* 0x1da6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1da8:
	/* 0x1da8: mov    eax,DWORD PTR [rbx+0x1380] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4992ULL);
x86_l_1dae:
	/* 0x1dae: mov    ecx,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1db2:
	/* 0x1db2: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1db5:
	/* 0x1db5: jb     1a05 <kprobe_unwind_native+0x1a05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a05;
	}
x86_l_1dbb:
	/* 0x1dbb: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_1dc3:
	/* 0x1dc3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_1dca:
	/* 0x1dca: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1dcf:
	/* 0x1dcf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dd4:
	/* 0x1dd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd6:
	/* 0x1dd6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dd9:
	/* 0x1dd9: je     1de0 <kprobe_unwind_native+0x1de0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1de0;
	}
x86_l_1ddb:
	/* 0x1ddb: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1dde:
	/* 0x1dde: jmp    1df0 <kprobe_unwind_native+0x1df0> */
	goto x86_l_1df0;
x86_l_1de0:
	/* 0x1de0: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1de7:
	/* 0x1de7: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dea:
	/* 0x1dea: jne    2de4 <kprobe_unwind_native+0x2de4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11748ULL;
	}
x86_l_1df0:
	/* 0x1df0: movzx  r12d,WORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1df5:
	/* 0x1df5: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1dfa:
	/* 0x1dfa: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dfd:
	/* 0x1dfd: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_1e01:
	/* 0x1e01: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_1e08:
	/* 0x1e08: jne    5f59 <kprobe_unwind_native+0x5f59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24409ULL;
	}
x86_l_1e0e:
	/* 0x1e0e: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e13:
	/* 0x1e13: jne    2af7 <kprobe_unwind_native+0x2af7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10999ULL;
	}
x86_l_1e19:
	/* 0x1e19: mov    DWORD PTR [rsp+0x10],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476741ULL);
x86_l_1e21:
	/* 0x1e21: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_1e28:
	/* 0x1e28: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e2d:
	/* 0x1e2d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e32:
	/* 0x1e32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e34:
	/* 0x1e34: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e37:
	/* 0x1e37: je     1ee4 <kprobe_unwind_native+0x1ee4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ee4;
	}
x86_l_1e3d:
	/* 0x1e3d: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1e40:
	/* 0x1e40: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e45:
	/* 0x1e45: je     1eef <kprobe_unwind_native+0x1eef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1eef;
	}
x86_l_1e4b:
	/* 0x1e4b: movabs rax,0x63617473206e6f20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7161132920309968672ULL);
x86_l_1e55:
	/* 0x1e55: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1e5d:
	/* 0x1e5d: movabs rax,0x7525206e6f697469 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8441188735263536233ULL);
x86_l_1e67:
	/* 0x1e67: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1e6f:
	/* 0x1e6f: movabs rax,0x736f70206f742078 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8317990321387741304ULL);
x86_l_1e79:
	/* 0x1e79: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1e81:
	/* 0x1e81: movabs rax,0x6c6c2520786c6c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660274970520613ULL);
x86_l_1e8b:
	/* 0x1e8b: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1e93:
	/* 0x1e93: movabs rax,0x20676e6968737550 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334956330817910096ULL);
x86_l_1e9d:
	/* 0x1e9d: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1ea5:
	/* 0x1ea5: mov    DWORD PTR [rsp+0xc7],0xa6b63 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 854699174755ULL);
x86_l_1eb0:
	/* 0x1eb0: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1eb8:
	/* 0x1eb8: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1ebd:
	/* 0x1ebd: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_1ec3:
	/* 0x1ec3: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_1eca:
	/* 0x1eca: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_1ed1:
	/* 0x1ed1: mov    r8d,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_1ed8:
	/* 0x1ed8: mov    esi,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 43ULL);
x86_l_1edd:
	/* 0x1edd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1edf:
	/* 0x1edf: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_1ee2:
	/* 0x1ee2: jmp    1eef <kprobe_unwind_native+0x1eef> */
	goto x86_l_1eef;
x86_l_1ee4:
	/* 0x1ee4: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ee9:
	/* 0x1ee9: jne    2bcc <kprobe_unwind_native+0x2bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11212ULL;
	}
x86_l_1eef:
	/* 0x1eef: mov    eax,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_1ef5:
	/* 0x1ef5: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_1ef9:
	/* 0x1ef9: ja     13a <kprobe_unwind_native+0x13a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 314ULL;
	}
x86_l_1eff:
	/* 0x1eff: movzx  ecx,BYTE PTR [rbx+0xf30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3888ULL);
x86_l_1f06:
	/* 0x1f06: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_1f0d:
	/* 0x1f0d: mov    rsi,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_1f14:
	/* 0x1f14: lea    edi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1f17:
	/* 0x1f17: mov    DWORD PTR [rbx+0x2c0],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_1f1d:
	/* 0x1f1d: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_1f21:
	/* 0x1f21: mov    QWORD PTR [rbx+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_1f29:
	/* 0x1f29: mov    QWORD PTR [rbx+rax*8+0x2d8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_1f31:
	/* 0x1f31: mov    BYTE PTR [rbx+rax*8+0x2e0],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 3161095929859ULL);
x86_l_1f39:
	/* 0x1f39: mov    BYTE PTR [rbx+rax*8+0x2e1],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 737ULL);
x86_l_1f40:
	/* 0x1f40: mov    DWORD PTR [rbx+rax*8+0x2e2],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3169685864448ULL);
x86_l_1f4b:
	/* 0x1f4b: mov    WORD PTR [rbx+rax*8+0x2e6],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3186865733632ULL);
x86_l_1f55:
	/* 0x1f55: mov    DWORD PTR [rsp+0x8c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1f60:
	/* 0x1f60: mov    rax,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_1f67:
	/* 0x1f67: mov    QWORD PTR [rsp+0x160],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_1f6f:
	/* 0x1f6f: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1f74:
	/* 0x1f74: mov    rax,0xffffffffffff0000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 18446744073709486080ULL);
x86_l_1f7b:
	/* 0x1f7b: and    rax,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 3864ULL);
x86_l_1f82:
	/* 0x1f82: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
	return 8074ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8074ULL: goto x86_l_1f8a;
	case 8079ULL: goto x86_l_1f8f;
	case 8085ULL: goto x86_l_1f95;
	case 8092ULL: goto x86_l_1f9c;
	case 8097ULL: goto x86_l_1fa1;
	case 8102ULL: goto x86_l_1fa6;
	case 8104ULL: goto x86_l_1fa8;
	case 8107ULL: goto x86_l_1fab;
	case 8113ULL: goto x86_l_1fb1;
	case 8116ULL: goto x86_l_1fb4;
	case 8119ULL: goto x86_l_1fb7;
	case 8123ULL: goto x86_l_1fbb;
	case 8127ULL: goto x86_l_1fbf;
	case 8130ULL: goto x86_l_1fc2;
	case 8132ULL: goto x86_l_1fc4;
	case 8135ULL: goto x86_l_1fc7;
	case 8137ULL: goto x86_l_1fc9;
	case 8140ULL: goto x86_l_1fcc;
	case 8146ULL: goto x86_l_1fd2;
	case 8149ULL: goto x86_l_1fd5;
	case 8155ULL: goto x86_l_1fdb;
	case 8158ULL: goto x86_l_1fde;
	case 8164ULL: goto x86_l_1fe4;
	case 8171ULL: goto x86_l_1feb;
	case 8176ULL: goto x86_l_1ff0;
	case 8179ULL: goto x86_l_1ff3;
	case 8181ULL: goto x86_l_1ff5;
	case 8184ULL: goto x86_l_1ff8;
	case 8190ULL: goto x86_l_1ffe;
	case 8193ULL: goto x86_l_2001;
	case 8199ULL: goto x86_l_2007;
	case 8202ULL: goto x86_l_200a;
	case 8208ULL: goto x86_l_2010;
	case 8215ULL: goto x86_l_2017;
	case 8220ULL: goto x86_l_201c;
	case 8223ULL: goto x86_l_201f;
	case 8225ULL: goto x86_l_2021;
	case 8228ULL: goto x86_l_2024;
	case 8234ULL: goto x86_l_202a;
	case 8237ULL: goto x86_l_202d;
	case 8243ULL: goto x86_l_2033;
	case 8250ULL: goto x86_l_203a;
	case 8255ULL: goto x86_l_203f;
	case 8258ULL: goto x86_l_2042;
	case 8260ULL: goto x86_l_2044;
	case 8263ULL: goto x86_l_2047;
	case 8269ULL: goto x86_l_204d;
	case 8272ULL: goto x86_l_2050;
	case 8278ULL: goto x86_l_2056;
	case 8285ULL: goto x86_l_205d;
	case 8290ULL: goto x86_l_2062;
	case 8293ULL: goto x86_l_2065;
	case 8299ULL: goto x86_l_206b;
	case 8302ULL: goto x86_l_206e;
	case 8308ULL: goto x86_l_2074;
	case 8315ULL: goto x86_l_207b;
	case 8320ULL: goto x86_l_2080;
	case 8323ULL: goto x86_l_2083;
	case 8325ULL: goto x86_l_2085;
	case 8328ULL: goto x86_l_2088;
	case 8334ULL: goto x86_l_208e;
	case 8341ULL: goto x86_l_2095;
	case 8343ULL: goto x86_l_2097;
	case 8346ULL: goto x86_l_209a;
	case 8348ULL: goto x86_l_209c;
	case 8351ULL: goto x86_l_209f;
	case 8357ULL: goto x86_l_20a5;
	case 8364ULL: goto x86_l_20ac;
	case 8366ULL: goto x86_l_20ae;
	case 8369ULL: goto x86_l_20b1;
	case 8371ULL: goto x86_l_20b3;
	case 8374ULL: goto x86_l_20b6;
	case 8380ULL: goto x86_l_20bc;
	case 8387ULL: goto x86_l_20c3;
	case 8389ULL: goto x86_l_20c5;
	case 8396ULL: goto x86_l_20cc;
	case 8398ULL: goto x86_l_20ce;
	case 8405ULL: goto x86_l_20d5;
	case 8407ULL: goto x86_l_20d7;
	case 8414ULL: goto x86_l_20de;
	case 8416ULL: goto x86_l_20e0;
	case 8423ULL: goto x86_l_20e7;
	case 8425ULL: goto x86_l_20e9;
	case 8432ULL: goto x86_l_20f0;
	case 8434ULL: goto x86_l_20f2;
	case 8441ULL: goto x86_l_20f9;
	case 8443ULL: goto x86_l_20fb;
	case 8450ULL: goto x86_l_2102;
	case 8452ULL: goto x86_l_2104;
	case 8459ULL: goto x86_l_210b;
	case 8467ULL: goto x86_l_2113;
	case 8472ULL: goto x86_l_2118;
	case 8474ULL: goto x86_l_211a;
	case 8479ULL: goto x86_l_211f;
	case 8482ULL: goto x86_l_2122;
	case 8488ULL: goto x86_l_2128;
	case 8492ULL: goto x86_l_212c;
	case 8500ULL: goto x86_l_2134;
	case 8507ULL: goto x86_l_213b;
	case 8512ULL: goto x86_l_2140;
	case 8518ULL: goto x86_l_2146;
	case 8520ULL: goto x86_l_2148;
	case 8526ULL: goto x86_l_214e;
	case 8529ULL: goto x86_l_2151;
	case 8532ULL: goto x86_l_2154;
	case 8539ULL: goto x86_l_215b;
	case 8542ULL: goto x86_l_215e;
	case 8548ULL: goto x86_l_2164;
	case 8552ULL: goto x86_l_2168;
	case 8554ULL: goto x86_l_216a;
	case 8558ULL: goto x86_l_216e;
	case 8563ULL: goto x86_l_2173;
	case 8568ULL: goto x86_l_2178;
	case 8573ULL: goto x86_l_217d;
	case 8575ULL: goto x86_l_217f;
	case 8578ULL: goto x86_l_2182;
	case 8584ULL: goto x86_l_2188;
	case 8588ULL: goto x86_l_218c;
	case 8591ULL: goto x86_l_218f;
	case 8596ULL: goto x86_l_2194;
	case 8599ULL: goto x86_l_2197;
	case 8603ULL: goto x86_l_219b;
	case 8607ULL: goto x86_l_219f;
	case 8612ULL: goto x86_l_21a4;
	case 8615ULL: goto x86_l_21a7;
	case 8621ULL: goto x86_l_21ad;
	case 8626ULL: goto x86_l_21b2;
	case 8628ULL: goto x86_l_21b4;
	case 8630ULL: goto x86_l_21b6;
	case 8634ULL: goto x86_l_21ba;
	case 8639ULL: goto x86_l_21bf;
	case 8644ULL: goto x86_l_21c4;
	case 8649ULL: goto x86_l_21c9;
	case 8651ULL: goto x86_l_21cb;
	case 8654ULL: goto x86_l_21ce;
	case 8660ULL: goto x86_l_21d4;
	case 8664ULL: goto x86_l_21d8;
	case 8668ULL: goto x86_l_21dc;
	case 8673ULL: goto x86_l_21e1;
	case 8676ULL: goto x86_l_21e4;
	case 8680ULL: goto x86_l_21e8;
	case 8685ULL: goto x86_l_21ed;
	case 8688ULL: goto x86_l_21f0;
	case 8693ULL: goto x86_l_21f5;
	case 8696ULL: goto x86_l_21f8;
	case 8702ULL: goto x86_l_21fe;
	case 8707ULL: goto x86_l_2203;
	case 8710ULL: goto x86_l_2206;
	case 8712ULL: goto x86_l_2208;
	case 8716ULL: goto x86_l_220c;
	case 8721ULL: goto x86_l_2211;
	case 8726ULL: goto x86_l_2216;
	case 8731ULL: goto x86_l_221b;
	case 8733ULL: goto x86_l_221d;
	case 8736ULL: goto x86_l_2220;
	case 8742ULL: goto x86_l_2226;
	case 8746ULL: goto x86_l_222a;
	case 8749ULL: goto x86_l_222d;
	case 8754ULL: goto x86_l_2232;
	case 8757ULL: goto x86_l_2235;
	case 8761ULL: goto x86_l_2239;
	case 8766ULL: goto x86_l_223e;
	case 8769ULL: goto x86_l_2241;
	case 8774ULL: goto x86_l_2246;
	case 8776ULL: goto x86_l_2248;
	case 8782ULL: goto x86_l_224e;
	case 8787ULL: goto x86_l_2253;
	case 8789ULL: goto x86_l_2255;
	case 8791ULL: goto x86_l_2257;
	case 8795ULL: goto x86_l_225b;
	case 8800ULL: goto x86_l_2260;
	case 8805ULL: goto x86_l_2265;
	case 8810ULL: goto x86_l_226a;
	case 8812ULL: goto x86_l_226c;
	case 8815ULL: goto x86_l_226f;
	case 8821ULL: goto x86_l_2275;
	case 8825ULL: goto x86_l_2279;
	case 8829ULL: goto x86_l_227d;
	case 8834ULL: goto x86_l_2282;
	case 8837ULL: goto x86_l_2285;
	case 8841ULL: goto x86_l_2289;
	case 8846ULL: goto x86_l_228e;
	case 8849ULL: goto x86_l_2291;
	case 8854ULL: goto x86_l_2296;
	case 8857ULL: goto x86_l_2299;
	case 8863ULL: goto x86_l_229f;
	case 8868ULL: goto x86_l_22a4;
	case 8871ULL: goto x86_l_22a7;
	case 8873ULL: goto x86_l_22a9;
	case 8877ULL: goto x86_l_22ad;
	case 8882ULL: goto x86_l_22b2;
	case 8887ULL: goto x86_l_22b7;
	case 8892ULL: goto x86_l_22bc;
	case 8894ULL: goto x86_l_22be;
	case 8897ULL: goto x86_l_22c1;
	case 8903ULL: goto x86_l_22c7;
	case 8907ULL: goto x86_l_22cb;
	case 8910ULL: goto x86_l_22ce;
	case 8915ULL: goto x86_l_22d3;
	case 8918ULL: goto x86_l_22d6;
	case 8922ULL: goto x86_l_22da;
	case 8927ULL: goto x86_l_22df;
	case 8930ULL: goto x86_l_22e2;
	case 8935ULL: goto x86_l_22e7;
	case 8937ULL: goto x86_l_22e9;
	case 8943ULL: goto x86_l_22ef;
	case 8948ULL: goto x86_l_22f4;
	case 8950ULL: goto x86_l_22f6;
	case 8952ULL: goto x86_l_22f8;
	case 8956ULL: goto x86_l_22fc;
	case 8961ULL: goto x86_l_2301;
	case 8966ULL: goto x86_l_2306;
	case 8971ULL: goto x86_l_230b;
	case 8973ULL: goto x86_l_230d;
	case 8976ULL: goto x86_l_2310;
	case 8982ULL: goto x86_l_2316;
	case 8986ULL: goto x86_l_231a;
	case 8990ULL: goto x86_l_231e;
	case 8995ULL: goto x86_l_2323;
	case 8998ULL: goto x86_l_2326;
	case 9002ULL: goto x86_l_232a;
	case 9007ULL: goto x86_l_232f;
	case 9010ULL: goto x86_l_2332;
	case 9015ULL: goto x86_l_2337;
	case 9018ULL: goto x86_l_233a;
	case 9024ULL: goto x86_l_2340;
	case 9029ULL: goto x86_l_2345;
	case 9032ULL: goto x86_l_2348;
	case 9034ULL: goto x86_l_234a;
	case 9038ULL: goto x86_l_234e;
	case 9043ULL: goto x86_l_2353;
	case 9048ULL: goto x86_l_2358;
	case 9053ULL: goto x86_l_235d;
	case 9055ULL: goto x86_l_235f;
	case 9058ULL: goto x86_l_2362;
	case 9064ULL: goto x86_l_2368;
	case 9068ULL: goto x86_l_236c;
	case 9071ULL: goto x86_l_236f;
	case 9076ULL: goto x86_l_2374;
	case 9079ULL: goto x86_l_2377;
	case 9083ULL: goto x86_l_237b;
	case 9088ULL: goto x86_l_2380;
	case 9091ULL: goto x86_l_2383;
	case 9096ULL: goto x86_l_2388;
	case 9098ULL: goto x86_l_238a;
	case 9104ULL: goto x86_l_2390;
	case 9109ULL: goto x86_l_2395;
	case 9111ULL: goto x86_l_2397;
	case 9113ULL: goto x86_l_2399;
	case 9117ULL: goto x86_l_239d;
	case 9122ULL: goto x86_l_23a2;
	case 9127ULL: goto x86_l_23a7;
	case 9132ULL: goto x86_l_23ac;
	case 9134ULL: goto x86_l_23ae;
	case 9137ULL: goto x86_l_23b1;
	case 9143ULL: goto x86_l_23b7;
	case 9147ULL: goto x86_l_23bb;
	case 9151ULL: goto x86_l_23bf;
	case 9156ULL: goto x86_l_23c4;
	case 9159ULL: goto x86_l_23c7;
	case 9163ULL: goto x86_l_23cb;
	case 9168ULL: goto x86_l_23d0;
	case 9171ULL: goto x86_l_23d3;
	case 9176ULL: goto x86_l_23d8;
	case 9179ULL: goto x86_l_23db;
	case 9185ULL: goto x86_l_23e1;
	case 9190ULL: goto x86_l_23e6;
	case 9193ULL: goto x86_l_23e9;
	case 9195ULL: goto x86_l_23eb;
	case 9199ULL: goto x86_l_23ef;
	case 9204ULL: goto x86_l_23f4;
	case 9209ULL: goto x86_l_23f9;
	case 9214ULL: goto x86_l_23fe;
	case 9216ULL: goto x86_l_2400;
	case 9219ULL: goto x86_l_2403;
	case 9225ULL: goto x86_l_2409;
	case 9229ULL: goto x86_l_240d;
	case 9232ULL: goto x86_l_2410;
	case 9237ULL: goto x86_l_2415;
	case 9240ULL: goto x86_l_2418;
	case 9244ULL: goto x86_l_241c;
	case 9249ULL: goto x86_l_2421;
	case 9252ULL: goto x86_l_2424;
	case 9257ULL: goto x86_l_2429;
	case 9259ULL: goto x86_l_242b;
	case 9265ULL: goto x86_l_2431;
	case 9270ULL: goto x86_l_2436;
	case 9272ULL: goto x86_l_2438;
	case 9274ULL: goto x86_l_243a;
	case 9278ULL: goto x86_l_243e;
	case 9283ULL: goto x86_l_2443;
	case 9288ULL: goto x86_l_2448;
	case 9293ULL: goto x86_l_244d;
	case 9295ULL: goto x86_l_244f;
	case 9298ULL: goto x86_l_2452;
	case 9304ULL: goto x86_l_2458;
	case 9308ULL: goto x86_l_245c;
	case 9312ULL: goto x86_l_2460;
	case 9317ULL: goto x86_l_2465;
	case 9320ULL: goto x86_l_2468;
	case 9324ULL: goto x86_l_246c;
	case 9329ULL: goto x86_l_2471;
	case 9332ULL: goto x86_l_2474;
	case 9337ULL: goto x86_l_2479;
	case 9340ULL: goto x86_l_247c;
	case 9346ULL: goto x86_l_2482;
	case 9351ULL: goto x86_l_2487;
	case 9354ULL: goto x86_l_248a;
	case 9356ULL: goto x86_l_248c;
	case 9360ULL: goto x86_l_2490;
	case 9365ULL: goto x86_l_2495;
	case 9370ULL: goto x86_l_249a;
	case 9375ULL: goto x86_l_249f;
	case 9377ULL: goto x86_l_24a1;
	case 9380ULL: goto x86_l_24a4;
	case 9386ULL: goto x86_l_24aa;
	case 9390ULL: goto x86_l_24ae;
	case 9393ULL: goto x86_l_24b1;
	case 9398ULL: goto x86_l_24b6;
	case 9401ULL: goto x86_l_24b9;
	case 9405ULL: goto x86_l_24bd;
	case 9410ULL: goto x86_l_24c2;
	case 9413ULL: goto x86_l_24c5;
	case 9418ULL: goto x86_l_24ca;
	case 9420ULL: goto x86_l_24cc;
	case 9426ULL: goto x86_l_24d2;
	case 9431ULL: goto x86_l_24d7;
	case 9433ULL: goto x86_l_24d9;
	case 9435ULL: goto x86_l_24db;
	case 9439ULL: goto x86_l_24df;
	case 9444ULL: goto x86_l_24e4;
	case 9449ULL: goto x86_l_24e9;
	case 9454ULL: goto x86_l_24ee;
	case 9456ULL: goto x86_l_24f0;
	case 9459ULL: goto x86_l_24f3;
	case 9465ULL: goto x86_l_24f9;
	case 9469ULL: goto x86_l_24fd;
	case 9473ULL: goto x86_l_2501;
	case 9478ULL: goto x86_l_2506;
	case 9481ULL: goto x86_l_2509;
	case 9485ULL: goto x86_l_250d;
	case 9490ULL: goto x86_l_2512;
	case 9493ULL: goto x86_l_2515;
	case 9498ULL: goto x86_l_251a;
	case 9501ULL: goto x86_l_251d;
	case 9507ULL: goto x86_l_2523;
	case 9512ULL: goto x86_l_2528;
	case 9515ULL: goto x86_l_252b;
	case 9517ULL: goto x86_l_252d;
	case 9521ULL: goto x86_l_2531;
	case 9526ULL: goto x86_l_2536;
	case 9531ULL: goto x86_l_253b;
	case 9536ULL: goto x86_l_2540;
	case 9538ULL: goto x86_l_2542;
	case 9541ULL: goto x86_l_2545;
	case 9547ULL: goto x86_l_254b;
	case 9551ULL: goto x86_l_254f;
	case 9554ULL: goto x86_l_2552;
	case 9559ULL: goto x86_l_2557;
	case 9562ULL: goto x86_l_255a;
	case 9566ULL: goto x86_l_255e;
	case 9571ULL: goto x86_l_2563;
	case 9574ULL: goto x86_l_2566;
	case 9579ULL: goto x86_l_256b;
	case 9581ULL: goto x86_l_256d;
	case 9587ULL: goto x86_l_2573;
	case 9592ULL: goto x86_l_2578;
	case 9594ULL: goto x86_l_257a;
	case 9596ULL: goto x86_l_257c;
	case 9600ULL: goto x86_l_2580;
	case 9605ULL: goto x86_l_2585;
	case 9610ULL: goto x86_l_258a;
	case 9615ULL: goto x86_l_258f;
	case 9617ULL: goto x86_l_2591;
	case 9620ULL: goto x86_l_2594;
	case 9626ULL: goto x86_l_259a;
	case 9630ULL: goto x86_l_259e;
	case 9634ULL: goto x86_l_25a2;
	case 9639ULL: goto x86_l_25a7;
	case 9642ULL: goto x86_l_25aa;
	case 9646ULL: goto x86_l_25ae;
	case 9651ULL: goto x86_l_25b3;
	case 9654ULL: goto x86_l_25b6;
	case 9659ULL: goto x86_l_25bb;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1f8a:
	/* 0x1f8a: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f8f:
	/* 0x1f8f: jne    2b5e <kprobe_unwind_native+0x2b5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11102ULL;
	}
x86_l_1f95:
	/* 0x1f95: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&stack_delta_page_to_info)));
x86_l_1f9c:
	/* 0x1f9c: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1fa1:
	/* 0x1fa1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fa6:
	/* 0x1fa6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fa8:
	/* 0x1fa8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fab:
	/* 0x1fab: je     569d <kprobe_unwind_native+0x569d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22173ULL;
	}
x86_l_1fb1:
	/* 0x1fb1: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1fb4:
	/* 0x1fb4: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1fb7:
	/* 0x1fb7: add    rbp,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_1fbb:
	/* 0x1fbb: movzx  eax,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_1fbf:
	/* 0x1fbf: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1fc2:
	/* 0x1fc2: jg     1ff0 <kprobe_unwind_native+0x1ff0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1ff0;
	}
x86_l_1fc4:
	/* 0x1fc4: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1fc7:
	/* 0x1fc7: jg     201c <kprobe_unwind_native+0x201c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_201c;
	}
x86_l_1fc9:
	/* 0x1fc9: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1fcc:
	/* 0x1fcc: jg     2062 <kprobe_unwind_native+0x2062> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2062;
	}
x86_l_1fd2:
	/* 0x1fd2: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1fd5:
	/* 0x1fd5: je     20c5 <kprobe_unwind_native+0x20c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20c5;
	}
x86_l_1fdb:
	/* 0x1fdb: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1fde:
	/* 0x1fde: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_1fe4:
	/* 0x1fe4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_9_stack_deltas)));
x86_l_1feb:
	/* 0x1feb: jmp    210b <kprobe_unwind_native+0x210b> */
	goto x86_l_210b;
x86_l_1ff0:
	/* 0x1ff0: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_1ff3:
	/* 0x1ff3: jg     203f <kprobe_unwind_native+0x203f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_203f;
	}
x86_l_1ff5:
	/* 0x1ff5: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1ff8:
	/* 0x1ff8: jg     2080 <kprobe_unwind_native+0x2080> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2080;
	}
x86_l_1ffe:
	/* 0x1ffe: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_2001:
	/* 0x2001: je     20ce <kprobe_unwind_native+0x20ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20ce;
	}
x86_l_2007:
	/* 0x2007: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_200a:
	/* 0x200a: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_2010:
	/* 0x2010: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_17_stack_deltas)));
x86_l_2017:
	/* 0x2017: jmp    210b <kprobe_unwind_native+0x210b> */
	goto x86_l_210b;
x86_l_201c:
	/* 0x201c: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_201f:
	/* 0x201f: jg     2097 <kprobe_unwind_native+0x2097> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2097;
	}
x86_l_2021:
	/* 0x2021: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2024:
	/* 0x2024: je     20d7 <kprobe_unwind_native+0x20d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20d7;
	}
x86_l_202a:
	/* 0x202a: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_202d:
	/* 0x202d: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_2033:
	/* 0x2033: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_13_stack_deltas)));
x86_l_203a:
	/* 0x203a: jmp    210b <kprobe_unwind_native+0x210b> */
	goto x86_l_210b;
x86_l_203f:
	/* 0x203f: cmp    eax,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_2042:
	/* 0x2042: jg     20ae <kprobe_unwind_native+0x20ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_20ae;
	}
x86_l_2044:
	/* 0x2044: cmp    eax,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 20ULL);
x86_l_2047:
	/* 0x2047: je     20e0 <kprobe_unwind_native+0x20e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20e0;
	}
x86_l_204d:
	/* 0x204d: cmp    eax,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_2050:
	/* 0x2050: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_2056:
	/* 0x2056: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_21_stack_deltas)));
x86_l_205d:
	/* 0x205d: jmp    210b <kprobe_unwind_native+0x210b> */
	goto x86_l_210b;
x86_l_2062:
	/* 0x2062: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_2065:
	/* 0x2065: je     20e9 <kprobe_unwind_native+0x20e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20e9;
	}
x86_l_206b:
	/* 0x206b: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_206e:
	/* 0x206e: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_2074:
	/* 0x2074: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_11_stack_deltas)));
x86_l_207b:
	/* 0x207b: jmp    210b <kprobe_unwind_native+0x210b> */
	goto x86_l_210b;
x86_l_2080:
	/* 0x2080: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_2083:
	/* 0x2083: je     20f2 <kprobe_unwind_native+0x20f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20f2;
	}
x86_l_2085:
	/* 0x2085: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_2088:
	/* 0x2088: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_208e:
	/* 0x208e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_19_stack_deltas)));
x86_l_2095:
	/* 0x2095: jmp    210b <kprobe_unwind_native+0x210b> */
	goto x86_l_210b;
x86_l_2097:
	/* 0x2097: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_209a:
	/* 0x209a: je     20fb <kprobe_unwind_native+0x20fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20fb;
	}
x86_l_209c:
	/* 0x209c: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_209f:
	/* 0x209f: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_20a5:
	/* 0x20a5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_15_stack_deltas)));
x86_l_20ac:
	/* 0x20ac: jmp    210b <kprobe_unwind_native+0x210b> */
	goto x86_l_210b;
x86_l_20ae:
	/* 0x20ae: cmp    eax,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 22ULL);
x86_l_20b1:
	/* 0x20b1: je     2104 <kprobe_unwind_native+0x2104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2104;
	}
x86_l_20b3:
	/* 0x20b3: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_20b6:
	/* 0x20b6: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_20bc:
	/* 0x20bc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_23_stack_deltas)));
x86_l_20c3:
	/* 0x20c3: jmp    210b <kprobe_unwind_native+0x210b> */
	goto x86_l_210b;
x86_l_20c5:
	/* 0x20c5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_8_stack_deltas)));
x86_l_20cc:
	/* 0x20cc: jmp    210b <kprobe_unwind_native+0x210b> */
	goto x86_l_210b;
x86_l_20ce:
	/* 0x20ce: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_16_stack_deltas)));
x86_l_20d5:
	/* 0x20d5: jmp    210b <kprobe_unwind_native+0x210b> */
	goto x86_l_210b;
x86_l_20d7:
	/* 0x20d7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_12_stack_deltas)));
x86_l_20de:
	/* 0x20de: jmp    210b <kprobe_unwind_native+0x210b> */
	goto x86_l_210b;
x86_l_20e0:
	/* 0x20e0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_20_stack_deltas)));
x86_l_20e7:
	/* 0x20e7: jmp    210b <kprobe_unwind_native+0x210b> */
	goto x86_l_210b;
x86_l_20e9:
	/* 0x20e9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_10_stack_deltas)));
x86_l_20f0:
	/* 0x20f0: jmp    210b <kprobe_unwind_native+0x210b> */
	goto x86_l_210b;
x86_l_20f2:
	/* 0x20f2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_18_stack_deltas)));
x86_l_20f9:
	/* 0x20f9: jmp    210b <kprobe_unwind_native+0x210b> */
	goto x86_l_210b;
x86_l_20fb:
	/* 0x20fb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_14_stack_deltas)));
x86_l_2102:
	/* 0x2102: jmp    210b <kprobe_unwind_native+0x210b> */
	goto x86_l_210b;
x86_l_2104:
	/* 0x2104: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_22_stack_deltas)));
x86_l_210b:
	/* 0x210b: lea    rsi,[rsp+0x160] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_2113:
	/* 0x2113: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2118:
	/* 0x2118: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_211a:
	/* 0x211a: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_211f:
	/* 0x211f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2122:
	/* 0x2122: je     5f24 <kprobe_unwind_native+0x5f24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24356ULL;
	}
x86_l_2128:
	/* 0x2128: mov    r13d,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_212c:
	/* 0x212c: mov    DWORD PTR [rsp+0x90],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2134:
	/* 0x2134: mov    rax,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_213b:
	/* 0x213b: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2140:
	/* 0x2140: movzx  eax,WORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2146:
	/* 0x2146: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2148:
	/* 0x2148: je     266e <kprobe_unwind_native+0x266e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9838ULL;
	}
x86_l_214e:
	/* 0x214e: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2151:
	/* 0x2151: add    r15d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2154:
	/* 0x2154: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_215b:
	/* 0x215b: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_215e:
	/* 0x215e: jne    2c67 <kprobe_unwind_native+0x2c67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11367ULL;
	}
x86_l_2164:
	/* 0x2164: lea    eax,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_2168:
	/* 0x2168: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_216a:
	/* 0x216a: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_216e:
	/* 0x216e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2173:
	/* 0x2173: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2178:
	/* 0x2178: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_217d:
	/* 0x217d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_217f:
	/* 0x217f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2182:
	/* 0x2182: je     2712 <kprobe_unwind_native+0x2712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10002ULL;
	}
x86_l_2188:
	/* 0x2188: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_218c:
	/* 0x218c: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_218f:
	/* 0x218f: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2194:
	/* 0x2194: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2197:
	/* 0x2197: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_219b:
	/* 0x219b: cmova  r15d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_219f:
	/* 0x219f: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21a4:
	/* 0x21a4: cmp    ebp,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R15, X86_WIDTH_32);
x86_l_21a7:
	/* 0x21a7: jae    265e <kprobe_unwind_native+0x265e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9822ULL;
	}
x86_l_21ad:
	/* 0x21ad: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21b2:
	/* 0x21b2: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_21b4:
	/* 0x21b4: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_21b6:
	/* 0x21b6: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21ba:
	/* 0x21ba: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21bf:
	/* 0x21bf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21c4:
	/* 0x21c4: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_21c9:
	/* 0x21c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21cb:
	/* 0x21cb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21ce:
	/* 0x21ce: je     2712 <kprobe_unwind_native+0x2712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10002ULL;
	}
x86_l_21d4:
	/* 0x21d4: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21d8:
	/* 0x21d8: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_21dc:
	/* 0x21dc: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_21e1:
	/* 0x21e1: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21e4:
	/* 0x21e4: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_21e8:
	/* 0x21e8: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21ed:
	/* 0x21ed: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_21f0:
	/* 0x21f0: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21f5:
	/* 0x21f5: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_21f8:
	/* 0x21f8: jae    265e <kprobe_unwind_native+0x265e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9822ULL;
	}
x86_l_21fe:
	/* 0x21fe: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2203:
	/* 0x2203: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2206:
	/* 0x2206: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_2208:
	/* 0x2208: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_220c:
	/* 0x220c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2211:
	/* 0x2211: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2216:
	/* 0x2216: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_221b:
	/* 0x221b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_221d:
	/* 0x221d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2220:
	/* 0x2220: je     2712 <kprobe_unwind_native+0x2712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10002ULL;
	}
x86_l_2226:
	/* 0x2226: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_222a:
	/* 0x222a: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_222d:
	/* 0x222d: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2232:
	/* 0x2232: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2235:
	/* 0x2235: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_2239:
	/* 0x2239: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_223e:
	/* 0x223e: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_2241:
	/* 0x2241: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2246:
	/* 0x2246: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_2248:
	/* 0x2248: jae    265e <kprobe_unwind_native+0x265e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9822ULL;
	}
x86_l_224e:
	/* 0x224e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2253:
	/* 0x2253: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2255:
	/* 0x2255: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_2257:
	/* 0x2257: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_225b:
	/* 0x225b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2260:
	/* 0x2260: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2265:
	/* 0x2265: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_226a:
	/* 0x226a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_226c:
	/* 0x226c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_226f:
	/* 0x226f: je     2712 <kprobe_unwind_native+0x2712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10002ULL;
	}
x86_l_2275:
	/* 0x2275: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2279:
	/* 0x2279: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_227d:
	/* 0x227d: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2282:
	/* 0x2282: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2285:
	/* 0x2285: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_2289:
	/* 0x2289: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_228e:
	/* 0x228e: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_2291:
	/* 0x2291: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2296:
	/* 0x2296: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_2299:
	/* 0x2299: jae    265e <kprobe_unwind_native+0x265e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9822ULL;
	}
x86_l_229f:
	/* 0x229f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22a4:
	/* 0x22a4: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_22a7:
	/* 0x22a7: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_22a9:
	/* 0x22a9: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22ad:
	/* 0x22ad: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22b2:
	/* 0x22b2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22b7:
	/* 0x22b7: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_22bc:
	/* 0x22bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22be:
	/* 0x22be: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22c1:
	/* 0x22c1: je     2712 <kprobe_unwind_native+0x2712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10002ULL;
	}
x86_l_22c7:
	/* 0x22c7: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22cb:
	/* 0x22cb: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_22ce:
	/* 0x22ce: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_22d3:
	/* 0x22d3: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22d6:
	/* 0x22d6: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_22da:
	/* 0x22da: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22df:
	/* 0x22df: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_22e2:
	/* 0x22e2: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22e7:
	/* 0x22e7: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_22e9:
	/* 0x22e9: jae    265e <kprobe_unwind_native+0x265e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9822ULL;
	}
x86_l_22ef:
	/* 0x22ef: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22f4:
	/* 0x22f4: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_22f6:
	/* 0x22f6: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_22f8:
	/* 0x22f8: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22fc:
	/* 0x22fc: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2301:
	/* 0x2301: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2306:
	/* 0x2306: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_230b:
	/* 0x230b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_230d:
	/* 0x230d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2310:
	/* 0x2310: je     2712 <kprobe_unwind_native+0x2712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10002ULL;
	}
x86_l_2316:
	/* 0x2316: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_231a:
	/* 0x231a: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_231e:
	/* 0x231e: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2323:
	/* 0x2323: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2326:
	/* 0x2326: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_232a:
	/* 0x232a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_232f:
	/* 0x232f: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_2332:
	/* 0x2332: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2337:
	/* 0x2337: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_233a:
	/* 0x233a: jae    265e <kprobe_unwind_native+0x265e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9822ULL;
	}
x86_l_2340:
	/* 0x2340: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2345:
	/* 0x2345: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2348:
	/* 0x2348: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_234a:
	/* 0x234a: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_234e:
	/* 0x234e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2353:
	/* 0x2353: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2358:
	/* 0x2358: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_235d:
	/* 0x235d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_235f:
	/* 0x235f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2362:
	/* 0x2362: je     2712 <kprobe_unwind_native+0x2712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10002ULL;
	}
x86_l_2368:
	/* 0x2368: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_236c:
	/* 0x236c: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_236f:
	/* 0x236f: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2374:
	/* 0x2374: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2377:
	/* 0x2377: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_237b:
	/* 0x237b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2380:
	/* 0x2380: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_2383:
	/* 0x2383: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2388:
	/* 0x2388: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_238a:
	/* 0x238a: jae    265e <kprobe_unwind_native+0x265e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9822ULL;
	}
x86_l_2390:
	/* 0x2390: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2395:
	/* 0x2395: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2397:
	/* 0x2397: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_2399:
	/* 0x2399: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_239d:
	/* 0x239d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23a2:
	/* 0x23a2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23a7:
	/* 0x23a7: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_23ac:
	/* 0x23ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23ae:
	/* 0x23ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23b1:
	/* 0x23b1: je     2712 <kprobe_unwind_native+0x2712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10002ULL;
	}
x86_l_23b7:
	/* 0x23b7: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23bb:
	/* 0x23bb: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_23bf:
	/* 0x23bf: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_23c4:
	/* 0x23c4: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23c7:
	/* 0x23c7: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_23cb:
	/* 0x23cb: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23d0:
	/* 0x23d0: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_23d3:
	/* 0x23d3: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23d8:
	/* 0x23d8: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_23db:
	/* 0x23db: jae    265e <kprobe_unwind_native+0x265e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9822ULL;
	}
x86_l_23e1:
	/* 0x23e1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23e6:
	/* 0x23e6: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_23e9:
	/* 0x23e9: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_23eb:
	/* 0x23eb: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23ef:
	/* 0x23ef: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23f4:
	/* 0x23f4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23f9:
	/* 0x23f9: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_23fe:
	/* 0x23fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2400:
	/* 0x2400: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2403:
	/* 0x2403: je     2712 <kprobe_unwind_native+0x2712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10002ULL;
	}
x86_l_2409:
	/* 0x2409: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_240d:
	/* 0x240d: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2410:
	/* 0x2410: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2415:
	/* 0x2415: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2418:
	/* 0x2418: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_241c:
	/* 0x241c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2421:
	/* 0x2421: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_2424:
	/* 0x2424: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2429:
	/* 0x2429: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_242b:
	/* 0x242b: jae    265e <kprobe_unwind_native+0x265e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9822ULL;
	}
x86_l_2431:
	/* 0x2431: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2436:
	/* 0x2436: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2438:
	/* 0x2438: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_243a:
	/* 0x243a: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_243e:
	/* 0x243e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2443:
	/* 0x2443: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2448:
	/* 0x2448: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_244d:
	/* 0x244d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_244f:
	/* 0x244f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2452:
	/* 0x2452: je     2712 <kprobe_unwind_native+0x2712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10002ULL;
	}
x86_l_2458:
	/* 0x2458: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_245c:
	/* 0x245c: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2460:
	/* 0x2460: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2465:
	/* 0x2465: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2468:
	/* 0x2468: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_246c:
	/* 0x246c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2471:
	/* 0x2471: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_2474:
	/* 0x2474: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2479:
	/* 0x2479: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_247c:
	/* 0x247c: jae    265e <kprobe_unwind_native+0x265e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9822ULL;
	}
x86_l_2482:
	/* 0x2482: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2487:
	/* 0x2487: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_248a:
	/* 0x248a: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_248c:
	/* 0x248c: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2490:
	/* 0x2490: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2495:
	/* 0x2495: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_249a:
	/* 0x249a: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_249f:
	/* 0x249f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24a1:
	/* 0x24a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24a4:
	/* 0x24a4: je     2712 <kprobe_unwind_native+0x2712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10002ULL;
	}
x86_l_24aa:
	/* 0x24aa: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24ae:
	/* 0x24ae: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_24b1:
	/* 0x24b1: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_24b6:
	/* 0x24b6: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24b9:
	/* 0x24b9: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_24bd:
	/* 0x24bd: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24c2:
	/* 0x24c2: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_24c5:
	/* 0x24c5: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24ca:
	/* 0x24ca: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_24cc:
	/* 0x24cc: jae    265e <kprobe_unwind_native+0x265e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9822ULL;
	}
x86_l_24d2:
	/* 0x24d2: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24d7:
	/* 0x24d7: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_24d9:
	/* 0x24d9: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_24db:
	/* 0x24db: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24df:
	/* 0x24df: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24e4:
	/* 0x24e4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24e9:
	/* 0x24e9: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_24ee:
	/* 0x24ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24f0:
	/* 0x24f0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24f3:
	/* 0x24f3: je     2712 <kprobe_unwind_native+0x2712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10002ULL;
	}
x86_l_24f9:
	/* 0x24f9: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24fd:
	/* 0x24fd: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2501:
	/* 0x2501: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2506:
	/* 0x2506: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2509:
	/* 0x2509: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_250d:
	/* 0x250d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2512:
	/* 0x2512: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_2515:
	/* 0x2515: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_251a:
	/* 0x251a: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_251d:
	/* 0x251d: jae    265e <kprobe_unwind_native+0x265e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9822ULL;
	}
x86_l_2523:
	/* 0x2523: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2528:
	/* 0x2528: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_252b:
	/* 0x252b: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_252d:
	/* 0x252d: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2531:
	/* 0x2531: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2536:
	/* 0x2536: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_253b:
	/* 0x253b: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2540:
	/* 0x2540: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2542:
	/* 0x2542: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2545:
	/* 0x2545: je     2712 <kprobe_unwind_native+0x2712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10002ULL;
	}
x86_l_254b:
	/* 0x254b: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_254f:
	/* 0x254f: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2552:
	/* 0x2552: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2557:
	/* 0x2557: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_255a:
	/* 0x255a: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_255e:
	/* 0x255e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2563:
	/* 0x2563: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_2566:
	/* 0x2566: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_256b:
	/* 0x256b: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_256d:
	/* 0x256d: jae    265e <kprobe_unwind_native+0x265e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9822ULL;
	}
x86_l_2573:
	/* 0x2573: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2578:
	/* 0x2578: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_257a:
	/* 0x257a: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_257c:
	/* 0x257c: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2580:
	/* 0x2580: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2585:
	/* 0x2585: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_258a:
	/* 0x258a: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_258f:
	/* 0x258f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2591:
	/* 0x2591: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2594:
	/* 0x2594: je     2712 <kprobe_unwind_native+0x2712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10002ULL;
	}
x86_l_259a:
	/* 0x259a: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_259e:
	/* 0x259e: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_25a2:
	/* 0x25a2: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_25a7:
	/* 0x25a7: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25aa:
	/* 0x25aa: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_25ae:
	/* 0x25ae: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25b3:
	/* 0x25b3: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_25b6:
	/* 0x25b6: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25bb:
	/* 0x25bb: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
	return 9662ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9662ULL: goto x86_l_25be;
	case 9668ULL: goto x86_l_25c4;
	case 9673ULL: goto x86_l_25c9;
	case 9676ULL: goto x86_l_25cc;
	case 9678ULL: goto x86_l_25ce;
	case 9682ULL: goto x86_l_25d2;
	case 9687ULL: goto x86_l_25d7;
	case 9692ULL: goto x86_l_25dc;
	case 9697ULL: goto x86_l_25e1;
	case 9699ULL: goto x86_l_25e3;
	case 9702ULL: goto x86_l_25e6;
	case 9708ULL: goto x86_l_25ec;
	case 9712ULL: goto x86_l_25f0;
	case 9715ULL: goto x86_l_25f3;
	case 9720ULL: goto x86_l_25f8;
	case 9723ULL: goto x86_l_25fb;
	case 9727ULL: goto x86_l_25ff;
	case 9732ULL: goto x86_l_2604;
	case 9735ULL: goto x86_l_2607;
	case 9740ULL: goto x86_l_260c;
	case 9742ULL: goto x86_l_260e;
	case 9744ULL: goto x86_l_2610;
	case 9749ULL: goto x86_l_2615;
	case 9751ULL: goto x86_l_2617;
	case 9753ULL: goto x86_l_2619;
	case 9757ULL: goto x86_l_261d;
	case 9762ULL: goto x86_l_2622;
	case 9767ULL: goto x86_l_2627;
	case 9772ULL: goto x86_l_262c;
	case 9774ULL: goto x86_l_262e;
	case 9777ULL: goto x86_l_2631;
	case 9783ULL: goto x86_l_2637;
	case 9787ULL: goto x86_l_263b;
	case 9790ULL: goto x86_l_263e;
	case 9795ULL: goto x86_l_2643;
	case 9798ULL: goto x86_l_2646;
	case 9801ULL: goto x86_l_2649;
	case 9806ULL: goto x86_l_264e;
	case 9809ULL: goto x86_l_2651;
	case 9814ULL: goto x86_l_2656;
	case 9816ULL: goto x86_l_2658;
	case 9822ULL: goto x86_l_265e;
	case 9827ULL: goto x86_l_2663;
	case 9830ULL: goto x86_l_2666;
	case 9832ULL: goto x86_l_2668;
	case 9838ULL: goto x86_l_266e;
	case 9841ULL: goto x86_l_2671;
	case 9849ULL: goto x86_l_2679;
	case 9857ULL: goto x86_l_2681;
	case 9862ULL: goto x86_l_2686;
	case 9867ULL: goto x86_l_268b;
	case 9869ULL: goto x86_l_268d;
	case 9872ULL: goto x86_l_2690;
	case 9878ULL: goto x86_l_2696;
	case 9881ULL: goto x86_l_2699;
	case 9888ULL: goto x86_l_26a0;
	case 9891ULL: goto x86_l_26a3;
	case 9897ULL: goto x86_l_26a9;
	case 9902ULL: goto x86_l_26ae;
	case 9906ULL: goto x86_l_26b2;
	case 9908ULL: goto x86_l_26b4;
	case 9915ULL: goto x86_l_26bb;
	case 9919ULL: goto x86_l_26bf;
	case 9926ULL: goto x86_l_26c6;
	case 9930ULL: goto x86_l_26ca;
	case 9934ULL: goto x86_l_26ce;
	case 9941ULL: goto x86_l_26d5;
	case 9946ULL: goto x86_l_26da;
	case 9952ULL: goto x86_l_26e0;
	case 9957ULL: goto x86_l_26e5;
	case 9959ULL: goto x86_l_26e7;
	case 9970ULL: goto x86_l_26f2;
	case 9977ULL: goto x86_l_26f9;
	case 9985ULL: goto x86_l_2701;
	case 9990ULL: goto x86_l_2706;
	case 9992ULL: goto x86_l_2708;
	case 9995ULL: goto x86_l_270b;
	case 9997ULL: goto x86_l_270d;
	case 10000ULL: goto x86_l_2710;
	case 10002ULL: goto x86_l_2712;
	case 10009ULL: goto x86_l_2719;
	case 10012ULL: goto x86_l_271c;
	case 10018ULL: goto x86_l_2722;
	case 10023ULL: goto x86_l_2727;
	case 10028ULL: goto x86_l_272c;
	case 10033ULL: goto x86_l_2731;
	case 10040ULL: goto x86_l_2738;
	case 10043ULL: goto x86_l_273b;
	case 10049ULL: goto x86_l_2741;
	case 10056ULL: goto x86_l_2748;
	case 10059ULL: goto x86_l_274b;
	case 10065ULL: goto x86_l_2751;
	case 10072ULL: goto x86_l_2758;
	case 10080ULL: goto x86_l_2760;
	case 10085ULL: goto x86_l_2765;
	case 10087ULL: goto x86_l_2767;
	case 10092ULL: goto x86_l_276c;
	case 10095ULL: goto x86_l_276f;
	case 10103ULL: goto x86_l_2777;
	case 10109ULL: goto x86_l_277d;
	case 10114ULL: goto x86_l_2782;
	case 10117ULL: goto x86_l_2785;
	case 10121ULL: goto x86_l_2789;
	case 10123ULL: goto x86_l_278b;
	case 10125ULL: goto x86_l_278d;
	case 10132ULL: goto x86_l_2794;
	case 10135ULL: goto x86_l_2797;
	case 10141ULL: goto x86_l_279d;
	case 10143ULL: goto x86_l_279f;
	case 10146ULL: goto x86_l_27a2;
	case 10149ULL: goto x86_l_27a5;
	case 10152ULL: goto x86_l_27a8;
	case 10154ULL: goto x86_l_27aa;
	case 10156ULL: goto x86_l_27ac;
	case 10158ULL: goto x86_l_27ae;
	case 10161ULL: goto x86_l_27b1;
	case 10164ULL: goto x86_l_27b4;
	case 10166ULL: goto x86_l_27b6;
	case 10169ULL: goto x86_l_27b9;
	case 10176ULL: goto x86_l_27c0;
	case 10179ULL: goto x86_l_27c3;
	case 10185ULL: goto x86_l_27c9;
	case 10190ULL: goto x86_l_27ce;
	case 10193ULL: goto x86_l_27d1;
	case 10195ULL: goto x86_l_27d3;
	case 10198ULL: goto x86_l_27d6;
	case 10200ULL: goto x86_l_27d8;
	case 10203ULL: goto x86_l_27db;
	case 10205ULL: goto x86_l_27dd;
	case 10208ULL: goto x86_l_27e0;
	case 10211ULL: goto x86_l_27e3;
	case 10214ULL: goto x86_l_27e6;
	case 10220ULL: goto x86_l_27ec;
	case 10223ULL: goto x86_l_27ef;
	case 10229ULL: goto x86_l_27f5;
	case 10232ULL: goto x86_l_27f8;
	case 10235ULL: goto x86_l_27fb;
	case 10241ULL: goto x86_l_2801;
	case 10246ULL: goto x86_l_2806;
	case 10251ULL: goto x86_l_280b;
	case 10257ULL: goto x86_l_2811;
	case 10260ULL: goto x86_l_2814;
	case 10266ULL: goto x86_l_281a;
	case 10269ULL: goto x86_l_281d;
	case 10274ULL: goto x86_l_2822;
	case 10282ULL: goto x86_l_282a;
	case 10290ULL: goto x86_l_2832;
	case 10296ULL: goto x86_l_2838;
	case 10299ULL: goto x86_l_283b;
	case 10305ULL: goto x86_l_2841;
	case 10308ULL: goto x86_l_2844;
	case 10311ULL: goto x86_l_2847;
	case 10313ULL: goto x86_l_2849;
	case 10316ULL: goto x86_l_284c;
	case 10318ULL: goto x86_l_284e;
	case 10321ULL: goto x86_l_2851;
	case 10324ULL: goto x86_l_2854;
	case 10328ULL: goto x86_l_2858;
	case 10332ULL: goto x86_l_285c;
	case 10339ULL: goto x86_l_2863;
	case 10342ULL: goto x86_l_2866;
	case 10348ULL: goto x86_l_286c;
	case 10358ULL: goto x86_l_2876;
	case 10363ULL: goto x86_l_287b;
	case 10373ULL: goto x86_l_2885;
	case 10378ULL: goto x86_l_288a;
	case 10383ULL: goto x86_l_288f;
	case 10388ULL: goto x86_l_2894;
	case 10393ULL: goto x86_l_2899;
	case 10398ULL: goto x86_l_289e;
	case 10401ULL: goto x86_l_28a1;
	case 10403ULL: goto x86_l_28a3;
	case 10405ULL: goto x86_l_28a5;
	case 10410ULL: goto x86_l_28aa;
	case 10413ULL: goto x86_l_28ad;
	case 10419ULL: goto x86_l_28b3;
	case 10422ULL: goto x86_l_28b6;
	case 10427ULL: goto x86_l_28bb;
	case 10432ULL: goto x86_l_28c0;
	case 10440ULL: goto x86_l_28c8;
	case 10446ULL: goto x86_l_28ce;
	case 10449ULL: goto x86_l_28d1;
	case 10454ULL: goto x86_l_28d6;
	case 10459ULL: goto x86_l_28db;
	case 10465ULL: goto x86_l_28e1;
	case 10468ULL: goto x86_l_28e4;
	case 10473ULL: goto x86_l_28e9;
	case 10476ULL: goto x86_l_28ec;
	case 10479ULL: goto x86_l_28ef;
	case 10485ULL: goto x86_l_28f5;
	case 10492ULL: goto x86_l_28fc;
	case 10496ULL: goto x86_l_2900;
	case 10503ULL: goto x86_l_2907;
	case 10508ULL: goto x86_l_290c;
	case 10515ULL: goto x86_l_2913;
	case 10520ULL: goto x86_l_2918;
	case 10527ULL: goto x86_l_291f;
	case 10532ULL: goto x86_l_2924;
	case 10535ULL: goto x86_l_2927;
	case 10541ULL: goto x86_l_292d;
	case 10544ULL: goto x86_l_2930;
	case 10550ULL: goto x86_l_2936;
	case 10552ULL: goto x86_l_2938;
	case 10554ULL: goto x86_l_293a;
	case 10557ULL: goto x86_l_293d;
	case 10559ULL: goto x86_l_293f;
	case 10564ULL: goto x86_l_2944;
	case 10571ULL: goto x86_l_294b;
	case 10574ULL: goto x86_l_294e;
	case 10580ULL: goto x86_l_2954;
	case 10583ULL: goto x86_l_2957;
	case 10586ULL: goto x86_l_295a;
	case 10589ULL: goto x86_l_295d;
	case 10595ULL: goto x86_l_2963;
	case 10603ULL: goto x86_l_296b;
	case 10605ULL: goto x86_l_296d;
	case 10611ULL: goto x86_l_2973;
	case 10614ULL: goto x86_l_2976;
	case 10620ULL: goto x86_l_297c;
	case 10628ULL: goto x86_l_2984;
	case 10633ULL: goto x86_l_2989;
	case 10641ULL: goto x86_l_2991;
	case 10644ULL: goto x86_l_2994;
	case 10648ULL: goto x86_l_2998;
	case 10656ULL: goto x86_l_29a0;
	case 10661ULL: goto x86_l_29a5;
	case 10667ULL: goto x86_l_29ab;
	case 10670ULL: goto x86_l_29ae;
	case 10673ULL: goto x86_l_29b1;
	case 10677ULL: goto x86_l_29b5;
	case 10682ULL: goto x86_l_29ba;
	case 10685ULL: goto x86_l_29bd;
	case 10688ULL: goto x86_l_29c0;
	case 10693ULL: goto x86_l_29c5;
	case 10699ULL: goto x86_l_29cb;
	case 10707ULL: goto x86_l_29d3;
	case 10714ULL: goto x86_l_29da;
	case 10722ULL: goto x86_l_29e2;
	case 10729ULL: goto x86_l_29e9;
	case 10737ULL: goto x86_l_29f1;
	case 10744ULL: goto x86_l_29f8;
	case 10752ULL: goto x86_l_2a00;
	case 10759ULL: goto x86_l_2a07;
	case 10767ULL: goto x86_l_2a0f;
	case 10774ULL: goto x86_l_2a16;
	case 10782ULL: goto x86_l_2a1e;
	case 10789ULL: goto x86_l_2a25;
	case 10797ULL: goto x86_l_2a2d;
	case 10804ULL: goto x86_l_2a34;
	case 10812ULL: goto x86_l_2a3c;
	case 10819ULL: goto x86_l_2a43;
	case 10826ULL: goto x86_l_2a4a;
	case 10833ULL: goto x86_l_2a51;
	case 10836ULL: goto x86_l_2a54;
	case 10842ULL: goto x86_l_2a5a;
	case 10852ULL: goto x86_l_2a64;
	case 10857ULL: goto x86_l_2a69;
	case 10867ULL: goto x86_l_2a73;
	case 10872ULL: goto x86_l_2a78;
	case 10877ULL: goto x86_l_2a7d;
	case 10882ULL: goto x86_l_2a82;
	case 10887ULL: goto x86_l_2a87;
	case 10892ULL: goto x86_l_2a8c;
	case 10894ULL: goto x86_l_2a8e;
	case 10896ULL: goto x86_l_2a90;
	case 10901ULL: goto x86_l_2a95;
	case 10906ULL: goto x86_l_2a9a;
	case 10909ULL: goto x86_l_2a9d;
	case 10912ULL: goto x86_l_2aa0;
	case 10915ULL: goto x86_l_2aa3;
	case 10918ULL: goto x86_l_2aa6;
	case 10920ULL: goto x86_l_2aa8;
	case 10926ULL: goto x86_l_2aae;
	case 10931ULL: goto x86_l_2ab3;
	case 10936ULL: goto x86_l_2ab8;
	case 10941ULL: goto x86_l_2abd;
	case 10946ULL: goto x86_l_2ac2;
	case 10949ULL: goto x86_l_2ac5;
	case 10951ULL: goto x86_l_2ac7;
	case 10954ULL: goto x86_l_2aca;
	case 10956ULL: goto x86_l_2acc;
	case 10963ULL: goto x86_l_2ad3;
	case 10966ULL: goto x86_l_2ad6;
	case 10972ULL: goto x86_l_2adc;
	case 10975ULL: goto x86_l_2adf;
	case 10980ULL: goto x86_l_2ae4;
	case 10983ULL: goto x86_l_2ae7;
	case 10986ULL: goto x86_l_2aea;
	case 10991ULL: goto x86_l_2aef;
	case 10994ULL: goto x86_l_2af2;
	case 10999ULL: goto x86_l_2af7;
	case 11005ULL: goto x86_l_2afd;
	case 11015ULL: goto x86_l_2b07;
	case 11023ULL: goto x86_l_2b0f;
	case 11033ULL: goto x86_l_2b19;
	case 11041ULL: goto x86_l_2b21;
	case 11051ULL: goto x86_l_2b2b;
	case 11059ULL: goto x86_l_2b33;
	case 11070ULL: goto x86_l_2b3e;
	case 11078ULL: goto x86_l_2b46;
	case 11083ULL: goto x86_l_2b4b;
	case 11088ULL: goto x86_l_2b50;
	case 11093ULL: goto x86_l_2b55;
	case 11095ULL: goto x86_l_2b57;
	case 11097ULL: goto x86_l_2b59;
	case 11102ULL: goto x86_l_2b5e;
	case 11112ULL: goto x86_l_2b68;
	case 11117ULL: goto x86_l_2b6d;
	case 11127ULL: goto x86_l_2b77;
	case 11132ULL: goto x86_l_2b7c;
	case 11142ULL: goto x86_l_2b86;
	case 11147ULL: goto x86_l_2b8b;
	case 11157ULL: goto x86_l_2b95;
	case 11162ULL: goto x86_l_2b9a;
	case 11167ULL: goto x86_l_2b9f;
	case 11172ULL: goto x86_l_2ba4;
	case 11177ULL: goto x86_l_2ba9;
	case 11183ULL: goto x86_l_2baf;
	case 11190ULL: goto x86_l_2bb6;
	case 11197ULL: goto x86_l_2bbd;
	case 11202ULL: goto x86_l_2bc2;
	case 11204ULL: goto x86_l_2bc4;
	case 11207ULL: goto x86_l_2bc7;
	case 11212ULL: goto x86_l_2bcc;
	case 11222ULL: goto x86_l_2bd6;
	case 11230ULL: goto x86_l_2bde;
	case 11240ULL: goto x86_l_2be8;
	case 11248ULL: goto x86_l_2bf0;
	case 11258ULL: goto x86_l_2bfa;
	case 11266ULL: goto x86_l_2c02;
	case 11276ULL: goto x86_l_2c0c;
	case 11284ULL: goto x86_l_2c14;
	case 11294ULL: goto x86_l_2c1e;
	case 11302ULL: goto x86_l_2c26;
	case 11312ULL: goto x86_l_2c30;
	case 11320ULL: goto x86_l_2c38;
	case 11328ULL: goto x86_l_2c40;
	case 11333ULL: goto x86_l_2c45;
	case 11338ULL: goto x86_l_2c4a;
	case 11342ULL: goto x86_l_2c4e;
	case 11347ULL: goto x86_l_2c53;
	case 11349ULL: goto x86_l_2c55;
	case 11351ULL: goto x86_l_2c57;
	case 11356ULL: goto x86_l_2c5c;
	case 11362ULL: goto x86_l_2c62;
	case 11367ULL: goto x86_l_2c67;
	case 11377ULL: goto x86_l_2c71;
	case 11382ULL: goto x86_l_2c76;
	case 11392ULL: goto x86_l_2c80;
	case 11397ULL: goto x86_l_2c85;
	case 11407ULL: goto x86_l_2c8f;
	case 11412ULL: goto x86_l_2c94;
	case 11422ULL: goto x86_l_2c9e;
	case 11427ULL: goto x86_l_2ca3;
	case 11437ULL: goto x86_l_2cad;
	case 11442ULL: goto x86_l_2cb2;
	case 11452ULL: goto x86_l_2cbc;
	case 11457ULL: goto x86_l_2cc1;
	case 11462ULL: goto x86_l_2cc6;
	case 11467ULL: goto x86_l_2ccb;
	case 11473ULL: goto x86_l_2cd1;
	case 11476ULL: goto x86_l_2cd4;
	case 11481ULL: goto x86_l_2cd9;
	case 11486ULL: goto x86_l_2cde;
	case 11489ULL: goto x86_l_2ce1;
	case 11491ULL: goto x86_l_2ce3;
	case 11494ULL: goto x86_l_2ce6;
	case 11499ULL: goto x86_l_2ceb;
	case 11509ULL: goto x86_l_2cf5;
	case 11514ULL: goto x86_l_2cfa;
	case 11524ULL: goto x86_l_2d04;
	case 11529ULL: goto x86_l_2d09;
	case 11539ULL: goto x86_l_2d13;
	case 11544ULL: goto x86_l_2d18;
	case 11554ULL: goto x86_l_2d22;
	case 11559ULL: goto x86_l_2d27;
	case 11569ULL: goto x86_l_2d31;
	case 11574ULL: goto x86_l_2d36;
	case 11582ULL: goto x86_l_2d3e;
	case 11587ULL: goto x86_l_2d43;
	case 11592ULL: goto x86_l_2d48;
	case 11597ULL: goto x86_l_2d4d;
	case 11602ULL: goto x86_l_2d52;
	case 11604ULL: goto x86_l_2d54;
	default: return 0xffffffffffffffffULL;
	}
x86_l_25be:
	/* 0x25be: jae    265e <kprobe_unwind_native+0x265e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_265e;
	}
x86_l_25c4:
	/* 0x25c4: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25c9:
	/* 0x25c9: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_25cc:
	/* 0x25cc: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_25ce:
	/* 0x25ce: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25d2:
	/* 0x25d2: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25d7:
	/* 0x25d7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_25dc:
	/* 0x25dc: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_25e1:
	/* 0x25e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25e3:
	/* 0x25e3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25e6:
	/* 0x25e6: je     2712 <kprobe_unwind_native+0x2712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2712;
	}
x86_l_25ec:
	/* 0x25ec: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25f0:
	/* 0x25f0: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_25f3:
	/* 0x25f3: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_25f8:
	/* 0x25f8: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25fb:
	/* 0x25fb: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_25ff:
	/* 0x25ff: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2604:
	/* 0x2604: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_2607:
	/* 0x2607: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_260c:
	/* 0x260c: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_260e:
	/* 0x260e: jae    265e <kprobe_unwind_native+0x265e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_265e;
	}
x86_l_2610:
	/* 0x2610: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2615:
	/* 0x2615: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2617:
	/* 0x2617: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_2619:
	/* 0x2619: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_261d:
	/* 0x261d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2622:
	/* 0x2622: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2627:
	/* 0x2627: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_262c:
	/* 0x262c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_262e:
	/* 0x262e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2631:
	/* 0x2631: je     2712 <kprobe_unwind_native+0x2712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2712;
	}
x86_l_2637:
	/* 0x2637: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_263b:
	/* 0x263b: lea    edx,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_263e:
	/* 0x263e: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2643:
	/* 0x2643: cmp    WORD PTR [rax],si */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2646:
	/* 0x2646: cmova  edx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_2649:
	/* 0x2649: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_264e:
	/* 0x264e: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_2651:
	/* 0x2651: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2656:
	/* 0x2656: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_2658:
	/* 0x2658: jb     2712 <kprobe_unwind_native+0x2712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2712;
	}
x86_l_265e:
	/* 0x265e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2663:
	/* 0x2663: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_2666:
	/* 0x2666: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2668:
	/* 0x2668: je     2712 <kprobe_unwind_native+0x2712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2712;
	}
x86_l_266e:
	/* 0x266e: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2671:
	/* 0x2671: mov    DWORD PTR [rsp+0x90],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2679:
	/* 0x2679: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2681:
	/* 0x2681: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2686:
	/* 0x2686: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_268b:
	/* 0x268b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_268d:
	/* 0x268d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2690:
	/* 0x2690: je     42fb <kprobe_unwind_native+0x42fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17147ULL;
	}
x86_l_2696:
	/* 0x2696: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2699:
	/* 0x2699: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_26a0:
	/* 0x26a0: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26a3:
	/* 0x26a3: jne    2d5b <kprobe_unwind_native+0x2d5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11611ULL;
	}
x86_l_26a9:
	/* 0x26a9: movzx  eax,WORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 88ULL);
x86_l_26ae:
	/* 0x26ae: movzx  ecx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_26b2:
	/* 0x26b2: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_26b4:
	/* 0x26b4: mov    ecx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_26bb:
	/* 0x26bb: cmp    ecx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_26bf:
	/* 0x26bf: lea    r13d,[rax+0x10000] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 65536ULL);
x86_l_26c6:
	/* 0x26c6: cmovae r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_26ca:
	/* 0x26ca: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_26ce:
	/* 0x26ce: mov    DWORD PTR [rsp+0x8c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_26d5:
	/* 0x26d5: cmp    eax,0x8000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32768ULL);
x86_l_26da:
	/* 0x26da: je     42de <kprobe_unwind_native+0x42de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17118ULL;
	}
x86_l_26e0:
	/* 0x26e0: cmp    eax,0x8001 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32769ULL);
x86_l_26e5:
	/* 0x26e5: jne    2748 <kprobe_unwind_native+0x2748> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2748;
	}
x86_l_26e7:
	/* 0x26e7: mov    DWORD PTR [rsp+0x94],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159815ULL);
x86_l_26f2:
	/* 0x26f2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_26f9:
	/* 0x26f9: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_2701:
	/* 0x2701: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2706:
	/* 0x2706: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2708:
	/* 0x2708: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_270b:
	/* 0x270b: je     2731 <kprobe_unwind_native+0x2731> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2731;
	}
x86_l_270d:
	/* 0x270d: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2710:
	/* 0x2710: jmp    2741 <kprobe_unwind_native+0x2741> */
	goto x86_l_2741;
x86_l_2712:
	/* 0x2712: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_2719:
	/* 0x2719: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_271c:
	/* 0x271c: jne    2ceb <kprobe_unwind_native+0x2ceb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ceb;
	}
x86_l_2722:
	/* 0x2722: mov    ecx,0xfa3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4003ULL);
x86_l_2727:
	/* 0x2727: mov    edx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_272c:
	/* 0x272c: jmp    42e8 <kprobe_unwind_native+0x42e8> */
	return 17128ULL;
x86_l_2731:
	/* 0x2731: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_2738:
	/* 0x2738: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_273b:
	/* 0x273b: jne    2ee8 <kprobe_unwind_native+0x2ee8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12008ULL;
	}
x86_l_2741:
	/* 0x2741: mov    eax,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_2748:
	/* 0x2748: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_274b:
	/* 0x274b: js     2806 <kprobe_unwind_native+0x2806> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2806;
	}
x86_l_2751:
	/* 0x2751: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&unwind_info_array)));
x86_l_2758:
	/* 0x2758: lea    rsi,[rsp+0x8c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_2760:
	/* 0x2760: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2765:
	/* 0x2765: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2767:
	/* 0x2767: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_276c:
	/* 0x276c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_276f:
	/* 0x276f: mov    r15,QWORD PTR [rsp+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_2777:
	/* 0x2777: je     6315 <kprobe_unwind_native+0x6315> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25365ULL;
	}
x86_l_277d:
	/* 0x277d: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2782:
	/* 0x2782: mov    ebp,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2785:
	/* 0x2785: movzx  eax,BYTE PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_2789:
	/* 0x2789: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_278b:
	/* 0x278b: je     27c9 <kprobe_unwind_native+0x27c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27c9;
	}
x86_l_278d:
	/* 0x278d: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_2794:
	/* 0x2794: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2797:
	/* 0x2797: jne    2e74 <kprobe_unwind_native+0x2e74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11892ULL;
	}
x86_l_279d:
	/* 0x279d: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_279f:
	/* 0x279f: and    cl,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_27a2:
	/* 0x27a2: movzx  ecx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_27a5:
	/* 0x27a5: cmp    r13d,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RCX, X86_WIDTH_32);
x86_l_27a8:
	/* 0x27a8: jl     27c9 <kprobe_unwind_native+0x27c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_27c9;
	}
x86_l_27aa:
	/* 0x27aa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27ac:
	/* 0x27ac: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_27ae:
	/* 0x27ae: setns  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NS);
x86_l_27b1:
	/* 0x27b1: shl    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_27b4:
	/* 0x27b4: add    ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_27b6:
	/* 0x27b6: add    ebp,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4294967288ULL);
x86_l_27b9:
	/* 0x27b9: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_27c0:
	/* 0x27c0: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27c3:
	/* 0x27c3: jne    2f66 <kprobe_unwind_native+0x2f66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12134ULL;
	}
x86_l_27c9:
	/* 0x27c9: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_27ce:
	/* 0x27ce: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_27d1:
	/* 0x27d1: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_27d3:
	/* 0x27d3: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_27d6:
	/* 0x27d6: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_27d8:
	/* 0x27d8: cmovns ecx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBP, X86_WIDTH_32, X86_CC_NS);
x86_l_27db:
	/* 0x27db: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_27dd:
	/* 0x27dd: and    edx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_27e0:
	/* 0x27e0: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27e3:
	/* 0x27e3: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_27e6:
	/* 0x27e6: jg     2924 <kprobe_unwind_native+0x2924> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2924;
	}
x86_l_27ec:
	/* 0x27ec: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_27ef:
	/* 0x27ef: je     2a9d <kprobe_unwind_native+0x2a9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a9d;
	}
x86_l_27f5:
	/* 0x27f5: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_27f8:
	/* 0x27f8: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_27fb:
	/* 0x27fb: je     2a9a <kprobe_unwind_native+0x2a9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a9a;
	}
x86_l_2801:
	/* 0x2801: jmp    3040 <kprobe_unwind_native+0x3040> */
	return 12352ULL;
x86_l_2806:
	/* 0x2806: and    eax,0xffff7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294934527ULL);
x86_l_280b:
	/* 0x280b: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_2811:
	/* 0x2811: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2814:
	/* 0x2814: jg     28aa <kprobe_unwind_native+0x28aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_28aa;
	}
x86_l_281a:
	/* 0x281a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_281d:
	/* 0x281d: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2822:
	/* 0x2822: mov    rcx,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_282a:
	/* 0x282a: mov    rdx,QWORD PTR [rsp+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_2832:
	/* 0x2832: je     6474 <kprobe_unwind_native+0x6474> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25716ULL;
	}
x86_l_2838:
	/* 0x2838: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_283b:
	/* 0x283b: jne    5f4c <kprobe_unwind_native+0x5f4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24396ULL;
	}
x86_l_2841:
	/* 0x2841: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_2844:
	/* 0x2844: mov    rax,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2847:
	/* 0x2847: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2849:
	/* 0x2849: and    ecx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_284c:
	/* 0x284c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_284e:
	/* 0x284e: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_2851:
	/* 0x2851: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_2854:
	/* 0x2854: lea    r13,[rax+rdx*8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_2858:
	/* 0x2858: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_285c:
	/* 0x285c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_2863:
	/* 0x2863: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2866:
	/* 0x2866: je     3255 <kprobe_unwind_native+0x3255> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12885ULL;
	}
x86_l_286c:
	/* 0x286c: movabs rax,0xa786c2578303d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541309ULL);
x86_l_2876:
	/* 0x2876: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_287b:
	/* 0x287b: movabs rax,0x616663202c544c50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018406059137322064ULL);
x86_l_2885:
	/* 0x2885: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_288a:
	/* 0x288a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_288f:
	/* 0x288f: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_2894:
	/* 0x2894: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2899:
	/* 0x2899: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_289e:
	/* 0x289e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_28a1:
	/* 0x28a1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28a3:
	/* 0x28a3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_28a5:
	/* 0x28a5: jmp    3255 <kprobe_unwind_native+0x3255> */
	return 12885ULL;
x86_l_28aa:
	/* 0x28aa: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_28ad:
	/* 0x28ad: je     2989 <kprobe_unwind_native+0x2989> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2989;
	}
x86_l_28b3:
	/* 0x28b3: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28b6:
	/* 0x28b6: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_28bb:
	/* 0x28bb: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_28c0:
	/* 0x28c0: mov    r15,QWORD PTR [rsp+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_28c8:
	/* 0x28c8: jne    5f4c <kprobe_unwind_native+0x5f4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24396ULL;
	}
x86_l_28ce:
	/* 0x28ce: mov    rax,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28d1:
	/* 0x28d1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28d6:
	/* 0x28d6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_28db:
	/* 0x28db: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_28e1:
	/* 0x28e1: mov    rdx,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28e4:
	/* 0x28e4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_28e9:
	/* 0x28e9: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_28ec:
	/* 0x28ec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28ef:
	/* 0x28ef: jne    1640 <kprobe_unwind_native+0x1640> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5696ULL;
	}
x86_l_28f5:
	/* 0x28f5: mov    rax,QWORD PTR [rbx+0xee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_28fc:
	/* 0x28fc: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2900:
	/* 0x2900: mov    QWORD PTR [rbx+0xed8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_2907:
	/* 0x2907: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_290c:
	/* 0x290c: mov    QWORD PTR [rbx+0xee0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_2913:
	/* 0x2913: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2918:
	/* 0x2918: mov    QWORD PTR [rbx+0xed0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_291f:
	/* 0x291f: jmp    3290 <kprobe_unwind_native+0x3290> */
	return 12944ULL;
x86_l_2924:
	/* 0x2924: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2927:
	/* 0x2927: je     2a95 <kprobe_unwind_native+0x2a95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a95;
	}
x86_l_292d:
	/* 0x292d: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_2930:
	/* 0x2930: jne    3040 <kprobe_unwind_native+0x3040> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12352ULL;
	}
x86_l_2936:
	/* 0x2936: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_2938:
	/* 0x2938: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_293a:
	/* 0x293a: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_293d:
	/* 0x293d: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_293f:
	/* 0x293f: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2944:
	/* 0x2944: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_294b:
	/* 0x294b: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_294e:
	/* 0x294e: jne    2fcb <kprobe_unwind_native+0x2fcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12235ULL;
	}
x86_l_2954:
	/* 0x2954: and    ebp,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2957:
	/* 0x2957: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_295a:
	/* 0x295a: cmp    ebp,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_295d:
	/* 0x295d: jg     301e <kprobe_unwind_native+0x301e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 12318ULL;
	}
x86_l_2963:
	/* 0x2963: mov    rax,QWORD PTR [rsp+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_296b:
	/* 0x296b: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_296d:
	/* 0x296d: je     3038 <kprobe_unwind_native+0x3038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12344ULL;
	}
x86_l_2973:
	/* 0x2973: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_2976:
	/* 0x2976: jne    3040 <kprobe_unwind_native+0x3040> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12352ULL;
	}
x86_l_297c:
	/* 0x297c: mov    rax,QWORD PTR [rsp+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_2984:
	/* 0x2984: jmp    3038 <kprobe_unwind_native+0x3038> */
	return 12344ULL;
x86_l_2989:
	/* 0x2989: mov    rdx,QWORD PTR [rsp+0x158] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 344ULL);
x86_l_2991:
	/* 0x2991: mov    rax,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2994:
	/* 0x2994: add    rax,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_2998:
	/* 0x2998: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_29a0:
	/* 0x29a0: mov    ecx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 144ULL);
x86_l_29a5:
	/* 0x29a5: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_29ab:
	/* 0x29ab: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_29ae:
	/* 0x29ae: mov    rdx,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29b1:
	/* 0x29b1: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_29b5:
	/* 0x29b5: mov    esi,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 144ULL);
x86_l_29ba:
	/* 0x29ba: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_29bd:
	/* 0x29bd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29c0:
	/* 0x29c0: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_29c5:
	/* 0x29c5: jne    1640 <kprobe_unwind_native+0x1640> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5696ULL;
	}
x86_l_29cb:
	/* 0x29cb: mov    rax,QWORD PTR [rsp+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_29d3:
	/* 0x29d3: mov    QWORD PTR [rbx+0xee8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3816ULL);
x86_l_29da:
	/* 0x29da: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_29e2:
	/* 0x29e2: mov    QWORD PTR [rbx+0xef0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3824ULL);
x86_l_29e9:
	/* 0x29e9: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_29f1:
	/* 0x29f1: mov    QWORD PTR [rbx+0xef8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3832ULL);
x86_l_29f8:
	/* 0x29f8: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2a00:
	/* 0x2a00: mov    QWORD PTR [rbx+0xf00],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3840ULL);
x86_l_2a07:
	/* 0x2a07: mov    rax,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2a0f:
	/* 0x2a0f: mov    QWORD PTR [rbx+0xf08],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3848ULL);
x86_l_2a16:
	/* 0x2a16: mov    rax,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2a1e:
	/* 0x2a1e: mov    QWORD PTR [rbx+0xee0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_2a25:
	/* 0x2a25: mov    rax,QWORD PTR [rsp+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2a2d:
	/* 0x2a2d: mov    QWORD PTR [rbx+0xed8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_2a34:
	/* 0x2a34: mov    rax,QWORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2a3c:
	/* 0x2a3c: mov    QWORD PTR [rbx+0xed0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_2a43:
	/* 0x2a43: mov    BYTE PTR [rbx+0xf30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16698832846848ULL);
x86_l_2a4a:
	/* 0x2a4a: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_2a51:
	/* 0x2a51: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a54:
	/* 0x2a54: je     3297 <kprobe_unwind_native+0x3297> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12951ULL;
	}
x86_l_2a5a:
	/* 0x2a5a: movabs rax,0xa656d61726620 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926270227834400ULL);
x86_l_2a64:
	/* 0x2a64: mov    QWORD PTR [rsp+0x16],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_2a69:
	/* 0x2a69: movabs rax,0x66206c616e676973 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7359000956843288947ULL);
x86_l_2a73:
	/* 0x2a73: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a78:
	/* 0x2a78: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a7d:
	/* 0x2a7d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2a82:
	/* 0x2a82: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2a87:
	/* 0x2a87: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_2a8c:
	/* 0x2a8c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a8e:
	/* 0x2a8e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2a90:
	/* 0x2a90: jmp    3297 <kprobe_unwind_native+0x3297> */
	return 12951ULL;
x86_l_2a95:
	/* 0x2a95: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2a9a:
	/* 0x2a9a: mov    r13,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a9d:
	/* 0x2a9d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2aa0:
	/* 0x2aa0: movsxd r13,ecx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_2aa3:
	/* 0x2aa3: add    r13,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2aa6:
	/* 0x2aa6: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2aa8:
	/* 0x2aa8: jns    3040 <kprobe_unwind_native+0x3040> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 12352ULL;
	}
x86_l_2aae:
	/* 0x2aae: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2ab3:
	/* 0x2ab3: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_2ab8:
	/* 0x2ab8: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_2abd:
	/* 0x2abd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ac2:
	/* 0x2ac2: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2ac5:
	/* 0x2ac5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2ac7:
	/* 0x2ac7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2aca:
	/* 0x2aca: je     2ae4 <kprobe_unwind_native+0x2ae4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ae4;
	}
x86_l_2acc:
	/* 0x2acc: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_2ad3:
	/* 0x2ad3: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ad6:
	/* 0x2ad6: jne    3758 <kprobe_unwind_native+0x3758> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14168ULL;
	}
x86_l_2adc:
	/* 0x2adc: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2adf:
	/* 0x2adf: jmp    3040 <kprobe_unwind_native+0x3040> */
	return 12352ULL;
x86_l_2ae4:
	/* 0x2ae4: shl    ebp,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_2ae7:
	/* 0x2ae7: and    ebp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 56ULL);
x86_l_2aea:
	/* 0x2aea: add    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_2aef:
	/* 0x2aef: mov    r13,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_2af2:
	/* 0x2af2: jmp    3040 <kprobe_unwind_native+0x3040> */
	return 12352ULL;
x86_l_2af7:
	/* 0x2af7: mov    edx,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_2afd:
	/* 0x2afd: movabs rax,0x3d3d206425206576 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4412718824384652662ULL);
x86_l_2b07:
	/* 0x2b07: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2b0f:
	/* 0x2b0f: movabs rax,0x6974616e5f646e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598805597955583593ULL);
x86_l_2b19:
	/* 0x2b19: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2b21:
	/* 0x2b21: movabs rax,0x776e75203d3d3d3d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8605944719278423357ULL);
x86_l_2b2b:
	/* 0x2b2b: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2b33:
	/* 0x2b33: mov    DWORD PTR [rsp+0xb8],0xa3d3d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 790274653501ULL);
x86_l_2b3e:
	/* 0x2b3e: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2b46:
	/* 0x2b46: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_2b4b:
	/* 0x2b4b: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2b50:
	/* 0x2b50: mov    esi,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 28ULL);
x86_l_2b55:
	/* 0x2b55: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b57:
	/* 0x2b57: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2b59:
	/* 0x2b59: jmp    1e19 <kprobe_unwind_native+0x1e19> */
	return 7705ULL;
x86_l_2b5e:
	/* 0x2b5e: movabs rax,0xa786c253a786c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 754471844735118373ULL);
x86_l_2b68:
	/* 0x2b68: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b6d:
	/* 0x2b6d: movabs rax,0x20726f662061746c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338053640979313772ULL);
x86_l_2b77:
	/* 0x2b77: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b7c:
	/* 0x2b7c: movabs rax,0x6564206b63617473 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7306000141102707827ULL);
x86_l_2b86:
	/* 0x2b86: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b8b:
	/* 0x2b8b: movabs rax,0x207075206b6f6f4c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337496988707155788ULL);
x86_l_2b95:
	/* 0x2b95: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b9a:
	/* 0x2b9a: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2b9f:
	/* 0x2b9f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ba4:
	/* 0x2ba4: mov    eax,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_2ba9:
	/* 0x2ba9: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_2baf:
	/* 0x2baf: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_2bb6:
	/* 0x2bb6: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_2bbd:
	/* 0x2bbd: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_2bc2:
	/* 0x2bc2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bc4:
	/* 0x2bc4: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2bc7:
	/* 0x2bc7: jmp    1f95 <kprobe_unwind_native+0x1f95> */
	return 8085ULL;
x86_l_2bcc:
	/* 0x2bcc: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_2bd6:
	/* 0x2bd6: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_2bde:
	/* 0x2bde: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_2be8:
	/* 0x2be8: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2bf0:
	/* 0x2bf0: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_2bfa:
	/* 0x2bfa: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2c02:
	/* 0x2c02: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_2c0c:
	/* 0x2c0c: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2c14:
	/* 0x2c14: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_2c1e:
	/* 0x2c1e: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2c26:
	/* 0x2c26: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2c30:
	/* 0x2c30: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2c38:
	/* 0x2c38: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2c40:
	/* 0x2c40: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2c45:
	/* 0x2c45: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2c4a:
	/* 0x2c4a: mov    edx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c4e:
	/* 0x2c4e: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2c53:
	/* 0x2c53: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c55:
	/* 0x2c55: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2c57:
	/* 0x2c57: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c5c:
	/* 0x2c5c: je     1eef <kprobe_unwind_native+0x1eef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7919ULL;
	}
x86_l_2c62:
	/* 0x2c62: jmp    1e4b <kprobe_unwind_native+0x1e4b> */
	return 7755ULL;
x86_l_2c67:
	/* 0x2c67: movabs rax,0xa296425204449 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2860259863446601ULL);
x86_l_2c71:
	/* 0x2c71: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2c76:
	/* 0x2c76: movabs rax,0x70616d2820756c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8097873624099548197ULL);
x86_l_2c80:
	/* 0x2c80: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c85:
	/* 0x2c85: movabs rax,0x206f7420756c2520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414386373920ULL);
x86_l_2c8f:
	/* 0x2c8f: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c94:
	/* 0x2c94: movabs rax,0x6d6f726620656220 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7885647255504773664ULL);
x86_l_2c9e:
	/* 0x2c9e: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ca3:
	/* 0x2ca3: movabs rax,0x646c756f68732073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7236287822631739507ULL);
x86_l_2cad:
	/* 0x2cad: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cb2:
	/* 0x2cb2: movabs rax,0x6c61767265746e49 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7809653462537629257ULL);
x86_l_2cbc:
	/* 0x2cbc: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cc1:
	/* 0x2cc1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cc6:
	/* 0x2cc6: mov    eax,0x30 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 48ULL);
x86_l_2ccb:
	/* 0x2ccb: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_2cd1:
	/* 0x2cd1: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_2cd4:
	/* 0x2cd4: movzx  r8d,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2cd9:
	/* 0x2cd9: mov    esi,0x30 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 48ULL);
x86_l_2cde:
	/* 0x2cde: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2ce1:
	/* 0x2ce1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ce3:
	/* 0x2ce3: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_2ce6:
	/* 0x2ce6: jmp    2164 <kprobe_unwind_native+0x2164> */
	return 8548ULL;
x86_l_2ceb:
	/* 0x2ceb: movabs rax,0x6174616420747075 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7022344801646571637ULL);
x86_l_2cf5:
	/* 0x2cf5: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2cfa:
	/* 0x2cfa: movabs rax,0x72726f43202e7370 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8246776201762206576ULL);
x86_l_2d04:
	/* 0x2d04: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d09:
	/* 0x2d09: movabs rax,0x657473203631206e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310594677314494574ULL);
x86_l_2d13:
	/* 0x2d13: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d18:
	/* 0x2d18: movabs rax,0x6920686372616573 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575169349567210867ULL);
x86_l_2d22:
	/* 0x2d22: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d27:
	/* 0x2d27: movabs rax,0x622064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7070761801744998726ULL);
x86_l_2d31:
	/* 0x2d31: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d36:
	/* 0x2d36: mov    DWORD PTR [rsp+0x37],0xa3f61 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 236223872865ULL);
x86_l_2d3e:
	/* 0x2d3e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d43:
	/* 0x2d43: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2d48:
	/* 0x2d48: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2d4d:
	/* 0x2d4d: mov    esi,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 43ULL);
x86_l_2d52:
	/* 0x2d52: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d54:
	/* 0x2d54: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
	return 11606ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11606ULL: goto x86_l_2d56;
	case 11611ULL: goto x86_l_2d5b;
	case 11621ULL: goto x86_l_2d65;
	case 11626ULL: goto x86_l_2d6a;
	case 11636ULL: goto x86_l_2d74;
	case 11641ULL: goto x86_l_2d79;
	case 11651ULL: goto x86_l_2d83;
	case 11656ULL: goto x86_l_2d88;
	case 11666ULL: goto x86_l_2d92;
	case 11671ULL: goto x86_l_2d97;
	case 11681ULL: goto x86_l_2da1;
	case 11686ULL: goto x86_l_2da6;
	case 11696ULL: goto x86_l_2db0;
	case 11701ULL: goto x86_l_2db5;
	case 11706ULL: goto x86_l_2dba;
	case 11711ULL: goto x86_l_2dbf;
	case 11717ULL: goto x86_l_2dc5;
	case 11724ULL: goto x86_l_2dcc;
	case 11728ULL: goto x86_l_2dd0;
	case 11733ULL: goto x86_l_2dd5;
	case 11738ULL: goto x86_l_2dda;
	case 11740ULL: goto x86_l_2ddc;
	case 11743ULL: goto x86_l_2ddf;
	case 11748ULL: goto x86_l_2de4;
	case 11758ULL: goto x86_l_2dee;
	case 11766ULL: goto x86_l_2df6;
	case 11776ULL: goto x86_l_2e00;
	case 11784ULL: goto x86_l_2e08;
	case 11794ULL: goto x86_l_2e12;
	case 11802ULL: goto x86_l_2e1a;
	case 11812ULL: goto x86_l_2e24;
	case 11820ULL: goto x86_l_2e2c;
	case 11830ULL: goto x86_l_2e36;
	case 11838ULL: goto x86_l_2e3e;
	case 11848ULL: goto x86_l_2e48;
	case 11856ULL: goto x86_l_2e50;
	case 11864ULL: goto x86_l_2e58;
	case 11869ULL: goto x86_l_2e5d;
	case 11874ULL: goto x86_l_2e62;
	case 11878ULL: goto x86_l_2e66;
	case 11883ULL: goto x86_l_2e6b;
	case 11885ULL: goto x86_l_2e6d;
	case 11887ULL: goto x86_l_2e6f;
	case 11892ULL: goto x86_l_2e74;
	case 11902ULL: goto x86_l_2e7e;
	case 11907ULL: goto x86_l_2e83;
	case 11917ULL: goto x86_l_2e8d;
	case 11922ULL: goto x86_l_2e92;
	case 11932ULL: goto x86_l_2e9c;
	case 11937ULL: goto x86_l_2ea1;
	case 11947ULL: goto x86_l_2eab;
	case 11952ULL: goto x86_l_2eb0;
	case 11957ULL: goto x86_l_2eb5;
	case 11962ULL: goto x86_l_2eba;
	case 11967ULL: goto x86_l_2ebf;
	case 11973ULL: goto x86_l_2ec5;
	case 11978ULL: goto x86_l_2eca;
	case 11984ULL: goto x86_l_2ed0;
	case 11989ULL: goto x86_l_2ed5;
	case 11992ULL: goto x86_l_2ed8;
	case 11994ULL: goto x86_l_2eda;
	case 11997ULL: goto x86_l_2edd;
	case 12003ULL: goto x86_l_2ee3;
	case 12008ULL: goto x86_l_2ee8;
	case 12018ULL: goto x86_l_2ef2;
	case 12023ULL: goto x86_l_2ef7;
	case 12033ULL: goto x86_l_2f01;
	case 12038ULL: goto x86_l_2f06;
	case 12048ULL: goto x86_l_2f10;
	case 12053ULL: goto x86_l_2f15;
	case 12063ULL: goto x86_l_2f1f;
	case 12068ULL: goto x86_l_2f24;
	case 12078ULL: goto x86_l_2f2e;
	case 12083ULL: goto x86_l_2f33;
	case 12093ULL: goto x86_l_2f3d;
	case 12098ULL: goto x86_l_2f42;
	case 12103ULL: goto x86_l_2f47;
	case 12108ULL: goto x86_l_2f4c;
	case 12113ULL: goto x86_l_2f51;
	case 12120ULL: goto x86_l_2f58;
	case 12125ULL: goto x86_l_2f5d;
	case 12127ULL: goto x86_l_2f5f;
	case 12129ULL: goto x86_l_2f61;
	case 12134ULL: goto x86_l_2f66;
	case 12144ULL: goto x86_l_2f70;
	case 12149ULL: goto x86_l_2f75;
	case 12159ULL: goto x86_l_2f7f;
	case 12164ULL: goto x86_l_2f84;
	case 12174ULL: goto x86_l_2f8e;
	case 12179ULL: goto x86_l_2f93;
	case 12189ULL: goto x86_l_2f9d;
	case 12194ULL: goto x86_l_2fa2;
	case 12199ULL: goto x86_l_2fa7;
	case 12204ULL: goto x86_l_2fac;
	case 12209ULL: goto x86_l_2fb1;
	case 12214ULL: goto x86_l_2fb6;
	case 12221ULL: goto x86_l_2fbd;
	case 12226ULL: goto x86_l_2fc2;
	case 12228ULL: goto x86_l_2fc4;
	case 12230ULL: goto x86_l_2fc6;
	case 12235ULL: goto x86_l_2fcb;
	case 12245ULL: goto x86_l_2fd5;
	case 12250ULL: goto x86_l_2fda;
	case 12260ULL: goto x86_l_2fe4;
	case 12265ULL: goto x86_l_2fe9;
	case 12270ULL: goto x86_l_2fee;
	case 12275ULL: goto x86_l_2ff3;
	case 12280ULL: goto x86_l_2ff8;
	case 12286ULL: goto x86_l_2ffe;
	case 12289ULL: goto x86_l_3001;
	case 12294ULL: goto x86_l_3006;
	case 12299ULL: goto x86_l_300b;
	case 12301ULL: goto x86_l_300d;
	case 12303ULL: goto x86_l_300f;
	case 12306ULL: goto x86_l_3012;
	case 12309ULL: goto x86_l_3015;
	case 12312ULL: goto x86_l_3018;
	case 12318ULL: goto x86_l_301e;
	case 12326ULL: goto x86_l_3026;
	case 12329ULL: goto x86_l_3029;
	case 12331ULL: goto x86_l_302b;
	case 12339ULL: goto x86_l_3033;
	case 12342ULL: goto x86_l_3036;
	case 12344ULL: goto x86_l_3038;
	case 12349ULL: goto x86_l_303d;
	case 12352ULL: goto x86_l_3040;
	case 12357ULL: goto x86_l_3045;
	case 12361ULL: goto x86_l_3049;
	case 12365ULL: goto x86_l_304d;
	case 12368ULL: goto x86_l_3050;
	case 12371ULL: goto x86_l_3053;
	case 12373ULL: goto x86_l_3055;
	case 12377ULL: goto x86_l_3059;
	case 12379ULL: goto x86_l_305b;
	case 12382ULL: goto x86_l_305e;
	case 12385ULL: goto x86_l_3061;
	case 12387ULL: goto x86_l_3063;
	case 12390ULL: goto x86_l_3066;
	case 12393ULL: goto x86_l_3069;
	case 12395ULL: goto x86_l_306b;
	case 12398ULL: goto x86_l_306e;
	case 12401ULL: goto x86_l_3071;
	case 12403ULL: goto x86_l_3073;
	case 12408ULL: goto x86_l_3078;
	case 12411ULL: goto x86_l_307b;
	case 12413ULL: goto x86_l_307d;
	case 12416ULL: goto x86_l_3080;
	case 12422ULL: goto x86_l_3086;
	case 12425ULL: goto x86_l_3089;
	case 12427ULL: goto x86_l_308b;
	case 12430ULL: goto x86_l_308e;
	case 12432ULL: goto x86_l_3090;
	case 12437ULL: goto x86_l_3095;
	case 12444ULL: goto x86_l_309c;
	case 12447ULL: goto x86_l_309f;
	case 12453ULL: goto x86_l_30a5;
	case 12457ULL: goto x86_l_30a9;
	case 12461ULL: goto x86_l_30ad;
	case 12467ULL: goto x86_l_30b3;
	case 12475ULL: goto x86_l_30bb;
	case 12478ULL: goto x86_l_30be;
	case 12484ULL: goto x86_l_30c4;
	case 12488ULL: goto x86_l_30c8;
	case 12494ULL: goto x86_l_30ce;
	case 12502ULL: goto x86_l_30d6;
	case 12507ULL: goto x86_l_30db;
	case 12512ULL: goto x86_l_30e0;
	case 12515ULL: goto x86_l_30e3;
	case 12518ULL: goto x86_l_30e6;
	case 12521ULL: goto x86_l_30e9;
	case 12523ULL: goto x86_l_30eb;
	case 12529ULL: goto x86_l_30f1;
	case 12534ULL: goto x86_l_30f6;
	case 12539ULL: goto x86_l_30fb;
	case 12544ULL: goto x86_l_3100;
	case 12549ULL: goto x86_l_3105;
	case 12552ULL: goto x86_l_3108;
	case 12554ULL: goto x86_l_310a;
	case 12557ULL: goto x86_l_310d;
	case 12563ULL: goto x86_l_3113;
	case 12570ULL: goto x86_l_311a;
	case 12573ULL: goto x86_l_311d;
	case 12579ULL: goto x86_l_3123;
	case 12589ULL: goto x86_l_312d;
	case 12594ULL: goto x86_l_3132;
	case 12604ULL: goto x86_l_313c;
	case 12609ULL: goto x86_l_3141;
	case 12619ULL: goto x86_l_314b;
	case 12624ULL: goto x86_l_3150;
	case 12634ULL: goto x86_l_315a;
	case 12639ULL: goto x86_l_315f;
	case 12649ULL: goto x86_l_3169;
	case 12654ULL: goto x86_l_316e;
	case 12662ULL: goto x86_l_3176;
	case 12667ULL: goto x86_l_317b;
	case 12672ULL: goto x86_l_3180;
	case 12677ULL: goto x86_l_3185;
	case 12682ULL: goto x86_l_318a;
	case 12685ULL: goto x86_l_318d;
	case 12687ULL: goto x86_l_318f;
	case 12689ULL: goto x86_l_3191;
	case 12694ULL: goto x86_l_3196;
	case 12698ULL: goto x86_l_319a;
	case 12702ULL: goto x86_l_319e;
	case 12707ULL: goto x86_l_31a3;
	case 12710ULL: goto x86_l_31a6;
	case 12712ULL: goto x86_l_31a8;
	case 12722ULL: goto x86_l_31b2;
	case 12727ULL: goto x86_l_31b7;
	case 12737ULL: goto x86_l_31c1;
	case 12742ULL: goto x86_l_31c6;
	case 12747ULL: goto x86_l_31cb;
	case 12752ULL: goto x86_l_31d0;
	case 12757ULL: goto x86_l_31d5;
	case 12763ULL: goto x86_l_31db;
	case 12767ULL: goto x86_l_31df;
	case 12772ULL: goto x86_l_31e4;
	case 12777ULL: goto x86_l_31e9;
	case 12780ULL: goto x86_l_31ec;
	case 12782ULL: goto x86_l_31ee;
	case 12785ULL: goto x86_l_31f1;
	case 12789ULL: goto x86_l_31f5;
	case 12795ULL: goto x86_l_31fb;
	case 12803ULL: goto x86_l_3203;
	case 12807ULL: goto x86_l_3207;
	case 12809ULL: goto x86_l_3209;
	case 12817ULL: goto x86_l_3211;
	case 12821ULL: goto x86_l_3215;
	case 12823ULL: goto x86_l_3217;
	case 12828ULL: goto x86_l_321c;
	case 12831ULL: goto x86_l_321f;
	case 12834ULL: goto x86_l_3222;
	case 12836ULL: goto x86_l_3224;
	case 12841ULL: goto x86_l_3229;
	case 12846ULL: goto x86_l_322e;
	case 12851ULL: goto x86_l_3233;
	case 12856ULL: goto x86_l_3238;
	case 12859ULL: goto x86_l_323b;
	case 12861ULL: goto x86_l_323d;
	case 12863ULL: goto x86_l_323f;
	case 12868ULL: goto x86_l_3244;
	case 12871ULL: goto x86_l_3247;
	case 12873ULL: goto x86_l_3249;
	case 12878ULL: goto x86_l_324e;
	case 12885ULL: goto x86_l_3255;
	case 12888ULL: goto x86_l_3258;
	case 12893ULL: goto x86_l_325d;
	case 12899ULL: goto x86_l_3263;
	case 12903ULL: goto x86_l_3267;
	case 12908ULL: goto x86_l_326c;
	case 12913ULL: goto x86_l_3271;
	case 12921ULL: goto x86_l_3279;
	case 12926ULL: goto x86_l_327e;
	case 12928ULL: goto x86_l_3280;
	case 12931ULL: goto x86_l_3283;
	case 12937ULL: goto x86_l_3289;
	case 12944ULL: goto x86_l_3290;
	case 12951ULL: goto x86_l_3297;
	case 12959ULL: goto x86_l_329f;
	case 12966ULL: goto x86_l_32a6;
	case 12971ULL: goto x86_l_32ab;
	case 12976ULL: goto x86_l_32b0;
	case 12978ULL: goto x86_l_32b2;
	case 12981ULL: goto x86_l_32b5;
	case 12987ULL: goto x86_l_32bb;
	case 12990ULL: goto x86_l_32be;
	case 12992ULL: goto x86_l_32c0;
	case 12999ULL: goto x86_l_32c7;
	case 13002ULL: goto x86_l_32ca;
	case 13008ULL: goto x86_l_32d0;
	case 13018ULL: goto x86_l_32da;
	case 13026ULL: goto x86_l_32e2;
	case 13036ULL: goto x86_l_32ec;
	case 13044ULL: goto x86_l_32f4;
	case 13054ULL: goto x86_l_32fe;
	case 13062ULL: goto x86_l_3306;
	case 13072ULL: goto x86_l_3310;
	case 13080ULL: goto x86_l_3318;
	case 13088ULL: goto x86_l_3320;
	case 13093ULL: goto x86_l_3325;
	case 13099ULL: goto x86_l_332b;
	case 13107ULL: goto x86_l_3333;
	case 13110ULL: goto x86_l_3336;
	case 13113ULL: goto x86_l_3339;
	case 13118ULL: goto x86_l_333e;
	case 13121ULL: goto x86_l_3341;
	case 13126ULL: goto x86_l_3346;
	case 13128ULL: goto x86_l_3348;
	case 13131ULL: goto x86_l_334b;
	case 13138ULL: goto x86_l_3352;
	case 13140ULL: goto x86_l_3354;
	case 13142ULL: goto x86_l_3356;
	case 13149ULL: goto x86_l_335d;
	case 13152ULL: goto x86_l_3360;
	case 13158ULL: goto x86_l_3366;
	case 13160ULL: goto x86_l_3368;
	case 13168ULL: goto x86_l_3370;
	case 13171ULL: goto x86_l_3373;
	case 13174ULL: goto x86_l_3376;
	case 13180ULL: goto x86_l_337c;
	case 13182ULL: goto x86_l_337e;
	case 13188ULL: goto x86_l_3384;
	case 13198ULL: goto x86_l_338e;
	case 13201ULL: goto x86_l_3391;
	case 13207ULL: goto x86_l_3397;
	case 13212ULL: goto x86_l_339c;
	case 13219ULL: goto x86_l_33a3;
	case 13222ULL: goto x86_l_33a6;
	case 13228ULL: goto x86_l_33ac;
	case 13238ULL: goto x86_l_33b6;
	case 13246ULL: goto x86_l_33be;
	case 13256ULL: goto x86_l_33c8;
	case 13264ULL: goto x86_l_33d0;
	case 13274ULL: goto x86_l_33da;
	case 13282ULL: goto x86_l_33e2;
	case 13292ULL: goto x86_l_33ec;
	case 13300ULL: goto x86_l_33f4;
	case 13310ULL: goto x86_l_33fe;
	case 13318ULL: goto x86_l_3406;
	case 13323ULL: goto x86_l_340b;
	case 13328ULL: goto x86_l_3410;
	case 13333ULL: goto x86_l_3415;
	case 13336ULL: goto x86_l_3418;
	case 13338ULL: goto x86_l_341a;
	case 13340ULL: goto x86_l_341c;
	case 13345ULL: goto x86_l_3421;
	case 13355ULL: goto x86_l_342b;
	case 13363ULL: goto x86_l_3433;
	case 13373ULL: goto x86_l_343d;
	case 13381ULL: goto x86_l_3445;
	case 13391ULL: goto x86_l_344f;
	case 13399ULL: goto x86_l_3457;
	case 13409ULL: goto x86_l_3461;
	case 13417ULL: goto x86_l_3469;
	case 13427ULL: goto x86_l_3473;
	case 13435ULL: goto x86_l_347b;
	case 13445ULL: goto x86_l_3485;
	case 13453ULL: goto x86_l_348d;
	case 13461ULL: goto x86_l_3495;
	case 13469ULL: goto x86_l_349d;
	case 13474ULL: goto x86_l_34a2;
	case 13479ULL: goto x86_l_34a7;
	case 13485ULL: goto x86_l_34ad;
	case 13490ULL: goto x86_l_34b2;
	case 13492ULL: goto x86_l_34b4;
	case 13494ULL: goto x86_l_34b6;
	case 13501ULL: goto x86_l_34bd;
	case 13511ULL: goto x86_l_34c7;
	case 13514ULL: goto x86_l_34ca;
	case 13520ULL: goto x86_l_34d0;
	case 13527ULL: goto x86_l_34d7;
	case 13533ULL: goto x86_l_34dd;
	case 13538ULL: goto x86_l_34e2;
	case 13545ULL: goto x86_l_34e9;
	case 13548ULL: goto x86_l_34ec;
	case 13554ULL: goto x86_l_34f2;
	case 13564ULL: goto x86_l_34fc;
	case 13572ULL: goto x86_l_3504;
	case 13582ULL: goto x86_l_350e;
	case 13590ULL: goto x86_l_3516;
	case 13600ULL: goto x86_l_3520;
	case 13608ULL: goto x86_l_3528;
	case 13618ULL: goto x86_l_3532;
	case 13626ULL: goto x86_l_353a;
	case 13634ULL: goto x86_l_3542;
	case 13639ULL: goto x86_l_3547;
	case 13644ULL: goto x86_l_354c;
	case 13649ULL: goto x86_l_3551;
	case 13652ULL: goto x86_l_3554;
	case 13654ULL: goto x86_l_3556;
	case 13656ULL: goto x86_l_3558;
	case 13661ULL: goto x86_l_355d;
	case 13663ULL: goto x86_l_355f;
	case 13671ULL: goto x86_l_3567;
	case 13677ULL: goto x86_l_356d;
	case 13684ULL: goto x86_l_3574;
	case 13691ULL: goto x86_l_357b;
	case 13696ULL: goto x86_l_3580;
	case 13701ULL: goto x86_l_3585;
	case 13703ULL: goto x86_l_3587;
	case 13706ULL: goto x86_l_358a;
	case 13712ULL: goto x86_l_3590;
	case 13716ULL: goto x86_l_3594;
	case 13719ULL: goto x86_l_3597;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2d56:
	/* 0x2d56: jmp    2722 <kprobe_unwind_native+0x2722> */
	return 10018ULL;
x86_l_2d5b:
	/* 0x2d5b: movabs rax,0xa6425206f666e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860387845742ULL);
x86_l_2d65:
	/* 0x2d65: mov    QWORD PTR [rsp+0x35],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_2d6a:
	/* 0x2d6a: movabs rax,0x6f666e49646e6977 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8027224647331113335ULL);
x86_l_2d74:
	/* 0x2d74: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d79:
	/* 0x2d79: movabs rax,0x6e75202c78257830 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7959303291813591088ULL);
x86_l_2d83:
	/* 0x2d83: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d88:
	/* 0x2d88: movabs rax,0x20776f4c72646461 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2339460905569641569ULL);
x86_l_2d92:
	/* 0x2d92: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d97:
	/* 0x2d97: movabs rax,0x202c642520786564 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2318338018810291556ULL);
x86_l_2da1:
	/* 0x2da1: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2da6:
	/* 0x2da6: movabs rax,0x6e692061746c6564 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7955925819663869284ULL);
x86_l_2db0:
	/* 0x2db0: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2db5:
	/* 0x2db5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dba:
	/* 0x2dba: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2dbf:
	/* 0x2dbf: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_2dc5:
	/* 0x2dc5: mov    edx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2dcc:
	/* 0x2dcc: movzx  ecx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2dd0:
	/* 0x2dd0: movzx  r8d,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2dd5:
	/* 0x2dd5: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_2dda:
	/* 0x2dda: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ddc:
	/* 0x2ddc: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_2ddf:
	/* 0x2ddf: jmp    26a9 <kprobe_unwind_native+0x26a9> */
	return 9897ULL;
x86_l_2de4:
	/* 0x2de4: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_2dee:
	/* 0x2dee: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_2df6:
	/* 0x2df6: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_2e00:
	/* 0x2e00: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2e08:
	/* 0x2e08: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_2e12:
	/* 0x2e12: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2e1a:
	/* 0x2e1a: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_2e24:
	/* 0x2e24: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2e2c:
	/* 0x2e2c: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_2e36:
	/* 0x2e36: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2e3e:
	/* 0x2e3e: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2e48:
	/* 0x2e48: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2e50:
	/* 0x2e50: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2e58:
	/* 0x2e58: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2e5d:
	/* 0x2e5d: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2e62:
	/* 0x2e62: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2e66:
	/* 0x2e66: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2e6b:
	/* 0x2e6b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e6d:
	/* 0x2e6d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2e6f:
	/* 0x2e6f: jmp    1df0 <kprobe_unwind_native+0x1df0> */
	return 7664ULL;
x86_l_2e74:
	/* 0x2e74: movabs rax,0xa78323023252061 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 754408119914012769ULL);
x86_l_2e7e:
	/* 0x2e7e: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e83:
	/* 0x2e83: movabs rax,0x746c656420646567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8389191686598976871ULL);
x86_l_2e8d:
	/* 0x2e8d: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e92:
	/* 0x2e92: movabs rax,0x72656d202c642520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243114677922702624ULL);
x86_l_2e9c:
	/* 0x2e9c: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ea1:
	/* 0x2ea1: movabs rax,0x6666694472646441 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7378700782191010881ULL);
x86_l_2eab:
	/* 0x2eab: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eb0:
	/* 0x2eb0: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2eb5:
	/* 0x2eb5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eba:
	/* 0x2eba: mov    eax,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_2ebf:
	/* 0x2ebf: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_2ec5:
	/* 0x2ec5: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2eca:
	/* 0x2eca: movzx  ecx,BYTE PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_2ed0:
	/* 0x2ed0: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_2ed5:
	/* 0x2ed5: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_2ed8:
	/* 0x2ed8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2eda:
	/* 0x2eda: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2edd:
	/* 0x2edd: movzx  eax,BYTE PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_2ee3:
	/* 0x2ee3: jmp    279d <kprobe_unwind_native+0x279d> */
	return 10141ULL;
x86_l_2ee8:
	/* 0x2ee8: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_2ef2:
	/* 0x2ef2: mov    QWORD PTR [rsp+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_2ef7:
	/* 0x2ef7: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_2f01:
	/* 0x2f01: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f06:
	/* 0x2f06: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_2f10:
	/* 0x2f10: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f15:
	/* 0x2f15: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_2f1f:
	/* 0x2f1f: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f24:
	/* 0x2f24: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_2f2e:
	/* 0x2f2e: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f33:
	/* 0x2f33: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_2f3d:
	/* 0x2f3d: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f42:
	/* 0x2f42: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f47:
	/* 0x2f47: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_2f4c:
	/* 0x2f4c: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2f51:
	/* 0x2f51: mov    edx,DWORD PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_2f58:
	/* 0x2f58: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_2f5d:
	/* 0x2f5d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f5f:
	/* 0x2f5f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2f61:
	/* 0x2f61: jmp    2741 <kprobe_unwind_native+0x2741> */
	return 10049ULL;
x86_l_2f66:
	/* 0x2f66: movabs rax,0xa64253d61746c65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 748764383608597605ULL);
x86_l_2f70:
	/* 0x2f70: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f75:
	/* 0x2f75: movabs rax,0x44616663203a6863 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4927332043248527459ULL);
x86_l_2f7f:
	/* 0x2f7f: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f84:
	/* 0x2f84: movabs rax,0x74616d2061746c65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8386103966981975141ULL);
x86_l_2f8e:
	/* 0x2f8e: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f93:
	/* 0x2f93: movabs rax,0x642064656772654d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7214876989737559373ULL);
x86_l_2f9d:
	/* 0x2f9d: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fa2:
	/* 0x2fa2: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2fa7:
	/* 0x2fa7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fac:
	/* 0x2fac: mov    eax,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_2fb1:
	/* 0x2fb1: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2fb6:
	/* 0x2fb6: mov    edx,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_2fbd:
	/* 0x2fbd: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_2fc2:
	/* 0x2fc2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fc4:
	/* 0x2fc4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2fc6:
	/* 0x2fc6: jmp    27c9 <kprobe_unwind_native+0x27c9> */
	return 10185ULL;
x86_l_2fcb:
	/* 0x2fcb: movabs rax,0xa756c252b642572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 753627419551999346ULL);
x86_l_2fd5:
	/* 0x2fd5: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2fda:
	/* 0x2fda: movabs rax,0x203a646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2322278983241526901ULL);
x86_l_2fe4:
	/* 0x2fe4: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fe9:
	/* 0x2fe9: mov    BYTE PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2fee:
	/* 0x2fee: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ff3:
	/* 0x2ff3: mov    eax,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2ff8:
	/* 0x2ff8: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_2ffe:
	/* 0x2ffe: and    ebp,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_3001:
	/* 0x3001: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3006:
	/* 0x3006: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_300b:
	/* 0x300b: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_300d:
	/* 0x300d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_300f:
	/* 0x300f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_3012:
	/* 0x3012: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3015:
	/* 0x3015: cmp    ebp,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_3018:
	/* 0x3018: jle    2963 <kprobe_unwind_native+0x2963> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 10595ULL;
	}
x86_l_301e:
	/* 0x301e: mov    rax,QWORD PTR [rsp+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3026:
	/* 0x3026: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_3029:
	/* 0x3029: je     3038 <kprobe_unwind_native+0x3038> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3038;
	}
x86_l_302b:
	/* 0x302b: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3033:
	/* 0x3033: cmp    ebp,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 15ULL);
x86_l_3036:
	/* 0x3036: jne    3040 <kprobe_unwind_native+0x3040> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3040;
	}
x86_l_3038:
	/* 0x3038: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_303d:
	/* 0x303d: add    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3040:
	/* 0x3040: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3045:
	/* 0x3045: movzx  eax,BYTE PTR [rcx+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_3049:
	/* 0x3049: mov    r12d,DWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_304d:
	/* 0x304d: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_3050:
	/* 0x3050: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_3053:
	/* 0x3053: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_3055:
	/* 0x3055: cmovns ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_NS);
x86_l_3059:
	/* 0x3059: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_305b:
	/* 0x305b: and    edx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_305e:
	/* 0x305e: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3061:
	/* 0x3061: jg     3078 <kprobe_unwind_native+0x3078> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3078;
	}
x86_l_3063:
	/* 0x3063: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3066:
	/* 0x3066: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_3069:
	/* 0x3069: je     30e3 <kprobe_unwind_native+0x30e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30e3;
	}
x86_l_306b:
	/* 0x306b: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_306e:
	/* 0x306e: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3071:
	/* 0x3071: je     30e0 <kprobe_unwind_native+0x30e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30e0;
	}
x86_l_3073:
	/* 0x3073: jmp    323f <kprobe_unwind_native+0x323f> */
	goto x86_l_323f;
x86_l_3078:
	/* 0x3078: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_307b:
	/* 0x307b: je     30db <kprobe_unwind_native+0x30db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30db;
	}
x86_l_307d:
	/* 0x307d: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_3080:
	/* 0x3080: jne    323f <kprobe_unwind_native+0x323f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_323f;
	}
x86_l_3086:
	/* 0x3086: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_3089:
	/* 0x3089: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_308b:
	/* 0x308b: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_308e:
	/* 0x308e: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3090:
	/* 0x3090: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3095:
	/* 0x3095: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_309c:
	/* 0x309c: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_309f:
	/* 0x309f: jne    31a8 <kprobe_unwind_native+0x31a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_31a8;
	}
x86_l_30a5:
	/* 0x30a5: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_30a9:
	/* 0x30a9: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_30ad:
	/* 0x30ad: jg     31fb <kprobe_unwind_native+0x31fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_31fb;
	}
x86_l_30b3:
	/* 0x30b3: mov    rax,QWORD PTR [rsp+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_30bb:
	/* 0x30bb: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_30be:
	/* 0x30be: je     3217 <kprobe_unwind_native+0x3217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3217;
	}
x86_l_30c4:
	/* 0x30c4: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_30c8:
	/* 0x30c8: jne    323f <kprobe_unwind_native+0x323f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_323f;
	}
x86_l_30ce:
	/* 0x30ce: mov    rax,QWORD PTR [rsp+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_30d6:
	/* 0x30d6: jmp    3217 <kprobe_unwind_native+0x3217> */
	goto x86_l_3217;
x86_l_30db:
	/* 0x30db: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_30e0:
	/* 0x30e0: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30e3:
	/* 0x30e3: movsxd rbp,ecx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_30e6:
	/* 0x30e6: add    rbp,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30e9:
	/* 0x30e9: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_30eb:
	/* 0x30eb: jns    321f <kprobe_unwind_native+0x321f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_321f;
	}
x86_l_30f1:
	/* 0x30f1: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_30f6:
	/* 0x30f6: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_30fb:
	/* 0x30fb: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_3100:
	/* 0x3100: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3105:
	/* 0x3105: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3108:
	/* 0x3108: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_310a:
	/* 0x310a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_310d:
	/* 0x310d: je     3196 <kprobe_unwind_native+0x3196> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3196;
	}
x86_l_3113:
	/* 0x3113: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_311a:
	/* 0x311a: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_311d:
	/* 0x311d: je     323f <kprobe_unwind_native+0x323f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_323f;
	}
x86_l_3123:
	/* 0x3123: movabs rax,0x2578302073736572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2699960892542641522ULL);
x86_l_312d:
	/* 0x312d: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3132:
	/* 0x3132: movabs rax,0x6464612065636e65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7234013693231722085ULL);
x86_l_313c:
	/* 0x313c: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3141:
	/* 0x3141: movabs rax,0x7265666572656420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243107278868538400ULL);
x86_l_314b:
	/* 0x314b: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3150:
	/* 0x3150: movabs rax,0x6f742064656c6961 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8031079651078859105ULL);
x86_l_315a:
	/* 0x315a: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_315f:
	/* 0x315f: movabs rax,0x6620646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358992216502005365ULL);
x86_l_3169:
	/* 0x3169: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_316e:
	/* 0x316e: mov    DWORD PTR [rsp+0x38],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518854764ULL);
x86_l_3176:
	/* 0x3176: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_317b:
	/* 0x317b: mov    eax,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_3180:
	/* 0x3180: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3185:
	/* 0x3185: mov    esi,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_318a:
	/* 0x318a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_318d:
	/* 0x318d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_318f:
	/* 0x318f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3191:
	/* 0x3191: jmp    323f <kprobe_unwind_native+0x323f> */
	goto x86_l_323f;
x86_l_3196:
	/* 0x3196: shl    r12d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_319a:
	/* 0x319a: and    r12d,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 56ULL);
x86_l_319e:
	/* 0x319e: add    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_31a3:
	/* 0x31a3: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_31a6:
	/* 0x31a6: jmp    321f <kprobe_unwind_native+0x321f> */
	goto x86_l_321f;
x86_l_31a8:
	/* 0x31a8: movabs rax,0xa756c252b642572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 753627419551999346ULL);
x86_l_31b2:
	/* 0x31b2: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31b7:
	/* 0x31b7: movabs rax,0x203a646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2322278983241526901ULL);
x86_l_31c1:
	/* 0x31c1: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31c6:
	/* 0x31c6: mov    BYTE PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_31cb:
	/* 0x31cb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31d0:
	/* 0x31d0: mov    eax,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_31d5:
	/* 0x31d5: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_31db:
	/* 0x31db: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_31df:
	/* 0x31df: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_31e4:
	/* 0x31e4: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_31e9:
	/* 0x31e9: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_31ec:
	/* 0x31ec: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31ee:
	/* 0x31ee: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_31f1:
	/* 0x31f1: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_31f5:
	/* 0x31f5: jle    30b3 <kprobe_unwind_native+0x30b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_30b3;
	}
x86_l_31fb:
	/* 0x31fb: mov    rax,QWORD PTR [rsp+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_3203:
	/* 0x3203: cmp    r12d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 11ULL);
x86_l_3207:
	/* 0x3207: je     3217 <kprobe_unwind_native+0x3217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3217;
	}
x86_l_3209:
	/* 0x3209: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3211:
	/* 0x3211: cmp    r12d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 15ULL);
x86_l_3215:
	/* 0x3215: jne    323f <kprobe_unwind_native+0x323f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_323f;
	}
x86_l_3217:
	/* 0x3217: mov    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_321c:
	/* 0x321c: add    rbp,QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_321f:
	/* 0x321f: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_3222:
	/* 0x3222: je     323f <kprobe_unwind_native+0x323f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_323f;
	}
x86_l_3224:
	/* 0x3224: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_3229:
	/* 0x3229: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_322e:
	/* 0x322e: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3233:
	/* 0x3233: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3238:
	/* 0x3238: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_323b:
	/* 0x323b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_323d:
	/* 0x323d: jmp    3255 <kprobe_unwind_native+0x3255> */
	goto x86_l_3255;
x86_l_323f:
	/* 0x323f: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3244:
	/* 0x3244: cmp    BYTE PTR [rax],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_3247:
	/* 0x3247: jne    3255 <kprobe_unwind_native+0x3255> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3255;
	}
x86_l_3249:
	/* 0x3249: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_324e:
	/* 0x324e: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3255:
	/* 0x3255: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_3258:
	/* 0x3258: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_325d:
	/* 0x325d: je     1640 <kprobe_unwind_native+0x1640> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5696ULL;
	}
x86_l_3263:
	/* 0x3263: lea    rdx,[r13-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_3267:
	/* 0x3267: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_326c:
	/* 0x326c: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_3271:
	/* 0x3271: mov    rdi,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_3279:
	/* 0x3279: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_327e:
	/* 0x327e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3280:
	/* 0x3280: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3283:
	/* 0x3283: jne    1640 <kprobe_unwind_native+0x1640> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5696ULL;
	}
x86_l_3289:
	/* 0x3289: mov    QWORD PTR [rbx+0xed8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_3290:
	/* 0x3290: mov    BYTE PTR [rbx+0xf30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16698832846849ULL);
x86_l_3297:
	/* 0x3297: mov    DWORD PTR [rsp+0x78],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075526ULL);
x86_l_329f:
	/* 0x329f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_32a6:
	/* 0x32a6: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_32ab:
	/* 0x32ab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32b0:
	/* 0x32b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32b2:
	/* 0x32b2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32b5:
	/* 0x32b5: je     3356 <kprobe_unwind_native+0x3356> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3356;
	}
x86_l_32bb:
	/* 0x32bb: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_32be:
	/* 0x32be: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32c0:
	/* 0x32c0: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_32c7:
	/* 0x32c7: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32ca:
	/* 0x32ca: je     3368 <kprobe_unwind_native+0x3368> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3368;
	}
x86_l_32d0:
	/* 0x32d0: movabs rax,0xa786c6c25203a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947156833280058ULL);
x86_l_32da:
	/* 0x32da: mov    QWORD PTR [rsp+0xb5],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 181ULL);
x86_l_32e2:
	/* 0x32e2: movabs rax,0x25203a706620786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675202433082226796ULL);
x86_l_32ec:
	/* 0x32ec: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_32f4:
	/* 0x32f4: movabs rax,0x6c25203a70732078 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7792670165601296504ULL);
x86_l_32fe:
	/* 0x32fe: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3306:
	/* 0x3306: movabs rax,0x6c6c25203a637020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660273929744416ULL);
x86_l_3310:
	/* 0x3310: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3318:
	/* 0x3318: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3320:
	/* 0x3320: mov    eax,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_3325:
	/* 0x3325: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_332b:
	/* 0x332b: mov    rax,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_3333:
	/* 0x3333: mov    rdx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3336:
	/* 0x3336: mov    rcx,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3339:
	/* 0x3339: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_333e:
	/* 0x333e: mov    r8,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3341:
	/* 0x3341: mov    esi,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 29ULL);
x86_l_3346:
	/* 0x3346: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3348:
	/* 0x3348: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_334b:
	/* 0x334b: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3352:
	/* 0x3352: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3354:
	/* 0x3354: jmp    3368 <kprobe_unwind_native+0x3368> */
	goto x86_l_3368;
x86_l_3356:
	/* 0x3356: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_335d:
	/* 0x335d: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3360:
	/* 0x3360: jne    36cb <kprobe_unwind_native+0x36cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 14027ULL;
	}
x86_l_3366:
	/* 0x3366: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3368:
	/* 0x3368: mov    rcx,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_3370:
	/* 0x3370: mov    r13,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3373:
	/* 0x3373: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_3376:
	/* 0x3376: je     706b <kprobe_unwind_native+0x706b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28779ULL;
	}
x86_l_337c:
	/* 0x337c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_337e:
	/* 0x337e: jne    3421 <kprobe_unwind_native+0x3421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3421;
	}
x86_l_3384:
	/* 0x3384: movabs rax,0xffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72057594037927935ULL);
x86_l_338e:
	/* 0x338e: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3391:
	/* 0x3391: jbe    34d0 <kprobe_unwind_native+0x34d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_34d0;
	}
x86_l_3397:
	/* 0x3397: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_339c:
	/* 0x339c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_33a3:
	/* 0x33a3: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33a6:
	/* 0x33a6: je     1799 <kprobe_unwind_native+0x1799> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6041ULL;
	}
x86_l_33ac:
	/* 0x33ac: movabs rax,0x7373657264646120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8319104478668415264ULL);
x86_l_33b6:
	/* 0x33b6: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_33be:
	/* 0x33be: movabs rax,0x6c656e72656b2061 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7810770566350839905ULL);
x86_l_33c8:
	/* 0x33c8: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_33d0:
	/* 0x33d0: movabs rax,0x20736920786c2520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338328219715642656ULL);
x86_l_33da:
	/* 0x33da: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_33e2:
	/* 0x33e2: movabs rax,0x65756c6176204350 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310868735955321680ULL);
x86_l_33ec:
	/* 0x33ec: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_33f4:
	/* 0x33f4: mov    WORD PTR [rsp+0xc0],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 824633720842ULL);
x86_l_33fe:
	/* 0x33fe: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3406:
	/* 0x3406: mov    eax,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_340b:
	/* 0x340b: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3410:
	/* 0x3410: mov    esi,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 34ULL);
x86_l_3415:
	/* 0x3415: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3418:
	/* 0x3418: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_341a:
	/* 0x341a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_341c:
	/* 0x341c: jmp    1799 <kprobe_unwind_native+0x1799> */
	return 6041ULL;
x86_l_3421:
	/* 0x3421: movabs rax,0xa3d3d3d3d206425 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 737813247186461733ULL);
x86_l_342b:
	/* 0x342b: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_3433:
	/* 0x3433: movabs rax,0x20656d617266203a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334392247160021050ULL);
x86_l_343d:
	/* 0x343d: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_3445:
	/* 0x3445: movabs rax,0x7265646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243105118350175861ULL);
x86_l_344f:
	/* 0x344f: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3457:
	/* 0x3457: movabs rax,0x20656d6172662074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334392247160021108ULL);
x86_l_3461:
	/* 0x3461: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3469:
	/* 0x3469: movabs rax,0x78656e2065766c6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8675461342619397231ULL);
x86_l_3473:
	/* 0x3473: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_347b:
	/* 0x347b: movabs rax,0x736552203d3d3d3d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8315142585429343549ULL);
x86_l_3485:
	/* 0x3485: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_348d:
	/* 0x348d: mov    BYTE PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_3495:
	/* 0x3495: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_349d:
	/* 0x349d: mov    eax,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 49ULL);
x86_l_34a2:
	/* 0x34a2: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_34a7:
	/* 0x34a7: mov    edx,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_34ad:
	/* 0x34ad: mov    esi,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 49ULL);
x86_l_34b2:
	/* 0x34b2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34b4:
	/* 0x34b4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_34b6:
	/* 0x34b6: mov    r13,QWORD PTR [rbx+0xed0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_34bd:
	/* 0x34bd: movabs rax,0xffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72057594037927935ULL);
x86_l_34c7:
	/* 0x34c7: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_34ca:
	/* 0x34ca: ja     3397 <kprobe_unwind_native+0x3397> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3397;
	}
x86_l_34d0:
	/* 0x34d0: cmp    r13,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4096ULL);
x86_l_34d7:
	/* 0x34d7: jae    355d <kprobe_unwind_native+0x355d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_355d;
	}
x86_l_34dd:
	/* 0x34dd: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_34e2:
	/* 0x34e2: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_34e9:
	/* 0x34e9: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34ec:
	/* 0x34ec: je     18eb <kprobe_unwind_native+0x18eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6379ULL;
	}
x86_l_34f2:
	/* 0x34f2: movabs rax,0xa676e69726f6e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2928473680277358ULL);
x86_l_34fc:
	/* 0x34fc: mov    QWORD PTR [rsp+0xb6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_3504:
	/* 0x3504: movabs rax,0x6f6e6769202c786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8029468886857185388ULL);
x86_l_350e:
	/* 0x350e: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3516:
	/* 0x3516: movabs rax,0x252065756c617620 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675249733661980192ULL);
x86_l_3520:
	/* 0x3520: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3528:
	/* 0x3528: movabs rax,0x6370206c6c616d73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7165262657193340275ULL);
x86_l_3532:
	/* 0x3532: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_353a:
	/* 0x353a: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3542:
	/* 0x3542: mov    eax,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 30ULL);
x86_l_3547:
	/* 0x3547: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_354c:
	/* 0x354c: mov    esi,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 30ULL);
x86_l_3551:
	/* 0x3551: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3554:
	/* 0x3554: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3556:
	/* 0x3556: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3558:
	/* 0x3558: jmp    18eb <kprobe_unwind_native+0x18eb> */
	return 6379ULL;
x86_l_355d:
	/* 0x355d: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_355f:
	/* 0x355f: mov    DWORD PTR [rsp+0x10],0x60 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476832ULL);
x86_l_3567:
	/* 0x3567: movbe  DWORD PTR [rsp+0x14],eax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_356d:
	/* 0x356d: movbe  QWORD PTR [rsp+0x18],r13 */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_3574:
	/* 0x3574: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_page_to_mapping_info)));
x86_l_357b:
	/* 0x357b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3580:
	/* 0x3580: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3585:
	/* 0x3585: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3587:
	/* 0x3587: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_358a:
	/* 0x358a: je     7127 <kprobe_unwind_native+0x7127> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28967ULL;
	}
x86_l_3590:
	/* 0x3590: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3594:
	/* 0x3594: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_3597:
	/* 0x3597: movabs rdx,0xffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 72057594037927935ULL);
	return 13729ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13729ULL: goto x86_l_35a1;
	case 13732ULL: goto x86_l_35a4;
	case 13739ULL: goto x86_l_35ab;
	case 13742ULL: goto x86_l_35ae;
	case 13749ULL: goto x86_l_35b5;
	case 13753ULL: goto x86_l_35b9;
	case 13756ULL: goto x86_l_35bc;
	case 13759ULL: goto x86_l_35bf;
	case 13766ULL: goto x86_l_35c6;
	case 13773ULL: goto x86_l_35cd;
	case 13776ULL: goto x86_l_35d0;
	case 13782ULL: goto x86_l_35d6;
	case 13786ULL: goto x86_l_35da;
	case 13792ULL: goto x86_l_35e0;
	case 13799ULL: goto x86_l_35e7;
	case 13804ULL: goto x86_l_35ec;
	case 13811ULL: goto x86_l_35f3;
	case 13818ULL: goto x86_l_35fa;
	case 13823ULL: goto x86_l_35ff;
	case 13828ULL: goto x86_l_3604;
	case 13830ULL: goto x86_l_3606;
	case 13836ULL: goto x86_l_360c;
	case 13839ULL: goto x86_l_360f;
	case 13845ULL: goto x86_l_3615;
	case 13848ULL: goto x86_l_3618;
	case 13851ULL: goto x86_l_361b;
	case 13853ULL: goto x86_l_361d;
	case 13857ULL: goto x86_l_3621;
	case 13859ULL: goto x86_l_3623;
	case 13863ULL: goto x86_l_3627;
	case 13869ULL: goto x86_l_362d;
	case 13873ULL: goto x86_l_3631;
	case 13879ULL: goto x86_l_3637;
	case 13886ULL: goto x86_l_363e;
	case 13889ULL: goto x86_l_3641;
	case 13895ULL: goto x86_l_3647;
	case 13901ULL: goto x86_l_364d;
	case 13905ULL: goto x86_l_3651;
	case 13908ULL: goto x86_l_3654;
	case 13914ULL: goto x86_l_365a;
	case 13921ULL: goto x86_l_3661;
	case 13924ULL: goto x86_l_3664;
	case 13930ULL: goto x86_l_366a;
	case 13940ULL: goto x86_l_3674;
	case 13948ULL: goto x86_l_367c;
	case 13958ULL: goto x86_l_3686;
	case 13966ULL: goto x86_l_368e;
	case 13976ULL: goto x86_l_3698;
	case 13984ULL: goto x86_l_36a0;
	case 13995ULL: goto x86_l_36ab;
	case 14003ULL: goto x86_l_36b3;
	case 14008ULL: goto x86_l_36b8;
	case 14013ULL: goto x86_l_36bd;
	case 14018ULL: goto x86_l_36c2;
	case 14020ULL: goto x86_l_36c4;
	case 14022ULL: goto x86_l_36c6;
	case 14027ULL: goto x86_l_36cb;
	case 14037ULL: goto x86_l_36d5;
	case 14042ULL: goto x86_l_36da;
	case 14052ULL: goto x86_l_36e4;
	case 14057ULL: goto x86_l_36e9;
	case 14067ULL: goto x86_l_36f3;
	case 14072ULL: goto x86_l_36f8;
	case 14082ULL: goto x86_l_3702;
	case 14087ULL: goto x86_l_3707;
	case 14097ULL: goto x86_l_3711;
	case 14102ULL: goto x86_l_3716;
	case 14112ULL: goto x86_l_3720;
	case 14117ULL: goto x86_l_3725;
	case 14122ULL: goto x86_l_372a;
	case 14127ULL: goto x86_l_372f;
	case 14132ULL: goto x86_l_3734;
	case 14136ULL: goto x86_l_3738;
	case 14141ULL: goto x86_l_373d;
	case 14143ULL: goto x86_l_373f;
	case 14145ULL: goto x86_l_3741;
	case 14147ULL: goto x86_l_3743;
	case 14154ULL: goto x86_l_374a;
	case 14157ULL: goto x86_l_374d;
	case 14163ULL: goto x86_l_3753;
	case 14168ULL: goto x86_l_3758;
	case 14178ULL: goto x86_l_3762;
	case 14183ULL: goto x86_l_3767;
	case 14193ULL: goto x86_l_3771;
	case 14198ULL: goto x86_l_3776;
	case 14208ULL: goto x86_l_3780;
	case 14213ULL: goto x86_l_3785;
	case 14223ULL: goto x86_l_378f;
	case 14228ULL: goto x86_l_3794;
	case 14238ULL: goto x86_l_379e;
	case 14243ULL: goto x86_l_37a3;
	case 14251ULL: goto x86_l_37ab;
	case 14256ULL: goto x86_l_37b0;
	case 14261ULL: goto x86_l_37b5;
	case 14266ULL: goto x86_l_37ba;
	case 14271ULL: goto x86_l_37bf;
	case 14274ULL: goto x86_l_37c2;
	case 14276ULL: goto x86_l_37c4;
	case 14278ULL: goto x86_l_37c6;
	case 14281ULL: goto x86_l_37c9;
	case 14286ULL: goto x86_l_37ce;
	case 14296ULL: goto x86_l_37d8;
	case 14304ULL: goto x86_l_37e0;
	case 14314ULL: goto x86_l_37ea;
	case 14322ULL: goto x86_l_37f2;
	case 14332ULL: goto x86_l_37fc;
	case 14340ULL: goto x86_l_3804;
	case 14350ULL: goto x86_l_380e;
	case 14358ULL: goto x86_l_3816;
	case 14368ULL: goto x86_l_3820;
	case 14376ULL: goto x86_l_3828;
	case 14386ULL: goto x86_l_3832;
	case 14394ULL: goto x86_l_383a;
	case 14404ULL: goto x86_l_3844;
	case 14412ULL: goto x86_l_384c;
	case 14417ULL: goto x86_l_3851;
	case 14423ULL: goto x86_l_3857;
	case 14430ULL: goto x86_l_385e;
	case 14435ULL: goto x86_l_3863;
	case 14438ULL: goto x86_l_3866;
	case 14441ULL: goto x86_l_3869;
	case 14443ULL: goto x86_l_386b;
	case 14446ULL: goto x86_l_386e;
	case 14453ULL: goto x86_l_3875;
	case 14456ULL: goto x86_l_3878;
	case 14462ULL: goto x86_l_387e;
	case 14472ULL: goto x86_l_3888;
	case 14480ULL: goto x86_l_3890;
	case 14490ULL: goto x86_l_389a;
	case 14498ULL: goto x86_l_38a2;
	case 14508ULL: goto x86_l_38ac;
	case 14516ULL: goto x86_l_38b4;
	case 14526ULL: goto x86_l_38be;
	case 14534ULL: goto x86_l_38c6;
	case 14544ULL: goto x86_l_38d0;
	case 14552ULL: goto x86_l_38d8;
	case 14560ULL: goto x86_l_38e0;
	case 14568ULL: goto x86_l_38e8;
	case 14573ULL: goto x86_l_38ed;
	case 14579ULL: goto x86_l_38f3;
	case 14586ULL: goto x86_l_38fa;
	case 14593ULL: goto x86_l_3901;
	case 14598ULL: goto x86_l_3906;
	case 14600ULL: goto x86_l_3908;
	case 14603ULL: goto x86_l_390b;
	case 14608ULL: goto x86_l_3910;
	case 14618ULL: goto x86_l_391a;
	case 14626ULL: goto x86_l_3922;
	case 14636ULL: goto x86_l_392c;
	case 14644ULL: goto x86_l_3934;
	case 14654ULL: goto x86_l_393e;
	case 14662ULL: goto x86_l_3946;
	case 14672ULL: goto x86_l_3950;
	case 14680ULL: goto x86_l_3958;
	case 14688ULL: goto x86_l_3960;
	case 14693ULL: goto x86_l_3965;
	case 14698ULL: goto x86_l_396a;
	case 14703ULL: goto x86_l_396f;
	case 14708ULL: goto x86_l_3974;
	case 14710ULL: goto x86_l_3976;
	case 14712ULL: goto x86_l_3978;
	case 14718ULL: goto x86_l_397e;
	case 14722ULL: goto x86_l_3982;
	case 14725ULL: goto x86_l_3985;
	case 14731ULL: goto x86_l_398b;
	case 14739ULL: goto x86_l_3993;
	case 14746ULL: goto x86_l_399a;
	case 14751ULL: goto x86_l_399f;
	case 14756ULL: goto x86_l_39a4;
	case 14758ULL: goto x86_l_39a6;
	case 14761ULL: goto x86_l_39a9;
	case 14763ULL: goto x86_l_39ab;
	case 14766ULL: goto x86_l_39ae;
	case 14768ULL: goto x86_l_39b0;
	case 14775ULL: goto x86_l_39b7;
	case 14778ULL: goto x86_l_39ba;
	case 14784ULL: goto x86_l_39c0;
	case 14789ULL: goto x86_l_39c5;
	case 14793ULL: goto x86_l_39c9;
	case 14799ULL: goto x86_l_39cf;
	case 14806ULL: goto x86_l_39d6;
	case 14809ULL: goto x86_l_39d9;
	case 14815ULL: goto x86_l_39df;
	case 14823ULL: goto x86_l_39e7;
	case 14830ULL: goto x86_l_39ee;
	case 14835ULL: goto x86_l_39f3;
	case 14840ULL: goto x86_l_39f8;
	case 14842ULL: goto x86_l_39fa;
	case 14845ULL: goto x86_l_39fd;
	case 14851ULL: goto x86_l_3a03;
	case 14854ULL: goto x86_l_3a06;
	case 14861ULL: goto x86_l_3a0d;
	case 14864ULL: goto x86_l_3a10;
	case 14870ULL: goto x86_l_3a16;
	case 14880ULL: goto x86_l_3a20;
	case 14888ULL: goto x86_l_3a28;
	case 14898ULL: goto x86_l_3a32;
	case 14906ULL: goto x86_l_3a3a;
	case 14916ULL: goto x86_l_3a44;
	case 14924ULL: goto x86_l_3a4c;
	case 14934ULL: goto x86_l_3a56;
	case 14942ULL: goto x86_l_3a5e;
	case 14952ULL: goto x86_l_3a68;
	case 14960ULL: goto x86_l_3a70;
	case 14971ULL: goto x86_l_3a7b;
	case 14979ULL: goto x86_l_3a83;
	case 14984ULL: goto x86_l_3a88;
	case 14990ULL: goto x86_l_3a8e;
	case 14997ULL: goto x86_l_3a95;
	case 15004ULL: goto x86_l_3a9c;
	case 15011ULL: goto x86_l_3aa3;
	case 15016ULL: goto x86_l_3aa8;
	case 15018ULL: goto x86_l_3aaa;
	case 15021ULL: goto x86_l_3aad;
	case 15023ULL: goto x86_l_3aaf;
	case 15030ULL: goto x86_l_3ab6;
	case 15033ULL: goto x86_l_3ab9;
	case 15039ULL: goto x86_l_3abf;
	case 15045ULL: goto x86_l_3ac5;
	case 15049ULL: goto x86_l_3ac9;
	case 15054ULL: goto x86_l_3ace;
	case 15061ULL: goto x86_l_3ad5;
	case 15067ULL: goto x86_l_3adb;
	case 15074ULL: goto x86_l_3ae2;
	case 15081ULL: goto x86_l_3ae9;
	case 15088ULL: goto x86_l_3af0;
	case 15091ULL: goto x86_l_3af3;
	case 15097ULL: goto x86_l_3af9;
	case 15101ULL: goto x86_l_3afd;
	case 15109ULL: goto x86_l_3b05;
	case 15117ULL: goto x86_l_3b0d;
	case 15125ULL: goto x86_l_3b15;
	case 15132ULL: goto x86_l_3b1c;
	case 15143ULL: goto x86_l_3b27;
	case 15153ULL: goto x86_l_3b31;
	case 15164ULL: goto x86_l_3b3c;
	case 15171ULL: goto x86_l_3b43;
	case 15179ULL: goto x86_l_3b4b;
	case 15184ULL: goto x86_l_3b50;
	case 15191ULL: goto x86_l_3b57;
	case 15198ULL: goto x86_l_3b5e;
	case 15206ULL: goto x86_l_3b66;
	case 15211ULL: goto x86_l_3b6b;
	case 15217ULL: goto x86_l_3b71;
	case 15224ULL: goto x86_l_3b78;
	case 15229ULL: goto x86_l_3b7d;
	case 15234ULL: goto x86_l_3b82;
	case 15236ULL: goto x86_l_3b84;
	case 15241ULL: goto x86_l_3b89;
	case 15244ULL: goto x86_l_3b8c;
	case 15249ULL: goto x86_l_3b91;
	case 15256ULL: goto x86_l_3b98;
	case 15262ULL: goto x86_l_3b9e;
	case 15267ULL: goto x86_l_3ba3;
	case 15270ULL: goto x86_l_3ba6;
	case 15274ULL: goto x86_l_3baa;
	case 15278ULL: goto x86_l_3bae;
	case 15281ULL: goto x86_l_3bb1;
	case 15283ULL: goto x86_l_3bb3;
	case 15286ULL: goto x86_l_3bb6;
	case 15288ULL: goto x86_l_3bb8;
	case 15291ULL: goto x86_l_3bbb;
	case 15297ULL: goto x86_l_3bc1;
	case 15300ULL: goto x86_l_3bc4;
	case 15306ULL: goto x86_l_3bca;
	case 15309ULL: goto x86_l_3bcd;
	case 15315ULL: goto x86_l_3bd3;
	case 15322ULL: goto x86_l_3bda;
	case 15327ULL: goto x86_l_3bdf;
	case 15330ULL: goto x86_l_3be2;
	case 15332ULL: goto x86_l_3be4;
	case 15335ULL: goto x86_l_3be7;
	case 15341ULL: goto x86_l_3bed;
	case 15344ULL: goto x86_l_3bf0;
	case 15350ULL: goto x86_l_3bf6;
	case 15353ULL: goto x86_l_3bf9;
	case 15359ULL: goto x86_l_3bff;
	case 15366ULL: goto x86_l_3c06;
	case 15371ULL: goto x86_l_3c0b;
	case 15374ULL: goto x86_l_3c0e;
	case 15376ULL: goto x86_l_3c10;
	case 15379ULL: goto x86_l_3c13;
	case 15385ULL: goto x86_l_3c19;
	case 15388ULL: goto x86_l_3c1c;
	case 15394ULL: goto x86_l_3c22;
	case 15401ULL: goto x86_l_3c29;
	case 15406ULL: goto x86_l_3c2e;
	case 15409ULL: goto x86_l_3c31;
	case 15411ULL: goto x86_l_3c33;
	case 15414ULL: goto x86_l_3c36;
	case 15420ULL: goto x86_l_3c3c;
	case 15423ULL: goto x86_l_3c3f;
	case 15429ULL: goto x86_l_3c45;
	case 15436ULL: goto x86_l_3c4c;
	case 15441ULL: goto x86_l_3c51;
	case 15444ULL: goto x86_l_3c54;
	case 15450ULL: goto x86_l_3c5a;
	case 15453ULL: goto x86_l_3c5d;
	case 15459ULL: goto x86_l_3c63;
	case 15466ULL: goto x86_l_3c6a;
	case 15471ULL: goto x86_l_3c6f;
	case 15474ULL: goto x86_l_3c72;
	case 15476ULL: goto x86_l_3c74;
	case 15479ULL: goto x86_l_3c77;
	case 15485ULL: goto x86_l_3c7d;
	case 15492ULL: goto x86_l_3c84;
	case 15494ULL: goto x86_l_3c86;
	case 15497ULL: goto x86_l_3c89;
	case 15499ULL: goto x86_l_3c8b;
	case 15502ULL: goto x86_l_3c8e;
	case 15508ULL: goto x86_l_3c94;
	case 15515ULL: goto x86_l_3c9b;
	case 15517ULL: goto x86_l_3c9d;
	case 15520ULL: goto x86_l_3ca0;
	case 15522ULL: goto x86_l_3ca2;
	case 15525ULL: goto x86_l_3ca5;
	case 15531ULL: goto x86_l_3cab;
	case 15538ULL: goto x86_l_3cb2;
	case 15540ULL: goto x86_l_3cb4;
	case 15547ULL: goto x86_l_3cbb;
	case 15549ULL: goto x86_l_3cbd;
	case 15556ULL: goto x86_l_3cc4;
	case 15558ULL: goto x86_l_3cc6;
	case 15565ULL: goto x86_l_3ccd;
	case 15567ULL: goto x86_l_3ccf;
	case 15574ULL: goto x86_l_3cd6;
	case 15576ULL: goto x86_l_3cd8;
	case 15583ULL: goto x86_l_3cdf;
	case 15585ULL: goto x86_l_3ce1;
	case 15592ULL: goto x86_l_3ce8;
	case 15594ULL: goto x86_l_3cea;
	case 15601ULL: goto x86_l_3cf1;
	case 15603ULL: goto x86_l_3cf3;
	case 15610ULL: goto x86_l_3cfa;
	case 15618ULL: goto x86_l_3d02;
	case 15623ULL: goto x86_l_3d07;
	case 15625ULL: goto x86_l_3d09;
	case 15630ULL: goto x86_l_3d0e;
	case 15633ULL: goto x86_l_3d11;
	case 15639ULL: goto x86_l_3d17;
	case 15644ULL: goto x86_l_3d1c;
	case 15647ULL: goto x86_l_3d1f;
	case 15655ULL: goto x86_l_3d27;
	case 15662ULL: goto x86_l_3d2e;
	case 15667ULL: goto x86_l_3d33;
	case 15671ULL: goto x86_l_3d37;
	case 15673ULL: goto x86_l_3d39;
	case 15679ULL: goto x86_l_3d3f;
	case 15682ULL: goto x86_l_3d42;
	case 15685ULL: goto x86_l_3d45;
	case 15692ULL: goto x86_l_3d4c;
	case 15695ULL: goto x86_l_3d4f;
	case 15701ULL: goto x86_l_3d55;
	case 15705ULL: goto x86_l_3d59;
	case 15707ULL: goto x86_l_3d5b;
	case 15711ULL: goto x86_l_3d5f;
	case 15716ULL: goto x86_l_3d64;
	case 15721ULL: goto x86_l_3d69;
	case 15726ULL: goto x86_l_3d6e;
	case 15728ULL: goto x86_l_3d70;
	case 15731ULL: goto x86_l_3d73;
	case 15737ULL: goto x86_l_3d79;
	case 15741ULL: goto x86_l_3d7d;
	case 15744ULL: goto x86_l_3d80;
	case 15749ULL: goto x86_l_3d85;
	case 15752ULL: goto x86_l_3d88;
	case 15756ULL: goto x86_l_3d8c;
	case 15760ULL: goto x86_l_3d90;
	case 15764ULL: goto x86_l_3d94;
	case 15767ULL: goto x86_l_3d97;
	case 15773ULL: goto x86_l_3d9d;
	case 15777ULL: goto x86_l_3da1;
	case 15779ULL: goto x86_l_3da3;
	case 15781ULL: goto x86_l_3da5;
	case 15785ULL: goto x86_l_3da9;
	case 15790ULL: goto x86_l_3dae;
	case 15795ULL: goto x86_l_3db3;
	case 15800ULL: goto x86_l_3db8;
	case 15802ULL: goto x86_l_3dba;
	case 15805ULL: goto x86_l_3dbd;
	case 15811ULL: goto x86_l_3dc3;
	case 15815ULL: goto x86_l_3dc7;
	case 15819ULL: goto x86_l_3dcb;
	case 15824ULL: goto x86_l_3dd0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_35a1:
	/* 0x35a1: and    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_AND);
x86_l_35a4:
	/* 0x35a4: mov    QWORD PTR [rbx+0xf20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3872ULL);
x86_l_35ab:
	/* 0x35ab: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35ae:
	/* 0x35ae: mov    QWORD PTR [rbx+0xf10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_35b5:
	/* 0x35b5: shr    r12,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_35b9:
	/* 0x35b9: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_35bc:
	/* 0x35bc: sub    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_35bf:
	/* 0x35bf: mov    QWORD PTR [rbx+0xf18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_35c6:
	/* 0x35c6: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_35cd:
	/* 0x35cd: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35d0:
	/* 0x35d0: jne    37ce <kprobe_unwind_native+0x37ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_37ce;
	}
x86_l_35d6:
	/* 0x35d6: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_35da:
	/* 0x35da: jne    39c5 <kprobe_unwind_native+0x39c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_39c5;
	}
x86_l_35e0:
	/* 0x35e0: mov    rax,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_35e7:
	/* 0x35e7: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35ec:
	/* 0x35ec: mov    rbp,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_35f3:
	/* 0x35f3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&interpreter_offsets)));
x86_l_35fa:
	/* 0x35fa: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35ff:
	/* 0x35ff: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3604:
	/* 0x3604: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3606:
	/* 0x3606: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_360c:
	/* 0x360c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_360f:
	/* 0x360f: je     39c5 <kprobe_unwind_native+0x39c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39c5;
	}
x86_l_3615:
	/* 0x3615: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3618:
	/* 0x3618: cmp    QWORD PTR [rax],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_361b:
	/* 0x361b: ja     3623 <kprobe_unwind_native+0x3623> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3623;
	}
x86_l_361d:
	/* 0x361d: cmp    QWORD PTR [r13+0x8],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3621:
	/* 0x3621: jae    3637 <kprobe_unwind_native+0x3637> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3637;
	}
x86_l_3623:
	/* 0x3623: cmp    QWORD PTR [r13+0x10],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3627:
	/* 0x3627: ja     39c5 <kprobe_unwind_native+0x39c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_39c5;
	}
x86_l_362d:
	/* 0x362d: cmp    QWORD PTR [r13+0x18],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3631:
	/* 0x3631: jb     39c5 <kprobe_unwind_native+0x39c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_39c5;
	}
x86_l_3637:
	/* 0x3637: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_363e:
	/* 0x363e: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3641:
	/* 0x3641: jne    3910 <kprobe_unwind_native+0x3910> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3910;
	}
x86_l_3647:
	/* 0x3647: mov    eax,DWORD PTR [rbx+0x1380] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4992ULL);
x86_l_364d:
	/* 0x364d: mov    ecx,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3651:
	/* 0x3651: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_3654:
	/* 0x3654: jae    398b <kprobe_unwind_native+0x398b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_398b;
	}
x86_l_365a:
	/* 0x365a: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3661:
	/* 0x3661: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3664:
	/* 0x3664: je     39c5 <kprobe_unwind_native+0x39c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39c5;
	}
x86_l_366a:
	/* 0x366a: movabs rax,0x6e6f64207265646e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7957689157107934318ULL);
x86_l_3674:
	/* 0x3674: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_367c:
	/* 0x367c: movabs rax,0x69776e7520726574 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7599664345545598324ULL);
x86_l_3686:
	/* 0x3686: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_368e:
	/* 0x368e: movabs rax,0x6572707265746e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310028781806448233ULL);
x86_l_3698:
	/* 0x3698: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_36a0:
	/* 0x36a0: mov    DWORD PTR [rsp+0xb7],0xa656e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 785979696494ULL);
x86_l_36ab:
	/* 0x36ab: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_36b3:
	/* 0x36b3: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_36b8:
	/* 0x36b8: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_36bd:
	/* 0x36bd: mov    esi,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 27ULL);
x86_l_36c2:
	/* 0x36c2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36c4:
	/* 0x36c4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_36c6:
	/* 0x36c6: jmp    39c5 <kprobe_unwind_native+0x39c5> */
	goto x86_l_39c5;
x86_l_36cb:
	/* 0x36cb: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_36d5:
	/* 0x36d5: mov    QWORD PTR [rsp+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_36da:
	/* 0x36da: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_36e4:
	/* 0x36e4: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_36e9:
	/* 0x36e9: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_36f3:
	/* 0x36f3: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_36f8:
	/* 0x36f8: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_3702:
	/* 0x3702: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3707:
	/* 0x3707: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_3711:
	/* 0x3711: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3716:
	/* 0x3716: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_3720:
	/* 0x3720: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3725:
	/* 0x3725: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_372a:
	/* 0x372a: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_372f:
	/* 0x372f: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3734:
	/* 0x3734: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3738:
	/* 0x3738: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_373d:
	/* 0x373d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_373f:
	/* 0x373f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3741:
	/* 0x3741: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3743:
	/* 0x3743: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_374a:
	/* 0x374a: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_374d:
	/* 0x374d: je     3368 <kprobe_unwind_native+0x3368> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13160ULL;
	}
x86_l_3753:
	/* 0x3753: jmp    32d0 <kprobe_unwind_native+0x32d0> */
	return 13008ULL;
x86_l_3758:
	/* 0x3758: movabs rax,0x2578302073736572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2699960892542641522ULL);
x86_l_3762:
	/* 0x3762: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3767:
	/* 0x3767: movabs rax,0x6464612065636e65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7234013693231722085ULL);
x86_l_3771:
	/* 0x3771: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3776:
	/* 0x3776: movabs rax,0x7265666572656420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243107278868538400ULL);
x86_l_3780:
	/* 0x3780: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3785:
	/* 0x3785: movabs rax,0x6f742064656c6961 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8031079651078859105ULL);
x86_l_378f:
	/* 0x378f: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3794:
	/* 0x3794: movabs rax,0x6620646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358992216502005365ULL);
x86_l_379e:
	/* 0x379e: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37a3:
	/* 0x37a3: mov    DWORD PTR [rsp+0x38],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518854764ULL);
x86_l_37ab:
	/* 0x37ab: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37b0:
	/* 0x37b0: mov    eax,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_37b5:
	/* 0x37b5: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_37ba:
	/* 0x37ba: mov    esi,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_37bf:
	/* 0x37bf: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_37c2:
	/* 0x37c2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37c4:
	/* 0x37c4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_37c6:
	/* 0x37c6: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37c9:
	/* 0x37c9: jmp    3040 <kprobe_unwind_native+0x3040> */
	return 12352ULL;
x86_l_37ce:
	/* 0x37ce: movabs rax,0x296425207265646e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2982549674514539630ULL);
x86_l_37d8:
	/* 0x37d8: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_37e0:
	/* 0x37e0: movabs rax,0x69776e752820786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7599664345674446956ULL);
x86_l_37ea:
	/* 0x37ea: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_37f2:
	/* 0x37f2: movabs rax,0x6c2520736920786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7792670410291574892ULL);
x86_l_37fc:
	/* 0x37fc: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3804:
	/* 0x3804: movabs rax,0x2520435020726f66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675212190078889830ULL);
x86_l_380e:
	/* 0x380e: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3816:
	/* 0x3816: movabs rax,0x206469206e6f6974 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334106094897424756ULL);
x86_l_3820:
	/* 0x3820: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3828:
	/* 0x3828: movabs rbp,0x6365732074786554 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 7162257365632836948ULL);
x86_l_3832:
	/* 0x3832: mov    QWORD PTR [rsp+0xa0],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_383a:
	/* 0x383a: mov    WORD PTR [rsp+0xd0],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 893353197578ULL);
x86_l_3844:
	/* 0x3844: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_384c:
	/* 0x384c: mov    eax,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_3851:
	/* 0x3851: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_3857:
	/* 0x3857: mov    rcx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_385e:
	/* 0x385e: mov    esi,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 50ULL);
x86_l_3863:
	/* 0x3863: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3866:
	/* 0x3866: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_3869:
	/* 0x3869: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_386b:
	/* 0x386b: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_386e:
	/* 0x386e: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3875:
	/* 0x3875: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3878:
	/* 0x3878: je     35d6 <kprobe_unwind_native+0x35d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35d6;
	}
x86_l_387e:
	/* 0x387e: movabs rax,0xa786c6c252073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947156833280115ULL);
x86_l_3888:
	/* 0x3888: mov    QWORD PTR [rsp+0xc7],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 199ULL);
x86_l_3890:
	/* 0x3890: movabs rax,0x7369207465736666 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8316213871206688358ULL);
x86_l_389a:
	/* 0x389a: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_38a2:
	/* 0x38a2: movabs rax,0x6f20646e61202c78 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8007510562703420536ULL);
x86_l_38ac:
	/* 0x38ac: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_38b4:
	/* 0x38b4: movabs rax,0x6c6c252073692073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660274886418547ULL);
x86_l_38be:
	/* 0x38be: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_38c6:
	/* 0x38c6: movabs rax,0x616962206e6f6974 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7019249385664899444ULL);
x86_l_38d0:
	/* 0x38d0: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_38d8:
	/* 0x38d8: mov    QWORD PTR [rsp+0xa0],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_38e0:
	/* 0x38e0: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_38e8:
	/* 0x38e8: mov    eax,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 47ULL);
x86_l_38ed:
	/* 0x38ed: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_38f3:
	/* 0x38f3: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_38fa:
	/* 0x38fa: mov    rdx,QWORD PTR [rbx+0xf20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3872ULL);
x86_l_3901:
	/* 0x3901: mov    esi,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 47ULL);
x86_l_3906:
	/* 0x3906: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3908:
	/* 0x3908: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_390b:
	/* 0x390b: jmp    35d6 <kprobe_unwind_native+0x35d6> */
	goto x86_l_35d6;
x86_l_3910:
	/* 0x3910: movabs rax,0xa642520686374 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860387386228ULL);
x86_l_391a:
	/* 0x391a: mov    QWORD PTR [rsp+0xb6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_3922:
	/* 0x3922: movabs rax,0x6374616d20737465 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7166460028377068645ULL);
x86_l_392c:
	/* 0x392c: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3934:
	/* 0x3934: movabs rax,0x7366666f5f726574 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8315446390514935156ULL);
x86_l_393e:
	/* 0x393e: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3946:
	/* 0x3946: movabs rax,0x6572707265746e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310028781806448233ULL);
x86_l_3950:
	/* 0x3950: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3958:
	/* 0x3958: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3960:
	/* 0x3960: mov    eax,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 30ULL);
x86_l_3965:
	/* 0x3965: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_396a:
	/* 0x396a: movzx  edx,WORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_396f:
	/* 0x396f: mov    esi,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 30ULL);
x86_l_3974:
	/* 0x3974: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3976:
	/* 0x3976: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3978:
	/* 0x3978: mov    eax,DWORD PTR [rbx+0x1380] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4992ULL);
x86_l_397e:
	/* 0x397e: mov    ecx,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3982:
	/* 0x3982: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_3985:
	/* 0x3985: jb     365a <kprobe_unwind_native+0x365a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_365a;
	}
x86_l_398b:
	/* 0x398b: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_3993:
	/* 0x3993: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_399a:
	/* 0x399a: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_399f:
	/* 0x399f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_39a4:
	/* 0x39a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39a6:
	/* 0x39a6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_39a9:
	/* 0x39a9: je     39b0 <kprobe_unwind_native+0x39b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39b0;
	}
x86_l_39ab:
	/* 0x39ab: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_39ae:
	/* 0x39ae: jmp    39c0 <kprobe_unwind_native+0x39c0> */
	goto x86_l_39c0;
x86_l_39b0:
	/* 0x39b0: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_39b7:
	/* 0x39b7: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39ba:
	/* 0x39ba: jne    49a3 <kprobe_unwind_native+0x49a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18851ULL;
	}
x86_l_39c0:
	/* 0x39c0: movzx  r12d,WORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_39c5:
	/* 0x39c5: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_39c9:
	/* 0x39c9: jne    75b1 <kprobe_unwind_native+0x75b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 30129ULL;
	}
x86_l_39cf:
	/* 0x39cf: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_39d6:
	/* 0x39d6: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39d9:
	/* 0x39d9: jne    4721 <kprobe_unwind_native+0x4721> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18209ULL;
	}
x86_l_39df:
	/* 0x39df: mov    DWORD PTR [rsp+0x10],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476741ULL);
x86_l_39e7:
	/* 0x39e7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_39ee:
	/* 0x39ee: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39f3:
	/* 0x39f3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_39f8:
	/* 0x39f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39fa:
	/* 0x39fa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_39fd:
	/* 0x39fd: je     3aaf <kprobe_unwind_native+0x3aaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3aaf;
	}
x86_l_3a03:
	/* 0x3a03: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3a06:
	/* 0x3a06: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3a0d:
	/* 0x3a0d: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a10:
	/* 0x3a10: je     3abf <kprobe_unwind_native+0x3abf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3abf;
	}
x86_l_3a16:
	/* 0x3a16: movabs rax,0x63617473206e6f20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7161132920309968672ULL);
x86_l_3a20:
	/* 0x3a20: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_3a28:
	/* 0x3a28: movabs rax,0x7525206e6f697469 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8441188735263536233ULL);
x86_l_3a32:
	/* 0x3a32: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3a3a:
	/* 0x3a3a: movabs rax,0x736f70206f742078 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8317990321387741304ULL);
x86_l_3a44:
	/* 0x3a44: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3a4c:
	/* 0x3a4c: movabs rax,0x6c6c2520786c6c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660274970520613ULL);
x86_l_3a56:
	/* 0x3a56: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3a5e:
	/* 0x3a5e: movabs rax,0x20676e6968737550 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334956330817910096ULL);
x86_l_3a68:
	/* 0x3a68: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3a70:
	/* 0x3a70: mov    DWORD PTR [rsp+0xc7],0xa6b63 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 854699174755ULL);
x86_l_3a7b:
	/* 0x3a7b: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3a83:
	/* 0x3a83: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_3a88:
	/* 0x3a88: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_3a8e:
	/* 0x3a8e: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_3a95:
	/* 0x3a95: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_3a9c:
	/* 0x3a9c: mov    r8d,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3aa3:
	/* 0x3aa3: mov    esi,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 43ULL);
x86_l_3aa8:
	/* 0x3aa8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3aaa:
	/* 0x3aaa: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_3aad:
	/* 0x3aad: jmp    3abf <kprobe_unwind_native+0x3abf> */
	goto x86_l_3abf;
x86_l_3aaf:
	/* 0x3aaf: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3ab6:
	/* 0x3ab6: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ab9:
	/* 0x3ab9: jne    47f6 <kprobe_unwind_native+0x47f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18422ULL;
	}
x86_l_3abf:
	/* 0x3abf: mov    eax,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3ac5:
	/* 0x3ac5: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_3ac9:
	/* 0x3ac9: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3ace:
	/* 0x3ace: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3ad5:
	/* 0x3ad5: ja     13a <kprobe_unwind_native+0x13a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 314ULL;
	}
x86_l_3adb:
	/* 0x3adb: movzx  ecx,BYTE PTR [rbx+0xf30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3888ULL);
x86_l_3ae2:
	/* 0x3ae2: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_3ae9:
	/* 0x3ae9: mov    rsi,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_3af0:
	/* 0x3af0: lea    edi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3af3:
	/* 0x3af3: mov    DWORD PTR [rbx+0x2c0],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_3af9:
	/* 0x3af9: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_3afd:
	/* 0x3afd: mov    QWORD PTR [rbx+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_3b05:
	/* 0x3b05: mov    QWORD PTR [rbx+rax*8+0x2d8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_3b0d:
	/* 0x3b0d: mov    BYTE PTR [rbx+rax*8+0x2e0],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 3161095929859ULL);
x86_l_3b15:
	/* 0x3b15: mov    BYTE PTR [rbx+rax*8+0x2e1],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 737ULL);
x86_l_3b1c:
	/* 0x3b1c: mov    DWORD PTR [rbx+rax*8+0x2e2],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3169685864448ULL);
x86_l_3b27:
	/* 0x3b27: mov    WORD PTR [rbx+rax*8+0x2e6],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3186865733632ULL);
x86_l_3b31:
	/* 0x3b31: mov    DWORD PTR [rsp+0x8c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_3b3c:
	/* 0x3b3c: mov    rax,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_3b43:
	/* 0x3b43: mov    QWORD PTR [rsp+0x160],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_3b4b:
	/* 0x3b4b: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3b50:
	/* 0x3b50: mov    rax,0xffffffffffff0000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 18446744073709486080ULL);
x86_l_3b57:
	/* 0x3b57: and    rax,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 3864ULL);
x86_l_3b5e:
	/* 0x3b5e: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3b66:
	/* 0x3b66: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b6b:
	/* 0x3b6b: jne    4788 <kprobe_unwind_native+0x4788> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18312ULL;
	}
x86_l_3b71:
	/* 0x3b71: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&stack_delta_page_to_info)));
x86_l_3b78:
	/* 0x3b78: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3b7d:
	/* 0x3b7d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3b82:
	/* 0x3b82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b84:
	/* 0x3b84: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3b89:
	/* 0x3b89: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3b8c:
	/* 0x3b8c: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3b91:
	/* 0x3b91: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3b98:
	/* 0x3b98: je     569d <kprobe_unwind_native+0x569d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22173ULL;
	}
x86_l_3b9e:
	/* 0x3b9e: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3ba3:
	/* 0x3ba3: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_3ba6:
	/* 0x3ba6: add    rbp,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_3baa:
	/* 0x3baa: movzx  eax,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_3bae:
	/* 0x3bae: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_3bb1:
	/* 0x3bb1: jg     3bdf <kprobe_unwind_native+0x3bdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3bdf;
	}
x86_l_3bb3:
	/* 0x3bb3: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_3bb6:
	/* 0x3bb6: jg     3c0b <kprobe_unwind_native+0x3c0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3c0b;
	}
x86_l_3bb8:
	/* 0x3bb8: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_3bbb:
	/* 0x3bbb: jg     3c51 <kprobe_unwind_native+0x3c51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3c51;
	}
x86_l_3bc1:
	/* 0x3bc1: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_3bc4:
	/* 0x3bc4: je     3cb4 <kprobe_unwind_native+0x3cb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cb4;
	}
x86_l_3bca:
	/* 0x3bca: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_3bcd:
	/* 0x3bcd: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_3bd3:
	/* 0x3bd3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_9_stack_deltas)));
x86_l_3bda:
	/* 0x3bda: jmp    3cfa <kprobe_unwind_native+0x3cfa> */
	goto x86_l_3cfa;
x86_l_3bdf:
	/* 0x3bdf: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_3be2:
	/* 0x3be2: jg     3c2e <kprobe_unwind_native+0x3c2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3c2e;
	}
x86_l_3be4:
	/* 0x3be4: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_3be7:
	/* 0x3be7: jg     3c6f <kprobe_unwind_native+0x3c6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3c6f;
	}
x86_l_3bed:
	/* 0x3bed: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_3bf0:
	/* 0x3bf0: je     3cbd <kprobe_unwind_native+0x3cbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cbd;
	}
x86_l_3bf6:
	/* 0x3bf6: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_3bf9:
	/* 0x3bf9: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_3bff:
	/* 0x3bff: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_17_stack_deltas)));
x86_l_3c06:
	/* 0x3c06: jmp    3cfa <kprobe_unwind_native+0x3cfa> */
	goto x86_l_3cfa;
x86_l_3c0b:
	/* 0x3c0b: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_3c0e:
	/* 0x3c0e: jg     3c86 <kprobe_unwind_native+0x3c86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3c86;
	}
x86_l_3c10:
	/* 0x3c10: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3c13:
	/* 0x3c13: je     3cc6 <kprobe_unwind_native+0x3cc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cc6;
	}
x86_l_3c19:
	/* 0x3c19: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_3c1c:
	/* 0x3c1c: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_3c22:
	/* 0x3c22: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_13_stack_deltas)));
x86_l_3c29:
	/* 0x3c29: jmp    3cfa <kprobe_unwind_native+0x3cfa> */
	goto x86_l_3cfa;
x86_l_3c2e:
	/* 0x3c2e: cmp    eax,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_3c31:
	/* 0x3c31: jg     3c9d <kprobe_unwind_native+0x3c9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3c9d;
	}
x86_l_3c33:
	/* 0x3c33: cmp    eax,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 20ULL);
x86_l_3c36:
	/* 0x3c36: je     3ccf <kprobe_unwind_native+0x3ccf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ccf;
	}
x86_l_3c3c:
	/* 0x3c3c: cmp    eax,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_3c3f:
	/* 0x3c3f: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_3c45:
	/* 0x3c45: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_21_stack_deltas)));
x86_l_3c4c:
	/* 0x3c4c: jmp    3cfa <kprobe_unwind_native+0x3cfa> */
	goto x86_l_3cfa;
x86_l_3c51:
	/* 0x3c51: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_3c54:
	/* 0x3c54: je     3cd8 <kprobe_unwind_native+0x3cd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cd8;
	}
x86_l_3c5a:
	/* 0x3c5a: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_3c5d:
	/* 0x3c5d: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_3c63:
	/* 0x3c63: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_11_stack_deltas)));
x86_l_3c6a:
	/* 0x3c6a: jmp    3cfa <kprobe_unwind_native+0x3cfa> */
	goto x86_l_3cfa;
x86_l_3c6f:
	/* 0x3c6f: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_3c72:
	/* 0x3c72: je     3ce1 <kprobe_unwind_native+0x3ce1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ce1;
	}
x86_l_3c74:
	/* 0x3c74: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_3c77:
	/* 0x3c77: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_3c7d:
	/* 0x3c7d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_19_stack_deltas)));
x86_l_3c84:
	/* 0x3c84: jmp    3cfa <kprobe_unwind_native+0x3cfa> */
	goto x86_l_3cfa;
x86_l_3c86:
	/* 0x3c86: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3c89:
	/* 0x3c89: je     3cea <kprobe_unwind_native+0x3cea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cea;
	}
x86_l_3c8b:
	/* 0x3c8b: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_3c8e:
	/* 0x3c8e: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_3c94:
	/* 0x3c94: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_15_stack_deltas)));
x86_l_3c9b:
	/* 0x3c9b: jmp    3cfa <kprobe_unwind_native+0x3cfa> */
	goto x86_l_3cfa;
x86_l_3c9d:
	/* 0x3c9d: cmp    eax,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 22ULL);
x86_l_3ca0:
	/* 0x3ca0: je     3cf3 <kprobe_unwind_native+0x3cf3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cf3;
	}
x86_l_3ca2:
	/* 0x3ca2: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_3ca5:
	/* 0x3ca5: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22563ULL;
	}
x86_l_3cab:
	/* 0x3cab: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_23_stack_deltas)));
x86_l_3cb2:
	/* 0x3cb2: jmp    3cfa <kprobe_unwind_native+0x3cfa> */
	goto x86_l_3cfa;
x86_l_3cb4:
	/* 0x3cb4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_8_stack_deltas)));
x86_l_3cbb:
	/* 0x3cbb: jmp    3cfa <kprobe_unwind_native+0x3cfa> */
	goto x86_l_3cfa;
x86_l_3cbd:
	/* 0x3cbd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_16_stack_deltas)));
x86_l_3cc4:
	/* 0x3cc4: jmp    3cfa <kprobe_unwind_native+0x3cfa> */
	goto x86_l_3cfa;
x86_l_3cc6:
	/* 0x3cc6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_12_stack_deltas)));
x86_l_3ccd:
	/* 0x3ccd: jmp    3cfa <kprobe_unwind_native+0x3cfa> */
	goto x86_l_3cfa;
x86_l_3ccf:
	/* 0x3ccf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_20_stack_deltas)));
x86_l_3cd6:
	/* 0x3cd6: jmp    3cfa <kprobe_unwind_native+0x3cfa> */
	goto x86_l_3cfa;
x86_l_3cd8:
	/* 0x3cd8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_10_stack_deltas)));
x86_l_3cdf:
	/* 0x3cdf: jmp    3cfa <kprobe_unwind_native+0x3cfa> */
	goto x86_l_3cfa;
x86_l_3ce1:
	/* 0x3ce1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_18_stack_deltas)));
x86_l_3ce8:
	/* 0x3ce8: jmp    3cfa <kprobe_unwind_native+0x3cfa> */
	goto x86_l_3cfa;
x86_l_3cea:
	/* 0x3cea: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_14_stack_deltas)));
x86_l_3cf1:
	/* 0x3cf1: jmp    3cfa <kprobe_unwind_native+0x3cfa> */
	goto x86_l_3cfa;
x86_l_3cf3:
	/* 0x3cf3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_22_stack_deltas)));
x86_l_3cfa:
	/* 0x3cfa: lea    rsi,[rsp+0x160] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_3d02:
	/* 0x3d02: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3d07:
	/* 0x3d07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d09:
	/* 0x3d09: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3d0e:
	/* 0x3d0e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3d11:
	/* 0x3d11: je     5f24 <kprobe_unwind_native+0x5f24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24356ULL;
	}
x86_l_3d17:
	/* 0x3d17: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3d1c:
	/* 0x3d1c: mov    r13d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d1f:
	/* 0x3d1f: mov    DWORD PTR [rsp+0x90],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3d27:
	/* 0x3d27: mov    rax,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_3d2e:
	/* 0x3d2e: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d33:
	/* 0x3d33: movzx  eax,WORD PTR [rcx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3d37:
	/* 0x3d37: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d39:
	/* 0x3d39: je     4230 <kprobe_unwind_native+0x4230> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 16944ULL;
	}
x86_l_3d3f:
	/* 0x3d3f: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_3d42:
	/* 0x3d42: add    r12d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3d45:
	/* 0x3d45: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_3d4c:
	/* 0x3d4c: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d4f:
	/* 0x3d4f: jne    4896 <kprobe_unwind_native+0x4896> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18582ULL;
	}
x86_l_3d55:
	/* 0x3d55: lea    eax,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3d59:
	/* 0x3d59: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_3d5b:
	/* 0x3d5b: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d5f:
	/* 0x3d5f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d64:
	/* 0x3d64: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3d69:
	/* 0x3d69: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3d6e:
	/* 0x3d6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d70:
	/* 0x3d70: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3d73:
	/* 0x3d73: je     4307 <kprobe_unwind_native+0x4307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17159ULL;
	}
x86_l_3d79:
	/* 0x3d79: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d7d:
	/* 0x3d7d: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3d80:
	/* 0x3d80: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d85:
	/* 0x3d85: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d88:
	/* 0x3d88: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_3d8c:
	/* 0x3d8c: cmova  r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_3d90:
	/* 0x3d90: mov    QWORD PTR [rsp],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d94:
	/* 0x3d94: cmp    ebp,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R12, X86_WIDTH_32);
x86_l_3d97:
	/* 0x3d97: jae    4221 <kprobe_unwind_native+0x4221> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 16929ULL;
	}
x86_l_3d9d:
	/* 0x3d9d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3da1:
	/* 0x3da1: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3da3:
	/* 0x3da3: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_3da5:
	/* 0x3da5: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3da9:
	/* 0x3da9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3dae:
	/* 0x3dae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3db3:
	/* 0x3db3: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3db8:
	/* 0x3db8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dba:
	/* 0x3dba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3dbd:
	/* 0x3dbd: je     4307 <kprobe_unwind_native+0x4307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17159ULL;
	}
x86_l_3dc3:
	/* 0x3dc3: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3dc7:
	/* 0x3dc7: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3dcb:
	/* 0x3dcb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3dd0:
	/* 0x3dd0: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 15827ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15827ULL: goto x86_l_3dd3;
	case 15831ULL: goto x86_l_3dd7;
	case 15835ULL: goto x86_l_3ddb;
	case 15838ULL: goto x86_l_3dde;
	case 15842ULL: goto x86_l_3de2;
	case 15845ULL: goto x86_l_3de5;
	case 15851ULL: goto x86_l_3deb;
	case 15855ULL: goto x86_l_3def;
	case 15858ULL: goto x86_l_3df2;
	case 15860ULL: goto x86_l_3df4;
	case 15864ULL: goto x86_l_3df8;
	case 15869ULL: goto x86_l_3dfd;
	case 15874ULL: goto x86_l_3e02;
	case 15879ULL: goto x86_l_3e07;
	case 15881ULL: goto x86_l_3e09;
	case 15884ULL: goto x86_l_3e0c;
	case 15890ULL: goto x86_l_3e12;
	case 15894ULL: goto x86_l_3e16;
	case 15897ULL: goto x86_l_3e19;
	case 15902ULL: goto x86_l_3e1e;
	case 15905ULL: goto x86_l_3e21;
	case 15909ULL: goto x86_l_3e25;
	case 15913ULL: goto x86_l_3e29;
	case 15916ULL: goto x86_l_3e2c;
	case 15920ULL: goto x86_l_3e30;
	case 15922ULL: goto x86_l_3e32;
	case 15928ULL: goto x86_l_3e38;
	case 15932ULL: goto x86_l_3e3c;
	case 15934ULL: goto x86_l_3e3e;
	case 15936ULL: goto x86_l_3e40;
	case 15940ULL: goto x86_l_3e44;
	case 15945ULL: goto x86_l_3e49;
	case 15950ULL: goto x86_l_3e4e;
	case 15955ULL: goto x86_l_3e53;
	case 15957ULL: goto x86_l_3e55;
	case 15960ULL: goto x86_l_3e58;
	case 15966ULL: goto x86_l_3e5e;
	case 15970ULL: goto x86_l_3e62;
	case 15974ULL: goto x86_l_3e66;
	case 15979ULL: goto x86_l_3e6b;
	case 15982ULL: goto x86_l_3e6e;
	case 15986ULL: goto x86_l_3e72;
	case 15990ULL: goto x86_l_3e76;
	case 15993ULL: goto x86_l_3e79;
	case 15997ULL: goto x86_l_3e7d;
	case 16000ULL: goto x86_l_3e80;
	case 16006ULL: goto x86_l_3e86;
	case 16010ULL: goto x86_l_3e8a;
	case 16013ULL: goto x86_l_3e8d;
	case 16015ULL: goto x86_l_3e8f;
	case 16019ULL: goto x86_l_3e93;
	case 16024ULL: goto x86_l_3e98;
	case 16029ULL: goto x86_l_3e9d;
	case 16034ULL: goto x86_l_3ea2;
	case 16036ULL: goto x86_l_3ea4;
	case 16039ULL: goto x86_l_3ea7;
	case 16045ULL: goto x86_l_3ead;
	case 16049ULL: goto x86_l_3eb1;
	case 16052ULL: goto x86_l_3eb4;
	case 16057ULL: goto x86_l_3eb9;
	case 16060ULL: goto x86_l_3ebc;
	case 16064ULL: goto x86_l_3ec0;
	case 16068ULL: goto x86_l_3ec4;
	case 16071ULL: goto x86_l_3ec7;
	case 16075ULL: goto x86_l_3ecb;
	case 16077ULL: goto x86_l_3ecd;
	case 16083ULL: goto x86_l_3ed3;
	case 16087ULL: goto x86_l_3ed7;
	case 16089ULL: goto x86_l_3ed9;
	case 16091ULL: goto x86_l_3edb;
	case 16095ULL: goto x86_l_3edf;
	case 16100ULL: goto x86_l_3ee4;
	case 16105ULL: goto x86_l_3ee9;
	case 16110ULL: goto x86_l_3eee;
	case 16112ULL: goto x86_l_3ef0;
	case 16115ULL: goto x86_l_3ef3;
	case 16121ULL: goto x86_l_3ef9;
	case 16125ULL: goto x86_l_3efd;
	case 16129ULL: goto x86_l_3f01;
	case 16134ULL: goto x86_l_3f06;
	case 16137ULL: goto x86_l_3f09;
	case 16141ULL: goto x86_l_3f0d;
	case 16145ULL: goto x86_l_3f11;
	case 16148ULL: goto x86_l_3f14;
	case 16152ULL: goto x86_l_3f18;
	case 16155ULL: goto x86_l_3f1b;
	case 16161ULL: goto x86_l_3f21;
	case 16165ULL: goto x86_l_3f25;
	case 16168ULL: goto x86_l_3f28;
	case 16170ULL: goto x86_l_3f2a;
	case 16174ULL: goto x86_l_3f2e;
	case 16179ULL: goto x86_l_3f33;
	case 16184ULL: goto x86_l_3f38;
	case 16189ULL: goto x86_l_3f3d;
	case 16191ULL: goto x86_l_3f3f;
	case 16194ULL: goto x86_l_3f42;
	case 16200ULL: goto x86_l_3f48;
	case 16204ULL: goto x86_l_3f4c;
	case 16207ULL: goto x86_l_3f4f;
	case 16212ULL: goto x86_l_3f54;
	case 16215ULL: goto x86_l_3f57;
	case 16219ULL: goto x86_l_3f5b;
	case 16223ULL: goto x86_l_3f5f;
	case 16226ULL: goto x86_l_3f62;
	case 16230ULL: goto x86_l_3f66;
	case 16232ULL: goto x86_l_3f68;
	case 16238ULL: goto x86_l_3f6e;
	case 16242ULL: goto x86_l_3f72;
	case 16244ULL: goto x86_l_3f74;
	case 16246ULL: goto x86_l_3f76;
	case 16250ULL: goto x86_l_3f7a;
	case 16255ULL: goto x86_l_3f7f;
	case 16260ULL: goto x86_l_3f84;
	case 16265ULL: goto x86_l_3f89;
	case 16267ULL: goto x86_l_3f8b;
	case 16270ULL: goto x86_l_3f8e;
	case 16276ULL: goto x86_l_3f94;
	case 16280ULL: goto x86_l_3f98;
	case 16284ULL: goto x86_l_3f9c;
	case 16289ULL: goto x86_l_3fa1;
	case 16292ULL: goto x86_l_3fa4;
	case 16296ULL: goto x86_l_3fa8;
	case 16300ULL: goto x86_l_3fac;
	case 16303ULL: goto x86_l_3faf;
	case 16307ULL: goto x86_l_3fb3;
	case 16310ULL: goto x86_l_3fb6;
	case 16316ULL: goto x86_l_3fbc;
	case 16320ULL: goto x86_l_3fc0;
	case 16323ULL: goto x86_l_3fc3;
	case 16325ULL: goto x86_l_3fc5;
	case 16329ULL: goto x86_l_3fc9;
	case 16334ULL: goto x86_l_3fce;
	case 16339ULL: goto x86_l_3fd3;
	case 16344ULL: goto x86_l_3fd8;
	case 16346ULL: goto x86_l_3fda;
	case 16349ULL: goto x86_l_3fdd;
	case 16355ULL: goto x86_l_3fe3;
	case 16359ULL: goto x86_l_3fe7;
	case 16362ULL: goto x86_l_3fea;
	case 16367ULL: goto x86_l_3fef;
	case 16370ULL: goto x86_l_3ff2;
	case 16374ULL: goto x86_l_3ff6;
	case 16378ULL: goto x86_l_3ffa;
	case 16381ULL: goto x86_l_3ffd;
	case 16385ULL: goto x86_l_4001;
	case 16387ULL: goto x86_l_4003;
	case 16393ULL: goto x86_l_4009;
	case 16397ULL: goto x86_l_400d;
	case 16399ULL: goto x86_l_400f;
	case 16401ULL: goto x86_l_4011;
	case 16405ULL: goto x86_l_4015;
	case 16410ULL: goto x86_l_401a;
	case 16415ULL: goto x86_l_401f;
	case 16420ULL: goto x86_l_4024;
	case 16422ULL: goto x86_l_4026;
	case 16425ULL: goto x86_l_4029;
	case 16431ULL: goto x86_l_402f;
	case 16435ULL: goto x86_l_4033;
	case 16439ULL: goto x86_l_4037;
	case 16444ULL: goto x86_l_403c;
	case 16447ULL: goto x86_l_403f;
	case 16451ULL: goto x86_l_4043;
	case 16455ULL: goto x86_l_4047;
	case 16458ULL: goto x86_l_404a;
	case 16462ULL: goto x86_l_404e;
	case 16465ULL: goto x86_l_4051;
	case 16471ULL: goto x86_l_4057;
	case 16475ULL: goto x86_l_405b;
	case 16478ULL: goto x86_l_405e;
	case 16480ULL: goto x86_l_4060;
	case 16484ULL: goto x86_l_4064;
	case 16489ULL: goto x86_l_4069;
	case 16494ULL: goto x86_l_406e;
	case 16499ULL: goto x86_l_4073;
	case 16501ULL: goto x86_l_4075;
	case 16504ULL: goto x86_l_4078;
	case 16510ULL: goto x86_l_407e;
	case 16514ULL: goto x86_l_4082;
	case 16517ULL: goto x86_l_4085;
	case 16522ULL: goto x86_l_408a;
	case 16525ULL: goto x86_l_408d;
	case 16529ULL: goto x86_l_4091;
	case 16533ULL: goto x86_l_4095;
	case 16536ULL: goto x86_l_4098;
	case 16540ULL: goto x86_l_409c;
	case 16542ULL: goto x86_l_409e;
	case 16548ULL: goto x86_l_40a4;
	case 16552ULL: goto x86_l_40a8;
	case 16554ULL: goto x86_l_40aa;
	case 16556ULL: goto x86_l_40ac;
	case 16560ULL: goto x86_l_40b0;
	case 16565ULL: goto x86_l_40b5;
	case 16570ULL: goto x86_l_40ba;
	case 16575ULL: goto x86_l_40bf;
	case 16577ULL: goto x86_l_40c1;
	case 16580ULL: goto x86_l_40c4;
	case 16586ULL: goto x86_l_40ca;
	case 16590ULL: goto x86_l_40ce;
	case 16594ULL: goto x86_l_40d2;
	case 16599ULL: goto x86_l_40d7;
	case 16602ULL: goto x86_l_40da;
	case 16606ULL: goto x86_l_40de;
	case 16610ULL: goto x86_l_40e2;
	case 16613ULL: goto x86_l_40e5;
	case 16617ULL: goto x86_l_40e9;
	case 16620ULL: goto x86_l_40ec;
	case 16626ULL: goto x86_l_40f2;
	case 16630ULL: goto x86_l_40f6;
	case 16633ULL: goto x86_l_40f9;
	case 16635ULL: goto x86_l_40fb;
	case 16639ULL: goto x86_l_40ff;
	case 16644ULL: goto x86_l_4104;
	case 16649ULL: goto x86_l_4109;
	case 16654ULL: goto x86_l_410e;
	case 16656ULL: goto x86_l_4110;
	case 16659ULL: goto x86_l_4113;
	case 16665ULL: goto x86_l_4119;
	case 16669ULL: goto x86_l_411d;
	case 16672ULL: goto x86_l_4120;
	case 16677ULL: goto x86_l_4125;
	case 16680ULL: goto x86_l_4128;
	case 16684ULL: goto x86_l_412c;
	case 16688ULL: goto x86_l_4130;
	case 16691ULL: goto x86_l_4133;
	case 16695ULL: goto x86_l_4137;
	case 16697ULL: goto x86_l_4139;
	case 16703ULL: goto x86_l_413f;
	case 16707ULL: goto x86_l_4143;
	case 16709ULL: goto x86_l_4145;
	case 16711ULL: goto x86_l_4147;
	case 16715ULL: goto x86_l_414b;
	case 16720ULL: goto x86_l_4150;
	case 16725ULL: goto x86_l_4155;
	case 16730ULL: goto x86_l_415a;
	case 16732ULL: goto x86_l_415c;
	case 16735ULL: goto x86_l_415f;
	case 16741ULL: goto x86_l_4165;
	case 16745ULL: goto x86_l_4169;
	case 16749ULL: goto x86_l_416d;
	case 16754ULL: goto x86_l_4172;
	case 16757ULL: goto x86_l_4175;
	case 16761ULL: goto x86_l_4179;
	case 16765ULL: goto x86_l_417d;
	case 16768ULL: goto x86_l_4180;
	case 16772ULL: goto x86_l_4184;
	case 16775ULL: goto x86_l_4187;
	case 16781ULL: goto x86_l_418d;
	case 16785ULL: goto x86_l_4191;
	case 16788ULL: goto x86_l_4194;
	case 16790ULL: goto x86_l_4196;
	case 16794ULL: goto x86_l_419a;
	case 16799ULL: goto x86_l_419f;
	case 16804ULL: goto x86_l_41a4;
	case 16809ULL: goto x86_l_41a9;
	case 16811ULL: goto x86_l_41ab;
	case 16814ULL: goto x86_l_41ae;
	case 16820ULL: goto x86_l_41b4;
	case 16824ULL: goto x86_l_41b8;
	case 16827ULL: goto x86_l_41bb;
	case 16832ULL: goto x86_l_41c0;
	case 16835ULL: goto x86_l_41c3;
	case 16839ULL: goto x86_l_41c7;
	case 16843ULL: goto x86_l_41cb;
	case 16846ULL: goto x86_l_41ce;
	case 16850ULL: goto x86_l_41d2;
	case 16852ULL: goto x86_l_41d4;
	case 16854ULL: goto x86_l_41d6;
	case 16858ULL: goto x86_l_41da;
	case 16860ULL: goto x86_l_41dc;
	case 16862ULL: goto x86_l_41de;
	case 16866ULL: goto x86_l_41e2;
	case 16871ULL: goto x86_l_41e7;
	case 16876ULL: goto x86_l_41ec;
	case 16881ULL: goto x86_l_41f1;
	case 16883ULL: goto x86_l_41f3;
	case 16886ULL: goto x86_l_41f6;
	case 16892ULL: goto x86_l_41fc;
	case 16896ULL: goto x86_l_4200;
	case 16899ULL: goto x86_l_4203;
	case 16904ULL: goto x86_l_4208;
	case 16907ULL: goto x86_l_420b;
	case 16910ULL: goto x86_l_420e;
	case 16914ULL: goto x86_l_4212;
	case 16917ULL: goto x86_l_4215;
	case 16921ULL: goto x86_l_4219;
	case 16923ULL: goto x86_l_421b;
	case 16929ULL: goto x86_l_4221;
	case 16933ULL: goto x86_l_4225;
	case 16936ULL: goto x86_l_4228;
	case 16938ULL: goto x86_l_422a;
	case 16944ULL: goto x86_l_4230;
	case 16947ULL: goto x86_l_4233;
	case 16955ULL: goto x86_l_423b;
	case 16963ULL: goto x86_l_4243;
	case 16968ULL: goto x86_l_4248;
	case 16973ULL: goto x86_l_424d;
	case 16975ULL: goto x86_l_424f;
	case 16978ULL: goto x86_l_4252;
	case 16984ULL: goto x86_l_4258;
	case 16987ULL: goto x86_l_425b;
	case 16994ULL: goto x86_l_4262;
	case 16997ULL: goto x86_l_4265;
	case 17003ULL: goto x86_l_426b;
	case 17008ULL: goto x86_l_4270;
	case 17012ULL: goto x86_l_4274;
	case 17014ULL: goto x86_l_4276;
	case 17021ULL: goto x86_l_427d;
	case 17026ULL: goto x86_l_4282;
	case 17028ULL: goto x86_l_4284;
	case 17035ULL: goto x86_l_428b;
	case 17039ULL: goto x86_l_428f;
	case 17043ULL: goto x86_l_4293;
	case 17050ULL: goto x86_l_429a;
	case 17055ULL: goto x86_l_429f;
	case 17057ULL: goto x86_l_42a1;
	case 17062ULL: goto x86_l_42a6;
	case 17068ULL: goto x86_l_42ac;
	case 17079ULL: goto x86_l_42b7;
	case 17086ULL: goto x86_l_42be;
	case 17094ULL: goto x86_l_42c6;
	case 17099ULL: goto x86_l_42cb;
	case 17101ULL: goto x86_l_42cd;
	case 17104ULL: goto x86_l_42d0;
	case 17110ULL: goto x86_l_42d6;
	case 17113ULL: goto x86_l_42d9;
	case 17118ULL: goto x86_l_42de;
	case 17123ULL: goto x86_l_42e3;
	case 17128ULL: goto x86_l_42e8;
	case 17134ULL: goto x86_l_42ee;
	case 17137ULL: goto x86_l_42f1;
	case 17142ULL: goto x86_l_42f6;
	case 17147ULL: goto x86_l_42fb;
	case 17152ULL: goto x86_l_4300;
	case 17157ULL: goto x86_l_4305;
	case 17159ULL: goto x86_l_4307;
	case 17166ULL: goto x86_l_430e;
	case 17169ULL: goto x86_l_4311;
	case 17175ULL: goto x86_l_4317;
	case 17185ULL: goto x86_l_4321;
	case 17190ULL: goto x86_l_4326;
	case 17200ULL: goto x86_l_4330;
	case 17205ULL: goto x86_l_4335;
	case 17215ULL: goto x86_l_433f;
	case 17220ULL: goto x86_l_4344;
	case 17230ULL: goto x86_l_434e;
	case 17235ULL: goto x86_l_4353;
	case 17245ULL: goto x86_l_435d;
	case 17250ULL: goto x86_l_4362;
	case 17258ULL: goto x86_l_436a;
	case 17263ULL: goto x86_l_436f;
	case 17268ULL: goto x86_l_4374;
	case 17273ULL: goto x86_l_4379;
	case 17278ULL: goto x86_l_437e;
	case 17285ULL: goto x86_l_4385;
	case 17288ULL: goto x86_l_4388;
	case 17294ULL: goto x86_l_438e;
	case 17301ULL: goto x86_l_4395;
	case 17304ULL: goto x86_l_4398;
	case 17310ULL: goto x86_l_439e;
	case 17317ULL: goto x86_l_43a5;
	case 17325ULL: goto x86_l_43ad;
	case 17330ULL: goto x86_l_43b2;
	case 17332ULL: goto x86_l_43b4;
	case 17337ULL: goto x86_l_43b9;
	case 17340ULL: goto x86_l_43bc;
	case 17346ULL: goto x86_l_43c2;
	case 17351ULL: goto x86_l_43c7;
	case 17354ULL: goto x86_l_43ca;
	case 17358ULL: goto x86_l_43ce;
	case 17360ULL: goto x86_l_43d0;
	case 17362ULL: goto x86_l_43d2;
	case 17369ULL: goto x86_l_43d9;
	case 17372ULL: goto x86_l_43dc;
	case 17378ULL: goto x86_l_43e2;
	case 17380ULL: goto x86_l_43e4;
	case 17383ULL: goto x86_l_43e7;
	case 17386ULL: goto x86_l_43ea;
	case 17389ULL: goto x86_l_43ed;
	case 17391ULL: goto x86_l_43ef;
	case 17393ULL: goto x86_l_43f1;
	case 17395ULL: goto x86_l_43f3;
	case 17398ULL: goto x86_l_43f6;
	case 17401ULL: goto x86_l_43f9;
	case 17403ULL: goto x86_l_43fb;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3dd3:
	/* 0x3dd3: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_3dd7:
	/* 0x3dd7: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ddb:
	/* 0x3ddb: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_3dde:
	/* 0x3dde: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3de2:
	/* 0x3de2: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_3de5:
	/* 0x3de5: jae    4221 <kprobe_unwind_native+0x4221> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4221;
	}
x86_l_3deb:
	/* 0x3deb: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3def:
	/* 0x3def: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3df2:
	/* 0x3df2: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_3df4:
	/* 0x3df4: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3df8:
	/* 0x3df8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3dfd:
	/* 0x3dfd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e02:
	/* 0x3e02: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3e07:
	/* 0x3e07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e09:
	/* 0x3e09: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e0c:
	/* 0x3e0c: je     4307 <kprobe_unwind_native+0x4307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4307;
	}
x86_l_3e12:
	/* 0x3e12: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e16:
	/* 0x3e16: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3e19:
	/* 0x3e19: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e1e:
	/* 0x3e1e: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e21:
	/* 0x3e21: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_3e25:
	/* 0x3e25: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e29:
	/* 0x3e29: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_3e2c:
	/* 0x3e2c: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e30:
	/* 0x3e30: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_3e32:
	/* 0x3e32: jae    4221 <kprobe_unwind_native+0x4221> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4221;
	}
x86_l_3e38:
	/* 0x3e38: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e3c:
	/* 0x3e3c: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3e3e:
	/* 0x3e3e: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_3e40:
	/* 0x3e40: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e44:
	/* 0x3e44: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e49:
	/* 0x3e49: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e4e:
	/* 0x3e4e: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3e53:
	/* 0x3e53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e55:
	/* 0x3e55: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e58:
	/* 0x3e58: je     4307 <kprobe_unwind_native+0x4307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4307;
	}
x86_l_3e5e:
	/* 0x3e5e: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e62:
	/* 0x3e62: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3e66:
	/* 0x3e66: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e6b:
	/* 0x3e6b: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e6e:
	/* 0x3e6e: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_3e72:
	/* 0x3e72: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e76:
	/* 0x3e76: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_3e79:
	/* 0x3e79: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e7d:
	/* 0x3e7d: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_3e80:
	/* 0x3e80: jae    4221 <kprobe_unwind_native+0x4221> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4221;
	}
x86_l_3e86:
	/* 0x3e86: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e8a:
	/* 0x3e8a: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3e8d:
	/* 0x3e8d: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_3e8f:
	/* 0x3e8f: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e93:
	/* 0x3e93: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e98:
	/* 0x3e98: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e9d:
	/* 0x3e9d: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3ea2:
	/* 0x3ea2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ea4:
	/* 0x3ea4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3ea7:
	/* 0x3ea7: je     4307 <kprobe_unwind_native+0x4307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4307;
	}
x86_l_3ead:
	/* 0x3ead: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3eb1:
	/* 0x3eb1: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3eb4:
	/* 0x3eb4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3eb9:
	/* 0x3eb9: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ebc:
	/* 0x3ebc: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_3ec0:
	/* 0x3ec0: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ec4:
	/* 0x3ec4: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_3ec7:
	/* 0x3ec7: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ecb:
	/* 0x3ecb: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_3ecd:
	/* 0x3ecd: jae    4221 <kprobe_unwind_native+0x4221> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4221;
	}
x86_l_3ed3:
	/* 0x3ed3: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ed7:
	/* 0x3ed7: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3ed9:
	/* 0x3ed9: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_3edb:
	/* 0x3edb: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3edf:
	/* 0x3edf: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ee4:
	/* 0x3ee4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3ee9:
	/* 0x3ee9: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3eee:
	/* 0x3eee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ef0:
	/* 0x3ef0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3ef3:
	/* 0x3ef3: je     4307 <kprobe_unwind_native+0x4307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4307;
	}
x86_l_3ef9:
	/* 0x3ef9: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3efd:
	/* 0x3efd: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3f01:
	/* 0x3f01: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f06:
	/* 0x3f06: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f09:
	/* 0x3f09: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_3f0d:
	/* 0x3f0d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f11:
	/* 0x3f11: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_3f14:
	/* 0x3f14: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f18:
	/* 0x3f18: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_3f1b:
	/* 0x3f1b: jae    4221 <kprobe_unwind_native+0x4221> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4221;
	}
x86_l_3f21:
	/* 0x3f21: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f25:
	/* 0x3f25: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3f28:
	/* 0x3f28: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_3f2a:
	/* 0x3f2a: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f2e:
	/* 0x3f2e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f33:
	/* 0x3f33: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3f38:
	/* 0x3f38: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3f3d:
	/* 0x3f3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f3f:
	/* 0x3f3f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f42:
	/* 0x3f42: je     4307 <kprobe_unwind_native+0x4307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4307;
	}
x86_l_3f48:
	/* 0x3f48: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f4c:
	/* 0x3f4c: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3f4f:
	/* 0x3f4f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f54:
	/* 0x3f54: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f57:
	/* 0x3f57: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_3f5b:
	/* 0x3f5b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f5f:
	/* 0x3f5f: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_3f62:
	/* 0x3f62: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f66:
	/* 0x3f66: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_3f68:
	/* 0x3f68: jae    4221 <kprobe_unwind_native+0x4221> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4221;
	}
x86_l_3f6e:
	/* 0x3f6e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f72:
	/* 0x3f72: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3f74:
	/* 0x3f74: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_3f76:
	/* 0x3f76: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f7a:
	/* 0x3f7a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f7f:
	/* 0x3f7f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3f84:
	/* 0x3f84: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3f89:
	/* 0x3f89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f8b:
	/* 0x3f8b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f8e:
	/* 0x3f8e: je     4307 <kprobe_unwind_native+0x4307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4307;
	}
x86_l_3f94:
	/* 0x3f94: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3f98:
	/* 0x3f98: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3f9c:
	/* 0x3f9c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fa1:
	/* 0x3fa1: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fa4:
	/* 0x3fa4: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_3fa8:
	/* 0x3fa8: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fac:
	/* 0x3fac: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_3faf:
	/* 0x3faf: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fb3:
	/* 0x3fb3: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_3fb6:
	/* 0x3fb6: jae    4221 <kprobe_unwind_native+0x4221> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4221;
	}
x86_l_3fbc:
	/* 0x3fbc: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fc0:
	/* 0x3fc0: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3fc3:
	/* 0x3fc3: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_3fc5:
	/* 0x3fc5: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3fc9:
	/* 0x3fc9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3fce:
	/* 0x3fce: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3fd3:
	/* 0x3fd3: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3fd8:
	/* 0x3fd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fda:
	/* 0x3fda: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3fdd:
	/* 0x3fdd: je     4307 <kprobe_unwind_native+0x4307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4307;
	}
x86_l_3fe3:
	/* 0x3fe3: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3fe7:
	/* 0x3fe7: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_3fea:
	/* 0x3fea: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fef:
	/* 0x3fef: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ff2:
	/* 0x3ff2: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_3ff6:
	/* 0x3ff6: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ffa:
	/* 0x3ffa: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_3ffd:
	/* 0x3ffd: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4001:
	/* 0x4001: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_4003:
	/* 0x4003: jae    4221 <kprobe_unwind_native+0x4221> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4221;
	}
x86_l_4009:
	/* 0x4009: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_400d:
	/* 0x400d: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_400f:
	/* 0x400f: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_4011:
	/* 0x4011: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4015:
	/* 0x4015: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_401a:
	/* 0x401a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_401f:
	/* 0x401f: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4024:
	/* 0x4024: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4026:
	/* 0x4026: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4029:
	/* 0x4029: je     4307 <kprobe_unwind_native+0x4307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4307;
	}
x86_l_402f:
	/* 0x402f: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4033:
	/* 0x4033: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4037:
	/* 0x4037: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_403c:
	/* 0x403c: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_403f:
	/* 0x403f: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_4043:
	/* 0x4043: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4047:
	/* 0x4047: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_404a:
	/* 0x404a: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_404e:
	/* 0x404e: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_4051:
	/* 0x4051: jae    4221 <kprobe_unwind_native+0x4221> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4221;
	}
x86_l_4057:
	/* 0x4057: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_405b:
	/* 0x405b: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_405e:
	/* 0x405e: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_4060:
	/* 0x4060: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4064:
	/* 0x4064: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4069:
	/* 0x4069: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_406e:
	/* 0x406e: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4073:
	/* 0x4073: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4075:
	/* 0x4075: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4078:
	/* 0x4078: je     4307 <kprobe_unwind_native+0x4307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4307;
	}
x86_l_407e:
	/* 0x407e: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4082:
	/* 0x4082: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4085:
	/* 0x4085: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_408a:
	/* 0x408a: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_408d:
	/* 0x408d: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_4091:
	/* 0x4091: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4095:
	/* 0x4095: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_4098:
	/* 0x4098: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_409c:
	/* 0x409c: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_409e:
	/* 0x409e: jae    4221 <kprobe_unwind_native+0x4221> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4221;
	}
x86_l_40a4:
	/* 0x40a4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40a8:
	/* 0x40a8: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_40aa:
	/* 0x40aa: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_40ac:
	/* 0x40ac: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40b0:
	/* 0x40b0: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40b5:
	/* 0x40b5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_40ba:
	/* 0x40ba: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_40bf:
	/* 0x40bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40c1:
	/* 0x40c1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_40c4:
	/* 0x40c4: je     4307 <kprobe_unwind_native+0x4307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4307;
	}
x86_l_40ca:
	/* 0x40ca: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40ce:
	/* 0x40ce: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_40d2:
	/* 0x40d2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40d7:
	/* 0x40d7: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40da:
	/* 0x40da: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_40de:
	/* 0x40de: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40e2:
	/* 0x40e2: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_40e5:
	/* 0x40e5: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40e9:
	/* 0x40e9: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_40ec:
	/* 0x40ec: jae    4221 <kprobe_unwind_native+0x4221> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4221;
	}
x86_l_40f2:
	/* 0x40f2: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40f6:
	/* 0x40f6: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_40f9:
	/* 0x40f9: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_40fb:
	/* 0x40fb: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40ff:
	/* 0x40ff: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4104:
	/* 0x4104: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4109:
	/* 0x4109: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_410e:
	/* 0x410e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4110:
	/* 0x4110: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4113:
	/* 0x4113: je     4307 <kprobe_unwind_native+0x4307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4307;
	}
x86_l_4119:
	/* 0x4119: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_411d:
	/* 0x411d: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4120:
	/* 0x4120: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4125:
	/* 0x4125: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4128:
	/* 0x4128: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_412c:
	/* 0x412c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4130:
	/* 0x4130: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_4133:
	/* 0x4133: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4137:
	/* 0x4137: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_4139:
	/* 0x4139: jae    4221 <kprobe_unwind_native+0x4221> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4221;
	}
x86_l_413f:
	/* 0x413f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4143:
	/* 0x4143: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4145:
	/* 0x4145: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_4147:
	/* 0x4147: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_414b:
	/* 0x414b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4150:
	/* 0x4150: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4155:
	/* 0x4155: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_415a:
	/* 0x415a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_415c:
	/* 0x415c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_415f:
	/* 0x415f: je     4307 <kprobe_unwind_native+0x4307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4307;
	}
x86_l_4165:
	/* 0x4165: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4169:
	/* 0x4169: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_416d:
	/* 0x416d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4172:
	/* 0x4172: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4175:
	/* 0x4175: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_4179:
	/* 0x4179: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_417d:
	/* 0x417d: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_4180:
	/* 0x4180: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4184:
	/* 0x4184: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_4187:
	/* 0x4187: jae    4221 <kprobe_unwind_native+0x4221> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4221;
	}
x86_l_418d:
	/* 0x418d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4191:
	/* 0x4191: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4194:
	/* 0x4194: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_4196:
	/* 0x4196: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_419a:
	/* 0x419a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_419f:
	/* 0x419f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_41a4:
	/* 0x41a4: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_41a9:
	/* 0x41a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41ab:
	/* 0x41ab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_41ae:
	/* 0x41ae: je     4307 <kprobe_unwind_native+0x4307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4307;
	}
x86_l_41b4:
	/* 0x41b4: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41b8:
	/* 0x41b8: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_41bb:
	/* 0x41bb: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41c0:
	/* 0x41c0: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41c3:
	/* 0x41c3: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_41c7:
	/* 0x41c7: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41cb:
	/* 0x41cb: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_41ce:
	/* 0x41ce: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41d2:
	/* 0x41d2: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_41d4:
	/* 0x41d4: jae    4221 <kprobe_unwind_native+0x4221> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4221;
	}
x86_l_41d6:
	/* 0x41d6: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41da:
	/* 0x41da: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_41dc:
	/* 0x41dc: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_41de:
	/* 0x41de: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41e2:
	/* 0x41e2: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_41e7:
	/* 0x41e7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_41ec:
	/* 0x41ec: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_41f1:
	/* 0x41f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41f3:
	/* 0x41f3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_41f6:
	/* 0x41f6: je     4307 <kprobe_unwind_native+0x4307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4307;
	}
x86_l_41fc:
	/* 0x41fc: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4200:
	/* 0x4200: lea    edx,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4203:
	/* 0x4203: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4208:
	/* 0x4208: cmp    WORD PTR [rax],si */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_420b:
	/* 0x420b: cmova  edx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_420e:
	/* 0x420e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4212:
	/* 0x4212: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_4215:
	/* 0x4215: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4219:
	/* 0x4219: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_421b:
	/* 0x421b: jb     4307 <kprobe_unwind_native+0x4307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4307;
	}
x86_l_4221:
	/* 0x4221: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4225:
	/* 0x4225: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_4228:
	/* 0x4228: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_422a:
	/* 0x422a: je     4307 <kprobe_unwind_native+0x4307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4307;
	}
x86_l_4230:
	/* 0x4230: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_4233:
	/* 0x4233: mov    DWORD PTR [rsp+0x90],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_423b:
	/* 0x423b: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4243:
	/* 0x4243: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4248:
	/* 0x4248: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_424d:
	/* 0x424d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_424f:
	/* 0x424f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4252:
	/* 0x4252: je     42fb <kprobe_unwind_native+0x42fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42fb;
	}
x86_l_4258:
	/* 0x4258: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_425b:
	/* 0x425b: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4262:
	/* 0x4262: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4265:
	/* 0x4265: jne    491a <kprobe_unwind_native+0x491a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18714ULL;
	}
x86_l_426b:
	/* 0x426b: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_4270:
	/* 0x4270: movzx  ecx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4274:
	/* 0x4274: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4276:
	/* 0x4276: mov    ecx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_427d:
	/* 0x427d: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4282:
	/* 0x4282: cmp    ecx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_4284:
	/* 0x4284: lea    r13d,[rax+0x10000] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 65536ULL);
x86_l_428b:
	/* 0x428b: cmovae r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_428f:
	/* 0x428f: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_4293:
	/* 0x4293: mov    DWORD PTR [rsp+0x8c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_429a:
	/* 0x429a: cmp    eax,0x8000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32768ULL);
x86_l_429f:
	/* 0x429f: je     42de <kprobe_unwind_native+0x42de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42de;
	}
x86_l_42a1:
	/* 0x42a1: cmp    eax,0x8001 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32769ULL);
x86_l_42a6:
	/* 0x42a6: jne    4395 <kprobe_unwind_native+0x4395> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4395;
	}
x86_l_42ac:
	/* 0x42ac: mov    DWORD PTR [rsp+0x94],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159815ULL);
x86_l_42b7:
	/* 0x42b7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_42be:
	/* 0x42be: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_42c6:
	/* 0x42c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_42cb:
	/* 0x42cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42cd:
	/* 0x42cd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_42d0:
	/* 0x42d0: je     437e <kprobe_unwind_native+0x437e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_437e;
	}
x86_l_42d6:
	/* 0x42d6: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_42d9:
	/* 0x42d9: jmp    438e <kprobe_unwind_native+0x438e> */
	goto x86_l_438e;
x86_l_42de:
	/* 0x42de: mov    edx,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_42e3:
	/* 0x42e3: mov    ecx,0xfa5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4005ULL);
x86_l_42e8:
	/* 0x42e8: mov    DWORD PTR [rbx+0xf28],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3880ULL);
x86_l_42ee:
	/* 0x42ee: mov    r13d,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_32);
x86_l_42f1:
	/* 0x42f1: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_42f6:
	/* 0x42f6: jmp    5f4c <kprobe_unwind_native+0x5f4c> */
	return 24396ULL;
x86_l_42fb:
	/* 0x42fb: mov    ecx,0xfa4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4004ULL);
x86_l_4300:
	/* 0x4300: mov    edx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_4305:
	/* 0x4305: jmp    42e8 <kprobe_unwind_native+0x42e8> */
	goto x86_l_42e8;
x86_l_4307:
	/* 0x4307: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_430e:
	/* 0x430e: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4311:
	/* 0x4311: je     2722 <kprobe_unwind_native+0x2722> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10018ULL;
	}
x86_l_4317:
	/* 0x4317: movabs rax,0x6174616420747075 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7022344801646571637ULL);
x86_l_4321:
	/* 0x4321: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4326:
	/* 0x4326: movabs rax,0x72726f43202e7370 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8246776201762206576ULL);
x86_l_4330:
	/* 0x4330: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4335:
	/* 0x4335: movabs rax,0x657473203631206e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310594677314494574ULL);
x86_l_433f:
	/* 0x433f: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4344:
	/* 0x4344: movabs rax,0x6920686372616573 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575169349567210867ULL);
x86_l_434e:
	/* 0x434e: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4353:
	/* 0x4353: movabs rax,0x622064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7070761801744998726ULL);
x86_l_435d:
	/* 0x435d: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4362:
	/* 0x4362: mov    DWORD PTR [rsp+0x37],0xa3f61 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 236223872865ULL);
x86_l_436a:
	/* 0x436a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_436f:
	/* 0x436f: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_4374:
	/* 0x4374: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4379:
	/* 0x4379: jmp    2d4d <kprobe_unwind_native+0x2d4d> */
	return 11597ULL;
x86_l_437e:
	/* 0x437e: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4385:
	/* 0x4385: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4388:
	/* 0x4388: jne    4aa7 <kprobe_unwind_native+0x4aa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 19111ULL;
	}
x86_l_438e:
	/* 0x438e: mov    eax,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_4395:
	/* 0x4395: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_4398:
	/* 0x4398: js     444b <kprobe_unwind_native+0x444b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 17483ULL;
	}
x86_l_439e:
	/* 0x439e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&unwind_info_array)));
x86_l_43a5:
	/* 0x43a5: lea    rsi,[rsp+0x8c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_43ad:
	/* 0x43ad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_43b2:
	/* 0x43b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43b4:
	/* 0x43b4: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_43b9:
	/* 0x43b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_43bc:
	/* 0x43bc: je     6315 <kprobe_unwind_native+0x6315> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25365ULL;
	}
x86_l_43c2:
	/* 0x43c2: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_43c7:
	/* 0x43c7: mov    ebp,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_43ca:
	/* 0x43ca: movzx  eax,BYTE PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_43ce:
	/* 0x43ce: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_43d0:
	/* 0x43d0: je     440e <kprobe_unwind_native+0x440e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17422ULL;
	}
x86_l_43d2:
	/* 0x43d2: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_43d9:
	/* 0x43d9: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43dc:
	/* 0x43dc: jne    4a33 <kprobe_unwind_native+0x4a33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 18995ULL;
	}
x86_l_43e2:
	/* 0x43e2: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_43e4:
	/* 0x43e4: and    cl,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_43e7:
	/* 0x43e7: movzx  ecx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_43ea:
	/* 0x43ea: cmp    r13d,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RCX, X86_WIDTH_32);
x86_l_43ed:
	/* 0x43ed: jl     440e <kprobe_unwind_native+0x440e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 17422ULL;
	}
x86_l_43ef:
	/* 0x43ef: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_43f1:
	/* 0x43f1: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_43f3:
	/* 0x43f3: setns  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NS);
x86_l_43f6:
	/* 0x43f6: shl    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_43f9:
	/* 0x43f9: add    ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_43fb:
	/* 0x43fb: add    ebp,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4294967288ULL);
	return 17406ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 17406ULL: goto x86_l_43fe;
	case 17413ULL: goto x86_l_4405;
	case 17416ULL: goto x86_l_4408;
	case 17422ULL: goto x86_l_440e;
	case 17427ULL: goto x86_l_4413;
	case 17430ULL: goto x86_l_4416;
	case 17432ULL: goto x86_l_4418;
	case 17435ULL: goto x86_l_441b;
	case 17437ULL: goto x86_l_441d;
	case 17440ULL: goto x86_l_4420;
	case 17442ULL: goto x86_l_4422;
	case 17445ULL: goto x86_l_4425;
	case 17448ULL: goto x86_l_4428;
	case 17451ULL: goto x86_l_442b;
	case 17457ULL: goto x86_l_4431;
	case 17460ULL: goto x86_l_4434;
	case 17466ULL: goto x86_l_443a;
	case 17469ULL: goto x86_l_443d;
	case 17472ULL: goto x86_l_4440;
	case 17478ULL: goto x86_l_4446;
	case 17483ULL: goto x86_l_444b;
	case 17488ULL: goto x86_l_4450;
	case 17494ULL: goto x86_l_4456;
	case 17497ULL: goto x86_l_4459;
	case 17503ULL: goto x86_l_445f;
	case 17506ULL: goto x86_l_4462;
	case 17511ULL: goto x86_l_4467;
	case 17519ULL: goto x86_l_446f;
	case 17525ULL: goto x86_l_4475;
	case 17528ULL: goto x86_l_4478;
	case 17534ULL: goto x86_l_447e;
	case 17537ULL: goto x86_l_4481;
	case 17540ULL: goto x86_l_4484;
	case 17542ULL: goto x86_l_4486;
	case 17545ULL: goto x86_l_4489;
	case 17547ULL: goto x86_l_448b;
	case 17550ULL: goto x86_l_448e;
	case 17553ULL: goto x86_l_4491;
	case 17557ULL: goto x86_l_4495;
	case 17561ULL: goto x86_l_4499;
	case 17568ULL: goto x86_l_44a0;
	case 17571ULL: goto x86_l_44a3;
	case 17577ULL: goto x86_l_44a9;
	case 17587ULL: goto x86_l_44b3;
	case 17592ULL: goto x86_l_44b8;
	case 17602ULL: goto x86_l_44c2;
	case 17607ULL: goto x86_l_44c7;
	case 17612ULL: goto x86_l_44cc;
	case 17617ULL: goto x86_l_44d1;
	case 17622ULL: goto x86_l_44d6;
	case 17627ULL: goto x86_l_44db;
	case 17630ULL: goto x86_l_44de;
	case 17632ULL: goto x86_l_44e0;
	case 17634ULL: goto x86_l_44e2;
	case 17639ULL: goto x86_l_44e7;
	case 17642ULL: goto x86_l_44ea;
	case 17648ULL: goto x86_l_44f0;
	case 17651ULL: goto x86_l_44f3;
	case 17656ULL: goto x86_l_44f8;
	case 17661ULL: goto x86_l_44fd;
	case 17667ULL: goto x86_l_4503;
	case 17670ULL: goto x86_l_4506;
	case 17675ULL: goto x86_l_450b;
	case 17680ULL: goto x86_l_4510;
	case 17686ULL: goto x86_l_4516;
	case 17689ULL: goto x86_l_4519;
	case 17694ULL: goto x86_l_451e;
	case 17697ULL: goto x86_l_4521;
	case 17700ULL: goto x86_l_4524;
	case 17706ULL: goto x86_l_452a;
	case 17713ULL: goto x86_l_4531;
	case 17717ULL: goto x86_l_4535;
	case 17724ULL: goto x86_l_453c;
	case 17729ULL: goto x86_l_4541;
	case 17736ULL: goto x86_l_4548;
	case 17741ULL: goto x86_l_454d;
	case 17748ULL: goto x86_l_4554;
	case 17753ULL: goto x86_l_4559;
	case 17756ULL: goto x86_l_455c;
	case 17762ULL: goto x86_l_4562;
	case 17765ULL: goto x86_l_4565;
	case 17771ULL: goto x86_l_456b;
	case 17773ULL: goto x86_l_456d;
	case 17775ULL: goto x86_l_456f;
	case 17778ULL: goto x86_l_4572;
	case 17780ULL: goto x86_l_4574;
	case 17785ULL: goto x86_l_4579;
	case 17792ULL: goto x86_l_4580;
	case 17795ULL: goto x86_l_4583;
	case 17801ULL: goto x86_l_4589;
	case 17804ULL: goto x86_l_458c;
	case 17807ULL: goto x86_l_458f;
	case 17810ULL: goto x86_l_4592;
	case 17816ULL: goto x86_l_4598;
	case 17824ULL: goto x86_l_45a0;
	case 17826ULL: goto x86_l_45a2;
	case 17832ULL: goto x86_l_45a8;
	case 17835ULL: goto x86_l_45ab;
	case 17841ULL: goto x86_l_45b1;
	case 17849ULL: goto x86_l_45b9;
	case 17854ULL: goto x86_l_45be;
	case 17857ULL: goto x86_l_45c1;
	case 17861ULL: goto x86_l_45c5;
	case 17869ULL: goto x86_l_45cd;
	case 17874ULL: goto x86_l_45d2;
	case 17880ULL: goto x86_l_45d8;
	case 17883ULL: goto x86_l_45db;
	case 17887ULL: goto x86_l_45df;
	case 17892ULL: goto x86_l_45e4;
	case 17895ULL: goto x86_l_45e7;
	case 17898ULL: goto x86_l_45ea;
	case 17903ULL: goto x86_l_45ef;
	case 17909ULL: goto x86_l_45f5;
	case 17917ULL: goto x86_l_45fd;
	case 17924ULL: goto x86_l_4604;
	case 17932ULL: goto x86_l_460c;
	case 17939ULL: goto x86_l_4613;
	case 17947ULL: goto x86_l_461b;
	case 17954ULL: goto x86_l_4622;
	case 17962ULL: goto x86_l_462a;
	case 17969ULL: goto x86_l_4631;
	case 17977ULL: goto x86_l_4639;
	case 17984ULL: goto x86_l_4640;
	case 17992ULL: goto x86_l_4648;
	case 17999ULL: goto x86_l_464f;
	case 18007ULL: goto x86_l_4657;
	case 18014ULL: goto x86_l_465e;
	case 18022ULL: goto x86_l_4666;
	case 18029ULL: goto x86_l_466d;
	case 18036ULL: goto x86_l_4674;
	case 18043ULL: goto x86_l_467b;
	case 18046ULL: goto x86_l_467e;
	case 18052ULL: goto x86_l_4684;
	case 18062ULL: goto x86_l_468e;
	case 18067ULL: goto x86_l_4693;
	case 18077ULL: goto x86_l_469d;
	case 18082ULL: goto x86_l_46a2;
	case 18087ULL: goto x86_l_46a7;
	case 18092ULL: goto x86_l_46ac;
	case 18097ULL: goto x86_l_46b1;
	case 18102ULL: goto x86_l_46b6;
	case 18104ULL: goto x86_l_46b8;
	case 18106ULL: goto x86_l_46ba;
	case 18111ULL: goto x86_l_46bf;
	case 18116ULL: goto x86_l_46c4;
	case 18119ULL: goto x86_l_46c7;
	case 18122ULL: goto x86_l_46ca;
	case 18125ULL: goto x86_l_46cd;
	case 18128ULL: goto x86_l_46d0;
	case 18130ULL: goto x86_l_46d2;
	case 18136ULL: goto x86_l_46d8;
	case 18141ULL: goto x86_l_46dd;
	case 18146ULL: goto x86_l_46e2;
	case 18151ULL: goto x86_l_46e7;
	case 18156ULL: goto x86_l_46ec;
	case 18159ULL: goto x86_l_46ef;
	case 18161ULL: goto x86_l_46f1;
	case 18164ULL: goto x86_l_46f4;
	case 18166ULL: goto x86_l_46f6;
	case 18173ULL: goto x86_l_46fd;
	case 18176ULL: goto x86_l_4700;
	case 18182ULL: goto x86_l_4706;
	case 18185ULL: goto x86_l_4709;
	case 18190ULL: goto x86_l_470e;
	case 18193ULL: goto x86_l_4711;
	case 18196ULL: goto x86_l_4714;
	case 18201ULL: goto x86_l_4719;
	case 18204ULL: goto x86_l_471c;
	case 18209ULL: goto x86_l_4721;
	case 18215ULL: goto x86_l_4727;
	case 18225ULL: goto x86_l_4731;
	case 18233ULL: goto x86_l_4739;
	case 18243ULL: goto x86_l_4743;
	case 18251ULL: goto x86_l_474b;
	case 18261ULL: goto x86_l_4755;
	case 18269ULL: goto x86_l_475d;
	case 18280ULL: goto x86_l_4768;
	case 18288ULL: goto x86_l_4770;
	case 18293ULL: goto x86_l_4775;
	case 18298ULL: goto x86_l_477a;
	case 18303ULL: goto x86_l_477f;
	case 18305ULL: goto x86_l_4781;
	case 18307ULL: goto x86_l_4783;
	case 18312ULL: goto x86_l_4788;
	case 18322ULL: goto x86_l_4792;
	case 18327ULL: goto x86_l_4797;
	case 18337ULL: goto x86_l_47a1;
	case 18342ULL: goto x86_l_47a6;
	case 18352ULL: goto x86_l_47b0;
	case 18357ULL: goto x86_l_47b5;
	case 18367ULL: goto x86_l_47bf;
	case 18372ULL: goto x86_l_47c4;
	case 18377ULL: goto x86_l_47c9;
	case 18382ULL: goto x86_l_47ce;
	case 18387ULL: goto x86_l_47d3;
	case 18393ULL: goto x86_l_47d9;
	case 18400ULL: goto x86_l_47e0;
	case 18407ULL: goto x86_l_47e7;
	case 18412ULL: goto x86_l_47ec;
	case 18414ULL: goto x86_l_47ee;
	case 18417ULL: goto x86_l_47f1;
	case 18422ULL: goto x86_l_47f6;
	case 18432ULL: goto x86_l_4800;
	case 18440ULL: goto x86_l_4808;
	case 18450ULL: goto x86_l_4812;
	case 18458ULL: goto x86_l_481a;
	case 18468ULL: goto x86_l_4824;
	case 18476ULL: goto x86_l_482c;
	case 18486ULL: goto x86_l_4836;
	case 18494ULL: goto x86_l_483e;
	case 18504ULL: goto x86_l_4848;
	case 18512ULL: goto x86_l_4850;
	case 18522ULL: goto x86_l_485a;
	case 18530ULL: goto x86_l_4862;
	case 18538ULL: goto x86_l_486a;
	case 18543ULL: goto x86_l_486f;
	case 18548ULL: goto x86_l_4874;
	case 18552ULL: goto x86_l_4878;
	case 18557ULL: goto x86_l_487d;
	case 18559ULL: goto x86_l_487f;
	case 18561ULL: goto x86_l_4881;
	case 18568ULL: goto x86_l_4888;
	case 18571ULL: goto x86_l_488b;
	case 18577ULL: goto x86_l_4891;
	case 18582ULL: goto x86_l_4896;
	case 18592ULL: goto x86_l_48a0;
	case 18597ULL: goto x86_l_48a5;
	case 18607ULL: goto x86_l_48af;
	case 18612ULL: goto x86_l_48b4;
	case 18622ULL: goto x86_l_48be;
	case 18627ULL: goto x86_l_48c3;
	case 18637ULL: goto x86_l_48cd;
	case 18642ULL: goto x86_l_48d2;
	case 18652ULL: goto x86_l_48dc;
	case 18657ULL: goto x86_l_48e1;
	case 18667ULL: goto x86_l_48eb;
	case 18672ULL: goto x86_l_48f0;
	case 18677ULL: goto x86_l_48f5;
	case 18682ULL: goto x86_l_48fa;
	case 18688ULL: goto x86_l_4900;
	case 18691ULL: goto x86_l_4903;
	case 18696ULL: goto x86_l_4908;
	case 18701ULL: goto x86_l_490d;
	case 18704ULL: goto x86_l_4910;
	case 18706ULL: goto x86_l_4912;
	case 18709ULL: goto x86_l_4915;
	case 18714ULL: goto x86_l_491a;
	case 18724ULL: goto x86_l_4924;
	case 18729ULL: goto x86_l_4929;
	case 18739ULL: goto x86_l_4933;
	case 18744ULL: goto x86_l_4938;
	case 18754ULL: goto x86_l_4942;
	case 18759ULL: goto x86_l_4947;
	case 18769ULL: goto x86_l_4951;
	case 18774ULL: goto x86_l_4956;
	case 18784ULL: goto x86_l_4960;
	case 18789ULL: goto x86_l_4965;
	case 18799ULL: goto x86_l_496f;
	case 18804ULL: goto x86_l_4974;
	case 18809ULL: goto x86_l_4979;
	case 18814ULL: goto x86_l_497e;
	case 18820ULL: goto x86_l_4984;
	case 18827ULL: goto x86_l_498b;
	case 18831ULL: goto x86_l_498f;
	case 18836ULL: goto x86_l_4994;
	case 18841ULL: goto x86_l_4999;
	case 18843ULL: goto x86_l_499b;
	case 18846ULL: goto x86_l_499e;
	case 18851ULL: goto x86_l_49a3;
	case 18861ULL: goto x86_l_49ad;
	case 18869ULL: goto x86_l_49b5;
	case 18879ULL: goto x86_l_49bf;
	case 18887ULL: goto x86_l_49c7;
	case 18897ULL: goto x86_l_49d1;
	case 18905ULL: goto x86_l_49d9;
	case 18915ULL: goto x86_l_49e3;
	case 18923ULL: goto x86_l_49eb;
	case 18933ULL: goto x86_l_49f5;
	case 18941ULL: goto x86_l_49fd;
	case 18951ULL: goto x86_l_4a07;
	case 18959ULL: goto x86_l_4a0f;
	case 18967ULL: goto x86_l_4a17;
	case 18972ULL: goto x86_l_4a1c;
	case 18977ULL: goto x86_l_4a21;
	case 18981ULL: goto x86_l_4a25;
	case 18986ULL: goto x86_l_4a2a;
	case 18988ULL: goto x86_l_4a2c;
	case 18990ULL: goto x86_l_4a2e;
	case 18995ULL: goto x86_l_4a33;
	case 19005ULL: goto x86_l_4a3d;
	case 19010ULL: goto x86_l_4a42;
	case 19020ULL: goto x86_l_4a4c;
	case 19025ULL: goto x86_l_4a51;
	case 19035ULL: goto x86_l_4a5b;
	case 19040ULL: goto x86_l_4a60;
	case 19050ULL: goto x86_l_4a6a;
	case 19055ULL: goto x86_l_4a6f;
	case 19060ULL: goto x86_l_4a74;
	case 19065ULL: goto x86_l_4a79;
	case 19070ULL: goto x86_l_4a7e;
	case 19076ULL: goto x86_l_4a84;
	case 19081ULL: goto x86_l_4a89;
	case 19087ULL: goto x86_l_4a8f;
	case 19092ULL: goto x86_l_4a94;
	case 19095ULL: goto x86_l_4a97;
	case 19097ULL: goto x86_l_4a99;
	case 19100ULL: goto x86_l_4a9c;
	case 19106ULL: goto x86_l_4aa2;
	case 19111ULL: goto x86_l_4aa7;
	case 19121ULL: goto x86_l_4ab1;
	case 19126ULL: goto x86_l_4ab6;
	case 19136ULL: goto x86_l_4ac0;
	case 19141ULL: goto x86_l_4ac5;
	case 19151ULL: goto x86_l_4acf;
	case 19156ULL: goto x86_l_4ad4;
	case 19166ULL: goto x86_l_4ade;
	case 19171ULL: goto x86_l_4ae3;
	case 19181ULL: goto x86_l_4aed;
	case 19186ULL: goto x86_l_4af2;
	case 19196ULL: goto x86_l_4afc;
	case 19201ULL: goto x86_l_4b01;
	case 19206ULL: goto x86_l_4b06;
	case 19211ULL: goto x86_l_4b0b;
	case 19216ULL: goto x86_l_4b10;
	case 19223ULL: goto x86_l_4b17;
	case 19228ULL: goto x86_l_4b1c;
	case 19230ULL: goto x86_l_4b1e;
	case 19232ULL: goto x86_l_4b20;
	case 19237ULL: goto x86_l_4b25;
	case 19247ULL: goto x86_l_4b2f;
	case 19252ULL: goto x86_l_4b34;
	case 19262ULL: goto x86_l_4b3e;
	case 19267ULL: goto x86_l_4b43;
	case 19277ULL: goto x86_l_4b4d;
	case 19282ULL: goto x86_l_4b52;
	case 19292ULL: goto x86_l_4b5c;
	case 19297ULL: goto x86_l_4b61;
	case 19302ULL: goto x86_l_4b66;
	case 19307ULL: goto x86_l_4b6b;
	case 19312ULL: goto x86_l_4b70;
	case 19317ULL: goto x86_l_4b75;
	case 19324ULL: goto x86_l_4b7c;
	case 19329ULL: goto x86_l_4b81;
	case 19331ULL: goto x86_l_4b83;
	case 19333ULL: goto x86_l_4b85;
	case 19338ULL: goto x86_l_4b8a;
	case 19348ULL: goto x86_l_4b94;
	case 19353ULL: goto x86_l_4b99;
	case 19363ULL: goto x86_l_4ba3;
	case 19368ULL: goto x86_l_4ba8;
	case 19373ULL: goto x86_l_4bad;
	case 19378ULL: goto x86_l_4bb2;
	case 19383ULL: goto x86_l_4bb7;
	case 19389ULL: goto x86_l_4bbd;
	case 19392ULL: goto x86_l_4bc0;
	case 19397ULL: goto x86_l_4bc5;
	case 19402ULL: goto x86_l_4bca;
	case 19404ULL: goto x86_l_4bcc;
	case 19406ULL: goto x86_l_4bce;
	case 19409ULL: goto x86_l_4bd1;
	case 19412ULL: goto x86_l_4bd4;
	case 19415ULL: goto x86_l_4bd7;
	case 19421ULL: goto x86_l_4bdd;
	case 19429ULL: goto x86_l_4be5;
	case 19432ULL: goto x86_l_4be8;
	case 19434ULL: goto x86_l_4bea;
	case 19442ULL: goto x86_l_4bf2;
	case 19445ULL: goto x86_l_4bf5;
	case 19447ULL: goto x86_l_4bf7;
	case 19452ULL: goto x86_l_4bfc;
	case 19455ULL: goto x86_l_4bff;
	case 19460ULL: goto x86_l_4c04;
	case 19464ULL: goto x86_l_4c08;
	case 19468ULL: goto x86_l_4c0c;
	case 19471ULL: goto x86_l_4c0f;
	case 19474ULL: goto x86_l_4c12;
	case 19476ULL: goto x86_l_4c14;
	case 19480ULL: goto x86_l_4c18;
	case 19482ULL: goto x86_l_4c1a;
	case 19485ULL: goto x86_l_4c1d;
	case 19488ULL: goto x86_l_4c20;
	case 19490ULL: goto x86_l_4c22;
	case 19493ULL: goto x86_l_4c25;
	case 19496ULL: goto x86_l_4c28;
	default: return 0xffffffffffffffffULL;
	}
x86_l_43fe:
	/* 0x43fe: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4405:
	/* 0x4405: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4408:
	/* 0x4408: jne    4b25 <kprobe_unwind_native+0x4b25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4b25;
	}
x86_l_440e:
	/* 0x440e: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4413:
	/* 0x4413: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_4416:
	/* 0x4416: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_4418:
	/* 0x4418: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_441b:
	/* 0x441b: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_441d:
	/* 0x441d: cmovns ecx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBP, X86_WIDTH_32, X86_CC_NS);
x86_l_4420:
	/* 0x4420: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_4422:
	/* 0x4422: and    edx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_4425:
	/* 0x4425: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4428:
	/* 0x4428: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_442b:
	/* 0x442b: jg     4559 <kprobe_unwind_native+0x4559> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4559;
	}
x86_l_4431:
	/* 0x4431: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4434:
	/* 0x4434: je     46c7 <kprobe_unwind_native+0x46c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46c7;
	}
x86_l_443a:
	/* 0x443a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_443d:
	/* 0x443d: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_4440:
	/* 0x4440: je     46c4 <kprobe_unwind_native+0x46c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46c4;
	}
x86_l_4446:
	/* 0x4446: jmp    4bff <kprobe_unwind_native+0x4bff> */
	goto x86_l_4bff;
x86_l_444b:
	/* 0x444b: and    eax,0xffff7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294934527ULL);
x86_l_4450:
	/* 0x4450: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_4456:
	/* 0x4456: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4459:
	/* 0x4459: jg     44e7 <kprobe_unwind_native+0x44e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_44e7;
	}
x86_l_445f:
	/* 0x445f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4462:
	/* 0x4462: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4467:
	/* 0x4467: mov    rcx,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_446f:
	/* 0x446f: je     6474 <kprobe_unwind_native+0x6474> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25716ULL;
	}
x86_l_4475:
	/* 0x4475: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4478:
	/* 0x4478: jne    5f4c <kprobe_unwind_native+0x5f4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24396ULL;
	}
x86_l_447e:
	/* 0x447e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4481:
	/* 0x4481: mov    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4484:
	/* 0x4484: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4486:
	/* 0x4486: and    ecx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_4489:
	/* 0x4489: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_448b:
	/* 0x448b: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_448e:
	/* 0x448e: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_4491:
	/* 0x4491: lea    r13,[rax+rdx*8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_4495:
	/* 0x4495: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4499:
	/* 0x4499: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_44a0:
	/* 0x44a0: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44a3:
	/* 0x44a3: je     4e14 <kprobe_unwind_native+0x4e14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19988ULL;
	}
x86_l_44a9:
	/* 0x44a9: movabs rax,0xa786c2578303d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541309ULL);
x86_l_44b3:
	/* 0x44b3: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_44b8:
	/* 0x44b8: movabs rax,0x616663202c544c50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018406059137322064ULL);
x86_l_44c2:
	/* 0x44c2: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44c7:
	/* 0x44c7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44cc:
	/* 0x44cc: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_44d1:
	/* 0x44d1: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_44d6:
	/* 0x44d6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_44db:
	/* 0x44db: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_44de:
	/* 0x44de: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_44e0:
	/* 0x44e0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_44e2:
	/* 0x44e2: jmp    4e14 <kprobe_unwind_native+0x4e14> */
	return 19988ULL;
x86_l_44e7:
	/* 0x44e7: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_44ea:
	/* 0x44ea: je     45be <kprobe_unwind_native+0x45be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45be;
	}
x86_l_44f0:
	/* 0x44f0: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_44f3:
	/* 0x44f3: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_44f8:
	/* 0x44f8: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_44fd:
	/* 0x44fd: jne    5f4c <kprobe_unwind_native+0x5f4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24396ULL;
	}
x86_l_4503:
	/* 0x4503: mov    rax,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4506:
	/* 0x4506: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_450b:
	/* 0x450b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4510:
	/* 0x4510: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_4516:
	/* 0x4516: mov    rdx,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4519:
	/* 0x4519: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_451e:
	/* 0x451e: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4521:
	/* 0x4521: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4524:
	/* 0x4524: jne    1640 <kprobe_unwind_native+0x1640> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5696ULL;
	}
x86_l_452a:
	/* 0x452a: mov    rax,QWORD PTR [rbx+0xee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_4531:
	/* 0x4531: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4535:
	/* 0x4535: mov    QWORD PTR [rbx+0xed8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_453c:
	/* 0x453c: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4541:
	/* 0x4541: mov    QWORD PTR [rbx+0xee0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_4548:
	/* 0x4548: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_454d:
	/* 0x454d: mov    QWORD PTR [rbx+0xed0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_4554:
	/* 0x4554: jmp    4e4f <kprobe_unwind_native+0x4e4f> */
	return 20047ULL;
x86_l_4559:
	/* 0x4559: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_455c:
	/* 0x455c: je     46bf <kprobe_unwind_native+0x46bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46bf;
	}
x86_l_4562:
	/* 0x4562: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4565:
	/* 0x4565: jne    4bff <kprobe_unwind_native+0x4bff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4bff;
	}
x86_l_456b:
	/* 0x456b: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_456d:
	/* 0x456d: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_456f:
	/* 0x456f: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_4572:
	/* 0x4572: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_4574:
	/* 0x4574: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4579:
	/* 0x4579: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4580:
	/* 0x4580: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4583:
	/* 0x4583: jne    4b8a <kprobe_unwind_native+0x4b8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4b8a;
	}
x86_l_4589:
	/* 0x4589: and    ebp,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_458c:
	/* 0x458c: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_458f:
	/* 0x458f: cmp    ebp,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_4592:
	/* 0x4592: jg     4bdd <kprobe_unwind_native+0x4bdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4bdd;
	}
x86_l_4598:
	/* 0x4598: mov    rax,QWORD PTR [rsp+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_45a0:
	/* 0x45a0: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_45a2:
	/* 0x45a2: je     4bf7 <kprobe_unwind_native+0x4bf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bf7;
	}
x86_l_45a8:
	/* 0x45a8: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_45ab:
	/* 0x45ab: jne    4bff <kprobe_unwind_native+0x4bff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4bff;
	}
x86_l_45b1:
	/* 0x45b1: mov    rax,QWORD PTR [rsp+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_45b9:
	/* 0x45b9: jmp    4bf7 <kprobe_unwind_native+0x4bf7> */
	goto x86_l_4bf7;
x86_l_45be:
	/* 0x45be: mov    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45c1:
	/* 0x45c1: add    rax,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_45c5:
	/* 0x45c5: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_45cd:
	/* 0x45cd: mov    ecx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 144ULL);
x86_l_45d2:
	/* 0x45d2: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_45d8:
	/* 0x45d8: mov    rdx,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45db:
	/* 0x45db: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_45df:
	/* 0x45df: mov    esi,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 144ULL);
x86_l_45e4:
	/* 0x45e4: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_45e7:
	/* 0x45e7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_45ea:
	/* 0x45ea: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_45ef:
	/* 0x45ef: jne    1640 <kprobe_unwind_native+0x1640> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5696ULL;
	}
x86_l_45f5:
	/* 0x45f5: mov    rax,QWORD PTR [rsp+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_45fd:
	/* 0x45fd: mov    QWORD PTR [rbx+0xee8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3816ULL);
x86_l_4604:
	/* 0x4604: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_460c:
	/* 0x460c: mov    QWORD PTR [rbx+0xef0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3824ULL);
x86_l_4613:
	/* 0x4613: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_461b:
	/* 0x461b: mov    QWORD PTR [rbx+0xef8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3832ULL);
x86_l_4622:
	/* 0x4622: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_462a:
	/* 0x462a: mov    QWORD PTR [rbx+0xf00],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3840ULL);
x86_l_4631:
	/* 0x4631: mov    rax,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_4639:
	/* 0x4639: mov    QWORD PTR [rbx+0xf08],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3848ULL);
x86_l_4640:
	/* 0x4640: mov    rax,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_4648:
	/* 0x4648: mov    QWORD PTR [rbx+0xee0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_464f:
	/* 0x464f: mov    rax,QWORD PTR [rsp+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_4657:
	/* 0x4657: mov    QWORD PTR [rbx+0xed8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_465e:
	/* 0x465e: mov    rax,QWORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_4666:
	/* 0x4666: mov    QWORD PTR [rbx+0xed0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_466d:
	/* 0x466d: mov    BYTE PTR [rbx+0xf30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16698832846848ULL);
x86_l_4674:
	/* 0x4674: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_467b:
	/* 0x467b: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_467e:
	/* 0x467e: je     4e56 <kprobe_unwind_native+0x4e56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20054ULL;
	}
x86_l_4684:
	/* 0x4684: movabs rax,0xa656d61726620 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926270227834400ULL);
x86_l_468e:
	/* 0x468e: mov    QWORD PTR [rsp+0x16],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_4693:
	/* 0x4693: movabs rax,0x66206c616e676973 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7359000956843288947ULL);
x86_l_469d:
	/* 0x469d: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46a2:
	/* 0x46a2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46a7:
	/* 0x46a7: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_46ac:
	/* 0x46ac: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_46b1:
	/* 0x46b1: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_46b6:
	/* 0x46b6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_46b8:
	/* 0x46b8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_46ba:
	/* 0x46ba: jmp    4e56 <kprobe_unwind_native+0x4e56> */
	return 20054ULL;
x86_l_46bf:
	/* 0x46bf: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_46c4:
	/* 0x46c4: mov    r13,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46c7:
	/* 0x46c7: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_46ca:
	/* 0x46ca: movsxd r13,ecx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_46cd:
	/* 0x46cd: add    r13,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_46d0:
	/* 0x46d0: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_46d2:
	/* 0x46d2: jns    4bff <kprobe_unwind_native+0x4bff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_4bff;
	}
x86_l_46d8:
	/* 0x46d8: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_46dd:
	/* 0x46dd: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_46e2:
	/* 0x46e2: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_46e7:
	/* 0x46e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46ec:
	/* 0x46ec: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_46ef:
	/* 0x46ef: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_46f1:
	/* 0x46f1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_46f4:
	/* 0x46f4: je     470e <kprobe_unwind_native+0x470e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_470e;
	}
x86_l_46f6:
	/* 0x46f6: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_46fd:
	/* 0x46fd: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4700:
	/* 0x4700: jne    5212 <kprobe_unwind_native+0x5212> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 21010ULL;
	}
x86_l_4706:
	/* 0x4706: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4709:
	/* 0x4709: jmp    4bff <kprobe_unwind_native+0x4bff> */
	goto x86_l_4bff;
x86_l_470e:
	/* 0x470e: shl    ebp,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_4711:
	/* 0x4711: and    ebp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 56ULL);
x86_l_4714:
	/* 0x4714: add    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_4719:
	/* 0x4719: mov    r13,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_471c:
	/* 0x471c: jmp    4bff <kprobe_unwind_native+0x4bff> */
	goto x86_l_4bff;
x86_l_4721:
	/* 0x4721: mov    edx,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_4727:
	/* 0x4727: movabs rax,0x3d3d206425206576 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4412718824384652662ULL);
x86_l_4731:
	/* 0x4731: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_4739:
	/* 0x4739: movabs rax,0x6974616e5f646e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598805597955583593ULL);
x86_l_4743:
	/* 0x4743: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_474b:
	/* 0x474b: movabs rax,0x776e75203d3d3d3d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8605944719278423357ULL);
x86_l_4755:
	/* 0x4755: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_475d:
	/* 0x475d: mov    DWORD PTR [rsp+0xb8],0xa3d3d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 790274653501ULL);
x86_l_4768:
	/* 0x4768: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4770:
	/* 0x4770: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_4775:
	/* 0x4775: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_477a:
	/* 0x477a: mov    esi,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 28ULL);
x86_l_477f:
	/* 0x477f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4781:
	/* 0x4781: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4783:
	/* 0x4783: jmp    39df <kprobe_unwind_native+0x39df> */
	return 14815ULL;
x86_l_4788:
	/* 0x4788: movabs rax,0xa786c253a786c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 754471844735118373ULL);
x86_l_4792:
	/* 0x4792: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4797:
	/* 0x4797: movabs rax,0x20726f662061746c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338053640979313772ULL);
x86_l_47a1:
	/* 0x47a1: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_47a6:
	/* 0x47a6: movabs rax,0x6564206b63617473 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7306000141102707827ULL);
x86_l_47b0:
	/* 0x47b0: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_47b5:
	/* 0x47b5: movabs rax,0x207075206b6f6f4c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337496988707155788ULL);
x86_l_47bf:
	/* 0x47bf: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47c4:
	/* 0x47c4: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_47c9:
	/* 0x47c9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47ce:
	/* 0x47ce: mov    eax,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_47d3:
	/* 0x47d3: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_47d9:
	/* 0x47d9: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_47e0:
	/* 0x47e0: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_47e7:
	/* 0x47e7: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_47ec:
	/* 0x47ec: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_47ee:
	/* 0x47ee: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_47f1:
	/* 0x47f1: jmp    3b71 <kprobe_unwind_native+0x3b71> */
	return 15217ULL;
x86_l_47f6:
	/* 0x47f6: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_4800:
	/* 0x4800: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_4808:
	/* 0x4808: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_4812:
	/* 0x4812: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_481a:
	/* 0x481a: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_4824:
	/* 0x4824: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_482c:
	/* 0x482c: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_4836:
	/* 0x4836: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_483e:
	/* 0x483e: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_4848:
	/* 0x4848: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4850:
	/* 0x4850: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_485a:
	/* 0x485a: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4862:
	/* 0x4862: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_486a:
	/* 0x486a: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_486f:
	/* 0x486f: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4874:
	/* 0x4874: mov    edx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4878:
	/* 0x4878: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_487d:
	/* 0x487d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_487f:
	/* 0x487f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4881:
	/* 0x4881: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4888:
	/* 0x4888: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_488b:
	/* 0x488b: je     3abf <kprobe_unwind_native+0x3abf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15039ULL;
	}
x86_l_4891:
	/* 0x4891: jmp    3a16 <kprobe_unwind_native+0x3a16> */
	return 14870ULL;
x86_l_4896:
	/* 0x4896: movabs rax,0xa296425204449 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2860259863446601ULL);
x86_l_48a0:
	/* 0x48a0: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_48a5:
	/* 0x48a5: movabs rax,0x70616d2820756c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8097873624099548197ULL);
x86_l_48af:
	/* 0x48af: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_48b4:
	/* 0x48b4: movabs rax,0x206f7420756c2520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414386373920ULL);
x86_l_48be:
	/* 0x48be: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_48c3:
	/* 0x48c3: movabs rax,0x6d6f726620656220 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7885647255504773664ULL);
x86_l_48cd:
	/* 0x48cd: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_48d2:
	/* 0x48d2: movabs rax,0x646c756f68732073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7236287822631739507ULL);
x86_l_48dc:
	/* 0x48dc: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_48e1:
	/* 0x48e1: movabs rax,0x6c61767265746e49 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7809653462537629257ULL);
x86_l_48eb:
	/* 0x48eb: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48f0:
	/* 0x48f0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_48f5:
	/* 0x48f5: mov    eax,0x30 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 48ULL);
x86_l_48fa:
	/* 0x48fa: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_4900:
	/* 0x4900: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_4903:
	/* 0x4903: movzx  r8d,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4908:
	/* 0x4908: mov    esi,0x30 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 48ULL);
x86_l_490d:
	/* 0x490d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4910:
	/* 0x4910: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4912:
	/* 0x4912: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_4915:
	/* 0x4915: jmp    3d55 <kprobe_unwind_native+0x3d55> */
	return 15701ULL;
x86_l_491a:
	/* 0x491a: movabs rax,0xa6425206f666e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860387845742ULL);
x86_l_4924:
	/* 0x4924: mov    QWORD PTR [rsp+0x35],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_4929:
	/* 0x4929: movabs rax,0x6f666e49646e6977 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8027224647331113335ULL);
x86_l_4933:
	/* 0x4933: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4938:
	/* 0x4938: movabs rax,0x6e75202c78257830 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7959303291813591088ULL);
x86_l_4942:
	/* 0x4942: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4947:
	/* 0x4947: movabs rax,0x20776f4c72646461 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2339460905569641569ULL);
x86_l_4951:
	/* 0x4951: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4956:
	/* 0x4956: movabs rax,0x202c642520786564 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2318338018810291556ULL);
x86_l_4960:
	/* 0x4960: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4965:
	/* 0x4965: movabs rax,0x6e692061746c6564 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7955925819663869284ULL);
x86_l_496f:
	/* 0x496f: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4974:
	/* 0x4974: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4979:
	/* 0x4979: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_497e:
	/* 0x497e: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_4984:
	/* 0x4984: mov    edx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_498b:
	/* 0x498b: movzx  ecx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_498f:
	/* 0x498f: movzx  r8d,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_4994:
	/* 0x4994: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_4999:
	/* 0x4999: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_499b:
	/* 0x499b: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_499e:
	/* 0x499e: jmp    426b <kprobe_unwind_native+0x426b> */
	return 17003ULL;
x86_l_49a3:
	/* 0x49a3: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_49ad:
	/* 0x49ad: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_49b5:
	/* 0x49b5: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_49bf:
	/* 0x49bf: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_49c7:
	/* 0x49c7: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_49d1:
	/* 0x49d1: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_49d9:
	/* 0x49d9: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_49e3:
	/* 0x49e3: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_49eb:
	/* 0x49eb: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_49f5:
	/* 0x49f5: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_49fd:
	/* 0x49fd: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_4a07:
	/* 0x4a07: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4a0f:
	/* 0x4a0f: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4a17:
	/* 0x4a17: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_4a1c:
	/* 0x4a1c: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4a21:
	/* 0x4a21: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4a25:
	/* 0x4a25: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_4a2a:
	/* 0x4a2a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4a2c:
	/* 0x4a2c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4a2e:
	/* 0x4a2e: jmp    39c0 <kprobe_unwind_native+0x39c0> */
	return 14784ULL;
x86_l_4a33:
	/* 0x4a33: movabs rax,0xa78323023252061 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 754408119914012769ULL);
x86_l_4a3d:
	/* 0x4a3d: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4a42:
	/* 0x4a42: movabs rax,0x746c656420646567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8389191686598976871ULL);
x86_l_4a4c:
	/* 0x4a4c: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4a51:
	/* 0x4a51: movabs rax,0x72656d202c642520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243114677922702624ULL);
x86_l_4a5b:
	/* 0x4a5b: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a60:
	/* 0x4a60: movabs rax,0x6666694472646441 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7378700782191010881ULL);
x86_l_4a6a:
	/* 0x4a6a: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a6f:
	/* 0x4a6f: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_4a74:
	/* 0x4a74: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a79:
	/* 0x4a79: mov    eax,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_4a7e:
	/* 0x4a7e: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_4a84:
	/* 0x4a84: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4a89:
	/* 0x4a89: movzx  ecx,BYTE PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_4a8f:
	/* 0x4a8f: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_4a94:
	/* 0x4a94: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_4a97:
	/* 0x4a97: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4a99:
	/* 0x4a99: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4a9c:
	/* 0x4a9c: movzx  eax,BYTE PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_4aa2:
	/* 0x4aa2: jmp    43e2 <kprobe_unwind_native+0x43e2> */
	return 17378ULL;
x86_l_4aa7:
	/* 0x4aa7: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_4ab1:
	/* 0x4ab1: mov    QWORD PTR [rsp+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_4ab6:
	/* 0x4ab6: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_4ac0:
	/* 0x4ac0: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4ac5:
	/* 0x4ac5: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_4acf:
	/* 0x4acf: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4ad4:
	/* 0x4ad4: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_4ade:
	/* 0x4ade: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ae3:
	/* 0x4ae3: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_4aed:
	/* 0x4aed: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4af2:
	/* 0x4af2: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_4afc:
	/* 0x4afc: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b01:
	/* 0x4b01: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b06:
	/* 0x4b06: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_4b0b:
	/* 0x4b0b: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4b10:
	/* 0x4b10: mov    edx,DWORD PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_4b17:
	/* 0x4b17: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_4b1c:
	/* 0x4b1c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4b1e:
	/* 0x4b1e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4b20:
	/* 0x4b20: jmp    438e <kprobe_unwind_native+0x438e> */
	return 17294ULL;
x86_l_4b25:
	/* 0x4b25: movabs rax,0xa64253d61746c65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 748764383608597605ULL);
x86_l_4b2f:
	/* 0x4b2f: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4b34:
	/* 0x4b34: movabs rax,0x44616663203a6863 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4927332043248527459ULL);
x86_l_4b3e:
	/* 0x4b3e: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4b43:
	/* 0x4b43: movabs rax,0x74616d2061746c65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8386103966981975141ULL);
x86_l_4b4d:
	/* 0x4b4d: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b52:
	/* 0x4b52: movabs rax,0x642064656772654d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7214876989737559373ULL);
x86_l_4b5c:
	/* 0x4b5c: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b61:
	/* 0x4b61: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_4b66:
	/* 0x4b66: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b6b:
	/* 0x4b6b: mov    eax,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_4b70:
	/* 0x4b70: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4b75:
	/* 0x4b75: mov    edx,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_4b7c:
	/* 0x4b7c: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_4b81:
	/* 0x4b81: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4b83:
	/* 0x4b83: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4b85:
	/* 0x4b85: jmp    440e <kprobe_unwind_native+0x440e> */
	goto x86_l_440e;
x86_l_4b8a:
	/* 0x4b8a: movabs rax,0xa756c252b642572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 753627419551999346ULL);
x86_l_4b94:
	/* 0x4b94: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b99:
	/* 0x4b99: movabs rax,0x203a646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2322278983241526901ULL);
x86_l_4ba3:
	/* 0x4ba3: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ba8:
	/* 0x4ba8: mov    BYTE PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4bad:
	/* 0x4bad: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4bb2:
	/* 0x4bb2: mov    eax,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_4bb7:
	/* 0x4bb7: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_4bbd:
	/* 0x4bbd: and    ebp,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_4bc0:
	/* 0x4bc0: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4bc5:
	/* 0x4bc5: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_4bca:
	/* 0x4bca: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_4bcc:
	/* 0x4bcc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4bce:
	/* 0x4bce: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4bd1:
	/* 0x4bd1: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4bd4:
	/* 0x4bd4: cmp    ebp,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_4bd7:
	/* 0x4bd7: jle    4598 <kprobe_unwind_native+0x4598> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4598;
	}
x86_l_4bdd:
	/* 0x4bdd: mov    rax,QWORD PTR [rsp+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_4be5:
	/* 0x4be5: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_4be8:
	/* 0x4be8: je     4bf7 <kprobe_unwind_native+0x4bf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bf7;
	}
x86_l_4bea:
	/* 0x4bea: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4bf2:
	/* 0x4bf2: cmp    ebp,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 15ULL);
x86_l_4bf5:
	/* 0x4bf5: jne    4bff <kprobe_unwind_native+0x4bff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4bff;
	}
x86_l_4bf7:
	/* 0x4bf7: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4bfc:
	/* 0x4bfc: add    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4bff:
	/* 0x4bff: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4c04:
	/* 0x4c04: movzx  eax,BYTE PTR [rcx+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_4c08:
	/* 0x4c08: mov    r12d,DWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c0c:
	/* 0x4c0c: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_4c0f:
	/* 0x4c0f: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_4c12:
	/* 0x4c12: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_4c14:
	/* 0x4c14: cmovns ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_NS);
x86_l_4c18:
	/* 0x4c18: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_4c1a:
	/* 0x4c1a: and    edx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_4c1d:
	/* 0x4c1d: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_4c20:
	/* 0x4c20: jg     4c37 <kprobe_unwind_native+0x4c37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 19511ULL;
	}
x86_l_4c22:
	/* 0x4c22: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_4c25:
	/* 0x4c25: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_4c28:
	/* 0x4c28: je     4ca2 <kprobe_unwind_native+0x4ca2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19618ULL;
	}
	return 19498ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 19498ULL: goto x86_l_4c2a;
	case 19501ULL: goto x86_l_4c2d;
	case 19504ULL: goto x86_l_4c30;
	case 19506ULL: goto x86_l_4c32;
	case 19511ULL: goto x86_l_4c37;
	case 19514ULL: goto x86_l_4c3a;
	case 19516ULL: goto x86_l_4c3c;
	case 19519ULL: goto x86_l_4c3f;
	case 19525ULL: goto x86_l_4c45;
	case 19528ULL: goto x86_l_4c48;
	case 19530ULL: goto x86_l_4c4a;
	case 19533ULL: goto x86_l_4c4d;
	case 19535ULL: goto x86_l_4c4f;
	case 19540ULL: goto x86_l_4c54;
	case 19547ULL: goto x86_l_4c5b;
	case 19550ULL: goto x86_l_4c5e;
	case 19556ULL: goto x86_l_4c64;
	case 19560ULL: goto x86_l_4c68;
	case 19564ULL: goto x86_l_4c6c;
	case 19570ULL: goto x86_l_4c72;
	case 19578ULL: goto x86_l_4c7a;
	case 19581ULL: goto x86_l_4c7d;
	case 19587ULL: goto x86_l_4c83;
	case 19591ULL: goto x86_l_4c87;
	case 19597ULL: goto x86_l_4c8d;
	case 19605ULL: goto x86_l_4c95;
	case 19610ULL: goto x86_l_4c9a;
	case 19615ULL: goto x86_l_4c9f;
	case 19618ULL: goto x86_l_4ca2;
	case 19621ULL: goto x86_l_4ca5;
	case 19624ULL: goto x86_l_4ca8;
	case 19626ULL: goto x86_l_4caa;
	case 19632ULL: goto x86_l_4cb0;
	case 19637ULL: goto x86_l_4cb5;
	case 19642ULL: goto x86_l_4cba;
	case 19647ULL: goto x86_l_4cbf;
	case 19652ULL: goto x86_l_4cc4;
	case 19655ULL: goto x86_l_4cc7;
	case 19657ULL: goto x86_l_4cc9;
	case 19660ULL: goto x86_l_4ccc;
	case 19666ULL: goto x86_l_4cd2;
	case 19673ULL: goto x86_l_4cd9;
	case 19676ULL: goto x86_l_4cdc;
	case 19682ULL: goto x86_l_4ce2;
	case 19692ULL: goto x86_l_4cec;
	case 19697ULL: goto x86_l_4cf1;
	case 19707ULL: goto x86_l_4cfb;
	case 19712ULL: goto x86_l_4d00;
	case 19722ULL: goto x86_l_4d0a;
	case 19727ULL: goto x86_l_4d0f;
	case 19737ULL: goto x86_l_4d19;
	case 19742ULL: goto x86_l_4d1e;
	case 19752ULL: goto x86_l_4d28;
	case 19757ULL: goto x86_l_4d2d;
	case 19765ULL: goto x86_l_4d35;
	case 19770ULL: goto x86_l_4d3a;
	case 19775ULL: goto x86_l_4d3f;
	case 19780ULL: goto x86_l_4d44;
	case 19785ULL: goto x86_l_4d49;
	case 19788ULL: goto x86_l_4d4c;
	case 19790ULL: goto x86_l_4d4e;
	case 19792ULL: goto x86_l_4d50;
	case 19797ULL: goto x86_l_4d55;
	case 19801ULL: goto x86_l_4d59;
	case 19805ULL: goto x86_l_4d5d;
	case 19810ULL: goto x86_l_4d62;
	case 19813ULL: goto x86_l_4d65;
	case 19815ULL: goto x86_l_4d67;
	case 19825ULL: goto x86_l_4d71;
	case 19830ULL: goto x86_l_4d76;
	case 19840ULL: goto x86_l_4d80;
	case 19845ULL: goto x86_l_4d85;
	case 19850ULL: goto x86_l_4d8a;
	case 19855ULL: goto x86_l_4d8f;
	case 19860ULL: goto x86_l_4d94;
	case 19866ULL: goto x86_l_4d9a;
	case 19870ULL: goto x86_l_4d9e;
	case 19875ULL: goto x86_l_4da3;
	case 19880ULL: goto x86_l_4da8;
	case 19883ULL: goto x86_l_4dab;
	case 19885ULL: goto x86_l_4dad;
	case 19888ULL: goto x86_l_4db0;
	case 19892ULL: goto x86_l_4db4;
	case 19898ULL: goto x86_l_4dba;
	case 19906ULL: goto x86_l_4dc2;
	case 19910ULL: goto x86_l_4dc6;
	case 19912ULL: goto x86_l_4dc8;
	case 19920ULL: goto x86_l_4dd0;
	case 19924ULL: goto x86_l_4dd4;
	case 19926ULL: goto x86_l_4dd6;
	case 19931ULL: goto x86_l_4ddb;
	case 19934ULL: goto x86_l_4dde;
	case 19937ULL: goto x86_l_4de1;
	case 19939ULL: goto x86_l_4de3;
	case 19944ULL: goto x86_l_4de8;
	case 19949ULL: goto x86_l_4ded;
	case 19954ULL: goto x86_l_4df2;
	case 19959ULL: goto x86_l_4df7;
	case 19962ULL: goto x86_l_4dfa;
	case 19964ULL: goto x86_l_4dfc;
	case 19966ULL: goto x86_l_4dfe;
	case 19971ULL: goto x86_l_4e03;
	case 19974ULL: goto x86_l_4e06;
	case 19976ULL: goto x86_l_4e08;
	case 19981ULL: goto x86_l_4e0d;
	case 19988ULL: goto x86_l_4e14;
	case 19991ULL: goto x86_l_4e17;
	case 19996ULL: goto x86_l_4e1c;
	case 20002ULL: goto x86_l_4e22;
	case 20006ULL: goto x86_l_4e26;
	case 20011ULL: goto x86_l_4e2b;
	case 20016ULL: goto x86_l_4e30;
	case 20024ULL: goto x86_l_4e38;
	case 20029ULL: goto x86_l_4e3d;
	case 20031ULL: goto x86_l_4e3f;
	case 20034ULL: goto x86_l_4e42;
	case 20040ULL: goto x86_l_4e48;
	case 20047ULL: goto x86_l_4e4f;
	case 20054ULL: goto x86_l_4e56;
	case 20062ULL: goto x86_l_4e5e;
	case 20069ULL: goto x86_l_4e65;
	case 20074ULL: goto x86_l_4e6a;
	case 20079ULL: goto x86_l_4e6f;
	case 20081ULL: goto x86_l_4e71;
	case 20084ULL: goto x86_l_4e74;
	case 20090ULL: goto x86_l_4e7a;
	case 20093ULL: goto x86_l_4e7d;
	case 20095ULL: goto x86_l_4e7f;
	case 20102ULL: goto x86_l_4e86;
	case 20105ULL: goto x86_l_4e89;
	case 20111ULL: goto x86_l_4e8f;
	case 20121ULL: goto x86_l_4e99;
	case 20129ULL: goto x86_l_4ea1;
	case 20139ULL: goto x86_l_4eab;
	case 20147ULL: goto x86_l_4eb3;
	case 20157ULL: goto x86_l_4ebd;
	case 20165ULL: goto x86_l_4ec5;
	case 20175ULL: goto x86_l_4ecf;
	case 20183ULL: goto x86_l_4ed7;
	case 20191ULL: goto x86_l_4edf;
	case 20196ULL: goto x86_l_4ee4;
	case 20202ULL: goto x86_l_4eea;
	case 20210ULL: goto x86_l_4ef2;
	case 20213ULL: goto x86_l_4ef5;
	case 20216ULL: goto x86_l_4ef8;
	case 20221ULL: goto x86_l_4efd;
	case 20224ULL: goto x86_l_4f00;
	case 20229ULL: goto x86_l_4f05;
	case 20231ULL: goto x86_l_4f07;
	case 20234ULL: goto x86_l_4f0a;
	case 20241ULL: goto x86_l_4f11;
	case 20243ULL: goto x86_l_4f13;
	case 20245ULL: goto x86_l_4f15;
	case 20252ULL: goto x86_l_4f1c;
	case 20255ULL: goto x86_l_4f1f;
	case 20261ULL: goto x86_l_4f25;
	case 20263ULL: goto x86_l_4f27;
	case 20271ULL: goto x86_l_4f2f;
	case 20274ULL: goto x86_l_4f32;
	case 20277ULL: goto x86_l_4f35;
	case 20283ULL: goto x86_l_4f3b;
	case 20285ULL: goto x86_l_4f3d;
	case 20291ULL: goto x86_l_4f43;
	case 20301ULL: goto x86_l_4f4d;
	case 20304ULL: goto x86_l_4f50;
	case 20310ULL: goto x86_l_4f56;
	case 20317ULL: goto x86_l_4f5d;
	case 20323ULL: goto x86_l_4f63;
	case 20325ULL: goto x86_l_4f65;
	case 20333ULL: goto x86_l_4f6d;
	case 20339ULL: goto x86_l_4f73;
	case 20346ULL: goto x86_l_4f7a;
	case 20353ULL: goto x86_l_4f81;
	case 20358ULL: goto x86_l_4f86;
	case 20363ULL: goto x86_l_4f8b;
	case 20365ULL: goto x86_l_4f8d;
	case 20368ULL: goto x86_l_4f90;
	case 20374ULL: goto x86_l_4f96;
	case 20378ULL: goto x86_l_4f9a;
	case 20381ULL: goto x86_l_4f9d;
	case 20391ULL: goto x86_l_4fa7;
	case 20394ULL: goto x86_l_4faa;
	case 20401ULL: goto x86_l_4fb1;
	case 20404ULL: goto x86_l_4fb4;
	case 20411ULL: goto x86_l_4fbb;
	case 20415ULL: goto x86_l_4fbf;
	case 20418ULL: goto x86_l_4fc2;
	case 20421ULL: goto x86_l_4fc5;
	case 20428ULL: goto x86_l_4fcc;
	case 20435ULL: goto x86_l_4fd3;
	case 20438ULL: goto x86_l_4fd6;
	case 20444ULL: goto x86_l_4fdc;
	case 20448ULL: goto x86_l_4fe0;
	case 20454ULL: goto x86_l_4fe6;
	case 20461ULL: goto x86_l_4fed;
	case 20466ULL: goto x86_l_4ff2;
	case 20473ULL: goto x86_l_4ff9;
	case 20480ULL: goto x86_l_5000;
	case 20485ULL: goto x86_l_5005;
	case 20490ULL: goto x86_l_500a;
	case 20492ULL: goto x86_l_500c;
	case 20498ULL: goto x86_l_5012;
	case 20501ULL: goto x86_l_5015;
	case 20507ULL: goto x86_l_501b;
	case 20510ULL: goto x86_l_501e;
	case 20513ULL: goto x86_l_5021;
	case 20515ULL: goto x86_l_5023;
	case 20519ULL: goto x86_l_5027;
	case 20521ULL: goto x86_l_5029;
	case 20525ULL: goto x86_l_502d;
	case 20531ULL: goto x86_l_5033;
	case 20535ULL: goto x86_l_5037;
	case 20541ULL: goto x86_l_503d;
	case 20548ULL: goto x86_l_5044;
	case 20551ULL: goto x86_l_5047;
	case 20557ULL: goto x86_l_504d;
	case 20563ULL: goto x86_l_5053;
	case 20567ULL: goto x86_l_5057;
	case 20570ULL: goto x86_l_505a;
	case 20576ULL: goto x86_l_5060;
	case 20583ULL: goto x86_l_5067;
	case 20586ULL: goto x86_l_506a;
	case 20592ULL: goto x86_l_5070;
	case 20602ULL: goto x86_l_507a;
	case 20610ULL: goto x86_l_5082;
	case 20620ULL: goto x86_l_508c;
	case 20628ULL: goto x86_l_5094;
	case 20638ULL: goto x86_l_509e;
	case 20646ULL: goto x86_l_50a6;
	case 20657ULL: goto x86_l_50b1;
	case 20665ULL: goto x86_l_50b9;
	case 20670ULL: goto x86_l_50be;
	case 20675ULL: goto x86_l_50c3;
	case 20680ULL: goto x86_l_50c8;
	case 20682ULL: goto x86_l_50ca;
	case 20684ULL: goto x86_l_50cc;
	case 20689ULL: goto x86_l_50d1;
	case 20699ULL: goto x86_l_50db;
	case 20707ULL: goto x86_l_50e3;
	case 20717ULL: goto x86_l_50ed;
	case 20725ULL: goto x86_l_50f5;
	case 20735ULL: goto x86_l_50ff;
	case 20743ULL: goto x86_l_5107;
	case 20753ULL: goto x86_l_5111;
	case 20761ULL: goto x86_l_5119;
	case 20771ULL: goto x86_l_5123;
	case 20779ULL: goto x86_l_512b;
	case 20789ULL: goto x86_l_5135;
	case 20797ULL: goto x86_l_513d;
	case 20805ULL: goto x86_l_5145;
	case 20813ULL: goto x86_l_514d;
	case 20818ULL: goto x86_l_5152;
	case 20823ULL: goto x86_l_5157;
	case 20829ULL: goto x86_l_515d;
	case 20834ULL: goto x86_l_5162;
	case 20836ULL: goto x86_l_5164;
	case 20838ULL: goto x86_l_5166;
	case 20845ULL: goto x86_l_516d;
	case 20855ULL: goto x86_l_5177;
	case 20858ULL: goto x86_l_517a;
	case 20864ULL: goto x86_l_5180;
	case 20869ULL: goto x86_l_5185;
	case 20879ULL: goto x86_l_518f;
	case 20884ULL: goto x86_l_5194;
	case 20894ULL: goto x86_l_519e;
	case 20899ULL: goto x86_l_51a3;
	case 20909ULL: goto x86_l_51ad;
	case 20914ULL: goto x86_l_51b2;
	case 20924ULL: goto x86_l_51bc;
	case 20929ULL: goto x86_l_51c1;
	case 20939ULL: goto x86_l_51cb;
	case 20944ULL: goto x86_l_51d0;
	case 20954ULL: goto x86_l_51da;
	case 20959ULL: goto x86_l_51df;
	case 20964ULL: goto x86_l_51e4;
	case 20969ULL: goto x86_l_51e9;
	case 20974ULL: goto x86_l_51ee;
	case 20978ULL: goto x86_l_51f2;
	case 20983ULL: goto x86_l_51f7;
	case 20985ULL: goto x86_l_51f9;
	case 20987ULL: goto x86_l_51fb;
	case 20989ULL: goto x86_l_51fd;
	case 20996ULL: goto x86_l_5204;
	case 20999ULL: goto x86_l_5207;
	case 21005ULL: goto x86_l_520d;
	case 21010ULL: goto x86_l_5212;
	case 21020ULL: goto x86_l_521c;
	case 21025ULL: goto x86_l_5221;
	case 21035ULL: goto x86_l_522b;
	case 21040ULL: goto x86_l_5230;
	case 21050ULL: goto x86_l_523a;
	case 21055ULL: goto x86_l_523f;
	case 21065ULL: goto x86_l_5249;
	case 21070ULL: goto x86_l_524e;
	case 21080ULL: goto x86_l_5258;
	case 21085ULL: goto x86_l_525d;
	case 21093ULL: goto x86_l_5265;
	case 21098ULL: goto x86_l_526a;
	case 21103ULL: goto x86_l_526f;
	case 21108ULL: goto x86_l_5274;
	case 21113ULL: goto x86_l_5279;
	case 21116ULL: goto x86_l_527c;
	case 21118ULL: goto x86_l_527e;
	case 21120ULL: goto x86_l_5280;
	case 21123ULL: goto x86_l_5283;
	case 21128ULL: goto x86_l_5288;
	case 21138ULL: goto x86_l_5292;
	case 21146ULL: goto x86_l_529a;
	case 21156ULL: goto x86_l_52a4;
	case 21164ULL: goto x86_l_52ac;
	case 21174ULL: goto x86_l_52b6;
	case 21182ULL: goto x86_l_52be;
	case 21192ULL: goto x86_l_52c8;
	case 21200ULL: goto x86_l_52d0;
	case 21210ULL: goto x86_l_52da;
	case 21218ULL: goto x86_l_52e2;
	case 21228ULL: goto x86_l_52ec;
	case 21236ULL: goto x86_l_52f4;
	case 21246ULL: goto x86_l_52fe;
	case 21254ULL: goto x86_l_5306;
	case 21259ULL: goto x86_l_530b;
	case 21265ULL: goto x86_l_5311;
	case 21272ULL: goto x86_l_5318;
	case 21277ULL: goto x86_l_531d;
	case 21280ULL: goto x86_l_5320;
	case 21283ULL: goto x86_l_5323;
	case 21285ULL: goto x86_l_5325;
	case 21288ULL: goto x86_l_5328;
	case 21295ULL: goto x86_l_532f;
	case 21298ULL: goto x86_l_5332;
	case 21304ULL: goto x86_l_5338;
	case 21314ULL: goto x86_l_5342;
	case 21322ULL: goto x86_l_534a;
	case 21332ULL: goto x86_l_5354;
	case 21340ULL: goto x86_l_535c;
	case 21350ULL: goto x86_l_5366;
	case 21358ULL: goto x86_l_536e;
	case 21368ULL: goto x86_l_5378;
	case 21376ULL: goto x86_l_5380;
	case 21386ULL: goto x86_l_538a;
	case 21394ULL: goto x86_l_5392;
	case 21402ULL: goto x86_l_539a;
	case 21410ULL: goto x86_l_53a2;
	case 21415ULL: goto x86_l_53a7;
	case 21421ULL: goto x86_l_53ad;
	case 21428ULL: goto x86_l_53b4;
	case 21435ULL: goto x86_l_53bb;
	case 21440ULL: goto x86_l_53c0;
	case 21442ULL: goto x86_l_53c2;
	case 21445ULL: goto x86_l_53c5;
	case 21450ULL: goto x86_l_53ca;
	case 21460ULL: goto x86_l_53d4;
	case 21468ULL: goto x86_l_53dc;
	case 21478ULL: goto x86_l_53e6;
	case 21486ULL: goto x86_l_53ee;
	case 21496ULL: goto x86_l_53f8;
	case 21504ULL: goto x86_l_5400;
	case 21514ULL: goto x86_l_540a;
	case 21522ULL: goto x86_l_5412;
	case 21530ULL: goto x86_l_541a;
	case 21535ULL: goto x86_l_541f;
	case 21540ULL: goto x86_l_5424;
	case 21545ULL: goto x86_l_5429;
	case 21550ULL: goto x86_l_542e;
	case 21552ULL: goto x86_l_5430;
	case 21554ULL: goto x86_l_5432;
	case 21560ULL: goto x86_l_5438;
	case 21564ULL: goto x86_l_543c;
	case 21567ULL: goto x86_l_543f;
	case 21573ULL: goto x86_l_5445;
	case 21581ULL: goto x86_l_544d;
	case 21588ULL: goto x86_l_5454;
	case 21593ULL: goto x86_l_5459;
	case 21598ULL: goto x86_l_545e;
	case 21600ULL: goto x86_l_5460;
	case 21603ULL: goto x86_l_5463;
	case 21605ULL: goto x86_l_5465;
	case 21608ULL: goto x86_l_5468;
	case 21610ULL: goto x86_l_546a;
	case 21617ULL: goto x86_l_5471;
	case 21620ULL: goto x86_l_5474;
	case 21626ULL: goto x86_l_547a;
	case 21631ULL: goto x86_l_547f;
	case 21635ULL: goto x86_l_5483;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4c2a:
	/* 0x4c2a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_4c2d:
	/* 0x4c2d: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_4c30:
	/* 0x4c30: je     4c9f <kprobe_unwind_native+0x4c9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c9f;
	}
x86_l_4c32:
	/* 0x4c32: jmp    4dfe <kprobe_unwind_native+0x4dfe> */
	goto x86_l_4dfe;
x86_l_4c37:
	/* 0x4c37: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4c3a:
	/* 0x4c3a: je     4c9a <kprobe_unwind_native+0x4c9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c9a;
	}
x86_l_4c3c:
	/* 0x4c3c: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4c3f:
	/* 0x4c3f: jne    4dfe <kprobe_unwind_native+0x4dfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4dfe;
	}
x86_l_4c45:
	/* 0x4c45: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_4c48:
	/* 0x4c48: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_4c4a:
	/* 0x4c4a: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_4c4d:
	/* 0x4c4d: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_4c4f:
	/* 0x4c4f: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4c54:
	/* 0x4c54: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4c5b:
	/* 0x4c5b: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c5e:
	/* 0x4c5e: jne    4d67 <kprobe_unwind_native+0x4d67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4d67;
	}
x86_l_4c64:
	/* 0x4c64: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_4c68:
	/* 0x4c68: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_4c6c:
	/* 0x4c6c: jg     4dba <kprobe_unwind_native+0x4dba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4dba;
	}
x86_l_4c72:
	/* 0x4c72: mov    rax,QWORD PTR [rsp+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_4c7a:
	/* 0x4c7a: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_4c7d:
	/* 0x4c7d: je     4dd6 <kprobe_unwind_native+0x4dd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4dd6;
	}
x86_l_4c83:
	/* 0x4c83: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_4c87:
	/* 0x4c87: jne    4dfe <kprobe_unwind_native+0x4dfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4dfe;
	}
x86_l_4c8d:
	/* 0x4c8d: mov    rax,QWORD PTR [rsp+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_4c95:
	/* 0x4c95: jmp    4dd6 <kprobe_unwind_native+0x4dd6> */
	goto x86_l_4dd6;
x86_l_4c9a:
	/* 0x4c9a: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4c9f:
	/* 0x4c9f: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ca2:
	/* 0x4ca2: movsxd rbp,ecx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_4ca5:
	/* 0x4ca5: add    rbp,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4ca8:
	/* 0x4ca8: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_4caa:
	/* 0x4caa: jns    4dde <kprobe_unwind_native+0x4dde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_4dde;
	}
x86_l_4cb0:
	/* 0x4cb0: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4cb5:
	/* 0x4cb5: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_4cba:
	/* 0x4cba: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_4cbf:
	/* 0x4cbf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cc4:
	/* 0x4cc4: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4cc7:
	/* 0x4cc7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4cc9:
	/* 0x4cc9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4ccc:
	/* 0x4ccc: je     4d55 <kprobe_unwind_native+0x4d55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d55;
	}
x86_l_4cd2:
	/* 0x4cd2: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4cd9:
	/* 0x4cd9: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4cdc:
	/* 0x4cdc: je     4dfe <kprobe_unwind_native+0x4dfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4dfe;
	}
x86_l_4ce2:
	/* 0x4ce2: movabs rax,0x2578302073736572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2699960892542641522ULL);
x86_l_4cec:
	/* 0x4cec: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4cf1:
	/* 0x4cf1: movabs rax,0x6464612065636e65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7234013693231722085ULL);
x86_l_4cfb:
	/* 0x4cfb: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4d00:
	/* 0x4d00: movabs rax,0x7265666572656420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243107278868538400ULL);
x86_l_4d0a:
	/* 0x4d0a: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4d0f:
	/* 0x4d0f: movabs rax,0x6f742064656c6961 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8031079651078859105ULL);
x86_l_4d19:
	/* 0x4d19: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4d1e:
	/* 0x4d1e: movabs rax,0x6620646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358992216502005365ULL);
x86_l_4d28:
	/* 0x4d28: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d2d:
	/* 0x4d2d: mov    DWORD PTR [rsp+0x38],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518854764ULL);
x86_l_4d35:
	/* 0x4d35: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d3a:
	/* 0x4d3a: mov    eax,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_4d3f:
	/* 0x4d3f: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4d44:
	/* 0x4d44: mov    esi,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_4d49:
	/* 0x4d49: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4d4c:
	/* 0x4d4c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4d4e:
	/* 0x4d4e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4d50:
	/* 0x4d50: jmp    4dfe <kprobe_unwind_native+0x4dfe> */
	goto x86_l_4dfe;
x86_l_4d55:
	/* 0x4d55: shl    r12d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_4d59:
	/* 0x4d59: and    r12d,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 56ULL);
x86_l_4d5d:
	/* 0x4d5d: add    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_4d62:
	/* 0x4d62: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_4d65:
	/* 0x4d65: jmp    4dde <kprobe_unwind_native+0x4dde> */
	goto x86_l_4dde;
x86_l_4d67:
	/* 0x4d67: movabs rax,0xa756c252b642572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 753627419551999346ULL);
x86_l_4d71:
	/* 0x4d71: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4d76:
	/* 0x4d76: movabs rax,0x203a646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2322278983241526901ULL);
x86_l_4d80:
	/* 0x4d80: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d85:
	/* 0x4d85: mov    BYTE PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4d8a:
	/* 0x4d8a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d8f:
	/* 0x4d8f: mov    eax,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_4d94:
	/* 0x4d94: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_4d9a:
	/* 0x4d9a: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_4d9e:
	/* 0x4d9e: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4da3:
	/* 0x4da3: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_4da8:
	/* 0x4da8: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_4dab:
	/* 0x4dab: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4dad:
	/* 0x4dad: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4db0:
	/* 0x4db0: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_4db4:
	/* 0x4db4: jle    4c72 <kprobe_unwind_native+0x4c72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4c72;
	}
x86_l_4dba:
	/* 0x4dba: mov    rax,QWORD PTR [rsp+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_4dc2:
	/* 0x4dc2: cmp    r12d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 11ULL);
x86_l_4dc6:
	/* 0x4dc6: je     4dd6 <kprobe_unwind_native+0x4dd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4dd6;
	}
x86_l_4dc8:
	/* 0x4dc8: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4dd0:
	/* 0x4dd0: cmp    r12d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 15ULL);
x86_l_4dd4:
	/* 0x4dd4: jne    4dfe <kprobe_unwind_native+0x4dfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4dfe;
	}
x86_l_4dd6:
	/* 0x4dd6: mov    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4ddb:
	/* 0x4ddb: add    rbp,QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_4dde:
	/* 0x4dde: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_4de1:
	/* 0x4de1: je     4dfe <kprobe_unwind_native+0x4dfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4dfe;
	}
x86_l_4de3:
	/* 0x4de3: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_4de8:
	/* 0x4de8: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_4ded:
	/* 0x4ded: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4df2:
	/* 0x4df2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4df7:
	/* 0x4df7: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4dfa:
	/* 0x4dfa: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4dfc:
	/* 0x4dfc: jmp    4e14 <kprobe_unwind_native+0x4e14> */
	goto x86_l_4e14;
x86_l_4dfe:
	/* 0x4dfe: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4e03:
	/* 0x4e03: cmp    BYTE PTR [rax],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_4e06:
	/* 0x4e06: jne    4e14 <kprobe_unwind_native+0x4e14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4e14;
	}
x86_l_4e08:
	/* 0x4e08: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4e0d:
	/* 0x4e0d: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e14:
	/* 0x4e14: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_4e17:
	/* 0x4e17: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4e1c:
	/* 0x4e1c: je     1640 <kprobe_unwind_native+0x1640> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5696ULL;
	}
x86_l_4e22:
	/* 0x4e22: lea    rdx,[r13-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_4e26:
	/* 0x4e26: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_4e2b:
	/* 0x4e2b: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_4e30:
	/* 0x4e30: mov    rdi,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_4e38:
	/* 0x4e38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e3d:
	/* 0x4e3d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4e3f:
	/* 0x4e3f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e42:
	/* 0x4e42: jne    1640 <kprobe_unwind_native+0x1640> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5696ULL;
	}
x86_l_4e48:
	/* 0x4e48: mov    QWORD PTR [rbx+0xed8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_4e4f:
	/* 0x4e4f: mov    BYTE PTR [rbx+0xf30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16698832846849ULL);
x86_l_4e56:
	/* 0x4e56: mov    DWORD PTR [rsp+0x78],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075526ULL);
x86_l_4e5e:
	/* 0x4e5e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_4e65:
	/* 0x4e65: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4e6a:
	/* 0x4e6a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e6f:
	/* 0x4e6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e71:
	/* 0x4e71: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e74:
	/* 0x4e74: je     4f15 <kprobe_unwind_native+0x4f15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f15;
	}
x86_l_4e7a:
	/* 0x4e7a: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4e7d:
	/* 0x4e7d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4e7f:
	/* 0x4e7f: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4e86:
	/* 0x4e86: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e89:
	/* 0x4e89: je     4f27 <kprobe_unwind_native+0x4f27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f27;
	}
x86_l_4e8f:
	/* 0x4e8f: movabs rax,0xa786c6c25203a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947156833280058ULL);
x86_l_4e99:
	/* 0x4e99: mov    QWORD PTR [rsp+0xb5],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 181ULL);
x86_l_4ea1:
	/* 0x4ea1: movabs rax,0x25203a706620786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675202433082226796ULL);
x86_l_4eab:
	/* 0x4eab: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_4eb3:
	/* 0x4eb3: movabs rax,0x6c25203a70732078 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7792670165601296504ULL);
x86_l_4ebd:
	/* 0x4ebd: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4ec5:
	/* 0x4ec5: movabs rax,0x6c6c25203a637020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660273929744416ULL);
x86_l_4ecf:
	/* 0x4ecf: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4ed7:
	/* 0x4ed7: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4edf:
	/* 0x4edf: mov    eax,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_4ee4:
	/* 0x4ee4: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_4eea:
	/* 0x4eea: mov    rax,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_4ef2:
	/* 0x4ef2: mov    rdx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ef5:
	/* 0x4ef5: mov    rcx,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ef8:
	/* 0x4ef8: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4efd:
	/* 0x4efd: mov    r8,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f00:
	/* 0x4f00: mov    esi,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 29ULL);
x86_l_4f05:
	/* 0x4f05: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f07:
	/* 0x4f07: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_4f0a:
	/* 0x4f0a: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4f11:
	/* 0x4f11: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f13:
	/* 0x4f13: jmp    4f27 <kprobe_unwind_native+0x4f27> */
	goto x86_l_4f27;
x86_l_4f15:
	/* 0x4f15: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4f1c:
	/* 0x4f1c: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f1f:
	/* 0x4f1f: jne    5185 <kprobe_unwind_native+0x5185> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5185;
	}
x86_l_4f25:
	/* 0x4f25: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f27:
	/* 0x4f27: mov    rcx,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_4f2f:
	/* 0x4f2f: mov    r13,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f32:
	/* 0x4f32: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_4f35:
	/* 0x4f35: je     706b <kprobe_unwind_native+0x706b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28779ULL;
	}
x86_l_4f3b:
	/* 0x4f3b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f3d:
	/* 0x4f3d: jne    50d1 <kprobe_unwind_native+0x50d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_50d1;
	}
x86_l_4f43:
	/* 0x4f43: movabs rax,0xffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72057594037927935ULL);
x86_l_4f4d:
	/* 0x4f4d: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_4f50:
	/* 0x4f50: ja     3397 <kprobe_unwind_native+0x3397> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13207ULL;
	}
x86_l_4f56:
	/* 0x4f56: cmp    r13,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4096ULL);
x86_l_4f5d:
	/* 0x4f5d: jb     34dd <kprobe_unwind_native+0x34dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13533ULL;
	}
x86_l_4f63:
	/* 0x4f63: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f65:
	/* 0x4f65: mov    DWORD PTR [rsp+0x10],0x60 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476832ULL);
x86_l_4f6d:
	/* 0x4f6d: movbe  DWORD PTR [rsp+0x14],eax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_4f73:
	/* 0x4f73: movbe  QWORD PTR [rsp+0x18],r13 */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_4f7a:
	/* 0x4f7a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_page_to_mapping_info)));
x86_l_4f81:
	/* 0x4f81: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f86:
	/* 0x4f86: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4f8b:
	/* 0x4f8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f8d:
	/* 0x4f8d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4f90:
	/* 0x4f90: je     7127 <kprobe_unwind_native+0x7127> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28967ULL;
	}
x86_l_4f96:
	/* 0x4f96: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f9a:
	/* 0x4f9a: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_4f9d:
	/* 0x4f9d: movabs rdx,0xffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 72057594037927935ULL);
x86_l_4fa7:
	/* 0x4fa7: and    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_AND);
x86_l_4faa:
	/* 0x4faa: mov    QWORD PTR [rbx+0xf20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3872ULL);
x86_l_4fb1:
	/* 0x4fb1: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fb4:
	/* 0x4fb4: mov    QWORD PTR [rbx+0xf10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_4fbb:
	/* 0x4fbb: shr    r12,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_4fbf:
	/* 0x4fbf: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_4fc2:
	/* 0x4fc2: sub    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_4fc5:
	/* 0x4fc5: mov    QWORD PTR [rbx+0xf18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_4fcc:
	/* 0x4fcc: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_4fd3:
	/* 0x4fd3: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fd6:
	/* 0x4fd6: jne    5288 <kprobe_unwind_native+0x5288> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5288;
	}
x86_l_4fdc:
	/* 0x4fdc: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_4fe0:
	/* 0x4fe0: jne    547f <kprobe_unwind_native+0x547f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_547f;
	}
x86_l_4fe6:
	/* 0x4fe6: mov    rax,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_4fed:
	/* 0x4fed: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ff2:
	/* 0x4ff2: mov    rbp,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_4ff9:
	/* 0x4ff9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&interpreter_offsets)));
x86_l_5000:
	/* 0x5000: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5005:
	/* 0x5005: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_500a:
	/* 0x500a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_500c:
	/* 0x500c: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_5012:
	/* 0x5012: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5015:
	/* 0x5015: je     547f <kprobe_unwind_native+0x547f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_547f;
	}
x86_l_501b:
	/* 0x501b: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_501e:
	/* 0x501e: cmp    QWORD PTR [rax],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5021:
	/* 0x5021: ja     5029 <kprobe_unwind_native+0x5029> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_5029;
	}
x86_l_5023:
	/* 0x5023: cmp    QWORD PTR [r13+0x8],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5027:
	/* 0x5027: jae    503d <kprobe_unwind_native+0x503d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_503d;
	}
x86_l_5029:
	/* 0x5029: cmp    QWORD PTR [r13+0x10],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_502d:
	/* 0x502d: ja     547f <kprobe_unwind_native+0x547f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_547f;
	}
x86_l_5033:
	/* 0x5033: cmp    QWORD PTR [r13+0x18],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5037:
	/* 0x5037: jb     547f <kprobe_unwind_native+0x547f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_547f;
	}
x86_l_503d:
	/* 0x503d: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5044:
	/* 0x5044: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5047:
	/* 0x5047: jne    53ca <kprobe_unwind_native+0x53ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_53ca;
	}
x86_l_504d:
	/* 0x504d: mov    eax,DWORD PTR [rbx+0x1380] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4992ULL);
x86_l_5053:
	/* 0x5053: mov    ecx,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5057:
	/* 0x5057: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_505a:
	/* 0x505a: jae    5445 <kprobe_unwind_native+0x5445> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5445;
	}
x86_l_5060:
	/* 0x5060: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5067:
	/* 0x5067: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_506a:
	/* 0x506a: je     547f <kprobe_unwind_native+0x547f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_547f;
	}
x86_l_5070:
	/* 0x5070: movabs rax,0x6e6f64207265646e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7957689157107934318ULL);
x86_l_507a:
	/* 0x507a: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_5082:
	/* 0x5082: movabs rax,0x69776e7520726574 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7599664345545598324ULL);
x86_l_508c:
	/* 0x508c: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_5094:
	/* 0x5094: movabs rax,0x6572707265746e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310028781806448233ULL);
x86_l_509e:
	/* 0x509e: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_50a6:
	/* 0x50a6: mov    DWORD PTR [rsp+0xb7],0xa656e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 785979696494ULL);
x86_l_50b1:
	/* 0x50b1: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_50b9:
	/* 0x50b9: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_50be:
	/* 0x50be: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_50c3:
	/* 0x50c3: mov    esi,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 27ULL);
x86_l_50c8:
	/* 0x50c8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_50ca:
	/* 0x50ca: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_50cc:
	/* 0x50cc: jmp    547f <kprobe_unwind_native+0x547f> */
	goto x86_l_547f;
x86_l_50d1:
	/* 0x50d1: movabs rax,0xa3d3d3d3d206425 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 737813247186461733ULL);
x86_l_50db:
	/* 0x50db: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_50e3:
	/* 0x50e3: movabs rax,0x20656d617266203a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334392247160021050ULL);
x86_l_50ed:
	/* 0x50ed: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_50f5:
	/* 0x50f5: movabs rax,0x7265646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243105118350175861ULL);
x86_l_50ff:
	/* 0x50ff: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_5107:
	/* 0x5107: movabs rax,0x20656d6172662074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334392247160021108ULL);
x86_l_5111:
	/* 0x5111: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_5119:
	/* 0x5119: movabs rax,0x78656e2065766c6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8675461342619397231ULL);
x86_l_5123:
	/* 0x5123: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_512b:
	/* 0x512b: movabs rax,0x736552203d3d3d3d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8315142585429343549ULL);
x86_l_5135:
	/* 0x5135: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_513d:
	/* 0x513d: mov    BYTE PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_5145:
	/* 0x5145: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_514d:
	/* 0x514d: mov    eax,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 49ULL);
x86_l_5152:
	/* 0x5152: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5157:
	/* 0x5157: mov    edx,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_515d:
	/* 0x515d: mov    esi,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 49ULL);
x86_l_5162:
	/* 0x5162: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5164:
	/* 0x5164: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5166:
	/* 0x5166: mov    r13,QWORD PTR [rbx+0xed0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_516d:
	/* 0x516d: movabs rax,0xffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72057594037927935ULL);
x86_l_5177:
	/* 0x5177: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_517a:
	/* 0x517a: ja     3397 <kprobe_unwind_native+0x3397> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13207ULL;
	}
x86_l_5180:
	/* 0x5180: jmp    4f56 <kprobe_unwind_native+0x4f56> */
	goto x86_l_4f56;
x86_l_5185:
	/* 0x5185: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_518f:
	/* 0x518f: mov    QWORD PTR [rsp+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_5194:
	/* 0x5194: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_519e:
	/* 0x519e: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_51a3:
	/* 0x51a3: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_51ad:
	/* 0x51ad: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_51b2:
	/* 0x51b2: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_51bc:
	/* 0x51bc: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_51c1:
	/* 0x51c1: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_51cb:
	/* 0x51cb: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_51d0:
	/* 0x51d0: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_51da:
	/* 0x51da: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51df:
	/* 0x51df: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51e4:
	/* 0x51e4: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_51e9:
	/* 0x51e9: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_51ee:
	/* 0x51ee: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_51f2:
	/* 0x51f2: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_51f7:
	/* 0x51f7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_51f9:
	/* 0x51f9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_51fb:
	/* 0x51fb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_51fd:
	/* 0x51fd: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5204:
	/* 0x5204: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5207:
	/* 0x5207: je     4f27 <kprobe_unwind_native+0x4f27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4f27;
	}
x86_l_520d:
	/* 0x520d: jmp    4e8f <kprobe_unwind_native+0x4e8f> */
	goto x86_l_4e8f;
x86_l_5212:
	/* 0x5212: movabs rax,0x2578302073736572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2699960892542641522ULL);
x86_l_521c:
	/* 0x521c: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5221:
	/* 0x5221: movabs rax,0x6464612065636e65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7234013693231722085ULL);
x86_l_522b:
	/* 0x522b: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5230:
	/* 0x5230: movabs rax,0x7265666572656420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243107278868538400ULL);
x86_l_523a:
	/* 0x523a: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_523f:
	/* 0x523f: movabs rax,0x6f742064656c6961 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8031079651078859105ULL);
x86_l_5249:
	/* 0x5249: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_524e:
	/* 0x524e: movabs rax,0x6620646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358992216502005365ULL);
x86_l_5258:
	/* 0x5258: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_525d:
	/* 0x525d: mov    DWORD PTR [rsp+0x38],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518854764ULL);
x86_l_5265:
	/* 0x5265: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_526a:
	/* 0x526a: mov    eax,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_526f:
	/* 0x526f: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5274:
	/* 0x5274: mov    esi,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_5279:
	/* 0x5279: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_527c:
	/* 0x527c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_527e:
	/* 0x527e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5280:
	/* 0x5280: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5283:
	/* 0x5283: jmp    4bff <kprobe_unwind_native+0x4bff> */
	return 19455ULL;
x86_l_5288:
	/* 0x5288: movabs rax,0x296425207265646e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2982549674514539630ULL);
x86_l_5292:
	/* 0x5292: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_529a:
	/* 0x529a: movabs rax,0x69776e752820786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7599664345674446956ULL);
x86_l_52a4:
	/* 0x52a4: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_52ac:
	/* 0x52ac: movabs rax,0x6c2520736920786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7792670410291574892ULL);
x86_l_52b6:
	/* 0x52b6: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_52be:
	/* 0x52be: movabs rax,0x2520435020726f66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675212190078889830ULL);
x86_l_52c8:
	/* 0x52c8: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_52d0:
	/* 0x52d0: movabs rax,0x206469206e6f6974 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334106094897424756ULL);
x86_l_52da:
	/* 0x52da: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_52e2:
	/* 0x52e2: movabs rbp,0x6365732074786554 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 7162257365632836948ULL);
x86_l_52ec:
	/* 0x52ec: mov    QWORD PTR [rsp+0xa0],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_52f4:
	/* 0x52f4: mov    WORD PTR [rsp+0xd0],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 893353197578ULL);
x86_l_52fe:
	/* 0x52fe: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_5306:
	/* 0x5306: mov    eax,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_530b:
	/* 0x530b: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_5311:
	/* 0x5311: mov    rcx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_5318:
	/* 0x5318: mov    esi,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 50ULL);
x86_l_531d:
	/* 0x531d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5320:
	/* 0x5320: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_5323:
	/* 0x5323: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5325:
	/* 0x5325: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_5328:
	/* 0x5328: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_532f:
	/* 0x532f: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5332:
	/* 0x5332: je     4fdc <kprobe_unwind_native+0x4fdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fdc;
	}
x86_l_5338:
	/* 0x5338: movabs rax,0xa786c6c252073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947156833280115ULL);
x86_l_5342:
	/* 0x5342: mov    QWORD PTR [rsp+0xc7],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 199ULL);
x86_l_534a:
	/* 0x534a: movabs rax,0x7369207465736666 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8316213871206688358ULL);
x86_l_5354:
	/* 0x5354: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_535c:
	/* 0x535c: movabs rax,0x6f20646e61202c78 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8007510562703420536ULL);
x86_l_5366:
	/* 0x5366: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_536e:
	/* 0x536e: movabs rax,0x6c6c252073692073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660274886418547ULL);
x86_l_5378:
	/* 0x5378: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_5380:
	/* 0x5380: movabs rax,0x616962206e6f6974 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7019249385664899444ULL);
x86_l_538a:
	/* 0x538a: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_5392:
	/* 0x5392: mov    QWORD PTR [rsp+0xa0],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_539a:
	/* 0x539a: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_53a2:
	/* 0x53a2: mov    eax,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 47ULL);
x86_l_53a7:
	/* 0x53a7: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_53ad:
	/* 0x53ad: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_53b4:
	/* 0x53b4: mov    rdx,QWORD PTR [rbx+0xf20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3872ULL);
x86_l_53bb:
	/* 0x53bb: mov    esi,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 47ULL);
x86_l_53c0:
	/* 0x53c0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_53c2:
	/* 0x53c2: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_53c5:
	/* 0x53c5: jmp    4fdc <kprobe_unwind_native+0x4fdc> */
	goto x86_l_4fdc;
x86_l_53ca:
	/* 0x53ca: movabs rax,0xa642520686374 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860387386228ULL);
x86_l_53d4:
	/* 0x53d4: mov    QWORD PTR [rsp+0xb6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_53dc:
	/* 0x53dc: movabs rax,0x6374616d20737465 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7166460028377068645ULL);
x86_l_53e6:
	/* 0x53e6: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_53ee:
	/* 0x53ee: movabs rax,0x7366666f5f726574 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8315446390514935156ULL);
x86_l_53f8:
	/* 0x53f8: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_5400:
	/* 0x5400: movabs rax,0x6572707265746e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310028781806448233ULL);
x86_l_540a:
	/* 0x540a: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_5412:
	/* 0x5412: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_541a:
	/* 0x541a: mov    eax,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 30ULL);
x86_l_541f:
	/* 0x541f: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5424:
	/* 0x5424: movzx  edx,WORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_5429:
	/* 0x5429: mov    esi,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 30ULL);
x86_l_542e:
	/* 0x542e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5430:
	/* 0x5430: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5432:
	/* 0x5432: mov    eax,DWORD PTR [rbx+0x1380] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4992ULL);
x86_l_5438:
	/* 0x5438: mov    ecx,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_543c:
	/* 0x543c: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_543f:
	/* 0x543f: jb     5060 <kprobe_unwind_native+0x5060> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5060;
	}
x86_l_5445:
	/* 0x5445: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_544d:
	/* 0x544d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_5454:
	/* 0x5454: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_5459:
	/* 0x5459: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_545e:
	/* 0x545e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5460:
	/* 0x5460: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5463:
	/* 0x5463: je     546a <kprobe_unwind_native+0x546a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_546a;
	}
x86_l_5465:
	/* 0x5465: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_5468:
	/* 0x5468: jmp    547a <kprobe_unwind_native+0x547a> */
	goto x86_l_547a;
x86_l_546a:
	/* 0x546a: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5471:
	/* 0x5471: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5474:
	/* 0x5474: jne    6938 <kprobe_unwind_native+0x6938> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 26936ULL;
	}
x86_l_547a:
	/* 0x547a: movzx  r12d,WORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_547f:
	/* 0x547f: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_5483:
	/* 0x5483: jne    75b1 <kprobe_unwind_native+0x75b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 30129ULL;
	}
	return 21641ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 21641ULL: goto x86_l_5489;
	case 21648ULL: goto x86_l_5490;
	case 21651ULL: goto x86_l_5493;
	case 21657ULL: goto x86_l_5499;
	case 21665ULL: goto x86_l_54a1;
	case 21672ULL: goto x86_l_54a8;
	case 21677ULL: goto x86_l_54ad;
	case 21682ULL: goto x86_l_54b2;
	case 21684ULL: goto x86_l_54b4;
	case 21687ULL: goto x86_l_54b7;
	case 21693ULL: goto x86_l_54bd;
	case 21696ULL: goto x86_l_54c0;
	case 21703ULL: goto x86_l_54c7;
	case 21706ULL: goto x86_l_54ca;
	case 21712ULL: goto x86_l_54d0;
	case 21722ULL: goto x86_l_54da;
	case 21730ULL: goto x86_l_54e2;
	case 21740ULL: goto x86_l_54ec;
	case 21748ULL: goto x86_l_54f4;
	case 21758ULL: goto x86_l_54fe;
	case 21766ULL: goto x86_l_5506;
	case 21776ULL: goto x86_l_5510;
	case 21784ULL: goto x86_l_5518;
	case 21794ULL: goto x86_l_5522;
	case 21802ULL: goto x86_l_552a;
	case 21813ULL: goto x86_l_5535;
	case 21821ULL: goto x86_l_553d;
	case 21826ULL: goto x86_l_5542;
	case 21832ULL: goto x86_l_5548;
	case 21839ULL: goto x86_l_554f;
	case 21846ULL: goto x86_l_5556;
	case 21853ULL: goto x86_l_555d;
	case 21858ULL: goto x86_l_5562;
	case 21860ULL: goto x86_l_5564;
	case 21863ULL: goto x86_l_5567;
	case 21865ULL: goto x86_l_5569;
	case 21872ULL: goto x86_l_5570;
	case 21875ULL: goto x86_l_5573;
	case 21881ULL: goto x86_l_5579;
	case 21887ULL: goto x86_l_557f;
	case 21891ULL: goto x86_l_5583;
	case 21896ULL: goto x86_l_5588;
	case 21903ULL: goto x86_l_558f;
	case 21909ULL: goto x86_l_5595;
	case 21916ULL: goto x86_l_559c;
	case 21923ULL: goto x86_l_55a3;
	case 21930ULL: goto x86_l_55aa;
	case 21933ULL: goto x86_l_55ad;
	case 21939ULL: goto x86_l_55b3;
	case 21943ULL: goto x86_l_55b7;
	case 21951ULL: goto x86_l_55bf;
	case 21959ULL: goto x86_l_55c7;
	case 21967ULL: goto x86_l_55cf;
	case 21974ULL: goto x86_l_55d6;
	case 21985ULL: goto x86_l_55e1;
	case 21995ULL: goto x86_l_55eb;
	case 22006ULL: goto x86_l_55f6;
	case 22013ULL: goto x86_l_55fd;
	case 22021ULL: goto x86_l_5605;
	case 22026ULL: goto x86_l_560a;
	case 22033ULL: goto x86_l_5611;
	case 22040ULL: goto x86_l_5618;
	case 22048ULL: goto x86_l_5620;
	case 22053ULL: goto x86_l_5625;
	case 22059ULL: goto x86_l_562b;
	case 22066ULL: goto x86_l_5632;
	case 22071ULL: goto x86_l_5637;
	case 22076ULL: goto x86_l_563c;
	case 22078ULL: goto x86_l_563e;
	case 22083ULL: goto x86_l_5643;
	case 22086ULL: goto x86_l_5646;
	case 22091ULL: goto x86_l_564b;
	case 22098ULL: goto x86_l_5652;
	case 22100ULL: goto x86_l_5654;
	case 22105ULL: goto x86_l_5659;
	case 22108ULL: goto x86_l_565c;
	case 22112ULL: goto x86_l_5660;
	case 22116ULL: goto x86_l_5664;
	case 22119ULL: goto x86_l_5667;
	case 22125ULL: goto x86_l_566d;
	case 22128ULL: goto x86_l_5670;
	case 22134ULL: goto x86_l_5676;
	case 22137ULL: goto x86_l_5679;
	case 22143ULL: goto x86_l_567f;
	case 22146ULL: goto x86_l_5682;
	case 22152ULL: goto x86_l_5688;
	case 22155ULL: goto x86_l_568b;
	case 22161ULL: goto x86_l_5691;
	case 22168ULL: goto x86_l_5698;
	case 22173ULL: goto x86_l_569d;
	case 22176ULL: goto x86_l_56a0;
	case 22182ULL: goto x86_l_56a6;
	case 22188ULL: goto x86_l_56ac;
	case 22191ULL: goto x86_l_56af;
	case 22197ULL: goto x86_l_56b5;
	case 22207ULL: goto x86_l_56bf;
	case 22212ULL: goto x86_l_56c4;
	case 22222ULL: goto x86_l_56ce;
	case 22227ULL: goto x86_l_56d3;
	case 22237ULL: goto x86_l_56dd;
	case 22242ULL: goto x86_l_56e2;
	case 22252ULL: goto x86_l_56ec;
	case 22257ULL: goto x86_l_56f1;
	case 22267ULL: goto x86_l_56fb;
	case 22272ULL: goto x86_l_5700;
	case 22282ULL: goto x86_l_570a;
	case 22287ULL: goto x86_l_570f;
	case 22297ULL: goto x86_l_5719;
	case 22302ULL: goto x86_l_571e;
	case 22309ULL: goto x86_l_5725;
	case 22314ULL: goto x86_l_572a;
	case 22319ULL: goto x86_l_572f;
	case 22325ULL: goto x86_l_5735;
	case 22330ULL: goto x86_l_573a;
	case 22338ULL: goto x86_l_5742;
	case 22343ULL: goto x86_l_5747;
	case 22345ULL: goto x86_l_5749;
	case 22348ULL: goto x86_l_574c;
	case 22353ULL: goto x86_l_5751;
	case 22356ULL: goto x86_l_5754;
	case 22358ULL: goto x86_l_5756;
	case 22361ULL: goto x86_l_5759;
	case 22363ULL: goto x86_l_575b;
	case 22366ULL: goto x86_l_575e;
	case 22372ULL: goto x86_l_5764;
	case 22375ULL: goto x86_l_5767;
	case 22381ULL: goto x86_l_576d;
	case 22388ULL: goto x86_l_5774;
	case 22393ULL: goto x86_l_5779;
	case 22396ULL: goto x86_l_577c;
	case 22398ULL: goto x86_l_577e;
	case 22401ULL: goto x86_l_5781;
	case 22407ULL: goto x86_l_5787;
	case 22410ULL: goto x86_l_578a;
	case 22416ULL: goto x86_l_5790;
	case 22423ULL: goto x86_l_5797;
	case 22428ULL: goto x86_l_579c;
	case 22431ULL: goto x86_l_579f;
	case 22433ULL: goto x86_l_57a1;
	case 22436ULL: goto x86_l_57a4;
	case 22442ULL: goto x86_l_57aa;
	case 22445ULL: goto x86_l_57ad;
	case 22447ULL: goto x86_l_57af;
	case 22454ULL: goto x86_l_57b6;
	case 22459ULL: goto x86_l_57bb;
	case 22462ULL: goto x86_l_57be;
	case 22468ULL: goto x86_l_57c4;
	case 22471ULL: goto x86_l_57c7;
	case 22473ULL: goto x86_l_57c9;
	case 22480ULL: goto x86_l_57d0;
	case 22485ULL: goto x86_l_57d5;
	case 22488ULL: goto x86_l_57d8;
	case 22494ULL: goto x86_l_57de;
	case 22497ULL: goto x86_l_57e1;
	case 22499ULL: goto x86_l_57e3;
	case 22506ULL: goto x86_l_57ea;
	case 22511ULL: goto x86_l_57ef;
	case 22514ULL: goto x86_l_57f2;
	case 22520ULL: goto x86_l_57f8;
	case 22523ULL: goto x86_l_57fb;
	case 22525ULL: goto x86_l_57fd;
	case 22532ULL: goto x86_l_5804;
	case 22537ULL: goto x86_l_5809;
	case 22540ULL: goto x86_l_580c;
	case 22546ULL: goto x86_l_5812;
	case 22549ULL: goto x86_l_5815;
	case 22551ULL: goto x86_l_5817;
	case 22558ULL: goto x86_l_581e;
	case 22563ULL: goto x86_l_5823;
	case 22569ULL: goto x86_l_5829;
	case 22575ULL: goto x86_l_582f;
	case 22582ULL: goto x86_l_5836;
	case 22585ULL: goto x86_l_5839;
	case 22591ULL: goto x86_l_583f;
	case 22601ULL: goto x86_l_5849;
	case 22606ULL: goto x86_l_584e;
	case 22616ULL: goto x86_l_5858;
	case 22621ULL: goto x86_l_585d;
	case 22631ULL: goto x86_l_5867;
	case 22636ULL: goto x86_l_586c;
	case 22646ULL: goto x86_l_5876;
	case 22651ULL: goto x86_l_587b;
	case 22661ULL: goto x86_l_5885;
	case 22666ULL: goto x86_l_588a;
	case 22676ULL: goto x86_l_5894;
	case 22681ULL: goto x86_l_5899;
	case 22691ULL: goto x86_l_58a3;
	case 22696ULL: goto x86_l_58a8;
	case 22706ULL: goto x86_l_58b2;
	case 22711ULL: goto x86_l_58b7;
	case 22716ULL: goto x86_l_58bc;
	case 22721ULL: goto x86_l_58c1;
	case 22727ULL: goto x86_l_58c7;
	case 22735ULL: goto x86_l_58cf;
	case 22739ULL: goto x86_l_58d3;
	case 22744ULL: goto x86_l_58d8;
	case 22746ULL: goto x86_l_58da;
	case 22749ULL: goto x86_l_58dd;
	case 22754ULL: goto x86_l_58e2;
	case 22761ULL: goto x86_l_58e9;
	case 22763ULL: goto x86_l_58eb;
	case 22770ULL: goto x86_l_58f2;
	case 22772ULL: goto x86_l_58f4;
	case 22779ULL: goto x86_l_58fb;
	case 22781ULL: goto x86_l_58fd;
	case 22788ULL: goto x86_l_5904;
	case 22790ULL: goto x86_l_5906;
	case 22797ULL: goto x86_l_590d;
	case 22799ULL: goto x86_l_590f;
	case 22806ULL: goto x86_l_5916;
	case 22808ULL: goto x86_l_5918;
	case 22815ULL: goto x86_l_591f;
	case 22817ULL: goto x86_l_5921;
	case 22824ULL: goto x86_l_5928;
	case 22832ULL: goto x86_l_5930;
	case 22837ULL: goto x86_l_5935;
	case 22839ULL: goto x86_l_5937;
	case 22844ULL: goto x86_l_593c;
	case 22847ULL: goto x86_l_593f;
	case 22853ULL: goto x86_l_5945;
	case 22858ULL: goto x86_l_594a;
	case 22861ULL: goto x86_l_594d;
	case 22869ULL: goto x86_l_5955;
	case 22876ULL: goto x86_l_595c;
	case 22881ULL: goto x86_l_5961;
	case 22885ULL: goto x86_l_5965;
	case 22887ULL: goto x86_l_5967;
	case 22893ULL: goto x86_l_596d;
	case 22896ULL: goto x86_l_5970;
	case 22899ULL: goto x86_l_5973;
	case 22906ULL: goto x86_l_597a;
	case 22909ULL: goto x86_l_597d;
	case 22915ULL: goto x86_l_5983;
	case 22919ULL: goto x86_l_5987;
	case 22921ULL: goto x86_l_5989;
	case 22925ULL: goto x86_l_598d;
	case 22930ULL: goto x86_l_5992;
	case 22935ULL: goto x86_l_5997;
	case 22940ULL: goto x86_l_599c;
	case 22942ULL: goto x86_l_599e;
	case 22945ULL: goto x86_l_59a1;
	case 22951ULL: goto x86_l_59a7;
	case 22955ULL: goto x86_l_59ab;
	case 22958ULL: goto x86_l_59ae;
	case 22963ULL: goto x86_l_59b3;
	case 22966ULL: goto x86_l_59b6;
	case 22970ULL: goto x86_l_59ba;
	case 22974ULL: goto x86_l_59be;
	case 22978ULL: goto x86_l_59c2;
	case 22981ULL: goto x86_l_59c5;
	case 22987ULL: goto x86_l_59cb;
	case 22991ULL: goto x86_l_59cf;
	case 22993ULL: goto x86_l_59d1;
	case 22995ULL: goto x86_l_59d3;
	case 22999ULL: goto x86_l_59d7;
	case 23004ULL: goto x86_l_59dc;
	case 23009ULL: goto x86_l_59e1;
	case 23014ULL: goto x86_l_59e6;
	case 23016ULL: goto x86_l_59e8;
	case 23019ULL: goto x86_l_59eb;
	case 23025ULL: goto x86_l_59f1;
	case 23029ULL: goto x86_l_59f5;
	case 23033ULL: goto x86_l_59f9;
	case 23038ULL: goto x86_l_59fe;
	case 23041ULL: goto x86_l_5a01;
	case 23045ULL: goto x86_l_5a05;
	case 23049ULL: goto x86_l_5a09;
	case 23052ULL: goto x86_l_5a0c;
	case 23056ULL: goto x86_l_5a10;
	case 23059ULL: goto x86_l_5a13;
	case 23065ULL: goto x86_l_5a19;
	case 23069ULL: goto x86_l_5a1d;
	case 23072ULL: goto x86_l_5a20;
	case 23074ULL: goto x86_l_5a22;
	case 23078ULL: goto x86_l_5a26;
	case 23083ULL: goto x86_l_5a2b;
	case 23088ULL: goto x86_l_5a30;
	case 23093ULL: goto x86_l_5a35;
	case 23095ULL: goto x86_l_5a37;
	case 23098ULL: goto x86_l_5a3a;
	case 23104ULL: goto x86_l_5a40;
	case 23108ULL: goto x86_l_5a44;
	case 23111ULL: goto x86_l_5a47;
	case 23116ULL: goto x86_l_5a4c;
	case 23119ULL: goto x86_l_5a4f;
	case 23123ULL: goto x86_l_5a53;
	case 23127ULL: goto x86_l_5a57;
	case 23130ULL: goto x86_l_5a5a;
	case 23134ULL: goto x86_l_5a5e;
	case 23136ULL: goto x86_l_5a60;
	case 23142ULL: goto x86_l_5a66;
	case 23146ULL: goto x86_l_5a6a;
	case 23148ULL: goto x86_l_5a6c;
	case 23150ULL: goto x86_l_5a6e;
	case 23154ULL: goto x86_l_5a72;
	case 23159ULL: goto x86_l_5a77;
	case 23164ULL: goto x86_l_5a7c;
	case 23169ULL: goto x86_l_5a81;
	case 23171ULL: goto x86_l_5a83;
	case 23174ULL: goto x86_l_5a86;
	case 23180ULL: goto x86_l_5a8c;
	case 23184ULL: goto x86_l_5a90;
	case 23188ULL: goto x86_l_5a94;
	case 23193ULL: goto x86_l_5a99;
	case 23196ULL: goto x86_l_5a9c;
	case 23200ULL: goto x86_l_5aa0;
	case 23204ULL: goto x86_l_5aa4;
	case 23207ULL: goto x86_l_5aa7;
	case 23211ULL: goto x86_l_5aab;
	case 23214ULL: goto x86_l_5aae;
	case 23220ULL: goto x86_l_5ab4;
	case 23224ULL: goto x86_l_5ab8;
	case 23227ULL: goto x86_l_5abb;
	case 23229ULL: goto x86_l_5abd;
	case 23233ULL: goto x86_l_5ac1;
	case 23238ULL: goto x86_l_5ac6;
	case 23243ULL: goto x86_l_5acb;
	case 23248ULL: goto x86_l_5ad0;
	case 23250ULL: goto x86_l_5ad2;
	case 23253ULL: goto x86_l_5ad5;
	case 23259ULL: goto x86_l_5adb;
	case 23263ULL: goto x86_l_5adf;
	case 23266ULL: goto x86_l_5ae2;
	case 23271ULL: goto x86_l_5ae7;
	case 23274ULL: goto x86_l_5aea;
	case 23278ULL: goto x86_l_5aee;
	case 23282ULL: goto x86_l_5af2;
	case 23285ULL: goto x86_l_5af5;
	case 23289ULL: goto x86_l_5af9;
	case 23291ULL: goto x86_l_5afb;
	case 23297ULL: goto x86_l_5b01;
	case 23301ULL: goto x86_l_5b05;
	case 23303ULL: goto x86_l_5b07;
	case 23305ULL: goto x86_l_5b09;
	case 23309ULL: goto x86_l_5b0d;
	case 23314ULL: goto x86_l_5b12;
	case 23319ULL: goto x86_l_5b17;
	case 23324ULL: goto x86_l_5b1c;
	case 23326ULL: goto x86_l_5b1e;
	case 23329ULL: goto x86_l_5b21;
	case 23335ULL: goto x86_l_5b27;
	case 23339ULL: goto x86_l_5b2b;
	case 23343ULL: goto x86_l_5b2f;
	case 23348ULL: goto x86_l_5b34;
	case 23351ULL: goto x86_l_5b37;
	case 23355ULL: goto x86_l_5b3b;
	case 23359ULL: goto x86_l_5b3f;
	case 23362ULL: goto x86_l_5b42;
	case 23366ULL: goto x86_l_5b46;
	case 23369ULL: goto x86_l_5b49;
	case 23375ULL: goto x86_l_5b4f;
	case 23379ULL: goto x86_l_5b53;
	case 23382ULL: goto x86_l_5b56;
	case 23384ULL: goto x86_l_5b58;
	case 23388ULL: goto x86_l_5b5c;
	case 23393ULL: goto x86_l_5b61;
	case 23398ULL: goto x86_l_5b66;
	case 23403ULL: goto x86_l_5b6b;
	case 23405ULL: goto x86_l_5b6d;
	case 23408ULL: goto x86_l_5b70;
	case 23414ULL: goto x86_l_5b76;
	case 23418ULL: goto x86_l_5b7a;
	case 23421ULL: goto x86_l_5b7d;
	case 23426ULL: goto x86_l_5b82;
	case 23429ULL: goto x86_l_5b85;
	case 23433ULL: goto x86_l_5b89;
	case 23437ULL: goto x86_l_5b8d;
	case 23440ULL: goto x86_l_5b90;
	case 23444ULL: goto x86_l_5b94;
	case 23446ULL: goto x86_l_5b96;
	case 23452ULL: goto x86_l_5b9c;
	case 23456ULL: goto x86_l_5ba0;
	case 23458ULL: goto x86_l_5ba2;
	case 23460ULL: goto x86_l_5ba4;
	case 23464ULL: goto x86_l_5ba8;
	case 23469ULL: goto x86_l_5bad;
	case 23474ULL: goto x86_l_5bb2;
	case 23479ULL: goto x86_l_5bb7;
	case 23481ULL: goto x86_l_5bb9;
	case 23484ULL: goto x86_l_5bbc;
	case 23490ULL: goto x86_l_5bc2;
	case 23494ULL: goto x86_l_5bc6;
	case 23498ULL: goto x86_l_5bca;
	case 23503ULL: goto x86_l_5bcf;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5489:
	/* 0x5489: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5490:
	/* 0x5490: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5493:
	/* 0x5493: jne    66b6 <kprobe_unwind_native+0x66b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 26294ULL;
	}
x86_l_5499:
	/* 0x5499: mov    DWORD PTR [rsp+0x10],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476741ULL);
x86_l_54a1:
	/* 0x54a1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_54a8:
	/* 0x54a8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54ad:
	/* 0x54ad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_54b2:
	/* 0x54b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54b4:
	/* 0x54b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_54b7:
	/* 0x54b7: je     5569 <kprobe_unwind_native+0x5569> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5569;
	}
x86_l_54bd:
	/* 0x54bd: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_54c0:
	/* 0x54c0: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_54c7:
	/* 0x54c7: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54ca:
	/* 0x54ca: je     5579 <kprobe_unwind_native+0x5579> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5579;
	}
x86_l_54d0:
	/* 0x54d0: movabs rax,0x63617473206e6f20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7161132920309968672ULL);
x86_l_54da:
	/* 0x54da: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_54e2:
	/* 0x54e2: movabs rax,0x7525206e6f697469 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8441188735263536233ULL);
x86_l_54ec:
	/* 0x54ec: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_54f4:
	/* 0x54f4: movabs rax,0x736f70206f742078 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8317990321387741304ULL);
x86_l_54fe:
	/* 0x54fe: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_5506:
	/* 0x5506: movabs rax,0x6c6c2520786c6c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660274970520613ULL);
x86_l_5510:
	/* 0x5510: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_5518:
	/* 0x5518: movabs rax,0x20676e6968737550 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334956330817910096ULL);
x86_l_5522:
	/* 0x5522: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_552a:
	/* 0x552a: mov    DWORD PTR [rsp+0xc7],0xa6b63 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 854699174755ULL);
x86_l_5535:
	/* 0x5535: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_553d:
	/* 0x553d: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_5542:
	/* 0x5542: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_5548:
	/* 0x5548: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_554f:
	/* 0x554f: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_5556:
	/* 0x5556: mov    r8d,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_555d:
	/* 0x555d: mov    esi,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 43ULL);
x86_l_5562:
	/* 0x5562: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5564:
	/* 0x5564: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_5567:
	/* 0x5567: jmp    5579 <kprobe_unwind_native+0x5579> */
	goto x86_l_5579;
x86_l_5569:
	/* 0x5569: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5570:
	/* 0x5570: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5573:
	/* 0x5573: jne    678b <kprobe_unwind_native+0x678b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 26507ULL;
	}
x86_l_5579:
	/* 0x5579: mov    eax,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_557f:
	/* 0x557f: cmp    rax,0x7e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 126ULL);
x86_l_5583:
	/* 0x5583: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5588:
	/* 0x5588: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_558f:
	/* 0x558f: ja     13a <kprobe_unwind_native+0x13a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 314ULL;
	}
x86_l_5595:
	/* 0x5595: movzx  ecx,BYTE PTR [rbx+0xf30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3888ULL);
x86_l_559c:
	/* 0x559c: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_55a3:
	/* 0x55a3: mov    rsi,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_55aa:
	/* 0x55aa: lea    edi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_55ad:
	/* 0x55ad: mov    DWORD PTR [rbx+0x2c0],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_55b3:
	/* 0x55b3: lea    rax,[rax+rax*2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_55b7:
	/* 0x55b7: mov    QWORD PTR [rbx+rax*8+0x2d0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 720ULL);
x86_l_55bf:
	/* 0x55bf: mov    QWORD PTR [rbx+rax*8+0x2d8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 728ULL);
x86_l_55c7:
	/* 0x55c7: mov    BYTE PTR [rbx+rax*8+0x2e0],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 3161095929859ULL);
x86_l_55cf:
	/* 0x55cf: mov    BYTE PTR [rbx+rax*8+0x2e1],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 3), 737ULL);
x86_l_55d6:
	/* 0x55d6: mov    DWORD PTR [rbx+rax*8+0x2e2],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 3169685864448ULL);
x86_l_55e1:
	/* 0x55e1: mov    WORD PTR [rbx+rax*8+0x2e6],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 3), 3186865733632ULL);
x86_l_55eb:
	/* 0x55eb: mov    DWORD PTR [rsp+0x8c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_55f6:
	/* 0x55f6: mov    rax,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_55fd:
	/* 0x55fd: mov    QWORD PTR [rsp+0x160],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_5605:
	/* 0x5605: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_560a:
	/* 0x560a: mov    rax,0xffffffffffff0000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 18446744073709486080ULL);
x86_l_5611:
	/* 0x5611: and    rax,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 3864ULL);
x86_l_5618:
	/* 0x5618: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5620:
	/* 0x5620: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5625:
	/* 0x5625: jne    671d <kprobe_unwind_native+0x671d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 26397ULL;
	}
x86_l_562b:
	/* 0x562b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&stack_delta_page_to_info)));
x86_l_5632:
	/* 0x5632: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_5637:
	/* 0x5637: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_563c:
	/* 0x563c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_563e:
	/* 0x563e: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5643:
	/* 0x5643: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5646:
	/* 0x5646: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_564b:
	/* 0x564b: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5652:
	/* 0x5652: je     569d <kprobe_unwind_native+0x569d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_569d;
	}
x86_l_5654:
	/* 0x5654: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5659:
	/* 0x5659: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_565c:
	/* 0x565c: add    rbp,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_5660:
	/* 0x5660: movzx  eax,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_5664:
	/* 0x5664: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_5667:
	/* 0x5667: jg     5751 <kprobe_unwind_native+0x5751> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_5751;
	}
x86_l_566d:
	/* 0x566d: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_5670:
	/* 0x5670: jg     5779 <kprobe_unwind_native+0x5779> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_5779;
	}
x86_l_5676:
	/* 0x5676: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_5679:
	/* 0x5679: jg     57bb <kprobe_unwind_native+0x57bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_57bb;
	}
x86_l_567f:
	/* 0x567f: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_5682:
	/* 0x5682: je     58e2 <kprobe_unwind_native+0x58e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58e2;
	}
x86_l_5688:
	/* 0x5688: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_568b:
	/* 0x568b: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5823;
	}
x86_l_5691:
	/* 0x5691: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_9_stack_deltas)));
x86_l_5698:
	/* 0x5698: jmp    5928 <kprobe_unwind_native+0x5928> */
	goto x86_l_5928;
x86_l_569d:
	/* 0x569d: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_56a0:
	/* 0x56a0: mov    r13d,0xfa0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4000ULL);
x86_l_56a6:
	/* 0x56a6: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_56ac:
	/* 0x56ac: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56af:
	/* 0x56af: je     5f45 <kprobe_unwind_native+0x5f45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24389ULL;
	}
x86_l_56b5:
	/* 0x56b5: movabs rax,0x786c252065676170 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8677351403106558320ULL);
x86_l_56bf:
	/* 0x56bf: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_56c4:
	/* 0x56c4: movabs rax,0x202c786c25204449 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2318360314063635529ULL);
x86_l_56ce:
	/* 0x56ce: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_56d3:
	/* 0x56d3: movabs rax,0x656c696620656761 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7308332182666569569ULL);
x86_l_56dd:
	/* 0x56dd: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_56e2:
	/* 0x56e2: movabs rax,0x702061746c656420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8079564884165354528ULL);
x86_l_56ec:
	/* 0x56ec: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_56f1:
	/* 0x56f1: movabs rax,0x6b63617473207075 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7738135737528250485ULL);
x86_l_56fb:
	/* 0x56fb: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5700:
	/* 0x5700: movabs rax,0x206b6f6f6c206f74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2336083356067852148ULL);
x86_l_570a:
	/* 0x570a: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_570f:
	/* 0x570f: movabs rax,0x206572756c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334397830517055814ULL);
x86_l_5719:
	/* 0x5719: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_571e:
	/* 0x571e: mov    WORD PTR [rsp+0x48],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 309237645322ULL);
x86_l_5725:
	/* 0x5725: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_572a:
	/* 0x572a: mov    eax,0x3a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_572f:
	/* 0x572f: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_5735:
	/* 0x5735: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_573a:
	/* 0x573a: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5742:
	/* 0x5742: mov    esi,0x3a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 58ULL);
x86_l_5747:
	/* 0x5747: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5749:
	/* 0x5749: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_574c:
	/* 0x574c: jmp    5f45 <kprobe_unwind_native+0x5f45> */
	return 24389ULL;
x86_l_5751:
	/* 0x5751: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_5754:
	/* 0x5754: jg     579c <kprobe_unwind_native+0x579c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_579c;
	}
x86_l_5756:
	/* 0x5756: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_5759:
	/* 0x5759: jg     57d5 <kprobe_unwind_native+0x57d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_57d5;
	}
x86_l_575b:
	/* 0x575b: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_575e:
	/* 0x575e: je     58eb <kprobe_unwind_native+0x58eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58eb;
	}
x86_l_5764:
	/* 0x5764: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_5767:
	/* 0x5767: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5823;
	}
x86_l_576d:
	/* 0x576d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_17_stack_deltas)));
x86_l_5774:
	/* 0x5774: jmp    5928 <kprobe_unwind_native+0x5928> */
	goto x86_l_5928;
x86_l_5779:
	/* 0x5779: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_577c:
	/* 0x577c: jg     57ef <kprobe_unwind_native+0x57ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_57ef;
	}
x86_l_577e:
	/* 0x577e: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_5781:
	/* 0x5781: je     58f4 <kprobe_unwind_native+0x58f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58f4;
	}
x86_l_5787:
	/* 0x5787: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_578a:
	/* 0x578a: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5823;
	}
x86_l_5790:
	/* 0x5790: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_13_stack_deltas)));
x86_l_5797:
	/* 0x5797: jmp    5928 <kprobe_unwind_native+0x5928> */
	goto x86_l_5928;
x86_l_579c:
	/* 0x579c: cmp    eax,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_579f:
	/* 0x579f: jg     5809 <kprobe_unwind_native+0x5809> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_5809;
	}
x86_l_57a1:
	/* 0x57a1: cmp    eax,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 20ULL);
x86_l_57a4:
	/* 0x57a4: je     58fd <kprobe_unwind_native+0x58fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_58fd;
	}
x86_l_57aa:
	/* 0x57aa: cmp    eax,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_57ad:
	/* 0x57ad: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5823;
	}
x86_l_57af:
	/* 0x57af: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_21_stack_deltas)));
x86_l_57b6:
	/* 0x57b6: jmp    5928 <kprobe_unwind_native+0x5928> */
	goto x86_l_5928;
x86_l_57bb:
	/* 0x57bb: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_57be:
	/* 0x57be: je     5906 <kprobe_unwind_native+0x5906> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5906;
	}
x86_l_57c4:
	/* 0x57c4: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_57c7:
	/* 0x57c7: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5823;
	}
x86_l_57c9:
	/* 0x57c9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_11_stack_deltas)));
x86_l_57d0:
	/* 0x57d0: jmp    5928 <kprobe_unwind_native+0x5928> */
	goto x86_l_5928;
x86_l_57d5:
	/* 0x57d5: cmp    eax,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 18ULL);
x86_l_57d8:
	/* 0x57d8: je     590f <kprobe_unwind_native+0x590f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_590f;
	}
x86_l_57de:
	/* 0x57de: cmp    eax,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 19ULL);
x86_l_57e1:
	/* 0x57e1: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5823;
	}
x86_l_57e3:
	/* 0x57e3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_19_stack_deltas)));
x86_l_57ea:
	/* 0x57ea: jmp    5928 <kprobe_unwind_native+0x5928> */
	goto x86_l_5928;
x86_l_57ef:
	/* 0x57ef: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_57f2:
	/* 0x57f2: je     5918 <kprobe_unwind_native+0x5918> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5918;
	}
x86_l_57f8:
	/* 0x57f8: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_57fb:
	/* 0x57fb: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5823;
	}
x86_l_57fd:
	/* 0x57fd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_15_stack_deltas)));
x86_l_5804:
	/* 0x5804: jmp    5928 <kprobe_unwind_native+0x5928> */
	goto x86_l_5928;
x86_l_5809:
	/* 0x5809: cmp    eax,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 22ULL);
x86_l_580c:
	/* 0x580c: je     5921 <kprobe_unwind_native+0x5921> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5921;
	}
x86_l_5812:
	/* 0x5812: cmp    eax,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_5815:
	/* 0x5815: jne    5823 <kprobe_unwind_native+0x5823> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5823;
	}
x86_l_5817:
	/* 0x5817: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_23_stack_deltas)));
x86_l_581e:
	/* 0x581e: jmp    5928 <kprobe_unwind_native+0x5928> */
	goto x86_l_5928;
x86_l_5823:
	/* 0x5823: mov    r13d,0xfa1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4001ULL);
x86_l_5829:
	/* 0x5829: mov    r14d,0x33 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 51ULL);
x86_l_582f:
	/* 0x582f: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5836:
	/* 0x5836: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5839:
	/* 0x5839: je     5f40 <kprobe_unwind_native+0x5f40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24384ULL;
	}
x86_l_583f:
	/* 0x583f: movabs rax,0xa642520444970 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020272ULL);
x86_l_5849:
	/* 0x5849: mov    QWORD PTR [rsp+0x47],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 71ULL);
x86_l_584e:
	/* 0x584e: movabs rax,0x70616d206e692078 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8097873591047626872ULL);
x86_l_5858:
	/* 0x5858: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_585d:
	/* 0x585d: movabs rax,0x6c25206e6f697463 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7792670388922184803ULL);
x86_l_5867:
	/* 0x5867: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_586c:
	/* 0x586c: movabs rax,0x6573207478657420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310222304760656928ULL);
x86_l_5876:
	/* 0x5876: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_587b:
	/* 0x587b: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_5885:
	/* 0x5885: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_588a:
	/* 0x588a: movabs rax,0x726574756f207075 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243122740695953525ULL);
x86_l_5894:
	/* 0x5894: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5899:
	/* 0x5899: movabs rax,0x206b6f6f6c206f74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2336083356067852148ULL);
x86_l_58a3:
	/* 0x58a3: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_58a8:
	/* 0x58a8: movabs rax,0x206572756c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334397830517055814ULL);
x86_l_58b2:
	/* 0x58b2: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_58b7:
	/* 0x58b7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_58bc:
	/* 0x58bc: mov    eax,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 63ULL);
x86_l_58c1:
	/* 0x58c1: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_58c7:
	/* 0x58c7: mov    rdx,QWORD PTR [rsp+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_58cf:
	/* 0x58cf: movzx  ecx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_58d3:
	/* 0x58d3: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_58d8:
	/* 0x58d8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_58da:
	/* 0x58da: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_58dd:
	/* 0x58dd: jmp    5f40 <kprobe_unwind_native+0x5f40> */
	return 24384ULL;
x86_l_58e2:
	/* 0x58e2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_8_stack_deltas)));
x86_l_58e9:
	/* 0x58e9: jmp    5928 <kprobe_unwind_native+0x5928> */
	goto x86_l_5928;
x86_l_58eb:
	/* 0x58eb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_16_stack_deltas)));
x86_l_58f2:
	/* 0x58f2: jmp    5928 <kprobe_unwind_native+0x5928> */
	goto x86_l_5928;
x86_l_58f4:
	/* 0x58f4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_12_stack_deltas)));
x86_l_58fb:
	/* 0x58fb: jmp    5928 <kprobe_unwind_native+0x5928> */
	goto x86_l_5928;
x86_l_58fd:
	/* 0x58fd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_20_stack_deltas)));
x86_l_5904:
	/* 0x5904: jmp    5928 <kprobe_unwind_native+0x5928> */
	goto x86_l_5928;
x86_l_5906:
	/* 0x5906: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_10_stack_deltas)));
x86_l_590d:
	/* 0x590d: jmp    5928 <kprobe_unwind_native+0x5928> */
	goto x86_l_5928;
x86_l_590f:
	/* 0x590f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_18_stack_deltas)));
x86_l_5916:
	/* 0x5916: jmp    5928 <kprobe_unwind_native+0x5928> */
	goto x86_l_5928;
x86_l_5918:
	/* 0x5918: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_14_stack_deltas)));
x86_l_591f:
	/* 0x591f: jmp    5928 <kprobe_unwind_native+0x5928> */
	goto x86_l_5928;
x86_l_5921:
	/* 0x5921: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&exe_id_to_22_stack_deltas)));
x86_l_5928:
	/* 0x5928: lea    rsi,[rsp+0x160] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_5930:
	/* 0x5930: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5935:
	/* 0x5935: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5937:
	/* 0x5937: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_593c:
	/* 0x593c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_593f:
	/* 0x593f: je     5f24 <kprobe_unwind_native+0x5f24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24356ULL;
	}
x86_l_5945:
	/* 0x5945: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_594a:
	/* 0x594a: mov    r13d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_594d:
	/* 0x594d: mov    DWORD PTR [rsp+0x90],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_5955:
	/* 0x5955: mov    rax,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_595c:
	/* 0x595c: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5961:
	/* 0x5961: movzx  eax,WORD PTR [rcx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_5965:
	/* 0x5965: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5967:
	/* 0x5967: je     5e5e <kprobe_unwind_native+0x5e5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24158ULL;
	}
x86_l_596d:
	/* 0x596d: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_5970:
	/* 0x5970: add    r12d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5973:
	/* 0x5973: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_597a:
	/* 0x597a: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_597d:
	/* 0x597d: jne    682b <kprobe_unwind_native+0x682b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 26667ULL;
	}
x86_l_5983:
	/* 0x5983: lea    eax,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_5987:
	/* 0x5987: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5989:
	/* 0x5989: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_598d:
	/* 0x598d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5992:
	/* 0x5992: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5997:
	/* 0x5997: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_599c:
	/* 0x599c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_599e:
	/* 0x599e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_59a1:
	/* 0x59a1: je     61d1 <kprobe_unwind_native+0x61d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25041ULL;
	}
x86_l_59a7:
	/* 0x59a7: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_59ab:
	/* 0x59ab: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_59ae:
	/* 0x59ae: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59b3:
	/* 0x59b3: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59b6:
	/* 0x59b6: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_59ba:
	/* 0x59ba: cmova  r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_59be:
	/* 0x59be: mov    QWORD PTR [rsp],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59c2:
	/* 0x59c2: cmp    ebp,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R12, X86_WIDTH_32);
x86_l_59c5:
	/* 0x59c5: jae    5e4f <kprobe_unwind_native+0x5e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 24143ULL;
	}
x86_l_59cb:
	/* 0x59cb: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59cf:
	/* 0x59cf: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_59d1:
	/* 0x59d1: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_59d3:
	/* 0x59d3: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_59d7:
	/* 0x59d7: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_59dc:
	/* 0x59dc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_59e1:
	/* 0x59e1: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_59e6:
	/* 0x59e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59e8:
	/* 0x59e8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_59eb:
	/* 0x59eb: je     61d1 <kprobe_unwind_native+0x61d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25041ULL;
	}
x86_l_59f1:
	/* 0x59f1: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_59f5:
	/* 0x59f5: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_59f9:
	/* 0x59f9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59fe:
	/* 0x59fe: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a01:
	/* 0x5a01: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_5a05:
	/* 0x5a05: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a09:
	/* 0x5a09: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5a0c:
	/* 0x5a0c: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a10:
	/* 0x5a10: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_5a13:
	/* 0x5a13: jae    5e4f <kprobe_unwind_native+0x5e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 24143ULL;
	}
x86_l_5a19:
	/* 0x5a19: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a1d:
	/* 0x5a1d: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5a20:
	/* 0x5a20: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5a22:
	/* 0x5a22: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a26:
	/* 0x5a26: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a2b:
	/* 0x5a2b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5a30:
	/* 0x5a30: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5a35:
	/* 0x5a35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a37:
	/* 0x5a37: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5a3a:
	/* 0x5a3a: je     61d1 <kprobe_unwind_native+0x61d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25041ULL;
	}
x86_l_5a40:
	/* 0x5a40: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a44:
	/* 0x5a44: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5a47:
	/* 0x5a47: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a4c:
	/* 0x5a4c: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a4f:
	/* 0x5a4f: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_5a53:
	/* 0x5a53: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a57:
	/* 0x5a57: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5a5a:
	/* 0x5a5a: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a5e:
	/* 0x5a5e: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_5a60:
	/* 0x5a60: jae    5e4f <kprobe_unwind_native+0x5e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 24143ULL;
	}
x86_l_5a66:
	/* 0x5a66: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a6a:
	/* 0x5a6a: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5a6c:
	/* 0x5a6c: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5a6e:
	/* 0x5a6e: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a72:
	/* 0x5a72: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a77:
	/* 0x5a77: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5a7c:
	/* 0x5a7c: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5a81:
	/* 0x5a81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a83:
	/* 0x5a83: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5a86:
	/* 0x5a86: je     61d1 <kprobe_unwind_native+0x61d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25041ULL;
	}
x86_l_5a8c:
	/* 0x5a8c: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a90:
	/* 0x5a90: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5a94:
	/* 0x5a94: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a99:
	/* 0x5a99: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a9c:
	/* 0x5a9c: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_5aa0:
	/* 0x5aa0: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5aa4:
	/* 0x5aa4: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5aa7:
	/* 0x5aa7: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5aab:
	/* 0x5aab: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_5aae:
	/* 0x5aae: jae    5e4f <kprobe_unwind_native+0x5e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 24143ULL;
	}
x86_l_5ab4:
	/* 0x5ab4: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ab8:
	/* 0x5ab8: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5abb:
	/* 0x5abb: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5abd:
	/* 0x5abd: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ac1:
	/* 0x5ac1: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ac6:
	/* 0x5ac6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5acb:
	/* 0x5acb: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5ad0:
	/* 0x5ad0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ad2:
	/* 0x5ad2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5ad5:
	/* 0x5ad5: je     61d1 <kprobe_unwind_native+0x61d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25041ULL;
	}
x86_l_5adb:
	/* 0x5adb: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5adf:
	/* 0x5adf: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5ae2:
	/* 0x5ae2: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ae7:
	/* 0x5ae7: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5aea:
	/* 0x5aea: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_5aee:
	/* 0x5aee: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5af2:
	/* 0x5af2: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5af5:
	/* 0x5af5: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5af9:
	/* 0x5af9: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_5afb:
	/* 0x5afb: jae    5e4f <kprobe_unwind_native+0x5e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 24143ULL;
	}
x86_l_5b01:
	/* 0x5b01: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b05:
	/* 0x5b05: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5b07:
	/* 0x5b07: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5b09:
	/* 0x5b09: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b0d:
	/* 0x5b0d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b12:
	/* 0x5b12: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5b17:
	/* 0x5b17: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5b1c:
	/* 0x5b1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b1e:
	/* 0x5b1e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b21:
	/* 0x5b21: je     61d1 <kprobe_unwind_native+0x61d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25041ULL;
	}
x86_l_5b27:
	/* 0x5b27: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b2b:
	/* 0x5b2b: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5b2f:
	/* 0x5b2f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b34:
	/* 0x5b34: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b37:
	/* 0x5b37: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_5b3b:
	/* 0x5b3b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b3f:
	/* 0x5b3f: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5b42:
	/* 0x5b42: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b46:
	/* 0x5b46: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_5b49:
	/* 0x5b49: jae    5e4f <kprobe_unwind_native+0x5e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 24143ULL;
	}
x86_l_5b4f:
	/* 0x5b4f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b53:
	/* 0x5b53: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5b56:
	/* 0x5b56: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5b58:
	/* 0x5b58: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b5c:
	/* 0x5b5c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b61:
	/* 0x5b61: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5b66:
	/* 0x5b66: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5b6b:
	/* 0x5b6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b6d:
	/* 0x5b6d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b70:
	/* 0x5b70: je     61d1 <kprobe_unwind_native+0x61d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25041ULL;
	}
x86_l_5b76:
	/* 0x5b76: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b7a:
	/* 0x5b7a: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5b7d:
	/* 0x5b7d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b82:
	/* 0x5b82: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b85:
	/* 0x5b85: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_5b89:
	/* 0x5b89: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b8d:
	/* 0x5b8d: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5b90:
	/* 0x5b90: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b94:
	/* 0x5b94: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_5b96:
	/* 0x5b96: jae    5e4f <kprobe_unwind_native+0x5e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 24143ULL;
	}
x86_l_5b9c:
	/* 0x5b9c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ba0:
	/* 0x5ba0: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5ba2:
	/* 0x5ba2: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5ba4:
	/* 0x5ba4: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ba8:
	/* 0x5ba8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5bad:
	/* 0x5bad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5bb2:
	/* 0x5bb2: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5bb7:
	/* 0x5bb7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bb9:
	/* 0x5bb9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5bbc:
	/* 0x5bbc: je     61d1 <kprobe_unwind_native+0x61d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25041ULL;
	}
x86_l_5bc2:
	/* 0x5bc2: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5bc6:
	/* 0x5bc6: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5bca:
	/* 0x5bca: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bcf:
	/* 0x5bcf: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 23506ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 23506ULL: goto x86_l_5bd2;
	case 23510ULL: goto x86_l_5bd6;
	case 23514ULL: goto x86_l_5bda;
	case 23517ULL: goto x86_l_5bdd;
	case 23521ULL: goto x86_l_5be1;
	case 23524ULL: goto x86_l_5be4;
	case 23530ULL: goto x86_l_5bea;
	case 23534ULL: goto x86_l_5bee;
	case 23537ULL: goto x86_l_5bf1;
	case 23539ULL: goto x86_l_5bf3;
	case 23543ULL: goto x86_l_5bf7;
	case 23548ULL: goto x86_l_5bfc;
	case 23553ULL: goto x86_l_5c01;
	case 23558ULL: goto x86_l_5c06;
	case 23560ULL: goto x86_l_5c08;
	case 23563ULL: goto x86_l_5c0b;
	case 23569ULL: goto x86_l_5c11;
	case 23573ULL: goto x86_l_5c15;
	case 23576ULL: goto x86_l_5c18;
	case 23581ULL: goto x86_l_5c1d;
	case 23584ULL: goto x86_l_5c20;
	case 23588ULL: goto x86_l_5c24;
	case 23592ULL: goto x86_l_5c28;
	case 23595ULL: goto x86_l_5c2b;
	case 23599ULL: goto x86_l_5c2f;
	case 23601ULL: goto x86_l_5c31;
	case 23607ULL: goto x86_l_5c37;
	case 23611ULL: goto x86_l_5c3b;
	case 23613ULL: goto x86_l_5c3d;
	case 23615ULL: goto x86_l_5c3f;
	case 23619ULL: goto x86_l_5c43;
	case 23624ULL: goto x86_l_5c48;
	case 23629ULL: goto x86_l_5c4d;
	case 23634ULL: goto x86_l_5c52;
	case 23636ULL: goto x86_l_5c54;
	case 23639ULL: goto x86_l_5c57;
	case 23645ULL: goto x86_l_5c5d;
	case 23649ULL: goto x86_l_5c61;
	case 23653ULL: goto x86_l_5c65;
	case 23658ULL: goto x86_l_5c6a;
	case 23661ULL: goto x86_l_5c6d;
	case 23665ULL: goto x86_l_5c71;
	case 23669ULL: goto x86_l_5c75;
	case 23672ULL: goto x86_l_5c78;
	case 23676ULL: goto x86_l_5c7c;
	case 23679ULL: goto x86_l_5c7f;
	case 23685ULL: goto x86_l_5c85;
	case 23689ULL: goto x86_l_5c89;
	case 23692ULL: goto x86_l_5c8c;
	case 23694ULL: goto x86_l_5c8e;
	case 23698ULL: goto x86_l_5c92;
	case 23703ULL: goto x86_l_5c97;
	case 23708ULL: goto x86_l_5c9c;
	case 23713ULL: goto x86_l_5ca1;
	case 23715ULL: goto x86_l_5ca3;
	case 23718ULL: goto x86_l_5ca6;
	case 23724ULL: goto x86_l_5cac;
	case 23728ULL: goto x86_l_5cb0;
	case 23731ULL: goto x86_l_5cb3;
	case 23736ULL: goto x86_l_5cb8;
	case 23739ULL: goto x86_l_5cbb;
	case 23743ULL: goto x86_l_5cbf;
	case 23747ULL: goto x86_l_5cc3;
	case 23750ULL: goto x86_l_5cc6;
	case 23754ULL: goto x86_l_5cca;
	case 23756ULL: goto x86_l_5ccc;
	case 23762ULL: goto x86_l_5cd2;
	case 23766ULL: goto x86_l_5cd6;
	case 23768ULL: goto x86_l_5cd8;
	case 23770ULL: goto x86_l_5cda;
	case 23774ULL: goto x86_l_5cde;
	case 23779ULL: goto x86_l_5ce3;
	case 23784ULL: goto x86_l_5ce8;
	case 23789ULL: goto x86_l_5ced;
	case 23791ULL: goto x86_l_5cef;
	case 23794ULL: goto x86_l_5cf2;
	case 23800ULL: goto x86_l_5cf8;
	case 23804ULL: goto x86_l_5cfc;
	case 23808ULL: goto x86_l_5d00;
	case 23813ULL: goto x86_l_5d05;
	case 23816ULL: goto x86_l_5d08;
	case 23820ULL: goto x86_l_5d0c;
	case 23824ULL: goto x86_l_5d10;
	case 23827ULL: goto x86_l_5d13;
	case 23831ULL: goto x86_l_5d17;
	case 23834ULL: goto x86_l_5d1a;
	case 23840ULL: goto x86_l_5d20;
	case 23844ULL: goto x86_l_5d24;
	case 23847ULL: goto x86_l_5d27;
	case 23849ULL: goto x86_l_5d29;
	case 23853ULL: goto x86_l_5d2d;
	case 23858ULL: goto x86_l_5d32;
	case 23863ULL: goto x86_l_5d37;
	case 23868ULL: goto x86_l_5d3c;
	case 23870ULL: goto x86_l_5d3e;
	case 23873ULL: goto x86_l_5d41;
	case 23879ULL: goto x86_l_5d47;
	case 23883ULL: goto x86_l_5d4b;
	case 23886ULL: goto x86_l_5d4e;
	case 23891ULL: goto x86_l_5d53;
	case 23894ULL: goto x86_l_5d56;
	case 23898ULL: goto x86_l_5d5a;
	case 23902ULL: goto x86_l_5d5e;
	case 23905ULL: goto x86_l_5d61;
	case 23909ULL: goto x86_l_5d65;
	case 23911ULL: goto x86_l_5d67;
	case 23917ULL: goto x86_l_5d6d;
	case 23921ULL: goto x86_l_5d71;
	case 23923ULL: goto x86_l_5d73;
	case 23925ULL: goto x86_l_5d75;
	case 23929ULL: goto x86_l_5d79;
	case 23934ULL: goto x86_l_5d7e;
	case 23939ULL: goto x86_l_5d83;
	case 23944ULL: goto x86_l_5d88;
	case 23946ULL: goto x86_l_5d8a;
	case 23949ULL: goto x86_l_5d8d;
	case 23955ULL: goto x86_l_5d93;
	case 23959ULL: goto x86_l_5d97;
	case 23963ULL: goto x86_l_5d9b;
	case 23968ULL: goto x86_l_5da0;
	case 23971ULL: goto x86_l_5da3;
	case 23975ULL: goto x86_l_5da7;
	case 23979ULL: goto x86_l_5dab;
	case 23982ULL: goto x86_l_5dae;
	case 23986ULL: goto x86_l_5db2;
	case 23989ULL: goto x86_l_5db5;
	case 23995ULL: goto x86_l_5dbb;
	case 23999ULL: goto x86_l_5dbf;
	case 24002ULL: goto x86_l_5dc2;
	case 24004ULL: goto x86_l_5dc4;
	case 24008ULL: goto x86_l_5dc8;
	case 24013ULL: goto x86_l_5dcd;
	case 24018ULL: goto x86_l_5dd2;
	case 24023ULL: goto x86_l_5dd7;
	case 24025ULL: goto x86_l_5dd9;
	case 24028ULL: goto x86_l_5ddc;
	case 24034ULL: goto x86_l_5de2;
	case 24038ULL: goto x86_l_5de6;
	case 24041ULL: goto x86_l_5de9;
	case 24046ULL: goto x86_l_5dee;
	case 24049ULL: goto x86_l_5df1;
	case 24053ULL: goto x86_l_5df5;
	case 24057ULL: goto x86_l_5df9;
	case 24060ULL: goto x86_l_5dfc;
	case 24064ULL: goto x86_l_5e00;
	case 24066ULL: goto x86_l_5e02;
	case 24068ULL: goto x86_l_5e04;
	case 24072ULL: goto x86_l_5e08;
	case 24074ULL: goto x86_l_5e0a;
	case 24076ULL: goto x86_l_5e0c;
	case 24080ULL: goto x86_l_5e10;
	case 24085ULL: goto x86_l_5e15;
	case 24090ULL: goto x86_l_5e1a;
	case 24095ULL: goto x86_l_5e1f;
	case 24097ULL: goto x86_l_5e21;
	case 24100ULL: goto x86_l_5e24;
	case 24106ULL: goto x86_l_5e2a;
	case 24110ULL: goto x86_l_5e2e;
	case 24113ULL: goto x86_l_5e31;
	case 24118ULL: goto x86_l_5e36;
	case 24121ULL: goto x86_l_5e39;
	case 24124ULL: goto x86_l_5e3c;
	case 24128ULL: goto x86_l_5e40;
	case 24131ULL: goto x86_l_5e43;
	case 24135ULL: goto x86_l_5e47;
	case 24137ULL: goto x86_l_5e49;
	case 24143ULL: goto x86_l_5e4f;
	case 24147ULL: goto x86_l_5e53;
	case 24150ULL: goto x86_l_5e56;
	case 24152ULL: goto x86_l_5e58;
	case 24158ULL: goto x86_l_5e5e;
	case 24161ULL: goto x86_l_5e61;
	case 24169ULL: goto x86_l_5e69;
	case 24177ULL: goto x86_l_5e71;
	case 24182ULL: goto x86_l_5e76;
	case 24187ULL: goto x86_l_5e7b;
	case 24189ULL: goto x86_l_5e7d;
	case 24192ULL: goto x86_l_5e80;
	case 24197ULL: goto x86_l_5e85;
	case 24202ULL: goto x86_l_5e8a;
	case 24208ULL: goto x86_l_5e90;
	case 24211ULL: goto x86_l_5e93;
	case 24218ULL: goto x86_l_5e9a;
	case 24221ULL: goto x86_l_5e9d;
	case 24227ULL: goto x86_l_5ea3;
	case 24232ULL: goto x86_l_5ea8;
	case 24236ULL: goto x86_l_5eac;
	case 24238ULL: goto x86_l_5eae;
	case 24245ULL: goto x86_l_5eb5;
	case 24252ULL: goto x86_l_5ebc;
	case 24257ULL: goto x86_l_5ec1;
	case 24259ULL: goto x86_l_5ec3;
	case 24263ULL: goto x86_l_5ec7;
	case 24267ULL: goto x86_l_5ecb;
	case 24274ULL: goto x86_l_5ed2;
	case 24279ULL: goto x86_l_5ed7;
	case 24284ULL: goto x86_l_5edc;
	case 24289ULL: goto x86_l_5ee1;
	case 24295ULL: goto x86_l_5ee7;
	case 24300ULL: goto x86_l_5eec;
	case 24306ULL: goto x86_l_5ef2;
	case 24317ULL: goto x86_l_5efd;
	case 24324ULL: goto x86_l_5f04;
	case 24332ULL: goto x86_l_5f0c;
	case 24337ULL: goto x86_l_5f11;
	case 24339ULL: goto x86_l_5f13;
	case 24342ULL: goto x86_l_5f16;
	case 24348ULL: goto x86_l_5f1c;
	case 24351ULL: goto x86_l_5f1f;
	case 24356ULL: goto x86_l_5f24;
	case 24362ULL: goto x86_l_5f2a;
	case 24368ULL: goto x86_l_5f30;
	case 24375ULL: goto x86_l_5f37;
	case 24378ULL: goto x86_l_5f3a;
	case 24384ULL: goto x86_l_5f40;
	case 24389ULL: goto x86_l_5f45;
	case 24396ULL: goto x86_l_5f4c;
	case 24399ULL: goto x86_l_5f4f;
	case 24402ULL: goto x86_l_5f52;
	case 24409ULL: goto x86_l_5f59;
	case 24416ULL: goto x86_l_5f60;
	case 24427ULL: goto x86_l_5f6b;
	case 24434ULL: goto x86_l_5f72;
	case 24442ULL: goto x86_l_5f7a;
	case 24447ULL: goto x86_l_5f7f;
	case 24449ULL: goto x86_l_5f81;
	case 24452ULL: goto x86_l_5f84;
	case 24454ULL: goto x86_l_5f86;
	case 24461ULL: goto x86_l_5f8d;
	case 24464ULL: goto x86_l_5f90;
	case 24467ULL: goto x86_l_5f93;
	case 24469ULL: goto x86_l_5f95;
	case 24472ULL: goto x86_l_5f98;
	case 24482ULL: goto x86_l_5fa2;
	case 24490ULL: goto x86_l_5faa;
	case 24497ULL: goto x86_l_5fb1;
	case 24502ULL: goto x86_l_5fb6;
	case 24507ULL: goto x86_l_5fbb;
	case 24509ULL: goto x86_l_5fbd;
	case 24512ULL: goto x86_l_5fc0;
	case 24514ULL: goto x86_l_5fc2;
	case 24517ULL: goto x86_l_5fc5;
	case 24519ULL: goto x86_l_5fc7;
	case 24526ULL: goto x86_l_5fce;
	case 24528ULL: goto x86_l_5fd0;
	case 24533ULL: goto x86_l_5fd5;
	case 24535ULL: goto x86_l_5fd7;
	case 24540ULL: goto x86_l_5fdc;
	case 24546ULL: goto x86_l_5fe2;
	case 24549ULL: goto x86_l_5fe5;
	case 24556ULL: goto x86_l_5fec;
	case 24558ULL: goto x86_l_5fee;
	case 24560ULL: goto x86_l_5ff0;
	case 24566ULL: goto x86_l_5ff6;
	case 24568ULL: goto x86_l_5ff8;
	case 24575ULL: goto x86_l_5fff;
	case 24580ULL: goto x86_l_6004;
	case 24587ULL: goto x86_l_600b;
	case 24590ULL: goto x86_l_600e;
	case 24592ULL: goto x86_l_6010;
	case 24597ULL: goto x86_l_6015;
	case 24599ULL: goto x86_l_6017;
	case 24604ULL: goto x86_l_601c;
	case 24611ULL: goto x86_l_6023;
	case 24613ULL: goto x86_l_6025;
	case 24614ULL: goto x86_l_6026;
	case 24619ULL: goto x86_l_602b;
	case 24629ULL: goto x86_l_6035;
	case 24637ULL: goto x86_l_603d;
	case 24647ULL: goto x86_l_6047;
	case 24655ULL: goto x86_l_604f;
	case 24665ULL: goto x86_l_6059;
	case 24673ULL: goto x86_l_6061;
	case 24683ULL: goto x86_l_606b;
	case 24691ULL: goto x86_l_6073;
	case 24701ULL: goto x86_l_607d;
	case 24709ULL: goto x86_l_6085;
	case 24719ULL: goto x86_l_608f;
	case 24727ULL: goto x86_l_6097;
	case 24735ULL: goto x86_l_609f;
	case 24740ULL: goto x86_l_60a4;
	case 24745ULL: goto x86_l_60a9;
	case 24750ULL: goto x86_l_60ae;
	case 24753ULL: goto x86_l_60b1;
	case 24755ULL: goto x86_l_60b3;
	case 24757ULL: goto x86_l_60b5;
	case 24762ULL: goto x86_l_60ba;
	case 24772ULL: goto x86_l_60c4;
	case 24780ULL: goto x86_l_60cc;
	case 24790ULL: goto x86_l_60d6;
	case 24798ULL: goto x86_l_60de;
	case 24808ULL: goto x86_l_60e8;
	case 24816ULL: goto x86_l_60f0;
	case 24826ULL: goto x86_l_60fa;
	case 24834ULL: goto x86_l_6102;
	case 24844ULL: goto x86_l_610c;
	case 24852ULL: goto x86_l_6114;
	case 24862ULL: goto x86_l_611e;
	case 24870ULL: goto x86_l_6126;
	case 24878ULL: goto x86_l_612e;
	case 24883ULL: goto x86_l_6133;
	case 24888ULL: goto x86_l_6138;
	case 24892ULL: goto x86_l_613c;
	case 24897ULL: goto x86_l_6141;
	case 24899ULL: goto x86_l_6143;
	case 24901ULL: goto x86_l_6145;
	case 24906ULL: goto x86_l_614a;
	case 24916ULL: goto x86_l_6154;
	case 24921ULL: goto x86_l_6159;
	case 24931ULL: goto x86_l_6163;
	case 24936ULL: goto x86_l_6168;
	case 24946ULL: goto x86_l_6172;
	case 24951ULL: goto x86_l_6177;
	case 24961ULL: goto x86_l_6181;
	case 24966ULL: goto x86_l_6186;
	case 24976ULL: goto x86_l_6190;
	case 24981ULL: goto x86_l_6195;
	case 24991ULL: goto x86_l_619f;
	case 24996ULL: goto x86_l_61a4;
	case 25004ULL: goto x86_l_61ac;
	case 25009ULL: goto x86_l_61b1;
	case 25014ULL: goto x86_l_61b6;
	case 25019ULL: goto x86_l_61bb;
	case 25027ULL: goto x86_l_61c3;
	case 25032ULL: goto x86_l_61c8;
	case 25034ULL: goto x86_l_61ca;
	case 25036ULL: goto x86_l_61cc;
	case 25041ULL: goto x86_l_61d1;
	case 25048ULL: goto x86_l_61d8;
	case 25051ULL: goto x86_l_61db;
	case 25057ULL: goto x86_l_61e1;
	case 25067ULL: goto x86_l_61eb;
	case 25072ULL: goto x86_l_61f0;
	case 25082ULL: goto x86_l_61fa;
	case 25087ULL: goto x86_l_61ff;
	case 25097ULL: goto x86_l_6209;
	case 25102ULL: goto x86_l_620e;
	case 25112ULL: goto x86_l_6218;
	case 25117ULL: goto x86_l_621d;
	case 25127ULL: goto x86_l_6227;
	case 25132ULL: goto x86_l_622c;
	case 25140ULL: goto x86_l_6234;
	case 25145ULL: goto x86_l_6239;
	case 25150ULL: goto x86_l_623e;
	case 25155ULL: goto x86_l_6243;
	case 25160ULL: goto x86_l_6248;
	case 25167ULL: goto x86_l_624f;
	case 25170ULL: goto x86_l_6252;
	case 25176ULL: goto x86_l_6258;
	case 25183ULL: goto x86_l_625f;
	case 25186ULL: goto x86_l_6262;
	case 25192ULL: goto x86_l_6268;
	case 25199ULL: goto x86_l_626f;
	case 25207ULL: goto x86_l_6277;
	case 25212ULL: goto x86_l_627c;
	case 25214ULL: goto x86_l_627e;
	case 25219ULL: goto x86_l_6283;
	case 25222ULL: goto x86_l_6286;
	case 25228ULL: goto x86_l_628c;
	case 25233ULL: goto x86_l_6291;
	case 25236ULL: goto x86_l_6294;
	case 25240ULL: goto x86_l_6298;
	case 25242ULL: goto x86_l_629a;
	case 25244ULL: goto x86_l_629c;
	case 25251ULL: goto x86_l_62a3;
	case 25254ULL: goto x86_l_62a6;
	case 25260ULL: goto x86_l_62ac;
	case 25262ULL: goto x86_l_62ae;
	case 25265ULL: goto x86_l_62b1;
	case 25268ULL: goto x86_l_62b4;
	case 25271ULL: goto x86_l_62b7;
	case 25273ULL: goto x86_l_62b9;
	case 25275ULL: goto x86_l_62bb;
	case 25277ULL: goto x86_l_62bd;
	case 25280ULL: goto x86_l_62c0;
	case 25283ULL: goto x86_l_62c3;
	case 25285ULL: goto x86_l_62c5;
	case 25288ULL: goto x86_l_62c8;
	case 25295ULL: goto x86_l_62cf;
	case 25298ULL: goto x86_l_62d2;
	case 25304ULL: goto x86_l_62d8;
	case 25309ULL: goto x86_l_62dd;
	case 25312ULL: goto x86_l_62e0;
	case 25314ULL: goto x86_l_62e2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5bd2:
	/* 0x5bd2: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_5bd6:
	/* 0x5bd6: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5bda:
	/* 0x5bda: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5bdd:
	/* 0x5bdd: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5be1:
	/* 0x5be1: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_5be4:
	/* 0x5be4: jae    5e4f <kprobe_unwind_native+0x5e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5e4f;
	}
x86_l_5bea:
	/* 0x5bea: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5bee:
	/* 0x5bee: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5bf1:
	/* 0x5bf1: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5bf3:
	/* 0x5bf3: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5bf7:
	/* 0x5bf7: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5bfc:
	/* 0x5bfc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5c01:
	/* 0x5c01: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5c06:
	/* 0x5c06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c08:
	/* 0x5c08: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5c0b:
	/* 0x5c0b: je     61d1 <kprobe_unwind_native+0x61d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61d1;
	}
x86_l_5c11:
	/* 0x5c11: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c15:
	/* 0x5c15: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5c18:
	/* 0x5c18: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c1d:
	/* 0x5c1d: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c20:
	/* 0x5c20: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_5c24:
	/* 0x5c24: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c28:
	/* 0x5c28: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5c2b:
	/* 0x5c2b: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c2f:
	/* 0x5c2f: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_5c31:
	/* 0x5c31: jae    5e4f <kprobe_unwind_native+0x5e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5e4f;
	}
x86_l_5c37:
	/* 0x5c37: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c3b:
	/* 0x5c3b: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5c3d:
	/* 0x5c3d: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5c3f:
	/* 0x5c3f: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c43:
	/* 0x5c43: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c48:
	/* 0x5c48: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5c4d:
	/* 0x5c4d: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5c52:
	/* 0x5c52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c54:
	/* 0x5c54: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5c57:
	/* 0x5c57: je     61d1 <kprobe_unwind_native+0x61d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61d1;
	}
x86_l_5c5d:
	/* 0x5c5d: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c61:
	/* 0x5c61: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5c65:
	/* 0x5c65: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c6a:
	/* 0x5c6a: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c6d:
	/* 0x5c6d: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_5c71:
	/* 0x5c71: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c75:
	/* 0x5c75: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5c78:
	/* 0x5c78: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c7c:
	/* 0x5c7c: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_5c7f:
	/* 0x5c7f: jae    5e4f <kprobe_unwind_native+0x5e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5e4f;
	}
x86_l_5c85:
	/* 0x5c85: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c89:
	/* 0x5c89: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5c8c:
	/* 0x5c8c: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5c8e:
	/* 0x5c8e: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c92:
	/* 0x5c92: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c97:
	/* 0x5c97: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5c9c:
	/* 0x5c9c: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5ca1:
	/* 0x5ca1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ca3:
	/* 0x5ca3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5ca6:
	/* 0x5ca6: je     61d1 <kprobe_unwind_native+0x61d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61d1;
	}
x86_l_5cac:
	/* 0x5cac: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5cb0:
	/* 0x5cb0: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5cb3:
	/* 0x5cb3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cb8:
	/* 0x5cb8: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cbb:
	/* 0x5cbb: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_5cbf:
	/* 0x5cbf: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cc3:
	/* 0x5cc3: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5cc6:
	/* 0x5cc6: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cca:
	/* 0x5cca: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_5ccc:
	/* 0x5ccc: jae    5e4f <kprobe_unwind_native+0x5e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5e4f;
	}
x86_l_5cd2:
	/* 0x5cd2: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cd6:
	/* 0x5cd6: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5cd8:
	/* 0x5cd8: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5cda:
	/* 0x5cda: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5cde:
	/* 0x5cde: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ce3:
	/* 0x5ce3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5ce8:
	/* 0x5ce8: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5ced:
	/* 0x5ced: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cef:
	/* 0x5cef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5cf2:
	/* 0x5cf2: je     61d1 <kprobe_unwind_native+0x61d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61d1;
	}
x86_l_5cf8:
	/* 0x5cf8: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5cfc:
	/* 0x5cfc: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5d00:
	/* 0x5d00: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d05:
	/* 0x5d05: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d08:
	/* 0x5d08: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_5d0c:
	/* 0x5d0c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d10:
	/* 0x5d10: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5d13:
	/* 0x5d13: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d17:
	/* 0x5d17: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_5d1a:
	/* 0x5d1a: jae    5e4f <kprobe_unwind_native+0x5e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5e4f;
	}
x86_l_5d20:
	/* 0x5d20: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d24:
	/* 0x5d24: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5d27:
	/* 0x5d27: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5d29:
	/* 0x5d29: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d2d:
	/* 0x5d2d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d32:
	/* 0x5d32: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5d37:
	/* 0x5d37: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5d3c:
	/* 0x5d3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d3e:
	/* 0x5d3e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5d41:
	/* 0x5d41: je     61d1 <kprobe_unwind_native+0x61d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61d1;
	}
x86_l_5d47:
	/* 0x5d47: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d4b:
	/* 0x5d4b: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5d4e:
	/* 0x5d4e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d53:
	/* 0x5d53: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d56:
	/* 0x5d56: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_5d5a:
	/* 0x5d5a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d5e:
	/* 0x5d5e: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5d61:
	/* 0x5d61: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d65:
	/* 0x5d65: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_5d67:
	/* 0x5d67: jae    5e4f <kprobe_unwind_native+0x5e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5e4f;
	}
x86_l_5d6d:
	/* 0x5d6d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d71:
	/* 0x5d71: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5d73:
	/* 0x5d73: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5d75:
	/* 0x5d75: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d79:
	/* 0x5d79: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d7e:
	/* 0x5d7e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5d83:
	/* 0x5d83: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5d88:
	/* 0x5d88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d8a:
	/* 0x5d8a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5d8d:
	/* 0x5d8d: je     61d1 <kprobe_unwind_native+0x61d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61d1;
	}
x86_l_5d93:
	/* 0x5d93: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d97:
	/* 0x5d97: lea    r13d,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5d9b:
	/* 0x5d9b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5da0:
	/* 0x5da0: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5da3:
	/* 0x5da3: cmova  r13d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_5da7:
	/* 0x5da7: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5dab:
	/* 0x5dab: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5dae:
	/* 0x5dae: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5db2:
	/* 0x5db2: cmp    r13d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_5db5:
	/* 0x5db5: jae    5e4f <kprobe_unwind_native+0x5e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5e4f;
	}
x86_l_5dbb:
	/* 0x5dbb: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5dbf:
	/* 0x5dbf: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5dc2:
	/* 0x5dc2: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5dc4:
	/* 0x5dc4: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5dc8:
	/* 0x5dc8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5dcd:
	/* 0x5dcd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5dd2:
	/* 0x5dd2: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5dd7:
	/* 0x5dd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5dd9:
	/* 0x5dd9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5ddc:
	/* 0x5ddc: je     61d1 <kprobe_unwind_native+0x61d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61d1;
	}
x86_l_5de2:
	/* 0x5de2: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5de6:
	/* 0x5de6: lea    ebp,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5de9:
	/* 0x5de9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dee:
	/* 0x5dee: cmp    WORD PTR [rax],dx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5df1:
	/* 0x5df1: cmova  ebp,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R13, X86_WIDTH_32, X86_CC_A);
x86_l_5df5:
	/* 0x5df5: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5df9:
	/* 0x5df9: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5dfc:
	/* 0x5dfc: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e00:
	/* 0x5e00: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_5e02:
	/* 0x5e02: jae    5e4f <kprobe_unwind_native+0x5e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5e4f;
	}
x86_l_5e04:
	/* 0x5e04: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e08:
	/* 0x5e08: add    eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5e0a:
	/* 0x5e0a: shr    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_5e0c:
	/* 0x5e0c: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e10:
	/* 0x5e10: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e15:
	/* 0x5e15: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5e1a:
	/* 0x5e1a: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5e1f:
	/* 0x5e1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e21:
	/* 0x5e21: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5e24:
	/* 0x5e24: je     61d1 <kprobe_unwind_native+0x61d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61d1;
	}
x86_l_5e2a:
	/* 0x5e2a: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e2e:
	/* 0x5e2e: lea    edx,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_5e31:
	/* 0x5e31: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e36:
	/* 0x5e36: cmp    WORD PTR [rax],si */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e39:
	/* 0x5e39: cmova  edx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RBP, X86_WIDTH_32, X86_CC_A);
x86_l_5e3c:
	/* 0x5e3c: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e40:
	/* 0x5e40: cmova  eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_A);
x86_l_5e43:
	/* 0x5e43: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e47:
	/* 0x5e47: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_5e49:
	/* 0x5e49: jb     61d1 <kprobe_unwind_native+0x61d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_61d1;
	}
x86_l_5e4f:
	/* 0x5e4f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e53:
	/* 0x5e53: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_5e56:
	/* 0x5e56: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5e58:
	/* 0x5e58: je     61d1 <kprobe_unwind_native+0x61d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61d1;
	}
x86_l_5e5e:
	/* 0x5e5e: dec    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_5e61:
	/* 0x5e61: mov    DWORD PTR [rsp+0x90],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_5e69:
	/* 0x5e69: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_5e71:
	/* 0x5e71: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5e76:
	/* 0x5e76: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5e7b:
	/* 0x5e7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e7d:
	/* 0x5e7d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5e80:
	/* 0x5e80: mov    ecx,0xfa4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4004ULL);
x86_l_5e85:
	/* 0x5e85: mov    edx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_5e8a:
	/* 0x5e8a: je     42e8 <kprobe_unwind_native+0x42e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17128ULL;
	}
x86_l_5e90:
	/* 0x5e90: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_5e93:
	/* 0x5e93: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5e9a:
	/* 0x5e9a: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e9d:
	/* 0x5e9d: jne    68af <kprobe_unwind_native+0x68af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 26799ULL;
	}
x86_l_5ea3:
	/* 0x5ea3: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_5ea8:
	/* 0x5ea8: movzx  ecx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5eac:
	/* 0x5eac: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5eae:
	/* 0x5eae: mov    ecx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_5eb5:
	/* 0x5eb5: lea    r13d,[rax+0x10000] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 65536ULL);
x86_l_5ebc:
	/* 0x5ebc: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5ec1:
	/* 0x5ec1: cmp    ecx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_5ec3:
	/* 0x5ec3: cmovae r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_AE);
x86_l_5ec7:
	/* 0x5ec7: movzx  eax,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_5ecb:
	/* 0x5ecb: mov    DWORD PTR [rsp+0x8c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_5ed2:
	/* 0x5ed2: mov    edx,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_5ed7:
	/* 0x5ed7: mov    ecx,0xfa5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4005ULL);
x86_l_5edc:
	/* 0x5edc: cmp    eax,0x8000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32768ULL);
x86_l_5ee1:
	/* 0x5ee1: je     42e8 <kprobe_unwind_native+0x42e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17128ULL;
	}
x86_l_5ee7:
	/* 0x5ee7: cmp    eax,0x8001 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32769ULL);
x86_l_5eec:
	/* 0x5eec: jne    625f <kprobe_unwind_native+0x625f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_625f;
	}
x86_l_5ef2:
	/* 0x5ef2: mov    DWORD PTR [rsp+0x94],0x7 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159815ULL);
x86_l_5efd:
	/* 0x5efd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_5f04:
	/* 0x5f04: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_5f0c:
	/* 0x5f0c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5f11:
	/* 0x5f11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f13:
	/* 0x5f13: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5f16:
	/* 0x5f16: je     6248 <kprobe_unwind_native+0x6248> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6248;
	}
x86_l_5f1c:
	/* 0x5f1c: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_5f1f:
	/* 0x5f1f: jmp    6258 <kprobe_unwind_native+0x6258> */
	goto x86_l_6258;
x86_l_5f24:
	/* 0x5f24: mov    r13d,0xfa2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4002ULL);
x86_l_5f2a:
	/* 0x5f2a: mov    r14d,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 50ULL);
x86_l_5f30:
	/* 0x5f30: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5f37:
	/* 0x5f37: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f3a:
	/* 0x5f3a: jne    614a <kprobe_unwind_native+0x614a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_614a;
	}
x86_l_5f40:
	/* 0x5f40: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5f45:
	/* 0x5f45: mov    DWORD PTR [rbx+0xf28],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3880ULL);
x86_l_5f4c:
	/* 0x5f4c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f4f:
	/* 0x5f4f: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_5f52:
	/* 0x5f52: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_5f59:
	/* 0x5f59: mov    DWORD PTR [rbx+0xf2c],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3884ULL);
x86_l_5f60:
	/* 0x5f60: mov    DWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_5f6b:
	/* 0x5f6b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&per_cpu_records)));
x86_l_5f72:
	/* 0x5f72: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_5f7a:
	/* 0x5f7a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5f7f:
	/* 0x5f7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f81:
	/* 0x5f81: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5f84:
	/* 0x5f84: je     5fc7 <kprobe_unwind_native+0x5fc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5fc7;
	}
x86_l_5f86:
	/* 0x5f86: movzx  ecx,BYTE PTR [rax+0x1384] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4996ULL);
x86_l_5f8d:
	/* 0x5f8d: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_5f90:
	/* 0x5f90: cmp    cl,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_5f93:
	/* 0x5f93: jb     5fee <kprobe_unwind_native+0x5fee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5fee;
	}
x86_l_5f95:
	/* 0x5f95: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_5f98:
	/* 0x5f98: mov    DWORD PTR [rax+0xf2c],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16681652977669ULL);
x86_l_5fa2:
	/* 0x5fa2: mov    DWORD PTR [rsp+0x10],0x44 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476804ULL);
x86_l_5faa:
	/* 0x5faa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_5fb1:
	/* 0x5fb1: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5fb6:
	/* 0x5fb6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5fbb:
	/* 0x5fbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fbd:
	/* 0x5fbd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5fc0:
	/* 0x5fc0: je     5fd7 <kprobe_unwind_native+0x5fd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5fd7;
	}
x86_l_5fc2:
	/* 0x5fc2: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_5fc5:
	/* 0x5fc5: jmp    5fe2 <kprobe_unwind_native+0x5fe2> */
	goto x86_l_5fe2;
x86_l_5fc7:
	/* 0x5fc7: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&perf_progs)));
x86_l_5fce:
	/* 0x5fce: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5fd0:
	/* 0x5fd0: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_5fd5:
	/* 0x5fd5: jmp    6004 <kprobe_unwind_native+0x6004> */
	goto x86_l_6004;
x86_l_5fd7:
	/* 0x5fd7: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5fdc:
	/* 0x5fdc: jne    60ba <kprobe_unwind_native+0x60ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_60ba;
	}
x86_l_5fe2:
	/* 0x5fe2: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_5fe5:
	/* 0x5fe5: movzx  ecx,BYTE PTR [rbx+0x1384] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4996ULL);
x86_l_5fec:
	/* 0x5fec: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5fee:
	/* 0x5fee: inc    cl */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_INC, 1);
x86_l_5ff0:
	/* 0x5ff0: mov    BYTE PTR [rax+0x1384],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4996ULL);
x86_l_5ff6:
	/* 0x5ff6: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_5ff8:
	/* 0x5ff8: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&perf_progs)));
x86_l_5fff:
	/* 0x5fff: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_6004:
	/* 0x6004: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&perf_progs)));
x86_l_600b:
	/* 0x600b: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_600e:
	/* 0x600e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6010:
	/* 0x6010: cmp    DWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6015:
	/* 0x6015: jne    602b <kprobe_unwind_native+0x602b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_602b;
	}
x86_l_6017:
	/* 0x6017: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_601c:
	/* 0x601c: add    rsp,0x168 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 360ULL);
x86_l_6023:
	/* 0x6023: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_6025:
	/* 0x6025: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_6026:
	/* 0x6026: jmp    764b <kprobe_unwind_native+0x764b> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_602b:
	/* 0x602b: movabs rax,0xa65766974616e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926309016887662ULL);
x86_l_6035:
	/* 0x6035: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_603d:
	/* 0x603d: movabs rax,0x616e5f646e69776e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7020653754070955886ULL);
x86_l_6047:
	/* 0x6047: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_604f:
	/* 0x604f: movabs rax,0x75206e6920642520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8439867099486364960ULL);
x86_l_6059:
	/* 0x6059: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_6061:
	/* 0x6061: movabs rax,0x726f662064656c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732048022633ULL);
x86_l_606b:
	/* 0x606b: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_6073:
	/* 0x6073: movabs rax,0x6166206c6c616320 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332719350375200ULL);
x86_l_607d:
	/* 0x607d: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_6085:
	/* 0x6085: movabs rax,0x6c6961745f667062 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7811882181095485538ULL);
x86_l_608f:
	/* 0x608f: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_6097:
	/* 0x6097: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_609f:
	/* 0x609f: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_60a4:
	/* 0x60a4: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_60a9:
	/* 0x60a9: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_60ae:
	/* 0x60ae: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_60b1:
	/* 0x60b1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_60b3:
	/* 0x60b3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_60b5:
	/* 0x60b5: jmp    6017 <kprobe_unwind_native+0x6017> */
	goto x86_l_6017;
x86_l_60ba:
	/* 0x60ba: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_60c4:
	/* 0x60c4: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_60cc:
	/* 0x60cc: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_60d6:
	/* 0x60d6: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_60de:
	/* 0x60de: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_60e8:
	/* 0x60e8: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_60f0:
	/* 0x60f0: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_60fa:
	/* 0x60fa: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_6102:
	/* 0x6102: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_610c:
	/* 0x610c: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_6114:
	/* 0x6114: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_611e:
	/* 0x611e: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_6126:
	/* 0x6126: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_612e:
	/* 0x612e: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_6133:
	/* 0x6133: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6138:
	/* 0x6138: mov    edx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_613c:
	/* 0x613c: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_6141:
	/* 0x6141: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6143:
	/* 0x6143: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6145:
	/* 0x6145: jmp    5fe2 <kprobe_unwind_native+0x5fe2> */
	goto x86_l_5fe2;
x86_l_614a:
	/* 0x614a: movabs rax,0x6c25206e6f697463 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7792670388922184803ULL);
x86_l_6154:
	/* 0x6154: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6159:
	/* 0x6159: movabs rax,0x6573207478657420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310222304760656928ULL);
x86_l_6163:
	/* 0x6163: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6168:
	/* 0x6168: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_6172:
	/* 0x6172: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6177:
	/* 0x6177: movabs rax,0x72656e6e69207075 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243116113460752501ULL);
x86_l_6181:
	/* 0x6181: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6186:
	/* 0x6186: movabs rax,0x206b6f6f6c206f74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2336083356067852148ULL);
x86_l_6190:
	/* 0x6190: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6195:
	/* 0x6195: movabs rax,0x206572756c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334397830517055814ULL);
x86_l_619f:
	/* 0x619f: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_61a4:
	/* 0x61a4: mov    DWORD PTR [rsp+0x3f],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 270583625836ULL);
x86_l_61ac:
	/* 0x61ac: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_61b1:
	/* 0x61b1: mov    eax,0x33 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_61b6:
	/* 0x61b6: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_61bb:
	/* 0x61bb: mov    rdx,QWORD PTR [rsp+0x160] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 352ULL);
x86_l_61c3:
	/* 0x61c3: mov    esi,0x33 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 51ULL);
x86_l_61c8:
	/* 0x61c8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_61ca:
	/* 0x61ca: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_61cc:
	/* 0x61cc: jmp    5f40 <kprobe_unwind_native+0x5f40> */
	goto x86_l_5f40;
x86_l_61d1:
	/* 0x61d1: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_61d8:
	/* 0x61d8: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_61db:
	/* 0x61db: je     2722 <kprobe_unwind_native+0x2722> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10018ULL;
	}
x86_l_61e1:
	/* 0x61e1: movabs rax,0x6174616420747075 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7022344801646571637ULL);
x86_l_61eb:
	/* 0x61eb: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_61f0:
	/* 0x61f0: movabs rax,0x72726f43202e7370 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8246776201762206576ULL);
x86_l_61fa:
	/* 0x61fa: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_61ff:
	/* 0x61ff: movabs rax,0x657473203631206e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310594677314494574ULL);
x86_l_6209:
	/* 0x6209: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_620e:
	/* 0x620e: movabs rax,0x6920686372616573 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7575169349567210867ULL);
x86_l_6218:
	/* 0x6218: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_621d:
	/* 0x621d: movabs rax,0x622064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7070761801744998726ULL);
x86_l_6227:
	/* 0x6227: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_622c:
	/* 0x622c: mov    DWORD PTR [rsp+0x37],0xa3f61 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 236223872865ULL);
x86_l_6234:
	/* 0x6234: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6239:
	/* 0x6239: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_623e:
	/* 0x623e: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6243:
	/* 0x6243: jmp    2d4d <kprobe_unwind_native+0x2d4d> */
	return 11597ULL;
x86_l_6248:
	/* 0x6248: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_624f:
	/* 0x624f: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6252:
	/* 0x6252: jne    6a3c <kprobe_unwind_native+0x6a3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 27196ULL;
	}
x86_l_6258:
	/* 0x6258: mov    eax,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_625f:
	/* 0x625f: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_6262:
	/* 0x6262: js     63dc <kprobe_unwind_native+0x63dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 25564ULL;
	}
x86_l_6268:
	/* 0x6268: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&unwind_info_array)));
x86_l_626f:
	/* 0x626f: lea    rsi,[rsp+0x8c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_6277:
	/* 0x6277: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_627c:
	/* 0x627c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_627e:
	/* 0x627e: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6283:
	/* 0x6283: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6286:
	/* 0x6286: je     6315 <kprobe_unwind_native+0x6315> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25365ULL;
	}
x86_l_628c:
	/* 0x628c: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6291:
	/* 0x6291: mov    ebp,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_6294:
	/* 0x6294: movzx  eax,BYTE PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_6298:
	/* 0x6298: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_629a:
	/* 0x629a: je     62d8 <kprobe_unwind_native+0x62d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_62d8;
	}
x86_l_629c:
	/* 0x629c: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_62a3:
	/* 0x62a3: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62a6:
	/* 0x62a6: jne    69c8 <kprobe_unwind_native+0x69c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 27080ULL;
	}
x86_l_62ac:
	/* 0x62ac: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_62ae:
	/* 0x62ae: and    cl,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_62b1:
	/* 0x62b1: movzx  ecx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_62b4:
	/* 0x62b4: cmp    r13d,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RCX, X86_WIDTH_32);
x86_l_62b7:
	/* 0x62b7: jl     62d8 <kprobe_unwind_native+0x62d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_62d8;
	}
x86_l_62b9:
	/* 0x62b9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_62bb:
	/* 0x62bb: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_62bd:
	/* 0x62bd: setns  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NS);
x86_l_62c0:
	/* 0x62c0: shl    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_62c3:
	/* 0x62c3: add    ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_62c5:
	/* 0x62c5: add    ebp,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4294967288ULL);
x86_l_62c8:
	/* 0x62c8: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_62cf:
	/* 0x62cf: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62d2:
	/* 0x62d2: jne    6aba <kprobe_unwind_native+0x6aba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 27322ULL;
	}
x86_l_62d8:
	/* 0x62d8: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_62dd:
	/* 0x62dd: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_62e0:
	/* 0x62e0: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_62e2:
	/* 0x62e2: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
	return 25317ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 25317ULL: goto x86_l_62e5;
	case 25319ULL: goto x86_l_62e7;
	case 25322ULL: goto x86_l_62ea;
	case 25324ULL: goto x86_l_62ec;
	case 25327ULL: goto x86_l_62ef;
	case 25330ULL: goto x86_l_62f2;
	case 25333ULL: goto x86_l_62f5;
	case 25339ULL: goto x86_l_62fb;
	case 25342ULL: goto x86_l_62fe;
	case 25348ULL: goto x86_l_6304;
	case 25351ULL: goto x86_l_6307;
	case 25354ULL: goto x86_l_630a;
	case 25360ULL: goto x86_l_6310;
	case 25365ULL: goto x86_l_6315;
	case 25373ULL: goto x86_l_631d;
	case 25380ULL: goto x86_l_6324;
	case 25385ULL: goto x86_l_6329;
	case 25390ULL: goto x86_l_632e;
	case 25392ULL: goto x86_l_6330;
	case 25395ULL: goto x86_l_6333;
	case 25397ULL: goto x86_l_6335;
	case 25400ULL: goto x86_l_6338;
	case 25405ULL: goto x86_l_633d;
	case 25407ULL: goto x86_l_633f;
	case 25414ULL: goto x86_l_6346;
	case 25417ULL: goto x86_l_6349;
	case 25422ULL: goto x86_l_634e;
	case 25424ULL: goto x86_l_6350;
	case 25430ULL: goto x86_l_6356;
	case 25435ULL: goto x86_l_635b;
	case 25445ULL: goto x86_l_6365;
	case 25450ULL: goto x86_l_636a;
	case 25460ULL: goto x86_l_6374;
	case 25465ULL: goto x86_l_6379;
	case 25475ULL: goto x86_l_6383;
	case 25480ULL: goto x86_l_6388;
	case 25490ULL: goto x86_l_6392;
	case 25495ULL: goto x86_l_6397;
	case 25505ULL: goto x86_l_63a1;
	case 25510ULL: goto x86_l_63a6;
	case 25520ULL: goto x86_l_63b0;
	case 25525ULL: goto x86_l_63b5;
	case 25530ULL: goto x86_l_63ba;
	case 25535ULL: goto x86_l_63bf;
	case 25540ULL: goto x86_l_63c4;
	case 25544ULL: goto x86_l_63c8;
	case 25549ULL: goto x86_l_63cd;
	case 25551ULL: goto x86_l_63cf;
	case 25553ULL: goto x86_l_63d1;
	case 25559ULL: goto x86_l_63d7;
	case 25564ULL: goto x86_l_63dc;
	case 25569ULL: goto x86_l_63e1;
	case 25575ULL: goto x86_l_63e7;
	case 25578ULL: goto x86_l_63ea;
	case 25584ULL: goto x86_l_63f0;
	case 25587ULL: goto x86_l_63f3;
	case 25592ULL: goto x86_l_63f8;
	case 25600ULL: goto x86_l_6400;
	case 25602ULL: goto x86_l_6402;
	case 25605ULL: goto x86_l_6405;
	case 25611ULL: goto x86_l_640b;
	case 25614ULL: goto x86_l_640e;
	case 25617ULL: goto x86_l_6411;
	case 25619ULL: goto x86_l_6413;
	case 25622ULL: goto x86_l_6416;
	case 25624ULL: goto x86_l_6418;
	case 25627ULL: goto x86_l_641b;
	case 25630ULL: goto x86_l_641e;
	case 25634ULL: goto x86_l_6422;
	case 25638ULL: goto x86_l_6426;
	case 25645ULL: goto x86_l_642d;
	case 25648ULL: goto x86_l_6430;
	case 25654ULL: goto x86_l_6436;
	case 25664ULL: goto x86_l_6440;
	case 25669ULL: goto x86_l_6445;
	case 25679ULL: goto x86_l_644f;
	case 25684ULL: goto x86_l_6454;
	case 25689ULL: goto x86_l_6459;
	case 25694ULL: goto x86_l_645e;
	case 25699ULL: goto x86_l_6463;
	case 25704ULL: goto x86_l_6468;
	case 25707ULL: goto x86_l_646b;
	case 25709ULL: goto x86_l_646d;
	case 25711ULL: goto x86_l_646f;
	case 25716ULL: goto x86_l_6474;
	case 25719ULL: goto x86_l_6477;
	case 25724ULL: goto x86_l_647c;
	case 25727ULL: goto x86_l_647f;
	case 25733ULL: goto x86_l_6485;
	case 25736ULL: goto x86_l_6488;
	case 25741ULL: goto x86_l_648d;
	case 25746ULL: goto x86_l_6492;
	case 25752ULL: goto x86_l_6498;
	case 25755ULL: goto x86_l_649b;
	case 25760ULL: goto x86_l_64a0;
	case 25765ULL: goto x86_l_64a5;
	case 25771ULL: goto x86_l_64ab;
	case 25774ULL: goto x86_l_64ae;
	case 25779ULL: goto x86_l_64b3;
	case 25782ULL: goto x86_l_64b6;
	case 25785ULL: goto x86_l_64b9;
	case 25791ULL: goto x86_l_64bf;
	case 25798ULL: goto x86_l_64c6;
	case 25802ULL: goto x86_l_64ca;
	case 25809ULL: goto x86_l_64d1;
	case 25814ULL: goto x86_l_64d6;
	case 25821ULL: goto x86_l_64dd;
	case 25826ULL: goto x86_l_64e2;
	case 25833ULL: goto x86_l_64e9;
	case 25838ULL: goto x86_l_64ee;
	case 25841ULL: goto x86_l_64f1;
	case 25847ULL: goto x86_l_64f7;
	case 25850ULL: goto x86_l_64fa;
	case 25856ULL: goto x86_l_6500;
	case 25858ULL: goto x86_l_6502;
	case 25860ULL: goto x86_l_6504;
	case 25863ULL: goto x86_l_6507;
	case 25865ULL: goto x86_l_6509;
	case 25870ULL: goto x86_l_650e;
	case 25877ULL: goto x86_l_6515;
	case 25880ULL: goto x86_l_6518;
	case 25886ULL: goto x86_l_651e;
	case 25889ULL: goto x86_l_6521;
	case 25892ULL: goto x86_l_6524;
	case 25895ULL: goto x86_l_6527;
	case 25901ULL: goto x86_l_652d;
	case 25909ULL: goto x86_l_6535;
	case 25911ULL: goto x86_l_6537;
	case 25917ULL: goto x86_l_653d;
	case 25920ULL: goto x86_l_6540;
	case 25926ULL: goto x86_l_6546;
	case 25934ULL: goto x86_l_654e;
	case 25939ULL: goto x86_l_6553;
	case 25942ULL: goto x86_l_6556;
	case 25946ULL: goto x86_l_655a;
	case 25954ULL: goto x86_l_6562;
	case 25959ULL: goto x86_l_6567;
	case 25965ULL: goto x86_l_656d;
	case 25968ULL: goto x86_l_6570;
	case 25972ULL: goto x86_l_6574;
	case 25977ULL: goto x86_l_6579;
	case 25980ULL: goto x86_l_657c;
	case 25983ULL: goto x86_l_657f;
	case 25988ULL: goto x86_l_6584;
	case 25994ULL: goto x86_l_658a;
	case 26002ULL: goto x86_l_6592;
	case 26009ULL: goto x86_l_6599;
	case 26017ULL: goto x86_l_65a1;
	case 26024ULL: goto x86_l_65a8;
	case 26032ULL: goto x86_l_65b0;
	case 26039ULL: goto x86_l_65b7;
	case 26047ULL: goto x86_l_65bf;
	case 26054ULL: goto x86_l_65c6;
	case 26062ULL: goto x86_l_65ce;
	case 26069ULL: goto x86_l_65d5;
	case 26077ULL: goto x86_l_65dd;
	case 26084ULL: goto x86_l_65e4;
	case 26092ULL: goto x86_l_65ec;
	case 26099ULL: goto x86_l_65f3;
	case 26107ULL: goto x86_l_65fb;
	case 26114ULL: goto x86_l_6602;
	case 26121ULL: goto x86_l_6609;
	case 26128ULL: goto x86_l_6610;
	case 26131ULL: goto x86_l_6613;
	case 26137ULL: goto x86_l_6619;
	case 26147ULL: goto x86_l_6623;
	case 26152ULL: goto x86_l_6628;
	case 26162ULL: goto x86_l_6632;
	case 26167ULL: goto x86_l_6637;
	case 26172ULL: goto x86_l_663c;
	case 26177ULL: goto x86_l_6641;
	case 26182ULL: goto x86_l_6646;
	case 26187ULL: goto x86_l_664b;
	case 26189ULL: goto x86_l_664d;
	case 26191ULL: goto x86_l_664f;
	case 26196ULL: goto x86_l_6654;
	case 26201ULL: goto x86_l_6659;
	case 26204ULL: goto x86_l_665c;
	case 26207ULL: goto x86_l_665f;
	case 26210ULL: goto x86_l_6662;
	case 26213ULL: goto x86_l_6665;
	case 26215ULL: goto x86_l_6667;
	case 26221ULL: goto x86_l_666d;
	case 26226ULL: goto x86_l_6672;
	case 26231ULL: goto x86_l_6677;
	case 26236ULL: goto x86_l_667c;
	case 26241ULL: goto x86_l_6681;
	case 26244ULL: goto x86_l_6684;
	case 26246ULL: goto x86_l_6686;
	case 26249ULL: goto x86_l_6689;
	case 26251ULL: goto x86_l_668b;
	case 26258ULL: goto x86_l_6692;
	case 26261ULL: goto x86_l_6695;
	case 26267ULL: goto x86_l_669b;
	case 26270ULL: goto x86_l_669e;
	case 26275ULL: goto x86_l_66a3;
	case 26278ULL: goto x86_l_66a6;
	case 26281ULL: goto x86_l_66a9;
	case 26286ULL: goto x86_l_66ae;
	case 26289ULL: goto x86_l_66b1;
	case 26294ULL: goto x86_l_66b6;
	case 26300ULL: goto x86_l_66bc;
	case 26310ULL: goto x86_l_66c6;
	case 26318ULL: goto x86_l_66ce;
	case 26328ULL: goto x86_l_66d8;
	case 26336ULL: goto x86_l_66e0;
	case 26346ULL: goto x86_l_66ea;
	case 26354ULL: goto x86_l_66f2;
	case 26365ULL: goto x86_l_66fd;
	case 26373ULL: goto x86_l_6705;
	case 26378ULL: goto x86_l_670a;
	case 26383ULL: goto x86_l_670f;
	case 26388ULL: goto x86_l_6714;
	case 26390ULL: goto x86_l_6716;
	case 26392ULL: goto x86_l_6718;
	case 26397ULL: goto x86_l_671d;
	case 26407ULL: goto x86_l_6727;
	case 26412ULL: goto x86_l_672c;
	case 26422ULL: goto x86_l_6736;
	case 26427ULL: goto x86_l_673b;
	case 26437ULL: goto x86_l_6745;
	case 26442ULL: goto x86_l_674a;
	case 26452ULL: goto x86_l_6754;
	case 26457ULL: goto x86_l_6759;
	case 26462ULL: goto x86_l_675e;
	case 26467ULL: goto x86_l_6763;
	case 26472ULL: goto x86_l_6768;
	case 26478ULL: goto x86_l_676e;
	case 26485ULL: goto x86_l_6775;
	case 26492ULL: goto x86_l_677c;
	case 26497ULL: goto x86_l_6781;
	case 26499ULL: goto x86_l_6783;
	case 26502ULL: goto x86_l_6786;
	case 26507ULL: goto x86_l_678b;
	case 26517ULL: goto x86_l_6795;
	case 26525ULL: goto x86_l_679d;
	case 26535ULL: goto x86_l_67a7;
	case 26543ULL: goto x86_l_67af;
	case 26553ULL: goto x86_l_67b9;
	case 26561ULL: goto x86_l_67c1;
	case 26571ULL: goto x86_l_67cb;
	case 26579ULL: goto x86_l_67d3;
	case 26589ULL: goto x86_l_67dd;
	case 26597ULL: goto x86_l_67e5;
	case 26607ULL: goto x86_l_67ef;
	case 26615ULL: goto x86_l_67f7;
	case 26623ULL: goto x86_l_67ff;
	case 26628ULL: goto x86_l_6804;
	case 26633ULL: goto x86_l_6809;
	case 26637ULL: goto x86_l_680d;
	case 26642ULL: goto x86_l_6812;
	case 26644ULL: goto x86_l_6814;
	case 26646ULL: goto x86_l_6816;
	case 26653ULL: goto x86_l_681d;
	case 26656ULL: goto x86_l_6820;
	case 26662ULL: goto x86_l_6826;
	case 26667ULL: goto x86_l_682b;
	case 26677ULL: goto x86_l_6835;
	case 26682ULL: goto x86_l_683a;
	case 26692ULL: goto x86_l_6844;
	case 26697ULL: goto x86_l_6849;
	case 26707ULL: goto x86_l_6853;
	case 26712ULL: goto x86_l_6858;
	case 26722ULL: goto x86_l_6862;
	case 26727ULL: goto x86_l_6867;
	case 26737ULL: goto x86_l_6871;
	case 26742ULL: goto x86_l_6876;
	case 26752ULL: goto x86_l_6880;
	case 26757ULL: goto x86_l_6885;
	case 26762ULL: goto x86_l_688a;
	case 26767ULL: goto x86_l_688f;
	case 26773ULL: goto x86_l_6895;
	case 26776ULL: goto x86_l_6898;
	case 26781ULL: goto x86_l_689d;
	case 26786ULL: goto x86_l_68a2;
	case 26789ULL: goto x86_l_68a5;
	case 26791ULL: goto x86_l_68a7;
	case 26794ULL: goto x86_l_68aa;
	case 26799ULL: goto x86_l_68af;
	case 26809ULL: goto x86_l_68b9;
	case 26814ULL: goto x86_l_68be;
	case 26824ULL: goto x86_l_68c8;
	case 26829ULL: goto x86_l_68cd;
	case 26839ULL: goto x86_l_68d7;
	case 26844ULL: goto x86_l_68dc;
	case 26854ULL: goto x86_l_68e6;
	case 26859ULL: goto x86_l_68eb;
	case 26869ULL: goto x86_l_68f5;
	case 26874ULL: goto x86_l_68fa;
	case 26884ULL: goto x86_l_6904;
	case 26889ULL: goto x86_l_6909;
	case 26894ULL: goto x86_l_690e;
	case 26899ULL: goto x86_l_6913;
	case 26905ULL: goto x86_l_6919;
	case 26912ULL: goto x86_l_6920;
	case 26916ULL: goto x86_l_6924;
	case 26921ULL: goto x86_l_6929;
	case 26926ULL: goto x86_l_692e;
	case 26928ULL: goto x86_l_6930;
	case 26931ULL: goto x86_l_6933;
	case 26936ULL: goto x86_l_6938;
	case 26946ULL: goto x86_l_6942;
	case 26954ULL: goto x86_l_694a;
	case 26964ULL: goto x86_l_6954;
	case 26972ULL: goto x86_l_695c;
	case 26982ULL: goto x86_l_6966;
	case 26990ULL: goto x86_l_696e;
	case 27000ULL: goto x86_l_6978;
	case 27008ULL: goto x86_l_6980;
	case 27018ULL: goto x86_l_698a;
	case 27026ULL: goto x86_l_6992;
	case 27036ULL: goto x86_l_699c;
	case 27044ULL: goto x86_l_69a4;
	case 27052ULL: goto x86_l_69ac;
	case 27057ULL: goto x86_l_69b1;
	case 27062ULL: goto x86_l_69b6;
	case 27066ULL: goto x86_l_69ba;
	case 27071ULL: goto x86_l_69bf;
	case 27073ULL: goto x86_l_69c1;
	case 27075ULL: goto x86_l_69c3;
	case 27080ULL: goto x86_l_69c8;
	case 27090ULL: goto x86_l_69d2;
	case 27095ULL: goto x86_l_69d7;
	case 27105ULL: goto x86_l_69e1;
	case 27110ULL: goto x86_l_69e6;
	case 27120ULL: goto x86_l_69f0;
	case 27125ULL: goto x86_l_69f5;
	case 27135ULL: goto x86_l_69ff;
	case 27140ULL: goto x86_l_6a04;
	case 27145ULL: goto x86_l_6a09;
	case 27150ULL: goto x86_l_6a0e;
	case 27155ULL: goto x86_l_6a13;
	case 27161ULL: goto x86_l_6a19;
	case 27166ULL: goto x86_l_6a1e;
	case 27172ULL: goto x86_l_6a24;
	case 27177ULL: goto x86_l_6a29;
	case 27180ULL: goto x86_l_6a2c;
	case 27182ULL: goto x86_l_6a2e;
	case 27185ULL: goto x86_l_6a31;
	case 27191ULL: goto x86_l_6a37;
	case 27196ULL: goto x86_l_6a3c;
	case 27206ULL: goto x86_l_6a46;
	case 27211ULL: goto x86_l_6a4b;
	case 27221ULL: goto x86_l_6a55;
	case 27226ULL: goto x86_l_6a5a;
	case 27236ULL: goto x86_l_6a64;
	case 27241ULL: goto x86_l_6a69;
	case 27251ULL: goto x86_l_6a73;
	case 27256ULL: goto x86_l_6a78;
	case 27266ULL: goto x86_l_6a82;
	case 27271ULL: goto x86_l_6a87;
	case 27281ULL: goto x86_l_6a91;
	case 27286ULL: goto x86_l_6a96;
	case 27291ULL: goto x86_l_6a9b;
	case 27296ULL: goto x86_l_6aa0;
	case 27301ULL: goto x86_l_6aa5;
	case 27308ULL: goto x86_l_6aac;
	case 27313ULL: goto x86_l_6ab1;
	case 27315ULL: goto x86_l_6ab3;
	case 27317ULL: goto x86_l_6ab5;
	case 27322ULL: goto x86_l_6aba;
	case 27332ULL: goto x86_l_6ac4;
	case 27337ULL: goto x86_l_6ac9;
	case 27347ULL: goto x86_l_6ad3;
	case 27352ULL: goto x86_l_6ad8;
	case 27362ULL: goto x86_l_6ae2;
	case 27367ULL: goto x86_l_6ae7;
	case 27377ULL: goto x86_l_6af1;
	case 27382ULL: goto x86_l_6af6;
	case 27387ULL: goto x86_l_6afb;
	case 27392ULL: goto x86_l_6b00;
	case 27397ULL: goto x86_l_6b05;
	case 27402ULL: goto x86_l_6b0a;
	case 27409ULL: goto x86_l_6b11;
	case 27414ULL: goto x86_l_6b16;
	case 27416ULL: goto x86_l_6b18;
	case 27418ULL: goto x86_l_6b1a;
	case 27423ULL: goto x86_l_6b1f;
	case 27433ULL: goto x86_l_6b29;
	case 27438ULL: goto x86_l_6b2e;
	case 27448ULL: goto x86_l_6b38;
	case 27453ULL: goto x86_l_6b3d;
	case 27458ULL: goto x86_l_6b42;
	case 27463ULL: goto x86_l_6b47;
	default: return 0xffffffffffffffffULL;
	}
x86_l_62e5:
	/* 0x62e5: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_62e7:
	/* 0x62e7: cmovns ecx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBP, X86_WIDTH_32, X86_CC_NS);
x86_l_62ea:
	/* 0x62ea: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_62ec:
	/* 0x62ec: and    edx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_62ef:
	/* 0x62ef: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_62f2:
	/* 0x62f2: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_62f5:
	/* 0x62f5: jg     64ee <kprobe_unwind_native+0x64ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_64ee;
	}
x86_l_62fb:
	/* 0x62fb: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_62fe:
	/* 0x62fe: je     665c <kprobe_unwind_native+0x665c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_665c;
	}
x86_l_6304:
	/* 0x6304: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_6307:
	/* 0x6307: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_630a:
	/* 0x630a: je     6659 <kprobe_unwind_native+0x6659> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6659;
	}
x86_l_6310:
	/* 0x6310: jmp    6b94 <kprobe_unwind_native+0x6b94> */
	return 27540ULL;
x86_l_6315:
	/* 0x6315: mov    DWORD PTR [rsp+0x78],0x55 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075605ULL);
x86_l_631d:
	/* 0x631d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_6324:
	/* 0x6324: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6329:
	/* 0x6329: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_632e:
	/* 0x632e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6330:
	/* 0x6330: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6333:
	/* 0x6333: je     633f <kprobe_unwind_native+0x633f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_633f;
	}
x86_l_6335:
	/* 0x6335: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6338:
	/* 0x6338: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_633d:
	/* 0x633d: jmp    6350 <kprobe_unwind_native+0x6350> */
	goto x86_l_6350;
x86_l_633f:
	/* 0x633f: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6346:
	/* 0x6346: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6349:
	/* 0x6349: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_634e:
	/* 0x634e: jne    635b <kprobe_unwind_native+0x635b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_635b;
	}
x86_l_6350:
	/* 0x6350: mov    r13d,0xfaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4015ULL);
x86_l_6356:
	/* 0x6356: jmp    5f4c <kprobe_unwind_native+0x5f4c> */
	return 24396ULL;
x86_l_635b:
	/* 0x635b: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_6365:
	/* 0x6365: mov    QWORD PTR [rsp+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_636a:
	/* 0x636a: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_6374:
	/* 0x6374: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6379:
	/* 0x6379: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_6383:
	/* 0x6383: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6388:
	/* 0x6388: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_6392:
	/* 0x6392: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6397:
	/* 0x6397: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_63a1:
	/* 0x63a1: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_63a6:
	/* 0x63a6: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_63b0:
	/* 0x63b0: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_63b5:
	/* 0x63b5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_63ba:
	/* 0x63ba: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_63bf:
	/* 0x63bf: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_63c4:
	/* 0x63c4: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_63c8:
	/* 0x63c8: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_63cd:
	/* 0x63cd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_63cf:
	/* 0x63cf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_63d1:
	/* 0x63d1: mov    r13d,0xfaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4015ULL);
x86_l_63d7:
	/* 0x63d7: jmp    5f4c <kprobe_unwind_native+0x5f4c> */
	return 24396ULL;
x86_l_63dc:
	/* 0x63dc: and    eax,0xffff7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294934527ULL);
x86_l_63e1:
	/* 0x63e1: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_63e7:
	/* 0x63e7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_63ea:
	/* 0x63ea: jg     647c <kprobe_unwind_native+0x647c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_647c;
	}
x86_l_63f0:
	/* 0x63f0: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_63f3:
	/* 0x63f3: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_63f8:
	/* 0x63f8: mov    rcx,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_6400:
	/* 0x6400: je     6474 <kprobe_unwind_native+0x6474> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6474;
	}
x86_l_6402:
	/* 0x6402: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6405:
	/* 0x6405: jne    5f4c <kprobe_unwind_native+0x5f4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24396ULL;
	}
x86_l_640b:
	/* 0x640b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_640e:
	/* 0x640e: mov    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6411:
	/* 0x6411: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6413:
	/* 0x6413: and    ecx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_6416:
	/* 0x6416: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6418:
	/* 0x6418: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_641b:
	/* 0x641b: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_641e:
	/* 0x641e: lea    r13,[rax+rdx*8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_6422:
	/* 0x6422: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6426:
	/* 0x6426: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_642d:
	/* 0x642d: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6430:
	/* 0x6430: je     6e3a <kprobe_unwind_native+0x6e3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28218ULL;
	}
x86_l_6436:
	/* 0x6436: movabs rax,0xa786c2578303d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947155647541309ULL);
x86_l_6440:
	/* 0x6440: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6445:
	/* 0x6445: movabs rax,0x616663202c544c50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018406059137322064ULL);
x86_l_644f:
	/* 0x644f: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6454:
	/* 0x6454: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6459:
	/* 0x6459: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_645e:
	/* 0x645e: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6463:
	/* 0x6463: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6468:
	/* 0x6468: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_646b:
	/* 0x646b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_646d:
	/* 0x646d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_646f:
	/* 0x646f: jmp    6e3a <kprobe_unwind_native+0x6e3a> */
	return 28218ULL;
x86_l_6474:
	/* 0x6474: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6477:
	/* 0x6477: jmp    5f4c <kprobe_unwind_native+0x5f4c> */
	return 24396ULL;
x86_l_647c:
	/* 0x647c: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_647f:
	/* 0x647f: je     6553 <kprobe_unwind_native+0x6553> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6553;
	}
x86_l_6485:
	/* 0x6485: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6488:
	/* 0x6488: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_648d:
	/* 0x648d: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6492:
	/* 0x6492: jne    5f4c <kprobe_unwind_native+0x5f4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24396ULL;
	}
x86_l_6498:
	/* 0x6498: mov    rax,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_649b:
	/* 0x649b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64a0:
	/* 0x64a0: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_64a5:
	/* 0x64a5: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_64ab:
	/* 0x64ab: mov    rdx,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_64ae:
	/* 0x64ae: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_64b3:
	/* 0x64b3: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_64b6:
	/* 0x64b6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_64b9:
	/* 0x64b9: jne    1640 <kprobe_unwind_native+0x1640> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5696ULL;
	}
x86_l_64bf:
	/* 0x64bf: mov    rax,QWORD PTR [rbx+0xee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_64c6:
	/* 0x64c6: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_64ca:
	/* 0x64ca: mov    QWORD PTR [rbx+0xed8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_64d1:
	/* 0x64d1: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_64d6:
	/* 0x64d6: mov    QWORD PTR [rbx+0xee0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_64dd:
	/* 0x64dd: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_64e2:
	/* 0x64e2: mov    QWORD PTR [rbx+0xed0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_64e9:
	/* 0x64e9: jmp    6e75 <kprobe_unwind_native+0x6e75> */
	return 28277ULL;
x86_l_64ee:
	/* 0x64ee: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_64f1:
	/* 0x64f1: je     6654 <kprobe_unwind_native+0x6654> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6654;
	}
x86_l_64f7:
	/* 0x64f7: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_64fa:
	/* 0x64fa: jne    6b94 <kprobe_unwind_native+0x6b94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 27540ULL;
	}
x86_l_6500:
	/* 0x6500: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_6502:
	/* 0x6502: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_6504:
	/* 0x6504: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_6507:
	/* 0x6507: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_6509:
	/* 0x6509: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_650e:
	/* 0x650e: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6515:
	/* 0x6515: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6518:
	/* 0x6518: jne    6b1f <kprobe_unwind_native+0x6b1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6b1f;
	}
x86_l_651e:
	/* 0x651e: and    ebp,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_6521:
	/* 0x6521: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6524:
	/* 0x6524: cmp    ebp,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_6527:
	/* 0x6527: jg     6b72 <kprobe_unwind_native+0x6b72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 27506ULL;
	}
x86_l_652d:
	/* 0x652d: mov    rax,QWORD PTR [rsp+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_6535:
	/* 0x6535: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_6537:
	/* 0x6537: je     6b8c <kprobe_unwind_native+0x6b8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 27532ULL;
	}
x86_l_653d:
	/* 0x653d: cmp    ebp,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 9ULL);
x86_l_6540:
	/* 0x6540: jne    6b94 <kprobe_unwind_native+0x6b94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 27540ULL;
	}
x86_l_6546:
	/* 0x6546: mov    rax,QWORD PTR [rsp+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_654e:
	/* 0x654e: jmp    6b8c <kprobe_unwind_native+0x6b8c> */
	return 27532ULL;
x86_l_6553:
	/* 0x6553: mov    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6556:
	/* 0x6556: add    rax,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_655a:
	/* 0x655a: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_6562:
	/* 0x6562: mov    ecx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 144ULL);
x86_l_6567:
	/* 0x6567: mov    r8d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 112ULL);
x86_l_656d:
	/* 0x656d: mov    rdx,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6570:
	/* 0x6570: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_6574:
	/* 0x6574: mov    esi,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 144ULL);
x86_l_6579:
	/* 0x6579: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_657c:
	/* 0x657c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_657f:
	/* 0x657f: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6584:
	/* 0x6584: jne    1640 <kprobe_unwind_native+0x1640> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5696ULL;
	}
x86_l_658a:
	/* 0x658a: mov    rax,QWORD PTR [rsp+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_6592:
	/* 0x6592: mov    QWORD PTR [rbx+0xee8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3816ULL);
x86_l_6599:
	/* 0x6599: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_65a1:
	/* 0x65a1: mov    QWORD PTR [rbx+0xef0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3824ULL);
x86_l_65a8:
	/* 0x65a8: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_65b0:
	/* 0x65b0: mov    QWORD PTR [rbx+0xef8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3832ULL);
x86_l_65b7:
	/* 0x65b7: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_65bf:
	/* 0x65bf: mov    QWORD PTR [rbx+0xf00],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3840ULL);
x86_l_65c6:
	/* 0x65c6: mov    rax,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_65ce:
	/* 0x65ce: mov    QWORD PTR [rbx+0xf08],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3848ULL);
x86_l_65d5:
	/* 0x65d5: mov    rax,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_65dd:
	/* 0x65dd: mov    QWORD PTR [rbx+0xee0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3808ULL);
x86_l_65e4:
	/* 0x65e4: mov    rax,QWORD PTR [rsp+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_65ec:
	/* 0x65ec: mov    QWORD PTR [rbx+0xed8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_65f3:
	/* 0x65f3: mov    rax,QWORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_65fb:
	/* 0x65fb: mov    QWORD PTR [rbx+0xed0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_6602:
	/* 0x6602: mov    BYTE PTR [rbx+0xf30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16698832846848ULL);
x86_l_6609:
	/* 0x6609: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6610:
	/* 0x6610: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6613:
	/* 0x6613: je     6e7c <kprobe_unwind_native+0x6e7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28284ULL;
	}
x86_l_6619:
	/* 0x6619: movabs rax,0xa656d61726620 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2926270227834400ULL);
x86_l_6623:
	/* 0x6623: mov    QWORD PTR [rsp+0x16],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_6628:
	/* 0x6628: movabs rax,0x66206c616e676973 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7359000956843288947ULL);
x86_l_6632:
	/* 0x6632: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6637:
	/* 0x6637: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_663c:
	/* 0x663c: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6641:
	/* 0x6641: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6646:
	/* 0x6646: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_664b:
	/* 0x664b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_664d:
	/* 0x664d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_664f:
	/* 0x664f: jmp    6e7c <kprobe_unwind_native+0x6e7c> */
	return 28284ULL;
x86_l_6654:
	/* 0x6654: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6659:
	/* 0x6659: mov    r13,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_665c:
	/* 0x665c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_665f:
	/* 0x665f: movsxd r13,ecx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_6662:
	/* 0x6662: add    r13,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6665:
	/* 0x6665: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_6667:
	/* 0x6667: jns    6b94 <kprobe_unwind_native+0x6b94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 27540ULL;
	}
x86_l_666d:
	/* 0x666d: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6672:
	/* 0x6672: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6677:
	/* 0x6677: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_667c:
	/* 0x667c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6681:
	/* 0x6681: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_6684:
	/* 0x6684: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6686:
	/* 0x6686: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6689:
	/* 0x6689: je     66a3 <kprobe_unwind_native+0x66a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_66a3;
	}
x86_l_668b:
	/* 0x668b: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6692:
	/* 0x6692: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6695:
	/* 0x6695: jne    6cff <kprobe_unwind_native+0x6cff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 27903ULL;
	}
x86_l_669b:
	/* 0x669b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_669e:
	/* 0x669e: jmp    6b94 <kprobe_unwind_native+0x6b94> */
	return 27540ULL;
x86_l_66a3:
	/* 0x66a3: shl    ebp,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_66a6:
	/* 0x66a6: and    ebp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 56ULL);
x86_l_66a9:
	/* 0x66a9: add    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_66ae:
	/* 0x66ae: mov    r13,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_66b1:
	/* 0x66b1: jmp    6b94 <kprobe_unwind_native+0x6b94> */
	return 27540ULL;
x86_l_66b6:
	/* 0x66b6: mov    edx,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_66bc:
	/* 0x66bc: movabs rax,0x3d3d206425206576 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4412718824384652662ULL);
x86_l_66c6:
	/* 0x66c6: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_66ce:
	/* 0x66ce: movabs rax,0x6974616e5f646e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7598805597955583593ULL);
x86_l_66d8:
	/* 0x66d8: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_66e0:
	/* 0x66e0: movabs rax,0x776e75203d3d3d3d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8605944719278423357ULL);
x86_l_66ea:
	/* 0x66ea: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_66f2:
	/* 0x66f2: mov    DWORD PTR [rsp+0xb8],0xa3d3d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 790274653501ULL);
x86_l_66fd:
	/* 0x66fd: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_6705:
	/* 0x6705: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_670a:
	/* 0x670a: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_670f:
	/* 0x670f: mov    esi,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 28ULL);
x86_l_6714:
	/* 0x6714: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6716:
	/* 0x6716: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6718:
	/* 0x6718: jmp    5499 <kprobe_unwind_native+0x5499> */
	return 21657ULL;
x86_l_671d:
	/* 0x671d: movabs rax,0xa786c253a786c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 754471844735118373ULL);
x86_l_6727:
	/* 0x6727: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_672c:
	/* 0x672c: movabs rax,0x20726f662061746c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2338053640979313772ULL);
x86_l_6736:
	/* 0x6736: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_673b:
	/* 0x673b: movabs rax,0x6564206b63617473 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7306000141102707827ULL);
x86_l_6745:
	/* 0x6745: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_674a:
	/* 0x674a: movabs rax,0x207075206b6f6f4c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337496988707155788ULL);
x86_l_6754:
	/* 0x6754: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6759:
	/* 0x6759: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_675e:
	/* 0x675e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6763:
	/* 0x6763: mov    eax,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_6768:
	/* 0x6768: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_676e:
	/* 0x676e: mov    rdx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_6775:
	/* 0x6775: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_677c:
	/* 0x677c: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_6781:
	/* 0x6781: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6783:
	/* 0x6783: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6786:
	/* 0x6786: jmp    562b <kprobe_unwind_native+0x562b> */
	return 22059ULL;
x86_l_678b:
	/* 0x678b: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_6795:
	/* 0x6795: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_679d:
	/* 0x679d: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_67a7:
	/* 0x67a7: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_67af:
	/* 0x67af: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_67b9:
	/* 0x67b9: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_67c1:
	/* 0x67c1: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_67cb:
	/* 0x67cb: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_67d3:
	/* 0x67d3: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_67dd:
	/* 0x67dd: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_67e5:
	/* 0x67e5: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_67ef:
	/* 0x67ef: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_67f7:
	/* 0x67f7: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_67ff:
	/* 0x67ff: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_6804:
	/* 0x6804: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6809:
	/* 0x6809: mov    edx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_680d:
	/* 0x680d: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_6812:
	/* 0x6812: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6814:
	/* 0x6814: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6816:
	/* 0x6816: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_681d:
	/* 0x681d: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6820:
	/* 0x6820: je     5579 <kprobe_unwind_native+0x5579> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 21881ULL;
	}
x86_l_6826:
	/* 0x6826: jmp    54d0 <kprobe_unwind_native+0x54d0> */
	return 21712ULL;
x86_l_682b:
	/* 0x682b: movabs rax,0xa296425204449 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2860259863446601ULL);
x86_l_6835:
	/* 0x6835: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_683a:
	/* 0x683a: movabs rax,0x70616d2820756c25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8097873624099548197ULL);
x86_l_6844:
	/* 0x6844: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6849:
	/* 0x6849: movabs rax,0x206f7420756c2520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2337214414386373920ULL);
x86_l_6853:
	/* 0x6853: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6858:
	/* 0x6858: movabs rax,0x6d6f726620656220 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7885647255504773664ULL);
x86_l_6862:
	/* 0x6862: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6867:
	/* 0x6867: movabs rax,0x646c756f68732073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7236287822631739507ULL);
x86_l_6871:
	/* 0x6871: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6876:
	/* 0x6876: movabs rax,0x6c61767265746e49 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7809653462537629257ULL);
x86_l_6880:
	/* 0x6880: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6885:
	/* 0x6885: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_688a:
	/* 0x688a: mov    eax,0x30 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 48ULL);
x86_l_688f:
	/* 0x688f: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_6895:
	/* 0x6895: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_6898:
	/* 0x6898: movzx  r8d,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_689d:
	/* 0x689d: mov    esi,0x30 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 48ULL);
x86_l_68a2:
	/* 0x68a2: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_68a5:
	/* 0x68a5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68a7:
	/* 0x68a7: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_68aa:
	/* 0x68aa: jmp    5983 <kprobe_unwind_native+0x5983> */
	return 22915ULL;
x86_l_68af:
	/* 0x68af: movabs rax,0xa6425206f666e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860387845742ULL);
x86_l_68b9:
	/* 0x68b9: mov    QWORD PTR [rsp+0x35],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_68be:
	/* 0x68be: movabs rax,0x6f666e49646e6977 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8027224647331113335ULL);
x86_l_68c8:
	/* 0x68c8: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_68cd:
	/* 0x68cd: movabs rax,0x6e75202c78257830 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7959303291813591088ULL);
x86_l_68d7:
	/* 0x68d7: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_68dc:
	/* 0x68dc: movabs rax,0x20776f4c72646461 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2339460905569641569ULL);
x86_l_68e6:
	/* 0x68e6: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_68eb:
	/* 0x68eb: movabs rax,0x202c642520786564 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2318338018810291556ULL);
x86_l_68f5:
	/* 0x68f5: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_68fa:
	/* 0x68fa: movabs rax,0x6e692061746c6564 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7955925819663869284ULL);
x86_l_6904:
	/* 0x6904: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6909:
	/* 0x6909: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_690e:
	/* 0x690e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_6913:
	/* 0x6913: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_6919:
	/* 0x6919: mov    edx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_6920:
	/* 0x6920: movzx  ecx,WORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_6924:
	/* 0x6924: movzx  r8d,WORD PTR [rbp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_6929:
	/* 0x6929: mov    esi,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 45ULL);
x86_l_692e:
	/* 0x692e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6930:
	/* 0x6930: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_6933:
	/* 0x6933: jmp    5ea3 <kprobe_unwind_native+0x5ea3> */
	return 24227ULL;
x86_l_6938:
	/* 0x6938: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_6942:
	/* 0x6942: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_694a:
	/* 0x694a: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_6954:
	/* 0x6954: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_695c:
	/* 0x695c: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_6966:
	/* 0x6966: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_696e:
	/* 0x696e: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_6978:
	/* 0x6978: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_6980:
	/* 0x6980: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_698a:
	/* 0x698a: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_6992:
	/* 0x6992: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_699c:
	/* 0x699c: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_69a4:
	/* 0x69a4: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_69ac:
	/* 0x69ac: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_69b1:
	/* 0x69b1: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_69b6:
	/* 0x69b6: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_69ba:
	/* 0x69ba: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_69bf:
	/* 0x69bf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69c1:
	/* 0x69c1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_69c3:
	/* 0x69c3: jmp    547a <kprobe_unwind_native+0x547a> */
	return 21626ULL;
x86_l_69c8:
	/* 0x69c8: movabs rax,0xa78323023252061 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 754408119914012769ULL);
x86_l_69d2:
	/* 0x69d2: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69d7:
	/* 0x69d7: movabs rax,0x746c656420646567 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8389191686598976871ULL);
x86_l_69e1:
	/* 0x69e1: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_69e6:
	/* 0x69e6: movabs rax,0x72656d202c642520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243114677922702624ULL);
x86_l_69f0:
	/* 0x69f0: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_69f5:
	/* 0x69f5: movabs rax,0x6666694472646441 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7378700782191010881ULL);
x86_l_69ff:
	/* 0x69ff: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6a04:
	/* 0x6a04: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_6a09:
	/* 0x6a09: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6a0e:
	/* 0x6a0e: mov    eax,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_6a13:
	/* 0x6a13: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_6a19:
	/* 0x6a19: mov    r12,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6a1e:
	/* 0x6a1e: movzx  ecx,BYTE PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_6a24:
	/* 0x6a24: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_6a29:
	/* 0x6a29: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_6a2c:
	/* 0x6a2c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a2e:
	/* 0x6a2e: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6a31:
	/* 0x6a31: movzx  eax,BYTE PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_6a37:
	/* 0x6a37: jmp    62ac <kprobe_unwind_native+0x62ac> */
	return 25260ULL;
x86_l_6a3c:
	/* 0x6a3c: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_6a46:
	/* 0x6a46: mov    QWORD PTR [rsp+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_6a4b:
	/* 0x6a4b: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_6a55:
	/* 0x6a55: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6a5a:
	/* 0x6a5a: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_6a64:
	/* 0x6a64: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a69:
	/* 0x6a69: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_6a73:
	/* 0x6a73: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6a78:
	/* 0x6a78: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_6a82:
	/* 0x6a82: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6a87:
	/* 0x6a87: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_6a91:
	/* 0x6a91: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6a96:
	/* 0x6a96: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6a9b:
	/* 0x6a9b: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_6aa0:
	/* 0x6aa0: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6aa5:
	/* 0x6aa5: mov    edx,DWORD PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_6aac:
	/* 0x6aac: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_6ab1:
	/* 0x6ab1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ab3:
	/* 0x6ab3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6ab5:
	/* 0x6ab5: jmp    6258 <kprobe_unwind_native+0x6258> */
	return 25176ULL;
x86_l_6aba:
	/* 0x6aba: movabs rax,0xa64253d61746c65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 748764383608597605ULL);
x86_l_6ac4:
	/* 0x6ac4: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6ac9:
	/* 0x6ac9: movabs rax,0x44616663203a6863 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4927332043248527459ULL);
x86_l_6ad3:
	/* 0x6ad3: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6ad8:
	/* 0x6ad8: movabs rax,0x74616d2061746c65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8386103966981975141ULL);
x86_l_6ae2:
	/* 0x6ae2: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6ae7:
	/* 0x6ae7: movabs rax,0x642064656772654d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7214876989737559373ULL);
x86_l_6af1:
	/* 0x6af1: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6af6:
	/* 0x6af6: mov    BYTE PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_6afb:
	/* 0x6afb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b00:
	/* 0x6b00: mov    eax,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_6b05:
	/* 0x6b05: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6b0a:
	/* 0x6b0a: mov    edx,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_6b11:
	/* 0x6b11: mov    esi,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_6b16:
	/* 0x6b16: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b18:
	/* 0x6b18: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6b1a:
	/* 0x6b1a: jmp    62d8 <kprobe_unwind_native+0x62d8> */
	return 25304ULL;
x86_l_6b1f:
	/* 0x6b1f: movabs rax,0xa756c252b642572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 753627419551999346ULL);
x86_l_6b29:
	/* 0x6b29: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6b2e:
	/* 0x6b2e: movabs rax,0x203a646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2322278983241526901ULL);
x86_l_6b38:
	/* 0x6b38: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b3d:
	/* 0x6b3d: mov    BYTE PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_6b42:
	/* 0x6b42: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b47:
	/* 0x6b47: mov    eax,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 17ULL);
	return 27468ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_14(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 27468ULL: goto x86_l_6b4c;
	case 27474ULL: goto x86_l_6b52;
	case 27477ULL: goto x86_l_6b55;
	case 27482ULL: goto x86_l_6b5a;
	case 27487ULL: goto x86_l_6b5f;
	case 27489ULL: goto x86_l_6b61;
	case 27491ULL: goto x86_l_6b63;
	case 27494ULL: goto x86_l_6b66;
	case 27497ULL: goto x86_l_6b69;
	case 27500ULL: goto x86_l_6b6c;
	case 27506ULL: goto x86_l_6b72;
	case 27514ULL: goto x86_l_6b7a;
	case 27517ULL: goto x86_l_6b7d;
	case 27519ULL: goto x86_l_6b7f;
	case 27527ULL: goto x86_l_6b87;
	case 27530ULL: goto x86_l_6b8a;
	case 27532ULL: goto x86_l_6b8c;
	case 27537ULL: goto x86_l_6b91;
	case 27540ULL: goto x86_l_6b94;
	case 27545ULL: goto x86_l_6b99;
	case 27549ULL: goto x86_l_6b9d;
	case 27553ULL: goto x86_l_6ba1;
	case 27556ULL: goto x86_l_6ba4;
	case 27559ULL: goto x86_l_6ba7;
	case 27561ULL: goto x86_l_6ba9;
	case 27565ULL: goto x86_l_6bad;
	case 27567ULL: goto x86_l_6baf;
	case 27570ULL: goto x86_l_6bb2;
	case 27573ULL: goto x86_l_6bb5;
	case 27575ULL: goto x86_l_6bb7;
	case 27578ULL: goto x86_l_6bba;
	case 27581ULL: goto x86_l_6bbd;
	case 27583ULL: goto x86_l_6bbf;
	case 27586ULL: goto x86_l_6bc2;
	case 27589ULL: goto x86_l_6bc5;
	case 27591ULL: goto x86_l_6bc7;
	case 27596ULL: goto x86_l_6bcc;
	case 27599ULL: goto x86_l_6bcf;
	case 27601ULL: goto x86_l_6bd1;
	case 27604ULL: goto x86_l_6bd4;
	case 27610ULL: goto x86_l_6bda;
	case 27613ULL: goto x86_l_6bdd;
	case 27615ULL: goto x86_l_6bdf;
	case 27618ULL: goto x86_l_6be2;
	case 27620ULL: goto x86_l_6be4;
	case 27625ULL: goto x86_l_6be9;
	case 27632ULL: goto x86_l_6bf0;
	case 27635ULL: goto x86_l_6bf3;
	case 27641ULL: goto x86_l_6bf9;
	case 27645ULL: goto x86_l_6bfd;
	case 27649ULL: goto x86_l_6c01;
	case 27655ULL: goto x86_l_6c07;
	case 27658ULL: goto x86_l_6c0a;
	case 27664ULL: goto x86_l_6c10;
	case 27668ULL: goto x86_l_6c14;
	case 27674ULL: goto x86_l_6c1a;
	case 27682ULL: goto x86_l_6c22;
	case 27690ULL: goto x86_l_6c2a;
	case 27695ULL: goto x86_l_6c2f;
	case 27700ULL: goto x86_l_6c34;
	case 27703ULL: goto x86_l_6c37;
	case 27706ULL: goto x86_l_6c3a;
	case 27709ULL: goto x86_l_6c3d;
	case 27711ULL: goto x86_l_6c3f;
	case 27717ULL: goto x86_l_6c45;
	case 27722ULL: goto x86_l_6c4a;
	case 27727ULL: goto x86_l_6c4f;
	case 27732ULL: goto x86_l_6c54;
	case 27737ULL: goto x86_l_6c59;
	case 27740ULL: goto x86_l_6c5c;
	case 27742ULL: goto x86_l_6c5e;
	case 27745ULL: goto x86_l_6c61;
	case 27751ULL: goto x86_l_6c67;
	case 27758ULL: goto x86_l_6c6e;
	case 27761ULL: goto x86_l_6c71;
	case 27767ULL: goto x86_l_6c77;
	case 27777ULL: goto x86_l_6c81;
	case 27782ULL: goto x86_l_6c86;
	case 27792ULL: goto x86_l_6c90;
	case 27797ULL: goto x86_l_6c95;
	case 27807ULL: goto x86_l_6c9f;
	case 27812ULL: goto x86_l_6ca4;
	case 27822ULL: goto x86_l_6cae;
	case 27827ULL: goto x86_l_6cb3;
	case 27837ULL: goto x86_l_6cbd;
	case 27842ULL: goto x86_l_6cc2;
	case 27850ULL: goto x86_l_6cca;
	case 27855ULL: goto x86_l_6ccf;
	case 27860ULL: goto x86_l_6cd4;
	case 27865ULL: goto x86_l_6cd9;
	case 27870ULL: goto x86_l_6cde;
	case 27873ULL: goto x86_l_6ce1;
	case 27875ULL: goto x86_l_6ce3;
	case 27877ULL: goto x86_l_6ce5;
	case 27882ULL: goto x86_l_6cea;
	case 27886ULL: goto x86_l_6cee;
	case 27890ULL: goto x86_l_6cf2;
	case 27895ULL: goto x86_l_6cf7;
	case 27898ULL: goto x86_l_6cfa;
	case 27903ULL: goto x86_l_6cff;
	case 27913ULL: goto x86_l_6d09;
	case 27918ULL: goto x86_l_6d0e;
	case 27928ULL: goto x86_l_6d18;
	case 27933ULL: goto x86_l_6d1d;
	case 27943ULL: goto x86_l_6d27;
	case 27948ULL: goto x86_l_6d2c;
	case 27958ULL: goto x86_l_6d36;
	case 27963ULL: goto x86_l_6d3b;
	case 27973ULL: goto x86_l_6d45;
	case 27978ULL: goto x86_l_6d4a;
	case 27986ULL: goto x86_l_6d52;
	case 27991ULL: goto x86_l_6d57;
	case 27996ULL: goto x86_l_6d5c;
	case 28001ULL: goto x86_l_6d61;
	case 28006ULL: goto x86_l_6d66;
	case 28009ULL: goto x86_l_6d69;
	case 28011ULL: goto x86_l_6d6b;
	case 28013ULL: goto x86_l_6d6d;
	case 28016ULL: goto x86_l_6d70;
	case 28021ULL: goto x86_l_6d75;
	case 28031ULL: goto x86_l_6d7f;
	case 28036ULL: goto x86_l_6d84;
	case 28046ULL: goto x86_l_6d8e;
	case 28051ULL: goto x86_l_6d93;
	case 28056ULL: goto x86_l_6d98;
	case 28061ULL: goto x86_l_6d9d;
	case 28066ULL: goto x86_l_6da2;
	case 28072ULL: goto x86_l_6da8;
	case 28076ULL: goto x86_l_6dac;
	case 28081ULL: goto x86_l_6db1;
	case 28086ULL: goto x86_l_6db6;
	case 28089ULL: goto x86_l_6db9;
	case 28091ULL: goto x86_l_6dbb;
	case 28094ULL: goto x86_l_6dbe;
	case 28098ULL: goto x86_l_6dc2;
	case 28104ULL: goto x86_l_6dc8;
	case 28112ULL: goto x86_l_6dd0;
	case 28120ULL: goto x86_l_6dd8;
	case 28124ULL: goto x86_l_6ddc;
	case 28126ULL: goto x86_l_6dde;
	case 28134ULL: goto x86_l_6de6;
	case 28142ULL: goto x86_l_6dee;
	case 28146ULL: goto x86_l_6df2;
	case 28148ULL: goto x86_l_6df4;
	case 28153ULL: goto x86_l_6df9;
	case 28161ULL: goto x86_l_6e01;
	case 28164ULL: goto x86_l_6e04;
	case 28167ULL: goto x86_l_6e07;
	case 28169ULL: goto x86_l_6e09;
	case 28174ULL: goto x86_l_6e0e;
	case 28179ULL: goto x86_l_6e13;
	case 28184ULL: goto x86_l_6e18;
	case 28189ULL: goto x86_l_6e1d;
	case 28192ULL: goto x86_l_6e20;
	case 28194ULL: goto x86_l_6e22;
	case 28196ULL: goto x86_l_6e24;
	case 28201ULL: goto x86_l_6e29;
	case 28204ULL: goto x86_l_6e2c;
	case 28206ULL: goto x86_l_6e2e;
	case 28211ULL: goto x86_l_6e33;
	case 28218ULL: goto x86_l_6e3a;
	case 28221ULL: goto x86_l_6e3d;
	case 28226ULL: goto x86_l_6e42;
	case 28232ULL: goto x86_l_6e48;
	case 28236ULL: goto x86_l_6e4c;
	case 28241ULL: goto x86_l_6e51;
	case 28246ULL: goto x86_l_6e56;
	case 28254ULL: goto x86_l_6e5e;
	case 28259ULL: goto x86_l_6e63;
	case 28261ULL: goto x86_l_6e65;
	case 28264ULL: goto x86_l_6e68;
	case 28270ULL: goto x86_l_6e6e;
	case 28277ULL: goto x86_l_6e75;
	case 28284ULL: goto x86_l_6e7c;
	case 28292ULL: goto x86_l_6e84;
	case 28299ULL: goto x86_l_6e8b;
	case 28304ULL: goto x86_l_6e90;
	case 28309ULL: goto x86_l_6e95;
	case 28311ULL: goto x86_l_6e97;
	case 28314ULL: goto x86_l_6e9a;
	case 28316ULL: goto x86_l_6e9c;
	case 28319ULL: goto x86_l_6e9f;
	case 28321ULL: goto x86_l_6ea1;
	case 28328ULL: goto x86_l_6ea8;
	case 28331ULL: goto x86_l_6eab;
	case 28333ULL: goto x86_l_6ead;
	case 28338ULL: goto x86_l_6eb2;
	case 28345ULL: goto x86_l_6eb9;
	case 28348ULL: goto x86_l_6ebc;
	case 28354ULL: goto x86_l_6ec2;
	case 28356ULL: goto x86_l_6ec4;
	case 28364ULL: goto x86_l_6ecc;
	case 28367ULL: goto x86_l_6ecf;
	case 28370ULL: goto x86_l_6ed2;
	case 28376ULL: goto x86_l_6ed8;
	case 28378ULL: goto x86_l_6eda;
	case 28384ULL: goto x86_l_6ee0;
	case 28394ULL: goto x86_l_6eea;
	case 28397ULL: goto x86_l_6eed;
	case 28403ULL: goto x86_l_6ef3;
	case 28410ULL: goto x86_l_6efa;
	case 28416ULL: goto x86_l_6f00;
	case 28418ULL: goto x86_l_6f02;
	case 28426ULL: goto x86_l_6f0a;
	case 28432ULL: goto x86_l_6f10;
	case 28439ULL: goto x86_l_6f17;
	case 28446ULL: goto x86_l_6f1e;
	case 28451ULL: goto x86_l_6f23;
	case 28456ULL: goto x86_l_6f28;
	case 28458ULL: goto x86_l_6f2a;
	case 28461ULL: goto x86_l_6f2d;
	case 28467ULL: goto x86_l_6f33;
	case 28471ULL: goto x86_l_6f37;
	case 28481ULL: goto x86_l_6f41;
	case 28484ULL: goto x86_l_6f44;
	case 28491ULL: goto x86_l_6f4b;
	case 28494ULL: goto x86_l_6f4e;
	case 28501ULL: goto x86_l_6f55;
	case 28505ULL: goto x86_l_6f59;
	case 28508ULL: goto x86_l_6f5c;
	case 28511ULL: goto x86_l_6f5f;
	case 28518ULL: goto x86_l_6f66;
	case 28525ULL: goto x86_l_6f6d;
	case 28528ULL: goto x86_l_6f70;
	case 28534ULL: goto x86_l_6f76;
	case 28538ULL: goto x86_l_6f7a;
	case 28544ULL: goto x86_l_6f80;
	case 28551ULL: goto x86_l_6f87;
	case 28556ULL: goto x86_l_6f8c;
	case 28563ULL: goto x86_l_6f93;
	case 28570ULL: goto x86_l_6f9a;
	case 28575ULL: goto x86_l_6f9f;
	case 28580ULL: goto x86_l_6fa4;
	case 28582ULL: goto x86_l_6fa6;
	case 28588ULL: goto x86_l_6fac;
	case 28591ULL: goto x86_l_6faf;
	case 28597ULL: goto x86_l_6fb5;
	case 28600ULL: goto x86_l_6fb8;
	case 28603ULL: goto x86_l_6fbb;
	case 28605ULL: goto x86_l_6fbd;
	case 28609ULL: goto x86_l_6fc1;
	case 28611ULL: goto x86_l_6fc3;
	case 28615ULL: goto x86_l_6fc7;
	case 28621ULL: goto x86_l_6fcd;
	case 28625ULL: goto x86_l_6fd1;
	case 28631ULL: goto x86_l_6fd7;
	case 28638ULL: goto x86_l_6fde;
	case 28641ULL: goto x86_l_6fe1;
	case 28647ULL: goto x86_l_6fe7;
	case 28653ULL: goto x86_l_6fed;
	case 28657ULL: goto x86_l_6ff1;
	case 28660ULL: goto x86_l_6ff4;
	case 28666ULL: goto x86_l_6ffa;
	case 28673ULL: goto x86_l_7001;
	case 28676ULL: goto x86_l_7004;
	case 28682ULL: goto x86_l_700a;
	case 28692ULL: goto x86_l_7014;
	case 28700ULL: goto x86_l_701c;
	case 28710ULL: goto x86_l_7026;
	case 28718ULL: goto x86_l_702e;
	case 28728ULL: goto x86_l_7038;
	case 28736ULL: goto x86_l_7040;
	case 28747ULL: goto x86_l_704b;
	case 28755ULL: goto x86_l_7053;
	case 28760ULL: goto x86_l_7058;
	case 28765ULL: goto x86_l_705d;
	case 28770ULL: goto x86_l_7062;
	case 28772ULL: goto x86_l_7064;
	case 28774ULL: goto x86_l_7066;
	case 28779ULL: goto x86_l_706b;
	case 28784ULL: goto x86_l_7070;
	case 28786ULL: goto x86_l_7072;
	case 28793ULL: goto x86_l_7079;
	case 28795ULL: goto x86_l_707b;
	case 28805ULL: goto x86_l_7085;
	case 28811ULL: goto x86_l_708b;
	case 28814ULL: goto x86_l_708e;
	case 28819ULL: goto x86_l_7093;
	case 28829ULL: goto x86_l_709d;
	case 28837ULL: goto x86_l_70a5;
	case 28847ULL: goto x86_l_70af;
	case 28855ULL: goto x86_l_70b7;
	case 28865ULL: goto x86_l_70c1;
	case 28873ULL: goto x86_l_70c9;
	case 28883ULL: goto x86_l_70d3;
	case 28891ULL: goto x86_l_70db;
	case 28901ULL: goto x86_l_70e5;
	case 28909ULL: goto x86_l_70ed;
	case 28919ULL: goto x86_l_70f7;
	case 28927ULL: goto x86_l_70ff;
	case 28935ULL: goto x86_l_7107;
	case 28943ULL: goto x86_l_710f;
	case 28948ULL: goto x86_l_7114;
	case 28953ULL: goto x86_l_7119;
	case 28958ULL: goto x86_l_711e;
	case 28960ULL: goto x86_l_7120;
	case 28962ULL: goto x86_l_7122;
	case 28967ULL: goto x86_l_7127;
	case 28972ULL: goto x86_l_712c;
	case 28979ULL: goto x86_l_7133;
	case 28982ULL: goto x86_l_7136;
	case 28984ULL: goto x86_l_7138;
	case 28994ULL: goto x86_l_7142;
	case 29000ULL: goto x86_l_7148;
	case 29003ULL: goto x86_l_714b;
	case 29008ULL: goto x86_l_7150;
	case 29018ULL: goto x86_l_715a;
	case 29026ULL: goto x86_l_7162;
	case 29036ULL: goto x86_l_716c;
	case 29044ULL: goto x86_l_7174;
	case 29054ULL: goto x86_l_717e;
	case 29062ULL: goto x86_l_7186;
	case 29072ULL: goto x86_l_7190;
	case 29080ULL: goto x86_l_7198;
	case 29090ULL: goto x86_l_71a2;
	case 29098ULL: goto x86_l_71aa;
	case 29108ULL: goto x86_l_71b4;
	case 29116ULL: goto x86_l_71bc;
	case 29126ULL: goto x86_l_71c6;
	case 29134ULL: goto x86_l_71ce;
	case 29142ULL: goto x86_l_71d6;
	case 29150ULL: goto x86_l_71de;
	case 29155ULL: goto x86_l_71e3;
	case 29160ULL: goto x86_l_71e8;
	case 29165ULL: goto x86_l_71ed;
	case 29168ULL: goto x86_l_71f0;
	case 29170ULL: goto x86_l_71f2;
	case 29172ULL: goto x86_l_71f4;
	case 29177ULL: goto x86_l_71f9;
	case 29187ULL: goto x86_l_7203;
	case 29192ULL: goto x86_l_7208;
	case 29202ULL: goto x86_l_7212;
	case 29207ULL: goto x86_l_7217;
	case 29217ULL: goto x86_l_7221;
	case 29222ULL: goto x86_l_7226;
	case 29232ULL: goto x86_l_7230;
	case 29237ULL: goto x86_l_7235;
	case 29247ULL: goto x86_l_723f;
	case 29252ULL: goto x86_l_7244;
	case 29262ULL: goto x86_l_724e;
	case 29267ULL: goto x86_l_7253;
	case 29272ULL: goto x86_l_7258;
	case 29277ULL: goto x86_l_725d;
	case 29282ULL: goto x86_l_7262;
	case 29286ULL: goto x86_l_7266;
	case 29291ULL: goto x86_l_726b;
	case 29293ULL: goto x86_l_726d;
	case 29295ULL: goto x86_l_726f;
	case 29297ULL: goto x86_l_7271;
	case 29304ULL: goto x86_l_7278;
	case 29307ULL: goto x86_l_727b;
	case 29313ULL: goto x86_l_7281;
	case 29323ULL: goto x86_l_728b;
	case 29331ULL: goto x86_l_7293;
	case 29341ULL: goto x86_l_729d;
	case 29349ULL: goto x86_l_72a5;
	case 29359ULL: goto x86_l_72af;
	case 29367ULL: goto x86_l_72b7;
	case 29377ULL: goto x86_l_72c1;
	case 29385ULL: goto x86_l_72c9;
	case 29393ULL: goto x86_l_72d1;
	case 29398ULL: goto x86_l_72d6;
	case 29404ULL: goto x86_l_72dc;
	case 29412ULL: goto x86_l_72e4;
	case 29415ULL: goto x86_l_72e7;
	case 29418ULL: goto x86_l_72ea;
	case 29423ULL: goto x86_l_72ef;
	case 29426ULL: goto x86_l_72f2;
	case 29431ULL: goto x86_l_72f7;
	case 29433ULL: goto x86_l_72f9;
	case 29436ULL: goto x86_l_72fc;
	case 29443ULL: goto x86_l_7303;
	case 29445ULL: goto x86_l_7305;
	case 29450ULL: goto x86_l_730a;
	case 29460ULL: goto x86_l_7314;
	case 29468ULL: goto x86_l_731c;
	case 29478ULL: goto x86_l_7326;
	case 29486ULL: goto x86_l_732e;
	case 29496ULL: goto x86_l_7338;
	case 29504ULL: goto x86_l_7340;
	case 29514ULL: goto x86_l_734a;
	case 29522ULL: goto x86_l_7352;
	case 29532ULL: goto x86_l_735c;
	case 29540ULL: goto x86_l_7364;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6b4c:
	/* 0x6b4c: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_6b52:
	/* 0x6b52: and    ebp,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_6b55:
	/* 0x6b55: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6b5a:
	/* 0x6b5a: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_6b5f:
	/* 0x6b5f: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_6b61:
	/* 0x6b61: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b63:
	/* 0x6b63: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6b66:
	/* 0x6b66: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b69:
	/* 0x6b69: cmp    ebp,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_6b6c:
	/* 0x6b6c: jle    652d <kprobe_unwind_native+0x652d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 25901ULL;
	}
x86_l_6b72:
	/* 0x6b72: mov    rax,QWORD PTR [rsp+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_6b7a:
	/* 0x6b7a: cmp    ebp,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 11ULL);
x86_l_6b7d:
	/* 0x6b7d: je     6b8c <kprobe_unwind_native+0x6b8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6b8c;
	}
x86_l_6b7f:
	/* 0x6b7f: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_6b87:
	/* 0x6b87: cmp    ebp,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 15ULL);
x86_l_6b8a:
	/* 0x6b8a: jne    6b94 <kprobe_unwind_native+0x6b94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6b94;
	}
x86_l_6b8c:
	/* 0x6b8c: mov    r13,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6b91:
	/* 0x6b91: add    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_6b94:
	/* 0x6b94: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6b99:
	/* 0x6b99: movzx  eax,BYTE PTR [rcx+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_6b9d:
	/* 0x6b9d: mov    r12d,DWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6ba1:
	/* 0x6ba1: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_6ba4:
	/* 0x6ba4: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_6ba7:
	/* 0x6ba7: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_6ba9:
	/* 0x6ba9: cmovns ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_NS);
x86_l_6bad:
	/* 0x6bad: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_6baf:
	/* 0x6baf: and    edx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_6bb2:
	/* 0x6bb2: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_6bb5:
	/* 0x6bb5: jg     6bcc <kprobe_unwind_native+0x6bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_6bcc;
	}
x86_l_6bb7:
	/* 0x6bb7: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_6bba:
	/* 0x6bba: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_6bbd:
	/* 0x6bbd: je     6c37 <kprobe_unwind_native+0x6c37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6c37;
	}
x86_l_6bbf:
	/* 0x6bbf: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_6bc2:
	/* 0x6bc2: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_6bc5:
	/* 0x6bc5: je     6c34 <kprobe_unwind_native+0x6c34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6c34;
	}
x86_l_6bc7:
	/* 0x6bc7: jmp    6e24 <kprobe_unwind_native+0x6e24> */
	goto x86_l_6e24;
x86_l_6bcc:
	/* 0x6bcc: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_6bcf:
	/* 0x6bcf: je     6c2f <kprobe_unwind_native+0x6c2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6c2f;
	}
x86_l_6bd1:
	/* 0x6bd1: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_6bd4:
	/* 0x6bd4: jne    6e24 <kprobe_unwind_native+0x6e24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6e24;
	}
x86_l_6bda:
	/* 0x6bda: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_6bdd:
	/* 0x6bdd: sar    eax,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 1ULL);
x86_l_6bdf:
	/* 0x6bdf: and    eax,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_6be2:
	/* 0x6be2: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_6be4:
	/* 0x6be4: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6be9:
	/* 0x6be9: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6bf0:
	/* 0x6bf0: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6bf3:
	/* 0x6bf3: jne    6d75 <kprobe_unwind_native+0x6d75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6d75;
	}
x86_l_6bf9:
	/* 0x6bf9: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_6bfd:
	/* 0x6bfd: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_6c01:
	/* 0x6c01: jg     6dc8 <kprobe_unwind_native+0x6dc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_6dc8;
	}
x86_l_6c07:
	/* 0x6c07: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_6c0a:
	/* 0x6c0a: je     6df4 <kprobe_unwind_native+0x6df4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6df4;
	}
x86_l_6c10:
	/* 0x6c10: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_6c14:
	/* 0x6c14: jne    6e24 <kprobe_unwind_native+0x6e24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6e24;
	}
x86_l_6c1a:
	/* 0x6c1a: mov    rax,QWORD PTR [rsp+0x148] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 328ULL);
x86_l_6c22:
	/* 0x6c22: mov    QWORD PTR [rsp+0x138],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_6c2a:
	/* 0x6c2a: jmp    6df4 <kprobe_unwind_native+0x6df4> */
	goto x86_l_6df4;
x86_l_6c2f:
	/* 0x6c2f: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6c34:
	/* 0x6c34: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6c37:
	/* 0x6c37: movsxd rbp,ecx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_6c3a:
	/* 0x6c3a: add    rbp,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6c3d:
	/* 0x6c3d: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_6c3f:
	/* 0x6c3f: jns    6e04 <kprobe_unwind_native+0x6e04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_6e04;
	}
x86_l_6c45:
	/* 0x6c45: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6c4a:
	/* 0x6c4a: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6c4f:
	/* 0x6c4f: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_6c54:
	/* 0x6c54: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6c59:
	/* 0x6c59: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6c5c:
	/* 0x6c5c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6c5e:
	/* 0x6c5e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6c61:
	/* 0x6c61: je     6cea <kprobe_unwind_native+0x6cea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6cea;
	}
x86_l_6c67:
	/* 0x6c67: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6c6e:
	/* 0x6c6e: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6c71:
	/* 0x6c71: je     6e24 <kprobe_unwind_native+0x6e24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6e24;
	}
x86_l_6c77:
	/* 0x6c77: movabs rax,0x2578302073736572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2699960892542641522ULL);
x86_l_6c81:
	/* 0x6c81: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6c86:
	/* 0x6c86: movabs rax,0x6464612065636e65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7234013693231722085ULL);
x86_l_6c90:
	/* 0x6c90: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6c95:
	/* 0x6c95: movabs rax,0x7265666572656420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243107278868538400ULL);
x86_l_6c9f:
	/* 0x6c9f: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6ca4:
	/* 0x6ca4: movabs rax,0x6f742064656c6961 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8031079651078859105ULL);
x86_l_6cae:
	/* 0x6cae: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6cb3:
	/* 0x6cb3: movabs rax,0x6620646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358992216502005365ULL);
x86_l_6cbd:
	/* 0x6cbd: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6cc2:
	/* 0x6cc2: mov    DWORD PTR [rsp+0x38],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518854764ULL);
x86_l_6cca:
	/* 0x6cca: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6ccf:
	/* 0x6ccf: mov    eax,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_6cd4:
	/* 0x6cd4: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6cd9:
	/* 0x6cd9: mov    esi,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_6cde:
	/* 0x6cde: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6ce1:
	/* 0x6ce1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ce3:
	/* 0x6ce3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6ce5:
	/* 0x6ce5: jmp    6e24 <kprobe_unwind_native+0x6e24> */
	goto x86_l_6e24;
x86_l_6cea:
	/* 0x6cea: shl    r12d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_6cee:
	/* 0x6cee: and    r12d,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 56ULL);
x86_l_6cf2:
	/* 0x6cf2: add    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_6cf7:
	/* 0x6cf7: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_6cfa:
	/* 0x6cfa: jmp    6e04 <kprobe_unwind_native+0x6e04> */
	goto x86_l_6e04;
x86_l_6cff:
	/* 0x6cff: movabs rax,0x2578302073736572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2699960892542641522ULL);
x86_l_6d09:
	/* 0x6d09: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6d0e:
	/* 0x6d0e: movabs rax,0x6464612065636e65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7234013693231722085ULL);
x86_l_6d18:
	/* 0x6d18: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6d1d:
	/* 0x6d1d: movabs rax,0x7265666572656420 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243107278868538400ULL);
x86_l_6d27:
	/* 0x6d27: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6d2c:
	/* 0x6d2c: movabs rax,0x6f742064656c6961 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8031079651078859105ULL);
x86_l_6d36:
	/* 0x6d36: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6d3b:
	/* 0x6d3b: movabs rax,0x6620646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7358992216502005365ULL);
x86_l_6d45:
	/* 0x6d45: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6d4a:
	/* 0x6d4a: mov    DWORD PTR [rsp+0x38],0xa786c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518854764ULL);
x86_l_6d52:
	/* 0x6d52: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6d57:
	/* 0x6d57: mov    eax,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_6d5c:
	/* 0x6d5c: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6d61:
	/* 0x6d61: mov    esi,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_6d66:
	/* 0x6d66: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_6d69:
	/* 0x6d69: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6d6b:
	/* 0x6d6b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6d6d:
	/* 0x6d6d: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6d70:
	/* 0x6d70: jmp    6b94 <kprobe_unwind_native+0x6b94> */
	goto x86_l_6b94;
x86_l_6d75:
	/* 0x6d75: movabs rax,0xa756c252b642572 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 753627419551999346ULL);
x86_l_6d7f:
	/* 0x6d7f: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6d84:
	/* 0x6d84: movabs rax,0x203a646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2322278983241526901ULL);
x86_l_6d8e:
	/* 0x6d8e: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6d93:
	/* 0x6d93: mov    BYTE PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_6d98:
	/* 0x6d98: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6d9d:
	/* 0x6d9d: mov    eax,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_6da2:
	/* 0x6da2: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_6da8:
	/* 0x6da8: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_6dac:
	/* 0x6dac: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6db1:
	/* 0x6db1: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_6db6:
	/* 0x6db6: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_6db9:
	/* 0x6db9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6dbb:
	/* 0x6dbb: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_6dbe:
	/* 0x6dbe: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_6dc2:
	/* 0x6dc2: jle    6c07 <kprobe_unwind_native+0x6c07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_6c07;
	}
x86_l_6dc8:
	/* 0x6dc8: mov    rax,QWORD PTR [rsp+0x150] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 336ULL);
x86_l_6dd0:
	/* 0x6dd0: mov    QWORD PTR [rsp+0x138],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_6dd8:
	/* 0x6dd8: cmp    r12d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 11ULL);
x86_l_6ddc:
	/* 0x6ddc: je     6df4 <kprobe_unwind_native+0x6df4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6df4;
	}
x86_l_6dde:
	/* 0x6dde: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_6de6:
	/* 0x6de6: mov    QWORD PTR [rsp+0x138],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_6dee:
	/* 0x6dee: cmp    r12d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 15ULL);
x86_l_6df2:
	/* 0x6df2: jne    6e24 <kprobe_unwind_native+0x6e24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6e24;
	}
x86_l_6df4:
	/* 0x6df4: mov    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6df9:
	/* 0x6df9: mov    rax,QWORD PTR [rsp+0x138] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_6e01:
	/* 0x6e01: add    rbp,QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_6e04:
	/* 0x6e04: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_6e07:
	/* 0x6e07: je     6e24 <kprobe_unwind_native+0x6e24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6e24;
	}
x86_l_6e09:
	/* 0x6e09: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6e0e:
	/* 0x6e0e: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_6e13:
	/* 0x6e13: mov    rdi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6e18:
	/* 0x6e18: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6e1d:
	/* 0x6e1d: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6e20:
	/* 0x6e20: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6e22:
	/* 0x6e22: jmp    6e3a <kprobe_unwind_native+0x6e3a> */
	goto x86_l_6e3a;
x86_l_6e24:
	/* 0x6e24: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6e29:
	/* 0x6e29: cmp    BYTE PTR [rax],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_6e2c:
	/* 0x6e2c: jne    6e3a <kprobe_unwind_native+0x6e3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6e3a;
	}
x86_l_6e2e:
	/* 0x6e2e: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6e33:
	/* 0x6e33: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6e3a:
	/* 0x6e3a: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_6e3d:
	/* 0x6e3d: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6e42:
	/* 0x6e42: je     1640 <kprobe_unwind_native+0x1640> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5696ULL;
	}
x86_l_6e48:
	/* 0x6e48: lea    rdx,[r13-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_6e4c:
	/* 0x6e4c: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6e51:
	/* 0x6e51: mov    ecx,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 112ULL);
x86_l_6e56:
	/* 0x6e56: mov    rdi,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_6e5e:
	/* 0x6e5e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6e63:
	/* 0x6e63: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6e65:
	/* 0x6e65: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6e68:
	/* 0x6e68: jne    1640 <kprobe_unwind_native+0x1640> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5696ULL;
	}
x86_l_6e6e:
	/* 0x6e6e: mov    QWORD PTR [rbx+0xed8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3800ULL);
x86_l_6e75:
	/* 0x6e75: mov    BYTE PTR [rbx+0xf30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16698832846849ULL);
x86_l_6e7c:
	/* 0x6e7c: mov    DWORD PTR [rsp+0x78],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075526ULL);
x86_l_6e84:
	/* 0x6e84: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_6e8b:
	/* 0x6e8b: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6e90:
	/* 0x6e90: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6e95:
	/* 0x6e95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e97:
	/* 0x6e97: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6e9a:
	/* 0x6e9a: je     6eb2 <kprobe_unwind_native+0x6eb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6eb2;
	}
x86_l_6e9c:
	/* 0x6e9c: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6e9f:
	/* 0x6e9f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ea1:
	/* 0x6ea1: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6ea8:
	/* 0x6ea8: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6eab:
	/* 0x6eab: je     6ec4 <kprobe_unwind_native+0x6ec4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6ec4;
	}
x86_l_6ead:
	/* 0x6ead: jmp    7281 <kprobe_unwind_native+0x7281> */
	goto x86_l_7281;
x86_l_6eb2:
	/* 0x6eb2: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6eb9:
	/* 0x6eb9: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ebc:
	/* 0x6ebc: jne    71f9 <kprobe_unwind_native+0x71f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_71f9;
	}
x86_l_6ec2:
	/* 0x6ec2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ec4:
	/* 0x6ec4: mov    rcx,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_6ecc:
	/* 0x6ecc: mov    r13,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ecf:
	/* 0x6ecf: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_6ed2:
	/* 0x6ed2: je     706b <kprobe_unwind_native+0x706b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_706b;
	}
x86_l_6ed8:
	/* 0x6ed8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6eda:
	/* 0x6eda: jne    730a <kprobe_unwind_native+0x730a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_730a;
	}
x86_l_6ee0:
	/* 0x6ee0: movabs rax,0xffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72057594037927935ULL);
x86_l_6eea:
	/* 0x6eea: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_6eed:
	/* 0x6eed: ja     3397 <kprobe_unwind_native+0x3397> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13207ULL;
	}
x86_l_6ef3:
	/* 0x6ef3: cmp    r13,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4096ULL);
x86_l_6efa:
	/* 0x6efa: jb     34dd <kprobe_unwind_native+0x34dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 13533ULL;
	}
x86_l_6f00:
	/* 0x6f00: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6f02:
	/* 0x6f02: mov    DWORD PTR [rsp+0x10],0x60 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476832ULL);
x86_l_6f0a:
	/* 0x6f0a: movbe  DWORD PTR [rsp+0x14],eax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_6f10:
	/* 0x6f10: movbe  QWORD PTR [rsp+0x18],r13 */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_6f17:
	/* 0x6f17: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_page_to_mapping_info)));
x86_l_6f1e:
	/* 0x6f1e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6f23:
	/* 0x6f23: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6f28:
	/* 0x6f28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f2a:
	/* 0x6f2a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6f2d:
	/* 0x6f2d: je     7127 <kprobe_unwind_native+0x7127> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7127;
	}
x86_l_6f33:
	/* 0x6f33: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6f37:
	/* 0x6f37: movabs rcx,0xffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 72057594037927935ULL);
x86_l_6f41:
	/* 0x6f41: and    rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_6f44:
	/* 0x6f44: mov    QWORD PTR [rbx+0xf20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3872ULL);
x86_l_6f4b:
	/* 0x6f4b: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6f4e:
	/* 0x6f4e: mov    QWORD PTR [rbx+0xf10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_6f55:
	/* 0x6f55: shr    r12,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHR, 56ULL);
x86_l_6f59:
	/* 0x6f59: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_6f5c:
	/* 0x6f5c: sub    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_6f5f:
	/* 0x6f5f: mov    QWORD PTR [rbx+0xf18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_6f66:
	/* 0x6f66: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6f6d:
	/* 0x6f6d: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6f70:
	/* 0x6f70: jne    73be <kprobe_unwind_native+0x73be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 29630ULL;
	}
x86_l_6f76:
	/* 0x6f76: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_6f7a:
	/* 0x6f7a: jne    75b1 <kprobe_unwind_native+0x75b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 30129ULL;
	}
x86_l_6f80:
	/* 0x6f80: mov    rax,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_6f87:
	/* 0x6f87: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6f8c:
	/* 0x6f8c: mov    r13,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_6f93:
	/* 0x6f93: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&interpreter_offsets)));
x86_l_6f9a:
	/* 0x6f9a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6f9f:
	/* 0x6f9f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6fa4:
	/* 0x6fa4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6fa6:
	/* 0x6fa6: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_6fac:
	/* 0x6fac: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6faf:
	/* 0x6faf: je     75b1 <kprobe_unwind_native+0x75b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 30129ULL;
	}
x86_l_6fb5:
	/* 0x6fb5: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_6fb8:
	/* 0x6fb8: cmp    QWORD PTR [rax],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6fbb:
	/* 0x6fbb: ja     6fc3 <kprobe_unwind_native+0x6fc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_6fc3;
	}
x86_l_6fbd:
	/* 0x6fbd: cmp    QWORD PTR [r15+0x8],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6fc1:
	/* 0x6fc1: jae    6fd7 <kprobe_unwind_native+0x6fd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_6fd7;
	}
x86_l_6fc3:
	/* 0x6fc3: cmp    QWORD PTR [r15+0x10],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6fc7:
	/* 0x6fc7: ja     75b1 <kprobe_unwind_native+0x75b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 30129ULL;
	}
x86_l_6fcd:
	/* 0x6fcd: cmp    QWORD PTR [r15+0x18],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6fd1:
	/* 0x6fd1: jb     75b1 <kprobe_unwind_native+0x75b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 30129ULL;
	}
x86_l_6fd7:
	/* 0x6fd7: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_6fde:
	/* 0x6fde: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6fe1:
	/* 0x6fe1: jne    7500 <kprobe_unwind_native+0x7500> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 29952ULL;
	}
x86_l_6fe7:
	/* 0x6fe7: mov    eax,DWORD PTR [rbx+0x1380] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4992ULL);
x86_l_6fed:
	/* 0x6fed: mov    ecx,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6ff1:
	/* 0x6ff1: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_6ff4:
	/* 0x6ff4: jae    757b <kprobe_unwind_native+0x757b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 30075ULL;
	}
x86_l_6ffa:
	/* 0x6ffa: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_7001:
	/* 0x7001: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7004:
	/* 0x7004: je     75b1 <kprobe_unwind_native+0x75b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 30129ULL;
	}
x86_l_700a:
	/* 0x700a: movabs rax,0x6e6f64207265646e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7957689157107934318ULL);
x86_l_7014:
	/* 0x7014: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_701c:
	/* 0x701c: movabs rax,0x69776e7520726574 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7599664345545598324ULL);
x86_l_7026:
	/* 0x7026: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_702e:
	/* 0x702e: movabs rax,0x6572707265746e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310028781806448233ULL);
x86_l_7038:
	/* 0x7038: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_7040:
	/* 0x7040: mov    DWORD PTR [rsp+0xb7],0xa656e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 785979696494ULL);
x86_l_704b:
	/* 0x704b: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_7053:
	/* 0x7053: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_7058:
	/* 0x7058: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_705d:
	/* 0x705d: mov    esi,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 27ULL);
x86_l_7062:
	/* 0x7062: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7064:
	/* 0x7064: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7066:
	/* 0x7066: jmp    75b1 <kprobe_unwind_native+0x75b1> */
	return 30129ULL;
x86_l_706b:
	/* 0x706b: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_7070:
	/* 0x7070: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7072:
	/* 0x7072: mov    r13,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_7079:
	/* 0x7079: jne    7093 <kprobe_unwind_native+0x7093> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7093;
	}
x86_l_707b:
	/* 0x707b: mov    DWORD PTR [rbx+0xf28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16664473108481ULL);
x86_l_7085:
	/* 0x7085: mov    r14d,0xfad */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4013ULL);
x86_l_708b:
	/* 0x708b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_708e:
	/* 0x708e: jmp    5f59 <kprobe_unwind_native+0x5f59> */
	return 24409ULL;
x86_l_7093:
	/* 0x7093: movabs rax,0xa2930203d3d2043 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 732169329448919107ULL);
x86_l_709d:
	/* 0x709d: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_70a5:
	/* 0x70a5: movabs rax,0x5028206572756c69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5775902142186744937ULL);
x86_l_70af:
	/* 0x70af: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_70b7:
	/* 0x70b7: movabs rax,0x616620646e69776e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7018332685024720750ULL);
x86_l_70c1:
	/* 0x70c1: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_70c9:
	/* 0x70c9: movabs rax,0x75206f7420657564 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8439868246242719076ULL);
x86_l_70d3:
	/* 0x70d3: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_70db:
	/* 0x70db: movabs rax,0x20646e69776e7520 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334111906139108640ULL);
x86_l_70e5:
	/* 0x70e5: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_70ed:
	/* 0x70ed: movabs rax,0x676e6970706f7453 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7453010364988355667ULL);
x86_l_70f7:
	/* 0x70f7: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_70ff:
	/* 0x70ff: mov    BYTE PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_7107:
	/* 0x7107: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_710f:
	/* 0x710f: mov    eax,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 49ULL);
x86_l_7114:
	/* 0x7114: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_7119:
	/* 0x7119: mov    esi,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 49ULL);
x86_l_711e:
	/* 0x711e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7120:
	/* 0x7120: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7122:
	/* 0x7122: jmp    707b <kprobe_unwind_native+0x707b> */
	goto x86_l_707b;
x86_l_7127:
	/* 0x7127: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_712c:
	/* 0x712c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_7133:
	/* 0x7133: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7136:
	/* 0x7136: jne    7150 <kprobe_unwind_native+0x7150> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7150;
	}
x86_l_7138:
	/* 0x7138: mov    DWORD PTR [rbx+0xf28],0xc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16664473108492ULL);
x86_l_7142:
	/* 0x7142: mov    r14d,0xfac */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4012ULL);
x86_l_7148:
	/* 0x7148: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_714b:
	/* 0x714b: jmp    5f52 <kprobe_unwind_native+0x5f52> */
	return 24402ULL;
x86_l_7150:
	/* 0x7150: movabs rax,0xa786c2578302043 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 754471845770567747ULL);
x86_l_715a:
	/* 0x715a: mov    QWORD PTR [rsp+0xd0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_7162:
	/* 0x7162: movabs rax,0x5020726f6620676e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5773740545069311854ULL);
x86_l_716c:
	/* 0x716c: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_7174:
	/* 0x7174: movabs rax,0x697070616d207972 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7597696135119010162ULL);
x86_l_717e:
	/* 0x717e: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_7186:
	/* 0x7186: movabs rax,0x6f6d656d206c6176 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8029185230041276790ULL);
x86_l_7190:
	/* 0x7190: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_7198:
	/* 0x7198: movabs rax,0x7265746e69207075 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243122710530519157ULL);
x86_l_71a2:
	/* 0x71a2: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_71aa:
	/* 0x71aa: movabs rax,0x206b6f6f6c206f74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2336083356067852148ULL);
x86_l_71b4:
	/* 0x71b4: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_71bc:
	/* 0x71bc: movabs rax,0x206572756c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334397830517055814ULL);
x86_l_71c6:
	/* 0x71c6: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_71ce:
	/* 0x71ce: mov    BYTE PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_71d6:
	/* 0x71d6: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_71de:
	/* 0x71de: mov    eax,0x39 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 57ULL);
x86_l_71e3:
	/* 0x71e3: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_71e8:
	/* 0x71e8: mov    esi,0x39 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 57ULL);
x86_l_71ed:
	/* 0x71ed: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_71f0:
	/* 0x71f0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_71f2:
	/* 0x71f2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_71f4:
	/* 0x71f4: jmp    7138 <kprobe_unwind_native+0x7138> */
	goto x86_l_7138;
x86_l_71f9:
	/* 0x71f9: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_7203:
	/* 0x7203: mov    QWORD PTR [rsp+0x36],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_7208:
	/* 0x7208: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_7212:
	/* 0x7212: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7217:
	/* 0x7217: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_7221:
	/* 0x7221: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7226:
	/* 0x7226: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_7230:
	/* 0x7230: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7235:
	/* 0x7235: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_723f:
	/* 0x723f: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7244:
	/* 0x7244: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_724e:
	/* 0x724e: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7253:
	/* 0x7253: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7258:
	/* 0x7258: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_725d:
	/* 0x725d: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_7262:
	/* 0x7262: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_7266:
	/* 0x7266: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_726b:
	/* 0x726b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_726d:
	/* 0x726d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_726f:
	/* 0x726f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7271:
	/* 0x7271: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_7278:
	/* 0x7278: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_727b:
	/* 0x727b: je     6ec4 <kprobe_unwind_native+0x6ec4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6ec4;
	}
x86_l_7281:
	/* 0x7281: movabs rax,0xa786c6c25203a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947156833280058ULL);
x86_l_728b:
	/* 0x728b: mov    QWORD PTR [rsp+0xb5],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 181ULL);
x86_l_7293:
	/* 0x7293: movabs rax,0x25203a706620786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675202433082226796ULL);
x86_l_729d:
	/* 0x729d: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_72a5:
	/* 0x72a5: movabs rax,0x6c25203a70732078 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7792670165601296504ULL);
x86_l_72af:
	/* 0x72af: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_72b7:
	/* 0x72b7: movabs rax,0x6c6c25203a637020 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660273929744416ULL);
x86_l_72c1:
	/* 0x72c1: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_72c9:
	/* 0x72c9: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_72d1:
	/* 0x72d1: mov    eax,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 29ULL);
x86_l_72d6:
	/* 0x72d6: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_72dc:
	/* 0x72dc: mov    rax,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_72e4:
	/* 0x72e4: mov    rdx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_72e7:
	/* 0x72e7: mov    rcx,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_72ea:
	/* 0x72ea: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_72ef:
	/* 0x72ef: mov    r8,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_72f2:
	/* 0x72f2: mov    esi,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 29ULL);
x86_l_72f7:
	/* 0x72f7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_72f9:
	/* 0x72f9: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_72fc:
	/* 0x72fc: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_7303:
	/* 0x7303: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7305:
	/* 0x7305: jmp    6ec4 <kprobe_unwind_native+0x6ec4> */
	goto x86_l_6ec4;
x86_l_730a:
	/* 0x730a: movabs rax,0xa3d3d3d3d206425 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 737813247186461733ULL);
x86_l_7314:
	/* 0x7314: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_731c:
	/* 0x731c: movabs rax,0x20656d617266203a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334392247160021050ULL);
x86_l_7326:
	/* 0x7326: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_732e:
	/* 0x732e: movabs rax,0x7265646e69776e75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8243105118350175861ULL);
x86_l_7338:
	/* 0x7338: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_7340:
	/* 0x7340: movabs rax,0x20656d6172662074 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334392247160021108ULL);
x86_l_734a:
	/* 0x734a: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7352:
	/* 0x7352: movabs rax,0x78656e2065766c6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8675461342619397231ULL);
x86_l_735c:
	/* 0x735c: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_7364:
	/* 0x7364: movabs rax,0x736552203d3d3d3d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8315142585429343549ULL);
	return 29550ULL;
}

static __noinline __u64 otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_15(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 29550ULL: goto x86_l_736e;
	case 29558ULL: goto x86_l_7376;
	case 29566ULL: goto x86_l_737e;
	case 29574ULL: goto x86_l_7386;
	case 29579ULL: goto x86_l_738b;
	case 29584ULL: goto x86_l_7390;
	case 29590ULL: goto x86_l_7396;
	case 29595ULL: goto x86_l_739b;
	case 29597ULL: goto x86_l_739d;
	case 29599ULL: goto x86_l_739f;
	case 29606ULL: goto x86_l_73a6;
	case 29616ULL: goto x86_l_73b0;
	case 29619ULL: goto x86_l_73b3;
	case 29625ULL: goto x86_l_73b9;
	case 29630ULL: goto x86_l_73be;
	case 29640ULL: goto x86_l_73c8;
	case 29648ULL: goto x86_l_73d0;
	case 29658ULL: goto x86_l_73da;
	case 29666ULL: goto x86_l_73e2;
	case 29676ULL: goto x86_l_73ec;
	case 29684ULL: goto x86_l_73f4;
	case 29694ULL: goto x86_l_73fe;
	case 29702ULL: goto x86_l_7406;
	case 29712ULL: goto x86_l_7410;
	case 29720ULL: goto x86_l_7418;
	case 29730ULL: goto x86_l_7422;
	case 29738ULL: goto x86_l_742a;
	case 29748ULL: goto x86_l_7434;
	case 29756ULL: goto x86_l_743c;
	case 29761ULL: goto x86_l_7441;
	case 29767ULL: goto x86_l_7447;
	case 29774ULL: goto x86_l_744e;
	case 29779ULL: goto x86_l_7453;
	case 29782ULL: goto x86_l_7456;
	case 29785ULL: goto x86_l_7459;
	case 29787ULL: goto x86_l_745b;
	case 29790ULL: goto x86_l_745e;
	case 29797ULL: goto x86_l_7465;
	case 29800ULL: goto x86_l_7468;
	case 29806ULL: goto x86_l_746e;
	case 29816ULL: goto x86_l_7478;
	case 29824ULL: goto x86_l_7480;
	case 29834ULL: goto x86_l_748a;
	case 29842ULL: goto x86_l_7492;
	case 29852ULL: goto x86_l_749c;
	case 29860ULL: goto x86_l_74a4;
	case 29870ULL: goto x86_l_74ae;
	case 29878ULL: goto x86_l_74b6;
	case 29888ULL: goto x86_l_74c0;
	case 29896ULL: goto x86_l_74c8;
	case 29904ULL: goto x86_l_74d0;
	case 29912ULL: goto x86_l_74d8;
	case 29917ULL: goto x86_l_74dd;
	case 29923ULL: goto x86_l_74e3;
	case 29930ULL: goto x86_l_74ea;
	case 29937ULL: goto x86_l_74f1;
	case 29942ULL: goto x86_l_74f6;
	case 29944ULL: goto x86_l_74f8;
	case 29947ULL: goto x86_l_74fb;
	case 29952ULL: goto x86_l_7500;
	case 29962ULL: goto x86_l_750a;
	case 29970ULL: goto x86_l_7512;
	case 29980ULL: goto x86_l_751c;
	case 29988ULL: goto x86_l_7524;
	case 29998ULL: goto x86_l_752e;
	case 30006ULL: goto x86_l_7536;
	case 30016ULL: goto x86_l_7540;
	case 30024ULL: goto x86_l_7548;
	case 30032ULL: goto x86_l_7550;
	case 30037ULL: goto x86_l_7555;
	case 30042ULL: goto x86_l_755a;
	case 30047ULL: goto x86_l_755f;
	case 30052ULL: goto x86_l_7564;
	case 30054ULL: goto x86_l_7566;
	case 30056ULL: goto x86_l_7568;
	case 30062ULL: goto x86_l_756e;
	case 30066ULL: goto x86_l_7572;
	case 30069ULL: goto x86_l_7575;
	case 30075ULL: goto x86_l_757b;
	case 30083ULL: goto x86_l_7583;
	case 30090ULL: goto x86_l_758a;
	case 30095ULL: goto x86_l_758f;
	case 30100ULL: goto x86_l_7594;
	case 30102ULL: goto x86_l_7596;
	case 30105ULL: goto x86_l_7599;
	case 30107ULL: goto x86_l_759b;
	case 30110ULL: goto x86_l_759e;
	case 30112ULL: goto x86_l_75a0;
	case 30119ULL: goto x86_l_75a7;
	case 30122ULL: goto x86_l_75aa;
	case 30124ULL: goto x86_l_75ac;
	case 30129ULL: goto x86_l_75b1;
	case 30134ULL: goto x86_l_75b6;
	case 30139ULL: goto x86_l_75bb;
	case 30149ULL: goto x86_l_75c5;
	case 30157ULL: goto x86_l_75cd;
	case 30167ULL: goto x86_l_75d7;
	case 30175ULL: goto x86_l_75df;
	case 30185ULL: goto x86_l_75e9;
	case 30193ULL: goto x86_l_75f1;
	case 30203ULL: goto x86_l_75fb;
	case 30211ULL: goto x86_l_7603;
	case 30221ULL: goto x86_l_760d;
	case 30229ULL: goto x86_l_7615;
	case 30239ULL: goto x86_l_761f;
	case 30247ULL: goto x86_l_7627;
	case 30255ULL: goto x86_l_762f;
	case 30260ULL: goto x86_l_7634;
	case 30265ULL: goto x86_l_7639;
	case 30269ULL: goto x86_l_763d;
	case 30274ULL: goto x86_l_7642;
	case 30276ULL: goto x86_l_7644;
	case 30278ULL: goto x86_l_7646;
	default: return 0xffffffffffffffffULL;
	}
x86_l_736e:
	/* 0x736e: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_7376:
	/* 0x7376: mov    BYTE PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_737e:
	/* 0x737e: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_7386:
	/* 0x7386: mov    eax,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 49ULL);
x86_l_738b:
	/* 0x738b: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_7390:
	/* 0x7390: mov    edx,DWORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704ULL);
x86_l_7396:
	/* 0x7396: mov    esi,0x31 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 49ULL);
x86_l_739b:
	/* 0x739b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_739d:
	/* 0x739d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_739f:
	/* 0x739f: mov    r13,QWORD PTR [rbx+0xed0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3792ULL);
x86_l_73a6:
	/* 0x73a6: movabs rax,0xffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72057594037927935ULL);
x86_l_73b0:
	/* 0x73b0: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_73b3:
	/* 0x73b3: ja     3397 <kprobe_unwind_native+0x3397> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13207ULL;
	}
x86_l_73b9:
	/* 0x73b9: jmp    6ef3 <kprobe_unwind_native+0x6ef3> */
	return 28403ULL;
x86_l_73be:
	/* 0x73be: movabs rax,0x296425207265646e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2982549674514539630ULL);
x86_l_73c8:
	/* 0x73c8: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_73d0:
	/* 0x73d0: movabs rax,0x69776e752820786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7599664345674446956ULL);
x86_l_73da:
	/* 0x73da: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_73e2:
	/* 0x73e2: movabs rax,0x6c2520736920786c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7792670410291574892ULL);
x86_l_73ec:
	/* 0x73ec: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_73f4:
	/* 0x73f4: movabs rax,0x2520435020726f66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2675212190078889830ULL);
x86_l_73fe:
	/* 0x73fe: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7406:
	/* 0x7406: movabs rax,0x206469206e6f6974 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2334106094897424756ULL);
x86_l_7410:
	/* 0x7410: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_7418:
	/* 0x7418: movabs r15,0x6365732074786554 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 7162257365632836948ULL);
x86_l_7422:
	/* 0x7422: mov    QWORD PTR [rsp+0xa0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_742a:
	/* 0x742a: mov    WORD PTR [rsp+0xd0],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 893353197578ULL);
x86_l_7434:
	/* 0x7434: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_743c:
	/* 0x743c: mov    eax,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_7441:
	/* 0x7441: mov    r9d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 6ULL);
x86_l_7447:
	/* 0x7447: mov    rcx,QWORD PTR [rbx+0xf10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3856ULL);
x86_l_744e:
	/* 0x744e: mov    esi,0x32 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 50ULL);
x86_l_7453:
	/* 0x7453: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_7456:
	/* 0x7456: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_7459:
	/* 0x7459: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_745b:
	/* 0x745b: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_745e:
	/* 0x745e: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_7465:
	/* 0x7465: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7468:
	/* 0x7468: je     6f76 <kprobe_unwind_native+0x6f76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 28534ULL;
	}
x86_l_746e:
	/* 0x746e: movabs rax,0xa786c6c252073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2947156833280115ULL);
x86_l_7478:
	/* 0x7478: mov    QWORD PTR [rsp+0xc7],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 199ULL);
x86_l_7480:
	/* 0x7480: movabs rax,0x7369207465736666 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8316213871206688358ULL);
x86_l_748a:
	/* 0x748a: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_7492:
	/* 0x7492: movabs rax,0x6f20646e61202c78 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8007510562703420536ULL);
x86_l_749c:
	/* 0x749c: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_74a4:
	/* 0x74a4: movabs rax,0x6c6c252073692073 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7812660274886418547ULL);
x86_l_74ae:
	/* 0x74ae: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_74b6:
	/* 0x74b6: movabs rax,0x616962206e6f6974 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7019249385664899444ULL);
x86_l_74c0:
	/* 0x74c0: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_74c8:
	/* 0x74c8: mov    QWORD PTR [rsp+0xa0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_74d0:
	/* 0x74d0: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_74d8:
	/* 0x74d8: mov    eax,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 47ULL);
x86_l_74dd:
	/* 0x74dd: mov    r8d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 6ULL);
x86_l_74e3:
	/* 0x74e3: mov    rcx,QWORD PTR [rbx+0xf18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3864ULL);
x86_l_74ea:
	/* 0x74ea: mov    rdx,QWORD PTR [rbx+0xf20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3872ULL);
x86_l_74f1:
	/* 0x74f1: mov    esi,0x2f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 47ULL);
x86_l_74f6:
	/* 0x74f6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_74f8:
	/* 0x74f8: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_74fb:
	/* 0x74fb: jmp    6f76 <kprobe_unwind_native+0x6f76> */
	return 28534ULL;
x86_l_7500:
	/* 0x7500: movabs rax,0xa642520686374 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860387386228ULL);
x86_l_750a:
	/* 0x750a: mov    QWORD PTR [rsp+0xb6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_7512:
	/* 0x7512: movabs rax,0x6374616d20737465 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7166460028377068645ULL);
x86_l_751c:
	/* 0x751c: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7524:
	/* 0x7524: movabs rax,0x7366666f5f726574 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8315446390514935156ULL);
x86_l_752e:
	/* 0x752e: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_7536:
	/* 0x7536: movabs rax,0x6572707265746e69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310028781806448233ULL);
x86_l_7540:
	/* 0x7540: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_7548:
	/* 0x7548: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_7550:
	/* 0x7550: mov    eax,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 30ULL);
x86_l_7555:
	/* 0x7555: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_755a:
	/* 0x755a: movzx  edx,WORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_755f:
	/* 0x755f: mov    esi,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 30ULL);
x86_l_7564:
	/* 0x7564: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7566:
	/* 0x7566: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7568:
	/* 0x7568: mov    eax,DWORD PTR [rbx+0x1380] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4992ULL);
x86_l_756e:
	/* 0x756e: mov    ecx,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7572:
	/* 0x7572: bt     eax,ecx */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_7575:
	/* 0x7575: jb     6ffa <kprobe_unwind_native+0x6ffa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 28666ULL;
	}
x86_l_757b:
	/* 0x757b: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_7583:
	/* 0x7583: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&metrics)));
x86_l_758a:
	/* 0x758a: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_758f:
	/* 0x758f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7594:
	/* 0x7594: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7596:
	/* 0x7596: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7599:
	/* 0x7599: je     75a0 <kprobe_unwind_native+0x75a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_75a0;
	}
x86_l_759b:
	/* 0x759b: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_759e:
	/* 0x759e: jmp    75ac <kprobe_unwind_native+0x75ac> */
	goto x86_l_75ac;
x86_l_75a0:
	/* 0x75a0: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&with_debug_output)));
x86_l_75a7:
	/* 0x75a7: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_75aa:
	/* 0x75aa: jne    75bb <kprobe_unwind_native+0x75bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_75bb;
	}
x86_l_75ac:
	/* 0x75ac: movzx  r12d,WORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_75b1:
	/* 0x75b1: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_75b6:
	/* 0x75b6: jmp    5f52 <kprobe_unwind_native+0x5f52> */
	return 24402ULL;
x86_l_75bb:
	/* 0x75bb: movabs rax,0xa642520444963 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2924860385020259ULL);
x86_l_75c5:
	/* 0x75c5: mov    QWORD PTR [rsp+0xc6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 198ULL);
x86_l_75cd:
	/* 0x75cd: movabs rax,0x4963697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 5288186327763086624ULL);
x86_l_75d7:
	/* 0x75d7: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_75df:
	/* 0x75df: movabs rax,0x726f662070616d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8245921732249087264ULL);
x86_l_75e9:
	/* 0x75e9: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_75f1:
	/* 0x75f1: movabs rax,0x7363697274656d20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8314605277356059936ULL);
x86_l_75fb:
	/* 0x75fb: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7603:
	/* 0x7603: movabs rax,0x70756b6f6f6c206f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8103501230877974639ULL);
x86_l_760d:
	/* 0x760d: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_7615:
	/* 0x7615: movabs rax,0x742064656c696146 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8367798494427701574ULL);
x86_l_761f:
	/* 0x761f: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_7627:
	/* 0x7627: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_762f:
	/* 0x762f: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_7634:
	/* 0x7634: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_7639:
	/* 0x7639: mov    edx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_763d:
	/* 0x763d: mov    esi,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 46ULL);
x86_l_7642:
	/* 0x7642: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7644:
	/* 0x7644: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7646:
	/* 0x7646: jmp    75ac <kprobe_unwind_native+0x75ac> */
	goto x86_l_75ac;
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
	for (__u32 __x86_iter = 0; __x86_iter < 23492U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1798ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1802ULL && __x86_pc <= 3667ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3671ULL && __x86_pc <= 5752ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5758ULL && __x86_pc <= 8066ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 8074ULL && __x86_pc <= 9659ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9662ULL && __x86_pc <= 11604ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 11606ULL && __x86_pc <= 13719ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 13729ULL && __x86_pc <= 15824ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 15827ULL && __x86_pc <= 17403ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 17406ULL && __x86_pc <= 19496ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 19498ULL && __x86_pc <= 21635ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 21641ULL && __x86_pc <= 23503ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 23506ULL && __x86_pc <= 25314ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 25317ULL && __x86_pc <= 27463ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_13(__x86_state, __x86_pc);
		else if (__x86_pc >= 27468ULL && __x86_pc <= 29540ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_14(__x86_state, __x86_pc);
		else if (__x86_pc >= 29550ULL && __x86_pc <= 30278ULL)
			__x86_pc = otelcol_ebpf_profiler_kprobe_unwind_native_x86_chunk_15(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

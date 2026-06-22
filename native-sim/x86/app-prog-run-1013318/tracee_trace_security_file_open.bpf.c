extern char binary_filter_version;
extern char bufs;
extern char cgroup_id_filter_version;
extern char comm_filter_version;
extern char config_map;
extern char containers_map;
extern char data_filter_bufs;
extern char data_filter_exact_version;
extern char data_filter_lpm_bufs;
extern char data_filter_prefix_version;
extern char data_filter_suffix_version;
extern char event_data_map;
extern char events;
extern char events_map_version;
extern char mnt_ns_filter_version;
extern char pid_filter_version;
extern char pid_ns_filter_version;
extern char proc_info_map;
extern char process_tree_map_version;
extern char scratch_map;
extern char stack_addresses;
extern char sys_32_to_64_map;
extern char task_info_map;
extern char uid_filter_version;
extern char uts_ns_filter_version;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tracee_trace_security_file_open_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 18ULL: goto x86_l_12;
	case 23ULL: goto x86_l_17;
	case 25ULL: goto x86_l_19;
	case 28ULL: goto x86_l_1c;
	case 33ULL: goto x86_l_21;
	case 35ULL: goto x86_l_23;
	case 38ULL: goto x86_l_26;
	case 42ULL: goto x86_l_2a;
	case 47ULL: goto x86_l_2f;
	case 52ULL: goto x86_l_34;
	case 57ULL: goto x86_l_39;
	case 59ULL: goto x86_l_3b;
	case 67ULL: goto x86_l_43;
	case 72ULL: goto x86_l_48;
	case 74ULL: goto x86_l_4a;
	case 79ULL: goto x86_l_4f;
	case 81ULL: goto x86_l_51;
	case 86ULL: goto x86_l_56;
	case 89ULL: goto x86_l_59;
	case 91ULL: goto x86_l_5b;
	case 95ULL: goto x86_l_5f;
	case 100ULL: goto x86_l_64;
	case 105ULL: goto x86_l_69;
	case 110ULL: goto x86_l_6e;
	case 112ULL: goto x86_l_70;
	case 116ULL: goto x86_l_74;
	case 120ULL: goto x86_l_78;
	case 125ULL: goto x86_l_7d;
	case 130ULL: goto x86_l_82;
	case 135ULL: goto x86_l_87;
	case 138ULL: goto x86_l_8a;
	case 140ULL: goto x86_l_8c;
	case 145ULL: goto x86_l_91;
	case 147ULL: goto x86_l_93;
	case 151ULL: goto x86_l_97;
	case 153ULL: goto x86_l_99;
	case 158ULL: goto x86_l_9e;
	case 165ULL: goto x86_l_a5;
	case 170ULL: goto x86_l_aa;
	case 172ULL: goto x86_l_ac;
	case 175ULL: goto x86_l_af;
	case 177ULL: goto x86_l_b1;
	case 179ULL: goto x86_l_b3;
	case 181ULL: goto x86_l_b5;
	case 186ULL: goto x86_l_ba;
	case 194ULL: goto x86_l_c2;
	case 199ULL: goto x86_l_c7;
	case 206ULL: goto x86_l_ce;
	case 211ULL: goto x86_l_d3;
	case 213ULL: goto x86_l_d5;
	case 216ULL: goto x86_l_d8;
	case 222ULL: goto x86_l_de;
	case 225ULL: goto x86_l_e1;
	case 230ULL: goto x86_l_e6;
	case 237ULL: goto x86_l_ed;
	case 242ULL: goto x86_l_f2;
	case 244ULL: goto x86_l_f4;
	case 247ULL: goto x86_l_f7;
	case 253ULL: goto x86_l_fd;
	case 256ULL: goto x86_l_100;
	case 266ULL: goto x86_l_10a;
	case 274ULL: goto x86_l_112;
	case 285ULL: goto x86_l_11d;
	case 296ULL: goto x86_l_128;
	case 307ULL: goto x86_l_133;
	case 318ULL: goto x86_l_13e;
	case 329ULL: goto x86_l_149;
	case 340ULL: goto x86_l_154;
	case 351ULL: goto x86_l_15f;
	case 362ULL: goto x86_l_16a;
	case 369ULL: goto x86_l_171;
	case 377ULL: goto x86_l_179;
	case 385ULL: goto x86_l_181;
	case 393ULL: goto x86_l_189;
	case 401ULL: goto x86_l_191;
	case 409ULL: goto x86_l_199;
	case 417ULL: goto x86_l_1a1;
	case 425ULL: goto x86_l_1a9;
	case 433ULL: goto x86_l_1b1;
	case 441ULL: goto x86_l_1b9;
	case 449ULL: goto x86_l_1c1;
	case 457ULL: goto x86_l_1c9;
	case 465ULL: goto x86_l_1d1;
	case 473ULL: goto x86_l_1d9;
	case 478ULL: goto x86_l_1de;
	case 480ULL: goto x86_l_1e0;
	case 484ULL: goto x86_l_1e4;
	case 488ULL: goto x86_l_1e8;
	case 492ULL: goto x86_l_1ec;
	case 500ULL: goto x86_l_1f4;
	case 505ULL: goto x86_l_1f9;
	case 507ULL: goto x86_l_1fb;
	case 510ULL: goto x86_l_1fe;
	case 515ULL: goto x86_l_203;
	case 517ULL: goto x86_l_205;
	case 522ULL: goto x86_l_20a;
	case 526ULL: goto x86_l_20e;
	case 530ULL: goto x86_l_212;
	case 537ULL: goto x86_l_219;
	case 542ULL: goto x86_l_21e;
	case 549ULL: goto x86_l_225;
	case 557ULL: goto x86_l_22d;
	case 559ULL: goto x86_l_22f;
	case 564ULL: goto x86_l_234;
	case 567ULL: goto x86_l_237;
	case 569ULL: goto x86_l_239;
	case 573ULL: goto x86_l_23d;
	case 580ULL: goto x86_l_244;
	case 585ULL: goto x86_l_249;
	case 592ULL: goto x86_l_250;
	case 600ULL: goto x86_l_258;
	case 608ULL: goto x86_l_260;
	case 610ULL: goto x86_l_262;
	case 613ULL: goto x86_l_265;
	case 616ULL: goto x86_l_268;
	case 624ULL: goto x86_l_270;
	case 630ULL: goto x86_l_276;
	case 635ULL: goto x86_l_27b;
	case 641ULL: goto x86_l_281;
	case 646ULL: goto x86_l_286;
	case 648ULL: goto x86_l_288;
	case 653ULL: goto x86_l_28d;
	case 660ULL: goto x86_l_294;
	case 664ULL: goto x86_l_298;
	case 672ULL: goto x86_l_2a0;
	case 677ULL: goto x86_l_2a5;
	case 684ULL: goto x86_l_2ac;
	case 689ULL: goto x86_l_2b1;
	case 691ULL: goto x86_l_2b3;
	case 694ULL: goto x86_l_2b6;
	case 700ULL: goto x86_l_2bc;
	case 704ULL: goto x86_l_2c0;
	case 708ULL: goto x86_l_2c4;
	case 719ULL: goto x86_l_2cf;
	case 730ULL: goto x86_l_2da;
	case 741ULL: goto x86_l_2e5;
	case 752ULL: goto x86_l_2f0;
	case 763ULL: goto x86_l_2fb;
	case 774ULL: goto x86_l_306;
	case 785ULL: goto x86_l_311;
	case 796ULL: goto x86_l_31c;
	case 807ULL: goto x86_l_327;
	case 818ULL: goto x86_l_332;
	case 829ULL: goto x86_l_33d;
	case 840ULL: goto x86_l_348;
	case 851ULL: goto x86_l_353;
	case 862ULL: goto x86_l_35e;
	case 873ULL: goto x86_l_369;
	case 884ULL: goto x86_l_374;
	case 895ULL: goto x86_l_37f;
	case 906ULL: goto x86_l_38a;
	case 917ULL: goto x86_l_395;
	case 928ULL: goto x86_l_3a0;
	case 939ULL: goto x86_l_3ab;
	case 950ULL: goto x86_l_3b6;
	case 961ULL: goto x86_l_3c1;
	case 972ULL: goto x86_l_3cc;
	case 983ULL: goto x86_l_3d7;
	case 994ULL: goto x86_l_3e2;
	case 1005ULL: goto x86_l_3ed;
	case 1016ULL: goto x86_l_3f8;
	case 1027ULL: goto x86_l_403;
	case 1038ULL: goto x86_l_40e;
	case 1046ULL: goto x86_l_416;
	case 1054ULL: goto x86_l_41e;
	case 1062ULL: goto x86_l_426;
	case 1070ULL: goto x86_l_42e;
	case 1078ULL: goto x86_l_436;
	case 1086ULL: goto x86_l_43e;
	case 1094ULL: goto x86_l_446;
	case 1102ULL: goto x86_l_44e;
	case 1110ULL: goto x86_l_456;
	case 1118ULL: goto x86_l_45e;
	case 1126ULL: goto x86_l_466;
	case 1134ULL: goto x86_l_46e;
	case 1142ULL: goto x86_l_476;
	case 1150ULL: goto x86_l_47e;
	case 1158ULL: goto x86_l_486;
	case 1165ULL: goto x86_l_48d;
	case 1171ULL: goto x86_l_493;
	case 1178ULL: goto x86_l_49a;
	case 1183ULL: goto x86_l_49f;
	case 1188ULL: goto x86_l_4a4;
	case 1191ULL: goto x86_l_4a7;
	case 1194ULL: goto x86_l_4aa;
	case 1197ULL: goto x86_l_4ad;
	case 1202ULL: goto x86_l_4b2;
	case 1207ULL: goto x86_l_4b7;
	case 1210ULL: goto x86_l_4ba;
	case 1212ULL: goto x86_l_4bc;
	case 1217ULL: goto x86_l_4c1;
	case 1220ULL: goto x86_l_4c4;
	case 1226ULL: goto x86_l_4ca;
	case 1231ULL: goto x86_l_4cf;
	case 1238ULL: goto x86_l_4d6;
	case 1242ULL: goto x86_l_4da;
	case 1250ULL: goto x86_l_4e2;
	case 1255ULL: goto x86_l_4e7;
	case 1262ULL: goto x86_l_4ee;
	case 1267ULL: goto x86_l_4f3;
	case 1269ULL: goto x86_l_4f5;
	case 1272ULL: goto x86_l_4f8;
	case 1278ULL: goto x86_l_4fe;
	case 1282ULL: goto x86_l_502;
	case 1286ULL: goto x86_l_506;
	case 1297ULL: goto x86_l_511;
	case 1308ULL: goto x86_l_51c;
	case 1319ULL: goto x86_l_527;
	case 1330ULL: goto x86_l_532;
	case 1341ULL: goto x86_l_53d;
	case 1352ULL: goto x86_l_548;
	case 1363ULL: goto x86_l_553;
	case 1374ULL: goto x86_l_55e;
	case 1385ULL: goto x86_l_569;
	case 1393ULL: goto x86_l_571;
	case 1401ULL: goto x86_l_579;
	case 1409ULL: goto x86_l_581;
	case 1417ULL: goto x86_l_589;
	case 1425ULL: goto x86_l_591;
	case 1433ULL: goto x86_l_599;
	case 1441ULL: goto x86_l_5a1;
	case 1449ULL: goto x86_l_5a9;
	case 1457ULL: goto x86_l_5b1;
	case 1465ULL: goto x86_l_5b9;
	case 1473ULL: goto x86_l_5c1;
	case 1481ULL: goto x86_l_5c9;
	case 1489ULL: goto x86_l_5d1;
	case 1497ULL: goto x86_l_5d9;
	case 1505ULL: goto x86_l_5e1;
	case 1512ULL: goto x86_l_5e8;
	case 1518ULL: goto x86_l_5ee;
	case 1525ULL: goto x86_l_5f5;
	case 1530ULL: goto x86_l_5fa;
	case 1535ULL: goto x86_l_5ff;
	case 1538ULL: goto x86_l_602;
	case 1541ULL: goto x86_l_605;
	case 1544ULL: goto x86_l_608;
	case 1549ULL: goto x86_l_60d;
	case 1554ULL: goto x86_l_612;
	case 1557ULL: goto x86_l_615;
	case 1559ULL: goto x86_l_617;
	case 1562ULL: goto x86_l_61a;
	case 1568ULL: goto x86_l_620;
	case 1571ULL: goto x86_l_623;
	case 1578ULL: goto x86_l_62a;
	case 1583ULL: goto x86_l_62f;
	case 1588ULL: goto x86_l_634;
	case 1593ULL: goto x86_l_639;
	case 1598ULL: goto x86_l_63e;
	case 1601ULL: goto x86_l_641;
	case 1603ULL: goto x86_l_643;
	case 1608ULL: goto x86_l_648;
	case 1616ULL: goto x86_l_650;
	case 1620ULL: goto x86_l_654;
	case 1625ULL: goto x86_l_659;
	case 1630ULL: goto x86_l_65e;
	case 1635ULL: goto x86_l_663;
	case 1637ULL: goto x86_l_665;
	case 1642ULL: goto x86_l_66a;
	case 1646ULL: goto x86_l_66e;
	case 1651ULL: goto x86_l_673;
	case 1656ULL: goto x86_l_678;
	case 1661ULL: goto x86_l_67d;
	case 1663ULL: goto x86_l_67f;
	case 1668ULL: goto x86_l_684;
	case 1672ULL: goto x86_l_688;
	case 1677ULL: goto x86_l_68d;
	case 1682ULL: goto x86_l_692;
	case 1687ULL: goto x86_l_697;
	case 1689ULL: goto x86_l_699;
	case 1693ULL: goto x86_l_69d;
	case 1696ULL: goto x86_l_6a0;
	case 1704ULL: goto x86_l_6a8;
	case 1708ULL: goto x86_l_6ac;
	case 1713ULL: goto x86_l_6b1;
	case 1718ULL: goto x86_l_6b6;
	case 1723ULL: goto x86_l_6bb;
	case 1726ULL: goto x86_l_6be;
	case 1728ULL: goto x86_l_6c0;
	case 1733ULL: goto x86_l_6c5;
	case 1738ULL: goto x86_l_6ca;
	case 1743ULL: goto x86_l_6cf;
	case 1748ULL: goto x86_l_6d4;
	case 1751ULL: goto x86_l_6d7;
	case 1753ULL: goto x86_l_6d9;
	case 1757ULL: goto x86_l_6dd;
	case 1761ULL: goto x86_l_6e1;
	case 1765ULL: goto x86_l_6e5;
	case 1769ULL: goto x86_l_6e9;
	case 1774ULL: goto x86_l_6ee;
	case 1779ULL: goto x86_l_6f3;
	case 1784ULL: goto x86_l_6f8;
	case 1786ULL: goto x86_l_6fa;
	case 1790ULL: goto x86_l_6fe;
	case 1793ULL: goto x86_l_701;
	case 1798ULL: goto x86_l_706;
	case 1803ULL: goto x86_l_70b;
	case 1808ULL: goto x86_l_710;
	case 1811ULL: goto x86_l_713;
	case 1813ULL: goto x86_l_715;
	case 1818ULL: goto x86_l_71a;
	case 1822ULL: goto x86_l_71e;
	case 1827ULL: goto x86_l_723;
	case 1832ULL: goto x86_l_728;
	case 1837ULL: goto x86_l_72d;
	case 1839ULL: goto x86_l_72f;
	case 1844ULL: goto x86_l_734;
	case 1849ULL: goto x86_l_739;
	case 1854ULL: goto x86_l_73e;
	case 1859ULL: goto x86_l_743;
	case 1862ULL: goto x86_l_746;
	case 1864ULL: goto x86_l_748;
	case 1868ULL: goto x86_l_74c;
	case 1872ULL: goto x86_l_750;
	case 1876ULL: goto x86_l_754;
	case 1880ULL: goto x86_l_758;
	case 1885ULL: goto x86_l_75d;
	case 1890ULL: goto x86_l_762;
	case 1895ULL: goto x86_l_767;
	case 1897ULL: goto x86_l_769;
	case 1901ULL: goto x86_l_76d;
	case 1904ULL: goto x86_l_770;
	case 1909ULL: goto x86_l_775;
	case 1914ULL: goto x86_l_77a;
	case 1919ULL: goto x86_l_77f;
	case 1922ULL: goto x86_l_782;
	case 1924ULL: goto x86_l_784;
	case 1929ULL: goto x86_l_789;
	case 1934ULL: goto x86_l_78e;
	case 1939ULL: goto x86_l_793;
	case 1944ULL: goto x86_l_798;
	case 1947ULL: goto x86_l_79b;
	case 1949ULL: goto x86_l_79d;
	case 1953ULL: goto x86_l_7a1;
	case 1957ULL: goto x86_l_7a5;
	case 1961ULL: goto x86_l_7a9;
	case 1965ULL: goto x86_l_7ad;
	case 1970ULL: goto x86_l_7b2;
	case 1975ULL: goto x86_l_7b7;
	case 1980ULL: goto x86_l_7bc;
	case 1982ULL: goto x86_l_7be;
	case 1987ULL: goto x86_l_7c3;
	case 1991ULL: goto x86_l_7c7;
	case 1996ULL: goto x86_l_7cc;
	case 2001ULL: goto x86_l_7d1;
	case 2006ULL: goto x86_l_7d6;
	case 2008ULL: goto x86_l_7d8;
	case 2011ULL: goto x86_l_7db;
	case 2015ULL: goto x86_l_7df;
	case 2020ULL: goto x86_l_7e4;
	case 2024ULL: goto x86_l_7e8;
	case 2029ULL: goto x86_l_7ed;
	case 2034ULL: goto x86_l_7f2;
	case 2039ULL: goto x86_l_7f7;
	case 2042ULL: goto x86_l_7fa;
	case 2044ULL: goto x86_l_7fc;
	case 2049ULL: goto x86_l_801;
	case 2054ULL: goto x86_l_806;
	case 2059ULL: goto x86_l_80b;
	case 2064ULL: goto x86_l_810;
	case 2067ULL: goto x86_l_813;
	case 2069ULL: goto x86_l_815;
	case 2073ULL: goto x86_l_819;
	case 2077ULL: goto x86_l_81d;
	case 2081ULL: goto x86_l_821;
	case 2085ULL: goto x86_l_825;
	case 2090ULL: goto x86_l_82a;
	case 2095ULL: goto x86_l_82f;
	case 2100ULL: goto x86_l_834;
	case 2102ULL: goto x86_l_836;
	case 2107ULL: goto x86_l_83b;
	case 2111ULL: goto x86_l_83f;
	case 2116ULL: goto x86_l_844;
	case 2121ULL: goto x86_l_849;
	case 2126ULL: goto x86_l_84e;
	case 2128ULL: goto x86_l_850;
	case 2132ULL: goto x86_l_854;
	case 2134ULL: goto x86_l_856;
	case 2139ULL: goto x86_l_85b;
	case 2144ULL: goto x86_l_860;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 200ULL);
x86_l_a:
	/* 0xa: mov    QWORD PTR [rsp+0xc0],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_12:
	/* 0x12: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_17:
	/* 0x17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19:
	/* 0x19: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1c:
	/* 0x1c: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_21:
	/* 0x21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23:
	/* 0x23: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_26:
	/* 0x26: lea    rdx,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2a:
	/* 0x2a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f:
	/* 0x2f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_34:
	/* 0x34: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_39:
	/* 0x39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b:
	/* 0x3b: test   DWORD PTR [rsp+0x30],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206160527360ULL);
x86_l_43:
	/* 0x43: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_48:
	/* 0x48: jne    ba <trace_security_file_open+0xba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ba;
	}
x86_l_4a:
	/* 0x4a: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_4f:
	/* 0x4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51:
	/* 0x51: mov    ecx,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 175ULL);
x86_l_56:
	/* 0x56: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_59:
	/* 0x59: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5b:
	/* 0x5b: lea    rdx,[rax+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_5f:
	/* 0x5f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_64:
	/* 0x64: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_69:
	/* 0x69: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6e:
	/* 0x6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_70:
	/* 0x70: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_74:
	/* 0x74: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_78:
	/* 0x78: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7d:
	/* 0x7d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_82:
	/* 0x82: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_87:
	/* 0x87: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_8a:
	/* 0x8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c:
	/* 0x8c: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_91:
	/* 0x91: jne    99 <trace_security_file_open+0x99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_99;
	}
x86_l_93:
	/* 0x93: mov    ebp,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_97:
	/* 0x97: jmp    ba <trace_security_file_open+0xba> */
	goto x86_l_ba;
x86_l_99:
	/* 0x99: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9e:
	/* 0x9e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_a5:
	/* 0xa5: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_aa:
	/* 0xaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac:
	/* 0xac: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_af:
	/* 0xaf: je     b5 <trace_security_file_open+0xb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b5;
	}
x86_l_b1:
	/* 0xb1: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b3:
	/* 0xb3: jmp    ba <trace_security_file_open+0xba> */
	goto x86_l_ba;
x86_l_b5:
	/* 0xb5: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_ba:
	/* 0xba: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_c2:
	/* 0xc2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c7:
	/* 0xc7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_ce:
	/* 0xce: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d3:
	/* 0xd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d5:
	/* 0xd5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d8:
	/* 0xd8: je     1e70 <trace_security_file_open+0x1e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7792ULL;
	}
x86_l_de:
	/* 0xde: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_e1:
	/* 0xe1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e6:
	/* 0xe6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_ed:
	/* 0xed: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f2:
	/* 0xf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f4:
	/* 0xf4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f7:
	/* 0xf7: je     1e70 <trace_security_file_open+0x1e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7792ULL;
	}
x86_l_fd:
	/* 0xfd: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_100:
	/* 0x100: mov    WORD PTR [r14+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_10a:
	/* 0x10a: mov    BYTE PTR [r14+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_112:
	/* 0x112: mov    QWORD PTR [r14+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_11d:
	/* 0x11d: mov    QWORD PTR [r14+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_128:
	/* 0x128: mov    QWORD PTR [r14+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_133:
	/* 0x133: mov    QWORD PTR [r14+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_13e:
	/* 0x13e: mov    QWORD PTR [r14+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_149:
	/* 0x149: mov    QWORD PTR [r14+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_154:
	/* 0x154: mov    QWORD PTR [r14+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_15f:
	/* 0x15f: mov    QWORD PTR [r14+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_16a:
	/* 0x16a: mov    QWORD PTR [r14+0x7dd0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_171:
	/* 0x171: mov    QWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_179:
	/* 0x179: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_181:
	/* 0x181: mov    QWORD PTR [r14+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_189:
	/* 0x189: mov    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_191:
	/* 0x191: mov    QWORD PTR [r14+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_199:
	/* 0x199: mov    QWORD PTR [r14+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1a1:
	/* 0x1a1: mov    QWORD PTR [r14+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1a9:
	/* 0x1a9: mov    QWORD PTR [r14+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1b1:
	/* 0x1b1: mov    QWORD PTR [r14+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1b9:
	/* 0x1b9: mov    QWORD PTR [r14+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1c1:
	/* 0x1c1: mov    QWORD PTR [r14+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1c9:
	/* 0x1c9: mov    QWORD PTR [r14+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1d1:
	/* 0x1d1: mov    QWORD PTR [r14+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1d9:
	/* 0x1d9: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1de:
	/* 0x1de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e0:
	/* 0x1e0: mov    DWORD PTR [r14+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e4:
	/* 0x1e4: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1e8:
	/* 0x1e8: mov    DWORD PTR [r14+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1ec:
	/* 0x1ec: mov    DWORD PTR [r14+0x70],0x2dc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337884ULL);
x86_l_1f4:
	/* 0x1f4: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_1f9:
	/* 0x1f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb:
	/* 0x1fb: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fe:
	/* 0x1fe: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_203:
	/* 0x203: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_205:
	/* 0x205: mov    WORD PTR [r14+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_20a:
	/* 0x20a: mov    DWORD PTR [r14+0x74],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_20e:
	/* 0x20e: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_212:
	/* 0x212: mov    DWORD PTR [rsp+0xa4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_219:
	/* 0x219: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21e:
	/* 0x21e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_225:
	/* 0x225: lea    rsi,[rsp+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_22d:
	/* 0x22d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22f:
	/* 0x22f: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_234:
	/* 0x234: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_237:
	/* 0x237: je     28d <trace_security_file_open+0x28d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28d;
	}
x86_l_239:
	/* 0x239: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_23d:
	/* 0x23d: mov    DWORD PTR [rsp+0xb4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_244:
	/* 0x244: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_249:
	/* 0x249: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_250:
	/* 0x250: lea    rsi,[rsp+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_258:
	/* 0x258: mov    QWORD PTR [rsp+0x98],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_260:
	/* 0x260: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_262:
	/* 0x262: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_265:
	/* 0x265: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_268:
	/* 0x268: mov    QWORD PTR [rsp+0x88],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_270:
	/* 0x270: je     4cf <trace_security_file_open+0x4cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4cf;
	}
x86_l_276:
	/* 0x276: test   BYTE PTR [r15+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_27b:
	/* 0x27b: jne    a31 <trace_security_file_open+0xa31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2609ULL;
	}
x86_l_281:
	/* 0x281: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_286:
	/* 0x286: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_288:
	/* 0x288: jmp    ab8 <trace_security_file_open+0xab8> */
	return 2744ULL;
x86_l_28d:
	/* 0x28d: mov    eax,DWORD PTR [rsp+0xa4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_294:
	/* 0x294: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_298:
	/* 0x298: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2a0:
	/* 0x2a0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a5:
	/* 0x2a5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_2ac:
	/* 0x2ac: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b1:
	/* 0x2b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b3:
	/* 0x2b3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b6:
	/* 0x2b6: je     1e70 <trace_security_file_open+0x1e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7792ULL;
	}
x86_l_2bc:
	/* 0x2bc: mov    ecx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c0:
	/* 0x2c0: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c4:
	/* 0x2c4: mov    QWORD PTR [rax+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_2cf:
	/* 0x2cf: mov    QWORD PTR [rax+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_2da:
	/* 0x2da: mov    QWORD PTR [rax+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_2e5:
	/* 0x2e5: mov    QWORD PTR [rax+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_2f0:
	/* 0x2f0: mov    QWORD PTR [rax+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_2fb:
	/* 0x2fb: mov    QWORD PTR [rax+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_306:
	/* 0x306: mov    QWORD PTR [rax+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_311:
	/* 0x311: mov    QWORD PTR [rax+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_31c:
	/* 0x31c: mov    QWORD PTR [rax+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_327:
	/* 0x327: mov    QWORD PTR [rax+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_332:
	/* 0x332: mov    QWORD PTR [rax+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_33d:
	/* 0x33d: mov    QWORD PTR [rax+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_348:
	/* 0x348: mov    QWORD PTR [rax+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_353:
	/* 0x353: mov    QWORD PTR [rax+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_35e:
	/* 0x35e: mov    QWORD PTR [rax+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_369:
	/* 0x369: mov    QWORD PTR [rax+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_374:
	/* 0x374: mov    QWORD PTR [rax+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_37f:
	/* 0x37f: mov    QWORD PTR [rax+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_38a:
	/* 0x38a: mov    QWORD PTR [rax+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_395:
	/* 0x395: mov    QWORD PTR [rax+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_3a0:
	/* 0x3a0: mov    QWORD PTR [rax+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_3ab:
	/* 0x3ab: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_3b6:
	/* 0x3b6: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_3c1:
	/* 0x3c1: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_3cc:
	/* 0x3cc: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_3d7:
	/* 0x3d7: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_3e2:
	/* 0x3e2: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_3ed:
	/* 0x3ed: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_3f8:
	/* 0x3f8: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_403:
	/* 0x403: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_40e:
	/* 0x40e: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_416:
	/* 0x416: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_41e:
	/* 0x41e: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_426:
	/* 0x426: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_42e:
	/* 0x42e: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_436:
	/* 0x436: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_43e:
	/* 0x43e: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_446:
	/* 0x446: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_44e:
	/* 0x44e: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_456:
	/* 0x456: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_45e:
	/* 0x45e: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_466:
	/* 0x466: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_46e:
	/* 0x46e: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_476:
	/* 0x476: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_47e:
	/* 0x47e: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_486:
	/* 0x486: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48d:
	/* 0x48d: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_493:
	/* 0x493: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_49a:
	/* 0x49a: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_49f:
	/* 0x49f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4a4:
	/* 0x4a4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4a7:
	/* 0x4a7: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4aa:
	/* 0x4aa: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4ad:
	/* 0x4ad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4b2:
	/* 0x4b2: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b7:
	/* 0x4b7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4ba:
	/* 0x4ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bc:
	/* 0x4bc: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4c1:
	/* 0x4c1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4c4:
	/* 0x4c4: jne    239 <trace_security_file_open+0x239> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_239;
	}
x86_l_4ca:
	/* 0x4ca: jmp    1e70 <trace_security_file_open+0x1e70> */
	return 7792ULL;
x86_l_4cf:
	/* 0x4cf: mov    eax,DWORD PTR [rsp+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_4d6:
	/* 0x4d6: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4da:
	/* 0x4da: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4e2:
	/* 0x4e2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e7:
	/* 0x4e7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_4ee:
	/* 0x4ee: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4f3:
	/* 0x4f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f5:
	/* 0x4f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4f8:
	/* 0x4f8: je     1e70 <trace_security_file_open+0x1e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7792ULL;
	}
x86_l_4fe:
	/* 0x4fe: mov    ecx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_502:
	/* 0x502: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_506:
	/* 0x506: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_511:
	/* 0x511: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_51c:
	/* 0x51c: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_527:
	/* 0x527: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_532:
	/* 0x532: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_53d:
	/* 0x53d: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_548:
	/* 0x548: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_553:
	/* 0x553: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_55e:
	/* 0x55e: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_569:
	/* 0x569: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_571:
	/* 0x571: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_579:
	/* 0x579: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_581:
	/* 0x581: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_589:
	/* 0x589: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_591:
	/* 0x591: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_599:
	/* 0x599: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_5a1:
	/* 0x5a1: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_5a9:
	/* 0x5a9: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_5b1:
	/* 0x5b1: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_5b9:
	/* 0x5b9: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_5c1:
	/* 0x5c1: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5c9:
	/* 0x5c9: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5d1:
	/* 0x5d1: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5d9:
	/* 0x5d9: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_5e1:
	/* 0x5e1: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e8:
	/* 0x5e8: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_5ee:
	/* 0x5ee: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_5f5:
	/* 0x5f5: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5fa:
	/* 0x5fa: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5ff:
	/* 0x5ff: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_602:
	/* 0x602: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_605:
	/* 0x605: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_608:
	/* 0x608: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_60d:
	/* 0x60d: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_612:
	/* 0x612: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_615:
	/* 0x615: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_617:
	/* 0x617: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_61a:
	/* 0x61a: je     1e70 <trace_security_file_open+0x1e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7792ULL;
	}
x86_l_620:
	/* 0x620: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_623:
	/* 0x623: mov    r12,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_62a:
	/* 0x62a: lea    r15,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_62f:
	/* 0x62f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_634:
	/* 0x634: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_639:
	/* 0x639: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_63e:
	/* 0x63e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_641:
	/* 0x641: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_643:
	/* 0x643: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_648:
	/* 0x648: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_650:
	/* 0x650: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_654:
	/* 0x654: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_659:
	/* 0x659: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_65e:
	/* 0x65e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_663:
	/* 0x663: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_665:
	/* 0x665: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_66a:
	/* 0x66a: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_66e:
	/* 0x66e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_673:
	/* 0x673: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_678:
	/* 0x678: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_67d:
	/* 0x67d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67f:
	/* 0x67f: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_684:
	/* 0x684: lea    rdx,[r13+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_688:
	/* 0x688: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_68d:
	/* 0x68d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_692:
	/* 0x692: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_697:
	/* 0x697: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_699:
	/* 0x699: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_69d:
	/* 0x69d: mov    DWORD PTR [rbx+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6a0:
	/* 0x6a0: mov    QWORD PTR [rsp+0x80],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_6a8:
	/* 0x6a8: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6ac:
	/* 0x6ac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6b1:
	/* 0x6b1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6b6:
	/* 0x6b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6bb:
	/* 0x6bb: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_6be:
	/* 0x6be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c0:
	/* 0x6c0: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6c5:
	/* 0x6c5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6ca:
	/* 0x6ca: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6cf:
	/* 0x6cf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6d4:
	/* 0x6d4: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6d7:
	/* 0x6d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d9:
	/* 0x6d9: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6dd:
	/* 0x6dd: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_6e1:
	/* 0x6e1: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_6e5:
	/* 0x6e5: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6e9:
	/* 0x6e9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6ee:
	/* 0x6ee: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6f3:
	/* 0x6f3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6f8:
	/* 0x6f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6fa:
	/* 0x6fa: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6fe:
	/* 0x6fe: mov    DWORD PTR [rbx+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_701:
	/* 0x701: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_706:
	/* 0x706: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_70b:
	/* 0x70b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_710:
	/* 0x710: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_713:
	/* 0x713: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_715:
	/* 0x715: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_71a:
	/* 0x71a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_71e:
	/* 0x71e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_723:
	/* 0x723: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_728:
	/* 0x728: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_72d:
	/* 0x72d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72f:
	/* 0x72f: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_734:
	/* 0x734: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_739:
	/* 0x739: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_73e:
	/* 0x73e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_743:
	/* 0x743: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_746:
	/* 0x746: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_748:
	/* 0x748: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_74c:
	/* 0x74c: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_750:
	/* 0x750: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_754:
	/* 0x754: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_758:
	/* 0x758: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_75d:
	/* 0x75d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_762:
	/* 0x762: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_767:
	/* 0x767: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_769:
	/* 0x769: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_76d:
	/* 0x76d: mov    DWORD PTR [rbx+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_770:
	/* 0x770: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_775:
	/* 0x775: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_77a:
	/* 0x77a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_77f:
	/* 0x77f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_782:
	/* 0x782: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_784:
	/* 0x784: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_789:
	/* 0x789: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_78e:
	/* 0x78e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_793:
	/* 0x793: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_798:
	/* 0x798: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_79b:
	/* 0x79b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_79d:
	/* 0x79d: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7a1:
	/* 0x7a1: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_7a5:
	/* 0x7a5: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_7a9:
	/* 0x7a9: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_7ad:
	/* 0x7ad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7b2:
	/* 0x7b2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7b7:
	/* 0x7b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7bc:
	/* 0x7bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7be:
	/* 0x7be: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7c3:
	/* 0x7c3: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_7c7:
	/* 0x7c7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7cc:
	/* 0x7cc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7d1:
	/* 0x7d1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7d6:
	/* 0x7d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7d8:
	/* 0x7d8: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_7db:
	/* 0x7db: mov    ebx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7df:
	/* 0x7df: mov    QWORD PTR [rsp+0x8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7e4:
	/* 0x7e4: lea    r15,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7e8:
	/* 0x7e8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7ed:
	/* 0x7ed: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7f2:
	/* 0x7f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7f7:
	/* 0x7f7: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_7fa:
	/* 0x7fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7fc:
	/* 0x7fc: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_801:
	/* 0x801: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_806:
	/* 0x806: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_80b:
	/* 0x80b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_810:
	/* 0x810: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_813:
	/* 0x813: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_815:
	/* 0x815: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_819:
	/* 0x819: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_81d:
	/* 0x81d: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_821:
	/* 0x821: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_825:
	/* 0x825: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_82a:
	/* 0x82a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_82f:
	/* 0x82f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_834:
	/* 0x834: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_836:
	/* 0x836: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_83b:
	/* 0x83b: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_83f:
	/* 0x83f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_844:
	/* 0x844: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_849:
	/* 0x849: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_84e:
	/* 0x84e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_850:
	/* 0x850: cmp    ebx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_854:
	/* 0x854: jne    8ad <trace_security_file_open+0x8ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2221ULL;
	}
x86_l_856:
	/* 0x856: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_85b:
	/* 0x85b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_860:
	/* 0x860: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 2149ULL;
}

static __noinline __u64 tracee_trace_security_file_open_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2149ULL: goto x86_l_865;
	case 2152ULL: goto x86_l_868;
	case 2154ULL: goto x86_l_86a;
	case 2159ULL: goto x86_l_86f;
	case 2164ULL: goto x86_l_874;
	case 2169ULL: goto x86_l_879;
	case 2174ULL: goto x86_l_87e;
	case 2177ULL: goto x86_l_881;
	case 2179ULL: goto x86_l_883;
	case 2183ULL: goto x86_l_887;
	case 2187ULL: goto x86_l_88b;
	case 2191ULL: goto x86_l_88f;
	case 2195ULL: goto x86_l_893;
	case 2200ULL: goto x86_l_898;
	case 2205ULL: goto x86_l_89d;
	case 2210ULL: goto x86_l_8a2;
	case 2212ULL: goto x86_l_8a4;
	case 2216ULL: goto x86_l_8a8;
	case 2221ULL: goto x86_l_8ad;
	case 2226ULL: goto x86_l_8b2;
	case 2234ULL: goto x86_l_8ba;
	case 2241ULL: goto x86_l_8c1;
	case 2246ULL: goto x86_l_8c6;
	case 2251ULL: goto x86_l_8cb;
	case 2256ULL: goto x86_l_8d0;
	case 2259ULL: goto x86_l_8d3;
	case 2261ULL: goto x86_l_8d5;
	case 2266ULL: goto x86_l_8da;
	case 2270ULL: goto x86_l_8de;
	case 2275ULL: goto x86_l_8e3;
	case 2280ULL: goto x86_l_8e8;
	case 2285ULL: goto x86_l_8ed;
	case 2287ULL: goto x86_l_8ef;
	case 2292ULL: goto x86_l_8f4;
	case 2297ULL: goto x86_l_8f9;
	case 2302ULL: goto x86_l_8fe;
	case 2307ULL: goto x86_l_903;
	case 2309ULL: goto x86_l_905;
	case 2313ULL: goto x86_l_909;
	case 2318ULL: goto x86_l_90e;
	case 2323ULL: goto x86_l_913;
	case 2325ULL: goto x86_l_915;
	case 2330ULL: goto x86_l_91a;
	case 2334ULL: goto x86_l_91e;
	case 2339ULL: goto x86_l_923;
	case 2344ULL: goto x86_l_928;
	case 2349ULL: goto x86_l_92d;
	case 2351ULL: goto x86_l_92f;
	case 2356ULL: goto x86_l_934;
	case 2360ULL: goto x86_l_938;
	case 2368ULL: goto x86_l_940;
	case 2372ULL: goto x86_l_944;
	case 2377ULL: goto x86_l_949;
	case 2382ULL: goto x86_l_94e;
	case 2387ULL: goto x86_l_953;
	case 2389ULL: goto x86_l_955;
	case 2394ULL: goto x86_l_95a;
	case 2399ULL: goto x86_l_95f;
	case 2404ULL: goto x86_l_964;
	case 2408ULL: goto x86_l_968;
	case 2413ULL: goto x86_l_96d;
	case 2418ULL: goto x86_l_972;
	case 2423ULL: goto x86_l_977;
	case 2425ULL: goto x86_l_979;
	case 2430ULL: goto x86_l_97e;
	case 2435ULL: goto x86_l_983;
	case 2440ULL: goto x86_l_988;
	case 2445ULL: goto x86_l_98d;
	case 2450ULL: goto x86_l_992;
	case 2453ULL: goto x86_l_995;
	case 2455ULL: goto x86_l_997;
	case 2460ULL: goto x86_l_99c;
	case 2468ULL: goto x86_l_9a4;
	case 2471ULL: goto x86_l_9a7;
	case 2473ULL: goto x86_l_9a9;
	case 2477ULL: goto x86_l_9ad;
	case 2481ULL: goto x86_l_9b1;
	case 2489ULL: goto x86_l_9b9;
	case 2497ULL: goto x86_l_9c1;
	case 2502ULL: goto x86_l_9c6;
	case 2507ULL: goto x86_l_9cb;
	case 2509ULL: goto x86_l_9cd;
	case 2514ULL: goto x86_l_9d2;
	case 2519ULL: goto x86_l_9d7;
	case 2524ULL: goto x86_l_9dc;
	case 2527ULL: goto x86_l_9df;
	case 2529ULL: goto x86_l_9e1;
	case 2534ULL: goto x86_l_9e6;
	case 2539ULL: goto x86_l_9eb;
	case 2544ULL: goto x86_l_9f0;
	case 2549ULL: goto x86_l_9f5;
	case 2551ULL: goto x86_l_9f7;
	case 2556ULL: goto x86_l_9fc;
	case 2561ULL: goto x86_l_a01;
	case 2566ULL: goto x86_l_a06;
	case 2569ULL: goto x86_l_a09;
	case 2574ULL: goto x86_l_a0e;
	case 2576ULL: goto x86_l_a10;
	case 2579ULL: goto x86_l_a13;
	case 2583ULL: goto x86_l_a17;
	case 2588ULL: goto x86_l_a1c;
	case 2593ULL: goto x86_l_a21;
	case 2596ULL: goto x86_l_a24;
	case 2598ULL: goto x86_l_a26;
	case 2603ULL: goto x86_l_a2b;
	case 2609ULL: goto x86_l_a31;
	case 2614ULL: goto x86_l_a36;
	case 2621ULL: goto x86_l_a3d;
	case 2626ULL: goto x86_l_a42;
	case 2631ULL: goto x86_l_a47;
	case 2636ULL: goto x86_l_a4c;
	case 2638ULL: goto x86_l_a4e;
	case 2643ULL: goto x86_l_a53;
	case 2648ULL: goto x86_l_a58;
	case 2653ULL: goto x86_l_a5d;
	case 2658ULL: goto x86_l_a62;
	case 2660ULL: goto x86_l_a64;
	case 2665ULL: goto x86_l_a69;
	case 2670ULL: goto x86_l_a6e;
	case 2675ULL: goto x86_l_a73;
	case 2680ULL: goto x86_l_a78;
	case 2682ULL: goto x86_l_a7a;
	case 2687ULL: goto x86_l_a7f;
	case 2692ULL: goto x86_l_a84;
	case 2697ULL: goto x86_l_a89;
	case 2702ULL: goto x86_l_a8e;
	case 2704ULL: goto x86_l_a90;
	case 2709ULL: goto x86_l_a95;
	case 2712ULL: goto x86_l_a98;
	case 2714ULL: goto x86_l_a9a;
	case 2718ULL: goto x86_l_a9e;
	case 2723ULL: goto x86_l_aa3;
	case 2728ULL: goto x86_l_aa8;
	case 2733ULL: goto x86_l_aad;
	case 2735ULL: goto x86_l_aaf;
	case 2740ULL: goto x86_l_ab4;
	case 2742ULL: goto x86_l_ab6;
	case 2744ULL: goto x86_l_ab8;
	case 2748ULL: goto x86_l_abc;
	case 2752ULL: goto x86_l_ac0;
	case 2756ULL: goto x86_l_ac4;
	case 2761ULL: goto x86_l_ac9;
	case 2768ULL: goto x86_l_ad0;
	case 2773ULL: goto x86_l_ad5;
	case 2775ULL: goto x86_l_ad7;
	case 2778ULL: goto x86_l_ada;
	case 2780ULL: goto x86_l_adc;
	case 2783ULL: goto x86_l_adf;
	case 2789ULL: goto x86_l_ae5;
	case 2792ULL: goto x86_l_ae8;
	case 2795ULL: goto x86_l_aeb;
	case 2797ULL: goto x86_l_aed;
	case 2802ULL: goto x86_l_af2;
	case 2807ULL: goto x86_l_af7;
	case 2812ULL: goto x86_l_afc;
	case 2818ULL: goto x86_l_b02;
	case 2829ULL: goto x86_l_b0d;
	case 2837ULL: goto x86_l_b15;
	case 2842ULL: goto x86_l_b1a;
	case 2847ULL: goto x86_l_b1f;
	case 2854ULL: goto x86_l_b26;
	case 2859ULL: goto x86_l_b2b;
	case 2861ULL: goto x86_l_b2d;
	case 2864ULL: goto x86_l_b30;
	case 2866ULL: goto x86_l_b32;
	case 2871ULL: goto x86_l_b37;
	case 2876ULL: goto x86_l_b3c;
	case 2879ULL: goto x86_l_b3f;
	case 2881ULL: goto x86_l_b41;
	case 2884ULL: goto x86_l_b44;
	case 2886ULL: goto x86_l_b46;
	case 2890ULL: goto x86_l_b4a;
	case 2897ULL: goto x86_l_b51;
	case 2900ULL: goto x86_l_b54;
	case 2907ULL: goto x86_l_b5b;
	case 2911ULL: goto x86_l_b5f;
	case 2915ULL: goto x86_l_b63;
	case 2922ULL: goto x86_l_b6a;
	case 2929ULL: goto x86_l_b71;
	case 2933ULL: goto x86_l_b75;
	case 2940ULL: goto x86_l_b7c;
	case 2944ULL: goto x86_l_b80;
	case 2951ULL: goto x86_l_b87;
	case 2955ULL: goto x86_l_b8b;
	case 2962ULL: goto x86_l_b92;
	case 2966ULL: goto x86_l_b96;
	case 2973ULL: goto x86_l_b9d;
	case 2980ULL: goto x86_l_ba4;
	case 2987ULL: goto x86_l_bab;
	case 2990ULL: goto x86_l_bae;
	case 2994ULL: goto x86_l_bb2;
	case 3002ULL: goto x86_l_bba;
	case 3004ULL: goto x86_l_bbc;
	case 3007ULL: goto x86_l_bbf;
	case 3010ULL: goto x86_l_bc2;
	case 3017ULL: goto x86_l_bc9;
	case 3023ULL: goto x86_l_bcf;
	case 3028ULL: goto x86_l_bd4;
	case 3035ULL: goto x86_l_bdb;
	case 3038ULL: goto x86_l_bde;
	case 3044ULL: goto x86_l_be4;
	case 3051ULL: goto x86_l_beb;
	case 3054ULL: goto x86_l_bee;
	case 3057ULL: goto x86_l_bf1;
	case 3060ULL: goto x86_l_bf4;
	case 3064ULL: goto x86_l_bf8;
	case 3067ULL: goto x86_l_bfb;
	case 3070ULL: goto x86_l_bfe;
	case 3077ULL: goto x86_l_c05;
	case 3080ULL: goto x86_l_c08;
	case 3087ULL: goto x86_l_c0f;
	case 3090ULL: goto x86_l_c12;
	case 3092ULL: goto x86_l_c14;
	case 3094ULL: goto x86_l_c16;
	case 3101ULL: goto x86_l_c1d;
	case 3104ULL: goto x86_l_c20;
	case 3107ULL: goto x86_l_c23;
	case 3110ULL: goto x86_l_c26;
	case 3117ULL: goto x86_l_c2d;
	case 3120ULL: goto x86_l_c30;
	case 3123ULL: goto x86_l_c33;
	case 3130ULL: goto x86_l_c3a;
	case 3133ULL: goto x86_l_c3d;
	case 3135ULL: goto x86_l_c3f;
	case 3139ULL: goto x86_l_c43;
	case 3142ULL: goto x86_l_c46;
	case 3145ULL: goto x86_l_c49;
	case 3148ULL: goto x86_l_c4c;
	case 3155ULL: goto x86_l_c53;
	case 3158ULL: goto x86_l_c56;
	case 3161ULL: goto x86_l_c59;
	case 3168ULL: goto x86_l_c60;
	case 3171ULL: goto x86_l_c63;
	case 3173ULL: goto x86_l_c65;
	case 3176ULL: goto x86_l_c68;
	case 3181ULL: goto x86_l_c6d;
	case 3185ULL: goto x86_l_c71;
	case 3188ULL: goto x86_l_c74;
	case 3195ULL: goto x86_l_c7b;
	case 3198ULL: goto x86_l_c7e;
	case 3201ULL: goto x86_l_c81;
	case 3206ULL: goto x86_l_c86;
	case 3213ULL: goto x86_l_c8d;
	case 3216ULL: goto x86_l_c90;
	case 3221ULL: goto x86_l_c95;
	case 3227ULL: goto x86_l_c9b;
	case 3234ULL: goto x86_l_ca2;
	case 3242ULL: goto x86_l_caa;
	case 3249ULL: goto x86_l_cb1;
	case 3257ULL: goto x86_l_cb9;
	case 3264ULL: goto x86_l_cc0;
	case 3272ULL: goto x86_l_cc8;
	case 3277ULL: goto x86_l_ccd;
	case 3282ULL: goto x86_l_cd2;
	case 3289ULL: goto x86_l_cd9;
	case 3294ULL: goto x86_l_cde;
	case 3296ULL: goto x86_l_ce0;
	case 3299ULL: goto x86_l_ce3;
	case 3303ULL: goto x86_l_ce7;
	case 3308ULL: goto x86_l_cec;
	case 3315ULL: goto x86_l_cf3;
	case 3318ULL: goto x86_l_cf6;
	case 3320ULL: goto x86_l_cf8;
	case 3325ULL: goto x86_l_cfd;
	case 3330ULL: goto x86_l_d02;
	case 3333ULL: goto x86_l_d05;
	case 3335ULL: goto x86_l_d07;
	case 3338ULL: goto x86_l_d0a;
	case 3340ULL: goto x86_l_d0c;
	case 3343ULL: goto x86_l_d0f;
	case 3347ULL: goto x86_l_d13;
	case 3350ULL: goto x86_l_d16;
	case 3352ULL: goto x86_l_d18;
	case 3354ULL: goto x86_l_d1a;
	case 3362ULL: goto x86_l_d22;
	case 3370ULL: goto x86_l_d2a;
	case 3375ULL: goto x86_l_d2f;
	case 3378ULL: goto x86_l_d32;
	case 3381ULL: goto x86_l_d35;
	case 3383ULL: goto x86_l_d37;
	case 3387ULL: goto x86_l_d3b;
	case 3389ULL: goto x86_l_d3d;
	case 3392ULL: goto x86_l_d40;
	case 3394ULL: goto x86_l_d42;
	case 3402ULL: goto x86_l_d4a;
	case 3405ULL: goto x86_l_d4d;
	case 3409ULL: goto x86_l_d51;
	case 3414ULL: goto x86_l_d56;
	case 3421ULL: goto x86_l_d5d;
	case 3424ULL: goto x86_l_d60;
	case 3426ULL: goto x86_l_d62;
	case 3434ULL: goto x86_l_d6a;
	case 3439ULL: goto x86_l_d6f;
	case 3444ULL: goto x86_l_d74;
	case 3447ULL: goto x86_l_d77;
	case 3449ULL: goto x86_l_d79;
	case 3452ULL: goto x86_l_d7c;
	case 3454ULL: goto x86_l_d7e;
	case 3457ULL: goto x86_l_d81;
	case 3461ULL: goto x86_l_d85;
	case 3464ULL: goto x86_l_d88;
	case 3466ULL: goto x86_l_d8a;
	case 3473ULL: goto x86_l_d91;
	case 3480ULL: goto x86_l_d98;
	case 3483ULL: goto x86_l_d9b;
	case 3489ULL: goto x86_l_da1;
	case 3494ULL: goto x86_l_da6;
	case 3496ULL: goto x86_l_da8;
	case 3499ULL: goto x86_l_dab;
	case 3504ULL: goto x86_l_db0;
	case 3507ULL: goto x86_l_db3;
	case 3509ULL: goto x86_l_db5;
	case 3511ULL: goto x86_l_db7;
	case 3513ULL: goto x86_l_db9;
	case 3521ULL: goto x86_l_dc1;
	case 3529ULL: goto x86_l_dc9;
	case 3532ULL: goto x86_l_dcc;
	case 3537ULL: goto x86_l_dd1;
	case 3540ULL: goto x86_l_dd4;
	case 3542ULL: goto x86_l_dd6;
	case 3546ULL: goto x86_l_dda;
	case 3548ULL: goto x86_l_ddc;
	case 3551ULL: goto x86_l_ddf;
	case 3553ULL: goto x86_l_de1;
	case 3561ULL: goto x86_l_de9;
	case 3564ULL: goto x86_l_dec;
	case 3567ULL: goto x86_l_def;
	case 3570ULL: goto x86_l_df2;
	case 3573ULL: goto x86_l_df5;
	case 3581ULL: goto x86_l_dfd;
	case 3587ULL: goto x86_l_e03;
	case 3592ULL: goto x86_l_e08;
	case 3594ULL: goto x86_l_e0a;
	case 3598ULL: goto x86_l_e0e;
	case 3605ULL: goto x86_l_e15;
	case 3612ULL: goto x86_l_e1c;
	case 3620ULL: goto x86_l_e24;
	case 3627ULL: goto x86_l_e2b;
	case 3634ULL: goto x86_l_e32;
	case 3639ULL: goto x86_l_e37;
	case 3644ULL: goto x86_l_e3c;
	case 3649ULL: goto x86_l_e41;
	case 3656ULL: goto x86_l_e48;
	case 3661ULL: goto x86_l_e4d;
	case 3663ULL: goto x86_l_e4f;
	case 3667ULL: goto x86_l_e53;
	case 3672ULL: goto x86_l_e58;
	case 3679ULL: goto x86_l_e5f;
	case 3682ULL: goto x86_l_e62;
	case 3684ULL: goto x86_l_e64;
	case 3689ULL: goto x86_l_e69;
	case 3694ULL: goto x86_l_e6e;
	case 3697ULL: goto x86_l_e71;
	case 3699ULL: goto x86_l_e73;
	case 3702ULL: goto x86_l_e76;
	case 3704ULL: goto x86_l_e78;
	case 3707ULL: goto x86_l_e7b;
	case 3711ULL: goto x86_l_e7f;
	case 3714ULL: goto x86_l_e82;
	case 3716ULL: goto x86_l_e84;
	case 3718ULL: goto x86_l_e86;
	case 3721ULL: goto x86_l_e89;
	case 3726ULL: goto x86_l_e8e;
	case 3729ULL: goto x86_l_e91;
	case 3732ULL: goto x86_l_e94;
	case 3734ULL: goto x86_l_e96;
	case 3739ULL: goto x86_l_e9b;
	case 3741ULL: goto x86_l_e9d;
	case 3746ULL: goto x86_l_ea2;
	case 3754ULL: goto x86_l_eaa;
	case 3756ULL: goto x86_l_eac;
	case 3761ULL: goto x86_l_eb1;
	case 3765ULL: goto x86_l_eb5;
	case 3770ULL: goto x86_l_eba;
	case 3772ULL: goto x86_l_ebc;
	case 3775ULL: goto x86_l_ebf;
	case 3777ULL: goto x86_l_ec1;
	case 3785ULL: goto x86_l_ec9;
	case 3788ULL: goto x86_l_ecc;
	case 3791ULL: goto x86_l_ecf;
	case 3794ULL: goto x86_l_ed2;
	case 3802ULL: goto x86_l_eda;
	case 3808ULL: goto x86_l_ee0;
	case 3813ULL: goto x86_l_ee5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_865:
	/* 0x865: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_868:
	/* 0x868: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_86a:
	/* 0x86a: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_86f:
	/* 0x86f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_874:
	/* 0x874: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_879:
	/* 0x879: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_87e:
	/* 0x87e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_881:
	/* 0x881: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_883:
	/* 0x883: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_887:
	/* 0x887: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_88b:
	/* 0x88b: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_88f:
	/* 0x88f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_893:
	/* 0x893: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_898:
	/* 0x898: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_89d:
	/* 0x89d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8a2:
	/* 0x8a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a4:
	/* 0x8a4: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8a8:
	/* 0x8a8: mov    DWORD PTR [r12+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8ad:
	/* 0x8ad: mov    DWORD PTR [r12+0x30],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8b2:
	/* 0x8b2: mov    rbx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8ba:
	/* 0x8ba: lea    rbp,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8c1:
	/* 0x8c1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8c6:
	/* 0x8c6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8cb:
	/* 0x8cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8d0:
	/* 0x8d0: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_8d3:
	/* 0x8d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d5:
	/* 0x8d5: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8da:
	/* 0x8da: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_8de:
	/* 0x8de: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8e3:
	/* 0x8e3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8e8:
	/* 0x8e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8ed:
	/* 0x8ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ef:
	/* 0x8ef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8f4:
	/* 0x8f4: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8f9:
	/* 0x8f9: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8fe:
	/* 0x8fe: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_903:
	/* 0x903: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_905:
	/* 0x905: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_909:
	/* 0x909: mov    DWORD PTR [r12+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_90e:
	/* 0x90e: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_913:
	/* 0x913: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_915:
	/* 0x915: mov    DWORD PTR [r12+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_91a:
	/* 0x91a: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_91e:
	/* 0x91e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_923:
	/* 0x923: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_928:
	/* 0x928: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_92d:
	/* 0x92d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_92f:
	/* 0x92f: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_934:
	/* 0x934: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_938:
	/* 0x938: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_940:
	/* 0x940: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_944:
	/* 0x944: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_949:
	/* 0x949: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_94e:
	/* 0x94e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_953:
	/* 0x953: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_955:
	/* 0x955: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_95a:
	/* 0x95a: mov    QWORD PTR [r12+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_95f:
	/* 0x95f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_964:
	/* 0x964: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_968:
	/* 0x968: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_96d:
	/* 0x96d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_972:
	/* 0x972: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_977:
	/* 0x977: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_979:
	/* 0x979: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_97e:
	/* 0x97e: mov    QWORD PTR [r12+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_983:
	/* 0x983: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_988:
	/* 0x988: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_98d:
	/* 0x98d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_992:
	/* 0x992: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_995:
	/* 0x995: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_997:
	/* 0x997: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_99c:
	/* 0x99c: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_9a4:
	/* 0x9a4: mov    rbx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_64);
x86_l_9a7:
	/* 0x9a7: je     9ad <trace_security_file_open+0x9ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9ad;
	}
x86_l_9a9:
	/* 0x9a9: or     BYTE PTR [rbx+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_9ad:
	/* 0x9ad: lea    rdi,[rbx+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_9b1:
	/* 0x9b1: mov    QWORD PTR [rbx+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_9b9:
	/* 0x9b9: mov    QWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_9c1:
	/* 0x9c1: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_9c6:
	/* 0x9c6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_9cb:
	/* 0x9cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9cd:
	/* 0x9cd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9d2:
	/* 0x9d2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9d7:
	/* 0x9d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9dc:
	/* 0x9dc: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_9df:
	/* 0x9df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e1:
	/* 0x9e1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9e6:
	/* 0x9e6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9eb:
	/* 0x9eb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9f0:
	/* 0x9f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9f5:
	/* 0x9f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f7:
	/* 0x9f7: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9fc:
	/* 0x9fc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a01:
	/* 0xa01: lea    rbp,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a06:
	/* 0xa06: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_a09:
	/* 0xa09: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_a0e:
	/* 0xa0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a10:
	/* 0xa10: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a13:
	/* 0xa13: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_a17:
	/* 0xa17: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_a1c:
	/* 0xa1c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_a21:
	/* 0xa21: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_a24:
	/* 0xa24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a26:
	/* 0xa26: test   BYTE PTR [r15+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_a2b:
	/* 0xa2b: je     281 <trace_security_file_open+0x281> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 641ULL;
	}
x86_l_a31:
	/* 0xa31: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_a36:
	/* 0xa36: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_a3d:
	/* 0xa3d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a42:
	/* 0xa42: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a47:
	/* 0xa47: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a4c:
	/* 0xa4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a4e:
	/* 0xa4e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a53:
	/* 0xa53: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a58:
	/* 0xa58: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a5d:
	/* 0xa5d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a62:
	/* 0xa62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a64:
	/* 0xa64: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a69:
	/* 0xa69: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a6e:
	/* 0xa6e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a73:
	/* 0xa73: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a78:
	/* 0xa78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a7a:
	/* 0xa7a: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a7f:
	/* 0xa7f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a84:
	/* 0xa84: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a89:
	/* 0xa89: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a8e:
	/* 0xa8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a90:
	/* 0xa90: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a95:
	/* 0xa95: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_a98:
	/* 0xa98: je     ab6 <trace_security_file_open+0xab6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ab6;
	}
x86_l_a9a:
	/* 0xa9a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_a9e:
	/* 0xa9e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_aa3:
	/* 0xaa3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_aa8:
	/* 0xaa8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_aad:
	/* 0xaad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aaf:
	/* 0xaaf: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ab4:
	/* 0xab4: jmp    ab8 <trace_security_file_open+0xab8> */
	goto x86_l_ab8;
x86_l_ab6:
	/* 0xab6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ab8:
	/* 0xab8: mov    QWORD PTR [r14+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_abc:
	/* 0xabc: mov    QWORD PTR [rbx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ac0:
	/* 0xac0: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ac4:
	/* 0xac4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ac9:
	/* 0xac9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_ad0:
	/* 0xad0: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ad5:
	/* 0xad5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad7:
	/* 0xad7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ada:
	/* 0xada: je     af2 <trace_security_file_open+0xaf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_af2;
	}
x86_l_adc:
	/* 0xadc: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_adf:
	/* 0xadf: mov    BYTE PTR [rbx+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_ae5:
	/* 0xae5: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_ae8:
	/* 0xae8: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_aeb:
	/* 0xaeb: jne    af2 <trace_security_file_open+0xaf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_af2;
	}
x86_l_aed:
	/* 0xaed: or     BYTE PTR [r14+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_af2:
	/* 0xaf2: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_af7:
	/* 0xaf7: cmp    ax,WORD PTR [r15+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_afc:
	/* 0xafc: jne    2581 <trace_security_file_open+0x2581> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9601ULL;
	}
x86_l_b02:
	/* 0xb02: mov    QWORD PTR [r14+0x7dd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138366666407936ULL);
x86_l_b0d:
	/* 0xb0d: mov    DWORD PTR [rsp+0x30],0x2dc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430940ULL);
x86_l_b15:
	/* 0xb15: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b1a:
	/* 0xb1a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b1f:
	/* 0xb1f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_b26:
	/* 0xb26: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b2b:
	/* 0xb2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b2d:
	/* 0xb2d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b30:
	/* 0xb30: je     b9d <trace_security_file_open+0xb9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b9d;
	}
x86_l_b32:
	/* 0xb32: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b37:
	/* 0xb37: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b3c:
	/* 0xb3c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_b3f:
	/* 0xb3f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_b41:
	/* 0xb41: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b44:
	/* 0xb44: je     b9d <trace_security_file_open+0xb9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b9d;
	}
x86_l_b46:
	/* 0xb46: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b4a:
	/* 0xb4a: mov    QWORD PTR [r14+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_b51:
	/* 0xb51: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b54:
	/* 0xb54: mov    QWORD PTR [r14+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_b5b:
	/* 0xb5b: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b5f:
	/* 0xb5f: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b63:
	/* 0xb63: mov    QWORD PTR [r14+0x7de8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_b6a:
	/* 0xb6a: mov    QWORD PTR [r14+0x7df0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_b71:
	/* 0xb71: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b75:
	/* 0xb75: mov    QWORD PTR [r14+0x7df8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_b7c:
	/* 0xb7c: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b80:
	/* 0xb80: mov    QWORD PTR [r14+0x7e00],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_b87:
	/* 0xb87: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b8b:
	/* 0xb8b: mov    QWORD PTR [r14+0x7e08],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_b92:
	/* 0xb92: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b96:
	/* 0xb96: mov    QWORD PTR [r14+0x7e10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_b9d:
	/* 0xb9d: mov    rax,QWORD PTR [r14+0x7dd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_ba4:
	/* 0xba4: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_bab:
	/* 0xbab: mov    ecx,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bae:
	/* 0xbae: cmp    ecx,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_bb2:
	/* 0xbb2: mov    QWORD PTR [rsp+0x90],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_bba:
	/* 0xbba: jne    bd4 <trace_security_file_open+0xbd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_bd4;
	}
x86_l_bbc:
	/* 0xbbc: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bbf:
	/* 0xbbf: and    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_bc2:
	/* 0xbc2: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_bc9:
	/* 0xbc9: jne    1389 <trace_security_file_open+0x1389> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5001ULL;
	}
x86_l_bcf:
	/* 0xbcf: jmp    1e70 <trace_security_file_open+0x1e70> */
	return 7792ULL;
x86_l_bd4:
	/* 0xbd4: mov    rax,QWORD PTR [r14+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_bdb:
	/* 0xbdb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bde:
	/* 0xbde: je     d8a <trace_security_file_open+0xd8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d8a;
	}
x86_l_be4:
	/* 0xbe4: movzx  ecx,BYTE PTR [rbx+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_beb:
	/* 0xbeb: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_bee:
	/* 0xbee: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bf1:
	/* 0xbf1: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_bf4:
	/* 0xbf4: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_bf8:
	/* 0xbf8: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_bfb:
	/* 0xbfb: neg    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_bfe:
	/* 0xbfe: xor    r12,QWORD PTR [r14+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_c05:
	/* 0xc05: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_c08:
	/* 0xc08: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_c0f:
	/* 0xc0f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c12:
	/* 0xc12: je     c33 <trace_security_file_open+0xc33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c33;
	}
x86_l_c14:
	/* 0xc14: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c16:
	/* 0xc16: cmp    BYTE PTR [rbx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_c1d:
	/* 0xc1d: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_c20:
	/* 0xc20: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_c23:
	/* 0xc23: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_c26:
	/* 0xc26: xor    rcx,QWORD PTR [r14+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_c2d:
	/* 0xc2d: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_c30:
	/* 0xc30: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_c33:
	/* 0xc33: mov    rax,QWORD PTR [r14+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_c3a:
	/* 0xc3a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c3d:
	/* 0xc3d: je     c59 <trace_security_file_open+0xc59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c59;
	}
x86_l_c3f:
	/* 0xc3f: mov    ecx,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_c43:
	/* 0xc43: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_c46:
	/* 0xc46: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_c49:
	/* 0xc49: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_c4c:
	/* 0xc4c: xor    rcx,QWORD PTR [r14+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_c53:
	/* 0xc53: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_c56:
	/* 0xc56: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_c59:
	/* 0xc59: mov    rax,QWORD PTR [r14+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_c60:
	/* 0xc60: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c63:
	/* 0xc63: je     c81 <trace_security_file_open+0xc81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c81;
	}
x86_l_c65:
	/* 0xc65: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_c68:
	/* 0xc68: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c6d:
	/* 0xc6d: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_c71:
	/* 0xc71: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_c74:
	/* 0xc74: xor    rcx,QWORD PTR [r14+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_c7b:
	/* 0xc7b: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_c7e:
	/* 0xc7e: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_c81:
	/* 0xc81: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_c86:
	/* 0xc86: mov    r13,QWORD PTR [r14+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_c8d:
	/* 0xc8d: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_c90:
	/* 0xc90: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c95:
	/* 0xc95: je     df5 <trace_security_file_open+0xdf5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_df5;
	}
x86_l_c9b:
	/* 0xc9b: mov    rcx,QWORD PTR [r14+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_ca2:
	/* 0xca2: mov    QWORD PTR [rsp+0xb8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_caa:
	/* 0xcaa: mov    rcx,QWORD PTR [r14+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_cb1:
	/* 0xcb1: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_cb9:
	/* 0xcb9: mov    rcx,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_cc0:
	/* 0xcc0: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_cc8:
	/* 0xcc8: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ccd:
	/* 0xccd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cd2:
	/* 0xcd2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_cd9:
	/* 0xcd9: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cde:
	/* 0xcde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ce0:
	/* 0xce0: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_ce3:
	/* 0xce3: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_ce7:
	/* 0xce7: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cec:
	/* 0xcec: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_cf3:
	/* 0xcf3: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_cf6:
	/* 0xcf6: je     d18 <trace_security_file_open+0xd18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d18;
	}
x86_l_cf8:
	/* 0xcf8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cfd:
	/* 0xcfd: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d02:
	/* 0xd02: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_d05:
	/* 0xd05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d07:
	/* 0xd07: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d0a:
	/* 0xd0a: je     d18 <trace_security_file_open+0xd18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d18;
	}
x86_l_d0c:
	/* 0xd0c: mov    rbx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d0f:
	/* 0xd0f: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d13:
	/* 0xd13: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d16:
	/* 0xd16: jmp    d1a <trace_security_file_open+0xd1a> */
	goto x86_l_d1a;
x86_l_d18:
	/* 0xd18: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d1a:
	/* 0xd1a: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_d22:
	/* 0xd22: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d2a:
	/* 0xd2a: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d2f:
	/* 0xd2f: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_d32:
	/* 0xd32: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_d35:
	/* 0xd35: jb     d4d <trace_security_file_open+0xd4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d4d;
	}
x86_l_d37:
	/* 0xd37: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_d3b:
	/* 0xd3b: je     d42 <trace_security_file_open+0xd42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d42;
	}
x86_l_d3d:
	/* 0xd3d: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_d40:
	/* 0xd40: jbe    d4d <trace_security_file_open+0xd4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_d4d;
	}
x86_l_d42:
	/* 0xd42: and    r15,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 184ULL);
x86_l_d4a:
	/* 0xd4a: or     rbx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_d4d:
	/* 0xd4d: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d51:
	/* 0xd51: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d56:
	/* 0xd56: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_d5d:
	/* 0xd5d: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_d60:
	/* 0xd60: je     da6 <trace_security_file_open+0xda6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_da6;
	}
x86_l_d62:
	/* 0xd62: mov    QWORD PTR [rsp+0x80],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d6a:
	/* 0xd6a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d6f:
	/* 0xd6f: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d74:
	/* 0xd74: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_d77:
	/* 0xd77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d79:
	/* 0xd79: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d7c:
	/* 0xd7c: je     db7 <trace_security_file_open+0xdb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_db7;
	}
x86_l_d7e:
	/* 0xd7e: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d81:
	/* 0xd81: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d85:
	/* 0xd85: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d88:
	/* 0xd88: jmp    db9 <trace_security_file_open+0xdb9> */
	goto x86_l_db9;
x86_l_d8a:
	/* 0xd8a: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_d91:
	/* 0xd91: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_d98:
	/* 0xd98: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d9b:
	/* 0xd9b: jne    c14 <trace_security_file_open+0xc14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c14;
	}
x86_l_da1:
	/* 0xda1: jmp    c33 <trace_security_file_open+0xc33> */
	goto x86_l_c33;
x86_l_da6:
	/* 0xda6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_da8:
	/* 0xda8: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_dab:
	/* 0xdab: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_db0:
	/* 0xdb0: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_db3:
	/* 0xdb3: jae    dd6 <trace_security_file_open+0xdd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_dd6;
	}
x86_l_db5:
	/* 0xdb5: jmp    dec <trace_security_file_open+0xdec> */
	goto x86_l_dec;
x86_l_db7:
	/* 0xdb7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_db9:
	/* 0xdb9: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_dc1:
	/* 0xdc1: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_dc9:
	/* 0xdc9: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_dcc:
	/* 0xdcc: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_dd1:
	/* 0xdd1: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_dd4:
	/* 0xdd4: jb     dec <trace_security_file_open+0xdec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_dec;
	}
x86_l_dd6:
	/* 0xdd6: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_dda:
	/* 0xdda: je     de1 <trace_security_file_open+0xde1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_de1;
	}
x86_l_ddc:
	/* 0xddc: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_ddf:
	/* 0xddf: jbe    dec <trace_security_file_open+0xdec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_dec;
	}
x86_l_de1:
	/* 0xde1: and    r15,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 184ULL);
x86_l_de9:
	/* 0xde9: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_dec:
	/* 0xdec: or     rbx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R13, X86_WIDTH_64, X86_ALU_OR);
x86_l_def:
	/* 0xdef: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_df2:
	/* 0xdf2: and    r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_AND);
x86_l_df5:
	/* 0xdf5: cmp    QWORD PTR [r14+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_dfd:
	/* 0xdfd: je     e9d <trace_security_file_open+0xe9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e9d;
	}
x86_l_e03:
	/* 0xe03: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_e08:
	/* 0xe08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e0a:
	/* 0xe0a: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e0e:
	/* 0xe0e: mov    rbx,QWORD PTR [r14+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_e15:
	/* 0xe15: mov    rax,QWORD PTR [r14+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_e1c:
	/* 0xe1c: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_e24:
	/* 0xe24: mov    rbp,QWORD PTR [r14+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_e2b:
	/* 0xe2b: mov    r13,QWORD PTR [r14+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_e32:
	/* 0xe32: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_e37:
	/* 0xe37: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e3c:
	/* 0xe3c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e41:
	/* 0xe41: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_e48:
	/* 0xe48: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e4d:
	/* 0xe4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e4f:
	/* 0xe4f: mov    ecx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e53:
	/* 0xe53: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e58:
	/* 0xe58: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e5f:
	/* 0xe5f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e62:
	/* 0xe62: je     e84 <trace_security_file_open+0xe84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e84;
	}
x86_l_e64:
	/* 0xe64: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e69:
	/* 0xe69: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e6e:
	/* 0xe6e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_e71:
	/* 0xe71: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e73:
	/* 0xe73: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e76:
	/* 0xe76: je     e84 <trace_security_file_open+0xe84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e84;
	}
x86_l_e78:
	/* 0xe78: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e7b:
	/* 0xe7b: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e7f:
	/* 0xe7f: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e82:
	/* 0xe82: jmp    e86 <trace_security_file_open+0xe86> */
	goto x86_l_e86;
x86_l_e84:
	/* 0xe84: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e86:
	/* 0xe86: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e89:
	/* 0xe89: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e8e:
	/* 0xe8e: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_e91:
	/* 0xe91: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_e94:
	/* 0xe94: jae    eb1 <trace_security_file_open+0xeb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_eb1;
	}
x86_l_e96:
	/* 0xe96: movzx  ebp,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_e9b:
	/* 0xe9b: jmp    ecc <trace_security_file_open+0xecc> */
	goto x86_l_ecc;
x86_l_e9d:
	/* 0xe9d: movzx  ebp,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_ea2:
	/* 0xea2: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_eaa:
	/* 0xeaa: jne    ee0 <trace_security_file_open+0xee0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ee0;
	}
x86_l_eac:
	/* 0xeac: jmp    f97 <trace_security_file_open+0xf97> */
	return 3991ULL;
x86_l_eb1:
	/* 0xeb1: cmp    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_eb5:
	/* 0xeb5: movzx  ebp,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_eba:
	/* 0xeba: je     ec1 <trace_security_file_open+0xec1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ec1;
	}
x86_l_ebc:
	/* 0xebc: cmp    rax,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_ebf:
	/* 0xebf: jbe    ecc <trace_security_file_open+0xecc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_ecc;
	}
x86_l_ec1:
	/* 0xec1: and    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_ec9:
	/* 0xec9: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_ecc:
	/* 0xecc: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_ecf:
	/* 0xecf: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_ed2:
	/* 0xed2: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_eda:
	/* 0xeda: je     f97 <trace_security_file_open+0xf97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3991ULL;
	}
x86_l_ee0:
	/* 0xee0: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_ee5:
	/* 0xee5: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
	return 3820ULL;
}

static __noinline __u64 tracee_trace_security_file_open_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3820ULL: goto x86_l_eec;
	case 3825ULL: goto x86_l_ef1;
	case 3830ULL: goto x86_l_ef6;
	case 3835ULL: goto x86_l_efb;
	case 3837ULL: goto x86_l_efd;
	case 3842ULL: goto x86_l_f02;
	case 3846ULL: goto x86_l_f06;
	case 3851ULL: goto x86_l_f0b;
	case 3856ULL: goto x86_l_f10;
	case 3861ULL: goto x86_l_f15;
	case 3863ULL: goto x86_l_f17;
	case 3868ULL: goto x86_l_f1c;
	case 3873ULL: goto x86_l_f21;
	case 3878ULL: goto x86_l_f26;
	case 3883ULL: goto x86_l_f2b;
	case 3885ULL: goto x86_l_f2d;
	case 3889ULL: goto x86_l_f31;
	case 3893ULL: goto x86_l_f35;
	case 3900ULL: goto x86_l_f3c;
	case 3907ULL: goto x86_l_f43;
	case 3910ULL: goto x86_l_f46;
	case 3915ULL: goto x86_l_f4b;
	case 3920ULL: goto x86_l_f50;
	case 3927ULL: goto x86_l_f57;
	case 3932ULL: goto x86_l_f5c;
	case 3934ULL: goto x86_l_f5e;
	case 3941ULL: goto x86_l_f65;
	case 3944ULL: goto x86_l_f68;
	case 3946ULL: goto x86_l_f6a;
	case 3950ULL: goto x86_l_f6e;
	case 3955ULL: goto x86_l_f73;
	case 3958ULL: goto x86_l_f76;
	case 3960ULL: goto x86_l_f78;
	case 3963ULL: goto x86_l_f7b;
	case 3965ULL: goto x86_l_f7d;
	case 3968ULL: goto x86_l_f80;
	case 3972ULL: goto x86_l_f84;
	case 3975ULL: goto x86_l_f87;
	case 3977ULL: goto x86_l_f89;
	case 3979ULL: goto x86_l_f8b;
	case 3982ULL: goto x86_l_f8e;
	case 3985ULL: goto x86_l_f91;
	case 3988ULL: goto x86_l_f94;
	case 3991ULL: goto x86_l_f97;
	case 3999ULL: goto x86_l_f9f;
	case 4005ULL: goto x86_l_fa5;
	case 4012ULL: goto x86_l_fac;
	case 4016ULL: goto x86_l_fb0;
	case 4021ULL: goto x86_l_fb5;
	case 4026ULL: goto x86_l_fba;
	case 4031ULL: goto x86_l_fbf;
	case 4033ULL: goto x86_l_fc1;
	case 4038ULL: goto x86_l_fc6;
	case 4043ULL: goto x86_l_fcb;
	case 4048ULL: goto x86_l_fd0;
	case 4053ULL: goto x86_l_fd5;
	case 4056ULL: goto x86_l_fd8;
	case 4058ULL: goto x86_l_fda;
	case 4062ULL: goto x86_l_fde;
	case 4066ULL: goto x86_l_fe2;
	case 4070ULL: goto x86_l_fe6;
	case 4074ULL: goto x86_l_fea;
	case 4079ULL: goto x86_l_fef;
	case 4084ULL: goto x86_l_ff4;
	case 4089ULL: goto x86_l_ff9;
	case 4094ULL: goto x86_l_ffe;
	case 4096ULL: goto x86_l_1000;
	case 4101ULL: goto x86_l_1005;
	case 4105ULL: goto x86_l_1009;
	case 4110ULL: goto x86_l_100e;
	case 4115ULL: goto x86_l_1013;
	case 4120ULL: goto x86_l_1018;
	case 4122ULL: goto x86_l_101a;
	case 4126ULL: goto x86_l_101e;
	case 4130ULL: goto x86_l_1022;
	case 4137ULL: goto x86_l_1029;
	case 4144ULL: goto x86_l_1030;
	case 4147ULL: goto x86_l_1033;
	case 4152ULL: goto x86_l_1038;
	case 4157ULL: goto x86_l_103d;
	case 4164ULL: goto x86_l_1044;
	case 4169ULL: goto x86_l_1049;
	case 4171ULL: goto x86_l_104b;
	case 4178ULL: goto x86_l_1052;
	case 4181ULL: goto x86_l_1055;
	case 4183ULL: goto x86_l_1057;
	case 4187ULL: goto x86_l_105b;
	case 4192ULL: goto x86_l_1060;
	case 4195ULL: goto x86_l_1063;
	case 4197ULL: goto x86_l_1065;
	case 4200ULL: goto x86_l_1068;
	case 4202ULL: goto x86_l_106a;
	case 4205ULL: goto x86_l_106d;
	case 4209ULL: goto x86_l_1071;
	case 4212ULL: goto x86_l_1074;
	case 4214ULL: goto x86_l_1076;
	case 4216ULL: goto x86_l_1078;
	case 4219ULL: goto x86_l_107b;
	case 4222ULL: goto x86_l_107e;
	case 4225ULL: goto x86_l_1081;
	case 4228ULL: goto x86_l_1084;
	case 4236ULL: goto x86_l_108c;
	case 4242ULL: goto x86_l_1092;
	case 4247ULL: goto x86_l_1097;
	case 4254ULL: goto x86_l_109e;
	case 4259ULL: goto x86_l_10a3;
	case 4264ULL: goto x86_l_10a8;
	case 4269ULL: goto x86_l_10ad;
	case 4271ULL: goto x86_l_10af;
	case 4276ULL: goto x86_l_10b4;
	case 4281ULL: goto x86_l_10b9;
	case 4286ULL: goto x86_l_10be;
	case 4291ULL: goto x86_l_10c3;
	case 4293ULL: goto x86_l_10c5;
	case 4298ULL: goto x86_l_10ca;
	case 4303ULL: goto x86_l_10cf;
	case 4308ULL: goto x86_l_10d4;
	case 4311ULL: goto x86_l_10d7;
	case 4316ULL: goto x86_l_10dc;
	case 4318ULL: goto x86_l_10de;
	case 4322ULL: goto x86_l_10e2;
	case 4327ULL: goto x86_l_10e7;
	case 4330ULL: goto x86_l_10ea;
	case 4335ULL: goto x86_l_10ef;
	case 4338ULL: goto x86_l_10f2;
	case 4340ULL: goto x86_l_10f4;
	case 4347ULL: goto x86_l_10fb;
	case 4354ULL: goto x86_l_1102;
	case 4362ULL: goto x86_l_110a;
	case 4365ULL: goto x86_l_110d;
	case 4370ULL: goto x86_l_1112;
	case 4375ULL: goto x86_l_1117;
	case 4382ULL: goto x86_l_111e;
	case 4387ULL: goto x86_l_1123;
	case 4389ULL: goto x86_l_1125;
	case 4396ULL: goto x86_l_112c;
	case 4399ULL: goto x86_l_112f;
	case 4401ULL: goto x86_l_1131;
	case 4406ULL: goto x86_l_1136;
	case 4409ULL: goto x86_l_1139;
	case 4412ULL: goto x86_l_113c;
	case 4414ULL: goto x86_l_113e;
	case 4417ULL: goto x86_l_1141;
	case 4419ULL: goto x86_l_1143;
	case 4422ULL: goto x86_l_1146;
	case 4426ULL: goto x86_l_114a;
	case 4429ULL: goto x86_l_114d;
	case 4431ULL: goto x86_l_114f;
	case 4433ULL: goto x86_l_1151;
	case 4438ULL: goto x86_l_1156;
	case 4446ULL: goto x86_l_115e;
	case 4449ULL: goto x86_l_1161;
	case 4452ULL: goto x86_l_1164;
	case 4455ULL: goto x86_l_1167;
	case 4458ULL: goto x86_l_116a;
	case 4466ULL: goto x86_l_1172;
	case 4472ULL: goto x86_l_1178;
	case 4475ULL: goto x86_l_117b;
	case 4479ULL: goto x86_l_117f;
	case 4484ULL: goto x86_l_1184;
	case 4487ULL: goto x86_l_1187;
	case 4492ULL: goto x86_l_118c;
	case 4494ULL: goto x86_l_118e;
	case 4501ULL: goto x86_l_1195;
	case 4508ULL: goto x86_l_119c;
	case 4511ULL: goto x86_l_119f;
	case 4517ULL: goto x86_l_11a5;
	case 4522ULL: goto x86_l_11aa;
	case 4529ULL: goto x86_l_11b1;
	case 4534ULL: goto x86_l_11b6;
	case 4536ULL: goto x86_l_11b8;
	case 4543ULL: goto x86_l_11bf;
	case 4546ULL: goto x86_l_11c2;
	case 4548ULL: goto x86_l_11c4;
	case 4553ULL: goto x86_l_11c9;
	case 4556ULL: goto x86_l_11cc;
	case 4559ULL: goto x86_l_11cf;
	case 4561ULL: goto x86_l_11d1;
	case 4564ULL: goto x86_l_11d4;
	case 4566ULL: goto x86_l_11d6;
	case 4569ULL: goto x86_l_11d9;
	case 4573ULL: goto x86_l_11dd;
	case 4576ULL: goto x86_l_11e0;
	case 4578ULL: goto x86_l_11e2;
	case 4580ULL: goto x86_l_11e4;
	case 4585ULL: goto x86_l_11e9;
	case 4588ULL: goto x86_l_11ec;
	case 4591ULL: goto x86_l_11ef;
	case 4594ULL: goto x86_l_11f2;
	case 4597ULL: goto x86_l_11f5;
	case 4604ULL: goto x86_l_11fc;
	case 4607ULL: goto x86_l_11ff;
	case 4609ULL: goto x86_l_1201;
	case 4613ULL: goto x86_l_1205;
	case 4617ULL: goto x86_l_1209;
	case 4624ULL: goto x86_l_1210;
	case 4627ULL: goto x86_l_1213;
	case 4632ULL: goto x86_l_1218;
	case 4637ULL: goto x86_l_121d;
	case 4644ULL: goto x86_l_1224;
	case 4649ULL: goto x86_l_1229;
	case 4651ULL: goto x86_l_122b;
	case 4658ULL: goto x86_l_1232;
	case 4661ULL: goto x86_l_1235;
	case 4663ULL: goto x86_l_1237;
	case 4668ULL: goto x86_l_123c;
	case 4673ULL: goto x86_l_1241;
	case 4676ULL: goto x86_l_1244;
	case 4678ULL: goto x86_l_1246;
	case 4681ULL: goto x86_l_1249;
	case 4683ULL: goto x86_l_124b;
	case 4686ULL: goto x86_l_124e;
	case 4690ULL: goto x86_l_1252;
	case 4693ULL: goto x86_l_1255;
	case 4695ULL: goto x86_l_1257;
	case 4697ULL: goto x86_l_1259;
	case 4700ULL: goto x86_l_125c;
	case 4703ULL: goto x86_l_125f;
	case 4706ULL: goto x86_l_1262;
	case 4709ULL: goto x86_l_1265;
	case 4716ULL: goto x86_l_126c;
	case 4719ULL: goto x86_l_126f;
	case 4721ULL: goto x86_l_1271;
	case 4728ULL: goto x86_l_1278;
	case 4731ULL: goto x86_l_127b;
	case 4736ULL: goto x86_l_1280;
	case 4741ULL: goto x86_l_1285;
	case 4748ULL: goto x86_l_128c;
	case 4753ULL: goto x86_l_1291;
	case 4755ULL: goto x86_l_1293;
	case 4762ULL: goto x86_l_129a;
	case 4765ULL: goto x86_l_129d;
	case 4767ULL: goto x86_l_129f;
	case 4771ULL: goto x86_l_12a3;
	case 4776ULL: goto x86_l_12a8;
	case 4779ULL: goto x86_l_12ab;
	case 4781ULL: goto x86_l_12ad;
	case 4784ULL: goto x86_l_12b0;
	case 4786ULL: goto x86_l_12b2;
	case 4789ULL: goto x86_l_12b5;
	case 4793ULL: goto x86_l_12b9;
	case 4796ULL: goto x86_l_12bc;
	case 4798ULL: goto x86_l_12be;
	case 4800ULL: goto x86_l_12c0;
	case 4803ULL: goto x86_l_12c3;
	case 4806ULL: goto x86_l_12c6;
	case 4809ULL: goto x86_l_12c9;
	case 4812ULL: goto x86_l_12cc;
	case 4819ULL: goto x86_l_12d3;
	case 4822ULL: goto x86_l_12d6;
	case 4824ULL: goto x86_l_12d8;
	case 4831ULL: goto x86_l_12df;
	case 4834ULL: goto x86_l_12e2;
	case 4839ULL: goto x86_l_12e7;
	case 4844ULL: goto x86_l_12ec;
	case 4851ULL: goto x86_l_12f3;
	case 4856ULL: goto x86_l_12f8;
	case 4858ULL: goto x86_l_12fa;
	case 4865ULL: goto x86_l_1301;
	case 4868ULL: goto x86_l_1304;
	case 4870ULL: goto x86_l_1306;
	case 4873ULL: goto x86_l_1309;
	case 4878ULL: goto x86_l_130e;
	case 4882ULL: goto x86_l_1312;
	case 4887ULL: goto x86_l_1317;
	case 4890ULL: goto x86_l_131a;
	case 4892ULL: goto x86_l_131c;
	case 4895ULL: goto x86_l_131f;
	case 4897ULL: goto x86_l_1321;
	case 4902ULL: goto x86_l_1326;
	case 4906ULL: goto x86_l_132a;
	case 4911ULL: goto x86_l_132f;
	case 4914ULL: goto x86_l_1332;
	case 4916ULL: goto x86_l_1334;
	case 4919ULL: goto x86_l_1337;
	case 4921ULL: goto x86_l_1339;
	case 4924ULL: goto x86_l_133c;
	case 4928ULL: goto x86_l_1340;
	case 4931ULL: goto x86_l_1343;
	case 4933ULL: goto x86_l_1345;
	case 4935ULL: goto x86_l_1347;
	case 4938ULL: goto x86_l_134a;
	case 4941ULL: goto x86_l_134d;
	case 4944ULL: goto x86_l_1350;
	case 4947ULL: goto x86_l_1353;
	case 4954ULL: goto x86_l_135a;
	case 4957ULL: goto x86_l_135d;
	case 4959ULL: goto x86_l_135f;
	case 4964ULL: goto x86_l_1364;
	case 4968ULL: goto x86_l_1368;
	case 4971ULL: goto x86_l_136b;
	case 4978ULL: goto x86_l_1372;
	case 4985ULL: goto x86_l_1379;
	case 4988ULL: goto x86_l_137c;
	case 4995ULL: goto x86_l_1383;
	case 5001ULL: goto x86_l_1389;
	case 5009ULL: goto x86_l_1391;
	case 5013ULL: goto x86_l_1395;
	case 5021ULL: goto x86_l_139d;
	case 5026ULL: goto x86_l_13a2;
	case 5033ULL: goto x86_l_13a9;
	case 5038ULL: goto x86_l_13ae;
	case 5040ULL: goto x86_l_13b0;
	case 5043ULL: goto x86_l_13b3;
	case 5049ULL: goto x86_l_13b9;
	case 5052ULL: goto x86_l_13bc;
	case 5056ULL: goto x86_l_13c0;
	case 5061ULL: goto x86_l_13c5;
	case 5066ULL: goto x86_l_13ca;
	case 5071ULL: goto x86_l_13cf;
	case 5073ULL: goto x86_l_13d1;
	case 5078ULL: goto x86_l_13d6;
	case 5083ULL: goto x86_l_13db;
	case 5088ULL: goto x86_l_13e0;
	case 5093ULL: goto x86_l_13e5;
	case 5098ULL: goto x86_l_13ea;
	case 5103ULL: goto x86_l_13ef;
	case 5105ULL: goto x86_l_13f1;
	case 5110ULL: goto x86_l_13f6;
	case 5116ULL: goto x86_l_13fc;
	case 5120ULL: goto x86_l_1400;
	case 5125ULL: goto x86_l_1405;
	case 5130ULL: goto x86_l_140a;
	case 5135ULL: goto x86_l_140f;
	case 5137ULL: goto x86_l_1411;
	case 5142ULL: goto x86_l_1416;
	case 5146ULL: goto x86_l_141a;
	case 5151ULL: goto x86_l_141f;
	case 5156ULL: goto x86_l_1424;
	case 5161ULL: goto x86_l_1429;
	case 5166ULL: goto x86_l_142e;
	case 5171ULL: goto x86_l_1433;
	case 5173ULL: goto x86_l_1435;
	case 5178ULL: goto x86_l_143a;
	case 5183ULL: goto x86_l_143f;
	case 5188ULL: goto x86_l_1444;
	case 5191ULL: goto x86_l_1447;
	case 5193ULL: goto x86_l_1449;
	case 5198ULL: goto x86_l_144e;
	case 5203ULL: goto x86_l_1453;
	case 5207ULL: goto x86_l_1457;
	case 5212ULL: goto x86_l_145c;
	case 5217ULL: goto x86_l_1461;
	case 5222ULL: goto x86_l_1466;
	case 5224ULL: goto x86_l_1468;
	case 5229ULL: goto x86_l_146d;
	case 5232ULL: goto x86_l_1470;
	case 5238ULL: goto x86_l_1476;
	case 5243ULL: goto x86_l_147b;
	case 5246ULL: goto x86_l_147e;
	case 5248ULL: goto x86_l_1480;
	case 5252ULL: goto x86_l_1484;
	case 5257ULL: goto x86_l_1489;
	case 5262ULL: goto x86_l_148e;
	case 5267ULL: goto x86_l_1493;
	case 5269ULL: goto x86_l_1495;
	case 5273ULL: goto x86_l_1499;
	case 5278ULL: goto x86_l_149e;
	case 5280ULL: goto x86_l_14a0;
	case 5286ULL: goto x86_l_14a6;
	case 5288ULL: goto x86_l_14a8;
	case 5290ULL: goto x86_l_14aa;
	case 5296ULL: goto x86_l_14b0;
	case 5299ULL: goto x86_l_14b3;
	case 5304ULL: goto x86_l_14b8;
	case 5306ULL: goto x86_l_14ba;
	case 5309ULL: goto x86_l_14bd;
	case 5315ULL: goto x86_l_14c3;
	case 5322ULL: goto x86_l_14ca;
	case 5327ULL: goto x86_l_14cf;
	case 5329ULL: goto x86_l_14d1;
	case 5334ULL: goto x86_l_14d6;
	case 5339ULL: goto x86_l_14db;
	case 5344ULL: goto x86_l_14e0;
	case 5346ULL: goto x86_l_14e2;
	case 5351ULL: goto x86_l_14e7;
	case 5356ULL: goto x86_l_14ec;
	case 5363ULL: goto x86_l_14f3;
	case 5368ULL: goto x86_l_14f8;
	case 5371ULL: goto x86_l_14fb;
	case 5377ULL: goto x86_l_1501;
	case 5382ULL: goto x86_l_1506;
	case 5387ULL: goto x86_l_150b;
	case 5393ULL: goto x86_l_1511;
	default: return 0xffffffffffffffffULL;
	}
x86_l_eec:
	/* 0xeec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ef1:
	/* 0xef1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ef6:
	/* 0xef6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_efb:
	/* 0xefb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_efd:
	/* 0xefd: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f02:
	/* 0xf02: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f06:
	/* 0xf06: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f0b:
	/* 0xf0b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f10:
	/* 0xf10: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f15:
	/* 0xf15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f17:
	/* 0xf17: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f1c:
	/* 0xf1c: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f21:
	/* 0xf21: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f26:
	/* 0xf26: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f2b:
	/* 0xf2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f2d:
	/* 0xf2d: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f31:
	/* 0xf31: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_f35:
	/* 0xf35: mov    rbx,QWORD PTR [r14+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_f3c:
	/* 0xf3c: mov    r15,QWORD PTR [r14+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_f43:
	/* 0xf43: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f46:
	/* 0xf46: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f4b:
	/* 0xf4b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f50:
	/* 0xf50: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_f57:
	/* 0xf57: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f5c:
	/* 0xf5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f5e:
	/* 0xf5e: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f65:
	/* 0xf65: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f68:
	/* 0xf68: je     f89 <trace_security_file_open+0xf89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f89;
	}
x86_l_f6a:
	/* 0xf6a: lea    rsi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_f6e:
	/* 0xf6e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f73:
	/* 0xf73: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f76:
	/* 0xf76: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f78:
	/* 0xf78: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f7b:
	/* 0xf7b: je     f89 <trace_security_file_open+0xf89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f89;
	}
x86_l_f7d:
	/* 0xf7d: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f80:
	/* 0xf80: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f84:
	/* 0xf84: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f87:
	/* 0xf87: jmp    f8b <trace_security_file_open+0xf8b> */
	goto x86_l_f8b;
x86_l_f89:
	/* 0xf89: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f8b:
	/* 0xf8b: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f8e:
	/* 0xf8e: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_f91:
	/* 0xf91: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f94:
	/* 0xf94: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_f97:
	/* 0xf97: cmp    QWORD PTR [r14+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_f9f:
	/* 0xf9f: je     1084 <trace_security_file_open+0x1084> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1084;
	}
x86_l_fa5:
	/* 0xfa5: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_fac:
	/* 0xfac: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_fb0:
	/* 0xfb0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fb5:
	/* 0xfb5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fba:
	/* 0xfba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fbf:
	/* 0xfbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fc1:
	/* 0xfc1: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fc6:
	/* 0xfc6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fcb:
	/* 0xfcb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fd0:
	/* 0xfd0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fd5:
	/* 0xfd5: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_fd8:
	/* 0xfd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fda:
	/* 0xfda: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fde:
	/* 0xfde: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_fe2:
	/* 0xfe2: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_fe6:
	/* 0xfe6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_fea:
	/* 0xfea: movzx  ebp,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_fef:
	/* 0xfef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ff4:
	/* 0xff4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ff9:
	/* 0xff9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ffe:
	/* 0xffe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1000:
	/* 0x1000: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1005:
	/* 0x1005: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1009:
	/* 0x1009: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_100e:
	/* 0x100e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1013:
	/* 0x1013: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1018:
	/* 0x1018: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_101a:
	/* 0x101a: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_101e:
	/* 0x101e: mov    DWORD PTR [r14+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1022:
	/* 0x1022: mov    rbx,QWORD PTR [r14+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_1029:
	/* 0x1029: mov    r15,QWORD PTR [r14+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_1030:
	/* 0x1030: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1033:
	/* 0x1033: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1038:
	/* 0x1038: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_103d:
	/* 0x103d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_1044:
	/* 0x1044: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1049:
	/* 0x1049: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_104b:
	/* 0x104b: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1052:
	/* 0x1052: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1055:
	/* 0x1055: je     1076 <trace_security_file_open+0x1076> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1076;
	}
x86_l_1057:
	/* 0x1057: lea    rsi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_105b:
	/* 0x105b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1060:
	/* 0x1060: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1063:
	/* 0x1063: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1065:
	/* 0x1065: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1068:
	/* 0x1068: je     1076 <trace_security_file_open+0x1076> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1076;
	}
x86_l_106a:
	/* 0x106a: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_106d:
	/* 0x106d: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1071:
	/* 0x1071: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1074:
	/* 0x1074: jmp    1078 <trace_security_file_open+0x1078> */
	goto x86_l_1078;
x86_l_1076:
	/* 0x1076: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1078:
	/* 0x1078: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_107b:
	/* 0x107b: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_107e:
	/* 0x107e: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1081:
	/* 0x1081: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1084:
	/* 0x1084: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_108c:
	/* 0x108c: je     116a <trace_security_file_open+0x116a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_116a;
	}
x86_l_1092:
	/* 0x1092: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1097:
	/* 0x1097: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_109e:
	/* 0x109e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10a3:
	/* 0x10a3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10a8:
	/* 0x10a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10ad:
	/* 0x10ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10af:
	/* 0x10af: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10b4:
	/* 0x10b4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10b9:
	/* 0x10b9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10be:
	/* 0x10be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10c3:
	/* 0x10c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10c5:
	/* 0x10c5: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10ca:
	/* 0x10ca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10cf:
	/* 0x10cf: lea    r13,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10d4:
	/* 0x10d4: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_10d7:
	/* 0x10d7: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_10dc:
	/* 0x10dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10de:
	/* 0x10de: lea    r15,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_10e2:
	/* 0x10e2: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_10e7:
	/* 0x10e7: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_10ea:
	/* 0x10ea: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_10ef:
	/* 0x10ef: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_10f2:
	/* 0x10f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10f4:
	/* 0x10f4: mov    rbx,QWORD PTR [r14+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_10fb:
	/* 0x10fb: mov    rax,QWORD PTR [r14+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_1102:
	/* 0x1102: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_110a:
	/* 0x110a: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_110d:
	/* 0x110d: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1112:
	/* 0x1112: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1117:
	/* 0x1117: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_111e:
	/* 0x111e: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1123:
	/* 0x1123: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1125:
	/* 0x1125: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_112c:
	/* 0x112c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_112f:
	/* 0x112f: je     114f <trace_security_file_open+0x114f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_114f;
	}
x86_l_1131:
	/* 0x1131: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1136:
	/* 0x1136: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1139:
	/* 0x1139: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_113c:
	/* 0x113c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_113e:
	/* 0x113e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1141:
	/* 0x1141: je     114f <trace_security_file_open+0x114f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_114f;
	}
x86_l_1143:
	/* 0x1143: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1146:
	/* 0x1146: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_114a:
	/* 0x114a: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_114d:
	/* 0x114d: jmp    1151 <trace_security_file_open+0x1151> */
	goto x86_l_1151;
x86_l_114f:
	/* 0x114f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1151:
	/* 0x1151: movzx  ebp,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1156:
	/* 0x1156: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_115e:
	/* 0x115e: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1161:
	/* 0x1161: and    r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1164:
	/* 0x1164: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1167:
	/* 0x1167: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_116a:
	/* 0x116a: cmp    QWORD PTR [r14+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_1172:
	/* 0x1172: je     11f5 <trace_security_file_open+0x11f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11f5;
	}
x86_l_1178:
	/* 0x1178: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_117b:
	/* 0x117b: lea    rbp,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_117f:
	/* 0x117f: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1184:
	/* 0x1184: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1187:
	/* 0x1187: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_118c:
	/* 0x118c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_118e:
	/* 0x118e: mov    rbx,QWORD PTR [r14+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_1195:
	/* 0x1195: mov    r15,QWORD PTR [r14+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_119c:
	/* 0x119c: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_119f:
	/* 0x119f: mov    WORD PTR [rsp+0x30],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11a5:
	/* 0x11a5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11aa:
	/* 0x11aa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_11b1:
	/* 0x11b1: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11b6:
	/* 0x11b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11b8:
	/* 0x11b8: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_11bf:
	/* 0x11bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11c2:
	/* 0x11c2: je     11e2 <trace_security_file_open+0x11e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11e2;
	}
x86_l_11c4:
	/* 0x11c4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11c9:
	/* 0x11c9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_11cc:
	/* 0x11cc: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_11cf:
	/* 0x11cf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_11d1:
	/* 0x11d1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11d4:
	/* 0x11d4: je     11e2 <trace_security_file_open+0x11e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11e2;
	}
x86_l_11d6:
	/* 0x11d6: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11d9:
	/* 0x11d9: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11dd:
	/* 0x11dd: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_11e0:
	/* 0x11e0: jmp    11e4 <trace_security_file_open+0x11e4> */
	goto x86_l_11e4;
x86_l_11e2:
	/* 0x11e2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11e4:
	/* 0x11e4: movzx  ebp,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_11e9:
	/* 0x11e9: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_11ec:
	/* 0x11ec: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_11ef:
	/* 0x11ef: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_11f2:
	/* 0x11f2: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_11f5:
	/* 0x11f5: mov    rbx,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_11fc:
	/* 0x11fc: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_11ff:
	/* 0x11ff: je     1265 <trace_security_file_open+0x1265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1265;
	}
x86_l_1201:
	/* 0x1201: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1205:
	/* 0x1205: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1209:
	/* 0x1209: mov    r15,QWORD PTR [r14+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_1210:
	/* 0x1210: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1213:
	/* 0x1213: mov    WORD PTR [rsp+0x18],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1218:
	/* 0x1218: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_121d:
	/* 0x121d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_1224:
	/* 0x1224: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1229:
	/* 0x1229: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_122b:
	/* 0x122b: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1232:
	/* 0x1232: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1235:
	/* 0x1235: je     1257 <trace_security_file_open+0x1257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1257;
	}
x86_l_1237:
	/* 0x1237: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_123c:
	/* 0x123c: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1241:
	/* 0x1241: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1244:
	/* 0x1244: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1246:
	/* 0x1246: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1249:
	/* 0x1249: je     1257 <trace_security_file_open+0x1257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1257;
	}
x86_l_124b:
	/* 0x124b: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_124e:
	/* 0x124e: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1252:
	/* 0x1252: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1255:
	/* 0x1255: jmp    1259 <trace_security_file_open+0x1259> */
	goto x86_l_1259;
x86_l_1257:
	/* 0x1257: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1259:
	/* 0x1259: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_125c:
	/* 0x125c: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_125f:
	/* 0x125f: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1262:
	/* 0x1262: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1265:
	/* 0x1265: mov    rbx,QWORD PTR [r14+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_126c:
	/* 0x126c: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_126f:
	/* 0x126f: je     12cc <trace_security_file_open+0x12cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12cc;
	}
x86_l_1271:
	/* 0x1271: mov    r15,QWORD PTR [r14+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_1278:
	/* 0x1278: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_127b:
	/* 0x127b: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1280:
	/* 0x1280: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1285:
	/* 0x1285: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_128c:
	/* 0x128c: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1291:
	/* 0x1291: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1293:
	/* 0x1293: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_129a:
	/* 0x129a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_129d:
	/* 0x129d: je     12be <trace_security_file_open+0x12be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12be;
	}
x86_l_129f:
	/* 0x129f: lea    rsi,[r14+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_12a3:
	/* 0x12a3: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_12a8:
	/* 0x12a8: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_12ab:
	/* 0x12ab: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_12ad:
	/* 0x12ad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12b0:
	/* 0x12b0: je     12be <trace_security_file_open+0x12be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12be;
	}
x86_l_12b2:
	/* 0x12b2: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12b5:
	/* 0x12b5: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12b9:
	/* 0x12b9: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12bc:
	/* 0x12bc: jmp    12c0 <trace_security_file_open+0x12c0> */
	goto x86_l_12c0;
x86_l_12be:
	/* 0x12be: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12c0:
	/* 0x12c0: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_12c3:
	/* 0x12c3: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_12c6:
	/* 0x12c6: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_12c9:
	/* 0x12c9: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_12cc:
	/* 0x12cc: mov    rbx,QWORD PTR [r14+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_12d3:
	/* 0x12d3: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_12d6:
	/* 0x12d6: je     1353 <trace_security_file_open+0x1353> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1353;
	}
x86_l_12d8:
	/* 0x12d8: mov    r15,QWORD PTR [r14+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_12df:
	/* 0x12df: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12e2:
	/* 0x12e2: mov    WORD PTR [rsp+0x30],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12e7:
	/* 0x12e7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12ec:
	/* 0x12ec: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_12f3:
	/* 0x12f3: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12f8:
	/* 0x12f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12fa:
	/* 0x12fa: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1301:
	/* 0x1301: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1304:
	/* 0x1304: je     1345 <trace_security_file_open+0x1345> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1345;
	}
x86_l_1306:
	/* 0x1306: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1309:
	/* 0x1309: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_130e:
	/* 0x130e: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1312:
	/* 0x1312: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1317:
	/* 0x1317: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_131a:
	/* 0x131a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_131c:
	/* 0x131c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_131f:
	/* 0x131f: jne    1339 <trace_security_file_open+0x1339> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1339;
	}
x86_l_1321:
	/* 0x1321: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1326:
	/* 0x1326: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_132a:
	/* 0x132a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_132f:
	/* 0x132f: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1332:
	/* 0x1332: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1334:
	/* 0x1334: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1337:
	/* 0x1337: je     1345 <trace_security_file_open+0x1345> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1345;
	}
x86_l_1339:
	/* 0x1339: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_133c:
	/* 0x133c: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1340:
	/* 0x1340: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1343:
	/* 0x1343: jmp    1347 <trace_security_file_open+0x1347> */
	goto x86_l_1347;
x86_l_1345:
	/* 0x1345: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1347:
	/* 0x1347: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_134a:
	/* 0x134a: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_134d:
	/* 0x134d: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1350:
	/* 0x1350: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1353:
	/* 0x1353: mov    rax,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_135a:
	/* 0x135a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_135d:
	/* 0x135d: je     136b <trace_security_file_open+0x136b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_136b;
	}
x86_l_135f:
	/* 0x135f: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1364:
	/* 0x1364: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_1368:
	/* 0x1368: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_136b:
	/* 0x136b: and    r12,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_1372:
	/* 0x1372: mov    rax,QWORD PTR [r14+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1379:
	/* 0x1379: and    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_137c:
	/* 0x137c: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1383:
	/* 0x1383: je     1e70 <trace_security_file_open+0x1e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7792ULL;
	}
x86_l_1389:
	/* 0x1389: mov    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1391:
	/* 0x1391: mov    rbx,QWORD PTR [rax+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1395:
	/* 0x1395: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_139d:
	/* 0x139d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13a2:
	/* 0x13a2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_13a9:
	/* 0x13a9: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13ae:
	/* 0x13ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b0:
	/* 0x13b0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13b3:
	/* 0x13b3: je     14e0 <trace_security_file_open+0x14e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14e0;
	}
x86_l_13b9:
	/* 0x13b9: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_13bc:
	/* 0x13bc: lea    rdx,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13c0:
	/* 0x13c0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13c5:
	/* 0x13c5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13ca:
	/* 0x13ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13cf:
	/* 0x13cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13d1:
	/* 0x13d1: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13d6:
	/* 0x13d6: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13db:
	/* 0x13db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13e0:
	/* 0x13e0: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13e5:
	/* 0x13e5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13ea:
	/* 0x13ea: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13ef:
	/* 0x13ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f1:
	/* 0x13f1: test   BYTE PTR [rsp+0x30],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430240ULL);
x86_l_13f6:
	/* 0x13f6: jne    14e7 <trace_security_file_open+0x14e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14e7;
	}
x86_l_13fc:
	/* 0x13fc: lea    rdx,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1400:
	/* 0x1400: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1405:
	/* 0x1405: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_140a:
	/* 0x140a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_140f:
	/* 0x140f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1411:
	/* 0x1411: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1416:
	/* 0x1416: lea    rax,[r13-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_141a:
	/* 0x141a: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_141f:
	/* 0x141f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1424:
	/* 0x1424: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1429:
	/* 0x1429: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_142e:
	/* 0x142e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1433:
	/* 0x1433: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1435:
	/* 0x1435: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_143a:
	/* 0x143a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_143f:
	/* 0x143f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1444:
	/* 0x1444: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1447:
	/* 0x1447: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1449:
	/* 0x1449: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_144e:
	/* 0x144e: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1453:
	/* 0x1453: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1457:
	/* 0x1457: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_145c:
	/* 0x145c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1461:
	/* 0x1461: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1466:
	/* 0x1466: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1468:
	/* 0x1468: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_146d:
	/* 0x146d: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1470:
	/* 0x1470: je     14f8 <trace_security_file_open+0x14f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14f8;
	}
x86_l_1476:
	/* 0x1476: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_147b:
	/* 0x147b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_147e:
	/* 0x147e: je     14f8 <trace_security_file_open+0x14f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14f8;
	}
x86_l_1480:
	/* 0x1480: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1484:
	/* 0x1484: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1489:
	/* 0x1489: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_148e:
	/* 0x148e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1493:
	/* 0x1493: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1495:
	/* 0x1495: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1499:
	/* 0x1499: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_149e:
	/* 0x149e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_14a0:
	/* 0x14a0: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14a6:
	/* 0x14a6: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_14a8:
	/* 0x14a8: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_14aa:
	/* 0x14aa: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_14b0:
	/* 0x14b0: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_14b3:
	/* 0x14b3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_14b8:
	/* 0x14b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14ba:
	/* 0x14ba: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_14bd:
	/* 0x14bd: jl     163c <trace_security_file_open+0x163c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5692ULL;
	}
x86_l_14c3:
	/* 0x14c3: mov    BYTE PTR [rbp+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_14ca:
	/* 0x14ca: mov    ecx,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16384ULL);
x86_l_14cf:
	/* 0x14cf: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_14d1:
	/* 0x14d1: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14d6:
	/* 0x14d6: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14db:
	/* 0x14db: jmp    156a <trace_security_file_open+0x156a> */
	return 5482ULL;
x86_l_14e0:
	/* 0x14e0: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14e2:
	/* 0x14e2: jmp    1677 <trace_security_file_open+0x1677> */
	return 5751ULL;
x86_l_14e7:
	/* 0x14e7: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_14ec:
	/* 0x14ec: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_14f3:
	/* 0x14f3: jmp    1660 <trace_security_file_open+0x1660> */
	return 5728ULL;
x86_l_14f8:
	/* 0x14f8: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_14fb:
	/* 0x14fb: jne    163c <trace_security_file_open+0x163c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5692ULL;
	}
x86_l_1501:
	/* 0x1501: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1506:
	/* 0x1506: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_150b:
	/* 0x150b: je     163c <trace_security_file_open+0x163c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5692ULL;
	}
x86_l_1511:
	/* 0x1511: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
	return 5398ULL;
}

static __noinline __u64 tracee_trace_security_file_open_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5398ULL: goto x86_l_1516;
	case 5403ULL: goto x86_l_151b;
	case 5407ULL: goto x86_l_151f;
	case 5412ULL: goto x86_l_1524;
	case 5417ULL: goto x86_l_1529;
	case 5419ULL: goto x86_l_152b;
	case 5424ULL: goto x86_l_1530;
	case 5429ULL: goto x86_l_1535;
	case 5434ULL: goto x86_l_153a;
	case 5439ULL: goto x86_l_153f;
	case 5441ULL: goto x86_l_1541;
	case 5446ULL: goto x86_l_1546;
	case 5451ULL: goto x86_l_154b;
	case 5456ULL: goto x86_l_1550;
	case 5461ULL: goto x86_l_1555;
	case 5463ULL: goto x86_l_1557;
	case 5468ULL: goto x86_l_155c;
	case 5472ULL: goto x86_l_1560;
	case 5477ULL: goto x86_l_1565;
	case 5482ULL: goto x86_l_156a;
	case 5487ULL: goto x86_l_156f;
	case 5492ULL: goto x86_l_1574;
	case 5497ULL: goto x86_l_1579;
	case 5500ULL: goto x86_l_157c;
	case 5502ULL: goto x86_l_157e;
	case 5507ULL: goto x86_l_1583;
	case 5512ULL: goto x86_l_1588;
	case 5516ULL: goto x86_l_158c;
	case 5521ULL: goto x86_l_1591;
	case 5526ULL: goto x86_l_1596;
	case 5531ULL: goto x86_l_159b;
	case 5533ULL: goto x86_l_159d;
	case 5538ULL: goto x86_l_15a2;
	case 5541ULL: goto x86_l_15a5;
	case 5543ULL: goto x86_l_15a7;
	case 5548ULL: goto x86_l_15ac;
	case 5551ULL: goto x86_l_15af;
	case 5553ULL: goto x86_l_15b1;
	case 5557ULL: goto x86_l_15b5;
	case 5562ULL: goto x86_l_15ba;
	case 5567ULL: goto x86_l_15bf;
	case 5572ULL: goto x86_l_15c4;
	case 5574ULL: goto x86_l_15c6;
	case 5578ULL: goto x86_l_15ca;
	case 5580ULL: goto x86_l_15cc;
	case 5586ULL: goto x86_l_15d2;
	case 5591ULL: goto x86_l_15d7;
	case 5594ULL: goto x86_l_15da;
	case 5596ULL: goto x86_l_15dc;
	case 5602ULL: goto x86_l_15e2;
	case 5607ULL: goto x86_l_15e7;
	case 5613ULL: goto x86_l_15ed;
	case 5616ULL: goto x86_l_15f0;
	case 5621ULL: goto x86_l_15f5;
	case 5623ULL: goto x86_l_15f7;
	case 5626ULL: goto x86_l_15fa;
	case 5628ULL: goto x86_l_15fc;
	case 5633ULL: goto x86_l_1601;
	case 5639ULL: goto x86_l_1607;
	case 5644ULL: goto x86_l_160c;
	case 5647ULL: goto x86_l_160f;
	case 5652ULL: goto x86_l_1614;
	case 5657ULL: goto x86_l_1619;
	case 5660ULL: goto x86_l_161c;
	case 5665ULL: goto x86_l_1621;
	case 5668ULL: goto x86_l_1624;
	case 5674ULL: goto x86_l_162a;
	case 5679ULL: goto x86_l_162f;
	case 5686ULL: goto x86_l_1636;
	case 5692ULL: goto x86_l_163c;
	case 5697ULL: goto x86_l_1641;
	case 5701ULL: goto x86_l_1645;
	case 5706ULL: goto x86_l_164a;
	case 5711ULL: goto x86_l_164f;
	case 5716ULL: goto x86_l_1654;
	case 5718ULL: goto x86_l_1656;
	case 5723ULL: goto x86_l_165b;
	case 5728ULL: goto x86_l_1660;
	case 5731ULL: goto x86_l_1663;
	case 5736ULL: goto x86_l_1668;
	case 5738ULL: goto x86_l_166a;
	case 5741ULL: goto x86_l_166d;
	case 5748ULL: goto x86_l_1674;
	case 5751ULL: goto x86_l_1677;
	case 5755ULL: goto x86_l_167b;
	case 5760ULL: goto x86_l_1680;
	case 5765ULL: goto x86_l_1685;
	case 5770ULL: goto x86_l_168a;
	case 5772ULL: goto x86_l_168c;
	case 5776ULL: goto x86_l_1690;
	case 5780ULL: goto x86_l_1694;
	case 5784ULL: goto x86_l_1698;
	case 5789ULL: goto x86_l_169d;
	case 5794ULL: goto x86_l_16a2;
	case 5799ULL: goto x86_l_16a7;
	case 5802ULL: goto x86_l_16aa;
	case 5804ULL: goto x86_l_16ac;
	case 5809ULL: goto x86_l_16b1;
	case 5814ULL: goto x86_l_16b6;
	case 5818ULL: goto x86_l_16ba;
	case 5823ULL: goto x86_l_16bf;
	case 5828ULL: goto x86_l_16c4;
	case 5830ULL: goto x86_l_16c6;
	case 5835ULL: goto x86_l_16cb;
	case 5840ULL: goto x86_l_16d0;
	case 5845ULL: goto x86_l_16d5;
	case 5850ULL: goto x86_l_16da;
	case 5852ULL: goto x86_l_16dc;
	case 5856ULL: goto x86_l_16e0;
	case 5863ULL: goto x86_l_16e7;
	case 5868ULL: goto x86_l_16ec;
	case 5873ULL: goto x86_l_16f1;
	case 5878ULL: goto x86_l_16f6;
	case 5881ULL: goto x86_l_16f9;
	case 5883ULL: goto x86_l_16fb;
	case 5888ULL: goto x86_l_1700;
	case 5893ULL: goto x86_l_1705;
	case 5897ULL: goto x86_l_1709;
	case 5902ULL: goto x86_l_170e;
	case 5907ULL: goto x86_l_1713;
	case 5909ULL: goto x86_l_1715;
	case 5914ULL: goto x86_l_171a;
	case 5919ULL: goto x86_l_171f;
	case 5924ULL: goto x86_l_1724;
	case 5929ULL: goto x86_l_1729;
	case 5934ULL: goto x86_l_172e;
	case 5937ULL: goto x86_l_1731;
	case 5939ULL: goto x86_l_1733;
	case 5948ULL: goto x86_l_173c;
	case 5953ULL: goto x86_l_1741;
	case 5962ULL: goto x86_l_174a;
	case 5966ULL: goto x86_l_174e;
	case 5971ULL: goto x86_l_1753;
	case 5976ULL: goto x86_l_1758;
	case 5981ULL: goto x86_l_175d;
	case 5983ULL: goto x86_l_175f;
	case 5988ULL: goto x86_l_1764;
	case 5993ULL: goto x86_l_1769;
	case 5997ULL: goto x86_l_176d;
	case 6002ULL: goto x86_l_1772;
	case 6007ULL: goto x86_l_1777;
	case 6012ULL: goto x86_l_177c;
	case 6015ULL: goto x86_l_177f;
	case 6017ULL: goto x86_l_1781;
	case 6021ULL: goto x86_l_1785;
	case 6026ULL: goto x86_l_178a;
	case 6031ULL: goto x86_l_178f;
	case 6036ULL: goto x86_l_1794;
	case 6041ULL: goto x86_l_1799;
	case 6046ULL: goto x86_l_179e;
	case 6048ULL: goto x86_l_17a0;
	case 6053ULL: goto x86_l_17a5;
	case 6056ULL: goto x86_l_17a8;
	case 6058ULL: goto x86_l_17aa;
	case 6063ULL: goto x86_l_17af;
	case 6068ULL: goto x86_l_17b4;
	case 6073ULL: goto x86_l_17b9;
	case 6078ULL: goto x86_l_17be;
	case 6080ULL: goto x86_l_17c0;
	case 6087ULL: goto x86_l_17c7;
	case 6092ULL: goto x86_l_17cc;
	case 6094ULL: goto x86_l_17ce;
	case 6096ULL: goto x86_l_17d0;
	case 6101ULL: goto x86_l_17d5;
	case 6109ULL: goto x86_l_17dd;
	case 6114ULL: goto x86_l_17e2;
	case 6116ULL: goto x86_l_17e4;
	case 6121ULL: goto x86_l_17e9;
	case 6124ULL: goto x86_l_17ec;
	case 6126ULL: goto x86_l_17ee;
	case 6129ULL: goto x86_l_17f1;
	case 6133ULL: goto x86_l_17f5;
	case 6138ULL: goto x86_l_17fa;
	case 6140ULL: goto x86_l_17fc;
	case 6145ULL: goto x86_l_1801;
	case 6147ULL: goto x86_l_1803;
	case 6152ULL: goto x86_l_1808;
	case 6154ULL: goto x86_l_180a;
	case 6159ULL: goto x86_l_180f;
	case 6165ULL: goto x86_l_1815;
	case 6172ULL: goto x86_l_181c;
	case 6177ULL: goto x86_l_1821;
	case 6182ULL: goto x86_l_1826;
	case 6187ULL: goto x86_l_182b;
	case 6189ULL: goto x86_l_182d;
	case 6194ULL: goto x86_l_1832;
	case 6196ULL: goto x86_l_1834;
	case 6200ULL: goto x86_l_1838;
	case 6202ULL: goto x86_l_183a;
	case 6205ULL: goto x86_l_183d;
	case 6207ULL: goto x86_l_183f;
	case 6210ULL: goto x86_l_1842;
	case 6212ULL: goto x86_l_1844;
	case 6219ULL: goto x86_l_184b;
	case 6224ULL: goto x86_l_1850;
	case 6229ULL: goto x86_l_1855;
	case 6234ULL: goto x86_l_185a;
	case 6236ULL: goto x86_l_185c;
	case 6241ULL: goto x86_l_1861;
	case 6243ULL: goto x86_l_1863;
	case 6247ULL: goto x86_l_1867;
	case 6249ULL: goto x86_l_1869;
	case 6253ULL: goto x86_l_186d;
	case 6258ULL: goto x86_l_1872;
	case 6260ULL: goto x86_l_1874;
	case 6264ULL: goto x86_l_1878;
	case 6269ULL: goto x86_l_187d;
	case 6274ULL: goto x86_l_1882;
	case 6279ULL: goto x86_l_1887;
	case 6282ULL: goto x86_l_188a;
	case 6284ULL: goto x86_l_188c;
	case 6289ULL: goto x86_l_1891;
	case 6297ULL: goto x86_l_1899;
	case 6305ULL: goto x86_l_18a1;
	case 6311ULL: goto x86_l_18a7;
	case 6313ULL: goto x86_l_18a9;
	case 6322ULL: goto x86_l_18b2;
	case 6330ULL: goto x86_l_18ba;
	case 6338ULL: goto x86_l_18c2;
	case 6343ULL: goto x86_l_18c7;
	case 6345ULL: goto x86_l_18c9;
	case 6350ULL: goto x86_l_18ce;
	case 6358ULL: goto x86_l_18d6;
	case 6362ULL: goto x86_l_18da;
	case 6369ULL: goto x86_l_18e1;
	case 6374ULL: goto x86_l_18e6;
	case 6377ULL: goto x86_l_18e9;
	case 6379ULL: goto x86_l_18eb;
	case 6381ULL: goto x86_l_18ed;
	case 6383ULL: goto x86_l_18ef;
	case 6391ULL: goto x86_l_18f7;
	case 6398ULL: goto x86_l_18fe;
	case 6400ULL: goto x86_l_1900;
	case 6408ULL: goto x86_l_1908;
	case 6416ULL: goto x86_l_1910;
	case 6419ULL: goto x86_l_1913;
	case 6427ULL: goto x86_l_191b;
	case 6434ULL: goto x86_l_1922;
	case 6442ULL: goto x86_l_192a;
	case 6449ULL: goto x86_l_1931;
	case 6451ULL: goto x86_l_1933;
	case 6460ULL: goto x86_l_193c;
	case 6466ULL: goto x86_l_1942;
	case 6468ULL: goto x86_l_1944;
	case 6472ULL: goto x86_l_1948;
	case 6479ULL: goto x86_l_194f;
	case 6484ULL: goto x86_l_1954;
	case 6489ULL: goto x86_l_1959;
	case 6494ULL: goto x86_l_195e;
	case 6496ULL: goto x86_l_1960;
	case 6499ULL: goto x86_l_1963;
	case 6501ULL: goto x86_l_1965;
	case 6504ULL: goto x86_l_1968;
	case 6512ULL: goto x86_l_1970;
	case 6519ULL: goto x86_l_1977;
	case 6527ULL: goto x86_l_197f;
	case 6534ULL: goto x86_l_1986;
	case 6536ULL: goto x86_l_1988;
	case 6545ULL: goto x86_l_1991;
	case 6551ULL: goto x86_l_1997;
	case 6553ULL: goto x86_l_1999;
	case 6557ULL: goto x86_l_199d;
	case 6564ULL: goto x86_l_19a4;
	case 6569ULL: goto x86_l_19a9;
	case 6577ULL: goto x86_l_19b1;
	case 6582ULL: goto x86_l_19b6;
	case 6584ULL: goto x86_l_19b8;
	case 6587ULL: goto x86_l_19bb;
	case 6589ULL: goto x86_l_19bd;
	case 6592ULL: goto x86_l_19c0;
	case 6600ULL: goto x86_l_19c8;
	case 6607ULL: goto x86_l_19cf;
	case 6615ULL: goto x86_l_19d7;
	case 6622ULL: goto x86_l_19de;
	case 6624ULL: goto x86_l_19e0;
	case 6633ULL: goto x86_l_19e9;
	case 6639ULL: goto x86_l_19ef;
	case 6641ULL: goto x86_l_19f1;
	case 6645ULL: goto x86_l_19f5;
	case 6652ULL: goto x86_l_19fc;
	case 6657ULL: goto x86_l_1a01;
	case 6662ULL: goto x86_l_1a06;
	case 6667ULL: goto x86_l_1a0b;
	case 6669ULL: goto x86_l_1a0d;
	case 6672ULL: goto x86_l_1a10;
	case 6674ULL: goto x86_l_1a12;
	case 6677ULL: goto x86_l_1a15;
	case 6685ULL: goto x86_l_1a1d;
	case 6692ULL: goto x86_l_1a24;
	case 6700ULL: goto x86_l_1a2c;
	case 6707ULL: goto x86_l_1a33;
	case 6713ULL: goto x86_l_1a39;
	case 6722ULL: goto x86_l_1a42;
	case 6728ULL: goto x86_l_1a48;
	case 6730ULL: goto x86_l_1a4a;
	case 6734ULL: goto x86_l_1a4e;
	case 6741ULL: goto x86_l_1a55;
	case 6746ULL: goto x86_l_1a5a;
	case 6751ULL: goto x86_l_1a5f;
	case 6756ULL: goto x86_l_1a64;
	case 6758ULL: goto x86_l_1a66;
	case 6761ULL: goto x86_l_1a69;
	case 6763ULL: goto x86_l_1a6b;
	case 6766ULL: goto x86_l_1a6e;
	case 6774ULL: goto x86_l_1a76;
	case 6781ULL: goto x86_l_1a7d;
	case 6784ULL: goto x86_l_1a80;
	case 6789ULL: goto x86_l_1a85;
	case 6791ULL: goto x86_l_1a87;
	case 6796ULL: goto x86_l_1a8c;
	case 6804ULL: goto x86_l_1a94;
	case 6807ULL: goto x86_l_1a97;
	case 6812ULL: goto x86_l_1a9c;
	case 6818ULL: goto x86_l_1aa2;
	case 6827ULL: goto x86_l_1aab;
	case 6835ULL: goto x86_l_1ab3;
	case 6843ULL: goto x86_l_1abb;
	case 6848ULL: goto x86_l_1ac0;
	case 6850ULL: goto x86_l_1ac2;
	case 6855ULL: goto x86_l_1ac7;
	case 6863ULL: goto x86_l_1acf;
	case 6867ULL: goto x86_l_1ad3;
	case 6874ULL: goto x86_l_1ada;
	case 6879ULL: goto x86_l_1adf;
	case 6887ULL: goto x86_l_1ae7;
	case 6889ULL: goto x86_l_1ae9;
	case 6891ULL: goto x86_l_1aeb;
	case 6893ULL: goto x86_l_1aed;
	case 6901ULL: goto x86_l_1af5;
	case 6908ULL: goto x86_l_1afc;
	case 6910ULL: goto x86_l_1afe;
	case 6918ULL: goto x86_l_1b06;
	case 6926ULL: goto x86_l_1b0e;
	case 6929ULL: goto x86_l_1b11;
	case 6937ULL: goto x86_l_1b19;
	case 6944ULL: goto x86_l_1b20;
	case 6951ULL: goto x86_l_1b27;
	case 6958ULL: goto x86_l_1b2e;
	case 6965ULL: goto x86_l_1b35;
	case 6968ULL: goto x86_l_1b38;
	case 6974ULL: goto x86_l_1b3e;
	case 6981ULL: goto x86_l_1b45;
	case 6985ULL: goto x86_l_1b49;
	case 6990ULL: goto x86_l_1b4e;
	case 6995ULL: goto x86_l_1b53;
	case 7003ULL: goto x86_l_1b5b;
	case 7008ULL: goto x86_l_1b60;
	case 7015ULL: goto x86_l_1b67;
	case 7020ULL: goto x86_l_1b6c;
	case 7022ULL: goto x86_l_1b6e;
	case 7025ULL: goto x86_l_1b71;
	case 7031ULL: goto x86_l_1b77;
	case 7034ULL: goto x86_l_1b7a;
	case 7038ULL: goto x86_l_1b7e;
	case 7040ULL: goto x86_l_1b80;
	case 7045ULL: goto x86_l_1b85;
	case 7048ULL: goto x86_l_1b88;
	case 7050ULL: goto x86_l_1b8a;
	case 7055ULL: goto x86_l_1b8f;
	case 7060ULL: goto x86_l_1b94;
	case 7066ULL: goto x86_l_1b9a;
	case 7072ULL: goto x86_l_1ba0;
	case 7080ULL: goto x86_l_1ba8;
	case 7086ULL: goto x86_l_1bae;
	case 7092ULL: goto x86_l_1bb4;
	case 7095ULL: goto x86_l_1bb7;
	case 7098ULL: goto x86_l_1bba;
	case 7101ULL: goto x86_l_1bbd;
	case 7107ULL: goto x86_l_1bc3;
	case 7113ULL: goto x86_l_1bc9;
	case 7117ULL: goto x86_l_1bcd;
	case 7124ULL: goto x86_l_1bd4;
	case 7129ULL: goto x86_l_1bd9;
	case 7132ULL: goto x86_l_1bdc;
	case 7134ULL: goto x86_l_1bde;
	case 7136ULL: goto x86_l_1be0;
	case 7142ULL: goto x86_l_1be6;
	case 7149ULL: goto x86_l_1bed;
	case 7154ULL: goto x86_l_1bf2;
	case 7159ULL: goto x86_l_1bf7;
	case 7166ULL: goto x86_l_1bfe;
	case 7170ULL: goto x86_l_1c02;
	case 7174ULL: goto x86_l_1c06;
	case 7179ULL: goto x86_l_1c0b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1516:
	/* 0x1516: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_151b:
	/* 0x151b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_151f:
	/* 0x151f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1524:
	/* 0x1524: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1529:
	/* 0x1529: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_152b:
	/* 0x152b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1530:
	/* 0x1530: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1535:
	/* 0x1535: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_153a:
	/* 0x153a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_153f:
	/* 0x153f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1541:
	/* 0x1541: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1546:
	/* 0x1546: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_154b:
	/* 0x154b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1550:
	/* 0x1550: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1555:
	/* 0x1555: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1557:
	/* 0x1557: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_155c:
	/* 0x155c: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1560:
	/* 0x1560: mov    eax,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16384ULL);
x86_l_1565:
	/* 0x1565: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_156a:
	/* 0x156a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_156f:
	/* 0x156f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1574:
	/* 0x1574: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1579:
	/* 0x1579: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_157c:
	/* 0x157c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_157e:
	/* 0x157e: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1583:
	/* 0x1583: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1588:
	/* 0x1588: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_158c:
	/* 0x158c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1591:
	/* 0x1591: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1596:
	/* 0x1596: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_159b:
	/* 0x159b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_159d:
	/* 0x159d: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15a2:
	/* 0x15a2: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_15a5:
	/* 0x15a5: je     1621 <trace_security_file_open+0x1621> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1621;
	}
x86_l_15a7:
	/* 0x15a7: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15ac:
	/* 0x15ac: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_15af:
	/* 0x15af: je     1621 <trace_security_file_open+0x1621> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1621;
	}
x86_l_15b1:
	/* 0x15b1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_15b5:
	/* 0x15b5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15ba:
	/* 0x15ba: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15bf:
	/* 0x15bf: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_15c4:
	/* 0x15c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15c6:
	/* 0x15c6: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_15ca:
	/* 0x15ca: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_15cc:
	/* 0x15cc: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15d2:
	/* 0x15d2: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15d7:
	/* 0x15d7: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_15da:
	/* 0x15da: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_15dc:
	/* 0x15dc: jb     1f64 <trace_security_file_open+0x1f64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8036ULL;
	}
x86_l_15e2:
	/* 0x15e2: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15e7:
	/* 0x15e7: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_15ed:
	/* 0x15ed: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_15f0:
	/* 0x15f0: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_15f5:
	/* 0x15f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15f7:
	/* 0x15f7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15fa:
	/* 0x15fa: jl     162f <trace_security_file_open+0x162f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_162f;
	}
x86_l_15fc:
	/* 0x15fc: lea    ecx,[r12-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1601:
	/* 0x1601: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1607:
	/* 0x1607: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_160c:
	/* 0x160c: sub    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_160f:
	/* 0x160f: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1614:
	/* 0x1614: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1619:
	/* 0x1619: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_161c:
	/* 0x161c: jmp    1eec <trace_security_file_open+0x1eec> */
	return 7916ULL;
x86_l_1621:
	/* 0x1621: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1624:
	/* 0x1624: je     1e8d <trace_security_file_open+0x1e8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7821ULL;
	}
x86_l_162a:
	/* 0x162a: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_162f:
	/* 0x162f: cmp    r12d,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 16384ULL);
x86_l_1636:
	/* 0x1636: jne    1f64 <trace_security_file_open+0x1f64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8036ULL;
	}
x86_l_163c:
	/* 0x163c: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1641:
	/* 0x1641: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1645:
	/* 0x1645: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_164a:
	/* 0x164a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_164f:
	/* 0x164f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1654:
	/* 0x1654: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1656:
	/* 0x1656: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_165b:
	/* 0x165b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1660:
	/* 0x1660: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1663:
	/* 0x1663: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1668:
	/* 0x1668: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_166a:
	/* 0x166a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_166d:
	/* 0x166d: and    r12d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1674:
	/* 0x1674: add    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1677:
	/* 0x1677: lea    rdx,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_167b:
	/* 0x167b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1680:
	/* 0x1680: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1685:
	/* 0x1685: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_168a:
	/* 0x168a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_168c:
	/* 0x168c: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1690:
	/* 0x1690: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1694:
	/* 0x1694: add    rbx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1698:
	/* 0x1698: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_169d:
	/* 0x169d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16a2:
	/* 0x16a2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16a7:
	/* 0x16a7: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_16aa:
	/* 0x16aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ac:
	/* 0x16ac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16b1:
	/* 0x16b1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16b6:
	/* 0x16b6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_16ba:
	/* 0x16ba: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16bf:
	/* 0x16bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16c4:
	/* 0x16c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c6:
	/* 0x16c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16cb:
	/* 0x16cb: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16d0:
	/* 0x16d0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16d5:
	/* 0x16d5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16da:
	/* 0x16da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16dc:
	/* 0x16dc: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16e0:
	/* 0x16e0: mov    DWORD PTR [rsp+0xa4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_16e7:
	/* 0x16e7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16ec:
	/* 0x16ec: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16f1:
	/* 0x16f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16f6:
	/* 0x16f6: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_16f9:
	/* 0x16f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16fb:
	/* 0x16fb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1700:
	/* 0x1700: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1705:
	/* 0x1705: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1709:
	/* 0x1709: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_170e:
	/* 0x170e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1713:
	/* 0x1713: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1715:
	/* 0x1715: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_171a:
	/* 0x171a: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_171f:
	/* 0x171f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1724:
	/* 0x1724: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1729:
	/* 0x1729: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_172e:
	/* 0x172e: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1731:
	/* 0x1731: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1733:
	/* 0x1733: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_173c:
	/* 0x173c: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1741:
	/* 0x1741: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_174a:
	/* 0x174a: lea    rdx,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_174e:
	/* 0x174e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1753:
	/* 0x1753: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1758:
	/* 0x1758: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_175d:
	/* 0x175d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_175f:
	/* 0x175f: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1764:
	/* 0x1764: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1769:
	/* 0x1769: add    rbx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_176d:
	/* 0x176d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1772:
	/* 0x1772: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1777:
	/* 0x1777: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_177c:
	/* 0x177c: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_177f:
	/* 0x177f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1781:
	/* 0x1781: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1785:
	/* 0x1785: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_178a:
	/* 0x178a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_178f:
	/* 0x178f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1794:
	/* 0x1794: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1799:
	/* 0x1799: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_179e:
	/* 0x179e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17a0:
	/* 0x17a0: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17a5:
	/* 0x17a5: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_17a8:
	/* 0x17a8: js     17ce <trace_security_file_open+0x17ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_17ce;
	}
x86_l_17aa:
	/* 0x17aa: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17af:
	/* 0x17af: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17b4:
	/* 0x17b4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17b9:
	/* 0x17b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17be:
	/* 0x17be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17c0:
	/* 0x17c0: imul   rax,rbx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RBX, X86_WIDTH_64, 1000000000ULL);
x86_l_17c7:
	/* 0x17c7: add    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_17cc:
	/* 0x17cc: jmp    17d0 <trace_security_file_open+0x17d0> */
	goto x86_l_17d0;
x86_l_17ce:
	/* 0x17ce: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17d0:
	/* 0x17d0: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17d5:
	/* 0x17d5: mov    BYTE PTR [rsp+0xb4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_17dd:
	/* 0x17dd: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_17e2:
	/* 0x17e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17e4:
	/* 0x17e4: mov    ecx,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 175ULL);
x86_l_17e9:
	/* 0x17e9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_17ec:
	/* 0x17ec: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_17ee:
	/* 0x17ee: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_17f1:
	/* 0x17f1: mov    eax,DWORD PTR [r14+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_17f5:
	/* 0x17f5: cmp    eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_17fa:
	/* 0x17fa: jle    183a <trace_security_file_open+0x183a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_183a;
	}
x86_l_17fc:
	/* 0x17fc: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_1801:
	/* 0x1801: je     1815 <trace_security_file_open+0x1815> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1815;
	}
x86_l_1803:
	/* 0x1803: cmp    eax,0x142 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 322ULL);
x86_l_1808:
	/* 0x1808: je     1815 <trace_security_file_open+0x1815> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1815;
	}
x86_l_180a:
	/* 0x180a: cmp    eax,0x1b5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 437ULL);
x86_l_180f:
	/* 0x180f: jne    1899 <trace_security_file_open+0x1899> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1899;
	}
x86_l_1815:
	/* 0x1815: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_181c:
	/* 0x181c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1821:
	/* 0x1821: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1826:
	/* 0x1826: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_182b:
	/* 0x182b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_182d:
	/* 0x182d: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_1832:
	/* 0x1832: jne    1869 <trace_security_file_open+0x1869> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1869;
	}
x86_l_1834:
	/* 0x1834: mov    rax,QWORD PTR [rbx+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1838:
	/* 0x1838: jmp    1891 <trace_security_file_open+0x1891> */
	goto x86_l_1891;
x86_l_183a:
	/* 0x183a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_183d:
	/* 0x183d: je     1844 <trace_security_file_open+0x1844> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1844;
	}
x86_l_183f:
	/* 0x183f: cmp    eax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 59ULL);
x86_l_1842:
	/* 0x1842: jne    1899 <trace_security_file_open+0x1899> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1899;
	}
x86_l_1844:
	/* 0x1844: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_184b:
	/* 0x184b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1850:
	/* 0x1850: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1855:
	/* 0x1855: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_185a:
	/* 0x185a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_185c:
	/* 0x185c: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_1861:
	/* 0x1861: jne    1874 <trace_security_file_open+0x1874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1874;
	}
x86_l_1863:
	/* 0x1863: mov    rax,QWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1867:
	/* 0x1867: jmp    1891 <trace_security_file_open+0x1891> */
	goto x86_l_1891;
x86_l_1869:
	/* 0x1869: add    rbx,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_186d:
	/* 0x186d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1872:
	/* 0x1872: jmp    187d <trace_security_file_open+0x187d> */
	goto x86_l_187d;
x86_l_1874:
	/* 0x1874: add    rbx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_1878:
	/* 0x1878: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_187d:
	/* 0x187d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1882:
	/* 0x1882: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1887:
	/* 0x1887: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_188a:
	/* 0x188a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_188c:
	/* 0x188c: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1891:
	/* 0x1891: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1899:
	/* 0x1899: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_18a1:
	/* 0x18a1: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_18a7:
	/* 0x18a7: ja     1922 <trace_security_file_open+0x1922> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1922;
	}
x86_l_18a9:
	/* 0x18a9: mov    BYTE PTR [r14+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_18b2:
	/* 0x18b2: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_18ba:
	/* 0x18ba: mov    WORD PTR [r14+0x7d8c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_18c2:
	/* 0x18c2: cmp    eax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27899ULL);
x86_l_18c7:
	/* 0x18c7: ja     1922 <trace_security_file_open+0x1922> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1922;
	}
x86_l_18c9:
	/* 0x18c9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_18ce:
	/* 0x18ce: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_18d6:
	/* 0x18d6: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_18da:
	/* 0x18da: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_18e1:
	/* 0x18e1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_18e6:
	/* 0x18e6: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_18e9:
	/* 0x18e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18eb:
	/* 0x18eb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18ed:
	/* 0x18ed: jle    1922 <trace_security_file_open+0x1922> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1922;
	}
x86_l_18ef:
	/* 0x18ef: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_18f7:
	/* 0x18f7: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_18fe:
	/* 0x18fe: ja     1922 <trace_security_file_open+0x1922> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1922;
	}
x86_l_1900:
	/* 0x1900: mov    DWORD PTR [rcx+r14*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_1908:
	/* 0x1908: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1910:
	/* 0x1910: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1913:
	/* 0x1913: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_191b:
	/* 0x191b: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1922:
	/* 0x1922: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_192a:
	/* 0x192a: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1931:
	/* 0x1931: ja     1977 <trace_security_file_open+0x1977> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1977;
	}
x86_l_1933:
	/* 0x1933: mov    BYTE PTR [r14+rbx*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519553ULL);
x86_l_193c:
	/* 0x193c: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_1942:
	/* 0x1942: ja     1977 <trace_security_file_open+0x1977> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1977;
	}
x86_l_1944:
	/* 0x1944: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1948:
	/* 0x1948: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_194f:
	/* 0x194f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1954:
	/* 0x1954: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1959:
	/* 0x1959: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_195e:
	/* 0x195e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1960:
	/* 0x1960: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1963:
	/* 0x1963: js     1977 <trace_security_file_open+0x1977> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1977;
	}
x86_l_1965:
	/* 0x1965: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1968:
	/* 0x1968: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1970:
	/* 0x1970: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1977:
	/* 0x1977: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_197f:
	/* 0x197f: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1986:
	/* 0x1986: ja     19cf <trace_security_file_open+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_19cf;
	}
x86_l_1988:
	/* 0x1988: mov    BYTE PTR [r14+rbx*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519554ULL);
x86_l_1991:
	/* 0x1991: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_1997:
	/* 0x1997: ja     19cf <trace_security_file_open+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_19cf;
	}
x86_l_1999:
	/* 0x1999: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_199d:
	/* 0x199d: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_19a4:
	/* 0x19a4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19a9:
	/* 0x19a9: lea    rdx,[rsp+0xa4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_19b1:
	/* 0x19b1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19b6:
	/* 0x19b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b8:
	/* 0x19b8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19bb:
	/* 0x19bb: js     19cf <trace_security_file_open+0x19cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_19cf;
	}
x86_l_19bd:
	/* 0x19bd: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_19c0:
	/* 0x19c0: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_19c8:
	/* 0x19c8: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_19cf:
	/* 0x19cf: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_19d7:
	/* 0x19d7: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_19de:
	/* 0x19de: ja     1a24 <trace_security_file_open+0x1a24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a24;
	}
x86_l_19e0:
	/* 0x19e0: mov    BYTE PTR [r14+rbx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519555ULL);
x86_l_19e9:
	/* 0x19e9: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_19ef:
	/* 0x19ef: ja     1a24 <trace_security_file_open+0x1a24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a24;
	}
x86_l_19f1:
	/* 0x19f1: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_19f5:
	/* 0x19f5: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_19fc:
	/* 0x19fc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a01:
	/* 0x1a01: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a06:
	/* 0x1a06: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a0b:
	/* 0x1a0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a0d:
	/* 0x1a0d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a10:
	/* 0x1a10: js     1a24 <trace_security_file_open+0x1a24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a24;
	}
x86_l_1a12:
	/* 0x1a12: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1a15:
	/* 0x1a15: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1a1d:
	/* 0x1a1d: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1a24:
	/* 0x1a24: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1a2c:
	/* 0x1a2c: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1a33:
	/* 0x1a33: ja     1b20 <trace_security_file_open+0x1b20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b20;
	}
x86_l_1a39:
	/* 0x1a39: mov    BYTE PTR [r14+rbx*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519556ULL);
x86_l_1a42:
	/* 0x1a42: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1a48:
	/* 0x1a48: ja     1a8c <trace_security_file_open+0x1a8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a8c;
	}
x86_l_1a4a:
	/* 0x1a4a: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1a4e:
	/* 0x1a4e: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1a55:
	/* 0x1a55: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a5a:
	/* 0x1a5a: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a5f:
	/* 0x1a5f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a64:
	/* 0x1a64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a66:
	/* 0x1a66: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a69:
	/* 0x1a69: js     1a8c <trace_security_file_open+0x1a8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a8c;
	}
x86_l_1a6b:
	/* 0x1a6b: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1a6e:
	/* 0x1a6e: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1a76:
	/* 0x1a76: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1a7d:
	/* 0x1a7d: movzx  eax,bx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1a80:
	/* 0x1a80: cmp    eax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31999ULL);
x86_l_1a85:
	/* 0x1a85: jbe    1aa2 <trace_security_file_open+0x1aa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1aa2;
	}
x86_l_1a87:
	/* 0x1a87: jmp    1b20 <trace_security_file_open+0x1b20> */
	goto x86_l_1b20;
x86_l_1a8c:
	/* 0x1a8c: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1a94:
	/* 0x1a94: movzx  eax,bx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1a97:
	/* 0x1a97: cmp    eax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31999ULL);
x86_l_1a9c:
	/* 0x1a9c: ja     1b20 <trace_security_file_open+0x1b20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b20;
	}
x86_l_1aa2:
	/* 0x1aa2: mov    BYTE PTR [r14+rax*1+0x89],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519557ULL);
x86_l_1aab:
	/* 0x1aab: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1ab3:
	/* 0x1ab3: mov    WORD PTR [r14+0x7d96],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32150ULL);
x86_l_1abb:
	/* 0x1abb: cmp    eax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27899ULL);
x86_l_1ac0:
	/* 0x1ac0: ja     1b20 <trace_security_file_open+0x1b20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b20;
	}
x86_l_1ac2:
	/* 0x1ac2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1ac7:
	/* 0x1ac7: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1acf:
	/* 0x1acf: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1ad3:
	/* 0x1ad3: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1ada:
	/* 0x1ada: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1adf:
	/* 0x1adf: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1ae7:
	/* 0x1ae7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ae9:
	/* 0x1ae9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1aeb:
	/* 0x1aeb: jle    1b20 <trace_security_file_open+0x1b20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1b20;
	}
x86_l_1aed:
	/* 0x1aed: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1af5:
	/* 0x1af5: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1afc:
	/* 0x1afc: ja     1b20 <trace_security_file_open+0x1b20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b20;
	}
x86_l_1afe:
	/* 0x1afe: mov    DWORD PTR [rcx+r14*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_1b06:
	/* 0x1b06: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1b0e:
	/* 0x1b0e: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1b11:
	/* 0x1b11: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1b19:
	/* 0x1b19: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1b20:
	/* 0x1b20: lea    r12,[r14+0x7d8c] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_1b27:
	/* 0x1b27: mov    r13,QWORD PTR [r14+0x7de8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_1b2e:
	/* 0x1b2e: mov    r15,QWORD PTR [r14+0x7df8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_1b35:
	/* 0x1b35: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1b38:
	/* 0x1b38: je     1c4e <trace_security_file_open+0x1c4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7246ULL;
	}
x86_l_1b3e:
	/* 0x1b3e: or     r13,QWORD PTR [r14+0x7df0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 32240ULL);
x86_l_1b45:
	/* 0x1b45: mov    ebp,DWORD PTR [r14+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1b49:
	/* 0x1b49: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_1b4e:
	/* 0x1b4e: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b53:
	/* 0x1b53: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1b5b:
	/* 0x1b5b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b60:
	/* 0x1b60: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_bufs)));
x86_l_1b67:
	/* 0x1b67: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b6c:
	/* 0x1b6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b6e:
	/* 0x1b6e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b71:
	/* 0x1b71: je     1dab <trace_security_file_open+0x1dab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7595ULL;
	}
x86_l_1b77:
	/* 0x1b77: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1b7a:
	/* 0x1b7a: mov    DWORD PTR [rsp+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b7e:
	/* 0x1b7e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b80:
	/* 0x1b80: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1b85:
	/* 0x1b85: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1b88:
	/* 0x1b88: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b8a:
	/* 0x1b8a: call   1b8f <trace_security_file_open+0x1b8f> */
	X86_SIM_L_EXEC_CALL_MEMSET(256ULL);
x86_l_1b8f:
	/* 0x1b8f: movzx  eax,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b94:
	/* 0x1b94: cmp    rax,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31995ULL);
x86_l_1b9a:
	/* 0x1b9a: ja     1dad <trace_security_file_open+0x1dad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7597ULL;
	}
x86_l_1ba0:
	/* 0x1ba0: mov    esi,DWORD PTR [rax+r14*1+0x8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_1ba8:
	/* 0x1ba8: cmp    esi,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_1bae:
	/* 0x1bae: ja     1dab <trace_security_file_open+0x1dab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7595ULL;
	}
x86_l_1bb4:
	/* 0x1bb4: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1bb7:
	/* 0x1bb7: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1bba:
	/* 0x1bba: lea    ecx,[rsi+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1bbd:
	/* 0x1bbd: cmp    ecx,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_1bc3:
	/* 0x1bc3: ja     1dab <trace_security_file_open+0x1dab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7595ULL;
	}
x86_l_1bc9:
	/* 0x1bc9: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1bcd:
	/* 0x1bcd: add    rdx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1bd4:
	/* 0x1bd4: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1bd9:
	/* 0x1bd9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1bdc:
	/* 0x1bdc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bde:
	/* 0x1bde: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1be0:
	/* 0x1be0: je     1dab <trace_security_file_open+0x1dab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7595ULL;
	}
x86_l_1be6:
	/* 0x1be6: mov    rbp,QWORD PTR [r14+0x7e10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_1bed:
	/* 0x1bed: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1bf2:
	/* 0x1bf2: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bf7:
	/* 0x1bf7: mov    WORD PTR [rsp+0x32],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 214748364800ULL);
x86_l_1bfe:
	/* 0x1bfe: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c02:
	/* 0x1c02: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1c06:
	/* 0x1c06: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c0b:
	/* 0x1c0b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_exact_version)));
	return 7186ULL;
}

static __noinline __u64 tracee_trace_security_file_open_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7186ULL: goto x86_l_1c12;
	case 7191ULL: goto x86_l_1c17;
	case 7193ULL: goto x86_l_1c19;
	case 7200ULL: goto x86_l_1c20;
	case 7203ULL: goto x86_l_1c23;
	case 7209ULL: goto x86_l_1c29;
	case 7214ULL: goto x86_l_1c2e;
	case 7217ULL: goto x86_l_1c31;
	case 7220ULL: goto x86_l_1c34;
	case 7222ULL: goto x86_l_1c36;
	case 7225ULL: goto x86_l_1c39;
	case 7231ULL: goto x86_l_1c3f;
	case 7234ULL: goto x86_l_1c42;
	case 7238ULL: goto x86_l_1c46;
	case 7241ULL: goto x86_l_1c49;
	case 7246ULL: goto x86_l_1c4e;
	case 7249ULL: goto x86_l_1c51;
	case 7251ULL: goto x86_l_1c53;
	case 7259ULL: goto x86_l_1c5b;
	case 7265ULL: goto x86_l_1c61;
	case 7272ULL: goto x86_l_1c68;
	case 7279ULL: goto x86_l_1c6f;
	case 7282ULL: goto x86_l_1c72;
	case 7286ULL: goto x86_l_1c76;
	case 7291ULL: goto x86_l_1c7b;
	case 7296ULL: goto x86_l_1c80;
	case 7298ULL: goto x86_l_1c82;
	case 7300ULL: goto x86_l_1c84;
	case 7302ULL: goto x86_l_1c86;
	case 7305ULL: goto x86_l_1c89;
	case 7311ULL: goto x86_l_1c8f;
	case 7319ULL: goto x86_l_1c97;
	case 7327ULL: goto x86_l_1c9f;
	case 7330ULL: goto x86_l_1ca2;
	case 7338ULL: goto x86_l_1caa;
	case 7343ULL: goto x86_l_1caf;
	case 7350ULL: goto x86_l_1cb6;
	case 7355ULL: goto x86_l_1cbb;
	case 7357ULL: goto x86_l_1cbd;
	case 7360ULL: goto x86_l_1cc0;
	case 7366ULL: goto x86_l_1cc6;
	case 7371ULL: goto x86_l_1ccb;
	case 7378ULL: goto x86_l_1cd2;
	case 7384ULL: goto x86_l_1cd8;
	case 7387ULL: goto x86_l_1cdb;
	case 7395ULL: goto x86_l_1ce3;
	case 7401ULL: goto x86_l_1ce9;
	case 7406ULL: goto x86_l_1cee;
	case 7409ULL: goto x86_l_1cf1;
	case 7412ULL: goto x86_l_1cf4;
	case 7415ULL: goto x86_l_1cf7;
	case 7421ULL: goto x86_l_1cfd;
	case 7427ULL: goto x86_l_1d03;
	case 7435ULL: goto x86_l_1d0b;
	case 7439ULL: goto x86_l_1d0f;
	case 7443ULL: goto x86_l_1d13;
	case 7450ULL: goto x86_l_1d1a;
	case 7455ULL: goto x86_l_1d1f;
	case 7457ULL: goto x86_l_1d21;
	case 7459ULL: goto x86_l_1d23;
	case 7465ULL: goto x86_l_1d29;
	case 7468ULL: goto x86_l_1d2c;
	case 7476ULL: goto x86_l_1d34;
	case 7478ULL: goto x86_l_1d36;
	case 7485ULL: goto x86_l_1d3d;
	case 7493ULL: goto x86_l_1d45;
	case 7498ULL: goto x86_l_1d4a;
	case 7503ULL: goto x86_l_1d4f;
	case 7510ULL: goto x86_l_1d56;
	case 7514ULL: goto x86_l_1d5a;
	case 7518ULL: goto x86_l_1d5e;
	case 7523ULL: goto x86_l_1d63;
	case 7530ULL: goto x86_l_1d6a;
	case 7535ULL: goto x86_l_1d6f;
	case 7537ULL: goto x86_l_1d71;
	case 7544ULL: goto x86_l_1d78;
	case 7547ULL: goto x86_l_1d7b;
	case 7553ULL: goto x86_l_1d81;
	case 7558ULL: goto x86_l_1d86;
	case 7561ULL: goto x86_l_1d89;
	case 7569ULL: goto x86_l_1d91;
	case 7571ULL: goto x86_l_1d93;
	case 7574ULL: goto x86_l_1d96;
	case 7580ULL: goto x86_l_1d9c;
	case 7583ULL: goto x86_l_1d9f;
	case 7587ULL: goto x86_l_1da3;
	case 7590ULL: goto x86_l_1da6;
	case 7595ULL: goto x86_l_1dab;
	case 7597ULL: goto x86_l_1dad;
	case 7605ULL: goto x86_l_1db5;
	case 7613ULL: goto x86_l_1dbd;
	case 7620ULL: goto x86_l_1dc4;
	case 7626ULL: goto x86_l_1dca;
	case 7629ULL: goto x86_l_1dcd;
	case 7633ULL: goto x86_l_1dd1;
	case 7637ULL: goto x86_l_1dd5;
	case 7641ULL: goto x86_l_1dd9;
	case 7645ULL: goto x86_l_1ddd;
	case 7650ULL: goto x86_l_1de2;
	case 7653ULL: goto x86_l_1de5;
	case 7656ULL: goto x86_l_1de8;
	case 7659ULL: goto x86_l_1deb;
	case 7663ULL: goto x86_l_1def;
	case 7667ULL: goto x86_l_1df3;
	case 7671ULL: goto x86_l_1df7;
	case 7675ULL: goto x86_l_1dfb;
	case 7680ULL: goto x86_l_1e00;
	case 7683ULL: goto x86_l_1e03;
	case 7686ULL: goto x86_l_1e06;
	case 7689ULL: goto x86_l_1e09;
	case 7694ULL: goto x86_l_1e0e;
	case 7696ULL: goto x86_l_1e10;
	case 7701ULL: goto x86_l_1e15;
	case 7708ULL: goto x86_l_1e1c;
	case 7713ULL: goto x86_l_1e21;
	case 7721ULL: goto x86_l_1e29;
	case 7723ULL: goto x86_l_1e2b;
	case 7725ULL: goto x86_l_1e2d;
	case 7727ULL: goto x86_l_1e2f;
	case 7731ULL: goto x86_l_1e33;
	case 7739ULL: goto x86_l_1e3b;
	case 7744ULL: goto x86_l_1e40;
	case 7749ULL: goto x86_l_1e45;
	case 7752ULL: goto x86_l_1e48;
	case 7758ULL: goto x86_l_1e4e;
	case 7762ULL: goto x86_l_1e52;
	case 7767ULL: goto x86_l_1e57;
	case 7774ULL: goto x86_l_1e5e;
	case 7779ULL: goto x86_l_1e63;
	case 7787ULL: goto x86_l_1e6b;
	case 7790ULL: goto x86_l_1e6e;
	case 7792ULL: goto x86_l_1e70;
	case 7794ULL: goto x86_l_1e72;
	case 7801ULL: goto x86_l_1e79;
	case 7803ULL: goto x86_l_1e7b;
	case 7804ULL: goto x86_l_1e7c;
	case 7809ULL: goto x86_l_1e81;
	case 7816ULL: goto x86_l_1e88;
	case 7821ULL: goto x86_l_1e8d;
	case 7826ULL: goto x86_l_1e92;
	case 7831ULL: goto x86_l_1e97;
	case 7837ULL: goto x86_l_1e9d;
	case 7842ULL: goto x86_l_1ea2;
	case 7847ULL: goto x86_l_1ea7;
	case 7851ULL: goto x86_l_1eab;
	case 7856ULL: goto x86_l_1eb0;
	case 7861ULL: goto x86_l_1eb5;
	case 7863ULL: goto x86_l_1eb7;
	case 7868ULL: goto x86_l_1ebc;
	case 7873ULL: goto x86_l_1ec1;
	case 7878ULL: goto x86_l_1ec6;
	case 7883ULL: goto x86_l_1ecb;
	case 7885ULL: goto x86_l_1ecd;
	case 7890ULL: goto x86_l_1ed2;
	case 7895ULL: goto x86_l_1ed7;
	case 7900ULL: goto x86_l_1edc;
	case 7905ULL: goto x86_l_1ee1;
	case 7907ULL: goto x86_l_1ee3;
	case 7912ULL: goto x86_l_1ee8;
	case 7916ULL: goto x86_l_1eec;
	case 7921ULL: goto x86_l_1ef1;
	case 7926ULL: goto x86_l_1ef6;
	case 7931ULL: goto x86_l_1efb;
	case 7934ULL: goto x86_l_1efe;
	case 7936ULL: goto x86_l_1f00;
	case 7941ULL: goto x86_l_1f05;
	case 7946ULL: goto x86_l_1f0a;
	case 7950ULL: goto x86_l_1f0e;
	case 7955ULL: goto x86_l_1f13;
	case 7960ULL: goto x86_l_1f18;
	case 7965ULL: goto x86_l_1f1d;
	case 7967ULL: goto x86_l_1f1f;
	case 7972ULL: goto x86_l_1f24;
	case 7975ULL: goto x86_l_1f27;
	case 7977ULL: goto x86_l_1f29;
	case 7982ULL: goto x86_l_1f2e;
	case 7985ULL: goto x86_l_1f31;
	case 7987ULL: goto x86_l_1f33;
	case 7991ULL: goto x86_l_1f37;
	case 7996ULL: goto x86_l_1f3c;
	case 8001ULL: goto x86_l_1f41;
	case 8006ULL: goto x86_l_1f46;
	case 8008ULL: goto x86_l_1f48;
	case 8012ULL: goto x86_l_1f4c;
	case 8014ULL: goto x86_l_1f4e;
	case 8020ULL: goto x86_l_1f54;
	case 8025ULL: goto x86_l_1f59;
	case 8028ULL: goto x86_l_1f5c;
	case 8030ULL: goto x86_l_1f5e;
	case 8036ULL: goto x86_l_1f64;
	case 8039ULL: goto x86_l_1f67;
	case 8042ULL: goto x86_l_1f6a;
	case 8047ULL: goto x86_l_1f6f;
	case 8052ULL: goto x86_l_1f74;
	case 8059ULL: goto x86_l_1f7b;
	case 8064ULL: goto x86_l_1f80;
	case 8067ULL: goto x86_l_1f83;
	case 8073ULL: goto x86_l_1f89;
	case 8078ULL: goto x86_l_1f8e;
	case 8083ULL: goto x86_l_1f93;
	case 8089ULL: goto x86_l_1f99;
	case 8094ULL: goto x86_l_1f9e;
	case 8099ULL: goto x86_l_1fa3;
	case 8103ULL: goto x86_l_1fa7;
	case 8108ULL: goto x86_l_1fac;
	case 8113ULL: goto x86_l_1fb1;
	case 8115ULL: goto x86_l_1fb3;
	case 8120ULL: goto x86_l_1fb8;
	case 8125ULL: goto x86_l_1fbd;
	case 8130ULL: goto x86_l_1fc2;
	case 8135ULL: goto x86_l_1fc7;
	case 8137ULL: goto x86_l_1fc9;
	case 8142ULL: goto x86_l_1fce;
	case 8147ULL: goto x86_l_1fd3;
	case 8152ULL: goto x86_l_1fd8;
	case 8157ULL: goto x86_l_1fdd;
	case 8159ULL: goto x86_l_1fdf;
	case 8164ULL: goto x86_l_1fe4;
	case 8168ULL: goto x86_l_1fe8;
	case 8173ULL: goto x86_l_1fed;
	case 8175ULL: goto x86_l_1fef;
	case 8178ULL: goto x86_l_1ff2;
	case 8186ULL: goto x86_l_1ffa;
	case 8194ULL: goto x86_l_2002;
	case 8202ULL: goto x86_l_200a;
	case 8205ULL: goto x86_l_200d;
	case 8208ULL: goto x86_l_2010;
	case 8213ULL: goto x86_l_2015;
	case 8216ULL: goto x86_l_2018;
	case 8221ULL: goto x86_l_201d;
	case 8224ULL: goto x86_l_2020;
	case 8227ULL: goto x86_l_2023;
	case 8230ULL: goto x86_l_2026;
	case 8234ULL: goto x86_l_202a;
	case 8236ULL: goto x86_l_202c;
	case 8238ULL: goto x86_l_202e;
	case 8240ULL: goto x86_l_2030;
	case 8242ULL: goto x86_l_2032;
	case 8249ULL: goto x86_l_2039;
	case 8256ULL: goto x86_l_2040;
	case 8259ULL: goto x86_l_2043;
	case 8262ULL: goto x86_l_2046;
	case 8265ULL: goto x86_l_2049;
	case 8270ULL: goto x86_l_204e;
	case 8275ULL: goto x86_l_2053;
	case 8278ULL: goto x86_l_2056;
	case 8281ULL: goto x86_l_2059;
	case 8288ULL: goto x86_l_2060;
	case 8292ULL: goto x86_l_2064;
	case 8295ULL: goto x86_l_2067;
	case 8301ULL: goto x86_l_206d;
	case 8305ULL: goto x86_l_2071;
	case 8311ULL: goto x86_l_2077;
	case 8319ULL: goto x86_l_207f;
	case 8322ULL: goto x86_l_2082;
	case 8325ULL: goto x86_l_2085;
	case 8333ULL: goto x86_l_208d;
	case 8338ULL: goto x86_l_2092;
	case 8345ULL: goto x86_l_2099;
	case 8350ULL: goto x86_l_209e;
	case 8352ULL: goto x86_l_20a0;
	case 8355ULL: goto x86_l_20a3;
	case 8363ULL: goto x86_l_20ab;
	case 8365ULL: goto x86_l_20ad;
	case 8370ULL: goto x86_l_20b2;
	case 8377ULL: goto x86_l_20b9;
	case 8379ULL: goto x86_l_20bb;
	case 8381ULL: goto x86_l_20bd;
	case 8389ULL: goto x86_l_20c5;
	case 8394ULL: goto x86_l_20ca;
	case 8397ULL: goto x86_l_20cd;
	case 8405ULL: goto x86_l_20d5;
	case 8411ULL: goto x86_l_20db;
	case 8419ULL: goto x86_l_20e3;
	case 8421ULL: goto x86_l_20e5;
	case 8423ULL: goto x86_l_20e7;
	case 8429ULL: goto x86_l_20ed;
	case 8432ULL: goto x86_l_20f0;
	case 8437ULL: goto x86_l_20f5;
	case 8443ULL: goto x86_l_20fb;
	case 8445ULL: goto x86_l_20fd;
	case 8447ULL: goto x86_l_20ff;
	case 8452ULL: goto x86_l_2104;
	case 8454ULL: goto x86_l_2106;
	case 8456ULL: goto x86_l_2108;
	case 8462ULL: goto x86_l_210e;
	case 8465ULL: goto x86_l_2111;
	case 8468ULL: goto x86_l_2114;
	case 8474ULL: goto x86_l_211a;
	case 8480ULL: goto x86_l_2120;
	case 8482ULL: goto x86_l_2122;
	case 8488ULL: goto x86_l_2128;
	case 8494ULL: goto x86_l_212e;
	case 8497ULL: goto x86_l_2131;
	case 8499ULL: goto x86_l_2133;
	case 8501ULL: goto x86_l_2135;
	case 8503ULL: goto x86_l_2137;
	case 8505ULL: goto x86_l_2139;
	case 8507ULL: goto x86_l_213b;
	case 8513ULL: goto x86_l_2141;
	case 8519ULL: goto x86_l_2147;
	case 8521ULL: goto x86_l_2149;
	case 8530ULL: goto x86_l_2152;
	case 8535ULL: goto x86_l_2157;
	case 8538ULL: goto x86_l_215a;
	case 8540ULL: goto x86_l_215c;
	case 8543ULL: goto x86_l_215f;
	case 8545ULL: goto x86_l_2161;
	case 8550ULL: goto x86_l_2166;
	case 8555ULL: goto x86_l_216b;
	case 8561ULL: goto x86_l_2171;
	case 8564ULL: goto x86_l_2174;
	case 8569ULL: goto x86_l_2179;
	case 8571ULL: goto x86_l_217b;
	case 8574ULL: goto x86_l_217e;
	case 8580ULL: goto x86_l_2184;
	case 8585ULL: goto x86_l_2189;
	case 8591ULL: goto x86_l_218f;
	case 8596ULL: goto x86_l_2194;
	case 8599ULL: goto x86_l_2197;
	case 8604ULL: goto x86_l_219c;
	case 8609ULL: goto x86_l_21a1;
	case 8612ULL: goto x86_l_21a4;
	case 8617ULL: goto x86_l_21a9;
	case 8622ULL: goto x86_l_21ae;
	case 8627ULL: goto x86_l_21b3;
	case 8630ULL: goto x86_l_21b6;
	case 8632ULL: goto x86_l_21b8;
	case 8637ULL: goto x86_l_21bd;
	case 8642ULL: goto x86_l_21c2;
	case 8646ULL: goto x86_l_21c6;
	case 8651ULL: goto x86_l_21cb;
	case 8656ULL: goto x86_l_21d0;
	case 8661ULL: goto x86_l_21d5;
	case 8663ULL: goto x86_l_21d7;
	case 8668ULL: goto x86_l_21dc;
	case 8671ULL: goto x86_l_21df;
	case 8673ULL: goto x86_l_21e1;
	case 8678ULL: goto x86_l_21e6;
	case 8681ULL: goto x86_l_21e9;
	case 8683ULL: goto x86_l_21eb;
	case 8687ULL: goto x86_l_21ef;
	case 8692ULL: goto x86_l_21f4;
	case 8697ULL: goto x86_l_21f9;
	case 8702ULL: goto x86_l_21fe;
	case 8704ULL: goto x86_l_2200;
	case 8708ULL: goto x86_l_2204;
	case 8710ULL: goto x86_l_2206;
	case 8716ULL: goto x86_l_220c;
	case 8721ULL: goto x86_l_2211;
	case 8724ULL: goto x86_l_2214;
	case 8726ULL: goto x86_l_2216;
	case 8732ULL: goto x86_l_221c;
	case 8737ULL: goto x86_l_2221;
	case 8743ULL: goto x86_l_2227;
	case 8746ULL: goto x86_l_222a;
	case 8751ULL: goto x86_l_222f;
	case 8753ULL: goto x86_l_2231;
	case 8756ULL: goto x86_l_2234;
	case 8762ULL: goto x86_l_223a;
	case 8767ULL: goto x86_l_223f;
	case 8773ULL: goto x86_l_2245;
	case 8778ULL: goto x86_l_224a;
	case 8781ULL: goto x86_l_224d;
	case 8786ULL: goto x86_l_2252;
	case 8791ULL: goto x86_l_2257;
	case 8794ULL: goto x86_l_225a;
	case 8796ULL: goto x86_l_225c;
	case 8799ULL: goto x86_l_225f;
	case 8805ULL: goto x86_l_2265;
	case 8810ULL: goto x86_l_226a;
	case 8815ULL: goto x86_l_226f;
	case 8821ULL: goto x86_l_2275;
	case 8826ULL: goto x86_l_227a;
	case 8831ULL: goto x86_l_227f;
	case 8835ULL: goto x86_l_2283;
	case 8840ULL: goto x86_l_2288;
	case 8845ULL: goto x86_l_228d;
	case 8847ULL: goto x86_l_228f;
	case 8852ULL: goto x86_l_2294;
	case 8857ULL: goto x86_l_2299;
	case 8862ULL: goto x86_l_229e;
	case 8867ULL: goto x86_l_22a3;
	case 8869ULL: goto x86_l_22a5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c12:
	/* 0x1c12: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c17:
	/* 0x1c17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c19:
	/* 0x1c19: mov    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1c20:
	/* 0x1c20: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c23:
	/* 0x1c23: je     202c <trace_security_file_open+0x202c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_202c;
	}
x86_l_1c29:
	/* 0x1c29: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1c2e:
	/* 0x1c2e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1c31:
	/* 0x1c31: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1c34:
	/* 0x1c34: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1c36:
	/* 0x1c36: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c39:
	/* 0x1c39: je     2030 <trace_security_file_open+0x2030> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2030;
	}
x86_l_1c3f:
	/* 0x1c3f: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c42:
	/* 0x1c42: mov    rdx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c46:
	/* 0x1c46: not    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1c49:
	/* 0x1c49: jmp    2039 <trace_security_file_open+0x2039> */
	goto x86_l_2039;
x86_l_1c4e:
	/* 0x1c4e: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1c51:
	/* 0x1c51: jne    1c61 <trace_security_file_open+0x1c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c61;
	}
x86_l_1c53:
	/* 0x1c53: cmp    QWORD PTR [r14+0x7df0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138469745623040ULL);
x86_l_1c5b:
	/* 0x1c5b: je     1e81 <trace_security_file_open+0x1e81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e81;
	}
x86_l_1c61:
	/* 0x1c61: lea    rbx,[r14+0x7df0] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_1c68:
	/* 0x1c68: mov    r15,QWORD PTR [r14+0x7df0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_1c6f:
	/* 0x1c6f: or     r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_OR);
x86_l_1c72:
	/* 0x1c72: mov    ebp,DWORD PTR [r14+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1c76:
	/* 0x1c76: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_1c7b:
	/* 0x1c7b: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c80:
	/* 0x1c80: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c82:
	/* 0x1c82: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c84:
	/* 0x1c84: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c86:
	/* 0x1c86: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_1c89:
	/* 0x1c89: je     206d <trace_security_file_open+0x206d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_206d;
	}
x86_l_1c8f:
	/* 0x1c8f: mov    QWORD PTR [rsp+0x98],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1c97:
	/* 0x1c97: mov    QWORD PTR [rsp+0x80],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1c9f:
	/* 0x1c9f: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_1ca2:
	/* 0x1ca2: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1caa:
	/* 0x1caa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1caf:
	/* 0x1caf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_lpm_bufs)));
x86_l_1cb6:
	/* 0x1cb6: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cbb:
	/* 0x1cbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cbd:
	/* 0x1cbd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cc0:
	/* 0x1cc0: je     1dab <trace_security_file_open+0x1dab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dab;
	}
x86_l_1cc6:
	/* 0x1cc6: movzx  ecx,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ccb:
	/* 0x1ccb: cmp    rcx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 31995ULL);
x86_l_1cd2:
	/* 0x1cd2: ja     1dab <trace_security_file_open+0x1dab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1dab;
	}
x86_l_1cd8:
	/* 0x1cd8: lea    edx,[rcx+0x5] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_1cdb:
	/* 0x1cdb: mov    ecx,DWORD PTR [rcx+r14*1+0x8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_1ce3:
	/* 0x1ce3: cmp    ecx,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_1ce9:
	/* 0x1ce9: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_1cee:
	/* 0x1cee: cmovb  esi,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1cf1:
	/* 0x1cf1: movzx  ecx,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1cf4:
	/* 0x1cf4: lea    edx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1cf7:
	/* 0x1cf7: cmp    edx,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 32000ULL);
x86_l_1cfd:
	/* 0x1cfd: ja     1dab <trace_security_file_open+0x1dab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1dab;
	}
x86_l_1d03:
	/* 0x1d03: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1d0b:
	/* 0x1d0b: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d0f:
	/* 0x1d0f: lea    rdx,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1d13:
	/* 0x1d13: add    rdx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1d1a:
	/* 0x1d1a: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1d1f:
	/* 0x1d1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d21:
	/* 0x1d21: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d23:
	/* 0x1d23: je     1dab <trace_security_file_open+0x1dab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dab;
	}
x86_l_1d29:
	/* 0x1d29: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1d2c:
	/* 0x1d2c: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1d34:
	/* 0x1d34: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d36:
	/* 0x1d36: mov    rax,QWORD PTR [r14+0x7e00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_1d3d:
	/* 0x1d3d: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1d45:
	/* 0x1d45: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1d4a:
	/* 0x1d4a: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d4f:
	/* 0x1d4f: mov    WORD PTR [rsp+0x32],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 214748364800ULL);
x86_l_1d56:
	/* 0x1d56: mov    DWORD PTR [rsp+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d5a:
	/* 0x1d5a: mov    DWORD PTR [rsp+0x34],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1d5e:
	/* 0x1d5e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d63:
	/* 0x1d63: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_prefix_version)));
x86_l_1d6a:
	/* 0x1d6a: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d6f:
	/* 0x1d6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d71:
	/* 0x1d71: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1d78:
	/* 0x1d78: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d7b:
	/* 0x1d7b: je     1fed <trace_security_file_open+0x1fed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fed;
	}
x86_l_1d81:
	/* 0x1d81: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1d86:
	/* 0x1d86: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1d89:
	/* 0x1d89: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1d91:
	/* 0x1d91: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1d93:
	/* 0x1d93: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d96:
	/* 0x1d96: je     1fed <trace_security_file_open+0x1fed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fed;
	}
x86_l_1d9c:
	/* 0x1d9c: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d9f:
	/* 0x1d9f: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1da3:
	/* 0x1da3: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1da6:
	/* 0x1da6: jmp    1fef <trace_security_file_open+0x1fef> */
	goto x86_l_1fef;
x86_l_1dab:
	/* 0x1dab: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dad:
	/* 0x1dad: mov    r10,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1db5:
	/* 0x1db5: mov    r11,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1dbd:
	/* 0x1dbd: and    QWORD PTR [r14+0x80],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_1dc4:
	/* 0x1dc4: je     1e70 <trace_security_file_open+0x1e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e70;
	}
x86_l_1dca:
	/* 0x1dca: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_1dcd:
	/* 0x1dcd: add    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1dd1:
	/* 0x1dd1: mov    rdx,QWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dd5:
	/* 0x1dd5: mov    r8,QWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1dd9:
	/* 0x1dd9: mov    r9d,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_1ddd:
	/* 0x1ddd: mov    ecx,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1de2:
	/* 0x1de2: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1de5:
	/* 0x1de5: mov    rsi,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R11, X86_WIDTH_64);
x86_l_1de8:
	/* 0x1de8: rep movs QWORD PTR es:[rdi],QWORD PTR ds:[rsi] */
	X86_SIM_L_EXEC_REP_MOVS(X86_WIDTH_64, 13ULL);
x86_l_1deb:
	/* 0x1deb: mov    QWORD PTR [r14+0x24],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1def:
	/* 0x1def: mov    QWORD PTR [r14+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1df3:
	/* 0x1df3: and    r9d,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_1df7:
	/* 0x1df7: or     DWORD PTR [r14+0x5c],r9d */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_R9, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 92ULL);
x86_l_1dfb:
	/* 0x1dfb: mov    ecx,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1e00:
	/* 0x1e00: mov    rdi,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R11, X86_WIDTH_64);
x86_l_1e03:
	/* 0x1e03: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1e06:
	/* 0x1e06: rep movs QWORD PTR es:[rdi],QWORD PTR ds:[rsi] */
	X86_SIM_L_EXEC_REP_MOVS(X86_WIDTH_64, 13ULL);
x86_l_1e09:
	/* 0x1e09: test   BYTE PTR [r10+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_1e0e:
	/* 0x1e0e: je     1e33 <trace_security_file_open+0x1e33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e33;
	}
x86_l_1e10:
	/* 0x1e10: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1e15:
	/* 0x1e15: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_1e1c:
	/* 0x1e1c: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1e21:
	/* 0x1e21: mov    rdi,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1e29:
	/* 0x1e29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e2b:
	/* 0x1e2b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e2d:
	/* 0x1e2d: js     1e33 <trace_security_file_open+0x1e33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1e33;
	}
x86_l_1e2f:
	/* 0x1e2f: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1e33:
	/* 0x1e33: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e3b:
	/* 0x1e3b: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_1e40:
	/* 0x1e40: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_1e45:
	/* 0x1e45: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_1e48:
	/* 0x1e48: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_1e4e:
	/* 0x1e4e: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1e52:
	/* 0x1e52: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1e57:
	/* 0x1e57: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_1e5e:
	/* 0x1e5e: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1e63:
	/* 0x1e63: mov    rdi,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1e6b:
	/* 0x1e6b: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_1e6e:
	/* 0x1e6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e70:
	/* 0x1e70: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e72:
	/* 0x1e72: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_1e79:
	/* 0x1e79: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1e7b:
	/* 0x1e7b: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1e7c:
	/* 0x1e7c: jmp    3608 <trace_security_file_open+0x3608> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1e81:
	/* 0x1e81: mov    rbp,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32496ULL);
x86_l_1e88:
	/* 0x1e88: jmp    1dad <trace_security_file_open+0x1dad> */
	goto x86_l_1dad;
x86_l_1e8d:
	/* 0x1e8d: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e92:
	/* 0x1e92: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1e97:
	/* 0x1e97: je     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5674ULL;
	}
x86_l_1e9d:
	/* 0x1e9d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ea2:
	/* 0x1ea2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ea7:
	/* 0x1ea7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1eab:
	/* 0x1eab: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1eb0:
	/* 0x1eb0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1eb5:
	/* 0x1eb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1eb7:
	/* 0x1eb7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ebc:
	/* 0x1ebc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ec1:
	/* 0x1ec1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ec6:
	/* 0x1ec6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ecb:
	/* 0x1ecb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ecd:
	/* 0x1ecd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ed2:
	/* 0x1ed2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ed7:
	/* 0x1ed7: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1edc:
	/* 0x1edc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ee1:
	/* 0x1ee1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ee3:
	/* 0x1ee3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ee8:
	/* 0x1ee8: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1eec:
	/* 0x1eec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ef1:
	/* 0x1ef1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ef6:
	/* 0x1ef6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1efb:
	/* 0x1efb: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_1efe:
	/* 0x1efe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f00:
	/* 0x1f00: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f05:
	/* 0x1f05: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f0a:
	/* 0x1f0a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1f0e:
	/* 0x1f0e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f13:
	/* 0x1f13: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f18:
	/* 0x1f18: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f1d:
	/* 0x1f1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f1f:
	/* 0x1f1f: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f24:
	/* 0x1f24: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f27:
	/* 0x1f27: je     1f80 <trace_security_file_open+0x1f80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f80;
	}
x86_l_1f29:
	/* 0x1f29: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f2e:
	/* 0x1f2e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1f31:
	/* 0x1f31: je     1f80 <trace_security_file_open+0x1f80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f80;
	}
x86_l_1f33:
	/* 0x1f33: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1f37:
	/* 0x1f37: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f3c:
	/* 0x1f3c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f41:
	/* 0x1f41: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1f46:
	/* 0x1f46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f48:
	/* 0x1f48: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1f4c:
	/* 0x1f4c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1f4e:
	/* 0x1f4e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1f54:
	/* 0x1f54: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f59:
	/* 0x1f59: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_1f5c:
	/* 0x1f5c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1f5e:
	/* 0x1f5e: jae    2166 <trace_security_file_open+0x2166> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2166;
	}
x86_l_1f64:
	/* 0x1f64: dec    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1f67:
	/* 0x1f67: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_1f6a:
	/* 0x1f6a: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1f6f:
	/* 0x1f6f: mov    BYTE PTR [rbp+rax*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_1f74:
	/* 0x1f74: mov    BYTE PTR [rbp+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_1f7b:
	/* 0x1f7b: jmp    166d <trace_security_file_open+0x166d> */
	return 5741ULL;
x86_l_1f80:
	/* 0x1f80: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f83:
	/* 0x1f83: jne    162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5674ULL;
	}
x86_l_1f89:
	/* 0x1f89: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f8e:
	/* 0x1f8e: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1f93:
	/* 0x1f93: je     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5674ULL;
	}
x86_l_1f99:
	/* 0x1f99: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f9e:
	/* 0x1f9e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fa3:
	/* 0x1fa3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1fa7:
	/* 0x1fa7: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fac:
	/* 0x1fac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fb1:
	/* 0x1fb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb3:
	/* 0x1fb3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fb8:
	/* 0x1fb8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fbd:
	/* 0x1fbd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fc2:
	/* 0x1fc2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fc7:
	/* 0x1fc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fc9:
	/* 0x1fc9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fce:
	/* 0x1fce: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fd3:
	/* 0x1fd3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fd8:
	/* 0x1fd8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fdd:
	/* 0x1fdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fdf:
	/* 0x1fdf: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fe4:
	/* 0x1fe4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1fe8:
	/* 0x1fe8: jmp    21a4 <trace_security_file_open+0x21a4> */
	goto x86_l_21a4;
x86_l_1fed:
	/* 0x1fed: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fef:
	/* 0x1fef: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1ff2:
	/* 0x1ff2: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1ffa:
	/* 0x1ffa: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2002:
	/* 0x2002: mov    r8,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_200a:
	/* 0x200a: and    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_AND);
x86_l_200d:
	/* 0x200d: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2010:
	/* 0x2010: andn   rax,r8,rcx */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_R8, X86_RCX, X86_WIDTH_64);
x86_l_2015:
	/* 0x2015: or     rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2018:
	/* 0x2018: andn   rax,rbp,r8 */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_RBP, X86_R8, X86_WIDTH_64);
x86_l_201d:
	/* 0x201d: or     rdi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2020:
	/* 0x2020: and    rbp,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R8, X86_WIDTH_64, X86_ALU_AND);
x86_l_2023:
	/* 0x2023: or     rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_2026:
	/* 0x2026: mov    ebp,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_202a:
	/* 0x202a: jmp    206d <trace_security_file_open+0x206d> */
	goto x86_l_206d;
x86_l_202c:
	/* 0x202c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_202e:
	/* 0x202e: jmp    2039 <trace_security_file_open+0x2039> */
	goto x86_l_2039;
x86_l_2030:
	/* 0x2030: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2032:
	/* 0x2032: mov    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2039:
	/* 0x2039: lea    rbx,[r14+0x7df0] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_2040:
	/* 0x2040: or     r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_2043:
	/* 0x2043: and    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_2046:
	/* 0x2046: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2049:
	/* 0x2049: andn   rsi,rbp,rcx */
	X86_SIM_L_EXEC_ANDN(X86_RSI, X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_204e:
	/* 0x204e: andn   rdi,rdx,rbp */
	X86_SIM_L_EXEC_ANDN(X86_RDI, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2053:
	/* 0x2053: and    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_2056:
	/* 0x2056: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_2059:
	/* 0x2059: mov    r13,QWORD PTR [r14+0x7de8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_2060:
	/* 0x2060: mov    ebp,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2064:
	/* 0x2064: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2067:
	/* 0x2067: jne    1c8f <trace_security_file_open+0x1c8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c8f;
	}
x86_l_206d:
	/* 0x206d: cmp    QWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2071:
	/* 0x2071: je     2425 <trace_security_file_open+0x2425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9253ULL;
	}
x86_l_2077:
	/* 0x2077: mov    QWORD PTR [rsp+0x98],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_207f:
	/* 0x207f: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_2082:
	/* 0x2082: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_2085:
	/* 0x2085: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_208d:
	/* 0x208d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2092:
	/* 0x2092: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_lpm_bufs)));
x86_l_2099:
	/* 0x2099: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_209e:
	/* 0x209e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20a0:
	/* 0x20a0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20a3:
	/* 0x20a3: mov    r11,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_20ab:
	/* 0x20ab: je     20bb <trace_security_file_open+0x20bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20bb;
	}
x86_l_20ad:
	/* 0x20ad: movzx  ecx,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_20b2:
	/* 0x20b2: cmp    rcx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 31995ULL);
x86_l_20b9:
	/* 0x20b9: jbe    20ca <trace_security_file_open+0x20ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_20ca;
	}
x86_l_20bb:
	/* 0x20bb: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20bd:
	/* 0x20bd: mov    r10,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_20c5:
	/* 0x20c5: jmp    1dbd <trace_security_file_open+0x1dbd> */
	goto x86_l_1dbd;
x86_l_20ca:
	/* 0x20ca: mov    r8d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_32);
x86_l_20cd:
	/* 0x20cd: mov    edx,DWORD PTR [rcx+r14*1+0x8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_20d5:
	/* 0x20d5: cmp    edx,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_20db:
	/* 0x20db: mov    r10,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_20e3:
	/* 0x20e3: jbe    2104 <trace_security_file_open+0x2104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2104;
	}
x86_l_20e5:
	/* 0x20e5: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_20e7:
	/* 0x20e7: add    ecx,0xffffff05 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967045ULL);
x86_l_20ed:
	/* 0x20ed: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_20f0:
	/* 0x20f0: mov    edx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 255ULL);
x86_l_20f5:
	/* 0x20f5: cmp    ecx,0x7c00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31744ULL);
x86_l_20fb:
	/* 0x20fb: jbe    2131 <trace_security_file_open+0x2131> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2131;
	}
x86_l_20fd:
	/* 0x20fd: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20ff:
	/* 0x20ff: jmp    1dbd <trace_security_file_open+0x1dbd> */
	goto x86_l_1dbd;
x86_l_2104:
	/* 0x2104: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2106:
	/* 0x2106: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2108:
	/* 0x2108: je     1dbd <trace_security_file_open+0x1dbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dbd;
	}
x86_l_210e:
	/* 0x210e: lea    esi,[rdx+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2111:
	/* 0x2111: add    esi,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2114:
	/* 0x2114: cmp    esi,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 32000ULL);
x86_l_211a:
	/* 0x211a: ja     1dbd <trace_security_file_open+0x1dbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1dbd;
	}
x86_l_2120:
	/* 0x2120: dec    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2122:
	/* 0x2122: and    edx,0xff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 255ULL);
x86_l_2128:
	/* 0x2128: je     2386 <trace_security_file_open+0x2386> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9094ULL;
	}
x86_l_212e:
	/* 0x212e: add    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2131:
	/* 0x2131: mov    esi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_2133:
	/* 0x2133: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2135:
	/* 0x2135: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2137:
	/* 0x2137: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2139:
	/* 0x2139: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_213b:
	/* 0x213b: cmp    ecx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31999ULL);
x86_l_2141:
	/* 0x2141: ja     1dbd <trace_security_file_open+0x1dbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1dbd;
	}
x86_l_2147:
	/* 0x2147: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_2149:
	/* 0x2149: movzx  edi,BYTE PTR [r14+rdi*1+0x89] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDI, 0, X86_WIDTH_8), 137ULL);
x86_l_2152:
	/* 0x2152: mov    BYTE PTR [rax+rdx*1+0x4],dil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RDX, 0), 4ULL);
x86_l_2157:
	/* 0x2157: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_215a:
	/* 0x215a: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_215c:
	/* 0x215c: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_215f:
	/* 0x215f: jne    213b <trace_security_file_open+0x213b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_213b;
	}
x86_l_2161:
	/* 0x2161: jmp    2388 <trace_security_file_open+0x2388> */
	return 9096ULL;
x86_l_2166:
	/* 0x2166: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_216b:
	/* 0x216b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2171:
	/* 0x2171: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2174:
	/* 0x2174: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2179:
	/* 0x2179: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_217b:
	/* 0x217b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_217e:
	/* 0x217e: jl     162f <trace_security_file_open+0x162f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5679ULL;
	}
x86_l_2184:
	/* 0x2184: lea    ecx,[r12-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2189:
	/* 0x2189: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_218f:
	/* 0x218f: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2194:
	/* 0x2194: sub    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2197:
	/* 0x2197: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_219c:
	/* 0x219c: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21a1:
	/* 0x21a1: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_21a4:
	/* 0x21a4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21a9:
	/* 0x21a9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21ae:
	/* 0x21ae: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21b3:
	/* 0x21b3: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_21b6:
	/* 0x21b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21b8:
	/* 0x21b8: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21bd:
	/* 0x21bd: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21c2:
	/* 0x21c2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_21c6:
	/* 0x21c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21cb:
	/* 0x21cb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21d0:
	/* 0x21d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21d5:
	/* 0x21d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21d7:
	/* 0x21d7: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21dc:
	/* 0x21dc: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_21df:
	/* 0x21df: je     225c <trace_security_file_open+0x225c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_225c;
	}
x86_l_21e1:
	/* 0x21e1: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21e6:
	/* 0x21e6: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_21e9:
	/* 0x21e9: je     225c <trace_security_file_open+0x225c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_225c;
	}
x86_l_21eb:
	/* 0x21eb: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_21ef:
	/* 0x21ef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21f4:
	/* 0x21f4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21f9:
	/* 0x21f9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_21fe:
	/* 0x21fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2200:
	/* 0x2200: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2204:
	/* 0x2204: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2206:
	/* 0x2206: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_220c:
	/* 0x220c: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2211:
	/* 0x2211: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_2214:
	/* 0x2214: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2216:
	/* 0x2216: jb     1f64 <trace_security_file_open+0x1f64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f64;
	}
x86_l_221c:
	/* 0x221c: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2221:
	/* 0x2221: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2227:
	/* 0x2227: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_222a:
	/* 0x222a: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_222f:
	/* 0x222f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2231:
	/* 0x2231: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2234:
	/* 0x2234: jl     162f <trace_security_file_open+0x162f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5679ULL;
	}
x86_l_223a:
	/* 0x223a: lea    ecx,[r12-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_223f:
	/* 0x223f: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2245:
	/* 0x2245: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_224a:
	/* 0x224a: sub    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_224d:
	/* 0x224d: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2252:
	/* 0x2252: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2257:
	/* 0x2257: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_225a:
	/* 0x225a: jmp    22c4 <trace_security_file_open+0x22c4> */
	return 8900ULL;
x86_l_225c:
	/* 0x225c: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_225f:
	/* 0x225f: jne    162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5674ULL;
	}
x86_l_2265:
	/* 0x2265: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_226a:
	/* 0x226a: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_226f:
	/* 0x226f: je     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5674ULL;
	}
x86_l_2275:
	/* 0x2275: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_227a:
	/* 0x227a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_227f:
	/* 0x227f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2283:
	/* 0x2283: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2288:
	/* 0x2288: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_228d:
	/* 0x228d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_228f:
	/* 0x228f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2294:
	/* 0x2294: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2299:
	/* 0x2299: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_229e:
	/* 0x229e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22a3:
	/* 0x22a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22a5:
	/* 0x22a5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
	return 8874ULL;
}

static __noinline __u64 tracee_trace_security_file_open_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8874ULL: goto x86_l_22aa;
	case 8879ULL: goto x86_l_22af;
	case 8884ULL: goto x86_l_22b4;
	case 8889ULL: goto x86_l_22b9;
	case 8891ULL: goto x86_l_22bb;
	case 8896ULL: goto x86_l_22c0;
	case 8900ULL: goto x86_l_22c4;
	case 8905ULL: goto x86_l_22c9;
	case 8910ULL: goto x86_l_22ce;
	case 8915ULL: goto x86_l_22d3;
	case 8920ULL: goto x86_l_22d8;
	case 8922ULL: goto x86_l_22da;
	case 8927ULL: goto x86_l_22df;
	case 8932ULL: goto x86_l_22e4;
	case 8936ULL: goto x86_l_22e8;
	case 8941ULL: goto x86_l_22ed;
	case 8946ULL: goto x86_l_22f2;
	case 8951ULL: goto x86_l_22f7;
	case 8953ULL: goto x86_l_22f9;
	case 8958ULL: goto x86_l_22fe;
	case 8961ULL: goto x86_l_2301;
	case 8967ULL: goto x86_l_2307;
	case 8972ULL: goto x86_l_230c;
	case 8975ULL: goto x86_l_230f;
	case 8981ULL: goto x86_l_2315;
	case 8985ULL: goto x86_l_2319;
	case 8990ULL: goto x86_l_231e;
	case 8995ULL: goto x86_l_2323;
	case 9000ULL: goto x86_l_2328;
	case 9002ULL: goto x86_l_232a;
	case 9006ULL: goto x86_l_232e;
	case 9008ULL: goto x86_l_2330;
	case 9014ULL: goto x86_l_2336;
	case 9019ULL: goto x86_l_233b;
	case 9022ULL: goto x86_l_233e;
	case 9024ULL: goto x86_l_2340;
	case 9030ULL: goto x86_l_2346;
	case 9035ULL: goto x86_l_234b;
	case 9041ULL: goto x86_l_2351;
	case 9044ULL: goto x86_l_2354;
	case 9049ULL: goto x86_l_2359;
	case 9051ULL: goto x86_l_235b;
	case 9054ULL: goto x86_l_235e;
	case 9060ULL: goto x86_l_2364;
	case 9065ULL: goto x86_l_2369;
	case 9071ULL: goto x86_l_236f;
	case 9076ULL: goto x86_l_2374;
	case 9079ULL: goto x86_l_2377;
	case 9084ULL: goto x86_l_237c;
	case 9089ULL: goto x86_l_2381;
	case 9094ULL: goto x86_l_2386;
	case 9096ULL: goto x86_l_2388;
	case 9098ULL: goto x86_l_238a;
	case 9103ULL: goto x86_l_238f;
	case 9110ULL: goto x86_l_2396;
	case 9115ULL: goto x86_l_239b;
	case 9117ULL: goto x86_l_239d;
	case 9124ULL: goto x86_l_23a4;
	case 9129ULL: goto x86_l_23a9;
	case 9134ULL: goto x86_l_23ae;
	case 9141ULL: goto x86_l_23b5;
	case 9146ULL: goto x86_l_23ba;
	case 9151ULL: goto x86_l_23bf;
	case 9158ULL: goto x86_l_23c6;
	case 9163ULL: goto x86_l_23cb;
	case 9165ULL: goto x86_l_23cd;
	case 9172ULL: goto x86_l_23d4;
	case 9175ULL: goto x86_l_23d7;
	case 9177ULL: goto x86_l_23d9;
	case 9182ULL: goto x86_l_23de;
	case 9185ULL: goto x86_l_23e1;
	case 9190ULL: goto x86_l_23e6;
	case 9192ULL: goto x86_l_23e8;
	case 9195ULL: goto x86_l_23eb;
	case 9197ULL: goto x86_l_23ed;
	case 9200ULL: goto x86_l_23f0;
	case 9204ULL: goto x86_l_23f4;
	case 9207ULL: goto x86_l_23f7;
	case 9209ULL: goto x86_l_23f9;
	case 9211ULL: goto x86_l_23fb;
	case 9214ULL: goto x86_l_23fe;
	case 9217ULL: goto x86_l_2401;
	case 9225ULL: goto x86_l_2409;
	case 9228ULL: goto x86_l_240c;
	case 9231ULL: goto x86_l_240f;
	case 9236ULL: goto x86_l_2414;
	case 9239ULL: goto x86_l_2417;
	case 9244ULL: goto x86_l_241c;
	case 9247ULL: goto x86_l_241f;
	case 9250ULL: goto x86_l_2422;
	case 9253ULL: goto x86_l_2425;
	case 9261ULL: goto x86_l_242d;
	case 9269ULL: goto x86_l_2435;
	case 9274ULL: goto x86_l_243a;
	case 9277ULL: goto x86_l_243d;
	case 9280ULL: goto x86_l_2440;
	case 9283ULL: goto x86_l_2443;
	case 9290ULL: goto x86_l_244a;
	case 9293ULL: goto x86_l_244d;
	case 9298ULL: goto x86_l_2452;
	case 9301ULL: goto x86_l_2455;
	case 9307ULL: goto x86_l_245b;
	case 9312ULL: goto x86_l_2460;
	case 9317ULL: goto x86_l_2465;
	case 9323ULL: goto x86_l_246b;
	case 9328ULL: goto x86_l_2470;
	case 9333ULL: goto x86_l_2475;
	case 9337ULL: goto x86_l_2479;
	case 9342ULL: goto x86_l_247e;
	case 9347ULL: goto x86_l_2483;
	case 9349ULL: goto x86_l_2485;
	case 9354ULL: goto x86_l_248a;
	case 9359ULL: goto x86_l_248f;
	case 9364ULL: goto x86_l_2494;
	case 9369ULL: goto x86_l_2499;
	case 9371ULL: goto x86_l_249b;
	case 9376ULL: goto x86_l_24a0;
	case 9381ULL: goto x86_l_24a5;
	case 9386ULL: goto x86_l_24aa;
	case 9391ULL: goto x86_l_24af;
	case 9393ULL: goto x86_l_24b1;
	case 9398ULL: goto x86_l_24b6;
	case 9402ULL: goto x86_l_24ba;
	case 9407ULL: goto x86_l_24bf;
	case 9412ULL: goto x86_l_24c4;
	case 9417ULL: goto x86_l_24c9;
	case 9422ULL: goto x86_l_24ce;
	case 9427ULL: goto x86_l_24d3;
	case 9429ULL: goto x86_l_24d5;
	case 9434ULL: goto x86_l_24da;
	case 9439ULL: goto x86_l_24df;
	case 9443ULL: goto x86_l_24e3;
	case 9448ULL: goto x86_l_24e8;
	case 9453ULL: goto x86_l_24ed;
	case 9458ULL: goto x86_l_24f2;
	case 9460ULL: goto x86_l_24f4;
	case 9465ULL: goto x86_l_24f9;
	case 9468ULL: goto x86_l_24fc;
	case 9474ULL: goto x86_l_2502;
	case 9479ULL: goto x86_l_2507;
	case 9482ULL: goto x86_l_250a;
	case 9488ULL: goto x86_l_2510;
	case 9492ULL: goto x86_l_2514;
	case 9497ULL: goto x86_l_2519;
	case 9502ULL: goto x86_l_251e;
	case 9507ULL: goto x86_l_2523;
	case 9509ULL: goto x86_l_2525;
	case 9513ULL: goto x86_l_2529;
	case 9515ULL: goto x86_l_252b;
	case 9521ULL: goto x86_l_2531;
	case 9526ULL: goto x86_l_2536;
	case 9529ULL: goto x86_l_2539;
	case 9531ULL: goto x86_l_253b;
	case 9537ULL: goto x86_l_2541;
	case 9542ULL: goto x86_l_2546;
	case 9548ULL: goto x86_l_254c;
	case 9551ULL: goto x86_l_254f;
	case 9556ULL: goto x86_l_2554;
	case 9558ULL: goto x86_l_2556;
	case 9561ULL: goto x86_l_2559;
	case 9567ULL: goto x86_l_255f;
	case 9572ULL: goto x86_l_2564;
	case 9578ULL: goto x86_l_256a;
	case 9583ULL: goto x86_l_256f;
	case 9586ULL: goto x86_l_2572;
	case 9591ULL: goto x86_l_2577;
	case 9596ULL: goto x86_l_257c;
	case 9601ULL: goto x86_l_2581;
	case 9608ULL: goto x86_l_2588;
	case 9611ULL: goto x86_l_258b;
	case 9615ULL: goto x86_l_258f;
	case 9620ULL: goto x86_l_2594;
	case 9625ULL: goto x86_l_2599;
	case 9627ULL: goto x86_l_259b;
	case 9630ULL: goto x86_l_259e;
	case 9636ULL: goto x86_l_25a4;
	case 9641ULL: goto x86_l_25a9;
	case 9646ULL: goto x86_l_25ae;
	case 9651ULL: goto x86_l_25b3;
	case 9654ULL: goto x86_l_25b6;
	case 9660ULL: goto x86_l_25bc;
	case 9665ULL: goto x86_l_25c1;
	case 9670ULL: goto x86_l_25c6;
	case 9676ULL: goto x86_l_25cc;
	case 9681ULL: goto x86_l_25d1;
	case 9686ULL: goto x86_l_25d6;
	case 9690ULL: goto x86_l_25da;
	case 9695ULL: goto x86_l_25df;
	case 9700ULL: goto x86_l_25e4;
	case 9702ULL: goto x86_l_25e6;
	case 9707ULL: goto x86_l_25eb;
	case 9712ULL: goto x86_l_25f0;
	case 9717ULL: goto x86_l_25f5;
	case 9722ULL: goto x86_l_25fa;
	case 9724ULL: goto x86_l_25fc;
	case 9729ULL: goto x86_l_2601;
	case 9734ULL: goto x86_l_2606;
	case 9739ULL: goto x86_l_260b;
	case 9744ULL: goto x86_l_2610;
	case 9746ULL: goto x86_l_2612;
	case 9751ULL: goto x86_l_2617;
	case 9755ULL: goto x86_l_261b;
	case 9760ULL: goto x86_l_2620;
	case 9765ULL: goto x86_l_2625;
	case 9770ULL: goto x86_l_262a;
	case 9775ULL: goto x86_l_262f;
	case 9780ULL: goto x86_l_2634;
	case 9782ULL: goto x86_l_2636;
	case 9787ULL: goto x86_l_263b;
	case 9792ULL: goto x86_l_2640;
	case 9796ULL: goto x86_l_2644;
	case 9801ULL: goto x86_l_2649;
	case 9806ULL: goto x86_l_264e;
	case 9811ULL: goto x86_l_2653;
	case 9813ULL: goto x86_l_2655;
	case 9818ULL: goto x86_l_265a;
	case 9821ULL: goto x86_l_265d;
	case 9823ULL: goto x86_l_265f;
	case 9828ULL: goto x86_l_2664;
	case 9831ULL: goto x86_l_2667;
	case 9833ULL: goto x86_l_2669;
	case 9837ULL: goto x86_l_266d;
	case 9842ULL: goto x86_l_2672;
	case 9847ULL: goto x86_l_2677;
	case 9852ULL: goto x86_l_267c;
	case 9854ULL: goto x86_l_267e;
	case 9858ULL: goto x86_l_2682;
	case 9860ULL: goto x86_l_2684;
	case 9866ULL: goto x86_l_268a;
	case 9871ULL: goto x86_l_268f;
	case 9873ULL: goto x86_l_2691;
	case 9875ULL: goto x86_l_2693;
	case 9880ULL: goto x86_l_2698;
	case 9885ULL: goto x86_l_269d;
	case 9888ULL: goto x86_l_26a0;
	case 9894ULL: goto x86_l_26a6;
	case 9899ULL: goto x86_l_26ab;
	case 9904ULL: goto x86_l_26b0;
	case 9910ULL: goto x86_l_26b6;
	case 9915ULL: goto x86_l_26bb;
	case 9920ULL: goto x86_l_26c0;
	case 9924ULL: goto x86_l_26c4;
	case 9929ULL: goto x86_l_26c9;
	case 9934ULL: goto x86_l_26ce;
	case 9936ULL: goto x86_l_26d0;
	case 9941ULL: goto x86_l_26d5;
	case 9946ULL: goto x86_l_26da;
	case 9951ULL: goto x86_l_26df;
	case 9956ULL: goto x86_l_26e4;
	case 9958ULL: goto x86_l_26e6;
	case 9963ULL: goto x86_l_26eb;
	case 9968ULL: goto x86_l_26f0;
	case 9973ULL: goto x86_l_26f5;
	case 9978ULL: goto x86_l_26fa;
	case 9980ULL: goto x86_l_26fc;
	case 9985ULL: goto x86_l_2701;
	case 9989ULL: goto x86_l_2705;
	case 9994ULL: goto x86_l_270a;
	case 9996ULL: goto x86_l_270c;
	case 10001ULL: goto x86_l_2711;
	case 10007ULL: goto x86_l_2717;
	case 10010ULL: goto x86_l_271a;
	case 10015ULL: goto x86_l_271f;
	case 10017ULL: goto x86_l_2721;
	case 10020ULL: goto x86_l_2724;
	case 10026ULL: goto x86_l_272a;
	case 10031ULL: goto x86_l_272f;
	case 10034ULL: goto x86_l_2732;
	case 10040ULL: goto x86_l_2738;
	case 10045ULL: goto x86_l_273d;
	case 10047ULL: goto x86_l_273f;
	case 10052ULL: goto x86_l_2744;
	case 10057ULL: goto x86_l_2749;
	case 10062ULL: goto x86_l_274e;
	case 10067ULL: goto x86_l_2753;
	case 10072ULL: goto x86_l_2758;
	case 10077ULL: goto x86_l_275d;
	case 10079ULL: goto x86_l_275f;
	case 10084ULL: goto x86_l_2764;
	case 10089ULL: goto x86_l_2769;
	case 10093ULL: goto x86_l_276d;
	case 10098ULL: goto x86_l_2772;
	case 10103ULL: goto x86_l_2777;
	case 10108ULL: goto x86_l_277c;
	case 10110ULL: goto x86_l_277e;
	case 10115ULL: goto x86_l_2783;
	case 10118ULL: goto x86_l_2786;
	case 10120ULL: goto x86_l_2788;
	case 10125ULL: goto x86_l_278d;
	case 10128ULL: goto x86_l_2790;
	case 10130ULL: goto x86_l_2792;
	case 10134ULL: goto x86_l_2796;
	case 10139ULL: goto x86_l_279b;
	case 10144ULL: goto x86_l_27a0;
	case 10149ULL: goto x86_l_27a5;
	case 10151ULL: goto x86_l_27a7;
	case 10155ULL: goto x86_l_27ab;
	case 10157ULL: goto x86_l_27ad;
	case 10163ULL: goto x86_l_27b3;
	case 10168ULL: goto x86_l_27b8;
	case 10170ULL: goto x86_l_27ba;
	case 10176ULL: goto x86_l_27c0;
	case 10181ULL: goto x86_l_27c5;
	case 10187ULL: goto x86_l_27cb;
	case 10190ULL: goto x86_l_27ce;
	case 10195ULL: goto x86_l_27d3;
	case 10197ULL: goto x86_l_27d5;
	case 10200ULL: goto x86_l_27d8;
	case 10206ULL: goto x86_l_27de;
	case 10211ULL: goto x86_l_27e3;
	case 10214ULL: goto x86_l_27e6;
	case 10220ULL: goto x86_l_27ec;
	case 10225ULL: goto x86_l_27f1;
	case 10227ULL: goto x86_l_27f3;
	case 10232ULL: goto x86_l_27f8;
	case 10237ULL: goto x86_l_27fd;
	case 10239ULL: goto x86_l_27ff;
	case 10242ULL: goto x86_l_2802;
	case 10248ULL: goto x86_l_2808;
	case 10253ULL: goto x86_l_280d;
	case 10258ULL: goto x86_l_2812;
	case 10264ULL: goto x86_l_2818;
	case 10269ULL: goto x86_l_281d;
	case 10274ULL: goto x86_l_2822;
	case 10278ULL: goto x86_l_2826;
	case 10283ULL: goto x86_l_282b;
	case 10288ULL: goto x86_l_2830;
	case 10290ULL: goto x86_l_2832;
	case 10295ULL: goto x86_l_2837;
	case 10300ULL: goto x86_l_283c;
	case 10305ULL: goto x86_l_2841;
	case 10310ULL: goto x86_l_2846;
	case 10312ULL: goto x86_l_2848;
	case 10317ULL: goto x86_l_284d;
	case 10322ULL: goto x86_l_2852;
	case 10327ULL: goto x86_l_2857;
	case 10332ULL: goto x86_l_285c;
	case 10334ULL: goto x86_l_285e;
	case 10339ULL: goto x86_l_2863;
	case 10343ULL: goto x86_l_2867;
	case 10348ULL: goto x86_l_286c;
	case 10353ULL: goto x86_l_2871;
	case 10358ULL: goto x86_l_2876;
	case 10363ULL: goto x86_l_287b;
	case 10368ULL: goto x86_l_2880;
	case 10370ULL: goto x86_l_2882;
	case 10375ULL: goto x86_l_2887;
	case 10380ULL: goto x86_l_288c;
	case 10384ULL: goto x86_l_2890;
	case 10389ULL: goto x86_l_2895;
	case 10394ULL: goto x86_l_289a;
	case 10399ULL: goto x86_l_289f;
	case 10401ULL: goto x86_l_28a1;
	case 10406ULL: goto x86_l_28a6;
	case 10409ULL: goto x86_l_28a9;
	case 10411ULL: goto x86_l_28ab;
	case 10416ULL: goto x86_l_28b0;
	case 10419ULL: goto x86_l_28b3;
	case 10421ULL: goto x86_l_28b5;
	case 10425ULL: goto x86_l_28b9;
	case 10430ULL: goto x86_l_28be;
	case 10435ULL: goto x86_l_28c3;
	case 10440ULL: goto x86_l_28c8;
	case 10442ULL: goto x86_l_28ca;
	case 10446ULL: goto x86_l_28ce;
	case 10448ULL: goto x86_l_28d0;
	case 10454ULL: goto x86_l_28d6;
	case 10459ULL: goto x86_l_28db;
	case 10461ULL: goto x86_l_28dd;
	case 10467ULL: goto x86_l_28e3;
	case 10472ULL: goto x86_l_28e8;
	case 10478ULL: goto x86_l_28ee;
	case 10481ULL: goto x86_l_28f1;
	case 10486ULL: goto x86_l_28f6;
	case 10488ULL: goto x86_l_28f8;
	case 10491ULL: goto x86_l_28fb;
	case 10497ULL: goto x86_l_2901;
	case 10502ULL: goto x86_l_2906;
	case 10505ULL: goto x86_l_2909;
	case 10511ULL: goto x86_l_290f;
	case 10516ULL: goto x86_l_2914;
	case 10518ULL: goto x86_l_2916;
	case 10523ULL: goto x86_l_291b;
	case 10528ULL: goto x86_l_2920;
	default: return 0xffffffffffffffffULL;
	}
x86_l_22aa:
	/* 0x22aa: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22af:
	/* 0x22af: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22b4:
	/* 0x22b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22b9:
	/* 0x22b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22bb:
	/* 0x22bb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22c0:
	/* 0x22c0: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_22c4:
	/* 0x22c4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22c9:
	/* 0x22c9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22ce:
	/* 0x22ce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22d3:
	/* 0x22d3: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22d8:
	/* 0x22d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22da:
	/* 0x22da: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22df:
	/* 0x22df: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22e4:
	/* 0x22e4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_22e8:
	/* 0x22e8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22ed:
	/* 0x22ed: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22f2:
	/* 0x22f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22f7:
	/* 0x22f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22f9:
	/* 0x22f9: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22fe:
	/* 0x22fe: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2301:
	/* 0x2301: je     2452 <trace_security_file_open+0x2452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2452;
	}
x86_l_2307:
	/* 0x2307: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_230c:
	/* 0x230c: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_230f:
	/* 0x230f: je     2452 <trace_security_file_open+0x2452> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2452;
	}
x86_l_2315:
	/* 0x2315: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2319:
	/* 0x2319: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_231e:
	/* 0x231e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2323:
	/* 0x2323: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2328:
	/* 0x2328: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_232a:
	/* 0x232a: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_232e:
	/* 0x232e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2330:
	/* 0x2330: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2336:
	/* 0x2336: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_233b:
	/* 0x233b: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_233e:
	/* 0x233e: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2340:
	/* 0x2340: jb     1f64 <trace_security_file_open+0x1f64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8036ULL;
	}
x86_l_2346:
	/* 0x2346: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_234b:
	/* 0x234b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2351:
	/* 0x2351: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2354:
	/* 0x2354: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2359:
	/* 0x2359: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_235b:
	/* 0x235b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_235e:
	/* 0x235e: jl     162f <trace_security_file_open+0x162f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5679ULL;
	}
x86_l_2364:
	/* 0x2364: lea    ecx,[r12-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2369:
	/* 0x2369: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_236f:
	/* 0x236f: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2374:
	/* 0x2374: sub    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2377:
	/* 0x2377: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_237c:
	/* 0x237c: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2381:
	/* 0x2381: jmp    24bf <trace_security_file_open+0x24bf> */
	goto x86_l_24bf;
x86_l_2386:
	/* 0x2386: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2388:
	/* 0x2388: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_238a:
	/* 0x238a: mov    BYTE PTR [rax+rcx*1+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 17179869184ULL);
x86_l_238f:
	/* 0x238f: lea    ecx,[rsi*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 8ULL);
x86_l_2396:
	/* 0x2396: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_239b:
	/* 0x239b: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_239d:
	/* 0x239d: mov    rbp,QWORD PTR [r14+0x7e08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_23a4:
	/* 0x23a4: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_23a9:
	/* 0x23a9: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23ae:
	/* 0x23ae: mov    WORD PTR [rsp+0x32],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 214748364800ULL);
x86_l_23b5:
	/* 0x23b5: mov    DWORD PTR [rsp+0x34],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_23ba:
	/* 0x23ba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23bf:
	/* 0x23bf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_suffix_version)));
x86_l_23c6:
	/* 0x23c6: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23cb:
	/* 0x23cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23cd:
	/* 0x23cd: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_23d4:
	/* 0x23d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23d7:
	/* 0x23d7: je     23f9 <trace_security_file_open+0x23f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23f9;
	}
x86_l_23d9:
	/* 0x23d9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_23de:
	/* 0x23de: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_23e1:
	/* 0x23e1: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_23e6:
	/* 0x23e6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_23e8:
	/* 0x23e8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23eb:
	/* 0x23eb: je     23f9 <trace_security_file_open+0x23f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23f9;
	}
x86_l_23ed:
	/* 0x23ed: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23f0:
	/* 0x23f0: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23f4:
	/* 0x23f4: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_23f7:
	/* 0x23f7: jmp    23fb <trace_security_file_open+0x23fb> */
	goto x86_l_23fb;
x86_l_23f9:
	/* 0x23f9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23fb:
	/* 0x23fb: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_23fe:
	/* 0x23fe: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2401:
	/* 0x2401: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2409:
	/* 0x2409: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_240c:
	/* 0x240c: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_240f:
	/* 0x240f: andn   rax,rbp,rcx */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_2414:
	/* 0x2414: or     rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2417:
	/* 0x2417: andn   rax,r12,rbp */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_241c:
	/* 0x241c: or     rdi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_241f:
	/* 0x241f: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_2422:
	/* 0x2422: or     rdx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_2425:
	/* 0x2425: mov    r10,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_242d:
	/* 0x242d: mov    r11,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2435:
	/* 0x2435: andn   rax,rdi,rdx */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_243a:
	/* 0x243a: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_243d:
	/* 0x243d: or     r15,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RSI, X86_WIDTH_64, X86_ALU_OR);
x86_l_2440:
	/* 0x2440: or     r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2443:
	/* 0x2443: and    r15,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_244a:
	/* 0x244a: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_244d:
	/* 0x244d: jmp    1dbd <trace_security_file_open+0x1dbd> */
	return 7613ULL;
x86_l_2452:
	/* 0x2452: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2455:
	/* 0x2455: jne    162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5674ULL;
	}
x86_l_245b:
	/* 0x245b: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2460:
	/* 0x2460: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2465:
	/* 0x2465: je     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5674ULL;
	}
x86_l_246b:
	/* 0x246b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2470:
	/* 0x2470: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2475:
	/* 0x2475: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2479:
	/* 0x2479: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_247e:
	/* 0x247e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2483:
	/* 0x2483: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2485:
	/* 0x2485: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_248a:
	/* 0x248a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_248f:
	/* 0x248f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2494:
	/* 0x2494: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2499:
	/* 0x2499: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_249b:
	/* 0x249b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24a0:
	/* 0x24a0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24a5:
	/* 0x24a5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24aa:
	/* 0x24aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24af:
	/* 0x24af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b1:
	/* 0x24b1: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24b6:
	/* 0x24b6: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_24ba:
	/* 0x24ba: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24bf:
	/* 0x24bf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24c4:
	/* 0x24c4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24c9:
	/* 0x24c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24ce:
	/* 0x24ce: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24d3:
	/* 0x24d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24d5:
	/* 0x24d5: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24da:
	/* 0x24da: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_24df:
	/* 0x24df: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_24e3:
	/* 0x24e3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24e8:
	/* 0x24e8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24ed:
	/* 0x24ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24f2:
	/* 0x24f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24f4:
	/* 0x24f4: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_24f9:
	/* 0x24f9: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_24fc:
	/* 0x24fc: je     25b3 <trace_security_file_open+0x25b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25b3;
	}
x86_l_2502:
	/* 0x2502: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2507:
	/* 0x2507: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_250a:
	/* 0x250a: je     25b3 <trace_security_file_open+0x25b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25b3;
	}
x86_l_2510:
	/* 0x2510: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2514:
	/* 0x2514: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2519:
	/* 0x2519: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_251e:
	/* 0x251e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2523:
	/* 0x2523: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2525:
	/* 0x2525: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2529:
	/* 0x2529: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_252b:
	/* 0x252b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2531:
	/* 0x2531: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2536:
	/* 0x2536: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_2539:
	/* 0x2539: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_253b:
	/* 0x253b: jb     1f64 <trace_security_file_open+0x1f64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8036ULL;
	}
x86_l_2541:
	/* 0x2541: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2546:
	/* 0x2546: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_254c:
	/* 0x254c: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_254f:
	/* 0x254f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2554:
	/* 0x2554: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2556:
	/* 0x2556: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2559:
	/* 0x2559: jl     162f <trace_security_file_open+0x162f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5679ULL;
	}
x86_l_255f:
	/* 0x255f: lea    ecx,[r12-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2564:
	/* 0x2564: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_256a:
	/* 0x256a: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_256f:
	/* 0x256f: sub    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2572:
	/* 0x2572: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2577:
	/* 0x2577: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_257c:
	/* 0x257c: jmp    2620 <trace_security_file_open+0x2620> */
	goto x86_l_2620;
x86_l_2581:
	/* 0x2581: lea    rdi,[r14+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_2588:
	/* 0x2588: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_258b:
	/* 0x258b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_258f:
	/* 0x258f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2594:
	/* 0x2594: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_2599:
	/* 0x2599: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_259b:
	/* 0x259b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_259e:
	/* 0x259e: jne    1e70 <trace_security_file_open+0x1e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7792ULL;
	}
x86_l_25a4:
	/* 0x25a4: movzx  eax,WORD PTR [r15+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_25a9:
	/* 0x25a9: mov    WORD PTR [r14+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_25ae:
	/* 0x25ae: jmp    b02 <trace_security_file_open+0xb02> */
	return 2818ULL;
x86_l_25b3:
	/* 0x25b3: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_25b6:
	/* 0x25b6: jne    162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5674ULL;
	}
x86_l_25bc:
	/* 0x25bc: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25c1:
	/* 0x25c1: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_25c6:
	/* 0x25c6: je     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5674ULL;
	}
x86_l_25cc:
	/* 0x25cc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25d1:
	/* 0x25d1: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25d6:
	/* 0x25d6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_25da:
	/* 0x25da: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_25df:
	/* 0x25df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25e4:
	/* 0x25e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25e6:
	/* 0x25e6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25eb:
	/* 0x25eb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25f0:
	/* 0x25f0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25f5:
	/* 0x25f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25fa:
	/* 0x25fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25fc:
	/* 0x25fc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2601:
	/* 0x2601: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2606:
	/* 0x2606: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_260b:
	/* 0x260b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2610:
	/* 0x2610: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2612:
	/* 0x2612: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2617:
	/* 0x2617: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_261b:
	/* 0x261b: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2620:
	/* 0x2620: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2625:
	/* 0x2625: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_262a:
	/* 0x262a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_262f:
	/* 0x262f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2634:
	/* 0x2634: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2636:
	/* 0x2636: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_263b:
	/* 0x263b: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2640:
	/* 0x2640: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2644:
	/* 0x2644: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2649:
	/* 0x2649: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_264e:
	/* 0x264e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2653:
	/* 0x2653: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2655:
	/* 0x2655: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_265a:
	/* 0x265a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_265d:
	/* 0x265d: je     269d <trace_security_file_open+0x269d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_269d;
	}
x86_l_265f:
	/* 0x265f: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2664:
	/* 0x2664: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2667:
	/* 0x2667: je     269d <trace_security_file_open+0x269d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_269d;
	}
x86_l_2669:
	/* 0x2669: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_266d:
	/* 0x266d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2672:
	/* 0x2672: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2677:
	/* 0x2677: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_267c:
	/* 0x267c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_267e:
	/* 0x267e: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2682:
	/* 0x2682: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2684:
	/* 0x2684: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_268a:
	/* 0x268a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_268f:
	/* 0x268f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2691:
	/* 0x2691: jae    270c <trace_security_file_open+0x270c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_270c;
	}
x86_l_2693:
	/* 0x2693: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2698:
	/* 0x2698: jmp    1f64 <trace_security_file_open+0x1f64> */
	return 8036ULL;
x86_l_269d:
	/* 0x269d: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_26a0:
	/* 0x26a0: jne    162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5674ULL;
	}
x86_l_26a6:
	/* 0x26a6: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26ab:
	/* 0x26ab: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_26b0:
	/* 0x26b0: je     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5674ULL;
	}
x86_l_26b6:
	/* 0x26b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26bb:
	/* 0x26bb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26c0:
	/* 0x26c0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_26c4:
	/* 0x26c4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_26c9:
	/* 0x26c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26ce:
	/* 0x26ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26d0:
	/* 0x26d0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26d5:
	/* 0x26d5: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26da:
	/* 0x26da: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26df:
	/* 0x26df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26e4:
	/* 0x26e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26e6:
	/* 0x26e6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26eb:
	/* 0x26eb: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26f0:
	/* 0x26f0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26f5:
	/* 0x26f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26fa:
	/* 0x26fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26fc:
	/* 0x26fc: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2701:
	/* 0x2701: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2705:
	/* 0x2705: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_270a:
	/* 0x270a: jmp    2749 <trace_security_file_open+0x2749> */
	goto x86_l_2749;
x86_l_270c:
	/* 0x270c: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2711:
	/* 0x2711: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2717:
	/* 0x2717: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_271a:
	/* 0x271a: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_271f:
	/* 0x271f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2721:
	/* 0x2721: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2724:
	/* 0x2724: jl     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5674ULL;
	}
x86_l_272a:
	/* 0x272a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_272f:
	/* 0x272f: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2732:
	/* 0x2732: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2738:
	/* 0x2738: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_273d:
	/* 0x273d: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_273f:
	/* 0x273f: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2744:
	/* 0x2744: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2749:
	/* 0x2749: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_274e:
	/* 0x274e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2753:
	/* 0x2753: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2758:
	/* 0x2758: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_275d:
	/* 0x275d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_275f:
	/* 0x275f: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2764:
	/* 0x2764: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2769:
	/* 0x2769: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_276d:
	/* 0x276d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2772:
	/* 0x2772: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2777:
	/* 0x2777: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_277c:
	/* 0x277c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_277e:
	/* 0x277e: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2783:
	/* 0x2783: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2786:
	/* 0x2786: je     27ff <trace_security_file_open+0x27ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27ff;
	}
x86_l_2788:
	/* 0x2788: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_278d:
	/* 0x278d: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2790:
	/* 0x2790: je     27ff <trace_security_file_open+0x27ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27ff;
	}
x86_l_2792:
	/* 0x2792: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2796:
	/* 0x2796: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_279b:
	/* 0x279b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27a0:
	/* 0x27a0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_27a5:
	/* 0x27a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27a7:
	/* 0x27a7: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_27ab:
	/* 0x27ab: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_27ad:
	/* 0x27ad: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_27b3:
	/* 0x27b3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27b8:
	/* 0x27b8: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_27ba:
	/* 0x27ba: jb     2693 <trace_security_file_open+0x2693> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2693;
	}
x86_l_27c0:
	/* 0x27c0: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_27c5:
	/* 0x27c5: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_27cb:
	/* 0x27cb: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_27ce:
	/* 0x27ce: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_27d3:
	/* 0x27d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27d5:
	/* 0x27d5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_27d8:
	/* 0x27d8: jl     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5674ULL;
	}
x86_l_27de:
	/* 0x27de: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27e3:
	/* 0x27e3: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_27e6:
	/* 0x27e6: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_27ec:
	/* 0x27ec: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_27f1:
	/* 0x27f1: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_27f3:
	/* 0x27f3: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27f8:
	/* 0x27f8: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27fd:
	/* 0x27fd: jmp    286c <trace_security_file_open+0x286c> */
	goto x86_l_286c;
x86_l_27ff:
	/* 0x27ff: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2802:
	/* 0x2802: jne    162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5674ULL;
	}
x86_l_2808:
	/* 0x2808: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_280d:
	/* 0x280d: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2812:
	/* 0x2812: je     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5674ULL;
	}
x86_l_2818:
	/* 0x2818: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_281d:
	/* 0x281d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2822:
	/* 0x2822: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2826:
	/* 0x2826: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_282b:
	/* 0x282b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2830:
	/* 0x2830: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2832:
	/* 0x2832: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2837:
	/* 0x2837: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_283c:
	/* 0x283c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2841:
	/* 0x2841: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2846:
	/* 0x2846: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2848:
	/* 0x2848: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_284d:
	/* 0x284d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2852:
	/* 0x2852: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2857:
	/* 0x2857: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_285c:
	/* 0x285c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_285e:
	/* 0x285e: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2863:
	/* 0x2863: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2867:
	/* 0x2867: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_286c:
	/* 0x286c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2871:
	/* 0x2871: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2876:
	/* 0x2876: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_287b:
	/* 0x287b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2880:
	/* 0x2880: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2882:
	/* 0x2882: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2887:
	/* 0x2887: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_288c:
	/* 0x288c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2890:
	/* 0x2890: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2895:
	/* 0x2895: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_289a:
	/* 0x289a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_289f:
	/* 0x289f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28a1:
	/* 0x28a1: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28a6:
	/* 0x28a6: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_28a9:
	/* 0x28a9: je     2922 <trace_security_file_open+0x2922> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10530ULL;
	}
x86_l_28ab:
	/* 0x28ab: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28b0:
	/* 0x28b0: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_28b3:
	/* 0x28b3: je     2922 <trace_security_file_open+0x2922> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10530ULL;
	}
x86_l_28b5:
	/* 0x28b5: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_28b9:
	/* 0x28b9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28be:
	/* 0x28be: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28c3:
	/* 0x28c3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_28c8:
	/* 0x28c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28ca:
	/* 0x28ca: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_28ce:
	/* 0x28ce: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_28d0:
	/* 0x28d0: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_28d6:
	/* 0x28d6: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28db:
	/* 0x28db: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_28dd:
	/* 0x28dd: jb     2693 <trace_security_file_open+0x2693> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2693;
	}
x86_l_28e3:
	/* 0x28e3: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_28e8:
	/* 0x28e8: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_28ee:
	/* 0x28ee: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28f1:
	/* 0x28f1: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_28f6:
	/* 0x28f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28f8:
	/* 0x28f8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_28fb:
	/* 0x28fb: jl     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5674ULL;
	}
x86_l_2901:
	/* 0x2901: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2906:
	/* 0x2906: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2909:
	/* 0x2909: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_290f:
	/* 0x290f: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2914:
	/* 0x2914: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2916:
	/* 0x2916: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_291b:
	/* 0x291b: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2920:
	/* 0x2920: jmp    298f <trace_security_file_open+0x298f> */
	return 10639ULL;
	return 10530ULL;
}

static __noinline __u64 tracee_trace_security_file_open_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10530ULL: goto x86_l_2922;
	case 10533ULL: goto x86_l_2925;
	case 10539ULL: goto x86_l_292b;
	case 10544ULL: goto x86_l_2930;
	case 10549ULL: goto x86_l_2935;
	case 10555ULL: goto x86_l_293b;
	case 10560ULL: goto x86_l_2940;
	case 10565ULL: goto x86_l_2945;
	case 10569ULL: goto x86_l_2949;
	case 10574ULL: goto x86_l_294e;
	case 10579ULL: goto x86_l_2953;
	case 10581ULL: goto x86_l_2955;
	case 10586ULL: goto x86_l_295a;
	case 10591ULL: goto x86_l_295f;
	case 10596ULL: goto x86_l_2964;
	case 10601ULL: goto x86_l_2969;
	case 10603ULL: goto x86_l_296b;
	case 10608ULL: goto x86_l_2970;
	case 10613ULL: goto x86_l_2975;
	case 10618ULL: goto x86_l_297a;
	case 10623ULL: goto x86_l_297f;
	case 10625ULL: goto x86_l_2981;
	case 10630ULL: goto x86_l_2986;
	case 10634ULL: goto x86_l_298a;
	case 10639ULL: goto x86_l_298f;
	case 10644ULL: goto x86_l_2994;
	case 10649ULL: goto x86_l_2999;
	case 10654ULL: goto x86_l_299e;
	case 10659ULL: goto x86_l_29a3;
	case 10661ULL: goto x86_l_29a5;
	case 10666ULL: goto x86_l_29aa;
	case 10671ULL: goto x86_l_29af;
	case 10675ULL: goto x86_l_29b3;
	case 10680ULL: goto x86_l_29b8;
	case 10685ULL: goto x86_l_29bd;
	case 10690ULL: goto x86_l_29c2;
	case 10692ULL: goto x86_l_29c4;
	case 10697ULL: goto x86_l_29c9;
	case 10700ULL: goto x86_l_29cc;
	case 10702ULL: goto x86_l_29ce;
	case 10707ULL: goto x86_l_29d3;
	case 10710ULL: goto x86_l_29d6;
	case 10712ULL: goto x86_l_29d8;
	case 10716ULL: goto x86_l_29dc;
	case 10721ULL: goto x86_l_29e1;
	case 10726ULL: goto x86_l_29e6;
	case 10731ULL: goto x86_l_29eb;
	case 10733ULL: goto x86_l_29ed;
	case 10737ULL: goto x86_l_29f1;
	case 10739ULL: goto x86_l_29f3;
	case 10745ULL: goto x86_l_29f9;
	case 10750ULL: goto x86_l_29fe;
	case 10752ULL: goto x86_l_2a00;
	case 10758ULL: goto x86_l_2a06;
	case 10763ULL: goto x86_l_2a0b;
	case 10769ULL: goto x86_l_2a11;
	case 10772ULL: goto x86_l_2a14;
	case 10777ULL: goto x86_l_2a19;
	case 10779ULL: goto x86_l_2a1b;
	case 10782ULL: goto x86_l_2a1e;
	case 10788ULL: goto x86_l_2a24;
	case 10793ULL: goto x86_l_2a29;
	case 10796ULL: goto x86_l_2a2c;
	case 10802ULL: goto x86_l_2a32;
	case 10807ULL: goto x86_l_2a37;
	case 10809ULL: goto x86_l_2a39;
	case 10814ULL: goto x86_l_2a3e;
	case 10819ULL: goto x86_l_2a43;
	case 10821ULL: goto x86_l_2a45;
	case 10824ULL: goto x86_l_2a48;
	case 10830ULL: goto x86_l_2a4e;
	case 10835ULL: goto x86_l_2a53;
	case 10840ULL: goto x86_l_2a58;
	case 10846ULL: goto x86_l_2a5e;
	case 10851ULL: goto x86_l_2a63;
	case 10856ULL: goto x86_l_2a68;
	case 10860ULL: goto x86_l_2a6c;
	case 10865ULL: goto x86_l_2a71;
	case 10870ULL: goto x86_l_2a76;
	case 10872ULL: goto x86_l_2a78;
	case 10877ULL: goto x86_l_2a7d;
	case 10882ULL: goto x86_l_2a82;
	case 10887ULL: goto x86_l_2a87;
	case 10892ULL: goto x86_l_2a8c;
	case 10894ULL: goto x86_l_2a8e;
	case 10899ULL: goto x86_l_2a93;
	case 10904ULL: goto x86_l_2a98;
	case 10909ULL: goto x86_l_2a9d;
	case 10914ULL: goto x86_l_2aa2;
	case 10916ULL: goto x86_l_2aa4;
	case 10921ULL: goto x86_l_2aa9;
	case 10925ULL: goto x86_l_2aad;
	case 10930ULL: goto x86_l_2ab2;
	case 10935ULL: goto x86_l_2ab7;
	case 10940ULL: goto x86_l_2abc;
	case 10945ULL: goto x86_l_2ac1;
	case 10950ULL: goto x86_l_2ac6;
	case 10952ULL: goto x86_l_2ac8;
	case 10957ULL: goto x86_l_2acd;
	case 10962ULL: goto x86_l_2ad2;
	case 10966ULL: goto x86_l_2ad6;
	case 10971ULL: goto x86_l_2adb;
	case 10976ULL: goto x86_l_2ae0;
	case 10981ULL: goto x86_l_2ae5;
	case 10983ULL: goto x86_l_2ae7;
	case 10988ULL: goto x86_l_2aec;
	case 10991ULL: goto x86_l_2aef;
	case 10993ULL: goto x86_l_2af1;
	case 10998ULL: goto x86_l_2af6;
	case 11001ULL: goto x86_l_2af9;
	case 11003ULL: goto x86_l_2afb;
	case 11007ULL: goto x86_l_2aff;
	case 11012ULL: goto x86_l_2b04;
	case 11017ULL: goto x86_l_2b09;
	case 11022ULL: goto x86_l_2b0e;
	case 11024ULL: goto x86_l_2b10;
	case 11028ULL: goto x86_l_2b14;
	case 11030ULL: goto x86_l_2b16;
	case 11036ULL: goto x86_l_2b1c;
	case 11041ULL: goto x86_l_2b21;
	case 11043ULL: goto x86_l_2b23;
	case 11049ULL: goto x86_l_2b29;
	case 11054ULL: goto x86_l_2b2e;
	case 11060ULL: goto x86_l_2b34;
	case 11063ULL: goto x86_l_2b37;
	case 11068ULL: goto x86_l_2b3c;
	case 11070ULL: goto x86_l_2b3e;
	case 11073ULL: goto x86_l_2b41;
	case 11079ULL: goto x86_l_2b47;
	case 11084ULL: goto x86_l_2b4c;
	case 11087ULL: goto x86_l_2b4f;
	case 11093ULL: goto x86_l_2b55;
	case 11098ULL: goto x86_l_2b5a;
	case 11100ULL: goto x86_l_2b5c;
	case 11105ULL: goto x86_l_2b61;
	case 11110ULL: goto x86_l_2b66;
	case 11112ULL: goto x86_l_2b68;
	case 11115ULL: goto x86_l_2b6b;
	case 11121ULL: goto x86_l_2b71;
	case 11126ULL: goto x86_l_2b76;
	case 11131ULL: goto x86_l_2b7b;
	case 11137ULL: goto x86_l_2b81;
	case 11142ULL: goto x86_l_2b86;
	case 11147ULL: goto x86_l_2b8b;
	case 11151ULL: goto x86_l_2b8f;
	case 11156ULL: goto x86_l_2b94;
	case 11161ULL: goto x86_l_2b99;
	case 11163ULL: goto x86_l_2b9b;
	case 11168ULL: goto x86_l_2ba0;
	case 11173ULL: goto x86_l_2ba5;
	case 11178ULL: goto x86_l_2baa;
	case 11183ULL: goto x86_l_2baf;
	case 11185ULL: goto x86_l_2bb1;
	case 11190ULL: goto x86_l_2bb6;
	case 11195ULL: goto x86_l_2bbb;
	case 11200ULL: goto x86_l_2bc0;
	case 11205ULL: goto x86_l_2bc5;
	case 11207ULL: goto x86_l_2bc7;
	case 11212ULL: goto x86_l_2bcc;
	case 11216ULL: goto x86_l_2bd0;
	case 11221ULL: goto x86_l_2bd5;
	case 11226ULL: goto x86_l_2bda;
	case 11231ULL: goto x86_l_2bdf;
	case 11236ULL: goto x86_l_2be4;
	case 11241ULL: goto x86_l_2be9;
	case 11243ULL: goto x86_l_2beb;
	case 11248ULL: goto x86_l_2bf0;
	case 11253ULL: goto x86_l_2bf5;
	case 11257ULL: goto x86_l_2bf9;
	case 11262ULL: goto x86_l_2bfe;
	case 11267ULL: goto x86_l_2c03;
	case 11272ULL: goto x86_l_2c08;
	case 11274ULL: goto x86_l_2c0a;
	case 11279ULL: goto x86_l_2c0f;
	case 11282ULL: goto x86_l_2c12;
	case 11284ULL: goto x86_l_2c14;
	case 11289ULL: goto x86_l_2c19;
	case 11292ULL: goto x86_l_2c1c;
	case 11294ULL: goto x86_l_2c1e;
	case 11298ULL: goto x86_l_2c22;
	case 11303ULL: goto x86_l_2c27;
	case 11308ULL: goto x86_l_2c2c;
	case 11313ULL: goto x86_l_2c31;
	case 11315ULL: goto x86_l_2c33;
	case 11319ULL: goto x86_l_2c37;
	case 11321ULL: goto x86_l_2c39;
	case 11327ULL: goto x86_l_2c3f;
	case 11332ULL: goto x86_l_2c44;
	case 11334ULL: goto x86_l_2c46;
	case 11340ULL: goto x86_l_2c4c;
	case 11345ULL: goto x86_l_2c51;
	case 11351ULL: goto x86_l_2c57;
	case 11354ULL: goto x86_l_2c5a;
	case 11359ULL: goto x86_l_2c5f;
	case 11361ULL: goto x86_l_2c61;
	case 11364ULL: goto x86_l_2c64;
	case 11370ULL: goto x86_l_2c6a;
	case 11375ULL: goto x86_l_2c6f;
	case 11378ULL: goto x86_l_2c72;
	case 11384ULL: goto x86_l_2c78;
	case 11389ULL: goto x86_l_2c7d;
	case 11391ULL: goto x86_l_2c7f;
	case 11396ULL: goto x86_l_2c84;
	case 11401ULL: goto x86_l_2c89;
	case 11403ULL: goto x86_l_2c8b;
	case 11406ULL: goto x86_l_2c8e;
	case 11412ULL: goto x86_l_2c94;
	case 11417ULL: goto x86_l_2c99;
	case 11422ULL: goto x86_l_2c9e;
	case 11428ULL: goto x86_l_2ca4;
	case 11433ULL: goto x86_l_2ca9;
	case 11438ULL: goto x86_l_2cae;
	case 11442ULL: goto x86_l_2cb2;
	case 11447ULL: goto x86_l_2cb7;
	case 11452ULL: goto x86_l_2cbc;
	case 11454ULL: goto x86_l_2cbe;
	case 11459ULL: goto x86_l_2cc3;
	case 11464ULL: goto x86_l_2cc8;
	case 11469ULL: goto x86_l_2ccd;
	case 11474ULL: goto x86_l_2cd2;
	case 11476ULL: goto x86_l_2cd4;
	case 11481ULL: goto x86_l_2cd9;
	case 11486ULL: goto x86_l_2cde;
	case 11491ULL: goto x86_l_2ce3;
	case 11496ULL: goto x86_l_2ce8;
	case 11498ULL: goto x86_l_2cea;
	case 11503ULL: goto x86_l_2cef;
	case 11507ULL: goto x86_l_2cf3;
	case 11512ULL: goto x86_l_2cf8;
	case 11517ULL: goto x86_l_2cfd;
	case 11522ULL: goto x86_l_2d02;
	case 11527ULL: goto x86_l_2d07;
	case 11532ULL: goto x86_l_2d0c;
	case 11534ULL: goto x86_l_2d0e;
	case 11539ULL: goto x86_l_2d13;
	case 11544ULL: goto x86_l_2d18;
	case 11548ULL: goto x86_l_2d1c;
	case 11553ULL: goto x86_l_2d21;
	case 11558ULL: goto x86_l_2d26;
	case 11563ULL: goto x86_l_2d2b;
	case 11565ULL: goto x86_l_2d2d;
	case 11570ULL: goto x86_l_2d32;
	case 11573ULL: goto x86_l_2d35;
	case 11575ULL: goto x86_l_2d37;
	case 11580ULL: goto x86_l_2d3c;
	case 11583ULL: goto x86_l_2d3f;
	case 11585ULL: goto x86_l_2d41;
	case 11589ULL: goto x86_l_2d45;
	case 11594ULL: goto x86_l_2d4a;
	case 11599ULL: goto x86_l_2d4f;
	case 11604ULL: goto x86_l_2d54;
	case 11606ULL: goto x86_l_2d56;
	case 11610ULL: goto x86_l_2d5a;
	case 11612ULL: goto x86_l_2d5c;
	case 11618ULL: goto x86_l_2d62;
	case 11623ULL: goto x86_l_2d67;
	case 11625ULL: goto x86_l_2d69;
	case 11631ULL: goto x86_l_2d6f;
	case 11636ULL: goto x86_l_2d74;
	case 11642ULL: goto x86_l_2d7a;
	case 11645ULL: goto x86_l_2d7d;
	case 11650ULL: goto x86_l_2d82;
	case 11652ULL: goto x86_l_2d84;
	case 11655ULL: goto x86_l_2d87;
	case 11661ULL: goto x86_l_2d8d;
	case 11666ULL: goto x86_l_2d92;
	case 11669ULL: goto x86_l_2d95;
	case 11675ULL: goto x86_l_2d9b;
	case 11680ULL: goto x86_l_2da0;
	case 11682ULL: goto x86_l_2da2;
	case 11687ULL: goto x86_l_2da7;
	case 11692ULL: goto x86_l_2dac;
	case 11694ULL: goto x86_l_2dae;
	case 11697ULL: goto x86_l_2db1;
	case 11703ULL: goto x86_l_2db7;
	case 11708ULL: goto x86_l_2dbc;
	case 11713ULL: goto x86_l_2dc1;
	case 11719ULL: goto x86_l_2dc7;
	case 11724ULL: goto x86_l_2dcc;
	case 11729ULL: goto x86_l_2dd1;
	case 11733ULL: goto x86_l_2dd5;
	case 11738ULL: goto x86_l_2dda;
	case 11743ULL: goto x86_l_2ddf;
	case 11745ULL: goto x86_l_2de1;
	case 11750ULL: goto x86_l_2de6;
	case 11755ULL: goto x86_l_2deb;
	case 11760ULL: goto x86_l_2df0;
	case 11765ULL: goto x86_l_2df5;
	case 11767ULL: goto x86_l_2df7;
	case 11772ULL: goto x86_l_2dfc;
	case 11777ULL: goto x86_l_2e01;
	case 11782ULL: goto x86_l_2e06;
	case 11787ULL: goto x86_l_2e0b;
	case 11789ULL: goto x86_l_2e0d;
	case 11794ULL: goto x86_l_2e12;
	case 11798ULL: goto x86_l_2e16;
	case 11803ULL: goto x86_l_2e1b;
	case 11808ULL: goto x86_l_2e20;
	case 11813ULL: goto x86_l_2e25;
	case 11818ULL: goto x86_l_2e2a;
	case 11823ULL: goto x86_l_2e2f;
	case 11825ULL: goto x86_l_2e31;
	case 11830ULL: goto x86_l_2e36;
	case 11835ULL: goto x86_l_2e3b;
	case 11839ULL: goto x86_l_2e3f;
	case 11844ULL: goto x86_l_2e44;
	case 11849ULL: goto x86_l_2e49;
	case 11854ULL: goto x86_l_2e4e;
	case 11856ULL: goto x86_l_2e50;
	case 11861ULL: goto x86_l_2e55;
	case 11864ULL: goto x86_l_2e58;
	case 11866ULL: goto x86_l_2e5a;
	case 11871ULL: goto x86_l_2e5f;
	case 11874ULL: goto x86_l_2e62;
	case 11876ULL: goto x86_l_2e64;
	case 11880ULL: goto x86_l_2e68;
	case 11885ULL: goto x86_l_2e6d;
	case 11890ULL: goto x86_l_2e72;
	case 11895ULL: goto x86_l_2e77;
	case 11897ULL: goto x86_l_2e79;
	case 11901ULL: goto x86_l_2e7d;
	case 11903ULL: goto x86_l_2e7f;
	case 11909ULL: goto x86_l_2e85;
	case 11914ULL: goto x86_l_2e8a;
	case 11916ULL: goto x86_l_2e8c;
	case 11922ULL: goto x86_l_2e92;
	case 11927ULL: goto x86_l_2e97;
	case 11933ULL: goto x86_l_2e9d;
	case 11936ULL: goto x86_l_2ea0;
	case 11941ULL: goto x86_l_2ea5;
	case 11943ULL: goto x86_l_2ea7;
	case 11946ULL: goto x86_l_2eaa;
	case 11952ULL: goto x86_l_2eb0;
	case 11957ULL: goto x86_l_2eb5;
	case 11960ULL: goto x86_l_2eb8;
	case 11966ULL: goto x86_l_2ebe;
	case 11971ULL: goto x86_l_2ec3;
	case 11973ULL: goto x86_l_2ec5;
	case 11978ULL: goto x86_l_2eca;
	case 11983ULL: goto x86_l_2ecf;
	case 11985ULL: goto x86_l_2ed1;
	case 11988ULL: goto x86_l_2ed4;
	case 11994ULL: goto x86_l_2eda;
	case 11999ULL: goto x86_l_2edf;
	case 12004ULL: goto x86_l_2ee4;
	case 12010ULL: goto x86_l_2eea;
	case 12015ULL: goto x86_l_2eef;
	case 12020ULL: goto x86_l_2ef4;
	case 12024ULL: goto x86_l_2ef8;
	case 12029ULL: goto x86_l_2efd;
	case 12034ULL: goto x86_l_2f02;
	case 12036ULL: goto x86_l_2f04;
	case 12041ULL: goto x86_l_2f09;
	case 12046ULL: goto x86_l_2f0e;
	case 12051ULL: goto x86_l_2f13;
	case 12056ULL: goto x86_l_2f18;
	case 12058ULL: goto x86_l_2f1a;
	case 12063ULL: goto x86_l_2f1f;
	case 12068ULL: goto x86_l_2f24;
	case 12073ULL: goto x86_l_2f29;
	case 12078ULL: goto x86_l_2f2e;
	case 12080ULL: goto x86_l_2f30;
	case 12085ULL: goto x86_l_2f35;
	case 12089ULL: goto x86_l_2f39;
	case 12094ULL: goto x86_l_2f3e;
	case 12099ULL: goto x86_l_2f43;
	case 12104ULL: goto x86_l_2f48;
	case 12109ULL: goto x86_l_2f4d;
	case 12114ULL: goto x86_l_2f52;
	case 12116ULL: goto x86_l_2f54;
	case 12121ULL: goto x86_l_2f59;
	case 12126ULL: goto x86_l_2f5e;
	case 12130ULL: goto x86_l_2f62;
	case 12135ULL: goto x86_l_2f67;
	case 12140ULL: goto x86_l_2f6c;
	case 12145ULL: goto x86_l_2f71;
	case 12147ULL: goto x86_l_2f73;
	case 12152ULL: goto x86_l_2f78;
	case 12155ULL: goto x86_l_2f7b;
	case 12157ULL: goto x86_l_2f7d;
	case 12162ULL: goto x86_l_2f82;
	case 12165ULL: goto x86_l_2f85;
	case 12167ULL: goto x86_l_2f87;
	case 12171ULL: goto x86_l_2f8b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2922:
	/* 0x2922: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2925:
	/* 0x2925: jne    162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5674ULL;
	}
x86_l_292b:
	/* 0x292b: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2930:
	/* 0x2930: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2935:
	/* 0x2935: je     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5674ULL;
	}
x86_l_293b:
	/* 0x293b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2940:
	/* 0x2940: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2945:
	/* 0x2945: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2949:
	/* 0x2949: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_294e:
	/* 0x294e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2953:
	/* 0x2953: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2955:
	/* 0x2955: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_295a:
	/* 0x295a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_295f:
	/* 0x295f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2964:
	/* 0x2964: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2969:
	/* 0x2969: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_296b:
	/* 0x296b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2970:
	/* 0x2970: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2975:
	/* 0x2975: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_297a:
	/* 0x297a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_297f:
	/* 0x297f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2981:
	/* 0x2981: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2986:
	/* 0x2986: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_298a:
	/* 0x298a: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_298f:
	/* 0x298f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2994:
	/* 0x2994: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2999:
	/* 0x2999: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_299e:
	/* 0x299e: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29a3:
	/* 0x29a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29a5:
	/* 0x29a5: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_29aa:
	/* 0x29aa: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29af:
	/* 0x29af: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_29b3:
	/* 0x29b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29b8:
	/* 0x29b8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_29bd:
	/* 0x29bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29c2:
	/* 0x29c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29c4:
	/* 0x29c4: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29c9:
	/* 0x29c9: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_29cc:
	/* 0x29cc: je     2a45 <trace_security_file_open+0x2a45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a45;
	}
x86_l_29ce:
	/* 0x29ce: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_29d3:
	/* 0x29d3: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_29d6:
	/* 0x29d6: je     2a45 <trace_security_file_open+0x2a45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a45;
	}
x86_l_29d8:
	/* 0x29d8: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_29dc:
	/* 0x29dc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29e1:
	/* 0x29e1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_29e6:
	/* 0x29e6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_29eb:
	/* 0x29eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29ed:
	/* 0x29ed: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_29f1:
	/* 0x29f1: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_29f3:
	/* 0x29f3: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_29f9:
	/* 0x29f9: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29fe:
	/* 0x29fe: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2a00:
	/* 0x2a00: jb     2693 <trace_security_file_open+0x2693> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9875ULL;
	}
x86_l_2a06:
	/* 0x2a06: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2a0b:
	/* 0x2a0b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2a11:
	/* 0x2a11: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a14:
	/* 0x2a14: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2a19:
	/* 0x2a19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a1b:
	/* 0x2a1b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a1e:
	/* 0x2a1e: jl     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5674ULL;
	}
x86_l_2a24:
	/* 0x2a24: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a29:
	/* 0x2a29: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2a2c:
	/* 0x2a2c: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2a32:
	/* 0x2a32: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2a37:
	/* 0x2a37: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2a39:
	/* 0x2a39: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a3e:
	/* 0x2a3e: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a43:
	/* 0x2a43: jmp    2ab2 <trace_security_file_open+0x2ab2> */
	goto x86_l_2ab2;
x86_l_2a45:
	/* 0x2a45: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2a48:
	/* 0x2a48: jne    162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5674ULL;
	}
x86_l_2a4e:
	/* 0x2a4e: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a53:
	/* 0x2a53: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2a58:
	/* 0x2a58: je     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5674ULL;
	}
x86_l_2a5e:
	/* 0x2a5e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a63:
	/* 0x2a63: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a68:
	/* 0x2a68: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2a6c:
	/* 0x2a6c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a71:
	/* 0x2a71: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a76:
	/* 0x2a76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a78:
	/* 0x2a78: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a7d:
	/* 0x2a7d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a82:
	/* 0x2a82: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a87:
	/* 0x2a87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a8c:
	/* 0x2a8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a8e:
	/* 0x2a8e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a93:
	/* 0x2a93: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a98:
	/* 0x2a98: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a9d:
	/* 0x2a9d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2aa2:
	/* 0x2aa2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aa4:
	/* 0x2aa4: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2aa9:
	/* 0x2aa9: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2aad:
	/* 0x2aad: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ab2:
	/* 0x2ab2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ab7:
	/* 0x2ab7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2abc:
	/* 0x2abc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ac1:
	/* 0x2ac1: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ac6:
	/* 0x2ac6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ac8:
	/* 0x2ac8: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2acd:
	/* 0x2acd: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ad2:
	/* 0x2ad2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2ad6:
	/* 0x2ad6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2adb:
	/* 0x2adb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ae0:
	/* 0x2ae0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ae5:
	/* 0x2ae5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae7:
	/* 0x2ae7: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2aec:
	/* 0x2aec: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2aef:
	/* 0x2aef: je     2b68 <trace_security_file_open+0x2b68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b68;
	}
x86_l_2af1:
	/* 0x2af1: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2af6:
	/* 0x2af6: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2af9:
	/* 0x2af9: je     2b68 <trace_security_file_open+0x2b68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b68;
	}
x86_l_2afb:
	/* 0x2afb: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2aff:
	/* 0x2aff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b04:
	/* 0x2b04: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b09:
	/* 0x2b09: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2b0e:
	/* 0x2b0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b10:
	/* 0x2b10: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2b14:
	/* 0x2b14: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2b16:
	/* 0x2b16: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b1c:
	/* 0x2b1c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b21:
	/* 0x2b21: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2b23:
	/* 0x2b23: jb     2693 <trace_security_file_open+0x2693> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9875ULL;
	}
x86_l_2b29:
	/* 0x2b29: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b2e:
	/* 0x2b2e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2b34:
	/* 0x2b34: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b37:
	/* 0x2b37: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2b3c:
	/* 0x2b3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b3e:
	/* 0x2b3e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2b41:
	/* 0x2b41: jl     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5674ULL;
	}
x86_l_2b47:
	/* 0x2b47: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b4c:
	/* 0x2b4c: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2b4f:
	/* 0x2b4f: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2b55:
	/* 0x2b55: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2b5a:
	/* 0x2b5a: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2b5c:
	/* 0x2b5c: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b61:
	/* 0x2b61: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b66:
	/* 0x2b66: jmp    2bd5 <trace_security_file_open+0x2bd5> */
	goto x86_l_2bd5;
x86_l_2b68:
	/* 0x2b68: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2b6b:
	/* 0x2b6b: jne    162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5674ULL;
	}
x86_l_2b71:
	/* 0x2b71: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b76:
	/* 0x2b76: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2b7b:
	/* 0x2b7b: je     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5674ULL;
	}
x86_l_2b81:
	/* 0x2b81: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b86:
	/* 0x2b86: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b8b:
	/* 0x2b8b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2b8f:
	/* 0x2b8f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b94:
	/* 0x2b94: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b99:
	/* 0x2b99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b9b:
	/* 0x2b9b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ba0:
	/* 0x2ba0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ba5:
	/* 0x2ba5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2baa:
	/* 0x2baa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2baf:
	/* 0x2baf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bb1:
	/* 0x2bb1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bb6:
	/* 0x2bb6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bbb:
	/* 0x2bbb: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2bc0:
	/* 0x2bc0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2bc5:
	/* 0x2bc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bc7:
	/* 0x2bc7: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bcc:
	/* 0x2bcc: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2bd0:
	/* 0x2bd0: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2bd5:
	/* 0x2bd5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bda:
	/* 0x2bda: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2bdf:
	/* 0x2bdf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2be4:
	/* 0x2be4: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2be9:
	/* 0x2be9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2beb:
	/* 0x2beb: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2bf0:
	/* 0x2bf0: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2bf5:
	/* 0x2bf5: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2bf9:
	/* 0x2bf9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bfe:
	/* 0x2bfe: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c03:
	/* 0x2c03: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c08:
	/* 0x2c08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c0a:
	/* 0x2c0a: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c0f:
	/* 0x2c0f: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2c12:
	/* 0x2c12: je     2c8b <trace_security_file_open+0x2c8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c8b;
	}
x86_l_2c14:
	/* 0x2c14: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c19:
	/* 0x2c19: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2c1c:
	/* 0x2c1c: je     2c8b <trace_security_file_open+0x2c8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c8b;
	}
x86_l_2c1e:
	/* 0x2c1e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2c22:
	/* 0x2c22: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c27:
	/* 0x2c27: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c2c:
	/* 0x2c2c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2c31:
	/* 0x2c31: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c33:
	/* 0x2c33: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2c37:
	/* 0x2c37: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2c39:
	/* 0x2c39: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2c3f:
	/* 0x2c3f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c44:
	/* 0x2c44: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c46:
	/* 0x2c46: jb     2693 <trace_security_file_open+0x2693> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9875ULL;
	}
x86_l_2c4c:
	/* 0x2c4c: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2c51:
	/* 0x2c51: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2c57:
	/* 0x2c57: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c5a:
	/* 0x2c5a: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2c5f:
	/* 0x2c5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c61:
	/* 0x2c61: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c64:
	/* 0x2c64: jl     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5674ULL;
	}
x86_l_2c6a:
	/* 0x2c6a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c6f:
	/* 0x2c6f: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2c72:
	/* 0x2c72: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2c78:
	/* 0x2c78: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2c7d:
	/* 0x2c7d: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c7f:
	/* 0x2c7f: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c84:
	/* 0x2c84: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c89:
	/* 0x2c89: jmp    2cf8 <trace_security_file_open+0x2cf8> */
	goto x86_l_2cf8;
x86_l_2c8b:
	/* 0x2c8b: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2c8e:
	/* 0x2c8e: jne    162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5674ULL;
	}
x86_l_2c94:
	/* 0x2c94: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c99:
	/* 0x2c99: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2c9e:
	/* 0x2c9e: je     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5674ULL;
	}
x86_l_2ca4:
	/* 0x2ca4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ca9:
	/* 0x2ca9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cae:
	/* 0x2cae: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2cb2:
	/* 0x2cb2: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2cb7:
	/* 0x2cb7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cbc:
	/* 0x2cbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cbe:
	/* 0x2cbe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cc3:
	/* 0x2cc3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cc8:
	/* 0x2cc8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ccd:
	/* 0x2ccd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cd2:
	/* 0x2cd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cd4:
	/* 0x2cd4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cd9:
	/* 0x2cd9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cde:
	/* 0x2cde: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ce3:
	/* 0x2ce3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ce8:
	/* 0x2ce8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cea:
	/* 0x2cea: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cef:
	/* 0x2cef: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2cf3:
	/* 0x2cf3: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2cf8:
	/* 0x2cf8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cfd:
	/* 0x2cfd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d02:
	/* 0x2d02: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d07:
	/* 0x2d07: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d0c:
	/* 0x2d0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d0e:
	/* 0x2d0e: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d13:
	/* 0x2d13: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d18:
	/* 0x2d18: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d1c:
	/* 0x2d1c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d21:
	/* 0x2d21: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d26:
	/* 0x2d26: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d2b:
	/* 0x2d2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d2d:
	/* 0x2d2d: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d32:
	/* 0x2d32: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2d35:
	/* 0x2d35: je     2dae <trace_security_file_open+0x2dae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dae;
	}
x86_l_2d37:
	/* 0x2d37: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d3c:
	/* 0x2d3c: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2d3f:
	/* 0x2d3f: je     2dae <trace_security_file_open+0x2dae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dae;
	}
x86_l_2d41:
	/* 0x2d41: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2d45:
	/* 0x2d45: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d4a:
	/* 0x2d4a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d4f:
	/* 0x2d4f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2d54:
	/* 0x2d54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d56:
	/* 0x2d56: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2d5a:
	/* 0x2d5a: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2d5c:
	/* 0x2d5c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2d62:
	/* 0x2d62: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d67:
	/* 0x2d67: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d69:
	/* 0x2d69: jb     2693 <trace_security_file_open+0x2693> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9875ULL;
	}
x86_l_2d6f:
	/* 0x2d6f: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2d74:
	/* 0x2d74: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2d7a:
	/* 0x2d7a: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d7d:
	/* 0x2d7d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2d82:
	/* 0x2d82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d84:
	/* 0x2d84: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d87:
	/* 0x2d87: jl     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5674ULL;
	}
x86_l_2d8d:
	/* 0x2d8d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d92:
	/* 0x2d92: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2d95:
	/* 0x2d95: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2d9b:
	/* 0x2d9b: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2da0:
	/* 0x2da0: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2da2:
	/* 0x2da2: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2da7:
	/* 0x2da7: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2dac:
	/* 0x2dac: jmp    2e1b <trace_security_file_open+0x2e1b> */
	goto x86_l_2e1b;
x86_l_2dae:
	/* 0x2dae: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2db1:
	/* 0x2db1: jne    162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5674ULL;
	}
x86_l_2db7:
	/* 0x2db7: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dbc:
	/* 0x2dbc: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2dc1:
	/* 0x2dc1: je     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5674ULL;
	}
x86_l_2dc7:
	/* 0x2dc7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2dcc:
	/* 0x2dcc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dd1:
	/* 0x2dd1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2dd5:
	/* 0x2dd5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2dda:
	/* 0x2dda: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ddf:
	/* 0x2ddf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2de1:
	/* 0x2de1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2de6:
	/* 0x2de6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2deb:
	/* 0x2deb: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2df0:
	/* 0x2df0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2df5:
	/* 0x2df5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2df7:
	/* 0x2df7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2dfc:
	/* 0x2dfc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e01:
	/* 0x2e01: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e06:
	/* 0x2e06: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e0b:
	/* 0x2e0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e0d:
	/* 0x2e0d: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e12:
	/* 0x2e12: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2e16:
	/* 0x2e16: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e1b:
	/* 0x2e1b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e20:
	/* 0x2e20: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e25:
	/* 0x2e25: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e2a:
	/* 0x2e2a: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e2f:
	/* 0x2e2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e31:
	/* 0x2e31: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e36:
	/* 0x2e36: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e3b:
	/* 0x2e3b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2e3f:
	/* 0x2e3f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e44:
	/* 0x2e44: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e49:
	/* 0x2e49: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e4e:
	/* 0x2e4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e50:
	/* 0x2e50: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e55:
	/* 0x2e55: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2e58:
	/* 0x2e58: je     2ed1 <trace_security_file_open+0x2ed1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ed1;
	}
x86_l_2e5a:
	/* 0x2e5a: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e5f:
	/* 0x2e5f: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2e62:
	/* 0x2e62: je     2ed1 <trace_security_file_open+0x2ed1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ed1;
	}
x86_l_2e64:
	/* 0x2e64: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2e68:
	/* 0x2e68: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e6d:
	/* 0x2e6d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e72:
	/* 0x2e72: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2e77:
	/* 0x2e77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e79:
	/* 0x2e79: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2e7d:
	/* 0x2e7d: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2e7f:
	/* 0x2e7f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2e85:
	/* 0x2e85: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e8a:
	/* 0x2e8a: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e8c:
	/* 0x2e8c: jb     2693 <trace_security_file_open+0x2693> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9875ULL;
	}
x86_l_2e92:
	/* 0x2e92: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e97:
	/* 0x2e97: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2e9d:
	/* 0x2e9d: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ea0:
	/* 0x2ea0: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2ea5:
	/* 0x2ea5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ea7:
	/* 0x2ea7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2eaa:
	/* 0x2eaa: jl     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5674ULL;
	}
x86_l_2eb0:
	/* 0x2eb0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2eb5:
	/* 0x2eb5: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2eb8:
	/* 0x2eb8: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2ebe:
	/* 0x2ebe: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2ec3:
	/* 0x2ec3: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2ec5:
	/* 0x2ec5: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2eca:
	/* 0x2eca: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ecf:
	/* 0x2ecf: jmp    2f3e <trace_security_file_open+0x2f3e> */
	goto x86_l_2f3e;
x86_l_2ed1:
	/* 0x2ed1: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2ed4:
	/* 0x2ed4: jne    162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5674ULL;
	}
x86_l_2eda:
	/* 0x2eda: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2edf:
	/* 0x2edf: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_2ee4:
	/* 0x2ee4: je     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5674ULL;
	}
x86_l_2eea:
	/* 0x2eea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2eef:
	/* 0x2eef: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ef4:
	/* 0x2ef4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2ef8:
	/* 0x2ef8: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2efd:
	/* 0x2efd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f02:
	/* 0x2f02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f04:
	/* 0x2f04: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f09:
	/* 0x2f09: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f0e:
	/* 0x2f0e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f13:
	/* 0x2f13: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f18:
	/* 0x2f18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f1a:
	/* 0x2f1a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f1f:
	/* 0x2f1f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f24:
	/* 0x2f24: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f29:
	/* 0x2f29: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f2e:
	/* 0x2f2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f30:
	/* 0x2f30: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f35:
	/* 0x2f35: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2f39:
	/* 0x2f39: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f3e:
	/* 0x2f3e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f43:
	/* 0x2f43: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f48:
	/* 0x2f48: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f4d:
	/* 0x2f4d: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f52:
	/* 0x2f52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f54:
	/* 0x2f54: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f59:
	/* 0x2f59: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f5e:
	/* 0x2f5e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f62:
	/* 0x2f62: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f67:
	/* 0x2f67: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f6c:
	/* 0x2f6c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f71:
	/* 0x2f71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f73:
	/* 0x2f73: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f78:
	/* 0x2f78: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2f7b:
	/* 0x2f7b: je     2ff4 <trace_security_file_open+0x2ff4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12276ULL;
	}
x86_l_2f7d:
	/* 0x2f7d: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f82:
	/* 0x2f82: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2f85:
	/* 0x2f85: je     2ff4 <trace_security_file_open+0x2ff4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12276ULL;
	}
x86_l_2f87:
	/* 0x2f87: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2f8b:
	/* 0x2f8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
	return 12176ULL;
}

static __noinline __u64 tracee_trace_security_file_open_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12176ULL: goto x86_l_2f90;
	case 12181ULL: goto x86_l_2f95;
	case 12186ULL: goto x86_l_2f9a;
	case 12188ULL: goto x86_l_2f9c;
	case 12192ULL: goto x86_l_2fa0;
	case 12194ULL: goto x86_l_2fa2;
	case 12200ULL: goto x86_l_2fa8;
	case 12205ULL: goto x86_l_2fad;
	case 12207ULL: goto x86_l_2faf;
	case 12213ULL: goto x86_l_2fb5;
	case 12218ULL: goto x86_l_2fba;
	case 12224ULL: goto x86_l_2fc0;
	case 12227ULL: goto x86_l_2fc3;
	case 12232ULL: goto x86_l_2fc8;
	case 12234ULL: goto x86_l_2fca;
	case 12237ULL: goto x86_l_2fcd;
	case 12243ULL: goto x86_l_2fd3;
	case 12248ULL: goto x86_l_2fd8;
	case 12251ULL: goto x86_l_2fdb;
	case 12257ULL: goto x86_l_2fe1;
	case 12262ULL: goto x86_l_2fe6;
	case 12264ULL: goto x86_l_2fe8;
	case 12269ULL: goto x86_l_2fed;
	case 12274ULL: goto x86_l_2ff2;
	case 12276ULL: goto x86_l_2ff4;
	case 12279ULL: goto x86_l_2ff7;
	case 12285ULL: goto x86_l_2ffd;
	case 12290ULL: goto x86_l_3002;
	case 12295ULL: goto x86_l_3007;
	case 12301ULL: goto x86_l_300d;
	case 12306ULL: goto x86_l_3012;
	case 12311ULL: goto x86_l_3017;
	case 12315ULL: goto x86_l_301b;
	case 12320ULL: goto x86_l_3020;
	case 12325ULL: goto x86_l_3025;
	case 12327ULL: goto x86_l_3027;
	case 12332ULL: goto x86_l_302c;
	case 12337ULL: goto x86_l_3031;
	case 12342ULL: goto x86_l_3036;
	case 12347ULL: goto x86_l_303b;
	case 12349ULL: goto x86_l_303d;
	case 12354ULL: goto x86_l_3042;
	case 12359ULL: goto x86_l_3047;
	case 12364ULL: goto x86_l_304c;
	case 12369ULL: goto x86_l_3051;
	case 12371ULL: goto x86_l_3053;
	case 12376ULL: goto x86_l_3058;
	case 12380ULL: goto x86_l_305c;
	case 12385ULL: goto x86_l_3061;
	case 12390ULL: goto x86_l_3066;
	case 12395ULL: goto x86_l_306b;
	case 12400ULL: goto x86_l_3070;
	case 12405ULL: goto x86_l_3075;
	case 12407ULL: goto x86_l_3077;
	case 12412ULL: goto x86_l_307c;
	case 12417ULL: goto x86_l_3081;
	case 12421ULL: goto x86_l_3085;
	case 12426ULL: goto x86_l_308a;
	case 12431ULL: goto x86_l_308f;
	case 12436ULL: goto x86_l_3094;
	case 12438ULL: goto x86_l_3096;
	case 12443ULL: goto x86_l_309b;
	case 12446ULL: goto x86_l_309e;
	case 12448ULL: goto x86_l_30a0;
	case 12453ULL: goto x86_l_30a5;
	case 12456ULL: goto x86_l_30a8;
	case 12458ULL: goto x86_l_30aa;
	case 12462ULL: goto x86_l_30ae;
	case 12467ULL: goto x86_l_30b3;
	case 12472ULL: goto x86_l_30b8;
	case 12477ULL: goto x86_l_30bd;
	case 12479ULL: goto x86_l_30bf;
	case 12483ULL: goto x86_l_30c3;
	case 12485ULL: goto x86_l_30c5;
	case 12491ULL: goto x86_l_30cb;
	case 12496ULL: goto x86_l_30d0;
	case 12498ULL: goto x86_l_30d2;
	case 12504ULL: goto x86_l_30d8;
	case 12509ULL: goto x86_l_30dd;
	case 12515ULL: goto x86_l_30e3;
	case 12518ULL: goto x86_l_30e6;
	case 12523ULL: goto x86_l_30eb;
	case 12525ULL: goto x86_l_30ed;
	case 12528ULL: goto x86_l_30f0;
	case 12534ULL: goto x86_l_30f6;
	case 12539ULL: goto x86_l_30fb;
	case 12542ULL: goto x86_l_30fe;
	case 12548ULL: goto x86_l_3104;
	case 12553ULL: goto x86_l_3109;
	case 12555ULL: goto x86_l_310b;
	case 12560ULL: goto x86_l_3110;
	case 12565ULL: goto x86_l_3115;
	case 12567ULL: goto x86_l_3117;
	case 12570ULL: goto x86_l_311a;
	case 12576ULL: goto x86_l_3120;
	case 12581ULL: goto x86_l_3125;
	case 12586ULL: goto x86_l_312a;
	case 12592ULL: goto x86_l_3130;
	case 12597ULL: goto x86_l_3135;
	case 12602ULL: goto x86_l_313a;
	case 12606ULL: goto x86_l_313e;
	case 12611ULL: goto x86_l_3143;
	case 12616ULL: goto x86_l_3148;
	case 12618ULL: goto x86_l_314a;
	case 12623ULL: goto x86_l_314f;
	case 12628ULL: goto x86_l_3154;
	case 12633ULL: goto x86_l_3159;
	case 12638ULL: goto x86_l_315e;
	case 12640ULL: goto x86_l_3160;
	case 12645ULL: goto x86_l_3165;
	case 12650ULL: goto x86_l_316a;
	case 12655ULL: goto x86_l_316f;
	case 12660ULL: goto x86_l_3174;
	case 12662ULL: goto x86_l_3176;
	case 12667ULL: goto x86_l_317b;
	case 12671ULL: goto x86_l_317f;
	case 12676ULL: goto x86_l_3184;
	case 12681ULL: goto x86_l_3189;
	case 12686ULL: goto x86_l_318e;
	case 12691ULL: goto x86_l_3193;
	case 12696ULL: goto x86_l_3198;
	case 12698ULL: goto x86_l_319a;
	case 12703ULL: goto x86_l_319f;
	case 12708ULL: goto x86_l_31a4;
	case 12712ULL: goto x86_l_31a8;
	case 12717ULL: goto x86_l_31ad;
	case 12722ULL: goto x86_l_31b2;
	case 12727ULL: goto x86_l_31b7;
	case 12729ULL: goto x86_l_31b9;
	case 12734ULL: goto x86_l_31be;
	case 12737ULL: goto x86_l_31c1;
	case 12739ULL: goto x86_l_31c3;
	case 12744ULL: goto x86_l_31c8;
	case 12747ULL: goto x86_l_31cb;
	case 12749ULL: goto x86_l_31cd;
	case 12753ULL: goto x86_l_31d1;
	case 12758ULL: goto x86_l_31d6;
	case 12763ULL: goto x86_l_31db;
	case 12768ULL: goto x86_l_31e0;
	case 12770ULL: goto x86_l_31e2;
	case 12774ULL: goto x86_l_31e6;
	case 12776ULL: goto x86_l_31e8;
	case 12782ULL: goto x86_l_31ee;
	case 12787ULL: goto x86_l_31f3;
	case 12789ULL: goto x86_l_31f5;
	case 12795ULL: goto x86_l_31fb;
	case 12800ULL: goto x86_l_3200;
	case 12806ULL: goto x86_l_3206;
	case 12809ULL: goto x86_l_3209;
	case 12814ULL: goto x86_l_320e;
	case 12816ULL: goto x86_l_3210;
	case 12819ULL: goto x86_l_3213;
	case 12825ULL: goto x86_l_3219;
	case 12830ULL: goto x86_l_321e;
	case 12833ULL: goto x86_l_3221;
	case 12839ULL: goto x86_l_3227;
	case 12844ULL: goto x86_l_322c;
	case 12846ULL: goto x86_l_322e;
	case 12851ULL: goto x86_l_3233;
	case 12856ULL: goto x86_l_3238;
	case 12858ULL: goto x86_l_323a;
	case 12861ULL: goto x86_l_323d;
	case 12867ULL: goto x86_l_3243;
	case 12872ULL: goto x86_l_3248;
	case 12877ULL: goto x86_l_324d;
	case 12883ULL: goto x86_l_3253;
	case 12888ULL: goto x86_l_3258;
	case 12893ULL: goto x86_l_325d;
	case 12897ULL: goto x86_l_3261;
	case 12902ULL: goto x86_l_3266;
	case 12907ULL: goto x86_l_326b;
	case 12909ULL: goto x86_l_326d;
	case 12914ULL: goto x86_l_3272;
	case 12919ULL: goto x86_l_3277;
	case 12924ULL: goto x86_l_327c;
	case 12929ULL: goto x86_l_3281;
	case 12931ULL: goto x86_l_3283;
	case 12936ULL: goto x86_l_3288;
	case 12941ULL: goto x86_l_328d;
	case 12946ULL: goto x86_l_3292;
	case 12951ULL: goto x86_l_3297;
	case 12953ULL: goto x86_l_3299;
	case 12958ULL: goto x86_l_329e;
	case 12962ULL: goto x86_l_32a2;
	case 12967ULL: goto x86_l_32a7;
	case 12972ULL: goto x86_l_32ac;
	case 12977ULL: goto x86_l_32b1;
	case 12982ULL: goto x86_l_32b6;
	case 12987ULL: goto x86_l_32bb;
	case 12989ULL: goto x86_l_32bd;
	case 12994ULL: goto x86_l_32c2;
	case 12999ULL: goto x86_l_32c7;
	case 13003ULL: goto x86_l_32cb;
	case 13008ULL: goto x86_l_32d0;
	case 13013ULL: goto x86_l_32d5;
	case 13018ULL: goto x86_l_32da;
	case 13020ULL: goto x86_l_32dc;
	case 13025ULL: goto x86_l_32e1;
	case 13028ULL: goto x86_l_32e4;
	case 13030ULL: goto x86_l_32e6;
	case 13035ULL: goto x86_l_32eb;
	case 13038ULL: goto x86_l_32ee;
	case 13040ULL: goto x86_l_32f0;
	case 13044ULL: goto x86_l_32f4;
	case 13049ULL: goto x86_l_32f9;
	case 13054ULL: goto x86_l_32fe;
	case 13059ULL: goto x86_l_3303;
	case 13061ULL: goto x86_l_3305;
	case 13065ULL: goto x86_l_3309;
	case 13067ULL: goto x86_l_330b;
	case 13073ULL: goto x86_l_3311;
	case 13078ULL: goto x86_l_3316;
	case 13080ULL: goto x86_l_3318;
	case 13086ULL: goto x86_l_331e;
	case 13091ULL: goto x86_l_3323;
	case 13097ULL: goto x86_l_3329;
	case 13100ULL: goto x86_l_332c;
	case 13105ULL: goto x86_l_3331;
	case 13107ULL: goto x86_l_3333;
	case 13110ULL: goto x86_l_3336;
	case 13116ULL: goto x86_l_333c;
	case 13121ULL: goto x86_l_3341;
	case 13124ULL: goto x86_l_3344;
	case 13130ULL: goto x86_l_334a;
	case 13135ULL: goto x86_l_334f;
	case 13137ULL: goto x86_l_3351;
	case 13142ULL: goto x86_l_3356;
	case 13147ULL: goto x86_l_335b;
	case 13149ULL: goto x86_l_335d;
	case 13152ULL: goto x86_l_3360;
	case 13158ULL: goto x86_l_3366;
	case 13163ULL: goto x86_l_336b;
	case 13168ULL: goto x86_l_3370;
	case 13174ULL: goto x86_l_3376;
	case 13179ULL: goto x86_l_337b;
	case 13184ULL: goto x86_l_3380;
	case 13188ULL: goto x86_l_3384;
	case 13193ULL: goto x86_l_3389;
	case 13198ULL: goto x86_l_338e;
	case 13200ULL: goto x86_l_3390;
	case 13205ULL: goto x86_l_3395;
	case 13210ULL: goto x86_l_339a;
	case 13215ULL: goto x86_l_339f;
	case 13220ULL: goto x86_l_33a4;
	case 13222ULL: goto x86_l_33a6;
	case 13227ULL: goto x86_l_33ab;
	case 13232ULL: goto x86_l_33b0;
	case 13237ULL: goto x86_l_33b5;
	case 13242ULL: goto x86_l_33ba;
	case 13244ULL: goto x86_l_33bc;
	case 13249ULL: goto x86_l_33c1;
	case 13253ULL: goto x86_l_33c5;
	case 13258ULL: goto x86_l_33ca;
	case 13263ULL: goto x86_l_33cf;
	case 13268ULL: goto x86_l_33d4;
	case 13273ULL: goto x86_l_33d9;
	case 13278ULL: goto x86_l_33de;
	case 13280ULL: goto x86_l_33e0;
	case 13285ULL: goto x86_l_33e5;
	case 13290ULL: goto x86_l_33ea;
	case 13294ULL: goto x86_l_33ee;
	case 13299ULL: goto x86_l_33f3;
	case 13304ULL: goto x86_l_33f8;
	case 13309ULL: goto x86_l_33fd;
	case 13311ULL: goto x86_l_33ff;
	case 13316ULL: goto x86_l_3404;
	case 13319ULL: goto x86_l_3407;
	case 13321ULL: goto x86_l_3409;
	case 13326ULL: goto x86_l_340e;
	case 13329ULL: goto x86_l_3411;
	case 13331ULL: goto x86_l_3413;
	case 13335ULL: goto x86_l_3417;
	case 13340ULL: goto x86_l_341c;
	case 13345ULL: goto x86_l_3421;
	case 13350ULL: goto x86_l_3426;
	case 13352ULL: goto x86_l_3428;
	case 13356ULL: goto x86_l_342c;
	case 13358ULL: goto x86_l_342e;
	case 13364ULL: goto x86_l_3434;
	case 13369ULL: goto x86_l_3439;
	case 13371ULL: goto x86_l_343b;
	case 13377ULL: goto x86_l_3441;
	case 13382ULL: goto x86_l_3446;
	case 13388ULL: goto x86_l_344c;
	case 13391ULL: goto x86_l_344f;
	case 13396ULL: goto x86_l_3454;
	case 13398ULL: goto x86_l_3456;
	case 13401ULL: goto x86_l_3459;
	case 13407ULL: goto x86_l_345f;
	case 13412ULL: goto x86_l_3464;
	case 13415ULL: goto x86_l_3467;
	case 13421ULL: goto x86_l_346d;
	case 13426ULL: goto x86_l_3472;
	case 13428ULL: goto x86_l_3474;
	case 13433ULL: goto x86_l_3479;
	case 13438ULL: goto x86_l_347e;
	case 13440ULL: goto x86_l_3480;
	case 13443ULL: goto x86_l_3483;
	case 13449ULL: goto x86_l_3489;
	case 13454ULL: goto x86_l_348e;
	case 13459ULL: goto x86_l_3493;
	case 13465ULL: goto x86_l_3499;
	case 13470ULL: goto x86_l_349e;
	case 13475ULL: goto x86_l_34a3;
	case 13479ULL: goto x86_l_34a7;
	case 13484ULL: goto x86_l_34ac;
	case 13489ULL: goto x86_l_34b1;
	case 13491ULL: goto x86_l_34b3;
	case 13496ULL: goto x86_l_34b8;
	case 13501ULL: goto x86_l_34bd;
	case 13506ULL: goto x86_l_34c2;
	case 13511ULL: goto x86_l_34c7;
	case 13513ULL: goto x86_l_34c9;
	case 13518ULL: goto x86_l_34ce;
	case 13523ULL: goto x86_l_34d3;
	case 13528ULL: goto x86_l_34d8;
	case 13533ULL: goto x86_l_34dd;
	case 13535ULL: goto x86_l_34df;
	case 13540ULL: goto x86_l_34e4;
	case 13544ULL: goto x86_l_34e8;
	case 13549ULL: goto x86_l_34ed;
	case 13554ULL: goto x86_l_34f2;
	case 13559ULL: goto x86_l_34f7;
	case 13564ULL: goto x86_l_34fc;
	case 13569ULL: goto x86_l_3501;
	case 13571ULL: goto x86_l_3503;
	case 13576ULL: goto x86_l_3508;
	case 13581ULL: goto x86_l_350d;
	case 13585ULL: goto x86_l_3511;
	case 13590ULL: goto x86_l_3516;
	case 13595ULL: goto x86_l_351b;
	case 13600ULL: goto x86_l_3520;
	case 13602ULL: goto x86_l_3522;
	case 13607ULL: goto x86_l_3527;
	case 13610ULL: goto x86_l_352a;
	case 13612ULL: goto x86_l_352c;
	case 13617ULL: goto x86_l_3531;
	case 13620ULL: goto x86_l_3534;
	case 13622ULL: goto x86_l_3536;
	case 13626ULL: goto x86_l_353a;
	case 13631ULL: goto x86_l_353f;
	case 13636ULL: goto x86_l_3544;
	case 13641ULL: goto x86_l_3549;
	case 13643ULL: goto x86_l_354b;
	case 13647ULL: goto x86_l_354f;
	case 13649ULL: goto x86_l_3551;
	case 13655ULL: goto x86_l_3557;
	case 13660ULL: goto x86_l_355c;
	case 13662ULL: goto x86_l_355e;
	case 13668ULL: goto x86_l_3564;
	case 13673ULL: goto x86_l_3569;
	case 13679ULL: goto x86_l_356f;
	case 13682ULL: goto x86_l_3572;
	case 13687ULL: goto x86_l_3577;
	case 13689ULL: goto x86_l_3579;
	case 13692ULL: goto x86_l_357c;
	case 13698ULL: goto x86_l_3582;
	case 13703ULL: goto x86_l_3587;
	case 13708ULL: goto x86_l_358c;
	case 13714ULL: goto x86_l_3592;
	case 13719ULL: goto x86_l_3597;
	case 13722ULL: goto x86_l_359a;
	case 13727ULL: goto x86_l_359f;
	case 13732ULL: goto x86_l_35a4;
	case 13735ULL: goto x86_l_35a7;
	case 13741ULL: goto x86_l_35ad;
	case 13746ULL: goto x86_l_35b2;
	case 13751ULL: goto x86_l_35b7;
	case 13757ULL: goto x86_l_35bd;
	case 13762ULL: goto x86_l_35c2;
	case 13767ULL: goto x86_l_35c7;
	case 13771ULL: goto x86_l_35cb;
	case 13776ULL: goto x86_l_35d0;
	case 13781ULL: goto x86_l_35d5;
	case 13783ULL: goto x86_l_35d7;
	case 13788ULL: goto x86_l_35dc;
	case 13793ULL: goto x86_l_35e1;
	case 13798ULL: goto x86_l_35e6;
	case 13803ULL: goto x86_l_35eb;
	case 13805ULL: goto x86_l_35ed;
	case 13810ULL: goto x86_l_35f2;
	case 13815ULL: goto x86_l_35f7;
	case 13820ULL: goto x86_l_35fc;
	case 13825ULL: goto x86_l_3601;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2f90:
	/* 0x2f90: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f95:
	/* 0x2f95: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2f9a:
	/* 0x2f9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f9c:
	/* 0x2f9c: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2fa0:
	/* 0x2fa0: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2fa2:
	/* 0x2fa2: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2fa8:
	/* 0x2fa8: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fad:
	/* 0x2fad: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2faf:
	/* 0x2faf: jb     2693 <trace_security_file_open+0x2693> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9875ULL;
	}
x86_l_2fb5:
	/* 0x2fb5: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2fba:
	/* 0x2fba: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2fc0:
	/* 0x2fc0: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2fc3:
	/* 0x2fc3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2fc8:
	/* 0x2fc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fca:
	/* 0x2fca: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2fcd:
	/* 0x2fcd: jl     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5674ULL;
	}
x86_l_2fd3:
	/* 0x2fd3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fd8:
	/* 0x2fd8: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2fdb:
	/* 0x2fdb: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2fe1:
	/* 0x2fe1: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2fe6:
	/* 0x2fe6: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2fe8:
	/* 0x2fe8: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fed:
	/* 0x2fed: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ff2:
	/* 0x2ff2: jmp    3061 <trace_security_file_open+0x3061> */
	goto x86_l_3061;
x86_l_2ff4:
	/* 0x2ff4: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2ff7:
	/* 0x2ff7: jne    162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5674ULL;
	}
x86_l_2ffd:
	/* 0x2ffd: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3002:
	/* 0x3002: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_3007:
	/* 0x3007: je     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5674ULL;
	}
x86_l_300d:
	/* 0x300d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3012:
	/* 0x3012: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3017:
	/* 0x3017: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_301b:
	/* 0x301b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3020:
	/* 0x3020: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3025:
	/* 0x3025: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3027:
	/* 0x3027: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_302c:
	/* 0x302c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3031:
	/* 0x3031: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3036:
	/* 0x3036: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_303b:
	/* 0x303b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_303d:
	/* 0x303d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3042:
	/* 0x3042: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3047:
	/* 0x3047: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_304c:
	/* 0x304c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3051:
	/* 0x3051: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3053:
	/* 0x3053: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3058:
	/* 0x3058: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_305c:
	/* 0x305c: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3061:
	/* 0x3061: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3066:
	/* 0x3066: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_306b:
	/* 0x306b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3070:
	/* 0x3070: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3075:
	/* 0x3075: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3077:
	/* 0x3077: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_307c:
	/* 0x307c: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3081:
	/* 0x3081: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3085:
	/* 0x3085: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_308a:
	/* 0x308a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_308f:
	/* 0x308f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3094:
	/* 0x3094: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3096:
	/* 0x3096: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_309b:
	/* 0x309b: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_309e:
	/* 0x309e: je     3117 <trace_security_file_open+0x3117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3117;
	}
x86_l_30a0:
	/* 0x30a0: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30a5:
	/* 0x30a5: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_30a8:
	/* 0x30a8: je     3117 <trace_security_file_open+0x3117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3117;
	}
x86_l_30aa:
	/* 0x30aa: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_30ae:
	/* 0x30ae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30b3:
	/* 0x30b3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_30b8:
	/* 0x30b8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_30bd:
	/* 0x30bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30bf:
	/* 0x30bf: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_30c3:
	/* 0x30c3: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_30c5:
	/* 0x30c5: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_30cb:
	/* 0x30cb: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30d0:
	/* 0x30d0: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_30d2:
	/* 0x30d2: jb     2693 <trace_security_file_open+0x2693> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9875ULL;
	}
x86_l_30d8:
	/* 0x30d8: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_30dd:
	/* 0x30dd: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_30e3:
	/* 0x30e3: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_30e6:
	/* 0x30e6: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_30eb:
	/* 0x30eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30ed:
	/* 0x30ed: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_30f0:
	/* 0x30f0: jl     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5674ULL;
	}
x86_l_30f6:
	/* 0x30f6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30fb:
	/* 0x30fb: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_30fe:
	/* 0x30fe: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3104:
	/* 0x3104: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3109:
	/* 0x3109: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_310b:
	/* 0x310b: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3110:
	/* 0x3110: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3115:
	/* 0x3115: jmp    3184 <trace_security_file_open+0x3184> */
	goto x86_l_3184;
x86_l_3117:
	/* 0x3117: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_311a:
	/* 0x311a: jne    162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5674ULL;
	}
x86_l_3120:
	/* 0x3120: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3125:
	/* 0x3125: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_312a:
	/* 0x312a: je     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5674ULL;
	}
x86_l_3130:
	/* 0x3130: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3135:
	/* 0x3135: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_313a:
	/* 0x313a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_313e:
	/* 0x313e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3143:
	/* 0x3143: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3148:
	/* 0x3148: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_314a:
	/* 0x314a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_314f:
	/* 0x314f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3154:
	/* 0x3154: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3159:
	/* 0x3159: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_315e:
	/* 0x315e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3160:
	/* 0x3160: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3165:
	/* 0x3165: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_316a:
	/* 0x316a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_316f:
	/* 0x316f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3174:
	/* 0x3174: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3176:
	/* 0x3176: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_317b:
	/* 0x317b: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_317f:
	/* 0x317f: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3184:
	/* 0x3184: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3189:
	/* 0x3189: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_318e:
	/* 0x318e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3193:
	/* 0x3193: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3198:
	/* 0x3198: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_319a:
	/* 0x319a: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_319f:
	/* 0x319f: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31a4:
	/* 0x31a4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_31a8:
	/* 0x31a8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31ad:
	/* 0x31ad: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31b2:
	/* 0x31b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31b7:
	/* 0x31b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31b9:
	/* 0x31b9: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31be:
	/* 0x31be: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_31c1:
	/* 0x31c1: je     323a <trace_security_file_open+0x323a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_323a;
	}
x86_l_31c3:
	/* 0x31c3: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31c8:
	/* 0x31c8: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_31cb:
	/* 0x31cb: je     323a <trace_security_file_open+0x323a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_323a;
	}
x86_l_31cd:
	/* 0x31cd: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_31d1:
	/* 0x31d1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31d6:
	/* 0x31d6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31db:
	/* 0x31db: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_31e0:
	/* 0x31e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31e2:
	/* 0x31e2: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_31e6:
	/* 0x31e6: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_31e8:
	/* 0x31e8: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_31ee:
	/* 0x31ee: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31f3:
	/* 0x31f3: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_31f5:
	/* 0x31f5: jb     2693 <trace_security_file_open+0x2693> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9875ULL;
	}
x86_l_31fb:
	/* 0x31fb: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3200:
	/* 0x3200: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3206:
	/* 0x3206: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3209:
	/* 0x3209: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_320e:
	/* 0x320e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3210:
	/* 0x3210: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3213:
	/* 0x3213: jl     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5674ULL;
	}
x86_l_3219:
	/* 0x3219: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_321e:
	/* 0x321e: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3221:
	/* 0x3221: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3227:
	/* 0x3227: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_322c:
	/* 0x322c: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_322e:
	/* 0x322e: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3233:
	/* 0x3233: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3238:
	/* 0x3238: jmp    32a7 <trace_security_file_open+0x32a7> */
	goto x86_l_32a7;
x86_l_323a:
	/* 0x323a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_323d:
	/* 0x323d: jne    162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5674ULL;
	}
x86_l_3243:
	/* 0x3243: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3248:
	/* 0x3248: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_324d:
	/* 0x324d: je     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5674ULL;
	}
x86_l_3253:
	/* 0x3253: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3258:
	/* 0x3258: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_325d:
	/* 0x325d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3261:
	/* 0x3261: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3266:
	/* 0x3266: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_326b:
	/* 0x326b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_326d:
	/* 0x326d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3272:
	/* 0x3272: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3277:
	/* 0x3277: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_327c:
	/* 0x327c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3281:
	/* 0x3281: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3283:
	/* 0x3283: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3288:
	/* 0x3288: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_328d:
	/* 0x328d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3292:
	/* 0x3292: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3297:
	/* 0x3297: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3299:
	/* 0x3299: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_329e:
	/* 0x329e: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_32a2:
	/* 0x32a2: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_32a7:
	/* 0x32a7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32ac:
	/* 0x32ac: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32b1:
	/* 0x32b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32b6:
	/* 0x32b6: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_32bb:
	/* 0x32bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32bd:
	/* 0x32bd: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32c2:
	/* 0x32c2: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_32c7:
	/* 0x32c7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_32cb:
	/* 0x32cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32d0:
	/* 0x32d0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32d5:
	/* 0x32d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32da:
	/* 0x32da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32dc:
	/* 0x32dc: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_32e1:
	/* 0x32e1: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_32e4:
	/* 0x32e4: je     335d <trace_security_file_open+0x335d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_335d;
	}
x86_l_32e6:
	/* 0x32e6: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32eb:
	/* 0x32eb: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_32ee:
	/* 0x32ee: je     335d <trace_security_file_open+0x335d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_335d;
	}
x86_l_32f0:
	/* 0x32f0: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_32f4:
	/* 0x32f4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_32f9:
	/* 0x32f9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32fe:
	/* 0x32fe: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3303:
	/* 0x3303: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3305:
	/* 0x3305: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3309:
	/* 0x3309: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_330b:
	/* 0x330b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3311:
	/* 0x3311: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3316:
	/* 0x3316: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3318:
	/* 0x3318: jb     2693 <trace_security_file_open+0x2693> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9875ULL;
	}
x86_l_331e:
	/* 0x331e: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3323:
	/* 0x3323: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3329:
	/* 0x3329: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_332c:
	/* 0x332c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3331:
	/* 0x3331: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3333:
	/* 0x3333: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3336:
	/* 0x3336: jl     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5674ULL;
	}
x86_l_333c:
	/* 0x333c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3341:
	/* 0x3341: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3344:
	/* 0x3344: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_334a:
	/* 0x334a: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_334f:
	/* 0x334f: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3351:
	/* 0x3351: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3356:
	/* 0x3356: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_335b:
	/* 0x335b: jmp    33ca <trace_security_file_open+0x33ca> */
	goto x86_l_33ca;
x86_l_335d:
	/* 0x335d: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3360:
	/* 0x3360: jne    162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5674ULL;
	}
x86_l_3366:
	/* 0x3366: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_336b:
	/* 0x336b: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_3370:
	/* 0x3370: je     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5674ULL;
	}
x86_l_3376:
	/* 0x3376: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_337b:
	/* 0x337b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3380:
	/* 0x3380: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3384:
	/* 0x3384: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3389:
	/* 0x3389: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_338e:
	/* 0x338e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3390:
	/* 0x3390: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3395:
	/* 0x3395: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_339a:
	/* 0x339a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_339f:
	/* 0x339f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33a4:
	/* 0x33a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33a6:
	/* 0x33a6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33ab:
	/* 0x33ab: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33b0:
	/* 0x33b0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33b5:
	/* 0x33b5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33ba:
	/* 0x33ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33bc:
	/* 0x33bc: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33c1:
	/* 0x33c1: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_33c5:
	/* 0x33c5: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_33ca:
	/* 0x33ca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33cf:
	/* 0x33cf: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_33d4:
	/* 0x33d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33d9:
	/* 0x33d9: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_33de:
	/* 0x33de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33e0:
	/* 0x33e0: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_33e5:
	/* 0x33e5: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33ea:
	/* 0x33ea: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_33ee:
	/* 0x33ee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33f3:
	/* 0x33f3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_33f8:
	/* 0x33f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33fd:
	/* 0x33fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33ff:
	/* 0x33ff: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3404:
	/* 0x3404: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3407:
	/* 0x3407: je     3480 <trace_security_file_open+0x3480> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3480;
	}
x86_l_3409:
	/* 0x3409: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_340e:
	/* 0x340e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3411:
	/* 0x3411: je     3480 <trace_security_file_open+0x3480> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3480;
	}
x86_l_3413:
	/* 0x3413: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3417:
	/* 0x3417: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_341c:
	/* 0x341c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3421:
	/* 0x3421: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3426:
	/* 0x3426: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3428:
	/* 0x3428: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_342c:
	/* 0x342c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_342e:
	/* 0x342e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3434:
	/* 0x3434: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3439:
	/* 0x3439: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_343b:
	/* 0x343b: jb     2693 <trace_security_file_open+0x2693> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9875ULL;
	}
x86_l_3441:
	/* 0x3441: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3446:
	/* 0x3446: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_344c:
	/* 0x344c: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_344f:
	/* 0x344f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3454:
	/* 0x3454: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3456:
	/* 0x3456: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3459:
	/* 0x3459: jl     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5674ULL;
	}
x86_l_345f:
	/* 0x345f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3464:
	/* 0x3464: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3467:
	/* 0x3467: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_346d:
	/* 0x346d: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3472:
	/* 0x3472: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3474:
	/* 0x3474: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3479:
	/* 0x3479: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_347e:
	/* 0x347e: jmp    34ed <trace_security_file_open+0x34ed> */
	goto x86_l_34ed;
x86_l_3480:
	/* 0x3480: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3483:
	/* 0x3483: jne    162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5674ULL;
	}
x86_l_3489:
	/* 0x3489: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_348e:
	/* 0x348e: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_3493:
	/* 0x3493: je     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5674ULL;
	}
x86_l_3499:
	/* 0x3499: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_349e:
	/* 0x349e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34a3:
	/* 0x34a3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_34a7:
	/* 0x34a7: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_34ac:
	/* 0x34ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34b1:
	/* 0x34b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34b3:
	/* 0x34b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34b8:
	/* 0x34b8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34bd:
	/* 0x34bd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34c2:
	/* 0x34c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34c7:
	/* 0x34c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34c9:
	/* 0x34c9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34ce:
	/* 0x34ce: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34d3:
	/* 0x34d3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34d8:
	/* 0x34d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34dd:
	/* 0x34dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34df:
	/* 0x34df: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34e4:
	/* 0x34e4: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_34e8:
	/* 0x34e8: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_34ed:
	/* 0x34ed: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34f2:
	/* 0x34f2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_34f7:
	/* 0x34f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34fc:
	/* 0x34fc: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3501:
	/* 0x3501: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3503:
	/* 0x3503: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3508:
	/* 0x3508: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_350d:
	/* 0x350d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3511:
	/* 0x3511: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3516:
	/* 0x3516: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_351b:
	/* 0x351b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3520:
	/* 0x3520: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3522:
	/* 0x3522: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3527:
	/* 0x3527: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_352a:
	/* 0x352a: je     35a4 <trace_security_file_open+0x35a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35a4;
	}
x86_l_352c:
	/* 0x352c: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3531:
	/* 0x3531: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3534:
	/* 0x3534: je     35a4 <trace_security_file_open+0x35a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35a4;
	}
x86_l_3536:
	/* 0x3536: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_353a:
	/* 0x353a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_353f:
	/* 0x353f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3544:
	/* 0x3544: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3549:
	/* 0x3549: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_354b:
	/* 0x354b: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_354f:
	/* 0x354f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3551:
	/* 0x3551: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3557:
	/* 0x3557: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_355c:
	/* 0x355c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_355e:
	/* 0x355e: jb     2693 <trace_security_file_open+0x2693> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9875ULL;
	}
x86_l_3564:
	/* 0x3564: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3569:
	/* 0x3569: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_356f:
	/* 0x356f: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3572:
	/* 0x3572: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3577:
	/* 0x3577: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3579:
	/* 0x3579: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_357c:
	/* 0x357c: jl     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5674ULL;
	}
x86_l_3582:
	/* 0x3582: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3587:
	/* 0x3587: lea    ecx,[r12-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_358c:
	/* 0x358c: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3592:
	/* 0x3592: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3597:
	/* 0x3597: sub    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_359a:
	/* 0x359a: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_359f:
	/* 0x359f: jmp    162f <trace_security_file_open+0x162f> */
	return 5679ULL;
x86_l_35a4:
	/* 0x35a4: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_35a7:
	/* 0x35a7: jne    162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5674ULL;
	}
x86_l_35ad:
	/* 0x35ad: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35b2:
	/* 0x35b2: cmp    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_35b7:
	/* 0x35b7: je     162a <trace_security_file_open+0x162a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5674ULL;
	}
x86_l_35bd:
	/* 0x35bd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_35c2:
	/* 0x35c2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35c7:
	/* 0x35c7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_35cb:
	/* 0x35cb: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_35d0:
	/* 0x35d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35d5:
	/* 0x35d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35d7:
	/* 0x35d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_35dc:
	/* 0x35dc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35e1:
	/* 0x35e1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35e6:
	/* 0x35e6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35eb:
	/* 0x35eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35ed:
	/* 0x35ed: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_35f2:
	/* 0x35f2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35f7:
	/* 0x35f7: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35fc:
	/* 0x35fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3601:
	/* 0x3601: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 13827ULL;
}

static __noinline __u64 tracee_trace_security_file_open_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13827ULL: goto x86_l_3603;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3603:
	/* 0x3603: jmp    162a <trace_security_file_open+0x162a> */
	return 5674ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_trace_security_file_open_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 12292U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2144ULL)
			__x86_pc = tracee_trace_security_file_open_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2149ULL && __x86_pc <= 3813ULL)
			__x86_pc = tracee_trace_security_file_open_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3820ULL && __x86_pc <= 5393ULL)
			__x86_pc = tracee_trace_security_file_open_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5398ULL && __x86_pc <= 7179ULL)
			__x86_pc = tracee_trace_security_file_open_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7186ULL && __x86_pc <= 8869ULL)
			__x86_pc = tracee_trace_security_file_open_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8874ULL && __x86_pc <= 10528ULL)
			__x86_pc = tracee_trace_security_file_open_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10530ULL && __x86_pc <= 12171ULL)
			__x86_pc = tracee_trace_security_file_open_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12176ULL && __x86_pc <= 13825ULL)
			__x86_pc = tracee_trace_security_file_open_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13827ULL && __x86_pc <= 13827ULL)
			__x86_pc = tracee_trace_security_file_open_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

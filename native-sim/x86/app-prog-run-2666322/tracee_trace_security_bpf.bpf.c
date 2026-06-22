extern char binary_filter_version;
extern char cgroup_id_filter_version;
extern char comm_filter_version;
extern char config_map;
extern char containers_map;
extern char event_data_map;
extern char events;
extern char events_map_version;
extern char mnt_ns_filter_version;
extern char pid_filter_version;
extern char pid_ns_filter_version;
extern char proc_info_map;
extern char process_tree_map_version;
extern char prog_array;
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

static __noinline __u64 tracee_trace_security_bpf_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 18ULL: goto x86_l_12;
	case 20ULL: goto x86_l_14;
	case 23ULL: goto x86_l_17;
	case 28ULL: goto x86_l_1c;
	case 30ULL: goto x86_l_1e;
	case 33ULL: goto x86_l_21;
	case 37ULL: goto x86_l_25;
	case 42ULL: goto x86_l_2a;
	case 45ULL: goto x86_l_2d;
	case 50ULL: goto x86_l_32;
	case 52ULL: goto x86_l_34;
	case 59ULL: goto x86_l_3b;
	case 64ULL: goto x86_l_40;
	case 66ULL: goto x86_l_42;
	case 71ULL: goto x86_l_47;
	case 73ULL: goto x86_l_49;
	case 78ULL: goto x86_l_4e;
	case 81ULL: goto x86_l_51;
	case 83ULL: goto x86_l_53;
	case 86ULL: goto x86_l_56;
	case 88ULL: goto x86_l_58;
	case 91ULL: goto x86_l_5b;
	case 93ULL: goto x86_l_5d;
	case 100ULL: goto x86_l_64;
	case 105ULL: goto x86_l_69;
	case 108ULL: goto x86_l_6c;
	case 113ULL: goto x86_l_71;
	case 116ULL: goto x86_l_74;
	case 118ULL: goto x86_l_76;
	case 122ULL: goto x86_l_7a;
	case 124ULL: goto x86_l_7c;
	case 131ULL: goto x86_l_83;
	case 133ULL: goto x86_l_85;
	case 138ULL: goto x86_l_8a;
	case 145ULL: goto x86_l_91;
	case 153ULL: goto x86_l_99;
	case 155ULL: goto x86_l_9b;
	case 158ULL: goto x86_l_9e;
	case 160ULL: goto x86_l_a0;
	case 162ULL: goto x86_l_a2;
	case 164ULL: goto x86_l_a4;
	case 169ULL: goto x86_l_a9;
	case 180ULL: goto x86_l_b4;
	case 185ULL: goto x86_l_b9;
	case 192ULL: goto x86_l_c0;
	case 200ULL: goto x86_l_c8;
	case 202ULL: goto x86_l_ca;
	case 205ULL: goto x86_l_cd;
	case 211ULL: goto x86_l_d3;
	case 214ULL: goto x86_l_d6;
	case 219ULL: goto x86_l_db;
	case 226ULL: goto x86_l_e2;
	case 234ULL: goto x86_l_ea;
	case 236ULL: goto x86_l_ec;
	case 239ULL: goto x86_l_ef;
	case 245ULL: goto x86_l_f5;
	case 248ULL: goto x86_l_f8;
	case 258ULL: goto x86_l_102;
	case 266ULL: goto x86_l_10a;
	case 277ULL: goto x86_l_115;
	case 288ULL: goto x86_l_120;
	case 299ULL: goto x86_l_12b;
	case 310ULL: goto x86_l_136;
	case 321ULL: goto x86_l_141;
	case 332ULL: goto x86_l_14c;
	case 343ULL: goto x86_l_157;
	case 354ULL: goto x86_l_162;
	case 361ULL: goto x86_l_169;
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
	case 470ULL: goto x86_l_1d6;
	case 472ULL: goto x86_l_1d8;
	case 476ULL: goto x86_l_1dc;
	case 480ULL: goto x86_l_1e0;
	case 484ULL: goto x86_l_1e4;
	case 492ULL: goto x86_l_1ec;
	case 497ULL: goto x86_l_1f1;
	case 499ULL: goto x86_l_1f3;
	case 502ULL: goto x86_l_1f6;
	case 507ULL: goto x86_l_1fb;
	case 509ULL: goto x86_l_1fd;
	case 514ULL: goto x86_l_202;
	case 518ULL: goto x86_l_206;
	case 522ULL: goto x86_l_20a;
	case 526ULL: goto x86_l_20e;
	case 531ULL: goto x86_l_213;
	case 538ULL: goto x86_l_21a;
	case 543ULL: goto x86_l_21f;
	case 545ULL: goto x86_l_221;
	case 553ULL: goto x86_l_229;
	case 556ULL: goto x86_l_22c;
	case 558ULL: goto x86_l_22e;
	case 562ULL: goto x86_l_232;
	case 569ULL: goto x86_l_239;
	case 574ULL: goto x86_l_23e;
	case 581ULL: goto x86_l_245;
	case 589ULL: goto x86_l_24d;
	case 591ULL: goto x86_l_24f;
	case 594ULL: goto x86_l_252;
	case 597ULL: goto x86_l_255;
	case 605ULL: goto x86_l_25d;
	case 613ULL: goto x86_l_265;
	case 619ULL: goto x86_l_26b;
	case 625ULL: goto x86_l_271;
	case 631ULL: goto x86_l_277;
	case 636ULL: goto x86_l_27c;
	case 638ULL: goto x86_l_27e;
	case 643ULL: goto x86_l_283;
	case 647ULL: goto x86_l_287;
	case 654ULL: goto x86_l_28e;
	case 665ULL: goto x86_l_299;
	case 670ULL: goto x86_l_29e;
	case 677ULL: goto x86_l_2a5;
	case 685ULL: goto x86_l_2ad;
	case 687ULL: goto x86_l_2af;
	case 690ULL: goto x86_l_2b2;
	case 696ULL: goto x86_l_2b8;
	case 703ULL: goto x86_l_2bf;
	case 706ULL: goto x86_l_2c2;
	case 717ULL: goto x86_l_2cd;
	case 728ULL: goto x86_l_2d8;
	case 739ULL: goto x86_l_2e3;
	case 750ULL: goto x86_l_2ee;
	case 761ULL: goto x86_l_2f9;
	case 772ULL: goto x86_l_304;
	case 783ULL: goto x86_l_30f;
	case 794ULL: goto x86_l_31a;
	case 805ULL: goto x86_l_325;
	case 816ULL: goto x86_l_330;
	case 827ULL: goto x86_l_33b;
	case 838ULL: goto x86_l_346;
	case 849ULL: goto x86_l_351;
	case 860ULL: goto x86_l_35c;
	case 871ULL: goto x86_l_367;
	case 882ULL: goto x86_l_372;
	case 893ULL: goto x86_l_37d;
	case 904ULL: goto x86_l_388;
	case 915ULL: goto x86_l_393;
	case 926ULL: goto x86_l_39e;
	case 937ULL: goto x86_l_3a9;
	case 948ULL: goto x86_l_3b4;
	case 959ULL: goto x86_l_3bf;
	case 970ULL: goto x86_l_3ca;
	case 981ULL: goto x86_l_3d5;
	case 992ULL: goto x86_l_3e0;
	case 1003ULL: goto x86_l_3eb;
	case 1014ULL: goto x86_l_3f6;
	case 1025ULL: goto x86_l_401;
	case 1036ULL: goto x86_l_40c;
	case 1044ULL: goto x86_l_414;
	case 1052ULL: goto x86_l_41c;
	case 1060ULL: goto x86_l_424;
	case 1068ULL: goto x86_l_42c;
	case 1076ULL: goto x86_l_434;
	case 1084ULL: goto x86_l_43c;
	case 1092ULL: goto x86_l_444;
	case 1100ULL: goto x86_l_44c;
	case 1108ULL: goto x86_l_454;
	case 1116ULL: goto x86_l_45c;
	case 1124ULL: goto x86_l_464;
	case 1132ULL: goto x86_l_46c;
	case 1140ULL: goto x86_l_474;
	case 1148ULL: goto x86_l_47c;
	case 1156ULL: goto x86_l_484;
	case 1163ULL: goto x86_l_48b;
	case 1169ULL: goto x86_l_491;
	case 1176ULL: goto x86_l_498;
	case 1179ULL: goto x86_l_49b;
	case 1184ULL: goto x86_l_4a0;
	case 1187ULL: goto x86_l_4a3;
	case 1190ULL: goto x86_l_4a6;
	case 1193ULL: goto x86_l_4a9;
	case 1198ULL: goto x86_l_4ae;
	case 1206ULL: goto x86_l_4b6;
	case 1209ULL: goto x86_l_4b9;
	case 1211ULL: goto x86_l_4bb;
	case 1219ULL: goto x86_l_4c3;
	case 1222ULL: goto x86_l_4c6;
	case 1228ULL: goto x86_l_4cc;
	case 1233ULL: goto x86_l_4d1;
	case 1240ULL: goto x86_l_4d8;
	case 1247ULL: goto x86_l_4df;
	case 1258ULL: goto x86_l_4ea;
	case 1263ULL: goto x86_l_4ef;
	case 1270ULL: goto x86_l_4f6;
	case 1278ULL: goto x86_l_4fe;
	case 1280ULL: goto x86_l_500;
	case 1283ULL: goto x86_l_503;
	case 1289ULL: goto x86_l_509;
	case 1296ULL: goto x86_l_510;
	case 1299ULL: goto x86_l_513;
	case 1310ULL: goto x86_l_51e;
	case 1321ULL: goto x86_l_529;
	case 1332ULL: goto x86_l_534;
	case 1343ULL: goto x86_l_53f;
	case 1354ULL: goto x86_l_54a;
	case 1365ULL: goto x86_l_555;
	case 1376ULL: goto x86_l_560;
	case 1387ULL: goto x86_l_56b;
	case 1398ULL: goto x86_l_576;
	case 1406ULL: goto x86_l_57e;
	case 1414ULL: goto x86_l_586;
	case 1422ULL: goto x86_l_58e;
	case 1430ULL: goto x86_l_596;
	case 1438ULL: goto x86_l_59e;
	case 1446ULL: goto x86_l_5a6;
	case 1454ULL: goto x86_l_5ae;
	case 1462ULL: goto x86_l_5b6;
	case 1470ULL: goto x86_l_5be;
	case 1478ULL: goto x86_l_5c6;
	case 1486ULL: goto x86_l_5ce;
	case 1494ULL: goto x86_l_5d6;
	case 1502ULL: goto x86_l_5de;
	case 1510ULL: goto x86_l_5e6;
	case 1518ULL: goto x86_l_5ee;
	case 1525ULL: goto x86_l_5f5;
	case 1531ULL: goto x86_l_5fb;
	case 1538ULL: goto x86_l_602;
	case 1541ULL: goto x86_l_605;
	case 1546ULL: goto x86_l_60a;
	case 1549ULL: goto x86_l_60d;
	case 1552ULL: goto x86_l_610;
	case 1555ULL: goto x86_l_613;
	case 1560ULL: goto x86_l_618;
	case 1568ULL: goto x86_l_620;
	case 1571ULL: goto x86_l_623;
	case 1573ULL: goto x86_l_625;
	case 1576ULL: goto x86_l_628;
	case 1582ULL: goto x86_l_62e;
	case 1585ULL: goto x86_l_631;
	case 1592ULL: goto x86_l_638;
	case 1596ULL: goto x86_l_63c;
	case 1601ULL: goto x86_l_641;
	case 1604ULL: goto x86_l_644;
	case 1609ULL: goto x86_l_649;
	case 1612ULL: goto x86_l_64c;
	case 1614ULL: goto x86_l_64e;
	case 1618ULL: goto x86_l_652;
	case 1623ULL: goto x86_l_657;
	case 1627ULL: goto x86_l_65b;
	case 1632ULL: goto x86_l_660;
	case 1635ULL: goto x86_l_663;
	case 1640ULL: goto x86_l_668;
	case 1642ULL: goto x86_l_66a;
	case 1646ULL: goto x86_l_66e;
	case 1650ULL: goto x86_l_672;
	case 1655ULL: goto x86_l_677;
	case 1658ULL: goto x86_l_67a;
	case 1663ULL: goto x86_l_67f;
	case 1665ULL: goto x86_l_681;
	case 1669ULL: goto x86_l_685;
	case 1673ULL: goto x86_l_689;
	case 1678ULL: goto x86_l_68e;
	case 1681ULL: goto x86_l_691;
	case 1686ULL: goto x86_l_696;
	case 1688ULL: goto x86_l_698;
	case 1691ULL: goto x86_l_69b;
	case 1694ULL: goto x86_l_69e;
	case 1702ULL: goto x86_l_6a6;
	case 1706ULL: goto x86_l_6aa;
	case 1711ULL: goto x86_l_6af;
	case 1714ULL: goto x86_l_6b2;
	case 1719ULL: goto x86_l_6b7;
	case 1722ULL: goto x86_l_6ba;
	case 1724ULL: goto x86_l_6bc;
	case 1728ULL: goto x86_l_6c0;
	case 1733ULL: goto x86_l_6c5;
	case 1736ULL: goto x86_l_6c8;
	case 1741ULL: goto x86_l_6cd;
	case 1744ULL: goto x86_l_6d0;
	case 1746ULL: goto x86_l_6d2;
	case 1749ULL: goto x86_l_6d5;
	case 1753ULL: goto x86_l_6d9;
	case 1757ULL: goto x86_l_6dd;
	case 1761ULL: goto x86_l_6e1;
	case 1766ULL: goto x86_l_6e6;
	case 1769ULL: goto x86_l_6e9;
	case 1774ULL: goto x86_l_6ee;
	case 1776ULL: goto x86_l_6f0;
	case 1779ULL: goto x86_l_6f3;
	case 1782ULL: goto x86_l_6f6;
	case 1787ULL: goto x86_l_6fb;
	case 1790ULL: goto x86_l_6fe;
	case 1795ULL: goto x86_l_703;
	case 1798ULL: goto x86_l_706;
	case 1800ULL: goto x86_l_708;
	case 1804ULL: goto x86_l_70c;
	case 1808ULL: goto x86_l_710;
	case 1813ULL: goto x86_l_715;
	case 1816ULL: goto x86_l_718;
	case 1821ULL: goto x86_l_71d;
	case 1823ULL: goto x86_l_71f;
	case 1827ULL: goto x86_l_723;
	case 1832ULL: goto x86_l_728;
	case 1835ULL: goto x86_l_72b;
	case 1840ULL: goto x86_l_730;
	case 1843ULL: goto x86_l_733;
	case 1845ULL: goto x86_l_735;
	case 1848ULL: goto x86_l_738;
	case 1852ULL: goto x86_l_73c;
	case 1856ULL: goto x86_l_740;
	case 1860ULL: goto x86_l_744;
	case 1865ULL: goto x86_l_749;
	case 1868ULL: goto x86_l_74c;
	case 1873ULL: goto x86_l_751;
	case 1875ULL: goto x86_l_753;
	case 1878ULL: goto x86_l_756;
	case 1881ULL: goto x86_l_759;
	case 1886ULL: goto x86_l_75e;
	case 1889ULL: goto x86_l_761;
	case 1894ULL: goto x86_l_766;
	case 1897ULL: goto x86_l_769;
	case 1899ULL: goto x86_l_76b;
	case 1903ULL: goto x86_l_76f;
	case 1908ULL: goto x86_l_774;
	case 1911ULL: goto x86_l_777;
	case 1916ULL: goto x86_l_77c;
	case 1919ULL: goto x86_l_77f;
	case 1921ULL: goto x86_l_781;
	case 1924ULL: goto x86_l_784;
	case 1928ULL: goto x86_l_788;
	case 1932ULL: goto x86_l_78c;
	case 1936ULL: goto x86_l_790;
	case 1941ULL: goto x86_l_795;
	case 1944ULL: goto x86_l_798;
	case 1949ULL: goto x86_l_79d;
	case 1951ULL: goto x86_l_79f;
	case 1955ULL: goto x86_l_7a3;
	case 1959ULL: goto x86_l_7a7;
	case 1964ULL: goto x86_l_7ac;
	case 1967ULL: goto x86_l_7af;
	case 1972ULL: goto x86_l_7b4;
	case 1974ULL: goto x86_l_7b6;
	case 1978ULL: goto x86_l_7ba;
	case 1982ULL: goto x86_l_7be;
	case 1987ULL: goto x86_l_7c3;
	case 1990ULL: goto x86_l_7c6;
	case 1995ULL: goto x86_l_7cb;
	case 1998ULL: goto x86_l_7ce;
	case 2000ULL: goto x86_l_7d0;
	case 2004ULL: goto x86_l_7d4;
	case 2009ULL: goto x86_l_7d9;
	case 2012ULL: goto x86_l_7dc;
	case 2017ULL: goto x86_l_7e1;
	case 2020ULL: goto x86_l_7e4;
	case 2022ULL: goto x86_l_7e6;
	case 2025ULL: goto x86_l_7e9;
	case 2029ULL: goto x86_l_7ed;
	case 2033ULL: goto x86_l_7f1;
	case 2037ULL: goto x86_l_7f5;
	case 2042ULL: goto x86_l_7fa;
	case 2045ULL: goto x86_l_7fd;
	case 2050ULL: goto x86_l_802;
	case 2052ULL: goto x86_l_804;
	case 2056ULL: goto x86_l_808;
	case 2060ULL: goto x86_l_80c;
	case 2065ULL: goto x86_l_811;
	case 2068ULL: goto x86_l_814;
	case 2073ULL: goto x86_l_819;
	case 2075ULL: goto x86_l_81b;
	case 2079ULL: goto x86_l_81f;
	case 2081ULL: goto x86_l_821;
	case 2086ULL: goto x86_l_826;
	case 2089ULL: goto x86_l_829;
	case 2094ULL: goto x86_l_82e;
	case 2097ULL: goto x86_l_831;
	case 2099ULL: goto x86_l_833;
	case 2103ULL: goto x86_l_837;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x148 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 328ULL);
x86_l_a:
	/* 0xa: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_12:
	/* 0x12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14:
	/* 0x14: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_17:
	/* 0x17: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_1c:
	/* 0x1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e:
	/* 0x1e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_21:
	/* 0x21: lea    rdx,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_25:
	/* 0x25: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a:
	/* 0x2a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2d:
	/* 0x2d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_32:
	/* 0x32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34:
	/* 0x34: test   DWORD PTR [rsp],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2097152ULL);
x86_l_3b:
	/* 0x3b: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_40:
	/* 0x40: jne    a9 <trace_security_bpf+0xa9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a9;
	}
x86_l_42:
	/* 0x42: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_47:
	/* 0x47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49:
	/* 0x49: mov    ecx,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 175ULL);
x86_l_4e:
	/* 0x4e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_51:
	/* 0x51: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_53:
	/* 0x53: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_56:
	/* 0x56: je     5d <trace_security_bpf+0x5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d;
	}
x86_l_58:
	/* 0x58: mov    eax,DWORD PTR [rax+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_5b:
	/* 0x5b: jmp    5d <trace_security_bpf+0x5d> */
	goto x86_l_5d;
x86_l_5d:
	/* 0x5d: mov    DWORD PTR [rsp+0xb0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_64:
	/* 0x64: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_69:
	/* 0x69: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6c:
	/* 0x6c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_71:
	/* 0x71: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_74:
	/* 0x74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76:
	/* 0x76: test   BYTE PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_7a:
	/* 0x7a: jne    85 <trace_security_bpf+0x85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_85;
	}
x86_l_7c:
	/* 0x7c: mov    ebp,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_83:
	/* 0x83: jmp    a9 <trace_security_bpf+0xa9> */
	goto x86_l_a9;
x86_l_85:
	/* 0x85: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8a:
	/* 0x8a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_91:
	/* 0x91: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_99:
	/* 0x99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b:
	/* 0x9b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9e:
	/* 0x9e: je     a4 <trace_security_bpf+0xa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a4;
	}
x86_l_a0:
	/* 0xa0: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a2:
	/* 0xa2: jmp    a9 <trace_security_bpf+0xa9> */
	goto x86_l_a9;
x86_l_a4:
	/* 0xa4: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_a9:
	/* 0xa9: mov    DWORD PTR [rsp+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_b4:
	/* 0xb4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b9:
	/* 0xb9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_c0:
	/* 0xc0: lea    rsi,[rsp+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_c8:
	/* 0xc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ca:
	/* 0xca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cd:
	/* 0xcd: je     2de5 <trace_security_bpf+0x2de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11749ULL;
	}
x86_l_d3:
	/* 0xd3: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_d6:
	/* 0xd6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_db:
	/* 0xdb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_e2:
	/* 0xe2: lea    rsi,[rsp+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_ea:
	/* 0xea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ec:
	/* 0xec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ef:
	/* 0xef: je     2de5 <trace_security_bpf+0x2de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11749ULL;
	}
x86_l_f5:
	/* 0xf5: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_f8:
	/* 0xf8: mov    WORD PTR [r14+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_102:
	/* 0x102: mov    BYTE PTR [r14+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_10a:
	/* 0x10a: mov    QWORD PTR [r14+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_115:
	/* 0x115: mov    QWORD PTR [r14+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_120:
	/* 0x120: mov    QWORD PTR [r14+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_12b:
	/* 0x12b: mov    QWORD PTR [r14+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_136:
	/* 0x136: mov    QWORD PTR [r14+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_141:
	/* 0x141: mov    QWORD PTR [r14+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_14c:
	/* 0x14c: mov    QWORD PTR [r14+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_157:
	/* 0x157: mov    QWORD PTR [r14+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_162:
	/* 0x162: mov    QWORD PTR [r14+0x7dd0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_169:
	/* 0x169: mov    QWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_171:
	/* 0x171: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_179:
	/* 0x179: mov    QWORD PTR [r14+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_181:
	/* 0x181: mov    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_189:
	/* 0x189: mov    QWORD PTR [r14+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_191:
	/* 0x191: mov    QWORD PTR [r14+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_199:
	/* 0x199: mov    QWORD PTR [r14+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1a1:
	/* 0x1a1: mov    QWORD PTR [r14+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1a9:
	/* 0x1a9: mov    QWORD PTR [r14+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1b1:
	/* 0x1b1: mov    QWORD PTR [r14+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1b9:
	/* 0x1b9: mov    QWORD PTR [r14+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1c1:
	/* 0x1c1: mov    QWORD PTR [r14+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1c9:
	/* 0x1c9: mov    QWORD PTR [r14+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1d1:
	/* 0x1d1: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1d6:
	/* 0x1d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d8:
	/* 0x1d8: mov    DWORD PTR [r14+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1dc:
	/* 0x1dc: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1e0:
	/* 0x1e0: mov    DWORD PTR [r14+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1e4:
	/* 0x1e4: mov    DWORD PTR [r14+0x70],0x2e5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337893ULL);
x86_l_1ec:
	/* 0x1ec: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_1f1:
	/* 0x1f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f3:
	/* 0x1f3: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f6:
	/* 0x1f6: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1fb:
	/* 0x1fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fd:
	/* 0x1fd: mov    WORD PTR [r14+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_202:
	/* 0x202: mov    DWORD PTR [r14+0x74],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_206:
	/* 0x206: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_20a:
	/* 0x20a: mov    DWORD PTR [rsp+0x6c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_20e:
	/* 0x20e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_213:
	/* 0x213: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_21a:
	/* 0x21a: lea    rsi,[rsp+0x6c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_21f:
	/* 0x21f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_221:
	/* 0x221: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_229:
	/* 0x229: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22c:
	/* 0x22c: je     283 <trace_security_bpf+0x283> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_283;
	}
x86_l_22e:
	/* 0x22e: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_232:
	/* 0x232: mov    DWORD PTR [rsp+0x118],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_239:
	/* 0x239: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23e:
	/* 0x23e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_245:
	/* 0x245: lea    rsi,[rsp+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_24d:
	/* 0x24d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24f:
	/* 0x24f: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_252:
	/* 0x252: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_255:
	/* 0x255: mov    QWORD PTR [rsp+0xa0],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_25d:
	/* 0x25d: mov    QWORD PTR [rsp+0x98],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_265:
	/* 0x265: je     4d1 <trace_security_bpf+0x4d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d1;
	}
x86_l_26b:
	/* 0x26b: test   BYTE PTR [r12+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_271:
	/* 0x271: jne    9d9 <trace_security_bpf+0x9d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2521ULL;
	}
x86_l_277:
	/* 0x277: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_27c:
	/* 0x27c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27e:
	/* 0x27e: jmp    a63 <trace_security_bpf+0xa63> */
	return 2659ULL;
x86_l_283:
	/* 0x283: mov    eax,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_287:
	/* 0x287: mov    DWORD PTR [rsp+0xb0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_28e:
	/* 0x28e: mov    DWORD PTR [rsp+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_299:
	/* 0x299: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29e:
	/* 0x29e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_2a5:
	/* 0x2a5: lea    rsi,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2ad:
	/* 0x2ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2af:
	/* 0x2af: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b2:
	/* 0x2b2: je     2de5 <trace_security_bpf+0x2de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11749ULL;
	}
x86_l_2b8:
	/* 0x2b8: mov    ecx,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2bf:
	/* 0x2bf: mov    DWORD PTR [rsp],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c2:
	/* 0x2c2: mov    QWORD PTR [rax+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_2cd:
	/* 0x2cd: mov    QWORD PTR [rax+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_2d8:
	/* 0x2d8: mov    QWORD PTR [rax+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_2e3:
	/* 0x2e3: mov    QWORD PTR [rax+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_2ee:
	/* 0x2ee: mov    QWORD PTR [rax+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_2f9:
	/* 0x2f9: mov    QWORD PTR [rax+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_304:
	/* 0x304: mov    QWORD PTR [rax+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_30f:
	/* 0x30f: mov    QWORD PTR [rax+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_31a:
	/* 0x31a: mov    QWORD PTR [rax+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_325:
	/* 0x325: mov    QWORD PTR [rax+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_330:
	/* 0x330: mov    QWORD PTR [rax+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_33b:
	/* 0x33b: mov    QWORD PTR [rax+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_346:
	/* 0x346: mov    QWORD PTR [rax+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_351:
	/* 0x351: mov    QWORD PTR [rax+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_35c:
	/* 0x35c: mov    QWORD PTR [rax+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_367:
	/* 0x367: mov    QWORD PTR [rax+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_372:
	/* 0x372: mov    QWORD PTR [rax+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_37d:
	/* 0x37d: mov    QWORD PTR [rax+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_388:
	/* 0x388: mov    QWORD PTR [rax+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_393:
	/* 0x393: mov    QWORD PTR [rax+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_39e:
	/* 0x39e: mov    QWORD PTR [rax+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_3a9:
	/* 0x3a9: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_3b4:
	/* 0x3b4: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_3bf:
	/* 0x3bf: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_3ca:
	/* 0x3ca: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_3d5:
	/* 0x3d5: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_3e0:
	/* 0x3e0: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_3eb:
	/* 0x3eb: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_3f6:
	/* 0x3f6: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_401:
	/* 0x401: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_40c:
	/* 0x40c: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_414:
	/* 0x414: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_41c:
	/* 0x41c: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_424:
	/* 0x424: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_42c:
	/* 0x42c: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_434:
	/* 0x434: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_43c:
	/* 0x43c: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_444:
	/* 0x444: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_44c:
	/* 0x44c: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_454:
	/* 0x454: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_45c:
	/* 0x45c: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_464:
	/* 0x464: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_46c:
	/* 0x46c: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_474:
	/* 0x474: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_47c:
	/* 0x47c: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_484:
	/* 0x484: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48b:
	/* 0x48b: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_491:
	/* 0x491: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_498:
	/* 0x498: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_49b:
	/* 0x49b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4a0:
	/* 0x4a0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4a3:
	/* 0x4a3: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4a6:
	/* 0x4a6: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_4a9:
	/* 0x4a9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4ae:
	/* 0x4ae: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_4b6:
	/* 0x4b6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4b9:
	/* 0x4b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bb:
	/* 0x4bb: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4c3:
	/* 0x4c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4c6:
	/* 0x4c6: jne    22e <trace_security_bpf+0x22e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22e;
	}
x86_l_4cc:
	/* 0x4cc: jmp    2de5 <trace_security_bpf+0x2de5> */
	return 11749ULL;
x86_l_4d1:
	/* 0x4d1: mov    eax,DWORD PTR [rsp+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_4d8:
	/* 0x4d8: mov    DWORD PTR [rsp+0xb0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_4df:
	/* 0x4df: mov    DWORD PTR [rsp+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_4ea:
	/* 0x4ea: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4ef:
	/* 0x4ef: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_4f6:
	/* 0x4f6: lea    rsi,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_4fe:
	/* 0x4fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_500:
	/* 0x500: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_503:
	/* 0x503: je     2de5 <trace_security_bpf+0x2de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11749ULL;
	}
x86_l_509:
	/* 0x509: mov    ecx,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_510:
	/* 0x510: mov    DWORD PTR [rsp],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_513:
	/* 0x513: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_51e:
	/* 0x51e: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_529:
	/* 0x529: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_534:
	/* 0x534: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_53f:
	/* 0x53f: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_54a:
	/* 0x54a: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_555:
	/* 0x555: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_560:
	/* 0x560: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_56b:
	/* 0x56b: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_576:
	/* 0x576: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_57e:
	/* 0x57e: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_586:
	/* 0x586: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_58e:
	/* 0x58e: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_596:
	/* 0x596: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_59e:
	/* 0x59e: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_5a6:
	/* 0x5a6: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_5ae:
	/* 0x5ae: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_5b6:
	/* 0x5b6: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_5be:
	/* 0x5be: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_5c6:
	/* 0x5c6: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_5ce:
	/* 0x5ce: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5d6:
	/* 0x5d6: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5de:
	/* 0x5de: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5e6:
	/* 0x5e6: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_5ee:
	/* 0x5ee: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f5:
	/* 0x5f5: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_5fb:
	/* 0x5fb: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_602:
	/* 0x602: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_605:
	/* 0x605: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_60a:
	/* 0x60a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_60d:
	/* 0x60d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_610:
	/* 0x610: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_613:
	/* 0x613: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_618:
	/* 0x618: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_620:
	/* 0x620: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_623:
	/* 0x623: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_625:
	/* 0x625: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_628:
	/* 0x628: je     2de5 <trace_security_bpf+0x2de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11749ULL;
	}
x86_l_62e:
	/* 0x62e: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_631:
	/* 0x631: mov    r15,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_638:
	/* 0x638: lea    r13,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_63c:
	/* 0x63c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_641:
	/* 0x641: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_644:
	/* 0x644: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_649:
	/* 0x649: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_64c:
	/* 0x64c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64e:
	/* 0x64e: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_652:
	/* 0x652: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_657:
	/* 0x657: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_65b:
	/* 0x65b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_660:
	/* 0x660: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_663:
	/* 0x663: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_668:
	/* 0x668: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66a:
	/* 0x66a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66e:
	/* 0x66e: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_672:
	/* 0x672: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_677:
	/* 0x677: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_67a:
	/* 0x67a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_67f:
	/* 0x67f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_681:
	/* 0x681: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_685:
	/* 0x685: lea    rdx,[rbx+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_689:
	/* 0x689: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_68e:
	/* 0x68e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_691:
	/* 0x691: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_696:
	/* 0x696: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_698:
	/* 0x698: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_69b:
	/* 0x69b: mov    DWORD PTR [rbp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_69e:
	/* 0x69e: mov    QWORD PTR [rsp+0x88],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_6a6:
	/* 0x6a6: lea    r12,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6aa:
	/* 0x6aa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6af:
	/* 0x6af: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6b2:
	/* 0x6b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6b7:
	/* 0x6b7: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_6ba:
	/* 0x6ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6bc:
	/* 0x6bc: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6c0:
	/* 0x6c0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6c5:
	/* 0x6c5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6c8:
	/* 0x6c8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6cd:
	/* 0x6cd: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6d0:
	/* 0x6d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d2:
	/* 0x6d2: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6d5:
	/* 0x6d5: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_6d9:
	/* 0x6d9: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_6dd:
	/* 0x6dd: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6e1:
	/* 0x6e1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6e6:
	/* 0x6e6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6e9:
	/* 0x6e9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6ee:
	/* 0x6ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f0:
	/* 0x6f0: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6f3:
	/* 0x6f3: mov    DWORD PTR [rbp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6f6:
	/* 0x6f6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6fb:
	/* 0x6fb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6fe:
	/* 0x6fe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_703:
	/* 0x703: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_706:
	/* 0x706: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_708:
	/* 0x708: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_70c:
	/* 0x70c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_710:
	/* 0x710: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_715:
	/* 0x715: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_718:
	/* 0x718: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_71d:
	/* 0x71d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_71f:
	/* 0x71f: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_723:
	/* 0x723: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_728:
	/* 0x728: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_72b:
	/* 0x72b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_730:
	/* 0x730: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_733:
	/* 0x733: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_735:
	/* 0x735: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_738:
	/* 0x738: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_73c:
	/* 0x73c: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_740:
	/* 0x740: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_744:
	/* 0x744: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_749:
	/* 0x749: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_74c:
	/* 0x74c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_751:
	/* 0x751: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_753:
	/* 0x753: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_756:
	/* 0x756: mov    DWORD PTR [rbp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_759:
	/* 0x759: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_75e:
	/* 0x75e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_761:
	/* 0x761: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_766:
	/* 0x766: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_769:
	/* 0x769: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76b:
	/* 0x76b: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_76f:
	/* 0x76f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_774:
	/* 0x774: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_777:
	/* 0x777: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_77c:
	/* 0x77c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_77f:
	/* 0x77f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_781:
	/* 0x781: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_784:
	/* 0x784: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_788:
	/* 0x788: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_78c:
	/* 0x78c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_790:
	/* 0x790: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_795:
	/* 0x795: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_798:
	/* 0x798: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_79d:
	/* 0x79d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_79f:
	/* 0x79f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7a3:
	/* 0x7a3: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_7a7:
	/* 0x7a7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7ac:
	/* 0x7ac: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_7af:
	/* 0x7af: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7b4:
	/* 0x7b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b6:
	/* 0x7b6: mov    r13d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7ba:
	/* 0x7ba: lea    r15,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7be:
	/* 0x7be: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7c3:
	/* 0x7c3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_7c6:
	/* 0x7c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7cb:
	/* 0x7cb: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_7ce:
	/* 0x7ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7d0:
	/* 0x7d0: mov    r12,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7d4:
	/* 0x7d4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7d9:
	/* 0x7d9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_7dc:
	/* 0x7dc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7e1:
	/* 0x7e1: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_7e4:
	/* 0x7e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e6:
	/* 0x7e6: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7e9:
	/* 0x7e9: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_7ed:
	/* 0x7ed: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_7f1:
	/* 0x7f1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_7f5:
	/* 0x7f5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7fa:
	/* 0x7fa: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_7fd:
	/* 0x7fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_802:
	/* 0x802: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_804:
	/* 0x804: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_808:
	/* 0x808: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_80c:
	/* 0x80c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_811:
	/* 0x811: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_814:
	/* 0x814: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_819:
	/* 0x819: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_81b:
	/* 0x81b: cmp    r13d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_81f:
	/* 0x81f: jne    86d <trace_security_bpf+0x86d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2157ULL;
	}
x86_l_821:
	/* 0x821: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_826:
	/* 0x826: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_829:
	/* 0x829: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_82e:
	/* 0x82e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_831:
	/* 0x831: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_833:
	/* 0x833: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_837:
	/* 0x837: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
	return 2108ULL;
}

static __noinline __u64 tracee_trace_security_bpf_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2108ULL: goto x86_l_83c;
	case 2111ULL: goto x86_l_83f;
	case 2116ULL: goto x86_l_844;
	case 2119ULL: goto x86_l_847;
	case 2121ULL: goto x86_l_849;
	case 2124ULL: goto x86_l_84c;
	case 2128ULL: goto x86_l_850;
	case 2132ULL: goto x86_l_854;
	case 2136ULL: goto x86_l_858;
	case 2141ULL: goto x86_l_85d;
	case 2144ULL: goto x86_l_860;
	case 2149ULL: goto x86_l_865;
	case 2151ULL: goto x86_l_867;
	case 2154ULL: goto x86_l_86a;
	case 2157ULL: goto x86_l_86d;
	case 2161ULL: goto x86_l_871;
	case 2169ULL: goto x86_l_879;
	case 2177ULL: goto x86_l_881;
	case 2182ULL: goto x86_l_886;
	case 2185ULL: goto x86_l_889;
	case 2190ULL: goto x86_l_88e;
	case 2193ULL: goto x86_l_891;
	case 2195ULL: goto x86_l_893;
	case 2199ULL: goto x86_l_897;
	case 2203ULL: goto x86_l_89b;
	case 2208ULL: goto x86_l_8a0;
	case 2211ULL: goto x86_l_8a3;
	case 2216ULL: goto x86_l_8a8;
	case 2218ULL: goto x86_l_8aa;
	case 2223ULL: goto x86_l_8af;
	case 2227ULL: goto x86_l_8b3;
	case 2235ULL: goto x86_l_8bb;
	case 2240ULL: goto x86_l_8c0;
	case 2242ULL: goto x86_l_8c2;
	case 2249ULL: goto x86_l_8c9;
	case 2252ULL: goto x86_l_8cc;
	case 2257ULL: goto x86_l_8d1;
	case 2259ULL: goto x86_l_8d3;
	case 2262ULL: goto x86_l_8d6;
	case 2267ULL: goto x86_l_8db;
	case 2272ULL: goto x86_l_8e0;
	case 2275ULL: goto x86_l_8e3;
	case 2280ULL: goto x86_l_8e8;
	case 2282ULL: goto x86_l_8ea;
	case 2286ULL: goto x86_l_8ee;
	case 2290ULL: goto x86_l_8f2;
	case 2295ULL: goto x86_l_8f7;
	case 2299ULL: goto x86_l_8fb;
	case 2304ULL: goto x86_l_900;
	case 2307ULL: goto x86_l_903;
	case 2312ULL: goto x86_l_908;
	case 2314ULL: goto x86_l_90a;
	case 2318ULL: goto x86_l_90e;
	case 2322ULL: goto x86_l_912;
	case 2326ULL: goto x86_l_916;
	case 2331ULL: goto x86_l_91b;
	case 2334ULL: goto x86_l_91e;
	case 2339ULL: goto x86_l_923;
	case 2342ULL: goto x86_l_926;
	case 2344ULL: goto x86_l_928;
	case 2348ULL: goto x86_l_92c;
	case 2352ULL: goto x86_l_930;
	case 2357ULL: goto x86_l_935;
	case 2360ULL: goto x86_l_938;
	case 2365ULL: goto x86_l_93d;
	case 2368ULL: goto x86_l_940;
	case 2370ULL: goto x86_l_942;
	case 2374ULL: goto x86_l_946;
	case 2382ULL: goto x86_l_94e;
	case 2384ULL: goto x86_l_950;
	case 2388ULL: goto x86_l_954;
	case 2392ULL: goto x86_l_958;
	case 2400ULL: goto x86_l_960;
	case 2408ULL: goto x86_l_968;
	case 2413ULL: goto x86_l_96d;
	case 2418ULL: goto x86_l_972;
	case 2420ULL: goto x86_l_974;
	case 2425ULL: goto x86_l_979;
	case 2428ULL: goto x86_l_97c;
	case 2433ULL: goto x86_l_981;
	case 2436ULL: goto x86_l_984;
	case 2438ULL: goto x86_l_986;
	case 2442ULL: goto x86_l_98a;
	case 2447ULL: goto x86_l_98f;
	case 2450ULL: goto x86_l_992;
	case 2455ULL: goto x86_l_997;
	case 2457ULL: goto x86_l_999;
	case 2461ULL: goto x86_l_99d;
	case 2466ULL: goto x86_l_9a2;
	case 2469ULL: goto x86_l_9a5;
	case 2472ULL: goto x86_l_9a8;
	case 2477ULL: goto x86_l_9ad;
	case 2479ULL: goto x86_l_9af;
	case 2482ULL: goto x86_l_9b2;
	case 2486ULL: goto x86_l_9b6;
	case 2491ULL: goto x86_l_9bb;
	case 2496ULL: goto x86_l_9c0;
	case 2499ULL: goto x86_l_9c3;
	case 2501ULL: goto x86_l_9c5;
	case 2509ULL: goto x86_l_9cd;
	case 2515ULL: goto x86_l_9d3;
	case 2521ULL: goto x86_l_9d9;
	case 2526ULL: goto x86_l_9de;
	case 2533ULL: goto x86_l_9e5;
	case 2538ULL: goto x86_l_9ea;
	case 2546ULL: goto x86_l_9f2;
	case 2551ULL: goto x86_l_9f7;
	case 2553ULL: goto x86_l_9f9;
	case 2558ULL: goto x86_l_9fe;
	case 2566ULL: goto x86_l_a06;
	case 2574ULL: goto x86_l_a0e;
	case 2579ULL: goto x86_l_a13;
	case 2581ULL: goto x86_l_a15;
	case 2586ULL: goto x86_l_a1a;
	case 2594ULL: goto x86_l_a22;
	case 2597ULL: goto x86_l_a25;
	case 2602ULL: goto x86_l_a2a;
	case 2604ULL: goto x86_l_a2c;
	case 2608ULL: goto x86_l_a30;
	case 2613ULL: goto x86_l_a35;
	case 2616ULL: goto x86_l_a38;
	case 2621ULL: goto x86_l_a3d;
	case 2623ULL: goto x86_l_a3f;
	case 2627ULL: goto x86_l_a43;
	case 2630ULL: goto x86_l_a46;
	case 2632ULL: goto x86_l_a48;
	case 2636ULL: goto x86_l_a4c;
	case 2641ULL: goto x86_l_a51;
	case 2644ULL: goto x86_l_a54;
	case 2649ULL: goto x86_l_a59;
	case 2651ULL: goto x86_l_a5b;
	case 2655ULL: goto x86_l_a5f;
	case 2657ULL: goto x86_l_a61;
	case 2659ULL: goto x86_l_a63;
	case 2663ULL: goto x86_l_a67;
	case 2667ULL: goto x86_l_a6b;
	case 2674ULL: goto x86_l_a72;
	case 2679ULL: goto x86_l_a77;
	case 2686ULL: goto x86_l_a7e;
	case 2694ULL: goto x86_l_a86;
	case 2696ULL: goto x86_l_a88;
	case 2699ULL: goto x86_l_a8b;
	case 2701ULL: goto x86_l_a8d;
	case 2704ULL: goto x86_l_a90;
	case 2710ULL: goto x86_l_a96;
	case 2713ULL: goto x86_l_a99;
	case 2716ULL: goto x86_l_a9c;
	case 2718ULL: goto x86_l_a9e;
	case 2723ULL: goto x86_l_aa3;
	case 2728ULL: goto x86_l_aa8;
	case 2734ULL: goto x86_l_aae;
	case 2740ULL: goto x86_l_ab4;
	case 2751ULL: goto x86_l_abf;
	case 2758ULL: goto x86_l_ac6;
	case 2766ULL: goto x86_l_ace;
	case 2771ULL: goto x86_l_ad3;
	case 2778ULL: goto x86_l_ada;
	case 2786ULL: goto x86_l_ae2;
	case 2788ULL: goto x86_l_ae4;
	case 2791ULL: goto x86_l_ae7;
	case 2793ULL: goto x86_l_ae9;
	case 2798ULL: goto x86_l_aee;
	case 2801ULL: goto x86_l_af1;
	case 2804ULL: goto x86_l_af4;
	case 2806ULL: goto x86_l_af6;
	case 2809ULL: goto x86_l_af9;
	case 2811ULL: goto x86_l_afb;
	case 2815ULL: goto x86_l_aff;
	case 2822ULL: goto x86_l_b06;
	case 2825ULL: goto x86_l_b09;
	case 2832ULL: goto x86_l_b10;
	case 2836ULL: goto x86_l_b14;
	case 2840ULL: goto x86_l_b18;
	case 2847ULL: goto x86_l_b1f;
	case 2854ULL: goto x86_l_b26;
	case 2858ULL: goto x86_l_b2a;
	case 2865ULL: goto x86_l_b31;
	case 2869ULL: goto x86_l_b35;
	case 2876ULL: goto x86_l_b3c;
	case 2880ULL: goto x86_l_b40;
	case 2887ULL: goto x86_l_b47;
	case 2891ULL: goto x86_l_b4b;
	case 2898ULL: goto x86_l_b52;
	case 2902ULL: goto x86_l_b56;
	case 2910ULL: goto x86_l_b5e;
	case 2917ULL: goto x86_l_b65;
	case 2924ULL: goto x86_l_b6c;
	case 2928ULL: goto x86_l_b70;
	case 2935ULL: goto x86_l_b77;
	case 2939ULL: goto x86_l_b7b;
	case 2943ULL: goto x86_l_b7f;
	case 2951ULL: goto x86_l_b87;
	case 2953ULL: goto x86_l_b89;
	case 2956ULL: goto x86_l_b8c;
	case 2961ULL: goto x86_l_b91;
	case 2968ULL: goto x86_l_b98;
	case 2971ULL: goto x86_l_b9b;
	case 2977ULL: goto x86_l_ba1;
	case 2984ULL: goto x86_l_ba8;
	case 2987ULL: goto x86_l_bab;
	case 2990ULL: goto x86_l_bae;
	case 2993ULL: goto x86_l_bb1;
	case 2997ULL: goto x86_l_bb5;
	case 3000ULL: goto x86_l_bb8;
	case 3003ULL: goto x86_l_bbb;
	case 3010ULL: goto x86_l_bc2;
	case 3013ULL: goto x86_l_bc5;
	case 3020ULL: goto x86_l_bcc;
	case 3023ULL: goto x86_l_bcf;
	case 3025ULL: goto x86_l_bd1;
	case 3027ULL: goto x86_l_bd3;
	case 3034ULL: goto x86_l_bda;
	case 3037ULL: goto x86_l_bdd;
	case 3040ULL: goto x86_l_be0;
	case 3043ULL: goto x86_l_be3;
	case 3050ULL: goto x86_l_bea;
	case 3053ULL: goto x86_l_bed;
	case 3056ULL: goto x86_l_bf0;
	case 3063ULL: goto x86_l_bf7;
	case 3066ULL: goto x86_l_bfa;
	case 3068ULL: goto x86_l_bfc;
	case 3072ULL: goto x86_l_c00;
	case 3075ULL: goto x86_l_c03;
	case 3078ULL: goto x86_l_c06;
	case 3081ULL: goto x86_l_c09;
	case 3088ULL: goto x86_l_c10;
	case 3091ULL: goto x86_l_c13;
	case 3094ULL: goto x86_l_c16;
	case 3101ULL: goto x86_l_c1d;
	case 3104ULL: goto x86_l_c20;
	case 3106ULL: goto x86_l_c22;
	case 3109ULL: goto x86_l_c25;
	case 3117ULL: goto x86_l_c2d;
	case 3121ULL: goto x86_l_c31;
	case 3124ULL: goto x86_l_c34;
	case 3131ULL: goto x86_l_c3b;
	case 3134ULL: goto x86_l_c3e;
	case 3137ULL: goto x86_l_c41;
	case 3142ULL: goto x86_l_c46;
	case 3149ULL: goto x86_l_c4d;
	case 3152ULL: goto x86_l_c50;
	case 3157ULL: goto x86_l_c55;
	case 3163ULL: goto x86_l_c5b;
	case 3170ULL: goto x86_l_c62;
	case 3175ULL: goto x86_l_c67;
	case 3182ULL: goto x86_l_c6e;
	case 3187ULL: goto x86_l_c73;
	case 3194ULL: goto x86_l_c7a;
	case 3199ULL: goto x86_l_c7f;
	case 3203ULL: goto x86_l_c83;
	case 3208ULL: goto x86_l_c88;
	case 3215ULL: goto x86_l_c8f;
	case 3218ULL: goto x86_l_c92;
	case 3220ULL: goto x86_l_c94;
	case 3223ULL: goto x86_l_c97;
	case 3227ULL: goto x86_l_c9b;
	case 3231ULL: goto x86_l_c9f;
	case 3238ULL: goto x86_l_ca6;
	case 3241ULL: goto x86_l_ca9;
	case 3243ULL: goto x86_l_cab;
	case 3248ULL: goto x86_l_cb0;
	case 3251ULL: goto x86_l_cb3;
	case 3254ULL: goto x86_l_cb6;
	case 3256ULL: goto x86_l_cb8;
	case 3259ULL: goto x86_l_cbb;
	case 3261ULL: goto x86_l_cbd;
	case 3264ULL: goto x86_l_cc0;
	case 3268ULL: goto x86_l_cc4;
	case 3271ULL: goto x86_l_cc7;
	case 3273ULL: goto x86_l_cc9;
	case 3276ULL: goto x86_l_ccc;
	case 3281ULL: goto x86_l_cd1;
	case 3286ULL: goto x86_l_cd6;
	case 3290ULL: goto x86_l_cda;
	case 3293ULL: goto x86_l_cdd;
	case 3296ULL: goto x86_l_ce0;
	case 3298ULL: goto x86_l_ce2;
	case 3302ULL: goto x86_l_ce6;
	case 3304ULL: goto x86_l_ce8;
	case 3307ULL: goto x86_l_ceb;
	case 3309ULL: goto x86_l_ced;
	case 3314ULL: goto x86_l_cf2;
	case 3317ULL: goto x86_l_cf5;
	case 3321ULL: goto x86_l_cf9;
	case 3325ULL: goto x86_l_cfd;
	case 3332ULL: goto x86_l_d04;
	case 3335ULL: goto x86_l_d07;
	case 3337ULL: goto x86_l_d09;
	case 3342ULL: goto x86_l_d0e;
	case 3347ULL: goto x86_l_d13;
	case 3350ULL: goto x86_l_d16;
	case 3353ULL: goto x86_l_d19;
	case 3355ULL: goto x86_l_d1b;
	case 3358ULL: goto x86_l_d1e;
	case 3360ULL: goto x86_l_d20;
	case 3363ULL: goto x86_l_d23;
	case 3367ULL: goto x86_l_d27;
	case 3370ULL: goto x86_l_d2a;
	case 3372ULL: goto x86_l_d2c;
	case 3379ULL: goto x86_l_d33;
	case 3386ULL: goto x86_l_d3a;
	case 3389ULL: goto x86_l_d3d;
	case 3395ULL: goto x86_l_d43;
	case 3400ULL: goto x86_l_d48;
	case 3402ULL: goto x86_l_d4a;
	case 3405ULL: goto x86_l_d4d;
	case 3409ULL: goto x86_l_d51;
	case 3412ULL: goto x86_l_d54;
	case 3414ULL: goto x86_l_d56;
	case 3416ULL: goto x86_l_d58;
	case 3418ULL: goto x86_l_d5a;
	case 3423ULL: goto x86_l_d5f;
	case 3428ULL: goto x86_l_d64;
	case 3431ULL: goto x86_l_d67;
	case 3435ULL: goto x86_l_d6b;
	case 3438ULL: goto x86_l_d6e;
	case 3440ULL: goto x86_l_d70;
	case 3444ULL: goto x86_l_d74;
	case 3446ULL: goto x86_l_d76;
	case 3449ULL: goto x86_l_d79;
	case 3451ULL: goto x86_l_d7b;
	case 3456ULL: goto x86_l_d80;
	case 3459ULL: goto x86_l_d83;
	case 3462ULL: goto x86_l_d86;
	case 3465ULL: goto x86_l_d89;
	case 3468ULL: goto x86_l_d8c;
	case 3476ULL: goto x86_l_d94;
	case 3482ULL: goto x86_l_d9a;
	case 3487ULL: goto x86_l_d9f;
	case 3489ULL: goto x86_l_da1;
	case 3493ULL: goto x86_l_da5;
	case 3500ULL: goto x86_l_dac;
	case 3507ULL: goto x86_l_db3;
	case 3512ULL: goto x86_l_db8;
	case 3519ULL: goto x86_l_dbf;
	case 3526ULL: goto x86_l_dc6;
	case 3531ULL: goto x86_l_dcb;
	case 3535ULL: goto x86_l_dcf;
	case 3540ULL: goto x86_l_dd4;
	case 3547ULL: goto x86_l_ddb;
	case 3550ULL: goto x86_l_dde;
	case 3552ULL: goto x86_l_de0;
	case 3556ULL: goto x86_l_de4;
	case 3560ULL: goto x86_l_de8;
	case 3567ULL: goto x86_l_def;
	case 3570ULL: goto x86_l_df2;
	case 3572ULL: goto x86_l_df4;
	case 3577ULL: goto x86_l_df9;
	case 3580ULL: goto x86_l_dfc;
	case 3583ULL: goto x86_l_dff;
	case 3585ULL: goto x86_l_e01;
	case 3588ULL: goto x86_l_e04;
	case 3590ULL: goto x86_l_e06;
	case 3593ULL: goto x86_l_e09;
	case 3597ULL: goto x86_l_e0d;
	case 3600ULL: goto x86_l_e10;
	case 3602ULL: goto x86_l_e12;
	case 3604ULL: goto x86_l_e14;
	case 3607ULL: goto x86_l_e17;
	case 3611ULL: goto x86_l_e1b;
	case 3614ULL: goto x86_l_e1e;
	case 3617ULL: goto x86_l_e21;
	case 3619ULL: goto x86_l_e23;
	case 3624ULL: goto x86_l_e28;
	case 3626ULL: goto x86_l_e2a;
	case 3631ULL: goto x86_l_e2f;
	case 3639ULL: goto x86_l_e37;
	case 3641ULL: goto x86_l_e39;
	case 3646ULL: goto x86_l_e3e;
	case 3650ULL: goto x86_l_e42;
	case 3655ULL: goto x86_l_e47;
	case 3657ULL: goto x86_l_e49;
	case 3660ULL: goto x86_l_e4c;
	case 3662ULL: goto x86_l_e4e;
	case 3667ULL: goto x86_l_e53;
	case 3670ULL: goto x86_l_e56;
	case 3673ULL: goto x86_l_e59;
	case 3676ULL: goto x86_l_e5c;
	case 3684ULL: goto x86_l_e64;
	case 3690ULL: goto x86_l_e6a;
	case 3695ULL: goto x86_l_e6f;
	case 3702ULL: goto x86_l_e76;
	case 3707ULL: goto x86_l_e7b;
	case 3710ULL: goto x86_l_e7e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_83c:
	/* 0x83c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_83f:
	/* 0x83f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_844:
	/* 0x844: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_847:
	/* 0x847: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_849:
	/* 0x849: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_84c:
	/* 0x84c: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_850:
	/* 0x850: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_854:
	/* 0x854: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_858:
	/* 0x858: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_85d:
	/* 0x85d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_860:
	/* 0x860: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_865:
	/* 0x865: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_867:
	/* 0x867: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_86a:
	/* 0x86a: mov    DWORD PTR [rbp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_86d:
	/* 0x86d: mov    DWORD PTR [rbp+0x30],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_871:
	/* 0x871: mov    r12,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_879:
	/* 0x879: lea    r15,[r12+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_881:
	/* 0x881: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_886:
	/* 0x886: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_889:
	/* 0x889: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_88e:
	/* 0x88e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_891:
	/* 0x891: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_893:
	/* 0x893: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_897:
	/* 0x897: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_89b:
	/* 0x89b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8a0:
	/* 0x8a0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8a3:
	/* 0x8a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8a8:
	/* 0x8a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8aa:
	/* 0x8aa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8af:
	/* 0x8af: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8b3:
	/* 0x8b3: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_8bb:
	/* 0x8bb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8c0:
	/* 0x8c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c2:
	/* 0x8c2: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_8c9:
	/* 0x8c9: mov    DWORD PTR [rbp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_8cc:
	/* 0x8cc: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_8d1:
	/* 0x8d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d3:
	/* 0x8d3: mov    DWORD PTR [rbp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8d6:
	/* 0x8d6: lea    rdx,[r12+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8db:
	/* 0x8db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8e0:
	/* 0x8e0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8e3:
	/* 0x8e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8e8:
	/* 0x8e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ea:
	/* 0x8ea: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8ee:
	/* 0x8ee: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8f2:
	/* 0x8f2: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8f7:
	/* 0x8f7: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_8fb:
	/* 0x8fb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_900:
	/* 0x900: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_903:
	/* 0x903: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_908:
	/* 0x908: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_90a:
	/* 0x90a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_90e:
	/* 0x90e: mov    QWORD PTR [rbp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_912:
	/* 0x912: add    rbx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_916:
	/* 0x916: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_91b:
	/* 0x91b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_91e:
	/* 0x91e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_923:
	/* 0x923: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_926:
	/* 0x926: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_928:
	/* 0x928: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_92c:
	/* 0x92c: mov    QWORD PTR [rbp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_930:
	/* 0x930: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_935:
	/* 0x935: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_938:
	/* 0x938: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_93d:
	/* 0x93d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_940:
	/* 0x940: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_942:
	/* 0x942: test   BYTE PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_946:
	/* 0x946: mov    r12,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_94e:
	/* 0x94e: je     954 <trace_security_bpf+0x954> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_954;
	}
x86_l_950:
	/* 0x950: or     BYTE PTR [rbp+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_954:
	/* 0x954: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_958:
	/* 0x958: mov    QWORD PTR [rbp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_960:
	/* 0x960: mov    QWORD PTR [rbp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_968:
	/* 0x968: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_96d:
	/* 0x96d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_972:
	/* 0x972: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_974:
	/* 0x974: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_979:
	/* 0x979: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_97c:
	/* 0x97c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_981:
	/* 0x981: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_984:
	/* 0x984: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_986:
	/* 0x986: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_98a:
	/* 0x98a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_98f:
	/* 0x98f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_992:
	/* 0x992: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_997:
	/* 0x997: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_999:
	/* 0x999: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_99d:
	/* 0x99d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9a2:
	/* 0x9a2: mov    rbx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSP, X86_WIDTH_64);
x86_l_9a5:
	/* 0x9a5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_9a8:
	/* 0x9a8: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_9ad:
	/* 0x9ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9af:
	/* 0x9af: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_9b2:
	/* 0x9b2: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_9b6:
	/* 0x9b6: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_9bb:
	/* 0x9bb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_9c0:
	/* 0x9c0: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_9c3:
	/* 0x9c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c5:
	/* 0x9c5: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_9cd:
	/* 0x9cd: test   BYTE PTR [r12+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_9d3:
	/* 0x9d3: je     277 <trace_security_bpf+0x277> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 631ULL;
	}
x86_l_9d9:
	/* 0x9d9: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_9de:
	/* 0x9de: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_9e5:
	/* 0x9e5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9ea:
	/* 0x9ea: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_9f2:
	/* 0x9f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9f7:
	/* 0x9f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f9:
	/* 0x9f9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9fe:
	/* 0x9fe: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a06:
	/* 0xa06: lea    rdi,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_a0e:
	/* 0xa0e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a13:
	/* 0xa13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a15:
	/* 0xa15: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a1a:
	/* 0xa1a: mov    rdx,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_a22:
	/* 0xa22: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a25:
	/* 0xa25: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a2a:
	/* 0xa2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a2c:
	/* 0xa2c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a30:
	/* 0xa30: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a35:
	/* 0xa35: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a38:
	/* 0xa38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a3d:
	/* 0xa3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a3f:
	/* 0xa3f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a43:
	/* 0xa43: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_a46:
	/* 0xa46: je     a61 <trace_security_bpf+0xa61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a61;
	}
x86_l_a48:
	/* 0xa48: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_a4c:
	/* 0xa4c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a51:
	/* 0xa51: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a54:
	/* 0xa54: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a59:
	/* 0xa59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a5b:
	/* 0xa5b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a5f:
	/* 0xa5f: jmp    a63 <trace_security_bpf+0xa63> */
	goto x86_l_a63;
x86_l_a61:
	/* 0xa61: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a63:
	/* 0xa63: mov    QWORD PTR [r14+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a67:
	/* 0xa67: mov    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a6b:
	/* 0xa6b: mov    DWORD PTR [rsp+0xb0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a72:
	/* 0xa72: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a77:
	/* 0xa77: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_a7e:
	/* 0xa7e: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a86:
	/* 0xa86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a88:
	/* 0xa88: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a8b:
	/* 0xa8b: je     aa3 <trace_security_bpf+0xaa3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_aa3;
	}
x86_l_a8d:
	/* 0xa8d: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_a90:
	/* 0xa90: mov    BYTE PTR [rbp+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_a96:
	/* 0xa96: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_a99:
	/* 0xa99: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_a9c:
	/* 0xa9c: jne    aa3 <trace_security_bpf+0xaa3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_aa3;
	}
x86_l_a9e:
	/* 0xa9e: or     BYTE PTR [r14+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_aa3:
	/* 0xaa3: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_aa8:
	/* 0xaa8: cmp    ax,WORD PTR [r12+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_aae:
	/* 0xaae: jne    2e87 <trace_security_bpf+0x2e87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11911ULL;
	}
x86_l_ab4:
	/* 0xab4: mov    QWORD PTR [r14+0x7dd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138366666407936ULL);
x86_l_abf:
	/* 0xabf: mov    DWORD PTR [rsp],0x2e5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 741ULL);
x86_l_ac6:
	/* 0xac6: mov    WORD PTR [rsp+0xf8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_ace:
	/* 0xace: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ad3:
	/* 0xad3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_ada:
	/* 0xada: lea    rsi,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_ae2:
	/* 0xae2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ae4:
	/* 0xae4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ae7:
	/* 0xae7: je     b52 <trace_security_bpf+0xb52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b52;
	}
x86_l_ae9:
	/* 0xae9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_aee:
	/* 0xaee: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_af1:
	/* 0xaf1: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_af4:
	/* 0xaf4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_af6:
	/* 0xaf6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_af9:
	/* 0xaf9: je     b52 <trace_security_bpf+0xb52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b52;
	}
x86_l_afb:
	/* 0xafb: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aff:
	/* 0xaff: mov    QWORD PTR [r14+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_b06:
	/* 0xb06: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b09:
	/* 0xb09: mov    QWORD PTR [r14+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_b10:
	/* 0xb10: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b14:
	/* 0xb14: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b18:
	/* 0xb18: mov    QWORD PTR [r14+0x7de8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_b1f:
	/* 0xb1f: mov    QWORD PTR [r14+0x7df0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_b26:
	/* 0xb26: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b2a:
	/* 0xb2a: mov    QWORD PTR [r14+0x7df8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_b31:
	/* 0xb31: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b35:
	/* 0xb35: mov    QWORD PTR [r14+0x7e00],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_b3c:
	/* 0xb3c: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b40:
	/* 0xb40: mov    QWORD PTR [r14+0x7e08],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_b47:
	/* 0xb47: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b4b:
	/* 0xb4b: mov    QWORD PTR [r14+0x7e10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_b52:
	/* 0xb52: lea    rax,[r14+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_b56:
	/* 0xb56: mov    QWORD PTR [rsp+0xf0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_b5e:
	/* 0xb5e: mov    rax,QWORD PTR [r14+0x7dd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_b65:
	/* 0xb65: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b6c:
	/* 0xb6c: mov    ecx,DWORD PTR [r15+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b70:
	/* 0xb70: mov    DWORD PTR [rsp+0x90],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_b77:
	/* 0xb77: mov    ecx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b7b:
	/* 0xb7b: cmp    ecx,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_b7f:
	/* 0xb7f: mov    QWORD PTR [rsp+0x88],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b87:
	/* 0xb87: jne    b91 <trace_security_bpf+0xb91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b91;
	}
x86_l_b89:
	/* 0xb89: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b8c:
	/* 0xb8c: jmp    12f6 <trace_security_bpf+0x12f6> */
	return 4854ULL;
x86_l_b91:
	/* 0xb91: mov    rax,QWORD PTR [r14+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_b98:
	/* 0xb98: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b9b:
	/* 0xb9b: je     d2c <trace_security_bpf+0xd2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d2c;
	}
x86_l_ba1:
	/* 0xba1: movzx  ecx,BYTE PTR [rbp+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_ba8:
	/* 0xba8: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_bab:
	/* 0xbab: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bae:
	/* 0xbae: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_bb1:
	/* 0xbb1: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_bb5:
	/* 0xbb5: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_bb8:
	/* 0xbb8: neg    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_bbb:
	/* 0xbbb: xor    r12,QWORD PTR [r14+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_bc2:
	/* 0xbc2: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_bc5:
	/* 0xbc5: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_bcc:
	/* 0xbcc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bcf:
	/* 0xbcf: je     bf0 <trace_security_bpf+0xbf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bf0;
	}
x86_l_bd1:
	/* 0xbd1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bd3:
	/* 0xbd3: cmp    BYTE PTR [rbp+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_bda:
	/* 0xbda: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_bdd:
	/* 0xbdd: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_be0:
	/* 0xbe0: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_be3:
	/* 0xbe3: xor    rcx,QWORD PTR [r14+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_bea:
	/* 0xbea: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_bed:
	/* 0xbed: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_bf0:
	/* 0xbf0: mov    rax,QWORD PTR [r14+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_bf7:
	/* 0xbf7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bfa:
	/* 0xbfa: je     c16 <trace_security_bpf+0xc16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c16;
	}
x86_l_bfc:
	/* 0xbfc: mov    ecx,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_c00:
	/* 0xc00: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_c03:
	/* 0xc03: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_c06:
	/* 0xc06: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_c09:
	/* 0xc09: xor    rcx,QWORD PTR [r14+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_c10:
	/* 0xc10: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_c13:
	/* 0xc13: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_c16:
	/* 0xc16: mov    rax,QWORD PTR [r14+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_c1d:
	/* 0xc1d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c20:
	/* 0xc20: je     c41 <trace_security_bpf+0xc41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c41;
	}
x86_l_c22:
	/* 0xc22: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_c25:
	/* 0xc25: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c2d:
	/* 0xc2d: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_c31:
	/* 0xc31: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_c34:
	/* 0xc34: xor    rcx,QWORD PTR [r14+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_c3b:
	/* 0xc3b: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_c3e:
	/* 0xc3e: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_c41:
	/* 0xc41: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_c46:
	/* 0xc46: mov    r15,QWORD PTR [r14+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_c4d:
	/* 0xc4d: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_c50:
	/* 0xc50: mov    WORD PTR [rsp+0x60],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c55:
	/* 0xc55: je     d8c <trace_security_bpf+0xd8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d8c;
	}
x86_l_c5b:
	/* 0xc5b: mov    rcx,QWORD PTR [r14+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_c62:
	/* 0xc62: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c67:
	/* 0xc67: mov    rcx,QWORD PTR [r14+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_c6e:
	/* 0xc6e: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c73:
	/* 0xc73: mov    rcx,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_c7a:
	/* 0xc7a: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_c7f:
	/* 0xc7f: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c83:
	/* 0xc83: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c88:
	/* 0xc88: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_c8f:
	/* 0xc8f: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_c92:
	/* 0xc92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c94:
	/* 0xc94: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_c97:
	/* 0xc97: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_c9b:
	/* 0xc9b: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c9f:
	/* 0xc9f: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_ca6:
	/* 0xca6: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_ca9:
	/* 0xca9: je     cc9 <trace_security_bpf+0xcc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc9;
	}
x86_l_cab:
	/* 0xcab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cb0:
	/* 0xcb0: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_cb3:
	/* 0xcb3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_cb6:
	/* 0xcb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cb8:
	/* 0xcb8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cbb:
	/* 0xcbb: je     cc9 <trace_security_bpf+0xcc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cc9;
	}
x86_l_cbd:
	/* 0xcbd: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cc0:
	/* 0xcc0: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cc4:
	/* 0xcc4: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_cc7:
	/* 0xcc7: jmp    ccc <trace_security_bpf+0xccc> */
	goto x86_l_ccc;
x86_l_cc9:
	/* 0xcc9: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ccc:
	/* 0xccc: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_cd1:
	/* 0xcd1: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_cd6:
	/* 0xcd6: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cda:
	/* 0xcda: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_cdd:
	/* 0xcdd: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_ce0:
	/* 0xce0: jb     cf5 <trace_security_bpf+0xcf5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cf5;
	}
x86_l_ce2:
	/* 0xce2: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_ce6:
	/* 0xce6: je     ced <trace_security_bpf+0xced> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ced;
	}
x86_l_ce8:
	/* 0xce8: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_ceb:
	/* 0xceb: jbe    cf5 <trace_security_bpf+0xcf5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_cf5;
	}
x86_l_ced:
	/* 0xced: and    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 120ULL);
x86_l_cf2:
	/* 0xcf2: or     r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_cf5:
	/* 0xcf5: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cf9:
	/* 0xcf9: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cfd:
	/* 0xcfd: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_d04:
	/* 0xd04: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_d07:
	/* 0xd07: je     d48 <trace_security_bpf+0xd48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d48;
	}
x86_l_d09:
	/* 0xd09: mov    QWORD PTR [rsp+0x58],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d0e:
	/* 0xd0e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d13:
	/* 0xd13: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_d16:
	/* 0xd16: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_d19:
	/* 0xd19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d1b:
	/* 0xd1b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d1e:
	/* 0xd1e: je     d58 <trace_security_bpf+0xd58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d58;
	}
x86_l_d20:
	/* 0xd20: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d23:
	/* 0xd23: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d27:
	/* 0xd27: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d2a:
	/* 0xd2a: jmp    d5a <trace_security_bpf+0xd5a> */
	goto x86_l_d5a;
x86_l_d2c:
	/* 0xd2c: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_d33:
	/* 0xd33: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_d3a:
	/* 0xd3a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d3d:
	/* 0xd3d: jne    bd1 <trace_security_bpf+0xbd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_bd1;
	}
x86_l_d43:
	/* 0xd43: jmp    bf0 <trace_security_bpf+0xbf0> */
	goto x86_l_bf0;
x86_l_d48:
	/* 0xd48: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d4a:
	/* 0xd4a: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d4d:
	/* 0xd4d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d51:
	/* 0xd51: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_d54:
	/* 0xd54: jae    d70 <trace_security_bpf+0xd70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_d70;
	}
x86_l_d56:
	/* 0xd56: jmp    d83 <trace_security_bpf+0xd83> */
	goto x86_l_d83;
x86_l_d58:
	/* 0xd58: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d5a:
	/* 0xd5a: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d5f:
	/* 0xd5f: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d64:
	/* 0xd64: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d67:
	/* 0xd67: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d6b:
	/* 0xd6b: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_d6e:
	/* 0xd6e: jb     d83 <trace_security_bpf+0xd83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d83;
	}
x86_l_d70:
	/* 0xd70: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_d74:
	/* 0xd74: je     d7b <trace_security_bpf+0xd7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d7b;
	}
x86_l_d76:
	/* 0xd76: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_d79:
	/* 0xd79: jbe    d83 <trace_security_bpf+0xd83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_d83;
	}
x86_l_d7b:
	/* 0xd7b: and    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 120ULL);
x86_l_d80:
	/* 0xd80: or     rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_d83:
	/* 0xd83: or     r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_d86:
	/* 0xd86: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d89:
	/* 0xd89: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_d8c:
	/* 0xd8c: cmp    QWORD PTR [r14+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_d94:
	/* 0xd94: je     e2a <trace_security_bpf+0xe2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e2a;
	}
x86_l_d9a:
	/* 0xd9a: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_d9f:
	/* 0xd9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_da1:
	/* 0xda1: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_da5:
	/* 0xda5: mov    rbx,QWORD PTR [r14+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_dac:
	/* 0xdac: mov    rax,QWORD PTR [r14+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_db3:
	/* 0xdb3: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_db8:
	/* 0xdb8: mov    rbp,QWORD PTR [r14+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_dbf:
	/* 0xdbf: mov    r13,QWORD PTR [r14+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_dc6:
	/* 0xdc6: movzx  eax,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_dcb:
	/* 0xdcb: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dcf:
	/* 0xdcf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dd4:
	/* 0xdd4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_ddb:
	/* 0xddb: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_dde:
	/* 0xdde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_de0:
	/* 0xde0: mov    ecx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_de4:
	/* 0xde4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_de8:
	/* 0xde8: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_def:
	/* 0xdef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_df2:
	/* 0xdf2: je     e12 <trace_security_bpf+0xe12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e12;
	}
x86_l_df4:
	/* 0xdf4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_df9:
	/* 0xdf9: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_dfc:
	/* 0xdfc: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_dff:
	/* 0xdff: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e01:
	/* 0xe01: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e04:
	/* 0xe04: je     e12 <trace_security_bpf+0xe12> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e12;
	}
x86_l_e06:
	/* 0xe06: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e09:
	/* 0xe09: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e0d:
	/* 0xe0d: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e10:
	/* 0xe10: jmp    e14 <trace_security_bpf+0xe14> */
	goto x86_l_e14;
x86_l_e12:
	/* 0xe12: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e14:
	/* 0xe14: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e17:
	/* 0xe17: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e1b:
	/* 0xe1b: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_e1e:
	/* 0xe1e: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_e21:
	/* 0xe21: jae    e3e <trace_security_bpf+0xe3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_e3e;
	}
x86_l_e23:
	/* 0xe23: movzx  ebp,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_e28:
	/* 0xe28: jmp    e56 <trace_security_bpf+0xe56> */
	goto x86_l_e56;
x86_l_e2a:
	/* 0xe2a: movzx  ebp,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_e2f:
	/* 0xe2f: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_e37:
	/* 0xe37: jne    e6a <trace_security_bpf+0xe6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e6a;
	}
x86_l_e39:
	/* 0xe39: jmp    f1e <trace_security_bpf+0xf1e> */
	return 3870ULL;
x86_l_e3e:
	/* 0xe3e: cmp    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e42:
	/* 0xe42: movzx  ebp,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_e47:
	/* 0xe47: je     e4e <trace_security_bpf+0xe4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e4e;
	}
x86_l_e49:
	/* 0xe49: cmp    rax,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_e4c:
	/* 0xe4c: jbe    e56 <trace_security_bpf+0xe56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e56;
	}
x86_l_e4e:
	/* 0xe4e: and    r15,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 88ULL);
x86_l_e53:
	/* 0xe53: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_e56:
	/* 0xe56: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_e59:
	/* 0xe59: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_e5c:
	/* 0xe5c: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_e64:
	/* 0xe64: je     f1e <trace_security_bpf+0xf1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3870ULL;
	}
x86_l_e6a:
	/* 0xe6a: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_e6f:
	/* 0xe6f: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_e76:
	/* 0xe76: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e7b:
	/* 0xe7b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_e7e:
	/* 0xe7e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 3715ULL;
}

static __noinline __u64 tracee_trace_security_bpf_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3715ULL: goto x86_l_e83;
	case 3717ULL: goto x86_l_e85;
	case 3721ULL: goto x86_l_e89;
	case 3725ULL: goto x86_l_e8d;
	case 3730ULL: goto x86_l_e92;
	case 3733ULL: goto x86_l_e95;
	case 3738ULL: goto x86_l_e9a;
	case 3740ULL: goto x86_l_e9c;
	case 3745ULL: goto x86_l_ea1;
	case 3749ULL: goto x86_l_ea5;
	case 3757ULL: goto x86_l_ead;
	case 3762ULL: goto x86_l_eb2;
	case 3764ULL: goto x86_l_eb4;
	case 3771ULL: goto x86_l_ebb;
	case 3775ULL: goto x86_l_ebf;
	case 3782ULL: goto x86_l_ec6;
	case 3789ULL: goto x86_l_ecd;
	case 3792ULL: goto x86_l_ed0;
	case 3796ULL: goto x86_l_ed4;
	case 3801ULL: goto x86_l_ed9;
	case 3808ULL: goto x86_l_ee0;
	case 3811ULL: goto x86_l_ee3;
	case 3813ULL: goto x86_l_ee5;
	case 3820ULL: goto x86_l_eec;
	case 3823ULL: goto x86_l_eef;
	case 3825ULL: goto x86_l_ef1;
	case 3829ULL: goto x86_l_ef5;
	case 3834ULL: goto x86_l_efa;
	case 3837ULL: goto x86_l_efd;
	case 3839ULL: goto x86_l_eff;
	case 3842ULL: goto x86_l_f02;
	case 3844ULL: goto x86_l_f04;
	case 3847ULL: goto x86_l_f07;
	case 3851ULL: goto x86_l_f0b;
	case 3854ULL: goto x86_l_f0e;
	case 3856ULL: goto x86_l_f10;
	case 3858ULL: goto x86_l_f12;
	case 3861ULL: goto x86_l_f15;
	case 3864ULL: goto x86_l_f18;
	case 3867ULL: goto x86_l_f1b;
	case 3870ULL: goto x86_l_f1e;
	case 3878ULL: goto x86_l_f26;
	case 3884ULL: goto x86_l_f2c;
	case 3891ULL: goto x86_l_f33;
	case 3895ULL: goto x86_l_f37;
	case 3900ULL: goto x86_l_f3c;
	case 3903ULL: goto x86_l_f3f;
	case 3908ULL: goto x86_l_f44;
	case 3910ULL: goto x86_l_f46;
	case 3914ULL: goto x86_l_f4a;
	case 3919ULL: goto x86_l_f4f;
	case 3922ULL: goto x86_l_f52;
	case 3927ULL: goto x86_l_f57;
	case 3930ULL: goto x86_l_f5a;
	case 3932ULL: goto x86_l_f5c;
	case 3935ULL: goto x86_l_f5f;
	case 3939ULL: goto x86_l_f63;
	case 3943ULL: goto x86_l_f67;
	case 3947ULL: goto x86_l_f6b;
	case 3952ULL: goto x86_l_f70;
	case 3955ULL: goto x86_l_f73;
	case 3960ULL: goto x86_l_f78;
	case 3962ULL: goto x86_l_f7a;
	case 3966ULL: goto x86_l_f7e;
	case 3970ULL: goto x86_l_f82;
	case 3975ULL: goto x86_l_f87;
	case 3978ULL: goto x86_l_f8a;
	case 3983ULL: goto x86_l_f8f;
	case 3985ULL: goto x86_l_f91;
	case 3988ULL: goto x86_l_f94;
	case 3992ULL: goto x86_l_f98;
	case 3999ULL: goto x86_l_f9f;
	case 4006ULL: goto x86_l_fa6;
	case 4009ULL: goto x86_l_fa9;
	case 4013ULL: goto x86_l_fad;
	case 4018ULL: goto x86_l_fb2;
	case 4025ULL: goto x86_l_fb9;
	case 4028ULL: goto x86_l_fbc;
	case 4030ULL: goto x86_l_fbe;
	case 4037ULL: goto x86_l_fc5;
	case 4040ULL: goto x86_l_fc8;
	case 4042ULL: goto x86_l_fca;
	case 4046ULL: goto x86_l_fce;
	case 4051ULL: goto x86_l_fd3;
	case 4054ULL: goto x86_l_fd6;
	case 4056ULL: goto x86_l_fd8;
	case 4059ULL: goto x86_l_fdb;
	case 4061ULL: goto x86_l_fdd;
	case 4064ULL: goto x86_l_fe0;
	case 4068ULL: goto x86_l_fe4;
	case 4071ULL: goto x86_l_fe7;
	case 4073ULL: goto x86_l_fe9;
	case 4075ULL: goto x86_l_feb;
	case 4078ULL: goto x86_l_fee;
	case 4081ULL: goto x86_l_ff1;
	case 4084ULL: goto x86_l_ff4;
	case 4087ULL: goto x86_l_ff7;
	case 4095ULL: goto x86_l_fff;
	case 4101ULL: goto x86_l_1005;
	case 4106ULL: goto x86_l_100a;
	case 4113ULL: goto x86_l_1011;
	case 4118ULL: goto x86_l_1016;
	case 4121ULL: goto x86_l_1019;
	case 4126ULL: goto x86_l_101e;
	case 4128ULL: goto x86_l_1020;
	case 4132ULL: goto x86_l_1024;
	case 4137ULL: goto x86_l_1029;
	case 4140ULL: goto x86_l_102c;
	case 4145ULL: goto x86_l_1031;
	case 4147ULL: goto x86_l_1033;
	case 4151ULL: goto x86_l_1037;
	case 4156ULL: goto x86_l_103c;
	case 4159ULL: goto x86_l_103f;
	case 4162ULL: goto x86_l_1042;
	case 4167ULL: goto x86_l_1047;
	case 4169ULL: goto x86_l_1049;
	case 4173ULL: goto x86_l_104d;
	case 4178ULL: goto x86_l_1052;
	case 4181ULL: goto x86_l_1055;
	case 4186ULL: goto x86_l_105a;
	case 4189ULL: goto x86_l_105d;
	case 4191ULL: goto x86_l_105f;
	case 4198ULL: goto x86_l_1066;
	case 4205ULL: goto x86_l_106d;
	case 4208ULL: goto x86_l_1070;
	case 4212ULL: goto x86_l_1074;
	case 4217ULL: goto x86_l_1079;
	case 4224ULL: goto x86_l_1080;
	case 4227ULL: goto x86_l_1083;
	case 4229ULL: goto x86_l_1085;
	case 4236ULL: goto x86_l_108c;
	case 4239ULL: goto x86_l_108f;
	case 4241ULL: goto x86_l_1091;
	case 4246ULL: goto x86_l_1096;
	case 4249ULL: goto x86_l_1099;
	case 4252ULL: goto x86_l_109c;
	case 4254ULL: goto x86_l_109e;
	case 4257ULL: goto x86_l_10a1;
	case 4259ULL: goto x86_l_10a3;
	case 4262ULL: goto x86_l_10a6;
	case 4266ULL: goto x86_l_10aa;
	case 4269ULL: goto x86_l_10ad;
	case 4271ULL: goto x86_l_10af;
	case 4273ULL: goto x86_l_10b1;
	case 4276ULL: goto x86_l_10b4;
	case 4279ULL: goto x86_l_10b7;
	case 4282ULL: goto x86_l_10ba;
	case 4285ULL: goto x86_l_10bd;
	case 4290ULL: goto x86_l_10c2;
	case 4298ULL: goto x86_l_10ca;
	case 4300ULL: goto x86_l_10cc;
	case 4304ULL: goto x86_l_10d0;
	case 4309ULL: goto x86_l_10d5;
	case 4312ULL: goto x86_l_10d8;
	case 4317ULL: goto x86_l_10dd;
	case 4319ULL: goto x86_l_10df;
	case 4326ULL: goto x86_l_10e6;
	case 4333ULL: goto x86_l_10ed;
	case 4336ULL: goto x86_l_10f0;
	case 4340ULL: goto x86_l_10f4;
	case 4345ULL: goto x86_l_10f9;
	case 4352ULL: goto x86_l_1100;
	case 4355ULL: goto x86_l_1103;
	case 4357ULL: goto x86_l_1105;
	case 4364ULL: goto x86_l_110c;
	case 4367ULL: goto x86_l_110f;
	case 4369ULL: goto x86_l_1111;
	case 4374ULL: goto x86_l_1116;
	case 4377ULL: goto x86_l_1119;
	case 4380ULL: goto x86_l_111c;
	case 4382ULL: goto x86_l_111e;
	case 4385ULL: goto x86_l_1121;
	case 4387ULL: goto x86_l_1123;
	case 4390ULL: goto x86_l_1126;
	case 4394ULL: goto x86_l_112a;
	case 4397ULL: goto x86_l_112d;
	case 4399ULL: goto x86_l_112f;
	case 4401ULL: goto x86_l_1131;
	case 4404ULL: goto x86_l_1134;
	case 4407ULL: goto x86_l_1137;
	case 4410ULL: goto x86_l_113a;
	case 4413ULL: goto x86_l_113d;
	case 4420ULL: goto x86_l_1144;
	case 4423ULL: goto x86_l_1147;
	case 4431ULL: goto x86_l_114f;
	case 4433ULL: goto x86_l_1151;
	case 4437ULL: goto x86_l_1155;
	case 4440ULL: goto x86_l_1158;
	case 4447ULL: goto x86_l_115f;
	case 4450ULL: goto x86_l_1162;
	case 4455ULL: goto x86_l_1167;
	case 4463ULL: goto x86_l_116f;
	case 4468ULL: goto x86_l_1174;
	case 4475ULL: goto x86_l_117b;
	case 4483ULL: goto x86_l_1183;
	case 4485ULL: goto x86_l_1185;
	case 4492ULL: goto x86_l_118c;
	case 4495ULL: goto x86_l_118f;
	case 4497ULL: goto x86_l_1191;
	case 4502ULL: goto x86_l_1196;
	case 4505ULL: goto x86_l_1199;
	case 4508ULL: goto x86_l_119c;
	case 4510ULL: goto x86_l_119e;
	case 4513ULL: goto x86_l_11a1;
	case 4515ULL: goto x86_l_11a3;
	case 4518ULL: goto x86_l_11a6;
	case 4522ULL: goto x86_l_11aa;
	case 4525ULL: goto x86_l_11ad;
	case 4527ULL: goto x86_l_11af;
	case 4529ULL: goto x86_l_11b1;
	case 4532ULL: goto x86_l_11b4;
	case 4535ULL: goto x86_l_11b7;
	case 4538ULL: goto x86_l_11ba;
	case 4541ULL: goto x86_l_11bd;
	case 4548ULL: goto x86_l_11c4;
	case 4551ULL: goto x86_l_11c7;
	case 4553ULL: goto x86_l_11c9;
	case 4560ULL: goto x86_l_11d0;
	case 4563ULL: goto x86_l_11d3;
	case 4568ULL: goto x86_l_11d8;
	case 4572ULL: goto x86_l_11dc;
	case 4577ULL: goto x86_l_11e1;
	case 4584ULL: goto x86_l_11e8;
	case 4587ULL: goto x86_l_11eb;
	case 4589ULL: goto x86_l_11ed;
	case 4596ULL: goto x86_l_11f4;
	case 4599ULL: goto x86_l_11f7;
	case 4601ULL: goto x86_l_11f9;
	case 4606ULL: goto x86_l_11fe;
	case 4609ULL: goto x86_l_1201;
	case 4617ULL: goto x86_l_1209;
	case 4619ULL: goto x86_l_120b;
	case 4622ULL: goto x86_l_120e;
	case 4624ULL: goto x86_l_1210;
	case 4627ULL: goto x86_l_1213;
	case 4631ULL: goto x86_l_1217;
	case 4634ULL: goto x86_l_121a;
	case 4636ULL: goto x86_l_121c;
	case 4638ULL: goto x86_l_121e;
	case 4641ULL: goto x86_l_1221;
	case 4644ULL: goto x86_l_1224;
	case 4647ULL: goto x86_l_1227;
	case 4650ULL: goto x86_l_122a;
	case 4657ULL: goto x86_l_1231;
	case 4660ULL: goto x86_l_1234;
	case 4666ULL: goto x86_l_123a;
	case 4673ULL: goto x86_l_1241;
	case 4676ULL: goto x86_l_1244;
	case 4681ULL: goto x86_l_1249;
	case 4685ULL: goto x86_l_124d;
	case 4690ULL: goto x86_l_1252;
	case 4697ULL: goto x86_l_1259;
	case 4700ULL: goto x86_l_125c;
	case 4702ULL: goto x86_l_125e;
	case 4709ULL: goto x86_l_1265;
	case 4712ULL: goto x86_l_1268;
	case 4714ULL: goto x86_l_126a;
	case 4717ULL: goto x86_l_126d;
	case 4725ULL: goto x86_l_1275;
	case 4729ULL: goto x86_l_1279;
	case 4734ULL: goto x86_l_127e;
	case 4737ULL: goto x86_l_1281;
	case 4739ULL: goto x86_l_1283;
	case 4742ULL: goto x86_l_1286;
	case 4744ULL: goto x86_l_1288;
	case 4752ULL: goto x86_l_1290;
	case 4756ULL: goto x86_l_1294;
	case 4761ULL: goto x86_l_1299;
	case 4764ULL: goto x86_l_129c;
	case 4766ULL: goto x86_l_129e;
	case 4769ULL: goto x86_l_12a1;
	case 4771ULL: goto x86_l_12a3;
	case 4774ULL: goto x86_l_12a6;
	case 4778ULL: goto x86_l_12aa;
	case 4781ULL: goto x86_l_12ad;
	case 4783ULL: goto x86_l_12af;
	case 4785ULL: goto x86_l_12b1;
	case 4788ULL: goto x86_l_12b4;
	case 4791ULL: goto x86_l_12b7;
	case 4794ULL: goto x86_l_12ba;
	case 4797ULL: goto x86_l_12bd;
	case 4805ULL: goto x86_l_12c5;
	case 4812ULL: goto x86_l_12cc;
	case 4815ULL: goto x86_l_12cf;
	case 4823ULL: goto x86_l_12d7;
	case 4825ULL: goto x86_l_12d9;
	case 4833ULL: goto x86_l_12e1;
	case 4837ULL: goto x86_l_12e5;
	case 4840ULL: goto x86_l_12e8;
	case 4847ULL: goto x86_l_12ef;
	case 4854ULL: goto x86_l_12f6;
	case 4861ULL: goto x86_l_12fd;
	case 4865ULL: goto x86_l_1301;
	case 4870ULL: goto x86_l_1306;
	case 4873ULL: goto x86_l_1309;
	case 4880ULL: goto x86_l_1310;
	case 4888ULL: goto x86_l_1318;
	case 4894ULL: goto x86_l_131e;
	case 4902ULL: goto x86_l_1326;
	case 4909ULL: goto x86_l_132d;
	case 4911ULL: goto x86_l_132f;
	case 4920ULL: goto x86_l_1338;
	case 4926ULL: goto x86_l_133e;
	case 4928ULL: goto x86_l_1340;
	case 4932ULL: goto x86_l_1344;
	case 4939ULL: goto x86_l_134b;
	case 4944ULL: goto x86_l_1350;
	case 4952ULL: goto x86_l_1358;
	case 4957ULL: goto x86_l_135d;
	case 4959ULL: goto x86_l_135f;
	case 4962ULL: goto x86_l_1362;
	case 4964ULL: goto x86_l_1364;
	case 4967ULL: goto x86_l_1367;
	case 4975ULL: goto x86_l_136f;
	case 4982ULL: goto x86_l_1376;
	case 4989ULL: goto x86_l_137d;
	case 4993ULL: goto x86_l_1381;
	case 4998ULL: goto x86_l_1386;
	case 5001ULL: goto x86_l_1389;
	case 5006ULL: goto x86_l_138e;
	case 5009ULL: goto x86_l_1391;
	case 5011ULL: goto x86_l_1393;
	case 5015ULL: goto x86_l_1397;
	case 5020ULL: goto x86_l_139c;
	case 5024ULL: goto x86_l_13a0;
	case 5029ULL: goto x86_l_13a5;
	case 5032ULL: goto x86_l_13a8;
	case 5037ULL: goto x86_l_13ad;
	case 5039ULL: goto x86_l_13af;
	case 5043ULL: goto x86_l_13b3;
	case 5047ULL: goto x86_l_13b7;
	case 5052ULL: goto x86_l_13bc;
	case 5055ULL: goto x86_l_13bf;
	case 5060ULL: goto x86_l_13c4;
	case 5062ULL: goto x86_l_13c6;
	case 5066ULL: goto x86_l_13ca;
	case 5070ULL: goto x86_l_13ce;
	case 5075ULL: goto x86_l_13d3;
	case 5078ULL: goto x86_l_13d6;
	case 5083ULL: goto x86_l_13db;
	case 5085ULL: goto x86_l_13dd;
	case 5088ULL: goto x86_l_13e0;
	case 5092ULL: goto x86_l_13e4;
	case 5097ULL: goto x86_l_13e9;
	case 5101ULL: goto x86_l_13ed;
	case 5106ULL: goto x86_l_13f2;
	case 5109ULL: goto x86_l_13f5;
	case 5114ULL: goto x86_l_13fa;
	case 5117ULL: goto x86_l_13fd;
	case 5119ULL: goto x86_l_13ff;
	case 5123ULL: goto x86_l_1403;
	case 5128ULL: goto x86_l_1408;
	case 5131ULL: goto x86_l_140b;
	case 5136ULL: goto x86_l_1410;
	case 5139ULL: goto x86_l_1413;
	case 5141ULL: goto x86_l_1415;
	case 5144ULL: goto x86_l_1418;
	case 5148ULL: goto x86_l_141c;
	case 5152ULL: goto x86_l_1420;
	case 5156ULL: goto x86_l_1424;
	case 5161ULL: goto x86_l_1429;
	case 5164ULL: goto x86_l_142c;
	case 5169ULL: goto x86_l_1431;
	case 5171ULL: goto x86_l_1433;
	case 5174ULL: goto x86_l_1436;
	case 5178ULL: goto x86_l_143a;
	case 5183ULL: goto x86_l_143f;
	case 5186ULL: goto x86_l_1442;
	case 5191ULL: goto x86_l_1447;
	case 5194ULL: goto x86_l_144a;
	case 5196ULL: goto x86_l_144c;
	case 5200ULL: goto x86_l_1450;
	case 5204ULL: goto x86_l_1454;
	case 5209ULL: goto x86_l_1459;
	case 5212ULL: goto x86_l_145c;
	case 5217ULL: goto x86_l_1461;
	case 5219ULL: goto x86_l_1463;
	case 5223ULL: goto x86_l_1467;
	case 5228ULL: goto x86_l_146c;
	case 5231ULL: goto x86_l_146f;
	case 5236ULL: goto x86_l_1474;
	case 5239ULL: goto x86_l_1477;
	case 5241ULL: goto x86_l_1479;
	case 5244ULL: goto x86_l_147c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e83:
	/* 0xe83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e85:
	/* 0xe85: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e89:
	/* 0xe89: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_e8d:
	/* 0xe8d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e92:
	/* 0xe92: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_e95:
	/* 0xe95: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e9a:
	/* 0xe9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e9c:
	/* 0xe9c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ea1:
	/* 0xea1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ea5:
	/* 0xea5: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_ead:
	/* 0xead: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_eb2:
	/* 0xeb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eb4:
	/* 0xeb4: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_ebb:
	/* 0xebb: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ebf:
	/* 0xebf: mov    rbx,QWORD PTR [r14+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_ec6:
	/* 0xec6: mov    r15,QWORD PTR [r14+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_ecd:
	/* 0xecd: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_ed0:
	/* 0xed0: mov    WORD PTR [rsp],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ed4:
	/* 0xed4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ed9:
	/* 0xed9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_ee0:
	/* 0xee0: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_ee3:
	/* 0xee3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee5:
	/* 0xee5: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_eec:
	/* 0xeec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_eef:
	/* 0xeef: je     f10 <trace_security_bpf+0xf10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f10;
	}
x86_l_ef1:
	/* 0xef1: lea    rsi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ef5:
	/* 0xef5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_efa:
	/* 0xefa: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_efd:
	/* 0xefd: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_eff:
	/* 0xeff: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f02:
	/* 0xf02: je     f10 <trace_security_bpf+0xf10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f10;
	}
x86_l_f04:
	/* 0xf04: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f07:
	/* 0xf07: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f0b:
	/* 0xf0b: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f0e:
	/* 0xf0e: jmp    f12 <trace_security_bpf+0xf12> */
	goto x86_l_f12;
x86_l_f10:
	/* 0xf10: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f12:
	/* 0xf12: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f15:
	/* 0xf15: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_f18:
	/* 0xf18: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f1b:
	/* 0xf1b: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_f1e:
	/* 0xf1e: cmp    QWORD PTR [r14+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_f26:
	/* 0xf26: je     ff7 <trace_security_bpf+0xff7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ff7;
	}
x86_l_f2c:
	/* 0xf2c: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_f33:
	/* 0xf33: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f37:
	/* 0xf37: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f3c:
	/* 0xf3c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_f3f:
	/* 0xf3f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f44:
	/* 0xf44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f46:
	/* 0xf46: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f4a:
	/* 0xf4a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f4f:
	/* 0xf4f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_f52:
	/* 0xf52: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f57:
	/* 0xf57: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_f5a:
	/* 0xf5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f5c:
	/* 0xf5c: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f5f:
	/* 0xf5f: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_f63:
	/* 0xf63: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_f67:
	/* 0xf67: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f6b:
	/* 0xf6b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f70:
	/* 0xf70: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_f73:
	/* 0xf73: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f78:
	/* 0xf78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f7a:
	/* 0xf7a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f7e:
	/* 0xf7e: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_f82:
	/* 0xf82: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f87:
	/* 0xf87: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_f8a:
	/* 0xf8a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f8f:
	/* 0xf8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f91:
	/* 0xf91: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f94:
	/* 0xf94: mov    DWORD PTR [r14+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f98:
	/* 0xf98: mov    rbx,QWORD PTR [r14+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_f9f:
	/* 0xf9f: mov    r15,QWORD PTR [r14+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_fa6:
	/* 0xfa6: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_fa9:
	/* 0xfa9: mov    WORD PTR [rsp],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fad:
	/* 0xfad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fb2:
	/* 0xfb2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_fb9:
	/* 0xfb9: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_fbc:
	/* 0xfbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fbe:
	/* 0xfbe: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_fc5:
	/* 0xfc5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fc8:
	/* 0xfc8: je     fe9 <trace_security_bpf+0xfe9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fe9;
	}
x86_l_fca:
	/* 0xfca: lea    rsi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_fce:
	/* 0xfce: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_fd3:
	/* 0xfd3: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_fd6:
	/* 0xfd6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_fd8:
	/* 0xfd8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fdb:
	/* 0xfdb: je     fe9 <trace_security_bpf+0xfe9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fe9;
	}
x86_l_fdd:
	/* 0xfdd: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fe0:
	/* 0xfe0: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fe4:
	/* 0xfe4: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_fe7:
	/* 0xfe7: jmp    feb <trace_security_bpf+0xfeb> */
	goto x86_l_feb;
x86_l_fe9:
	/* 0xfe9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_feb:
	/* 0xfeb: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_fee:
	/* 0xfee: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_ff1:
	/* 0xff1: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_ff4:
	/* 0xff4: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_ff7:
	/* 0xff7: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_fff:
	/* 0xfff: je     10c2 <trace_security_bpf+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10c2;
	}
x86_l_1005:
	/* 0x1005: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_100a:
	/* 0x100a: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1011:
	/* 0x1011: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1016:
	/* 0x1016: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1019:
	/* 0x1019: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_101e:
	/* 0x101e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1020:
	/* 0x1020: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1024:
	/* 0x1024: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1029:
	/* 0x1029: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_102c:
	/* 0x102c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1031:
	/* 0x1031: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1033:
	/* 0x1033: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1037:
	/* 0x1037: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_103c:
	/* 0x103c: mov    r15,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSP, X86_WIDTH_64);
x86_l_103f:
	/* 0x103f: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1042:
	/* 0x1042: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_1047:
	/* 0x1047: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1049:
	/* 0x1049: lea    rbx,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_104d:
	/* 0x104d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1052:
	/* 0x1052: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1055:
	/* 0x1055: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_105a:
	/* 0x105a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_105d:
	/* 0x105d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_105f:
	/* 0x105f: mov    r15,QWORD PTR [r14+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_1066:
	/* 0x1066: mov    r13,QWORD PTR [r14+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_106d:
	/* 0x106d: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1070:
	/* 0x1070: mov    WORD PTR [rsp],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1074:
	/* 0x1074: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1079:
	/* 0x1079: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_1080:
	/* 0x1080: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1083:
	/* 0x1083: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1085:
	/* 0x1085: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_108c:
	/* 0x108c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_108f:
	/* 0x108f: je     10af <trace_security_bpf+0x10af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10af;
	}
x86_l_1091:
	/* 0x1091: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1096:
	/* 0x1096: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1099:
	/* 0x1099: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_109c:
	/* 0x109c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_109e:
	/* 0x109e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10a1:
	/* 0x10a1: je     10af <trace_security_bpf+0x10af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10af;
	}
x86_l_10a3:
	/* 0x10a3: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10a6:
	/* 0x10a6: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10aa:
	/* 0x10aa: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_10ad:
	/* 0x10ad: jmp    10b1 <trace_security_bpf+0x10b1> */
	goto x86_l_10b1;
x86_l_10af:
	/* 0x10af: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10b1:
	/* 0x10b1: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_10b4:
	/* 0x10b4: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_10b7:
	/* 0x10b7: or     rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_10ba:
	/* 0x10ba: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_10bd:
	/* 0x10bd: movzx  ebp,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_10c2:
	/* 0x10c2: cmp    QWORD PTR [r14+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_10ca:
	/* 0x10ca: je     113d <trace_security_bpf+0x113d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_113d;
	}
x86_l_10cc:
	/* 0x10cc: lea    rbx,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_10d0:
	/* 0x10d0: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_10d5:
	/* 0x10d5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10d8:
	/* 0x10d8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_10dd:
	/* 0x10dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10df:
	/* 0x10df: mov    r15,QWORD PTR [r14+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_10e6:
	/* 0x10e6: mov    r13,QWORD PTR [r14+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_10ed:
	/* 0x10ed: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_10f0:
	/* 0x10f0: mov    WORD PTR [rsp],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10f4:
	/* 0x10f4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10f9:
	/* 0x10f9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_1100:
	/* 0x1100: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1103:
	/* 0x1103: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1105:
	/* 0x1105: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_110c:
	/* 0x110c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_110f:
	/* 0x110f: je     112f <trace_security_bpf+0x112f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_112f;
	}
x86_l_1111:
	/* 0x1111: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1116:
	/* 0x1116: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1119:
	/* 0x1119: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_111c:
	/* 0x111c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_111e:
	/* 0x111e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1121:
	/* 0x1121: je     112f <trace_security_bpf+0x112f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_112f;
	}
x86_l_1123:
	/* 0x1123: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1126:
	/* 0x1126: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_112a:
	/* 0x112a: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_112d:
	/* 0x112d: jmp    1131 <trace_security_bpf+0x1131> */
	goto x86_l_1131;
x86_l_112f:
	/* 0x112f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1131:
	/* 0x1131: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1134:
	/* 0x1134: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1137:
	/* 0x1137: or     rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_113a:
	/* 0x113a: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_113d:
	/* 0x113d: mov    rbx,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_1144:
	/* 0x1144: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1147:
	/* 0x1147: mov    rbp,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_114f:
	/* 0x114f: je     11bd <trace_security_bpf+0x11bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11bd;
	}
x86_l_1151:
	/* 0x1151: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1155:
	/* 0x1155: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1158:
	/* 0x1158: mov    r15,QWORD PTR [r14+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_115f:
	/* 0x115f: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1162:
	/* 0x1162: movzx  eax,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_1167:
	/* 0x1167: mov    WORD PTR [rsp+0xb0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_116f:
	/* 0x116f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1174:
	/* 0x1174: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_117b:
	/* 0x117b: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1183:
	/* 0x1183: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1185:
	/* 0x1185: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_118c:
	/* 0x118c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_118f:
	/* 0x118f: je     11af <trace_security_bpf+0x11af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11af;
	}
x86_l_1191:
	/* 0x1191: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1196:
	/* 0x1196: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1199:
	/* 0x1199: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_119c:
	/* 0x119c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_119e:
	/* 0x119e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11a1:
	/* 0x11a1: je     11af <trace_security_bpf+0x11af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11af;
	}
x86_l_11a3:
	/* 0x11a3: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11a6:
	/* 0x11a6: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11aa:
	/* 0x11aa: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_11ad:
	/* 0x11ad: jmp    11b1 <trace_security_bpf+0x11b1> */
	goto x86_l_11b1;
x86_l_11af:
	/* 0x11af: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11b1:
	/* 0x11b1: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_11b4:
	/* 0x11b4: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_11b7:
	/* 0x11b7: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_11ba:
	/* 0x11ba: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_11bd:
	/* 0x11bd: mov    rbx,QWORD PTR [r14+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_11c4:
	/* 0x11c4: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_11c7:
	/* 0x11c7: je     122a <trace_security_bpf+0x122a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_122a;
	}
x86_l_11c9:
	/* 0x11c9: mov    r15,QWORD PTR [r14+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_11d0:
	/* 0x11d0: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_11d3:
	/* 0x11d3: movzx  eax,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_11d8:
	/* 0x11d8: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11dc:
	/* 0x11dc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11e1:
	/* 0x11e1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_11e8:
	/* 0x11e8: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_11eb:
	/* 0x11eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ed:
	/* 0x11ed: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_11f4:
	/* 0x11f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11f7:
	/* 0x11f7: je     121c <trace_security_bpf+0x121c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_121c;
	}
x86_l_11f9:
	/* 0x11f9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11fe:
	/* 0x11fe: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1201:
	/* 0x1201: mov    rsi,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1209:
	/* 0x1209: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_120b:
	/* 0x120b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_120e:
	/* 0x120e: je     121c <trace_security_bpf+0x121c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_121c;
	}
x86_l_1210:
	/* 0x1210: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1213:
	/* 0x1213: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1217:
	/* 0x1217: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_121a:
	/* 0x121a: jmp    121e <trace_security_bpf+0x121e> */
	goto x86_l_121e;
x86_l_121c:
	/* 0x121c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_121e:
	/* 0x121e: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1221:
	/* 0x1221: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1224:
	/* 0x1224: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1227:
	/* 0x1227: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_122a:
	/* 0x122a: mov    r15,QWORD PTR [r14+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_1231:
	/* 0x1231: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1234:
	/* 0x1234: je     12c5 <trace_security_bpf+0x12c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12c5;
	}
x86_l_123a:
	/* 0x123a: mov    r13,QWORD PTR [r14+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_1241:
	/* 0x1241: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1244:
	/* 0x1244: movzx  eax,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_1249:
	/* 0x1249: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_124d:
	/* 0x124d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1252:
	/* 0x1252: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_1259:
	/* 0x1259: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_125c:
	/* 0x125c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_125e:
	/* 0x125e: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1265:
	/* 0x1265: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1268:
	/* 0x1268: je     12af <trace_security_bpf+0x12af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12af;
	}
x86_l_126a:
	/* 0x126a: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_126d:
	/* 0x126d: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1275:
	/* 0x1275: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1279:
	/* 0x1279: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_127e:
	/* 0x127e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1281:
	/* 0x1281: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1283:
	/* 0x1283: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1286:
	/* 0x1286: jne    12a3 <trace_security_bpf+0x12a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_12a3;
	}
x86_l_1288:
	/* 0x1288: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1290:
	/* 0x1290: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1294:
	/* 0x1294: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1299:
	/* 0x1299: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_129c:
	/* 0x129c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_129e:
	/* 0x129e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12a1:
	/* 0x12a1: je     12af <trace_security_bpf+0x12af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12af;
	}
x86_l_12a3:
	/* 0x12a3: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12a6:
	/* 0x12a6: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12aa:
	/* 0x12aa: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12ad:
	/* 0x12ad: jmp    12b1 <trace_security_bpf+0x12b1> */
	goto x86_l_12b1;
x86_l_12af:
	/* 0x12af: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12b1:
	/* 0x12b1: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_12b4:
	/* 0x12b4: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_12b7:
	/* 0x12b7: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_12ba:
	/* 0x12ba: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_12bd:
	/* 0x12bd: mov    rbp,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_12c5:
	/* 0x12c5: mov    rax,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_12cc:
	/* 0x12cc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12cf:
	/* 0x12cf: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_12d7:
	/* 0x12d7: je     12e8 <trace_security_bpf+0x12e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12e8;
	}
x86_l_12d9:
	/* 0x12d9: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_12e1:
	/* 0x12e1: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_12e5:
	/* 0x12e5: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_12e8:
	/* 0x12e8: and    r12,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_12ef:
	/* 0x12ef: mov    rax,QWORD PTR [r14+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_12f6:
	/* 0x12f6: lea    r13,[r14+0x7d8c] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_12fd:
	/* 0x12fd: lea    rcx,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1301:
	/* 0x1301: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1306:
	/* 0x1306: and    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1309:
	/* 0x1309: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1310:
	/* 0x1310: mov    r12,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1318:
	/* 0x1318: je     1788 <trace_security_bpf+0x1788> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6024ULL;
	}
x86_l_131e:
	/* 0x131e: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1326:
	/* 0x1326: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_132d:
	/* 0x132d: ja     1376 <trace_security_bpf+0x1376> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1376;
	}
x86_l_132f:
	/* 0x132f: mov    BYTE PTR [r14+rbx*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519552ULL);
x86_l_1338:
	/* 0x1338: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_133e:
	/* 0x133e: ja     1376 <trace_security_bpf+0x1376> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1376;
	}
x86_l_1340:
	/* 0x1340: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1344:
	/* 0x1344: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_134b:
	/* 0x134b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1350:
	/* 0x1350: lea    rdx,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1358:
	/* 0x1358: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_135d:
	/* 0x135d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_135f:
	/* 0x135f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1362:
	/* 0x1362: js     1376 <trace_security_bpf+0x1376> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1376;
	}
x86_l_1364:
	/* 0x1364: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1367:
	/* 0x1367: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_136f:
	/* 0x136f: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1376:
	/* 0x1376: mov    rbx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_137d:
	/* 0x137d: lea    r15,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1381:
	/* 0x1381: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1386:
	/* 0x1386: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1389:
	/* 0x1389: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_138e:
	/* 0x138e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1391:
	/* 0x1391: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1393:
	/* 0x1393: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1397:
	/* 0x1397: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_139c:
	/* 0x139c: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13a0:
	/* 0x13a0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13a5:
	/* 0x13a5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_13a8:
	/* 0x13a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13ad:
	/* 0x13ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13af:
	/* 0x13af: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13b3:
	/* 0x13b3: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_13b7:
	/* 0x13b7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13bc:
	/* 0x13bc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_13bf:
	/* 0x13bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13c4:
	/* 0x13c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13c6:
	/* 0x13c6: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13ca:
	/* 0x13ca: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_13ce:
	/* 0x13ce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13d3:
	/* 0x13d3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_13d6:
	/* 0x13d6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13db:
	/* 0x13db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13dd:
	/* 0x13dd: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13e0:
	/* 0x13e0: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_13e4:
	/* 0x13e4: mov    QWORD PTR [rsp+0x58],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_13e9:
	/* 0x13e9: lea    r12,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13ed:
	/* 0x13ed: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13f2:
	/* 0x13f2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_13f5:
	/* 0x13f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13fa:
	/* 0x13fa: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_13fd:
	/* 0x13fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13ff:
	/* 0x13ff: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1403:
	/* 0x1403: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1408:
	/* 0x1408: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_140b:
	/* 0x140b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1410:
	/* 0x1410: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1413:
	/* 0x1413: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1415:
	/* 0x1415: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1418:
	/* 0x1418: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_141c:
	/* 0x141c: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1420:
	/* 0x1420: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1424:
	/* 0x1424: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1429:
	/* 0x1429: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_142c:
	/* 0x142c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1431:
	/* 0x1431: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1433:
	/* 0x1433: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1436:
	/* 0x1436: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_143a:
	/* 0x143a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_143f:
	/* 0x143f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1442:
	/* 0x1442: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1447:
	/* 0x1447: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_144a:
	/* 0x144a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_144c:
	/* 0x144c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1450:
	/* 0x1450: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1454:
	/* 0x1454: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1459:
	/* 0x1459: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_145c:
	/* 0x145c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1461:
	/* 0x1461: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1463:
	/* 0x1463: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1467:
	/* 0x1467: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_146c:
	/* 0x146c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_146f:
	/* 0x146f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1474:
	/* 0x1474: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1477:
	/* 0x1477: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1479:
	/* 0x1479: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_147c:
	/* 0x147c: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
	return 5248ULL;
}

static __noinline __u64 tracee_trace_security_bpf_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5248ULL: goto x86_l_1480;
	case 5252ULL: goto x86_l_1484;
	case 5256ULL: goto x86_l_1488;
	case 5261ULL: goto x86_l_148d;
	case 5264ULL: goto x86_l_1490;
	case 5269ULL: goto x86_l_1495;
	case 5271ULL: goto x86_l_1497;
	case 5274ULL: goto x86_l_149a;
	case 5278ULL: goto x86_l_149e;
	case 5283ULL: goto x86_l_14a3;
	case 5286ULL: goto x86_l_14a6;
	case 5291ULL: goto x86_l_14ab;
	case 5294ULL: goto x86_l_14ae;
	case 5296ULL: goto x86_l_14b0;
	case 5300ULL: goto x86_l_14b4;
	case 5305ULL: goto x86_l_14b9;
	case 5308ULL: goto x86_l_14bc;
	case 5313ULL: goto x86_l_14c1;
	case 5316ULL: goto x86_l_14c4;
	case 5318ULL: goto x86_l_14c6;
	case 5321ULL: goto x86_l_14c9;
	case 5325ULL: goto x86_l_14cd;
	case 5329ULL: goto x86_l_14d1;
	case 5333ULL: goto x86_l_14d5;
	case 5338ULL: goto x86_l_14da;
	case 5341ULL: goto x86_l_14dd;
	case 5346ULL: goto x86_l_14e2;
	case 5348ULL: goto x86_l_14e4;
	case 5352ULL: goto x86_l_14e8;
	case 5356ULL: goto x86_l_14ec;
	case 5361ULL: goto x86_l_14f1;
	case 5364ULL: goto x86_l_14f4;
	case 5369ULL: goto x86_l_14f9;
	case 5371ULL: goto x86_l_14fb;
	case 5375ULL: goto x86_l_14ff;
	case 5379ULL: goto x86_l_1503;
	case 5384ULL: goto x86_l_1508;
	case 5387ULL: goto x86_l_150b;
	case 5392ULL: goto x86_l_1510;
	case 5395ULL: goto x86_l_1513;
	case 5397ULL: goto x86_l_1515;
	case 5401ULL: goto x86_l_1519;
	case 5406ULL: goto x86_l_151e;
	case 5409ULL: goto x86_l_1521;
	case 5414ULL: goto x86_l_1526;
	case 5417ULL: goto x86_l_1529;
	case 5419ULL: goto x86_l_152b;
	case 5422ULL: goto x86_l_152e;
	case 5426ULL: goto x86_l_1532;
	case 5430ULL: goto x86_l_1536;
	case 5434ULL: goto x86_l_153a;
	case 5439ULL: goto x86_l_153f;
	case 5442ULL: goto x86_l_1542;
	case 5447ULL: goto x86_l_1547;
	case 5449ULL: goto x86_l_1549;
	case 5453ULL: goto x86_l_154d;
	case 5457ULL: goto x86_l_1551;
	case 5462ULL: goto x86_l_1556;
	case 5465ULL: goto x86_l_1559;
	case 5470ULL: goto x86_l_155e;
	case 5472ULL: goto x86_l_1560;
	case 5476ULL: goto x86_l_1564;
	case 5478ULL: goto x86_l_1566;
	case 5483ULL: goto x86_l_156b;
	case 5486ULL: goto x86_l_156e;
	case 5491ULL: goto x86_l_1573;
	case 5494ULL: goto x86_l_1576;
	case 5496ULL: goto x86_l_1578;
	case 5500ULL: goto x86_l_157c;
	case 5505ULL: goto x86_l_1581;
	case 5508ULL: goto x86_l_1584;
	case 5513ULL: goto x86_l_1589;
	case 5516ULL: goto x86_l_158c;
	case 5518ULL: goto x86_l_158e;
	case 5521ULL: goto x86_l_1591;
	case 5525ULL: goto x86_l_1595;
	case 5529ULL: goto x86_l_1599;
	case 5533ULL: goto x86_l_159d;
	case 5538ULL: goto x86_l_15a2;
	case 5541ULL: goto x86_l_15a5;
	case 5546ULL: goto x86_l_15aa;
	case 5548ULL: goto x86_l_15ac;
	case 5551ULL: goto x86_l_15af;
	case 5555ULL: goto x86_l_15b3;
	case 5559ULL: goto x86_l_15b7;
	case 5564ULL: goto x86_l_15bc;
	case 5571ULL: goto x86_l_15c3;
	case 5576ULL: goto x86_l_15c8;
	case 5579ULL: goto x86_l_15cb;
	case 5584ULL: goto x86_l_15d0;
	case 5587ULL: goto x86_l_15d3;
	case 5589ULL: goto x86_l_15d5;
	case 5593ULL: goto x86_l_15d9;
	case 5597ULL: goto x86_l_15dd;
	case 5602ULL: goto x86_l_15e2;
	case 5605ULL: goto x86_l_15e5;
	case 5610ULL: goto x86_l_15ea;
	case 5612ULL: goto x86_l_15ec;
	case 5617ULL: goto x86_l_15f1;
	case 5621ULL: goto x86_l_15f5;
	case 5629ULL: goto x86_l_15fd;
	case 5634ULL: goto x86_l_1602;
	case 5636ULL: goto x86_l_1604;
	case 5643ULL: goto x86_l_160b;
	case 5647ULL: goto x86_l_160f;
	case 5652ULL: goto x86_l_1614;
	case 5654ULL: goto x86_l_1616;
	case 5658ULL: goto x86_l_161a;
	case 5662ULL: goto x86_l_161e;
	case 5667ULL: goto x86_l_1623;
	case 5670ULL: goto x86_l_1626;
	case 5675ULL: goto x86_l_162b;
	case 5677ULL: goto x86_l_162d;
	case 5681ULL: goto x86_l_1631;
	case 5685ULL: goto x86_l_1635;
	case 5690ULL: goto x86_l_163a;
	case 5694ULL: goto x86_l_163e;
	case 5699ULL: goto x86_l_1643;
	case 5702ULL: goto x86_l_1646;
	case 5707ULL: goto x86_l_164b;
	case 5709ULL: goto x86_l_164d;
	case 5713ULL: goto x86_l_1651;
	case 5717ULL: goto x86_l_1655;
	case 5721ULL: goto x86_l_1659;
	case 5726ULL: goto x86_l_165e;
	case 5729ULL: goto x86_l_1661;
	case 5734ULL: goto x86_l_1666;
	case 5737ULL: goto x86_l_1669;
	case 5739ULL: goto x86_l_166b;
	case 5743ULL: goto x86_l_166f;
	case 5747ULL: goto x86_l_1673;
	case 5752ULL: goto x86_l_1678;
	case 5755ULL: goto x86_l_167b;
	case 5760ULL: goto x86_l_1680;
	case 5763ULL: goto x86_l_1683;
	case 5765ULL: goto x86_l_1685;
	case 5769ULL: goto x86_l_1689;
	case 5777ULL: goto x86_l_1691;
	case 5779ULL: goto x86_l_1693;
	case 5784ULL: goto x86_l_1698;
	case 5788ULL: goto x86_l_169c;
	case 5796ULL: goto x86_l_16a4;
	case 5804ULL: goto x86_l_16ac;
	case 5809ULL: goto x86_l_16b1;
	case 5814ULL: goto x86_l_16b6;
	case 5816ULL: goto x86_l_16b8;
	case 5821ULL: goto x86_l_16bd;
	case 5824ULL: goto x86_l_16c0;
	case 5829ULL: goto x86_l_16c5;
	case 5832ULL: goto x86_l_16c8;
	case 5834ULL: goto x86_l_16ca;
	case 5838ULL: goto x86_l_16ce;
	case 5843ULL: goto x86_l_16d3;
	case 5846ULL: goto x86_l_16d6;
	case 5851ULL: goto x86_l_16db;
	case 5853ULL: goto x86_l_16dd;
	case 5857ULL: goto x86_l_16e1;
	case 5862ULL: goto x86_l_16e6;
	case 5865ULL: goto x86_l_16e9;
	case 5868ULL: goto x86_l_16ec;
	case 5873ULL: goto x86_l_16f1;
	case 5875ULL: goto x86_l_16f3;
	case 5879ULL: goto x86_l_16f7;
	case 5884ULL: goto x86_l_16fc;
	case 5889ULL: goto x86_l_1701;
	case 5892ULL: goto x86_l_1704;
	case 5894ULL: goto x86_l_1706;
	case 5899ULL: goto x86_l_170b;
	case 5907ULL: goto x86_l_1713;
	case 5910ULL: goto x86_l_1716;
	case 5915ULL: goto x86_l_171b;
	case 5920ULL: goto x86_l_1720;
	case 5922ULL: goto x86_l_1722;
	case 5930ULL: goto x86_l_172a;
	case 5936ULL: goto x86_l_1730;
	case 5938ULL: goto x86_l_1732;
	case 5943ULL: goto x86_l_1737;
	case 5950ULL: goto x86_l_173e;
	case 5955ULL: goto x86_l_1743;
	case 5958ULL: goto x86_l_1746;
	case 5960ULL: goto x86_l_1748;
	case 5962ULL: goto x86_l_174a;
	case 5964ULL: goto x86_l_174c;
	case 5968ULL: goto x86_l_1750;
	case 5976ULL: goto x86_l_1758;
	case 5981ULL: goto x86_l_175d;
	case 5986ULL: goto x86_l_1762;
	case 5989ULL: goto x86_l_1765;
	case 5995ULL: goto x86_l_176b;
	case 5999ULL: goto x86_l_176f;
	case 6004ULL: goto x86_l_1774;
	case 6011ULL: goto x86_l_177b;
	case 6016ULL: goto x86_l_1780;
	case 6019ULL: goto x86_l_1783;
	case 6022ULL: goto x86_l_1786;
	case 6024ULL: goto x86_l_1788;
	case 6028ULL: goto x86_l_178c;
	case 6033ULL: goto x86_l_1791;
	case 6041ULL: goto x86_l_1799;
	case 6051ULL: goto x86_l_17a3;
	case 6059ULL: goto x86_l_17ab;
	case 6067ULL: goto x86_l_17b3;
	case 6075ULL: goto x86_l_17bb;
	case 6083ULL: goto x86_l_17c3;
	case 6091ULL: goto x86_l_17cb;
	case 6099ULL: goto x86_l_17d3;
	case 6107ULL: goto x86_l_17db;
	case 6115ULL: goto x86_l_17e3;
	case 6123ULL: goto x86_l_17eb;
	case 6134ULL: goto x86_l_17f6;
	case 6139ULL: goto x86_l_17fb;
	case 6146ULL: goto x86_l_1802;
	case 6154ULL: goto x86_l_180a;
	case 6159ULL: goto x86_l_180f;
	case 6166ULL: goto x86_l_1816;
	case 6174ULL: goto x86_l_181e;
	case 6176ULL: goto x86_l_1820;
	case 6179ULL: goto x86_l_1823;
	case 6185ULL: goto x86_l_1829;
	case 6190ULL: goto x86_l_182e;
	case 6193ULL: goto x86_l_1831;
	case 6196ULL: goto x86_l_1834;
	case 6198ULL: goto x86_l_1836;
	case 6201ULL: goto x86_l_1839;
	case 6207ULL: goto x86_l_183f;
	case 6211ULL: goto x86_l_1843;
	case 6218ULL: goto x86_l_184a;
	case 6221ULL: goto x86_l_184d;
	case 6228ULL: goto x86_l_1854;
	case 6235ULL: goto x86_l_185b;
	case 6239ULL: goto x86_l_185f;
	case 6246ULL: goto x86_l_1866;
	case 6250ULL: goto x86_l_186a;
	case 6257ULL: goto x86_l_1871;
	case 6261ULL: goto x86_l_1875;
	case 6268ULL: goto x86_l_187c;
	case 6272ULL: goto x86_l_1880;
	case 6279ULL: goto x86_l_1887;
	case 6283ULL: goto x86_l_188b;
	case 6287ULL: goto x86_l_188f;
	case 6294ULL: goto x86_l_1896;
	case 6301ULL: goto x86_l_189d;
	case 6305ULL: goto x86_l_18a1;
	case 6309ULL: goto x86_l_18a5;
	case 6311ULL: goto x86_l_18a7;
	case 6314ULL: goto x86_l_18aa;
	case 6317ULL: goto x86_l_18ad;
	case 6324ULL: goto x86_l_18b4;
	case 6332ULL: goto x86_l_18bc;
	case 6338ULL: goto x86_l_18c2;
	case 6343ULL: goto x86_l_18c7;
	case 6350ULL: goto x86_l_18ce;
	case 6353ULL: goto x86_l_18d1;
	case 6359ULL: goto x86_l_18d7;
	case 6366ULL: goto x86_l_18de;
	case 6369ULL: goto x86_l_18e1;
	case 6372ULL: goto x86_l_18e4;
	case 6375ULL: goto x86_l_18e7;
	case 6379ULL: goto x86_l_18eb;
	case 6382ULL: goto x86_l_18ee;
	case 6385ULL: goto x86_l_18f1;
	case 6392ULL: goto x86_l_18f8;
	case 6395ULL: goto x86_l_18fb;
	case 6402ULL: goto x86_l_1902;
	case 6405ULL: goto x86_l_1905;
	case 6407ULL: goto x86_l_1907;
	case 6409ULL: goto x86_l_1909;
	case 6416ULL: goto x86_l_1910;
	case 6419ULL: goto x86_l_1913;
	case 6422ULL: goto x86_l_1916;
	case 6425ULL: goto x86_l_1919;
	case 6432ULL: goto x86_l_1920;
	case 6435ULL: goto x86_l_1923;
	case 6438ULL: goto x86_l_1926;
	case 6445ULL: goto x86_l_192d;
	case 6448ULL: goto x86_l_1930;
	case 6450ULL: goto x86_l_1932;
	case 6454ULL: goto x86_l_1936;
	case 6457ULL: goto x86_l_1939;
	case 6460ULL: goto x86_l_193c;
	case 6463ULL: goto x86_l_193f;
	case 6470ULL: goto x86_l_1946;
	case 6473ULL: goto x86_l_1949;
	case 6476ULL: goto x86_l_194c;
	case 6483ULL: goto x86_l_1953;
	case 6486ULL: goto x86_l_1956;
	case 6488ULL: goto x86_l_1958;
	case 6491ULL: goto x86_l_195b;
	case 6499ULL: goto x86_l_1963;
	case 6503ULL: goto x86_l_1967;
	case 6506ULL: goto x86_l_196a;
	case 6513ULL: goto x86_l_1971;
	case 6516ULL: goto x86_l_1974;
	case 6519ULL: goto x86_l_1977;
	case 6524ULL: goto x86_l_197c;
	case 6531ULL: goto x86_l_1983;
	case 6534ULL: goto x86_l_1986;
	case 6539ULL: goto x86_l_198b;
	case 6545ULL: goto x86_l_1991;
	case 6552ULL: goto x86_l_1998;
	case 6560ULL: goto x86_l_19a0;
	case 6567ULL: goto x86_l_19a7;
	case 6572ULL: goto x86_l_19ac;
	case 6579ULL: goto x86_l_19b3;
	case 6587ULL: goto x86_l_19bb;
	case 6591ULL: goto x86_l_19bf;
	case 6596ULL: goto x86_l_19c4;
	case 6603ULL: goto x86_l_19cb;
	case 6606ULL: goto x86_l_19ce;
	case 6608ULL: goto x86_l_19d0;
	case 6611ULL: goto x86_l_19d3;
	case 6615ULL: goto x86_l_19d7;
	case 6619ULL: goto x86_l_19db;
	case 6626ULL: goto x86_l_19e2;
	case 6629ULL: goto x86_l_19e5;
	case 6631ULL: goto x86_l_19e7;
	case 6636ULL: goto x86_l_19ec;
	case 6639ULL: goto x86_l_19ef;
	case 6642ULL: goto x86_l_19f2;
	case 6644ULL: goto x86_l_19f4;
	case 6647ULL: goto x86_l_19f7;
	case 6649ULL: goto x86_l_19f9;
	case 6652ULL: goto x86_l_19fc;
	case 6656ULL: goto x86_l_1a00;
	case 6659ULL: goto x86_l_1a03;
	case 6661ULL: goto x86_l_1a05;
	case 6664ULL: goto x86_l_1a08;
	case 6672ULL: goto x86_l_1a10;
	case 6677ULL: goto x86_l_1a15;
	case 6681ULL: goto x86_l_1a19;
	case 6684ULL: goto x86_l_1a1c;
	case 6687ULL: goto x86_l_1a1f;
	case 6689ULL: goto x86_l_1a21;
	case 6693ULL: goto x86_l_1a25;
	case 6695ULL: goto x86_l_1a27;
	case 6698ULL: goto x86_l_1a2a;
	case 6700ULL: goto x86_l_1a2c;
	case 6708ULL: goto x86_l_1a34;
	case 6711ULL: goto x86_l_1a37;
	case 6715ULL: goto x86_l_1a3b;
	case 6719ULL: goto x86_l_1a3f;
	case 6726ULL: goto x86_l_1a46;
	case 6729ULL: goto x86_l_1a49;
	case 6731ULL: goto x86_l_1a4b;
	case 6736ULL: goto x86_l_1a50;
	case 6741ULL: goto x86_l_1a55;
	case 6744ULL: goto x86_l_1a58;
	case 6747ULL: goto x86_l_1a5b;
	case 6749ULL: goto x86_l_1a5d;
	case 6752ULL: goto x86_l_1a60;
	case 6754ULL: goto x86_l_1a62;
	case 6757ULL: goto x86_l_1a65;
	case 6761ULL: goto x86_l_1a69;
	case 6764ULL: goto x86_l_1a6c;
	case 6766ULL: goto x86_l_1a6e;
	case 6773ULL: goto x86_l_1a75;
	case 6780ULL: goto x86_l_1a7c;
	case 6783ULL: goto x86_l_1a7f;
	case 6789ULL: goto x86_l_1a85;
	case 6794ULL: goto x86_l_1a8a;
	case 6796ULL: goto x86_l_1a8c;
	case 6799ULL: goto x86_l_1a8f;
	case 6803ULL: goto x86_l_1a93;
	case 6806ULL: goto x86_l_1a96;
	case 6808ULL: goto x86_l_1a98;
	case 6810ULL: goto x86_l_1a9a;
	case 6812ULL: goto x86_l_1a9c;
	case 6820ULL: goto x86_l_1aa4;
	case 6825ULL: goto x86_l_1aa9;
	case 6828ULL: goto x86_l_1aac;
	case 6832ULL: goto x86_l_1ab0;
	case 6835ULL: goto x86_l_1ab3;
	case 6837ULL: goto x86_l_1ab5;
	case 6841ULL: goto x86_l_1ab9;
	case 6843ULL: goto x86_l_1abb;
	case 6846ULL: goto x86_l_1abe;
	case 6848ULL: goto x86_l_1ac0;
	case 6856ULL: goto x86_l_1ac8;
	case 6859ULL: goto x86_l_1acb;
	case 6862ULL: goto x86_l_1ace;
	case 6865ULL: goto x86_l_1ad1;
	case 6868ULL: goto x86_l_1ad4;
	case 6876ULL: goto x86_l_1adc;
	case 6882ULL: goto x86_l_1ae2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1480:
	/* 0x1480: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1484:
	/* 0x1484: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1488:
	/* 0x1488: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_148d:
	/* 0x148d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1490:
	/* 0x1490: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1495:
	/* 0x1495: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1497:
	/* 0x1497: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_149a:
	/* 0x149a: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_149e:
	/* 0x149e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14a3:
	/* 0x14a3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_14a6:
	/* 0x14a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14ab:
	/* 0x14ab: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_14ae:
	/* 0x14ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14b0:
	/* 0x14b0: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14b4:
	/* 0x14b4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14b9:
	/* 0x14b9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_14bc:
	/* 0x14bc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14c1:
	/* 0x14c1: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_14c4:
	/* 0x14c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c6:
	/* 0x14c6: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14c9:
	/* 0x14c9: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_14cd:
	/* 0x14cd: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_14d1:
	/* 0x14d1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_14d5:
	/* 0x14d5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14da:
	/* 0x14da: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_14dd:
	/* 0x14dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14e2:
	/* 0x14e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14e4:
	/* 0x14e4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14e8:
	/* 0x14e8: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_14ec:
	/* 0x14ec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14f1:
	/* 0x14f1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_14f4:
	/* 0x14f4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14f9:
	/* 0x14f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14fb:
	/* 0x14fb: mov    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14ff:
	/* 0x14ff: lea    r15,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1503:
	/* 0x1503: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1508:
	/* 0x1508: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_150b:
	/* 0x150b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1510:
	/* 0x1510: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1513:
	/* 0x1513: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1515:
	/* 0x1515: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1519:
	/* 0x1519: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_151e:
	/* 0x151e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1521:
	/* 0x1521: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1526:
	/* 0x1526: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1529:
	/* 0x1529: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_152b:
	/* 0x152b: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_152e:
	/* 0x152e: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1532:
	/* 0x1532: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1536:
	/* 0x1536: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_153a:
	/* 0x153a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_153f:
	/* 0x153f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1542:
	/* 0x1542: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1547:
	/* 0x1547: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1549:
	/* 0x1549: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_154d:
	/* 0x154d: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1551:
	/* 0x1551: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1556:
	/* 0x1556: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1559:
	/* 0x1559: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_155e:
	/* 0x155e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1560:
	/* 0x1560: cmp    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_1564:
	/* 0x1564: jne    15b3 <trace_security_bpf+0x15b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_15b3;
	}
x86_l_1566:
	/* 0x1566: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_156b:
	/* 0x156b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_156e:
	/* 0x156e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1573:
	/* 0x1573: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1576:
	/* 0x1576: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1578:
	/* 0x1578: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_157c:
	/* 0x157c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1581:
	/* 0x1581: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1584:
	/* 0x1584: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1589:
	/* 0x1589: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_158c:
	/* 0x158c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_158e:
	/* 0x158e: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1591:
	/* 0x1591: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1595:
	/* 0x1595: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1599:
	/* 0x1599: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_159d:
	/* 0x159d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15a2:
	/* 0x15a2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_15a5:
	/* 0x15a5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_15aa:
	/* 0x15aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ac:
	/* 0x15ac: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15af:
	/* 0x15af: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15b3:
	/* 0x15b3: mov    DWORD PTR [r14+0x38],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15b7:
	/* 0x15b7: mov    rbx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_15bc:
	/* 0x15bc: lea    r12,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_15c3:
	/* 0x15c3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15c8:
	/* 0x15c8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_15cb:
	/* 0x15cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15d0:
	/* 0x15d0: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_15d3:
	/* 0x15d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d5:
	/* 0x15d5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15d9:
	/* 0x15d9: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_15dd:
	/* 0x15dd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15e2:
	/* 0x15e2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_15e5:
	/* 0x15e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15ea:
	/* 0x15ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ec:
	/* 0x15ec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15f1:
	/* 0x15f1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15f5:
	/* 0x15f5: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_15fd:
	/* 0x15fd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1602:
	/* 0x1602: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1604:
	/* 0x1604: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_160b:
	/* 0x160b: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_160f:
	/* 0x160f: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1614:
	/* 0x1614: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1616:
	/* 0x1616: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_161a:
	/* 0x161a: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_161e:
	/* 0x161e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1623:
	/* 0x1623: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1626:
	/* 0x1626: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_162b:
	/* 0x162b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_162d:
	/* 0x162d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1631:
	/* 0x1631: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1635:
	/* 0x1635: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_163a:
	/* 0x163a: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_163e:
	/* 0x163e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1643:
	/* 0x1643: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1646:
	/* 0x1646: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_164b:
	/* 0x164b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_164d:
	/* 0x164d: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1651:
	/* 0x1651: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1655:
	/* 0x1655: add    rbp,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_1659:
	/* 0x1659: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_165e:
	/* 0x165e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1661:
	/* 0x1661: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1666:
	/* 0x1666: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1669:
	/* 0x1669: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_166b:
	/* 0x166b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_166f:
	/* 0x166f: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1673:
	/* 0x1673: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1678:
	/* 0x1678: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_167b:
	/* 0x167b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1680:
	/* 0x1680: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1683:
	/* 0x1683: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1685:
	/* 0x1685: test   BYTE PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1689:
	/* 0x1689: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1691:
	/* 0x1691: je     1698 <trace_security_bpf+0x1698> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1698;
	}
x86_l_1693:
	/* 0x1693: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_1698:
	/* 0x1698: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_169c:
	/* 0x169c: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_16a4:
	/* 0x16a4: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_16ac:
	/* 0x16ac: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_16b1:
	/* 0x16b1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_16b6:
	/* 0x16b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16b8:
	/* 0x16b8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16bd:
	/* 0x16bd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_16c0:
	/* 0x16c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16c5:
	/* 0x16c5: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_16c8:
	/* 0x16c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ca:
	/* 0x16ca: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16ce:
	/* 0x16ce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16d3:
	/* 0x16d3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_16d6:
	/* 0x16d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16db:
	/* 0x16db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16dd:
	/* 0x16dd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16e1:
	/* 0x16e1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16e6:
	/* 0x16e6: mov    rbx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSP, X86_WIDTH_64);
x86_l_16e9:
	/* 0x16e9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_16ec:
	/* 0x16ec: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_16f1:
	/* 0x16f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16f3:
	/* 0x16f3: lea    rdi,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_16f7:
	/* 0x16f7: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_16fc:
	/* 0x16fc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1701:
	/* 0x1701: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1704:
	/* 0x1704: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1706:
	/* 0x1706: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_170b:
	/* 0x170b: mov    rbp,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1713:
	/* 0x1713: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1716:
	/* 0x1716: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_171b:
	/* 0x171b: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1720:
	/* 0x1720: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1722:
	/* 0x1722: mov    r12,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_172a:
	/* 0x172a: test   BYTE PTR [r12+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_1730:
	/* 0x1730: je     1750 <trace_security_bpf+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1750;
	}
x86_l_1732:
	/* 0x1732: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1737:
	/* 0x1737: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_173e:
	/* 0x173e: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1743:
	/* 0x1743: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1746:
	/* 0x1746: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1748:
	/* 0x1748: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_174a:
	/* 0x174a: js     1750 <trace_security_bpf+0x1750> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1750;
	}
x86_l_174c:
	/* 0x174c: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1750:
	/* 0x1750: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1758:
	/* 0x1758: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_175d:
	/* 0x175d: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_1762:
	/* 0x1762: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_1765:
	/* 0x1765: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_176b:
	/* 0x176b: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_176f:
	/* 0x176f: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1774:
	/* 0x1774: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_177b:
	/* 0x177b: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1780:
	/* 0x1780: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1783:
	/* 0x1783: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_1786:
	/* 0x1786: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1788:
	/* 0x1788: mov    rax,QWORD PTR [r15+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_178c:
	/* 0x178c: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1791:
	/* 0x1791: mov    DWORD PTR [r14+0x70],0x302 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337922ULL);
x86_l_1799:
	/* 0x1799: mov    WORD PTR [r14+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_17a3:
	/* 0x17a3: mov    BYTE PTR [r14+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_17ab:
	/* 0x17ab: mov    QWORD PTR [r13+0x38],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 244813135871ULL);
x86_l_17b3:
	/* 0x17b3: mov    QWORD PTR [r13+0x30],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 210453397503ULL);
x86_l_17bb:
	/* 0x17bb: mov    QWORD PTR [r13+0x28],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176093659135ULL);
x86_l_17c3:
	/* 0x17c3: mov    QWORD PTR [r13+0x20],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 141733920767ULL);
x86_l_17cb:
	/* 0x17cb: mov    QWORD PTR [r13+0x18],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 107374182399ULL);
x86_l_17d3:
	/* 0x17d3: mov    QWORD PTR [r13+0x10],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 73014444031ULL);
x86_l_17db:
	/* 0x17db: mov    QWORD PTR [r13+0x8],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38654705663ULL);
x86_l_17e3:
	/* 0x17e3: mov    QWORD PTR [r13+0x0],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4294967295ULL);
x86_l_17eb:
	/* 0x17eb: mov    QWORD PTR [r14+0x7dd8],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138370961375231ULL);
x86_l_17f6:
	/* 0x17f6: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_17fb:
	/* 0x17fb: mov    DWORD PTR [rsp],0x302 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 770ULL);
x86_l_1802:
	/* 0x1802: mov    WORD PTR [rsp+0xb0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_180a:
	/* 0x180a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_180f:
	/* 0x180f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_1816:
	/* 0x1816: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_181e:
	/* 0x181e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1820:
	/* 0x1820: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1823:
	/* 0x1823: je     2c25 <trace_security_bpf+0x2c25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11301ULL;
	}
x86_l_1829:
	/* 0x1829: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_182e:
	/* 0x182e: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1831:
	/* 0x1831: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1834:
	/* 0x1834: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1836:
	/* 0x1836: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1839:
	/* 0x1839: je     2c25 <trace_security_bpf+0x2c25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11301ULL;
	}
x86_l_183f:
	/* 0x183f: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1843:
	/* 0x1843: mov    QWORD PTR [r14+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_184a:
	/* 0x184a: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_184d:
	/* 0x184d: mov    QWORD PTR [r14+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_1854:
	/* 0x1854: mov    QWORD PTR [r14+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_185b:
	/* 0x185b: mov    rdx,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_185f:
	/* 0x185f: mov    QWORD PTR [r14+0x7e10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_1866:
	/* 0x1866: mov    rdx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_186a:
	/* 0x186a: mov    QWORD PTR [r14+0x7e08],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_1871:
	/* 0x1871: mov    rdx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1875:
	/* 0x1875: mov    QWORD PTR [r14+0x7e00],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_187c:
	/* 0x187c: mov    rdx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1880:
	/* 0x1880: mov    QWORD PTR [r14+0x7df8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_1887:
	/* 0x1887: mov    rdx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_188b:
	/* 0x188b: mov    rax,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_188f:
	/* 0x188f: mov    QWORD PTR [r14+0x7df0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_1896:
	/* 0x1896: mov    QWORD PTR [r14+0x7de8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_189d:
	/* 0x189d: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18a1:
	/* 0x18a1: cmp    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_18a5:
	/* 0x18a5: jne    18c7 <trace_security_bpf+0x18c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18c7;
	}
x86_l_18a7:
	/* 0x18a7: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18aa:
	/* 0x18aa: and    rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_18ad:
	/* 0x18ad: mov    QWORD PTR [r14+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_18b4:
	/* 0x18b4: mov    r12,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_18bc:
	/* 0x18bc: jne    2056 <trace_security_bpf+0x2056> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8278ULL;
	}
x86_l_18c2:
	/* 0x18c2: jmp    2c25 <trace_security_bpf+0x2c25> */
	return 11301ULL;
x86_l_18c7:
	/* 0x18c7: mov    rax,QWORD PTR [r14+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_18ce:
	/* 0x18ce: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18d1:
	/* 0x18d1: je     1a6e <trace_security_bpf+0x1a6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a6e;
	}
x86_l_18d7:
	/* 0x18d7: movzx  ecx,BYTE PTR [rbp+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_18de:
	/* 0x18de: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_18e1:
	/* 0x18e1: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18e4:
	/* 0x18e4: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_18e7:
	/* 0x18e7: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_18eb:
	/* 0x18eb: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_18ee:
	/* 0x18ee: neg    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_18f1:
	/* 0x18f1: xor    r12,QWORD PTR [r14+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_18f8:
	/* 0x18f8: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_18fb:
	/* 0x18fb: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_1902:
	/* 0x1902: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1905:
	/* 0x1905: je     1926 <trace_security_bpf+0x1926> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1926;
	}
x86_l_1907:
	/* 0x1907: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1909:
	/* 0x1909: cmp    BYTE PTR [rbp+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_1910:
	/* 0x1910: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1913:
	/* 0x1913: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1916:
	/* 0x1916: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_1919:
	/* 0x1919: xor    rcx,QWORD PTR [r14+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_1920:
	/* 0x1920: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1923:
	/* 0x1923: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1926:
	/* 0x1926: mov    rax,QWORD PTR [r14+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_192d:
	/* 0x192d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1930:
	/* 0x1930: je     194c <trace_security_bpf+0x194c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_194c;
	}
x86_l_1932:
	/* 0x1932: mov    ecx,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_1936:
	/* 0x1936: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1939:
	/* 0x1939: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_193c:
	/* 0x193c: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_193f:
	/* 0x193f: xor    rcx,QWORD PTR [r14+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_1946:
	/* 0x1946: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1949:
	/* 0x1949: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_194c:
	/* 0x194c: mov    rax,QWORD PTR [r14+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_1953:
	/* 0x1953: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1956:
	/* 0x1956: je     1977 <trace_security_bpf+0x1977> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1977;
	}
x86_l_1958:
	/* 0x1958: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_195b:
	/* 0x195b: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1963:
	/* 0x1963: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1967:
	/* 0x1967: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_196a:
	/* 0x196a: xor    rcx,QWORD PTR [r14+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_1971:
	/* 0x1971: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1974:
	/* 0x1974: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1977:
	/* 0x1977: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_197c:
	/* 0x197c: mov    r15,QWORD PTR [r14+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_1983:
	/* 0x1983: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1986:
	/* 0x1986: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_198b:
	/* 0x198b: je     1ad4 <trace_security_bpf+0x1ad4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ad4;
	}
x86_l_1991:
	/* 0x1991: mov    rcx,QWORD PTR [r14+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_1998:
	/* 0x1998: mov    QWORD PTR [rsp+0x140],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_19a0:
	/* 0x19a0: mov    rcx,QWORD PTR [r14+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_19a7:
	/* 0x19a7: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_19ac:
	/* 0x19ac: mov    rcx,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_19b3:
	/* 0x19b3: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_19bb:
	/* 0x19bb: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19bf:
	/* 0x19bf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19c4:
	/* 0x19c4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_19cb:
	/* 0x19cb: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_19ce:
	/* 0x19ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d0:
	/* 0x19d0: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_19d3:
	/* 0x19d3: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_19d7:
	/* 0x19d7: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19db:
	/* 0x19db: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_19e2:
	/* 0x19e2: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_19e5:
	/* 0x19e5: je     1a05 <trace_security_bpf+0x1a05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a05;
	}
x86_l_19e7:
	/* 0x19e7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19ec:
	/* 0x19ec: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_19ef:
	/* 0x19ef: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_19f2:
	/* 0x19f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19f4:
	/* 0x19f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19f7:
	/* 0x19f7: je     1a05 <trace_security_bpf+0x1a05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a05;
	}
x86_l_19f9:
	/* 0x19f9: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19fc:
	/* 0x19fc: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a00:
	/* 0x1a00: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1a03:
	/* 0x1a03: jmp    1a08 <trace_security_bpf+0x1a08> */
	goto x86_l_1a08;
x86_l_1a05:
	/* 0x1a05: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a08:
	/* 0x1a08: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1a10:
	/* 0x1a10: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1a15:
	/* 0x1a15: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a19:
	/* 0x1a19: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1a1c:
	/* 0x1a1c: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1a1f:
	/* 0x1a1f: jb     1a37 <trace_security_bpf+0x1a37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1a37;
	}
x86_l_1a21:
	/* 0x1a21: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1a25:
	/* 0x1a25: je     1a2c <trace_security_bpf+0x1a2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a2c;
	}
x86_l_1a27:
	/* 0x1a27: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1a2a:
	/* 0x1a2a: jbe    1a37 <trace_security_bpf+0x1a37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1a37;
	}
x86_l_1a2c:
	/* 0x1a2c: and    rbp,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 320ULL);
x86_l_1a34:
	/* 0x1a34: or     r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_1a37:
	/* 0x1a37: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a3b:
	/* 0x1a3b: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a3f:
	/* 0x1a3f: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1a46:
	/* 0x1a46: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1a49:
	/* 0x1a49: je     1a8a <trace_security_bpf+0x1a8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a8a;
	}
x86_l_1a4b:
	/* 0x1a4b: mov    QWORD PTR [rsp+0x78],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1a50:
	/* 0x1a50: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a55:
	/* 0x1a55: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1a58:
	/* 0x1a58: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1a5b:
	/* 0x1a5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a5d:
	/* 0x1a5d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a60:
	/* 0x1a60: je     1a9a <trace_security_bpf+0x1a9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a9a;
	}
x86_l_1a62:
	/* 0x1a62: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a65:
	/* 0x1a65: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a69:
	/* 0x1a69: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1a6c:
	/* 0x1a6c: jmp    1a9c <trace_security_bpf+0x1a9c> */
	goto x86_l_1a9c;
x86_l_1a6e:
	/* 0x1a6e: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1a75:
	/* 0x1a75: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_1a7c:
	/* 0x1a7c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a7f:
	/* 0x1a7f: jne    1907 <trace_security_bpf+0x1907> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1907;
	}
x86_l_1a85:
	/* 0x1a85: jmp    1926 <trace_security_bpf+0x1926> */
	goto x86_l_1926;
x86_l_1a8a:
	/* 0x1a8a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a8c:
	/* 0x1a8c: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1a8f:
	/* 0x1a8f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a93:
	/* 0x1a93: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1a96:
	/* 0x1a96: jae    1ab5 <trace_security_bpf+0x1ab5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1ab5;
	}
x86_l_1a98:
	/* 0x1a98: jmp    1acb <trace_security_bpf+0x1acb> */
	goto x86_l_1acb;
x86_l_1a9a:
	/* 0x1a9a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a9c:
	/* 0x1a9c: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1aa4:
	/* 0x1aa4: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1aa9:
	/* 0x1aa9: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1aac:
	/* 0x1aac: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ab0:
	/* 0x1ab0: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1ab3:
	/* 0x1ab3: jb     1acb <trace_security_bpf+0x1acb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1acb;
	}
x86_l_1ab5:
	/* 0x1ab5: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1ab9:
	/* 0x1ab9: je     1ac0 <trace_security_bpf+0x1ac0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ac0;
	}
x86_l_1abb:
	/* 0x1abb: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1abe:
	/* 0x1abe: jbe    1acb <trace_security_bpf+0x1acb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1acb;
	}
x86_l_1ac0:
	/* 0x1ac0: and    rbp,QWORD PTR [rsp+0x140] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 320ULL);
x86_l_1ac8:
	/* 0x1ac8: or     rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_1acb:
	/* 0x1acb: or     r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1ace:
	/* 0x1ace: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1ad1:
	/* 0x1ad1: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1ad4:
	/* 0x1ad4: cmp    QWORD PTR [r14+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_1adc:
	/* 0x1adc: je     1b72 <trace_security_bpf+0x1b72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7026ULL;
	}
x86_l_1ae2:
	/* 0x1ae2: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
	return 6887ULL;
}

static __noinline __u64 tracee_trace_security_bpf_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6887ULL: goto x86_l_1ae7;
	case 6889ULL: goto x86_l_1ae9;
	case 6893ULL: goto x86_l_1aed;
	case 6900ULL: goto x86_l_1af4;
	case 6907ULL: goto x86_l_1afb;
	case 6912ULL: goto x86_l_1b00;
	case 6919ULL: goto x86_l_1b07;
	case 6926ULL: goto x86_l_1b0e;
	case 6931ULL: goto x86_l_1b13;
	case 6935ULL: goto x86_l_1b17;
	case 6940ULL: goto x86_l_1b1c;
	case 6947ULL: goto x86_l_1b23;
	case 6950ULL: goto x86_l_1b26;
	case 6952ULL: goto x86_l_1b28;
	case 6956ULL: goto x86_l_1b2c;
	case 6960ULL: goto x86_l_1b30;
	case 6967ULL: goto x86_l_1b37;
	case 6970ULL: goto x86_l_1b3a;
	case 6972ULL: goto x86_l_1b3c;
	case 6977ULL: goto x86_l_1b41;
	case 6980ULL: goto x86_l_1b44;
	case 6983ULL: goto x86_l_1b47;
	case 6985ULL: goto x86_l_1b49;
	case 6988ULL: goto x86_l_1b4c;
	case 6990ULL: goto x86_l_1b4e;
	case 6993ULL: goto x86_l_1b51;
	case 6997ULL: goto x86_l_1b55;
	case 7000ULL: goto x86_l_1b58;
	case 7002ULL: goto x86_l_1b5a;
	case 7004ULL: goto x86_l_1b5c;
	case 7007ULL: goto x86_l_1b5f;
	case 7011ULL: goto x86_l_1b63;
	case 7014ULL: goto x86_l_1b66;
	case 7017ULL: goto x86_l_1b69;
	case 7019ULL: goto x86_l_1b6b;
	case 7024ULL: goto x86_l_1b70;
	case 7026ULL: goto x86_l_1b72;
	case 7031ULL: goto x86_l_1b77;
	case 7039ULL: goto x86_l_1b7f;
	case 7041ULL: goto x86_l_1b81;
	case 7046ULL: goto x86_l_1b86;
	case 7050ULL: goto x86_l_1b8a;
	case 7055ULL: goto x86_l_1b8f;
	case 7057ULL: goto x86_l_1b91;
	case 7060ULL: goto x86_l_1b94;
	case 7062ULL: goto x86_l_1b96;
	case 7067ULL: goto x86_l_1b9b;
	case 7070ULL: goto x86_l_1b9e;
	case 7073ULL: goto x86_l_1ba1;
	case 7076ULL: goto x86_l_1ba4;
	case 7084ULL: goto x86_l_1bac;
	case 7090ULL: goto x86_l_1bb2;
	case 7095ULL: goto x86_l_1bb7;
	case 7102ULL: goto x86_l_1bbe;
	case 7107ULL: goto x86_l_1bc3;
	case 7110ULL: goto x86_l_1bc6;
	case 7115ULL: goto x86_l_1bcb;
	case 7117ULL: goto x86_l_1bcd;
	case 7121ULL: goto x86_l_1bd1;
	case 7125ULL: goto x86_l_1bd5;
	case 7130ULL: goto x86_l_1bda;
	case 7133ULL: goto x86_l_1bdd;
	case 7138ULL: goto x86_l_1be2;
	case 7140ULL: goto x86_l_1be4;
	case 7145ULL: goto x86_l_1be9;
	case 7149ULL: goto x86_l_1bed;
	case 7157ULL: goto x86_l_1bf5;
	case 7162ULL: goto x86_l_1bfa;
	case 7164ULL: goto x86_l_1bfc;
	case 7171ULL: goto x86_l_1c03;
	case 7175ULL: goto x86_l_1c07;
	case 7182ULL: goto x86_l_1c0e;
	case 7189ULL: goto x86_l_1c15;
	case 7192ULL: goto x86_l_1c18;
	case 7196ULL: goto x86_l_1c1c;
	case 7201ULL: goto x86_l_1c21;
	case 7208ULL: goto x86_l_1c28;
	case 7211ULL: goto x86_l_1c2b;
	case 7213ULL: goto x86_l_1c2d;
	case 7220ULL: goto x86_l_1c34;
	case 7223ULL: goto x86_l_1c37;
	case 7225ULL: goto x86_l_1c39;
	case 7229ULL: goto x86_l_1c3d;
	case 7234ULL: goto x86_l_1c42;
	case 7237ULL: goto x86_l_1c45;
	case 7239ULL: goto x86_l_1c47;
	case 7242ULL: goto x86_l_1c4a;
	case 7244ULL: goto x86_l_1c4c;
	case 7247ULL: goto x86_l_1c4f;
	case 7251ULL: goto x86_l_1c53;
	case 7254ULL: goto x86_l_1c56;
	case 7256ULL: goto x86_l_1c58;
	case 7258ULL: goto x86_l_1c5a;
	case 7261ULL: goto x86_l_1c5d;
	case 7264ULL: goto x86_l_1c60;
	case 7267ULL: goto x86_l_1c63;
	case 7270ULL: goto x86_l_1c66;
	case 7278ULL: goto x86_l_1c6e;
	case 7284ULL: goto x86_l_1c74;
	case 7291ULL: goto x86_l_1c7b;
	case 7295ULL: goto x86_l_1c7f;
	case 7300ULL: goto x86_l_1c84;
	case 7303ULL: goto x86_l_1c87;
	case 7308ULL: goto x86_l_1c8c;
	case 7310ULL: goto x86_l_1c8e;
	case 7314ULL: goto x86_l_1c92;
	case 7319ULL: goto x86_l_1c97;
	case 7322ULL: goto x86_l_1c9a;
	case 7327ULL: goto x86_l_1c9f;
	case 7330ULL: goto x86_l_1ca2;
	case 7332ULL: goto x86_l_1ca4;
	case 7335ULL: goto x86_l_1ca7;
	case 7339ULL: goto x86_l_1cab;
	case 7343ULL: goto x86_l_1caf;
	case 7347ULL: goto x86_l_1cb3;
	case 7352ULL: goto x86_l_1cb8;
	case 7355ULL: goto x86_l_1cbb;
	case 7360ULL: goto x86_l_1cc0;
	case 7362ULL: goto x86_l_1cc2;
	case 7366ULL: goto x86_l_1cc6;
	case 7370ULL: goto x86_l_1cca;
	case 7375ULL: goto x86_l_1ccf;
	case 7378ULL: goto x86_l_1cd2;
	case 7383ULL: goto x86_l_1cd7;
	case 7385ULL: goto x86_l_1cd9;
	case 7388ULL: goto x86_l_1cdc;
	case 7392ULL: goto x86_l_1ce0;
	case 7399ULL: goto x86_l_1ce7;
	case 7406ULL: goto x86_l_1cee;
	case 7409ULL: goto x86_l_1cf1;
	case 7413ULL: goto x86_l_1cf5;
	case 7418ULL: goto x86_l_1cfa;
	case 7425ULL: goto x86_l_1d01;
	case 7428ULL: goto x86_l_1d04;
	case 7430ULL: goto x86_l_1d06;
	case 7437ULL: goto x86_l_1d0d;
	case 7440ULL: goto x86_l_1d10;
	case 7442ULL: goto x86_l_1d12;
	case 7446ULL: goto x86_l_1d16;
	case 7451ULL: goto x86_l_1d1b;
	case 7454ULL: goto x86_l_1d1e;
	case 7456ULL: goto x86_l_1d20;
	case 7459ULL: goto x86_l_1d23;
	case 7461ULL: goto x86_l_1d25;
	case 7464ULL: goto x86_l_1d28;
	case 7468ULL: goto x86_l_1d2c;
	case 7471ULL: goto x86_l_1d2f;
	case 7473ULL: goto x86_l_1d31;
	case 7475ULL: goto x86_l_1d33;
	case 7478ULL: goto x86_l_1d36;
	case 7481ULL: goto x86_l_1d39;
	case 7484ULL: goto x86_l_1d3c;
	case 7487ULL: goto x86_l_1d3f;
	case 7495ULL: goto x86_l_1d47;
	case 7501ULL: goto x86_l_1d4d;
	case 7506ULL: goto x86_l_1d52;
	case 7513ULL: goto x86_l_1d59;
	case 7518ULL: goto x86_l_1d5e;
	case 7521ULL: goto x86_l_1d61;
	case 7526ULL: goto x86_l_1d66;
	case 7528ULL: goto x86_l_1d68;
	case 7532ULL: goto x86_l_1d6c;
	case 7537ULL: goto x86_l_1d71;
	case 7540ULL: goto x86_l_1d74;
	case 7545ULL: goto x86_l_1d79;
	case 7547ULL: goto x86_l_1d7b;
	case 7551ULL: goto x86_l_1d7f;
	case 7556ULL: goto x86_l_1d84;
	case 7559ULL: goto x86_l_1d87;
	case 7562ULL: goto x86_l_1d8a;
	case 7567ULL: goto x86_l_1d8f;
	case 7569ULL: goto x86_l_1d91;
	case 7573ULL: goto x86_l_1d95;
	case 7578ULL: goto x86_l_1d9a;
	case 7581ULL: goto x86_l_1d9d;
	case 7586ULL: goto x86_l_1da2;
	case 7589ULL: goto x86_l_1da5;
	case 7591ULL: goto x86_l_1da7;
	case 7598ULL: goto x86_l_1dae;
	case 7605ULL: goto x86_l_1db5;
	case 7608ULL: goto x86_l_1db8;
	case 7612ULL: goto x86_l_1dbc;
	case 7617ULL: goto x86_l_1dc1;
	case 7624ULL: goto x86_l_1dc8;
	case 7627ULL: goto x86_l_1dcb;
	case 7629ULL: goto x86_l_1dcd;
	case 7636ULL: goto x86_l_1dd4;
	case 7639ULL: goto x86_l_1dd7;
	case 7641ULL: goto x86_l_1dd9;
	case 7646ULL: goto x86_l_1dde;
	case 7649ULL: goto x86_l_1de1;
	case 7652ULL: goto x86_l_1de4;
	case 7654ULL: goto x86_l_1de6;
	case 7657ULL: goto x86_l_1de9;
	case 7659ULL: goto x86_l_1deb;
	case 7662ULL: goto x86_l_1dee;
	case 7666ULL: goto x86_l_1df2;
	case 7669ULL: goto x86_l_1df5;
	case 7671ULL: goto x86_l_1df7;
	case 7673ULL: goto x86_l_1df9;
	case 7676ULL: goto x86_l_1dfc;
	case 7679ULL: goto x86_l_1dff;
	case 7682ULL: goto x86_l_1e02;
	case 7685ULL: goto x86_l_1e05;
	case 7690ULL: goto x86_l_1e0a;
	case 7698ULL: goto x86_l_1e12;
	case 7700ULL: goto x86_l_1e14;
	case 7704ULL: goto x86_l_1e18;
	case 7709ULL: goto x86_l_1e1d;
	case 7712ULL: goto x86_l_1e20;
	case 7717ULL: goto x86_l_1e25;
	case 7719ULL: goto x86_l_1e27;
	case 7726ULL: goto x86_l_1e2e;
	case 7733ULL: goto x86_l_1e35;
	case 7736ULL: goto x86_l_1e38;
	case 7740ULL: goto x86_l_1e3c;
	case 7745ULL: goto x86_l_1e41;
	case 7752ULL: goto x86_l_1e48;
	case 7755ULL: goto x86_l_1e4b;
	case 7757ULL: goto x86_l_1e4d;
	case 7764ULL: goto x86_l_1e54;
	case 7767ULL: goto x86_l_1e57;
	case 7769ULL: goto x86_l_1e59;
	case 7774ULL: goto x86_l_1e5e;
	case 7777ULL: goto x86_l_1e61;
	case 7780ULL: goto x86_l_1e64;
	case 7782ULL: goto x86_l_1e66;
	case 7785ULL: goto x86_l_1e69;
	case 7787ULL: goto x86_l_1e6b;
	case 7790ULL: goto x86_l_1e6e;
	case 7794ULL: goto x86_l_1e72;
	case 7797ULL: goto x86_l_1e75;
	case 7799ULL: goto x86_l_1e77;
	case 7801ULL: goto x86_l_1e79;
	case 7804ULL: goto x86_l_1e7c;
	case 7807ULL: goto x86_l_1e7f;
	case 7810ULL: goto x86_l_1e82;
	case 7813ULL: goto x86_l_1e85;
	case 7820ULL: goto x86_l_1e8c;
	case 7823ULL: goto x86_l_1e8f;
	case 7831ULL: goto x86_l_1e97;
	case 7833ULL: goto x86_l_1e99;
	case 7837ULL: goto x86_l_1e9d;
	case 7840ULL: goto x86_l_1ea0;
	case 7847ULL: goto x86_l_1ea7;
	case 7850ULL: goto x86_l_1eaa;
	case 7855ULL: goto x86_l_1eaf;
	case 7863ULL: goto x86_l_1eb7;
	case 7868ULL: goto x86_l_1ebc;
	case 7875ULL: goto x86_l_1ec3;
	case 7883ULL: goto x86_l_1ecb;
	case 7885ULL: goto x86_l_1ecd;
	case 7892ULL: goto x86_l_1ed4;
	case 7895ULL: goto x86_l_1ed7;
	case 7897ULL: goto x86_l_1ed9;
	case 7902ULL: goto x86_l_1ede;
	case 7905ULL: goto x86_l_1ee1;
	case 7908ULL: goto x86_l_1ee4;
	case 7910ULL: goto x86_l_1ee6;
	case 7913ULL: goto x86_l_1ee9;
	case 7915ULL: goto x86_l_1eeb;
	case 7918ULL: goto x86_l_1eee;
	case 7922ULL: goto x86_l_1ef2;
	case 7925ULL: goto x86_l_1ef5;
	case 7927ULL: goto x86_l_1ef7;
	case 7929ULL: goto x86_l_1ef9;
	case 7932ULL: goto x86_l_1efc;
	case 7935ULL: goto x86_l_1eff;
	case 7938ULL: goto x86_l_1f02;
	case 7941ULL: goto x86_l_1f05;
	case 7948ULL: goto x86_l_1f0c;
	case 7951ULL: goto x86_l_1f0f;
	case 7953ULL: goto x86_l_1f11;
	case 7960ULL: goto x86_l_1f18;
	case 7963ULL: goto x86_l_1f1b;
	case 7968ULL: goto x86_l_1f20;
	case 7972ULL: goto x86_l_1f24;
	case 7977ULL: goto x86_l_1f29;
	case 7984ULL: goto x86_l_1f30;
	case 7987ULL: goto x86_l_1f33;
	case 7989ULL: goto x86_l_1f35;
	case 7996ULL: goto x86_l_1f3c;
	case 7999ULL: goto x86_l_1f3f;
	case 8001ULL: goto x86_l_1f41;
	case 8006ULL: goto x86_l_1f46;
	case 8009ULL: goto x86_l_1f49;
	case 8017ULL: goto x86_l_1f51;
	case 8019ULL: goto x86_l_1f53;
	case 8022ULL: goto x86_l_1f56;
	case 8024ULL: goto x86_l_1f58;
	case 8027ULL: goto x86_l_1f5b;
	case 8031ULL: goto x86_l_1f5f;
	case 8034ULL: goto x86_l_1f62;
	case 8036ULL: goto x86_l_1f64;
	case 8038ULL: goto x86_l_1f66;
	case 8041ULL: goto x86_l_1f69;
	case 8044ULL: goto x86_l_1f6c;
	case 8047ULL: goto x86_l_1f6f;
	case 8050ULL: goto x86_l_1f72;
	case 8057ULL: goto x86_l_1f79;
	case 8060ULL: goto x86_l_1f7c;
	case 8066ULL: goto x86_l_1f82;
	case 8073ULL: goto x86_l_1f89;
	case 8076ULL: goto x86_l_1f8c;
	case 8081ULL: goto x86_l_1f91;
	case 8085ULL: goto x86_l_1f95;
	case 8090ULL: goto x86_l_1f9a;
	case 8097ULL: goto x86_l_1fa1;
	case 8100ULL: goto x86_l_1fa4;
	case 8102ULL: goto x86_l_1fa6;
	case 8109ULL: goto x86_l_1fad;
	case 8112ULL: goto x86_l_1fb0;
	case 8114ULL: goto x86_l_1fb2;
	case 8117ULL: goto x86_l_1fb5;
	case 8125ULL: goto x86_l_1fbd;
	case 8129ULL: goto x86_l_1fc1;
	case 8134ULL: goto x86_l_1fc6;
	case 8137ULL: goto x86_l_1fc9;
	case 8139ULL: goto x86_l_1fcb;
	case 8142ULL: goto x86_l_1fce;
	case 8144ULL: goto x86_l_1fd0;
	case 8152ULL: goto x86_l_1fd8;
	case 8156ULL: goto x86_l_1fdc;
	case 8161ULL: goto x86_l_1fe1;
	case 8164ULL: goto x86_l_1fe4;
	case 8166ULL: goto x86_l_1fe6;
	case 8169ULL: goto x86_l_1fe9;
	case 8171ULL: goto x86_l_1feb;
	case 8174ULL: goto x86_l_1fee;
	case 8178ULL: goto x86_l_1ff2;
	case 8181ULL: goto x86_l_1ff5;
	case 8183ULL: goto x86_l_1ff7;
	case 8185ULL: goto x86_l_1ff9;
	case 8188ULL: goto x86_l_1ffc;
	case 8191ULL: goto x86_l_1fff;
	case 8194ULL: goto x86_l_2002;
	case 8197ULL: goto x86_l_2005;
	case 8205ULL: goto x86_l_200d;
	case 8212ULL: goto x86_l_2014;
	case 8215ULL: goto x86_l_2017;
	case 8223ULL: goto x86_l_201f;
	case 8225ULL: goto x86_l_2021;
	case 8233ULL: goto x86_l_2029;
	case 8237ULL: goto x86_l_202d;
	case 8240ULL: goto x86_l_2030;
	case 8247ULL: goto x86_l_2037;
	case 8254ULL: goto x86_l_203e;
	case 8257ULL: goto x86_l_2041;
	case 8264ULL: goto x86_l_2048;
	case 8272ULL: goto x86_l_2050;
	case 8278ULL: goto x86_l_2056;
	case 8285ULL: goto x86_l_205d;
	case 8288ULL: goto x86_l_2060;
	case 8294ULL: goto x86_l_2066;
	case 8299ULL: goto x86_l_206b;
	case 8302ULL: goto x86_l_206e;
	case 8307ULL: goto x86_l_2073;
	case 8312ULL: goto x86_l_2078;
	case 8315ULL: goto x86_l_207b;
	case 8317ULL: goto x86_l_207d;
	case 8321ULL: goto x86_l_2081;
	case 8325ULL: goto x86_l_2085;
	case 8330ULL: goto x86_l_208a;
	case 8333ULL: goto x86_l_208d;
	case 8338ULL: goto x86_l_2092;
	case 8340ULL: goto x86_l_2094;
	case 8343ULL: goto x86_l_2097;
	case 8348ULL: goto x86_l_209c;
	case 8350ULL: goto x86_l_209e;
	case 8353ULL: goto x86_l_20a1;
	case 8355ULL: goto x86_l_20a3;
	case 8359ULL: goto x86_l_20a7;
	case 8364ULL: goto x86_l_20ac;
	case 8372ULL: goto x86_l_20b4;
	case 8377ULL: goto x86_l_20b9;
	case 8380ULL: goto x86_l_20bc;
	case 8382ULL: goto x86_l_20be;
	case 8387ULL: goto x86_l_20c3;
	case 8395ULL: goto x86_l_20cb;
	case 8403ULL: goto x86_l_20d3;
	case 8408ULL: goto x86_l_20d8;
	case 8410ULL: goto x86_l_20da;
	case 8415ULL: goto x86_l_20df;
	case 8423ULL: goto x86_l_20e7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1ae7:
	/* 0x1ae7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ae9:
	/* 0x1ae9: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1aed:
	/* 0x1aed: mov    rbx,QWORD PTR [r14+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_1af4:
	/* 0x1af4: mov    rax,QWORD PTR [r14+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_1afb:
	/* 0x1afb: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1b00:
	/* 0x1b00: mov    rbp,QWORD PTR [r14+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_1b07:
	/* 0x1b07: mov    r13,QWORD PTR [r14+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_1b0e:
	/* 0x1b0e: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_1b13:
	/* 0x1b13: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b17:
	/* 0x1b17: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b1c:
	/* 0x1b1c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_1b23:
	/* 0x1b23: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1b26:
	/* 0x1b26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b28:
	/* 0x1b28: mov    ecx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b2c:
	/* 0x1b2c: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b30:
	/* 0x1b30: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1b37:
	/* 0x1b37: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b3a:
	/* 0x1b3a: je     1b5a <trace_security_bpf+0x1b5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b5a;
	}
x86_l_1b3c:
	/* 0x1b3c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1b41:
	/* 0x1b41: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1b44:
	/* 0x1b44: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1b47:
	/* 0x1b47: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1b49:
	/* 0x1b49: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b4c:
	/* 0x1b4c: je     1b5a <trace_security_bpf+0x1b5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b5a;
	}
x86_l_1b4e:
	/* 0x1b4e: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b51:
	/* 0x1b51: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b55:
	/* 0x1b55: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1b58:
	/* 0x1b58: jmp    1b5c <trace_security_bpf+0x1b5c> */
	goto x86_l_1b5c;
x86_l_1b5a:
	/* 0x1b5a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b5c:
	/* 0x1b5c: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1b5f:
	/* 0x1b5f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b63:
	/* 0x1b63: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1b66:
	/* 0x1b66: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1b69:
	/* 0x1b69: jae    1b86 <trace_security_bpf+0x1b86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b86;
	}
x86_l_1b6b:
	/* 0x1b6b: movzx  ebp,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_1b70:
	/* 0x1b70: jmp    1b9e <trace_security_bpf+0x1b9e> */
	goto x86_l_1b9e;
x86_l_1b72:
	/* 0x1b72: movzx  ebp,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_1b77:
	/* 0x1b77: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_1b7f:
	/* 0x1b7f: jne    1bb2 <trace_security_bpf+0x1bb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bb2;
	}
x86_l_1b81:
	/* 0x1b81: jmp    1c66 <trace_security_bpf+0x1c66> */
	goto x86_l_1c66;
x86_l_1b86:
	/* 0x1b86: cmp    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1b8a:
	/* 0x1b8a: movzx  ebp,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_1b8f:
	/* 0x1b8f: je     1b96 <trace_security_bpf+0x1b96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b96;
	}
x86_l_1b91:
	/* 0x1b91: cmp    rax,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_1b94:
	/* 0x1b94: jbe    1b9e <trace_security_bpf+0x1b9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1b9e;
	}
x86_l_1b96:
	/* 0x1b96: and    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 120ULL);
x86_l_1b9b:
	/* 0x1b9b: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1b9e:
	/* 0x1b9e: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1ba1:
	/* 0x1ba1: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1ba4:
	/* 0x1ba4: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_1bac:
	/* 0x1bac: je     1c66 <trace_security_bpf+0x1c66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c66;
	}
x86_l_1bb2:
	/* 0x1bb2: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1bb7:
	/* 0x1bb7: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1bbe:
	/* 0x1bbe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bc3:
	/* 0x1bc3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1bc6:
	/* 0x1bc6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bcb:
	/* 0x1bcb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bcd:
	/* 0x1bcd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bd1:
	/* 0x1bd1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1bd5:
	/* 0x1bd5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bda:
	/* 0x1bda: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1bdd:
	/* 0x1bdd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1be2:
	/* 0x1be2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1be4:
	/* 0x1be4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1be9:
	/* 0x1be9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bed:
	/* 0x1bed: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1bf5:
	/* 0x1bf5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bfa:
	/* 0x1bfa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bfc:
	/* 0x1bfc: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1c03:
	/* 0x1c03: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1c07:
	/* 0x1c07: mov    rbx,QWORD PTR [r14+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_1c0e:
	/* 0x1c0e: mov    r15,QWORD PTR [r14+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_1c15:
	/* 0x1c15: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1c18:
	/* 0x1c18: mov    WORD PTR [rsp],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c1c:
	/* 0x1c1c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c21:
	/* 0x1c21: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_1c28:
	/* 0x1c28: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1c2b:
	/* 0x1c2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c2d:
	/* 0x1c2d: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1c34:
	/* 0x1c34: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c37:
	/* 0x1c37: je     1c58 <trace_security_bpf+0x1c58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c58;
	}
x86_l_1c39:
	/* 0x1c39: lea    rsi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1c3d:
	/* 0x1c3d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1c42:
	/* 0x1c42: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1c45:
	/* 0x1c45: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1c47:
	/* 0x1c47: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c4a:
	/* 0x1c4a: je     1c58 <trace_security_bpf+0x1c58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c58;
	}
x86_l_1c4c:
	/* 0x1c4c: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c4f:
	/* 0x1c4f: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c53:
	/* 0x1c53: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1c56:
	/* 0x1c56: jmp    1c5a <trace_security_bpf+0x1c5a> */
	goto x86_l_1c5a;
x86_l_1c58:
	/* 0x1c58: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c5a:
	/* 0x1c5a: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1c5d:
	/* 0x1c5d: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1c60:
	/* 0x1c60: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1c63:
	/* 0x1c63: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1c66:
	/* 0x1c66: cmp    QWORD PTR [r14+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_1c6e:
	/* 0x1c6e: je     1d3f <trace_security_bpf+0x1d3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d3f;
	}
x86_l_1c74:
	/* 0x1c74: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1c7b:
	/* 0x1c7b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1c7f:
	/* 0x1c7f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c84:
	/* 0x1c84: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1c87:
	/* 0x1c87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c8c:
	/* 0x1c8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c8e:
	/* 0x1c8e: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c92:
	/* 0x1c92: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c97:
	/* 0x1c97: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1c9a:
	/* 0x1c9a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c9f:
	/* 0x1c9f: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1ca2:
	/* 0x1ca2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca4:
	/* 0x1ca4: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ca7:
	/* 0x1ca7: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1cab:
	/* 0x1cab: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1caf:
	/* 0x1caf: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1cb3:
	/* 0x1cb3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cb8:
	/* 0x1cb8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1cbb:
	/* 0x1cbb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cc0:
	/* 0x1cc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cc2:
	/* 0x1cc2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cc6:
	/* 0x1cc6: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1cca:
	/* 0x1cca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ccf:
	/* 0x1ccf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1cd2:
	/* 0x1cd2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cd7:
	/* 0x1cd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd9:
	/* 0x1cd9: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cdc:
	/* 0x1cdc: mov    DWORD PTR [r14+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ce0:
	/* 0x1ce0: mov    rbx,QWORD PTR [r14+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_1ce7:
	/* 0x1ce7: mov    r15,QWORD PTR [r14+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_1cee:
	/* 0x1cee: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1cf1:
	/* 0x1cf1: mov    WORD PTR [rsp],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cf5:
	/* 0x1cf5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cfa:
	/* 0x1cfa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_1d01:
	/* 0x1d01: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1d04:
	/* 0x1d04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d06:
	/* 0x1d06: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1d0d:
	/* 0x1d0d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d10:
	/* 0x1d10: je     1d31 <trace_security_bpf+0x1d31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d31;
	}
x86_l_1d12:
	/* 0x1d12: lea    rsi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d16:
	/* 0x1d16: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1d1b:
	/* 0x1d1b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1d1e:
	/* 0x1d1e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1d20:
	/* 0x1d20: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d23:
	/* 0x1d23: je     1d31 <trace_security_bpf+0x1d31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d31;
	}
x86_l_1d25:
	/* 0x1d25: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d28:
	/* 0x1d28: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d2c:
	/* 0x1d2c: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1d2f:
	/* 0x1d2f: jmp    1d33 <trace_security_bpf+0x1d33> */
	goto x86_l_1d33;
x86_l_1d31:
	/* 0x1d31: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d33:
	/* 0x1d33: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1d36:
	/* 0x1d36: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1d39:
	/* 0x1d39: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1d3c:
	/* 0x1d3c: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1d3f:
	/* 0x1d3f: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_1d47:
	/* 0x1d47: je     1e0a <trace_security_bpf+0x1e0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e0a;
	}
x86_l_1d4d:
	/* 0x1d4d: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1d52:
	/* 0x1d52: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1d59:
	/* 0x1d59: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d5e:
	/* 0x1d5e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1d61:
	/* 0x1d61: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d66:
	/* 0x1d66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d68:
	/* 0x1d68: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d6c:
	/* 0x1d6c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d71:
	/* 0x1d71: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1d74:
	/* 0x1d74: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d79:
	/* 0x1d79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d7b:
	/* 0x1d7b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d7f:
	/* 0x1d7f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d84:
	/* 0x1d84: mov    r15,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSP, X86_WIDTH_64);
x86_l_1d87:
	/* 0x1d87: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1d8a:
	/* 0x1d8a: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_1d8f:
	/* 0x1d8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d91:
	/* 0x1d91: lea    rbx,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1d95:
	/* 0x1d95: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1d9a:
	/* 0x1d9a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d9d:
	/* 0x1d9d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1da2:
	/* 0x1da2: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1da5:
	/* 0x1da5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1da7:
	/* 0x1da7: mov    r15,QWORD PTR [r14+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_1dae:
	/* 0x1dae: mov    r13,QWORD PTR [r14+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_1db5:
	/* 0x1db5: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1db8:
	/* 0x1db8: mov    WORD PTR [rsp],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dbc:
	/* 0x1dbc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dc1:
	/* 0x1dc1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_1dc8:
	/* 0x1dc8: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1dcb:
	/* 0x1dcb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dcd:
	/* 0x1dcd: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1dd4:
	/* 0x1dd4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dd7:
	/* 0x1dd7: je     1df7 <trace_security_bpf+0x1df7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1df7;
	}
x86_l_1dd9:
	/* 0x1dd9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1dde:
	/* 0x1dde: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1de1:
	/* 0x1de1: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1de4:
	/* 0x1de4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1de6:
	/* 0x1de6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1de9:
	/* 0x1de9: je     1df7 <trace_security_bpf+0x1df7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1df7;
	}
x86_l_1deb:
	/* 0x1deb: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dee:
	/* 0x1dee: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1df2:
	/* 0x1df2: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1df5:
	/* 0x1df5: jmp    1df9 <trace_security_bpf+0x1df9> */
	goto x86_l_1df9;
x86_l_1df7:
	/* 0x1df7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1df9:
	/* 0x1df9: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1dfc:
	/* 0x1dfc: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1dff:
	/* 0x1dff: or     rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1e02:
	/* 0x1e02: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_1e05:
	/* 0x1e05: movzx  ebp,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_1e0a:
	/* 0x1e0a: cmp    QWORD PTR [r14+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_1e12:
	/* 0x1e12: je     1e85 <trace_security_bpf+0x1e85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e85;
	}
x86_l_1e14:
	/* 0x1e14: lea    rbx,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1e18:
	/* 0x1e18: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1e1d:
	/* 0x1e1d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e20:
	/* 0x1e20: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e25:
	/* 0x1e25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e27:
	/* 0x1e27: mov    r15,QWORD PTR [r14+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_1e2e:
	/* 0x1e2e: mov    r13,QWORD PTR [r14+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_1e35:
	/* 0x1e35: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1e38:
	/* 0x1e38: mov    WORD PTR [rsp],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e3c:
	/* 0x1e3c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e41:
	/* 0x1e41: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_1e48:
	/* 0x1e48: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1e4b:
	/* 0x1e4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e4d:
	/* 0x1e4d: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1e54:
	/* 0x1e54: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e57:
	/* 0x1e57: je     1e77 <trace_security_bpf+0x1e77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e77;
	}
x86_l_1e59:
	/* 0x1e59: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1e5e:
	/* 0x1e5e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1e61:
	/* 0x1e61: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1e64:
	/* 0x1e64: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1e66:
	/* 0x1e66: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e69:
	/* 0x1e69: je     1e77 <trace_security_bpf+0x1e77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e77;
	}
x86_l_1e6b:
	/* 0x1e6b: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e6e:
	/* 0x1e6e: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e72:
	/* 0x1e72: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1e75:
	/* 0x1e75: jmp    1e79 <trace_security_bpf+0x1e79> */
	goto x86_l_1e79;
x86_l_1e77:
	/* 0x1e77: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e79:
	/* 0x1e79: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1e7c:
	/* 0x1e7c: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1e7f:
	/* 0x1e7f: or     rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1e82:
	/* 0x1e82: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_1e85:
	/* 0x1e85: mov    rbx,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_1e8c:
	/* 0x1e8c: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1e8f:
	/* 0x1e8f: mov    rbp,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1e97:
	/* 0x1e97: je     1f05 <trace_security_bpf+0x1f05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f05;
	}
x86_l_1e99:
	/* 0x1e99: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e9d:
	/* 0x1e9d: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ea0:
	/* 0x1ea0: mov    r15,QWORD PTR [r14+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_1ea7:
	/* 0x1ea7: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1eaa:
	/* 0x1eaa: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_1eaf:
	/* 0x1eaf: mov    WORD PTR [rsp+0xb0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1eb7:
	/* 0x1eb7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ebc:
	/* 0x1ebc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_1ec3:
	/* 0x1ec3: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1ecb:
	/* 0x1ecb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ecd:
	/* 0x1ecd: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1ed4:
	/* 0x1ed4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ed7:
	/* 0x1ed7: je     1ef7 <trace_security_bpf+0x1ef7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ef7;
	}
x86_l_1ed9:
	/* 0x1ed9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1ede:
	/* 0x1ede: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1ee1:
	/* 0x1ee1: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1ee4:
	/* 0x1ee4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1ee6:
	/* 0x1ee6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ee9:
	/* 0x1ee9: je     1ef7 <trace_security_bpf+0x1ef7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ef7;
	}
x86_l_1eeb:
	/* 0x1eeb: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1eee:
	/* 0x1eee: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ef2:
	/* 0x1ef2: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1ef5:
	/* 0x1ef5: jmp    1ef9 <trace_security_bpf+0x1ef9> */
	goto x86_l_1ef9;
x86_l_1ef7:
	/* 0x1ef7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ef9:
	/* 0x1ef9: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1efc:
	/* 0x1efc: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1eff:
	/* 0x1eff: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1f02:
	/* 0x1f02: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1f05:
	/* 0x1f05: mov    rbx,QWORD PTR [r14+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_1f0c:
	/* 0x1f0c: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1f0f:
	/* 0x1f0f: je     1f72 <trace_security_bpf+0x1f72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f72;
	}
x86_l_1f11:
	/* 0x1f11: mov    r15,QWORD PTR [r14+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_1f18:
	/* 0x1f18: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1f1b:
	/* 0x1f1b: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_1f20:
	/* 0x1f20: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f24:
	/* 0x1f24: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f29:
	/* 0x1f29: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_1f30:
	/* 0x1f30: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1f33:
	/* 0x1f33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f35:
	/* 0x1f35: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1f3c:
	/* 0x1f3c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f3f:
	/* 0x1f3f: je     1f64 <trace_security_bpf+0x1f64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f64;
	}
x86_l_1f41:
	/* 0x1f41: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1f46:
	/* 0x1f46: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1f49:
	/* 0x1f49: mov    rsi,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1f51:
	/* 0x1f51: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1f53:
	/* 0x1f53: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f56:
	/* 0x1f56: je     1f64 <trace_security_bpf+0x1f64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f64;
	}
x86_l_1f58:
	/* 0x1f58: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f5b:
	/* 0x1f5b: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f5f:
	/* 0x1f5f: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1f62:
	/* 0x1f62: jmp    1f66 <trace_security_bpf+0x1f66> */
	goto x86_l_1f66;
x86_l_1f64:
	/* 0x1f64: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f66:
	/* 0x1f66: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1f69:
	/* 0x1f69: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1f6c:
	/* 0x1f6c: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1f6f:
	/* 0x1f6f: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1f72:
	/* 0x1f72: mov    r15,QWORD PTR [r14+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_1f79:
	/* 0x1f79: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1f7c:
	/* 0x1f7c: je     200d <trace_security_bpf+0x200d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_200d;
	}
x86_l_1f82:
	/* 0x1f82: mov    r13,QWORD PTR [r14+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_1f89:
	/* 0x1f89: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1f8c:
	/* 0x1f8c: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_1f91:
	/* 0x1f91: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f95:
	/* 0x1f95: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f9a:
	/* 0x1f9a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_1fa1:
	/* 0x1fa1: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1fa4:
	/* 0x1fa4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fa6:
	/* 0x1fa6: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1fad:
	/* 0x1fad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fb0:
	/* 0x1fb0: je     1ff7 <trace_security_bpf+0x1ff7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ff7;
	}
x86_l_1fb2:
	/* 0x1fb2: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1fb5:
	/* 0x1fb5: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1fbd:
	/* 0x1fbd: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1fc1:
	/* 0x1fc1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fc6:
	/* 0x1fc6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1fc9:
	/* 0x1fc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fcb:
	/* 0x1fcb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fce:
	/* 0x1fce: jne    1feb <trace_security_bpf+0x1feb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1feb;
	}
x86_l_1fd0:
	/* 0x1fd0: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1fd8:
	/* 0x1fd8: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fdc:
	/* 0x1fdc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fe1:
	/* 0x1fe1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1fe4:
	/* 0x1fe4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fe6:
	/* 0x1fe6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fe9:
	/* 0x1fe9: je     1ff7 <trace_security_bpf+0x1ff7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ff7;
	}
x86_l_1feb:
	/* 0x1feb: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fee:
	/* 0x1fee: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ff2:
	/* 0x1ff2: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1ff5:
	/* 0x1ff5: jmp    1ff9 <trace_security_bpf+0x1ff9> */
	goto x86_l_1ff9;
x86_l_1ff7:
	/* 0x1ff7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ff9:
	/* 0x1ff9: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1ffc:
	/* 0x1ffc: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1fff:
	/* 0x1fff: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2002:
	/* 0x2002: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_2005:
	/* 0x2005: mov    rbp,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_200d:
	/* 0x200d: mov    rax,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_2014:
	/* 0x2014: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2017:
	/* 0x2017: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_201f:
	/* 0x201f: je     2030 <trace_security_bpf+0x2030> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2030;
	}
x86_l_2021:
	/* 0x2021: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2029:
	/* 0x2029: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_202d:
	/* 0x202d: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2030:
	/* 0x2030: and    r12,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_2037:
	/* 0x2037: mov    rcx,QWORD PTR [r14+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_203e:
	/* 0x203e: and    rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_2041:
	/* 0x2041: mov    QWORD PTR [r14+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2048:
	/* 0x2048: mov    r12,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2050:
	/* 0x2050: je     2c25 <trace_security_bpf+0x2c25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11301ULL;
	}
x86_l_2056:
	/* 0x2056: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_205d:
	/* 0x205d: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_2060:
	/* 0x2060: jne    2c2c <trace_security_bpf+0x2c2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11308ULL;
	}
x86_l_2066:
	/* 0x2066: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_206b:
	/* 0x206b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_206e:
	/* 0x206e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2073:
	/* 0x2073: mov    rbx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2078:
	/* 0x2078: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_207b:
	/* 0x207b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_207d:
	/* 0x207d: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2081:
	/* 0x2081: lea    rdx,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2085:
	/* 0x2085: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_208a:
	/* 0x208a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_208d:
	/* 0x208d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2092:
	/* 0x2092: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2094:
	/* 0x2094: mov    ebx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2097:
	/* 0x2097: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_209c:
	/* 0x209c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_209e:
	/* 0x209e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20a1:
	/* 0x20a1: je     2113 <trace_security_bpf+0x2113> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8467ULL;
	}
x86_l_20a3:
	/* 0x20a3: sub    rax,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_20a7:
	/* 0x20a7: mov    ecx,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 113ULL);
x86_l_20ac:
	/* 0x20ac: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_20b4:
	/* 0x20b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20b9:
	/* 0x20b9: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_20bc:
	/* 0x20bc: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_20be:
	/* 0x20be: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20c3:
	/* 0x20c3: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_20cb:
	/* 0x20cb: lea    rdi,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_20d3:
	/* 0x20d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20d8:
	/* 0x20d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20da:
	/* 0x20da: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20df:
	/* 0x20df: mov    rdx,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_20e7:
	/* 0x20e7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
	return 8426ULL;
}

static __noinline __u64 tracee_trace_security_bpf_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8426ULL: goto x86_l_20ea;
	case 8431ULL: goto x86_l_20ef;
	case 8433ULL: goto x86_l_20f1;
	case 8437ULL: goto x86_l_20f5;
	case 8440ULL: goto x86_l_20f8;
	case 8442ULL: goto x86_l_20fa;
	case 8446ULL: goto x86_l_20fe;
	case 8451ULL: goto x86_l_2103;
	case 8454ULL: goto x86_l_2106;
	case 8459ULL: goto x86_l_210b;
	case 8461ULL: goto x86_l_210d;
	case 8465ULL: goto x86_l_2111;
	case 8467ULL: goto x86_l_2113;
	case 8469ULL: goto x86_l_2115;
	case 8474ULL: goto x86_l_211a;
	case 8476ULL: goto x86_l_211c;
	case 8479ULL: goto x86_l_211f;
	case 8481ULL: goto x86_l_2121;
	case 8485ULL: goto x86_l_2125;
	case 8490ULL: goto x86_l_212a;
	case 8498ULL: goto x86_l_2132;
	case 8503ULL: goto x86_l_2137;
	case 8506ULL: goto x86_l_213a;
	case 8508ULL: goto x86_l_213c;
	case 8513ULL: goto x86_l_2141;
	case 8521ULL: goto x86_l_2149;
	case 8529ULL: goto x86_l_2151;
	case 8534ULL: goto x86_l_2156;
	case 8536ULL: goto x86_l_2158;
	case 8541ULL: goto x86_l_215d;
	case 8549ULL: goto x86_l_2165;
	case 8552ULL: goto x86_l_2168;
	case 8557ULL: goto x86_l_216d;
	case 8559ULL: goto x86_l_216f;
	case 8563ULL: goto x86_l_2173;
	case 8566ULL: goto x86_l_2176;
	case 8568ULL: goto x86_l_2178;
	case 8572ULL: goto x86_l_217c;
	case 8577ULL: goto x86_l_2181;
	case 8580ULL: goto x86_l_2184;
	case 8585ULL: goto x86_l_2189;
	case 8587ULL: goto x86_l_218b;
	case 8591ULL: goto x86_l_218f;
	case 8593ULL: goto x86_l_2191;
	case 8595ULL: goto x86_l_2193;
	case 8599ULL: goto x86_l_2197;
	case 8604ULL: goto x86_l_219c;
	case 8607ULL: goto x86_l_219f;
	case 8612ULL: goto x86_l_21a4;
	case 8614ULL: goto x86_l_21a6;
	case 8618ULL: goto x86_l_21aa;
	case 8623ULL: goto x86_l_21af;
	case 8626ULL: goto x86_l_21b2;
	case 8631ULL: goto x86_l_21b7;
	case 8633ULL: goto x86_l_21b9;
	case 8637ULL: goto x86_l_21bd;
	case 8641ULL: goto x86_l_21c1;
	case 8646ULL: goto x86_l_21c6;
	case 8649ULL: goto x86_l_21c9;
	case 8654ULL: goto x86_l_21ce;
	case 8656ULL: goto x86_l_21d0;
	case 8660ULL: goto x86_l_21d4;
	case 8665ULL: goto x86_l_21d9;
	case 8668ULL: goto x86_l_21dc;
	case 8673ULL: goto x86_l_21e1;
	case 8676ULL: goto x86_l_21e4;
	case 8678ULL: goto x86_l_21e6;
	case 8682ULL: goto x86_l_21ea;
	case 8687ULL: goto x86_l_21ef;
	case 8690ULL: goto x86_l_21f2;
	case 8695ULL: goto x86_l_21f7;
	case 8698ULL: goto x86_l_21fa;
	case 8700ULL: goto x86_l_21fc;
	case 8706ULL: goto x86_l_2202;
	case 8711ULL: goto x86_l_2207;
	case 8714ULL: goto x86_l_220a;
	case 8719ULL: goto x86_l_220f;
	case 8722ULL: goto x86_l_2212;
	case 8724ULL: goto x86_l_2214;
	case 8728ULL: goto x86_l_2218;
	case 8733ULL: goto x86_l_221d;
	case 8738ULL: goto x86_l_2222;
	case 8741ULL: goto x86_l_2225;
	case 8746ULL: goto x86_l_222a;
	case 8751ULL: goto x86_l_222f;
	case 8753ULL: goto x86_l_2231;
	case 8755ULL: goto x86_l_2233;
	case 8760ULL: goto x86_l_2238;
	case 8765ULL: goto x86_l_223d;
	case 8767ULL: goto x86_l_223f;
	case 8769ULL: goto x86_l_2241;
	case 8774ULL: goto x86_l_2246;
	case 8776ULL: goto x86_l_2248;
	case 8782ULL: goto x86_l_224e;
	case 8787ULL: goto x86_l_2253;
	case 8792ULL: goto x86_l_2258;
	case 8794ULL: goto x86_l_225a;
	case 8796ULL: goto x86_l_225c;
	case 8801ULL: goto x86_l_2261;
	case 8806ULL: goto x86_l_2266;
	case 8808ULL: goto x86_l_2268;
	case 8810ULL: goto x86_l_226a;
	case 8815ULL: goto x86_l_226f;
	case 8820ULL: goto x86_l_2274;
	case 8822ULL: goto x86_l_2276;
	case 8824ULL: goto x86_l_2278;
	case 8829ULL: goto x86_l_227d;
	case 8831ULL: goto x86_l_227f;
	case 8833ULL: goto x86_l_2281;
	case 8838ULL: goto x86_l_2286;
	case 8843ULL: goto x86_l_228b;
	case 8845ULL: goto x86_l_228d;
	case 8847ULL: goto x86_l_228f;
	case 8851ULL: goto x86_l_2293;
	case 8853ULL: goto x86_l_2295;
	case 8858ULL: goto x86_l_229a;
	case 8863ULL: goto x86_l_229f;
	case 8867ULL: goto x86_l_22a3;
	case 8873ULL: goto x86_l_22a9;
	case 8876ULL: goto x86_l_22ac;
	case 8878ULL: goto x86_l_22ae;
	case 8880ULL: goto x86_l_22b0;
	case 8884ULL: goto x86_l_22b4;
	case 8889ULL: goto x86_l_22b9;
	case 8892ULL: goto x86_l_22bc;
	case 8897ULL: goto x86_l_22c1;
	case 8900ULL: goto x86_l_22c4;
	case 8902ULL: goto x86_l_22c6;
	case 8908ULL: goto x86_l_22cc;
	case 8913ULL: goto x86_l_22d1;
	case 8918ULL: goto x86_l_22d6;
	case 8922ULL: goto x86_l_22da;
	case 8928ULL: goto x86_l_22e0;
	case 8931ULL: goto x86_l_22e3;
	case 8939ULL: goto x86_l_22eb;
	case 8947ULL: goto x86_l_22f3;
	case 8953ULL: goto x86_l_22f9;
	case 8957ULL: goto x86_l_22fd;
	case 8962ULL: goto x86_l_2302;
	case 8965ULL: goto x86_l_2305;
	case 8970ULL: goto x86_l_230a;
	case 8972ULL: goto x86_l_230c;
	case 8977ULL: goto x86_l_2311;
	case 8983ULL: goto x86_l_2317;
	case 8987ULL: goto x86_l_231b;
	case 8991ULL: goto x86_l_231f;
	case 8996ULL: goto x86_l_2324;
	case 8999ULL: goto x86_l_2327;
	case 9004ULL: goto x86_l_232c;
	case 9007ULL: goto x86_l_232f;
	case 9009ULL: goto x86_l_2331;
	case 9015ULL: goto x86_l_2337;
	case 9020ULL: goto x86_l_233c;
	case 9023ULL: goto x86_l_233f;
	case 9028ULL: goto x86_l_2344;
	case 9031ULL: goto x86_l_2347;
	case 9033ULL: goto x86_l_2349;
	case 9037ULL: goto x86_l_234d;
	case 9045ULL: goto x86_l_2355;
	case 9050ULL: goto x86_l_235a;
	case 9053ULL: goto x86_l_235d;
	case 9057ULL: goto x86_l_2361;
	case 9062ULL: goto x86_l_2366;
	case 9067ULL: goto x86_l_236b;
	case 9072ULL: goto x86_l_2370;
	case 9076ULL: goto x86_l_2374;
	case 9082ULL: goto x86_l_237a;
	case 9086ULL: goto x86_l_237e;
	case 9091ULL: goto x86_l_2383;
	case 9094ULL: goto x86_l_2386;
	case 9099ULL: goto x86_l_238b;
	case 9102ULL: goto x86_l_238e;
	case 9104ULL: goto x86_l_2390;
	case 9108ULL: goto x86_l_2394;
	case 9113ULL: goto x86_l_2399;
	case 9116ULL: goto x86_l_239c;
	case 9121ULL: goto x86_l_23a1;
	case 9124ULL: goto x86_l_23a4;
	case 9126ULL: goto x86_l_23a6;
	case 9132ULL: goto x86_l_23ac;
	case 9137ULL: goto x86_l_23b1;
	case 9140ULL: goto x86_l_23b4;
	case 9145ULL: goto x86_l_23b9;
	case 9148ULL: goto x86_l_23bc;
	case 9150ULL: goto x86_l_23be;
	case 9154ULL: goto x86_l_23c2;
	case 9162ULL: goto x86_l_23ca;
	case 9167ULL: goto x86_l_23cf;
	case 9170ULL: goto x86_l_23d2;
	case 9176ULL: goto x86_l_23d8;
	case 9179ULL: goto x86_l_23db;
	case 9183ULL: goto x86_l_23df;
	case 9188ULL: goto x86_l_23e4;
	case 9191ULL: goto x86_l_23e7;
	case 9196ULL: goto x86_l_23ec;
	case 9199ULL: goto x86_l_23ef;
	case 9201ULL: goto x86_l_23f1;
	case 9205ULL: goto x86_l_23f5;
	case 9213ULL: goto x86_l_23fd;
	case 9221ULL: goto x86_l_2405;
	case 9226ULL: goto x86_l_240a;
	case 9229ULL: goto x86_l_240d;
	case 9234ULL: goto x86_l_2412;
	case 9237ULL: goto x86_l_2415;
	case 9239ULL: goto x86_l_2417;
	case 9242ULL: goto x86_l_241a;
	case 9249ULL: goto x86_l_2421;
	case 9253ULL: goto x86_l_2425;
	case 9258ULL: goto x86_l_242a;
	case 9261ULL: goto x86_l_242d;
	case 9266ULL: goto x86_l_2432;
	case 9269ULL: goto x86_l_2435;
	case 9271ULL: goto x86_l_2437;
	case 9275ULL: goto x86_l_243b;
	case 9280ULL: goto x86_l_2440;
	case 9283ULL: goto x86_l_2443;
	case 9288ULL: goto x86_l_2448;
	case 9291ULL: goto x86_l_244b;
	case 9293ULL: goto x86_l_244d;
	case 9296ULL: goto x86_l_2450;
	case 9303ULL: goto x86_l_2457;
	case 9307ULL: goto x86_l_245b;
	case 9312ULL: goto x86_l_2460;
	case 9320ULL: goto x86_l_2468;
	case 9325ULL: goto x86_l_246d;
	case 9328ULL: goto x86_l_2470;
	case 9330ULL: goto x86_l_2472;
	case 9342ULL: goto x86_l_247e;
	case 9354ULL: goto x86_l_248a;
	case 9366ULL: goto x86_l_2496;
	case 9378ULL: goto x86_l_24a2;
	case 9383ULL: goto x86_l_24a7;
	case 9390ULL: goto x86_l_24ae;
	case 9398ULL: goto x86_l_24b6;
	case 9400ULL: goto x86_l_24b8;
	case 9403ULL: goto x86_l_24bb;
	case 9406ULL: goto x86_l_24be;
	case 9414ULL: goto x86_l_24c6;
	case 9418ULL: goto x86_l_24ca;
	case 9426ULL: goto x86_l_24d2;
	case 9433ULL: goto x86_l_24d9;
	case 9439ULL: goto x86_l_24df;
	case 9448ULL: goto x86_l_24e8;
	case 9454ULL: goto x86_l_24ee;
	case 9456ULL: goto x86_l_24f0;
	case 9460ULL: goto x86_l_24f4;
	case 9467ULL: goto x86_l_24fb;
	case 9472ULL: goto x86_l_2500;
	case 9480ULL: goto x86_l_2508;
	case 9485ULL: goto x86_l_250d;
	case 9487ULL: goto x86_l_250f;
	case 9490ULL: goto x86_l_2512;
	case 9492ULL: goto x86_l_2514;
	case 9495ULL: goto x86_l_2517;
	case 9503ULL: goto x86_l_251f;
	case 9510ULL: goto x86_l_2526;
	case 9512ULL: goto x86_l_2528;
	case 9520ULL: goto x86_l_2530;
	case 9523ULL: goto x86_l_2533;
	case 9528ULL: goto x86_l_2538;
	case 9534ULL: goto x86_l_253e;
	case 9543ULL: goto x86_l_2547;
	case 9551ULL: goto x86_l_254f;
	case 9559ULL: goto x86_l_2557;
	case 9564ULL: goto x86_l_255c;
	case 9566ULL: goto x86_l_255e;
	case 9571ULL: goto x86_l_2563;
	case 9579ULL: goto x86_l_256b;
	case 9583ULL: goto x86_l_256f;
	case 9590ULL: goto x86_l_2576;
	case 9598ULL: goto x86_l_257e;
	case 9603ULL: goto x86_l_2583;
	case 9605ULL: goto x86_l_2585;
	case 9607ULL: goto x86_l_2587;
	case 9609ULL: goto x86_l_2589;
	case 9617ULL: goto x86_l_2591;
	case 9624ULL: goto x86_l_2598;
	case 9626ULL: goto x86_l_259a;
	case 9634ULL: goto x86_l_25a2;
	case 9642ULL: goto x86_l_25aa;
	case 9645ULL: goto x86_l_25ad;
	case 9653ULL: goto x86_l_25b5;
	case 9660ULL: goto x86_l_25bc;
	case 9668ULL: goto x86_l_25c4;
	case 9675ULL: goto x86_l_25cb;
	case 9681ULL: goto x86_l_25d1;
	case 9690ULL: goto x86_l_25da;
	case 9696ULL: goto x86_l_25e0;
	case 9698ULL: goto x86_l_25e2;
	case 9702ULL: goto x86_l_25e6;
	case 9709ULL: goto x86_l_25ed;
	case 9714ULL: goto x86_l_25f2;
	case 9722ULL: goto x86_l_25fa;
	case 9727ULL: goto x86_l_25ff;
	case 9729ULL: goto x86_l_2601;
	case 9732ULL: goto x86_l_2604;
	case 9734ULL: goto x86_l_2606;
	case 9737ULL: goto x86_l_2609;
	case 9745ULL: goto x86_l_2611;
	case 9752ULL: goto x86_l_2618;
	case 9754ULL: goto x86_l_261a;
	case 9762ULL: goto x86_l_2622;
	case 9765ULL: goto x86_l_2625;
	case 9770ULL: goto x86_l_262a;
	case 9776ULL: goto x86_l_2630;
	case 9785ULL: goto x86_l_2639;
	case 9793ULL: goto x86_l_2641;
	case 9800ULL: goto x86_l_2648;
	case 9802ULL: goto x86_l_264a;
	case 9813ULL: goto x86_l_2655;
	case 9821ULL: goto x86_l_265d;
	case 9827ULL: goto x86_l_2663;
	case 9829ULL: goto x86_l_2665;
	case 9834ULL: goto x86_l_266a;
	case 9842ULL: goto x86_l_2672;
	case 9846ULL: goto x86_l_2676;
	case 9853ULL: goto x86_l_267d;
	case 9858ULL: goto x86_l_2682;
	case 9861ULL: goto x86_l_2685;
	case 9863ULL: goto x86_l_2687;
	case 9871ULL: goto x86_l_268f;
	case 9874ULL: goto x86_l_2692;
	case 9876ULL: goto x86_l_2694;
	case 9883ULL: goto x86_l_269b;
	case 9886ULL: goto x86_l_269e;
	case 9894ULL: goto x86_l_26a6;
	case 9897ULL: goto x86_l_26a9;
	case 9902ULL: goto x86_l_26ae;
	case 9908ULL: goto x86_l_26b4;
	case 9917ULL: goto x86_l_26bd;
	case 9925ULL: goto x86_l_26c5;
	case 9933ULL: goto x86_l_26cd;
	case 9938ULL: goto x86_l_26d2;
	case 9940ULL: goto x86_l_26d4;
	case 9945ULL: goto x86_l_26d9;
	case 9953ULL: goto x86_l_26e1;
	case 9957ULL: goto x86_l_26e5;
	case 9964ULL: goto x86_l_26ec;
	case 9972ULL: goto x86_l_26f4;
	case 9977ULL: goto x86_l_26f9;
	case 9979ULL: goto x86_l_26fb;
	case 9981ULL: goto x86_l_26fd;
	case 9983ULL: goto x86_l_26ff;
	case 9991ULL: goto x86_l_2707;
	case 9998ULL: goto x86_l_270e;
	case 10000ULL: goto x86_l_2710;
	case 10008ULL: goto x86_l_2718;
	case 10016ULL: goto x86_l_2720;
	case 10019ULL: goto x86_l_2723;
	case 10027ULL: goto x86_l_272b;
	case 10034ULL: goto x86_l_2732;
	case 10042ULL: goto x86_l_273a;
	case 10049ULL: goto x86_l_2741;
	case 10051ULL: goto x86_l_2743;
	case 10060ULL: goto x86_l_274c;
	case 10066ULL: goto x86_l_2752;
	case 10068ULL: goto x86_l_2754;
	case 10072ULL: goto x86_l_2758;
	case 10079ULL: goto x86_l_275f;
	case 10084ULL: goto x86_l_2764;
	case 10092ULL: goto x86_l_276c;
	case 10097ULL: goto x86_l_2771;
	case 10099ULL: goto x86_l_2773;
	case 10102ULL: goto x86_l_2776;
	case 10104ULL: goto x86_l_2778;
	case 10107ULL: goto x86_l_277b;
	case 10115ULL: goto x86_l_2783;
	case 10122ULL: goto x86_l_278a;
	case 10130ULL: goto x86_l_2792;
	case 10138ULL: goto x86_l_279a;
	case 10145ULL: goto x86_l_27a1;
	case 10147ULL: goto x86_l_27a3;
	case 10156ULL: goto x86_l_27ac;
	case 10162ULL: goto x86_l_27b2;
	case 10164ULL: goto x86_l_27b4;
	case 10168ULL: goto x86_l_27b8;
	case 10175ULL: goto x86_l_27bf;
	case 10180ULL: goto x86_l_27c4;
	case 10188ULL: goto x86_l_27cc;
	case 10193ULL: goto x86_l_27d1;
	case 10195ULL: goto x86_l_27d3;
	case 10198ULL: goto x86_l_27d6;
	case 10200ULL: goto x86_l_27d8;
	case 10203ULL: goto x86_l_27db;
	default: return 0xffffffffffffffffULL;
	}
x86_l_20ea:
	/* 0x20ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20ef:
	/* 0x20ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20f1:
	/* 0x20f1: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20f5:
	/* 0x20f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20f8:
	/* 0x20f8: je     2113 <trace_security_bpf+0x2113> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2113;
	}
x86_l_20fa:
	/* 0x20fa: lea    rdx,[rax+r15*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 0ULL);
x86_l_20fe:
	/* 0x20fe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2103:
	/* 0x2103: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2106:
	/* 0x2106: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_210b:
	/* 0x210b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_210d:
	/* 0x210d: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2111:
	/* 0x2111: jmp    2115 <trace_security_bpf+0x2115> */
	goto x86_l_2115;
x86_l_2113:
	/* 0x2113: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2115:
	/* 0x2115: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_211a:
	/* 0x211a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_211c:
	/* 0x211c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_211f:
	/* 0x211f: je     2191 <trace_security_bpf+0x2191> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2191;
	}
x86_l_2121:
	/* 0x2121: sub    rax,0xffffffffffffff80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SUB, 18446744073709551488ULL);
x86_l_2125:
	/* 0x2125: mov    ecx,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 113ULL);
x86_l_212a:
	/* 0x212a: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2132:
	/* 0x2132: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2137:
	/* 0x2137: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_213a:
	/* 0x213a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_213c:
	/* 0x213c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2141:
	/* 0x2141: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2149:
	/* 0x2149: lea    rdi,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2151:
	/* 0x2151: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2156:
	/* 0x2156: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2158:
	/* 0x2158: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_215d:
	/* 0x215d: mov    rdx,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2165:
	/* 0x2165: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2168:
	/* 0x2168: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_216d:
	/* 0x216d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_216f:
	/* 0x216f: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2173:
	/* 0x2173: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2176:
	/* 0x2176: je     2191 <trace_security_bpf+0x2191> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2191;
	}
x86_l_2178:
	/* 0x2178: lea    rdx,[rax+rbx*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 3), 0ULL);
x86_l_217c:
	/* 0x217c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2181:
	/* 0x2181: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2184:
	/* 0x2184: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2189:
	/* 0x2189: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_218b:
	/* 0x218b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_218f:
	/* 0x218f: jmp    2193 <trace_security_bpf+0x2193> */
	goto x86_l_2193;
x86_l_2191:
	/* 0x2191: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2193:
	/* 0x2193: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_2197:
	/* 0x2197: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_219c:
	/* 0x219c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_219f:
	/* 0x219f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21a4:
	/* 0x21a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21a6:
	/* 0x21a6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21aa:
	/* 0x21aa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21af:
	/* 0x21af: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_21b2:
	/* 0x21b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21b7:
	/* 0x21b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21b9:
	/* 0x21b9: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21bd:
	/* 0x21bd: lea    rdx,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21c1:
	/* 0x21c1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21c6:
	/* 0x21c6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_21c9:
	/* 0x21c9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_21ce:
	/* 0x21ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21d0:
	/* 0x21d0: mov    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21d4:
	/* 0x21d4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21d9:
	/* 0x21d9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_21dc:
	/* 0x21dc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21e1:
	/* 0x21e1: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_21e4:
	/* 0x21e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21e6:
	/* 0x21e6: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21ea:
	/* 0x21ea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21ef:
	/* 0x21ef: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_21f2:
	/* 0x21f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21f7:
	/* 0x21f7: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_21fa:
	/* 0x21fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21fc:
	/* 0x21fc: mov    r13d,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 115ULL);
x86_l_2202:
	/* 0x2202: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2207:
	/* 0x2207: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_220a:
	/* 0x220a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_220f:
	/* 0x220f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2212:
	/* 0x2212: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2214:
	/* 0x2214: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2218:
	/* 0x2218: lea    rdi,[rsp+0x6c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_221d:
	/* 0x221d: mov    esi,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 9ULL);
x86_l_2222:
	/* 0x2222: call   r13 */
	X86_SIM_BPF_CALL_REG(X86_R13);
x86_l_2225:
	/* 0x2225: mov    BYTE PTR [rsp+0x74],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_222a:
	/* 0x222a: movzx  eax,BYTE PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 108ULL);
x86_l_222f:
	/* 0x222f: cmp    al,0x73 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 115ULL);
x86_l_2231:
	/* 0x2231: jne    229a <trace_security_bpf+0x229a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_229a;
	}
x86_l_2233:
	/* 0x2233: movzx  eax,BYTE PTR [rsp+0x6d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 109ULL);
x86_l_2238:
	/* 0x2238: mov    ecx,0x79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 121ULL);
x86_l_223d:
	/* 0x223d: cmp    al,0x79 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 121ULL);
x86_l_223f:
	/* 0x223f: jne    229f <trace_security_bpf+0x229f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_229f;
	}
x86_l_2241:
	/* 0x2241: movzx  eax,BYTE PTR [rsp+0x6e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 110ULL);
x86_l_2246:
	/* 0x2246: cmp    al,0x73 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 115ULL);
x86_l_2248:
	/* 0x2248: jne    236b <trace_security_bpf+0x236b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_236b;
	}
x86_l_224e:
	/* 0x224e: movzx  eax,BYTE PTR [rsp+0x6f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 111ULL);
x86_l_2253:
	/* 0x2253: mov    ecx,0x63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 99ULL);
x86_l_2258:
	/* 0x2258: cmp    al,0x63 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 99ULL);
x86_l_225a:
	/* 0x225a: jne    229f <trace_security_bpf+0x229f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_229f;
	}
x86_l_225c:
	/* 0x225c: movzx  eax,BYTE PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 112ULL);
x86_l_2261:
	/* 0x2261: mov    ecx,0x61 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 97ULL);
x86_l_2266:
	/* 0x2266: cmp    al,0x61 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 97ULL);
x86_l_2268:
	/* 0x2268: jne    229f <trace_security_bpf+0x229f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_229f;
	}
x86_l_226a:
	/* 0x226a: movzx  eax,BYTE PTR [rsp+0x71] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 113ULL);
x86_l_226f:
	/* 0x226f: mov    ecx,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 108ULL);
x86_l_2274:
	/* 0x2274: cmp    al,0x6c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 108ULL);
x86_l_2276:
	/* 0x2276: jne    229f <trace_security_bpf+0x229f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_229f;
	}
x86_l_2278:
	/* 0x2278: movzx  eax,BYTE PTR [rsp+0x72] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 114ULL);
x86_l_227d:
	/* 0x227d: cmp    al,0x6c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 108ULL);
x86_l_227f:
	/* 0x227f: jne    229f <trace_security_bpf+0x229f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_229f;
	}
x86_l_2281:
	/* 0x2281: movzx  eax,BYTE PTR [rsp+0x73] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 115ULL);
x86_l_2286:
	/* 0x2286: mov    ecx,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 115ULL);
x86_l_228b:
	/* 0x228b: cmp    al,0x73 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 115ULL);
x86_l_228d:
	/* 0x228d: jne    229f <trace_security_bpf+0x229f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_229f;
	}
x86_l_228f:
	/* 0x228f: test   r12b,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_8, 16ULL);
x86_l_2293:
	/* 0x2293: je     22b0 <trace_security_bpf+0x22b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22b0;
	}
x86_l_2295:
	/* 0x2295: jmp    237a <trace_security_bpf+0x237a> */
	goto x86_l_237a;
x86_l_229a:
	/* 0x229a: mov    ecx,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 115ULL);
x86_l_229f:
	/* 0x229f: test   r12b,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_8, 16ULL);
x86_l_22a3:
	/* 0x22a3: jne    237a <trace_security_bpf+0x237a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_237a;
	}
x86_l_22a9:
	/* 0x22a9: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_22ac:
	/* 0x22ac: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_22ae:
	/* 0x22ae: jne    22d6 <trace_security_bpf+0x22d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22d6;
	}
x86_l_22b0:
	/* 0x22b0: add    rbx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_22b4:
	/* 0x22b4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22b9:
	/* 0x22b9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_22bc:
	/* 0x22bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22c1:
	/* 0x22c1: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_22c4:
	/* 0x22c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22c6:
	/* 0x22c6: mov    r15d,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 115ULL);
x86_l_22cc:
	/* 0x22cc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22d1:
	/* 0x22d1: jmp    23b1 <trace_security_bpf+0x23b1> */
	goto x86_l_23b1;
x86_l_22d6:
	/* 0x22d6: test   r12b,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_8, 64ULL);
x86_l_22da:
	/* 0x22da: jne    2df6 <trace_security_bpf+0x2df6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11766ULL;
	}
x86_l_22e0:
	/* 0x22e0: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_22e3:
	/* 0x22e3: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_22eb:
	/* 0x22eb: mov    r12,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_22f3:
	/* 0x22f3: jns    2c1d <trace_security_bpf+0x2c1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 11293ULL;
	}
x86_l_22f9:
	/* 0x22f9: lea    rdx,[rbx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_22fd:
	/* 0x22fd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2302:
	/* 0x2302: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2305:
	/* 0x2305: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_230a:
	/* 0x230a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_230c:
	/* 0x230c: cmp    QWORD PTR [rsp],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2311:
	/* 0x2311: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_2317:
	/* 0x2317: sbb    r12d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SBB, 0ULL);
x86_l_231b:
	/* 0x231b: lea    r15,[rbx-0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_231f:
	/* 0x231f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2324:
	/* 0x2324: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2327:
	/* 0x2327: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_232c:
	/* 0x232c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_232f:
	/* 0x232f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2331:
	/* 0x2331: mov    r13d,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 115ULL);
x86_l_2337:
	/* 0x2337: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_233c:
	/* 0x233c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_233f:
	/* 0x233f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2344:
	/* 0x2344: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2347:
	/* 0x2347: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2349:
	/* 0x2349: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_234d:
	/* 0x234d: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2355:
	/* 0x2355: mov    esi,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 64ULL);
x86_l_235a:
	/* 0x235a: call   r13 */
	X86_SIM_BPF_CALL_REG(X86_R13);
x86_l_235d:
	/* 0x235d: add    rbx,0xfffffffffffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551608ULL);
x86_l_2361:
	/* 0x2361: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2366:
	/* 0x2366: jmp    2e71 <trace_security_bpf+0x2e71> */
	return 11889ULL;
x86_l_236b:
	/* 0x236b: mov    ecx,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 115ULL);
x86_l_2370:
	/* 0x2370: test   r12b,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_8, 16ULL);
x86_l_2374:
	/* 0x2374: je     22a9 <trace_security_bpf+0x22a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22a9;
	}
x86_l_237a:
	/* 0x237a: add    rbx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_237e:
	/* 0x237e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2383:
	/* 0x2383: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2386:
	/* 0x2386: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_238b:
	/* 0x238b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_238e:
	/* 0x238e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2390:
	/* 0x2390: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2394:
	/* 0x2394: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2399:
	/* 0x2399: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_239c:
	/* 0x239c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23a1:
	/* 0x23a1: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_23a4:
	/* 0x23a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23a6:
	/* 0x23a6: mov    r15d,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 115ULL);
x86_l_23ac:
	/* 0x23ac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23b1:
	/* 0x23b1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_23b4:
	/* 0x23b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23b9:
	/* 0x23b9: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_23bc:
	/* 0x23bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23be:
	/* 0x23be: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23c2:
	/* 0x23c2: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_23ca:
	/* 0x23ca: mov    esi,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 64ULL);
x86_l_23cf:
	/* 0x23cf: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_23d2:
	/* 0x23d2: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_23d8:
	/* 0x23d8: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23db:
	/* 0x23db: add    rbp,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_23df:
	/* 0x23df: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23e4:
	/* 0x23e4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_23e7:
	/* 0x23e7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23ec:
	/* 0x23ec: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_23ef:
	/* 0x23ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23f1:
	/* 0x23f1: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23f5:
	/* 0x23f5: mov    QWORD PTR [rsp+0x118],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_23fd:
	/* 0x23fd: mov    DWORD PTR [rsp+0x138],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_2405:
	/* 0x2405: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_240a:
	/* 0x240a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_240d:
	/* 0x240d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2412:
	/* 0x2412: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2415:
	/* 0x2415: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2417:
	/* 0x2417: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_241a:
	/* 0x241a: mov    DWORD PTR [rsp+0x134],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 308ULL);
x86_l_2421:
	/* 0x2421: add    rbx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2425:
	/* 0x2425: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_242a:
	/* 0x242a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_242d:
	/* 0x242d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2432:
	/* 0x2432: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2435:
	/* 0x2435: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2437:
	/* 0x2437: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_243b:
	/* 0x243b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2440:
	/* 0x2440: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2443:
	/* 0x2443: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2448:
	/* 0x2448: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_244b:
	/* 0x244b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_244d:
	/* 0x244d: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2450:
	/* 0x2450: mov    DWORD PTR [rsp+0x94],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_2457:
	/* 0x2457: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_245b:
	/* 0x245b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2460:
	/* 0x2460: lea    rdi,[rsp+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2468:
	/* 0x2468: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_246d:
	/* 0x246d: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2470:
	/* 0x2470: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2472:
	/* 0x2472: mov    QWORD PTR [rsp+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_247e:
	/* 0x247e: mov    QWORD PTR [rsp+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_248a:
	/* 0x248a: mov    QWORD PTR [rsp+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_2496:
	/* 0x2496: mov    QWORD PTR [rsp+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_24a2:
	/* 0x24a2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24a7:
	/* 0x24a7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_HELPER_ID(X86_RDI, X86_SIM_HELPER_bpf_attach_map);
x86_l_24ae:
	/* 0x24ae: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_24b6:
	/* 0x24b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b8:
	/* 0x24b8: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_24bb:
	/* 0x24bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24be:
	/* 0x24be: lea    rax,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_24c6:
	/* 0x24c6: cmove  r15,rax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_64, X86_CC_E);
x86_l_24ca:
	/* 0x24ca: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_24d2:
	/* 0x24d2: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_24d9:
	/* 0x24d9: ja     25bc <trace_security_bpf+0x25bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_25bc;
	}
x86_l_24df:
	/* 0x24df: mov    BYTE PTR [r14+rbx*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519552ULL);
x86_l_24e8:
	/* 0x24e8: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_24ee:
	/* 0x24ee: ja     2528 <trace_security_bpf+0x2528> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2528;
	}
x86_l_24f0:
	/* 0x24f0: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_24f4:
	/* 0x24f4: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_24fb:
	/* 0x24fb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2500:
	/* 0x2500: lea    rdx,[rsp+0x134] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 308ULL);
x86_l_2508:
	/* 0x2508: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_250d:
	/* 0x250d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_250f:
	/* 0x250f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2512:
	/* 0x2512: js     2528 <trace_security_bpf+0x2528> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2528;
	}
x86_l_2514:
	/* 0x2514: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2517:
	/* 0x2517: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_251f:
	/* 0x251f: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2526:
	/* 0x2526: jmp    2530 <trace_security_bpf+0x2530> */
	goto x86_l_2530;
x86_l_2528:
	/* 0x2528: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2530:
	/* 0x2530: movzx  eax,bx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2533:
	/* 0x2533: cmp    eax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31999ULL);
x86_l_2538:
	/* 0x2538: ja     25bc <trace_security_bpf+0x25bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_25bc;
	}
x86_l_253e:
	/* 0x253e: mov    BYTE PTR [r14+rax*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519553ULL);
x86_l_2547:
	/* 0x2547: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_254f:
	/* 0x254f: mov    WORD PTR [r14+0x7d8e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32142ULL);
x86_l_2557:
	/* 0x2557: cmp    eax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27899ULL);
x86_l_255c:
	/* 0x255c: ja     25bc <trace_security_bpf+0x25bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_25bc;
	}
x86_l_255e:
	/* 0x255e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2563:
	/* 0x2563: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_256b:
	/* 0x256b: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_256f:
	/* 0x256f: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_2576:
	/* 0x2576: lea    rdx,[rsp+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_257e:
	/* 0x257e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2583:
	/* 0x2583: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2585:
	/* 0x2585: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2587:
	/* 0x2587: jle    25bc <trace_security_bpf+0x25bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_25bc;
	}
x86_l_2589:
	/* 0x2589: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2591:
	/* 0x2591: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_2598:
	/* 0x2598: ja     25bc <trace_security_bpf+0x25bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_25bc;
	}
x86_l_259a:
	/* 0x259a: mov    DWORD PTR [rcx+r14*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_25a2:
	/* 0x25a2: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_25aa:
	/* 0x25aa: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_25ad:
	/* 0x25ad: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_25b5:
	/* 0x25b5: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_25bc:
	/* 0x25bc: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_25c4:
	/* 0x25c4: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_25cb:
	/* 0x25cb: ja     2732 <trace_security_bpf+0x2732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2732;
	}
x86_l_25d1:
	/* 0x25d1: mov    BYTE PTR [r14+rbx*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519554ULL);
x86_l_25da:
	/* 0x25da: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_25e0:
	/* 0x25e0: ja     261a <trace_security_bpf+0x261a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_261a;
	}
x86_l_25e2:
	/* 0x25e2: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_25e6:
	/* 0x25e6: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_25ed:
	/* 0x25ed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25f2:
	/* 0x25f2: lea    rdx,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_25fa:
	/* 0x25fa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_25ff:
	/* 0x25ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2601:
	/* 0x2601: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2604:
	/* 0x2604: js     261a <trace_security_bpf+0x261a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_261a;
	}
x86_l_2606:
	/* 0x2606: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2609:
	/* 0x2609: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2611:
	/* 0x2611: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2618:
	/* 0x2618: jmp    2622 <trace_security_bpf+0x2622> */
	goto x86_l_2622;
x86_l_261a:
	/* 0x261a: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2622:
	/* 0x2622: movzx  eax,bx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2625:
	/* 0x2625: cmp    eax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31999ULL);
x86_l_262a:
	/* 0x262a: ja     2732 <trace_security_bpf+0x2732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2732;
	}
x86_l_2630:
	/* 0x2630: mov    BYTE PTR [r14+rax*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519555ULL);
x86_l_2639:
	/* 0x2639: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2641:
	/* 0x2641: cmp    rcx,0x7cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 31997ULL);
x86_l_2648:
	/* 0x2648: ja     26a6 <trace_security_bpf+0x26a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_26a6;
	}
x86_l_264a:
	/* 0x264a: mov    WORD PTR [rcx+r14*1+0x8a],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R14, 0), 592705486852ULL);
x86_l_2655:
	/* 0x2655: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_265d:
	/* 0x265d: cmp    ecx,0x6cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27901ULL);
x86_l_2663:
	/* 0x2663: ja     26a6 <trace_security_bpf+0x26a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_26a6;
	}
x86_l_2665:
	/* 0x2665: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_266a:
	/* 0x266a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2672:
	/* 0x2672: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2676:
	/* 0x2676: add    rdi,0x8c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 140ULL);
x86_l_267d:
	/* 0x267d: mov    esi,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32ULL);
x86_l_2682:
	/* 0x2682: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2685:
	/* 0x2685: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2687:
	/* 0x2687: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_268f:
	/* 0x268f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2692:
	/* 0x2692: jne    26a6 <trace_security_bpf+0x26a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_26a6;
	}
x86_l_2694:
	/* 0x2694: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_269b:
	/* 0x269b: add    ecx,0x23 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 35ULL);
x86_l_269e:
	/* 0x269e: mov    WORD PTR [r14+0x7d8a],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_26a6:
	/* 0x26a6: movzx  eax,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_26a9:
	/* 0x26a9: cmp    eax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31999ULL);
x86_l_26ae:
	/* 0x26ae: ja     2732 <trace_security_bpf+0x2732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2732;
	}
x86_l_26b4:
	/* 0x26b4: mov    BYTE PTR [r14+rax*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519556ULL);
x86_l_26bd:
	/* 0x26bd: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_26c5:
	/* 0x26c5: mov    WORD PTR [r14+0x7d94],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32148ULL);
x86_l_26cd:
	/* 0x26cd: cmp    eax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27899ULL);
x86_l_26d2:
	/* 0x26d2: ja     2732 <trace_security_bpf+0x2732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2732;
	}
x86_l_26d4:
	/* 0x26d4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_26d9:
	/* 0x26d9: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_26e1:
	/* 0x26e1: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_26e5:
	/* 0x26e5: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_26ec:
	/* 0x26ec: lea    rdx,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_26f4:
	/* 0x26f4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_26f9:
	/* 0x26f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26fb:
	/* 0x26fb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26fd:
	/* 0x26fd: jle    2732 <trace_security_bpf+0x2732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2732;
	}
x86_l_26ff:
	/* 0x26ff: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2707:
	/* 0x2707: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_270e:
	/* 0x270e: ja     2732 <trace_security_bpf+0x2732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2732;
	}
x86_l_2710:
	/* 0x2710: mov    DWORD PTR [rcx+r14*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_2718:
	/* 0x2718: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2720:
	/* 0x2720: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2723:
	/* 0x2723: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_272b:
	/* 0x272b: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_2732:
	/* 0x2732: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_273a:
	/* 0x273a: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_2741:
	/* 0x2741: ja     278a <trace_security_bpf+0x278a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_278a;
	}
x86_l_2743:
	/* 0x2743: mov    BYTE PTR [r14+rbx*1+0x89],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519557ULL);
x86_l_274c:
	/* 0x274c: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_2752:
	/* 0x2752: ja     278a <trace_security_bpf+0x278a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_278a;
	}
x86_l_2754:
	/* 0x2754: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2758:
	/* 0x2758: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_275f:
	/* 0x275f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2764:
	/* 0x2764: lea    rdx,[rsp+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_276c:
	/* 0x276c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2771:
	/* 0x2771: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2773:
	/* 0x2773: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2776:
	/* 0x2776: js     278a <trace_security_bpf+0x278a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_278a;
	}
x86_l_2778:
	/* 0x2778: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_277b:
	/* 0x277b: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2783:
	/* 0x2783: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_278a:
	/* 0x278a: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2792:
	/* 0x2792: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_279a:
	/* 0x279a: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_27a1:
	/* 0x27a1: ja     27ea <trace_security_bpf+0x27ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10218ULL;
	}
x86_l_27a3:
	/* 0x27a3: mov    BYTE PTR [r14+rbx*1+0x89],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519558ULL);
x86_l_27ac:
	/* 0x27ac: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_27b2:
	/* 0x27b2: ja     27ea <trace_security_bpf+0x27ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10218ULL;
	}
x86_l_27b4:
	/* 0x27b4: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_27b8:
	/* 0x27b8: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_27bf:
	/* 0x27bf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27c4:
	/* 0x27c4: lea    rdx,[rsp+0x138] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_27cc:
	/* 0x27cc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_27d1:
	/* 0x27d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27d3:
	/* 0x27d3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27d6:
	/* 0x27d6: js     27ea <trace_security_bpf+0x27ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10218ULL;
	}
x86_l_27d8:
	/* 0x27d8: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_27db:
	/* 0x27db: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
	return 10211ULL;
}

static __noinline __u64 tracee_trace_security_bpf_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10211ULL: goto x86_l_27e3;
	case 10218ULL: goto x86_l_27ea;
	case 10225ULL: goto x86_l_27f1;
	case 10229ULL: goto x86_l_27f5;
	case 10234ULL: goto x86_l_27fa;
	case 10237ULL: goto x86_l_27fd;
	case 10242ULL: goto x86_l_2802;
	case 10245ULL: goto x86_l_2805;
	case 10247ULL: goto x86_l_2807;
	case 10251ULL: goto x86_l_280b;
	case 10259ULL: goto x86_l_2813;
	case 10263ULL: goto x86_l_2817;
	case 10268ULL: goto x86_l_281c;
	case 10271ULL: goto x86_l_281f;
	case 10276ULL: goto x86_l_2824;
	case 10278ULL: goto x86_l_2826;
	case 10282ULL: goto x86_l_282a;
	case 10286ULL: goto x86_l_282e;
	case 10291ULL: goto x86_l_2833;
	case 10294ULL: goto x86_l_2836;
	case 10299ULL: goto x86_l_283b;
	case 10301ULL: goto x86_l_283d;
	case 10305ULL: goto x86_l_2841;
	case 10309ULL: goto x86_l_2845;
	case 10314ULL: goto x86_l_284a;
	case 10317ULL: goto x86_l_284d;
	case 10322ULL: goto x86_l_2852;
	case 10324ULL: goto x86_l_2854;
	case 10327ULL: goto x86_l_2857;
	case 10331ULL: goto x86_l_285b;
	case 10335ULL: goto x86_l_285f;
	case 10340ULL: goto x86_l_2864;
	case 10343ULL: goto x86_l_2867;
	case 10348ULL: goto x86_l_286c;
	case 10351ULL: goto x86_l_286f;
	case 10353ULL: goto x86_l_2871;
	case 10357ULL: goto x86_l_2875;
	case 10362ULL: goto x86_l_287a;
	case 10365ULL: goto x86_l_287d;
	case 10370ULL: goto x86_l_2882;
	case 10373ULL: goto x86_l_2885;
	case 10375ULL: goto x86_l_2887;
	case 10378ULL: goto x86_l_288a;
	case 10382ULL: goto x86_l_288e;
	case 10386ULL: goto x86_l_2892;
	case 10390ULL: goto x86_l_2896;
	case 10395ULL: goto x86_l_289b;
	case 10398ULL: goto x86_l_289e;
	case 10403ULL: goto x86_l_28a3;
	case 10405ULL: goto x86_l_28a5;
	case 10408ULL: goto x86_l_28a8;
	case 10412ULL: goto x86_l_28ac;
	case 10417ULL: goto x86_l_28b1;
	case 10420ULL: goto x86_l_28b4;
	case 10425ULL: goto x86_l_28b9;
	case 10428ULL: goto x86_l_28bc;
	case 10430ULL: goto x86_l_28be;
	case 10434ULL: goto x86_l_28c2;
	case 10438ULL: goto x86_l_28c6;
	case 10443ULL: goto x86_l_28cb;
	case 10446ULL: goto x86_l_28ce;
	case 10451ULL: goto x86_l_28d3;
	case 10453ULL: goto x86_l_28d5;
	case 10457ULL: goto x86_l_28d9;
	case 10462ULL: goto x86_l_28de;
	case 10465ULL: goto x86_l_28e1;
	case 10470ULL: goto x86_l_28e6;
	case 10473ULL: goto x86_l_28e9;
	case 10475ULL: goto x86_l_28eb;
	case 10478ULL: goto x86_l_28ee;
	case 10482ULL: goto x86_l_28f2;
	case 10486ULL: goto x86_l_28f6;
	case 10490ULL: goto x86_l_28fa;
	case 10495ULL: goto x86_l_28ff;
	case 10498ULL: goto x86_l_2902;
	case 10503ULL: goto x86_l_2907;
	case 10505ULL: goto x86_l_2909;
	case 10508ULL: goto x86_l_290c;
	case 10512ULL: goto x86_l_2910;
	case 10517ULL: goto x86_l_2915;
	case 10520ULL: goto x86_l_2918;
	case 10525ULL: goto x86_l_291d;
	case 10528ULL: goto x86_l_2920;
	case 10530ULL: goto x86_l_2922;
	case 10534ULL: goto x86_l_2926;
	case 10539ULL: goto x86_l_292b;
	case 10542ULL: goto x86_l_292e;
	case 10547ULL: goto x86_l_2933;
	case 10550ULL: goto x86_l_2936;
	case 10552ULL: goto x86_l_2938;
	case 10555ULL: goto x86_l_293b;
	case 10559ULL: goto x86_l_293f;
	case 10563ULL: goto x86_l_2943;
	case 10567ULL: goto x86_l_2947;
	case 10572ULL: goto x86_l_294c;
	case 10575ULL: goto x86_l_294f;
	case 10580ULL: goto x86_l_2954;
	case 10582ULL: goto x86_l_2956;
	case 10586ULL: goto x86_l_295a;
	case 10590ULL: goto x86_l_295e;
	case 10595ULL: goto x86_l_2963;
	case 10598ULL: goto x86_l_2966;
	case 10603ULL: goto x86_l_296b;
	case 10605ULL: goto x86_l_296d;
	case 10609ULL: goto x86_l_2971;
	case 10613ULL: goto x86_l_2975;
	case 10618ULL: goto x86_l_297a;
	case 10621ULL: goto x86_l_297d;
	case 10626ULL: goto x86_l_2982;
	case 10629ULL: goto x86_l_2985;
	case 10631ULL: goto x86_l_2987;
	case 10635ULL: goto x86_l_298b;
	case 10640ULL: goto x86_l_2990;
	case 10643ULL: goto x86_l_2993;
	case 10648ULL: goto x86_l_2998;
	case 10651ULL: goto x86_l_299b;
	case 10653ULL: goto x86_l_299d;
	case 10656ULL: goto x86_l_29a0;
	case 10660ULL: goto x86_l_29a4;
	case 10664ULL: goto x86_l_29a8;
	case 10668ULL: goto x86_l_29ac;
	case 10673ULL: goto x86_l_29b1;
	case 10676ULL: goto x86_l_29b4;
	case 10681ULL: goto x86_l_29b9;
	case 10683ULL: goto x86_l_29bb;
	case 10687ULL: goto x86_l_29bf;
	case 10691ULL: goto x86_l_29c3;
	case 10696ULL: goto x86_l_29c8;
	case 10699ULL: goto x86_l_29cb;
	case 10704ULL: goto x86_l_29d0;
	case 10706ULL: goto x86_l_29d2;
	case 10710ULL: goto x86_l_29d6;
	case 10712ULL: goto x86_l_29d8;
	case 10717ULL: goto x86_l_29dd;
	case 10720ULL: goto x86_l_29e0;
	case 10725ULL: goto x86_l_29e5;
	case 10728ULL: goto x86_l_29e8;
	case 10730ULL: goto x86_l_29ea;
	case 10734ULL: goto x86_l_29ee;
	case 10739ULL: goto x86_l_29f3;
	case 10742ULL: goto x86_l_29f6;
	case 10747ULL: goto x86_l_29fb;
	case 10750ULL: goto x86_l_29fe;
	case 10752ULL: goto x86_l_2a00;
	case 10755ULL: goto x86_l_2a03;
	case 10759ULL: goto x86_l_2a07;
	case 10763ULL: goto x86_l_2a0b;
	case 10767ULL: goto x86_l_2a0f;
	case 10772ULL: goto x86_l_2a14;
	case 10775ULL: goto x86_l_2a17;
	case 10780ULL: goto x86_l_2a1c;
	case 10782ULL: goto x86_l_2a1e;
	case 10785ULL: goto x86_l_2a21;
	case 10789ULL: goto x86_l_2a25;
	case 10793ULL: goto x86_l_2a29;
	case 10800ULL: goto x86_l_2a30;
	case 10805ULL: goto x86_l_2a35;
	case 10808ULL: goto x86_l_2a38;
	case 10813ULL: goto x86_l_2a3d;
	case 10816ULL: goto x86_l_2a40;
	case 10818ULL: goto x86_l_2a42;
	case 10822ULL: goto x86_l_2a46;
	case 10826ULL: goto x86_l_2a4a;
	case 10831ULL: goto x86_l_2a4f;
	case 10834ULL: goto x86_l_2a52;
	case 10839ULL: goto x86_l_2a57;
	case 10841ULL: goto x86_l_2a59;
	case 10846ULL: goto x86_l_2a5e;
	case 10850ULL: goto x86_l_2a62;
	case 10858ULL: goto x86_l_2a6a;
	case 10863ULL: goto x86_l_2a6f;
	case 10865ULL: goto x86_l_2a71;
	case 10872ULL: goto x86_l_2a78;
	case 10876ULL: goto x86_l_2a7c;
	case 10881ULL: goto x86_l_2a81;
	case 10883ULL: goto x86_l_2a83;
	case 10887ULL: goto x86_l_2a87;
	case 10891ULL: goto x86_l_2a8b;
	case 10896ULL: goto x86_l_2a90;
	case 10899ULL: goto x86_l_2a93;
	case 10904ULL: goto x86_l_2a98;
	case 10906ULL: goto x86_l_2a9a;
	case 10910ULL: goto x86_l_2a9e;
	case 10914ULL: goto x86_l_2aa2;
	case 10922ULL: goto x86_l_2aaa;
	case 10926ULL: goto x86_l_2aae;
	case 10931ULL: goto x86_l_2ab3;
	case 10934ULL: goto x86_l_2ab6;
	case 10939ULL: goto x86_l_2abb;
	case 10941ULL: goto x86_l_2abd;
	case 10945ULL: goto x86_l_2ac1;
	case 10949ULL: goto x86_l_2ac5;
	case 10953ULL: goto x86_l_2ac9;
	case 10958ULL: goto x86_l_2ace;
	case 10961ULL: goto x86_l_2ad1;
	case 10966ULL: goto x86_l_2ad6;
	case 10969ULL: goto x86_l_2ad9;
	case 10971ULL: goto x86_l_2adb;
	case 10975ULL: goto x86_l_2adf;
	case 10979ULL: goto x86_l_2ae3;
	case 10984ULL: goto x86_l_2ae8;
	case 10987ULL: goto x86_l_2aeb;
	case 10992ULL: goto x86_l_2af0;
	case 10995ULL: goto x86_l_2af3;
	case 10997ULL: goto x86_l_2af5;
	case 11001ULL: goto x86_l_2af9;
	case 11003ULL: goto x86_l_2afb;
	case 11008ULL: goto x86_l_2b00;
	case 11012ULL: goto x86_l_2b04;
	case 11020ULL: goto x86_l_2b0c;
	case 11028ULL: goto x86_l_2b14;
	case 11033ULL: goto x86_l_2b19;
	case 11038ULL: goto x86_l_2b1e;
	case 11040ULL: goto x86_l_2b20;
	case 11045ULL: goto x86_l_2b25;
	case 11048ULL: goto x86_l_2b28;
	case 11053ULL: goto x86_l_2b2d;
	case 11056ULL: goto x86_l_2b30;
	case 11058ULL: goto x86_l_2b32;
	case 11062ULL: goto x86_l_2b36;
	case 11067ULL: goto x86_l_2b3b;
	case 11070ULL: goto x86_l_2b3e;
	case 11075ULL: goto x86_l_2b43;
	case 11077ULL: goto x86_l_2b45;
	case 11081ULL: goto x86_l_2b49;
	case 11086ULL: goto x86_l_2b4e;
	case 11089ULL: goto x86_l_2b51;
	case 11092ULL: goto x86_l_2b54;
	case 11097ULL: goto x86_l_2b59;
	case 11099ULL: goto x86_l_2b5b;
	case 11103ULL: goto x86_l_2b5f;
	case 11108ULL: goto x86_l_2b64;
	case 11113ULL: goto x86_l_2b69;
	case 11116ULL: goto x86_l_2b6c;
	case 11118ULL: goto x86_l_2b6e;
	case 11123ULL: goto x86_l_2b73;
	case 11131ULL: goto x86_l_2b7b;
	case 11136ULL: goto x86_l_2b80;
	case 11141ULL: goto x86_l_2b85;
	case 11143ULL: goto x86_l_2b87;
	case 11151ULL: goto x86_l_2b8f;
	case 11157ULL: goto x86_l_2b95;
	case 11165ULL: goto x86_l_2b9d;
	case 11167ULL: goto x86_l_2b9f;
	case 11172ULL: goto x86_l_2ba4;
	case 11179ULL: goto x86_l_2bab;
	case 11184ULL: goto x86_l_2bb0;
	case 11187ULL: goto x86_l_2bb3;
	case 11189ULL: goto x86_l_2bb5;
	case 11191ULL: goto x86_l_2bb7;
	case 11193ULL: goto x86_l_2bb9;
	case 11197ULL: goto x86_l_2bbd;
	case 11205ULL: goto x86_l_2bc5;
	case 11210ULL: goto x86_l_2bca;
	case 11215ULL: goto x86_l_2bcf;
	case 11218ULL: goto x86_l_2bd2;
	case 11224ULL: goto x86_l_2bd8;
	case 11228ULL: goto x86_l_2bdc;
	case 11233ULL: goto x86_l_2be1;
	case 11240ULL: goto x86_l_2be8;
	case 11245ULL: goto x86_l_2bed;
	case 11248ULL: goto x86_l_2bf0;
	case 11251ULL: goto x86_l_2bf3;
	case 11253ULL: goto x86_l_2bf5;
	case 11261ULL: goto x86_l_2bfd;
	case 11269ULL: goto x86_l_2c05;
	case 11271ULL: goto x86_l_2c07;
	case 11276ULL: goto x86_l_2c0c;
	case 11283ULL: goto x86_l_2c13;
	case 11291ULL: goto x86_l_2c1b;
	case 11293ULL: goto x86_l_2c1d;
	case 11301ULL: goto x86_l_2c25;
	case 11308ULL: goto x86_l_2c2c;
	case 11311ULL: goto x86_l_2c2f;
	case 11317ULL: goto x86_l_2c35;
	case 11323ULL: goto x86_l_2c3b;
	case 11329ULL: goto x86_l_2c41;
	case 11338ULL: goto x86_l_2c4a;
	case 11347ULL: goto x86_l_2c53;
	case 11356ULL: goto x86_l_2c5c;
	case 11365ULL: goto x86_l_2c65;
	case 11374ULL: goto x86_l_2c6e;
	case 11383ULL: goto x86_l_2c77;
	case 11392ULL: goto x86_l_2c80;
	case 11400ULL: goto x86_l_2c88;
	case 11403ULL: goto x86_l_2c8b;
	case 11410ULL: goto x86_l_2c92;
	case 11415ULL: goto x86_l_2c97;
	case 11423ULL: goto x86_l_2c9f;
	case 11428ULL: goto x86_l_2ca4;
	case 11433ULL: goto x86_l_2ca9;
	case 11436ULL: goto x86_l_2cac;
	case 11438ULL: goto x86_l_2cae;
	case 11445ULL: goto x86_l_2cb5;
	case 11450ULL: goto x86_l_2cba;
	case 11455ULL: goto x86_l_2cbf;
	case 11463ULL: goto x86_l_2cc7;
	case 11468ULL: goto x86_l_2ccc;
	case 11470ULL: goto x86_l_2cce;
	case 11473ULL: goto x86_l_2cd1;
	case 11480ULL: goto x86_l_2cd8;
	case 11484ULL: goto x86_l_2cdc;
	case 11496ULL: goto x86_l_2ce8;
	case 11504ULL: goto x86_l_2cf0;
	case 11516ULL: goto x86_l_2cfc;
	case 11520ULL: goto x86_l_2d00;
	case 11525ULL: goto x86_l_2d05;
	case 11533ULL: goto x86_l_2d0d;
	case 11538ULL: goto x86_l_2d12;
	case 11541ULL: goto x86_l_2d15;
	case 11543ULL: goto x86_l_2d17;
	case 11546ULL: goto x86_l_2d1a;
	case 11548ULL: goto x86_l_2d1c;
	case 11553ULL: goto x86_l_2d21;
	case 11558ULL: goto x86_l_2d26;
	case 11566ULL: goto x86_l_2d2e;
	case 11568ULL: goto x86_l_2d30;
	case 11570ULL: goto x86_l_2d32;
	case 11575ULL: goto x86_l_2d37;
	case 11577ULL: goto x86_l_2d39;
	case 11581ULL: goto x86_l_2d3d;
	case 11586ULL: goto x86_l_2d42;
	case 11591ULL: goto x86_l_2d47;
	case 11596ULL: goto x86_l_2d4c;
	case 11601ULL: goto x86_l_2d51;
	case 11603ULL: goto x86_l_2d53;
	case 11608ULL: goto x86_l_2d58;
	case 11613ULL: goto x86_l_2d5d;
	case 11621ULL: goto x86_l_2d65;
	case 11626ULL: goto x86_l_2d6a;
	case 11628ULL: goto x86_l_2d6c;
	case 11633ULL: goto x86_l_2d71;
	case 11638ULL: goto x86_l_2d76;
	case 11646ULL: goto x86_l_2d7e;
	case 11651ULL: goto x86_l_2d83;
	case 11653ULL: goto x86_l_2d85;
	case 11658ULL: goto x86_l_2d8a;
	case 11667ULL: goto x86_l_2d93;
	case 11674ULL: goto x86_l_2d9a;
	case 11678ULL: goto x86_l_2d9e;
	case 11686ULL: goto x86_l_2da6;
	case 11691ULL: goto x86_l_2dab;
	case 11693ULL: goto x86_l_2dad;
	case 11698ULL: goto x86_l_2db2;
	case 11706ULL: goto x86_l_2dba;
	case 11710ULL: goto x86_l_2dbe;
	case 11717ULL: goto x86_l_2dc5;
	case 11720ULL: goto x86_l_2dc8;
	case 11725ULL: goto x86_l_2dcd;
	case 11727ULL: goto x86_l_2dcf;
	case 11732ULL: goto x86_l_2dd4;
	case 11739ULL: goto x86_l_2ddb;
	case 11742ULL: goto x86_l_2dde;
	case 11747ULL: goto x86_l_2de3;
	case 11749ULL: goto x86_l_2de5;
	case 11751ULL: goto x86_l_2de7;
	case 11758ULL: goto x86_l_2dee;
	case 11760ULL: goto x86_l_2df0;
	case 11761ULL: goto x86_l_2df1;
	case 11766ULL: goto x86_l_2df6;
	case 11770ULL: goto x86_l_2dfa;
	case 11775ULL: goto x86_l_2dff;
	case 11778ULL: goto x86_l_2e02;
	case 11783ULL: goto x86_l_2e07;
	case 11785ULL: goto x86_l_2e09;
	case 11790ULL: goto x86_l_2e0e;
	case 11796ULL: goto x86_l_2e14;
	case 11800ULL: goto x86_l_2e18;
	case 11804ULL: goto x86_l_2e1c;
	case 11809ULL: goto x86_l_2e21;
	case 11812ULL: goto x86_l_2e24;
	case 11817ULL: goto x86_l_2e29;
	case 11820ULL: goto x86_l_2e2c;
	case 11822ULL: goto x86_l_2e2e;
	case 11828ULL: goto x86_l_2e34;
	case 11833ULL: goto x86_l_2e39;
	case 11836ULL: goto x86_l_2e3c;
	case 11841ULL: goto x86_l_2e41;
	case 11844ULL: goto x86_l_2e44;
	case 11846ULL: goto x86_l_2e46;
	case 11850ULL: goto x86_l_2e4a;
	case 11858ULL: goto x86_l_2e52;
	case 11863ULL: goto x86_l_2e57;
	case 11866ULL: goto x86_l_2e5a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_27e3:
	/* 0x27e3: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_27ea:
	/* 0x27ea: mov    rbp,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_27f1:
	/* 0x27f1: lea    r15,[rbp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27f5:
	/* 0x27f5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27fa:
	/* 0x27fa: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_27fd:
	/* 0x27fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2802:
	/* 0x2802: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2805:
	/* 0x2805: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2807:
	/* 0x2807: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_280b:
	/* 0x280b: mov    QWORD PTR [rsp+0xf0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2813:
	/* 0x2813: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2817:
	/* 0x2817: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_281c:
	/* 0x281c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_281f:
	/* 0x281f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2824:
	/* 0x2824: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2826:
	/* 0x2826: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_282a:
	/* 0x282a: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_282e:
	/* 0x282e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2833:
	/* 0x2833: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2836:
	/* 0x2836: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_283b:
	/* 0x283b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_283d:
	/* 0x283d: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2841:
	/* 0x2841: lea    rdx,[r13+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2845:
	/* 0x2845: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_284a:
	/* 0x284a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_284d:
	/* 0x284d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2852:
	/* 0x2852: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2854:
	/* 0x2854: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2857:
	/* 0x2857: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_285b:
	/* 0x285b: lea    r12,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_285f:
	/* 0x285f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2864:
	/* 0x2864: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2867:
	/* 0x2867: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_286c:
	/* 0x286c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_286f:
	/* 0x286f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2871:
	/* 0x2871: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2875:
	/* 0x2875: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_287a:
	/* 0x287a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_287d:
	/* 0x287d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2882:
	/* 0x2882: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2885:
	/* 0x2885: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2887:
	/* 0x2887: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_288a:
	/* 0x288a: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_288e:
	/* 0x288e: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2892:
	/* 0x2892: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2896:
	/* 0x2896: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_289b:
	/* 0x289b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_289e:
	/* 0x289e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_28a3:
	/* 0x28a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28a5:
	/* 0x28a5: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28a8:
	/* 0x28a8: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_28ac:
	/* 0x28ac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28b1:
	/* 0x28b1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_28b4:
	/* 0x28b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28b9:
	/* 0x28b9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_28bc:
	/* 0x28bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28be:
	/* 0x28be: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28c2:
	/* 0x28c2: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_28c6:
	/* 0x28c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28cb:
	/* 0x28cb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_28ce:
	/* 0x28ce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28d3:
	/* 0x28d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28d5:
	/* 0x28d5: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28d9:
	/* 0x28d9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28de:
	/* 0x28de: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_28e1:
	/* 0x28e1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_28e6:
	/* 0x28e6: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_28e9:
	/* 0x28e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28eb:
	/* 0x28eb: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28ee:
	/* 0x28ee: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_28f2:
	/* 0x28f2: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_28f6:
	/* 0x28f6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_28fa:
	/* 0x28fa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28ff:
	/* 0x28ff: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2902:
	/* 0x2902: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2907:
	/* 0x2907: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2909:
	/* 0x2909: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_290c:
	/* 0x290c: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2910:
	/* 0x2910: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2915:
	/* 0x2915: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2918:
	/* 0x2918: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_291d:
	/* 0x291d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2920:
	/* 0x2920: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2922:
	/* 0x2922: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2926:
	/* 0x2926: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_292b:
	/* 0x292b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_292e:
	/* 0x292e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2933:
	/* 0x2933: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2936:
	/* 0x2936: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2938:
	/* 0x2938: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_293b:
	/* 0x293b: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_293f:
	/* 0x293f: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2943:
	/* 0x2943: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2947:
	/* 0x2947: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_294c:
	/* 0x294c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_294f:
	/* 0x294f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2954:
	/* 0x2954: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2956:
	/* 0x2956: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_295a:
	/* 0x295a: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_295e:
	/* 0x295e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2963:
	/* 0x2963: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2966:
	/* 0x2966: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_296b:
	/* 0x296b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_296d:
	/* 0x296d: mov    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2971:
	/* 0x2971: lea    r15,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2975:
	/* 0x2975: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_297a:
	/* 0x297a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_297d:
	/* 0x297d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2982:
	/* 0x2982: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2985:
	/* 0x2985: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2987:
	/* 0x2987: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_298b:
	/* 0x298b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2990:
	/* 0x2990: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2993:
	/* 0x2993: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2998:
	/* 0x2998: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_299b:
	/* 0x299b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_299d:
	/* 0x299d: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29a0:
	/* 0x29a0: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_29a4:
	/* 0x29a4: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_29a8:
	/* 0x29a8: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_29ac:
	/* 0x29ac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29b1:
	/* 0x29b1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29b4:
	/* 0x29b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29b9:
	/* 0x29b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29bb:
	/* 0x29bb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29bf:
	/* 0x29bf: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_29c3:
	/* 0x29c3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29c8:
	/* 0x29c8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29cb:
	/* 0x29cb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_29d0:
	/* 0x29d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29d2:
	/* 0x29d2: cmp    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_29d6:
	/* 0x29d6: jne    2a25 <trace_security_bpf+0x2a25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a25;
	}
x86_l_29d8:
	/* 0x29d8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29dd:
	/* 0x29dd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29e0:
	/* 0x29e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29e5:
	/* 0x29e5: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_29e8:
	/* 0x29e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29ea:
	/* 0x29ea: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29ee:
	/* 0x29ee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29f3:
	/* 0x29f3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_29f6:
	/* 0x29f6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_29fb:
	/* 0x29fb: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_29fe:
	/* 0x29fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a00:
	/* 0x2a00: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a03:
	/* 0x2a03: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2a07:
	/* 0x2a07: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2a0b:
	/* 0x2a0b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2a0f:
	/* 0x2a0f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a14:
	/* 0x2a14: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a17:
	/* 0x2a17: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a1c:
	/* 0x2a1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a1e:
	/* 0x2a1e: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a21:
	/* 0x2a21: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a25:
	/* 0x2a25: mov    DWORD PTR [r14+0x38],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2a29:
	/* 0x2a29: lea    r12,[rbp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2a30:
	/* 0x2a30: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a35:
	/* 0x2a35: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a38:
	/* 0x2a38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a3d:
	/* 0x2a3d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2a40:
	/* 0x2a40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a42:
	/* 0x2a42: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a46:
	/* 0x2a46: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2a4a:
	/* 0x2a4a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a4f:
	/* 0x2a4f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a52:
	/* 0x2a52: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a57:
	/* 0x2a57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a59:
	/* 0x2a59: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a5e:
	/* 0x2a5e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a62:
	/* 0x2a62: lea    rdi,[rsp+0x13c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 316ULL);
x86_l_2a6a:
	/* 0x2a6a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a6f:
	/* 0x2a6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a71:
	/* 0x2a71: mov    eax,DWORD PTR [rsp+0x13c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 316ULL);
x86_l_2a78:
	/* 0x2a78: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2a7c:
	/* 0x2a7c: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_2a81:
	/* 0x2a81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a83:
	/* 0x2a83: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a87:
	/* 0x2a87: lea    rdx,[rbp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2a8b:
	/* 0x2a8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a90:
	/* 0x2a90: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2a93:
	/* 0x2a93: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a98:
	/* 0x2a98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a9a:
	/* 0x2a9a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a9e:
	/* 0x2a9e: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2aa2:
	/* 0x2aa2: mov    rdx,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2aaa:
	/* 0x2aaa: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_2aae:
	/* 0x2aae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ab3:
	/* 0x2ab3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ab6:
	/* 0x2ab6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2abb:
	/* 0x2abb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2abd:
	/* 0x2abd: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ac1:
	/* 0x2ac1: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2ac5:
	/* 0x2ac5: add    r13,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_2ac9:
	/* 0x2ac9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ace:
	/* 0x2ace: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ad1:
	/* 0x2ad1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ad6:
	/* 0x2ad6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2ad9:
	/* 0x2ad9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2adb:
	/* 0x2adb: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2adf:
	/* 0x2adf: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2ae3:
	/* 0x2ae3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ae8:
	/* 0x2ae8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2aeb:
	/* 0x2aeb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2af0:
	/* 0x2af0: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2af3:
	/* 0x2af3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2af5:
	/* 0x2af5: test   BYTE PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2af9:
	/* 0x2af9: je     2b00 <trace_security_bpf+0x2b00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b00;
	}
x86_l_2afb:
	/* 0x2afb: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_2b00:
	/* 0x2b00: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2b04:
	/* 0x2b04: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_2b0c:
	/* 0x2b0c: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_2b14:
	/* 0x2b14: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_2b19:
	/* 0x2b19: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2b1e:
	/* 0x2b1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b20:
	/* 0x2b20: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b25:
	/* 0x2b25: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b28:
	/* 0x2b28: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b2d:
	/* 0x2b2d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2b30:
	/* 0x2b30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b32:
	/* 0x2b32: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b36:
	/* 0x2b36: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b3b:
	/* 0x2b3b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2b3e:
	/* 0x2b3e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b43:
	/* 0x2b43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b45:
	/* 0x2b45: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b49:
	/* 0x2b49: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b4e:
	/* 0x2b4e: mov    rbx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSP, X86_WIDTH_64);
x86_l_2b51:
	/* 0x2b51: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2b54:
	/* 0x2b54: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_2b59:
	/* 0x2b59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b5b:
	/* 0x2b5b: lea    rdi,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2b5f:
	/* 0x2b5f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2b64:
	/* 0x2b64: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2b69:
	/* 0x2b69: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2b6c:
	/* 0x2b6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b6e:
	/* 0x2b6e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b73:
	/* 0x2b73: mov    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2b7b:
	/* 0x2b7b: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_2b80:
	/* 0x2b80: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2b85:
	/* 0x2b85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b87:
	/* 0x2b87: mov    r12,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2b8f:
	/* 0x2b8f: test   BYTE PTR [r12+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_2b95:
	/* 0x2b95: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2b9d:
	/* 0x2b9d: je     2bbd <trace_security_bpf+0x2bbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bbd;
	}
x86_l_2b9f:
	/* 0x2b9f: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_2ba4:
	/* 0x2ba4: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_2bab:
	/* 0x2bab: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_2bb0:
	/* 0x2bb0: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2bb3:
	/* 0x2bb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bb5:
	/* 0x2bb5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bb7:
	/* 0x2bb7: js     2bbd <trace_security_bpf+0x2bbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2bbd;
	}
x86_l_2bb9:
	/* 0x2bb9: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2bbd:
	/* 0x2bbd: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2bc5:
	/* 0x2bc5: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_2bca:
	/* 0x2bca: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_2bcf:
	/* 0x2bcf: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_2bd2:
	/* 0x2bd2: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_2bd8:
	/* 0x2bd8: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2bdc:
	/* 0x2bdc: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2be1:
	/* 0x2be1: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_2be8:
	/* 0x2be8: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_2bed:
	/* 0x2bed: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2bf0:
	/* 0x2bf0: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_2bf3:
	/* 0x2bf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf5:
	/* 0x2bf5: lea    rax,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2bfd:
	/* 0x2bfd: cmp    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2c05:
	/* 0x2c05: je     2c1d <trace_security_bpf+0x2c1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c1d;
	}
x86_l_2c07:
	/* 0x2c07: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2c0c:
	/* 0x2c0c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_HELPER_ID(X86_RDI, X86_SIM_HELPER_bpf_attach_map);
x86_l_2c13:
	/* 0x2c13: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_2c1b:
	/* 0x2c1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c1d:
	/* 0x2c1d: mov    rbp,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2c25:
	/* 0x2c25: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2c2c:
	/* 0x2c2c: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2c2f:
	/* 0x2c2f: jne    2de5 <trace_security_bpf+0x2de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2de5;
	}
x86_l_2c35:
	/* 0x2c35: test   BYTE PTR [r12+0x4],0x80 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869312ULL);
x86_l_2c3b:
	/* 0x2c3b: je     2de5 <trace_security_bpf+0x2de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2de5;
	}
x86_l_2c41:
	/* 0x2c41: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2c4a:
	/* 0x2c4a: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2c53:
	/* 0x2c53: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2c5c:
	/* 0x2c5c: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2c65:
	/* 0x2c65: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2c6e:
	/* 0x2c6e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2c77:
	/* 0x2c77: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2c80:
	/* 0x2c80: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c88:
	/* 0x2c88: mov    eax,DWORD PTR [rbp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2c8b:
	/* 0x2c8b: mov    DWORD PTR [rsp+0xf8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2c92:
	/* 0x2c92: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c97:
	/* 0x2c97: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2c9f:
	/* 0x2c9f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2ca4:
	/* 0x2ca4: mov    r12,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2ca9:
	/* 0x2ca9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2cac:
	/* 0x2cac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cae:
	/* 0x2cae: mov    ebx,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2cb5:
	/* 0x2cb5: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cba:
	/* 0x2cba: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cbf:
	/* 0x2cbf: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2cc7:
	/* 0x2cc7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ccc:
	/* 0x2ccc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cce:
	/* 0x2cce: shl    ebx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_2cd1:
	/* 0x2cd1: mov    DWORD PTR [rsp+0x120],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2cd8:
	/* 0x2cd8: mov    BYTE PTR [rsp],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2cdc:
	/* 0x2cdc: mov    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_2ce8:
	/* 0x2ce8: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2cf0:
	/* 0x2cf0: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_2cfc:
	/* 0x2cfc: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2d00:
	/* 0x2d00: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2d05:
	/* 0x2d05: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2d0d:
	/* 0x2d0d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2d12:
	/* 0x2d12: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2d15:
	/* 0x2d15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d17:
	/* 0x2d17: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d1a:
	/* 0x2d1a: jle    2d32 <trace_security_bpf+0x2d32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2d32;
	}
x86_l_2d1c:
	/* 0x2d1c: lea    rdi,[rsp+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2d21:
	/* 0x2d21: mov    ecx,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 115ULL);
x86_l_2d26:
	/* 0x2d26: lea    rdx,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2d2e:
	/* 0x2d2e: mov    esi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2d30:
	/* 0x2d30: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2d32:
	/* 0x2d32: mov    eax,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2d37:
	/* 0x2d37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d39:
	/* 0x2d39: mov    DWORD PTR [rsp+0x6c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_2d3d:
	/* 0x2d3d: lea    rdi,[rsp+0x11] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_2d42:
	/* 0x2d42: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d47:
	/* 0x2d47: lea    rdx,[rsp+0x6c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_2d4c:
	/* 0x2d4c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d51:
	/* 0x2d51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d53:
	/* 0x2d53: lea    rdi,[rsp+0x15] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_2d58:
	/* 0x2d58: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d5d:
	/* 0x2d5d: lea    rdx,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2d65:
	/* 0x2d65: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d6a:
	/* 0x2d6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d6c:
	/* 0x2d6c: lea    rdi,[rsp+0x19] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_2d71:
	/* 0x2d71: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d76:
	/* 0x2d76: lea    rdx,[rsp+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2d7e:
	/* 0x2d7e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d83:
	/* 0x2d83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d85:
	/* 0x2d85: mov    QWORD PTR [rsp+0x20],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d8a:
	/* 0x2d8a: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2d93:
	/* 0x2d93: mov    eax,DWORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2d9a:
	/* 0x2d9a: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d9e:
	/* 0x2d9e: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2da6:
	/* 0x2da6: cmp    eax,0x7cbf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31935ULL);
x86_l_2dab:
	/* 0x2dab: ja     2de5 <trace_security_bpf+0x2de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2de5;
	}
x86_l_2dad:
	/* 0x2dad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2db2:
	/* 0x2db2: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2dba:
	/* 0x2dba: lea    rdi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2dbe:
	/* 0x2dbe: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2dc5:
	/* 0x2dc5: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2dc8:
	/* 0x2dc8: mov    esi,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 64ULL);
x86_l_2dcd:
	/* 0x2dcd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dcf:
	/* 0x2dcf: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2dd4:
	/* 0x2dd4: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&prog_array)));
x86_l_2ddb:
	/* 0x2ddb: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2dde:
	/* 0x2dde: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2de3:
	/* 0x2de3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2de5:
	/* 0x2de5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2de7:
	/* 0x2de7: add    rsp,0x148 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 328ULL);
x86_l_2dee:
	/* 0x2dee: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2df0:
	/* 0x2df0: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2df1:
	/* 0x2df1: jmp    2eba <trace_security_bpf+0x2eba> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2df6:
	/* 0x2df6: lea    rdx,[rbx-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_2dfa:
	/* 0x2dfa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2dff:
	/* 0x2dff: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2e02:
	/* 0x2e02: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e07:
	/* 0x2e07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e09:
	/* 0x2e09: cmp    QWORD PTR [rsp],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2e0e:
	/* 0x2e0e: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_2e14:
	/* 0x2e14: sbb    r12d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SBB, 0ULL);
x86_l_2e18:
	/* 0x2e18: lea    r15,[rbx-0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_2e1c:
	/* 0x2e1c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e21:
	/* 0x2e21: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2e24:
	/* 0x2e24: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e29:
	/* 0x2e29: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2e2c:
	/* 0x2e2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e2e:
	/* 0x2e2e: mov    r13d,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 115ULL);
x86_l_2e34:
	/* 0x2e34: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e39:
	/* 0x2e39: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2e3c:
	/* 0x2e3c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e41:
	/* 0x2e41: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2e44:
	/* 0x2e44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e46:
	/* 0x2e46: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e4a:
	/* 0x2e4a: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2e52:
	/* 0x2e52: mov    esi,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 64ULL);
x86_l_2e57:
	/* 0x2e57: call   r13 */
	X86_SIM_BPF_CALL_REG(X86_R13);
x86_l_2e5a:
	/* 0x2e5a: cmp    BYTE PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
	return 11874ULL;
}

static __noinline __u64 tracee_trace_security_bpf_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11874ULL: goto x86_l_2e62;
	case 11880ULL: goto x86_l_2e68;
	case 11884ULL: goto x86_l_2e6c;
	case 11889ULL: goto x86_l_2e71;
	case 11892ULL: goto x86_l_2e74;
	case 11897ULL: goto x86_l_2e79;
	case 11900ULL: goto x86_l_2e7c;
	case 11902ULL: goto x86_l_2e7e;
	case 11906ULL: goto x86_l_2e82;
	case 11911ULL: goto x86_l_2e87;
	case 11918ULL: goto x86_l_2e8e;
	case 11921ULL: goto x86_l_2e91;
	case 11925ULL: goto x86_l_2e95;
	case 11930ULL: goto x86_l_2e9a;
	case 11935ULL: goto x86_l_2e9f;
	case 11937ULL: goto x86_l_2ea1;
	case 11940ULL: goto x86_l_2ea4;
	case 11946ULL: goto x86_l_2eaa;
	case 11952ULL: goto x86_l_2eb0;
	case 11957ULL: goto x86_l_2eb5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2e62:
	/* 0x2e62: jne    23d8 <trace_security_bpf+0x23d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9176ULL;
	}
x86_l_2e68:
	/* 0x2e68: add    rbx,0xffffffffffffffd0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551568ULL);
x86_l_2e6c:
	/* 0x2e6c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e71:
	/* 0x2e71: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2e74:
	/* 0x2e74: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e79:
	/* 0x2e79: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2e7c:
	/* 0x2e7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e7e:
	/* 0x2e7e: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e82:
	/* 0x2e82: jmp    23db <trace_security_bpf+0x23db> */
	return 9179ULL;
x86_l_2e87:
	/* 0x2e87: lea    rdi,[r14+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_2e8e:
	/* 0x2e8e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2e91:
	/* 0x2e91: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2e95:
	/* 0x2e95: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e9a:
	/* 0x2e9a: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_2e9f:
	/* 0x2e9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ea1:
	/* 0x2ea1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ea4:
	/* 0x2ea4: jne    2de5 <trace_security_bpf+0x2de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11749ULL;
	}
x86_l_2eaa:
	/* 0x2eaa: movzx  eax,WORD PTR [r12+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_2eb0:
	/* 0x2eb0: mov    WORD PTR [r14+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_2eb5:
	/* 0x2eb5: jmp    ab4 <trace_security_bpf+0xab4> */
	return 2740ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_trace_security_bpf_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 10832U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2103ULL)
			__x86_pc = tracee_trace_security_bpf_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2108ULL && __x86_pc <= 3710ULL)
			__x86_pc = tracee_trace_security_bpf_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3715ULL && __x86_pc <= 5244ULL)
			__x86_pc = tracee_trace_security_bpf_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5248ULL && __x86_pc <= 6882ULL)
			__x86_pc = tracee_trace_security_bpf_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6887ULL && __x86_pc <= 8423ULL)
			__x86_pc = tracee_trace_security_bpf_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8426ULL && __x86_pc <= 10203ULL)
			__x86_pc = tracee_trace_security_bpf_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10211ULL && __x86_pc <= 11866ULL)
			__x86_pc = tracee_trace_security_bpf_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 11874ULL && __x86_pc <= 11957ULL)
			__x86_pc = tracee_trace_security_bpf_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
